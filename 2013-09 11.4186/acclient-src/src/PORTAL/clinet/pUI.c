/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : pUI
   Object     : PORTAL\clinet\pUI.obj
   Functions  : 22
   Addresses  : 00546740 - 00705630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00546740) --------------------------------------------------------  // acclient.c:373842
int __cdecl Proto_UI::SendBlob(NetBlob *pBlob)
{
  int result; // eax@3
  signed int v2; // eax@4
  char v3; // cl@4
  unsigned __int16 v4; // bp@4
  signed int v5; // ebx@9
  unsigned __int64 v6; // rax@11
  unsigned __int64 v7; // ST00_8@11
  unsigned __int64 v8; // rax@11

  if ( PacketController::Instance() && pBlob )
  {
    v2 = pBlob->queueID_;
    v3 = 0;
    v4 = *(_WORD *)&SharedNet::s_pNet[1].receivers_[454];
    if ( v2 >= 4 && (v2 <= 5 || v2 == 8) )
    {
      v4 = *(_WORD *)&SharedNet::s_pNet[1].receivers_[452];
      v3 = 1;
    }
    if ( !pBlob->id )
    {
      v5 = 587202560;
      if ( !v3 )
        v5 = 50331648;
      LODWORD(v6) = NetInterface::GetNonEphemeralID();
      HIDWORD(v7) = v5;
      LODWORD(v7) = 0;
      LODWORD(v8) = NetBlobIDUtils::MakeNetBlobID(v7, Proto_UI::m_UnorderedStamp++, v6);
      pBlob->id = v8;
    }
    result = (unsigned __int8)NetBlob::Send(pBlob, v4, 5u);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005467E0) --------------------------------------------------------  // acclient.c:373884
unsigned int __cdecl Proto_UI::GetNextUICounter()
{
  return Proto_UI::eventCounter_++ + 1;
}
// 845F28: using guessed type unsigned int Proto_UI::eventCounter_;

//----- (005467F0) --------------------------------------------------------  // acclient.c:373891
void __cdecl Proto_UI::UICounterFailedSend()
{
  --Proto_UI::eventCounter_;
}
// 845F28: using guessed type unsigned int Proto_UI::eventCounter_;

//----- (00546800) --------------------------------------------------------  // acclient.c:373898
void __cdecl Proto_UI::SetEventCounter(unsigned int tsVal)
{
  Proto_UI::eventCounter_ = tsVal;
}
// 845F28: using guessed type unsigned int Proto_UI::eventCounter_;

//----- (00546810) --------------------------------------------------------  // acclient.c:373905
bool __cdecl Proto_UI::SendToWeenie(char *buf, int size)
{
  bool v2; // bl@1
  NetBlob *v3; // eax@2
  int v4; // eax@3
  int v5; // esi@3

  v2 = 0;
  if ( PacketController::Instance() )
  {
    v3 = (NetBlob *)operator new(0x50u);
    if ( v3 )
    {
      NetBlob::NetBlob(v3, buf, size, 3);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    v2 = Proto_UI::SendBlob((NetBlob *)v5) != 0;
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
  return v2;
}

//----- (00546880) --------------------------------------------------------  // acclient.c:373933
bool __cdecl Proto_UI::SendToControl(char *buf, int size)
{
  bool result; // al@2
  NetBlob *v3; // eax@3
  int v4; // eax@4
  int v5; // esi@4
  bool v6; // bl@6

  if ( PacketController::Instance() )
  {
    v3 = (NetBlob *)operator new(0x50u);
    if ( v3 )
    {
      NetBlob::NetBlob(v3, buf, size, 2);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    v6 = Proto_UI::SendBlob((NetBlob *)v5) != 0;
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005468F0) --------------------------------------------------------  // acclient.c:373969
bool __cdecl Proto_UI::SendToLogon(char *buf, int size)
{
  bool result; // al@2
  NetBlob *v3; // eax@3
  int v4; // eax@4
  int v5; // esi@4
  bool v6; // bl@6

  if ( PacketController::Instance() )
  {
    v3 = (NetBlob *)operator new(0x50u);
    if ( v3 )
    {
      NetBlob::NetBlob(v3, buf, size, 4);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    v6 = Proto_UI::SendBlob((NetBlob *)v5) != 0;
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00546960) --------------------------------------------------------  // acclient.c:374005
bool __cdecl Proto_UI::SendToDatabase(char *buf, int size)
{
  bool result; // al@2
  NetBlob *v3; // eax@3
  int v4; // eax@4
  int v5; // esi@4
  bool v6; // bl@6

  if ( PacketController::Instance() )
  {
    v3 = (NetBlob *)operator new(0x50u);
    if ( v3 )
    {
      NetBlob::NetBlob(v3, buf, size, 5);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    v6 = Proto_UI::SendBlob((NetBlob *)v5) != 0;
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005469D0) --------------------------------------------------------  // acclient.c:374041
BOOL __cdecl Proto_UI::SendForceObjdesc(unsigned int object_id)
{
  void *v1; // eax@1

  v1 = operator new[](8u);
  *(_DWORD *)v1 = 63210;
  *((_DWORD *)v1 + 1) = object_id;
  return Proto_UI::SendToControl((char *)v1, 8);
}

//----- (00546A00) --------------------------------------------------------  // acclient.c:374052
BOOL __cdecl Proto_UI::SendEnterWorldRequest()
{
  char *v0; // eax@1

  v0 = (char *)operator new[](4u);
  *(_DWORD *)v0 = 63432;
  return Proto_UI::SendToLogon(v0, 4);
}

//----- (00546A20) --------------------------------------------------------  // acclient.c:374062
BOOL __cdecl Proto_UI::LogOffCharacter(unsigned int gid)
{
  void *v1; // eax@1

  v1 = operator new[](8u);
  *(_DWORD *)v1 = 63059;
  *((_DWORD *)v1 + 1) = gid;
  return Proto_UI::SendToLogon((char *)v1, 8);
}

//----- (00546A50) --------------------------------------------------------  // acclient.c:374073
BOOL __cdecl Proto_UI::SendAdminGetServerVersion()
{
  char *v0; // eax@1

  v0 = (char *)operator new[](4u);
  *(_DWORD *)v0 = 63436;
  return Proto_UI::SendToControl(v0, 4);
}

//----- (00546A70) --------------------------------------------------------  // acclient.c:374083
int __cdecl Proto_UI::SendCharGenResult(CharGenResult *_charGenResult, accountID account)
{
  int v2; // esi@1
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // ebx@1
  bool v6; // al@1
  AC1Legacy::PSRefBuffer<char> *v7; // esi@1
  int v8; // edi@1
  void *buf; // [sp+Ch] [bp-8h]@1
  void *dummy; // [sp+10h] [bp-4h]@1

  dummy = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&account.m_buffer, &dummy, 0);
  v3 = v2 + ((int (__thiscall *)(CharGenResult *))_charGenResult->vfptr->GetPackSize)(_charGenResult) + 4;
  v4 = operator new[](v3);
  buf = v4;
  *(_DWORD *)v4 = 63062;
  v5 = (char *)v4;
  buf = (char *)buf + 4;
  AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&account.m_buffer, &buf, v3);
  ((void (__thiscall *)(CharGenResult *, void **, int))_charGenResult->vfptr->Pack)(_charGenResult, &buf, v3);
  v6 = Proto_UI::SendToLogon(v5, v3);
  v7 = account.m_buffer;
  v8 = v6;
  if ( !InterlockedDecrement((volatile LONG *)&account.m_buffer->m_cRef) && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  return v8;
}

//----- (00546B30) --------------------------------------------------------  // acclient.c:374114
int __cdecl Proto_UI::SendDeleteCharacter(accountID account, int slot)
{
  int v2; // esi@1
  void *v3; // edi@1
  bool v4; // al@1
  AC1Legacy::PSRefBuffer<char> *v5; // esi@1
  int v6; // edi@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&account.m_buffer, &dummy, 0) + 8;
  v3 = operator new[](v2);
  dummy = (char *)v3 + 4;
  *(_DWORD *)v3 = 63061;
  AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&account.m_buffer, &dummy, v2);
  *(_DWORD *)dummy = slot;
  v4 = Proto_UI::SendToLogon((char *)v3, v2);
  v5 = account.m_buffer;
  v6 = v4;
  if ( !InterlockedDecrement((volatile LONG *)&account.m_buffer->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  return v6;
}

//----- (00546BC0) --------------------------------------------------------  // acclient.c:374139
int __cdecl Proto_UI::SendEnterWorld(unsigned int gid, accountID account)
{
  int v2; // eax@1
  int v3; // esi@1
  void *v4; // eax@1
  unsigned int v5; // ecx@1
  char *v6; // edi@1
  bool v7; // al@1
  AC1Legacy::PSRefBuffer<char> *v8; // esi@1
  int v9; // edi@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&account.m_buffer, &dummy, 0);
  v3 = v2 + 8;
  v4 = operator new[](v2 + 8);
  v5 = gid;
  v6 = (char *)v4;
  v4 = (char *)v4 + 4;
  *(_DWORD *)v6 = 63063;
  *(_DWORD *)v4 = v5;
  gid = (unsigned int)((char *)v4 + 4);
  AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&account.m_buffer, (void **)&gid, v3);
  v7 = Proto_UI::SendToLogon(v6, v3);
  v8 = account.m_buffer;
  v9 = v7;
  if ( !InterlockedDecrement((volatile LONG *)&account.m_buffer->m_cRef) && v8 )
    v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
  return v9;
}

//----- (00546C50) --------------------------------------------------------  // acclient.c:374171
int __cdecl Proto_UI::SendFriendsCommand(unsigned int cmd, PStringBase<char> *i_player)
{
  AC1Legacy::PSRefBuffer<char> *v2; // ecx@0
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // ebx@1
  bool v6; // al@1
  AC1Legacy::PSRefBuffer<char> *v7; // esi@1
  int v8; // edi@1
  AC1Legacy::PStringBase<char> player; // [sp+0h] [bp-4h]@1

  player.m_buffer = v2;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&player, i_player->m_charbuffer->m_data);
  i_player = 0;
  v3 = AC1Legacy::PStringBase<char>::Pack(&player, (void **)&i_player, 0);
  v4 = operator new[](v3 + 8);
  *(_DWORD *)v4 = 63437;
  v5 = (char *)v4;
  v4 = (char *)v4 + 4;
  *(_DWORD *)v4 = cmd;
  i_player = (PStringBase<char> *)((char *)v4 + 4);
  AC1Legacy::PStringBase<char>::Pack(&player, (void **)&i_player, v3);
  v6 = Proto_UI::SendToControl(v5, v3 + 8);
  v7 = player.m_buffer;
  v8 = v6;
  if ( !InterlockedDecrement((volatile LONG *)&player.m_buffer->m_cRef) && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  return v8;
}

//----- (00546CF0) --------------------------------------------------------  // acclient.c:374202
int __cdecl Proto_UI::SendAdminRestoreCharacter(unsigned int iid, PStringBase<char> *i_restoredCharName, PStringBase<char> *i_acctToRestoreTo)
{
  AC1Legacy::PSRefBuffer<char> *v3; // ecx@0
  int v4; // esi@1
  int v5; // esi@1
  void *v6; // eax@1
  char *v7; // edi@1
  bool v8; // al@1
  PStringBase<char> *v9; // esi@1
  int v10; // edi@1
  AC1Legacy::PSRefBuffer<char> *v11; // esi@4
  AC1Legacy::PStringBase<char> restoredCharName; // [sp+4h] [bp-4h]@1

  restoredCharName.m_buffer = v3;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&restoredCharName, i_restoredCharName->m_charbuffer->m_data);
  AC1Legacy::PStringBase<char>::PStringBase<char>(
    (AC1Legacy::PStringBase<char> *)&i_acctToRestoreTo,
    i_acctToRestoreTo->m_charbuffer->m_data);
  i_restoredCharName = 0;
  v4 = AC1Legacy::PStringBase<char>::Pack(
         (AC1Legacy::PStringBase<char> *)&i_acctToRestoreTo,
         (void **)&i_restoredCharName,
         0);
  v5 = v4 + AC1Legacy::PStringBase<char>::Pack(&restoredCharName, (void **)&i_restoredCharName, 0) + 8;
  v6 = operator new[](v5);
  *(_DWORD *)v6 = 63449;
  v7 = (char *)v6;
  v6 = (char *)v6 + 4;
  *(_DWORD *)v6 = iid;
  i_restoredCharName = (PStringBase<char> *)((char *)v6 + 4);
  AC1Legacy::PStringBase<char>::Pack(&restoredCharName, (void **)&i_restoredCharName, v5);
  AC1Legacy::PStringBase<char>::Pack(
    (AC1Legacy::PStringBase<char> *)&i_acctToRestoreTo,
    (void **)&i_restoredCharName,
    v5);
  v8 = Proto_UI::SendToControl(v7, v5);
  v9 = i_acctToRestoreTo;
  v10 = v8;
  if ( !InterlockedDecrement((volatile LONG *)&i_acctToRestoreTo[1]) && v9 )
    (*(void (__thiscall **)(PStringBase<char> *, signed int))&v9->m_charbuffer->m_data[0])(v9, 1);
  v11 = restoredCharName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&restoredCharName.m_buffer->m_cRef) && v11 )
    v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
  return v10;
}

//----- (007055F0) --------------------------------------------------------  // acclient.c:792624
int _E77_9()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_26;
  dword_845F40 = LOWEST_DATA_RATE_26;
  return result;
}

//----- (00705600) --------------------------------------------------------  // acclient.c:792634
int _E79_52()
{
  return atexit(_E80_51);
}

//----- (00705610) --------------------------------------------------------  // acclient.c:792640
int _E82_33()
{
  return atexit(_E83_31);
}

//----- (00705620) --------------------------------------------------------  // acclient.c:792646
int _E85_23()
{
  return atexit(_E86_20);
}

//----- (00705630) --------------------------------------------------------  // acclient.c:792652
int sub_705630()
{
  return atexit(nullsub_1208);
}

