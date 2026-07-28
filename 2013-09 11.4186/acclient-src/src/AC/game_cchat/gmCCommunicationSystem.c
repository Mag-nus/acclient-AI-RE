/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCCommunicationSystem
   Object     : AC\game_cchat\gmCCommunicationSystem.obj
   Functions  : 80
   Addresses  : 00589000 - 007742E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00589000) --------------------------------------------------------  // acclient.c:433638
HRESULT __stdcall CCommunicationSystem::ChatInterfaceProvider::QueryInterface(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *riid, void **ppvObject)
{
  return -2147467263;
}

//----- (00589010) --------------------------------------------------------  // acclient.c:433644
CCommunicationSystem::ChatInterfaceProvider *__thiscall CCommunicationSystem::ChatInterfaceProvider::vector_deleting_destructor(CCommunicationSystem::ChatInterfaceProvider *this, unsigned int a2)
{
  CCommunicationSystem::ChatInterfaceProvider *v2; // esi@1

  v2 = this;
  this->vfptr = (IUnknownVtbl *)&CCommunicationSystem::ChatInterfaceProvider::vftable;
  this->vfptr = (IUnknownVtbl *)&CCommunicationSystem::ChatInterfaceProvider::vftable;
  this->vfptr = (IUnknownVtbl *)&CCommunicationSystem::ChatInterfaceProvider::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E2E90: using guessed type int (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int);
// 7E2EAC: using guessed type int (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int);
// 7E2EBC: using guessed type __int32 (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *riid, void **ppvObject);

//----- (00589040) --------------------------------------------------------  // acclient.c:433661
void __cdecl gmCCommunicationSystem::SetTalkFocus(unsigned int _focus)
{
  if ( CCommunicationSystem::s_pInstance )
    CCommunicationSystem::s_pInstance->mRoleplayChatRoomID = _focus;
}

//----- (00589060) --------------------------------------------------------  // acclient.c:433668
unsigned int __cdecl gmCCommunicationSystem::GetTalkFocus()
{
  unsigned int result; // eax@2

  if ( CCommunicationSystem::s_pInstance )
    result = CCommunicationSystem::s_pInstance->mRoleplayChatRoomID;
  else
    result = 1;
  return result;
}

//----- (00589080) --------------------------------------------------------  // acclient.c:433680
void __cdecl gmCCommunicationSystem::SetTalkFocusEnabled(unsigned int i_eFocus, int i_bEnabled)
{
  signed int v2; // esi@1
  unsigned int v3; // edi@1

  v2 = 1 << i_eFocus;
  v3 = CCommunicationSystem::s_pInstance->mOlthoiChatRoomID;
  if ( (_BYTE)i_bEnabled )
  {
    CCommunicationSystem::s_pInstance->mOlthoiChatRoomID = v2 | v3;
    CM_UI::SendNotice_EnableChatTargetSelection(i_eFocus, i_bEnabled);
  }
  else
  {
    CCommunicationSystem::s_pInstance->mOlthoiChatRoomID = ~v2 & v3;
    CM_UI::SendNotice_EnableChatTargetSelection(i_eFocus, i_bEnabled);
  }
}

//----- (005890D0) --------------------------------------------------------  // acclient.c:433700
bool __cdecl gmCCommunicationSystem::IsTalkFocusEnabled(unsigned int i_eFocus)
{
  return ((1 << i_eFocus) & CCommunicationSystem::s_pInstance->mOlthoiChatRoomID) != 0;
}

//----- (005890F0) --------------------------------------------------------  // acclient.c:433706
ChatRoomTracker *__cdecl gmCCommunicationSystem::GetChatRoomTracker()
{
  ChatRoomTracker *result; // eax@1

  result = CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
    result = (ChatRoomTracker *)CCommunicationSystem::s_pInstance[2].mSocietyRadBloChatRoomID;
  return result;
}

//----- (00589110) --------------------------------------------------------  // acclient.c:433717
int __cdecl gmCCommunicationSystem::SetChatRoomTracker(ChatRoomTracker *i_pChatTracker)
{
  int result; // eax@1

  result = (int)CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
  {
    ChatRoomTracker::operator=(CCommunicationSystem::s_pInstance[2].mSocietyRadBloChatRoomID, (int)i_pChatTracker);
    result = 1;
  }
  return result;
}

//----- (00589130) --------------------------------------------------------  // acclient.c:433731
void __cdecl gmCCommunicationSystem::SetWantsToBeInAllegChat(int wantsToBeInAllegChat)
{
  if ( CCommunicationSystem::s_pInstance )
    CCommunicationSystem::s_pInstance[3].vfptr = (PackObjVtbl *)wantsToBeInAllegChat;
}

//----- (00589150) --------------------------------------------------------  // acclient.c:433738
PackObjVtbl *__cdecl gmCCommunicationSystem::WantsToBeInAllegChat()
{
  PackObjVtbl *result; // eax@1

  result = (PackObjVtbl *)CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
    result = CCommunicationSystem::s_pInstance[3].vfptr;
  return result;
}

//----- (00589170) --------------------------------------------------------  // acclient.c:433749
void __cdecl gmCCommunicationSystem::SetLastSpeakableTarget(unsigned int i_iidTarget)
{
  if ( CCommunicationSystem::s_pInstance )
    CCommunicationSystem::s_pInstance[2].mTradeChatRoomID = i_iidTarget;
}

//----- (00589190) --------------------------------------------------------  // acclient.c:433756
unsigned int __cdecl gmCCommunicationSystem::GetLastSpeakableTarget()
{
  unsigned int result; // eax@1

  result = (unsigned int)CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
    result = CCommunicationSystem::s_pInstance[2].mTradeChatRoomID;
  return result;
}

//----- (005891A0) --------------------------------------------------------  // acclient.c:433767
void __cdecl gmCCommunicationSystem::SetLastTeller(unsigned int id)
{
  if ( CCommunicationSystem::s_pInstance )
    CCommunicationSystem::s_pInstance[2].mRoleplayChatRoomID = id;
}

//----- (005891C0) --------------------------------------------------------  // acclient.c:433774
unsigned int __cdecl gmCCommunicationSystem::GetLastTeller()
{
  unsigned int result; // eax@1

  result = (unsigned int)CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
    result = CCommunicationSystem::s_pInstance[2].mRoleplayChatRoomID;
  return result;
}

//----- (005891D0) --------------------------------------------------------  // acclient.c:433785
int __cdecl gmCCommunicationSystem::IsSquelched(const unsigned int char_iid, AC1Legacy::PStringBase<char> *account_name, const unsigned int msg_type)
{
  int result; // eax@2

  if ( CCommunicationSystem::s_pInstance )
  {
    if ( msg_type == 1 || (result = LogTextTypeEnumMapper::IsLegalChannel(msg_type)) != 0 )
      result = SquelchDB::IsSquelched(
                 (SquelchDB *)&CCommunicationSystem::s_pInstance->mSocietyChatRoomID,
                 char_iid,
                 account_name,
                 msg_type);
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00589220) --------------------------------------------------------  // acclient.c:433806
void __cdecl gmCCommunicationSystem::SetSquelchDB(SquelchDB *db)
{
  if ( CCommunicationSystem::s_pInstance )
  {
    SquelchDB::operator=((int)&CCommunicationSystem::s_pInstance->mSocietyChatRoomID, (int)db);
    CM_UI::SendNotice_UpdateSquelchPanel();
  }
}

//----- (00589240) --------------------------------------------------------  // acclient.c:433816
void __cdecl gmCCommunicationSystem::ClearSquelchDB()
{
  if ( CCommunicationSystem::s_pInstance )
  {
    SquelchDB::Clear((SquelchDB *)&CCommunicationSystem::s_pInstance->mSocietyChatRoomID);
    CM_UI::SendNotice_UpdateSquelchPanel();
  }
}

//----- (00589260) --------------------------------------------------------  // acclient.c:433826
PackableHashIterator<unsigned long,SquelchInfo> *__thiscall PackableHashIterator<unsigned long,SquelchInfo>::scalar_deleting_destructor(PackableHashIterator<unsigned long,SquelchInfo> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,SquelchInfo> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,SquelchInfo>Vtbl *)PackableHashIterator<unsigned long,SquelchInfo>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E2ED4: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SquelchInfo>::vftable[2])(void *, char);

//----- (00589280) --------------------------------------------------------  // acclient.c:433839
HRESULT __stdcall CCommunicationSystem::ChatInterfaceProvider::QueryInterface(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *a2, void **a3)
{
  return CCommunicationSystem::ChatInterfaceProvider::QueryInterface(
           (CCommunicationSystem::ChatInterfaceProvider *)((char *)this - 4),
           a2,
           a3);
}

//----- (00589290) --------------------------------------------------------  // acclient.c:433848
HRESULT __stdcall CCommunicationSystem::ChatInterfaceProvider::QueryInterface(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *a2, void **a3)
{
  return CCommunicationSystem::ChatInterfaceProvider::QueryInterface(
           (CCommunicationSystem::ChatInterfaceProvider *)((char *)this - 8),
           a2,
           a3);
}

//----- (005892A0) --------------------------------------------------------  // acclient.c:433857
PackableHashIterator<unsigned long,SquelchInfo> *__thiscall PackableHashTable<unsigned long,SquelchInfo>::begin(PackableHashTable<unsigned long,SquelchInfo> *this, PackableHashIterator<unsigned long,SquelchInfo> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,SquelchInfo> **v4; // edi@2
  PackableHashData<unsigned long,SquelchInfo> **v5; // esi@2
  PackableHashData<unsigned long,SquelchInfo> **v6; // ecx@5
  PackableHashIterator<unsigned long,SquelchInfo> *v7; // eax@5
  PackableHashData<unsigned long,SquelchInfo> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<unsigned long,SquelchInfo>Vtbl *)PackableHashIterator<unsigned long,SquelchInfo>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,SquelchInfo>Vtbl *)PackableHashIterator<unsigned long,SquelchInfo>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E2ED4: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SquelchInfo>::vftable[2])(void *, char);

