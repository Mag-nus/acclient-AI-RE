/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCommunicationSystem
   Object     : PORTAL\cchat\CCommunicationSystem.obj
   Functions  : 20
   Addresses  : 00556290 - 00707260 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00556290) --------------------------------------------------------  // acclient.c:389529
void __cdecl CCommunicationSystem::Init()
{
  if ( !CCommunicationSystem::s_pInstance )
    CCommunicationSystem::s_pInstance = (ChatRoomTracker *)CFactory::MakeCCommunicationSystem();
}

//----- (005562B0) --------------------------------------------------------  // acclient.c:389536
unsigned int __cdecl CCommunicationSystem::IsUsingTurbineChat()
{
  unsigned int result; // eax@1

  result = (unsigned int)CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
    result = CCommunicationSystem::s_pInstance->mTradeChatRoomID;
  return result;
}

//----- (005562E0) --------------------------------------------------------  // acclient.c:389547
IChatClient *__cdecl CCommunicationSystem::CSendToTurbineRoomByID(unsigned int dwRoomID, const unsigned __int16 *pwszText, tagBLOB localBlob, tagBLOB remoteBlob)
{
  IChatClient *result; // eax@1

  result = AC1ClientChatManager::GetIChatClient();
  if ( result )
    result = (IChatClient *)(((int (__stdcall *)(IChatClient *, unsigned int, const unsigned __int16 *, unsigned int, char *, unsigned int, char *))result->vfptr[4].Release)(
                               result,
                               dwRoomID,
                               pwszText,
                               localBlob.cbSize,
                               localBlob.pBlobData,
                               remoteBlob.cbSize,
                               remoteBlob.pBlobData) == 0);
  return result;
}

//----- (00556320) --------------------------------------------------------  // acclient.c:389565
unsigned int __cdecl CCommunicationSystem::GetChatManager()
{
  unsigned int result; // eax@1

  result = (unsigned int)CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
    result = CCommunicationSystem::s_pInstance->mGeneralChatRoomID;
  return result;
}

//----- (00556330) --------------------------------------------------------  // acclient.c:389576
CCliDatEvent *__cdecl CChatEvent::CreateForSend(const char *pChatData, unsigned int DataLen)
{
  void *v2; // ebx@1
  CCliDatEvent *v3; // eax@1
  CCliDatEvent *v4; // esi@1
  CCliDatEvent *result; // eax@2

  v2 = operator new[](DataLen + 8);
  *((_DWORD *)v2 + 1) = DataLen;
  *(_DWORD *)v2 = 63454;
  qmemcpy((char *)v2 + 8, pChatData, DataLen);
  v3 = (CCliDatEvent *)operator new(0x50u);
  v4 = v3;
  if ( v3 )
  {
    CCliDatEvent::CCliDatEvent(v3, (char *)v2, DataLen + 8);
    v4->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)CChatEvent::vftable;
    v4->vfptr = (PackObjVtbl *)&CChatEvent::vftable;
    v4->vfptr = (HashBaseData<unsigned __int64>Vtbl *)&CChatEvent::vftable;
    v4->queueID_ = 4;
    result = v4;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E5A10: using guessed type void *CChatEvent::vftable;
// 7E5A14: using guessed type void *CChatEvent::vftable;
// 7E5A28: using guessed type int (__thiscall *CChatEvent::vftable[4])(void *, char);

//----- (005563D0) --------------------------------------------------------  // acclient.c:389621
HRESULT __stdcall CCommunicationSystem::ChatInterfaceProvider::SendData(CCommunicationSystem::ChatInterfaceProvider *this, tagBLOB blob)
{
  signed int v2; // edi@1
  NetBlob *v3; // eax@1
  NetBlob *v4; // esi@1
  HRESULT result; // eax@2

  v2 = -2147418113;
  v3 = (NetBlob *)CChatEvent::CreateForSend(blob.pBlobData, blob.cbSize);
  v4 = v3;
  if ( v3 )
  {
    if ( Proto_UI::SendBlob(v3) )
      v2 = 0;
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
    result = v2;
  }
  else
  {
    result = -2147418113;
  }
  return result;
}

//----- (00556430) --------------------------------------------------------  // acclient.c:389647
int __thiscall AC1Legacy::PStringBase<unsigned short>::vsprintf(AC1Legacy::PStringBase<unsigned short> *this, const unsigned __int16 *fmt, char *args)
{
  AC1Legacy::PStringBase<unsigned short> *v3; // esi@1
  int v4; // eax@1
  AC1Legacy::PStringBase<unsigned short> v5; // ebx@1
  int v6; // edi@1

  v3 = this;
  v4 = __vscwprintf(fmt, args);
  v5.m_buffer = v3->m_buffer;
  v6 = v4;
  AC1Legacy::PStringBase<unsigned short>::allocate_ref_buffer(v3, v4);
  __vsnwprintf(v3->m_buffer->m_data, v6 + 1, fmt, args);
  if ( !InterlockedDecrement((volatile LONG *)&v5.m_buffer->m_cRef) && v5.m_buffer )
    v5.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5.m_buffer, 1u);
  return v6;
}

