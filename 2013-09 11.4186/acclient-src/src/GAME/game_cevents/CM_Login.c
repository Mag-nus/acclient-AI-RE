/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Login
   Object     : GAME\game_cevents\CM_Login.obj
   Functions  : 17
   Addresses  : 006AD810 - 00722CF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AD810) --------------------------------------------------------  // acclient.c:710718
char __cdecl CM_Login::SendNotice_BeginEnterWorld()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD1E0 + 1));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 356))(v3);
    }
  }
  return 1;
}

//----- (006AD860) --------------------------------------------------------  // acclient.c:710744
unsigned int __cdecl CM_Login::DispatchUI_WorldInfo(UIQueueManager *ui, void *buf, unsigned int size)
{
  AC1Legacy::PSRefBuffer<char> *v3; // ecx@0
  unsigned int result; // eax@3
  void *v5; // edi@4
  int v6; // ebx@6
  int v7; // ebp@6
  void *v8; // esi@6
  ClientUISystem *v9; // ecx@6
  unsigned int v10; // edi@6
  AC1Legacy::PSRefBuffer<char> *v11; // esi@6
  AC1Legacy::PStringBase<char> strWorldName; // [sp+0h] [bp-4h]@1

  strWorldName.m_buffer = v3;
  if ( ui && ui->m_pUISystem )
  {
    v5 = buf;
    if ( *(_DWORD *)buf == 63457 )
    {
      v6 = *((_DWORD *)buf + 1);
      v7 = *((_DWORD *)buf + 2);
      strWorldName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      buf = (char *)buf + 12;
      v8 = buf;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&strWorldName, &buf, size + (_BYTE *)v5 - (_BYTE *)v8);
      v9 = ui->m_pUISystem;
      v10 = ClientUISystem::Handle_Login__WorldInfo(v6, v7, &strWorldName);
      v11 = strWorldName.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&strWorldName.m_buffer->m_cRef) )
      {
        if ( v11 )
          v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
      }
      result = v10;
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
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00722BB0) --------------------------------------------------------  // acclient.c:820591
void sub_722BB0()
{
  flt_8FA4D0 = 1000.0 + 1.0;
}

//----- (00722BD0) --------------------------------------------------------  // acclient.c:820597
void sub_722BD0()
{
  flt_8FA4D4 = 24.0 * 8.0;
}

//----- (00722BF0) --------------------------------------------------------  // acclient.c:820603
void sub_722BF0()
{
  flt_8FA4D8 = 24.0 * 0.5;
}

//----- (00722C10) --------------------------------------------------------  // acclient.c:820609
int sub_722C10()
{
  return atexit(nullsub_427);
}

//----- (00722C20) --------------------------------------------------------  // acclient.c:820615
int sub_722C20()
{
  return atexit(nullsub_428);
}

//----- (00722C30) --------------------------------------------------------  // acclient.c:820621
int sub_722C30()
{
  return atexit(nullsub_429);
}

//----- (00722C40) --------------------------------------------------------  // acclient.c:820627
void sub_722C40()
{
  flt_8FA4DC = 0.00019999999 * 3.0 + 0.1;
}

//----- (00722C60) --------------------------------------------------------  // acclient.c:820633
void sub_722C60()
{
  dbl_8FA4E0 = 1.0 / 30.0;
}

//----- (00722C80) --------------------------------------------------------  // acclient.c:820639
void _E110_95()
{
  dbl_8FA4E8 = 1.0 / 5.0;
}

//----- (00722CA0) --------------------------------------------------------  // acclient.c:820645
void sub_722CA0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA4F0, PFID_A8R8G8B8);
}

//----- (00722CB0) --------------------------------------------------------  // acclient.c:820651
void sub_722CB0()
{
  dword_8FA528 = 1024;
}

//----- (00722CC0) --------------------------------------------------------  // acclient.c:820657
void sub_722CC0()
{
  dword_8FA52C = 0x7FFF;
}

//----- (00722CD0) --------------------------------------------------------  // acclient.c:820663
int _E119_47()
{
  const int result; // eax@1

  result = dword_8FA528;
  dword_8FA530 = dword_8FA528;
  return result;
}

//----- (00722CE0) --------------------------------------------------------  // acclient.c:820673
int sub_722CE0()
{
  return atexit(nullsub_425);
}

//----- (00722CF0) --------------------------------------------------------  // acclient.c:820679
int sub_722CF0()
{
  return atexit(nullsub_426);
}