//----- (00589300) --------------------------------------------------------  // acclient.c:433902
void __thiscall PackableHashIterator<unsigned long,SquelchInfo>::GetNext(PackableHashIterator<unsigned long,SquelchInfo> *this)
{
  PackableHashData<unsigned long,SquelchInfo> *v1; // eax@1
  PackableHashData<unsigned long,SquelchInfo> *v2; // edx@1
  unsigned int v3; // eax@3
  PackableHashData<unsigned long,SquelchInfo> **v4; // esi@4
  int v5; // edx@4

  v1 = this->_current;
  v2 = v1->_next;
  if ( v2 )
  {
    this->_current = v2;
  }
  else
  {
    v3 = v1->_hashVal + 1;
    if ( v3 >= this->_table_size )
    {
LABEL_7:
      this->_current = 0;
    }
    else
    {
      v4 = this->_buckets;
      v5 = (int)&v4[v3];
      while ( !*(_DWORD *)v5 )
      {
        ++v3;
        v5 += 4;
        if ( v3 >= this->_table_size )
          goto LABEL_7;
      }
      this->_current = v4[v3];
    }
  }
}

//----- (00589350) --------------------------------------------------------  // acclient.c:433941
void __thiscall SquelchInfo::InqName(SquelchInfo *this, AC1Legacy::PStringBase<char> *name)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  SquelchInfo *v3; // edi@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@5

  v2 = name->m_buffer;
  v3 = this;
  if ( name->m_buffer != this->_name.m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) )
    {
      if ( v2 )
        v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    }
    v4 = v3->_name.m_buffer;
    name->m_buffer = v4;
    InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  }
}

//----- (005893A0) --------------------------------------------------------  // acclient.c:433963
SquelchInfo *__thiscall SquelchInfo::vector_deleting_destructor(SquelchInfo *this, unsigned int a2)
{
  SquelchInfo *v2; // esi@1

  v2 = this;
  SquelchInfo::~SquelchInfo(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005893C0) --------------------------------------------------------  // acclient.c:433975
void __thiscall gmCCommunicationSystem::gmCCommunicationSystem(gmCCommunicationSystem *this)
{
  gmCCommunicationSystem *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1
  volatile LONG *v6; // ST00_4@1
  ChatRoomTracker *v7; // eax@1
  ChatRoomTracker *v8; // eax@2

  v1 = this;
  CCommunicationSystem::CCommunicationSystem((CCommunicationSystem *)&this->vfptr);
  v1->vfptr = (CCommunicationSystemVtbl *)&gmCCommunicationSystem::vftable;
  v1->talkFocus = 1;
  v1->m_uiAllowedTalkFocusBitmask = 2;
  SquelchDB::SquelchDB(&v1->_squelch_db);
  v1->chatSquelched = 0;
  v1->m_iidLastSpeakableTarget = 0;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->lastTelleeName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->lastTeller = 0;
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->lastTellerName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->lastAtMonarchUserName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->lastAtPatronUserName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v5);
  v6 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->system_message_string.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v6);
  v1->m_WantsToBeInAllegChat = 0;
  v7 = (ChatRoomTracker *)operator new(0x2Cu);
  if ( v7 )
  {
    ChatRoomTracker::ChatRoomTracker(v7);
    v1->crt = v8;
  }
  else
  {
    v1->crt = 0;
  }
}
// 7E2EEC: using guessed type int (__thiscall *gmCCommunicationSystem::vftable)(AC1Legacy::PStringBase<char> accountName, AC1Legacy::PStringBase<char> accountName);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00589480) --------------------------------------------------------  // acclient.c:434026
void __cdecl gmCCommunicationSystem::SetLastTelleeName(PStringBase<char> name)
{
  char *v1; // esi@2
  LONG v2; // eax@2
  char *v3; // edi@3
  unsigned int v4; // eax@3
  int v5; // esi@4

  if ( CCommunicationSystem::s_pInstance )
  {
    v3 = (char *)&CCommunicationSystem::s_pInstance[2].mLFGChatRoomID;
    v4 = CCommunicationSystem::s_pInstance[2].mLFGChatRoomID;
    if ( (PSRefBufferCharData<char> *)v4 != name.m_charbuffer )
    {
      v5 = v4 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v4 - 20 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      *(_DWORD *)v3 = name.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&name.m_charbuffer[-1]);
    }
    v1 = &name.m_charbuffer[-2].m_data[12];
    v2 = InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]);
  }
  else
  {
    v1 = &name.m_charbuffer[-2].m_data[12];
    v2 = InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]);
  }
  if ( !v2 )
  {
    if ( v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  }
}

//----- (00589500) --------------------------------------------------------  // acclient.c:434062
void __cdecl gmCCommunicationSystem::SetLastTellerName(PStringBase<char> *name)
{
  char *v1; // esi@2
  unsigned int v2; // eax@2
  int v3; // edi@3
  PSRefBufferCharData<char> *v4; // eax@6

  if ( CCommunicationSystem::s_pInstance )
  {
    v1 = (char *)&CCommunicationSystem::s_pInstance[2].mOlthoiChatRoomID;
    v2 = CCommunicationSystem::s_pInstance[2].mOlthoiChatRoomID;
    if ( (PSRefBufferCharData<char> *)v2 != name->m_charbuffer )
    {
      v3 = v2 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v2 - 20 + 4)) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
      v4 = name->m_charbuffer;
      *(_DWORD *)v1 = name->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v4[-1]);
    }
  }
}