//----- (005564A0) --------------------------------------------------------  // acclient.c:389666
int __cdecl CCommunicationSystem::StartupTurbineChat(AC1Legacy::PStringBase<char> accountName)
{
  int result; // eax@5
  int v2; // ebx@6

  if ( CCommunicationSystem::s_pInstance )
  {
    InterlockedIncrement((volatile LONG *)&accountName.m_buffer->m_cRef);
    v2 = ((int (__stdcall *)(AC1Legacy::PSRefBuffer<char> *))CCommunicationSystem::s_pInstance->vfptr->__vecDelDtor)(accountName.m_buffer);
    if ( !InterlockedDecrement((volatile LONG *)&accountName.m_buffer->m_cRef) && accountName.m_buffer )
      accountName.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)accountName.m_buffer, 1u);
    result = v2;
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)&accountName.m_buffer->m_cRef) )
    {
      if ( accountName.m_buffer )
        accountName.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)accountName.m_buffer, 1u);
    }
    result = 0;
  }
  return result;
}

//----- (00556510) --------------------------------------------------------  // acclient.c:389692
int AC1Legacy::PStringBase<unsigned short>::sprintf(AC1Legacy::PStringBase<unsigned short> *this, const unsigned __int16 *fmt, ...)
{
  va_list va; // [sp+Ch] [bp+Ch]@1

  va_start(va, fmt);
  return AC1Legacy::PStringBase<unsigned short>::vsprintf(this, fmt, va);
}

//----- (00556530) --------------------------------------------------------  // acclient.c:389701
void __cdecl CCommunicationSystem::Cleanup()
{
  ChatRoomTracker *v0; // edi@1
  unsigned int v1; // esi@2
  int v2; // esi@2

  v0 = CCommunicationSystem::s_pInstance;
  if ( CCommunicationSystem::s_pInstance )
  {
    v1 = CCommunicationSystem::s_pInstance->mLFGChatRoomID;
    CCommunicationSystem::s_pInstance->vfptr = (PackObjVtbl *)&CCommunicationSystem::vftable;
    v2 = v1 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    operator delete(v0);
  }
  CCommunicationSystem::s_pInstance = 0;
}
// 7CB694: using guessed type int (__stdcall *CCommunicationSystem::vftable)(AC1Legacy::PStringBase<char> accountName);

