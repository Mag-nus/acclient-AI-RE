/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ChatRoomTracker
   Object     : AC\turbinechat\ChatRoomTracker.obj
   Functions  : 15
   Addresses  : 00489D70 - 006BC230 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00489D70) --------------------------------------------------------  // acclient.c:197459
AC1Legacy::PStringBase<unsigned short> *__thiscall AC1Legacy::PStringBase<unsigned short>::operator=(AC1Legacy::PStringBase<unsigned short> *this, AC1Legacy::PStringBase<unsigned short> *rhs)
{
  AC1Legacy::PStringBase<unsigned short> *v2; // esi@1
  AC1Legacy::PSRefBuffer<unsigned short> *v3; // edi@1
  AC1Legacy::PSRefBuffer<unsigned short> *v4; // eax@5

  v2 = this;
  v3 = this->m_buffer;
  if ( this->m_buffer != rhs->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    v4 = rhs->m_buffer;
    v2->m_buffer = rhs->m_buffer;
    InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  }
  return v2;
}

//----- (004F1880) --------------------------------------------------------  // acclient.c:285663
unsigned int __thiscall AnimSequenceNode::get_high_frame(ChatRoomTracker *this)
{
  return this->mOlthoiChatRoomID;
}

//----- (004F2650) --------------------------------------------------------  // acclient.c:286428
unsigned int __thiscall PhysicsDesc::get_animframe_id(ChatRoomTracker *this)
{
  return this->mRoleplayChatRoomID;
}

//----- (0051D440) --------------------------------------------------------  // acclient.c:331290
unsigned int __thiscall PhysicsDesc::get_autonomous_movement(ChatRoomTracker *this)
{
  return this->mLFGChatRoomID;
}

//----- (0051D4B0) --------------------------------------------------------  // acclient.c:331332
int __thiscall HookAppraisalProfile::GetValidLocations(ChatDisplayInfo *this)
{
  return this->m_doDisplayText;
}

//----- (0051D4C0) --------------------------------------------------------  // acclient.c:331338
unsigned int __thiscall ChatRoomTracker::GetGlobalTradeRoomID(ChatRoomTracker *this)
{
  return this->mTradeChatRoomID;
}

//----- (00526EE0) --------------------------------------------------------  // acclient.c:342518
signed int ChatRoomTracker::GetPackSize()
{
  return 40;
}

//----- (005CD5D0) --------------------------------------------------------  // acclient.c:505486
void __thiscall ChatRoomTracker::ChatRoomTracker(ChatRoomTracker *this)
{
  this->vfptr = (PackObjVtbl *)&ChatRoomTracker::vftable;
  this->m_allegianceRoomID = 0;
  this->mGeneralChatRoomID = 0;
  this->mTradeChatRoomID = 0;
  this->mLFGChatRoomID = 0;
  this->mRoleplayChatRoomID = 0;
  this->mOlthoiChatRoomID = 0;
  this->mSocietyChatRoomID = 0;
  this->mSocietyCelHanChatRoomID = 0;
  this->mSocietyEldWebChatRoomID = 0;
  this->mSocietyRadBloChatRoomID = 0;
}
// 7E83D4: using guessed type int (__thiscall *ChatRoomTracker::vftable)(void *, char);

//----- (005CD600) --------------------------------------------------------  // acclient.c:505503
int __thiscall ChatRoomTracker::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  return result;
}