//----- (00589550) --------------------------------------------------------  // acclient.c:434089
PStringBase<char> *__cdecl gmCCommunicationSystem::GetLastTellerName(PStringBase<char> *result)
{
  volatile LONG *v1; // ST00_4@2
  PStringBase<char> *v2; // eax@2
  unsigned int v3; // eax@3

  if ( CCommunicationSystem::s_pInstance )
  {
    v3 = CCommunicationSystem::s_pInstance[2].mOlthoiChatRoomID;
    result->m_charbuffer = (PSRefBufferCharData<char> *)v3;
    InterlockedIncrement((volatile LONG *)(v3 - 16));
    v2 = result;
  }
  else
  {
    v1 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement(v1);
    v2 = result;
  }
  return v2;
}

//----- (00589590) --------------------------------------------------------  // acclient.c:434113
void __cdecl gmCCommunicationSystem::SetLastAtMonarchUserName(AC1Legacy::PStringBase<char> name)
{
  unsigned int v1; // esi@5
  char *v2; // ebx@5

  if ( CCommunicationSystem::s_pInstance )
  {
    v1 = CCommunicationSystem::s_pInstance[2].mSocietyChatRoomID;
    v2 = (char *)&CCommunicationSystem::s_pInstance[2].mSocietyChatRoomID;
    if ( (AC1Legacy::PSRefBuffer<char> *)v1 != name.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v1 + 4)) && v1 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
      *(_DWORD *)v2 = name.m_buffer;
      InterlockedIncrement((volatile LONG *)&name.m_buffer->m_cRef);
    }
    if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) && name.m_buffer )
      name.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)name.m_buffer, 1u);
  }
  else if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) )
  {
    if ( name.m_buffer )
      name.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)name.m_buffer, 1u);
  }
}

//----- (00589610) --------------------------------------------------------  // acclient.c:434140
AC1Legacy::PStringBase<char> *__cdecl gmCCommunicationSystem::GetLastAtMonarchUserName(AC1Legacy::PStringBase<char> *result)
{
  volatile LONG *v1; // ST00_4@2
  AC1Legacy::PStringBase<char> *v2; // eax@2
  unsigned int v3; // eax@3

  if ( CCommunicationSystem::s_pInstance )
  {
    v3 = CCommunicationSystem::s_pInstance[2].mSocietyChatRoomID;
    result->m_buffer = (AC1Legacy::PSRefBuffer<char> *)v3;
    InterlockedIncrement((volatile LONG *)(v3 + 4));
    v2 = result;
  }
  else
  {
    v1 = (volatile LONG *)&AC1Legacy::PStringBase<char>::null_string.m_buffer->m_cRef;
    result->m_buffer = AC1Legacy::PStringBase<char>::null_string.m_buffer;
    InterlockedIncrement(v1);
    v2 = result;
  }
  return v2;
}

//----- (00589650) --------------------------------------------------------  // acclient.c:434164
void __cdecl gmCCommunicationSystem::SetLastAtPatronUserName(AC1Legacy::PStringBase<char> name)
{
  unsigned int v1; // esi@5
  char *v2; // ebx@5

  if ( CCommunicationSystem::s_pInstance )
  {
    v1 = CCommunicationSystem::s_pInstance[2].mSocietyCelHanChatRoomID;
    v2 = (char *)&CCommunicationSystem::s_pInstance[2].mSocietyCelHanChatRoomID;
    if ( (AC1Legacy::PSRefBuffer<char> *)v1 != name.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v1 + 4)) && v1 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
      *(_DWORD *)v2 = name.m_buffer;
      InterlockedIncrement((volatile LONG *)&name.m_buffer->m_cRef);
    }
    if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) && name.m_buffer )
      name.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)name.m_buffer, 1u);
  }
  else if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) )
  {
    if ( name.m_buffer )
      name.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)name.m_buffer, 1u);
  }
}

//----- (005896D0) --------------------------------------------------------  // acclient.c:434191
AC1Legacy::PStringBase<char> *__cdecl gmCCommunicationSystem::GetLastAtPatronUserName(AC1Legacy::PStringBase<char> *result)
{
  volatile LONG *v1; // ST00_4@2
  AC1Legacy::PStringBase<char> *v2; // eax@2
  unsigned int v3; // eax@3

  if ( CCommunicationSystem::s_pInstance )
  {
    v3 = CCommunicationSystem::s_pInstance[2].mSocietyCelHanChatRoomID;
    result->m_buffer = (AC1Legacy::PSRefBuffer<char> *)v3;
    InterlockedIncrement((volatile LONG *)(v3 + 4));
    v2 = result;
  }
  else
  {
    v1 = (volatile LONG *)&AC1Legacy::PStringBase<char>::null_string.m_buffer->m_cRef;
    result->m_buffer = AC1Legacy::PStringBase<char>::null_string.m_buffer;
    InterlockedIncrement(v1);
    v2 = result;
  }
  return v2;
}

//----- (00589710) --------------------------------------------------------  // acclient.c:434215
void __cdecl gmCCommunicationSystem::StartSquelchIteration()
{
  PackableHashIterator<unsigned long,SquelchInfo> result; // [sp+0h] [bp-10h]@1

  PackableHashTable<unsigned long,SquelchInfo>::begin(
    (PackableHashTable<unsigned long,SquelchInfo> *)&CCommunicationSystem::s_pInstance[1].mGeneralChatRoomID,
    &result);
  global_Squelch_Iter._current = result._current;
  global_Squelch_Iter._table_size = result._table_size;
  global_Squelch_Iter._buckets = result._buckets;
}

//----- (00589750) --------------------------------------------------------  // acclient.c:434228
CCommunicationSystem *__thiscall gmCCommunicationSystem::StartupTurbineChat_Internal(gmCCommunicationSystem *this, AC1Legacy::PStringBase<char> accountName)
{
  int v2; // eax@1
  CCommunicationSystem *v3; // ebx@1
  ClientCommunicationSystem *v4; // eax@2

  v3 = (CCommunicationSystem *)this;
  InterlockedIncrement((volatile LONG *)&accountName.m_buffer->m_cRef);
  v2 = CCommunicationSystem::StartupTurbineChat_Internal(v3, accountName);
  LOBYTE(v3) = v2 != 0;
  if ( v2 )
  {
    v4 = ClientCommunicationSystem::GetCommunicationSystem();
    if ( v4 )
      ClientCommunicationSystem::StartupTurbineChatSystem(v4);
  }
  v3 = (CCommunicationSystem *)(unsigned __int8)v3;
  if ( !InterlockedDecrement((volatile LONG *)&accountName.m_buffer->m_cRef) && accountName.m_buffer )
    accountName.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)accountName.m_buffer, 1u);
  return v3;
}

//----- (005897B0) --------------------------------------------------------  // acclient.c:434251
unsigned int __stdcall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::Release(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this)
{
  return ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&this->vfptr);
}

//----- (005897C0) --------------------------------------------------------  // acclient.c:434257
RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *__thiscall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::scalar_deleting_destructor(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this, unsigned int a2)
{
  RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *v2; // esi@1

  v2 = this;
  RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::~RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005897E0) --------------------------------------------------------  // acclient.c:434269