//----- (00556580) --------------------------------------------------------  // acclient.c:389722
AC1Legacy::PStringBase<unsigned short> *__thiscall AC1Legacy::PStringBase<char>::to_wpstring(AC1Legacy::PStringBase<char> *this, AC1Legacy::PStringBase<unsigned short> *result, const unsigned __int16 i_sourceCodePage)
{
  AC1Legacy::PSRefBuffer<unsigned short> *v3; // esi@1
  volatile LONG *v4; // edi@1
  AC1Legacy::PStringBase<char> *v5; // ebp@1
  int v6; // ecx@1
  AC1Legacy::PStringBase<unsigned short> *v7; // ebp@2
  int v9; // eax@5
  int v10; // edi@5
  AC1Legacy::PSRefBuffer<char> *v11; // eax@7
  int v12; // ecx@7
  int v13; // edi@7
  int v14; // eax@7
  DWORD v15; // esi@9
  volatile LONG *v16; // edi@9
  volatile LONG *v17; // ST10_4@9
  AC1Legacy::PStringBase<unsigned short> *v18; // [sp-24h] [bp-58h]@0
  const unsigned __int16 *v19; // [sp-20h] [bp-54h]@0
  int v20; // [sp-1Ch] [bp-50h]@0
  DWORD v21; // [sp-18h] [bp-4Ch]@0
  DWORD v22; // [sp-14h] [bp-48h]@0
  DWORD v23; // [sp+0h] [bp-34h]@6
  int v24; // [sp+4h] [bp-30h]@6
  AC1Legacy::PStringBase<unsigned short> *v25; // [sp+8h] [bp-2Ch]@9
  int v26; // [sp+18h] [bp-1Ch]@7
  volatile LONG *v27; // [sp+1Ch] [bp-18h]@2
  AC1Legacy::PStringBase<unsigned short> ret_str; // [sp+30h] [bp-4h]@1

  v3 = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4);
  v5 = this;
  ret_str.m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4));
  v6 = v5->m_buffer->m_len;
  if ( v6 == 1 )
  {
    v7 = result;
    v27 = v4;
    result->m_buffer = v3;
    InterlockedIncrement(v27);
    if ( !InterlockedDecrement(v4) && v3 )
    {
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
      return result;
    }
    return v7;
  }
  v9 = MultiByteToWideChar(i_sourceCodePage, 0, v5->m_buffer->m_data, v6, 0, 0);
  v10 = v9;
  if ( v9 )
  {
    AC1Legacy::PStringBase<unsigned short>::allocate_ref_buffer((AC1Legacy::PStringBase<unsigned short> *)&v26, v9);
    v11 = v5->m_buffer;
    v12 = v5->m_buffer->m_len;
    v24 = v10;
    v13 = v26;
    v14 = MultiByteToWideChar(i_sourceCodePage, 0, v11->m_data, v12, (LPWSTR)(v26 + 20), v24);
    if ( v14 )
    {
      v7 = v25;
      *(_DWORD *)(v13 + 8) = v14;
      v7->m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)v13;
      InterlockedIncrement((volatile LONG *)(v13 + 4));
      if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      return v7;
    }
    v22 = GetLastError();
    v21 = GetLastError();
    v20 = i_sourceCodePage;
    v19 = L"Failed conversion from codepage %hu! GetLastError %d (0x%08x)\n";
    v18 = (AC1Legacy::PStringBase<unsigned short> *)&v23;
  }
  else
  {
    v24 = GetLastError();
    v23 = GetLastError();
  }
  AC1Legacy::PStringBase<unsigned short>::sprintf(v18, v19, v20, v21, v22);
  v15 = v23;
  v7 = v25;
  v16 = (volatile LONG *)(v23 + 4);
  v17 = (volatile LONG *)(v23 + 4);
  v25->m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)v23;
  InterlockedIncrement(v17);
  if ( !InterlockedDecrement(v16) && v15 )
  {
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    return v7;
  }
  return v7;
}
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

