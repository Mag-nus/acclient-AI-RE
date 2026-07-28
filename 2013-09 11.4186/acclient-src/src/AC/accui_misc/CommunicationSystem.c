/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CommunicationSystem
   Object     : AC\accui_misc\CommunicationSystem.obj
   Functions  : 277
   Addresses  : 0056E290 - 007740B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0056E290) --------------------------------------------------------  // acclient.c:410722
int __cdecl MagicEnumMapper::SpellComponentCategoryFromString(const char *const buf, SpellComponentCategory *st)
{
  int result; // eax@2

  if ( !buf )
    return 0;
  if ( !__stricmp(buf, "Scarab") )
    goto LABEL_4;
  if ( !__stricmp(buf, "Herb") )
  {
LABEL_6:
    *st = 1;
    return 1;
  }
  if ( !__stricmp(buf, "PowderedGem") )
    goto LABEL_8;
  if ( !__stricmp(buf, "Powder") )
  {
LABEL_10:
    *st = 2;
    return 1;
  }
  if ( !__stricmp(buf, "AlchemicalSubstance") )
    goto LABEL_12;
  if ( !__stricmp(buf, "Potion") )
  {
LABEL_14:
    *st = 3;
    return 1;
  }
  if ( !__stricmp(buf, "Talisman") )
    goto LABEL_16;
  if ( !__stricmp(buf, "Taper") )
  {
LABEL_18:
    *st = 5;
    return 1;
  }
  if ( !__stricmp(buf, "Pea") )
    goto LABEL_33;
  if ( !__stricmp(buf, "Scarabs") )
  {
LABEL_4:
    *st = 0;
    return 1;
  }
  if ( !__stricmp(buf, "Herbs") )
    goto LABEL_6;
  if ( !__stricmp(buf, "PowderedGems") )
  {
LABEL_8:
    *st = 2;
    return 1;
  }
  if ( !__stricmp(buf, "Powders") )
    goto LABEL_10;
  if ( !__stricmp(buf, "AlchemicalSubstances") )
  {
LABEL_12:
    *st = 3;
    return 1;
  }
  if ( !__stricmp(buf, "Potions") )
    goto LABEL_14;
  if ( !__stricmp(buf, "Talismans") )
  {
LABEL_16:
    *st = 4;
    return 1;
  }
  if ( !__stricmp(buf, "Tapers") )
    goto LABEL_18;
  if ( !__stricmp(buf, "Peas") )
  {
LABEL_33:
    *st = 6;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0056E480) --------------------------------------------------------  // acclient.c:410808
ClientCommunicationSystem *__cdecl ClientCommunicationSystem::GetCommunicationSystem()
{
  return ClientCommunicationSystem::s_pCommunicationSystem;
}
// 8707EC: using guessed type struct ClientCommunicationSystem *ClientCommunicationSystem::s_pCommunicationSystem;

//----- (0056E490) --------------------------------------------------------  // acclient.c:410815
void __thiscall ClientCommunicationSystem::OnBeginCharacterSession(ClientCommunicationSystem *this)
{
  if ( this )
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
      13,
      110,
      &this->vfptr);
  else
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
      13,
      110,
      0);
}

//----- (0056E4C0) --------------------------------------------------------  // acclient.c:410830
void __thiscall ClientCommunicationSystem::OnEndCharacterSession(ClientCommunicationSystem *this)
{
  if ( this )
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
      13,
      110,
      &this->vfptr);
  else
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
      13,
      110,
      0);
}

//----- (0056E4F0) --------------------------------------------------------  // acclient.c:410845
unsigned int __stdcall ClientCommunicationSystem::Handle_Communication__Recv_ChatRoomTracker(ChatRoomTracker *chatRoomTracker)
{
  PlayerModule *v2; // eax@1
  ShortCutManager *v3; // eax@2
  int v4; // esi@2
  int v5; // ecx@2

  gmCCommunicationSystem::SetChatRoomTracker(chatRoomTracker);
  v2 = (PlayerModule *)gmCCommunicationSystem::GetChatRoomTracker();
  if ( v2 )
  {
    v3 = CInputManager::GetMouseX(v2);
    v4 = v3 != 0;
    LOBYTE(v5) = v3 != 0;
    gmCCommunicationSystem::SetTalkFocusEnabled(7u, v5);
    if ( gmCCommunicationSystem::WantsToBeInAllegChat() )
    {
      if ( v4 )
        gmCCommunicationSystem::SetTalkFocus(7u);
    }
  }
  return 0;
}

//----- (0056E550) --------------------------------------------------------  // acclient.c:410870
unsigned int __stdcall ClientCommunicationSystem::Handle_Communication__HearRangedSpeech(AC1Legacy::PStringBase<char> *msg, AC1Legacy::PStringBase<char> *name, unsigned int sender_id, float range, unsigned int ltt)
{
  gmCCommunicationSystem::HandleRangedTalkEvent(msg, name, sender_id, range, ltt);
  return 0;
}

//----- (0056E580) --------------------------------------------------------  // acclient.c:410877
bool __thiscall ClientCommunicationSystem::IsMessageSpam(ClientCommunicationSystem *this, int wait_time)
{
  ClientCommunicationSystem *v2; // esi@1
  int v3; // eax@1
  int v4; // edx@1
  bool result; // al@2
  int v6; // eax@3
  bool v7; // sf@3

  v2 = this;
  v3 = Timer::get_real_time();
  v4 = v2->m_LastSpamCheck;
  v2->m_LastSpamCheck = v3;
  if ( v4 )
  {
    v6 = 1 - (v3 - v4);
    v7 = v6 + v2->m_ChatMessageCount < 0;
    v2->m_ChatMessageCount += v6;
    if ( v7 )
      v2->m_ChatMessageCount = 0;
    result = v2->m_ChatMessageCount > 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0056E5D0) --------------------------------------------------------  // acclient.c:410907
char __stdcall ClientCommunicationSystem::HelpMessageTypes(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  gmCCommunicationSystem::GetListofSquelchChannels(msg);
  return 1;
}

//----- (0056E5F0) --------------------------------------------------------  // acclient.c:410914
bool __stdcall ClientCommunicationSystem::DoBirth(int argc, char **argv)
{
  return CM_Character::Event_QueryBirth(0);
}

//----- (0056E600) --------------------------------------------------------  // acclient.c:410920
char __thiscall ClientCommunicationSystem::DoClear(ClientCommunicationSystem *this, int argc, char **argv)
{
  unsigned int v3; // esi@1

  v3 = this->m_idCurrentCommandSource;
  if ( argc && !__stricmp(*argv, "all") )
    v3 = 0;
  CM_UI::SendNotice_ClearChatBuffer(v3);
  return 1;
}

//----- (0056E640) --------------------------------------------------------  // acclient.c:410932
bool __stdcall ClientCommunicationSystem::DoChannelIndex(int argc, char **argv)
{
  return CM_Communication::Event_ChannelIndex();
}

//----- (0056E650) --------------------------------------------------------  // acclient.c:410938
char __thiscall ClientCommunicationSystem::EnableChatTalkFocuses(ClientCommunicationSystem *this)
{
  char result; // al@2
  CPlayerSystem *v2; // eax@3
  CPlayerSystem *v3; // eax@3
  CPlayerSystem *v4; // eax@3
  CPlayerSystem *v5; // eax@3
  CPlayerSystem *v6; // eax@3
  int bEnabled; // [sp+0h] [bp-4h]@1

  bEnabled = (int)this;
  if ( CCommunicationSystem::IsUsingTurbineChat() )
  {
    v2 = CPlayerSystem::GetPlayerSystem();
    LOBYTE(bEnabled) = PlayerModule::HearGeneralChat((PlayerModule *)&v2->playerModule.vfptr);
    gmCCommunicationSystem::SetTalkFocusEnabled(8u, bEnabled);
    v3 = CPlayerSystem::GetPlayerSystem();
    LOBYTE(bEnabled) = PlayerModule::HearTradeChat((PlayerModule *)&v3->playerModule.vfptr);
    gmCCommunicationSystem::SetTalkFocusEnabled(9u, bEnabled);
    v4 = CPlayerSystem::GetPlayerSystem();
    LOBYTE(bEnabled) = PlayerModule::HearLFGChat((PlayerModule *)&v4->playerModule.vfptr);
    gmCCommunicationSystem::SetTalkFocusEnabled(0xAu, bEnabled);
    v5 = CPlayerSystem::GetPlayerSystem();
    LOBYTE(bEnabled) = PlayerModule::HearRoleplayChat((PlayerModule *)&v5->playerModule.vfptr);
    gmCCommunicationSystem::SetTalkFocusEnabled(0xBu, bEnabled);
    v6 = CPlayerSystem::GetPlayerSystem();
    LOBYTE(bEnabled) = PlayerModule::HearSocietyChat((PlayerModule *)&v6->playerModule.vfptr);
    gmCCommunicationSystem::SetTalkFocusEnabled(0xCu, bEnabled);
    LOBYTE(bEnabled) = CPlayerSystem::IsOlthoi() != 0;
    gmCCommunicationSystem::SetTalkFocusEnabled(0xDu, bEnabled);
    result = 1;
  }
  else
  {
    gmCCommunicationSystem::SetTalkFocusEnabled(8u, 0);
    gmCCommunicationSystem::SetTalkFocusEnabled(9u, 0);
    gmCCommunicationSystem::SetTalkFocusEnabled(0xAu, 0);
    gmCCommunicationSystem::SetTalkFocusEnabled(0xBu, 0);
    gmCCommunicationSystem::SetTalkFocusEnabled(0xCu, 0);
    gmCCommunicationSystem::SetTalkFocusEnabled(0xDu, 0);
    result = 0;
  }
  return result;
}

//----- (0056E760) --------------------------------------------------------  // acclient.c:410984
char __cdecl PStringBaseIter_Common<char>::FindSubStringIter(const char *my_curr, const char *substring_curr)
{
  const char *v2; // esi@1
  int *v3; // edi@2
  int v4; // ebp@4
  const char v5; // al@5
  char result; // al@6

  v2 = substring_curr;
  if ( *substring_curr )
  {
    v3 = (int *)my_curr;
    while ( *(_BYTE *)v3 )
    {
      v4 = _tolower(*(_BYTE *)v3);
      if ( v4 != _tolower(*v2) )
        break;
      v5 = v2[1];
      v3 = (int *)((char *)v3 + 1);
      ++v2;
      if ( !v5 )
        goto LABEL_6;
    }
    result = 0;
  }
  else
  {
LABEL_6:
    result = 1;
  }
  return result;
}

//----- (0056E7B0) --------------------------------------------------------  // acclient.c:411018
LONG __thiscall ClientUISystem::AddRef(ClientCommunicationSystem *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (0056E7C0) --------------------------------------------------------  // acclient.c:411024
TResult *__thiscall ClientCommunicationSystem::QueryInterface(ClientCommunicationSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S197_33 & 1 )
  {
    v4 = Offsets_10[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientCommunicationSystem_InterfaceType_63;
    _S197_33 |= 1u;
    Offsets_10[0].key = (_GUID *)&ClientCommunicationSystem_InterfaceType_63;
    dword_8708D4 = 0;
    dword_8708D8 = (int)&ClientSystem_InterfaceType_89;
    dword_8708DC = 0;
    dword_8708E0 = (int)&stru_7D0008;
    dword_8708E4 = 0;
    dword_8708E8 = 0;
    dword_8708EC = 0;
  }
  v5 = (int)Offsets_10;
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
// 8708D4: using guessed type int dword_8708D4;
// 8708D8: using guessed type int dword_8708D8;
// 8708DC: using guessed type int dword_8708DC;
// 8708E0: using guessed type int dword_8708E0;
// 8708E4: using guessed type int dword_8708E4;
// 8708E8: using guessed type int dword_8708E8;
// 8708EC: using guessed type int dword_8708EC;

//----- (0056E890) --------------------------------------------------------  // acclient.c:411091
void __thiscall ClientCommunicationSystem::RecvNotice_DisplayStringInfo(ClientCommunicationSystem *this, unsigned int type, StringInfo *msg)
{
  unsigned int v3; // ST08_4@1
  ClientCommunicationSystem *v4; // esi@1
  PStringBase<unsigned short> *v5; // eax@1
  unsigned int v6; // esi@1

  v3 = type;
  v4 = this;
  v5 = StringInfo::GetString(msg, (PStringBase<unsigned short> *)&type, 0);
  ClientSystem::AddTextToScroll((ClientSystem *)&v4[-1].m_strLogName, v5, v3, 1, 0);
  v6 = type - 20;
  if ( !InterlockedDecrement((volatile LONG *)(type - 20 + 4)) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}

//----- (0056E8E0) --------------------------------------------------------  // acclient.c:411111
void __thiscall ClientCommunicationSystem::RecvNotice_PlayerDescReceived(ClientCommunicationSystem *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  ClientCommunicationSystem::EnableChatTalkFocuses((ClientCommunicationSystem *)((char *)this - 4));
}

//----- (0056E8F0) --------------------------------------------------------  // acclient.c:411117
void __thiscall ClientCommunicationSystem::RecvNotice_PlayerOptionChanged(ClientCommunicationSystem *this, PlayerOption i_eOption)
{
  if ( i_eOption == 35 || i_eOption == 36 || i_eOption == 37 || i_eOption == 38 || i_eOption == 46 )
    ClientCommunicationSystem::EnableChatTalkFocuses((ClientCommunicationSystem *)((char *)this - 4));
}

//----- (0056E920) --------------------------------------------------------  // acclient.c:411124
IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *__thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vector_deleting_destructor(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v2; // esi@1
  ClientCommunicationSystem::CmdHashData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1>Vtbl *)&IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7D00DC: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vftable)(void *, char);

//----- (0056E960) --------------------------------------------------------  // acclient.c:411145
bool __thiscall PStringBaseIter_Common<char>::FindSubString(PStringBaseIter_Common<char> *this, PStringBase<char> *substring, bool reverse)
{
  int v3; // eax@1
  PStringBaseIter_Common<char> *v4; // esi@1
  int v5; // ebp@2
  unsigned int v6; // eax@5
  int i; // eax@8
  PStringBaseIter_Common<char>Vtbl *v8; // edx@9
  const char *v9; // eax@9
  unsigned int v10; // eax@10
  const char *v11; // eax@13
  int v12; // edi@14

  v3 = *(_DWORD *)&substring->m_charbuffer[-1].m_data[12];
  v4 = this;
  if ( v3 != 1 )
  {
    v5 = v3 - 1;
    if ( reverse )
    {
      if ( v5 < 0 )
        PStringBaseIter_Common<char>::Next(this, v5);
      v6 = v4->curr;
      if ( v5 <= v6 )
      {
        for ( i = v6 - v5; ; i = v10 - 1 )
        {
          v8 = v4->vfptr;
          v4->curr = i;
          v9 = v8->IndexToConstPointer(v4, i);
          if ( PStringBaseIter_Common<char>::FindSubStringIter(v9, substring->m_charbuffer->m_data) )
            break;
          v10 = v4->curr;
          if ( v10 < 1 )
            goto LABEL_7;
        }
        v4->mark = v5 + v4->curr;
        LOBYTE(v3) = 1;
      }
      else
      {
        v4->curr = 0;
LABEL_7:
        v4->curr = 0;
        LOBYTE(v3) = 0;
      }
    }
    else
    {
      while ( 1 )
      {
        v11 = v4->vfptr->IndexToConstPointer(v4, v4->curr);
        if ( PStringBaseIter_Common<char>::FindSubStringIter(v11, substring->m_charbuffer->m_data) )
          break;
        v12 = v4->curr + 1;
        if ( v12 > v4->vfptr->GetStrLen(v4) )
        {
          v4->curr = v4->vfptr->GetStrLen(v4);
          LOBYTE(v3) = 0;
          return v3;
        }
        v4->curr = v12;
      }
      v4->mark = v5 + v4->curr;
      LOBYTE(v3) = 1;
    }
  }
  return v3;
}

//----- (0056EA40) --------------------------------------------------------  // acclient.c:411216
bool __cdecl PSUtils::is_int32(PStringBase<char> str)
{
  bool v1; // bl@3
  const char *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  _strtol(str.m_charbuffer->m_data, (char **)&end, 0);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1])
    && str.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&str.m_charbuffer[-2].m_data[12])(&str.m_charbuffer[-2].m_data[12], 1);
  return v1;
}

//----- (0056EAB0) --------------------------------------------------------  // acclient.c:411232
void __thiscall ClientCommunicationSystem::~ClientCommunicationSystem(ClientCommunicationSystem *this)
{
  ClientCommunicationSystem *v1; // esi@1
  NoticeHandler *v2; // ebp@1
  GlobalEventHandler *v3; // eax@1
  int v4; // edi@3
  int v5; // edi@6
  int v6; // edi@9
  void *v7; // eax@12

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&ClientCommunicationSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientCommunicationSystem::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)&ClientCommunicationSystem::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v4 = (int)&v1->m_strLogName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = (int)&v1->m_strCurrentCommand.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = (int)&v1->m_strLastCommandLine.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = v1->m_hashCommands.m_buckets;
  v1->m_hashCommands.vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1>Vtbl *)&IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vftable;
  if ( v7 != v1->m_hashCommands.m_aInplaceBuckets )
    operator delete[](v7);
  v1->m_hashCommands.m_buckets = 0;
  v1->m_hashCommands.m_firstInterestingBucket = 0;
  v1->m_hashCommands.m_numBuckets = 0;
  v1->m_hashCommands.m_numElements = 0;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7D00DC: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vftable)(void *, char);
// 7D00E0: using guessed type void (__thiscall *ClientCommunicationSystem::vftable)(ClientCommunicationSystem *this, CWeenieObject *cwobj, enum StatType bAFK, unsigned __int32);
// 7D00E8: using guessed type bool (__thiscall *ClientCommunicationSystem::vftable)(DBCache *this);
// 7D0390: using guessed type __int32 (__stdcall *ClientCommunicationSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0056EB90) --------------------------------------------------------  // acclient.c:411279
unsigned int __stdcall ClientCommunicationSystem::Handle_Communication__SetSquelchDB(SquelchDB *db)
{
  const unsigned int v2; // esi@1
  SquelchDB *v3; // esi@2

  gmCCommunicationSystem::SetSquelchDB(db);
  v2 = ACCWeenieObject::selectedID;
  if ( ACCWeenieObject::selectedID )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&db, &name);
    gmCCommunicationSystem::IsSquelched(v2, (AC1Legacy::PStringBase<char> *)&db, 1u);
    v3 = db;
    if ( !InterlockedDecrement((volatile LONG *)&db->_account_hash) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((PackObj *)v3, 1u);
    }
  }
  return 0;
}

//----- (0056EBF0) --------------------------------------------------------  // acclient.c:411301
void __thiscall AC1Legacy::PStringBase<char>::trim(AC1Legacy::PStringBase<char> *this, int pre, int post, AC1Legacy::PStringBase<char> filter)
{
  char *v4; // edi@1
  unsigned int v5; // esi@1
  const char i; // al@2
  AC1Legacy::PSRefBuffer<char> *v7; // eax@9
  AC1Legacy::PSRefBuffer<char> *v8; // esi@11
  LONG v9; // eax@11
  AC1Legacy::PSRefBuffer<char> *v10; // ebp@12
  AC1Legacy::PSRefBuffer<char> *v11; // ebx@12
  AC1Legacy::PStringBase<char> *v12; // ebx@16
  volatile LONG *v13; // ST04_4@16
  AC1Legacy::PStringBase<char> *v14; // [sp+10h] [bp-4h]@1

  v4 = this->m_buffer->m_data;
  v5 = this->m_buffer->m_len - 1;
  v14 = this;
  if ( pre )
  {
    for ( i = *v4; i; --v5 )
    {
      if ( !_strchr(filter.m_buffer->m_data, i) )
        break;
      i = (v4++)[1];
    }
  }
  if ( post && v5 )
  {
    do
    {
      if ( !_strchr(filter.m_buffer->m_data, v4[v5 - 1]) )
        break;
      --v5;
    }
    while ( v5 );
  }
  v7 = v14->m_buffer;
  if ( v4 != (char *)v14->m_buffer->m_data || v5 != v7->m_len - 1 )
  {
    v10 = v14->m_buffer;
    InterlockedIncrement((volatile LONG *)&v7->m_cRef);
    v11 = v14->m_buffer;
    if ( v14->m_buffer == (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      v12 = v14;
    }
    else
    {
      if ( !InterlockedDecrement((volatile LONG *)&v11->m_cRef) && v11 )
        v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
      v12 = v14;
      v13 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
      v14->m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement(v13);
    }
    if ( v5 )
      AC1Legacy::PStringBase<char>::append_n_chars(v12, v4, v5);
    if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) && v10 )
      v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
    v8 = filter.m_buffer;
    v9 = InterlockedDecrement((volatile LONG *)&filter.m_buffer->m_cRef);
  }
  else
  {
    v8 = filter.m_buffer;
    v9 = InterlockedDecrement((volatile LONG *)&filter.m_buffer->m_cRef);
  }
  if ( !v9 )
  {
    if ( v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056ED30) --------------------------------------------------------  // acclient.c:411377
void __thiscall ClientCommunicationSystem::CmdHashData::CmdHashData(ClientCommunicationSystem::CmdHashData *this, CaseInsensitiveStringBase<PStringBase<char> > *name, bool (__thiscall *i_pfnFunc)(ClientCommunicationSystem *this, int, char **), bool (__thiscall *i_pfnHelp)(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *), bool (__thiscall *i_pfnHelpa)(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *), int a6)
{
  PSRefBufferCharData<char> *v6; // eax@1
  ClientCommunicationSystem::CmdHashData *v7; // esi@1

  v6 = name->m_charbuffer;
  v7 = this;
  this->m_hashKey.m_charbuffer = name->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v6[-1]);
  v7->func = i_pfnFunc;
  v7->help = i_pfnHelpa;
  v7->m_hashNext = 0;
  *((_DWORD *)&v7->func + 1) = i_pfnHelp;
  *((_DWORD *)&v7->help + 1) = a6;
}

//----- (0056ED70) --------------------------------------------------------  // acclient.c:411394
int __stdcall ClientCommunicationSystem::IsMessageSafe(PStringBase<char> *msg)
{
  const char **v2; // edi@1
  char *v3; // eax@1
  int v4; // eax@2
  char *v5; // esi@4
  char *v6; // eax@7
  int v7; // eax@8
  char *v8; // esi@10
  int v9; // edi@10
  int v10; // edi@15
  PStringBase<char> *v11; // esi@17
  PStringBase<char> v13; // [sp+10h] [bp-8h]@1
  int bContainsGreenText; // [sp+14h] [bp-4h]@4

  v2 = (const char **)msg;
  msg = (PStringBase<char> *)msg->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&msg[-4]);
  PStringBase<char>::break_reference((PStringBase<char> *)&msg);
  __strlwr((char *)msg);
  PStringBase<char>::PStringBase<char>(&v13, "<tell:");
  v3 = _strstr((const char *)msg, v13.m_charbuffer->m_data);
  if ( v3 )
    v4 = v3 - (char *)msg;
  else
    v4 = -1;
  v5 = &v13.m_charbuffer[-2].m_data[12];
  bContainsGreenText = v4 != -1;
  if ( !InterlockedDecrement((volatile LONG *)&v13.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  PStringBase<char>::PStringBase<char>(&v13, "\n");
  v6 = _strstr(*v2, v13.m_charbuffer->m_data);
  if ( v6 )
    v7 = v6 - *v2;
  else
    v7 = -1;
  v8 = &v13.m_charbuffer[-2].m_data[12];
  v9 = v7 != -1;
  if ( !InterlockedDecrement((volatile LONG *)&v13.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  v10 = !bContainsGreenText && !v9;
  v11 = msg - 5;
  if ( !InterlockedDecrement((volatile LONG *)&msg[-4]) && v11 )
    (*(void (__thiscall **)(PStringBase<char> *, signed int))&v11->m_charbuffer->m_data[0])(v11, 1);
  return v10;
}

//----- (0056EE90) --------------------------------------------------------  // acclient.c:411442
PStringBase<char> *__cdecl NextArg(PStringBase<char> *result, int *argc, char ***argv)
{
  PSRefBufferCharData<char> *v3; // eax@3
  char *v4; // esi@3
  PStringBase<char> strResult; // [sp+0h] [bp-4h]@1

  strResult.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( *argc )
  {
    PStringBase<char>::set(&strResult, **argv);
    --*argc;
    ++*argv;
  }
  v3 = strResult.m_charbuffer;
  result->m_charbuffer = strResult.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  v4 = &strResult.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strResult.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return result;
}

//----- (0056EF10) --------------------------------------------------------  // acclient.c:411466
bool __thiscall ClientCommunicationSystem::DoAllegianceHometown(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  bool result; // al@5

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"This command takes no arguments!");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  else
  {
    result = CM_Allegiance::Event_RecallAllegianceHometown();
  }
  return result;
}

//----- (0056EF70) --------------------------------------------------------  // acclient.c:411500
bool __stdcall ClientCommunicationSystem::DoAllegianceHouse(int argc, char **argv)
{
  char *v4; // edi@3
  int *v5; // eax@6
  int v6; // ebp@6
  volatile LONG *v7; // ST08_4@6
  char *v8; // edi@6
  int v9; // eax@9
  char **v10; // edi@9
  bool v11; // bl@9
  int v12; // eax@13
  char **v13; // edi@13
  bool v14; // bl@13
  bool v15; // bl@17
  char *v16; // edi@20
  int v17; // eax@24
  char **v18; // edi@24
  bool v19; // bl@24
  bool v20; // al@28
  bool v21; // bl@29
  int v22; // eax@30
  char **v23; // edi@30
  bool v24; // bl@30
  int v25; // eax@34
  char **v26; // edi@34
  bool v27; // bl@34
  bool v28; // bl@39
  char *v29; // edi@44
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+18h] [bp-8h]@3
  PStringBase<char> result; // [sp+1Ch] [bp-4h]@3

  if ( argc < 2 )
    return CM_Allegiance::Event_DoAllegianceHouseAction(1u);
  command.m_charbuffer = NextArg(&result, &argc, &argv)->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&command.m_charbuffer[-1]);
  v4 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  v5 = (int *)NextArg(&result, &argc, &argv);
  v6 = *v5;
  v7 = (volatile LONG *)(*v5 - 16);
  argc = *v5;
  InterlockedIncrement(v7);
  v8 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "guest");
  v9 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, (PStringBase<char> *)&argv, 0);
  v10 = argv - 5;
  v11 = v9 == 0;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v10 )
    (*(void (__thiscall **)(char **, signed int))*v10)(v10, 1);
  if ( v11 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "open");
    v12 = PStringBase<char>::cmp((PStringBase<char> *)&argc, (PStringBase<char> *)&argv, 0);
    v13 = argv - 5;
    v14 = v12 == 0;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v13 )
      (*(void (__thiscall **)(char **, signed int))*v13)(v13, 1);
    if ( v14 )
    {
      v15 = CM_Allegiance::Event_DoAllegianceHouseAction(2u);
      if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v6 != 20 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))(v6 - 20))(v6 - 20, 1);
      v16 = &command.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) )
      {
        if ( v16 )
          (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
      }
      return v15;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "close");
    v17 = PStringBase<char>::cmp((PStringBase<char> *)&argc, (PStringBase<char> *)&argv, 0);
    v18 = argv - 5;
    v19 = v17 == 0;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v18 )
      (*(void (__thiscall **)(char **, signed int))*v18)(v18, 1);
    if ( v19 )
    {
      v20 = CM_Allegiance::Event_DoAllegianceHouseAction(3u);
LABEL_29:
      v21 = v20;
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
      PStringBase<char>::~PStringBase<char>(&command);
      return v21;
    }
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "storage");
    v22 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, (PStringBase<char> *)&argv, 0);
    v23 = argv - 5;
    v24 = v22 == 0;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v23 )
      (*(void (__thiscall **)(char **, signed int))*v23)(v23, 1);
    if ( v24 )
    {
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "open");
      v25 = PStringBase<char>::cmp((PStringBase<char> *)&argc, (PStringBase<char> *)&argv, 0);
      v26 = argv - 5;
      v27 = v25 == 0;
      if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v26 )
        (*(void (__thiscall **)(char **, signed int))*v26)(v26, 1);
      if ( v27 )
      {
        v20 = CM_Allegiance::Event_DoAllegianceHouseAction(4u);
        goto LABEL_29;
      }
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "close");
      v28 = PStringBase<char>::cmp((PStringBase<char> *)&argc, (PStringBase<char> *)&argv, 0) == 0;
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      if ( v28 )
      {
        v20 = CM_Allegiance::Event_DoAllegianceHouseAction(5u);
        goto LABEL_29;
      }
    }
  }
  if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v6 != 20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))(v6 - 20))(v6 - 20, 1);
  v29 = &command.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v29 )
    (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
  return 0;
}

//----- (0056F290) --------------------------------------------------------  // acclient.c:411629
char __stdcall ClientCommunicationSystem::HelpStupidChannelHack(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  const char *v4; // esi@1
  int v5; // edi@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebx@1
  PStringBase<char> *v7; // esi@4
  PStringBase<char> *v8; // eax@4
  PStringBase<char> *v9; // eax@4
  PStringBase<char> *v10; // eax@4
  PStringBase<char> *v11; // eax@4
  PStringBase<char> *v12; // edi@4
  PSRefBufferCharData<char> *v13; // eax@4
  int v14; // ebx@5
  PSRefBufferCharData<char> *v15; // edi@8
  char *v16; // esi@9
  char *v17; // esi@12
  char *v18; // esi@15
  char *v19; // esi@18
  char *v20; // esi@21
  char *v21; // esi@24
  char *v22; // esi@27
  char *v23; // esi@30
  char *v24; // esi@33
  char *v25; // esi@36
  const char *v26; // esi@39
  AC1Legacy::PStringBase<char> name; // [sp+1Ch] [bp-28h]@1
  PStringBase<char> rhs; // [sp+20h] [bp-24h]@4
  PStringBase<char> v30; // [sp+24h] [bp-20h]@4
  PStringBase<char> v31; // [sp+28h] [bp-1Ch]@4
  PStringBase<char> v32; // [sp+2Ch] [bp-18h]@4
  PStringBase<char> v33; // [sp+30h] [bp-14h]@4
  PStringBase<char> v34; // [sp+34h] [bp-10h]@4
  PStringBase<char> v35; // [sp+38h] [bp-Ch]@4
  PStringBase<char> v36; // [sp+3Ch] [bp-8h]@4
  PStringBase<char> result; // [sp+40h] [bp-4h]@4

  v4 = argv0;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&name, argv0);
  v5 = ChannelSystem::GetChannelID(&name);
  v6 = name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  argv0 = (const char *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  ChannelSystem::GetChannelName(v5, (AC1Legacy::PStringBase<char> *)&argv0);
  PStringBase<char>::PStringBase<char>(&v32, ".\n");
  PStringBase<char>::PStringBase<char>(&v31, argv0 + 20);
  PStringBase<char>::PStringBase<char>(&v30, " - Sends a broadcast to your ");
  PStringBase<char>::PStringBase<char>(&rhs, v4);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&name, "@");
  v7 = msg;
  v8 = PStringBase<char>::operator+(msg, &result, (PStringBase<char> *)&name);
  v9 = PStringBase<char>::operator+(v8, &v36, &rhs);
  v10 = PStringBase<char>::operator+(v9, &v35, &v30);
  v11 = PStringBase<char>::operator+(v10, &v34, &v31);
  v12 = PStringBase<char>::operator+(v11, &v33, &v32);
  v13 = v7->m_charbuffer;
  if ( v7->m_charbuffer != v12->m_charbuffer )
  {
    v14 = (int)&v13[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v13[-1]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    v15 = v12->m_charbuffer;
    v7->m_charbuffer = v15;
    InterlockedIncrement((volatile LONG *)&v15[-1]);
  }
  v16 = &v33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v33.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  v17 = &v34.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v34.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  v18 = &v35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v35.m_charbuffer[-1]) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  v19 = &v36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v36.m_charbuffer[-1]) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  v20 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
  v21 = (char *)&name.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer[-1].m_cRef + 1) && v21 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  v22 = &rhs.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  v23 = &v30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v30.m_charbuffer[-1]) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  v24 = &v31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v31.m_charbuffer[-1]) && v24 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
  v25 = &v32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v32.m_charbuffer[-1]) && v25 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
  v26 = argv0;
  if ( !InterlockedDecrement((volatile LONG *)argv0 + 1) && v26 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0056F510) --------------------------------------------------------  // acclient.c:411733
bool __stdcall ClientCommunicationSystem::DoJoinChat(int argc, char **argv)
{
  char ***v3; // eax@1
  char **v4; // ebp@1
  volatile LONG *v5; // ST08_4@1
  char *v6; // edi@1
  int v7; // eax@4
  int v8; // edi@4
  bool v9; // bl@4
  CPlayerSystem *v10; // eax@8
  int v11; // eax@9
  int v12; // edi@9
  bool v13; // bl@9
  CPlayerSystem *v14; // eax@13
  int v15; // eax@14
  int v16; // edi@14
  bool v17; // bl@14
  CPlayerSystem *v18; // eax@18
  bool v19; // al@22
  int v20; // eax@23
  int v21; // edi@23
  bool v22; // bl@23
  CPlayerSystem *v23; // eax@27
  bool v24; // bl@28
  CPlayerSystem *v25; // eax@29
  bool v26; // bl@31
  CPlayerSystem *v27; // eax@34
  PStringBase<char> result; // [sp+14h] [bp-4h]@1

  v3 = (char ***)NextArg(&result, &argc, &argv);
  v4 = *v3;
  v5 = (volatile LONG *)(*v3 - 4);
  argv = *v3;
  InterlockedIncrement(v5);
  v6 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Allegiance");
  v7 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v8 = argc - 20;
  v9 = v7 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  if ( v9 )
  {
    v10 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearAllegianceChat((PlayerModule *)&v10->playerModule.vfptr, 1);
LABEL_19:
    if ( !InterlockedDecrement((volatile LONG *)v4 - 4) && v4 != (char **)20 )
      (*(void (__thiscall **)(char **, signed int))*(v4 - 5))(v4 - 5, 1);
    return 1;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "General");
  v11 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v12 = argc - 20;
  v13 = v11 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  if ( v13 )
  {
    v14 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearGeneralChat((PlayerModule *)&v14->playerModule.vfptr, 1);
    goto LABEL_19;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Trade");
  v15 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v16 = argc - 20;
  v17 = v15 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  if ( v17 )
  {
    v18 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearTradeChat((PlayerModule *)&v18->playerModule.vfptr, 1);
    goto LABEL_19;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "LFG");
  v20 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v21 = argc - 20;
  v22 = v20 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v21 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  if ( v22 )
  {
    v23 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearLFGChat((PlayerModule *)&v23->playerModule.vfptr, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    v19 = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Roleplay");
    v24 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0) == 0;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
    if ( v24 )
    {
      v25 = CPlayerSystem::GetPlayerSystem();
      PlayerModule::SetHearRoleplayChat((PlayerModule *)&v25->playerModule.vfptr, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      v19 = 1;
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&result, "Society");
      if ( !PStringBase<char>::cmp((PStringBase<char> *)&argv, &result, 0)
        || (PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Soc"),
            v26 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0) == 0,
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc),
            v26) )
        v26 = 1;
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( v26 )
      {
        v27 = CPlayerSystem::GetPlayerSystem();
        PlayerModule::SetHearSocietyChat((PlayerModule *)&v27->playerModule.vfptr, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
        v19 = 1;
      }
      else
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
        v19 = 0;
      }
    }
  }
  return v19;
}

//----- (0056F7F0) --------------------------------------------------------  // acclient.c:411862
bool __stdcall ClientCommunicationSystem::DoLeaveChat(int argc, char **argv)
{
  char ***v3; // eax@1
  char **v4; // ebp@1
  volatile LONG *v5; // ST08_4@1
  char *v6; // edi@1
  int v7; // eax@4
  int v8; // edi@4
  bool v9; // bl@4
  CPlayerSystem *v10; // eax@8
  int v11; // eax@9
  int v12; // edi@9
  bool v13; // bl@9
  CPlayerSystem *v14; // eax@13
  int v15; // eax@14
  int v16; // edi@14
  bool v17; // bl@14
  CPlayerSystem *v18; // eax@18
  bool v19; // al@22
  int v20; // eax@23
  int v21; // edi@23
  bool v22; // bl@23
  CPlayerSystem *v23; // eax@27
  bool v24; // bl@28
  CPlayerSystem *v25; // eax@29
  bool v26; // bl@31
  CPlayerSystem *v27; // eax@34
  PStringBase<char> result; // [sp+14h] [bp-4h]@1

  v3 = (char ***)NextArg(&result, &argc, &argv);
  v4 = *v3;
  v5 = (volatile LONG *)(*v3 - 4);
  argv = *v3;
  InterlockedIncrement(v5);
  v6 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Allegiance");
  v7 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v8 = argc - 20;
  v9 = v7 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  if ( v9 )
  {
    v10 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearAllegianceChat((PlayerModule *)&v10->playerModule.vfptr, 0);
LABEL_19:
    if ( !InterlockedDecrement((volatile LONG *)v4 - 4) && v4 != (char **)20 )
      (*(void (__thiscall **)(char **, signed int))*(v4 - 5))(v4 - 5, 1);
    return 1;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "General");
  v11 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v12 = argc - 20;
  v13 = v11 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  if ( v13 )
  {
    v14 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearGeneralChat((PlayerModule *)&v14->playerModule.vfptr, 0);
    goto LABEL_19;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Trade");
  v15 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v16 = argc - 20;
  v17 = v15 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  if ( v17 )
  {
    v18 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearTradeChat((PlayerModule *)&v18->playerModule.vfptr, 0);
    goto LABEL_19;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "LFG");
  v20 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0);
  v21 = argc - 20;
  v22 = v20 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v21 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  if ( v22 )
  {
    v23 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearLFGChat((PlayerModule *)&v23->playerModule.vfptr, 0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    v19 = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Roleplay");
    v24 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0) == 0;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
    if ( v24 )
    {
      v25 = CPlayerSystem::GetPlayerSystem();
      PlayerModule::SetHearRoleplayChat((PlayerModule *)&v25->playerModule.vfptr, 0);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      v19 = 1;
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&result, "Society");
      if ( !PStringBase<char>::cmp((PStringBase<char> *)&argv, &result, 0)
        || (PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Soc"),
            v26 = PStringBase<char>::cmp((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, 0) == 0,
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc),
            v26) )
        v26 = 1;
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( v26 )
      {
        v27 = CPlayerSystem::GetPlayerSystem();
        PlayerModule::SetHearSocietyChat((PlayerModule *)&v27->playerModule.vfptr, 0);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
        v19 = 1;
      }
      else
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
        v19 = 0;
      }
    }
  }
  return v19;
}

//----- (0056FAD0) --------------------------------------------------------  // acclient.c:411991
bool __thiscall ClientCommunicationSystem::DoChatToggle(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  bool result; // al@5
  char **v6; // edi@6
  int v7; // esi@10

  v3 = this;
  if ( argc == 1 )
  {
    v6 = argv;
    if ( !__stricmp(*argv, "on") )
    {
      result = CM_Communication::Event_ModifyGlobalSquelch(0, 2u);
    }
    else if ( !__stricmp(*v6, "off") )
    {
      result = CM_Communication::Event_ModifyGlobalSquelch(1, 2u);
    }
    else
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"Please specify on or off.");
      ClientSystem::AddTextToScroll(
        (ClientSystem *)&v3->vfptr,
        (PStringBase<unsigned short> *)&argc,
        0x1Au,
        1,
        v3->m_idCurrentCommandSource);
      v7 = argc - 20;
      if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      result = 1;
    }
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please specify if you want chat text on or off.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0056FBD0) --------------------------------------------------------  // acclient.c:412051
bool __thiscall ClientCommunicationSystem::DoNoTell(ClientCommunicationSystem *this, int argc, char **argv)
{
  char v3; // bl@1
  ClientCommunicationSystem *v4; // esi@1
  int v5; // esi@2
  bool result; // al@5
  char **v7; // esi@6

  v3 = 1;
  v4 = this;
  if ( argc == 1 )
  {
    v7 = argv;
    if ( __stricmp(*argv, "on") && !__stricmp(*v7, "off") )
      v3 = 0;
    result = CM_Communication::Event_ModifyGlobalSquelch((unsigned __int8)v3, 3u);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please specify if you want tells on or off.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v4->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v4->m_idCurrentCommandSource);
    v5 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0056FC70) --------------------------------------------------------  // acclient.c:412091
char __thiscall ClientCommunicationSystem::DoLifestone(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please see @help lifestone for more information on how to use this command.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    CM_Character::Event_TeleToLifestone();
  }
  return 1;
}

//----- (0056FCE0) --------------------------------------------------------  // acclient.c:412123
char __thiscall ClientCommunicationSystem::DoMarketplace(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please see @help marketplace for more information on how to use this command.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    CM_Character::Event_TeleToMarketplace();
  }
  return 1;
}

//----- (0056FD50) --------------------------------------------------------  // acclient.c:412155
char __thiscall ClientCommunicationSystem::DoFillComponents(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  PStringBase<char> v6; // ebp@7
  int v7; // eax@7
  char *v8; // edi@7
  bool v9; // bl@7
  CPlayerSystem *v10; // eax@11
  int v11; // esi@11
  int v12; // esi@14
  LONG v13; // eax@14
  char v14; // bl@15
  const unsigned __int16 *v15; // eax@17
  int v16; // eax@19
  PStringBase<char> command; // [sp+10h] [bp-10h]@7
  PStringBase<char> result; // [sp+14h] [bp-Ch]@7
  SpellComponentCategory sp_cat; // [sp+18h] [bp-8h]@1
  int max_to_spend; // [sp+1Ch] [bp-4h]@1

  v3 = this;
  max_to_spend = 0;
  sp_cat = 8;
  if ( argc > 2 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please use @help fillcomps for proper usage.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
    return 1;
  }
  if ( !argc )
  {
    CM_UI::SendNotice_FillComponentBuyList(Undef_SpellComponentCategory, 0);
    return 1;
  }
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>(&result, "clear");
  v6.m_charbuffer = command.m_charbuffer;
  v7 = __stricmp(command.m_charbuffer->m_data, result.m_charbuffer->m_data);
  v8 = &result.m_charbuffer[-2].m_data[12];
  v9 = v7 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  if ( v9 )
  {
    CM_Character::Event_SetDesiredComponentLevel(i_wcid, -1);
    v10 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::ClearDesiredCompList((PlayerModule *)&v10->playerModule.vfptr);
    CM_Magic::SendNotice_UpdateSpellComponents(2);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Component list cleared.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v12 = (int)&v6.m_charbuffer[-2].m_data[12];
    v13 = InterlockedDecrement((volatile LONG *)&v6.m_charbuffer[-1]);
    goto LABEL_26;
  }
  v14 = 0;
  if ( MagicEnumMapper::SpellComponentCategoryFromString(v6.m_charbuffer->m_data, &sp_cat) )
  {
    v14 = 1;
    if ( argc )
    {
      v15 = (const unsigned __int16 *)NextArg(&result, &argc, &argv);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&command, v15);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      v6.m_charbuffer = command.m_charbuffer;
    }
  }
  InterlockedIncrement((volatile LONG *)&v6.m_charbuffer[-1]);
  if ( PSUtils::is_int32(v6) )
  {
    v16 = PStringBase<char>::to_int32(&command);
    if ( v16 <= 0 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"Please specify a value greater than 0.");
      ClientSystem::AddTextToScroll(
        (ClientSystem *)&v3->vfptr,
        (PStringBase<unsigned short> *)&argc,
        0x1Au,
        1,
        v3->m_idCurrentCommandSource);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
      return 1;
    }
  }
  else
  {
    if ( !v14 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"Invalid component type specified.");
      ClientSystem::AddTextToScroll(
        (ClientSystem *)&v3->vfptr,
        (PStringBase<unsigned short> *)&argc,
        0x1Au,
        1,
        v3->m_idCurrentCommandSource);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
      goto LABEL_25;
    }
    v16 = max_to_spend;
  }
  CM_UI::SendNotice_FillComponentBuyList(sp_cat, v16);
LABEL_25:
  v12 = (int)&v6.m_charbuffer[-2].m_data[12];
  v13 = InterlockedDecrement((volatile LONG *)&v6.m_charbuffer[-1]);
LABEL_26:
  if ( !v13 && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  return 1;
}

//----- (0056FFF0) --------------------------------------------------------  // acclient.c:412293
char __thiscall ClientCommunicationSystem::DoSaveUI(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // edi@1
  ClientCommunicationSystem *v4; // esi@1
  PSRefBufferCharData<char> *v5; // esi@2
  int v6; // esi@5
  const unsigned __int16 *v8; // eax@8
  char *v9; // edi@8
  int v10; // esi@12
  char *v11; // esi@15
  LONG v12; // eax@15
  PStringBase<char> file_name; // [sp+8h] [bp-8h]@3
  PStringBase<char> result; // [sp+Ch] [bp-4h]@8

  v3 = argc;
  v4 = this;
  if ( argc <= 1 )
  {
    PStringBase<char>::PStringBase<char>(&file_name, &name);
    if ( v3 )
    {
      v8 = (const unsigned __int16 *)NextArg(&result, &argc, &argv);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&file_name, v8);
      v9 = &result.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      if ( *(_DWORD *)&file_name.m_charbuffer[-1].m_data[12] <= 0x10u )
      {
        CM_UI::SendNotice_SaveUI(&file_name);
        v11 = &file_name.m_charbuffer[-2].m_data[12];
        v12 = InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1]);
      }
      else
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&argc,
          L"The file name must be 16 characters or less.");
        ClientSystem::AddTextToScroll(
          (ClientSystem *)&v4->vfptr,
          (PStringBase<unsigned short> *)&argc,
          0x1Au,
          1,
          v4->m_idCurrentCommandSource);
        v10 = argc - 20;
        if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        v11 = &file_name.m_charbuffer[-2].m_data[12];
        v12 = InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1]);
      }
      if ( !v12 && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      return 1;
    }
    CM_UI::SendNotice_SaveUI(&file_name);
    v5 = file_name.m_charbuffer;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please use @help saveui for proper usage.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v4->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v4->m_idCurrentCommandSource);
    v5 = (PSRefBufferCharData<char> *)argc;
  }
  v6 = (int)&v5[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
  {
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    return 1;
  }
  return 1;
}

//----- (00570150) --------------------------------------------------------  // acclient.c:412372
char __thiscall ClientCommunicationSystem::DoLoadUI(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // edi@1
  ClientCommunicationSystem *v4; // esi@1
  PSRefBufferCharData<char> *v5; // esi@2
  int v6; // esi@5
  const unsigned __int16 *v8; // eax@8
  char *v9; // edi@8
  int v10; // esi@12
  char *v11; // esi@15
  LONG v12; // eax@15
  PStringBase<char> file_name; // [sp+8h] [bp-8h]@3
  PStringBase<char> result; // [sp+Ch] [bp-4h]@8

  v3 = argc;
  v4 = this;
  if ( argc <= 1 )
  {
    PStringBase<char>::PStringBase<char>(&file_name, &name);
    if ( v3 )
    {
      v8 = (const unsigned __int16 *)NextArg(&result, &argc, &argv);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&file_name, v8);
      v9 = &result.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      if ( *(_DWORD *)&file_name.m_charbuffer[-1].m_data[12] <= 0x10u )
      {
        CM_UI::SendNotice_LoadUI(&file_name);
        v11 = &file_name.m_charbuffer[-2].m_data[12];
        v12 = InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1]);
      }
      else
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&argc,
          L"The file name must be 16 characters or less.");
        ClientSystem::AddTextToScroll(
          (ClientSystem *)&v4->vfptr,
          (PStringBase<unsigned short> *)&argc,
          0x1Au,
          1,
          v4->m_idCurrentCommandSource);
        v10 = argc - 20;
        if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        v11 = &file_name.m_charbuffer[-2].m_data[12];
        v12 = InterlockedDecrement((volatile LONG *)&file_name.m_charbuffer[-1]);
      }
      if ( !v12 && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      return 1;
    }
    CM_UI::SendNotice_LoadUI(&file_name);
    v5 = file_name.m_charbuffer;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please use @help loadui for proper usage.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v4->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v4->m_idCurrentCommandSource);
    v5 = (PSRefBufferCharData<char> *)argc;
  }
  v6 = (int)&v5[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
  {
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    return 1;
  }
  return 1;
}

//----- (005702B0) --------------------------------------------------------  // acclient.c:412451
char __thiscall ClientCommunicationSystem::DoSaveAutoUI(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  PSRefBufferCharData<char> *v4; // esi@2
  int v5; // esi@4
  PStringBase<char> file_name; // [sp+0h] [bp-4h]@1

  file_name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  if ( argc <= 0 )
  {
    PStringBase<char>::PStringBase<char>(&file_name, "#auto");
    CM_UI::SendNotice_SaveUI(&file_name);
    v4 = file_name.m_charbuffer;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please use @help saveautoui for proper usage.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = (PSRefBufferCharData<char> *)argc;
  }
  v5 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return 1;
}

//----- (00570330) --------------------------------------------------------  // acclient.c:412486
char __thiscall ClientCommunicationSystem::DoLoadAutoUI(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  PSRefBufferCharData<char> *v4; // esi@2
  int v5; // esi@4
  PStringBase<char> file_name; // [sp+0h] [bp-4h]@1

  file_name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  if ( argc <= 0 )
  {
    PStringBase<char>::PStringBase<char>(&file_name, "#auto");
    CM_UI::SendNotice_LoadUI(&file_name);
    v4 = file_name.m_charbuffer;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please use @help loadautoui for proper usage.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = (PSRefBufferCharData<char> *)argc;
  }
  v5 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return 1;
}

//----- (005703B0) --------------------------------------------------------  // acclient.c:412521
char __thiscall ClientCommunicationSystem::DoLockUI(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  CPlayerSystem *v6; // eax@6
  CPlayerSystem *v7; // eax@7
  CPlayerSystem *v8; // eax@8

  v3 = this;
  if ( argc <= 0 )
  {
    if ( CPlayerSystem::GetPlayerSystem()
      && (v6 = CPlayerSystem::GetPlayerSystem(),
          (unsigned __int8)PlayerModule::LockUI((PlayerModule *)&v6->playerModule.vfptr)) )
    {
      v7 = CPlayerSystem::GetPlayerSystem();
      PlayerModule::SetLockUI((PlayerModule *)&v7->playerModule.vfptr, 0);
    }
    else
    {
      v8 = CPlayerSystem::GetPlayerSystem();
      PlayerModule::SetLockUI((PlayerModule *)&v8->playerModule.vfptr, 1);
    }
    UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 0xDu, 0);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please use @help lockui for proper usage.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  return 1;
}

//----- (00570450) --------------------------------------------------------  // acclient.c:412568
bool __thiscall ClientCommunicationSystem::DoHouseRecall(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  bool result; // al@5

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please see @help House for more information on how to use this command");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  else
  {
    result = CM_House::Event_TeleToHouse_Event();
  }
  return result;
}

//----- (005704B0) --------------------------------------------------------  // acclient.c:412602
bool __thiscall ClientCommunicationSystem::DoMansionRecall(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  bool result; // al@5

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please see @help House for more information on how to use this command");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  else
  {
    result = CM_House::Event_TeleToMansion_Event();
  }
  return result;
}

//----- (00570510) --------------------------------------------------------  // acclient.c:412636
char __thiscall ClientCommunicationSystem::DoHouseAvailableList(ClientCommunicationSystem *this, int argc, char **argv)
{
  PSRefBufferCharData<char> *v3; // ebp@1
  int v4; // eax@1
  char **v5; // esi@1
  bool v6; // bl@1
  unsigned int v7; // eax@5
  int v8; // eax@6
  char **v9; // esi@6
  bool v10; // bl@6
  int v11; // eax@11
  char **v12; // esi@11
  bool v13; // bl@11
  int v14; // eax@16
  char **v15; // esi@16
  bool v16; // bl@16
  bool v17; // bl@21
  int v18; // ebp@21
  PStringBase<char> command; // [sp+10h] [bp-8h]@1
  ClientSystem *v21; // [sp+14h] [bp-4h]@1

  v21 = (ClientSystem *)this;
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "apartment");
  v3 = command.m_charbuffer;
  v4 = __stricmp(command.m_charbuffer->m_data, (const char *)argv);
  v5 = argv - 5;
  v6 = v4 == 0;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v5 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
  if ( v6 )
  {
    v7 = 4;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "cottage");
    v8 = __stricmp(v3->m_data, (const char *)argv);
    v9 = argv - 5;
    v10 = v8 == 0;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v9 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v9)(v9, 1);
    if ( v10 )
    {
      v7 = 1;
    }
    else
    {
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "villa");
      v11 = __stricmp(v3->m_data, (const char *)argv);
      v12 = argv - 5;
      v13 = v11 == 0;
      if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v12 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v12)(v12, 1);
      if ( v13 )
      {
        v7 = 2;
      }
      else
      {
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "mansion");
        v14 = __stricmp(v3->m_data, (const char *)argv);
        v15 = argv - 5;
        v16 = v14 == 0;
        if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v15 )
          (*(void (__thiscall **)(_DWORD, _DWORD))*v15)(v15, 1);
        if ( !v16 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&argv,
            L"Please see @help hslist for more information on how to use this command");
          ClientSystem::AddTextToScroll(
            v21,
            (PStringBase<unsigned short> *)&argv,
            0x1Au,
            1,
            (unsigned int)v21[17].vfptr);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
          return 1;
        }
        v7 = 3;
      }
    }
  }
  v17 = CM_House::Event_ListAvailableHouses(v7);
  v18 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) )
  {
    if ( v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  }
  return v17;
}

//----- (005706F0) --------------------------------------------------------  // acclient.c:412732
char __thiscall ClientCommunicationSystem::DoDay(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char *v4; // esi@2
  CPlayerSystem *v5; // eax@5
  char result; // al@5
  char *v7; // esi@6
  CPlayerSystem *v8; // eax@9
  PStringBase<unsigned short> i_text; // [sp+0h] [bp-4h]@1

  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v3 = this;
  LScape::SetDay(LScape::m_fAlwaysDaylight == 0);
  if ( LScape::m_fAlwaysDaylight )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"Let there be light!");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
    v4 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetPersistentAtDay((PlayerModule *)&v5->playerModule.vfptr, 1);
    result = 1;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"Normality has been restored.");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
    v7 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetPersistentAtDay((PlayerModule *)&v8->playerModule.vfptr, 0);
    result = 1;
  }
  return result;
}
// 841798: using guessed type bool LScape::m_fAlwaysDaylight;

//----- (005707D0) --------------------------------------------------------  // acclient.c:412775
char __thiscall ClientCommunicationSystem::DoFrameRate(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // eax@1
  ClientCommunicationSystem *v4; // esi@1
  int v5; // esi@2

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Unexpected arguments to @framerate");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v4->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v4->m_idCurrentCommandSource);
    v5 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v5 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      return 1;
    }
  }
  else
  {
    fShowFramerate = fShowFramerate == 0;
    LOBYTE(v3) = fShowFramerate;
    CM_UI::SendNotice_SetFramerateDisplay(v3);
  }
  return 1;
}

//----- (00570850) --------------------------------------------------------  // acclient.c:412811
unsigned int __cdecl PSUtils::FindAllWords(PStringBase<char> str, PStringBase<char> separators, List<PStringBase<char> > *words)
{
  PSRefBufferCharData<char> *v3; // ebx@2
  unsigned int v4; // esi@4
  unsigned int v5; // eax@5
  char *v6; // esi@7
  char *v7; // esi@13
  PSRefBufferCharData<char> *v8; // edi@17
  char *v9; // esi@19
  char *v10; // esi@25
  char *v11; // esi@28
  char *v12; // esi@31
  unsigned int count; // [sp+20h] [bp-20h]@1
  PStringBase<char> word; // [sp+24h] [bp-1Ch]@2
  PStringBase<char> remainder; // [sp+28h] [bp-18h]@2
  PStringBase<char> oldcrap; // [sp+2Ch] [bp-14h]@2
  PStringBaseIter_Const<char> iter; // [sp+30h] [bp-10h]@1

  iter.pstring_ptr = &str;
  count = 0;
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.curr = 0;
  iter.mark = 0;
  while ( PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter.vfptr, &separators, 0) )
  {
    oldcrap.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    word.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    remainder.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBaseIter_Common<char>::Split((PStringBaseIter_Common<char> *)&iter.vfptr, &oldcrap, &word, &remainder);
    v3 = word.m_charbuffer;
    if ( *(_DWORD *)&word.m_charbuffer[-1].m_data[12] != 1 )
    {
      List<PStringBase<char>>::push_back(words, &word);
      ++count;
    }
    v4 = iter.curr + 1;
    if ( v4 <= iter.vfptr->GetStrLen(&iter) )
      v5 = v4;
    else
      v5 = iter.vfptr->GetStrLen(&iter);
    v6 = &remainder.m_charbuffer[-2].m_data[12];
    iter.curr = v5;
    iter.mark = v5;
    if ( !InterlockedDecrement((volatile LONG *)&remainder.m_charbuffer[-1]) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v3 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v3[-2].m_data[12])(&v3[-2].m_data[12], 1);
    v7 = &oldcrap.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldcrap.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  }
  remainder.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  word.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  oldcrap.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBaseIter_Common<char>::Split((PStringBaseIter_Common<char> *)&iter.vfptr, &remainder, &word, &oldcrap);
  v8 = word.m_charbuffer;
  if ( *(_DWORD *)&word.m_charbuffer[-1].m_data[12] != 1 )
  {
    List<PStringBase<char>>::push_back(words, &word);
    ++count;
  }
  v9 = &oldcrap.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&oldcrap.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v8 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&v8[-2].m_data[12])(&v8[-2].m_data[12], 1);
  v10 = &remainder.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&remainder.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  v11 = &str.m_charbuffer[-2].m_data[12];
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  v12 = &separators.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&separators.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  return count;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (00570AA0) --------------------------------------------------------  // acclient.c:412899
unsigned int __thiscall ClientCommunicationSystem::Release(ClientCommunicationSystem *this)
{
  ClientCommunicationSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    ClientCommunicationSystem::~ClientCommunicationSystem(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (00570AD0) --------------------------------------------------------  // acclient.c:412915
int __thiscall ChatPoseTable::InqChatPoseCommand(ChatPoseTable *this, AC1Legacy::PStringBase<char> *key, AC1Legacy::PStringBase<char> *command, AC1Legacy::PStringBase<char> *myEmote, AC1Legacy::PStringBase<char> *otherEmote)
{
  AC1Legacy::PSRefBuffer<char> *v5; // edi@1
  volatile LONG *v6; // esi@1
  volatile LONG *v7; // ST00_4@1
  ChatPoseTable *v8; // ebp@1
  AC1Legacy::PStringBase<char> *v9; // ebx@1
  AC1Legacy::PStringBase<char> *v10; // edi@5
  AC1Legacy::PSRefBuffer<char> *v11; // esi@5
  AC1Legacy::PSRefBuffer<char> *v12; // eax@9
  ChatEmoteData *v13; // esi@10
  int result; // eax@11

  v5 = key->m_buffer;
  v6 = (volatile LONG *)&key->m_buffer->m_cRef;
  v7 = (volatile LONG *)&key->m_buffer->m_cRef;
  v8 = this;
  key = (AC1Legacy::PStringBase<char> *)key->m_buffer;
  InterlockedIncrement(v7);
  v9 = PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::lookup(
         &v8->_chatPoseHash,
         (AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&key);
  if ( !InterlockedDecrement(v6) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  if ( !v9 )
    goto LABEL_15;
  v10 = command;
  v11 = command->m_buffer;
  if ( command->m_buffer != v9->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v11->m_cRef) )
    {
      if ( v11 )
        v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
    }
    v12 = v9->m_buffer;
    v10->m_buffer = v9->m_buffer;
    InterlockedIncrement((volatile LONG *)&v12->m_cRef);
  }
  v13 = PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::lookup(&v8->_chatEmoteHash, v10);
  if ( v13 )
  {
    AC1Legacy::PStringBase<unsigned short>::operator=(
      (AC1Legacy::PStringBase<unsigned short> *)myEmote,
      (AC1Legacy::PStringBase<unsigned short> *)&v13->myEmote);
    AC1Legacy::PStringBase<unsigned short>::operator=(
      (AC1Legacy::PStringBase<unsigned short> *)otherEmote,
      (AC1Legacy::PStringBase<unsigned short> *)&v13->otherEmote);
    result = 1;
  }
  else
  {
LABEL_15:
    result = 0;
  }
  return result;
}

//----- (00570B90) --------------------------------------------------------  // acclient.c:412974
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__ChannelBroadcast(ClientCommunicationSystem *this, unsigned int chanID, AC1Legacy::PStringBase<char> *senderName, AC1Legacy::PStringBase<char> *msg)
{
  unsigned int v4; // ebp@1
  AC1Legacy::PStringBase<char> *v5; // ebx@3
  AC1Legacy::PSRefBuffer<char> *v6; // eax@3
  signed int v7; // esi@9
  unsigned int v8; // ecx@9
  int v9; // eax@9
  int v10; // edi@11
  AC1Legacy::PStringBase<char> *v11; // ecx@14
  AC1Legacy::PSRefBuffer<char> *v12; // eax@14
  int v13; // edi@16
  PSRefBufferCharData<char> *v14; // eax@19
  int v15; // ecx@19
  int v16; // edi@21
  int v17; // eax@49
  AC1Legacy::PSRefBuffer<char> *v18; // eax@51
  int v19; // eax@53
  int v20; // eax@55
  int v21; // eax@57
  unsigned int v22; // ecx@64
  int v23; // eax@64
  int v24; // edi@66
  int v25; // edx@68
  AC1Legacy::PStringBase<char> *v26; // eax@70
  int v27; // ecx@70
  AC1Legacy::PSRefBuffer<char> *v28; // ecx@72
  int v29; // edi@74
  int v30; // edx@76
  int v31; // eax@77
  unsigned int v32; // edi@77
  bool v33; // bl@77
  int v34; // edx@79
  PStringBase<unsigned short> *v35; // eax@81
  unsigned int v36; // esi@81
  int v37; // edx@83
  char *v38; // esi@84
  int v39; // edx@86
  AC1Legacy::PSRefBuffer<char> *v40; // esi@87
  ReferenceCountTemplate<268435456,0>Vtbl *v41; // edx@89
  PStringBase<char> *v43; // [sp-10h] [bp-3Ch]@60
  const char *v44; // [sp-Ch] [bp-38h]@41
  int v45; // [sp-8h] [bp-34h]@41
  unsigned int v46; // [sp-4h] [bp-30h]@24
  PStringBase<char> txtmsg; // [sp+10h] [bp-1Ch]@3
  AC1Legacy::PStringBase<char> chanName; // [sp+14h] [bp-18h]@1
  PStringBase<char> v49; // [sp+18h] [bp-14h]@19
  PStringBase<char> rhs; // [sp+1Ch] [bp-10h]@31
  PStringBase<char> v51; // [sp+20h] [bp-Ch]@31
  PStringBase<char> v52; // [sp+24h] [bp-8h]@31
  ClientSystem *v53; // [sp+28h] [bp-4h]@1

  chanName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v53 = (ClientSystem *)this;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v4 = chanID;
  if ( !ChannelSystem::GetChannelName(chanID, &chanName) )
    AC1Legacy::PStringBase<char>::set(&chanName, "<unknown>");
  txtmsg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = senderName;
  v6 = senderName->m_buffer;
  if ( senderName->m_buffer->m_len == 1 )
  {
    if ( v4 > 0x4000 )
    {
      if ( v4 == 0x1000000 )
      {
        v46 = (unsigned int)v6->m_data;
        v7 = 10;
        PStringBase<char>::sprintf(&txtmsg, "[Co-Vassals] You say, \"", v6->m_data);
        goto LABEL_64;
      }
      if ( v4 == 0x2000000 )
      {
        v46 = (unsigned int)v6->m_data;
        v7 = 10;
        PStringBase<char>::sprintf(&txtmsg, "[Allegiance Broadcast] You say, \"", v6->m_data);
        goto LABEL_64;
      }
      if ( v4 == 0x4000000 )
      {
        v7 = 19;
        PStringBase<char>::set(&txtmsg, &name);
        goto LABEL_64;
      }
    }
    else
    {
      if ( v4 == 0x4000 )
        goto LABEL_93;
      if ( v4 == 2048 )
      {
        v46 = (unsigned int)v6->m_data;
        v7 = 19;
        PStringBase<char>::sprintf(&txtmsg, "[Fellowship] You say, \"", v6->m_data);
        goto LABEL_64;
      }
      if ( v4 == 4096 || v4 == 0x2000 )
      {
LABEL_93:
        v7 = 11;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&chanID, "You say to your ");
        v8 = chanID;
        v9 = *(_DWORD *)(chanID - 4);
        if ( v9 != 1 )
        {
          PStringBase<char>::append_n_chars(&txtmsg, (const char *)chanID, v9 - 1);
          v8 = chanID;
        }
        v10 = v8 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&senderName, chanName.m_buffer->m_data);
        v11 = senderName;
        v12 = senderName[-1].m_buffer;
        if ( v12 != (AC1Legacy::PSRefBuffer<char> *)1 )
        {
          PStringBase<char>::append_n_chars(&txtmsg, (const char *)senderName, (unsigned int)&v12[-1].m_data[3]);
          v11 = senderName;
        }
        v13 = (int)&v11[-5];
        if ( !InterlockedDecrement((volatile LONG *)&v11[-4]) && v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        PStringBase<char>::PStringBase<char>(&v49, ", \"");
        v14 = v49.m_charbuffer;
        v15 = *(_DWORD *)&v49.m_charbuffer[-1].m_data[12];
        if ( v15 != 1 )
        {
          PStringBase<char>::append_n_chars(&txtmsg, v49.m_charbuffer->m_data, v15 - 1);
          v14 = v49.m_charbuffer;
        }
        v16 = (int)&v14[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v14[-1]) && v16 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
        goto LABEL_64;
      }
    }
    if ( v4 == 1024 )
      v7 = 15;
    else
      v7 = v4 != 1 ? 9 : 14;
    PStringBase<char>::PStringBase<char>(&rhs, "You say on the ");
    PStringBase<char>::operator+=(&txtmsg, &rhs);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
    PStringBase<char>::PStringBase<char>(&v51, chanName.m_buffer->m_data);
    PStringBase<char>::operator+=(&txtmsg, &v51);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v51);
    PStringBase<char>::PStringBase<char>(&v52, " channel, \"");
    PStringBase<char>::operator+=(&txtmsg, &v52);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v52);
    goto LABEL_64;
  }
  if ( v4 <= 0x4000 )
  {
    if ( v4 == 0x4000 )
    {
      v46 = (unsigned int)v6->m_data;
      v7 = 10;
      PStringBase<char>::sprintf(&txtmsg, "Your follower <Tell:IIDString:0:%s>%s<\\Tell> says to you, \"", v6->m_data);
      v46 = (unsigned int)v5->m_buffer;
      InterlockedIncrement((volatile LONG *)(v46 + 4));
      gmCCommunicationSystem::SetLastAtMonarchUserName((AC1Legacy::PStringBase<char>)v46);
      goto LABEL_64;
    }
    if ( v4 == 2048 )
    {
      v46 = (unsigned int)v6->m_data;
      v7 = 19;
      PStringBase<char>::sprintf(
        &txtmsg,
        "[Fellowship] <Tell:IIDString:0:%s>%s<\\Tell> says, \"",
        v6->m_data,
        v6->m_data);
      goto LABEL_64;
    }
    if ( v4 != 4096 )
    {
      if ( v4 == 0x2000 )
      {
        v46 = (unsigned int)v6->m_data;
        v7 = 10;
        PStringBase<char>::sprintf(&txtmsg, "Your vassal <Tell:IIDString:0:%s>%s<\\Tell> says to you, \"", v6->m_data);
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v46, v5);
        gmCCommunicationSystem::SetLastAtPatronUserName((AC1Legacy::PStringBase<char>)v46);
        goto LABEL_64;
      }
      goto LABEL_46;
    }
    v46 = (unsigned int)v6->m_data;
    v45 = (int)v6->m_data;
    v44 = "Your patron <Tell:IIDString:0:%s>%s<\\Tell> says to you, \"";
    goto LABEL_62;
  }
  if ( v4 == 0x1000000 )
  {
    v46 = (unsigned int)v6->m_data;
    v45 = (int)v6->m_data;
    v44 = "[Co-Vassals] <Tell:IIDString:0:%s>%s<\\Tell> says, \"";
LABEL_62:
    v43 = &txtmsg;
    goto LABEL_63;
  }
  if ( v4 == 0x2000000 )
  {
    v46 = (unsigned int)v6->m_data;
    v45 = (int)v6->m_data;
    v44 = "[Allegiance Broadcast] <Tell:IIDString:0:%s>%s<\\Tell> says, \"";
    v43 = &txtmsg;
LABEL_63:
    v7 = 10;
    PStringBase<char>::sprintf(v43, v44, v45, v46);
    goto LABEL_64;
  }
LABEL_46:
  if ( v4 == 1024 )
    v7 = 15;
  else
    v7 = v4 != 1 ? 8 : 14;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&chanID, "<Tell:IIDString:0:%s>");
  v17 = *(_DWORD *)(chanID - 4);
  if ( v17 != 1 )
    PStringBase<char>::append_n_chars(&txtmsg, (const char *)chanID, v17 - 1);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&chanID);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&senderName, v5->m_buffer->m_data);
  v18 = senderName[-1].m_buffer;
  if ( v18 != (AC1Legacy::PSRefBuffer<char> *)1 )
    PStringBase<char>::append_n_chars(&txtmsg, (const char *)senderName, (unsigned int)&v18[-1].m_data[3]);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&senderName);
  PStringBase<char>::PStringBase<char>(&v52, "<\\Tell> says on the ");
  v19 = *(_DWORD *)&v52.m_charbuffer[-1].m_data[12];
  if ( v19 != 1 )
    PStringBase<char>::append_n_chars(&txtmsg, v52.m_charbuffer->m_data, v19 - 1);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v52);
  PStringBase<char>::PStringBase<char>(&v51, chanName.m_buffer->m_data);
  v20 = *(_DWORD *)&v51.m_charbuffer[-1].m_data[12];
  if ( v20 != 1 )
    PStringBase<char>::append_n_chars(&txtmsg, v51.m_charbuffer->m_data, v20 - 1);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v51);
  PStringBase<char>::PStringBase<char>(&rhs, " channel, \"");
  v21 = *(_DWORD *)&rhs.m_charbuffer[-1].m_data[12];
  if ( v21 != 1 )
    PStringBase<char>::append_n_chars(&txtmsg, rhs.m_charbuffer->m_data, v21 - 1);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
LABEL_64:
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&chanID, msg->m_buffer->m_data);
  v22 = chanID;
  v23 = *(_DWORD *)(chanID - 4);
  if ( v23 != 1 )
  {
    PStringBase<char>::append_n_chars(&txtmsg, (const char *)chanID, v23 - 1);
    v22 = chanID;
  }
  v24 = v22 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v22 - 20 + 4)) && v24 )
  {
    v25 = *(_DWORD *)v24;
    v46 = 1;
    (*(void (__thiscall **)(int, signed int))v25)(v24, 1);
  }
  if ( v4 == 0x4000000 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&senderName, "\n");
    v26 = senderName;
    v28 = senderName[-1].m_buffer;
    if ( v28 != (AC1Legacy::PSRefBuffer<char> *)1 )
    {
      PStringBase<char>::append_n_chars(&txtmsg, (const char *)senderName, (unsigned int)&v28[-1].m_data[3]);
      v26 = senderName;
    }
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&chanID, "\"\n");
    v26 = (AC1Legacy::PStringBase<char> *)chanID;
    v27 = *(_DWORD *)(chanID - 4);
    if ( v27 != 1 )
    {
      PStringBase<char>::append_n_chars(&txtmsg, (const char *)chanID, v27 - 1);
      v26 = (AC1Legacy::PStringBase<char> *)chanID;
    }
  }
  v29 = (int)&v26[-5];
  if ( !InterlockedDecrement((volatile LONG *)&v26[-4]) && v29 )
  {
    v30 = *(_DWORD *)v29;
    v46 = 1;
    (*(void (__thiscall **)(int, signed int))v30)(v29, 1);
  }
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&chanID, &name);
  v31 = gmCCommunicationSystem::IsSquelched(0, (AC1Legacy::PStringBase<char> *)&chanID, v7);
  v32 = chanID;
  v33 = v31 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(chanID + 4)) && v32 )
  {
    v34 = *(_DWORD *)v32;
    v46 = 1;
    (*(void (__thiscall **)(unsigned int, signed int))v34)(v32, 1);
  }
  if ( v33 )
  {
    v46 = 0;
    v35 = PStringBase<char>::to_wpstring(&txtmsg, (PStringBase<unsigned short> *)&chanID, 0);
    ClientSystem::AddTextToScroll(v53, v35, v7, 1, v46);
    v36 = chanID - 20;
    if ( !InterlockedDecrement((volatile LONG *)(chanID - 20 + 4)) )
    {
      if ( v36 )
      {
        v37 = *(_DWORD *)v36;
        v46 = 1;
        (*(void (__thiscall **)(unsigned int, signed int))v37)(v36, 1);
      }
    }
  }
  v38 = &txtmsg.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&txtmsg.m_charbuffer[-1]) && v38 )
  {
    v39 = *(_DWORD *)v38;
    v46 = 1;
    (*(void (__thiscall **)(char *, signed int))v39)(v38, 1);
  }
  v40 = chanName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&chanName.m_buffer->m_cRef) && v40 )
  {
    v41 = v40->vfptr;
    v46 = 1;
    v41->__vecDelDtor(v40, 1);
  }
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005711D0) --------------------------------------------------------  // acclient.c:413308
unsigned int __thiscall ClientCommunicationSystem::Handle_Character__QueryAgeResponse(ClientCommunicationSystem *this, AC1Legacy::PStringBase<char> *targetName, AC1Legacy::PStringBase<char> *age)
{
  ClientSystem *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // edx@1
  PStringBase<unsigned short> *v5; // eax@4
  AC1Legacy::PStringBase<char> *v6; // esi@4
  char *v7; // esi@7
  PStringBase<char> spew; // [sp+4h] [bp-4h]@1

  spew.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = (ClientSystem *)this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v4 = age->m_buffer;
  if ( targetName->m_buffer->m_len == 1 )
    PStringBase<char>::sprintf(&spew, "You have played for %s.\n", v4->m_data);
  else
    PStringBase<char>::sprintf(&spew, "%s has played for %s.\n", targetName->m_buffer->m_data, v4->m_data);
  v5 = PStringBase<char>::to_wpstring(&spew, (PStringBase<unsigned short> *)&age, 0);
  ClientSystem::AddTextToScroll(v3, v5, 0, 1, 0);
  v6 = age - 5;
  if ( !InterlockedDecrement((volatile LONG *)&age[-4]) && v6 )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v6->m_buffer->vfptr)(v6, 1);
  v7 = &spew.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&spew.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  return 0;
}

//----- (005712A0) --------------------------------------------------------  // acclient.c:413337
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__HearSpeech(ClientCommunicationSystem *this, AC1Legacy::PStringBase<char> *msg, AC1Legacy::PStringBase<char> *name, unsigned int sender_id, unsigned int ltt)
{
  ClientSystem *v5; // ebx@1
  CPhysicsObj *v6; // ecx@1
  signed int v7; // ebp@1
  unsigned int v8; // edi@2
  unsigned int v9; // eax@4
  PlayerDesc *v11; // eax@10
  AC1Legacy::PStringBase<char> *v12; // edi@10
  bool v13; // bl@10
  char *v14; // ecx@10
  int v15; // ebx@12
  int v16; // ebp@15
  bool v17; // bl@16
  char *v18; // ecx@16
  InterfacePtr<Interface> *v19; // eax@19
  PlayerDesc *v20; // esi@21
  AC1Legacy::PStringBase<char> *v21; // eax@26
  char *v22; // esi@36
  int v23; // edx@38
  char *v24; // [sp-4h] [bp-38h]@10
  PStringBase<char> txt; // [sp+10h] [bp-24h]@3
  AC1Legacy::PStringBase<char> modified_msg; // [sp+14h] [bp-20h]@10
  AC1Legacy::PStringBase<char> str; // [sp+18h] [bp-1Ch]@10
  InterfacePtr<Interface> sender_is_Olthoi; // [sp+1Ch] [bp-18h]@10
  int no_olthoi_talk; // [sp+24h] [bp-10h]@19
  InterfacePtr<PlayerDesc> spPD; // [sp+28h] [bp-Ch]@10
  ClientSystem *v31; // [sp+30h] [bp-4h]@1

  v5 = (ClientSystem *)this;
  v6 = SmartBox::smartbox->player;
  v7 = 0;
  v31 = v5;
  if ( v6 )
  {
    v8 = sender_id;
    if ( sender_id )
    {
      txt.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      if ( SmartBox::smartbox )
        v9 = SmartBox::smartbox->player_id;
      else
        v9 = 0;
      if ( v8 == v9 )
      {
        PStringBase<char>::sprintf(&txt, "You say, \"%s\"\n", msg->m_buffer->m_data);
        ClientSystem::AddTextToScroll(v5, &txt, ltt, 1, 0);
LABEL_36:
        v22 = &txt.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&txt.m_charbuffer[-1]) )
        {
          if ( v22 )
          {
            v23 = *(_DWORD *)v22;
            v24 = (char *)1;
            (*(void (__thiscall **)(char *, signed int))v23)(v22, 1);
          }
        }
        return 0;
      }
      if ( !gmCCommunicationSystem::CanHear(v8, ltt) )
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&txt);
        return 0;
      }
      sender_is_Olthoi.m_pInterface = 0;
      v11 = (PlayerDesc *)CPlayerSystem::IsOlthoi();
      v12 = (AC1Legacy::PStringBase<char> *)name->m_buffer;
      v24 = (char *)&name->m_buffer->m_cRef;
      spPD.m_pInterface = v11;
      name = v12;
      InterlockedIncrement((volatile LONG *)v24);
      modified_msg.m_buffer = msg->m_buffer;
      InterlockedIncrement((volatile LONG *)&modified_msg.m_buffer->m_cRef);
      AC1Legacy::PStringBase<char>::PStringBase<char>(&str, "^");
      v13 = AC1Legacy::PStringBase<char>::find_substring((AC1Legacy::PStringBase<char> *)&name, &str) >= 0;
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&str);
      if ( v13 )
      {
        v24 = v14;
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v24, "^");
        AC1Legacy::PStringBase<char>::trim(
          (AC1Legacy::PStringBase<char> *)&name,
          0,
          1,
          (AC1Legacy::PStringBase<char>)v24);
        v12 = name;
        v7 = 1;
      }
      else
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(&str, "&");
        v17 = AC1Legacy::PStringBase<char>::find_substring((AC1Legacy::PStringBase<char> *)&name, &str) >= 0;
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&str);
        if ( v17 )
        {
          v24 = v18;
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v24, "&");
          AC1Legacy::PStringBase<char>::trim(
            (AC1Legacy::PStringBase<char> *)&name,
            0,
            1,
            (AC1Legacy::PStringBase<char>)v24);
          v12 = name;
          v15 = 1;
LABEL_13:
          v16 = v15 != (_DWORD)spPD.m_pInterface && !v7;
          no_olthoi_talk = 0;
          v19 = GetClassObject(&sender_is_Olthoi, &PlayerDesc_ClassType_30);
          InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&spPD, v19);
          if ( (_DWORD)sender_is_Olthoi.m_pInterface )
            ((void (*)(void))sender_is_Olthoi.m_pInterface->vfptr->Release)();
          v20 = spPD.m_pInterface;
          if ( (_DWORD)spPD.m_pInterface
            && (spPD.m_trStatus.m_val & 0x80000000) == 0
            && (CBaseQualities::InqBool((CBaseQualities *)&spPD.m_pInterface->vfptr, 0x81u, &no_olthoi_talk),
                no_olthoi_talk)
            || !v16 )
          {
            if ( sender_id < 0x50000001 || sender_id > 0x6FFFFFFF )
            {
              v24 = msg->m_buffer->m_data;
              PStringBase<char>::sprintf(&txt, "%s says, \"%s\"\n", &v12[5], v24);
            }
            else
            {
              v24 = msg->m_buffer->m_data;
              PStringBase<char>::sprintf(
                &txt,
                "<Tell:IIDString:%d:%s>%s<\\Tell> says, \"%s\"\n",
                sender_id,
                &v12[5],
                &v12[5],
                v24);
            }
          }
          else
          {
            if ( v15 )
              v21 = GetRandomOlthoiText((AC1Legacy::PStringBase<char> *)&msg);
            else
              v21 = GetRandomHumanText((AC1Legacy::PStringBase<char> *)&msg);
            AC1Legacy::PStringBase<unsigned short>::operator=(
              (AC1Legacy::PStringBase<unsigned short> *)&modified_msg,
              (AC1Legacy::PStringBase<unsigned short> *)v21);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&msg);
            v24 = modified_msg.m_buffer->m_data;
            PStringBase<char>::sprintf(&txt, "%s %s\n", &v12[5], modified_msg.m_buffer->m_data);
          }
          ClientSystem::AddTextToScroll(v31, &txt, ltt, 1, 0);
          if ( v20 )
            v20->vfptr->Release((Interface *)v20);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&modified_msg);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
          goto LABEL_36;
        }
      }
      v15 = (signed int)sender_is_Olthoi.m_pInterface;
      goto LABEL_13;
    }
  }
  return 0;
}

//----- (005715A0) --------------------------------------------------------  // acclient.c:413503
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__HearDirectSpeech(ClientCommunicationSystem *this, AC1Legacy::PStringBase<char> *msg, AC1Legacy::PStringBase<char> *name, unsigned int sender_id, unsigned int target_id, unsigned int ltt, unsigned int secretFlags)
{
  ClientSystem *v7; // edi@1
  CPhysicsObj *v8; // ecx@1
  signed int v9; // ebp@1
  LONG (__stdcall *v10)(volatile LONG *); // ebx@3
  int v11; // eax@4
  void *v12; // edi@4
  AC1Legacy::PSRefBuffer<char> *v13; // esi@4
  char *v14; // eax@4
  int v15; // eax@5
  bool v16; // bl@7
  int v17; // ecx@7
  int v18; // eax@12
  AC1Legacy::PSRefBuffer<char> *v19; // esi@12
  bool v20; // bl@12
  int v21; // ecx@12
  int v22; // ebp@19
  InterfaceSystem *v23; // eax@21
  AC1Legacy::PStringBase<char> *v24; // esi@21
  int v25; // ebx@23
  AC1Legacy::PStringBase<char> *v26; // eax@30
  AC1Legacy::PSRefBuffer<char> *v27; // esi@32
  unsigned int v28; // eax@34
  unsigned int v29; // ebx@37
  const char *v30; // esi@39
  ReferenceCountTemplate<268435456,0>Vtbl *v31; // edx@50
  AC1Legacy::PStringBase<char> v32; // edx@53
  char *v33; // esi@54
  int v34; // edx@56
  int v36; // [sp-8h] [bp-3Ch]@21
  int v37; // [sp-4h] [bp-38h]@4
  AC1Legacy::PStringBase<char> modified_msg; // [sp+10h] [bp-24h]@4
  PStringBase<char> txt; // [sp+14h] [bp-20h]@2
  int sender_is_Olthoi; // [sp+18h] [bp-1Ch]@4
  AC1Legacy::PStringBase<char> str; // [sp+1Ch] [bp-18h]@4
  int no_olthoi_talk; // [sp+20h] [bp-14h]@21
  ClientSystem *v43; // [sp+24h] [bp-10h]@1
  int player_is_Olthoi; // [sp+28h] [bp-Ch]@4
  InterfacePtr<PlayerDesc> spPD; // [sp+2Ch] [bp-8h]@21

  v7 = (ClientSystem *)this;
  v8 = SmartBox::smartbox->player;
  v9 = 0;
  v43 = v7;
  if ( v8 )
  {
    txt.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( sender_id == target_id )
    {
      PStringBase<char>::sprintf(&txt, "You think, \"%s\"\n", msg->m_buffer->m_data);
      ClientSystem::AddTextToScroll(v7, &txt, ltt, 1, 0);
      v10 = InterlockedDecrement;
    }
    else
    {
      sender_is_Olthoi = 0;
      v11 = CPlayerSystem::IsOlthoi();
      v12 = name->m_buffer;
      v37 = (int)&name->m_buffer->m_cRef;
      player_is_Olthoi = v11;
      name = (AC1Legacy::PStringBase<char> *)v12;
      InterlockedIncrement((volatile LONG *)v37);
      modified_msg.m_buffer = msg->m_buffer;
      InterlockedIncrement((volatile LONG *)&modified_msg.m_buffer->m_cRef);
      AC1Legacy::PStringBase<char>::PStringBase<char>(&str, "^");
      v13 = str.m_buffer;
      v14 = _strstr((const char *)v12 + 20, str.m_buffer->m_data);
      if ( v14 )
        v15 = v14 - (_BYTE *)v12 - 20;
      else
        v15 = -1;
      v16 = v15 >= 0;
      if ( !InterlockedDecrement((volatile LONG *)&v13->m_cRef) && v13 )
        v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
      if ( v16 )
      {
        v37 = v17;
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v37, "^");
        AC1Legacy::PStringBase<char>::trim(
          (AC1Legacy::PStringBase<char> *)&name,
          0,
          1,
          (AC1Legacy::PStringBase<char>)v37);
        v12 = name;
        v9 = 1;
      }
      else
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(&str, "&");
        v18 = AC1Legacy::PStringBase<char>::find_substring((AC1Legacy::PStringBase<char> *)&name, &str);
        v19 = str.m_buffer;
        v20 = v18 >= 0;
        if ( !InterlockedDecrement((volatile LONG *)&str.m_buffer->m_cRef) && v19 )
          v19->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v19, 1u);
        if ( v20 )
        {
          v37 = v21;
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v37, "&");
          AC1Legacy::PStringBase<char>::trim(
            (AC1Legacy::PStringBase<char> *)&name,
            0,
            1,
            (AC1Legacy::PStringBase<char>)v37);
          v12 = name;
          sender_is_Olthoi = 1;
        }
      }
      v22 = sender_is_Olthoi != player_is_Olthoi && !v9;
      v37 = (int)&name;
      no_olthoi_talk = 0;
      name = 0;
      v23 = InterfaceSystem::GetInstance();
      InterfaceSystem::GetClass(v23, (TResult *)&player_is_Olthoi, &PlayerDesc_ClassType_30, (Interface **)v37);
      v24 = name;
      v36 = (int)name;
      v37 = 0;
      spPD.m_pInterface = 0;
      spPD.m_trStatus.m_val = 0;
      if ( name )
        ((void (__thiscall *)(AC1Legacy::PStringBase<char> *))name->m_buffer->m_hash)(name);
      v25 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&str, v36, v37);
      if ( v24 )
        (*(void (__thiscall **)(AC1Legacy::PStringBase<char> *))&v24->m_buffer->m_data[0])(v24);
      if ( (_DWORD)spPD.m_pInterface
        && v25 >= 0
        && (CBaseQualities::InqBool((CBaseQualities *)&spPD.m_pInterface->vfptr, 0x81u, &no_olthoi_talk), no_olthoi_talk)
        || !v22 )
      {
        if ( SmartBox::smartbox )
          v28 = SmartBox::smartbox->player_id;
        else
          v28 = 0;
        if ( target_id == v28 )
        {
          target_id = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          v29 = sender_id;
          if ( sender_id < 0x50000001 || sender_id > 0x6FFFFFFF )
          {
            v37 = (int)msg->m_buffer->m_data;
            v30 = (char *)v12 + 20;
            PStringBase<char>::sprintf((PStringBase<char> *)&target_id, "%s tells you, \"%s\"\n", (char *)v12 + 20, v37);
          }
          else
          {
            v37 = (int)msg->m_buffer->m_data;
            v30 = (char *)v12 + 20;
            PStringBase<char>::sprintf(
              (PStringBase<char> *)&target_id,
              "<Tell:IIDString:%d:%s>%s<\\Tell> tells you, \"%s\"\n",
              sender_id,
              (char *)v12 + 20,
              (char *)v12 + 20,
              v37);
          }
          ClientSystem::AddTextToScroll(v43, (PStringBase<char> *)&target_id, ltt, 1, 0);
          if ( v29 >= 0x50000001 && v29 <= 0x6FFFFFFF )
          {
            gmCCommunicationSystem::SetLastTeller(v29);
            PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, v30);
            gmCCommunicationSystem::SetLastTellerName((PStringBase<char> *)&msg);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&msg);
          }
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&target_id);
        }
        v27 = modified_msg.m_buffer;
      }
      else
      {
        if ( sender_is_Olthoi )
          v26 = GetRandomOlthoiText((AC1Legacy::PStringBase<char> *)&msg);
        else
          v26 = GetRandomHumanText((AC1Legacy::PStringBase<char> *)&msg);
        AC1Legacy::PStringBase<unsigned short>::operator=(
          (AC1Legacy::PStringBase<unsigned short> *)&modified_msg,
          (AC1Legacy::PStringBase<unsigned short> *)v26);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&msg);
        v27 = modified_msg.m_buffer;
        v37 = (int)modified_msg.m_buffer->m_data;
        PStringBase<char>::sprintf(&txt, "%s %s\n", (char *)v12 + 20, modified_msg.m_buffer->m_data);
        ClientSystem::AddTextToScroll(v43, &txt, ltt, 1, 0);
      }
      if ( (_DWORD)spPD.m_pInterface )
        ((void (*)(void))spPD.m_pInterface->vfptr->Release)();
      v10 = InterlockedDecrement;
      if ( !InterlockedDecrement((volatile LONG *)&v27->m_cRef) && v27 )
      {
        v31 = v27->vfptr;
        v37 = 1;
        v31->__vecDelDtor(v27, 1);
      }
      if ( !InterlockedDecrement((volatile LONG *)v12 + 1) && v12 )
      {
        v32.m_buffer = *(AC1Legacy::PSRefBuffer<char> **)v12;
        v37 = 1;
        ((void (__thiscall *)(void *, signed int))v32.m_buffer->vfptr)(v12, 1);
      }
    }
    v33 = &txt.m_charbuffer[-2].m_data[12];
    if ( !v10((volatile LONG *)&txt.m_charbuffer[-1]) && v33 )
    {
      v34 = *(_DWORD *)v33;
      v37 = 1;
      (*(void (__thiscall **)(char *, signed int))v34)(v33, 1);
    }
  }
  return 0;
}

//----- (00571990) --------------------------------------------------------  // acclient.c:413715
void __thiscall ClientCommunicationSystem::HandleFailureEvent(ClientCommunicationSystem *this, unsigned int etype, PStringBase<unsigned short> *user_data)
{
  char v3; // bl@1
  ClientSystem *v4; // esi@1
  ClientCombatSystem *v5; // eax@9
  ClientCombatSystem *v6; // eax@10
  PStringBase<unsigned short> *v7; // ecx@20
  ClientUISystem *v8; // eax@24
  PSRefBufferCharData<unsigned short> *v9; // eax@170
  PSRefBufferCharData<unsigned short> **v10; // eax@171
  PSRefBufferCharData<unsigned short> *v11; // eax@175
  const unsigned __int16 *v12; // eax@198
  const unsigned __int16 *v13; // eax@307
  PStringBase<unsigned short> *v14; // eax@308
  PStringBase<unsigned short> *v15; // eax@308
  const unsigned __int16 *v16; // eax@308
  const unsigned __int16 *v17; // eax@309
  const unsigned __int16 *v18; // eax@312
  const unsigned __int16 *v19; // eax@313
  const unsigned __int16 *v20; // eax@314
  const unsigned __int16 *v21; // eax@317
  IACPlugin *v22; // eax@355
  char *v23; // esi@377
  PStringBase<unsigned short> msg; // [sp+Ch] [bp-3CCh]@1
  PStringBase<unsigned short> v25; // [sp+10h] [bp-3C8h]@168
  PStringBase<unsigned short> v26; // [sp+14h] [bp-3C4h]@169
  PStringBase<unsigned short> v27; // [sp+18h] [bp-3C0h]@21
  PStringBase<unsigned short> v28; // [sp+1Ch] [bp-3BCh]@179
  PStringBase<unsigned short> v29; // [sp+20h] [bp-3B8h]@23
  PStringBase<unsigned short> v30; // [sp+24h] [bp-3B4h]@180
  PStringBase<unsigned short> v31; // [sp+28h] [bp-3B0h]@25
  PStringBase<unsigned short> v32; // [sp+2Ch] [bp-3ACh]@181
  PStringBase<unsigned short> v33; // [sp+30h] [bp-3A8h]@27
  PStringBase<unsigned short> v34; // [sp+34h] [bp-3A4h]@182
  PStringBase<unsigned short> v35; // [sp+38h] [bp-3A0h]@29
  PStringBase<unsigned short> v36; // [sp+3Ch] [bp-39Ch]@183
  PStringBase<unsigned short> v37; // [sp+40h] [bp-398h]@31
  PStringBase<unsigned short> v38; // [sp+44h] [bp-394h]@186
  PStringBase<unsigned short> v39; // [sp+48h] [bp-390h]@33
  PStringBase<unsigned short> v40; // [sp+4Ch] [bp-38Ch]@197
  PStringBase<unsigned short> v41; // [sp+50h] [bp-388h]@50
  PStringBase<unsigned short> v42; // [sp+54h] [bp-384h]@198
  PStringBase<unsigned short> v43; // [sp+58h] [bp-380h]@53
  PStringBase<unsigned short> v44; // [sp+5Ch] [bp-37Ch]@199
  PStringBase<unsigned short> v45; // [sp+60h] [bp-378h]@55
  PStringBase<unsigned short> v46; // [sp+64h] [bp-374h]@200
  PStringBase<unsigned short> v47; // [sp+68h] [bp-370h]@57
  PStringBase<unsigned short> v48; // [sp+6Ch] [bp-36Ch]@203
  PStringBase<unsigned short> v49; // [sp+70h] [bp-368h]@59
  PStringBase<unsigned short> v50; // [sp+74h] [bp-364h]@204
  PStringBase<unsigned short> v51; // [sp+78h] [bp-360h]@61
  PStringBase<unsigned short> v52; // [sp+7Ch] [bp-35Ch]@205
  PStringBase<unsigned short> v53; // [sp+80h] [bp-358h]@63
  PStringBase<unsigned short> v54; // [sp+84h] [bp-354h]@214
  PStringBase<unsigned short> v55; // [sp+88h] [bp-350h]@65
  PStringBase<unsigned short> v56; // [sp+8Ch] [bp-34Ch]@215
  PStringBase<unsigned short> v57; // [sp+90h] [bp-348h]@68
  PStringBase<unsigned short> v58; // [sp+94h] [bp-344h]@216
  PStringBase<unsigned short> v59; // [sp+98h] [bp-340h]@70
  PStringBase<unsigned short> v60; // [sp+9Ch] [bp-33Ch]@217
  PStringBase<unsigned short> v61; // [sp+A0h] [bp-338h]@72
  PStringBase<unsigned short> v62; // [sp+A4h] [bp-334h]@218
  PStringBase<unsigned short> v63; // [sp+A8h] [bp-330h]@74
  PStringBase<unsigned short> v64; // [sp+ACh] [bp-32Ch]@219
  PStringBase<unsigned short> v65; // [sp+B0h] [bp-328h]@76
  PStringBase<unsigned short> v66; // [sp+B4h] [bp-324h]@220
  PStringBase<unsigned short> v67; // [sp+B8h] [bp-320h]@78
  PStringBase<unsigned short> v68; // [sp+BCh] [bp-31Ch]@221
  PStringBase<unsigned short> v69; // [sp+C0h] [bp-318h]@80
  PStringBase<unsigned short> v70; // [sp+C4h] [bp-314h]@222
  PStringBase<unsigned short> v71; // [sp+C8h] [bp-310h]@82
  PStringBase<unsigned short> v72; // [sp+CCh] [bp-30Ch]@225
  PStringBase<unsigned short> v73; // [sp+D0h] [bp-308h]@86
  PStringBase<unsigned short> v74; // [sp+D4h] [bp-304h]@227
  PStringBase<unsigned short> v75; // [sp+D8h] [bp-300h]@88
  PStringBase<unsigned short> v76; // [sp+DCh] [bp-2FCh]@228
  PStringBase<unsigned short> v77; // [sp+E0h] [bp-2F8h]@90
  PStringBase<unsigned short> v78; // [sp+E4h] [bp-2F4h]@229
  PStringBase<unsigned short> v79; // [sp+E8h] [bp-2F0h]@92
  PStringBase<unsigned short> v80; // [sp+ECh] [bp-2ECh]@230
  PStringBase<unsigned short> v81; // [sp+F0h] [bp-2E8h]@94
  PStringBase<unsigned short> v82; // [sp+F4h] [bp-2E4h]@231
  PStringBase<unsigned short> v83; // [sp+F8h] [bp-2E0h]@96
  PStringBase<unsigned short> v84; // [sp+FCh] [bp-2DCh]@234
  PStringBase<unsigned short> v85; // [sp+100h] [bp-2D8h]@98
  PStringBase<unsigned short> v86; // [sp+104h] [bp-2D4h]@235
  PStringBase<unsigned short> v87; // [sp+108h] [bp-2D0h]@100
  PStringBase<unsigned short> v88; // [sp+10Ch] [bp-2CCh]@241
  PStringBase<unsigned short> v89; // [sp+110h] [bp-2C8h]@102
  PStringBase<unsigned short> v90; // [sp+114h] [bp-2C4h]@244
  PStringBase<unsigned short> v91; // [sp+118h] [bp-2C0h]@104
  PStringBase<unsigned short> v92; // [sp+11Ch] [bp-2BCh]@245
  PStringBase<unsigned short> v93; // [sp+120h] [bp-2B8h]@108
  PStringBase<unsigned short> v94; // [sp+124h] [bp-2B4h]@248
  PStringBase<unsigned short> v95; // [sp+128h] [bp-2B0h]@111
  PStringBase<unsigned short> v96; // [sp+12Ch] [bp-2ACh]@251
  PStringBase<unsigned short> v97; // [sp+130h] [bp-2A8h]@113
  PStringBase<unsigned short> v98; // [sp+134h] [bp-2A4h]@254
  PStringBase<unsigned short> v99; // [sp+138h] [bp-2A0h]@115
  PStringBase<unsigned short> v100; // [sp+13Ch] [bp-29Ch]@255
  PStringBase<unsigned short> v101; // [sp+140h] [bp-298h]@117
  PStringBase<unsigned short> v102; // [sp+144h] [bp-294h]@258
  PStringBase<unsigned short> v103; // [sp+148h] [bp-290h]@119
  PStringBase<unsigned short> v104; // [sp+14Ch] [bp-28Ch]@261
  PStringBase<unsigned short> v105; // [sp+150h] [bp-288h]@121
  PStringBase<unsigned short> v106; // [sp+154h] [bp-284h]@267
  PStringBase<unsigned short> v107; // [sp+158h] [bp-280h]@123
  PStringBase<unsigned short> v108; // [sp+15Ch] [bp-27Ch]@267
  PStringBase<unsigned short> v109; // [sp+160h] [bp-278h]@126
  PStringBase<unsigned short> v110; // [sp+164h] [bp-274h]@281
  PStringBase<unsigned short> v111; // [sp+168h] [bp-270h]@132
  PStringBase<unsigned short> v112; // [sp+16Ch] [bp-26Ch]@284
  PStringBase<unsigned short> v113; // [sp+170h] [bp-268h]@134
  PStringBase<unsigned short> v114; // [sp+174h] [bp-264h]@285
  PStringBase<unsigned short> v115; // [sp+178h] [bp-260h]@136
  PStringBase<unsigned short> v116; // [sp+17Ch] [bp-25Ch]@291
  PStringBase<unsigned short> v117; // [sp+180h] [bp-258h]@138
  PStringBase<unsigned short> v118; // [sp+184h] [bp-254h]@294
  PStringBase<unsigned short> v119; // [sp+188h] [bp-250h]@140
  PStringBase<unsigned short> v120; // [sp+18Ch] [bp-24Ch]@295
  PStringBase<unsigned short> v121; // [sp+190h] [bp-248h]@142
  PStringBase<unsigned short> v122; // [sp+194h] [bp-244h]@296
  PStringBase<unsigned short> v123; // [sp+198h] [bp-240h]@144
  PStringBase<unsigned short> v124; // [sp+19Ch] [bp-23Ch]@297
  PStringBase<unsigned short> v125; // [sp+1A0h] [bp-238h]@146
  PStringBase<unsigned short> v126; // [sp+1A4h] [bp-234h]@298
  PStringBase<unsigned short> v127; // [sp+1A8h] [bp-230h]@148
  PStringBase<unsigned short> v128; // [sp+1ACh] [bp-22Ch]@299
  PStringBase<unsigned short> v129; // [sp+1B0h] [bp-228h]@150
  PStringBase<unsigned short> v130; // [sp+1B4h] [bp-224h]@300
  PStringBase<unsigned short> v131; // [sp+1B8h] [bp-220h]@152
  PStringBase<unsigned short> v132; // [sp+1BCh] [bp-21Ch]@301
  PStringBase<unsigned short> v133; // [sp+1C0h] [bp-218h]@154
  PStringBase<unsigned short> v134; // [sp+1C4h] [bp-214h]@302
  PStringBase<unsigned short> v135; // [sp+1C8h] [bp-210h]@156
  PStringBase<unsigned short> v136; // [sp+1CCh] [bp-20Ch]@303
  PStringBase<unsigned short> v137; // [sp+1D0h] [bp-208h]@158
  PStringBase<unsigned short> v138; // [sp+1D4h] [bp-204h]@307
  PStringBase<unsigned short> v139; // [sp+1D8h] [bp-200h]@160
  PStringBase<unsigned short> v140; // [sp+1DCh] [bp-1FCh]@308
  PStringBase<unsigned short> v141; // [sp+1E0h] [bp-1F8h]@162
  PStringBase<unsigned short> v142; // [sp+1E4h] [bp-1F4h]@308
  PStringBase<unsigned short> v143; // [sp+1E8h] [bp-1F0h]@165
  PStringBase<unsigned short> v144; // [sp+1ECh] [bp-1ECh]@309
  PStringBase<unsigned short> v145; // [sp+1F0h] [bp-1E8h]@167
  PStringBase<unsigned short> v146; // [sp+1F4h] [bp-1E4h]@310
  PStringBase<unsigned short> v147; // [sp+1F8h] [bp-1E0h]@22
  PStringBase<unsigned short> v148; // [sp+1FCh] [bp-1DCh]@311
  PStringBase<unsigned short> v149; // [sp+200h] [bp-1D8h]@26
  PStringBase<unsigned short> v150; // [sp+204h] [bp-1D4h]@312
  PStringBase<unsigned short> v151; // [sp+208h] [bp-1D0h]@30
  PStringBase<unsigned short> v152; // [sp+20Ch] [bp-1CCh]@313
  PStringBase<unsigned short> v153; // [sp+210h] [bp-1C8h]@35
  PStringBase<unsigned short> v154; // [sp+214h] [bp-1C4h]@314
  PStringBase<unsigned short> v155; // [sp+218h] [bp-1C0h]@54
  PStringBase<unsigned short> v156; // [sp+21Ch] [bp-1BCh]@316
  PStringBase<unsigned short> v157; // [sp+220h] [bp-1B8h]@58
  PStringBase<unsigned short> v158; // [sp+224h] [bp-1B4h]@317
  PStringBase<unsigned short> v159; // [sp+228h] [bp-1B0h]@62
  PStringBase<unsigned short> v160; // [sp+22Ch] [bp-1ACh]@318
  PStringBase<unsigned short> v161; // [sp+230h] [bp-1A8h]@66
  PStringBase<unsigned short> errorText; // [sp+234h] [bp-1A4h]@319
  PStringBase<unsigned short> v163; // [sp+238h] [bp-1A0h]@71
  PStringBase<unsigned short> v164; // [sp+23Ch] [bp-19Ch]@320
  PStringBase<unsigned short> v165; // [sp+240h] [bp-198h]@75
  PStringBase<unsigned short> v166; // [sp+244h] [bp-194h]@321
  PStringBase<unsigned short> v167; // [sp+248h] [bp-190h]@79
  PStringBase<unsigned short> v168; // [sp+24Ch] [bp-18Ch]@322
  PStringBase<unsigned short> v169; // [sp+250h] [bp-188h]@83
  PStringBase<unsigned short> v170; // [sp+254h] [bp-184h]@323
  PStringBase<unsigned short> v171; // [sp+258h] [bp-180h]@89
  PStringBase<unsigned short> v172; // [sp+25Ch] [bp-17Ch]@324
  PStringBase<unsigned short> v173; // [sp+260h] [bp-178h]@93
  PStringBase<unsigned short> v174; // [sp+264h] [bp-174h]@326
  PStringBase<unsigned short> v175; // [sp+268h] [bp-170h]@97
  PStringBase<unsigned short> v176; // [sp+26Ch] [bp-16Ch]@327
  PStringBase<unsigned short> v177; // [sp+270h] [bp-168h]@101
  PStringBase<unsigned short> v178; // [sp+274h] [bp-164h]@329
  PStringBase<unsigned short> v179; // [sp+278h] [bp-160h]@105
  PStringBase<unsigned short> v180; // [sp+27Ch] [bp-15Ch]@330
  PStringBase<unsigned short> v181; // [sp+280h] [bp-158h]@112
  PStringBase<unsigned short> v182; // [sp+284h] [bp-154h]@331
  PStringBase<unsigned short> v183; // [sp+288h] [bp-150h]@116
  PStringBase<unsigned short> v184; // [sp+28Ch] [bp-14Ch]@332
  PStringBase<unsigned short> v185; // [sp+290h] [bp-148h]@120
  PStringBase<unsigned short> v186; // [sp+294h] [bp-144h]@333
  PStringBase<unsigned short> v187; // [sp+298h] [bp-140h]@124
  PStringBase<unsigned short> v188; // [sp+29Ch] [bp-13Ch]@335
  PStringBase<unsigned short> v189; // [sp+2A0h] [bp-138h]@133
  PStringBase<unsigned short> v190; // [sp+2A4h] [bp-134h]@336
  PStringBase<unsigned short> v191; // [sp+2A8h] [bp-130h]@137
  PStringBase<unsigned short> v192; // [sp+2ACh] [bp-12Ch]@339
  PStringBase<unsigned short> v193; // [sp+2B0h] [bp-128h]@141
  PStringBase<unsigned short> v194; // [sp+2B4h] [bp-124h]@341
  PStringBase<unsigned short> v195; // [sp+2B8h] [bp-120h]@145
  PStringBase<unsigned short> v196; // [sp+2BCh] [bp-11Ch]@342
  PStringBase<unsigned short> v197; // [sp+2C0h] [bp-118h]@149
  PStringBase<unsigned short> v198; // [sp+2C4h] [bp-114h]@346
  PStringBase<unsigned short> v199; // [sp+2C8h] [bp-110h]@153
  PStringBase<unsigned short> v200; // [sp+2CCh] [bp-10Ch]@348
  PStringBase<unsigned short> v201; // [sp+2D0h] [bp-108h]@157
  PStringBase<unsigned short> v202; // [sp+2D4h] [bp-104h]@349
  PStringBase<unsigned short> v203; // [sp+2D8h] [bp-100h]@161
  PStringBase<unsigned short> v204; // [sp+2DCh] [bp-FCh]@350
  PStringBase<unsigned short> v205; // [sp+2E0h] [bp-F8h]@166
  PStringBase<unsigned short> v206; // [sp+2E4h] [bp-F4h]@351
  PStringBase<unsigned short> v207; // [sp+2E8h] [bp-F0h]@24
  PStringBase<unsigned short> v208; // [sp+2ECh] [bp-ECh]@354
  PStringBase<unsigned short> rhs; // [sp+2F0h] [bp-E8h]@32
  PStringBase<unsigned short> v210; // [sp+2F4h] [bp-E4h]@356
  PStringBase<unsigned short> v211; // [sp+2F8h] [bp-E0h]@56
  PStringBase<unsigned short> v212; // [sp+2FCh] [bp-DCh]@357
  PStringBase<unsigned short> v213; // [sp+300h] [bp-D8h]@64
  PStringBase<unsigned short> v214; // [sp+304h] [bp-D4h]@358
  PStringBase<unsigned short> v215; // [sp+308h] [bp-D0h]@73
  PStringBase<unsigned short> v216; // [sp+30Ch] [bp-CCh]@359
  PStringBase<unsigned short> v217; // [sp+310h] [bp-C8h]@81
  PStringBase<unsigned short> v218; // [sp+314h] [bp-C4h]@360
  PStringBase<unsigned short> v219; // [sp+318h] [bp-C0h]@91
  PStringBase<unsigned short> v220; // [sp+31Ch] [bp-BCh]@361
  PStringBase<unsigned short> v221; // [sp+320h] [bp-B8h]@99
  PStringBase<unsigned short> v222; // [sp+324h] [bp-B4h]@362
  PStringBase<unsigned short> v223; // [sp+328h] [bp-B0h]@110
  PStringBase<unsigned short> v224; // [sp+32Ch] [bp-ACh]@363
  PStringBase<unsigned short> v225; // [sp+330h] [bp-A8h]@118
  PStringBase<unsigned short> v226; // [sp+334h] [bp-A4h]@364
  PStringBase<unsigned short> v227; // [sp+338h] [bp-A0h]@127
  PStringBase<unsigned short> v228; // [sp+33Ch] [bp-9Ch]@367
  PStringBase<unsigned short> v229; // [sp+340h] [bp-98h]@139
  PStringBase<unsigned short> v230; // [sp+344h] [bp-94h]@368
  PStringBase<unsigned short> v231; // [sp+348h] [bp-90h]@147
  PStringBase<unsigned short> v232; // [sp+34Ch] [bp-8Ch]@369
  PStringBase<unsigned short> v233; // [sp+350h] [bp-88h]@155
  PStringBase<unsigned short> v234; // [sp+354h] [bp-84h]@370
  PStringBase<unsigned short> v235; // [sp+358h] [bp-80h]@163
  PStringBase<unsigned short> v236; // [sp+35Ch] [bp-7Ch]@371
  PStringBase<unsigned short> v237; // [sp+360h] [bp-78h]@28
  PStringBase<unsigned short> v238; // [sp+364h] [bp-74h]@372
  PStringBase<unsigned short> v239; // [sp+368h] [bp-70h]@60
  PStringBase<unsigned short> v240; // [sp+36Ch] [bp-6Ch]@373
  PStringBase<unsigned short> v241; // [sp+370h] [bp-68h]@77
  PStringBase<unsigned short> v242; // [sp+374h] [bp-64h]@374
  PStringBase<unsigned short> v243; // [sp+378h] [bp-60h]@95
  PStringBase<unsigned short> v244; // [sp+37Ch] [bp-5Ch]@375
  PStringBase<unsigned short> v245; // [sp+380h] [bp-58h]@114
  PStringBase<unsigned short> v246; // [sp+384h] [bp-54h]@52
  PStringBase<unsigned short> v247; // [sp+388h] [bp-50h]@1
  PStringBase<unsigned short> v248; // [sp+38Ch] [bp-4Ch]@69
  PStringBase<unsigned short> v249; // [sp+390h] [bp-48h]@151
  PStringBase<unsigned short> v250; // [sp+394h] [bp-44h]@87
  PStringBase<unsigned short> i_text; // [sp+398h] [bp-40h]@20
  PStringBase<unsigned short> v252; // [sp+39Ch] [bp-3Ch]@103
  PStringBase<unsigned short> v253; // [sp+3A0h] [bp-38h]@159
  PStringBase<unsigned short> v254; // [sp+3A4h] [bp-34h]@122
  PStringBase<unsigned short> v255; // [sp+3A8h] [bp-30h]@143
  PStringBase<unsigned short> v256; // [sp+3ACh] [bp-2Ch]@135
  PStringBase<unsigned short> v257; // [sp+3B0h] [bp-28h]@171
  PStringBase<unsigned short> v258; // [sp+3B4h] [bp-24h]@309
  PStringBase<unsigned short> v259; // [sp+3B8h] [bp-20h]@307
  PStringBase<unsigned short> v260; // [sp+3BCh] [bp-1Ch]@312
  PStringBase<unsigned short> v261; // [sp+3C0h] [bp-18h]@308
  PStringBase<unsigned short> v262; // [sp+3C4h] [bp-14h]@313
  PStringBase<unsigned short> v263; // [sp+3C8h] [bp-10h]@308
  PStringBase<unsigned short> v264; // [sp+3CCh] [bp-Ch]@314
  PStringBase<unsigned short> v265; // [sp+3D0h] [bp-8h]@308
  PStringBase<unsigned short> result; // [sp+3D4h] [bp-4h]@198

  v3 = 0;
  v247.m_charbuffer = 0;
  msg.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v4 = (ClientSystem *)this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( etype > 0x3E )
  {
    if ( etype != 67 && etype != 1015 )
      goto LABEL_11;
  }
  else if ( etype != 62 && etype != 35 && etype != 54 )
  {
    goto LABEL_11;
  }
  if ( ClientCombatSystem::GetCombatSystem() )
  {
    v5 = ClientCombatSystem::GetCombatSystem();
    if ( (unsigned __int8)ClientCombatSystem::RepeatAttackInProgress(v5) )
    {
      v6 = ClientCombatSystem::GetCombatSystem();
      ClientCombatSystem::AbortAutomaticAttack(v6);
    }
  }
LABEL_11:
  if ( etype > 0x4E8 )
  {
    switch ( etype )
    {
      case 0x4EBu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v48, L"You can't do that while in the air!");
        ClientSystem::AddTextToScroll(v4, &v48, 0x1Au, 1, 0);
        v7 = &v48;
        goto LABEL_376;
      case 0x550u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v50, L"Out of Range!");
        ClientSystem::AddTextToScroll(v4, &v50, 0x1Au, 1, 0);
        v7 = &v50;
        goto LABEL_376;
      case 0x52Bu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v52, L"That person is not available now.");
        ClientSystem::AddTextToScroll(v4, &v52, 0x1Au, 1, 0);
        v7 = &v52;
        goto LABEL_376;
      case 0x52Cu:
        PStringBase<unsigned short>::sprintf(&msg, L"You are now snooping on %s.\n", user_data->m_charbuffer);
        goto LABEL_207;
      case 0x52Du:
        PStringBase<unsigned short>::sprintf(&msg, L"You are no longer snooping on %s.\n", user_data->m_charbuffer);
        goto LABEL_366;
      case 0x52Eu:
        PStringBase<unsigned short>::sprintf(&msg, L"You fail to snoop on %s.\n", user_data->m_charbuffer);
        goto LABEL_210;
      case 0x52Fu:
        PStringBase<unsigned short>::sprintf(&msg, L"%s attempted to snoop on you.\n", user_data->m_charbuffer);
        goto LABEL_207;
      case 0x530u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s is already being snooped on, only one person may snoop on another at a time.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x531u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s is in limbo and cannot receive your message.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x506u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v54, L"You can't do that -- you're trading!");
        ClientSystem::AddTextToScroll(v4, &v54, 0x1Au, 1, 0);
        v7 = &v54;
        goto LABEL_376;
      case 0x584u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v56, L"You cannot pick up more of that item!");
        ClientSystem::AddTextToScroll(v4, &v56, 0x1Au, 1, 0);
        v7 = &v56;
        goto LABEL_376;
      case 0x4FCu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v58, L"You aren't trained in healing!");
        ClientSystem::AddTextToScroll(v4, &v58, 0x1Au, 1, 0);
        v7 = &v58;
        goto LABEL_376;
      case 0x4FDu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v60, L"You don't own that healing kit!");
        ClientSystem::AddTextToScroll(v4, &v60, 0x1Au, 1, 0);
        v7 = &v60;
        goto LABEL_376;
      case 0x4FEu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v62, L"You can't heal that!");
        ClientSystem::AddTextToScroll(v4, &v62, 0x1Au, 1, 0);
        v7 = &v62;
        goto LABEL_376;
      case 0x4FFu:
        PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v64, L" is already at full health!");
        PStringBase<unsigned short>::operator+=(&msg, &v64);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v64);
        ClientSystem::AddTextToScroll(v4, &msg, 0x1Au, 1, 0);
        break;
      case 0x500u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v66, L"You aren't ready to heal!");
        ClientSystem::AddTextToScroll(v4, &v66, 0x1Au, 1, 0);
        v7 = &v66;
        goto LABEL_376;
      case 0x501u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v68,
          L"You can only use Healing Kits on player characters.");
        ClientSystem::AddTextToScroll(v4, &v68, 0x1Au, 1, 0);
        v7 = &v68;
        goto LABEL_376;
      case 0x4FAu:
        PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v70, L" is an invalid target.\n");
        PStringBase<unsigned short>::operator+=(&msg, &v70);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v70);
        goto LABEL_48;
      case 0x4FBu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You are an invalid target for the spell of %s.\n",
          user_data->m_charbuffer);
        goto LABEL_224;
      case 0x509u:
        PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v72,
          L" has no appropriate targets equipped for this spell.\n");
        PStringBase<unsigned short>::operator+=(&msg, &v72);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v72);
        ClientSystem::AddTextToScroll(v4, &msg, 7u, 1, 0);
        break;
      case 0x50Au:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You have no appropriate targets equipped for %s's spell.\n",
          user_data->m_charbuffer);
        goto LABEL_46;
      case 0x51Au:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v74,
          L"Only the original owner may use that item's magic.");
        ClientSystem::AddTextToScroll(v4, &v74, 0x1Au, 1, 0);
        v7 = &v74;
        goto LABEL_376;
      case 0x4F3u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v76,
          L"Lite Player Killers may not interact with that portal!\n");
        ClientSystem::AddTextToScroll(v4, &v76, 7u, 1, 0);
        v7 = &v76;
        goto LABEL_376;
      case 0x503u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v78,
          L"The portal's residual energy protects you from the attack!\n");
        ClientSystem::AddTextToScroll(v4, &v78, 7u, 1, 0);
        v7 = &v78;
        goto LABEL_376;
      case 0x55Du:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v80,
          L"You must exit the Training Academy before that command will be available to you.\n");
        ClientSystem::AddTextToScroll(v4, &v80, 0, 1, 0);
        v7 = &v80;
        goto LABEL_376;
      case 0x502u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v82,
          L"The Lifestone's magic protects you from the attack!\n");
        ClientSystem::AddTextToScroll(v4, &v82, 7u, 1, 0);
        v7 = &v82;
        goto LABEL_376;
      case 0x53Eu:
        PStringBase<unsigned short>::sprintf(&msg, L"%s is banned from the allegiance!\n", user_data->m_charbuffer);
        goto LABEL_210;
      case 0x53Fu:
        PStringBase<unsigned short>::sprintf(&msg, L"You are banned from %s's allegiance!\n", user_data->m_charbuffer);
        goto LABEL_207;
      case 0x540u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v84,
          L"You have the maximum number of accounts banned.!\n");
        ClientSystem::AddTextToScroll(v4, &v84, 0, 1, 0);
        v7 = &v84;
        goto LABEL_376;
      case 0x56Fu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v86, L"That is an invalid officer level.\n");
        ClientSystem::AddTextToScroll(v4, &v86, 0, 1, 0);
        v7 = &v86;
        goto LABEL_376;
      case 0x541u:
        PStringBase<unsigned short>::sprintf(&msg, L"%s is now an allegiance officer.\n", user_data->m_charbuffer);
        goto LABEL_207;
      case 0x549u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"Your allegiance officer status has been modified. You now hold the position of: %s.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x542u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"An unspecified error occurred while attempting to set %s as an allegiance officer.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x56Du:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s is the monarch and cannot be promoted or demoted.\n",
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x54Bu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s is already an allegiance officer of that level.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x545u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v88,
          L"You already have the maximum number of allegiance officers. You must remove some before you add any more.\n");
        ClientSystem::AddTextToScroll(v4, &v88, 0, 1, 0);
        v7 = &v88;
        goto LABEL_376;
      case 0x543u:
        PStringBase<unsigned short>::sprintf(&msg, L"%s is no longer an allegiance officer.\n", user_data->m_charbuffer);
        goto LABEL_207;
      case 0x544u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"An unspecified error occurred while attempting to remove %s as an allegiance officer.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x54Au:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v90, L"You are no longer an allegiance officer.\n");
        ClientSystem::AddTextToScroll(v4, &v90, 0, 1, 0);
        v7 = &v90;
        goto LABEL_376;
      case 0x546u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v92, L"Your allegiance officers have been cleared.\n");
        ClientSystem::AddTextToScroll(v4, &v92, 0, 1, 0);
        v7 = &v92;
        goto LABEL_376;
      case 0x56Eu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"That level of allegiance officer is now known as: %s.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x571u:
        PStringBase<unsigned short>::sprintf(&msg, L"That allegiance name is too long. Please choose another name.\n");
        goto LABEL_207;
      case 0x570u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v94,
          L"That allegiance officer title is not appropriate.\n");
        ClientSystem::AddTextToScroll(v4, &v94, 0, 1, 0);
        v7 = &v94;
        goto LABEL_376;
      case 0x573u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"That allegiance title contains illegal characters. Please choose another name using only letters, spaces, - and '.\n");
        goto LABEL_207;
      case 0x572u:
        PStringBase<unsigned short>::sprintf(&msg, L"All of your allegiance officer titles have been cleared.\n");
        goto LABEL_210;
      case 0x54Cu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v96, L"Your allegiance does not have a hometown.\n");
        ClientSystem::AddTextToScroll(v4, &v96, 0, 1, 0);
        v7 = &v96;
        goto LABEL_376;
      case 0x533u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You have been booted from your allegiance chat room. Use \"@allegiance chat on\" to rejoin. (%s).\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x534u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s has been booted from the allegiance chat room.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x57Du:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v98, L"That character is already gagged!\n");
        ClientSystem::AddTextToScroll(v4, &v98, 0, 1, 0);
        v7 = &v98;
        goto LABEL_376;
      case 0x57Eu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v100, L"That character is not currently gagged!\n");
        ClientSystem::AddTextToScroll(v4, &v100, 0, 1, 0);
        v7 = &v100;
        goto LABEL_376;
      case 0x57Fu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"Your allegiance chat privileges have been temporarily removed by %s. Until they are restored, you may not view or speak in the allegiance chat channel.",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x580u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s is now temporarily unable to view or speak in allegiance chat. The gag will run out in 5 minutes, or %s may be explicitly ungagged before then.",
          user_data->m_charbuffer,
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x581u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v102,
          L"Your allegiance chat privileges have been restored.\n");
        ClientSystem::AddTextToScroll(v4, &v102, 0, 1, 0);
        v7 = &v102;
        goto LABEL_376;
      case 0x582u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"Your allegiance chat privileges have been restored by %s.",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x583u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You have restored allegiance chat privileges to %s.",
          user_data->m_charbuffer,
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x535u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v104,
          L"You do not have the authority within your allegiance to do that.\n");
        ClientSystem::AddTextToScroll(v4, &v104, 0, 1, 0);
        v7 = &v104;
        goto LABEL_376;
      case 0x536u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"The account of %s is already banned from the allegiance.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x537u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"The account of %s is not banned from the allegiance.\n",
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x538u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"The account of %s was not unbanned from the allegiance.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x539u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"The account of %s has been banned from the allegiance.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x53Au:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"The account of %s is no longer banned from the allegiance.\n",
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x53Bu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v106, L"Banned Characters: ");
        ClientSystem::AddTextToScroll(v4, &v106, 0, 1, 0);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v106);
        ClientSystem::AddTextToScroll(v4, user_data, 0, 1, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v108, L"\n");
        ClientSystem::AddTextToScroll(v4, &v108, 0, 1, 0);
        v7 = &v108;
        goto LABEL_376;
      case 0x565u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"That allegiance name is invalid because it is empty. Please use the @allegiance name clear command to clear your allegiance name.\n");
        goto LABEL_210;
      case 0x566u:
        PStringBase<unsigned short>::sprintf(&msg, L"That allegiance name is too long. Please choose another name.\n");
        goto LABEL_366;
      case 0x567u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"That allegiance name contains illegal characters. Please choose another name using only letters, spaces, - and '.\n");
        goto LABEL_207;
      case 0x568u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"That allegiance name is not appropriate. Please choose another name.\n");
        goto LABEL_210;
      case 0x569u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"That allegiance name is already in use. Please choose another name.\n");
        goto LABEL_366;
      case 0x56Au:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You may only change your allegiance name once every 24 hours. You may change your allegiance name again in %s.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x56Bu:
        PStringBase<unsigned short>::sprintf(&msg, L"Your allegiance name has been cleared.\n");
        goto LABEL_366;
      case 0x56Cu:
        PStringBase<unsigned short>::sprintf(&msg, L"That is already the name of your allegiance!\n");
        goto LABEL_207;
      case 0x574u:
        PStringBase<unsigned short>::sprintf(&msg, L"Your allegiance is currently: %s.\n", user_data->m_charbuffer);
        goto LABEL_366;
      case 0x575u:
        PStringBase<unsigned short>::sprintf(&msg, L"Your allegiance is now: %s.\n", user_data->m_charbuffer);
        goto LABEL_210;
      case 0x576u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You may not accept the offer of allegiance from %s because your allegiance is locked.\n",
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x577u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You may not swear allegiance at this time because the allegiance of %s is locked.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x578u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You have pre-approved %s to join your allegiance.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x579u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v110,
          L"You have not pre-approved any vassals to join your allegiance.\n");
        ClientSystem::AddTextToScroll(v4, &v110, 0, 1, 0);
        v7 = &v110;
        goto LABEL_376;
      case 0x57Au:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s is already a member of your allegiance!\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x57Bu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s has been pre-approved to join your allegiance.\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x57Cu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v112,
          L"You have cleared the pre-approved vassal for your allegiance.\n");
        ClientSystem::AddTextToScroll(v4, &v112, 0, 1, 0);
        v7 = &v112;
        goto LABEL_376;
      case 0x561u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v114,
          L"You may only have a maximum of 50 friends at once. If you wish to add more friends, you must first remove some.");
        ClientSystem::AddTextToScroll(v4, &v114, 0x1Au, 1, 0);
        v7 = &v114;
        goto LABEL_376;
      case 0x562u:
        PStringBase<unsigned short>::sprintf(&msg, L"%s is already on your friends list!\n", user_data->m_charbuffer);
        goto LABEL_210;
      case 0x563u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"That character is not on your friends list!\n",
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x51Bu:
        PStringBase<unsigned short>::sprintf(&msg, L"You have entered the %s channel.\n", user_data->m_charbuffer);
        goto LABEL_366;
      case 0x51Cu:
        PStringBase<unsigned short>::sprintf(&msg, L"You have left the %s channel.\n", user_data->m_charbuffer);
        goto LABEL_210;
      case 0x547u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You must wait %s before communicating again!\n",
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x548u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v116,
          L"You cannot join any chat channels while gagged.\n");
        ClientSystem::AddTextToScroll(v4, &v116, 0, 1, 0);
        v7 = &v116;
        goto LABEL_376;
      case 0x551u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You are not listening to the %s channel!\n",
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x55Eu:
        ClientSystem::AddTextToScroll(v4, user_data, 0, 1, 0);
        break;
      case 0x4ECu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v118,
          L"You cannot modify your player killer status while you are recovering from a PK death.\n");
        ClientSystem::AddTextToScroll(v4, &v118, 0, 1, 0);
        v7 = &v118;
        goto LABEL_376;
      case 0x4EDu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v120,
          L"Advocates may not change their player killer status!\n");
        ClientSystem::AddTextToScroll(v4, &v120, 0, 1, 0);
        v7 = &v120;
        goto LABEL_376;
      case 0x4EEu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v122,
          L"Your level is too low to change your player killer status with this object.\n");
        ClientSystem::AddTextToScroll(v4, &v122, 0, 1, 0);
        v7 = &v122;
        goto LABEL_376;
      case 0x4EFu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v124,
          L"Your level is too high to change your player killer status with this object.\n");
        ClientSystem::AddTextToScroll(v4, &v124, 0, 1, 0);
        v7 = &v124;
        goto LABEL_376;
      case 0x4F0u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v126,
          L"You feel a harsh dissonance, and you sense that an act of killing you have committed recently is interfering with the conversion.\n");
        ClientSystem::AddTextToScroll(v4, &v126, 0, 1, 0);
        v7 = &v126;
        goto LABEL_376;
      case 0x4F1u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v128,
          L"Bael'Zharon's power flows through you again. You are once more a player killer.\n");
        ClientSystem::AddTextToScroll(v4, &v128, 0, 1, 0);
        v7 = &v128;
        goto LABEL_376;
      case 0x4F2u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v130,
          L"Bael'Zharon has granted you respite after your moment of weakness. You are temporarily no longer a player killer.\n");
        ClientSystem::AddTextToScroll(v4, &v130, 0, 1, 0);
        v7 = &v130;
        goto LABEL_376;
      case 0x504u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v132,
          L"You are enveloped in a feeling of warmth as you are brought back into the protection of the Light. You are once again a Non-Player Killer.\n");
        ClientSystem::AddTextToScroll(v4, &v132, 0, 1, 0);
        v7 = &v132;
        goto LABEL_376;
      case 0x507u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v134,
          L"Only Non-Player Killers may enter PK Lite. Please see @help pklite for more details about this command.\n");
        ClientSystem::AddTextToScroll(v4, &v134, 0, 1, 0);
        v7 = &v134;
        goto LABEL_376;
      case 0x508u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v136,
          L"A cold wind touches your heart. You are now a Player Killer Lite.\n");
        ClientSystem::AddTextToScroll(v4, &v136, 0, 1, 0);
        v7 = &v136;
        goto LABEL_376;
      case 0x4F4u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s fails to affect you because $s cannot affect anyone!\n",
          user_data->m_charbuffer,
          user_data->m_charbuffer);
        goto LABEL_46;
      case 0x4F5u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s fails to affect you because you cannot be harmed!\n",
          user_data->m_charbuffer);
LABEL_48:
        ClientSystem::AddTextToScroll(v4, &msg, 7u, 1, 0);
        break;
      case 0x4F6u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"%s fails to affect you because %s is not a player killer!\n",
          user_data->m_charbuffer,
          user_data->m_charbuffer);
        goto LABEL_46;
      case 0x4F7u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v138,
          L" fails to affect you because you are not a player killer!\n");
        v13 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(user_data, &v259, &v138);
        PStringBase<unsigned short>::operator=(&msg, v13);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v259);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v138);
        ClientSystem::AddTextToScroll(v4, &msg, 7u, 1, 0);
        break;
      case 0x4F8u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v142, L"!\n");
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v140,
          L" fails to affect you because you are not the same sort of player killer as ");
        v14 = PStringBase<unsigned short>::operator+(user_data, &v265, &v140);
        v15 = PStringBase<unsigned short>::operator+(v14, &v261, user_data);
        v16 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(v15, &v263, &v142);
        PStringBase<unsigned short>::operator=(&msg, v16);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v263);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v261);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v265);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v140);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v142);
        goto LABEL_224;
      case 0x4F9u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v144,
          L" fails to affect you across a house boundary!\n");
        v17 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(user_data, &v258, &v144);
        PStringBase<unsigned short>::operator=(&msg, v17);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v258);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v144);
LABEL_224:
        ClientSystem::AddTextToScroll(v4, &msg, 7u, 1, 0);
        break;
      case 0x55Fu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v146,
          L"Only Player Killer characters may use this command!\n");
        ClientSystem::AddTextToScroll(v4, &v146, 0, 1, 0);
        v7 = &v146;
        goto LABEL_376;
      case 0x560u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v148,
          L"Only Player Killer Lite characters may use this command!\n");
        ClientSystem::AddTextToScroll(v4, &v148, 0, 1, 0);
        v7 = &v148;
        goto LABEL_376;
      case 0x50Bu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v150,
          L" is now an open fellowship; anyone may recruit new members.\n");
        v18 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(user_data, &v260, &v150);
        PStringBase<unsigned short>::operator=(&msg, v18);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v260);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v150);
        goto LABEL_207;
      case 0x50Cu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v152, L" is now a closed fellowship.\n");
        v19 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(user_data, &v262, &v152);
        PStringBase<unsigned short>::operator=(&msg, v19);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v262);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v152);
        goto LABEL_207;
      case 0x50Du:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v154, L" is now the leader of this fellowship.\n");
        v20 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(user_data, &v264, &v154);
        PStringBase<unsigned short>::operator=(&msg, v20);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v264);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v154);
        goto LABEL_207;
      case 0x50Eu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You have passed leadership of the fellowship to %s\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x50Fu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v156, L"You do not belong to a Fellowship.");
        ClientSystem::AddTextToScroll(v4, &v156, 0x1Au, 1, 0);
        v7 = &v156;
        goto LABEL_376;
      case 0x517u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v158, L" is not close enough to your level.\n");
        v21 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(user_data, &v247, &v158);
        PStringBase<unsigned short>::operator=(&msg, v21);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v247);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v158);
        goto LABEL_210;
      case 0x51Eu:
        PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v160,
          L" will not receive your message, please use urgent assistance to speak with an in-game representative\n");
        PStringBase<unsigned short>::operator+=(&msg, &v160);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v160);
        goto LABEL_210;
      case 0x51Fu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &errorText,
          0,
          L"Message Blocked: %s",
          user_data->m_charbuffer);
        ClientSystem::AddTextToScroll(v4, &errorText, 0x1Au, 1, 0);
        v7 = &errorText;
        goto LABEL_376;
      case 0x521u:
        PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v164,
          L" has been added to the list of people you can hear.\n");
        PStringBase<unsigned short>::operator+=(&msg, &v164);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v164);
        goto LABEL_207;
      case 0x522u:
        PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v166,
          L" has been removed from the list of people you can hear.\n");
        PStringBase<unsigned short>::operator+=(&msg, &v166);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v166);
        goto LABEL_207;
      case 0x520u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v168,
          L"You cannot add anymore people to the list of players that you can hear.\n");
        ClientSystem::AddTextToScroll(v4, &v168, 0, 1, 0);
        v7 = &v168;
        goto LABEL_376;
      case 0x523u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v170, L"You are now deaf to player's screams.\n");
        ClientSystem::AddTextToScroll(v4, &v170, 0, 1, 0);
        v7 = &v170;
        goto LABEL_376;
      case 0x524u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v172, L"You can hear all players once again.\n");
        ClientSystem::AddTextToScroll(v4, &v172, 0, 1, 0);
        v7 = &v172;
        goto LABEL_376;
      case 0x525u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You fail to remove %s from your loud list.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x518u:
        PStringBase<unsigned short>::set(&msg, L"This fellowship is locked; ");
        PStringBase<unsigned short>::operator+=(&msg, user_data);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v174, L" cannot be recruited into the fellowship.\n");
        PStringBase<unsigned short>::operator+=(&msg, &v174);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v174);
        goto LABEL_366;
      case 0x519u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v176,
          L"The fellowship is locked, you were not added to the fellowship.\n");
        ClientSystem::AddTextToScroll(v4, &v176, 0, 1, 0);
        v7 = &v176;
        goto LABEL_376;
      case 0x528u:
        PStringBase<unsigned short>::set(&msg, L"The fellowship is locked; you cannot open locked fellowships.\n");
        goto LABEL_207;
      case 0x505u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v178, L"You're too close to your sanctuary!");
        ClientSystem::AddTextToScroll(v4, &v178, 0x1Au, 1, 0);
        v7 = &v178;
        goto LABEL_376;
      case 0x526u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v180, L"You chicken out.");
        ClientSystem::AddTextToScroll(v4, &v180, 0x1Au, 1, 0);
        v7 = &v180;
        goto LABEL_376;
      case 0x527u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v182, L"You cannot posssibly succeed.");
        ClientSystem::AddTextToScroll(v4, &v182, 0x1Au, 1, 0);
        v7 = &v182;
        goto LABEL_376;
      case 0x52Au:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v184, L"That is not a salvaging tool.");
        ClientSystem::AddTextToScroll(v4, &v184, 0x1Au, 1, 0);
        v7 = &v184;
        goto LABEL_376;
      case 0x564u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v186,
          L"Only the character who owns the house may use this command.");
        ClientSystem::AddTextToScroll(v4, &v186, 0, 1, 0);
        v7 = &v186;
        goto LABEL_376;
      case 0x510u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You may not hook any more %s on your house.  You already have the maximum number of %s hooked or you are not permitted to hook any on your type of house.\n",
          user_data->m_charbuffer,
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x512u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v188,
          L"You are now using the maximum number of hooks.  You cannot use another hook until you take an item off one of your hooks.\n");
        ClientSystem::AddTextToScroll(v4, &v188, 0, 1, 0);
        v7 = &v188;
        goto LABEL_376;
      case 0x513u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v190,
          L"You are no longer using the maximum number of hooks.  You may again add items to your hooks.\n");
        ClientSystem::AddTextToScroll(v4, &v190, 0, 1, 0);
        v7 = &v190;
        goto LABEL_376;
      case 0x514u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You now have the maximum number of %s hooked.  You cannot hook any additional %s until you remove one or more from your house.\n",
          user_data->m_charbuffer,
          user_data->m_charbuffer);
        goto LABEL_207;
      case 0x515u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"You no longer have the maximum number of %s hooked.  You may hook additional %s.\n",
          user_data->m_charbuffer,
          user_data->m_charbuffer);
        goto LABEL_210;
      case 0x516u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v192, L"You are not permitted to use that hook.\n");
        ClientSystem::AddTextToScroll(v4, &v192, 0, 1, 0);
        v7 = &v192;
        goto LABEL_376;
      case 0x4E9u:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"The %s cannot be used while on a hook, use the '@house hooks on' command to make the hook openable.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x54Eu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v194,
          L"The hook does not contain a usable item. You cannot open the hook because you do not own the house to which it belongs.\n");
        ClientSystem::AddTextToScroll(v4, &v194, 0, 1, 0);
        v7 = &v194;
        goto LABEL_376;
      case 0x54Fu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v196,
          L"The hook does not contain a usable item. Use the '@house hooks on'command to make the hook openable.\n");
        ClientSystem::AddTextToScroll(v4, &v196, 0, 1, 0);
        v7 = &v196;
        goto LABEL_376;
      case 0x4EAu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"The %s can only be used while on a hook.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x54Du:
        PStringBase<unsigned short>::sprintf(&msg, L"The %s is currently in use.\n", user_data->m_charbuffer);
LABEL_345:
        ClientSystem::AddTextToScroll(v4, &msg, 0x1Au, 1, 0);
        break;
      case 0x532u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v198,
          L"You must wait 30 days after purchasing a house before you may purchase another with any character on the same account. This applies to all housing except apartments.\n");
        ClientSystem::AddTextToScroll(v4, &v198, 0, 1, 0);
        v7 = &v198;
        goto LABEL_376;
      case 0x55Cu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"Although your augmentation will not allow you to untrain your %s skill, you have succeeded in recovering all the experience you had invested in it.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x556u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v200,
          L"You have failed to complete the augmentation.\n");
        ClientSystem::AddTextToScroll(v4, &v200, 0, 1, 0);
        v7 = &v200;
        goto LABEL_376;
      case 0x557u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v202,
          L"You have used this augmentation too many times already.\n");
        ClientSystem::AddTextToScroll(v4, &v202, 0, 1, 0);
        v7 = &v202;
        goto LABEL_376;
      case 0x558u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v204,
          L"You have used augmentations of this type too many times already.\n");
        ClientSystem::AddTextToScroll(v4, &v204, 0, 1, 0);
        v7 = &v204;
        goto LABEL_376;
      case 0x559u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v206,
          L"You do not have enough unspent experience available to purchase this augmentation.\n");
        ClientSystem::AddTextToScroll(v4, &v206, 0, 1, 0);
        v7 = &v206;
        goto LABEL_376;
      case 0x55Au:
        PStringBase<unsigned short>::sprintf(&msg, L"%s\n", user_data->m_charbuffer);
LABEL_207:
        ClientSystem::AddTextToScroll(v4, &msg, 0, 1, 0);
        break;
      case 0x55Bu:
        PStringBase<unsigned short>::sprintf(
          &msg,
          L"Congratulations! You have succeeded in acquiring the %s augmentation.\n",
          user_data->m_charbuffer);
        goto LABEL_366;
      case 0x529u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v208, L"Trade Complete!");
        ClientSystem::AddTextToScroll(v4, &v208, 0x1Au, 1, 0);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v208);
        if ( APIManager::APIIsReady() )
        {
          v22 = APIManager::GetACPlugin();
          v22->vfptr[6].Release((IUnknown *)v22);
        }
        break;
      case 0x552u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v210,
          L"You must purchase Asheron's Call -- Throne of Destiny to use this function.");
        ClientSystem::AddTextToScroll(v4, &v210, 0x1Au, 1, 0);
        v7 = &v210;
        goto LABEL_376;
      case 0x553u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v212,
          L"You must purchase Asheron's Call -- Throne of Destiny to use this item.");
        ClientSystem::AddTextToScroll(v4, &v212, 0x1Au, 1, 0);
        v7 = &v212;
        goto LABEL_376;
      case 0x554u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v214,
          L"You must purchase Asheron's Call -- Throne of Destiny to use this portal.");
        ClientSystem::AddTextToScroll(v4, &v214, 0x1Au, 1, 0);
        v7 = &v214;
        goto LABEL_376;
      case 0x555u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v216,
          L"You must purchase Asheron's Call -- Throne of Destiny to access this quest.");
        ClientSystem::AddTextToScroll(v4, &v216, 0x1Au, 1, 0);
        v7 = &v216;
        goto LABEL_376;
      case 0x585u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v218,
          L"You are restricted to clothes and armor created for your race.");
        ClientSystem::AddTextToScroll(v4, &v218, 0x1Au, 1, 0);
        v7 = &v218;
        goto LABEL_376;
      case 0x586u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v220,
          L"That item was specifically created for another race.");
        ClientSystem::AddTextToScroll(v4, &v220, 0x1Au, 1, 0);
        v7 = &v220;
        goto LABEL_376;
      case 0x587u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v222, L"Olthoi cannot interact with that!\n");
        ClientSystem::AddTextToScroll(v4, &v222, 7u, 1, 0);
        v7 = &v222;
        goto LABEL_376;
      case 0x588u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v224,
          L"Olthoi cannot use regular lifestones! Asheron would not allow it!\n");
        ClientSystem::AddTextToScroll(v4, &v224, 7u, 1, 0);
        v7 = &v224;
        goto LABEL_376;
      case 0x589u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v226, L"The vendor looks at you in horror!\n");
        ClientSystem::AddTextToScroll(v4, &v226, 7u, 1, 0);
        v7 = &v226;
        goto LABEL_376;
      case 0x58Au:
        PStringBase<unsigned short>::sprintf(&msg, L"%s cowers from you!\n", user_data->m_charbuffer);
LABEL_366:
        ClientSystem::AddTextToScroll(v4, &msg, 0, 1, 0);
        break;
      case 0x58Bu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v228,
          L"As a mindless engine of destruction an Olthoi cannot join a fellowship!\n");
        ClientSystem::AddTextToScroll(v4, &v228, 7u, 1, 0);
        v7 = &v228;
        goto LABEL_376;
      case 0x58Cu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v230,
          L"The Olthoi only have an allegiance to the Olthoi Queen!\n");
        ClientSystem::AddTextToScroll(v4, &v230, 7u, 1, 0);
        v7 = &v230;
        goto LABEL_376;
      case 0x58Du:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v232, L"You cannot use that item!\n");
        ClientSystem::AddTextToScroll(v4, &v232, 7u, 1, 0);
        v7 = &v232;
        goto LABEL_376;
      case 0x58Eu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v234, L"This person will not interact with you!\n");
        ClientSystem::AddTextToScroll(v4, &v234, 7u, 1, 0);
        v7 = &v234;
        goto LABEL_376;
      case 0x58Fu:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v236, L"Only Olthoi may pass through this portal!\n");
        ClientSystem::AddTextToScroll(v4, &v236, 7u, 1, 0);
        v7 = &v236;
        goto LABEL_376;
      case 0x590u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v238, L"Olthoi may not pass through this portal!\n");
        ClientSystem::AddTextToScroll(v4, &v238, 7u, 1, 0);
        v7 = &v238;
        goto LABEL_376;
      case 0x591u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v240,
          L"You may not pass through this portal while Vitae weakens you!\n");
        ClientSystem::AddTextToScroll(v4, &v240, 7u, 1, 0);
        v7 = &v240;
        goto LABEL_376;
      case 0x592u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v242,
          L"This character must be two weeks old or have been created on an account at least two weeks old to use this portal!\n");
        ClientSystem::AddTextToScroll(v4, &v242, 7u, 1, 0);
        v7 = &v242;
        goto LABEL_376;
      case 0x593u:
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v244,
          L"Olthoi characters can only use Lifestone and PK Arena recalls!\n");
        ClientSystem::AddTextToScroll(v4, &v244, 7u, 1, 0);
        v7 = &v244;
        goto LABEL_376;
      default:
        break;
    }
  }
  else
  {
    if ( etype != 1256 )
    {
      if ( etype > 0x48A )
      {
        switch ( etype )
        {
          case 0x48Fu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v223, L"You are already involved in something!");
            ClientSystem::AddTextToScroll(v4, &v223, 0x1Au, 1, 0);
            v7 = &v223;
            goto LABEL_376;
          case 0x498u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v95, L"You have moved too far!");
            ClientSystem::AddTextToScroll(v4, &v95, 0x1Au, 1, 0);
            v7 = &v95;
            goto LABEL_376;
          case 0x499u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v181, L"That is not a valid destination!");
            ClientSystem::AddTextToScroll(v4, &v181, 0x1Au, 1, 0);
            v7 = &v181;
            goto LABEL_376;
          case 0x490u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v97,
              L"You must be a monarch to use this command.");
            ClientSystem::AddTextToScroll(v4, &v97, 0x1Au, 1, 0);
            v7 = &v97;
            goto LABEL_376;
          case 0x493u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v245, L"That character does not exist.");
            ClientSystem::AddTextToScroll(v4, &v245, 0x1Au, 1, 0);
            v7 = &v245;
            goto LABEL_376;
          case 0x49Au:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v99,
              L"You must purchase Asheron's Call -- Dark Majesty to use this function.");
            ClientSystem::AddTextToScroll(v4, &v99, 0x1Au, 1, 0);
            v7 = &v99;
            goto LABEL_376;
          case 0x4CFu:
            PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v183,
              L" cannot accept stacked objects. Try giving one at a time.\n");
            PStringBase<unsigned short>::operator+=(&msg, &v183);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v183);
            goto LABEL_366;
          case 0x4CEu:
$L188165:
            PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v101,
              L" is too busy to accept gifts right now.\n");
            PStringBase<unsigned short>::operator+=(&msg, &v101);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v101);
            goto LABEL_366;
          case 0x4AFu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v225, L"The lock is already unlocked.");
            ClientSystem::AddTextToScroll(v4, &v225, 0x1Au, 1, 0);
            v7 = &v225;
            goto LABEL_376;
          case 0x4B0u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v103, L"You can't lock or unlock that!");
            ClientSystem::AddTextToScroll(v4, &v103, 0x1Au, 1, 0);
            v7 = &v103;
            goto LABEL_376;
          case 0x4B1u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v185, L"You can't lock or unlock what is open!");
            ClientSystem::AddTextToScroll(v4, &v185, 0x1Au, 1, 0);
            v7 = &v185;
            goto LABEL_376;
          case 0x4B2u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v105, L"The key doesn't fit this lock.\n");
            ClientSystem::AddTextToScroll(v4, &v105, 0, 1, 0);
            v7 = &v105;
            goto LABEL_376;
          case 0x4B3u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v254, L"The lock has been used too recently.");
            ClientSystem::AddTextToScroll(v4, &v254, 0x1Au, 1, 0);
            v7 = &v254;
            goto LABEL_376;
          case 0x4B4u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v107, L"You aren't trained in lockpicking!");
            ClientSystem::AddTextToScroll(v4, &v107, 0x1Au, 1, 0);
            v7 = &v107;
            goto LABEL_376;
          case 0x4C5u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v187,
              L"Your Allegiance Rank is too low to use that item's magic.");
            ClientSystem::AddTextToScroll(v4, &v187, 0x1Au, 1, 0);
            v7 = &v187;
            goto LABEL_376;
          case 0x4C6u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You must be %s to use that item's magic.",
              user_data->m_charbuffer);
            goto LABEL_178;
          case 0x4C7u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v109,
              L"Your Arcane Lore skill is too low to use that item's magic.");
            ClientSystem::AddTextToScroll(v4, &v109, 0x1Au, 1, 0);
            v7 = &v109;
            goto LABEL_376;
          case 0x4C8u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v227, L"That item doesn't have enough Mana.");
            ClientSystem::AddTextToScroll(v4, &v227, 0x1Au, 1, 0);
            v7 = &v227;
            goto LABEL_376;
          case 0x4C9u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"Your %s is too low to use that item's magic.",
              user_data->m_charbuffer);
            goto LABEL_178;
          case 0x4CAu:
            PStringBase<unsigned short>::sprintf(&msg, L"Only %s may use that item's magic.", user_data->m_charbuffer);
LABEL_130:
            ClientSystem::AddTextToScroll(v4, &msg, 0x1Au, 1, 0);
            goto LABEL_377;
          case 0x4CBu:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You must have %s specialized to use that item's magic.",
              user_data->m_charbuffer);
            goto LABEL_345;
          case 0x4A0u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v111, L"You fail to link with the portal!\n");
            ClientSystem::AddTextToScroll(v4, &v111, 7u, 1, 0);
            v7 = &v111;
            goto LABEL_376;
          case 0x4A1u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v189, L"You successfully link with the portal!\n");
            ClientSystem::AddTextToScroll(v4, &v189, 7u, 1, 0);
            v7 = &v189;
            goto LABEL_376;
          case 0x4A2u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v113, L"You fail to recall to the portal!\n");
            ClientSystem::AddTextToScroll(v4, &v113, 7u, 1, 0);
            v7 = &v113;
            goto LABEL_376;
          case 0x4A3u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v256,
              L"You must have linked with a portal in order to recall to it!\n");
            ClientSystem::AddTextToScroll(v4, &v256, 7u, 1, 0);
            v7 = &v256;
            goto LABEL_376;
          case 0x4A4u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v115, L"You fail to summon the portal!\n");
            ClientSystem::AddTextToScroll(v4, &v115, 7u, 1, 0);
            v7 = &v115;
            goto LABEL_376;
          case 0x4A5u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v191,
              L"You must have linked with a portal in order to summon it!\n");
            ClientSystem::AddTextToScroll(v4, &v191, 7u, 1, 0);
            v7 = &v191;
            goto LABEL_376;
          case 0x4A6u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v117, L"You fail to teleport!\n");
            ClientSystem::AddTextToScroll(v4, &v117, 7u, 1, 0);
            v7 = &v117;
            goto LABEL_376;
          case 0x4A7u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v229, L"You have been teleported too recently!\n");
            ClientSystem::AddTextToScroll(v4, &v229, 7u, 1, 0);
            v7 = &v229;
            goto LABEL_376;
          case 0x4A8u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v119,
              L"You must be an Advocate to interact with that portal.\n");
            ClientSystem::AddTextToScroll(v4, &v119, 7u, 1, 0);
            v7 = &v119;
            goto LABEL_376;
          case 0x4AAu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v193,
              L"Players may not interact with that portal.\n");
            ClientSystem::AddTextToScroll(v4, &v193, 7u, 1, 0);
            v7 = &v193;
            goto LABEL_376;
          case 0x4ACu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v121,
              L"You are too powerful to interact with that portal!\n");
            ClientSystem::AddTextToScroll(v4, &v121, 7u, 1, 0);
            v7 = &v121;
            goto LABEL_376;
          case 0x4ABu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v255,
              L"You are not powerful enough to interact with that portal!\n");
            ClientSystem::AddTextToScroll(v4, &v255, 7u, 1, 0);
            v7 = &v255;
            goto LABEL_376;
          case 0x4C4u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v123,
              L"You must be a guest in this house to interact with that portal.\n");
            ClientSystem::AddTextToScroll(v4, &v123, 7u, 1, 0);
            v7 = &v123;
            goto LABEL_376;
          case 0x4ADu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v195, L"You cannot recall to that portal!\n");
            ClientSystem::AddTextToScroll(v4, &v195, 7u, 1, 0);
            v7 = &v195;
            goto LABEL_376;
          case 0x4AEu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v125, L"You cannot summon that portal!\n");
            ClientSystem::AddTextToScroll(v4, &v125, 7u, 1, 0);
            v7 = &v125;
            goto LABEL_376;
          case 0x4CCu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v231,
              L"You have been involved in a player killer battle too recently to do that!\n");
            ClientSystem::AddTextToScroll(v4, &v231, 7u, 1, 0);
            v7 = &v231;
            goto LABEL_376;
          case 0x49Bu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v127, L"You fail to link with the lifestone!\n");
            ClientSystem::AddTextToScroll(v4, &v127, 7u, 1, 0);
            v7 = &v127;
            goto LABEL_376;
          case 0x49Cu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v197,
              L"You wandered too far to link with the lifestone!\n");
            ClientSystem::AddTextToScroll(v4, &v197, 7u, 1, 0);
            v7 = &v197;
            goto LABEL_376;
          case 0x49Du:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v129,
              L"You successfully link with the lifestone!\n");
            ClientSystem::AddTextToScroll(v4, &v129, 7u, 1, 0);
            v7 = &v129;
            goto LABEL_376;
          case 0x49Eu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v249,
              L"You must have linked with a lifestone in order to recall to it!\n");
            ClientSystem::AddTextToScroll(v4, &v249, 7u, 1, 0);
            v7 = &v249;
            goto LABEL_376;
          case 0x49Fu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v131, L"You fail to recall to the lifestone!\n");
            ClientSystem::AddTextToScroll(v4, &v131, 7u, 1, 0);
            v7 = &v131;
            goto LABEL_376;
          case 0x48Eu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v199,
              L"Your offer of Allegiance has been ignored.");
            ClientSystem::AddTextToScroll(v4, &v199, 0x1Au, 1, 0);
            v7 = &v199;
            goto LABEL_376;
          case 0x491u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v133, L"You must specify a character to boot.");
            ClientSystem::AddTextToScroll(v4, &v133, 0x1Au, 1, 0);
            v7 = &v133;
            goto LABEL_376;
          case 0x492u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v233, L"You can't boot yourself!");
            ClientSystem::AddTextToScroll(v4, &v233, 0x1Au, 1, 0);
            v7 = &v233;
            goto LABEL_376;
          case 0x4B5u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v135, L"You must specify a character to query.");
            ClientSystem::AddTextToScroll(v4, &v135, 0x1Au, 1, 0);
            v7 = &v135;
            goto LABEL_376;
          case 0x4B6u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v201,
              L"Please use the allegiance panel to view your own information.");
            ClientSystem::AddTextToScroll(v4, &v201, 0x1Au, 1, 0);
            v7 = &v201;
            goto LABEL_376;
          case 0x4B7u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v137, L"You have used that command too recently.");
            ClientSystem::AddTextToScroll(v4, &v137, 0x1Au, 1, 0);
            v7 = &v137;
            goto LABEL_376;
          case 0x494u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v253,
              L"That person is not a member of your Allegiance!");
            ClientSystem::AddTextToScroll(v4, &v253, 0x1Au, 1, 0);
            v7 = &v253;
            goto LABEL_376;
          case 0x495u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v139, L"No patron from which to break!");
            ClientSystem::AddTextToScroll(v4, &v139, 0x1Au, 1, 0);
            v7 = &v139;
            goto LABEL_376;
          case 0x496u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v203, L"Your Allegiance has been dissolved!\n");
            ClientSystem::AddTextToScroll(v4, &v203, 0, 1, 0);
            v7 = &v203;
            goto LABEL_376;
          case 0x497u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v141,
              L"Your patron's Allegiance to you has been broken!\n");
            ClientSystem::AddTextToScroll(v4, &v141, 0, 1, 0);
            v7 = &v141;
            goto LABEL_376;
          case 0x4E7u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v235,
              L"You cannot swear allegiance to anyone because you own a monarch-only house. Please abandon your house and try again.\n");
            ClientSystem::AddTextToScroll(v4, &v235, 0, 1, 0);
            v7 = &v235;
            goto LABEL_376;
          case 0x4B8u:
          case 0x4B9u:
          case 0x4BAu:
            CM_Character::SendNotice_AbuseReportResponse(etype);
            goto LABEL_377;
          case 0x4BDu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v143, L"You do not own that salvage tool!\n");
            ClientSystem::AddTextToScroll(v4, &v143, 0, 1, 0);
            v7 = &v143;
            goto LABEL_376;
          case 0x4BEu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v205, L"You do not own that item!\n");
            ClientSystem::AddTextToScroll(v4, &v205, 0, 1, 0);
            v7 = &v205;
            goto LABEL_376;
          case 0x4C1u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v145, L"The material cannot be created.\n");
            ClientSystem::AddTextToScroll(v4, &v145, 0, 1, 0);
            v7 = &v145;
            goto LABEL_376;
          case 0x4C2u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v25,
              L"The list of items you are attempting to salvage is invalid.\n");
            ClientSystem::AddTextToScroll(v4, &v25, 0, 1, 0);
            v7 = &v25;
            goto LABEL_376;
          case 0x4C3u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v26,
              L"You cannot salvage items that you are trading!\n");
            ClientSystem::AddTextToScroll(v4, &v26, 0, 1, 0);
            v7 = &v26;
            goto LABEL_376;
          case 0x4BFu:
            v9 = user_data->m_charbuffer;
            if ( *(_DWORD *)&user_data->m_charbuffer[-1].m_data[14] == 1 )
            {
              v3 = 1;
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v257, L"item");
              v9 = *v10;
            }
            PStringBase<unsigned short>::sprintf(&msg, L"The %s was not suitable for salvaging.", v9);
            if ( v3 & 1 )
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v257);
            ClientSystem::AddTextToScroll(v4, &msg, 0x1Au, 1, 0);
            goto LABEL_377;
          case 0x4C0u:
            v11 = user_data->m_charbuffer;
            if ( *(_DWORD *)&user_data->m_charbuffer[-1].m_data[14] == 1 )
              v11 = (PSRefBufferCharData<unsigned short> *)L"item";
            PStringBase<unsigned short>::sprintf(&msg, L"The %s contains the wrong material.", v11);
LABEL_178:
            ClientSystem::AddTextToScroll(v4, &msg, 0x1Au, 1, 0);
            goto LABEL_377;
          case 0x4E2u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v28,
              L"This hook is a duplicated housing object. You may not add items to a duplicated housing object. Please empty the hook and allow it to reset.\n");
            ClientSystem::AddTextToScroll(v4, &v28, 0, 1, 0);
            v7 = &v28;
            goto LABEL_376;
          case 0x4E5u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v30,
              L"This hook was a duplicated housing object. Since it is now empty, it will be deleted momentarily. Once it is gone, it is safe to use the other, non-duplicated hook that is here.\n");
            ClientSystem::AddTextToScroll(v4, &v30, 0, 1, 0);
            v7 = &v30;
            goto LABEL_376;
          case 0x4E3u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v32,
              L"That item is of the wrong type to be placed on this hook.\n");
            ClientSystem::AddTextToScroll(v4, &v32, 0, 1, 0);
            v7 = &v32;
            goto LABEL_376;
          case 0x4E4u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v34,
              L"This chest is a duplicated housing object. You may not add items to a duplicated housing object. Please empty everything -- including backpacks -- out of the chest and allow the chest to reset.\n");
            ClientSystem::AddTextToScroll(v4, &v34, 0, 1, 0);
            v7 = &v34;
            goto LABEL_376;
          case 0x4E6u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v36,
              L"This chest was a duplicated housing object. Since it is now empty, it will be deleted momentarily. Once it is gone, it is safe to use the other, non-duplicated chest that is here.\n");
            ClientSystem::AddTextToScroll(v4, &v36, 0, 1, 0);
            v7 = &v36;
            goto LABEL_376;
          case 0x48Bu:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You must be above allegiance rank %s to purchase this dwelling.\n",
              user_data->m_charbuffer);
            goto LABEL_207;
          case 0x48Cu:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You must be at or below allegiance rank %s to purchase this dwelling.\n",
              user_data->m_charbuffer);
            goto LABEL_366;
          case 0x4D0u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v38, L"You have failed to alter your skill.\n");
            ClientSystem::AddTextToScroll(v4, &v38, 0, 1, 0);
            v7 = &v38;
            goto LABEL_376;
          case 0x4D1u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"Your %s skill must be trained, not untrained or specialized, in order to be altered in this way!\n",
              user_data->m_charbuffer);
            goto LABEL_207;
          case 0x4D2u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You do not have enough skill credits to specialize your %s skill.\n",
              user_data->m_charbuffer);
            goto LABEL_366;
          case 0x4D3u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You have too many available experience points to be able to absorb the experience points from your %s skill. Please spend some of your experience points and try again.\n",
              user_data->m_charbuffer);
            goto LABEL_210;
          case 0x4D4u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"Your %s skill is already untrained!\n",
              user_data->m_charbuffer);
            goto LABEL_207;
          case 0x4D5u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You are currently wielding items which require a certain level of %s.  Your %s skill cannot be lowered while you are wielding these items.  Please remove these items and try again.\n",
              user_data->m_charbuffer,
              user_data->m_charbuffer);
            ClientSystem::AddTextToScroll(v4, &msg, 0, 1, 0);
            goto LABEL_377;
          case 0x4DAu:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You have too many credits invested in specialized skills already! Before you can specialize your %s skill, you will need to unspecialize some other skill.\n",
              user_data->m_charbuffer);
            goto LABEL_207;
          case 0x4D6u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You have succeeded in specializing your %s skill!\n",
              user_data->m_charbuffer);
            goto LABEL_366;
          case 0x4D7u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You have succeeded in lowering your %s skill from specialized to trained!\n",
              user_data->m_charbuffer);
            goto LABEL_210;
          case 0x4D8u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"You have succeeded in untraining your %s skill!\n",
              user_data->m_charbuffer);
            goto LABEL_207;
          case 0x4D9u:
            PStringBase<unsigned short>::sprintf(
              &msg,
              L"Although you cannot untrain your %s skill, you have succeeded in recovering all the experience you had invested in it.\n",
              user_data->m_charbuffer);
            goto LABEL_366;
          case 0x4DDu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v40,
              L"You have failed to alter your attributes.\n");
            ClientSystem::AddTextToScroll(v4, &v40, 0, 1, 0);
            v7 = &v40;
            goto LABEL_376;
          case 0x4DEu:
          case 0x4DFu:
            PStringBase<unsigned short>::PStringBase<unsigned short>(&v42, L"\n");
            v12 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(user_data, &result, &v42);
            PStringBase<unsigned short>::operator=(&msg, v12);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v42);
            ClientSystem::AddTextToScroll(v4, &msg, 0, 1, 0);
            goto LABEL_377;
          case 0x4E0u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v44,
              L"You are currently wielding items which require a certain level of skill. Your attributes cannot be transferred while you are wielding these items. Please remove these items and try again.\n");
            ClientSystem::AddTextToScroll(v4, &v44, 0, 1, 0);
            v7 = &v44;
            goto LABEL_376;
          case 0x4E1u:
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &v46,
              L"You have succeeded in transferring your attributes!\n");
            ClientSystem::AddTextToScroll(v4, &v46, 0, 1, 0);
            v7 = &v46;
            goto LABEL_376;
          default:
            goto LABEL_377;
        }
        goto LABEL_377;
      }
      if ( etype == 1162 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v93,
          L"You must be a monarch to purchase this dwelling.\n");
        ClientSystem::AddTextToScroll(v4, &v93, 0, 1, 0);
        v7 = &v93;
      }
      else
      {
        if ( etype > 0x408 )
        {
          switch ( etype )
          {
            case 0x427u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v57, L"You cannot merge different stacks!");
              ClientSystem::AddTextToScroll(v4, &v57, 0x1Au, 1, 0);
              v7 = &v57;
              goto LABEL_376;
            case 0x428u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v248, L"You cannot merge enchanted items!");
              ClientSystem::AddTextToScroll(v4, &v248, 0x1Au, 1, 0);
              v7 = &v248;
              goto LABEL_376;
            case 0x429u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v59, L"You must control at least one stack!");
              ClientSystem::AddTextToScroll(v4, &v59, 0x1Au, 1, 0);
              v7 = &v59;
              goto LABEL_376;
            case 0x46Au:
              PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v163, L" doesn't know what to do with that.\n");
              PStringBase<unsigned short>::operator+=(&msg, &v163);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v163);
              ClientSystem::AddTextToScroll(v4, &msg, 0, 1, 0);
              goto LABEL_377;
            case 0x43Eu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v61,
                L"You have solved this quest too recently!\n");
              ClientSystem::AddTextToScroll(v4, &v61, 0, 1, 0);
              v7 = &v61;
              goto LABEL_376;
            case 0x43Fu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v215,
                L"You have solved this quest too many times!\n");
              ClientSystem::AddTextToScroll(v4, &v215, 0, 1, 0);
              v7 = &v215;
              goto LABEL_376;
            case 0x445u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v63,
                L"This item requires you to complete a specific quest before you can pick it up!\n");
              ClientSystem::AddTextToScroll(v4, &v63, 0, 1, 0);
              v7 = &v63;
              goto LABEL_376;
            case 0x40Au:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v165, L"You are unprepared to cast a spell");
              ClientSystem::AddTextToScroll(v4, &v165, 0x1Au, 1, 0);
              v7 = &v165;
              goto LABEL_376;
            case 0x45Cu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v65,
                L"Player killers may not interact with that portal!\n");
              ClientSystem::AddTextToScroll(v4, &v65, 7u, 1, 0);
              v7 = &v65;
              goto LABEL_376;
            case 0x45Du:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v241,
                L"Non-player killers may not interact with that portal!\n");
              ClientSystem::AddTextToScroll(v4, &v241, 7u, 1, 0);
              v7 = &v241;
              goto LABEL_376;
            case 0x466u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v67,
                L"You must purchase Asheron's Call: Dark Majesty to interact with that portal.\n");
              ClientSystem::AddTextToScroll(v4, &v67, 7u, 1, 0);
              v7 = &v67;
              goto LABEL_376;
            case 0x474u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v167,
                L"You must complete a quest to interact with that portal.\n");
              ClientSystem::AddTextToScroll(v4, &v167, 7u, 1, 0);
              v7 = &v167;
              goto LABEL_376;
            case 0x43Du:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v69, L"You cannot link to that portal!\n");
              ClientSystem::AddTextToScroll(v4, &v69, 7u, 1, 0);
              v7 = &v69;
              goto LABEL_376;
            case 0x40Cu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v217,
                L"You don't have enough experience available to swear Allegiance");
              ClientSystem::AddTextToScroll(v4, &v217, 0x1Au, 1, 0);
              v7 = &v217;
              goto LABEL_376;
            case 0x40Bu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v71, L"You've already sworn your Allegiance");
              ClientSystem::AddTextToScroll(v4, &v71, 0x1Au, 1, 0);
              v7 = &v71;
              goto LABEL_376;
            case 0x414u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v169, L"You are not in an allegiance!");
              ClientSystem::AddTextToScroll(v4, &v169, 0x1Au, 1, 0);
              v7 = &v169;
              goto LABEL_376;
            case 0x416u:
              PStringBase<unsigned short>::sprintf(&msg, L"%s cannot have any more Vassals", user_data->m_charbuffer);
              goto LABEL_130;
            case 0x413u:
              PStringBase<unsigned short>::sprintf(
                &msg,
                L"%s is already one of your followers",
                user_data->m_charbuffer);
              goto LABEL_345;
            case 0x41Du:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v73, L"You must be the leader of a Fellowship");
              ClientSystem::AddTextToScroll(v4, &v73, 0x1Au, 1, 0);
              v7 = &v73;
              goto LABEL_376;
            case 0x41Eu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v250, L"Your Fellowship is full");
              ClientSystem::AddTextToScroll(v4, &v250, 0x1Au, 1, 0);
              v7 = &v250;
              goto LABEL_376;
            case 0x41Fu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v75, L"That Fellowship name is not permitted");
              ClientSystem::AddTextToScroll(v4, &v75, 0x1Au, 1, 0);
              v7 = &v75;
              goto LABEL_376;
            case 0x422u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v171, L"That channel doesn't exist.");
              ClientSystem::AddTextToScroll(v4, &v171, 0x1Au, 1, 0);
              v7 = &v171;
              goto LABEL_376;
            case 0x423u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v77, L"You can't use that channel.");
              ClientSystem::AddTextToScroll(v4, &v77, 0x1Au, 1, 0);
              v7 = &v77;
              goto LABEL_376;
            case 0x424u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v219, L"You're already on that channel.");
              ClientSystem::AddTextToScroll(v4, &v219, 0x1Au, 1, 0);
              v7 = &v219;
              goto LABEL_376;
            case 0x425u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v79, L"You're not currently on that channel.");
              ClientSystem::AddTextToScroll(v4, &v79, 0x1Au, 1, 0);
              v7 = &v79;
              goto LABEL_376;
            case 0x432u:
            case 0x433u:
            case 0x435u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v173, L"Your craft attempt fails.");
              ClientSystem::AddTextToScroll(v4, &v173, 0x1Au, 1, 0);
              v7 = &v173;
              goto LABEL_376;
            case 0x439u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v81, L"Not all the items are avaliable.");
              ClientSystem::AddTextToScroll(v4, &v81, 0x1Au, 1, 0);
              v7 = &v81;
              goto LABEL_376;
            case 0x437u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v243,
                L"Either you or one of the items involved does not pass the requirements for this craft interaction.");
              ClientSystem::AddTextToScroll(v4, &v243, 0x1Au, 1, 0);
              v7 = &v243;
              goto LABEL_376;
            case 0x434u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v83,
                L"Given that number of items, you cannot craft anything.");
              ClientSystem::AddTextToScroll(v4, &v83, 0x1Au, 1, 0);
              v7 = &v83;
              goto LABEL_376;
            case 0x438u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v175,
                L"You do not have all the neccessary items.");
              ClientSystem::AddTextToScroll(v4, &v175, 0x1Au, 1, 0);
              v7 = &v175;
              goto LABEL_376;
            case 0x43Au:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v85,
                L"You must be at rest in peace mode to do trade skills.");
              ClientSystem::AddTextToScroll(v4, &v85, 0x1Au, 1, 0);
              v7 = &v85;
              goto LABEL_376;
            case 0x43Bu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v221,
                L"You are not trained in that trade skill.");
              ClientSystem::AddTextToScroll(v4, &v221, 0x1Au, 1, 0);
              v7 = &v221;
              goto LABEL_376;
            case 0x43Cu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v87, L"Your hands must be free.");
              ClientSystem::AddTextToScroll(v4, &v87, 0x1Au, 1, 0);
              v7 = &v87;
              goto LABEL_376;
            case 0x47Fu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v177,
                L"You must own a house to use this command.");
              ClientSystem::AddTextToScroll(v4, &v177, 0x1Au, 1, 0);
              v7 = &v177;
              goto LABEL_376;
            case 0x45Eu:
            case 0x45Fu:
              PStringBase<unsigned short>::PStringBase<unsigned short>(&v89, L"You do not own a house!");
              ClientSystem::AddTextToScroll(v4, &v89, 0x1Au, 1, 0);
              v7 = &v89;
              goto LABEL_376;
            case 0x480u:
            case 0x481u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v252,
                L"Your monarch does not own a mansion or a villa!");
              ClientSystem::AddTextToScroll(v4, &v252, 0x1Au, 1, 0);
              v7 = &v252;
              goto LABEL_376;
            case 0x482u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v91,
                L"Your monarch has closed the mansion to the Allegiance.");
              ClientSystem::AddTextToScroll(v4, &v91, 0x1Au, 1, 0);
              v7 = &v91;
              goto LABEL_376;
            case 0x469u:
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &v179,
                L"You have used all the hooks you are allowed to use for this house.\n");
              ClientSystem::AddTextToScroll(v4, &v179, 0, 1, 0);
              v7 = &v179;
              goto LABEL_376;
            case 0x488u:
              PStringBase<unsigned short>::sprintf(
                &msg,
                L"You must be above level %s to purchase this dwelling.\n",
                user_data->m_charbuffer);
              goto LABEL_210;
            case 0x489u:
              PStringBase<unsigned short>::sprintf(
                &msg,
                L"You must be at or below level %s to purchase this dwelling.\n",
                user_data->m_charbuffer);
              goto LABEL_207;
            default:
              goto LABEL_377;
          }
          goto LABEL_377;
        }
        if ( etype == 1032 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v161, L"Your spell cannot be cast inside");
          ClientSystem::AddTextToScroll(v4, &v161, 0x1Au, 1, 0);
          v7 = &v161;
        }
        else
        {
          if ( etype <= 0x4F )
          {
            if ( etype == 79 )
            {
              PStringBase<unsigned short>::sprintf(
                &msg,
                L"You fail to affect %s because $s cannot be harmed!\n",
                user_data->m_charbuffer,
                user_data->m_charbuffer);
LABEL_46:
              ClientSystem::AddTextToScroll(v4, &msg, 7u, 1, 0);
            }
            else
            {
              switch ( etype )
              {
                case 0x1Du:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"You're too busy!");
                  ClientSystem::AddTextToScroll(v4, &i_text, 0x1Au, 1, 0);
                  v7 = &i_text;
                  goto LABEL_376;
                case 0x3Au:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v27, L"You can't do that... you're dead!");
                  ClientSystem::AddTextToScroll(v4, &v27, 0x1Au, 1, 0);
                  v7 = &v27;
                  goto LABEL_376;
                case 0x17u:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(
                    &v147,
                    L"You failed to go to non-combat mode.");
                  ClientSystem::AddTextToScroll(v4, &v147, 0x1Au, 1, 0);
                  v7 = &v147;
                  goto LABEL_376;
                case 0x20u:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v29, L"You must control both objects!");
                  ClientSystem::AddTextToScroll(v4, &v29, 0x1Au, 1, 0);
                  v7 = &v29;
                  goto LABEL_376;
                case 0x23u:
                case 0x37u:
                case 0x38u:
                case 0x39u:
                  v8 = ClientUISystem::GetUISystem();
                  ClientUISystem::SetGroundObject(v8, 0, 1);
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v207, L"Unable to move to object!");
                  ClientSystem::AddTextToScroll(v4, &v207, 0x1Au, 1, 0);
                  v7 = &v207;
                  goto LABEL_376;
                case 0x3Du:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v31, L"You charged too far!");
                  ClientSystem::AddTextToScroll(v4, &v31, 0x1Au, 1, 0);
                  v7 = &v31;
                  goto LABEL_376;
                case 0x36u:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v149, L"Action cancelled!");
                  ClientSystem::AddTextToScroll(v4, &v149, 0x1Au, 1, 0);
                  v7 = &v149;
                  goto LABEL_376;
                case 0x28u:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(
                    &v33,
                    L"The item is under someone else's control!");
                  ClientSystem::AddTextToScroll(v4, &v33, 0x1Au, 1, 0);
                  v7 = &v33;
                  goto LABEL_376;
                case 0x29u:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v237, L"You cannot pick that up!");
                  ClientSystem::AddTextToScroll(v4, &v237, 0x1Au, 1, 0);
                  v7 = &v237;
                  goto LABEL_376;
                case 0x2Au:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(
                    &v35,
                    L"You are too encumbered to carry that!");
                  ClientSystem::AddTextToScroll(v4, &v35, 0x1Au, 1, 0);
                  v7 = &v35;
                  goto LABEL_376;
                case 0x3Eu:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v151, L"You are too tired to do that!");
                  ClientSystem::AddTextToScroll(v4, &v151, 0x1Au, 1, 0);
                  v7 = &v151;
                  goto LABEL_376;
                case 0x26u:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v37, L"That is not a valid command.");
                  ClientSystem::AddTextToScroll(v4, &v37, 0x1Au, 1, 0);
                  v7 = &v37;
                  goto LABEL_376;
                case 0x2Bu:
                  PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&rhs, L" cannot carry anymore.\n");
                  PStringBase<unsigned short>::operator+=(&msg, &rhs);
                  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
                  goto LABEL_366;
                case 0x4Du:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v39, L"Invalid PK status!");
                  ClientSystem::AddTextToScroll(v4, &v39, 0x1Au, 1, 0);
                  v7 = &v39;
                  goto LABEL_376;
                case 0x4Eu:
                  PStringBase<unsigned short>::sprintf(
                    &msg,
                    L"You fail to affect %s because you cannot affect anyone!\n",
                    user_data->m_charbuffer);
                  ClientSystem::AddTextToScroll(v4, &msg, 7u, 1, 0);
                  goto LABEL_377;
                case 0x4Au:
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&v153, L"Ack! You killed yourself!\n");
                  ClientSystem::AddTextToScroll(v4, &v153, 0, 1, 0);
                  v7 = &v153;
                  goto LABEL_376;
                case 0x48u:
                  ClientSystem::AddTextToScroll(v4, &cant_jump_position_0, 0x1Au, 1, 0);
                  goto LABEL_377;
                case 0x49u:
                  ClientSystem::AddTextToScroll(v4, &cant_jump_load_0, 0x1Au, 1, 0);
                  goto LABEL_377;
                case 0x24u:
                  ClientSystem::AddTextToScroll(v4, &cant_jump_in_air_0, 0x1Au, 1, 0);
                  goto LABEL_377;
                case 0x1Eu:
                  goto $L188165;
                default:
                  goto LABEL_377;
              }
            }
            goto LABEL_377;
          }
          if ( etype > 0x3EE )
          {
            switch ( etype )
            {
              case 0x3F1u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v246, L"You failed to go to non-combat mode.");
                ClientSystem::AddTextToScroll(v4, &v246, 0x1Au, 1, 0);
                v7 = &v246;
                goto LABEL_376;
              case 0x3F7u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v43, L"You are too fatigued to attack!");
                ClientSystem::AddTextToScroll(v4, &v43, 0x1Au, 1, 0);
                v7 = &v43;
                goto LABEL_376;
              case 0x3F8u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v155, L"You are out of ammunition!");
                ClientSystem::AddTextToScroll(v4, &v155, 0x1Au, 1, 0);
                v7 = &v155;
                goto LABEL_376;
              case 0x3F9u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v45, L"Your missile attack misfired!");
                ClientSystem::AddTextToScroll(v4, &v45, 0x1Au, 1, 0);
                v7 = &v45;
                goto LABEL_376;
              case 0x3EFu:
                PStringBase<unsigned short>::operator=(&msg, (const unsigned __int16 *)user_data);
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v211, L" is not accepting gifts right now.\n");
                PStringBase<unsigned short>::operator+=(&msg, &v211);
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v211);
                goto LABEL_366;
              case 0x3FEu:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v47, L"You don't know that spell!");
                ClientSystem::AddTextToScroll(v4, &v47, 0x1Au, 1, 0);
                v7 = &v47;
                goto LABEL_376;
              case 0x3FFu:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v157, L"Incorrect target type");
                ClientSystem::AddTextToScroll(v4, &v157, 0x1Au, 1, 0);
                v7 = &v157;
                goto LABEL_376;
              case 0x400u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(
                  &v49,
                  L"You don't have all the components for this spell.");
                ClientSystem::AddTextToScroll(v4, &v49, 0x1Au, 1, 0);
                v7 = &v49;
                goto LABEL_376;
              case 0x401u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(
                  &v239,
                  L"You don't have enough Mana to cast this spell.");
                ClientSystem::AddTextToScroll(v4, &v239, 0x1Au, 1, 0);
                v7 = &v239;
                goto LABEL_376;
              case 0x402u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v51, L"Your spell fizzled.\n");
                ClientSystem::AddTextToScroll(v4, &v51, 7u, 1, 0);
                v7 = &v51;
                goto LABEL_376;
              case 0x403u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v159, L"Your spell's target is missing!");
                ClientSystem::AddTextToScroll(v4, &v159, 0x1Au, 1, 0);
                v7 = &v159;
                goto LABEL_376;
              case 0x404u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v53, L"Your projectile spell mislaunched!");
                ClientSystem::AddTextToScroll(v4, &v53, 0x1Au, 1, 0);
                v7 = &v53;
                goto LABEL_376;
              case 0x3FAu:
                PStringBase<unsigned short>::PStringBase<unsigned short>(
                  &v213,
                  L"You've attempted an impossible spell path!");
                ClientSystem::AddTextToScroll(v4, &v213, 0x1Au, 1, 0);
                v7 = &v213;
                goto LABEL_376;
              case 0x407u:
                PStringBase<unsigned short>::PStringBase<unsigned short>(&v55, L"Your spell cannot be cast outside");
                ClientSystem::AddTextToScroll(v4, &v55, 0x1Au, 1, 0);
                v7 = &v55;
                goto LABEL_376;
              default:
                goto LABEL_377;
            }
            goto LABEL_377;
          }
          if ( etype != 1006 )
          {
            switch ( etype )
            {
              case 0x50u:
                PStringBase<unsigned short>::sprintf(
                  &msg,
                  L"You fail to affect %s because beneficial spells do not affect %s!\n",
                  user_data->m_charbuffer,
                  user_data->m_charbuffer);
                goto LABEL_48;
              case 0x51u:
                PStringBase<unsigned short>::sprintf(
                  &msg,
                  L"You fail to affect %s because you are not a player killer!\n",
                  user_data->m_charbuffer);
                goto LABEL_224;
              case 0x52u:
                PStringBase<unsigned short>::sprintf(
                  &msg,
                  L"You fail to affect %s because %s is not a player killer!\n",
                  user_data->m_charbuffer,
                  user_data->m_charbuffer);
                goto LABEL_46;
              case 0x53u:
                PStringBase<unsigned short>::sprintf(
                  &msg,
                  L"You fail to affect %s because you are not the same sort of player killer as %s!\n",
                  user_data->m_charbuffer,
                  user_data->m_charbuffer);
                goto LABEL_48;
              case 0x54u:
                PStringBase<unsigned short>::sprintf(
                  &msg,
                  L"You fail to affect %s because you are acting across a house boundary!\n",
                  user_data->m_charbuffer);
                goto LABEL_224;
              default:
                goto LABEL_377;
            }
            goto LABEL_377;
          }
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v41, L"The container is closed!");
          ClientSystem::AddTextToScroll(v4, &v41, 0x1Au, 1, 0);
          v7 = &v41;
        }
      }
LABEL_376:
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v7);
      goto LABEL_377;
    }
    PStringBase<unsigned short>::sprintf(
      &msg,
      L"The %s cannot be used while on a hook and only the owner may open the hook.\n",
      user_data->m_charbuffer);
LABEL_210:
    ClientSystem::AddTextToScroll(v4, &msg, 0, 1, 0);
  }
LABEL_377:
  v23 = (char *)&msg.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1].m_data[8]) )
  {
    if ( v23 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  }
}
// 7D17E8: using guessed type wchar_t aCongratulation[71];
// 7D1878: using guessed type wchar_t aS_11[4];
// 7D1A88: using guessed type wchar_t aAlthoughYourAu[149];
// 7D1D48: using guessed type wchar_t aTheSCanOnlyBeU[42];
// 7D1F68: using guessed type wchar_t aTheSCannotBe_2[101];
// 7D2820: using guessed type wchar_t aYouFailToRemov[44];
// 7D2C28: using guessed type wchar_t aYouHavePassedL[52];
// 7D3000: using guessed type wchar_t aSFailsToAffe_0[59];
// 7D30E8: using guessed type wchar_t aSFailsToAffect[57];
// 7D38D0: using guessed type wchar_t aYouAreNotListe[42];
// 7D3990: using guessed type wchar_t aYouMustWaitSBe[46];
// 7D39EC: using guessed type wchar_t aYouHaveLeftThe[31];
// 7D3A30: using guessed type wchar_t aYouHaveEntered[34];
// 7D3A78: using guessed type wchar_t aThatCharacte_2[45];
// 7D3AD8: using guessed type wchar_t aSIsAlreadyOnYo[37];
// 7D3C88: using guessed type wchar_t aSHasBeenPreApp[51];
// 7D3CF0: using guessed type wchar_t aSIsAlreadyAMem[44];
// 7D3DC8: using guessed type wchar_t aYouHavePreAppr[51];
// 7D3E30: using guessed type wchar_t aYouMayNotSwear[83];
// 7D3ED8: using guessed type wchar_t aYouMayNotAccep[87];
// 7D3F88: using guessed type wchar_t aYourAllegian_7[29];
// 7D3FC8: using guessed type wchar_t aYourAllegian_6[35];
// 7D40C0: using guessed type wchar_t aYouMayOnlyChan[112];
// 7D44D8: using guessed type wchar_t aTheAccountOf_0[60];
// 7D4550: using guessed type wchar_t aTheAccountOfSH[56];
// 7D45C0: using guessed type wchar_t aTheAccountOfSW[57];
// 7D4638: using guessed type wchar_t aTheAccountOf_2[54];
// 7D46A8: using guessed type wchar_t aTheAccountOfSI[58];
// 7D4810: using guessed type wchar_t aYourAllegian_3[58];
// 7D4A20: using guessed type wchar_t aYourAllegian_0[152];
// 7D4BF0: using guessed type wchar_t aSHasBeenBooted[51];
// 7D4C58: using guessed type wchar_t aYouHaveBeenBoo[97];
// 7D4FC0: using guessed type wchar_t aThatLevelOfAll[55];
// 7D50E8: using guessed type wchar_t aAnUnspecifie_1[87];
// 7D5198: using guessed type wchar_t aSIsNoLongerAnA[40];
// 7D52C0: using guessed type wchar_t aSIsAlreadyAnAl[52];
// 7D5328: using guessed type wchar_t aSIsTheMonarchA[54];
// 7D5398: using guessed type wchar_t aAnUnspecifiedE[84];
// 7D5440: using guessed type wchar_t aYourAllegia_10[85];
// 7D54F0: using guessed type wchar_t aSIsNowAnAllegi[34];
// 7D55E8: using guessed type wchar_t aYouAreBannedFr[38];
// 7D5638: using guessed type wchar_t aSIsBannedFromT[35];
// 7D5C80: using guessed type wchar_t aSIsInLimboAndC[49];
// 7D5CE8: using guessed type wchar_t aSIsAlreadyBein[81];
// 7D5D8C: using guessed type wchar_t aSAttemptedToSn[31];
// 7D5E00: using guessed type wchar_t aYouAreNoLong_1[35];
// 7D5F30: using guessed type wchar_t aTheSCannotBeUs[77];
// 7D6218: using guessed type wchar_t aAlthoughYouCan[120];
// 7D6308: using guessed type wchar_t aYouHaveSucce_2[49];
// 7D6370: using guessed type wchar_t aYouHaveSucce_3[75];
// 7D6408: using guessed type wchar_t aYouHaveSucceed[51];
// 7D6470: using guessed type wchar_t aYouHaveTooMa_1[156];
// 7D6718: using guessed type wchar_t aYourSSkillIsAl[37];
// 7D6768: using guessed type wchar_t aYouHaveTooMany[169];
// 7D68C0: using guessed type wchar_t aYouDoNotHaveEn[67];
// 7D6948: using guessed type wchar_t aYourSSkillMust[98];
// 7D6A60: using guessed type wchar_t aYouMustBeAtO_1[71];
// 7D6AF0: using guessed type wchar_t aYouMustBeAbo_1[65];
// 7D7FD0: using guessed type wchar_t aYouMustHaveSSp[55];
// 7D8088: using guessed type wchar_t aYourSIsTooLowT[45];
// 7D81A8: using guessed type wchar_t aYouMustBeSToUs[41];
// 7D8748: using guessed type wchar_t aYouMustBeAtOrB[61];
// 7D87C8: using guessed type wchar_t aYouMustBeAbove[55];
// 7D8EE8: using guessed type wchar_t aSIsAlreadyOneO[36];
// 7D8F30: using guessed type wchar_t aSCannotHaveAny[32];
// 7D9980: using guessed type wchar_t aYouFailToAff_2[71];
// 7D9B30: using guessed type wchar_t aYouFailToAff_4[60];
// 7D9BA8: using guessed type wchar_t aYouFailToAff_3[67];
// 7D9C30: using guessed type wchar_t aYouFailToAff_1[52];

//----- (00575AC0) --------------------------------------------------------  // acclient.c:416169
PStringBase<char> *__cdecl JoinArgs(PStringBase<char> *result, int argc, char **argv)
{
  int v3; // ebx@1
  char **v4; // ebp@2
  PSRefBufferCharData<char> *v5; // ecx@3
  int v6; // eax@3
  int v7; // esi@5
  unsigned int v8; // edi@9
  int v9; // ecx@9
  char *v10; // esi@12
  PSRefBufferCharData<char> *v11; // eax@16
  char *v12; // esi@16
  PStringBase<char> strResult; // [sp+Ch] [bp-8h]@1
  PStringBase<char> v15; // [sp+10h] [bp-4h]@3

  strResult.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v3 = argc;
  if ( argc )
  {
    v4 = argv;
    while ( 1 )
    {
      PStringBase<char>::PStringBase<char>(&v15, *v4);
      v5 = v15.m_charbuffer;
      v6 = *(_DWORD *)&v15.m_charbuffer[-1].m_data[12];
      if ( v6 != 1 )
      {
        PStringBase<char>::append_n_chars(&strResult, v15.m_charbuffer->m_data, v6 - 1);
        v5 = v15.m_charbuffer;
      }
      v7 = (int)&v5[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      --v3;
      ++v4;
      if ( !v3 )
        break;
      LOBYTE(argc) = 32;
      v8 = *(_DWORD *)&strResult.m_charbuffer[-1].m_data[12];
      v9 = v8 + 1;
      if ( *(_DWORD *)&strResult.m_charbuffer[-1].m_data[0] != 1
        || (unsigned int)v9 > *(_DWORD *)&strResult.m_charbuffer[-1].m_data[4] )
      {
        v10 = &strResult.m_charbuffer[-2].m_data[12];
        PStringBase<char>::allocate_ref_buffer(&strResult, v8);
        strcpy(strResult.m_charbuffer->m_data, v10 + 20);
        if ( !InterlockedDecrement((volatile LONG *)v10 + 1) )
        {
          if ( v10 )
            (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
        }
      }
      else
      {
        *(_DWORD *)&strResult.m_charbuffer[-1].m_data[12] = v9;
        *(_DWORD *)&strResult.m_charbuffer[-1].m_data[8] = -1;
      }
      _strncpy((char *)strResult.m_charbuffer + v8 - 1, (const char *)&argc, 1u);
      strResult.m_charbuffer->m_data[*(_DWORD *)&strResult.m_charbuffer[-1].m_data[12] - 1] = 0;
    }
  }
  v11 = strResult.m_charbuffer;
  result->m_charbuffer = strResult.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v11[-1]);
  v12 = &strResult.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strResult.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  return result;
}

//----- (00575C10) --------------------------------------------------------  // acclient.c:416241
PStringBase<char> *__cdecl JoinArgsAsName(PStringBase<char> *result, int argc, char **argv)
{
  PSRefBufferCharData<char> *v3; // ecx@0
  PSRefBufferCharData<char> *v4; // ecx@1
  PSRefBufferCharData<char> *v5; // eax@1
  char *v6; // esi@1
  int v7; // eax@3
  PStringBase<char> v9; // [sp-10h] [bp-14h]@1
  PStringBase<char> name; // [sp+0h] [bp-4h]@1

  name.m_charbuffer = v3;
  JoinArgs(&name, argc, argv);
  v9.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
  PStringBase<char>::trim(&name, 1, 1, v9);
  v9.m_charbuffer = v4;
  PStringBase<char>::allocate_ref_buffer(&v9, 1u);
  v9.m_charbuffer->m_data[0] = 43;
  v9.m_charbuffer->m_data[1] = 0;
  PStringBase<char>::trim(&name, 1, 0, v9);
  v5 = name.m_charbuffer;
  result->m_charbuffer = name.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v5[-1]);
  v6 = &name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]) && v6 )
  {
    v7 = *(_DWORD *)v6;
    v9.m_charbuffer = (PSRefBufferCharData<char> *)1;
    (*(void (__thiscall **)(char *, signed int))v7)(v6, 1);
  }
  return result;
}

//----- (00575CB0) --------------------------------------------------------  // acclient.c:416275
char __thiscall ClientCommunicationSystem::DoAllegianceChat(ClientCommunicationSystem *this, int argc, char **argv)
{
  char *v3; // edi@1
  int v4; // eax@4
  char *v5; // edi@4
  bool v6; // bl@4
  CPlayerSystem *v7; // eax@8
  char *v8; // edi@9
  bool v9; // zf@10
  int v11; // eax@13
  char *v12; // edi@13
  bool v13; // bl@13
  CPlayerSystem *v14; // eax@17
  int v15; // eax@18
  char *v16; // edi@18
  bool v17; // bl@18
  char *v18; // edi@22
  unsigned int v19; // edi@26
  const unsigned __int16 *v20; // eax@29
  PStringBase<char> v21; // ST10_4@32
  PSRefBufferCharData<char> *v22; // edi@33
  PSRefBufferCharData<char> *v23; // edi@36
  char **v24; // edi@39
  int v25; // edi@42
  int v26; // eax@47
  char *v27; // edi@47
  bool v28; // bl@47
  int *v29; // eax@51
  int v30; // esi@51
  volatile LONG *v31; // ST10_4@51
  CaseInsensitiveStringBase<PStringBase<char> > *v32; // ecx@52
  bool v33; // bl@54
  PStringBase<char> *v34; // eax@55
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+24h] [bp-20h]@1
  PStringBase<char> rhs; // [sp+28h] [bp-1Ch]@4
  PStringBase<char> result; // [sp+2Ch] [bp-18h]@1
  PStringBase<char> v38; // [sp+30h] [bp-14h]@1
  PStringBaseIter<char> iter; // [sp+34h] [bp-10h]@25

  v38.m_charbuffer = (PSRefBufferCharData<char> *)this;
  command.m_charbuffer = NextArg(&result, &argc, &argv)->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&command.m_charbuffer[-1]);
  v3 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&rhs, "on");
  v4 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &rhs, 0);
  v5 = &rhs.m_charbuffer[-2].m_data[12];
  v6 = v4 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  if ( v6 )
  {
    v7 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearAllegianceChat((PlayerModule *)&v7->playerModule.vfptr, 1);
    goto LABEL_9;
  }
  PStringBase<char>::PStringBase<char>(&rhs, "off");
  v11 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &rhs, 0);
  v12 = &rhs.m_charbuffer[-2].m_data[12];
  v13 = v11 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  if ( v13 )
  {
    v14 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetHearAllegianceChat((PlayerModule *)&v14->playerModule.vfptr, 0);
LABEL_9:
    v8 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) )
    {
      v9 = v8 == 0;
      goto LABEL_11;
    }
    return 1;
  }
  PStringBase<char>::PStringBase<char>(&rhs, "kick");
  v15 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &rhs, 0);
  v16 = &rhs.m_charbuffer[-2].m_data[12];
  v17 = v15 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  if ( v17 )
  {
    argc = (int)JoinArgs(&v38, argc, argv)->m_charbuffer;
    InterlockedIncrement((volatile LONG *)(argc - 16));
    v18 = &v38.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v38.m_charbuffer[-1]) && v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
    iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
    iter.pstring_ptr = (PStringBase<char> *)&argc;
    iter.mark = 0;
    iter.curr = 0;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "No reason given.");
    if ( PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter.vfptr, 44, 0) )
    {
      v19 = iter.curr + 1;
      if ( v19 <= iter.vfptr->GetStrLen(&iter) )
        iter.curr = v19;
      else
        iter.curr = iter.vfptr->GetStrLen(&iter);
      PStringBaseIter_Common<unsigned short>::SetMark(
        (PStringBaseIter_Common<unsigned short> *)&iter,
        *(_DWORD *)&iter.pstring_ptr->m_charbuffer[-1].m_data[12] - 1);
      v20 = (const unsigned __int16 *)PStringBaseIter_Common<char>::GetSubString(
                                        (PStringBaseIter_Common<char> *)&iter.vfptr,
                                        &v38);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&argv, v20);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v38);
      if ( iter.curr >= 1 )
        --iter.curr;
      else
        iter.curr = 0;
      PStringBaseIter<char>::Truncate(&iter);
      v21.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
      PStringBase<char>::trim((PStringBase<char> *)&argv, 1, 1, v21);
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&result, (const char *)argv);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&rhs, (const char *)argc);
    CM_Allegiance::Event_AllegianceChatBoot(
      (AC1Legacy::PStringBase<char> *)&rhs,
      (AC1Legacy::PStringBase<char> *)&result);
    v22 = rhs.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer->m_data[4]) && v22 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v22->m_data[0])(v22, 1);
    v23 = result.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer->m_data[4]) && v23 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v23->m_data[0])(v23, 1);
    v24 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v24 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v24)(v24, 1);
    v25 = argc - 20;
    iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v25 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
    }
    v8 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) )
    {
      v9 = v8 == 0;
LABEL_11:
      if ( !v9 )
      {
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        return 1;
      }
    }
    return 1;
  }
  PStringBase<char>::PStringBase<char>(&result, "gag");
  v26 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v27 = &result.m_charbuffer[-2].m_data[12];
  v28 = v26 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v27 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
  if ( v28 )
  {
    v29 = (int *)JoinArgs((PStringBase<char> *)&argv, argc, argv);
    v31 = (volatile LONG *)(*v29 - 16);
    argc = *v29;
    v30 = argc;
    InterlockedIncrement(v31);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    if ( *(_DWORD *)(v30 - 4) == 1 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argv,
        L"Please specify an actual name.");
      ClientSystem::AddTextToScroll(
        (ClientSystem *)v38.m_charbuffer,
        (PStringBase<unsigned short> *)&argv,
        0x1Au,
        1,
        *(_DWORD *)&v38.m_charbuffer[8].m_data[12]);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      v32 = (CaseInsensitiveStringBase<PStringBase<char> > *)&argc;
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)v30);
      CM_Allegiance::Event_AllegianceChatGag((AC1Legacy::PStringBase<char> *)&argv, 1);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argv);
      v32 = (CaseInsensitiveStringBase<PStringBase<char> > *)&argc;
    }
LABEL_58:
    PStringBase<char>::~PStringBase<char>(v32);
    PStringBase<char>::~PStringBase<char>(&command);
    return 1;
  }
  PStringBase<char>::PStringBase<char>(&result, "ungag");
  v33 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v33 )
  {
    v34 = JoinArgs((PStringBase<char> *)&argc, argc, argv);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)&argv,
      v34);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
    if ( *(argv - 1) == (char *)1 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"Please specify an actual name.");
      ClientSystem::AddTextToScroll(
        (ClientSystem *)v38.m_charbuffer,
        (PStringBase<unsigned short> *)&argc,
        0x1Au,
        1,
        *(_DWORD *)&v38.m_charbuffer[8].m_data[12]);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      PStringBase<char>::~PStringBase<char>(&command);
      return 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
    CM_Allegiance::Event_AllegianceChatGag((AC1Legacy::PStringBase<char> *)&argc, 0);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argc);
    v32 = (CaseInsensitiveStringBase<PStringBase<char> > *)&argv;
    goto LABEL_58;
  }
  PStringBase<char>::~PStringBase<char>(&command);
  return 0;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (005761F0) --------------------------------------------------------  // acclient.c:416506
bool __stdcall ClientCommunicationSystem::DoAllegianceBroadcast(int argc, char **argv)
{
  char **v3; // edi@1
  bool v4; // bl@2
  char **v5; // esi@2
  bool result; // al@8
  char **v7; // esi@9

  JoinArgs((PStringBase<char> *)&argv, argc, argv);
  v3 = argv;
  if ( *(argv - 1) == (char *)1 )
  {
    v7 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v3 != (char **)20 )
      (*(void (__thiscall **)(char **, signed int))*v7)(v3 - 5, 1);
    result = 0;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argv);
    v4 = CM_Communication::Event_ChannelBroadcast(0x2000000u, (AC1Legacy::PStringBase<char> *)&argv);
    v5 = argv;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v5 )
      (*(void (__thiscall **)(char **, signed int))*v5)(v5, 1);
    if ( !InterlockedDecrement((volatile LONG *)v3 - 4) && v3 != (char **)20 )
      (*(void (__thiscall **)(char **, signed int))*(v3 - 5))(v3 - 5, 1);
    result = v4;
  }
  return result;
}

//----- (005762A0) --------------------------------------------------------  // acclient.c:416538
char __thiscall ClientCommunicationSystem::DoAllegianceBan(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // ebp@1
  char *v4; // edi@1
  int v5; // eax@4
  char *v6; // edi@4
  bool v7; // bl@4
  bool v8; // bl@8
  char **v9; // ebx@9
  char **v10; // edi@10
  char *v11; // edi@16
  char v12; // al@19
  int v13; // eax@20
  int v14; // edi@20
  bool v15; // bl@20
  char **v16; // ebp@24
  bool v17; // al@24
  char **v18; // edi@24
  char *v19; // edi@30
  int v20; // eax@34
  int v21; // edi@34
  bool v22; // bl@34
  bool v23; // bl@38
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+14h] [bp-8h]@1
  PStringBase<char> result; // [sp+18h] [bp-4h]@1

  v3 = this;
  command.m_charbuffer = NextArg(&result, &argc, &argv)->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&command.m_charbuffer[-1]);
  v4 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&result, "list");
  v5 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v6 = &result.m_charbuffer[-2].m_data[12];
  v7 = v5 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  if ( v7 )
  {
    v8 = CM_Allegiance::Event_ListAllegianceBans();
LABEL_30:
    v19 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) )
    {
      if ( v19 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    }
    return v8;
  }
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  v9 = argv;
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      L"Please specify an actual name.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argv,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v10 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v10 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v10)(v10, 1);
    if ( !InterlockedDecrement((volatile LONG *)v9 - 4) && v9 != (char **)20 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*(v9 - 5))(v9 - 5, 1);
    v11 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v12 = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "add");
    v13 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, (PStringBase<char> *)&argc, 0);
    v14 = argc - 20;
    v15 = v13 == 0;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    if ( v15 )
    {
      v16 = argv;
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argv);
      v17 = CM_Allegiance::Event_AddAllegianceBan((AC1Legacy::PStringBase<char> *)&argv);
      v18 = argv;
      v8 = v17;
      if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v18 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v18)(v18, 1);
      if ( !InterlockedDecrement((volatile LONG *)v16 - 4) && v16 != (char **)20 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*(v16 - 5))(v16 - 5, 1);
      goto LABEL_30;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "remove");
    v20 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, (PStringBase<char> *)&argc, 0);
    v21 = argc - 20;
    v22 = v20 == 0;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v21 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    if ( v22 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
      v23 = CM_Allegiance::Event_RemoveAllegianceBan((AC1Legacy::PStringBase<char> *)&argc);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      PStringBase<char>::~PStringBase<char>(&command);
      v12 = v23;
    }
    else
    {
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      PStringBase<char>::~PStringBase<char>(&command);
      v12 = 0;
    }
  }
  return v12;
}

//----- (00576560) --------------------------------------------------------  // acclient.c:416658
char __thiscall ClientCommunicationSystem::DoAllegianceInfo(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char **v4; // edi@1
  char **v5; // esi@2
  char result; // al@8
  bool v7; // bl@9
  char **v8; // esi@9

  v3 = this;
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  v4 = argv;
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      L"Please specify an actual name.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argv,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v5 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v5 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
    if ( !InterlockedDecrement((volatile LONG *)v4 - 4) && v4 != (char **)20 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*(v4 - 5))(v4 - 5, 1);
    result = 1;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argv);
    v7 = CM_Allegiance::Event_AllegianceInfoRequest((AC1Legacy::PStringBase<char> *)&argv);
    v8 = argv;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v8 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v8)(v8, 1);
    if ( !InterlockedDecrement((volatile LONG *)v4 - 4) && v4 != (char **)20 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*(v4 - 5))(v4 - 5, 1);
    result = v7;
  }
  return result;
}

//----- (00576650) --------------------------------------------------------  // acclient.c:416703
bool __thiscall ClientCommunicationSystem::DoAllegianceOfficer(ClientCommunicationSystem *this, int argc, char **argv)
{
  PSRefBufferCharData<char> **v4; // eax@3
  PSRefBufferCharData<char> *v5; // ebp@3
  volatile LONG *v6; // ST14_4@3
  char *v7; // edi@3
  int v8; // eax@6
  char *v9; // edi@6
  bool v10; // bl@6
  bool v11; // al@10
  bool v12; // bl@11
  int v13; // eax@15
  char *v14; // edi@15
  bool v15; // bl@15
  int v16; // eax@20
  char *v17; // edi@20
  bool v18; // bl@20
  CaseInsensitiveStringBase<PStringBase<char> > *v19; // ecx@25
  bool v20; // bl@27
  bool v21; // bl@29
  __int32 v22; // eax@32
  unsigned int v23; // esi@32
  bool v24; // bl@36
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+10h] [bp-10h]@3
  PStringBase<char> levelStr; // [sp+14h] [bp-Ch]@6
  ClientSystem *v27; // [sp+18h] [bp-8h]@1
  PStringBase<char> result; // [sp+1Ch] [bp-4h]@3

  v27 = (ClientSystem *)this;
  if ( !argc )
    return CM_Allegiance::Event_ListAllegianceOfficers();
  v4 = (PSRefBufferCharData<char> **)NextArg(&result, &argc, &argv);
  v5 = *v4;
  v6 = (volatile LONG *)&(*v4)[-1];
  command.m_charbuffer = *v4;
  InterlockedIncrement(v6);
  v7 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  PStringBase<char>::PStringBase<char>(&levelStr, "list");
  v8 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &levelStr, 0);
  v9 = &levelStr.m_charbuffer[-2].m_data[12];
  v10 = v8 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&levelStr.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  if ( v10 )
  {
    v11 = CM_Allegiance::Event_ListAllegianceOfficers();
  }
  else
  {
    PStringBase<char>::PStringBase<char>(&levelStr, "clear");
    v13 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &levelStr, 0);
    v14 = &levelStr.m_charbuffer[-2].m_data[12];
    v15 = v13 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&levelStr.m_charbuffer[-1]) && v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
    if ( !v15 )
    {
      PStringBase<char>::PStringBase<char>(&levelStr, "remove");
      v16 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &levelStr, 0);
      v17 = &levelStr.m_charbuffer[-2].m_data[12];
      v18 = v16 == 0;
      if ( !InterlockedDecrement((volatile LONG *)&levelStr.m_charbuffer[-1]) && v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      if ( v18 )
      {
        JoinArgsAsName((PStringBase<char> *)&argc, argc, argv);
        if ( *(_DWORD *)(argc - 4) != 1 )
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argc);
          v20 = CM_Allegiance::Event_RemoveAllegianceOfficer((AC1Legacy::PStringBase<char> *)&argv);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argv);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          PStringBase<char>::~PStringBase<char>(&command);
          return v20;
        }
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&argv,
          L"Please specify the name of an allegiance member.");
        ClientSystem::AddTextToScroll(v27, (PStringBase<unsigned short> *)&argv, 0x1Au, 1, (unsigned int)v27[17].vfptr);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
        v19 = (CaseInsensitiveStringBase<PStringBase<char> > *)&argc;
      }
      else
      {
        PStringBase<char>::PStringBase<char>(&result, "set");
        if ( !PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0)
          || (PStringBase<char>::PStringBase<char>(&levelStr, "add"),
              v21 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &levelStr, 0) == 0,
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&levelStr),
              v21) )
          v21 = 1;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        if ( !v21 )
        {
          PStringBase<char>::~PStringBase<char>(&command);
          return 0;
        }
        NextArg(&levelStr, &argc, &argv);
        v22 = _strtol(levelStr.m_charbuffer->m_data, 0, 0);
        v23 = v22;
        if ( v22 <= 0 || v22 > 3 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&argc,
            L"Please specify a valid officer level as a number between 1 and 3. Check the game help files for more information on officer levels.");
          ClientSystem::AddTextToScroll(
            v27,
            (PStringBase<unsigned short> *)&argc,
            0x1Au,
            1,
            (unsigned int)v27[17].vfptr);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          v19 = (CaseInsensitiveStringBase<PStringBase<char> > *)&levelStr;
        }
        else
        {
          JoinArgsAsName((PStringBase<char> *)&argc, argc, argv);
          if ( *(_DWORD *)(argc - 4) != 1 )
          {
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argc);
            v24 = CM_Allegiance::Event_SetAllegianceOfficer((AC1Legacy::PStringBase<char> *)&argv, v23);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argv);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&levelStr);
            PStringBase<char>::~PStringBase<char>(&command);
            return v24;
          }
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&argv,
            L"Please specify the name of an allegiance member.");
          ClientSystem::AddTextToScroll(
            v27,
            (PStringBase<unsigned short> *)&argv,
            0x1Au,
            1,
            (unsigned int)v27[17].vfptr);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          v19 = (CaseInsensitiveStringBase<PStringBase<char> > *)&levelStr;
        }
      }
      PStringBase<char>::~PStringBase<char>(v19);
      PStringBase<char>::~PStringBase<char>(&command);
      return 1;
    }
    v11 = CM_Allegiance::Event_ClearAllegianceOfficers();
  }
  v12 = v11;
  if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
  return v12;
}

//----- (00576A10) --------------------------------------------------------  // acclient.c:416859
bool __thiscall ClientCommunicationSystem::DoAllegianceOfficerTitle(ClientCommunicationSystem *this, int argc, char **argv)
{
  bool result; // al@2
  PSRefBufferCharData<char> **v4; // eax@3
  PSRefBufferCharData<char> *v5; // ebp@3
  volatile LONG *v6; // ST14_4@3
  char *v7; // edi@3
  int v8; // eax@6
  char *v9; // edi@6
  bool v10; // bl@6
  bool v11; // al@10
  bool v12; // bl@11
  int v13; // eax@15
  char *v14; // edi@15
  bool v15; // bl@15
  int v16; // eax@20
  char *v17; // edi@20
  bool v18; // bl@20
  __int32 v19; // eax@24
  unsigned int v20; // esi@24
  bool v21; // bl@26
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+10h] [bp-Ch]@3
  PStringBase<char> levelStr; // [sp+14h] [bp-8h]@3
  ClientSystem *v24; // [sp+18h] [bp-4h]@1

  v24 = (ClientSystem *)this;
  if ( !argc )
    return CM_Allegiance::Event_ListAllegianceOfficerTitles();
  v4 = (PSRefBufferCharData<char> **)NextArg(&levelStr, &argc, &argv);
  v5 = *v4;
  v6 = (volatile LONG *)&(*v4)[-1];
  command.m_charbuffer = *v4;
  InterlockedIncrement(v6);
  v7 = &levelStr.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&levelStr.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  PStringBase<char>::PStringBase<char>(&levelStr, "list");
  v8 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &levelStr, 0);
  v9 = &levelStr.m_charbuffer[-2].m_data[12];
  v10 = v8 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&levelStr.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  if ( v10 )
  {
    v11 = CM_Allegiance::Event_ListAllegianceOfficerTitles();
LABEL_11:
    v12 = v11;
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
    return v12;
  }
  PStringBase<char>::PStringBase<char>(&levelStr, "clear");
  v13 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &levelStr, 0);
  v14 = &levelStr.m_charbuffer[-2].m_data[12];
  v15 = v13 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&levelStr.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  if ( v15 )
  {
    v11 = CM_Allegiance::Event_ClearAllegianceOfficerTitles();
    goto LABEL_11;
  }
  PStringBase<char>::PStringBase<char>(&levelStr, "set");
  v16 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &levelStr, 0);
  v17 = &levelStr.m_charbuffer[-2].m_data[12];
  v18 = v16 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&levelStr.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
  if ( v18 )
  {
    NextArg(&levelStr, &argc, &argv);
    v19 = _strtol(levelStr.m_charbuffer->m_data, 0, 0);
    v20 = v19;
    if ( v19 <= 0 || v19 > 3 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"Please specify a valid officer level as a number between 1 and 3.");
      ClientSystem::AddTextToScroll(v24, (PStringBase<unsigned short> *)&argc, 0x1Au, 1, (unsigned int)v24[17].vfptr);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&levelStr);
      PStringBase<char>::~PStringBase<char>(&command);
      result = 1;
    }
    else
    {
      JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
      v21 = CM_Allegiance::Event_SetAllegianceOfficerTitle(v20, (AC1Legacy::PStringBase<char> *)&argc);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&levelStr);
      PStringBase<char>::~PStringBase<char>(&command);
      result = v21;
    }
  }
  else
  {
    PStringBase<char>::~PStringBase<char>(&command);
    result = 0;
  }
  return result;
}

//----- (00576C80) --------------------------------------------------------  // acclient.c:416964
bool __stdcall ClientCommunicationSystem::DoAllegianceName(int argc, char **argv)
{
  char *v4; // edi@3
  int v5; // eax@6
  char *v6; // edi@6
  bool v7; // bl@6
  PStringBase<char> v8; // ST08_4@10
  bool v9; // bl@10
  char **v10; // edi@10
  int v11; // edi@13
  int v12; // eax@16
  int v13; // edi@16
  bool v14; // bl@16
  char *v15; // edi@21
  char *v16; // edi@25
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+10h] [bp-8h]@3
  PStringBase<char> result; // [sp+14h] [bp-4h]@3

  if ( !argc )
    return CM_Allegiance::Event_QueryAllegianceName();
  command.m_charbuffer = NextArg(&result, &argc, &argv)->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&command.m_charbuffer[-1]);
  v4 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&result, "set");
  v5 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v6 = &result.m_charbuffer[-2].m_data[12];
  v7 = v5 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  if ( v7 )
  {
    JoinArgs((PStringBase<char> *)&argc, argc, argv);
    v8.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
    PStringBase<char>::trim((PStringBase<char> *)&argc, 1, 1, v8);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argc);
    v9 = CM_Allegiance::Event_SetAllegianceName((AC1Legacy::PStringBase<char> *)&argv);
    v10 = argv;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v10 )
      (*(void (__thiscall **)(char **, signed int))*v10)(v10, 1);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    goto LABEL_21;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "clear");
  v12 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, (PStringBase<char> *)&argc, 0);
  v13 = argc - 20;
  v14 = v12 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  if ( v14 )
  {
    v9 = CM_Allegiance::Event_ClearAllegianceName();
LABEL_21:
    v15 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) )
    {
      if ( v15 )
        (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
    }
    return v9;
  }
  v16 = &command.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  return 0;
}

//----- (00576E70) --------------------------------------------------------  // acclient.c:417036
bool __stdcall ClientCommunicationSystem::DoAllegianceLock(int argc, char **argv)
{
  bool v3; // al@2
  PSRefBufferCharData<char> **v4; // eax@3
  PSRefBufferCharData<char> *v5; // ebp@3
  volatile LONG *v6; // ST08_4@3
  char *v7; // edi@3
  int v8; // eax@6
  char *v9; // edi@6
  bool v10; // bl@6
  bool v11; // al@10
  bool v12; // bl@11
  int v13; // eax@15
  char *v14; // edi@15
  bool v15; // bl@15
  int v16; // eax@20
  char *v17; // edi@20
  bool v18; // bl@20
  bool v19; // bl@24
  bool v20; // bl@25
  bool v21; // bl@26
  bool v22; // bl@27
  int v23; // esi@28
  bool v24; // bl@29
  int v25; // edi@30
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+10h] [bp-8h]@3
  PStringBase<char> result; // [sp+14h] [bp-4h]@3

  if ( !argc )
    return CM_Allegiance::Event_DoAllegianceLockAction(4u);
  v4 = (PSRefBufferCharData<char> **)NextArg(&result, &argc, &argv);
  v5 = *v4;
  v6 = (volatile LONG *)&(*v4)[-1];
  command.m_charbuffer = *v4;
  InterlockedIncrement(v6);
  v7 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  PStringBase<char>::PStringBase<char>(&result, "off");
  v8 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v9 = &result.m_charbuffer[-2].m_data[12];
  v10 = v8 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  if ( v10 )
  {
    v11 = CM_Allegiance::Event_DoAllegianceLockAction(1u);
LABEL_11:
    v12 = v11;
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
    return v12;
  }
  PStringBase<char>::PStringBase<char>(&result, "on");
  v13 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v14 = &result.m_charbuffer[-2].m_data[12];
  v15 = v13 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  if ( v15 )
  {
    v11 = CM_Allegiance::Event_DoAllegianceLockAction(2u);
    goto LABEL_11;
  }
  PStringBase<char>::PStringBase<char>(&result, "toggle");
  v16 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v17 = &result.m_charbuffer[-2].m_data[12];
  v18 = v16 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
  if ( v18 )
  {
    v19 = CM_Allegiance::Event_DoAllegianceLockAction(3u);
    PStringBase<char>::~PStringBase<char>(&command);
    v3 = v19;
  }
  else
  {
    PStringBase<char>::PStringBase<char>(&result, "check");
    v20 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    if ( v20 )
    {
      v21 = CM_Allegiance::Event_DoAllegianceLockAction(4u);
      PStringBase<char>::~PStringBase<char>(&command);
      v3 = v21;
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&result, "bypass");
      v22 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( v22 )
      {
        JoinArgsAsName((PStringBase<char> *)&argc, argc, argv);
        v23 = argc;
        if ( *(_DWORD *)(argc - 4) == 1 )
        {
          v24 = CM_Allegiance::Event_DoAllegianceLockAction(5u);
        }
        else
        {
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "clear");
          v25 = __stricmp((const char *)v23, (const char *)argv);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
          if ( v25 )
          {
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)v23);
            v24 = CM_Allegiance::Event_SetAllegianceApprovedVassal((AC1Legacy::PStringBase<char> *)&argv);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argv);
          }
          else
          {
            v24 = CM_Allegiance::Event_DoAllegianceLockAction(6u);
          }
        }
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
        PStringBase<char>::~PStringBase<char>(&command);
        v3 = v24;
      }
      else
      {
        PStringBase<char>::~PStringBase<char>(&command);
        v3 = 0;
      }
    }
  }
  return v3;
}

//----- (00577150) --------------------------------------------------------  // acclient.c:417167
bool __stdcall ClientCommunicationSystem::DoMotd(int argc, char **argv)
{
  bool v3; // al@2
  PSRefBufferCharData<char> **v4; // eax@3
  PSRefBufferCharData<char> *v5; // ebp@3
  volatile LONG *v6; // ST08_4@3
  char *v7; // edi@3
  int v8; // eax@6
  char *v9; // edi@6
  bool v10; // bl@6
  int v11; // ebx@10
  bool v12; // al@10
  char **v13; // edi@10
  int v14; // eax@20
  int v15; // edi@20
  bool v16; // bl@20
  bool v17; // bl@24
  PStringBase<char> result; // [sp+8h] [bp-8h]@3
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+Ch] [bp-4h]@3

  if ( argc )
  {
    v4 = (PSRefBufferCharData<char> **)NextArg(&result, &argc, &argv);
    v5 = *v4;
    v6 = (volatile LONG *)&(*v4)[-1];
    command.m_charbuffer = *v4;
    InterlockedIncrement(v6);
    v7 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    PStringBase<char>::PStringBase<char>(&result, "set");
    v8 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
    v9 = &result.m_charbuffer[-2].m_data[12];
    v10 = v8 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    if ( v10 )
    {
      JoinArgs((PStringBase<char> *)&argc, argc, argv);
      v11 = argc;
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argc);
      v12 = CM_Allegiance::Event_SetMotd((AC1Legacy::PStringBase<char> *)&argv);
      v13 = argv;
      LOBYTE(argc) = v12;
      if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v13 )
        (*(void (__thiscall **)(char **, signed int))*v13)(v13, 1);
      if ( !InterlockedDecrement((volatile LONG *)(v11 - 20 + 4)) && v11 != 20 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))(v11 - 20))(v11 - 20, 1);
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
        (**(void (__thiscall ***)(char *, signed int))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
      v3 = argc;
    }
    else
    {
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "clear");
      v14 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, (PStringBase<char> *)&argc, 0);
      v15 = argc - 20;
      v16 = v14 == 0;
      if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v15 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      if ( v16 )
      {
        v17 = CM_Allegiance::Event_ClearMotd();
        if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
          (**(void (__thiscall ***)(char *, signed int))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
        v3 = v17;
      }
      else
      {
        if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
        v3 = 0;
      }
    }
  }
  else
  {
    v3 = CM_Allegiance::Event_QueryMotd();
  }
  return v3;
}

//----- (00577330) --------------------------------------------------------  // acclient.c:417250
char __stdcall ClientCommunicationSystem::HelpMotd(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@allegiance motd - Displays the message of the day for your allegiance.\n@allegiance motd set <text> - Sets the MOTD. Can only be used by monarchs.\n@allegiance motd clear- Clears the MOTD. Can only be used by monarchs.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@allegiance motd - Displays or sets the message of the day for your allegiance, see @help motd for more information.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577390) --------------------------------------------------------  // acclient.c:417278
char __thiscall ClientCommunicationSystem::HelpSpeaker(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@speaker - No longer used, see @allegiance officer for a similar command.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005773E0) --------------------------------------------------------  // acclient.c:417303
char __stdcall ClientCommunicationSystem::HelpChannelsGroup(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@2
  int v5; // eax@2
  int v6; // esi@4
  PStringBase<char> *v8; // edi@7

  if ( type )
  {
    v8 = msg;
    ClientCommunicationSystem::HelpStupidChannelHack(0, "a", msg);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "c", v8);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "m", v8);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "p", v8);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "v", v8);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "f", v8);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help channels - How to communicate with people in your allegiance or fellowship.\n");
    v4 = type;
    v5 = *(_DWORD *)(type - 4);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
      v4 = type;
    }
    v6 = v4 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      return 1;
    }
  }
  return 1;
}

//----- (005774A0) --------------------------------------------------------  // acclient.c:417343
bool __thiscall ClientCommunicationSystem::DoChannelCommand(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  bool result; // al@2
  int v5; // esi@3
  int v6; // edi@3
  char **v7; // edi@8
  bool v8; // bl@8
  int v9; // esi@8

  v3 = argc;
  if ( argc > 0 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&argc,
      this->m_strCurrentCommand.m_charbuffer->m_data);
    v5 = ChannelSystem::GetChannelID((AC1Legacy::PStringBase<char> *)&argc);
    v6 = argc;
    if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    if ( v5 && v5 != 1024 )
    {
      JoinArgs((PStringBase<char> *)&argv, v3, argv);
      v7 = argv;
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
      v8 = CM_Communication::Event_ChannelBroadcast(v5, (AC1Legacy::PStringBase<char> *)&argc);
      v9 = argc;
      if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      if ( !InterlockedDecrement((volatile LONG *)v7 - 4) && v7 != (char **)20 )
        (*(void (__thiscall **)(char **, signed int))*(v7 - 5))(v7 - 5, 1);
      result = v8;
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

//----- (00577580) --------------------------------------------------------  // acclient.c:417389
char __thiscall ClientCommunicationSystem::HelpJoinChat(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@join <channel tag> - Allows you to hear and speak on the given channel.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005775D0) --------------------------------------------------------  // acclient.c:417414
char __thiscall ClientCommunicationSystem::HelpLeaveChat(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@leave <channel tag> - Prevents you from hearing or speaking on the given channel.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577620) --------------------------------------------------------  // acclient.c:417439
char __thiscall ClientCommunicationSystem::HelpTurbineChat_Allegiance(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@a - Sends a message to your Allegiance. Also: @guild, @gu\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577670) --------------------------------------------------------  // acclient.c:417462
char __thiscall ClientCommunicationSystem::HelpTurbineChat_General(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@general - Sends a message to the global General chat channel. Also: @cg\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005776C0) --------------------------------------------------------  // acclient.c:417487
char __thiscall ClientCommunicationSystem::HelpTurbineChat_Trade(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@trade - Sends a message to the global Trade chat channel. Also: @ct\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577710) --------------------------------------------------------  // acclient.c:417510
char __thiscall ClientCommunicationSystem::HelpTurbineChat_LFG(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@lfg - Sends a message to the global Looking For Group (LFG) chat channel. Also: @clfg\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577760) --------------------------------------------------------  // acclient.c:417535
char __thiscall ClientCommunicationSystem::HelpTurbineChat_Roleplay(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@roleplay - Sends a message to the global Roleplay chat channel. Also: @crp\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005777B0) --------------------------------------------------------  // acclient.c:417560
char __thiscall ClientCommunicationSystem::HelpTurbineChat_Olthoi(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@olthoi - If you are an Olthoi, sends a message to the global Olthoi chat channel. Also: @o\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577800) --------------------------------------------------------  // acclient.c:417585
char __thiscall ClientCommunicationSystem::HelpTurbineChat_Society(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@society - Sends a message to the your Society chat channel. Also: @soc\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577850) --------------------------------------------------------  // acclient.c:417608
char __stdcall ClientCommunicationSystem::HelpChatToggle(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@chat <on/off> - Sets whether or not you receive normal chat. When set to \"off\", you will no longer receive any spoken speech (normal chat).  However, you will still receive tells.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@chat - Sets whether or not you receive normal chat.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005778B0) --------------------------------------------------------  // acclient.c:417636
char __stdcall ClientCommunicationSystem::HelpNoTell(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@notell <on/off> - Sets whether or not you receive @tells. When set to \"on\", you will not receive any tells.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@notell - Sets whether or not you receive @tell's.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577910) --------------------------------------------------------  // acclient.c:417664
char __thiscall ClientCommunicationSystem::DoReply(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  PStringBase<char> v4; // ST0C_4@1
  int v5; // esi@2
  char **v6; // esi@5
  int v7; // esi@7
  unsigned int v8; // eax@8
  LONG v9; // eax@5

  v3 = this;
  JoinArgs((PStringBase<char> *)&argv, argc, argv);
  v4.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
  PStringBase<char>::trim((PStringBase<char> *)&argv, 1, 1, v4);
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"You must specify the text you wish to say!");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v5 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = argv - 5;
    v9 = InterlockedDecrement((volatile LONG *)argv - 4);
  }
  else
  {
    if ( gmCCommunicationSystem::GetLastTeller() )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
      v8 = gmCCommunicationSystem::GetLastTeller();
      CM_Communication::Event_TalkDirect((AC1Legacy::PStringBase<char> *)&argc, v8);
      v7 = argc;
    }
    else
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"Someone must @tell you first!");
      ClientSystem::AddTextToScroll(
        (ClientSystem *)&v3->vfptr,
        (PStringBase<unsigned short> *)&argc,
        0x1Au,
        1,
        v3->m_idCurrentCommandSource);
      v7 = argc - 20;
    }
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v6 = argv - 5;
    v9 = InterlockedDecrement((volatile LONG *)argv - 4);
  }
  if ( !v9 && v6 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v6)(v6, 1);
  return 1;
}

//----- (00577A50) --------------------------------------------------------  // acclient.c:417729
char __stdcall ClientCommunicationSystem::HelpReply(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@2
  int v5; // eax@2
  PStringBase<char> *v6; // ebx@2
  LONG (__stdcall *v7)(volatile LONG *); // edi@4
  int v8; // esi@4
  PStringBase<char> *v9; // eax@7
  PSRefBufferCharData<char> *v10; // ecx@7
  int v11; // esi@9
  ClientCommunicationSystem::HelpType v12; // ecx@13
  int v13; // eax@13
  int v14; // esi@15
  PStringBase<char> *v15; // eax@18
  PSRefBufferCharData<char> *v16; // ecx@18
  int v17; // esi@20
  PStringBase<char> *v18; // eax@24
  PSRefBufferCharData<char> *v19; // ecx@24
  int v20; // esi@26

  if ( type )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@reply <text> - Sends the text to the last person who @tell'd you. You may also use @r or @rp.\n");
    v12 = type;
    v13 = *(_DWORD *)(type - 4);
    v6 = msg;
    if ( v13 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v13 - 1);
      v12 = type;
    }
    v7 = InterlockedDecrement;
    v14 = v12 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v12 - 20 + 4)) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@pr <text> - Sends the text to the last vassal who used @p to send  you a message.\n");
    v15 = msg;
    v16 = msg[-1].m_charbuffer;
    if ( v16 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v6, (const char *)msg, (unsigned int)&v16[-1].m_data[15]);
      v15 = msg;
    }
    v17 = (int)&v15[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v15[-4]) && v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@mr <text> - Sends the text to the last person who used @m to send  you a message. This only works for monarchs.\n");
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@reply - Sends some text to the last person who @tell'd you.\n");
    v4 = type;
    v5 = *(_DWORD *)(type - 4);
    v6 = msg;
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
      v4 = type;
    }
    v7 = InterlockedDecrement;
    v8 = v4 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@pr - Sends some text to the last person who @p'd you.\n");
    v9 = msg;
    v10 = msg[-1].m_charbuffer;
    if ( v10 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v6, (const char *)msg, (unsigned int)&v10[-1].m_data[15]);
      v9 = msg;
    }
    v11 = (int)&v9[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v9[-4]) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@mr - Sends some text to the last person who @m'd you.\n");
  }
  v18 = msg;
  v19 = msg[-1].m_charbuffer;
  if ( v19 != (PSRefBufferCharData<char> *)1 )
  {
    PStringBase<char>::append_n_chars(v6, (const char *)msg, (unsigned int)&v19[-1].m_data[15]);
    v18 = msg;
  }
  v20 = (int)&v18[-5];
  if ( !v7((volatile LONG *)&v18[-4]) && v20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
  return 1;
}

//----- (00577BD0) --------------------------------------------------------  // acclient.c:417831
char __thiscall ClientCommunicationSystem::DoReTell(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // ebp@1
  PStringBase<char> v4; // ST0C_4@1
  char **v5; // esi@2
  LONG v6; // eax@2
  PStringBase<char> *v7; // eax@3
  bool v8; // al@3
  int v9; // esi@3
  bool v10; // bl@3
  int v11; // esi@7
  const char **v12; // eax@11
  int v13; // esi@11
  AC1Legacy::PSRefBuffer<char> *v14; // esi@14
  char *v15; // esi@17
  AC1Legacy::PStringBase<char> i_target_name; // [sp+10h] [bp-8h]@11
  PStringBase<char> result; // [sp+14h] [bp-4h]@11

  v3 = this;
  JoinArgs((PStringBase<char> *)&argv, argc, argv);
  v4.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
  PStringBase<char>::trim((PStringBase<char> *)&argv, 1, 1, v4);
  if ( *(argv - 1) == (char *)1 )
  {
    v5 = argv - 5;
    v6 = InterlockedDecrement((volatile LONG *)argv - 4);
  }
  else
  {
    v7 = gmCCommunicationSystem::GetLastTelleeName((PStringBase<char> *)&argc);
    v8 = PStringBase<char>::operator==(v7, &PStringBase<char>::null_string);
    v9 = argc - 20;
    v10 = v8;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    if ( v10 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"You must first provide a name using @tell");
      ClientSystem::AddTextToScroll(
        (ClientSystem *)&v3->vfptr,
        (PStringBase<unsigned short> *)&argc,
        0x1Au,
        1,
        v3->m_idCurrentCommandSource);
      v11 = argc - 20;
      if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v5 = argv - 5;
      v6 = InterlockedDecrement((volatile LONG *)argv - 4);
    }
    else
    {
      v12 = (const char **)gmCCommunicationSystem::GetLastTelleeName(&result);
      AC1Legacy::PStringBase<char>::PStringBase<char>(&i_target_name, *v12);
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
      CM_Communication::Event_TalkDirectByName((AC1Legacy::PStringBase<char> *)&argc, &i_target_name);
      v13 = argc;
      if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      v14 = i_target_name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&i_target_name.m_buffer->m_cRef) && v14 )
        v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
      v15 = &result.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v15 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      v5 = argv - 5;
      v6 = InterlockedDecrement((volatile LONG *)argv - 4);
    }
  }
  if ( !v6 && v5 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
  return 1;
}

//----- (00577D80) --------------------------------------------------------  // acclient.c:417909
char __stdcall ClientCommunicationSystem::HelpReTell(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@retell <text> - Sends the text to the last person you @tell'd. You may also use @rt.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@retell - Sends some text to the last person you @tell'd.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577DE0) --------------------------------------------------------  // acclient.c:417937
char __stdcall ClientCommunicationSystem::HelpSay(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@say <text> - Says the text to the all the people around you. This is useful when your normal default chat is set to some other channel -- for instance, when you have selected Talk to Fellows as your default.\nAlso: @s\n");
  else
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&type, "@say - Says some text to everyone around you.");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00577E40) --------------------------------------------------------  // acclient.c:417963
char __thiscall ClientCommunicationSystem::DoTell(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  char **v4; // ebp@1
  char *v5; // eax@1
  int v6; // esi@2
  char **v7; // esi@3
  int v8; // esi@6
  LONG v9; // eax@6
  PStringBase<char> v10; // ST10_4@7
  PSRefBufferCharData<char> *v11; // esi@7
  PStringBase<char> v12; // ST10_4@7
  char **v13; // edi@7
  AC1Legacy::PSRefBuffer<char> *v14; // edi@10
  int v15; // edi@13
  int v16; // esi@16
  AC1Legacy::PStringBase<char> i_target_name; // [sp+10h] [bp-8h]@7
  PStringBase<char> playerName; // [sp+14h] [bp-4h]@7

  v3 = this;
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  v4 = argv;
  v5 = _strchr((const char *)argv, 44);
  if ( v5 && (v6 = v5 - (char *)v4, v5 - (char *)v4 >= 1) )
  {
    PStringBase<char>::substring((PStringBase<char> *)&argv, &playerName, 0, v6 - 1);
    PStringBase<char>::substring((PStringBase<char> *)&argv, (PStringBase<char> *)&argc, v6 + 1, 0xFFFFFFFF);
    v10.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
    PStringBase<char>::trim((PStringBase<char> *)&argc, 1, 1, v10);
    v11 = playerName.m_charbuffer;
    v12.m_charbuffer = playerName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&playerName.m_charbuffer[-1]);
    gmCCommunicationSystem::SetLastTelleeName(v12);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&i_target_name, v11->m_data);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argc);
    CM_Communication::Event_TalkDirectByName((AC1Legacy::PStringBase<char> *)&argv, &i_target_name);
    v13 = argv;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v13 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v13)(v13, 1);
    v14 = i_target_name.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&i_target_name.m_buffer->m_cRef) && v14 )
      v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
    v15 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    v16 = (int)&v11[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    v8 = (int)(v4 - 5);
    v9 = InterlockedDecrement((volatile LONG *)v4 - 4);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      L"Use comma after the name for targeted chat.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argv,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v7 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v7 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v7)(v7, 1);
    v8 = (int)(v4 - 5);
    v9 = InterlockedDecrement((volatile LONG *)v4 - 4);
  }
  if ( !v9 && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  return 1;
}

//----- (00578000) --------------------------------------------------------  // acclient.c:418038
char __stdcall ClientCommunicationSystem::HelpTell(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@tell <name>, <text>  - Sends a long-distance, private message to the specified character. Note that you must put a comma after the character's name.\nAlso: @t, @send, @whisper, @w\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@tell - Sends a private message to another character.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578060) --------------------------------------------------------  // acclient.c:418066
char __stdcall ClientCommunicationSystem::HelpAFK(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@2
  int v5; // eax@2
  int v6; // esi@4
  LONG v7; // eax@4
  ClientCommunicationSystem::HelpType v8; // ecx@5
  int v9; // eax@5
  PStringBase<char> *v10; // ebx@5
  int v11; // esi@7
  PStringBase<char> *v12; // eax@10
  PSRefBufferCharData<char> *v13; // ecx@10
  int v14; // esi@12
  PStringBase<char> *v15; // eax@15
  PSRefBufferCharData<char> *v16; // ecx@15
  int v17; // esi@17
  PStringBase<char> *v18; // eax@20
  PSRefBufferCharData<char> *v19; // ecx@20

  if ( type )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@afk - Turns on AFK (away-from-keyboard) mode. When set to AFK, other players that send you directed chatyou will receive a customizable message that your are not currently at the keyboard.\n");
    v8 = type;
    v9 = *(_DWORD *)(type - 4);
    v10 = msg;
    if ( v9 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v9 - 1);
      v8 = type;
    }
    v11 = v8 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@afk on - Turns on AFK mode. When set to AFK, other players that send you directed chatyou will receive a customizable message that your are not currently at the keyboard.\n");
    v12 = msg;
    v13 = msg[-1].m_charbuffer;
    if ( v13 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v13[-1].m_data[15]);
      v12 = msg;
    }
    v14 = (int)&v12[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v12[-4]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, "@afk off - Turn off AFK mode.\n");
    v15 = msg;
    v16 = msg[-1].m_charbuffer;
    if ( v16 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v16[-1].m_data[15]);
      v15 = msg;
    }
    v17 = (int)&v15[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v15[-4]) && v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@afk msg <message> - Set the message that will be sent to players that send you directed chat while you are in AFK mode. Issuing \"@afk msg\" with no message will set your AFK message back to the default. Your custom AFK message is limited to 192 characters.\n");
    v18 = msg;
    v19 = msg[-1].m_charbuffer;
    if ( v19 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v19[-1].m_data[15]);
      v18 = msg;
    }
    v6 = (int)&v18[-5];
    v7 = InterlockedDecrement((volatile LONG *)&v18[-4]);
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&type, "@afk - Set your away-from-keyboard status.\n");
    v4 = type;
    v5 = *(_DWORD *)(type - 4);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
      v4 = type;
    }
    v6 = v4 - 20;
    v7 = InterlockedDecrement((volatile LONG *)(v4 - 20 + 4));
  }
  if ( !v7 && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005781C0) --------------------------------------------------------  // acclient.c:418157
char __stdcall ClientCommunicationSystem::HelpConsent(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "The @consent commands allow you to display and manage your corpse-looting consent list. This list lets you control whether others may permit you to loot their corpse and also allows you to monitor who has given you permission. You may have a maximum of 20 separate permissions at any given time. You will not be able to loot a corpse that was the victim of a player killer, even if its owner has given you permission. Also, players who have squelched you are not able to permit you to loot their corpse. Note that you can toggle your consent on/off via the Character Options panel as well as through these commands.\n@consent on - Turns on your ability to accept permissions from other players.\n@consent off - Turns off your ability to accept permissions from other players.\n@consent who - Lists those who have given you permission to loot their corpses.\n@consent remove <name> - Removes the permission a player granted to you.\n@consent clear - Clears your entire consent list.\n\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@consent - Commands to help you manage the corpse-looting permissions that others give you.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578220) --------------------------------------------------------  // acclient.c:418185
char __thiscall ClientCommunicationSystem::DoCorpse(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // ebp@1
  InterfaceSystem *v4; // eax@1
  AC1Legacy::PSRefBuffer<char> *v5; // esi@1
  int v6; // edi@3
  AC1Legacy::PStringBase<unsigned short> *v8; // eax@10
  unsigned int v9; // esi@10
  AC1Legacy::PSRefBuffer<char> *v10; // esi@13
  unsigned int v11; // ST10_4@17
  PStringBase<unsigned short> *v12; // eax@17
  unsigned int v13; // esi@17
  char *v14; // esi@20
  int v15; // [sp-8h] [bp-78h]@1
  PStringBase<char> corpseString; // [sp+10h] [bp-60h]@9
  AC1Legacy::PStringBase<char> coordString; // [sp+14h] [bp-5Ch]@1
  TResult result; // [sp+18h] [bp-58h]@1
  char v19; // [sp+1Ch] [bp-54h]@3
  InterfacePtr<PlayerDesc> spPD; // [sp+20h] [bp-50h]@1
  Position corpse_pos; // [sp+28h] [bp-48h]@9

  v3 = this;
  coordString.m_buffer = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &PlayerDesc_ClassType_30, (Interface **)&coordString);
  v15 = (int)coordString.m_buffer;
  v5 = coordString.m_buffer;
  spPD.m_pInterface = 0;
  spPD.m_trStatus.m_val = 0;
  if ( coordString.m_buffer )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))coordString.m_buffer->vfptr[4].__vecDelDtor)(coordString.m_buffer);
  v6 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v19, v15, 0);
  if ( v5 )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))v5->vfptr[5].__vecDelDtor)(v5);
  if ( !(_DWORD)spPD.m_pInterface )
    return 0;
  if ( v6 < 0 )
  {
    ((void (*)(void))spPD.m_pInterface->vfptr->Release)();
    return 0;
  }
  corpse_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  corpse_pos.objcell_id = 0;
  LODWORD(corpse_pos.frame.qw) = 1065353216;
  LODWORD(corpse_pos.frame.qx) = 0;
  LODWORD(corpse_pos.frame.qy) = 0;
  LODWORD(corpse_pos.frame.qz) = 0;
  LODWORD(corpse_pos.frame.m_fOrigin.x) = 0;
  LODWORD(corpse_pos.frame.m_fOrigin.y) = 0;
  LODWORD(corpse_pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&corpse_pos.frame);
  corpseString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( CBaseQualities::InqPosition((CBaseQualities *)&spPD.m_pInterface->vfptr, 0xEu, &corpse_pos) )
  {
    coordString.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v8 = (AC1Legacy::PStringBase<unsigned short> *)LandDefs::CellidToCoordinateString(
                                                     (AC1Legacy::PStringBase<char> *)&result,
                                                     corpse_pos.objcell_id);
    AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)&coordString, v8);
    v9 = result.m_val;
    if ( !InterlockedDecrement((volatile LONG *)(result.m_val + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = coordString.m_buffer;
    PStringBase<char>::sprintf(
      &corpseString,
      "The last time you died outside, your corpse was located at (%s).\n",
      coordString.m_buffer->m_data);
    if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) && v10 )
      v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
  }
  else
  {
    PStringBase<char>::set(&corpseString, "We're sorry, but we have no record of your last outside corpse location.\n");
  }
  v11 = v3->m_idCurrentCommandSource;
  v12 = PStringBase<char>::to_wpstring(&corpseString, (PStringBase<unsigned short> *)&result, 0);
  ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v12, 0, 1, v11);
  v13 = result.m_val - 20;
  if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  v14 = &corpseString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&corpseString.m_charbuffer[-1]) )
  {
    if ( v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  }
  corpse_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  ((void (*)(void))spPD.m_pInterface->vfptr->Release)();
  return 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00578430) --------------------------------------------------------  // acclient.c:418282
char __stdcall ClientCommunicationSystem::HelpCorpse(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@5
  int v5; // eax@5
  int v6; // esi@7

  if ( type && type != 1 )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@corpse - Displays the location of your last outdoor death. Even if your corpse has disappeared or if you have subsequently died indoors, typing this command will display your last outdoor corpse location.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@corpse - Displays the location of your last outdoor death.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005784A0) --------------------------------------------------------  // acclient.c:418310
char __stdcall ClientCommunicationSystem::HelpDie(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@die - If you wish to kill your character and leave a corpse, you may use the @die command.  This will result in your character's death, you will leave behind a corpse with some of your items, and you will appear at your lifestone.  If you wish to travel to your lifestone without leaving behind a corpse, you may use the @lifestone command.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@die - Kills your character and leaves a corpse, returning you to your lifestone.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578500) --------------------------------------------------------  // acclient.c:418338
char __thiscall ClientCommunicationSystem::HelpLifestone(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@lifestone - Returns you to the last lifestone you used without killing you.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578550) --------------------------------------------------------  // acclient.c:418363
char __thiscall ClientCommunicationSystem::HelpMarketplace(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@marketplace - Teleports you to the Marketplace of Dereth.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005785A0) --------------------------------------------------------  // acclient.c:418386
char __thiscall ClientCommunicationSystem::DoPermit(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // ebx@1
  PSRefBufferCharData<char> *v4; // edi@1
  char *v5; // edi@2
  bool v6; // zf@5
  char *v7; // edi@7
  char **v8; // edi@11
  char *v9; // edi@14
  int v11; // edi@18
  char **v12; // edi@21
  char *v13; // edi@24
  int v14; // eax@28
  int v15; // edi@28
  bool v16; // bl@28
  char **v17; // ebp@31
  bool v18; // al@32
  char **v19; // edi@32
  bool v20; // bl@32
  int v21; // edi@35
  bool v22; // al@36
  char **v23; // edi@36
  LONG v24; // eax@35
  char *v25; // edi@43
  bool v26; // [sp+13h] [bp-Dh]@2
  char v27; // [sp+13h] [bp-Dh]@5
  PStringBase<char> command; // [sp+14h] [bp-Ch]@1
  PStringBase<char> v29; // [sp+18h] [bp-8h]@2
  PStringBase<char> v30; // [sp+1Ch] [bp-4h]@1

  v3 = this;
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>(&v30, "add");
  v4 = command.m_charbuffer;
  if ( !__stricmp(command.m_charbuffer->m_data, v30.m_charbuffer->m_data) )
    goto LABEL_49;
  PStringBase<char>::PStringBase<char>(&v29, "remove");
  v26 = __stricmp(v4->m_data, v29.m_charbuffer->m_data) != 0;
  v5 = &v29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v29.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = v26 == 0;
  v27 = 1;
  if ( v6 )
LABEL_49:
    v27 = 0;
  v7 = &v30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v30.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  if ( v27 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      L"Please specify a valid permit command.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argv,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v8 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v8 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v8)(v8, 1);
    v9 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v9 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      return 1;
    }
    return 1;
  }
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please specify a person for the permit command.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v12 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v12 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v12)(v12, 1);
    v13 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    return 1;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "add");
  v14 = __stricmp(command.m_charbuffer->m_data, (const char *)argc);
  v15 = argc - 20;
  v16 = v14 == 0;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  v17 = argv;
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argv);
  if ( v16 )
  {
    v18 = CM_Character::Event_AddPlayerPermission((AC1Legacy::PStringBase<char> *)&argv);
    v19 = argv;
    v20 = v18;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v19 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v19)(v19, 1);
    v21 = (int)(v17 - 5);
    v24 = InterlockedDecrement((volatile LONG *)v17 - 4);
  }
  else
  {
    v22 = CM_Character::Event_RemovePlayerPermission((AC1Legacy::PStringBase<char> *)&argv);
    v23 = argv;
    v20 = v22;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v23 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v23)(v23, 1);
    v21 = (int)(v17 - 5);
    v24 = InterlockedDecrement((volatile LONG *)v17 - 4);
  }
  if ( !v24 && v21 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  v25 = &command.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v25 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
  return v20;
}

//----- (00578870) --------------------------------------------------------  // acclient.c:418517
char __stdcall ClientCommunicationSystem::HelpPermit(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "The @permit command gives or revokes corpse-looting permissions to other players. You can permit other players to loot any one of your corpses. You may not @permit a player again until he or she has looted your corpse. Permissions expire either after one hour or when the permitted player logs off. If you were killed by a player killer, no one can loot your corpse except you or your killer, even if you give someone else permission.\n@permit add <name> - Allows  another player to loot your corpse.\n@permit remove <name> - Removes permission to access your corpse from the named character.\nType @help consent for more details on corpse looting.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@permit - Commands to give or revoke permission for others to loot your corpse.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005788D0) --------------------------------------------------------  // acclient.c:418545
char __thiscall ClientCommunicationSystem::DoPKArena(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  unsigned int v6; // eax@6
  HashBaseData<unsigned long> *v7; // eax@8

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please see @help pkarena for more information on how to use this command.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    if ( SmartBox::smartbox )
      v6 = SmartBox::smartbox->player_id;
    else
      v6 = 0;
    v7 = ClientObjMaintSystem::GetWeenieObject(v6);
    if ( v7 && !((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[8].__vecDelDtor)(v7) )
    {
      ClientCommunicationSystem::HandleFailureEvent(v3, 0x55Fu, &PStringBase<unsigned short>::null_string);
      return 1;
    }
    CM_Character::Event_TeleToPKArena();
  }
  return 1;
}

//----- (00578980) --------------------------------------------------------  // acclient.c:418589
char __thiscall ClientCommunicationSystem::HelpPKArena(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@pkarena - Teleports you to the PK Arena. You must be PK to use this command.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (005789D0) --------------------------------------------------------  // acclient.c:418614
char __thiscall ClientCommunicationSystem::DoPKLArena(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  unsigned int v6; // eax@6
  HashBaseData<unsigned long> *v7; // eax@8

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please see @help pklarena for more information on how to use this command.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    if ( SmartBox::smartbox )
      v6 = SmartBox::smartbox->player_id;
    else
      v6 = 0;
    v7 = ClientObjMaintSystem::GetWeenieObject(v6);
    if ( v7 && !((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[9].__vecDelDtor)(v7) )
    {
      ClientCommunicationSystem::HandleFailureEvent(v3, 0x560u, &PStringBase<unsigned short>::null_string);
      return 1;
    }
    CM_Character::Event_TeleToPKLArena();
  }
  return 1;
}

//----- (00578A80) --------------------------------------------------------  // acclient.c:418658
char __thiscall ClientCommunicationSystem::HelpPKLArena(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@pklarena - Teleports you to the PKL Arena. You must be PKL to use this command.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578AD0) --------------------------------------------------------  // acclient.c:418683
char __stdcall ClientCommunicationSystem::DoEmote(int argc, char **argv)
{
  char **v3; // edi@1
  char **v4; // esi@2
  char result; // al@5
  bool v6; // bl@6
  char **v7; // esi@6

  JoinArgs((PStringBase<char> *)&argv, argc, argv);
  v3 = argv;
  if ( *(argv - 1) == (char *)1 )
  {
    v4 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v3 != (char **)20 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v4)(v3 - 5, 1);
    result = 1;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argv);
    v6 = CM_Communication::Event_Emote((AC1Legacy::PStringBase<char> *)&argv);
    v7 = argv;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v7 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v7)(v7, 1);
    if ( !InterlockedDecrement((volatile LONG *)v3 - 4) && v3 != (char **)20 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*(v3 - 5))(v3 - 5, 1);
    result = v6;
  }
  return result;
}

//----- (00578B80) --------------------------------------------------------  // acclient.c:418715
char __stdcall ClientCommunicationSystem::HelpEmote(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@5
  int v5; // eax@5
  int v6; // esi@7
  LONG v7; // eax@7
  ClientCommunicationSystem::HelpType v8; // ecx@8
  int v9; // eax@8
  PStringBase<char> *v10; // ebx@8
  int v11; // esi@10
  PStringBase<char> *v12; // eax@13
  PSRefBufferCharData<char> *v13; // ecx@13

  if ( type == Summary_HelpType )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help emote - How to perform text and action emotes.\n");
LABEL_5:
    v4 = type;
    v5 = *(_DWORD *)(type - 4);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
      v4 = type;
    }
    v6 = v4 - 20;
    v7 = InterlockedDecrement((volatile LONG *)(v4 - 20 + 4));
    goto LABEL_16;
  }
  if ( type == 1 )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@emote - Performs a text emote.\n@emotes - Lists all standard emotes.\n");
    goto LABEL_5;
  }
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&type,
    "The @emote command causes your character to emote some text, by performing an action in the third person. For example, if you typed the following while logged in as a character named Arville:\n    @emote looks around the town curiously.\nthen the chat windows of everyone around you would display:\n    Arville looks around the town curiously.\nYou can use any of these shorter forms of the command as well:\n         @e <text>\n         @em <text>\n         ; <text>\n         : <text>\n\n");
  v8 = type;
  v9 = *(_DWORD *)(type - 4);
  v10 = msg;
  if ( v9 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v9 - 1);
    v8 = type;
  }
  v11 = v8 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&msg,
    "You can also use a variety of standard emotes. These emotes come with special animations as well as text. Type @emotes to see a list.\n\n");
  v12 = msg;
  v13 = msg[-1].m_charbuffer;
  if ( v13 != (PSRefBufferCharData<char> *)1 )
  {
    PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v13[-1].m_data[15]);
    v12 = msg;
  }
  v6 = (int)&v12[-5];
  v7 = InterlockedDecrement((volatile LONG *)&v12[-4]);
LABEL_16:
  if ( !v7 && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578C60) --------------------------------------------------------  // acclient.c:418785
char __thiscall ClientCommunicationSystem::HelpEmoteList(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "Standard Emotes:\nNote: These commands should be bound on either side by asterisks. (Example: *wave*)\nShakeFist; Beckon; BeSeeingYou; BlowKiss; BowDeep; ClapHands; Cry; Laugh; Nod; Point; Shrug; Wave; Akimbo; HeartyLaugh; Salute; TapFoot; WaveHigh; WaveLow; Yawn; Stretch; Cringe; Kneel; Plead; Shiver; Shoo; Slouch; Spit; Surrender; Woah; Winded; YMCA; Eat; Drink; Teapot; Pray; Mock; Cheer; Helper; Warm Hands; Scratch Head; Shake Head\n\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578CB0) --------------------------------------------------------  // acclient.c:418810
char __stdcall ClientCommunicationSystem::HelpFillComponents(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@6
  int v5; // eax@6
  int v6; // esi@8

  if ( type )
  {
    if ( type == 1 )
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@fillcomps - Helps you buy components in bulk.\n");
    else
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "The @fillcomps command assists in the bulk purchase of spell components. It is the sole interface for filling the buy list, which is the column of red zeros to the right in your components panel. To designate which components you would like to buy, change the zeros to the number of each component you would like to buy. The types of components you can buy are scarabs, herbs, powders, potions, and talismans.\n\nThis is the proper syntax: @fillcomps <component type> <pyreal value>\n\n@fillcomps - Fills the buy list with all of the components that are desired.\n@fillcomps <component type> - Fills the buy list with all of the components of the given type.\n@fillcomps <pyreal value> - Fills the buy list with all of the components until the total price of the components exceeds the given value.\n@fillcomps <component type> <pyreal value> - Fills the buy list with all of the components of the given type until the total price of components exceeds the given value.\n@fillcomps clear - Sets the requested amount for );
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help fillcomps - A command to help you buy components in bulk.\n");
  }
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578D20) --------------------------------------------------------  // acclient.c:418847
char __stdcall ClientCommunicationSystem::HelpSaveUI(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@6
  int v5; // eax@6
  int v6; // esi@8

  if ( type )
  {
    if ( type == 1 )
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@saveui <filename> - Saves the current user interface.\n");
    else
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@saveui <filename> - Saves the current user interface layout to disk using the provided file name. If no file name is provided the layout is saved with a name that is unique for your server, character and resolution.\n");
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help saveui <filename> - Saves the current user interface layout to disk. If a file name is provided the layout will be saved using provided file name.\n");
  }
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578D90) --------------------------------------------------------  // acclient.c:418884
char __stdcall ClientCommunicationSystem::HelpLoadUI(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@6
  int v5; // eax@6
  int v6; // esi@8

  if ( type )
  {
    if ( type == 1 )
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@loadui <filename> - Loads a previously saved user interface.\n");
    else
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@loadui <filename> - Loads a previously saved user interface layout from disk using the provided file name");
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help loadui <filename> - Loads a previously saved user interface layout from disk using the provided file name.\n");
  }
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578E00) --------------------------------------------------------  // acclient.c:418921
char __stdcall ClientCommunicationSystem::HelpSaveAutoUI(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@6
  int v5; // eax@6
  int v6; // esi@8

  if ( type )
  {
    if ( type == 1 )
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@saveautoui - Saves the current user interface to be loaded for specific character and resolution.\n");
    else
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@saveautoui - Stores the current layout to a character and resolution specific file. This layout will automatically be used when the resolution changes for this character to the current size.\n");
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help saveautoui - Saves the current user interface layout to disk for use by this character at a specific resolution. This layout will be loaded for this character when the resolution changes to this specific size.\n");
  }
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578E70) --------------------------------------------------------  // acclient.c:418958
char __stdcall ClientCommunicationSystem::HelpLoadAutoUI(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@6
  int v5; // eax@6
  int v6; // esi@8

  if ( type )
  {
    if ( type == 1 )
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@loadautoui - Forces a previously saved layout to load for this user and resolution.\n");
    else
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@loadautoui - Forces a previously saved layout to load for this user and resolution.");
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help loadautoui - Forces a previously saved layout to load for this user and resolution.\n");
  }
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578EE0) --------------------------------------------------------  // acclient.c:418995
char __stdcall ClientCommunicationSystem::HelpLockUI(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@lockui - Toggles the locked state of the UI layout.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help lockui - Toggles the locked state of the UI layout.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578F40) --------------------------------------------------------  // acclient.c:419023
char __stdcall ClientCommunicationSystem::HelpFriends(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@6
  int v5; // eax@6
  int v6; // esi@8

  if ( type )
  {
    if ( type == 1 )
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@friends - Helps you manage your friends list.\n");
    else
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "Every time someone on your friends list logs in or out, you will receive notification. In addition, you can query the online status of your friends list at any time. Your friends list can contain up to 50 characters.\n@friends - Shows all your current friends and indicates if any of them are online.\n@friends online - Shows your current online friends.\n@friends add <name> - Adds a character to your friends list.\n@friends remove <name> - Removes a character from your friends list.\n@friends remove -all - Clears your friends list.\n@friends old - Shows the characters who were on your old-style friends list prior to the January 2006 update, so you can move them to your new-style friends list if necessary.\n");
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help friends - Commands to help you manage your friends list.\n");
  }
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00578FB0) --------------------------------------------------------  // acclient.c:419060
char __thiscall ClientCommunicationSystem::DoFriendsAdd(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  char **v5; // esi@5
  char result; // al@8
  char v7; // al@9
  char **v8; // esi@9
  char v9; // bl@9

  v3 = this;
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"You must specify the name of the friend you wish to add.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) )
    {
      if ( v5 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
    }
    result = 1;
  }
  else
  {
    v7 = CM_Social::SendNotice_ChatCommand_AddFriend((PStringBase<char> *)&argv);
    v8 = argv - 5;
    v9 = v7;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v8 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v8)(v8, 1);
    result = v9;
  }
  return result;
}

//----- (00579080) --------------------------------------------------------  // acclient.c:419107
char __thiscall ClientCommunicationSystem::DoFriendsRemove(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  char **v5; // esi@5
  char result; // al@8
  int v7; // eax@9
  int v8; // esi@9
  bool v9; // bl@9
  char v10; // al@13
  char **v11; // esi@15
  char v12; // bl@15

  v3 = this;
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"You must specify the name of the friend you wish to remove.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) )
    {
      if ( v5 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
    }
    result = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "-all");
    v7 = __stricmp((const char *)argv, (const char *)argc);
    v8 = argc - 20;
    v9 = v7 == 0;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    if ( v9 )
      v10 = CM_Social::SendNotice_ChatCommand_RemoveAllFriends();
    else
      v10 = CM_Social::SendNotice_ChatCommand_RemoveFriend((PStringBase<char> *)&argv);
    v11 = argv - 5;
    v12 = v10;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v11 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v11)(v11, 1);
    result = v12;
  }
  return result;
}

//----- (005791A0) --------------------------------------------------------  // acclient.c:419166
char __thiscall ClientCommunicationSystem::DoHouseGuests(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // eax@1
  char *v4; // ebp@1
  bool v5; // bl@1
  char v6; // bl@5
  int v7; // eax@6
  char *v8; // ebp@6
  bool v9; // bl@6
  char **v10; // ebp@11
  char **v11; // edi@12
  char *v12; // edi@18
  bool v14; // al@22
  char **v15; // edi@24
  bool v16; // bl@24
  char *v17; // edi@30
  int v18; // eax@34
  char **v19; // ebp@34
  bool v20; // bl@34
  bool v21; // al@38
  char *v22; // edi@38
  int v23; // eax@41
  char **v24; // ebp@41
  bool v25; // bl@41
  bool v26; // bl@45
  PSRefBufferCharData<char> *v27; // esi@46
  int v28; // ebx@46
  int v29; // ebx@47
  int v30; // esi@49
  bool v31; // al@48
  bool v32; // bl@51
  PStringBase<char> command; // [sp+10h] [bp-Ch]@1
  PStringBase<char> v34; // [sp+14h] [bp-8h]@1
  ClientSystem *v35; // [sp+18h] [bp-4h]@1

  v35 = (ClientSystem *)this;
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>(&v34, "add");
  v3 = __stricmp(command.m_charbuffer->m_data, v34.m_charbuffer->m_data);
  v4 = &v34.m_charbuffer[-2].m_data[12];
  v5 = v3 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v34.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  if ( v5 )
  {
    v6 = 1;
LABEL_11:
    JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
    v10 = argv;
    if ( *(argv - 1) == (char *)1 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argv,
        L"Please specify the guest's name.");
      ClientSystem::AddTextToScroll(v35, (PStringBase<unsigned short> *)&argv, 0x1Au, 1, (unsigned int)v35[17].vfptr);
      v11 = argv - 5;
      if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v11 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v11)(v11, 1);
      if ( !InterlockedDecrement((volatile LONG *)v10 - 4) && v10 != (char **)20 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*(v10 - 5))(v10 - 5, 1);
      v12 = &command.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v12 )
      {
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
        return 1;
      }
      return 1;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)argv);
    if ( v6 )
      v14 = CM_House::Event_AddPermanentGuest_Event((AC1Legacy::PStringBase<char> *)&argv);
    else
      v14 = CM_House::Event_RemovePermanentGuest_Event((AC1Legacy::PStringBase<char> *)&argv);
    v15 = argv;
    v16 = v14;
    if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v15 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v15)(v15, 1);
    if ( !InterlockedDecrement((volatile LONG *)v10 - 4) && v10 != (char **)20 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*(v10 - 5))(v10 - 5, 1);
    v17 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
    return v16;
  }
  PStringBase<char>::PStringBase<char>(&v34, "remove");
  v7 = __stricmp(command.m_charbuffer->m_data, v34.m_charbuffer->m_data);
  v8 = &v34.m_charbuffer[-2].m_data[12];
  v9 = v7 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v34.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  if ( v9 )
  {
    v6 = 0;
    goto LABEL_11;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "remove_all");
  v18 = __stricmp(command.m_charbuffer->m_data, (const char *)argv);
  v19 = argv - 5;
  v20 = v18 == 0;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v19 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v19)(v19, 1);
  if ( v20 )
  {
    v21 = CM_House::Event_RemoveAllPermanentGuests_Event();
    v22 = &command.m_charbuffer[-2].m_data[12];
    v16 = v21;
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v22 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
      return v16;
    }
    return v16;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "list");
  v23 = __stricmp(command.m_charbuffer->m_data, (const char *)argv);
  v24 = argv - 5;
  v25 = v23 == 0;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v24 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v24)(v24, 1);
  if ( v25
    || (PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "show"),
        v27 = command.m_charbuffer,
        v28 = __stricmp(command.m_charbuffer->m_data, (const char *)argv),
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv),
        !v28) )
  {
    v26 = CM_House::Event_RequestFullGuestList_Event();
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
    return v26;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "add_allegiance");
  v29 = __stricmp(v27->m_data, (const char *)argv);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
  if ( !v29 )
  {
    v31 = CM_House::Event_ModifyAllegianceGuestPermission(1);
LABEL_51:
    v32 = v31;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
    return v32;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "remove_allegiance");
  v30 = __stricmp(v27->m_data, (const char *)argv);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
  if ( !v30 )
  {
    v31 = CM_House::Event_ModifyAllegianceGuestPermission(0);
    goto LABEL_51;
  }
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&argv,
    L"Please see @help House for more information on how to use this command");
  ClientSystem::AddTextToScroll(v35, (PStringBase<unsigned short> *)&argv, 0x1Au, 1, (unsigned int)v35[17].vfptr);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
  return 1;
}

//----- (00579560) --------------------------------------------------------  // acclient.c:419325
char __thiscall ClientCommunicationSystem::DoHouseStorage(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // eax@1
  char *v4; // ebp@1
  bool v5; // bl@1
  int v6; // eax@6
  char *v7; // ebp@6
  bool v8; // bl@6
  char **v9; // ebp@11
  char **v10; // edi@12
  int v11; // ebp@15
  char *v12; // edi@18
  int v14; // eax@21
  char **v15; // edi@21
  bool v16; // bl@21
  bool v17; // al@26
  bool v18; // bl@28
  int v19; // edx@30
  int v20; // ecx@30
  char **v21; // edi@31
  int v22; // ebp@34
  char *v23; // edi@38
  LONG v24; // eax@38
  int v25; // eax@43
  char **v26; // ebp@43
  bool v27; // bl@43
  bool v28; // al@47
  int v29; // eax@48
  char **v30; // ebp@48
  bool v31; // bl@48
  bool v32; // bl@52
  PSRefBufferCharData<char> *v33; // esi@53
  int v34; // ebx@53
  int v35; // ebx@54
  bool v36; // al@55
  bool v37; // bl@56
  int v38; // esi@57
  bool add; // [sp+13h] [bp-Dh]@5
  PStringBase<char> command; // [sp+14h] [bp-Ch]@1
  PStringBase<char> v41; // [sp+18h] [bp-8h]@1
  ClientSystem *v42; // [sp+1Ch] [bp-4h]@1

  v42 = (ClientSystem *)this;
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>(&v41, "add");
  v3 = __stricmp(command.m_charbuffer->m_data, v41.m_charbuffer->m_data);
  v4 = &v41.m_charbuffer[-2].m_data[12];
  v5 = v3 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v41.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  if ( v5 )
  {
    add = 1;
    goto LABEL_11;
  }
  PStringBase<char>::PStringBase<char>(&v41, "remove");
  v6 = __stricmp(command.m_charbuffer->m_data, v41.m_charbuffer->m_data);
  v7 = &v41.m_charbuffer[-2].m_data[12];
  v8 = v6 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v41.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  if ( v8 )
  {
    add = 0;
LABEL_11:
    JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
    v9 = argv;
    if ( *(argv - 1) == (char *)1 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argv,
        L"Please specify an actual name.");
      ClientSystem::AddTextToScroll(v42, (PStringBase<unsigned short> *)&argv, 0x1Au, 1, (unsigned int)v42[17].vfptr);
      v10 = argv - 5;
      if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v10 )
        (*(void (__thiscall **)(char **, signed int))*v10)(v10, 1);
      v11 = (int)(v9 - 5);
      if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = &command.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v12 )
      {
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
        return 1;
      }
      return 1;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "-all");
    v14 = __stricmp((const char *)v9, (const char *)argv);
    v15 = argv - 5;
    v16 = v14 == 0;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v15 )
      (*(void (__thiscall **)(char **, signed int))*v15)(v15, 1);
    if ( v16 )
    {
      if ( add )
        v17 = CM_House::Event_AddAllStoragePermission();
      else
        v17 = CM_House::Event_RemoveAllStoragePermission();
      v18 = v17;
      if ( InterlockedDecrement((volatile LONG *)v9 - 4) || v9 == (char **)20 )
        goto LABEL_38;
      v19 = (int)*(v9 - 5);
      v20 = (int)(v9 - 5);
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)v9);
      v18 = CM_House::Event_ChangeStoragePermission_Event((AC1Legacy::PStringBase<char> *)&argv, add);
      v21 = argv;
      if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v21 )
        (*(void (__thiscall **)(char **, signed int))*v21)(v21, 1);
      v22 = (int)(v9 - 5);
      if ( InterlockedDecrement((volatile LONG *)(v22 + 4)) || !v22 )
        goto LABEL_38;
      v19 = *(_DWORD *)v22;
      v20 = v22;
    }
    (*(void (__thiscall **)(int, signed int))v19)(v20, 1);
LABEL_38:
    v23 = &command.m_charbuffer[-2].m_data[12];
    v24 = InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]);
    goto LABEL_39;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "remove_all");
  v25 = __stricmp(command.m_charbuffer->m_data, (const char *)argv);
  v26 = argv - 5;
  v27 = v25 == 0;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v26 )
    (*(void (__thiscall **)(char **, signed int))*v26)(v26, 1);
  if ( !v27 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "list");
    v29 = __stricmp(command.m_charbuffer->m_data, (const char *)argv);
    v30 = argv - 5;
    v31 = v29 == 0;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v30 )
      (*(void (__thiscall **)(char **, signed int))*v30)(v30, 1);
    if ( v31
      || (PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "show"),
          v33 = command.m_charbuffer,
          v34 = __stricmp(command.m_charbuffer->m_data, (const char *)argv),
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv),
          !v34) )
    {
      v32 = CM_House::Event_RequestFullGuestList_Event();
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
      return v32;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "add_allegiance");
    v35 = __stricmp(v33->m_data, (const char *)argv);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    if ( v35 )
    {
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "remove_allegiance");
      v38 = __stricmp(v33->m_data, (const char *)argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
      if ( v38 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&argv,
          L"Please see @help House for more information on how to use this command");
        ClientSystem::AddTextToScroll(v42, (PStringBase<unsigned short> *)&argv, 0x1Au, 1, (unsigned int)v42[17].vfptr);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
        return 1;
      }
      v36 = CM_House::Event_ModifyAllegianceStoragePermission(0);
    }
    else
    {
      v36 = CM_House::Event_ModifyAllegianceStoragePermission(1);
    }
    v37 = v36;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
    return v37;
  }
  v28 = CM_House::Event_RemoveAllStoragePermission();
  v23 = &command.m_charbuffer[-2].m_data[12];
  v18 = v28;
  v24 = InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]);
LABEL_39:
  if ( !v24 && v23 )
    (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
  return v18;
}

//----- (00579970) --------------------------------------------------------  // acclient.c:419513
char __thiscall ClientCommunicationSystem::DoHouseBoot(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char **v4; // edi@1
  char **v5; // esi@2
  int v6; // edi@5
  char result; // al@8
  int v8; // eax@9
  char **v9; // esi@9
  bool v10; // bl@9
  bool v11; // bl@13
  bool v12; // al@16
  char **v13; // esi@16
  int v14; // edi@19

  v3 = this;
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  v4 = argv;
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      L"Please see @help House for more information on how to use this command");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argv,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v5 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v5 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
    v6 = (int)(v4 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
    result = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "-all");
    v8 = __stricmp((const char *)v4, (const char *)argv);
    v9 = argv - 5;
    v10 = v8 == 0;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v9 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v9)(v9, 1);
    if ( v10 )
    {
      v11 = CM_House::Event_BootEveryone_Event();
      if ( !InterlockedDecrement((volatile LONG *)v4 - 4) && v4 != (char **)20 )
      {
        (*(void (__thiscall **)(_DWORD, _DWORD))*(v4 - 5))(v4 - 5, 1);
        return v11;
      }
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argv, (const char *)v4);
      v12 = CM_House::Event_BootSpecificHouseGuest_Event((AC1Legacy::PStringBase<char> *)&argv);
      v13 = argv;
      v11 = v12;
      if ( !InterlockedDecrement((volatile LONG *)argv + 1) && v13 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v13)(v13, 1);
      v14 = (int)(v4 - 5);
      if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    }
    result = v11;
  }
  return result;
}

//----- (00579AD0) --------------------------------------------------------  // acclient.c:419588
char __stdcall ClientCommunicationSystem::HelpHouse(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@6
  int v5; // eax@6
  int v6; // esi@8

  if ( type )
  {
    if ( type == 1 )
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@house - Commands that help you manage your house, including guest and storage management.\n");
    else
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@house abandon - Abandons your house.\n@house boot <name> - Removes a player from your house.\n@house boot -all - Removes everyone from your house.\n@house guest add <name> - Adds players to your house guest list.\n@house guest remove <name> - Removes players from your house guest list.\n@house guest add_allegiance - Adds your allegiance to the guest list.\n@house guest remove_allegiance - Removes your allegiance from the guest list.\n@house guest remove_all - Removes all guests from your house guest list.\n@house guest list - Shows the current guest list.\n@house recall - Teleports you to your house.\n@house storage add <name> - Gives a player permission to use your house storage.\n@house storage remove <name> - Removes permission to use your house storage from a player.\n@house storage add_allegiance - Grants storage permission to your allegiance.\n@house storage remove_allegiance - Removes storage permission from your allegiance.\n@house storage remove_all - Removes all storage permissions from guests.);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help house - Commands that help you manage your house, including guest and storage management.\n");
  }
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00579B40) --------------------------------------------------------  // acclient.c:419625
char __thiscall ClientCommunicationSystem::HelpHouseAvailableList(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@hslist <house type> - Lists the number and, if appropriate, positions of houses currently available for purchase. Types include: Apartment, Cottage, Villa, Mansion\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00579B90) --------------------------------------------------------  // acclient.c:419650
char __thiscall ClientCommunicationSystem::HelpAdvancedSquelch(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@squelch - Shows the current list of squelched characters.\n@squelch [-account] <name> - Squelches all messages from a character. With the account flag, this command also stops everything except normal chat coming from the target's other characters.\n@squelch [-message_type] <character> - This will filter out all text messages of a certain type  from a specific character.  For example, the following will filter out all tell messages from Oswald:\n     Example: @squelch -tell Oswald.\n@squelch -reply [-account] [-message_type] - This filters out all text messages from whoever last tell'd you.  You may also use the -account flag and/or limit the squelch by indicating specific message types. For example, this will filter out all tell messages from the account of Oswald, assuming that Oswald was the last person who sent you an @tell:\n     Example: @squelch -reply -account -tell\n\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00579BE0) --------------------------------------------------------  // acclient.c:419675
char __thiscall ClientCommunicationSystem::HelpAdvancedUnSquelch(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@unsquelch - Shows the current list of squelched characters.\n@unsquelch <name> - Removes all squelches from a character, including account squelch.\n@unsquelch [-message_type] <character> : This allows text messages of type message_type to come from a squelched character. For example the following allows assessment messages from a character name Oswald:\n     Example: @unsquelch -assessment Oswald\n@unsquelch -reply [-account] [-message_type] : This allows text messages of type message_type from whoever last sent you an @tell. For example, the following will allow any character on Oswald's account to once again send you @tells, assuming that Oswald was the last person who sent you an @tell:\n     Example: @squelch -reply -account -tell\n\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00579C30) --------------------------------------------------------  // acclient.c:419700
char __thiscall ClientCommunicationSystem::ProcessSquelchArgs(ClientCommunicationSystem *this, int argc, char **argv, bool requires_name_output, bool *is_zoneid, PStringBase<char> *name, unsigned int *mask)
{
  ClientCommunicationSystem *v7; // esi@1
  unsigned int *v8; // ecx@1
  int v9; // ecx@1
  int v10; // esi@2
  char result; // al@5
  int v12; // ebp@6
  char *v13; // eax@7
  int v14; // eax@8
  char *v15; // esi@8
  bool v16; // bl@8
  char *v17; // esi@12
  int v18; // eax@15
  char *v19; // esi@15
  bool v20; // bl@15
  char *v21; // esi@22
  PSRefBufferCharData<char> **v22; // ebx@27
  PSRefBufferCharData<char> *v23; // eax@27
  int v24; // esi@28
  PSRefBufferCharData<char> *v25; // eax@31
  int v26; // esi@32
  unsigned int v27; // eax@36
  int v28; // esi@36
  char *v29; // esi@37
  PStringBase<char> *v30; // ebx@41
  PSRefBufferCharData<char> *v31; // eax@41
  int v32; // esi@42
  PSRefBufferCharData<char> *v33; // ebx@45
  int v34; // esi@46
  LONG v35; // eax@36
  bool is_reply; // [sp+Fh] [bp-15h]@6
  PStringBase<char> tmp; // [sp+10h] [bp-14h]@8
  ClientSystem *v38; // [sp+14h] [bp-10h]@1
  PStringBase<char> v39; // [sp+18h] [bp-Ch]@8
  PStringBase<char> v40; // [sp+1Ch] [bp-8h]@15
  unsigned int ltt; // [sp+20h] [bp-4h]@20

  v7 = this;
  v8 = mask;
  *is_zoneid = 0;
  *v8 = 1;
  v38 = (ClientSystem *)v7;
  PStringBase<char>::set(name, &::name);
  v9 = argc;
  if ( argc >= 1 )
  {
    v12 = 0;
    is_reply = 0;
    if ( argc <= 0 )
    {
LABEL_41:
      v30 = JoinArgsAsName((PStringBase<char> *)&argc, v9 - v12, &argv[v12]);
      v31 = name->m_charbuffer;
      if ( name->m_charbuffer != v30->m_charbuffer )
      {
        v32 = (int)&v31[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v31[-1]) && v32 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
        v33 = v30->m_charbuffer;
        name->m_charbuffer = v33;
        InterlockedIncrement((volatile LONG *)&v33[-1]);
      }
      v34 = argc - 20;
      if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v34 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
      if ( requires_name_output && *(_DWORD *)&name->m_charbuffer[-1].m_data[12] == 1 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&requires_name_output,
          L"You have not specified a squelch target.");
        ClientSystem::AddTextToScroll(
          v38,
          (PStringBase<unsigned short> *)&requires_name_output,
          0x1Au,
          1,
          (unsigned int)v38[17].vfptr);
        v28 = requires_name_output - 20;
        v35 = InterlockedDecrement((volatile LONG *)(requires_name_output - 20 + 4));
LABEL_52:
        if ( !v35 && v28 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
      }
    }
    else
    {
      do
      {
        v13 = argv[v12];
        if ( *v13 != 45 )
          break;
        PStringBase<char>::PStringBase<char>(&tmp, v13 + 1);
        PStringBase<char>::PStringBase<char>(&v39, "reply");
        v14 = __stricmp(tmp.m_charbuffer->m_data, v39.m_charbuffer->m_data);
        v15 = &v39.m_charbuffer[-2].m_data[12];
        v16 = v14 == 0;
        if ( !InterlockedDecrement((volatile LONG *)&v39.m_charbuffer[-1]) && v15 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
        if ( v16 )
        {
          v17 = &tmp.m_charbuffer[-2].m_data[12];
          is_reply = 1;
          if ( !InterlockedDecrement((volatile LONG *)&tmp.m_charbuffer[-1]) && v17 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
        }
        else
        {
          PStringBase<char>::PStringBase<char>(&v40, "account");
          v18 = __stricmp(tmp.m_charbuffer->m_data, v40.m_charbuffer->m_data);
          v19 = &v40.m_charbuffer[-2].m_data[12];
          v20 = v18 == 0;
          if ( !InterlockedDecrement((volatile LONG *)&v40.m_charbuffer[-1]) && v19 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
          if ( v20 )
          {
            *is_zoneid = 1;
          }
          else
          {
            ltt = 0;
            if ( !LogTextTypeEnumMapper::LogTextTypeFromString(tmp.m_charbuffer->m_data, &ltt) )
            {
              PStringBase<char>::sprintf(&tmp, "\"%s\" is not a valid squelch category.", argv[v12++]);
              ClientSystem::AddTextToScroll(v38, &tmp, 0x1Au, 1, (unsigned int)v38[17].vfptr);
              v29 = &tmp.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&tmp.m_charbuffer[-1]) && v29 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
              return 0;
            }
            *mask = ltt;
          }
          v21 = &tmp.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&tmp.m_charbuffer[-1]) && v21 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
        }
        v9 = argc;
      }
      while ( v12 < argc );
      if ( !is_reply )
        goto LABEL_41;
      v22 = (PSRefBufferCharData<char> **)gmCCommunicationSystem::GetLastTellerName((PStringBase<char> *)&requires_name_output);
      v23 = name->m_charbuffer;
      if ( name->m_charbuffer != *v22 )
      {
        v24 = (int)&v23[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v23[-1]) && v24 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
        v25 = *v22;
        name->m_charbuffer = *v22;
        InterlockedIncrement((volatile LONG *)&v25[-1]);
      }
      v26 = requires_name_output - 20;
      if ( !InterlockedDecrement((volatile LONG *)(requires_name_output - 20 + 4)) && v26 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
      if ( *(_DWORD *)&name->m_charbuffer[-1].m_data[12] == 1 )
      {
        v27 = _wcslen(L"A player must @tell you before you can squelch them with this command.");
        PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&requires_name_output, v27);
        _wcscpy(
          (wchar_t *)requires_name_output,
          L"A player must @tell you before you can squelch them with this command.");
        ClientSystem::AddTextToScroll(
          v38,
          (PStringBase<unsigned short> *)&requires_name_output,
          0x1Au,
          1,
          (unsigned int)v38[17].vfptr);
        v28 = requires_name_output - 20;
        v35 = InterlockedDecrement((volatile LONG *)(requires_name_output - 20 + 4));
        goto LABEL_52;
      }
    }
    result = 1;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&requires_name_output,
      L"Not enough arguements.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v7->vfptr,
      (PStringBase<unsigned short> *)&requires_name_output,
      0x1Au,
      1,
      v7->m_idCurrentCommandSource);
    v10 = requires_name_output - 20;
    if ( !InterlockedDecrement((volatile LONG *)(requires_name_output - 20 + 4)) )
    {
      if ( v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0057A010) --------------------------------------------------------  // acclient.c:419897
char __thiscall ClientCommunicationSystem::DoMessageTypes(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  unsigned int v4; // ST10_4@1
  PStringBase<unsigned short> *v5; // eax@1
  char *v6; // esi@1
  char *v7; // esi@4
  PStringBase<char> msg; // [sp+8h] [bp-8h]@1
  PStringBase<unsigned short> result; // [sp+Ch] [bp-4h]@1

  msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  gmCCommunicationSystem::GetListofSquelchChannels(&msg);
  v4 = v3->m_idCurrentCommandSource;
  v5 = PStringBase<char>::to_wpstring(&msg, &result, 0);
  ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v5, 0, 1, v4);
  v6 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = &msg.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return 1;
}

//----- (0057A0B0) --------------------------------------------------------  // acclient.c:419924
char __thiscall ClientCommunicationSystem::HelpAge(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@age - Displays your total gameplay time.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A100) --------------------------------------------------------  // acclient.c:419947
char __thiscall ClientCommunicationSystem::HelpBirth(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@birth - Displays when your character was created.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A150) --------------------------------------------------------  // acclient.c:419970
char __thiscall ClientCommunicationSystem::HelpDay(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(
    &v8,
    "@day - A toggle that lightens the outdoor landscape. Note that this command may take several seconds to take effect. \n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A1A0) --------------------------------------------------------  // acclient.c:419995
char __stdcall ClientCommunicationSystem::HelpEndurance(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "The endurance attribute has a number of abilities tied to it.\nFirst, some combination of strength and endurance (with endurance being more important) now allows one to regenerate hit points at a faster rate the higher one's endurance is.  This bonus is in addition to any regeneration spells one may have placed upon themselves.  This endurance regeneration bonus caps at around 110%.\nSecond, the higher a player's Endurance, the less stamina one uses while attacking.  This benefit is tied to Endurance only, and it caps out at around 50% less stamina used per attack.  The minimum stamina used per attack remains one.\nThird, the higher a player's Endurance, the more likely they are not to use a point of stamina to successfully evade a missile or melee attack.  A player is required to have Melee Defense for melee attacks or Missile Defense for missile attacks trained or specialized in order for this specific ability to work.  This benefit is tied to Endurance only, and it caps out at around a 75% chance to av);
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@endurance - Explains how endurance affects your character.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A200) --------------------------------------------------------  // acclient.c:420023
char __thiscall ClientCommunicationSystem::HelpFrameRate(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@framerate - Toggles the framerate display.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A250) --------------------------------------------------------  // acclient.c:420046
char __thiscall ClientCommunicationSystem::DoLoc(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char *v4; // esi@2
  CPhysicsObj *v6; // edi@5
  char *v7; // esi@7
  char *v8; // esi@10
  PStringBase<unsigned short> i_text; // [sp+4h] [bp-B4h]@2
  PStringBase<char> msg; // [sp+8h] [bp-B0h]@10
  Position p; // [sp+Ch] [bp-ACh]@6
  char text[100]; // [sp+54h] [bp-64h]@10

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"Unexpected arguments to @loc");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
    v4 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    v6 = SmartBox::smartbox->player;
    if ( v6 )
    {
      p.vfptr = (PackObjVtbl *)&Position::vftable;
      p.objcell_id = 0;
      LODWORD(p.frame.qw) = 1065353216;
      LODWORD(p.frame.qx) = 0;
      LODWORD(p.frame.qy) = 0;
      LODWORD(p.frame.qz) = 0;
      LODWORD(p.frame.m_fOrigin.x) = 0;
      LODWORD(p.frame.m_fOrigin.y) = 0;
      LODWORD(p.frame.m_fOrigin.z) = 0;
      Frame::cache(&p.frame);
      p.objcell_id = v6->m_position.objcell_id;
      Frame::operator=((int)&p.frame, (int)&v6->m_position.frame);
      if ( p.objcell_id )
      {
        text[0] = 0;
        memset(&text[1], 0, 0x60u);
        *(_WORD *)&text[97] = 0;
        text[99] = 0;
        Position::ToString(&p, text, 0x64u);
        msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        PStringBase<char>::sprintf(&msg, "Your location is: %s\n", text);
        ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &msg, 0, 1, v3->m_idCurrentCommandSource);
        v8 = &msg.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      else
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"Not in valid cell!");
        ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
        v7 = (char *)&i_text.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v7 )
        {
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
          return 1;
        }
      }
    }
  }
  return 1;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0057A430) --------------------------------------------------------  // acclient.c:420120
char __stdcall ClientCommunicationSystem::HelpLoc(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@loc - Displays your current position in your chat window. Use this information when you wish to submit a bug report.\n");
  else
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&type, "@loc - Displays your current position.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A490) --------------------------------------------------------  // acclient.c:420146
char __thiscall ClientCommunicationSystem::DoPKLite(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  unsigned int v6; // eax@6
  HashBaseData<unsigned long> *v7; // eax@8

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please see @help pklite for more information on how to use this command.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    if ( SmartBox::smartbox )
      v6 = SmartBox::smartbox->player_id;
    else
      v6 = 0;
    v7 = ClientObjMaintSystem::GetWeenieObject(v6);
    if ( v7 && ((int (__thiscall *)(HashBaseData<unsigned long> *))v7->vfptr[7].__vecDelDtor)(v7) )
    {
      ClientCommunicationSystem::HandleFailureEvent(v3, 0x507u, &PStringBase<unsigned short>::null_string);
      return 1;
    }
    CM_Character::Event_EnterPKLite();
  }
  return 1;
}

//----- (0057A540) --------------------------------------------------------  // acclient.c:420190
char __stdcall ClientCommunicationSystem::HelpPKLite(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@pklite - Sets your status to Player Killer Lite (PK Lite). PK Lite characters can attack other PK Lite characters. They cannot, however, attack Player Killer (PK) characters. PK Lite characters operate under the same combat rules as PK characters, except that if you are killed  in a PK Lite battle, you will not accrue vitae and you will not drop any coins or items. Only Non-Player Killers may use this command to enter PK Lite. Dying in a PK Lite battle and logging off will restore your status to Non-Player Killer.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@pklite - Sets your status to Player Killer Lite. Type @help pklite for more details.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A5A0) --------------------------------------------------------  // acclient.c:420218
char __thiscall ClientCommunicationSystem::HelpVersion(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@version - Tells you what version of the software you are using.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A5F0) --------------------------------------------------------  // acclient.c:420241
char __thiscall ClientCommunicationSystem::HelpClear(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@clear - Clears the chat box of all text.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A640) --------------------------------------------------------  // acclient.c:420264
bool __thiscall ClientCommunicationSystem::DoTitle(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  unsigned int v4; // eax@1
  PSRefBufferCharData<char> *v5; // ebx@3
  unsigned int v6; // eax@3
  char *v7; // esi@4
  int v8; // esi@7
  LONG v9; // eax@7
  bool result; // al@9
  PStringBase<unsigned short> *v11; // eax@10
  PStringBase<unsigned short> i_text; // [sp+8h] [bp-98h]@9
  PStringBase<char> strTitle; // [sp+Ch] [bp-94h]@3
  StringInfo siTitle; // [sp+10h] [bp-90h]@10

  v3 = this;
  v4 = this->m_idCurrentCommandSource;
  if ( v4 == 1 || v4 == 8 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &i_text,
      L"This command must be issued from a popup chat window.");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0, 1, v3->m_idCurrentCommandSource);
    v8 = (int)&i_text.m_charbuffer[-1].m_data[6];
    v9 = InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]);
  }
  else
  {
    JoinArgs(&strTitle, argc, argv);
    v5 = strTitle.m_charbuffer;
    v6 = *(_DWORD *)&strTitle.m_charbuffer[-1].m_data[12];
    if ( v6 != 1 )
    {
      if ( v6 < 0x64 )
      {
        StringInfo::StringInfo(&siTitle);
        v11 = PStringBase<char>::to_wpstring(&strTitle, &i_text, 0);
        StringInfo::SetLiteralValue(&siTitle, v11, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_text);
        CM_UI::SendNotice_SetChatWindowTitle(v3->m_idCurrentCommandSource, &siTitle);
        StringInfo::~StringInfo(&siTitle);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strTitle);
        result = 1;
      }
      else
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &i_text,
          L"Window title length cannot exceed 100 characters.");
        ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0, 1, v3->m_idCurrentCommandSource);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_text);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strTitle);
        result = 1;
      }
      return result;
    }
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&strTitle,
      L"You must provide a new title for the window.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&strTitle,
      0,
      1,
      v3->m_idCurrentCommandSource);
    v7 = &strTitle.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strTitle.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    v8 = (int)&v5[-2].m_data[12];
    v9 = InterlockedDecrement((volatile LONG *)&v5[-1]);
  }
  if ( !v9 )
  {
    if ( v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
  return 1;
}

//----- (0057A7E0) --------------------------------------------------------  // acclient.c:420344
char __thiscall ClientCommunicationSystem::HelpTitle(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  PStringBase<char> v8; // [sp+0h] [bp-4h]@1

  v8.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PStringBase<char>::PStringBase<char>(&v8, "@title <new title> - Sets the title of the popup chat window.\n");
  v4 = v8.m_charbuffer;
  v5 = *(_DWORD *)&v8.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, v8.m_charbuffer->m_data, v5 - 1);
    v4 = v8.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A830) --------------------------------------------------------  // acclient.c:420367
char __stdcall ClientCommunicationSystem::HelpFilter(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "The @filter commands filter out all incoming messages of a certain type. Type @messagetypes to see a list of the message types that you can filter.\n@filter - List all the filters currently in place.\n@filter <-message_type> - Filters out all incoming messages of a specific type. For example, the following will filter out all spellcasting text: \n     Example: @filter -spellcasting\n@filter -all - Filters out all incoming messages of all types.\n\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@filter - Commands to filter out incoming messages.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A890) --------------------------------------------------------  // acclient.c:420395
char __stdcall ClientCommunicationSystem::HelpUnFilter(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "The @unfilter commands remove specific filters from your incoming messages. For a complete list of message types that you can filter, type @help messagetypes.\n@unfilter <-message_type> - Removes filters on incoming messages of a specific type.  For example, the following allows spellcasting text to resume:\n     Example: @unfilter -spellcasting\n@unfilter -all - Removes all filters on incoming messages of all types.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@unfilter - Commands to remove filters from incoming messages.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A8F0) --------------------------------------------------------  // acclient.c:420423
char __stdcall ClientCommunicationSystem::HelpLoadFile(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "usage: @loadfile filename\nThis command reads in the specified text file and executes every line as if you typed it in the chat entry field.  Essentially, this plays a script.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@loadfile - Reads in the given text file and executes each line in the chat entry field.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A950) --------------------------------------------------------  // acclient.c:420451
char __stdcall ClientCommunicationSystem::DoSetOutputHelp(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@4
  int v5; // eax@4
  int v6; // esi@6

  if ( type )
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@log <name> - Echoes chat text to a logfile. All the information that appears in your chat window after you type this command will be copied into a text file. Choose the file you are copying to by naming it in the command. If this file already exists, it will add the additional text to the end of it. To turn off logging, simply retype @log.\n@log AClog.txt - Echoes chat text to a log file named Aclog.txt in your Asheron's Call directory. After you use this command, all the information that appears in your chat window will be written to a file in your Asheron's Call directory named Aclog.txt.\n@log - If you are currently copying the text in your chat window to a logfile, this command will stop the process.\n");
  else
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@log - Commands to echo chat text to a logfile.\n");
  v4 = type;
  v5 = *(_DWORD *)(type - 4);
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
    v4 = type;
  }
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057A9B0) --------------------------------------------------------  // acclient.c:420479
bool __thiscall ClientCommunicationSystem::DoChannelList(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  int v4; // esi@2
  bool result; // al@5
  int v6; // eax@6
  int v7; // esi@6
  unsigned int v8; // ebx@6

  v3 = this;
  if ( argc == 1 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, *argv);
    v6 = ChannelSystem::GetChannelID((AC1Legacy::PStringBase<char> *)&argc);
    v7 = argc;
    v8 = v6;
    if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
    {
      result = CM_Communication::Event_ChannelList(v8);
    }
    else
    {
      ClientCommunicationSystem::HandleFailureEvent(v3, 0x422u, &PStringBase<unsigned short>::null_string);
      result = 1;
    }
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please specify the channel name.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0057AA80) --------------------------------------------------------  // acclient.c:420530
bool __thiscall ClientCommunicationSystem::DoChannelOn(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  int v4; // esi@2
  bool result; // al@5
  int v6; // eax@6
  int v7; // esi@6
  unsigned int v8; // ebx@6

  v3 = this;
  if ( argc == 1 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, *argv);
    v6 = ChannelSystem::GetChannelID((AC1Legacy::PStringBase<char> *)&argc);
    v7 = argc;
    v8 = v6;
    if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
    {
      result = CM_Communication::Event_AddToChannel(v8);
    }
    else
    {
      ClientCommunicationSystem::HandleFailureEvent(v3, 0x422u, &PStringBase<unsigned short>::null_string);
      result = 1;
    }
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please specify the channel name.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0057AB50) --------------------------------------------------------  // acclient.c:420581
bool __thiscall ClientCommunicationSystem::DoChannelOff(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  int v4; // esi@2
  bool result; // al@5
  int v6; // eax@6
  int v7; // esi@6
  unsigned int v8; // ebx@6

  v3 = this;
  if ( argc == 1 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, *argv);
    v6 = ChannelSystem::GetChannelID((AC1Legacy::PStringBase<char> *)&argc);
    v7 = argc;
    v8 = v6;
    if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
    {
      result = CM_Communication::Event_RemoveFromChannel(v8);
    }
    else
    {
      ClientCommunicationSystem::HandleFailureEvent(v3, 0x422u, &PStringBase<unsigned short>::null_string);
      result = 1;
    }
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please specify the channel name.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0057AC20) --------------------------------------------------------  // acclient.c:420632
char ClientCommunicationSystem::PlayerIsPSR()
{
  InterfaceSystem *v1; // eax@1
  Interface *v2; // esi@1
  int v3; // ebx@3
  PlayerDesc *v4; // esi@5
  int v6; // [sp-8h] [bp-28h]@1
  Interface *_rpInterface; // [sp+Ch] [bp-14h]@1
  TResult result; // [sp+10h] [bp-10h]@1
  char v9; // [sp+14h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPD; // [sp+18h] [bp-8h]@1

  _rpInterface = 0;
  v1 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v1, &result, &PlayerDesc_ClassType_30, &_rpInterface);
  v2 = _rpInterface;
  v6 = (int)_rpInterface;
  spPD.m_pInterface = 0;
  spPD.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v3 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v9, v6, 0);
  if ( v2 )
    v2->vfptr->Release(v2);
  v4 = spPD.m_pInterface;
  if ( (_DWORD)spPD.m_pInterface )
  {
    if ( v3 >= 0 && PlayerDesc::PlayerIsPSR(spPD.m_pInterface) )
    {
      v4->vfptr->Release((Interface *)v4);
      return 1;
    }
    v4->vfptr->Release((Interface *)v4);
  }
  return 0;
}

//----- (0057ACC0) --------------------------------------------------------  // acclient.c:420670
char __thiscall ClientCommunicationSystem::CloseLogFile(ClientCommunicationSystem *this)
{
  ClientCommunicationSystem *v1; // esi@1
  unsigned int v2; // ST10_4@2
  PStringBase<unsigned short> *v3; // eax@2
  char *v4; // esi@2
  char *v5; // esi@5
  char v6; // al@8
  PStringBase<char> msg; // [sp+4h] [bp-8h]@2
  PStringBase<unsigned short> result; // [sp+8h] [bp-4h]@2

  v1 = this;
  if ( ClientSystem::s_pLogFile )
  {
    PStringBase<char>::PStringBase<char>(&msg, 0, "Chat log %s closed.\n", this->m_strLogName.m_charbuffer);
    v2 = v1->m_idCurrentCommandSource;
    v3 = PStringBase<char>::to_wpstring(&msg, &result, 0);
    ClientSystem::AddTextToScroll((ClientSystem *)&v1->vfptr, v3, 0, 1, v2);
    v4 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    _fclose(ClientSystem::s_pLogFile);
    v5 = &msg.m_charbuffer[-2].m_data[12];
    ClientSystem::s_pLogFile = 0;
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6;
}

//----- (0057AD80) --------------------------------------------------------  // acclient.c:420709
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::grow(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0057ADD0) --------------------------------------------------------  // acclient.c:420729
void __thiscall ClientCommunicationSystem::OnShutdown(ClientCommunicationSystem *this)
{
  ClientCommunicationSystem::CloseLogFile(this);
  if ( ClientCommunicationSystem::s_pCommunicationSystem )
  {
    ((void (*)(void))ClientCommunicationSystem::s_pCommunicationSystem->vfptr->Release)();
    ClientCommunicationSystem::s_pCommunicationSystem = 0;
  }
}
// 8707EC: using guessed type struct ClientCommunicationSystem *ClientCommunicationSystem::s_pCommunicationSystem;

//----- (0057ADF0) --------------------------------------------------------  // acclient.c:420741
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__WeenieError(ClientCommunicationSystem *this, unsigned int etype)
{
  ClientCommunicationSystem::HandleFailureEvent(this, etype, &PStringBase<unsigned short>::null_string);
  return 0;
}

//----- (0057AE10) --------------------------------------------------------  // acclient.c:420748
char __stdcall ClientCommunicationSystem::HelpAllegiance(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@2
  int v5; // eax@2
  int v6; // esi@4
  LONG v7; // eax@4
  ClientCommunicationSystem::HelpType v8; // ecx@5
  int v9; // eax@5
  PStringBase<char> *v10; // ebx@5
  int v11; // esi@7
  PStringBase<char> *v12; // eax@10
  PSRefBufferCharData<char> *v13; // ecx@10

  if ( type )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@allegiance boot [-account] <name> - Removes a character from your allegiance.\n@allegiance ban <add/remove> <name> - Bans all characters on the given character's account from your allegiance (and boots them too!)\n@allegiance ban list - List the characters whose accounts are banned from your allegiance.\n WARNING! Officers banning or booting a character by account could wind up in a situation where they are no longer in the allegiance if they boot a character that is above them in the hierarchy.\n@allegiance info <name> - Requests information on a member of your allegiance.\n@allegiance chat <on/off> - Turn allegiance chat on and off.\n@allegiance chat kick <name>[, <reason>] - Kick a player temporarily from the allegiance chat room.\n@allegiance chat gag <name> - Gags a player so that they cannot see or speak in the allegiance chat room for 5 minutes.\n@allegiance chat ungag <name> - Ungags a gagged allegiance member so that they may once again see and speak in the allegiance chat room.\n@allegiance bro);
    v8 = type;
    v9 = *(_DWORD *)(type - 4);
    v10 = msg;
    if ( v9 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v9 - 1);
      v8 = type;
    }
    v11 = v8 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@allegiance motd - Displays or sets the message of the day for your allegiance, see @help motd for more information.\n");
    v12 = msg;
    v13 = msg[-1].m_charbuffer;
    if ( v13 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v13[-1].m_data[15]);
      v12 = msg;
    }
    v6 = (int)&v12[-5];
    v7 = InterlockedDecrement((volatile LONG *)&v12[-4]);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@allegiance - Commands to help manage your allegiance.\n");
    v4 = type;
    v5 = *(_DWORD *)(type - 4);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
      v4 = type;
    }
    v6 = v4 - 20;
    v7 = InterlockedDecrement((volatile LONG *)(v4 - 20 + 4));
  }
  if ( !v7 && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057AEF0) --------------------------------------------------------  // acclient.c:420811
char __thiscall ClientCommunicationSystem::DoAllegianceBoot(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char *v4; // esi@2
  char **v5; // esi@5
  char result; // al@8
  char v7; // bl@9
  PStringBase<char> v8; // ST10_4@11
  char *v9; // eax@11
  unsigned int v10; // ST10_4@13
  PStringBase<unsigned short> *v11; // eax@13
  char *v12; // esi@13
  bool v13; // al@16
  PSRefBufferCharData<unsigned short> *v14; // esi@16
  char v15; // bl@16
  char *v16; // esi@19
  int v17; // esi@22
  char **v18; // esi@25
  PStringBase<unsigned short> i_text; // [sp+Ch] [bp-18h]@2
  PStringBase<char> msg; // [sp+10h] [bp-14h]@13
  PStringBaseIter<char> iter; // [sp+14h] [bp-10h]@9

  v3 = this;
  JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"Please specify an actual name.");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
    v4 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) )
    {
      if ( v5 )
        (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
    }
    result = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "-account");
    v7 = 0;
    iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
    iter.pstring_ptr = (PStringBase<char> *)&argv;
    iter.curr = 0;
    iter.mark = 0;
    if ( PStringBaseIter_Common<char>::FindSubString(
           (PStringBaseIter_Common<char> *)&iter.vfptr,
           (PStringBase<char> *)&argc,
           0) )
    {
      iter.mark = iter.curr;
      v7 = 1;
      PStringBaseIter_Common<char>::Next((PStringBaseIter_Common<char> *)&iter.vfptr, *(_DWORD *)(argc - 4));
      PStringBaseIter<char>::Replace(&iter, &PStringBase<char>::s_NullBuffer);
    }
    v8.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
    PStringBase<char>::trim((PStringBase<char> *)&argv, 1, 1, v8);
    v9 = " (Account)";
    if ( !v7 )
      v9 = &name;
    PStringBase<char>::PStringBase<char>(&msg, 0, "Attempting to boot %s%s...\n", argv, v9);
    v10 = v3->m_idCurrentCommandSource;
    v11 = PStringBase<char>::to_wpstring(&msg, &i_text, 0);
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v11, 0, 1, v10);
    v12 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&i_text, (const char *)argv);
    v13 = CM_Allegiance::Event_BreakAllegianceBoot((AC1Legacy::PStringBase<char> *)&i_text, (unsigned __int8)v7);
    v14 = i_text.m_charbuffer;
    v15 = v13;
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer->m_data[2]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v14->m_data[0])(v14, 1);
    v16 = &msg.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    v17 = argc - 20;
    iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
    v18 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v18 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v18)(v18, 1);
    result = v15;
  }
  return result;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0057B130) --------------------------------------------------------  // acclient.c:420905
bool __thiscall ClientCommunicationSystem::DoStupidChannelHack(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  int v4; // esi@2
  bool result; // al@5

  v3 = this;
  if ( argc > 0 )
  {
    result = ClientCommunicationSystem::DoChannelCommand(this, argc, argv);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"You must specify the text you wish to broadcast!");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v4 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    result = 1;
  }
  return result;
}

//----- (0057B1A0) --------------------------------------------------------  // acclient.c:420939
char __stdcall ClientCommunicationSystem::HelpChattingGroup(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@2
  int v5; // eax@2
  int v6; // esi@4
  LONG v7; // eax@4
  ClientCommunicationSystem::HelpType v8; // ecx@5
  int v9; // eax@5
  PStringBase<char> *v10; // esi@5
  int v11; // ebx@7
  PStringBase<char> *v12; // eax@10
  PSRefBufferCharData<char> *v13; // ecx@10
  int v14; // ebx@12
  PStringBase<char> *v15; // ecx@15
  PSRefBufferCharData<char> *v16; // eax@15
  int v17; // ebx@17
  PStringBase<char> *v18; // eax@20
  PSRefBufferCharData<char> *v19; // ecx@20
  int v20; // ebx@22
  PStringBase<char> *v21; // ebx@25
  PSRefBufferCharData<char> *v22; // eax@25
  int v23; // ebx@27
  PStringBase<char> *v24; // ecx@30
  PSRefBufferCharData<char> *v25; // eax@30

  if ( type )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@chat - Sets whether or not you receive normal chat.\n");
    v8 = type;
    v9 = *(_DWORD *)(type - 4);
    v10 = msg;
    if ( v9 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v9 - 1);
      v8 = type;
    }
    v11 = v8 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@notell - Sets whether or not you receive @tell's.\n");
    v12 = msg;
    v13 = msg[-1].m_charbuffer;
    if ( v13 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v13[-1].m_data[15]);
      v12 = msg;
    }
    v14 = (int)&v12[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v12[-4]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    ClientCommunicationSystem::HelpReply(0, "@reply", v10);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@retell - Sends some text to the last person you @tell'd.\n");
    v15 = msg;
    v16 = msg[-1].m_charbuffer;
    if ( v16 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v16[-1].m_data[15]);
      v15 = msg;
    }
    v17 = (int)&v15[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v15[-4]) && v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, "@say - Says some text to everyone around you.");
    v18 = msg;
    v19 = msg[-1].m_charbuffer;
    if ( v19 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v19[-1].m_data[15]);
      v18 = msg;
    }
    v20 = (int)&v18[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v18[-4]) && v20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@tell - Sends a private message to another character.\n");
    v21 = msg;
    v22 = msg[-1].m_charbuffer;
    if ( v22 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v22[-1].m_data[15]);
      v21 = msg;
    }
    v23 = (int)&v21[-5];
    if ( !InterlockedDecrement((volatile LONG *)(v23 + 4)) && v23 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "a", v10);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "c", v10);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "m", v10);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "p", v10);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "v", v10);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "f", v10);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, "@afk - Set your away-from-keyboard status.\n");
    v24 = msg;
    v25 = msg[-1].m_charbuffer;
    if ( v25 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v25[-1].m_data[15]);
      v24 = msg;
    }
    v6 = (int)&v24[-5];
    v7 = InterlockedDecrement((volatile LONG *)&v24[-4]);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help chatting - How to chat publically and privately.\n");
    v4 = type;
    v5 = *(_DWORD *)(type - 4);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
      v4 = type;
    }
    v6 = v4 - 20;
    v7 = InterlockedDecrement((volatile LONG *)(v4 - 20 + 4));
  }
  if ( !v7 && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057B3F0) --------------------------------------------------------  // acclient.c:421069
char __thiscall ClientCommunicationSystem::DoAFK(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // ebp@1
  PSRefBufferCharData<char> *v4; // esi@1
  int v5; // eax@2
  char *v6; // esi@2
  bool v7; // bl@2
  char *v8; // esi@7
  InterfaceSystem *v9; // eax@11
  char **v10; // esi@11
  PlayerDesc *v11; // esi@15
  int v12; // eax@19
  char *v13; // esi@19
  bool v14; // bl@19
  InterfaceSystem *v15; // eax@23
  char **v16; // esi@23
  PlayerDesc *v17; // esi@27
  int v18; // eax@31
  char *v19; // esi@31
  bool v20; // bl@31
  unsigned int v21; // eax@35
  const unsigned __int16 *v22; // eax@37
  bool v23; // bl@38
  AC1Legacy::PStringBase<char> *v24; // eax@40
  int v25; // esi@40
  int v26; // edx@42
  char **v27; // esi@44
  PStringBase<char> *v28; // eax@45
  PStringBase<unsigned short> *v29; // eax@46
  int v30; // esi@46
  char *v31; // edx@52
  char *v32; // esi@53
  int v33; // edx@55
  int v35; // [sp+0h] [bp-2Ch]@11
  int v36; // [sp+0h] [bp-2Ch]@23
  PStringBase<char> v37; // [sp+4h] [bp-28h]@11
  PStringBase<char> command; // [sp+18h] [bp-14h]@1
  PStringBase<char> v39; // [sp+1Ch] [bp-10h]@2
  PStringBase<char> v40; // [sp+20h] [bp-Ch]@1
  InterfacePtr<PlayerDesc> pPlayerDesc; // [sp+24h] [bp-8h]@11

  v3 = this;
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>(&v40, &name);
  v4 = command.m_charbuffer;
  if ( !__stricmp(command.m_charbuffer->m_data, v40.m_charbuffer->m_data) )
    goto LABEL_59;
  PStringBase<char>::PStringBase<char>(&v39, "on");
  v5 = __stricmp(v4->m_data, v39.m_charbuffer->m_data);
  v6 = &v39.m_charbuffer[-2].m_data[12];
  v7 = v5 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v39.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  if ( v7 )
LABEL_59:
    v7 = 1;
  v8 = &v40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v40.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  if ( v7 )
  {
    argc = 0;
    argv = 0;
    v9 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v9, (TResult *)&v40, &PlayerDesc_ClassType_30, (Interface **)&argv);
    v35 = (int)argv;
    v37.m_charbuffer = 0;
    v10 = argv;
    pPlayerDesc.m_pInterface = 0;
    pPlayerDesc.m_trStatus.m_val = 0;
    if ( argv )
      (*(void (__thiscall **)(char **))((void (__thiscall **)(_DWORD))*argv + 4))(argv);
    InterfacePtr<PlayerDesc>::_QueryInterface(&pPlayerDesc, (int)&v39, v35, (int)v37.m_charbuffer);
    if ( v10 )
      (*((void (__thiscall **)(char **))*v10 + 5))(v10);
    v11 = pPlayerDesc.m_pInterface;
    CBaseQualities::InqBool((CBaseQualities *)&pPlayerDesc.m_pInterface->vfptr, 0x6Eu, &argc);
    if ( !argc )
      CM_Communication::Event_SetAFKMode(1);
    if ( v11 )
      v11->vfptr->Release((Interface *)v11);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(&v40, "off");
    v12 = __stricmp(command.m_charbuffer->m_data, v40.m_charbuffer->m_data);
    v13 = &v40.m_charbuffer[-2].m_data[12];
    v14 = v12 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v40.m_charbuffer[-1]) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    if ( v14 )
    {
      argc = 0;
      argv = 0;
      v15 = InterfaceSystem::GetInstance();
      InterfaceSystem::GetClass(v15, (TResult *)&v40, &PlayerDesc_ClassType_30, (Interface **)&argv);
      v36 = (int)argv;
      v37.m_charbuffer = 0;
      v16 = argv;
      pPlayerDesc.m_pInterface = 0;
      pPlayerDesc.m_trStatus.m_val = 0;
      if ( argv )
        (*(void (__thiscall **)(char **))((void (__thiscall **)(_DWORD))*argv + 4))(argv);
      InterfacePtr<PlayerDesc>::_QueryInterface(&pPlayerDesc, (int)&v39, v36, (int)v37.m_charbuffer);
      if ( v16 )
        (*((void (__thiscall **)(char **))*v16 + 5))(v16);
      v17 = pPlayerDesc.m_pInterface;
      CBaseQualities::InqBool((CBaseQualities *)&pPlayerDesc.m_pInterface->vfptr, 0x6Eu, &argc);
      if ( argc )
        CM_Communication::Event_SetAFKMode(0);
      if ( v17 )
        v17->vfptr->Release((Interface *)v17);
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&v40, "msg");
      v18 = __stricmp(command.m_charbuffer->m_data, v40.m_charbuffer->m_data);
      v19 = &v40.m_charbuffer[-2].m_data[12];
      v20 = v18 == 0;
      if ( !InterlockedDecrement((volatile LONG *)&v40.m_charbuffer[-1]) && v19 )
        (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
      if ( v20 )
      {
        JoinArgs((PStringBase<char> *)&argv, argc, argv);
        PStringBase<char>::PStringBase<char>(&v37, " ");
        PStringBase<char>::trim((PStringBase<char> *)&argv, 1, 1, v37);
        v21 = (unsigned int)*(argv - 1);
        if ( v21 != 1 )
        {
          if ( v21 > 0xC0 )
          {
            v22 = (const unsigned __int16 *)PStringBase<char>::substring(
                                              (PStringBase<char> *)&argv,
                                              (PStringBase<char> *)&argc,
                                              0,
                                              0xBFu);
            PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&argv, v22);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          }
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "\n");
          v23 = PStringBase<char>::find_substring((PStringBase<char> *)&argv, (PStringBase<char> *)&argc) == -1;
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          if ( v23 )
          {
            PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "\n");
            PStringBase<char>::operator+=((PStringBase<char> *)&argv, (PStringBase<char> *)&argc);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          }
        }
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
        CM_Communication::Event_SetAFKMessage(v24);
        v25 = argc;
        if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v25 )
        {
          v26 = *(_DWORD *)v25;
          v37.m_charbuffer = (PSRefBufferCharData<char> *)1;
          (*(void (__thiscall **)(int, signed int))v26)(v25, 1);
        }
        if ( *(argv - 1) == (char *)1 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&argc,
            L"New AFK message set: I am currently away from the keyboard.");
          ClientSystem::AddTextToScroll(
            (ClientSystem *)&v3->vfptr,
            (PStringBase<unsigned short> *)&argc,
            0,
            1,
            v3->m_idCurrentCommandSource);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          v27 = argv - 5;
          v37.m_charbuffer = (PSRefBufferCharData<char> *)(argv - 4);
        }
        else
        {
          v37.m_charbuffer = (PSRefBufferCharData<char> *)v3->m_idCurrentCommandSource;
          v28 = operator+((PStringBase<char> *)&argc, "New AFK message set: ", (PStringBase<char> *)&argv);
          ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v28, 0, 1, (unsigned int)v37.m_charbuffer);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
          v27 = argv - 5;
          v37.m_charbuffer = (PSRefBufferCharData<char> *)(argv - 4);
        }
      }
      else
      {
        argv = (char **)PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        ClientCommunicationSystem::HelpAFK(Detail_HelpType, "@afk", (PStringBase<char> *)&argv);
        v37.m_charbuffer = (PSRefBufferCharData<char> *)v3->m_idCurrentCommandSource;
        v29 = PStringBase<char>::to_wpstring((PStringBase<char> *)&argv, (PStringBase<unsigned short> *)&argc, 0);
        ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v29, 0, 1, (unsigned int)v37.m_charbuffer);
        v30 = argc - 20;
        if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v30 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
        v27 = argv - 5;
        v37.m_charbuffer = (PSRefBufferCharData<char> *)(argv - 4);
      }
      if ( !InterlockedDecrement((volatile LONG *)v37.m_charbuffer) && v27 )
      {
        v31 = *v27;
        v37.m_charbuffer = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char **, signed int))v31)(v27, 1);
      }
    }
  }
  v32 = &command.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v32 )
  {
    v33 = *(_DWORD *)v32;
    v37.m_charbuffer = (PSRefBufferCharData<char> *)1;
    (*(void (__thiscall **)(char *, signed int))v33)(v32, 1);
  }
  return 1;
}

//----- (0057B8B0) --------------------------------------------------------  // acclient.c:421285
char __thiscall ClientCommunicationSystem::HelpDeathGroup(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem *v4; // ebp@1
  ClientCommunicationSystem::HelpType v5; // ecx@2
  int v6; // eax@2
  int v7; // esi@4
  ClientCommunicationSystem::HelpType v9; // ecx@7
  int v10; // eax@7
  PStringBase<char> *v11; // edi@7
  int v12; // esi@9
  PStringBase<char> *v13; // eax@12
  PSRefBufferCharData<char> *v14; // ecx@12
  int v15; // esi@14
  PStringBase<char> *v16; // eax@17
  PSRefBufferCharData<char> *v17; // ecx@17
  int v18; // esi@19
  PStringBase<char> *v19; // eax@22
  PSRefBufferCharData<char> *v20; // ecx@22
  int v21; // esi@24

  v4 = this;
  if ( type )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@permit - Commands to give or revoke permission for others to loot your corpse.\n");
    v9 = type;
    v10 = *(_DWORD *)(type - 4);
    v11 = msg;
    if ( v10 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v10 - 1);
      v9 = type;
    }
    v12 = v9 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v9 - 20 + 4)) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@consent - Commands to help you manage the corpse-looting permissions that others give you.\n");
    v13 = msg;
    v14 = msg[-1].m_charbuffer;
    if ( v14 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v11, (const char *)msg, (unsigned int)&v14[-1].m_data[15]);
      v13 = msg;
    }
    v15 = (int)&v13[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v13[-4]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@corpse - Displays the location of your last outdoor death.\n");
    v16 = msg;
    v17 = msg[-1].m_charbuffer;
    if ( v17 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v11, (const char *)msg, (unsigned int)&v17[-1].m_data[15]);
      v16 = msg;
    }
    v18 = (int)&v16[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v16[-4]) && v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@die - Kills your character and leaves a corpse, returning you to your lifestone.\n");
    v19 = msg;
    v20 = msg[-1].m_charbuffer;
    if ( v20 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v11, (const char *)msg, (unsigned int)&v20[-1].m_data[15]);
      v19 = msg;
    }
    v21 = (int)&v19[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v19[-4]) && v21 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    ClientCommunicationSystem::HelpLifestone(v4, 0, "@lifestone", v11);
    ClientCommunicationSystem::HelpMarketplace(v4, 0, "@marketplace", v11);
    ClientCommunicationSystem::HelpPKArena(v4, 0, "@pkarena", v11);
    ClientCommunicationSystem::HelpPKLArena(v4, 0, "@pklarena", v11);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help death - Commands for making, finding, and looting corpses.\n");
    v5 = type;
    v6 = *(_DWORD *)(type - 4);
    if ( v6 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v6 - 1);
      v5 = type;
    }
    v7 = v5 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v5 - 20 + 4)) && v7 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      return 1;
    }
  }
  return 1;
}

//----- (0057BA70) --------------------------------------------------------  // acclient.c:421389
void __cdecl ClientCommunicationSystem::DieDialogCallback(PropertyCollection *i_rcResults)
{
  unsigned int v1; // edx@1
  HashTableData<unsigned long,BaseProperty> **v2; // eax@1
  HashTableData<unsigned long,BaseProperty> *v3; // eax@1
  BasePropertyValue *v4; // ecx@6
  BasePropertyDesc *v5; // ecx@11
  unsigned int v6; // edx@11
  int v7; // edx@15
  bool confirm; // [sp+7h] [bp-9h]@1
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v2 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  confirm = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v3 = v2[v1];
  if ( v3 )
  {
    while ( v3->m_hashKey != 146 )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      BaseProperty::operator=(&p, (int)&v3->m_data);
      v4 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&confirm);
        v4 = p.m_pcPropertyValue;
      }
      if ( confirm )
      {
        CM_Character::Event_Suicide();
        v4 = p.m_pcPropertyValue;
      }
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v5 = p.m_pcPropertyDesc;
        v6 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v6;
        if ( !v6 )
          ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
        v4 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v4 )
      {
        v7 = v4->m_cRef - 1;
        v4->m_cRef = v7;
        if ( !v7 )
          ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (0057BB30) --------------------------------------------------------  // acclient.c:421451
char __thiscall ClientCommunicationSystem::DoEmoteList(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  unsigned int v7; // ST10_4@6
  PStringBase<unsigned short> *v8; // eax@6
  char *v9; // esi@6
  char *v10; // esi@9
  PStringBase<char> msg; // [sp+Ch] [bp-8h]@1
  PStringBase<char> v13; // [sp+10h] [bp-4h]@1

  msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::PStringBase<char>(
    &v13,
    "Standard Emotes:\nNote: These commands should be bound on either side by asterisks. (Example: *wave*)\nShakeFist; Beckon; BeSeeingYou; BlowKiss; BowDeep; ClapHands; Cry; Laugh; Nod; Point; Shrug; Wave; Akimbo; HeartyLaugh; Salute; TapFoot; WaveHigh; WaveLow; Yawn; Stretch; Cringe; Kneel; Plead; Shiver; Shoo; Slouch; Spit; Surrender; Woah; Winded; YMCA; Eat; Drink; Teapot; Pray; Mock; Cheer; Helper; Warm Hands; Scratch Head; Shake Head\n\n");
  v4 = v13.m_charbuffer;
  v5 = *(_DWORD *)&v13.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(&msg, v13.m_charbuffer->m_data, v5 - 1);
    v4 = v13.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = v3->m_idCurrentCommandSource;
  v8 = PStringBase<char>::to_wpstring(&msg, (PStringBase<unsigned short> *)&v13, 0);
  ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v8, 0, 1, v7);
  v9 = &v13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v13.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  v10 = &msg.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  return 1;
}

//----- (0057BC00) --------------------------------------------------------  // acclient.c:421493
char __thiscall ClientCommunicationSystem::DoFriends(ClientCommunicationSystem *this, int argc, char **argv)
{
  PSRefBufferCharData<char> *v3; // edi@1
  int v4; // eax@1
  char *v5; // ebp@1
  bool v6; // bl@1
  int v7; // edi@5
  char v8; // bl@5
  char result; // al@7
  int v10; // eax@8
  char *v11; // ebp@8
  bool v12; // bl@8
  char v13; // al@12
  int v14; // eax@13
  char **v15; // ebp@13
  bool v16; // bl@13
  int v17; // edi@18
  int v18; // eax@22
  char **v19; // ebp@22
  bool v20; // bl@22
  bool v21; // bl@26
  char v22; // bl@28
  PStringBase<char> command; // [sp+10h] [bp-Ch]@1
  ClientCommunicationSystem *v24; // [sp+14h] [bp-8h]@1
  PStringBase<char> v25; // [sp+18h] [bp-4h]@1

  v24 = this;
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>(&v25, "add");
  v3 = command.m_charbuffer;
  v4 = __stricmp(command.m_charbuffer->m_data, v25.m_charbuffer->m_data);
  v5 = &v25.m_charbuffer[-2].m_data[12];
  v6 = v4 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v25.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  if ( v6 )
  {
    v7 = (int)&v3[-2].m_data[12];
    v8 = ClientCommunicationSystem::DoFriendsAdd(v24, argc, argv);
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      return v8;
    }
    return v8;
  }
  PStringBase<char>::PStringBase<char>(&v25, "remove");
  v10 = __stricmp(v3->m_data, v25.m_charbuffer->m_data);
  v11 = &v25.m_charbuffer[-2].m_data[12];
  v12 = v10 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v25.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  if ( v12 )
  {
    v13 = ClientCommunicationSystem::DoFriendsRemove(v24, argc, argv);
LABEL_18:
    v8 = v13;
    v17 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
    return v8;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "online");
  v14 = __stricmp(v3->m_data, (const char *)argv);
  v15 = argv - 5;
  v16 = v14 == 0;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v15 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v15)(v15, 1);
  if ( v16 )
  {
    v13 = CM_Social::SendNotice_ChatCommand_DisplayFriends(1);
    goto LABEL_18;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argv, "old");
  v18 = __stricmp(v3->m_data, (const char *)argv);
  v19 = argv - 5;
  v20 = v18 == 0;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v19 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v19)(v19, 1);
  if ( v20 )
  {
    argv = (char **)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v21 = Proto_UI::SendFriendsCommand(0, (PStringBase<char> *)&argv) != 0;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
    result = v21;
  }
  else if ( *(_DWORD *)&v3[-1].m_data[12] == 1 )
  {
    v22 = CM_Social::SendNotice_ChatCommand_DisplayFriends(0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
    result = v22;
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      L"Invalid friends command specified.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v24->vfptr,
      (PStringBase<unsigned short> *)&argv,
      0x1Au,
      1,
      v24->m_idCurrentCommandSource);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
    result = 1;
  }
  return result;
}

//----- (0057BE90) --------------------------------------------------------  // acclient.c:421606
void __cdecl ClientCommunicationSystem::HouseAbandonDialogCallback_Second(PropertyCollection *i_rcResults)
{
  unsigned int v1; // edx@1
  HashTableData<unsigned long,BaseProperty> **v2; // eax@1
  HashTableData<unsigned long,BaseProperty> *v3; // eax@1
  BasePropertyValue *v4; // ecx@6
  BasePropertyDesc *v5; // ecx@11
  unsigned int v6; // edx@11
  int v7; // edx@15
  bool confirm; // [sp+7h] [bp-9h]@1
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v2 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  confirm = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v3 = v2[v1];
  if ( v3 )
  {
    while ( v3->m_hashKey != 146 )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      BaseProperty::operator=(&p, (int)&v3->m_data);
      v4 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&confirm);
        v4 = p.m_pcPropertyValue;
      }
      if ( confirm )
      {
        CM_House::Event_AbandonHouse();
        v4 = p.m_pcPropertyValue;
      }
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v5 = p.m_pcPropertyDesc;
        v6 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v6;
        if ( !v6 )
          ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
        v4 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v4 )
      {
        v7 = v4->m_cRef - 1;
        v4->m_cRef = v7;
        if ( !v7 )
          ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (0057BF50) --------------------------------------------------------  // acclient.c:421668
bool __thiscall ClientCommunicationSystem::DoSquelch(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // edi@1
  ClientCommunicationSystem *v4; // esi@1
  bool result; // al@2
  char *v6; // esi@4
  LONG v7; // eax@4
  int v8; // esi@6
  LONG (__stdcall *v9)(volatile LONG *); // edi@6
  int v10; // esi@9
  PStringBase<char> name; // [sp+4h] [bp-4h]@1

  name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = argc;
  v4 = this;
  if ( argc )
  {
    name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( ClientCommunicationSystem::ProcessSquelchArgs(v4, v3, argv, 1, (bool *)&argc, &name, (unsigned int *)&argv) )
    {
      if ( (_BYTE)argc )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(
          (AC1Legacy::PStringBase<char> *)&argc,
          name.m_charbuffer->m_data);
        CM_Communication::Event_ModifyAccountSquelch(1, (AC1Legacy::PStringBase<char> *)&argc);
        v8 = argc;
        v9 = InterlockedDecrement;
        if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      else
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(
          (AC1Legacy::PStringBase<char> *)&argc,
          name.m_charbuffer->m_data);
        CM_Communication::Event_ModifyCharacterSquelch(1, 0, (AC1Legacy::PStringBase<char> *)&argc, (unsigned int)argv);
        v10 = argc;
        v9 = InterlockedDecrement;
        if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      }
      v6 = &name.m_charbuffer[-2].m_data[12];
      v7 = v9((volatile LONG *)&name.m_charbuffer[-1]);
    }
    else
    {
      v6 = &name.m_charbuffer[-2].m_data[12];
      v7 = InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]);
    }
    if ( !v7 )
    {
      if ( v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    }
    result = 1;
  }
  else
  {
    result = gmCCommunicationSystem::DoSquelchQuery() != 0;
  }
  return result;
}

//----- (0057C070) --------------------------------------------------------  // acclient.c:421734
bool __thiscall ClientCommunicationSystem::DoUnSquelch(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // edi@1
  ClientCommunicationSystem *v4; // esi@1
  bool result; // al@2
  char *v6; // esi@4
  LONG v7; // eax@4
  int v8; // esi@6
  LONG (__stdcall *v9)(volatile LONG *); // edi@6
  int v10; // esi@9
  PStringBase<char> name; // [sp+4h] [bp-4h]@1

  name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = argc;
  v4 = this;
  if ( argc )
  {
    name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( ClientCommunicationSystem::ProcessSquelchArgs(v4, v3, argv, 1, (bool *)&argc, &name, (unsigned int *)&argv) )
    {
      if ( (_BYTE)argc )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(
          (AC1Legacy::PStringBase<char> *)&argc,
          name.m_charbuffer->m_data);
        CM_Communication::Event_ModifyAccountSquelch(0, (AC1Legacy::PStringBase<char> *)&argc);
        v8 = argc;
        v9 = InterlockedDecrement;
        if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      else
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(
          (AC1Legacy::PStringBase<char> *)&argc,
          name.m_charbuffer->m_data);
        CM_Communication::Event_ModifyCharacterSquelch(0, 0, (AC1Legacy::PStringBase<char> *)&argc, (unsigned int)argv);
        v10 = argc;
        v9 = InterlockedDecrement;
        if ( !InterlockedDecrement((volatile LONG *)(argc + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      }
      v6 = &name.m_charbuffer[-2].m_data[12];
      v7 = v9((volatile LONG *)&name.m_charbuffer[-1]);
    }
    else
    {
      v6 = &name.m_charbuffer[-2].m_data[12];
      v7 = InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]);
    }
    if ( !v7 )
    {
      if ( v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    }
    result = 1;
  }
  else
  {
    result = gmCCommunicationSystem::DoSquelchQuery() != 0;
  }
  return result;
}

//----- (0057C190) --------------------------------------------------------  // acclient.c:421800
char __thiscall ClientCommunicationSystem::HelpSquelch(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem *v4; // ebx@1
  ClientCommunicationSystem::HelpType v5; // esi@2
  int v6; // eax@2
  int v7; // esi@4
  LONG v8; // eax@4
  ClientCommunicationSystem::HelpType v9; // ecx@6
  int v10; // eax@6
  ClientCommunicationSystem::HelpType v11; // ecx@9
  int v12; // eax@9
  PStringBase<char> *v13; // esi@9
  int v14; // edi@11
  PStringBase<char> *v15; // ecx@14
  PSRefBufferCharData<char> *v16; // eax@14

  v4 = this;
  if ( type )
  {
    if ( type == 1 )
    {
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "@squelch - Squelches a character or account.\n@unsquelch - Unsquelches a squelched character or account.\n@messagetypes - Lists all types of messages that can be squelched or filtered.\n");
      v9 = type;
      v10 = *(_DWORD *)(type - 4);
      if ( v10 != 1 )
      {
        PStringBase<char>::append_n_chars(msg, (const char *)type, v10 - 1);
        v9 = type;
      }
      v7 = v9 - 20;
      v8 = InterlockedDecrement((volatile LONG *)(v9 - 20 + 4));
    }
    else
    {
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&type,
        "The @squelch commands let you block out messages from specific characters or players. The @unsquelch commands lets squelched messages reach you again. Use the options on these commands to squelch all message types or just some types of messages; one character or an entire account. You may have up to 32 players squelched at once. Note that NPCs cannot be permanently squelched.\n\n");
      v11 = type;
      v12 = *(_DWORD *)(type - 4);
      v13 = msg;
      if ( v12 != 1 )
      {
        PStringBase<char>::append_n_chars(msg, (const char *)type, v12 - 1);
        v11 = type;
      }
      v14 = v11 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v11 - 20 + 4)) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      ClientCommunicationSystem::HelpAdvancedSquelch(v4, Detail_HelpType, &name, v13);
      ClientCommunicationSystem::HelpAdvancedUnSquelch(v4, Detail_HelpType, &name, v13);
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&msg,
        "Type @messagetypes for a complete list of message types.\n");
      v15 = msg;
      v16 = msg[-1].m_charbuffer;
      if ( v16 != (PSRefBufferCharData<char> *)1 )
      {
        PStringBase<char>::append_n_chars(v13, (const char *)msg, (unsigned int)&v16[-1].m_data[15]);
        v15 = msg;
      }
      v7 = (int)&v15[-5];
      v8 = InterlockedDecrement((volatile LONG *)&v15[-4]);
    }
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help squelch - Commands that let you block out messages from other players.\n");
    v5 = type;
    v6 = *(_DWORD *)(type - 4);
    if ( v6 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v6 - 1);
      v5 = type;
    }
    v7 = v5 - 20;
    v8 = InterlockedDecrement((volatile LONG *)(v7 + 4));
  }
  if ( !v8 && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return 1;
}

//----- (0057C2D0) --------------------------------------------------------  // acclient.c:421887
char __thiscall ClientCommunicationSystem::PerformGlobalSquelchMod(ClientCommunicationSystem *this, int argc, char **argv, bool add)
{
  ClientCommunicationSystem *v4; // esi@1
  bool v5; // bl@2
  char *v7; // esi@9
  LONG v8; // eax@9
  int v9; // esi@14
  PStringBase<char> name; // [sp+4h] [bp-4h]@1

  name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( !argc )
  {
    v5 = gmCCommunicationSystem::DoGlobalSquelchQuery() != 0;
    if ( !InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1])
      && name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&name.m_charbuffer[-2].m_data[12])(&name.m_charbuffer[-2].m_data[12], 1);
    return v5;
  }
  if ( **argv != 45 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&add,
      L"You must specify a valid message type prefixed by a dash.");
LABEL_14:
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v4->vfptr,
      (PStringBase<unsigned short> *)&add,
      0x1Au,
      1,
      v4->m_idCurrentCommandSource);
    v9 = add - 20;
    if ( !InterlockedDecrement((volatile LONG *)(add - 20 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v7 = &name.m_charbuffer[-2].m_data[12];
    v8 = InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]);
    goto LABEL_18;
  }
  if ( ClientCommunicationSystem::ProcessSquelchArgs(v4, argc, argv, 0, (bool *)&argc, &name, (unsigned int *)&argv) )
  {
    if ( (_BYTE)argc != 1 && *(_DWORD *)&name.m_charbuffer[-1].m_data[12] == 1 )
    {
      CM_Communication::Event_ModifyGlobalSquelch(add, (unsigned int)argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&name);
      return 1;
    }
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&add,
      L"Incorrect usage, use @help for proper arguements.");
    goto LABEL_14;
  }
  v7 = &name.m_charbuffer[-2].m_data[12];
  v8 = InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]);
LABEL_18:
  if ( !v8 && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return 1;
}
// 7E0980: using guessed type wchar_t aYouMustSpeci_4[58];

//----- (0057C410) --------------------------------------------------------  // acclient.c:421949
char __thiscall ClientCommunicationSystem::HelpStatusGroup(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem *v4; // edi@1
  ClientCommunicationSystem::HelpType v5; // ecx@2
  int v6; // eax@2
  int v7; // esi@4
  PStringBase<char> *v9; // esi@7
  PStringBase<char> *v10; // ecx@7
  PSRefBufferCharData<char> *v11; // eax@7
  int v12; // ebx@9
  PStringBase<char> *v13; // ecx@12
  PSRefBufferCharData<char> *v14; // eax@12
  int v15; // ebx@14
  PStringBase<char> *v16; // ebx@17
  PSRefBufferCharData<char> *v17; // eax@17
  int v18; // ebx@19

  v4 = this;
  if ( type )
  {
    v9 = msg;
    ClientCommunicationSystem::HelpAge(this, 0, "@age", msg);
    ClientCommunicationSystem::HelpBirth(v4, 0, "@birth", v9);
    ClientCommunicationSystem::HelpDay(v4, 0, "@day", v9);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@endurance - Explains how endurance affects your character.\n");
    v10 = msg;
    v11 = msg[-1].m_charbuffer;
    if ( v11 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v11[-1].m_data[15]);
      v10 = msg;
    }
    v12 = (int)&v10[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-4]) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    ClientCommunicationSystem::HelpFrameRate(v4, 0, "@framerate", v9);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, "@loc - Displays your current position.\n");
    v13 = msg;
    v14 = msg[-1].m_charbuffer;
    if ( v14 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v14[-1].m_data[15]);
      v13 = msg;
    }
    v15 = (int)&v13[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v13[-4]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@pklite - Sets your status to Player Killer Lite. Type @help pklite for more details.\n");
    v16 = msg;
    v17 = msg[-1].m_charbuffer;
    if ( v17 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v17[-1].m_data[15]);
      v16 = msg;
    }
    v18 = (int)&v16[-5];
    if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) && v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
    ClientCommunicationSystem::HelpVersion(v4, 0, "@version", v9);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help status - Commands that display useful information.\n");
    v5 = type;
    v6 = *(_DWORD *)(type - 4);
    if ( v6 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v6 - 1);
      v5 = type;
    }
    v7 = v5 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v5 - 20 + 4)) && v7 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      return 1;
    }
  }
  return 1;
}

//----- (0057C5A0) --------------------------------------------------------  // acclient.c:422036
bool __stdcall ClientCommunicationSystem::DoAge(int argc, char **argv)
{
  unsigned int v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@3

  v3 = 0;
  if ( ClientCommunicationSystem::PlayerIsPSR() )
  {
    v3 = ACCWeenieObject::selectedID;
    if ( ACCWeenieObject::selectedID )
    {
      v4 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( !v4 )
        return 0;
      if ( !((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[4].__vecDelDtor)(v4) )
        v3 = 0;
    }
  }
  return CM_Character::Event_QueryAge(v3);
}

//----- (0057C5F0) --------------------------------------------------------  // acclient.c:422058
char __thiscall ClientCommunicationSystem::DoEndurance(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  PSRefBufferCharData<char> *v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@3
  unsigned int v7; // ST10_4@6
  PStringBase<unsigned short> *v8; // eax@6
  char *v9; // esi@6
  char *v10; // esi@9
  PStringBase<char> msg; // [sp+Ch] [bp-8h]@1
  PStringBase<char> v13; // [sp+10h] [bp-4h]@1

  msg.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::PStringBase<char>(
    &v13,
    "The endurance attribute has a number of abilities tied to it.\nFirst, some combination of strength and endurance (with endurance being more important) now allows one to regenerate hit points at a faster rate the higher one's endurance is.  This bonus is in addition to any regeneration spells one may have placed upon themselves.  This endurance regeneration bonus caps at around 110%.\nSecond, the higher a player's Endurance, the less stamina one uses while attacking.  This benefit is tied to Endurance only, and it caps out at around 50% less stamina used per attack.  The minimum stamina used per attack remains one.\nThird, the higher a player's Endurance, the more likely they are not to use a point of stamina to successfully evade a missile or melee attack.  A player is required to have Melee Defense for melee attacks or Missile Defense for missile attacks trained or specialized in order for this specific ability to work.  This benefit is tied to Endurance only, and it caps out at around a 75% chance to av);
  v4 = v13.m_charbuffer;
  v5 = *(_DWORD *)&v13.m_charbuffer[-1].m_data[12];
  if ( v5 != 1 )
  {
    PStringBase<char>::append_n_chars(&msg, v13.m_charbuffer->m_data, v5 - 1);
    v4 = v13.m_charbuffer;
  }
  v6 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = v3->m_idCurrentCommandSource;
  v8 = PStringBase<char>::to_wpstring(&msg, (PStringBase<unsigned short> *)&v13, 0);
  ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v8, 0, 1, v7);
  v9 = &v13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v13.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  v10 = &msg.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  return 1;
}

//----- (0057C6C0) --------------------------------------------------------  // acclient.c:422100
char __thiscall ClientCommunicationSystem::HelpTextGroup(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem *v4; // ebp@1
  ClientCommunicationSystem::HelpType v5; // ecx@2
  int v6; // eax@2
  int v7; // esi@4
  PStringBase<char> *v9; // edi@7
  PStringBase<char> *v10; // ecx@7
  PSRefBufferCharData<char> *v11; // eax@7
  int v12; // esi@9
  PStringBase<char> *v13; // eax@12
  PSRefBufferCharData<char> *v14; // ecx@12
  int v15; // esi@14
  PStringBase<char> *v16; // eax@17
  PSRefBufferCharData<char> *v17; // ecx@17
  int v18; // esi@19
  PStringBase<char> *v19; // eax@22
  PSRefBufferCharData<char> *v20; // ecx@22
  int v21; // esi@24

  v4 = this;
  if ( type )
  {
    v9 = msg;
    ClientCommunicationSystem::HelpClear(this, 0, "@clear", msg);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@filter - Commands to filter out incoming messages.\n");
    v10 = msg;
    v11 = msg[-1].m_charbuffer;
    if ( v11 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v11[-1].m_data[15]);
      v10 = msg;
    }
    v12 = (int)&v10[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-4]) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@unfilter - Commands to remove filters from incoming messages.\n");
    v13 = msg;
    v14 = msg[-1].m_charbuffer;
    if ( v14 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v14[-1].m_data[15]);
      v13 = msg;
    }
    v15 = (int)&v13[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v13[-4]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@loadfile - Reads in the given text file and executes each line in the chat entry field.\n");
    v16 = msg;
    v17 = msg[-1].m_charbuffer;
    if ( v17 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v17[-1].m_data[15]);
      v16 = msg;
    }
    v18 = (int)&v16[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v16[-4]) && v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, "@log - Commands to echo chat text to a logfile.\n");
    v19 = msg;
    v20 = msg[-1].m_charbuffer;
    if ( v20 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v20[-1].m_data[15]);
      v19 = msg;
    }
    v21 = (int)&v19[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v19[-4]) && v21 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    ClientCommunicationSystem::HelpTitle(v4, 0, "@title", v9);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help text - Commands that help you manage your text window.\n");
    v5 = type;
    v6 = *(_DWORD *)(type - 4);
    if ( v6 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v6 - 1);
      v5 = type;
    }
    v7 = v5 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v5 - 20 + 4)) && v7 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      return 1;
    }
  }
  return 1;
}

//----- (0057C860) --------------------------------------------------------  // acclient.c:422200
char __thiscall ClientCommunicationSystem::DoFilter(ClientCommunicationSystem *this, int argc, char **argv)
{
  return ClientCommunicationSystem::PerformGlobalSquelchMod(this, argc, argv, 1);
}

//----- (0057C880) --------------------------------------------------------  // acclient.c:422206
char __thiscall ClientCommunicationSystem::DoUnFilter(ClientCommunicationSystem *this, int argc, char **argv)
{
  return ClientCommunicationSystem::PerformGlobalSquelchMod(this, argc, argv, 0);
}

//----- (0057C8A0) --------------------------------------------------------  // acclient.c:422212
BOOL __thiscall ClientCommunicationSystem::StartCopyOutputToFile(ClientCommunicationSystem *this, PStringBase<char> *file)
{
  ClientCommunicationSystem *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ebx@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  ClientCommunicationSystem::CloseLogFile(this);
  ClientSystem::s_pLogFile = _fopen(file->m_charbuffer->m_data, "a+");
  v3 = v2->m_strLogName.m_charbuffer;
  if ( v3 != file->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = file->m_charbuffer;
    v2->m_strLogName.m_charbuffer = file->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
  return ClientSystem::s_pLogFile != 0;
}

//----- (0057C920) --------------------------------------------------------  // acclient.c:422236
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1>Vtbl *)&IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (ClientCommunicationSystem::CmdHashData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (ClientCommunicationSystem::CmdHashData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7D00DC: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vftable)(void *, char);

//----- (0057C9B0) --------------------------------------------------------  // acclient.c:422269
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this, ClientCommunicationSystem::CmdHashData *data)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v2; // esi@1
  unsigned int v3; // ebx@3
  unsigned int v4; // edx@3
  ClientCommunicationSystem::CmdHashData **v5; // eax@3
  int v6; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::grow(this);
  v3 = v2->m_numBuckets;
  v4 = CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(&data->m_hashKey) % v3;
  v5 = v2->m_buckets;
  data->m_hashNext = v5[v4];
  v5[v4] = data;
  v6 = (int)&v5[v4];
  if ( (ClientCommunicationSystem::CmdHashData **)v6 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = (ClientCommunicationSystem::CmdHashData **)v6;
  ++v2->m_numElements;
}

//----- (0057CA00) --------------------------------------------------------  // acclient.c:422292
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::resize_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v3; // esi@1
  char result; // al@2
  ClientCommunicationSystem::CmdHashData *v5; // edi@3
  int v6; // ecx@4
  ClientCommunicationSystem::CmdHashData **v7; // eax@5
  int v8; // eax@6
  ClientCommunicationSystem::CmdHashData **v9; // ebx@7
  ClientCommunicationSystem::CmdHashData *v10; // ecx@7
  ClientCommunicationSystem::CmdHashData *v11; // eax@9
  ClientCommunicationSystem::CmdHashData *v12; // edx@10
  ClientCommunicationSystem::CmdHashData *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  unsigned int v16; // ebx@23
  unsigned int v17; // edx@23
  ClientCommunicationSystem::CmdHashData **v18; // eax@23
  int v19; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (ClientCommunicationSystem::CmdHashData **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (ClientCommunicationSystem::CmdHashData **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (ClientCommunicationSystem::CmdHashData **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v3->m_numBuckets;
        v17 = CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(&v5->m_hashKey) % v16;
        v18 = v3->m_buckets;
        v5->m_hashNext = v18[v17];
        v18[v17] = v5;
        v19 = (int)&v18[v17];
        if ( (ClientCommunicationSystem::CmdHashData **)v19 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (ClientCommunicationSystem::CmdHashData **)v19;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0057CB40) --------------------------------------------------------  // acclient.c:422412
void __thiscall ClientCommunicationSystem::OnQualityChanged(ClientCommunicationSystem *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  ClientCommunicationSystem *v4; // esi@1
  ClientSystem *v5; // ecx@2

  v4 = this;
  if ( CBaseQualities::InqBool((CBaseQualities *)&cwobj[4].vfptr[2].GetNoticeHandlers, 0x6Eu, (int *)&cwobj) )
  {
    v5 = (ClientSystem *)&v4[-1].m_ChatMessageCount;
    if ( cwobj )
      ClientSystem::AddTextToScroll(v5, "You are now set to away-from-keyboard.\n", 0, 1, 0);
    else
      ClientSystem::AddTextToScroll(v5, "You are no longer set to away-from-keyboard.\n", 0, 1, 0);
  }
}

//----- (0057CB90) --------------------------------------------------------  // acclient.c:422429
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__WeenieErrorWithString(ClientCommunicationSystem *this, unsigned int etype, AC1Legacy::PStringBase<char> *user_data)
{
  ClientCommunicationSystem *v3; // esi@1
  AC1Legacy::PStringBase<char> *v4; // esi@1

  v3 = this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&user_data,
    0,
    user_data->m_buffer->m_data);
  ClientCommunicationSystem::HandleFailureEvent(v3, etype, (PStringBase<unsigned short> *)&user_data);
  v4 = user_data - 5;
  if ( !InterlockedDecrement((volatile LONG *)&user_data[-4]) && v4 )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v4->m_buffer->vfptr)(v4, 1);
  return 0;
}

//----- (0057CBE0) --------------------------------------------------------  // acclient.c:422447
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__HearEmote(ClientCommunicationSystem *this, unsigned int sender, AC1Legacy::PStringBase<char> *name, AC1Legacy::PStringBase<char> *msg)
{
  int v4; // eax@2
  unsigned int v5; // ebx@2
  AC1Legacy::PSRefBuffer<char> *v6; // edi@2
  const char *v7; // esi@2
  char *v8; // eax@2
  int v9; // eax@3
  bool v10; // bl@5
  int v11; // ecx@5
  AC1Legacy::PSRefBuffer<char> *v12; // edi@10
  char *v13; // eax@10
  unsigned int v14; // eax@11
  bool v15; // bl@13
  int v16; // ecx@13
  PlayerDesc *v17; // ebp@17
  int v18; // ebx@21
  InterfaceSystem *v19; // eax@23
  int v20; // esi@23
  int v21; // edi@25
  AC1Legacy::PStringBase<unsigned short> *v22; // eax@32
  AC1Legacy::PStringBase<char> *v23; // esi@32
  AC1Legacy::PStringBase<unsigned short> *v24; // eax@33
  AC1Legacy::PSRefBuffer<char> *v25; // edx@36
  AC1Legacy::PSRefBuffer<char> *v26; // ebx@37
  unsigned int v27; // ebp@37
  AC1Legacy::PStringBase<char> *v28; // edi@38
  AC1Legacy::PSRefBuffer<char> *v29; // eax@38
  int v30; // eax@39
  AC1Legacy::PStringBase<char> *v31; // esi@42
  AC1Legacy::PSRefBuffer<char> *v32; // eax@42
  LONG (__stdcall *v33)(volatile LONG *); // ebx@45
  AC1Legacy::PSRefBuffer<char> *v34; // eax@46
  AC1Legacy::PStringBase<char> *v35; // esi@48
  AC1Legacy::PSRefBuffer<char> *v36; // eax@48
  AC1Legacy::PSRefBuffer<char> *v37; // edx@52
  AC1Legacy::PStringBase<char> *v38; // esi@53
  AC1Legacy::PSRefBuffer<char> *v39; // eax@53
  AC1Legacy::PSRefBuffer<char> *v40; // edx@57
  AC1Legacy::PStringBase<char> *v41; // edi@59
  AC1Legacy::PStringBase<char> *v42; // esi@59
  AC1Legacy::PSRefBuffer<char> *v43; // eax@61
  AC1Legacy::PSRefBuffer<char> *v44; // edx@66
  ReferenceCountTemplate<268435456,0>Vtbl *v45; // edx@69
  int v46; // edx@72
  int v48; // [sp-8h] [bp-38h]@23
  int v49; // [sp-4h] [bp-34h]@2
  AC1Legacy::PStringBase<char> modified_msg; // [sp+10h] [bp-20h]@2
  InterfacePtr<PlayerDesc> spPD; // [sp+14h] [bp-1Ch]@2
  int no_scramble; // [sp+1Ch] [bp-14h]@2
  int no_olthoi_talk; // [sp+20h] [bp-10h]@23
  AC1Legacy::PStringBase<char> v54; // [sp+24h] [bp-Ch]@2
  int player_is_Olthoi; // [sp+28h] [bp-8h]@2
  ClientSystem *v56; // [sp+2Ch] [bp-4h]@1

  v56 = (ClientSystem *)this;
  if ( !gmCCommunicationSystem::CanHear(sender, 0xCu) )
    return 0;
  spPD.m_pInterface = 0;
  no_scramble = 0;
  v4 = CPlayerSystem::IsOlthoi();
  v5 = (unsigned int)name->m_buffer;
  v49 = (int)&name->m_buffer->m_cRef;
  player_is_Olthoi = v4;
  sender = v5;
  InterlockedIncrement((volatile LONG *)v49);
  modified_msg.m_buffer = msg->m_buffer;
  InterlockedIncrement((volatile LONG *)&modified_msg.m_buffer->m_cRef);
  name = (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "^");
  v6 = v54.m_buffer;
  v7 = (const char *)(v5 + 20);
  v8 = _strstr((const char *)(v5 + 20), v54.m_buffer->m_data);
  if ( v8 )
    v9 = (int)&v8[-v5 - 20];
  else
    v9 = -1;
  v10 = v9 >= 0;
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  if ( v10 )
  {
    v49 = v11;
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v49, "^");
    AC1Legacy::PStringBase<char>::trim((AC1Legacy::PStringBase<char> *)&sender, 0, 1, (AC1Legacy::PStringBase<char>)v49);
    no_scramble = 1;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "&");
    v12 = v54.m_buffer;
    v13 = _strstr(v7, v54.m_buffer->m_data);
    if ( v13 )
      v14 = (unsigned int)&v13[-sender - 20];
    else
      v14 = -1;
    v15 = (v14 & 0x80000000) == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v12->m_cRef) && v12 )
      v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
    if ( v15 )
    {
      v49 = v16;
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&v49, "&");
      AC1Legacy::PStringBase<char>::trim(
        (AC1Legacy::PStringBase<char> *)&sender,
        0,
        1,
        (AC1Legacy::PStringBase<char>)v49);
      v17 = (PlayerDesc *)1;
      goto LABEL_19;
    }
  }
  v17 = spPD.m_pInterface;
LABEL_19:
  v18 = v17 != (PlayerDesc *)player_is_Olthoi && !no_scramble;
  v49 = (int)&no_scramble;
  no_olthoi_talk = 0;
  no_scramble = 0;
  v19 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v19, (TResult *)&player_is_Olthoi, &PlayerDesc_ClassType_30, (Interface **)v49);
  v20 = no_scramble;
  v48 = no_scramble;
  v49 = 0;
  spPD.m_pInterface = 0;
  spPD.m_trStatus.m_val = 0;
  if ( no_scramble )
    (*(void (__thiscall **)(int))(*(_DWORD *)no_scramble + 16))(no_scramble);
  v21 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v54, v48, v49);
  if ( v20 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 20))(v20);
  if ( (_DWORD)spPD.m_pInterface
    && v21 >= 0
    && (CBaseQualities::InqBool((CBaseQualities *)&spPD.m_pInterface->vfptr, 0x81u, &no_olthoi_talk), no_olthoi_talk)
    || !v18 )
  {
    AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&name, (const char *)(sender + 20));
    v28 = msg;
    v29 = msg->m_buffer;
    if ( msg->m_buffer->m_len )
      v30 = (int)v29->m_data;
    else
      v30 = (int)((char *)&v29->m_hash + 3);
    if ( *(_BYTE *)v30 == 39 )
    {
      v33 = InterlockedDecrement;
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&msg, " ");
      v31 = msg;
      v32 = msg[2].m_buffer;
      if ( v32 != (AC1Legacy::PSRefBuffer<char> *)1
        && msg != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(
          (AC1Legacy::PStringBase<char> *)&name,
          (const char *)&msg[5],
          (unsigned int)&v32[-1].m_data[3]);
      v33 = InterlockedDecrement;
      if ( !InterlockedDecrement((volatile LONG *)&v31[1]) )
      {
        v34 = v31->m_buffer;
        v49 = 1;
        ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v34->vfptr)(v31, 1);
      }
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&msg, v28->m_buffer->m_data);
    v35 = msg;
    v36 = msg[2].m_buffer;
    if ( v36 != (AC1Legacy::PSRefBuffer<char> *)1
      && msg != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(
        (AC1Legacy::PStringBase<char> *)&name,
        (const char *)&msg[5],
        (unsigned int)&v36[-1].m_data[3]);
    if ( !v33((volatile LONG *)&v35[1]) )
    {
      v37 = v35->m_buffer;
      v49 = 1;
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v37->vfptr)(v35, 1);
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&msg, "\n");
    v38 = msg;
    v39 = msg[2].m_buffer;
    if ( v39 != (AC1Legacy::PSRefBuffer<char> *)1
      && msg != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(
        (AC1Legacy::PStringBase<char> *)&name,
        (const char *)&msg[5],
        (unsigned int)&v39[-1].m_data[3]);
    if ( !v33((volatile LONG *)&v38[1]) )
    {
      v40 = v38->m_buffer;
      v49 = 1;
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v40->vfptr)(v38, 1);
    }
    v26 = modified_msg.m_buffer;
    v27 = sender;
  }
  else
  {
    if ( v17 )
    {
      v22 = (AC1Legacy::PStringBase<unsigned short> *)GetRandomOlthoiText((AC1Legacy::PStringBase<char> *)&msg);
      AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)&modified_msg, v22);
      v23 = msg;
      v49 = (int)&msg[1];
    }
    else
    {
      v24 = (AC1Legacy::PStringBase<unsigned short> *)GetRandomHumanText((AC1Legacy::PStringBase<char> *)&msg);
      AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)&modified_msg, v24);
      v23 = msg;
      v49 = (int)&msg[1];
    }
    if ( !InterlockedDecrement((volatile LONG *)v49) && v23 )
    {
      v25 = v23->m_buffer;
      v49 = 1;
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v25->vfptr)(v23, 1);
    }
    v26 = modified_msg.m_buffer;
    v27 = sender;
    v49 = (int)modified_msg.m_buffer->m_data;
    AC1Legacy::PStringBase<char>::sprintf(
      (AC1Legacy::PStringBase<char> *)&name,
      "%s %s\n",
      sender + 20,
      modified_msg.m_buffer->m_data);
  }
  v41 = name;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&msg,
    0,
    (const char *)&name[5]);
  ClientSystem::AddTextToScroll(v56, (PStringBase<unsigned short> *)&msg, 0xCu, 1, 0);
  v42 = msg - 5;
  if ( !InterlockedDecrement((volatile LONG *)&msg[-4]) && v42 )
  {
    v43 = v42->m_buffer;
    v49 = 1;
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v43->vfptr)(v42, 1);
  }
  if ( (_DWORD)spPD.m_pInterface )
    ((void (*)(void))spPD.m_pInterface->vfptr->Release)();
  if ( !InterlockedDecrement((volatile LONG *)&v41[1]) && v41 )
  {
    v44 = v41->m_buffer;
    v49 = 1;
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v44->vfptr)(v41, 1);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v26->m_cRef) && v26 )
  {
    v45 = v26->vfptr;
    v49 = 1;
    v45->__vecDelDtor(v26, 1);
  }
  if ( !InterlockedDecrement((volatile LONG *)(v27 + 4)) && v27 )
  {
    v46 = *(_DWORD *)v27;
    v49 = 1;
    (*(void (__thiscall **)(unsigned int, signed int))v46)(v27, 1);
  }
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0057D020) --------------------------------------------------------  // acclient.c:422715
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__HearSoulEmote(ClientCommunicationSystem *this, unsigned int sender, AC1Legacy::PStringBase<char> *name, AC1Legacy::PStringBase<char> *msg)
{
  ClientCommunicationSystem *v4; // ebp@1
  unsigned int v5; // eax@2
  unsigned int v6; // ebx@4
  unsigned int result; // eax@5
  unsigned int v8; // esi@6
  unsigned int v9; // eax@9
  AC1Legacy::PStringBase<char> *v10; // esi@9
  unsigned int v11; // ebx@9

  v4 = this;
  if ( SmartBox::smartbox )
    v5 = SmartBox::smartbox->player_id;
  else
    v5 = 0;
  v6 = sender;
  if ( sender == v5 )
  {
    result = 0;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&sender, "^");
    AC1Legacy::PStringBase<char>::operator+(
      name,
      (AC1Legacy::PStringBase<char> *)&name,
      (AC1Legacy::PStringBase<char> *)&sender);
    v8 = sender;
    if ( !InterlockedDecrement((volatile LONG *)(sender + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = ClientCommunicationSystem::Handle_Communication__HearEmote(v4, v6, (AC1Legacy::PStringBase<char> *)&name, msg);
    v10 = name;
    v11 = v9;
    if ( !InterlockedDecrement((volatile LONG *)&name[1]) )
    {
      if ( v10 )
        ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v10->m_buffer->vfptr)(v10, 1);
    }
    result = v11;
  }
  return result;
}

//----- (0057D0C0) --------------------------------------------------------  // acclient.c:422760
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__ChannelIndex(ClientCommunicationSystem *this, PackableList<AC1Legacy::PStringBase<char> > *index)
{
  ClientSystem *v2; // esi@1
  char *v3; // esi@1
  PackableList<AC1Legacy::PStringBase<char> > *v4; // edi@4
  PackableLLNode<AC1Legacy::PStringBase<char> > *v5; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v6; // eax@5
  unsigned int v7; // ecx@5
  AC1Legacy::PSRefBuffer<char> *v8; // esi@8
  unsigned int v9; // eax@8
  char *v10; // esi@13
  PStringBase<unsigned short> i_text; // [sp+10h] [bp-Ch]@1
  AC1Legacy::PStringBase<char> v13; // [sp+14h] [bp-8h]@8
  ClientSystem *v14; // [sp+18h] [bp-4h]@1

  v2 = (ClientSystem *)this;
  v14 = (ClientSystem *)this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, 0, "The following channels are available to you:\n");
  ClientSystem::AddTextToScroll(v2, &i_text, 0, 1, 0);
  v3 = (char *)&i_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = (PackableList<AC1Legacy::PStringBase<char> > *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v5 = index->head;
  index = (PackableList<AC1Legacy::PStringBase<char> > *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  for ( ; v5; v5 = v5->next )
  {
    AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&index, "   ");
    v6 = v5->data.m_buffer;
    v7 = v5->data.m_buffer->m_len;
    if ( v7 != 1 && v6 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars((AC1Legacy::PStringBase<char> *)&index, v6->m_data, v7 - 1);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v13, "\n");
    v8 = v13.m_buffer;
    v9 = v13.m_buffer->m_len;
    if ( v9 != 1 && v13.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars((AC1Legacy::PStringBase<char> *)&index, v13.m_buffer->m_data, v9 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    v4 = index;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, 0, (const char *)&index[1].head);
    ClientSystem::AddTextToScroll(v14, &i_text, 0, 1, 0);
    v10 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v4->head) && v4 )
    v4->vfptr->__vecDelDtor((PackObj *)v4, 1u);
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0057D230) --------------------------------------------------------  // acclient.c:422814
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__ChannelList(ClientCommunicationSystem *this, PackableList<AC1Legacy::PStringBase<char> > *list)
{
  ClientSystem *v2; // esi@1
  char *v3; // esi@1
  PackableList<AC1Legacy::PStringBase<char> > *v4; // edi@4
  PackableLLNode<AC1Legacy::PStringBase<char> > *v5; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v6; // eax@5
  unsigned int v7; // ecx@5
  AC1Legacy::PSRefBuffer<char> *v8; // esi@8
  unsigned int v9; // eax@8
  char *v10; // esi@13
  PStringBase<unsigned short> i_text; // [sp+10h] [bp-Ch]@1
  AC1Legacy::PStringBase<char> v13; // [sp+14h] [bp-8h]@8
  ClientSystem *v14; // [sp+18h] [bp-4h]@1

  v2 = (ClientSystem *)this;
  v14 = (ClientSystem *)this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    &i_text,
    0,
    "The following characters are currently listening on the channel:\n");
  ClientSystem::AddTextToScroll(v2, &i_text, 0, 1, 0);
  v3 = (char *)&i_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = (PackableList<AC1Legacy::PStringBase<char> > *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v5 = list->head;
  list = (PackableList<AC1Legacy::PStringBase<char> > *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  for ( ; v5; v5 = v5->next )
  {
    AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&list, "   ");
    v6 = v5->data.m_buffer;
    v7 = v5->data.m_buffer->m_len;
    if ( v7 != 1 && v6 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars((AC1Legacy::PStringBase<char> *)&list, v6->m_data, v7 - 1);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v13, "\n");
    v8 = v13.m_buffer;
    v9 = v13.m_buffer->m_len;
    if ( v9 != 1 && v13.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars((AC1Legacy::PStringBase<char> *)&list, v13.m_buffer->m_data, v9 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    v4 = list;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, 0, (const char *)&list[1].head);
    ClientSystem::AddTextToScroll(v14, &i_text, 0, 1, 0);
    v10 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v4->head) && v4 )
    v4->vfptr->__vecDelDtor((PackObj *)v4, 1u);
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0057D3A0) --------------------------------------------------------  // acclient.c:422871
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__TextboxString(ClientCommunicationSystem *this, AC1Legacy::PStringBase<char> *msg, unsigned int ltt)
{
  ClientSystem *v3; // ebp@1
  int v4; // eax@1
  AC1Legacy::PSRefBuffer<char> *v5; // esi@1
  bool v6; // bl@1
  AC1Legacy::PSRefBuffer<char> *v7; // esi@5
  unsigned int v8; // eax@5
  AC1Legacy::PStringBase<char> account_name; // [sp+Ch] [bp-4h]@1

  v3 = (ClientSystem *)this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&account_name, &name);
  v4 = gmCCommunicationSystem::IsSquelched(0, &account_name, ltt);
  v5 = account_name.m_buffer;
  v6 = v4 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&account_name.m_buffer->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  if ( v6 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&account_name, "\n");
    v7 = account_name.m_buffer;
    v8 = account_name.m_buffer->m_len;
    if ( v8 != 1 && account_name.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(msg, account_name.m_buffer->m_data, v8 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    ClientSystem::AddTextToScroll(v3, msg->m_buffer->m_data, ltt, 1, 0);
  }
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0057D460) --------------------------------------------------------  // acclient.c:422904
unsigned int __thiscall ClientCommunicationSystem::Handle_Communication__TransientString(ClientCommunicationSystem *this, AC1Legacy::PStringBase<char> *msg)
{
  ClientSystem *v2; // esi@1
  AC1Legacy::PStringBase<char> *v3; // esi@1

  v2 = (ClientSystem *)this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&msg,
    0,
    msg->m_buffer->m_data);
  ClientSystem::AddTextToScroll(v2, (PStringBase<unsigned short> *)&msg, 0x1Au, 1, 0);
  v3 = msg - 5;
  if ( !InterlockedDecrement((volatile LONG *)&msg[-4]) && v3 )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v3->m_buffer->vfptr)(v3, 1);
  return 0;
}

//----- (0057D4C0) --------------------------------------------------------  // acclient.c:422922
char __stdcall ClientCommunicationSystem::HelpAllegiancesGroup(ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem::HelpType v4; // ecx@2
  int v5; // eax@2
  int v6; // esi@4
  LONG v7; // eax@4
  ClientCommunicationSystem::HelpType v8; // ecx@5
  int v9; // eax@5
  PStringBase<char> *v10; // ebx@5
  int v11; // esi@7
  PStringBase<char> *v12; // eax@10
  PSRefBufferCharData<char> *v13; // ecx@10

  if ( type )
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@allegiance - Commands to help manage your allegiance.\n");
    v8 = type;
    v9 = *(_DWORD *)(type - 4);
    v10 = msg;
    if ( v9 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v9 - 1);
      v8 = type;
    }
    v11 = v8 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@allegiance motd - Displays or sets the message of the day for your allegiance, see @help motd for more information.\n");
    v12 = msg;
    v13 = msg[-1].m_charbuffer;
    if ( v13 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v10, (const char *)msg, (unsigned int)&v13[-1].m_data[15]);
      v12 = msg;
    }
    v6 = (int)&v12[-5];
    v7 = InterlockedDecrement((volatile LONG *)&v12[-4]);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&type,
      "@help allegiances - Commands to help you deal with your Allegiance.\n");
    v4 = type;
    v5 = *(_DWORD *)(type - 4);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v5 - 1);
      v4 = type;
    }
    v6 = v4 - 20;
    v7 = InterlockedDecrement((volatile LONG *)(v4 - 20 + 4));
  }
  if ( !v7 && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (0057D5A0) --------------------------------------------------------  // acclient.c:422985
char __thiscall ClientCommunicationSystem::DoAllegiance(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  char *v4; // esi@1
  int v5; // eax@4
  char *v6; // esi@4
  bool v7; // bl@4
  char v8; // al@8
  int v9; // eax@9
  char *v10; // esi@9
  bool v11; // bl@9
  int v12; // eax@14
  char *v13; // esi@14
  bool v14; // bl@14
  int v15; // eax@19
  char *v16; // esi@19
  bool v17; // bl@19
  bool v18; // bl@23
  bool v19; // bl@25
  bool v20; // bl@26
  bool v21; // bl@28
  bool v22; // bl@30
  bool v23; // bl@32
  bool v24; // bl@34
  bool v25; // bl@36
  bool v26; // bl@38
  bool v27; // bl@40
  bool v28; // bl@42
  char **v29; // esi@45
  char *v30; // esi@48
  CaseInsensitiveStringBase<PStringBase<char> > command; // [sp+18h] [bp-8h]@1
  PStringBase<char> result; // [sp+1Ch] [bp-4h]@1

  v3 = this;
  command.m_charbuffer = NextArg(&result, &argc, &argv)->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&command.m_charbuffer[-1]);
  v4 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&result, "boot");
  v5 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v6 = &result.m_charbuffer[-2].m_data[12];
  v7 = v5 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  if ( v7 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceBoot(v3, argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "info");
  v9 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v10 = &result.m_charbuffer[-2].m_data[12];
  v11 = v9 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  if ( v11 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceInfo(v3, argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "chat");
  v12 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v13 = &result.m_charbuffer[-2].m_data[12];
  v14 = v12 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  if ( v14 )
    goto LABEL_54;
  PStringBase<char>::PStringBase<char>(&result, "ch");
  v15 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0);
  v16 = &result.m_charbuffer[-2].m_data[12];
  v17 = v15 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  if ( v17 )
  {
LABEL_54:
    v8 = ClientCommunicationSystem::DoAllegianceChat(v3, argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "broadcast");
  v18 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v18
    || (PStringBase<char>::PStringBase<char>(&result, "br"),
        v19 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0,
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result),
        v19) )
  {
    v8 = ClientCommunicationSystem::DoAllegianceBroadcast(argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "ban");
  v20 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v20 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceBan(v3, argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "officer");
  v21 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v21 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceOfficer(v3, argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "title");
  v22 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v22 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceOfficerTitle(v3, argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "hometown");
  v23 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v23 )
  {
    v8 = CM_Allegiance::Event_RecallAllegianceHometown();
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "ho");
  v24 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v24 )
  {
    v8 = CM_Allegiance::Event_RecallAllegianceHometown();
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "motd");
  v25 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v25 )
  {
    v8 = ClientCommunicationSystem::DoMotd(argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "name");
  v26 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v26 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceName(argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "lock");
  v27 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v27 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceLock(argc, argv);
    goto LABEL_44;
  }
  PStringBase<char>::PStringBase<char>(&result, "house");
  v28 = PStringBase<char>::cmp((PStringBase<char> *)&command.m_charbuffer, &result, 0) == 0;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v28 )
  {
    v8 = ClientCommunicationSystem::DoAllegianceHouse(argc, argv);
LABEL_44:
    if ( v8 )
      goto LABEL_48;
  }
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&argv,
    L"Please see @help Allegiance for more information on how to use this command.");
  ClientSystem::AddTextToScroll(
    (ClientSystem *)&v3->vfptr,
    (PStringBase<unsigned short> *)&argv,
    0x1Au,
    1,
    v3->m_idCurrentCommandSource);
  v29 = argv - 5;
  if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v29 )
    (*(void (__thiscall **)(char **, signed int))*v29)(v29, 1);
LABEL_48:
  v30 = &command.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v30 )
    (**(void (__thiscall ***)(char *, signed int))v30)(v30, 1);
  return 1;
}

//----- (0057DAB0) --------------------------------------------------------  // acclient.c:423172
char __thiscall ClientCommunicationSystem::DoSpeaker(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientSystem *v3; // esi@1
  unsigned int v4; // edi@1
  char *v5; // esi@1
  PStringBase<unsigned short> i_text; // [sp+0h] [bp-4h]@1

  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v3 = (ClientSystem *)this;
  v4 = this->m_idCurrentCommandSource;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    &i_text,
    0,
    "This command is no longer in use, please see @allegiance officer.\n");
  ClientSystem::AddTextToScroll(v3, &i_text, 0, 1, v4);
  v5 = (char *)&i_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return 1;
}

//----- (0057DB10) --------------------------------------------------------  // acclient.c:423194
bool __thiscall ClientCommunicationSystem::SendTurbineChat(ClientCommunicationSystem *this, unsigned int roomID, ChatTypeEnum chatType, PStringBase<char> *message, bool isListening)
{
  ClientCommunicationSystem *v5; // edi@1
  unsigned int v6; // esi@4
  int v7; // esi@7
  bool result; // al@10
  PStringBase<char> *v9; // ebx@11
  int v10; // eax@13
  TurbineChatBlob *v11; // eax@15
  int v12; // eax@16
  int v13; // esi@16
  unsigned int v14; // eax@18
  PSRefBufferCharData<unsigned short> *v15; // ebp@18
  int v16; // ebx@18
  int v17; // eax@18
  unsigned int v18; // esi@20
  int v19; // esi@20
  char v20; // [sp+Ch] [bp-10h]@18
  char v21; // [sp+14h] [bp-8h]@18

  v5 = this;
  if ( !CCommunicationSystem::IsUsingTurbineChat() || !roomID )
  {
    v18 = v5->m_idCurrentCommandSource;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&isListening,
      0,
      "Turbine chat is not available.\n");
    ClientSystem::AddTextToScroll((ClientSystem *)&v5->vfptr, (PStringBase<unsigned short> *)&isListening, 0, 1, v18);
    v19 = isListening - 20;
    if ( !InterlockedDecrement((volatile LONG *)(isListening - 20 + 4)) && v19 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    return 0;
  }
  if ( !isListening )
  {
    *(_DWORD *)&isListening = AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    ChannelSystem::GetGlobalChannelName(chatType, (AC1Legacy::PStringBase<char> *)&isListening);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&roomID,
      0,
      (const char *)(isListening + 20));
    ClientCommunicationSystem::HandleFailureEvent(v5, 0x551u, (PStringBase<unsigned short> *)&roomID);
    v6 = roomID - 20;
    if ( !InterlockedDecrement((volatile LONG *)(roomID - 20 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = isListening;
    if ( !InterlockedDecrement((volatile LONG *)(isListening + 4)) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
    return 1;
  }
  v9 = message;
  if ( *(_DWORD *)&message->m_charbuffer[-1].m_data[12] == 1 || !ClientCommunicationSystem::IsMessageSafe(message) )
    return 0;
  LOBYTE(v10) = ClientCommunicationSystem::IsMessageSpam(v5, 0);
  if ( v10 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&isListening);
    PStringBase<char>::sprintf((PStringBase<char> *)&isListening, "You must wait %ds before communicating again!", 0);
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v5->vfptr,
      (PStringBase<char> *)&isListening,
      0,
      1,
      v5->m_idCurrentCommandSource);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&isListening);
    result = 0;
  }
  else
  {
    v11 = (TurbineChatBlob *)operator new(0xCu);
    if ( v11 )
    {
      CSceneDesc::CSceneDesc(v11);
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    v14 = GetPlayerID();
    TurbineChatBlob::SetTargetID((TurbineChatBlob *)v13, v14);
    *(_DWORD *)(v13 + 8) = chatType;
    v15 = PStringBase<char>::to_wpstring(v9, (PStringBase<unsigned short> *)&isListening, 0)->m_charbuffer;
    v16 = TurbineChatBlob::GetBlob((TurbineChatBlob *)v13, (int)&v20);
    v17 = TurbineChatBlob::GetBlob((TurbineChatBlob *)v13, (int)&v21);
    LOBYTE(v16) = CCommunicationSystem::CSendToTurbineRoomByID(roomID, v15->m_data, *(tagBLOB *)v17, *(tagBLOB *)v16) == 0;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&isListening);
    if ( !(_BYTE)v16 )
      return 1;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&roomID);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&isListening);
    ChannelSystem::GetGlobalChannelName(chatType, (AC1Legacy::PStringBase<char> *)&isListening);
    PStringBase<char>::sprintf((PStringBase<char> *)&roomID, "Failed to send text to channel: %s\n", isListening + 20);
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v5->vfptr,
      (PStringBase<char> *)&roomID,
      0,
      1,
      v5->m_idCurrentCommandSource);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&isListening);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&roomID);
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0057DDA0) --------------------------------------------------------  // acclient.c:423307
char __thiscall ClientCommunicationSystem::DoConsent(ClientCommunicationSystem *this, int argc, char **argv)
{
  PSRefBufferCharData<char> *v3; // edi@1
  int v4; // eax@1
  char *v5; // ebp@1
  bool v6; // bl@1
  CPlayerSystem *v7; // eax@5
  ClientSystem *v8; // ebp@5
  unsigned int v9; // ebx@5
  char **v10; // ebx@5
  int v11; // edi@8
  int v13; // eax@11
  char *v14; // ebp@11
  bool v15; // bl@11
  CPlayerSystem *v16; // eax@15
  int v17; // edi@15
  int v18; // eax@18
  char *v19; // ebp@18
  bool v20; // bl@18
  bool v21; // bl@22
  int v22; // edi@22
  int v23; // eax@26
  char *v24; // ebp@26
  bool v25; // bl@26
  bool v26; // bl@30
  int v27; // esi@31
  bool v28; // bl@34
  PStringBase<char> command; // [sp+10h] [bp-Ch]@1
  ClientSystem *v30; // [sp+14h] [bp-8h]@1
  PStringBase<char> v31; // [sp+18h] [bp-4h]@1

  v30 = (ClientSystem *)this;
  NextArg(&command, &argc, &argv);
  PStringBase<char>::PStringBase<char>(&v31, "on");
  v3 = command.m_charbuffer;
  v4 = __stricmp(command.m_charbuffer->m_data, v31.m_charbuffer->m_data);
  v5 = &v31.m_charbuffer[-2].m_data[12];
  v6 = v4 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v31.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  if ( v6 )
  {
    v7 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetAcceptLootPermits((PlayerModule *)&v7->playerModule.vfptr, 1);
    v8 = v30;
    v9 = (unsigned int)v30[17].vfptr;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      0,
      "You can now accept corpse looting permissions from other players.\n");
    ClientSystem::AddTextToScroll(v8, (PStringBase<unsigned short> *)&argv, 0, 1, v9);
    v10 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v10 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v10)(v10, 1);
    v11 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) && v11 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      return 1;
    }
    return 1;
  }
  PStringBase<char>::PStringBase<char>(&v31, "off");
  v13 = __stricmp(v3->m_data, v31.m_charbuffer->m_data);
  v14 = &v31.m_charbuffer[-2].m_data[12];
  v15 = v13 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v31.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  if ( v15 )
  {
    v16 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetAcceptLootPermits((PlayerModule *)&v16->playerModule.vfptr, 0);
    ClientSystem::AddTextToScroll(
      v30,
      "You are no longer accepting corpse looting permissions from other players.\n",
      0,
      1,
      (unsigned int)v30[17].vfptr);
    v17 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
      return 1;
    }
    return 1;
  }
  PStringBase<char>::PStringBase<char>(&v31, "who");
  v18 = __stricmp(v3->m_data, v31.m_charbuffer->m_data);
  v19 = &v31.m_charbuffer[-2].m_data[12];
  v20 = v18 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v31.m_charbuffer[-1]) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  if ( !v20 )
  {
    PStringBase<char>::PStringBase<char>(&v31, "clear");
    v23 = __stricmp(v3->m_data, v31.m_charbuffer->m_data);
    v24 = &v31.m_charbuffer[-2].m_data[12];
    v25 = v23 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v31.m_charbuffer[-1]) && v24 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
    if ( v25 )
    {
      v26 = CM_Character::Event_ClearPlayerConsentList();
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
      return v26;
    }
    PStringBase<char>::PStringBase<char>(&v31, "remove");
    v27 = __stricmp(v3->m_data, v31.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v31);
    if ( v27 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argv,
        L"Please specify a valid consent command.");
      ClientSystem::AddTextToScroll(v30, (PStringBase<unsigned short> *)&argv, 0x1Au, 1, (unsigned int)v30[17].vfptr);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    }
    else
    {
      JoinArgsAsName((PStringBase<char> *)&argv, argc, argv);
      if ( *(argv - 1) != (char *)1 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&argc, (const char *)argv);
        v28 = CM_Character::Event_RemoveFromPlayerConsentList((AC1Legacy::PStringBase<char> *)&argc);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&argc);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
        return v28;
      }
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argc,
        L"Please specify a person to remove from your consent list.");
      ClientSystem::AddTextToScroll(v30, (PStringBase<unsigned short> *)&argc, 0x1Au, 1, (unsigned int)v30[17].vfptr);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argv);
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
    return 1;
  }
  v21 = CM_Character::Event_DisplayPlayerConsentList();
  v22 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v22 + 4)) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  return v21;
}

//----- (0057E120) --------------------------------------------------------  // acclient.c:423454
bool __thiscall ClientCommunicationSystem::DoRenderOption(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  bool v4; // bl@2
  bool result; // al@6
  const char *status_string; // [sp+4h] [bp-8h]@2
  const char *usage_string; // [sp+8h] [bp-4h]@2

  v3 = this;
  if ( SmartBox::smartbox )
  {
    status_string = 0;
    usage_string = 0;
    v4 = SmartBox::HandleRenderOption(argc, argv, &status_string, &usage_string) != 0;
    if ( status_string )
      ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, status_string, 0x1Au, 1, v3->m_idCurrentCommandSource);
    if ( usage_string )
      ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, usage_string, 0, 1, v3->m_idCurrentCommandSource);
    result = v4;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0057E1B0) --------------------------------------------------------  // acclient.c:423482
char __thiscall ClientCommunicationSystem::DoVersion(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char *v4; // esi@2
  unsigned int v6; // ST10_4@7
  PStringBase<unsigned short> *v7; // eax@7
  char *v8; // edi@7
  int v9; // esi@12
  PStringBase<unsigned short> i_text; // [sp+0h] [bp-4h]@1

  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, L"Unexpected arguments to @version");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
    v4 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    if ( CCommunicationSystem::IsUsingTurbineChat() )
      ClientSystem::AddTextToScroll(
        (ClientSystem *)&v3->vfptr,
        "Using Turbine Chat.\n",
        0,
        1,
        v3->m_idCurrentCommandSource);
    argc = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&argc,
      "Client version %s\n",
      AC1Legacy::Version::VerboseVersionString_);
    v6 = v3->m_idCurrentCommandSource;
    v7 = PStringBase<char>::to_wpstring((PStringBase<char> *)&argc, &i_text, 0);
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v7, 0, 1, v6);
    v8 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    if ( ClientCommunicationSystem::PlayerIsPSR() )
      Proto_UI::SendAdminGetServerVersion();
    v9 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
  return 1;
}

//----- (0057E2E0) --------------------------------------------------------  // acclient.c:423536
char __thiscall ClientCommunicationSystem::DoCommand(ClientCommunicationSystem *this)
{
  ClientCommunicationSystem *v1; // ebx@1
  PStringBase<char> v2; // ST04_4@1
  int v3; // esi@1
  unsigned int v4; // edi@1
  char v5; // al@2
  int v6; // edi@3
  PStringBase<char> *v7; // ebp@3
  ReferenceCountTemplate<268435456,0>Vtbl *v8; // edx@6
  PSRefBufferCharData<char> *v9; // ebp@7
  char *v10; // ebp@8
  PSRefBufferCharData<char> *v11; // ecx@8
  int v12; // edx@10
  void *v13; // eax@11
  ListNode<PStringBase<char> > *v14; // ecx@11
  char **v15; // ebp@11
  unsigned int v16; // eax@11
  PSRefBufferCharData<char> *v17; // esi@17
  int v18; // esi@17
  int v19; // edx@19
  bool (__thiscall *v20)(ClientCommunicationSystem *, int, char **); // eax@21
  AC1Legacy::PSRefBuffer<char> *v21; // esi@25
  ReferenceCountTemplate<268435456,0>Vtbl *v22; // eax@27
  PStringBase<char> v23; // [sp-8h] [bp-3Ch]@1
  PStringBase<char> v24; // [sp-4h] [bp-38h]@1
  AC1Legacy::PStringBase<char> i_msg; // [sp+10h] [bp-24h]@4
  PStringBase<char> result; // [sp+14h] [bp-20h]@3
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> v27; // [sp+18h] [bp-1Ch]@17
  List<PStringBase<char> > list; // [sp+24h] [bp-10h]@1

  list._head = 0;
  list._tail = 0;
  list._num_elements = 0;
  v24.m_charbuffer = (PSRefBufferCharData<char> *)&list;
  v23.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  PStringBase<char>::PStringBase<char>(&v23, " \t");
  v2.m_charbuffer = v1->m_strLastCommandLine.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2.m_charbuffer[-1]);
  v3 = (int)&v1->m_strCurrentCommand;
  v4 = PSUtils::FindAllWords(v2, v23, (List<PStringBase<char> > *)v24.m_charbuffer);
  if ( List<PStringBase<char>>::pop_front(&list, &v1->m_strCurrentCommand) )
  {
    v6 = v4 - 1;
    v7 = PStringBase<char>::substring(&v1->m_strCurrentCommand, &result, 1u, 0xFFFFFFFF);
    if ( *(PSRefBufferCharData<char> **)v3 != v7->m_charbuffer )
    {
      i_msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)(*(_DWORD *)v3 - 20);
      if ( !InterlockedDecrement((volatile LONG *)&i_msg.m_buffer->m_cRef) && i_msg.m_buffer )
      {
        v8 = i_msg.m_buffer->vfptr;
        v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
        ((void (__stdcall *)(signed int))v8->__vecDelDtor)(1);
      }
      v9 = v7->m_charbuffer;
      *(_DWORD *)v3 = v9;
      InterlockedIncrement((volatile LONG *)&v9[-1]);
    }
    v10 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v10 )
    {
      v12 = *(_DWORD *)v10;
      v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v12)(v10, 1);
    }
    v24.m_charbuffer = v11;
    PStringBase<char>::PStringBase<char>(&v24, ",");
    PStringBase<char>::trim(&v1->m_strCurrentCommand, 0, 1, v24);
    v13 = operator new[](4 * v6);
    v14 = list._head;
    v15 = (char **)v13;
    v16 = 0;
    if ( v6 )
    {
      if ( (unsigned int)v6 <= 0 )
        goto LABEL_14;
      do
      {
        v15[v16] = v14->data.m_charbuffer->m_data;
LABEL_14:
        if ( v14 )
          v14 = v14->next;
        ++v16;
      }
      while ( v16 < v6 );
    }
    v17 = *(PSRefBufferCharData<char> **)v3;
    result.m_charbuffer = v17;
    InterlockedIncrement((volatile LONG *)&v17[-1]);
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
      &v1->m_hashCommands,
      &v27,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    v18 = (int)&v17[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) && v18 )
    {
      v19 = *(_DWORD *)v18;
      v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(int, signed int))v19)(v18, 1);
    }
    if ( v27.m_currElement && (v20 = v27.m_currElement->func) != 0 )
    {
      if ( !v20((ClientCommunicationSystem *)((char *)v1 + *((_DWORD *)&v27.m_currElement->func + 1)), v6, v15) )
        ClientCommunicationSystem::HandleFailureEvent(v1, 0x26u, &PStringBase<unsigned short>::null_string);
    }
    else if ( !ClientCommunicationSystem::DoChannelCommand(v1, v6, v15) )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&i_msg, v1->m_strLastCommandLine.m_charbuffer->m_data);
      CM_Communication::Event_Talk(&i_msg);
      v21 = i_msg.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&i_msg.m_buffer->m_cRef) )
      {
        if ( v21 )
        {
          v22 = v21->vfptr;
          v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
          v22->__vecDelDtor(v21, 1);
        }
      }
    }
    operator delete[](v15);
    list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    List<PStringBase<char>>::flush(&list);
    v5 = 1;
  }
  else
  {
    list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    List<PStringBase<char>>::flush(&list);
    v5 = 0;
  }
  return v5;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (0057E4F0) --------------------------------------------------------  // acclient.c:423674
char __thiscall ClientCommunicationSystem::DoSetOutput(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  PStringBase<char> *v4; // eax@2
  LONG (__stdcall *v5)(volatile LONG *); // edi@2
  bool v6; // bl@2
  char *v7; // ebp@2
  PSRefBufferCharData<char> *v8; // eax@6
  int v9; // ecx@6
  int v10; // ebx@8
  unsigned int v11; // ST14_4@13
  PStringBase<unsigned short> *v12; // eax@13
  char *v13; // esi@13
  int v14; // esi@17
  int v15; // esi@21
  char **v16; // esi@24
  PStringBase<char> result; // [sp+8h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  JoinArgs((PStringBase<char> *)&argv, argc, argv);
  if ( *(argv - 1) != (char *)1 )
  {
    v4 = PSUtils::get_extension(&result, (PStringBase<char> *)&argv);
    v5 = InterlockedDecrement;
    v6 = PStringBase<char>::operator==(v4, &PStringBase<char>::null_string);
    v7 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    if ( v6 )
    {
      PStringBase<char>::PStringBase<char>(&result, ".txt");
      v8 = result.m_charbuffer;
      v9 = *(_DWORD *)&result.m_charbuffer[-1].m_data[12];
      if ( v9 != 1 )
      {
        PStringBase<char>::append_n_chars((PStringBase<char> *)&argv, result.m_charbuffer->m_data, v9 - 1);
        v8 = result.m_charbuffer;
      }
      v10 = (int)&v8[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argc,
      0,
      "Copying chat to %s.  Run command again with no arguments to turn off logging.\n",
      argv);
    if ( !(unsigned __int8)ClientCommunicationSystem::StartCopyOutputToFile(v3, (PStringBase<char> *)&argv) )
      PStringBase<char>::sprintf((PStringBase<char> *)&argc, "Failed to redirect to file %s!\n", argv);
    v11 = v3->m_idCurrentCommandSource;
    v12 = PStringBase<char>::to_wpstring((PStringBase<char> *)&argc, (PStringBase<unsigned short> *)&result, 0);
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, v12, 0, 1, v11);
    v13 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    goto LABEL_21;
  }
  if ( !ClientCommunicationSystem::CloseLogFile(v3) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"Please specify a file to append chat messages to.\n");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0,
      1,
      v3->m_idCurrentCommandSource);
    v5 = InterlockedDecrement;
LABEL_21:
    v15 = argc - 20;
    if ( !v5((volatile LONG *)(argc - 20 + 4)) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    goto LABEL_24;
  }
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&argc,
    L"Chat output now directed only to the screen.\n");
  ClientSystem::AddTextToScroll(
    (ClientSystem *)&v3->vfptr,
    (PStringBase<unsigned short> *)&argc,
    0,
    1,
    v3->m_idCurrentCommandSource);
  v5 = InterlockedDecrement;
  v14 = argc - 20;
  if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
LABEL_24:
  v16 = argv - 5;
  if ( !v5((volatile LONG *)argv - 4) && v16 )
    (*(void (__thiscall **)(char **, signed int))*v16)(v16, 1);
  return 1;
}

//----- (0057E700) --------------------------------------------------------  // acclient.c:423771
void __thiscall ClientCommunicationSystem::RecvNotice_DisplayWeenieError(ClientCommunicationSystem *this, unsigned int etype, AC1Legacy::PStringBase<char> *user_data)
{
  ClientCommunicationSystem *v3; // esi@1
  AC1Legacy::PStringBase<char> *v4; // esi@1

  v3 = this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&user_data,
    0,
    user_data->m_buffer->m_data);
  ClientCommunicationSystem::HandleFailureEvent(
    (ClientCommunicationSystem *)((char *)v3 - 4),
    etype,
    (PStringBase<unsigned short> *)&user_data);
  v4 = user_data - 5;
  if ( !InterlockedDecrement((volatile LONG *)&user_data[-4]) )
  {
    if ( v4 )
      ((void (__thiscall *)(_DWORD, _DWORD))v4->m_buffer->vfptr)(v4, 1);
  }
}

//----- (0057E750) --------------------------------------------------------  // acclient.c:423794
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this, ClientCommunicationSystem::CmdHashData *data)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v2; // esi@1
  char v3; // al@2
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+8h] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    this,
    &result,
    &data->m_hashKey);
  if ( result.m_currElement )
  {
    v3 = 0;
  }
  else
  {
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v2,
      data);
    v3 = 1;
  }
  return v3;
}

//----- (0057E790) --------------------------------------------------------  // acclient.c:423820
ClientCommunicationSystem::CmdHashData *__thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::remove(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this, CaseInsensitiveStringBase<PStringBase<char> > *key)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v2; // esi@1
  ClientCommunicationSystem::CmdHashData *v3; // edi@1
  _BYTE v4[12]; // ST00_12@2
  ClientCommunicationSystem::CmdHashData *result; // eax@2
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> iter; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    this,
    &iter,
    key);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    *(_QWORD *)&v4[4] = *(_QWORD *)&iter.m_currBucket;
    *(_DWORD *)v4 = iter.m_currHashTable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
      (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v2,
      *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0057E7F0) --------------------------------------------------------  // acclient.c:423851
char __thiscall ClientCommunicationSystem::HelpAllGroup(ClientCommunicationSystem *this, ClientCommunicationSystem::HelpType type, const char *argv0, PStringBase<char> *msg)
{
  ClientCommunicationSystem *v4; // ebx@1
  ClientCommunicationSystem::HelpType v5; // esi@2
  int v6; // eax@2
  int v7; // esi@4
  PStringBase<char> *v9; // esi@7
  PStringBase<char> *v10; // ecx@7
  PSRefBufferCharData<char> *v11; // eax@7
  int v12; // edi@9
  PStringBase<char> *v13; // eax@12
  PSRefBufferCharData<char> *v14; // ecx@12
  int v15; // edi@14
  PStringBase<char> *v16; // ecx@17
  PSRefBufferCharData<char> *v17; // eax@17
  int v18; // edi@19
  PStringBase<char> *v19; // ecx@22
  PSRefBufferCharData<char> *v20; // eax@22
  int v21; // edi@24
  PStringBase<char> *v22; // ecx@27
  PSRefBufferCharData<char> *v23; // eax@27
  int v24; // edi@29
  PStringBase<char> *v25; // ecx@32
  PSRefBufferCharData<char> *v26; // eax@32
  int v27; // edi@34
  PStringBase<char> *v28; // eax@37
  PSRefBufferCharData<char> *v29; // ecx@37
  int v30; // edi@39
  PStringBase<char> *v31; // eax@42
  PSRefBufferCharData<char> *v32; // ecx@42
  int v33; // edi@44
  PStringBase<char> *v34; // eax@47
  PSRefBufferCharData<char> *v35; // ecx@47
  int v36; // edi@49
  PStringBase<char> *v37; // eax@52
  PSRefBufferCharData<char> *v38; // ecx@52
  int v39; // edi@54

  v4 = this;
  if ( type )
  {
    v9 = msg;
    ClientCommunicationSystem::HelpAllegiancesGroup(Detail_HelpType, "@allegiances", msg);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "a", v9);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "c", v9);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "m", v9);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "p", v9);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "v", v9);
    ClientCommunicationSystem::HelpStupidChannelHack(0, "f", v9);
    ClientCommunicationSystem::HelpChattingGroup(Detail_HelpType, "@chatting", v9);
    ClientCommunicationSystem::HelpDeathGroup(v4, Detail_HelpType, "@death", v9);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@emote - Performs a text emote.\n@emotes - Lists all standard emotes.\n");
    v10 = msg;
    v11 = msg[-1].m_charbuffer;
    if ( v11 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v11[-1].m_data[15]);
      v10 = msg;
    }
    v12 = (int)&v10[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-4]) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, "@fillcomps - Helps you buy components in bulk.\n");
    v13 = msg;
    v14 = msg[-1].m_charbuffer;
    if ( v14 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v14[-1].m_data[15]);
      v13 = msg;
    }
    v15 = (int)&v13[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v13[-4]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@saveui <filename> - Saves the current user interface.\n");
    v16 = msg;
    v17 = msg[-1].m_charbuffer;
    if ( v17 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v17[-1].m_data[15]);
      v16 = msg;
    }
    v18 = (int)&v16[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v16[-4]) && v18 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@loadui <filename> - Loads a previously saved user interface.\n");
    v19 = msg;
    v20 = msg[-1].m_charbuffer;
    if ( v20 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v20[-1].m_data[15]);
      v19 = msg;
    }
    v21 = (int)&v19[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v19[-4]) && v21 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@saveui <filename> - Saves the current user interface.\n");
    v22 = msg;
    v23 = msg[-1].m_charbuffer;
    if ( v23 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v23[-1].m_data[15]);
      v22 = msg;
    }
    v24 = (int)&v22[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v22[-4]) && v24 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@loadui <filename> - Loads a previously saved user interface.\n");
    v25 = msg;
    v26 = msg[-1].m_charbuffer;
    if ( v26 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v26[-1].m_data[15]);
      v25 = msg;
    }
    v27 = (int)&v25[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v25[-4]) && v27 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@lockui - Toggles the locked state of the UI layout.\n");
    v28 = msg;
    v29 = msg[-1].m_charbuffer;
    if ( v29 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v29[-1].m_data[15]);
      v28 = msg;
    }
    v30 = (int)&v28[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v28[-4]) && v30 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&msg, "@friends - Helps you manage your friends list.\n");
    v31 = msg;
    v32 = msg[-1].m_charbuffer;
    if ( v32 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v32[-1].m_data[15]);
      v31 = msg;
    }
    v33 = (int)&v31[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v31[-4]) && v33 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v33)(v33, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@house - Commands that help you manage your house, including guest and storage management.\n");
    v34 = msg;
    v35 = msg[-1].m_charbuffer;
    if ( v35 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v35[-1].m_data[15]);
      v34 = msg;
    }
    v36 = (int)&v34[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v34[-4]) && v36 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&msg,
      "@squelch - Squelches a character or account.\n@unsquelch - Unsquelches a squelched character or account.\n@messagetypes - Lists all types of messages that can be squelched or filtered.\n");
    v37 = msg;
    v38 = msg[-1].m_charbuffer;
    if ( v38 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v9, (const char *)msg, (unsigned int)&v38[-1].m_data[15]);
      v37 = msg;
    }
    v39 = (int)&v37[-5];
    if ( !InterlockedDecrement((volatile LONG *)&v37[-4]) && v39 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v39)(v39, 1);
    ClientCommunicationSystem::HelpStatusGroup(v4, Detail_HelpType, "@status", v9);
    ClientCommunicationSystem::HelpTextGroup(v4, Detail_HelpType, "@text", v9);
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&type, "@help commands - Lists all commands.\n");
    v5 = type;
    v6 = *(_DWORD *)(type - 4);
    if ( v6 != 1 )
    {
      PStringBase<char>::append_n_chars(msg, (const char *)type, v6 - 1);
      v5 = type;
    }
    v7 = v5 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      return 1;
    }
  }
  return 1;
}

//----- (0057EBA0) --------------------------------------------------------  // acclient.c:424052
bool __thiscall ClientCommunicationSystem::DoTurbineChat_Allegiance(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  ClientCommunicationSystem *v4; // edi@1
  bool result; // al@2
  PlayerModule *v6; // eax@3
  unsigned int v7; // esi@3
  CPlayerSystem *v8; // eax@5
  char v9; // al@5
  bool v10; // bl@5
  int v11; // esi@5

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    v6 = (PlayerModule *)gmCCommunicationSystem::GetChatRoomTracker();
    v7 = (unsigned int)CInputManager::GetMouseX(v6);
    if ( v7 )
    {
      JoinArgs((PStringBase<char> *)&argc, v3, argv);
      v8 = CPlayerSystem::GetPlayerSystem();
      v9 = PlayerModule::HearAllegianceChat((PlayerModule *)&v8->playerModule.vfptr);
      v10 = ClientCommunicationSystem::SendTurbineChat(v4, v7, Allegiance_ChatTypeEnum, (PStringBase<char> *)&argc, v9);
      v11 = argc - 20;
      if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
      {
        if ( v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      }
      result = v10;
    }
    else
    {
      ClientCommunicationSystem::HandleFailureEvent(v4, 0x414u, &PStringBase<unsigned short>::null_string);
      result = 0;
    }
  }
  else
  {
    ClientCommunicationSystem::HandleFailureEvent(this, 0x26u, &PStringBase<unsigned short>::null_string);
    result = 0;
  }
  return result;
}

//----- (0057EC50) --------------------------------------------------------  // acclient.c:424099
bool __thiscall ClientCommunicationSystem::DoTurbineChat_General(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  ClientCommunicationSystem *v4; // edi@1
  bool result; // al@2
  ChatDisplayInfo *v6; // eax@3
  unsigned int v7; // esi@3
  CPlayerSystem *v8; // eax@3
  char v9; // al@3
  bool v10; // bl@3
  int v11; // esi@3

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    v6 = (ChatDisplayInfo *)gmCCommunicationSystem::GetChatRoomTracker();
    v7 = HookAppraisalProfile::GetValidLocations(v6);
    JoinArgs((PStringBase<char> *)&argc, v3, argv);
    v8 = CPlayerSystem::GetPlayerSystem();
    v9 = PlayerModule::HearGeneralChat((PlayerModule *)&v8->playerModule.vfptr);
    v10 = ClientCommunicationSystem::SendTurbineChat(v4, v7, General_ChatTypeEnum, (PStringBase<char> *)&argc, v9);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    result = v10;
  }
  else
  {
    ClientCommunicationSystem::HandleFailureEvent(this, 0x26u, &PStringBase<unsigned short>::null_string);
    result = 0;
  }
  return result;
}

//----- (0057ECE0) --------------------------------------------------------  // acclient.c:424138
bool __thiscall ClientCommunicationSystem::DoTurbineChat_Trade(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  ClientCommunicationSystem *v4; // edi@1
  bool result; // al@2
  ChatRoomTracker *v6; // eax@3
  unsigned int v7; // esi@3
  CPlayerSystem *v8; // eax@3
  char v9; // al@3
  bool v10; // bl@3
  int v11; // esi@3

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    v6 = gmCCommunicationSystem::GetChatRoomTracker();
    v7 = ChatRoomTracker::GetGlobalTradeRoomID(v6);
    JoinArgs((PStringBase<char> *)&argc, v3, argv);
    v8 = CPlayerSystem::GetPlayerSystem();
    v9 = PlayerModule::HearTradeChat((PlayerModule *)&v8->playerModule.vfptr);
    v10 = ClientCommunicationSystem::SendTurbineChat(v4, v7, Trade_ChatTypeEnum, (PStringBase<char> *)&argc, v9);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    result = v10;
  }
  else
  {
    ClientCommunicationSystem::HandleFailureEvent(this, 0x26u, &PStringBase<unsigned short>::null_string);
    result = 0;
  }
  return result;
}

//----- (0057ED70) --------------------------------------------------------  // acclient.c:424177
bool __thiscall ClientCommunicationSystem::DoTurbineChat_LFG(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  ClientCommunicationSystem *v4; // edi@1
  bool result; // al@2
  ChatRoomTracker *v6; // eax@3
  unsigned int v7; // esi@3
  CPlayerSystem *v8; // eax@3
  char v9; // al@3
  bool v10; // bl@3
  int v11; // esi@3

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    v6 = gmCCommunicationSystem::GetChatRoomTracker();
    v7 = PhysicsDesc::get_autonomous_movement(v6);
    JoinArgs((PStringBase<char> *)&argc, v3, argv);
    v8 = CPlayerSystem::GetPlayerSystem();
    v9 = PlayerModule::HearLFGChat((PlayerModule *)&v8->playerModule.vfptr);
    v10 = ClientCommunicationSystem::SendTurbineChat(v4, v7, LFG_ChatTypeEnum, (PStringBase<char> *)&argc, v9);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    result = v10;
  }
  else
  {
    ClientCommunicationSystem::HandleFailureEvent(this, 0x26u, &PStringBase<unsigned short>::null_string);
    result = 0;
  }
  return result;
}

//----- (0057EE00) --------------------------------------------------------  // acclient.c:424216
bool __thiscall ClientCommunicationSystem::DoTurbineChat_Roleplay(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  ClientCommunicationSystem *v4; // edi@1
  bool result; // al@2
  ChatRoomTracker *v6; // eax@3
  unsigned int v7; // esi@3
  CPlayerSystem *v8; // eax@3
  char v9; // al@3
  bool v10; // bl@3
  int v11; // esi@3

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    v6 = gmCCommunicationSystem::GetChatRoomTracker();
    v7 = PhysicsDesc::get_animframe_id(v6);
    JoinArgs((PStringBase<char> *)&argc, v3, argv);
    v8 = CPlayerSystem::GetPlayerSystem();
    v9 = PlayerModule::HearRoleplayChat((PlayerModule *)&v8->playerModule.vfptr);
    v10 = ClientCommunicationSystem::SendTurbineChat(v4, v7, Roleplay_ChatTypeEnum, (PStringBase<char> *)&argc, v9);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    result = v10;
  }
  else
  {
    ClientCommunicationSystem::HandleFailureEvent(this, 0x26u, &PStringBase<unsigned short>::null_string);
    result = 0;
  }
  return result;
}

//----- (0057EE90) --------------------------------------------------------  // acclient.c:424255
bool __thiscall ClientCommunicationSystem::DoTurbineChat_Olthoi(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  ClientCommunicationSystem *v4; // edi@1
  bool result; // al@2
  ChatRoomTracker *v6; // eax@3
  unsigned int v7; // esi@3
  int v8; // eax@3
  bool v9; // al@3
  int v10; // esi@3
  bool v11; // bl@3

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    v6 = gmCCommunicationSystem::GetChatRoomTracker();
    v7 = AnimSequenceNode::get_high_frame(v6);
    JoinArgs((PStringBase<char> *)&argc, v3, argv);
    v8 = CPlayerSystem::IsOlthoi();
    v9 = ClientCommunicationSystem::SendTurbineChat(v4, v7, Olthoi_ChatTypeEnum, (PStringBase<char> *)&argc, v8 != 0);
    v10 = argc - 20;
    v11 = v9;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    result = v11;
  }
  else
  {
    ClientCommunicationSystem::HandleFailureEvent(this, 0x26u, &PStringBase<unsigned short>::null_string);
    result = 0;
  }
  return result;
}

//----- (0057EF20) --------------------------------------------------------  // acclient.c:424294
bool __thiscall ClientCommunicationSystem::DoTurbineChat_Society(ClientCommunicationSystem *this, int argc, char **argv)
{
  int v3; // ebx@1
  ClientCommunicationSystem *v4; // edi@1
  bool result; // al@2
  ChatRoomTracker *v6; // eax@3
  unsigned int v7; // esi@3
  CPlayerSystem *v8; // eax@3
  char v9; // al@3
  bool v10; // bl@3
  int v11; // esi@3

  v3 = argc;
  v4 = this;
  if ( argc )
  {
    v6 = gmCCommunicationSystem::GetChatRoomTracker();
    v7 = ChatRoomTracker::GetGlobalSocietyRoomID(v6);
    JoinArgs((PStringBase<char> *)&argc, v3, argv);
    v8 = CPlayerSystem::GetPlayerSystem();
    v9 = PlayerModule::HearSocietyChat((PlayerModule *)&v8->playerModule.vfptr);
    v10 = ClientCommunicationSystem::SendTurbineChat(v4, v7, Society_ChatTypeEnum, (PStringBase<char> *)&argc, v9);
    v11 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    result = v10;
  }
  else
  {
    ClientCommunicationSystem::HandleFailureEvent(this, 0x26u, &PStringBase<unsigned short>::null_string);
    result = 0;
  }
  return result;
}

//----- (0057EFB0) --------------------------------------------------------  // acclient.c:424333
char __thiscall ClientCommunicationSystem::StartupTurbineChatSystem(ClientCommunicationSystem *this)
{
  ClientCommunicationSystem *v1; // esi@1
  signed __int16 v2; // bx@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v3; // ebp@1
  ClientCommunicationSystem::CmdHashData *v4; // eax@1
  char *v5; // esi@1
  void *v6; // edi@1
  int v7; // esi@5
  void *v8; // esi@9
  char *v9; // esi@15
  void *v10; // esi@18
  char *v11; // esi@24
  void *v12; // esi@27
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v13; // edx@28
  char *v14; // esi@33
  void *v15; // esi@36
  char *v16; // esi@42
  void *v17; // esi@45
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v18; // edx@46
  char *v19; // esi@51
  void *v20; // esi@54
  char *v21; // esi@60
  void *v22; // esi@63
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v23; // edx@64
  char *v24; // esi@69
  void *v25; // esi@72
  char *v26; // esi@78
  void *v27; // esi@81
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v28; // edx@82
  char *v29; // esi@87
  void *v30; // esi@90
  char *v31; // esi@96
  void *v32; // esi@99
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v33; // edx@100
  char *v34; // esi@105
  void *v35; // esi@108
  char *v36; // esi@114
  void *v37; // esi@117
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v38; // edx@118
  char *v39; // esi@123
  void *v40; // esi@126
  char *v41; // esi@132
  void *v42; // esi@135
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v43; // edx@136
  char *v44; // esi@141
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v46; // [sp+40h] [bp-14h]@1
  PStringBase<char> v47; // [sp+44h] [bp-10h]@1
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+48h] [bp-Ch]@12

  v1 = this;
  v2 = 0;
  v47.m_charbuffer = 0;
  PStringBase<char>::PStringBase<char>(&v47, "a");
  v3 = &v1->m_hashCommands;
  v46 = &v1->m_hashCommands;
  v4 = IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::remove(
         &v1->m_hashCommands,
         (CaseInsensitiveStringBase<PStringBase<char> > *)&v47);
  v5 = &v47.m_charbuffer[-2].m_data[12];
  v6 = v4;
  if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  if ( v6 )
  {
    v7 = *(_DWORD *)v6 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    operator delete(v6);
  }
  v8 = operator new(0x18u);
  if ( v8 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "a");
    *(_DWORD *)v8 = v47.m_charbuffer;
    v2 = 1;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v8 + 2) = ClientCommunicationSystem::DoTurbineChat_Allegiance;
    *((_DWORD *)v8 + 4) = ClientCommunicationSystem::HelpTurbineChat_Allegiance;
    v3 = v46;
    *((_DWORD *)v8 + 1) = 0;
    *((_DWORD *)v8 + 3) = 0;
    *((_DWORD *)v8 + 5) = 0;
  }
  else
  {
    v8 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v8);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v8);
  if ( v2 & 1 )
  {
    v9 = &v47.m_charbuffer[-2].m_data[12];
    v2 &= 0xFFFEu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
  }
  v10 = operator new(0x18u);
  if ( v10 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "guild");
    *(_DWORD *)v10 = v47.m_charbuffer;
    v2 |= 2u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v10 + 2) = ClientCommunicationSystem::DoTurbineChat_Allegiance;
    *((_DWORD *)v10 + 4) = ClientCommunicationSystem::HelpTurbineChat_Allegiance;
    v3 = v46;
    *((_DWORD *)v10 + 1) = 0;
    *((_DWORD *)v10 + 3) = 0;
    *((_DWORD *)v10 + 5) = 0;
  }
  else
  {
    v10 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v10);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v10);
  if ( v2 & 2 )
  {
    v11 = &v47.m_charbuffer[-2].m_data[12];
    v2 &= 0xFFFDu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
  }
  v12 = operator new(0x18u);
  if ( v12 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoTurbineChat_Allegiance;
    PStringBase<char>::PStringBase<char>(&v47, "gu");
    *(_DWORD *)v12 = v47.m_charbuffer;
    v2 |= 4u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    v13 = result.m_currHashTable;
    *((_DWORD *)v12 + 4) = ClientCommunicationSystem::HelpTurbineChat_Allegiance;
    v3 = v46;
    *((_DWORD *)v12 + 1) = 0;
    *((_DWORD *)v12 + 2) = v13;
    *((_DWORD *)v12 + 3) = 0;
    *((_DWORD *)v12 + 5) = 0;
  }
  else
  {
    v12 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v12);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v12);
  if ( v2 & 4 )
  {
    v14 = &v47.m_charbuffer[-2].m_data[12];
    v2 &= 0xFFFBu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    }
  }
  v15 = operator new(0x18u);
  if ( v15 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "general");
    *(_DWORD *)v15 = v47.m_charbuffer;
    v2 |= 8u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v15 + 2) = ClientCommunicationSystem::DoTurbineChat_General;
    *((_DWORD *)v15 + 4) = ClientCommunicationSystem::HelpTurbineChat_General;
    v3 = v46;
    *((_DWORD *)v15 + 1) = 0;
    *((_DWORD *)v15 + 3) = 0;
    *((_DWORD *)v15 + 5) = 0;
  }
  else
  {
    v15 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v15);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v15);
  if ( v2 & 8 )
  {
    v16 = &v47.m_charbuffer[-2].m_data[12];
    v2 &= 0xFFF7u;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v16 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    }
  }
  v17 = operator new(0x18u);
  if ( v17 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoTurbineChat_General;
    PStringBase<char>::PStringBase<char>(&v47, "cg");
    *(_DWORD *)v17 = v47.m_charbuffer;
    v2 |= 0x10u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    v18 = result.m_currHashTable;
    *((_DWORD *)v17 + 4) = ClientCommunicationSystem::HelpTurbineChat_General;
    v3 = v46;
    *((_DWORD *)v17 + 1) = 0;
    *((_DWORD *)v17 + 2) = v18;
    *((_DWORD *)v17 + 3) = 0;
    *((_DWORD *)v17 + 5) = 0;
  }
  else
  {
    v17 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v17);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v17);
  if ( v2 & 0x10 )
  {
    v19 = &v47.m_charbuffer[-2].m_data[12];
    v2 &= 0xFFEFu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v19 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    }
  }
  v20 = operator new(0x18u);
  if ( v20 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "trade");
    *(_DWORD *)v20 = v47.m_charbuffer;
    v2 |= 0x20u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v20 + 2) = ClientCommunicationSystem::DoTurbineChat_Trade;
    *((_DWORD *)v20 + 4) = ClientCommunicationSystem::HelpTurbineChat_Trade;
    v3 = v46;
    *((_DWORD *)v20 + 1) = 0;
    *((_DWORD *)v20 + 3) = 0;
    *((_DWORD *)v20 + 5) = 0;
  }
  else
  {
    v20 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v20);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v20);
  if ( v2 & 0x20 )
  {
    v21 = &v47.m_charbuffer[-2].m_data[12];
    v2 &= 0xFFDFu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v21 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    }
  }
  v22 = operator new(0x18u);
  if ( v22 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoTurbineChat_Trade;
    PStringBase<char>::PStringBase<char>(&v47, "ct");
    *(_DWORD *)v22 = v47.m_charbuffer;
    v2 |= 0x40u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    v23 = result.m_currHashTable;
    *((_DWORD *)v22 + 4) = ClientCommunicationSystem::HelpTurbineChat_Trade;
    v3 = v46;
    *((_DWORD *)v22 + 1) = 0;
    *((_DWORD *)v22 + 2) = v23;
    *((_DWORD *)v22 + 3) = 0;
    *((_DWORD *)v22 + 5) = 0;
  }
  else
  {
    v22 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v22);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v22);
  if ( v2 & 0x40 )
  {
    v24 = &v47.m_charbuffer[-2].m_data[12];
    v2 &= 0xFFBFu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v24 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
    }
  }
  v25 = operator new(0x18u);
  if ( v25 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "lfg");
    *(_DWORD *)v25 = v47.m_charbuffer;
    v2 |= 0x80u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v25 + 2) = ClientCommunicationSystem::DoTurbineChat_LFG;
    *((_DWORD *)v25 + 4) = ClientCommunicationSystem::HelpTurbineChat_LFG;
    v3 = v46;
    *((_DWORD *)v25 + 1) = 0;
    *((_DWORD *)v25 + 3) = 0;
    *((_DWORD *)v25 + 5) = 0;
  }
  else
  {
    v25 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v25);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v25);
  if ( (char)v2 < 0 )
  {
    v26 = &v47.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v26 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
    }
  }
  v27 = operator new(0x18u);
  if ( v27 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoTurbineChat_LFG;
    PStringBase<char>::PStringBase<char>(&v47, "clfg");
    *(_DWORD *)v27 = v47.m_charbuffer;
    HIBYTE(v2) |= 1u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    v28 = result.m_currHashTable;
    *((_DWORD *)v27 + 4) = ClientCommunicationSystem::HelpTurbineChat_LFG;
    v3 = v46;
    *((_DWORD *)v27 + 1) = 0;
    *((_DWORD *)v27 + 2) = v28;
    *((_DWORD *)v27 + 3) = 0;
    *((_DWORD *)v27 + 5) = 0;
  }
  else
  {
    v27 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v27);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v27);
  if ( HIBYTE(v2) & 1 )
  {
    v29 = &v47.m_charbuffer[-2].m_data[12];
    HIBYTE(v2) &= 0xFEu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v29 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
    }
  }
  v30 = operator new(0x18u);
  if ( v30 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "roleplay");
    *(_DWORD *)v30 = v47.m_charbuffer;
    HIBYTE(v2) |= 2u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v30 + 2) = ClientCommunicationSystem::DoTurbineChat_Roleplay;
    *((_DWORD *)v30 + 4) = ClientCommunicationSystem::HelpTurbineChat_Roleplay;
    v3 = v46;
    *((_DWORD *)v30 + 1) = 0;
    *((_DWORD *)v30 + 3) = 0;
    *((_DWORD *)v30 + 5) = 0;
  }
  else
  {
    v30 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v30);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v30);
  if ( HIBYTE(v2) & 2 )
  {
    v31 = &v47.m_charbuffer[-2].m_data[12];
    HIBYTE(v2) &= 0xFDu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v31 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
    }
  }
  v32 = operator new(0x18u);
  if ( v32 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoTurbineChat_Roleplay;
    PStringBase<char>::PStringBase<char>(&v47, "crp");
    *(_DWORD *)v32 = v47.m_charbuffer;
    HIBYTE(v2) |= 4u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    v33 = result.m_currHashTable;
    *((_DWORD *)v32 + 4) = ClientCommunicationSystem::HelpTurbineChat_Roleplay;
    v3 = v46;
    *((_DWORD *)v32 + 1) = 0;
    *((_DWORD *)v32 + 2) = v33;
    *((_DWORD *)v32 + 3) = 0;
    *((_DWORD *)v32 + 5) = 0;
  }
  else
  {
    v32 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v32);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v32);
  if ( HIBYTE(v2) & 4 )
  {
    v34 = &v47.m_charbuffer[-2].m_data[12];
    HIBYTE(v2) &= 0xFBu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v34 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
    }
  }
  v35 = operator new(0x18u);
  if ( v35 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "society");
    *(_DWORD *)v35 = v47.m_charbuffer;
    HIBYTE(v2) |= 8u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v35 + 2) = ClientCommunicationSystem::DoTurbineChat_Society;
    *((_DWORD *)v35 + 4) = ClientCommunicationSystem::HelpTurbineChat_Society;
    v3 = v46;
    *((_DWORD *)v35 + 1) = 0;
    *((_DWORD *)v35 + 3) = 0;
    *((_DWORD *)v35 + 5) = 0;
  }
  else
  {
    v35 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v35);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v35);
  if ( HIBYTE(v2) & 8 )
  {
    v36 = &v47.m_charbuffer[-2].m_data[12];
    HIBYTE(v2) &= 0xF7u;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v36 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
    }
  }
  v37 = operator new(0x18u);
  if ( v37 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoTurbineChat_Society;
    PStringBase<char>::PStringBase<char>(&v47, "soc");
    *(_DWORD *)v37 = v47.m_charbuffer;
    HIBYTE(v2) |= 0x10u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    v38 = result.m_currHashTable;
    *((_DWORD *)v37 + 4) = ClientCommunicationSystem::HelpTurbineChat_Society;
    v3 = v46;
    *((_DWORD *)v37 + 1) = 0;
    *((_DWORD *)v37 + 2) = v38;
    *((_DWORD *)v37 + 3) = 0;
    *((_DWORD *)v37 + 5) = 0;
  }
  else
  {
    v37 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v37);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v37);
  if ( HIBYTE(v2) & 0x10 )
  {
    v39 = &v47.m_charbuffer[-2].m_data[12];
    HIBYTE(v2) &= 0xEFu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v39 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v39)(v39, 1);
    }
  }
  v40 = operator new(0x18u);
  if ( v40 )
  {
    PStringBase<char>::PStringBase<char>(&v47, "olthoi");
    *(_DWORD *)v40 = v47.m_charbuffer;
    HIBYTE(v2) |= 0x20u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    *((_DWORD *)v40 + 2) = ClientCommunicationSystem::DoTurbineChat_Olthoi;
    *((_DWORD *)v40 + 4) = ClientCommunicationSystem::HelpTurbineChat_Olthoi;
    v3 = v46;
    *((_DWORD *)v40 + 1) = 0;
    *((_DWORD *)v40 + 3) = 0;
    *((_DWORD *)v40 + 5) = 0;
  }
  else
  {
    v40 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v40);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v40);
  if ( HIBYTE(v2) & 0x20 )
  {
    v41 = &v47.m_charbuffer[-2].m_data[12];
    HIBYTE(v2) &= 0xDFu;
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v41 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v41)(v41, 1);
    }
  }
  v42 = operator new(0x18u);
  if ( v42 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoTurbineChat_Olthoi;
    PStringBase<char>::PStringBase<char>(&v47, "o");
    *(_DWORD *)v42 = v47.m_charbuffer;
    HIBYTE(v2) |= 0x40u;
    InterlockedIncrement((volatile LONG *)&v47.m_charbuffer[-1]);
    v43 = result.m_currHashTable;
    *((_DWORD *)v42 + 4) = ClientCommunicationSystem::HelpTurbineChat_Olthoi;
    v3 = v46;
    *((_DWORD *)v42 + 1) = 0;
    *((_DWORD *)v42 + 2) = v43;
    *((_DWORD *)v42 + 3) = 0;
    *((_DWORD *)v42 + 5) = 0;
  }
  else
  {
    v42 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v42);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v42);
  if ( HIBYTE(v2) & 0x40 )
  {
    v44 = &v47.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) )
    {
      if ( v44 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v44)(v44, 1);
    }
  }
  return 1;
}

//----- (0057F9E0) --------------------------------------------------------  // acclient.c:424959
char __thiscall ClientCommunicationSystem::DoHelp(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char **v4; // edi@2
  int v5; // eax@2
  LONG (__stdcall *v6)(volatile LONG *); // ebx@4
  int v7; // edi@4
  char **v8; // edi@7
  int v9; // eax@7
  int v10; // edi@9
  char **v11; // edi@12
  int v12; // eax@12
  int v13; // edi@14
  char **v14; // edi@17
  int v15; // eax@17
  int v16; // edi@19
  char **v17; // edi@22
  int v18; // eax@22
  int v19; // edi@24
  char **v20; // edi@27
  int v21; // eax@27
  int v22; // edi@29
  char **v23; // edi@32
  int v24; // eax@32
  int v25; // edi@34
  int v26; // esi@37
  char *v27; // esi@40
  PSRefBufferCharData<char> *v28; // edi@41
  int v29; // edi@41
  int v30; // eax@43
  bool (__thiscall *v31)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *); // eax@45
  int v33; // esi@50
  int v34; // eax@52
  char *v35; // esi@53
  int v36; // edx@55
  char *v37; // esi@56
  int v38; // edx@58
  int v39; // edx@62
  PStringBase<char> v40; // [sp+Ch] [bp-28h]@40
  PStringBase<char> command; // [sp+1Ch] [bp-18h]@41
  PStringBase<char> header; // [sp+20h] [bp-14h]@1
  PStringBase<char> msg; // [sp+24h] [bp-10h]@41
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+28h] [bp-Ch]@41

  v3 = this;
  PStringBase<char>::PStringBase<char>(
    &header,
    "\nNote: You may substitute a forward slash (/) for the at symbol (@).\n\n");
  if ( argc > 0 )
  {
    PStringBase<char>::PStringBase<char>(&msg, "For more information, type @help <command>.\n");
    NextArg(&command, &argc, &argv);
    PStringBase<char>::PStringBase<char>(&v40, "/@");
    PStringBase<char>::trim(&command, 1, 0, v40);
    v28 = command.m_charbuffer;
    argc = (int)command.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&command.m_charbuffer[-1]);
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
      &v3->m_hashCommands,
      &result,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
    v6 = InterlockedDecrement;
    v29 = (int)&v28[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v29 + 4)) && v29 )
    {
      v30 = *(_DWORD *)v29;
      v40.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(int, signed int))v30)(v29, 1);
    }
    if ( result.m_currElement )
    {
      v31 = result.m_currElement->help;
      if ( v31 )
      {
        if ( v31(
               (ClientCommunicationSystem *)((char *)v3 + *((_DWORD *)&result.m_currElement->help + 1)),
               Detail_HelpType,
               command.m_charbuffer->m_data,
               &msg) )
        {
          ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &header, 0, 1, v3->m_idCurrentCommandSource);
          ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &msg, 0, 1, v3->m_idCurrentCommandSource);
        }
        else
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&argc,
            L"Unknown command");
          ClientSystem::AddTextToScroll(
            (ClientSystem *)&v3->vfptr,
            (PStringBase<unsigned short> *)&argc,
            0x1Au,
            1,
            v3->m_idCurrentCommandSource);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&argc);
        }
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&command);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&msg);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&header);
        return 1;
      }
    }
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&argc, L"Unknown command");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v33 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v33 )
    {
      v34 = *(_DWORD *)v33;
      v40.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(int, signed int))v34)(v33, 1);
    }
    v35 = &command.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&command.m_charbuffer[-1]) && v35 )
    {
      v36 = *(_DWORD *)v35;
      v40.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v36)(v35, 1);
    }
    v37 = &msg.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v37 )
    {
      v38 = *(_DWORD *)v37;
      v40.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v38)(v37, 1);
    }
    v27 = &header.m_charbuffer[-2].m_data[12];
    v40.m_charbuffer = header.m_charbuffer - 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&argc, "Available help:\n");
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argv,
      "@help allegiances - Commands to help you deal with your Allegiance.\n");
    v4 = argv;
    v5 = (int)*(argv - 1);
    if ( v5 != 1 )
    {
      PStringBase<char>::append_n_chars((PStringBase<char> *)&argc, (const char *)argv, v5 - 1);
      v4 = argv;
    }
    v6 = InterlockedDecrement;
    v7 = (int)(v4 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argv,
      "@help channels - How to communicate with people in your allegiance or fellowship.\n");
    v8 = argv;
    v9 = (int)*(argv - 1);
    if ( v9 != 1 )
    {
      PStringBase<char>::append_n_chars((PStringBase<char> *)&argc, (const char *)argv, v9 - 1);
      v8 = argv;
    }
    v10 = (int)(v8 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argv,
      "@help chatting - How to chat publically and privately.\n");
    v11 = argv;
    v12 = (int)*(argv - 1);
    if ( v12 != 1 )
    {
      PStringBase<char>::append_n_chars((PStringBase<char> *)&argc, (const char *)argv, v12 - 1);
      v11 = argv;
    }
    v13 = (int)(v11 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argv,
      "@help death - Commands for making, finding, and looting corpses.\n");
    v14 = argv;
    v15 = (int)*(argv - 1);
    if ( v15 != 1 )
    {
      PStringBase<char>::append_n_chars((PStringBase<char> *)&argc, (const char *)argv, v15 - 1);
      v14 = argv;
    }
    v16 = (int)(v14 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    ClientCommunicationSystem::HelpEmote(0, "@emote", (PStringBase<char> *)&argc);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argv,
      "@help fillcomps - A command to help you buy components in bulk.\n");
    v17 = argv;
    v18 = (int)*(argv - 1);
    if ( v18 != 1 )
    {
      PStringBase<char>::append_n_chars((PStringBase<char> *)&argc, (const char *)argv, v18 - 1);
      v17 = argv;
    }
    v19 = (int)(v17 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argv,
      "@help friends - Commands to help you manage your friends list.\n");
    v20 = argv;
    v21 = (int)*(argv - 1);
    if ( v21 != 1 )
    {
      PStringBase<char>::append_n_chars((PStringBase<char> *)&argc, (const char *)argv, v21 - 1);
      v20 = argv;
    }
    v22 = (int)(v20 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v22 + 4)) && v22 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&argv,
      "@help house - Commands that help you manage your house, including guest and storage management.\n");
    v23 = argv;
    v24 = (int)*(argv - 1);
    if ( v24 != 1 )
    {
      PStringBase<char>::append_n_chars((PStringBase<char> *)&argc, (const char *)argv, v24 - 1);
      v23 = argv;
    }
    v25 = (int)(v23 - 5);
    if ( !InterlockedDecrement((volatile LONG *)(v25 + 4)) && v25 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
    ClientCommunicationSystem::HelpSquelch(v3, 0, "@squelching", (PStringBase<char> *)&argc);
    ClientCommunicationSystem::HelpStatusGroup(v3, 0, "@status", (PStringBase<char> *)&argc);
    ClientCommunicationSystem::HelpTextGroup(v3, 0, "@text", (PStringBase<char> *)&argc);
    ClientCommunicationSystem::HelpAllGroup(v3, 0, "@commands", (PStringBase<char> *)&argc);
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      header.m_charbuffer->m_data,
      0,
      1,
      v3->m_idCurrentCommandSource);
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, (const char *)argc, 0, 1, v3->m_idCurrentCommandSource);
    v26 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v26 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
    v27 = &header.m_charbuffer[-2].m_data[12];
    v40.m_charbuffer = header.m_charbuffer - 1;
  }
  if ( !v6((volatile LONG *)v40.m_charbuffer) )
  {
    if ( v27 )
    {
      v39 = *(_DWORD *)v27;
      v40.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v39)(v27, 1);
    }
  }
  return 1;
}

//----- (0057FE80) --------------------------------------------------------  // acclient.c:425218
unsigned int __stdcall ClientCommunicationSystem::Handle_Communication__PopUpString(AC1Legacy::PStringBase<char> *msg)
{
  PStringBase<unsigned short> *v2; // eax@1
  char *v3; // esi@1
  BasePropertyDesc *v4; // ecx@11
  unsigned int v5; // esi@11
  BasePropertyValue *v6; // ecx@15
  unsigned int v7; // edx@15
  BaseProperty p; // [sp+14h] [bp-114h]@4
  PStringBase<unsigned short> v10; // [sp+1Ch] [bp-10Ch]@1
  PropertyCollection pc; // [sp+20h] [bp-108h]@4
  StringInfo popupString; // [sp+98h] [bp-90h]@1

  StringInfo::StringInfo(&popupString);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v10, 0, msg->m_buffer->m_data);
  StringInfo::SetLiteralValue(&popupString, v2, 1);
  v3 = (char *)&v10.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v10.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(3);
  }
  v10.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&v10,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC3u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  v10.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&v10,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&popupString);
  }
  v10.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&v10,
    &p);
  DialogFactory::MakeDialogInCurrentUI(&pc);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v4 = p.m_pcPropertyDesc;
    v5 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v6 = p.m_pcPropertyValue;
    v7 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&popupString);
  return 0;
}

//----- (00580050) --------------------------------------------------------  // acclient.c:425298
char __thiscall ClientCommunicationSystem::DoDie(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char *v4; // esi@2
  char *v6; // esi@5
  BasePropertyDesc *v7; // ecx@13
  unsigned int v8; // esi@13
  BasePropertyValue *v9; // ecx@17
  unsigned int v10; // edx@17
  PStringBase<unsigned short> i_text; // [sp+Ch] [bp-114h]@2
  BaseProperty p; // [sp+10h] [bp-110h]@8
  PropertyCollection pc; // [sp+18h] [bp-108h]@8
  StringInfo v14; // [sp+90h] [bp-90h]@5

  v3 = this;
  if ( argc )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &i_text,
      L"Please see @help die for more information on how to use this command.");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
    v4 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v4 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      return 1;
    }
  }
  else
  {
    StringInfo::StringInfo(&v14);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &i_text,
      L"Do you really want to kill your character? You may drop items and accrue a vitae penalty.");
    StringInfo::SetLiteralValue(&v14, &i_text, 1);
    v6 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
    }
    i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&i_text,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v14);
    }
    i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&i_text,
      &p);
    DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientCommunicationSystem::DieDialogCallback);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v7 = p.m_pcPropertyDesc;
      v8 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v9 = p.m_pcPropertyValue;
      v10 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&v14);
  }
  return 1;
}

//----- (00580240) --------------------------------------------------------  // acclient.c:425387
void __cdecl ClientCommunicationSystem::HouseAbandonDialogCallback_First(PropertyCollection *i_rcResults)
{
  unsigned int v1; // edx@1
  HashTableData<unsigned long,BaseProperty> **v2; // eax@1
  HashTableData<unsigned long,BaseProperty> *v3; // eax@1
  BasePropertyValue *v4; // ecx@6
  char *v5; // esi@9
  BasePropertyDesc *v6; // ecx@17
  unsigned int v7; // esi@17
  BasePropertyValue *v8; // ecx@21
  unsigned int v9; // edx@21
  BasePropertyDesc *v10; // ecx@26
  unsigned int v11; // edx@26
  int v12; // edx@30
  int v13; // [sp+10h] [bp-120h]@1
  BaseProperty _data; // [sp+14h] [bp-11Ch]@12
  PStringBase<unsigned short> _value; // [sp+1Ch] [bp-114h]@9
  BaseProperty p; // [sp+20h] [bp-110h]@1
  PropertyCollection pc; // [sp+28h] [bp-108h]@12
  StringInfo v18; // [sp+A0h] [bp-90h]@9

  v1 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v2 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  BYTE3(v13) = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v3 = v2[v1];
  if ( v3 )
  {
    while ( v3->m_hashKey != 146 )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      BaseProperty::operator=(&p, (int)&v3->m_data);
      v4 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(char *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)((char *)&v13 + 3);
        v4 = p.m_pcPropertyValue;
      }
      if ( BYTE3(v13) )
      {
        StringInfo::StringInfo(&v18);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &_value,
          L"Are you absolutely certain you wish to abandon your house? Click yes only if you are sure!");
        StringInfo::SetLiteralValue(&v18, &_value, 1);
        v5 = (char *)&_value.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v5 )
          (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
        PropertyCollection::PropertyCollection(&pc);
        _data.m_pcPropertyDesc = 0;
        _data.m_pcPropertyValue = 0;
        BaseProperty::SetPropertyName(&_data, 0x8Eu);
        if ( _data.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&_data);
          ((void (__stdcall *)(signed int))_data.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
        }
        _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&_data);
        HashTable<unsigned long,BaseProperty,1>::add(
          (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
          (const unsigned int *)&_value,
          &_data);
        BaseProperty::SetPropertyName(&_data, 0xC5u);
        if ( _data.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&_data);
          ((void (__stdcall *)(StringInfo *))_data.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v18);
        }
        _value.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&_data);
        HashTable<unsigned long,BaseProperty,1>::add(
          (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
          (const unsigned int *)&_value,
          &_data);
        DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientCommunicationSystem::HouseAbandonDialogCallback_Second);
        if ( (_DWORD)_data.m_pcPropertyDesc )
        {
          v6 = _data.m_pcPropertyDesc;
          v7 = _data.m_pcPropertyDesc->m_cRef - 1;
          _data.m_pcPropertyDesc->m_cRef = v7;
          if ( !v7 )
            ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
          _data.m_pcPropertyDesc = 0;
        }
        if ( _data.m_pcPropertyValue )
        {
          v8 = _data.m_pcPropertyValue;
          v9 = _data.m_pcPropertyValue->m_cRef - 1;
          _data.m_pcPropertyValue->m_cRef = v9;
          if ( !v9 )
            ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
          _data.m_pcPropertyValue = 0;
        }
        PropertyCollection::~PropertyCollection(&pc);
        StringInfo::~StringInfo(&v18);
        v4 = p.m_pcPropertyValue;
      }
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v10 = p.m_pcPropertyDesc;
        v11 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
        v4 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v4 )
      {
        v12 = v4->m_cRef - 1;
        v4->m_cRef = v12;
        if ( !v12 )
          ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (00580480) --------------------------------------------------------  // acclient.c:425511
char __thiscall ClientCommunicationSystem::Pose(ClientCommunicationSystem *this, PStringBase<char> *pose_txt)
{
  int v2; // ebx@1
  char v3; // al@2
  int v4; // eax@3
  unsigned int v5; // esi@3
  int v6; // edi@3
  SmartBox *v7; // edx@8
  InterfacePtr<Interface> *v8; // eax@10
  PlayerDesc *v9; // edi@12
  const char *v10; // eax@15
  Interface *v11; // esi@17
  PlayerDesc *v12; // esi@20
  AC1Legacy::PSRefBuffer<char> *v13; // edi@25
  PlayerDesc *v14; // esi@26
  AC1Legacy::PSRefBuffer<char> *v15; // esi@30
  AC1Legacy::PSRefBuffer<char> *v16; // esi@36
  char v17; // [sp+11h] [bp-131h]@1
  unsigned int gender; // [sp+12h] [bp-130h]@3
  AC1Legacy::PStringBase<char> otherEmote; // [sp+16h] [bp-12Ch]@3
  AC1Legacy::PStringBase<char> myEmote; // [sp+1Ah] [bp-128h]@3
  InterfacePtr<PlayerDesc> spPD; // [sp+1Eh] [bp-124h]@10
  AC1Legacy::PStringBase<char> cmdstring; // [sp+26h] [bp-11Ch]@3
  InterfacePtr<Interface> result; // [sp+2Ah] [bp-118h]@10
  ClientCommunicationSystem *v24; // [sp+32h] [bp-110h]@1
  CmdStruct cmdstruct; // [sp+36h] [bp-10Ch]@7

  v24 = this;
  v17 = 0;
  v2 = DBObj::GetByEnum(7, 2, 0x11u);
  if ( v2 )
  {
    cmdstring.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    myEmote.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    otherEmote.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&gender,
      pose_txt->m_charbuffer->m_data);
    v4 = ChatPoseTable::InqChatPoseCommand(
           (ChatPoseTable *)v2,
           (AC1Legacy::PStringBase<char> *)&gender,
           &cmdstring,
           &myEmote,
           &otherEmote);
    v5 = gender;
    v6 = v4;
    if ( !InterlockedDecrement((volatile LONG *)(gender + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    if ( v6 )
    {
      cmdstruct.size = 0;
      cmdstruct.curr = 0;
      cmdstruct.command = string2command(cmdstring.m_buffer->m_data);
      if ( cmdstruct.command )
      {
        v7 = SmartBox::smartbox;
        *(_DWORD *)&cmdstruct.args[cmdstruct.size] = 1;
        cmdstruct.size += 4;
        ((void (__stdcall *)(CmdStruct *))v7->cmdinterp->vfptr[12].OnLoseFocus)(&cmdstruct);
        v17 = 1;
      }
      if ( otherEmote.m_buffer->m_len != 1 )
      {
        gender = 1;
        v8 = GetClassObject(&result, &PlayerDesc_ClassType_30);
        InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&spPD, v8);
        if ( (_DWORD)result.m_pInterface )
          ((void (*)(void))result.m_pInterface->vfptr->Release)();
        v9 = spPD.m_pInterface;
        if ( (_DWORD)spPD.m_pInterface && (spPD.m_trStatus.m_val & 0x80000000) == 0 )
          CBaseQualities::InqInt((CBaseQualities *)&spPD.m_pInterface->vfptr, 0x71u, (int *)&gender, 0, 0);
        v10 = "his";
        if ( gender != 1 )
          v10 = "her";
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&spPD, v10);
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&result, "%p");
        AC1Legacy::PStringBase<char>::replace(
          &otherEmote,
          (AC1Legacy::PStringBase<char> *)&result,
          (AC1Legacy::PStringBase<char> *)&spPD);
        v11 = result.m_pInterface;
        if ( !InterlockedDecrement((volatile LONG *)&result.m_pInterface[1]) && v11 )
          ((void (__thiscall *)(_DWORD, _DWORD))v11->vfptr->IUnknown_QueryInterface)(v11, 1);
        v12 = spPD.m_pInterface;
        if ( !InterlockedDecrement((volatile LONG *)&spPD.m_pInterface->m_dataCategory) && v12 )
          ((void (__thiscall *)(_DWORD, _DWORD))v12->vfptr->IUnknown_QueryInterface)(v12, 1);
        CM_Communication::Event_SoulEmote(&otherEmote);
        if ( v9 )
          v9->vfptr->Release((Interface *)v9);
      }
      v13 = myEmote.m_buffer;
      if ( myEmote.m_buffer->m_len != 1 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&spPD, "You");
        ClientCommunicationSystem::Handle_Communication__HearSoulEmote(
          v24,
          0,
          (AC1Legacy::PStringBase<char> *)&spPD,
          &myEmote);
        v14 = spPD.m_pInterface;
        if ( !InterlockedDecrement((volatile LONG *)&spPD.m_pInterface->m_dataCategory) )
        {
          if ( v14 )
            ((void (__thiscall *)(_DWORD, _DWORD))v14->vfptr->IUnknown_QueryInterface)(v14, 1);
        }
      }
    }
    else
    {
      v13 = myEmote.m_buffer;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
    v15 = otherEmote.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&otherEmote.m_buffer->m_cRef) && v15 )
      v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
    if ( !InterlockedDecrement((volatile LONG *)&v13->m_cRef) && v13 )
      v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
    v16 = cmdstring.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&cmdstring.m_buffer->m_cRef) )
    {
      if ( v16 )
        v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
    }
    v3 = v17;
  }
  else
  {
    v3 = 0;
  }
  return v3;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00580740) --------------------------------------------------------  // acclient.c:425648
void __stdcall ClientCommunicationSystem::MakeLoadFileVariableSubstitutions(PStringBase<char> *lineStr)
{
  char *v2; // esi@1
  char *v3; // esi@4
  struct tm *v4; // eax@7
  char *v5; // esi@7
  char *v6; // esi@10
  PStringBase<char> str; // [sp+Ch] [bp-40Ch]@1
  PStringBase<char> search; // [sp+10h] [bp-408h]@1
  int currTime; // [sp+14h] [bp-404h]@7
  char time[1024]; // [sp+18h] [bp-400h]@7

  PStringBase<char>::PStringBase<char>(&str, &name);
  PStringBase<char>::PStringBase<char>(&search, "\n");
  PStringBase<char>::replace(lineStr, &search, &str);
  v2 = &search.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = &str.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  currTime = Timer::get_real_time();
  v4 = _localtime(&currTime);
  _strftime(time, 0x400u, "%Y-%m-%d-%a", v4);
  PStringBase<char>::PStringBase<char>(&search, time);
  PStringBase<char>::PStringBase<char>(&str, "%DATE%");
  PStringBase<char>::replace(lineStr, &str, &search);
  v5 = &str.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = &search.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1]) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}

//----- (00580860) --------------------------------------------------------  // acclient.c:425687
char __thiscall ClientCommunicationSystem::DoHouse(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // edi@1
  PSRefBufferCharData<char> *v4; // esi@1
  char *v5; // edi@2
  int v6; // esi@5
  int v8; // eax@9
  bool v9; // bl@9
  bool v10; // al@13
  bool v11; // bl@14
  int v12; // esi@14
  int v13; // eax@18
  bool v14; // bl@18
  int v15; // eax@23
  bool v16; // bl@23
  bool v17; // bl@27
  int v18; // ebx@28
  int v19; // ebx@30
  bool v20; // bl@31
  bool v21; // bl@34
  int v22; // ebx@36
  bool v23; // bl@37
  bool v24; // bl@40
  int v25; // ebx@41
  int v26; // ebx@42
  int v27; // ebx@44
  bool v28; // bl@45
  char v29; // bl@48
  int v30; // ebx@50
  bool v31; // bl@51
  bool v32; // bl@54
  int v33; // ebx@55
  int v34; // ebx@56
  int v35; // ebx@57
  int v36; // ebx@59
  int v37; // ebx@60
  int v38; // esi@61
  const unsigned __int16 *v39; // eax@62
  PSRefBufferCharData<char> *v40; // esi@62
  int v41; // ebx@62
  int v42; // esi@64
  bool v43; // al@63
  bool v44; // bl@66
  PStringBase<char> result; // [sp+Ch] [bp-11Ch]@9
  PStringBase<char> arg; // [sp+10h] [bp-118h]@1
  BaseProperty p; // [sp+14h] [bp-114h]@9
  PStringBase<unsigned short> i_text; // [sp+1Ch] [bp-10Ch]@1
  PropertyCollection pc; // [sp+20h] [bp-108h]@58
  StringInfo _value; // [sp+98h] [bp-90h]@58

  v3 = this;
  i_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  NextArg(&arg, &argc, &argv);
  v4 = arg.m_charbuffer;
  if ( *(_DWORD *)&arg.m_charbuffer[-1].m_data[12] == 1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &i_text,
      L"Please see @help House for more information on how to use this command");
    ClientSystem::AddTextToScroll((ClientSystem *)&v3->vfptr, &i_text, 0x1Au, 1, v3->m_idCurrentCommandSource);
    v5 = (char *)&i_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
    v6 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
    return 1;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "open");
  v8 = __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc);
  result.m_charbuffer = (PSRefBufferCharData<char> *)&p.m_pcPropertyDesc[-1].m_bRecorded;
  v9 = v8 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&p.m_pcPropertyDesc[-1].m_nMinElements) && result.m_charbuffer )
    (**(void (__stdcall ***)(_DWORD))&result.m_charbuffer->m_data[0])(1);
  if ( v9 )
  {
    v10 = CM_House::Event_SetOpenHouseStatus_Event(1);
    goto LABEL_14;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "close");
  v13 = __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc);
  result.m_charbuffer = (PSRefBufferCharData<char> *)&p.m_pcPropertyDesc[-1].m_bRecorded;
  v14 = v13 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&p.m_pcPropertyDesc[-1].m_nMinElements) && result.m_charbuffer )
    (**(void (__stdcall ***)(_DWORD))&result.m_charbuffer->m_data[0])(1);
  if ( !v14 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "recall");
    v15 = __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc);
    result.m_charbuffer = (PSRefBufferCharData<char> *)&p.m_pcPropertyDesc[-1].m_bRecorded;
    v16 = v15 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&p.m_pcPropertyDesc[-1].m_nMinElements) && result.m_charbuffer )
      (**(void (__stdcall ***)(_DWORD))&result.m_charbuffer->m_data[0])(1);
    if ( v16
      || (PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "re"),
          v18 = __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc),
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&p),
          !v18) )
    {
      v17 = ClientCommunicationSystem::DoHouseRecall((ClientCommunicationSystem *)i_text.m_charbuffer, argc, argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v17;
    }
    PStringBase<char>::PStringBase<char>(&result, "mansion_recall");
    v20 = 1;
    if ( __stricmp(v4->m_data, result.m_charbuffer->m_data) )
    {
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "alleg_recall");
      v19 = __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&p);
      if ( v19 )
        v20 = 0;
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    if ( v20 )
    {
      v21 = ClientCommunicationSystem::DoMansionRecall((ClientCommunicationSystem *)i_text.m_charbuffer, argc, argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v21;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "ma");
    v23 = 1;
    if ( __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc) )
    {
      PStringBase<char>::PStringBase<char>(&result, "alleg_recall");
      v22 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( v22 )
        v23 = 0;
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&p);
    if ( v23 )
    {
      v24 = ClientCommunicationSystem::DoMansionRecall((ClientCommunicationSystem *)i_text.m_charbuffer, argc, argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v24;
    }
    PStringBase<char>::PStringBase<char>(&result, "storage");
    v25 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    if ( !v25 )
    {
      v26 = (unsigned __int8)ClientCommunicationSystem::DoHouseStorage(
                               (ClientCommunicationSystem *)i_text.m_charbuffer,
                               argc,
                               argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v26;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "remove");
    v28 = 1;
    if ( __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc) )
    {
      PStringBase<char>::PStringBase<char>(&result, "boot");
      v27 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( v27 )
        v28 = 0;
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&p);
    if ( v28 )
    {
      v29 = ClientCommunicationSystem::DoHouseBoot((ClientCommunicationSystem *)i_text.m_charbuffer, argc, argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v29;
    }
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&p, "boot_all");
    v31 = 1;
    if ( __stricmp(v4->m_data, (const char *)p.m_pcPropertyDesc) )
    {
      PStringBase<char>::PStringBase<char>(&result, "remove_all");
      v30 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( v30 )
        v31 = 0;
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&p);
    if ( v31 )
    {
      v32 = CM_House::Event_BootEveryone_Event();
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v32;
    }
    PStringBase<char>::PStringBase<char>(&result, "guest");
    v33 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    if ( !v33 )
    {
      v34 = (unsigned __int8)ClientCommunicationSystem::DoHouseGuests(
                               (ClientCommunicationSystem *)i_text.m_charbuffer,
                               argc,
                               argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v34;
    }
    PStringBase<char>::PStringBase<char>(&result, "abandon");
    v35 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    if ( !v35 )
    {
      StringInfo::StringInfo(&_value);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&result,
        L"Do you really want to abandon your house? Any items in the house (on hooks or in storage) will stay with the house, and you will lose access to them.");
      StringInfo::SetLiteralValue(&_value, (PStringBase<unsigned short> *)&result, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      PropertyCollection::PropertyCollection(&pc);
      p.m_pcPropertyDesc = 0;
      p.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&p, 0x8Eu);
      BaseProperty::SetEnum(&p, 1u);
      PropertyCollection::AddProperty(&pc, &p);
      BaseProperty::SetPropertyName(&p, 0xC5u);
      BaseProperty::SetStringInfo(&p, &_value);
      PropertyCollection::AddProperty(&pc, &p);
      DialogFactory::MakeCallbackDialogInCurrentUI(&pc, ClientCommunicationSystem::HouseAbandonDialogCallback_First);
      BaseProperty::~BaseProperty(&p);
      PropertyCollection::~PropertyCollection(&pc);
      StringInfo::~StringInfo(&_value);
LABEL_68:
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return 1;
    }
    PStringBase<char>::PStringBase<char>(&result, "available");
    v36 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    if ( !v36 )
    {
      v37 = (unsigned __int8)ClientCommunicationSystem::DoHouseAvailableList(
                               (ClientCommunicationSystem *)i_text.m_charbuffer,
                               argc,
                               argv);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
      return v37;
    }
    PStringBase<char>::PStringBase<char>(&result, "hooks");
    v38 = __stricmp(v4->m_data, result.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    if ( !v38 )
    {
      v39 = (const unsigned __int16 *)NextArg(&result, &argc, &argv);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&arg, v39);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      PStringBase<char>::PStringBase<char>(&result, "on");
      v40 = arg.m_charbuffer;
      v41 = __stricmp(arg.m_charbuffer->m_data, result.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( !v41 )
      {
        v43 = CM_House::Event_SetHooksVisibility(1);
LABEL_66:
        v44 = v43;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&arg);
        return v44;
      }
      PStringBase<char>::PStringBase<char>(&result, "off");
      v42 = __stricmp(v40->m_data, result.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      if ( !v42 )
      {
        v43 = CM_House::Event_SetHooksVisibility(0);
        goto LABEL_66;
      }
    }
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&result,
      L"Please see @help House for more information on how to use this command");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)i_text.m_charbuffer,
      (PStringBase<unsigned short> *)&result,
      0x1Au,
      1,
      *(_DWORD *)&i_text.m_charbuffer[4].m_data[6]);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    goto LABEL_68;
  }
  v10 = CM_House::Event_SetOpenHouseStatus_Event(0);
LABEL_14:
  v11 = v10;
  v12 = (int)&v4[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  return v11;
}

//----- (00580FD0) --------------------------------------------------------  // acclient.c:425976
void __thiscall ClientCommunicationSystem::RemoveTextBetween(ClientCommunicationSystem *this, PStringBaseIter<char> *iter, char first, char second)
{
  ClientCommunicationSystem *v4; // ebx@1
  unsigned int v5; // edi@2
  unsigned int v6; // edi@5
  unsigned int v7; // edi@11
  unsigned int v8; // eax@14
  char *v9; // esi@17
  PStringBase<char> emoteStr; // [sp+0h] [bp-4h]@1

  emoteStr.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter->vfptr, first, 0) )
  {
    v5 = iter->curr + 1;
    iter->curr = v5 <= iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)iter) ? v5 : iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)iter);
    v6 = iter->curr;
    if ( PStringBaseIter_Common<char>::FindChar((PStringBaseIter_Common<char> *)&iter->vfptr, second, 0) )
    {
      iter->mark = v6 <= iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)iter) ? v6 : iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)iter);
      if ( PStringBaseIter_Common<char>::GetSubString((PStringBaseIter_Common<char> *)&iter->vfptr, &emoteStr)
        && ClientCommunicationSystem::Pose(v4, &emoteStr) )
      {
        PStringBaseIter_Common<unsigned short>::SetMark((PStringBaseIter_Common<unsigned short> *)iter, iter->mark - 1);
        v7 = iter->curr + 1;
        if ( v7 <= iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)iter) )
          iter->curr = v7;
        else
          iter->curr = iter->vfptr->GetStrLen((PStringBaseIter_Common<char> *)iter);
        PStringBaseIter<char>::Replace(iter, &PStringBase<char>::s_NullBuffer);
        v8 = iter->curr;
        if ( v8 >= 1 )
          iter->curr = v8 - 1;
        else
          iter->curr = 0;
      }
    }
  }
  v9 = &emoteStr.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&emoteStr.m_charbuffer[-1]) )
  {
    if ( v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
}

//----- (005810F0) --------------------------------------------------------  // acclient.c:426024
void __thiscall ClientCommunicationSystem::PublicChat(ClientCommunicationSystem *this, PStringBase<char> *input)
{
  PStringBase<char> *v2; // ebp@1
  ClientCommunicationSystem *v3; // edi@1
  unsigned int v4; // esi@2
  unsigned int v5; // ebx@2
  unsigned int v6; // esi@8
  PStringBase<char> v7; // ST08_4@12
  PStringBase<char> *v8; // esi@13
  PStringBaseIter<char> iter; // [sp+10h] [bp-10h]@1

  v2 = input;
  v3 = this;
  iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
  iter.pstring_ptr = input;
  iter.curr = 0;
  iter.mark = 0;
  if ( PStringBaseIter_Const<char>::IndexToChar(&iter, 0) )
  {
    do
    {
      v4 = iter.curr;
      v5 = iter.mark;
      ClientCommunicationSystem::RemoveTextBetween(v3, &iter, 42, 42);
      if ( v4 <= iter.vfptr->GetStrLen(&iter) )
        iter.curr = v4;
      else
        iter.curr = iter.vfptr->GetStrLen(&iter);
      if ( v5 <= iter.vfptr->GetStrLen(&iter) )
        iter.mark = v5;
      else
        iter.mark = iter.vfptr->GetStrLen(&iter);
      ClientCommunicationSystem::RemoveTextBetween(v3, &iter, 60, 62);
      v6 = iter.curr;
      if ( v6 <= iter.vfptr->GetStrLen(&iter) )
        iter.mark = v6;
      else
        iter.mark = iter.vfptr->GetStrLen(&iter);
    }
    while ( iter.vfptr->IndexToChar((PStringBaseIter_Common<char> *)&iter, iter.curr) );
  }
  v7.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
  PStringBase<char>::trim(v2, 1, 1, v7);
  if ( *(_DWORD *)&v2->m_charbuffer[-1].m_data[12] != 1 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&input, v2->m_charbuffer->m_data);
    CM_Communication::Event_Talk((AC1Legacy::PStringBase<char> *)&input);
    v8 = input;
    if ( !InterlockedDecrement((volatile LONG *)&input[1]) )
    {
      if ( v8 )
        (*(void (__thiscall **)(_DWORD, _DWORD))&v8->m_charbuffer->m_data[0])(v8, 1);
    }
  }
}
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (00581240) --------------------------------------------------------  // acclient.c:426083
char __thiscall ClientCommunicationSystem::DoSay(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  PStringBase<char> v4; // ST0C_4@1
  int v5; // esi@2
  char **v6; // esi@5
  LONG v7; // eax@5

  v3 = this;
  JoinArgs((PStringBase<char> *)&argv, argc, argv);
  v4.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
  PStringBase<char>::trim((PStringBase<char> *)&argv, 1, 1, v4);
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argc,
      L"You must specify the text you wish to say!");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argc,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v5 = argc - 20;
    if ( !InterlockedDecrement((volatile LONG *)(argc - 20 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = argv - 5;
    v7 = InterlockedDecrement((volatile LONG *)argv - 4);
  }
  else
  {
    ClientCommunicationSystem::PublicChat(v3, (PStringBase<char> *)&argv);
    v6 = argv - 5;
    v7 = InterlockedDecrement((volatile LONG *)argv - 4);
  }
  if ( !v7 && v6 )
    (*(void (__thiscall **)(_DWORD, _DWORD))*v6)(v6, 1);
  return 1;
}

//----- (00581320) --------------------------------------------------------  // acclient.c:426125
char __thiscall ClientCommunicationSystem::OnChatCommand(ClientCommunicationSystem *this, PStringBase<unsigned short> *i_strLine, unsigned int i_idCommandSource)
{
  ClientCommunicationSystem *v3; // edi@1
  int v4; // eax@1
  PStringBase<unsigned short> *v5; // esi@1
  BSTR v6; // ebx@2
  IACPlugin *v7; // eax@2
  PStringBase<char> *v8; // ebx@3
  PSRefBufferCharData<char> *v9; // eax@3
  const char **v10; // esi@3
  int v11; // ebp@4
  PSRefBufferCharData<char> *v12; // ebx@7
  PStringBase<unsigned short> *v13; // ebx@8
  PStringBase<char> v14; // ST0C_4@11
  const char *v15; // eax@11
  PStringBase<char> *v17; // eax@16
  const unsigned __int16 *v18; // eax@16
  PStringBase<unsigned short> *v19; // esi@16
  unsigned int v20; // esi@19
  unsigned int v21; // eax@23
  unsigned int v22; // edi@27
  PlayerModule *v23; // eax@33
  int v24; // eax@33
  ChatDisplayInfo *v25; // eax@34
  ChatRoomTracker *v26; // eax@35
  ChatRoomTracker *v27; // eax@36
  ChatRoomTracker *v28; // eax@37
  ChatRoomTracker *v29; // eax@38
  unsigned int v30; // ebx@38
  int v31; // eax@38
  ChatRoomTracker *v32; // eax@39
  unsigned int v33; // ebx@40
  CPlayerSystem *v34; // eax@40
  char v35; // al@40
  AC1Legacy::PStringBase<char> i_msg; // [sp+14h] [bp-Ch]@30
  AC1Legacy::PStringBase<char> v37; // [sp+18h] [bp-8h]@31
  AC1Legacy::PStringBase<char> v38; // [sp+1Ch] [bp-4h]@32

  v3 = this;
  v4 = APIManager::APIIsReady();
  v5 = i_strLine;
  if ( !v4
    || (v6 = SysAllocString(i_strLine->m_charbuffer->m_data),
        i_strLine = 0,
        v7 = APIManager::GetACPlugin(),
        ((void (__stdcall *)(IACPlugin *, BSTR, PStringBase<unsigned short> **))v7->vfptr[2].Release)(
          v7,
          v6,
          &i_strLine),
        !i_strLine) )
  {
    v3->m_idCurrentCommandSource = i_idCommandSource;
    v8 = PStringBase<unsigned short>::to_spstring(v5, (PStringBase<char> *)&i_strLine, 0);
    v9 = v3->m_strLastCommandLine.m_charbuffer;
    v10 = (const char **)&v3->m_strLastCommandLine;
    if ( v9 != v8->m_charbuffer )
    {
      v11 = (int)&v9[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = v8->m_charbuffer;
      *v10 = (const char *)v12;
      InterlockedIncrement((volatile LONG *)&v12[-1]);
    }
    v13 = i_strLine - 5;
    if ( !InterlockedDecrement((volatile LONG *)&i_strLine[-4]) && v13 )
      (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v13->m_charbuffer->m_data[0])(v13, 1);
    v14.m_charbuffer = PStringBase<char>::whitespace_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::whitespace_string.m_charbuffer[-1]);
    PStringBase<char>::trim(&v3->m_strLastCommandLine, 1, 1, v14);
    v15 = *v10;
    if ( !*((_DWORD *)*v10 - 1) )
      --v15;
    switch ( *v15 )
    {
      case 47:
        PStringBase<char>::SetAtIndex(&v3->m_strLastCommandLine, 0, 64);
        return ClientCommunicationSystem::DoCommand(v3);
      case 64:
        return ClientCommunicationSystem::DoCommand(v3);
      case 58:
      case 59:
        PStringBase<char>::SetAtIndex(&v3->m_strLastCommandLine, 0, 32);
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_idCommandSource, "@emote");
        v18 = (const unsigned __int16 *)PStringBase<char>::operator+(
                                          v17,
                                          (PStringBase<char> *)&i_strLine,
                                          &v3->m_strLastCommandLine);
        PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&v3->m_strLastCommandLine, v18);
        v19 = i_strLine - 5;
        if ( !InterlockedDecrement((volatile LONG *)&i_strLine[-4]) && v19 )
          (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v19->m_charbuffer->m_data[0])(v19, 1);
        v20 = i_idCommandSource - 20;
        if ( !InterlockedDecrement((volatile LONG *)(i_idCommandSource - 20 + 4)) )
        {
          if ( v20 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
        }
        return ClientCommunicationSystem::DoCommand(v3);
      default:
        v21 = v3->m_idCurrentCommandSource;
        if ( v21 != 1 && v21 != 8 )
        {
$L192338:
          ClientCommunicationSystem::PublicChat(v3, &v3->m_strLastCommandLine);
          return 1;
        }
        switch ( gmCCommunicationSystem::GetTalkFocus() )
        {
          case 1u:
            goto $L192338;
          case 2u:
            v22 = gmCCommunicationSystem::GetLastSpeakableTarget();
            if ( !v22 )
              return 1;
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&i_strLine, *v10);
            CM_Communication::Event_TalkDirect((AC1Legacy::PStringBase<char> *)&i_strLine, v22);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&i_strLine);
            return 1;
          case 3u:
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&i_idCommandSource, *v10);
            CM_Communication::Event_ChannelBroadcast(0x800u, (AC1Legacy::PStringBase<char> *)&i_idCommandSource);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&i_idCommandSource);
            return 1;
          case 4u:
            AC1Legacy::PStringBase<char>::PStringBase<char>(&i_msg, *v10);
            CM_Communication::Event_ChannelBroadcast(0x2000u, &i_msg);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&i_msg);
            return 1;
          case 5u:
            AC1Legacy::PStringBase<char>::PStringBase<char>(&v37, *v10);
            CM_Communication::Event_ChannelBroadcast(0x4000u, &v37);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v37);
            return 1;
          case 6u:
            AC1Legacy::PStringBase<char>::PStringBase<char>(&v38, *v10);
            CM_Communication::Event_ChannelBroadcast(0x1000u, &v38);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v38);
            return 1;
          case 7u:
            v23 = (PlayerModule *)gmCCommunicationSystem::GetChatRoomTracker();
            v24 = (int)CInputManager::GetMouseX(v23);
            goto LABEL_40;
          case 8u:
            v25 = (ChatDisplayInfo *)gmCCommunicationSystem::GetChatRoomTracker();
            v24 = HookAppraisalProfile::GetValidLocations(v25);
            goto LABEL_40;
          case 9u:
            v26 = gmCCommunicationSystem::GetChatRoomTracker();
            v24 = ChatRoomTracker::GetGlobalTradeRoomID(v26);
            goto LABEL_40;
          case 0xAu:
            v27 = gmCCommunicationSystem::GetChatRoomTracker();
            v24 = PhysicsDesc::get_autonomous_movement(v27);
            goto LABEL_40;
          case 0xBu:
            v28 = gmCCommunicationSystem::GetChatRoomTracker();
            v24 = PhysicsDesc::get_animframe_id(v28);
            goto LABEL_40;
          case 0xDu:
            v29 = gmCCommunicationSystem::GetChatRoomTracker();
            v30 = AnimSequenceNode::get_high_frame(v29);
            v31 = CPlayerSystem::IsOlthoi();
            ClientCommunicationSystem::SendTurbineChat(
              v3,
              v30,
              Olthoi_ChatTypeEnum,
              &v3->m_strLastCommandLine,
              v31 != 0);
            return 1;
          case 0xCu:
            v32 = gmCCommunicationSystem::GetChatRoomTracker();
            v24 = ChatRoomTracker::GetGlobalSocietyRoomID(v32);
LABEL_40:
            v33 = v24;
            v34 = CPlayerSystem::GetPlayerSystem();
            v35 = PlayerModule::HearAllegianceChat((PlayerModule *)&v34->playerModule.vfptr);
            ClientCommunicationSystem::SendTurbineChat(v3, v33, Allegiance_ChatTypeEnum, &v3->m_strLastCommandLine, v35);
            break;
          default:
            return 1;
        }
        return 1;
    }
  }
  return 1;
}

//----- (00581710) --------------------------------------------------------  // acclient.c:426314
char __thiscall ClientCommunicationSystem::LoadFile(ClientCommunicationSystem *this, PStringBase<char> *fileName)
{
  ClientCommunicationSystem *v2; // esi@1
  FILE *v3; // ebp@1
  char v4; // al@2
  unsigned int v5; // ST10_4@4
  PStringBase<unsigned short> *v6; // eax@4
  char *v7; // edi@4
  unsigned int v8; // ST10_4@7
  PStringBase<unsigned short> *v9; // eax@7
  char *v10; // edi@7
  char *v11; // esi@11
  PStringBase<char> lineStr; // [sp+8h] [bp-40Ch]@3
  PStringBase<unsigned short> result; // [sp+Ch] [bp-408h]@4
  PStringBase<unsigned short> v14; // [sp+10h] [bp-404h]@7
  char line[1024]; // [sp+14h] [bp-400h]@3

  v2 = this;
  v3 = _fopen(fileName->m_charbuffer->m_data, "rt");
  if ( v3 )
  {
    lineStr.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    while ( _fgets(line, 1024, v3) )
    {
      PStringBase<char>::set(&lineStr, line);
      ClientCommunicationSystem::MakeLoadFileVariableSubstitutions(&lineStr);
      v5 = v2->m_idCurrentCommandSource;
      v6 = PStringBase<char>::to_wpstring(&lineStr, &result, 0);
      ClientSystem::AddTextToScroll((ClientSystem *)&v2->vfptr, v6, 0, 1, v5);
      v7 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = v2->m_idCurrentCommandSource;
      v9 = PStringBase<char>::to_wpstring(&lineStr, &v14, 0);
      ClientCommunicationSystem::OnChatCommand(v2, v9, v8);
      v10 = (char *)&v14.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v14.m_charbuffer[-1].m_data[8]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    _fclose(v3);
    v11 = &lineStr.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&lineStr.m_charbuffer[-1]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  return v4;
}

//----- (00581870) --------------------------------------------------------  // acclient.c:426371
char __thiscall ClientCommunicationSystem::DoLoadFile(ClientCommunicationSystem *this, int argc, char **argv)
{
  ClientCommunicationSystem *v3; // esi@1
  char **v4; // ebx@1
  char **v5; // esi@2
  int v6; // esi@5
  char **v7; // esi@7
  LONG v8; // eax@5

  v3 = this;
  JoinArgs((PStringBase<char> *)&argv, argc, argv);
  v4 = argv;
  if ( *(argv - 1) == (char *)1 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&argv,
      L"You must provide a file name.");
    ClientSystem::AddTextToScroll(
      (ClientSystem *)&v3->vfptr,
      (PStringBase<unsigned short> *)&argv,
      0x1Au,
      1,
      v3->m_idCurrentCommandSource);
    v5 = argv - 5;
    if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v5 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v5)(v5, 1);
    v6 = (int)(v4 - 5);
    v8 = InterlockedDecrement((volatile LONG *)v4 - 4);
  }
  else
  {
    if ( !ClientCommunicationSystem::LoadFile(v3, (PStringBase<char> *)&argv) )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&argv,
        0,
        L"Cannot open file %hs",
        v4);
      ClientSystem::AddTextToScroll(
        (ClientSystem *)&v3->vfptr,
        (PStringBase<unsigned short> *)&argv,
        0x1Au,
        1,
        v3->m_idCurrentCommandSource);
      v7 = argv - 5;
      if ( !InterlockedDecrement((volatile LONG *)argv - 4) )
      {
        if ( v7 )
          (*(void (__thiscall **)(_DWORD, _DWORD))*v7)(v7, 1);
      }
    }
    v6 = (int)(v4 - 5);
    v8 = InterlockedDecrement((volatile LONG *)v4 - 4);
  }
  if ( !v8 && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 1;
}

//----- (00581970) --------------------------------------------------------  // acclient.c:426431
void __thiscall ClientCommunicationSystem::InitializeCommands(ClientCommunicationSystem *this)
{
  signed int v1; // ebx@1
  void *v2; // esi@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v3; // ebp@4
  char *v4; // esi@7
  void *v5; // esi@10
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v6; // edx@11
  char *v7; // esi@16
  void *v8; // esi@19
  char *v9; // esi@25
  void *v10; // esi@28
  char *v11; // esi@34
  void *v12; // esi@37
  char *v13; // esi@43
  void *v14; // esi@46
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v15; // edx@47
  char *v16; // esi@52
  void *v17; // esi@55
  char *v18; // esi@61
  void *v19; // esi@64
  char *v20; // esi@70
  void *v21; // esi@73
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v22; // edx@74
  char *v23; // esi@79
  void *v24; // esi@82
  char *v25; // esi@88
  void *v26; // esi@91
  char *v27; // esi@97
  void *v28; // esi@100
  char *v29; // esi@106
  void *v30; // esi@109
  char *v31; // esi@115
  void *v32; // esi@118
  char *v33; // esi@124
  void *v34; // esi@127
  char *v35; // esi@133
  void *v36; // esi@136
  char *v37; // esi@142
  void *v38; // esi@145
  char *v39; // esi@151
  void *v40; // esi@154
  char *v41; // esi@160
  void *v42; // esi@163
  char *v43; // esi@169
  void *v44; // esi@172
  char *v45; // esi@178
  void *v46; // esi@181
  char *v47; // esi@187
  void *v48; // esi@190
  char *v49; // esi@196
  ClientCommunicationSystem::CmdHashData *v50; // eax@200
  char *v51; // esi@203
  ClientCommunicationSystem::CmdHashData *v52; // eax@207
  char *v53; // esi@210
  ClientCommunicationSystem::CmdHashData *v54; // eax@214
  char *v55; // esi@217
  ClientCommunicationSystem::CmdHashData *v56; // eax@221
  char *v57; // esi@224
  ClientCommunicationSystem::CmdHashData *v58; // eax@228
  char *v59; // esi@231
  ClientCommunicationSystem::CmdHashData *v60; // eax@235
  char *v61; // esi@238
  ClientCommunicationSystem::CmdHashData *v62; // eax@242
  char *v63; // esi@245
  ClientCommunicationSystem::CmdHashData *v64; // eax@249
  char *v65; // esi@252
  ClientCommunicationSystem::CmdHashData *v66; // eax@256
  char *v67; // esi@259
  ClientCommunicationSystem::CmdHashData *v68; // eax@263
  char *v69; // esi@266
  ClientCommunicationSystem::CmdHashData *v70; // ebx@270
  ClientCommunicationSystem::CmdHashData *v71; // eax@270
  char *v72; // esi@273
  ClientCommunicationSystem::CmdHashData *v73; // eax@277
  char *v74; // esi@280
  ClientCommunicationSystem::CmdHashData *v75; // eax@284
  char *v76; // esi@287
  ClientCommunicationSystem::CmdHashData *v77; // eax@291
  char *v78; // esi@294
  ClientCommunicationSystem::CmdHashData *v79; // eax@298
  char *v80; // esi@301
  ClientCommunicationSystem::CmdHashData *v81; // eax@305
  char *v82; // esi@308
  ClientCommunicationSystem::CmdHashData *v83; // eax@312
  char *v84; // esi@315
  ClientCommunicationSystem::CmdHashData *v85; // eax@319
  char *v86; // esi@322
  ClientCommunicationSystem::CmdHashData *v87; // eax@326
  char *v88; // esi@329
  ClientCommunicationSystem::CmdHashData *v89; // eax@333
  char *v90; // esi@336
  ClientCommunicationSystem::CmdHashData *v91; // eax@340
  char *v92; // esi@343
  ClientCommunicationSystem::CmdHashData *v93; // eax@347
  char *v94; // esi@350
  ClientCommunicationSystem::CmdHashData *v95; // eax@354
  char *v96; // esi@357
  ClientCommunicationSystem::CmdHashData *v97; // eax@361
  char *v98; // esi@364
  ClientCommunicationSystem::CmdHashData *v99; // eax@368
  char *v100; // esi@371
  ClientCommunicationSystem::CmdHashData *v101; // eax@375
  char *v102; // esi@378
  ClientCommunicationSystem::CmdHashData *v103; // eax@382
  char *v104; // esi@385
  ClientCommunicationSystem::CmdHashData *v105; // eax@389
  char *v106; // esi@392
  ClientCommunicationSystem::CmdHashData *v107; // eax@396
  char *v108; // esi@399
  ClientCommunicationSystem::CmdHashData *v109; // eax@403
  char *v110; // esi@406
  ClientCommunicationSystem::CmdHashData *v111; // eax@410
  char *v112; // esi@413
  ClientCommunicationSystem::CmdHashData *v113; // eax@417
  char *v114; // esi@420
  ClientCommunicationSystem::CmdHashData *v115; // eax@424
  char *v116; // esi@427
  ClientCommunicationSystem::CmdHashData *v117; // eax@431
  char *v118; // esi@434
  ClientCommunicationSystem::CmdHashData *v119; // eax@438
  char *v120; // esi@441
  ClientCommunicationSystem::CmdHashData *v121; // eax@445
  char *v122; // esi@448
  ClientCommunicationSystem::CmdHashData *v123; // eax@452
  char *v124; // esi@455
  ClientCommunicationSystem::CmdHashData *v125; // eax@459
  char *v126; // esi@462
  ClientCommunicationSystem::CmdHashData *v127; // eax@466
  char *v128; // esi@469
  ClientCommunicationSystem::CmdHashData *v129; // eax@473
  char *v130; // esi@476
  ClientCommunicationSystem::CmdHashData *v131; // eax@480
  char *v132; // esi@483
  ClientCommunicationSystem::CmdHashData *v133; // eax@487
  char *v134; // esi@490
  ClientCommunicationSystem::CmdHashData *v135; // ebx@494
  ClientCommunicationSystem::CmdHashData *v136; // eax@494
  char *v137; // esi@497
  ClientCommunicationSystem::CmdHashData *v138; // eax@501
  char *v139; // esi@504
  ClientCommunicationSystem::CmdHashData *v140; // eax@508
  char *v141; // esi@511
  ClientCommunicationSystem::CmdHashData *v142; // eax@515
  char *v143; // esi@518
  ClientCommunicationSystem::CmdHashData *v144; // eax@522
  char *v145; // esi@525
  ClientCommunicationSystem::CmdHashData *v146; // eax@529
  char *v147; // esi@532
  ClientCommunicationSystem::CmdHashData *v148; // eax@536
  char *v149; // esi@539
  ClientCommunicationSystem::CmdHashData *v150; // eax@543
  char *v151; // esi@546
  ClientCommunicationSystem::CmdHashData *v152; // eax@550
  char *v153; // esi@553
  ClientCommunicationSystem::CmdHashData *v154; // eax@557
  char *v155; // esi@560
  ClientCommunicationSystem::CmdHashData *v156; // eax@564
  char *v157; // esi@567
  ClientCommunicationSystem::CmdHashData *v158; // eax@571
  char *v159; // esi@574
  ClientCommunicationSystem::CmdHashData *v160; // eax@578
  char *v161; // esi@581
  ClientCommunicationSystem::CmdHashData *v162; // eax@585
  char *v163; // esi@588
  ClientCommunicationSystem::CmdHashData *v164; // eax@592
  char *v165; // esi@595
  ClientCommunicationSystem::CmdHashData *v166; // eax@599
  char *v167; // esi@602
  ClientCommunicationSystem::CmdHashData *v168; // eax@606
  char *v169; // esi@609
  ClientCommunicationSystem::CmdHashData *v170; // eax@613
  char *v171; // esi@616
  ClientCommunicationSystem::CmdHashData *v172; // eax@620
  char *v173; // esi@623
  ClientCommunicationSystem::CmdHashData *v174; // eax@627
  char *v175; // esi@630
  ClientCommunicationSystem::CmdHashData *v176; // eax@634
  char *v177; // esi@637
  ClientCommunicationSystem::CmdHashData *v178; // eax@641
  char *v179; // esi@644
  ClientCommunicationSystem::CmdHashData *v180; // eax@648
  char *v181; // esi@651
  ClientCommunicationSystem::CmdHashData *v182; // eax@655
  char *v183; // esi@658
  ClientCommunicationSystem::CmdHashData *v184; // eax@662
  char *v185; // esi@665
  ClientCommunicationSystem::CmdHashData *v186; // eax@669
  char *v187; // esi@672
  ClientCommunicationSystem::CmdHashData *v188; // eax@676
  char *v189; // esi@679
  ClientCommunicationSystem::CmdHashData *v190; // eax@683
  ClientCommunicationSystem::CmdHashData *v191; // eax@688
  ClientCommunicationSystem::CmdHashData *v192; // eax@693
  ClientCommunicationSystem::CmdHashData *v193; // eax@698
  ClientCommunicationSystem::CmdHashData *v194; // eax@703
  ClientCommunicationSystem::CmdHashData *v195; // ebx@708
  ClientCommunicationSystem::CmdHashData *v196; // eax@708
  ClientCommunicationSystem::CmdHashData *v197; // eax@713
  ClientCommunicationSystem::CmdHashData *v198; // eax@718
  ClientCommunicationSystem::CmdHashData *v199; // eax@723
  ClientCommunicationSystem::CmdHashData *v200; // eax@728
  ClientCommunicationSystem::CmdHashData *v201; // eax@733
  ClientCommunicationSystem::CmdHashData *v202; // eax@738
  ClientCommunicationSystem::CmdHashData *v203; // eax@743
  ClientCommunicationSystem::CmdHashData *v204; // eax@748
  ClientCommunicationSystem::CmdHashData *v205; // eax@753
  ClientCommunicationSystem::CmdHashData *v206; // eax@758
  ClientCommunicationSystem::CmdHashData *v207; // eax@763
  ClientCommunicationSystem::CmdHashData *v208; // eax@768
  ClientCommunicationSystem::CmdHashData *v209; // eax@773
  ClientCommunicationSystem::CmdHashData *v210; // eax@778
  ClientCommunicationSystem::CmdHashData *v211; // eax@783
  ClientCommunicationSystem::CmdHashData *v212; // eax@788
  ClientCommunicationSystem::CmdHashData *v213; // eax@793
  ClientCommunicationSystem::CmdHashData *v214; // eax@798
  ClientCommunicationSystem::CmdHashData *v215; // eax@803
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v216; // [sp+16Ch] [bp-24h]@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v217; // [sp+16Ch] [bp-24h]@4
  PStringBase<char> v218; // [sp+170h] [bp-20h]@2
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+174h] [bp-1Ch]@4
  ClientCommunicationSystem::CmdHashData *v220; // [sp+180h] [bp-10h]@1
  ClientCommunicationSystem::CmdHashData *v221; // [sp+184h] [bp-Ch]@1
  int v222; // [sp+188h] [bp-8h]@803
  ClientCommunicationSystem::CmdHashData *v223; // [sp+18Ch] [bp-4h]@1

  v1 = 0;
  v216 = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)this;
  v220 = 0;
  v221 = 0;
  v223 = 0;
  v2 = operator new(0x18u);
  if ( v2 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "?");
    *(_DWORD *)v2 = v218.m_charbuffer;
    v1 = 1;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v2 + 2) = ClientCommunicationSystem::DoHelp;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 3) = 0;
    *((_DWORD *)v2 + 4) = 0;
    *((_DWORD *)v2 + 5) = 0;
  }
  else
  {
    v2 = 0;
  }
  v3 = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)((char *)v216 + 20);
  v217 = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)((char *)v216 + 20);
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v217,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v2);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v2);
  if ( v1 & 1 )
  {
    v4 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFFFE;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
  }
  v5 = operator new(0x18u);
  if ( v5 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoHelp;
    PStringBase<char>::PStringBase<char>(&v218, "help");
    *(_DWORD *)v5 = v218.m_charbuffer;
    v1 |= 2u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    v6 = result.m_currHashTable;
    *((_DWORD *)v5 + 1) = 0;
    *((_DWORD *)v5 + 4) = 0;
    v3 = v217;
    *((_DWORD *)v5 + 2) = v6;
    *((_DWORD *)v5 + 3) = 0;
    *((_DWORD *)v5 + 5) = 0;
  }
  else
  {
    v5 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v5);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v5);
  if ( v1 & 2 )
  {
    v7 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFFFD;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    }
  }
  v8 = operator new(0x18u);
  if ( v8 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "commands");
    *(_DWORD *)v8 = v218.m_charbuffer;
    v1 |= 4u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v8 + 4) = ClientCommunicationSystem::HelpAllGroup;
    v3 = v217;
    *((_DWORD *)v8 + 1) = 0;
    *((_DWORD *)v8 + 2) = 0;
    *((_DWORD *)v8 + 3) = 0;
    *((_DWORD *)v8 + 5) = 0;
  }
  else
  {
    v8 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v8);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v8);
  if ( v1 & 4 )
  {
    v9 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFFFB;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    }
  }
  v10 = operator new(0x18u);
  if ( v10 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "allegiances");
    *(_DWORD *)v10 = v218.m_charbuffer;
    v1 |= 8u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v10 + 4) = ClientCommunicationSystem::HelpAllegiancesGroup;
    v3 = v217;
    *((_DWORD *)v10 + 1) = 0;
    *((_DWORD *)v10 + 2) = 0;
    *((_DWORD *)v10 + 3) = 0;
    *((_DWORD *)v10 + 5) = 0;
  }
  else
  {
    v10 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v10);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v10);
  if ( v1 & 8 )
  {
    v11 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFFF7;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    }
  }
  v12 = operator new(0x18u);
  if ( v12 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "allegiance");
    *(_DWORD *)v12 = v218.m_charbuffer;
    v1 |= 0x10u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v12 + 2) = ClientCommunicationSystem::DoAllegiance;
    *((_DWORD *)v12 + 4) = ClientCommunicationSystem::HelpAllegiance;
    v3 = v217;
    *((_DWORD *)v12 + 1) = 0;
    *((_DWORD *)v12 + 3) = 0;
    *((_DWORD *)v12 + 5) = 0;
  }
  else
  {
    v12 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v12);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v12);
  if ( v1 & 0x10 )
  {
    v13 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFFEF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v13 )
        (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    }
  }
  v14 = operator new(0x18u);
  if ( v14 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoAllegiance;
    PStringBase<char>::PStringBase<char>(&v218, "all");
    *(_DWORD *)v14 = v218.m_charbuffer;
    v1 |= 0x20u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    v15 = result.m_currHashTable;
    *((_DWORD *)v14 + 4) = ClientCommunicationSystem::HelpAllegiance;
    v3 = v217;
    *((_DWORD *)v14 + 1) = 0;
    *((_DWORD *)v14 + 2) = v15;
    *((_DWORD *)v14 + 3) = 0;
    *((_DWORD *)v14 + 5) = 0;
  }
  else
  {
    v14 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v14);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v14);
  if ( v1 & 0x20 )
  {
    v16 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFFDF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v16 )
        (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    }
  }
  v17 = operator new(0x18u);
  if ( v17 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "ab");
    *(_DWORD *)v17 = v218.m_charbuffer;
    v1 |= 0x40u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v17 + 2) = ClientCommunicationSystem::DoAllegianceBroadcast;
    *((_DWORD *)v17 + 4) = ClientCommunicationSystem::HelpAllegiance;
    v3 = v217;
    *((_DWORD *)v17 + 1) = 0;
    *((_DWORD *)v17 + 3) = 0;
    *((_DWORD *)v17 + 5) = 0;
  }
  else
  {
    v17 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v17);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v17);
  if ( v1 & 0x40 )
  {
    v18 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFFBF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v18 )
        (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    }
  }
  v19 = operator new(0x18u);
  if ( v19 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "alh");
    *(_DWORD *)v19 = v218.m_charbuffer;
    v1 |= 0x80u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v19 + 2) = ClientCommunicationSystem::DoAllegianceHometown;
    *((_DWORD *)v19 + 4) = ClientCommunicationSystem::HelpAllegiance;
    v3 = v217;
    *((_DWORD *)v19 + 1) = 0;
    *((_DWORD *)v19 + 3) = 0;
    *((_DWORD *)v19 + 5) = 0;
  }
  else
  {
    v19 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v19);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v19);
  if ( (char)v1 < 0 )
  {
    v20 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFF7F;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v20 )
        (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
    }
  }
  v21 = operator new(0x18u);
  if ( v21 )
  {
    result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)ClientCommunicationSystem::DoAllegianceHometown;
    PStringBase<char>::PStringBase<char>(&v218, "ah");
    *(_DWORD *)v21 = v218.m_charbuffer;
    v1 |= 0x100u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    v22 = result.m_currHashTable;
    *((_DWORD *)v21 + 4) = ClientCommunicationSystem::HelpAllegiance;
    v3 = v217;
    *((_DWORD *)v21 + 1) = 0;
    *((_DWORD *)v21 + 2) = v22;
    *((_DWORD *)v21 + 3) = 0;
    *((_DWORD *)v21 + 5) = 0;
  }
  else
  {
    v21 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v21);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v21);
  if ( BYTE1(v1) & 1 )
  {
    v23 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFEFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v23 )
        (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
    }
  }
  v24 = operator new(0x18u);
  if ( v24 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "motd");
    *(_DWORD *)v24 = v218.m_charbuffer;
    v1 |= 0x200u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v24 + 2) = ClientCommunicationSystem::DoMotd;
    *((_DWORD *)v24 + 4) = ClientCommunicationSystem::HelpMotd;
    v3 = v217;
    *((_DWORD *)v24 + 1) = 0;
    *((_DWORD *)v24 + 3) = 0;
    *((_DWORD *)v24 + 5) = 0;
  }
  else
  {
    v24 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v24);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v24);
  if ( BYTE1(v1) & 2 )
  {
    v25 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFDFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v25 )
        (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
    }
  }
  v26 = operator new(0x18u);
  if ( v26 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "speaker");
    *(_DWORD *)v26 = v218.m_charbuffer;
    v1 |= 0x400u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v26 + 2) = ClientCommunicationSystem::DoSpeaker;
    *((_DWORD *)v26 + 4) = ClientCommunicationSystem::HelpSpeaker;
    v3 = v217;
    *((_DWORD *)v26 + 1) = 0;
    *((_DWORD *)v26 + 3) = 0;
    *((_DWORD *)v26 + 5) = 0;
  }
  else
  {
    v26 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v26);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v26);
  if ( BYTE1(v1) & 4 )
  {
    v27 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFFBFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v27 )
        (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
    }
  }
  v28 = operator new(0x18u);
  if ( v28 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "channels");
    *(_DWORD *)v28 = v218.m_charbuffer;
    v1 |= 0x800u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v28 + 4) = ClientCommunicationSystem::HelpChannelsGroup;
    v3 = v217;
    *((_DWORD *)v28 + 1) = 0;
    *((_DWORD *)v28 + 2) = 0;
    *((_DWORD *)v28 + 3) = 0;
    *((_DWORD *)v28 + 5) = 0;
  }
  else
  {
    v28 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v28);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v28);
  if ( BYTE1(v1) & 8 )
  {
    v29 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFF7FF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v29 )
        (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
    }
  }
  v30 = operator new(0x18u);
  if ( v30 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "a");
    *(_DWORD *)v30 = v218.m_charbuffer;
    v1 |= 0x1000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v30 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v30 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v30 + 1) = 0;
    *((_DWORD *)v30 + 3) = 0;
    *((_DWORD *)v30 + 5) = 0;
  }
  else
  {
    v30 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v30);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v30);
  if ( BYTE1(v1) & 0x10 )
  {
    v31 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFEFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v31 )
        (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
    }
  }
  v32 = operator new(0x18u);
  if ( v32 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "co-vassals");
    *(_DWORD *)v32 = v218.m_charbuffer;
    v1 |= 0x2000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v32 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v32 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v32 + 1) = 0;
    *((_DWORD *)v32 + 3) = 0;
    *((_DWORD *)v32 + 5) = 0;
  }
  else
  {
    v32 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v32);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v32);
  if ( BYTE1(v1) & 0x20 )
  {
    v33 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFDFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v33 )
        (**(void (__thiscall ***)(char *, signed int))v33)(v33, 1);
    }
  }
  v34 = operator new(0x18u);
  if ( v34 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "covassals");
    *(_DWORD *)v34 = v218.m_charbuffer;
    v1 |= 0x4000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v34 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v34 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v34 + 1) = 0;
    *((_DWORD *)v34 + 3) = 0;
    *((_DWORD *)v34 + 5) = 0;
  }
  else
  {
    v34 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v34);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v34);
  if ( BYTE1(v1) & 0x40 )
  {
    v35 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFFBFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v35 )
        (**(void (__thiscall ***)(char *, signed int))v35)(v35, 1);
    }
  }
  v36 = operator new(0x18u);
  if ( v36 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "covassal");
    *(_DWORD *)v36 = v218.m_charbuffer;
    v1 |= 0x8000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v36 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v36 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v36 + 1) = 0;
    *((_DWORD *)v36 + 3) = 0;
    *((_DWORD *)v36 + 5) = 0;
  }
  else
  {
    v36 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v36);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v36);
  if ( SBYTE1(v1) < 0 )
  {
    v37 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFF7FFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v37 )
        (**(void (__thiscall ***)(char *, signed int))v37)(v37, 1);
    }
  }
  v38 = operator new(0x18u);
  if ( v38 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "c");
    *(_DWORD *)v38 = v218.m_charbuffer;
    v1 |= 0x10000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v38 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v38 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v38 + 1) = 0;
    *((_DWORD *)v38 + 3) = 0;
    *((_DWORD *)v38 + 5) = 0;
  }
  else
  {
    v38 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v38);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v38);
  if ( v1 & 0x10000 )
  {
    v39 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFEFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v39 )
        (**(void (__thiscall ***)(char *, signed int))v39)(v39, 1);
    }
  }
  v40 = operator new(0x18u);
  if ( v40 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "fellowship");
    *(_DWORD *)v40 = v218.m_charbuffer;
    v1 |= 0x20000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v40 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v40 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v40 + 1) = 0;
    *((_DWORD *)v40 + 3) = 0;
    *((_DWORD *)v40 + 5) = 0;
  }
  else
  {
    v40 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v40);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v40);
  if ( v1 & 0x20000 )
  {
    v41 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFDFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v41 )
        (**(void (__thiscall ***)(char *, signed int))v41)(v41, 1);
    }
  }
  v42 = operator new(0x18u);
  if ( v42 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "fellows");
    *(_DWORD *)v42 = v218.m_charbuffer;
    v1 |= 0x40000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v42 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v42 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v42 + 1) = 0;
    *((_DWORD *)v42 + 3) = 0;
    *((_DWORD *)v42 + 5) = 0;
  }
  else
  {
    v42 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v42);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v42);
  if ( v1 & 0x40000 )
  {
    v43 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFFBFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v43 )
        (**(void (__thiscall ***)(char *, signed int))v43)(v43, 1);
    }
  }
  v44 = operator new(0x18u);
  if ( v44 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "fellow");
    *(_DWORD *)v44 = v218.m_charbuffer;
    v1 |= 0x80000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v44 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v44 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v44 + 1) = 0;
    *((_DWORD *)v44 + 3) = 0;
    *((_DWORD *)v44 + 5) = 0;
  }
  else
  {
    v44 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v44);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v44);
  if ( v1 & 0x80000 )
  {
    v45 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFF7FFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v45 )
        (**(void (__thiscall ***)(char *, signed int))v45)(v45, 1);
    }
  }
  v46 = operator new(0x18u);
  if ( v46 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "f");
    *(_DWORD *)v46 = v218.m_charbuffer;
    v1 |= 0x100000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v46 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v46 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v46 + 1) = 0;
    *((_DWORD *)v46 + 3) = 0;
    *((_DWORD *)v46 + 5) = 0;
  }
  else
  {
    v46 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v46);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v46);
  if ( v1 & 0x100000 )
  {
    v47 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFEFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v47 )
        (**(void (__thiscall ***)(char *, signed int))v47)(v47, 1);
    }
  }
  v48 = operator new(0x18u);
  if ( v48 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "group");
    *(_DWORD *)v48 = v218.m_charbuffer;
    v1 |= 0x200000u;
    InterlockedIncrement((volatile LONG *)&v218.m_charbuffer[-1]);
    *((_DWORD *)v48 + 2) = ClientCommunicationSystem::DoStupidChannelHack;
    *((_DWORD *)v48 + 4) = ClientCommunicationSystem::HelpStupidChannelHack;
    v3 = v217;
    *((_DWORD *)v48 + 1) = 0;
    *((_DWORD *)v48 + 3) = 0;
    *((_DWORD *)v48 + 5) = 0;
  }
  else
  {
    v48 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v3,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v48);
  if ( !result.m_currElement )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add_internal(
      v3,
      (ClientCommunicationSystem::CmdHashData *)v48);
  if ( v1 & 0x200000 )
  {
    v49 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFDFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v49 )
        (**(void (__thiscall ***)(char *, signed int))v49)(v49, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "g");
    v1 |= 0x400000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v50 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v50);
  if ( v1 & 0x400000 )
  {
    v51 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFFBFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v51 )
        (**(void (__thiscall ***)(char *, signed int))v51)(v51, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "party");
    v1 |= (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)";
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v52 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v52);
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v1 )
  {
    v53 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFF7FFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v53 )
        (**(void (__thiscall ***)(char *, signed int))v53)(v53, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "monarch");
    v1 |= 0x1000000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v54 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v54);
  if ( v1 & 0x1000000 )
  {
    v55 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFEFFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v55 )
        (**(void (__thiscall ***)(char *, signed int))v55)(v55, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "m");
    v1 |= 0x2000000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v56 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v56);
  if ( v1 & 0x2000000 )
  {
    v57 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFDFFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v57 )
        (**(void (__thiscall ***)(char *, signed int))v57)(v57, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "patron");
    v1 |= 0x4000000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v58 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v58);
  if ( v1 & 0x4000000 )
  {
    v59 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xFBFFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v59 )
        (**(void (__thiscall ***)(char *, signed int))v59)(v59, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "p");
    v1 |= 0x8000000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v60 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v60);
  if ( v1 & 0x8000000 )
  {
    v61 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xF7FFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v61 )
        (**(void (__thiscall ***)(char *, signed int))v61)(v61, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "vassals");
    v1 |= 0x10000000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v62 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v62);
  if ( v1 & 0x10000000 )
  {
    v63 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xEFFFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v63 )
        (**(void (__thiscall ***)(char *, signed int))v63)(v63, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "vassal");
    v1 |= 0x20000000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v64 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v64);
  if ( v1 & 0x20000000 )
  {
    v65 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xDFFFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v65 )
        (**(void (__thiscall ***)(char *, signed int))v65)(v65, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "v");
    v1 |= 0x40000000u;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoStupidChannelHack,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStupidChannelHack,
      0);
    v3 = v217;
  }
  else
  {
    v66 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v66);
  if ( v1 & 0x40000000 )
  {
    v67 = &v218.m_charbuffer[-2].m_data[12];
    v1 &= 0xBFFFFFFF;
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v67 )
        (**(void (__thiscall ***)(char *, signed int))v67)(v67, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "join");
    v1 |= 0x80000000;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoJoinChat,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpJoinChat,
      0);
    v3 = v217;
  }
  else
  {
    v68 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v68);
  if ( v1 < 0 )
  {
    v69 = &v218.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v69 )
        (**(void (__thiscall ***)(char *, signed int))v69)(v69, 1);
    }
  }
  result.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)operator new(0x18u);
  if ( (_DWORD)result.m_currHashTable )
  {
    PStringBase<char>::PStringBase<char>(&v218, "leave");
    v70 = (ClientCommunicationSystem::CmdHashData *)1;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      (ClientCommunicationSystem::CmdHashData *)result.m_currHashTable,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLeaveChat,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLeaveChat,
      0);
    v3 = v217;
  }
  else
  {
    v70 = v220;
    v71 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v71);
  if ( (unsigned __int8)v70 & 1 )
  {
    v72 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFFFE);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v72 )
        (**(void (__thiscall ***)(char *, signed int))v72)(v72, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "chatting");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 2);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      0,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpChattingGroup,
      0);
    v3 = v217;
  }
  else
  {
    v73 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v73);
  if ( (unsigned __int8)v70 & 2 )
  {
    v74 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFFFD);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v74 )
        (**(void (__thiscall ***)(char *, signed int))v74)(v74, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "chat");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 4);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoChatToggle,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpChatToggle,
      0);
    v3 = v217;
  }
  else
  {
    v75 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v75);
  if ( (unsigned __int8)v70 & 4 )
  {
    v76 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFFFB);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v76 )
        (**(void (__thiscall ***)(char *, signed int))v76)(v76, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "notell");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 8);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoNoTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpNoTell,
      0);
    v3 = v217;
  }
  else
  {
    v77 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v77);
  if ( (unsigned __int8)v70 & 8 )
  {
    v78 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFFF7);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v78 )
        (**(void (__thiscall ***)(char *, signed int))v78)(v78, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "reply");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x10);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoReply,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpReply,
      0);
    v3 = v217;
  }
  else
  {
    v79 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v79);
  if ( (unsigned __int8)v70 & 0x10 )
  {
    v80 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFFEF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v80 )
        (**(void (__thiscall ***)(char *, signed int))v80)(v80, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "r");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x20);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoReply,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpReply,
      0);
    v3 = v217;
  }
  else
  {
    v81 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v81);
  if ( (unsigned __int8)v70 & 0x20 )
  {
    v82 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFFDF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v82 )
        (**(void (__thiscall ***)(char *, signed int))v82)(v82, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "rp");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x40);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoReply,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpReply,
      0);
    v3 = v217;
  }
  else
  {
    v83 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v83);
  if ( (unsigned __int8)v70 & 0x40 )
  {
    v84 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFFBF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v84 )
        (**(void (__thiscall ***)(char *, signed int))v84)(v84, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "mr");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x80);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      0,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpReply,
      0);
    v3 = v217;
  }
  else
  {
    v85 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v85);
  if ( (char)v70 < 0 )
  {
    v86 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFF7F);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v86 )
        (**(void (__thiscall ***)(char *, signed int))v86)(v86, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "pr");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x100);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      0,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpReply,
      0);
    v3 = v217;
  }
  else
  {
    v87 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v87);
  if ( BYTE1(v70) & 1 )
  {
    v88 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFEFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v88 )
        (**(void (__thiscall ***)(char *, signed int))v88)(v88, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "retell");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x200);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoReTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpReTell,
      0);
    v3 = v217;
  }
  else
  {
    v89 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v89);
  if ( BYTE1(v70) & 2 )
  {
    v90 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFDFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v90 )
        (**(void (__thiscall ***)(char *, signed int))v90)(v90, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "rt");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x400);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoReTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpReTell,
      0);
    v3 = v217;
  }
  else
  {
    v91 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v91);
  if ( BYTE1(v70) & 4 )
  {
    v92 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFFBFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v92 )
        (**(void (__thiscall ***)(char *, signed int))v92)(v92, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "say");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x800);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoSay,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpSay,
      0);
    v3 = v217;
  }
  else
  {
    v93 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v93);
  if ( BYTE1(v70) & 8 )
  {
    v94 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFF7FF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v94 )
        (**(void (__thiscall ***)(char *, signed int))v94)(v94, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "s");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x1000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoSay,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpSay,
      0);
    v3 = v217;
  }
  else
  {
    v95 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v95);
  if ( BYTE1(v70) & 0x10 )
  {
    v96 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFEFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v96 )
        (**(void (__thiscall ***)(char *, signed int))v96)(v96, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "tell");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x2000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpTell,
      0);
    v3 = v217;
  }
  else
  {
    v97 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v97);
  if ( BYTE1(v70) & 0x20 )
  {
    v98 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFDFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v98 )
        (**(void (__thiscall ***)(char *, signed int))v98)(v98, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "t");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x4000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpTell,
      0);
    v3 = v217;
  }
  else
  {
    v99 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v99);
  if ( BYTE1(v70) & 0x40 )
  {
    v100 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFFBFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v100 )
        (**(void (__thiscall ***)(char *, signed int))v100)(v100, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "send");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x8000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpTell,
      0);
    v3 = v217;
  }
  else
  {
    v101 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v101);
  if ( SBYTE1(v70) < 0 )
  {
    v102 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFF7FFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v102 )
        (**(void (__thiscall ***)(char *, signed int))v102)(v102, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "whisper");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x10000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpTell,
      0);
    v3 = v217;
  }
  else
  {
    v103 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v103);
  if ( (unsigned int)v70 & 0x10000 )
  {
    v104 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFEFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v104 )
        (**(void (__thiscall ***)(char *, signed int))v104)(v104, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "w");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x20000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoTell,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpTell,
      0);
    v3 = v217;
  }
  else
  {
    v105 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v105);
  if ( (unsigned int)v70 & 0x20000 )
  {
    v106 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFDFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v106 )
        (**(void (__thiscall ***)(char *, signed int))v106)(v106, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "afk");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x40000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoAFK,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpAFK,
      0);
    v3 = v217;
  }
  else
  {
    v107 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v107);
  if ( (unsigned int)v70 & 0x40000 )
  {
    v108 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFFBFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v108 )
        (**(void (__thiscall ***)(char *, signed int))v108)(v108, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "death");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x80000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      0,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpDeathGroup,
      0);
    v3 = v217;
  }
  else
  {
    v109 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v109);
  if ( (unsigned int)v70 & 0x80000 )
  {
    v110 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFF7FFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v110 )
        (**(void (__thiscall ***)(char *, signed int))v110)(v110, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "consent");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x100000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoConsent,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpConsent,
      0);
    v3 = v217;
  }
  else
  {
    v111 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v111);
  if ( (unsigned int)v70 & 0x100000 )
  {
    v112 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFEFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v112 )
        (**(void (__thiscall ***)(char *, signed int))v112)(v112, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "corpse");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x200000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoCorpse,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpCorpse,
      0);
    v3 = v217;
  }
  else
  {
    v113 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v113);
  if ( (unsigned int)v70 & 0x200000 )
  {
    v114 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFDFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v114 )
        (**(void (__thiscall ***)(char *, signed int))v114)(v114, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "cor");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x400000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoCorpse,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpCorpse,
      0);
    v3 = v217;
  }
  else
  {
    v115 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v115);
  if ( (unsigned int)v70 & 0x400000 )
  {
    v116 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFFBFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v116 )
        (**(void (__thiscall ***)(char *, signed int))v116)(v116, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "die");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" | (unsigned int)v70);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoDie,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpDie,
      0);
    v3 = v217;
  }
  else
  {
    v117 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v117);
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v70 )
  {
    v118 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFF7FFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v118 )
        (**(void (__thiscall ***)(char *, signed int))v118)(v118, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "lifestone");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x1000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLifestone,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLifestone,
      0);
    v3 = v217;
  }
  else
  {
    v119 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v119);
  if ( (unsigned int)v70 & 0x1000000 )
  {
    v120 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFEFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v120 )
        (**(void (__thiscall ***)(char *, signed int))v120)(v120, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "lif");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x2000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLifestone,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLifestone,
      0);
    v3 = v217;
  }
  else
  {
    v121 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v121);
  if ( (unsigned int)v70 & 0x2000000 )
  {
    v122 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFDFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v122 )
        (**(void (__thiscall ***)(char *, signed int))v122)(v122, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "ls");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x4000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLifestone,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLifestone,
      0);
    v3 = v217;
  }
  else
  {
    v123 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v123);
  if ( (unsigned int)v70 & 0x4000000 )
  {
    v124 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xFBFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v124 )
        (**(void (__thiscall ***)(char *, signed int))v124)(v124, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "marketplace");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x8000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoMarketplace,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpMarketplace,
      0);
    v3 = v217;
  }
  else
  {
    v125 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v125);
  if ( (unsigned int)v70 & 0x8000000 )
  {
    v126 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xF7FFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v126 )
        (**(void (__thiscall ***)(char *, signed int))v126)(v126, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "mar");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x10000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoMarketplace,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpMarketplace,
      0);
    v3 = v217;
  }
  else
  {
    v127 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v127);
  if ( (unsigned int)v70 & 0x10000000 )
  {
    v128 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xEFFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v128 )
        (**(void (__thiscall ***)(char *, signed int))v128)(v128, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "mp");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x20000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoMarketplace,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpMarketplace,
      0);
    v3 = v217;
  }
  else
  {
    v129 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v129);
  if ( (unsigned int)v70 & 0x20000000 )
  {
    v130 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xDFFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v130 )
        (**(void (__thiscall ***)(char *, signed int))v130)(v130, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "permit");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x40000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoPermit,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpPermit,
      0);
    v3 = v217;
  }
  else
  {
    v131 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v131);
  if ( (unsigned int)v70 & 0x40000000 )
  {
    v132 = &v218.m_charbuffer[-2].m_data[12];
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 & 0xBFFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v132 )
        (**(void (__thiscall ***)(char *, signed int))v132)(v132, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "pkarena");
    v70 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v70 | 0x80000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoPKArena,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpPKArena,
      0);
    v3 = v217;
  }
  else
  {
    v133 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v133);
  if ( (signed int)v70 < 0 )
  {
    v134 = &v218.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v134 )
        (**(void (__thiscall ***)(char *, signed int))v134)(v134, 1);
    }
  }
  v220 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v220 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "pka");
    v135 = (ClientCommunicationSystem::CmdHashData *)1;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v220,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoPKArena,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpPKArena,
      0);
    v3 = v217;
  }
  else
  {
    v135 = v221;
    v136 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v136);
  if ( (unsigned __int8)v135 & 1 )
  {
    v137 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFFFE);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v137 )
        (**(void (__thiscall ***)(char *, signed int))v137)(v137, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "pklarena");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 2);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoPKLArena,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpPKLArena,
      0);
    v3 = v217;
  }
  else
  {
    v138 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v138);
  if ( (unsigned __int8)v135 & 2 )
  {
    v139 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFFFD);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v139 )
        (**(void (__thiscall ***)(char *, signed int))v139)(v139, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "pla");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 4);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoPKLArena,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpPKLArena,
      0);
    v3 = v217;
  }
  else
  {
    v140 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v140);
  if ( (unsigned __int8)v135 & 4 )
  {
    v141 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFFFB);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v141 )
        (**(void (__thiscall ***)(char *, signed int))v141)(v141, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "e");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 8);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoEmote,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpEmote,
      0);
    v3 = v217;
  }
  else
  {
    v142 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v142);
  if ( (unsigned __int8)v135 & 8 )
  {
    v143 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFFF7);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v143 )
        (**(void (__thiscall ***)(char *, signed int))v143)(v143, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "em");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x10);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoEmote,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpEmote,
      0);
    v3 = v217;
  }
  else
  {
    v144 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v144);
  if ( (unsigned __int8)v135 & 0x10 )
  {
    v145 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFFEF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v145 )
        (**(void (__thiscall ***)(char *, signed int))v145)(v145, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "emote");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x20);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoEmote,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpEmote,
      0);
    v3 = v217;
  }
  else
  {
    v146 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v146);
  if ( (unsigned __int8)v135 & 0x20 )
  {
    v147 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFFDF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v147 )
        (**(void (__thiscall ***)(char *, signed int))v147)(v147, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "me");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x40);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoEmote,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpEmote,
      0);
    v3 = v217;
  }
  else
  {
    v148 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v148);
  if ( (unsigned __int8)v135 & 0x40 )
  {
    v149 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFFBF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v149 )
        (**(void (__thiscall ***)(char *, signed int))v149)(v149, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "emotes");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x80);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoEmoteList,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpEmoteList,
      0);
    v3 = v217;
  }
  else
  {
    v150 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v150);
  if ( (char)v135 < 0 )
  {
    v151 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFF7F);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v151 )
        (**(void (__thiscall ***)(char *, signed int))v151)(v151, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "fillcomps");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x100);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoFillComponents,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpFillComponents,
      0);
    v3 = v217;
  }
  else
  {
    v152 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v152);
  if ( BYTE1(v135) & 1 )
  {
    v153 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFEFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v153 )
        (**(void (__thiscall ***)(char *, signed int))v153)(v153, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "loadfile");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x200);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLoadFile,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLoadFile,
      0);
    v3 = v217;
  }
  else
  {
    v154 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v154);
  if ( BYTE1(v135) & 2 )
  {
    v155 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFDFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v155 )
        (**(void (__thiscall ***)(char *, signed int))v155)(v155, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "friends");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x400);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoFriends,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpFriends,
      0);
    v3 = v217;
  }
  else
  {
    v156 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v156);
  if ( BYTE1(v135) & 4 )
  {
    v157 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFFBFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v157 )
        (**(void (__thiscall ***)(char *, signed int))v157)(v157, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "friends_add");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x800);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoFriendsAdd,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpFriends,
      0);
    v3 = v217;
  }
  else
  {
    v158 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v158);
  if ( BYTE1(v135) & 8 )
  {
    v159 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFF7FF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v159 )
        (**(void (__thiscall ***)(char *, signed int))v159)(v159, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "friends_remove");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x1000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoFriendsRemove,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpFriends,
      0);
    v3 = v217;
  }
  else
  {
    v160 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v160);
  if ( BYTE1(v135) & 0x10 )
  {
    v161 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFEFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v161 )
        (**(void (__thiscall ***)(char *, signed int))v161)(v161, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "house");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x2000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoHouse,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpHouse,
      0);
    v3 = v217;
  }
  else
  {
    v162 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v162);
  if ( BYTE1(v135) & 0x20 )
  {
    v163 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFDFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v163 )
        (**(void (__thiscall ***)(char *, signed int))v163)(v163, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "hou");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x4000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoHouse,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpHouse,
      0);
    v3 = v217;
  }
  else
  {
    v164 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v164);
  if ( BYTE1(v135) & 0x40 )
  {
    v165 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFFBFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v165 )
        (**(void (__thiscall ***)(char *, signed int))v165)(v165, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "hslist");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x8000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoHouseAvailableList,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpHouseAvailableList,
      0);
    v3 = v217;
  }
  else
  {
    v166 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v166);
  if ( SBYTE1(v135) < 0 )
  {
    v167 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFF7FFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v167 )
        (**(void (__thiscall ***)(char *, signed int))v167)(v167, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "hor");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x10000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoHouseRecall,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpHouse,
      0);
    v3 = v217;
  }
  else
  {
    v168 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v168);
  if ( (unsigned int)v135 & 0x10000 )
  {
    v169 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFEFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v169 )
        (**(void (__thiscall ***)(char *, signed int))v169)(v169, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "hr");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x20000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoHouseRecall,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpHouse,
      0);
    v3 = v217;
  }
  else
  {
    v170 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v170);
  if ( (unsigned int)v135 & 0x20000 )
  {
    v171 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFDFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v171 )
        (**(void (__thiscall ***)(char *, signed int))v171)(v171, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "hom");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x40000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoMansionRecall,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpHouse,
      0);
    v3 = v217;
  }
  else
  {
    v172 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v172);
  if ( (unsigned int)v135 & 0x40000 )
  {
    v173 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFFBFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v173 )
        (**(void (__thiscall ***)(char *, signed int))v173)(v173, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "hoa");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x80000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoMansionRecall,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpHouse,
      0);
    v3 = v217;
  }
  else
  {
    v174 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v174);
  if ( (unsigned int)v135 & 0x80000 )
  {
    v175 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFF7FFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v175 )
        (**(void (__thiscall ***)(char *, signed int))v175)(v175, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "squelch");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x100000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoSquelch,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpSquelch,
      0);
    v3 = v217;
  }
  else
  {
    v176 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v176);
  if ( (unsigned int)v135 & 0x100000 )
  {
    v177 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFEFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v177 )
        (**(void (__thiscall ***)(char *, signed int))v177)(v177, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "unsquelch");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x200000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoUnSquelch,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpSquelch,
      0);
    v3 = v217;
  }
  else
  {
    v178 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v178);
  if ( (unsigned int)v135 & 0x200000 )
  {
    v179 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFDFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v179 )
        (**(void (__thiscall ***)(char *, signed int))v179)(v179, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "messagetypes");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x400000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoMessageTypes,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpMessageTypes,
      0);
    v3 = v217;
  }
  else
  {
    v180 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v180);
  if ( (unsigned int)v135 & 0x400000 )
  {
    v181 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFFBFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v181 )
        (**(void (__thiscall ***)(char *, signed int))v181)(v181, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "message_types");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" | (unsigned int)v135);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoMessageTypes,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpMessageTypes,
      0);
    v3 = v217;
  }
  else
  {
    v182 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v182);
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & (unsigned int)v135 )
  {
    v183 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFF7FFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v183 )
        (**(void (__thiscall ***)(char *, signed int))v183)(v183, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "msgtypes");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x1000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoMessageTypes,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpMessageTypes,
      0);
    v3 = v217;
  }
  else
  {
    v184 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v184);
  if ( (unsigned int)v135 & 0x1000000 )
  {
    v185 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFEFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v185 )
        (**(void (__thiscall ***)(char *, signed int))v185)(v185, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "msg_types");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x2000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoMessageTypes,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpMessageTypes,
      0);
    v3 = v217;
  }
  else
  {
    v186 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v186);
  if ( (unsigned int)v135 & 0x2000000 )
  {
    v187 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFDFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v187 )
        (**(void (__thiscall ***)(char *, signed int))v187)(v187, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "status");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x4000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      0,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpStatusGroup,
      0);
    v3 = v217;
  }
  else
  {
    v188 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v188);
  if ( (unsigned int)v135 & 0x4000000 )
  {
    v189 = &v218.m_charbuffer[-2].m_data[12];
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xFBFFFFFF);
    if ( !InterlockedDecrement((volatile LONG *)&v218.m_charbuffer[-1]) )
    {
      if ( v189 )
        (**(void (__thiscall ***)(char *, signed int))v189)(v189, 1);
    }
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "age");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x8000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoAge,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpAge,
      0);
    v3 = v217;
  }
  else
  {
    v190 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v190);
  if ( (unsigned int)v135 & 0x8000000 )
  {
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xF7FFFFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "birth");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x10000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoBirth,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpBirth,
      0);
    v3 = v217;
  }
  else
  {
    v191 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v191);
  if ( (unsigned int)v135 & 0x10000000 )
  {
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xEFFFFFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "day");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x20000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoDay,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpDay,
      0);
    v3 = v217;
  }
  else
  {
    v192 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v192);
  if ( (unsigned int)v135 & 0x20000000 )
  {
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xDFFFFFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "endurance");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x40000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoEndurance,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpEndurance,
      0);
    v3 = v217;
  }
  else
  {
    v193 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v193);
  if ( (unsigned int)v135 & 0x40000000 )
  {
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 & 0xBFFFFFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "framerate");
    v135 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v135 | 0x80000000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoFrameRate,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpFrameRate,
      0);
    v3 = v217;
  }
  else
  {
    v194 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v194);
  if ( (signed int)v135 < 0 )
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  v221 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v221 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "loc");
    v195 = (ClientCommunicationSystem::CmdHashData *)1;
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v221,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLoc,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLoc,
      0);
    v3 = v217;
  }
  else
  {
    v195 = v223;
    v196 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v196);
  if ( (unsigned __int8)v195 & 1 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFFFE);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "pklite");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 2);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoPKLite,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpPKLite,
      0);
    v3 = v217;
  }
  else
  {
    v197 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v197);
  if ( (unsigned __int8)v195 & 2 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFFFD);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "pkl");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 4);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoPKLite,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpPKLite,
      0);
    v3 = v217;
  }
  else
  {
    v198 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v198);
  if ( (unsigned __int8)v195 & 4 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFFFB);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "render");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 8);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoRenderOption,
      0,
      0,
      0);
    v3 = v217;
  }
  else
  {
    v199 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v199);
  if ( (unsigned __int8)v195 & 8 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFFF7);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "version");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x10);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoVersion,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpVersion,
      0);
    v3 = v217;
  }
  else
  {
    v200 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v200);
  if ( (unsigned __int8)v195 & 0x10 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFFEF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "saveui");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x20);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoSaveUI,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpSaveUI,
      0);
    v3 = v217;
  }
  else
  {
    v201 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v201);
  if ( (unsigned __int8)v195 & 0x20 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFFDF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "loadui");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x40);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLoadUI,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLoadUI,
      0);
    v3 = v217;
  }
  else
  {
    v202 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v202);
  if ( (unsigned __int8)v195 & 0x40 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFFBF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "saveautoui");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x80);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoSaveAutoUI,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpSaveAutoUI,
      0);
    v3 = v217;
  }
  else
  {
    v203 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v203);
  if ( (char)v195 < 0 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFF7F);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "loadautoui");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x100);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLoadAutoUI,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLoadAutoUI,
      0);
    v3 = v217;
  }
  else
  {
    v204 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v204);
  if ( BYTE1(v195) & 1 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFEFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "lockui");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x200);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoLockUI,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpLockUI,
      0);
    v3 = v217;
  }
  else
  {
    v205 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v205);
  if ( BYTE1(v195) & 2 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFDFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "text");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x400);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      0,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpTextGroup,
      0);
    v3 = v217;
  }
  else
  {
    v206 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v206);
  if ( BYTE1(v195) & 4 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFFBFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "clear");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x800);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoClear,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpClear,
      0);
    v3 = v217;
  }
  else
  {
    v207 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v207);
  if ( BYTE1(v195) & 8 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFF7FF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "filter");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x1000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoFilter,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpFilter,
      0);
    v3 = v217;
  }
  else
  {
    v208 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v208);
  if ( BYTE1(v195) & 0x10 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFEFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "unfilter");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x2000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoUnFilter,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpUnFilter,
      0);
    v3 = v217;
  }
  else
  {
    v209 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v209);
  if ( BYTE1(v195) & 0x20 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFDFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "log");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x4000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoSetOutput,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::DoSetOutputHelp,
      0);
    v3 = v217;
  }
  else
  {
    v210 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v210);
  if ( BYTE1(v195) & 0x40 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFFBFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "title");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x8000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoTitle,
      0,
      (bool (__thiscall *)(ClientCommunicationSystem *, ClientCommunicationSystem::HelpType, const char *, PStringBase<char> *))ClientCommunicationSystem::HelpTitle,
      0);
    v3 = v217;
  }
  else
  {
    v211 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v211);
  if ( SBYTE1(v195) < 0 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFF7FFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "index");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x10000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      (bool (__thiscall *)(ClientCommunicationSystem *, int, char **))ClientCommunicationSystem::DoChannelIndex,
      0,
      0,
      0);
    v3 = v217;
  }
  else
  {
    v212 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v212);
  if ( (unsigned int)v195 & 0x10000 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFEFFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "clist");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x20000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoChannelList,
      0,
      0,
      0);
    v3 = v217;
  }
  else
  {
    v213 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v213);
  if ( (unsigned int)v195 & 0x20000 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFDFFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    PStringBase<char>::PStringBase<char>(&v218, "on");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x40000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoChannelOn,
      0,
      0,
      0);
    v3 = v217;
  }
  else
  {
    v214 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v214);
  if ( (unsigned int)v195 & 0x40000 )
  {
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 & 0xFFFBFFFF);
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
  }
  v223 = (ClientCommunicationSystem::CmdHashData *)operator new(0x18u);
  if ( v223 )
  {
    v222 = 0;
    PStringBase<char>::PStringBase<char>(&v218, "off");
    v195 = (ClientCommunicationSystem::CmdHashData *)((unsigned int)v195 | 0x80000);
    ClientCommunicationSystem::CmdHashData::CmdHashData(
      v223,
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v218,
      ClientCommunicationSystem::DoChannelOff,
      0,
      0,
      0);
    v3 = v217;
  }
  else
  {
    v215 = 0;
  }
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::add(
    v3,
    v215);
  if ( (unsigned int)v195 & 0x80000 )
    ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v218.m_charbuffer[-2].m_data[12]);
}

//----- (00585520) --------------------------------------------------------  // acclient.c:430249
void __thiscall ClientCommunicationSystem::ClientCommunicationSystem(ClientCommunicationSystem *this)
{
  ClientCommunicationSystem *v1; // esi@1
  char *v2; // ebx@1
  volatile LONG *v3; // ST04_4@1
  volatile LONG *v4; // ST04_4@1
  volatile LONG *v5; // ST04_4@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebp@2
  GlobalEventHandler *v7; // eax@6
  GlobalEventHandler *v8; // edi@6

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v2 = (char *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&ClientCommunicationSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientCommunicationSystem::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)&ClientCommunicationSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>(
    &this->m_hashCommands,
    0x64u);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strLastCommandLine.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strCurrentCommand.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v1->m_idCurrentCommandSource = 0;
  v1->m_LastSpamCheck = 0;
  v1->m_ChatMessageCount = 0;
  v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strLogName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v5);
  if ( g_rename_cache.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    v6 = g_rename_cache.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&g_rename_cache.m_buffer->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    g_rename_cache.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  }
  ClientCommunicationSystem::s_pCommunicationSystem = v1;
  InterlockedIncrement((volatile LONG *)&v1->m_cTurbineRefCount.m_cRef);
  ClientCommunicationSystem::InitializeCommands(v1);
  v7 = GlobalEventHandler::GetGlobalEventHandler();
  v8 = v7;
  if ( v7 )
  {
    v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, 100005u, (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, 100023u, (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v2);
    v8->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v8,
      (unsigned int)((char *)&loc_4DD21E + 1),
      (NoticeHandler *)v2);
  }
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7D00E0: using guessed type void (__thiscall *ClientCommunicationSystem::vftable)(ClientCommunicationSystem *this, CWeenieObject *cwobj, enum StatType bAFK, unsigned __int32);
// 7D00E8: using guessed type bool (__thiscall *ClientCommunicationSystem::vftable)(DBCache *this);
// 7D0390: using guessed type __int32 (__stdcall *ClientCommunicationSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8707EC: using guessed type struct ClientCommunicationSystem *ClientCommunicationSystem::s_pCommunicationSystem;
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00678FB0) --------------------------------------------------------  // acclient.c:655725
IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *__thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *this, IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *result, CaseInsensitiveStringBase<PStringBase<char> > *_key)
{
  const char **v3; // edi@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v4; // ebx@1
  unsigned int v5; // esi@1
  unsigned int v6; // edx@1
  ClientCommunicationSystem::CmdHashData **v7; // eax@1
  ClientCommunicationSystem::CmdHashData *v8; // esi@1
  ClientCommunicationSystem::CmdHashData **v9; // edx@1
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v10; // eax@5
  CaseInsensitiveStringBase<PStringBase<char> > *_keya; // [sp+14h] [bp+8h]@1

  v3 = (const char **)_key;
  v4 = this;
  v5 = this->m_numBuckets;
  v6 = CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(_key) % v5;
  v7 = v4->m_buckets;
  v8 = v7[v6];
  v9 = &v7[v6];
  _keya = (CaseInsensitiveStringBase<PStringBase<char> > *)v9;
  if ( v8 )
  {
    do
    {
      if ( !__stricmp(v8->m_hashKey.m_charbuffer->m_data, *v3) )
        break;
      v8 = v8->m_hashNext;
    }
    while ( v8 );
    v9 = (ClientCommunicationSystem::CmdHashData **)_keya;
  }
  v10 = result;
  result->m_currElement = v8;
  result->m_currHashTable = v4;
  result->m_currBucket = v9;
  return v10;
}

//----- (00709320) --------------------------------------------------------  // acclient.c:796457
void sub_709320()
{
  flt_87080C = 1000.0 + 1.0;
}

//----- (00709340) --------------------------------------------------------  // acclient.c:796463
void sub_709340()
{
  flt_870810 = 24.0 * 8.0;
}

//----- (00709360) --------------------------------------------------------  // acclient.c:796469
void sub_709360()
{
  flt_870814 = 24.0 * 0.5;
}

//----- (00709380) --------------------------------------------------------  // acclient.c:796475
int sub_709380()
{
  return atexit(nullsub_1345);
}

//----- (00709390) --------------------------------------------------------  // acclient.c:796481
int sub_709390()
{
  return atexit(nullsub_1346);
}

//----- (007093A0) --------------------------------------------------------  // acclient.c:796487
int sub_7093A0()
{
  return atexit(nullsub_1347);
}

//----- (007093B0) --------------------------------------------------------  // acclient.c:796493
void sub_7093B0()
{
  flt_870818 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007093D0) --------------------------------------------------------  // acclient.c:796499
void _E108_93()
{
  dbl_870820 = 1.0 / 30.0;
}

//----- (007093F0) --------------------------------------------------------  // acclient.c:796505
void _E110_77()
{
  dbl_870828 = 1.0 / 5.0;
}

//----- (00709410) --------------------------------------------------------  // acclient.c:796511
void sub_709410()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870830, PFID_A8R8G8B8);
}

//----- (00709420) --------------------------------------------------------  // acclient.c:796517
int _E114_60()
{
  return atexit(nullsub_1343);
}

//----- (00709430) --------------------------------------------------------  // acclient.c:796523
void _E122_31()
{
  dword_870868 = 1024;
}

//----- (00709440) --------------------------------------------------------  // acclient.c:796529
void _E124_66()
{
  dword_87086C = 0x7FFF;
}

//----- (00709450) --------------------------------------------------------  // acclient.c:796535
int _E126_48()
{
  const int result; // eax@1

  result = dword_870868;
  dword_870870 = dword_870868;
  return result;
}

//----- (00709460) --------------------------------------------------------  // acclient.c:796545
int _E128_12()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't sit down while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_sit_combat_0, v0);
  _wcscpy(cant_sit_combat_0.m_charbuffer->m_data, L"You can't sit down while in combat mode");
  return atexit(_E129_60);
}

//----- (007094A0) --------------------------------------------------------  // acclient.c:796556
int _E131_8()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't lie down while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_lie_down_combat_0, v0);
  _wcscpy(cant_lie_down_combat_0.m_charbuffer->m_data, L"You can't lie down while in combat mode");
  return atexit(_E132_61);
}

//----- (007094E0) --------------------------------------------------------  // acclient.c:796567
int _E134_8()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't crouch while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_crouch_combat_0, v0);
  _wcscpy(cant_crouch_combat_0.m_charbuffer->m_data, L"You can't crouch while in combat mode");
  return atexit(_E135_69);
}

//----- (00709520) --------------------------------------------------------  // acclient.c:796578
int _E137_9()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't use chat emotes from this position");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_emote_position_0, v0);
  _wcscpy(cant_emote_position_0.m_charbuffer->m_data, L"You can't use chat emotes from this position");
  return atexit(_E138_54);
}

//----- (00709560) --------------------------------------------------------  // acclient.c:796589
int _E140_5()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't use chat emotes in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_emote_combat_0, v0);
  _wcscpy(cant_emote_combat_0.m_charbuffer->m_data, L"You can't use chat emotes in combat mode");
  return atexit(_E141_56);
}

//----- (007095A0) --------------------------------------------------------  // acclient.c:796600
int _E143_7()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't jump from this position");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_position_0, v0);
  _wcscpy(cant_jump_position_0.m_charbuffer->m_data, L"You can't jump from this position");
  return atexit(_E144_52);
}

//----- (007095E0) --------------------------------------------------------  // acclient.c:796611
int _E146_6()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't jump while in the air");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_in_air_0, v0);
  _wcscpy(cant_jump_in_air_0.m_charbuffer->m_data, L"You can't jump while in the air");
  return atexit(_E147_51);
}

//----- (00709620) --------------------------------------------------------  // acclient.c:796622
int _E149_6()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You're too loaded down to jump");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_load_0, v0);
  _wcscpy(cant_jump_load_0.m_charbuffer->m_data, L"You're too loaded down to jump");
  return atexit(_E150_50);
}

//----- (00709660) --------------------------------------------------------  // acclient.c:796633
int _E152_5()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You're too tired to jump!");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_stamina_0, v0);
  _wcscpy(cant_jump_stamina_0.m_charbuffer->m_data, L"You're too tired to jump!");
  return atexit(_E153_48);
}

//----- (007096A0) --------------------------------------------------------  // acclient.c:796644
int _E155_3()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You've jumped too recently!");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_recent_0, v0);
  _wcscpy(cant_jump_recent_0.m_charbuffer->m_data, L"You've jumped too recently!");
  return atexit(_E156_49);
}

//----- (007096E0) --------------------------------------------------------  // acclient.c:796655
int _E158_6()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You are too tired to move!");
  PStringBase<unsigned short>::allocate_ref_buffer(&too_tired_0, v0);
  _wcscpy(too_tired_0.m_charbuffer->m_data, L"You are too tired to move!");
  return atexit(_E159_47);
}

//----- (00709720) --------------------------------------------------------  // acclient.c:796666
int _E161_3()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_47, "Misc.TooltipEnable");
  return atexit(_E162_50);
}

//----- (00709740) --------------------------------------------------------  // acclient.c:796673
int _E164_7()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_47, "Misc.TooltipDelay");
  return atexit(_E165_46);
}

//----- (00709760) --------------------------------------------------------  // acclient.c:796680
int _E167_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_62, "None");
  return atexit(_E168_47);
}

//----- (00709780) --------------------------------------------------------  // acclient.c:796687
int _E170_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_62, "Speed");
  return atexit(_E171_46);
}

//----- (007097A0) --------------------------------------------------------  // acclient.c:796694
int _E173_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_62, "Noise");
  return atexit(_E174_48);
}

//----- (007097C0) --------------------------------------------------------  // acclient.c:796701
int _E176_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_62, "Sine");
  return atexit(_E177_45);
}

//----- (007097E0) --------------------------------------------------------  // acclient.c:796708
int _E179_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_62, "Square");
  return atexit(_E180_46);
}

//----- (00709800) --------------------------------------------------------  // acclient.c:796715
int _E182_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_62, "Bounce");
  return atexit(_E183_45);
}

//----- (00709820) --------------------------------------------------------  // acclient.c:796722
int _E185_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_62, "Perlin");
  return atexit(_E186_45);
}

//----- (00709840) --------------------------------------------------------  // acclient.c:796729
int _E188_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_62, "Fractal");
  return atexit(_E189_44);
}

//----- (00709860) --------------------------------------------------------  // acclient.c:796736
int _E191_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_62, "FrameLoop");
  return atexit(_E192_34);
}

//----- (00709880) --------------------------------------------------------  // acclient.c:796743
int _E194_7()
{
  g_rename_cache.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  return atexit(_E195_25);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (007098A0) --------------------------------------------------------  // acclient.c:796752
int sub_7098A0()
{
  return atexit(nullsub_1344);
}

//----- (00773C90) --------------------------------------------------------  // acclient.c:907434
void __cdecl _E129_60()
{
  char *v0; // esi@1

  v0 = (char *)&cant_sit_combat_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_sit_combat_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773CC0) --------------------------------------------------------  // acclient.c:907447
void __cdecl _E132_61()
{
  char *v0; // esi@1

  v0 = (char *)&cant_lie_down_combat_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_lie_down_combat_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773CF0) --------------------------------------------------------  // acclient.c:907460
void __cdecl _E135_69()
{
  char *v0; // esi@1

  v0 = (char *)&cant_crouch_combat_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_crouch_combat_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773D20) --------------------------------------------------------  // acclient.c:907473
void __cdecl _E138_54()
{
  char *v0; // esi@1

  v0 = (char *)&cant_emote_position_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_emote_position_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773D50) --------------------------------------------------------  // acclient.c:907486
void __cdecl _E141_56()
{
  char *v0; // esi@1

  v0 = (char *)&cant_emote_combat_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_emote_combat_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773D80) --------------------------------------------------------  // acclient.c:907499
void __cdecl _E144_52()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_position_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_position_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773DB0) --------------------------------------------------------  // acclient.c:907512
void __cdecl _E147_51()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_in_air_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_in_air_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773DE0) --------------------------------------------------------  // acclient.c:907525
void __cdecl _E150_50()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_load_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_load_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773E10) --------------------------------------------------------  // acclient.c:907538
void __cdecl _E153_48()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_stamina_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_stamina_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773E40) --------------------------------------------------------  // acclient.c:907551
void __cdecl _E156_49()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_recent_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_recent_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773E70) --------------------------------------------------------  // acclient.c:907564
void __cdecl _E159_47()
{
  char *v0; // esi@1

  v0 = (char *)&too_tired_0.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&too_tired_0.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773EA0) --------------------------------------------------------  // acclient.c:907577
void __cdecl _E162_50()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773ED0) --------------------------------------------------------  // acclient.c:907590
void __cdecl _E165_46()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773F00) --------------------------------------------------------  // acclient.c:907603
void __cdecl _E168_47()
{
  char *v0; // esi@1

  v0 = &waveform_None_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773F30) --------------------------------------------------------  // acclient.c:907616
void __cdecl _E171_46()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773F60) --------------------------------------------------------  // acclient.c:907629
void __cdecl _E174_48()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773F90) --------------------------------------------------------  // acclient.c:907642
void __cdecl _E177_45()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773FC0) --------------------------------------------------------  // acclient.c:907655
void __cdecl _E180_46()
{
  char *v0; // esi@1

  v0 = &waveform_Square_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773FF0) --------------------------------------------------------  // acclient.c:907668
void __cdecl _E183_45()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774020) --------------------------------------------------------  // acclient.c:907681
void __cdecl _E186_45()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774050) --------------------------------------------------------  // acclient.c:907694
void __cdecl _E189_44()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774080) --------------------------------------------------------  // acclient.c:907707
void __cdecl _E192_34()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_62.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_62.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007740B0) --------------------------------------------------------  // acclient.c:907720
void __cdecl _E195_25()
{
  AC1Legacy::PSRefBuffer<char> *v0; // esi@1

  v0 = g_rename_cache.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&g_rename_cache.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