void __thiscall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::~RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this)
{
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  this->vfptr = (IUnknownVtbl *)&CCommunicationSystem::ChatInterfaceProvider::vftable;
  this->vfptr = (IUnknownVtbl *)&CCommunicationSystem::ChatInterfaceProvider::vftable;
  this->vfptr = (IUnknownVtbl *)&CCommunicationSystem::ChatInterfaceProvider::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7E2E90: using guessed type int (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int);
// 7E2EAC: using guessed type int (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int);
// 7E2EBC: using guessed type __int32 (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *riid, void **ppvObject);
// 7E2EF4: using guessed type int (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(int);

//----- (00589810) --------------------------------------------------------  // acclient.c:434284
LONG __stdcall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::AddRef(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this)
{
  return RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::AddRef((RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *)((char *)this - 4));
}

//----- (00589820) --------------------------------------------------------  // acclient.c:434290
unsigned int __stdcall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::Release(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this)
{
  return RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::Release((RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *)((char *)this - 4));
}

//----- (00589830) --------------------------------------------------------  // acclient.c:434296
LONG __stdcall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::AddRef(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this)
{
  return RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::AddRef((RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *)((char *)this - 8));
}

//----- (00589840) --------------------------------------------------------  // acclient.c:434302
unsigned int __stdcall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::Release(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this)
{
  return RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::Release((RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *)((char *)this - 8));
}

//----- (00589850) --------------------------------------------------------  // acclient.c:434308
RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *__thiscall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vector_deleting_destructor(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this, unsigned int a2)
{
  return RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::scalar_deleting_destructor(
           (RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *)((char *)this - 12),
           a2);
}

//----- (00589860) --------------------------------------------------------  // acclient.c:434316
int __cdecl gmCCommunicationSystem::CanHear(const unsigned int iid, const unsigned int msg_type)
{
  unsigned int v2; // ebx@1
  int result; // eax@2
  int v4; // edi@4
  unsigned int v5; // esi@5
  const unsigned int v6; // esi@9
  HashBaseData<unsigned long> *v7; // esi@14
  float v8; // ST18_4@15
  AC1Legacy::Vector3 point; // [sp+8h] [bp-Ch]@15

  v2 = iid;
  if ( *(float *)&iid == 0.0 )
  {
    result = 1;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&iid, &name);
    if ( CCommunicationSystem::s_pInstance )
    {
      v5 = msg_type;
      if ( msg_type == 1 || LogTextTypeEnumMapper::IsLegalChannel(msg_type) )
        v4 = SquelchDB::IsSquelched(
               (SquelchDB *)&CCommunicationSystem::s_pInstance->mSocietyChatRoomID,
               v2,
               (AC1Legacy::PStringBase<char> *)&iid,
               v5);
      else
        v4 = 0;
    }
    else
    {
      v4 = 1;
    }
    v6 = iid;
    if ( !InterlockedDecrement((volatile LONG *)(iid + 4)) && v6 )
      (**(void (__thiscall ***)(const unsigned int, signed int))v6)(v6, 1);
    result = 0;
    if ( !v4 )
    {
      v7 = ClientObjMaintSystem::GetPhysicsObject(v2);
      if ( !v7
        || (CPlayerSystem::GetPlayerSystem(),
            SmartBox::convert_to_player_space(SmartBox::smartbox, (CPhysicsObj *)v7, &point),
            v8 = point.y * point.y + point.x * point.x,
            *(float *)&iid = CPlayerSystem::GetRadarRadius(),
            CPlayerSystem::GetRadarRadius() * *(float *)&iid > v8) )
        result = 1;
    }
  }
  return result;
}

//----- (00589960) --------------------------------------------------------  // acclient.c:434371
int __cdecl gmCCommunicationSystem::NextSquelchIteration(AC1Legacy::PStringBase<char> *squelch_name, int *is_account)
{
  char *v2; // esi@3
  SquelchInfo sinfo; // [sp+0h] [bp-18h]@3

  if ( !CCommunicationSystem::s_pInstance || !global_Squelch_Iter._current )
    return 0;
  v2 = (char *)&global_Squelch_Iter._current->_data;
  sinfo.vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
  AC1Legacy::vlong::vlong(&sinfo._squelch_msgs, &global_Squelch_Iter._current->_data._squelch_msgs);
  sinfo._is_zone_squelch = *((_DWORD *)v2 + 4);
  sinfo._name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)*((_DWORD *)v2 + 5);
  InterlockedIncrement((volatile LONG *)&sinfo._name.m_buffer->m_cRef);
  if ( SquelchInfo::IsEmpty(&sinfo) )
  {
    SquelchInfo::~SquelchInfo(&sinfo);
    return 0;
  }
  SquelchInfo::InqName(&sinfo, squelch_name);
  *is_account = sinfo._is_zone_squelch;
  PackableHashIterator<unsigned long,SquelchInfo>::GetNext(&global_Squelch_Iter);
  SquelchInfo::~SquelchInfo(&sinfo);
  return 1;
}
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);