//----- (005566C0) --------------------------------------------------------  // acclient.c:389817
void __thiscall CCommunicationSystem::CCommunicationSystem(CCommunicationSystem *this)
{
  this->vfptr = (CCommunicationSystemVtbl *)&CCommunicationSystem::vftable;
  this->m_pChatInterfaceProvider = 0;
  this->m_fUseTurbineChat = 0;
  PStringBase<char>::PStringBase<char>(&this->m_TurbineChatDllName, "chatclient.dll");
}
// 7CB694: using guessed type int (__stdcall *CCommunicationSystem::vftable)(AC1Legacy::PStringBase<char> accountName);

//----- (005566F0) --------------------------------------------------------  // acclient.c:389827
int __thiscall CCommunicationSystem::StartupTurbineChat_Internal(CCommunicationSystem *this, AC1Legacy::PStringBase<char> accountName)
{
  CCommunicationSystem *v2; // esi@1
  CCommunicationSystem::ChatInterfaceProvider *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@2
  LONG v5; // eax@2
  AC1ClientChatManager *v6; // eax@3
  AC1ClientChatManager *v7; // eax@4
  AC1Legacy::PStringBase<unsigned short> *v8; // ST0C_4@6
  CCommunicationSystem::ChatInterfaceProvider *v9; // ST08_4@6
  PStringBase<char> v10; // ST04_4@6
  bool v11; // bl@6
  AC1Legacy::PSRefBuffer<unsigned short> *v12; // esi@6
  AC1Legacy::PStringBase<unsigned short> result; // [sp+0h] [bp-4h]@1

  result.m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)this;
  v2 = this;
  v3 = this->m_pChatInterfaceProvider;
  this->m_fUseTurbineChat = 1;
  if ( v3 )
  {
    v4 = accountName.m_buffer;
    v5 = InterlockedDecrement((volatile LONG *)&accountName.m_buffer->m_cRef);
LABEL_15:
    if ( !v5 )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    }
    return 1;
  }
  this->m_pChatInterfaceProvider = (CCommunicationSystem::ChatInterfaceProvider *)((int (*)(void))this->vfptr->CreateChatInterfaceProvider)();
  v6 = (AC1ClientChatManager *)operator new(0x10u);
  if ( v6 )
    AC1ClientChatManager::AC1ClientChatManager(v6);
  else
    v7 = 0;
  v2->m_pChatManager = v7;
  v8 = AC1Legacy::PStringBase<char>::to_wpstring(&accountName, &result, 0);
  v9 = v2->m_pChatInterfaceProvider;
  v10.m_charbuffer = v2->m_TurbineChatDllName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v10.m_charbuffer[-1]);
  v11 = AC1ClientChatManager::Init(v2->m_pChatManager, v10, v9, v8) == 0;
  v12 = result.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v12 )
    v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
  v4 = accountName.m_buffer;
  if ( !v11 )
  {
    v5 = InterlockedDecrement((volatile LONG *)&accountName.m_buffer->m_cRef);
    goto LABEL_15;
  }
  if ( !InterlockedDecrement((volatile LONG *)&accountName.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  return 0;
}

//----- (00707200) --------------------------------------------------------  // acclient.c:794363
int sub_707200()
{
  return atexit(_E74_79);
}

//----- (00707210) --------------------------------------------------------  // acclient.c:794369
int _E76_64()
{
  return atexit(_E77_92);
}

//----- (00707220) --------------------------------------------------------  // acclient.c:794375
int _E79_58()
{
  return atexit(_E80_57);
}

//----- (00707230) --------------------------------------------------------  // acclient.c:794381
void _E98_11()
{
  dword_86FBE8 = 1024;
}

//----- (00707240) --------------------------------------------------------  // acclient.c:794387
void sub_707240()
{
  dword_86FBEC = 0x7FFF;
}

//----- (00707250) --------------------------------------------------------  // acclient.c:794393
int _E102_28()
{
  const int result; // eax@1

  result = dword_86FBE8;
  dword_86FBF0 = dword_86FBE8;
  return result;
}

//----- (00707260) --------------------------------------------------------  // acclient.c:794403
int sub_707260()
{
  return atexit(nullsub_1267);
}