//----- (005CD650) --------------------------------------------------------  // acclient.c:505522
unsigned int __thiscall ChatRoomTracker::Pack(ChatRoomTracker *this, void **addr, unsigned int size)
{
  ChatRoomTracker *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edi@2
  char *v6; // edx@2
  char *v7; // edi@2
  char *v8; // edx@2
  char *v9; // edi@2
  char *v10; // edx@2
  char *v11; // edi@2
  char *v12; // edx@2
  char *v13; // edi@2

  v3 = this;
  result = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->m_allegianceRoomID;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->mGeneralChatRoomID;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->mTradeChatRoomID;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->mLFGChatRoomID;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->mRoleplayChatRoomID;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->mOlthoiChatRoomID;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->mSocietyChatRoomID;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->mSocietyCelHanChatRoomID;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->mSocietyEldWebChatRoomID;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(_DWORD *)v13 = v3->mSocietyRadBloChatRoomID;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (005CD6F0) --------------------------------------------------------  // acclient.c:505574
int __thiscall ChatRoomTracker::UnPack(ChatRoomTracker *this, void **addr, unsigned int size)
{
  ChatRoomTracker *v3; // esi@1
  int result; // eax@2
  char *v5; // edx@3
  char *v6; // ecx@3
  char *v7; // edx@3
  char *v8; // ecx@3
  char *v9; // edx@3
  char *v10; // ecx@3
  char *v11; // edx@3
  char *v12; // ecx@3
  char *v13; // edx@3

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() )
  {
    v3->m_allegianceRoomID = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v3->mGeneralChatRoomID = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v3->mTradeChatRoomID = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    v3->mLFGChatRoomID = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    v3->mRoleplayChatRoomID = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    v3->mOlthoiChatRoomID = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    v3->mSocietyChatRoomID = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    v3->mSocietyCelHanChatRoomID = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    v3->mSocietyEldWebChatRoomID = *(_DWORD *)v12;
    v13 = (char *)*addr + 4;
    *addr = v13;
    v3->mSocietyRadBloChatRoomID = *(_DWORD *)v13;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005CD7A0) --------------------------------------------------------  // acclient.c:505630
AC1Legacy::PStringBase<char> *__thiscall ChatDisplayInfo::GetDisplayText(ChatDisplayInfo *this, AC1Legacy::PStringBase<char> *result)
{
  AC1Legacy::PSRefBuffer<char> *v2; // eax@1

  v2 = this->m_display.m_buffer;
  result->m_buffer = v2;
  InterlockedIncrement((volatile LONG *)&v2->m_cRef);
  return result;
}

//----- (005CD7C0) --------------------------------------------------------  // acclient.c:505641
ChatDisplayInfo *__thiscall ChatRoomTracker::GetChatFormat(ChatRoomTracker *this, ChatDisplayInfo *result, unsigned int roomid, AC1Legacy::PStringBase<unsigned short> sender, AC1Legacy::PStringBase<unsigned short> text)
{
  AC1Legacy::PSRefBuffer<char> *v5; // edi@1
  ChatRoomTracker *v6; // esi@1
  AC1Legacy::PSRefBuffer<unsigned short> *v7; // ebp@1
  unsigned int v8; // ebx@1
  int v9; // esi@7
  AC1Legacy::PStringBase<unsigned short> *v11; // [sp-4h] [bp-1Ch]@39
  AC1Legacy::PStringBase<unsigned short> strChannelName; // [sp+10h] [bp-8h]@1
  AC1Legacy::PStringBase<char> msg; // [sp+14h] [bp-4h]@1

  v5 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v6 = this;
  msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v7 = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  v8 = 0;
  strChannelName.m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4));
  if ( roomid == v6->m_allegianceRoomID )
  {
    v8 = 18;
    if ( v7 != ChannelSystem::Allegiance_GlobalChannelName.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
        v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
      v7 = ChannelSystem::Allegiance_GlobalChannelName.m_buffer;
      InterlockedIncrement((volatile LONG *)&ChannelSystem::Allegiance_GlobalChannelName.m_buffer->m_cRef);
    }
    v9 = 1;
  }
  else
  {
    if ( roomid == v6->mGeneralChatRoomID )
    {
      v8 = 27;
      AC1Legacy::PStringBase<unsigned short>::operator=(&strChannelName, &ChannelSystem::General_GlobalChannelName);
    }
    else if ( roomid == v6->mTradeChatRoomID )
    {
      v8 = 28;
      AC1Legacy::PStringBase<unsigned short>::operator=(&strChannelName, &ChannelSystem::Trade_GlobalChannelName);
    }
    else if ( roomid == v6->mLFGChatRoomID )
    {
      v8 = 29;
      AC1Legacy::PStringBase<unsigned short>::operator=(&strChannelName, &ChannelSystem::LFG_GlobalChannelName);
    }
    else if ( roomid == v6->mRoleplayChatRoomID )
    {
      v8 = 30;
      AC1Legacy::PStringBase<unsigned short>::operator=(&strChannelName, &ChannelSystem::Roleplay_GlobalChannelName);
    }
    else if ( roomid == v6->mOlthoiChatRoomID )
    {
      v8 = 18;
      AC1Legacy::PStringBase<unsigned short>::operator=(&strChannelName, &ChannelSystem::Olthoi_GlobalChannelName);
    }
    else
    {
      if ( roomid == v6->mSocietyChatRoomID )
      {
        v11 = &ChannelSystem::Society_GlobalChannelName;
      }
      else if ( roomid == v6->mSocietyCelHanChatRoomID )
      {
        v11 = &ChannelSystem::SocietyCelHan_GlobalChannelName;
      }
      else if ( roomid == v6->mSocietyEldWebChatRoomID )
      {
        v11 = &ChannelSystem::SocietyEldWeb_GlobalChannelName;
      }
      else
      {
        if ( roomid != v6->mSocietyRadBloChatRoomID )
        {
          v9 = 0;
          goto LABEL_9;
        }
        v11 = &ChannelSystem::SocietyRadBlo_GlobalChannelName;
      }
      v8 = 32;
      AC1Legacy::PStringBase<unsigned short>::operator=(&strChannelName, v11);
    }
    v7 = strChannelName.m_buffer;
    v9 = 1;
  }
  AC1Legacy::PStringBase<char>::sprintf(
    &msg,
    "[%ws] <Tell:IIDString:0:%ws>%ws<\\Tell> says, \"%ws\"",
    v7->m_data,
    sender.m_buffer->m_data,
    sender.m_buffer->m_data,
    text.m_buffer->m_data);
  v5 = msg.m_buffer;
LABEL_9:
  InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  result->m_ltt = v8;
  result->m_display.m_buffer = v5;
  InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  result->m_doDisplayText = v9;
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&sender.m_buffer->m_cRef) && sender.m_buffer )
    sender.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)sender.m_buffer, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&text.m_buffer->m_cRef) && text.m_buffer )
    text.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)text.m_buffer, 1u);
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

//----- (006B4A40) --------------------------------------------------------  // acclient.c:718374
unsigned int __thiscall CommandList::GetHead(ChatDisplayInfo *this)
{
  return this->m_ltt;
}

//----- (006BC230) --------------------------------------------------------  // acclient.c:723975
unsigned int __thiscall ChatRoomTracker::GetGlobalSocietyRoomID(ChatRoomTracker *this)
{
  return this->mSocietyChatRoomID;
}