//----- (00589A00) --------------------------------------------------------  // acclient.c:434398
CCommunicationSystem::ChatInterfaceProvider *gmCCommunicationSystem::CreateChatInterfaceProvider()
{
  CCommunicationSystem::ChatInterfaceProvider *result; // eax@1

  result = (CCommunicationSystem::ChatInterfaceProvider *)operator new(0x14u);
  if ( result )
  {
    result[1].vfptr = (IUnknownVtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
    result[1].vfptr = (IUnknownVtbl *)1;
    result->vfptr = (IUnknownVtbl *)&RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable;
    result->vfptr = (IUnknownVtbl *)&RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable;
    result->vfptr = (IUnknownVtbl *)&RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable;
    result[1].vfptr = (IUnknownVtbl *)&RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7E2EF4: using guessed type int (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(int);
// 7E2EF8: using guessed type int (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int);
// 7E2F14: using guessed type int (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int);
// 7E2F24: using guessed type __int32 (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *riid, void **ppvObject);

//----- (00589A40) --------------------------------------------------------  // acclient.c:434425
PStringBase<char> *__cdecl gmCCommunicationSystem::GetLastTelleeName(PStringBase<char> *result)
{
  volatile LONG *v1; // ST00_4@2
  PStringBase<char> *v2; // eax@2
  unsigned int v3; // eax@3

  if ( CCommunicationSystem::s_pInstance )
  {
    v3 = CCommunicationSystem::s_pInstance[2].mLFGChatRoomID;
    result->m_charbuffer = (PSRefBufferCharData<char> *)v3;
    InterlockedIncrement((volatile LONG *)(v3 - 16));
    v2 = result;
  }
  else
  {
    v1 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v1);
    v2 = result;
  }
  return v2;
}

//----- (00589A80) --------------------------------------------------------  // acclient.c:434449
void __cdecl gmCCommunicationSystem::ConvertSQToPString(SquelchInfo *sinfo, AC1Legacy::PStringBase<char> *txt, const int force_all)
{
  AC1Legacy::PSRefBuffer<char> *v3; // ebx@2
  volatile LONG *v4; // edi@2
  SquelchInfo *v5; // edi@6
  AC1Legacy::PStringBase<char> *v6; // eax@11
  AC1Legacy::PStringBase<char> *v7; // ST18_4@11
  AC1Legacy::PStringBase<char> *v8; // eax@11
  AC1Legacy::PStringBase<char> *v9; // eax@11
  AC1Legacy::PStringBase<char> *v10; // eax@11
  AC1Legacy::PSRefBuffer<char> *v11; // eax@11
  unsigned int v12; // ecx@11
  AC1Legacy::PSRefBuffer<char> *v13; // esi@14
  int v14; // esi@17
  AC1Legacy::PSRefBuffer<char> *v15; // esi@20
  AC1Legacy::PSRefBuffer<char> *v16; // esi@23
  AC1Legacy::PSRefBuffer<char> *v17; // esi@26
  AC1Legacy::PSRefBuffer<char> *v18; // esi@31
  unsigned int v19; // eax@31
  AC1Legacy::PSRefBuffer<char> *v20; // esi@36
  unsigned int v21; // edi@37
  int v22; // eax@40
  int v23; // esi@40
  int v24; // eax@40
  int v25; // eax@40
  AC1Legacy::PSRefBuffer<char> *v26; // esi@40
  bool v27; // bl@40
  AC1Legacy::PSRefBuffer<char> *v28; // esi@43
  AC1Legacy::PSRefBuffer<char> *v29; // esi@49
  AC1Legacy::PSRefBuffer<char> *v30; // esi@52
  unsigned int v31; // eax@52
  LONG v32; // eax@36
  AC1Legacy::PStringBase<char> v33; // [sp+20h] [bp-41Ch]@11
  AC1Legacy::PStringBase<char> name; // [sp+24h] [bp-418h]@2
  AC1Legacy::PStringBase<char> rhs; // [sp+28h] [bp-414h]@11
  int first; // [sp+2Ch] [bp-410h]@11
  AC1Legacy::PStringBase<char> zone; // [sp+30h] [bp-40Ch]@8
  AC1Legacy::PStringBase<char> v38; // [sp+34h] [bp-408h]@11
  AC1Legacy::PStringBase<char> result; // [sp+38h] [bp-404h]@11
  char buf[1024]; // [sp+3Ch] [bp-400h]@40

  AC1Legacy::PStringBase<char>::set(txt, &::name);
  if ( !SquelchInfo::IsEmpty(sinfo) )
  {
    v3 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    if ( v3 == sinfo->_name.m_buffer )
    {
      v5 = sinfo;
    }
    else
    {
      if ( !InterlockedDecrement(v4) && v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
      v5 = sinfo;
      name.m_buffer = sinfo->_name.m_buffer;
      InterlockedIncrement((volatile LONG *)&name.m_buffer->m_cRef);
      v3 = name.m_buffer;
    }
    zone.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    if ( v5->_is_zone_squelch )
      AC1Legacy::PStringBase<char>::set(&zone, " (account) ");
    if ( v3->m_len != 1 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v33, " ");
      v7 = v6;
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v38, "Name: ");
      v9 = AC1Legacy::PStringBase<char>::operator+(v8, &result, &name);
      v10 = AC1Legacy::PStringBase<char>::operator+(v9, (AC1Legacy::PStringBase<char> *)&first, &zone);
      v11 = AC1Legacy::PStringBase<char>::operator+(v10, &rhs, v7)->m_buffer;
      v12 = v11->m_len;
      if ( v12 != 1 && v11 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(txt, v11->m_data, v12 - 1);
      v13 = rhs.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v13 )
        v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
      v14 = first;
      if ( !InterlockedDecrement((volatile LONG *)(first + 4)) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      v15 = result.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v15 )
        v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
      v16 = v38.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&v38.m_buffer->m_cRef) && v16 )
        v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
      v17 = v33.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&v33.m_buffer->m_cRef) && v17 )
        v17->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v17, 1u);
    }
    if ( force_all || !SquelchInfo::IsSquelched(v5, 1u) )
    {
      first = 1;
      v21 = 0;
      do
      {
        if ( SquelchInfo::IsSquelched(sinfo, v21) && LogTextTypeEnumMapper::IsLegalChannel(v21) )
        {
          LogTextTypeEnumMapper::LogTextTypeToString(v21, buf, 0x400u);
          AC1Legacy::PStringBase<char>::PStringBase<char>(&v38, "Unknown");
          v23 = v22;
          AC1Legacy::PStringBase<char>::PStringBase<char>(&v33, buf);
          v25 = __stricmp((const char *)(*(_DWORD *)v24 + 20), (const char *)(*(_DWORD *)v23 + 20));
          v26 = v33.m_buffer;
          v27 = v25 == 0;
          if ( !InterlockedDecrement((volatile LONG *)&v33.m_buffer->m_cRef) && v26 )
            v26->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v26, 1u);
          v28 = v38.m_buffer;
          if ( !InterlockedDecrement((volatile LONG *)&v38.m_buffer->m_cRef) && v28 )
            v28->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v28, 1u);
          if ( !v27 )
          {
            if ( first )
            {
              first = 0;
            }
            else
            {
              AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, ", ");
              AC1Legacy::PStringBase<char>::operator+=(txt, &rhs);
              v29 = rhs.m_buffer;
              if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v29 )
                v29->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v29, 1u);
            }
            AC1Legacy::PStringBase<char>::PStringBase<char>(&result, buf);
            v30 = result.m_buffer;
            v31 = result.m_buffer->m_len;
            if ( v31 != 1
              && result.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
              AC1Legacy::PStringBase<char>::append_n_chars(txt, result.m_buffer->m_data, v31 - 1);
            if ( !InterlockedDecrement((volatile LONG *)&v30->m_cRef) )
              v30->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v30, 1u);
          }
          v3 = name.m_buffer;
        }
        ++v21;
      }
      while ( v21 < 0x22 );
      v20 = zone.m_buffer;
      v32 = InterlockedDecrement((volatile LONG *)&zone.m_buffer->m_cRef);
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v33, "All message types");
      v18 = v33.m_buffer;
      v19 = v33.m_buffer->m_len;
      if ( v19 != 1 && v33.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(txt, v33.m_buffer->m_data, v19 - 1);
      if ( !InterlockedDecrement((volatile LONG *)&v18->m_cRef) )
        v18->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v18, 1u);
      v20 = zone.m_buffer;
      v32 = InterlockedDecrement((volatile LONG *)&zone.m_buffer->m_cRef);
    }
    if ( !v32 && v20 )
      v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00589E30) --------------------------------------------------------  // acclient.c:434613
void __stdcall gmCCommunicationSystem::uiChatInterfaceProvider::OnSendToRoomByIDResult(gmCCommunicationSystem::uiChatInterfaceProvider *this, HRESULT hAsyncResult, unsigned int dwRoomID, const unsigned __int16 *pwszText, tagBLOB localBlob)
{
  ClientSystem *v5; // eax@2
  char *v6; // esi@3
  PStringBase<unsigned short> out; // [sp+0h] [bp-4h]@1

  out.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( hAsyncResult )
  {
    PStringBase<unsigned short>::sprintf(&out, L"Failed to send text: [%ws] to room %X.\n", pwszText, dwRoomID);
    v5 = (ClientSystem *)ClientUISystem::GetUISystem();
    ClientSystem::AddTextToScroll(v5, &out, 0, 1, 0);
  }
  v6 = (char *)&out.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&out.m_charbuffer[-1].m_data[8]) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}

//----- (00589EB0) --------------------------------------------------------  // acclient.c:434636
int __cdecl gmCCommunicationSystem::GetListofSquelchChannels(PStringBase<char> *o_msg)
{
  AC1Legacy::PSRefBuffer<char> *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@4
  AC1Legacy::PStringBase<char> tmp; // [sp+8h] [bp-1Ch]@1
  SquelchInfo sinfo; // [sp+Ch] [bp-18h]@1

  AC1Legacy::PStringBase<char>::PStringBase<char>(&tmp, &name);
  SquelchInfo::SquelchInfo(&sinfo, &tmp, 1u);
  v1 = tmp.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&tmp.m_buffer->m_cRef) && v1 )
    v1->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v1, 1u);
  tmp.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  gmCCommunicationSystem::ConvertSQToPString(&sinfo, &tmp, 1);
  v2 = tmp.m_buffer;
  PStringBase<char>::sprintf(o_msg, "Squelch channels are as follows:\n  %s\n", tmp.m_buffer->m_data);
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  SquelchInfo::~SquelchInfo(&sinfo);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00589F60) --------------------------------------------------------  // acclient.c:434661
void __cdecl gmCCommunicationSystem::HandleRangedTalkEvent(AC1Legacy::PStringBase<char> *msg, AC1Legacy::PStringBase<char> *name, const unsigned int sender_id, float range, const unsigned int ltt)
{
  AC1Legacy::PSRefBuffer<char> *v5; // ecx@0
  int v6; // ebx@3
  AC1Legacy::PSRefBuffer<char> *v7; // edi@3
  const char *_range; // ST08_4@12
  ClientSystem *v9; // eax@12
  AC1Legacy::PStringBase<char> txtmsg; // [sp+24h] [bp-4h]@1

  txtmsg.m_buffer = v5;
  if ( SmartBox::smartbox->player && sender_id )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&txtmsg, &::name);
    v6 = gmCCommunicationSystem::IsSquelched(sender_id, &txtmsg, ltt);
    v7 = txtmsg.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&txtmsg.m_buffer->m_cRef) && v7 )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    if ( !v6 && ACCWeenieObject::ObjectsInRange(SmartBox::smartbox->player_id, sender_id, range, 0, 0) )
    {
      txtmsg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      if ( sender_id < 0x50000001 || sender_id > 0x6FFFFFFF )
        AC1Legacy::PStringBase<char>::sprintf(
          &txtmsg,
          "%s says, \"%s\"\n",
          name->m_buffer->m_data,
          msg->m_buffer->m_data);
      else
        AC1Legacy::PStringBase<char>::sprintf(
          &txtmsg,
          "<Tell:IIDString:%d:%s>%s<\\Tell> says, \"%s\"\n",
          sender_id,
          name->m_buffer->m_data,
          name->m_buffer->m_data,
          msg->m_buffer->m_data);
      _range = txtmsg.m_buffer->m_data;
      v9 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v9, _range, ltt, 1, 0);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&txtmsg);
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0058A0A0) --------------------------------------------------------  // acclient.c:434706
int __cdecl gmCCommunicationSystem::DoGlobalSquelchQuery()
{
  int result; // eax@2
  char *v1; // esi@3
  AC1Legacy::PSRefBuffer<char> *v2; // eax@4
  int v3; // ecx@4
  LONG (__stdcall *v4)(volatile LONG *); // ebx@6
  int v5; // esi@6
  AC1Legacy::PSRefBuffer<char> *v6; // edi@9
  const unsigned __int16 **v7; // eax@9
  const unsigned __int16 *v8; // eax@9
  int v9; // ecx@9
  char *v10; // esi@11
  AC1Legacy::PSRefBuffer<char> *v11; // eax@17
  int v12; // ecx@17
  int v13; // esi@19
  AC1Legacy::PSRefBuffer<char> *v14; // eax@22
  int v15; // ecx@22
  int v16; // esi@24
  ClientSystem *v17; // eax@27
  char *v18; // esi@27
  PStringBase<unsigned short> msg; // [sp+10h] [bp-20h]@3
  AC1Legacy::PStringBase<char> tmp; // [sp+14h] [bp-1Ch]@4
  SquelchInfo global_info; // [sp+18h] [bp-18h]@3

  if ( CCommunicationSystem::s_pInstance )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &msg,
      L"The following types of messages are currently being filtered globally:\n");
    v1 = (char *)&CCommunicationSystem::s_pInstance[1].mSocietyChatRoomID;
    global_info.vfptr = (PackObjVtbl *)&SquelchInfo::vftable;
    AC1Legacy::vlong::vlong(
      &global_info._squelch_msgs,
      (AC1Legacy::vlong *)&CCommunicationSystem::s_pInstance[1].mSocietyCelHanChatRoomID);
    global_info._is_zone_squelch = *((_DWORD *)v1 + 4);
    global_info._name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)*((_DWORD *)v1 + 5);
    InterlockedIncrement((volatile LONG *)&global_info._name.m_buffer->m_cRef);
    if ( SquelchInfo::IsEmpty(&global_info) )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&tmp, L"none");
      v2 = tmp.m_buffer;
      v3 = *(_DWORD *)&tmp.m_buffer[-1].m_data[0];
      if ( v3 != 1 )
      {
        PStringBase<unsigned short>::append_n_chars(&msg, (const unsigned __int16 *)tmp.m_buffer, v3 - 1);
        v2 = tmp.m_buffer;
      }
      v4 = InterlockedDecrement;
      v5 = (int)&v2[-1].m_cRef;
      if ( !InterlockedDecrement((volatile LONG *)&v2[-1].m_cRef + 1) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    else
    {
      tmp.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      gmCCommunicationSystem::ConvertSQToPString(&global_info, &tmp, 0);
      v6 = tmp.m_buffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&tmp,
        0,
        tmp.m_buffer->m_data);
      v8 = *v7;
      v9 = *((_DWORD *)v8 - 1);
      if ( v9 != 1 )
        PStringBase<unsigned short>::append_n_chars(&msg, v8, v9 - 1);
      v4 = InterlockedDecrement;
      v10 = (char *)&tmp.m_buffer[-1].m_cRef;
      if ( !InterlockedDecrement((volatile LONG *)&tmp.m_buffer[-1].m_cRef + 1) && v10 )
        (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
      if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    }
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&tmp, L"\n");
    v11 = tmp.m_buffer;
    v12 = *(_DWORD *)&tmp.m_buffer[-1].m_data[0];
    if ( v12 != 1 )
    {
      PStringBase<unsigned short>::append_n_chars(&msg, (const unsigned __int16 *)tmp.m_buffer, v12 - 1);
      v11 = tmp.m_buffer;
    }
    v13 = (int)&v11[-1].m_cRef;
    if ( !v4((volatile LONG *)&v11[-1].m_cRef + 1) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&tmp,
      L"(For a list of filter options, type @help filter)\n");
    v14 = tmp.m_buffer;
    v15 = *(_DWORD *)&tmp.m_buffer[-1].m_data[0];
    if ( v15 != 1 )
    {
      PStringBase<unsigned short>::append_n_chars(&msg, (const unsigned __int16 *)tmp.m_buffer, v15 - 1);
      v14 = tmp.m_buffer;
    }
    v16 = (int)&v14[-1].m_cRef;
    if ( !v4((volatile LONG *)&v14[-1].m_cRef + 1) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    v17 = (ClientSystem *)ClientUISystem::GetUISystem();
    ClientSystem::AddTextToScroll(v17, &msg, 0, 1, 0);
    SquelchInfo::~SquelchInfo(&global_info);
    v18 = (char *)&msg.m_charbuffer[-1].m_data[6];
    if ( !v4((volatile LONG *)&msg.m_charbuffer[-1].m_data[8]) )
    {
      if ( v18 )
        (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E2ED8: using guessed type int (__thiscall *SquelchInfo::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0058A2C0) --------------------------------------------------------  // acclient.c:434825
int __cdecl gmCCommunicationSystem::DoSquelchQuery()
{
  int v0; // eax@2
  AC1Legacy::PSRefBuffer<char> *v1; // ebx@3
  PackableHashData<unsigned long,SquelchInfo> *v2; // edi@3
  AC1Legacy::PSRefBuffer<char> *v3; // esi@4
  unsigned int v4; // eax@4
  LONG (__stdcall *v5)(volatile LONG *); // ebp@7
  AC1Legacy::PSRefBuffer<char> *v6; // esi@9
  unsigned int v7; // eax@9
  PackableHashData<unsigned long,SquelchInfo> **v8; // ebx@14
  AC1Legacy::PStringBase<char> *v9; // eax@15
  AC1Legacy::PStringBase<char> *v10; // ST10_4@15
  AC1Legacy::PStringBase<char> *v11; // eax@15
  AC1Legacy::PStringBase<char> *v12; // eax@15
  AC1Legacy::PSRefBuffer<char> *v13; // eax@15
  unsigned int v14; // ecx@15
  AC1Legacy::PSRefBuffer<char> *v15; // esi@18
  AC1Legacy::PSRefBuffer<char> *v16; // esi@21
  AC1Legacy::PSRefBuffer<char> *v17; // esi@24
  AC1Legacy::PSRefBuffer<char> *v18; // esi@27
  PackableHashData<unsigned long,SquelchInfo> *v19; // eax@30
  unsigned int v20; // eax@31
  unsigned int v21; // eax@37
  AC1Legacy::PSRefBuffer<char> *v22; // edi@40
  PStringBase<unsigned short> *v23; // eax@40
  PStringBase<unsigned short> *v24; // ST04_4@40
  ClientSystem *v25; // eax@40
  char *v26; // esi@40
  AC1Legacy::PSRefBuffer<char> *v27; // esi@46
  AC1Legacy::PStringBase<char> character; // [sp+1Ch] [bp-2Ch]@3
  AC1Legacy::PStringBase<char> tmp; // [sp+20h] [bp-28h]@3
  AC1Legacy::PStringBase<char> final; // [sp+24h] [bp-24h]@3
  AC1Legacy::PStringBase<char> v31; // [sp+28h] [bp-20h]@9
  AC1Legacy::PStringBase<char> result; // [sp+2Ch] [bp-1Ch]@15
  AC1Legacy::PStringBase<char> v33; // [sp+30h] [bp-18h]@15
  AC1Legacy::PStringBase<char> v34; // [sp+34h] [bp-14h]@15
  PackableHashIterator<unsigned long,SquelchInfo> char_iter; // [sp+38h] [bp-10h]@3

  if ( CCommunicationSystem::s_pInstance )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      &final,
      "(account) denotes a character whose account has also been squelched.\nFormat: Name : List of squelched message types.\n--------\n");
    character.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v1 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    tmp.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    PackableHashTable<unsigned long,SquelchInfo>::begin(
      (PackableHashTable<unsigned long,SquelchInfo> *)&CCommunicationSystem::s_pInstance[1].mGeneralChatRoomID,
      &char_iter);
    v2 = char_iter._current;
    if ( char_iter._current )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v31, "\n");
      v6 = v31.m_buffer;
      v7 = v31.m_buffer->m_len;
      if ( v7 != 1 && v31.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(&character, v31.m_buffer->m_data, v7 - 1);
      v5 = InterlockedDecrement;
      if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
      v8 = char_iter._buckets;
      do
      {
        gmCCommunicationSystem::ConvertSQToPString(&v2->_data, &tmp, 0);
        AC1Legacy::PStringBase<char>::PStringBase<char>(&v34, "\n");
        v10 = v9;
        AC1Legacy::PStringBase<char>::PStringBase<char>(&v33, "  ");
        v12 = AC1Legacy::PStringBase<char>::operator+(v11, &result, &tmp);
        v13 = AC1Legacy::PStringBase<char>::operator+(v12, &v31, v10)->m_buffer;
        v14 = v13->m_len;
        if ( v14 != 1 && v13 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
          AC1Legacy::PStringBase<char>::append_n_chars(&character, v13->m_data, v14 - 1);
        v15 = v31.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&v31.m_buffer->m_cRef) && v15 )
          v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
        v16 = result.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v16 )
          v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
        v17 = v33.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&v33.m_buffer->m_cRef) && v17 )
          v17->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v17, 1u);
        v18 = v34.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&v34.m_buffer->m_cRef) && v18 )
          v18->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v18, 1u);
        v19 = v2->_next;
        if ( !v19 )
        {
          v20 = v2->_hashVal + 1;
          if ( v20 >= char_iter._table_size )
          {
LABEL_34:
            v19 = 0;
          }
          else
          {
            while ( !v8[v20] )
            {
              ++v20;
              if ( v20 >= char_iter._table_size )
                goto LABEL_34;
            }
            v19 = v8[v20];
          }
        }
        v2 = v19;
      }
      while ( v19 );
      v1 = tmp.m_buffer;
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&tmp, "none\n");
      v3 = tmp.m_buffer;
      v4 = tmp.m_buffer->m_len;
      if ( v4 != 1 && tmp.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(&character, tmp.m_buffer->m_data, v4 - 1);
      v5 = InterlockedDecrement;
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    }
    v21 = character.m_buffer->m_len;
    if ( v21 != 1 && character.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&final, character.m_buffer->m_data, v21 - 1);
    v22 = final.m_buffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&v34,
      0,
      final.m_buffer->m_data);
    v24 = v23;
    v25 = (ClientSystem *)ClientUISystem::GetUISystem();
    ClientSystem::AddTextToScroll(v25, v24, 0, 1, 0);
    v26 = (char *)&v34.m_buffer[-1].m_cRef;
    if ( !v5((volatile LONG *)&v34.m_buffer[-1].m_cRef + 1) && v26 )
      (**(void (__thiscall ***)(char *, signed int))v26)(v26, 1);
    if ( !v5((volatile LONG *)&v1->m_cRef) && v1 )
      v1->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v1, 1u);
    v27 = character.m_buffer;
    if ( !v5((volatile LONG *)&character.m_buffer->m_cRef) )
      v27->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v27, 1u);
    if ( !v5((volatile LONG *)&v22->m_cRef) )
    {
      if ( v22 )
        v22->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v22, 1u);
    }
    v0 = 1;
  }
  else
  {
    v0 = 0;
  }
  return v0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0058A590) --------------------------------------------------------  // acclient.c:434983
void __stdcall gmCCommunicationSystem::uiChatInterfaceProvider::OnSendToRoom(gmCCommunicationSystem::uiChatInterfaceProvider *this, unsigned int dwRoomID, const unsigned __int16 *pwszDisplayName, const unsigned __int16 *pwszText, tagBLOB extraInfoBlob)
{
  unsigned int v5; // eax@1
  int v6; // ebx@1
  int v7; // eax@2
  LONG (__stdcall *v8)(volatile LONG *); // edi@2
  const unsigned __int16 *v9; // esi@2
  bool v10; // bl@2
  int v11; // eax@7
  bool v12; // bl@9
  const unsigned __int16 *v13; // esi@9
  AC1Legacy::PStringBase<unsigned short> v14; // edi@12
  ChatRoomTracker *v15; // eax@13
  const char *v16; // esi@16
  unsigned int v17; // ST08_4@16
  PStringBase<unsigned short> *v18; // eax@16
  PStringBase<unsigned short> *v19; // ST04_4@16
  ClientSystem *v20; // eax@16
  AC1Legacy::PSRefBuffer<char> *v21; // esi@17
  LONG (__stdcall *v22)(volatile LONG *); // ebx@17
  AC1Legacy::PSRefBuffer<char> *v23; // esi@21
  unsigned int v24; // esi@24
  AC1Legacy::PSRefBuffer<char> *v25; // esi@35
  unsigned int v26; // esi@38
  AC1Legacy::PSRefBuffer<unsigned short> *v27; // esi@41
  unsigned int v28; // [sp+0h] [bp-30h]@13
  AC1Legacy::PStringBase<char> out; // [sp+14h] [bp-1Ch]@1
  AC1Legacy::PStringBase<char> narrowText; // [sp+18h] [bp-18h]@1
  AC1Legacy::PStringBase<unsigned short> sender; // [sp+1Ch] [bp-14h]@1
  unsigned int speakerID; // [sp+20h] [bp-10h]@1
  ChatDisplayInfo cdi; // [sp+24h] [bp-Ch]@15

  v5 = CommandList::GetHead((ChatDisplayInfo *)extraInfoBlob.pBlobData);
  v6 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  speakerID = v5;
  out.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&sender, pwszDisplayName);
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    (AC1Legacy::PStringBase<unsigned short> *)&extraInfoBlob,
    pwszText);
  PSUtils::narrowify(&narrowText, (AC1Legacy::PStringBase<unsigned short> *)&extraInfoBlob);
  if ( ClientCommunicationSystem::GetCommunicationSystem() )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&pwszDisplayName, narrowText.m_buffer->m_data);
    v7 = ClientCommunicationSystem::IsMessageSafe((PStringBase<char> *)&pwszDisplayName);
    v8 = InterlockedDecrement;
    v9 = pwszDisplayName - 10;
    v10 = v7 == 0;
    if ( !InterlockedDecrement((volatile LONG *)pwszDisplayName - 4) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    if ( !v10 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&pwszDisplayName, &name);
      if ( CCommunicationSystem::s_pInstance )
        v11 = SquelchDB::IsSquelched(
                (SquelchDB *)&CCommunicationSystem::s_pInstance->mSocietyChatRoomID,
                speakerID,
                (AC1Legacy::PStringBase<char> *)&pwszDisplayName,
                1u);
      else
        v11 = 1;
      v12 = v11 == 0;
      v13 = pwszDisplayName;
      if ( !InterlockedDecrement((volatile LONG *)pwszDisplayName + 1) && v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      v14.m_buffer = sender.m_buffer;
      if ( v12 )
      {
        v28 = extraInfoBlob.cbSize;
        InterlockedIncrement((volatile LONG *)(extraInfoBlob.cbSize + 4));
        InterlockedIncrement((volatile LONG *)&v14.m_buffer->m_cRef);
        v15 = CCommunicationSystem::s_pInstance;
        if ( CCommunicationSystem::s_pInstance )
          v15 = (ChatRoomTracker *)CCommunicationSystem::s_pInstance[2].mSocietyRadBloChatRoomID;
        ChatRoomTracker::GetChatFormat(v15, &cdi, dwRoomID, v14, (AC1Legacy::PStringBase<unsigned short>)v28);
        if ( HookAppraisalProfile::GetValidLocations(&cdi) )
        {
          v16 = ChatDisplayInfo::GetDisplayText(&cdi, (AC1Legacy::PStringBase<char> *)&pwszText)->m_buffer->m_data;
          v17 = CommandList::GetHead(&cdi);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&pwszDisplayName,
            0,
            v16);
          v19 = v18;
          v20 = (ClientSystem *)ClientUISystem::GetUISystem();
          ClientSystem::AddTextToScroll(v20, v19, v17, 1, 0);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&pwszDisplayName);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&pwszText);
        }
        v21 = cdi.m_display.m_buffer;
        v22 = InterlockedDecrement;
        if ( !InterlockedDecrement((volatile LONG *)&cdi.m_display.m_buffer->m_cRef) && v21 )
          v21->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v21, 1u);
      }
      else
      {
        v22 = InterlockedDecrement;
      }
      v23 = narrowText.m_buffer;
      if ( !v22((volatile LONG *)&narrowText.m_buffer->m_cRef) && v23 )
        v23->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v23, 1u);
      v24 = extraInfoBlob.cbSize;
      if ( !v22((volatile LONG *)(extraInfoBlob.cbSize + 4)) && v24 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
      if ( !v22((volatile LONG *)&v14.m_buffer->m_cRef) && v14.m_buffer )
        v14.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14.m_buffer, 1u);
      if ( !v22((volatile LONG *)&out.m_buffer->m_cRef) )
      {
        if ( out.m_buffer )
          ((void (__stdcall *)(_DWORD))out.m_buffer->vfptr->__vecDelDtor)(1);
      }
      return;
    }
    v6 = (int)out.m_buffer;
  }
  else
  {
    v8 = InterlockedDecrement;
  }
  v25 = narrowText.m_buffer;
  if ( !v8((volatile LONG *)&narrowText.m_buffer->m_cRef) && v25 )
    v25->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v25, 1u);
  v26 = extraInfoBlob.cbSize;
  if ( !v8((volatile LONG *)(extraInfoBlob.cbSize + 4)) && v26 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  v27 = sender.m_buffer;
  if ( !v8((volatile LONG *)&sender.m_buffer->m_cRef) && v27 )
    v27->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v27, 1u);
  if ( !v8((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006BF830) --------------------------------------------------------  // acclient.c:727530
LONG __stdcall RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::AddRef(RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider> *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cRef);
}

//----- (00709DB0) --------------------------------------------------------  // acclient.c:797106
int sub_709DB0()
{
  return atexit(nullsub_1389);
}

//----- (00709DC0) --------------------------------------------------------  // acclient.c:797112
int _E4_5()
{
  return atexit(_E5_5);
}

//----- (00709DD0) --------------------------------------------------------  // acclient.c:797118
int _E7_5()
{
  Outside_CellID_5.id = Invalid_CellID_5.id + 1;
  return atexit(_E8_5);
}

//----- (00709DF0) --------------------------------------------------------  // acclient.c:797125
int _E10_4()
{
  In_Limbo_CellID_4.id = Outside_CellID_5.id + 1;
  return atexit(_E11_4);
}

//----- (00709E10) --------------------------------------------------------  // acclient.c:797132
int _E13_4()
{
  First_Interior_CellID_4.id = In_Limbo_CellID_4.id + 1;
  return atexit(_E14_4);
}

//----- (00709E30) --------------------------------------------------------  // acclient.c:797139
int _E16_4()
{
  Last_Interior_CellID_4.id = Invalid_CellID_5.id - 1;
  return atexit(_E17_4);
}

//----- (00709E50) --------------------------------------------------------  // acclient.c:797146
int _E21_6()
{
  return atexit(_E22_6);
}

//----- (00709E60) --------------------------------------------------------  // acclient.c:797152
int _E40_4()
{
  return atexit(_E41_4);
}

//----- (00709E70) --------------------------------------------------------  // acclient.c:797158
int _E43_5()
{
  return atexit(_E44_5);
}

//----- (00709E80) --------------------------------------------------------  // acclient.c:797164
void _E92_5()
{
  LODWORD(dword_870C44) = 1053364187;
}

//----- (00709E90) --------------------------------------------------------  // acclient.c:797170
void _E94_29()
{
  flt_870BD4 = 1000.0 + 1.0;
}

//----- (00709EB0) --------------------------------------------------------  // acclient.c:797176
void _E96_1()
{
  flt_870C5C = 24.0 * 8.0;
}

//----- (00709ED0) --------------------------------------------------------  // acclient.c:797182
void _E98_16()
{
  flt_870C38 = 24.0 * 0.5;
}

//----- (00709EF0) --------------------------------------------------------  // acclient.c:797188
int sub_709EF0()
{
  return atexit(nullsub_1396);
}

//----- (00709F00) --------------------------------------------------------  // acclient.c:797194
int sub_709F00()
{
  return atexit(nullsub_1397);
}

//----- (00709F10) --------------------------------------------------------  // acclient.c:797200
int sub_709F10()
{
  return atexit(_E107_96);
}

//----- (00709F20) --------------------------------------------------------  // acclient.c:797206
void _E109_75()
{
  flt_870C3C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00709F40) --------------------------------------------------------  // acclient.c:797212
void _E111_50()
{
  dbl_870BF0 = 1.0 / 30.0;
}

//----- (00709F60) --------------------------------------------------------  // acclient.c:797218
void _E113_27()
{
  dbl_870BE0 = 1.0 / 5.0;
}

//----- (00709F80) --------------------------------------------------------  // acclient.c:797224
void _E115_81()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870BF8, PFID_A8R8G8B8);
}

//----- (00709F90) --------------------------------------------------------  // acclient.c:797230
void _E118_77()
{
  dword_870C30 = 1024;
}

//----- (00709FA0) --------------------------------------------------------  // acclient.c:797236
void _E120_69()
{
  dword_870C34 = 0x7FFF;
}

//----- (00709FB0) --------------------------------------------------------  // acclient.c:797242
int _E122_33()
{
  const int result; // eax@1

  result = dword_870C30;
  dword_870C58 = dword_870C30;
  return result;
}

//----- (00709FC0) --------------------------------------------------------  // acclient.c:797252
int _E124_68()
{
  return atexit(_E125_65);
}

//----- (00709FD0) --------------------------------------------------------  // acclient.c:797258
int _E127_57()
{
  return atexit(_E128_63);
}

//----- (007742E0) --------------------------------------------------------  // acclient.c:907733
void __cdecl _E128_63()
{
  global_Squelch_Iter.vfptr = (PackableHashIterator<unsigned long,SquelchInfo>Vtbl *)PackableHashIterator<unsigned long,SquelchInfo>::vftable;
}
// 7E2ED4: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SquelchInfo>::vftable[2])(void *, char);

