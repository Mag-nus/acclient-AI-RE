/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MiniGameSystem
   Object     : AC\accui_misc\MiniGameSystem.obj
   Functions  : 26
   Addresses  : 00585650 - 007099F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00585650) --------------------------------------------------------  // acclient.c:430318
void __thiscall ClientMiniGameSystem::~ClientMiniGameSystem(ClientMiniGameSystem *this)
{
  ClientMiniGameSystem *v1; // eax@1
  NoticeHandler *v2; // ecx@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v1->vfptr = (InterfaceVtbl *)&ClientMiniGameSystem::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7E1B14: using guessed type __int32 (__stdcall *ClientMiniGameSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00585680) --------------------------------------------------------  // acclient.c:430336
void ClientMiniGameSystem::OnShutdown()
{
  if ( ClientMiniGameSystem::s_pMiniGameSystem )
  {
    ((void (*)(void))ClientMiniGameSystem::s_pMiniGameSystem->vfptr->Release)();
    ClientMiniGameSystem::s_pMiniGameSystem = 0;
  }
}
// 8708FC: using guessed type struct ClientMiniGameSystem *ClientMiniGameSystem::s_pMiniGameSystem;

//----- (005856A0) --------------------------------------------------------  // acclient.c:430347
unsigned int __stdcall ClientMiniGameSystem::Handle_Game__Recv_JoinGameResponse(unsigned int idGame, int iTeam)
{
  CM_Game::SendNotice_JoinGameResponse(idGame, iTeam);
  return 0;
}

//----- (005856C0) --------------------------------------------------------  // acclient.c:430354
unsigned int __stdcall ClientMiniGameSystem::Handle_Game__Recv_StartGame(unsigned int idGame, int iTeam)
{
  CM_Game::SendNotice_StartGame(idGame, iTeam);
  return 0;
}

//----- (005856E0) --------------------------------------------------------  // acclient.c:430361
unsigned int __stdcall ClientMiniGameSystem::Handle_Game__Recv_MoveResponse(unsigned int idGame, int iMoveResult)
{
  CM_Game::SendNotice_MoveResponse(idGame, iMoveResult);
  return 0;
}

//----- (00585700) --------------------------------------------------------  // acclient.c:430368
unsigned int __stdcall ClientMiniGameSystem::Handle_Game__Recv_OpponentTurn(unsigned int idGame, int iTeam, GameMoveData *move)
{
  CM_Game::SendNotice_OpponentTurn(idGame, iTeam, move);
  return 0;
}

//----- (00585720) --------------------------------------------------------  // acclient.c:430375
unsigned int __stdcall ClientMiniGameSystem::Handle_Game__Recv_OppenentStalemateState(unsigned int idGame, int iTeam, int fOn)
{
  CM_Game::SendNotice_OpponentOffersStalemate(idGame, iTeam, fOn);
  return 0;
}

//----- (00585740) --------------------------------------------------------  // acclient.c:430382
unsigned int __stdcall ClientMiniGameSystem::Handle_Game__Recv_GameOver(unsigned int idGame, int iTeamWinner)
{
  CM_Game::SendNotice_GameOver(idGame, iTeamWinner);
  return 0;
}

//----- (00585760) --------------------------------------------------------  // acclient.c:430389
TResult *__thiscall ClientMiniGameSystem::QueryInterface(ClientMiniGameSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S124_12 & 1 )
  {
    v4 = Offsets_11[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientMiniGameSystem_InterfaceType_62;
    _S124_12 |= 1u;
    Offsets_11[0].key = (_GUID *)&ClientMiniGameSystem_InterfaceType_62;
    dword_870988 = 0;
    dword_87098C = (int)&ClientSystem_InterfaceType_90;
    dword_870990 = 0;
    dword_870994 = (int)&stru_7E1B00;
    dword_870998 = 0;
    dword_87099C = 0;
    dword_8709A0 = 0;
  }
  v5 = (int)Offsets_11;
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
// 870988: using guessed type int dword_870988;
// 87098C: using guessed type int dword_87098C;
// 870990: using guessed type int dword_870990;
// 870994: using guessed type int dword_870994;
// 870998: using guessed type int dword_870998;
// 87099C: using guessed type int dword_87099C;
// 8709A0: using guessed type int dword_8709A0;

//----- (00585830) --------------------------------------------------------  // acclient.c:430456
unsigned int __thiscall ClientMiniGameSystem::Release(ClientMiniGameSystem *this)
{
  ClientMiniGameSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    ClientMiniGameSystem::~ClientMiniGameSystem(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (00585860) --------------------------------------------------------  // acclient.c:430472
void __thiscall ClientMiniGameSystem::ClientMiniGameSystem(ClientMiniGameSystem *this)
{
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientMiniGameSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  ClientMiniGameSystem::s_pMiniGameSystem = this;
  InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7E1B14: using guessed type __int32 (__stdcall *ClientMiniGameSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8708FC: using guessed type struct ClientMiniGameSystem *ClientMiniGameSystem::s_pMiniGameSystem;

//----- (007098B0) --------------------------------------------------------  // acclient.c:796758
void sub_7098B0()
{
  flt_87091C = 1000.0 + 1.0;
}

//----- (007098D0) --------------------------------------------------------  // acclient.c:796764
void sub_7098D0()
{
  flt_870920 = 24.0 * 8.0;
}

//----- (007098F0) --------------------------------------------------------  // acclient.c:796770
void sub_7098F0()
{
  flt_870924 = 24.0 * 0.5;
}

//----- (00709910) --------------------------------------------------------  // acclient.c:796776
int sub_709910()
{
  return atexit(nullsub_1365);
}

//----- (00709920) --------------------------------------------------------  // acclient.c:796782
int sub_709920()
{
  return atexit(nullsub_1366);
}

//----- (00709930) --------------------------------------------------------  // acclient.c:796788
int sub_709930()
{
  return atexit(nullsub_1367);
}

//----- (00709940) --------------------------------------------------------  // acclient.c:796794
void sub_709940()
{
  flt_870928 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00709960) --------------------------------------------------------  // acclient.c:796800
void _E108_94()
{
  dbl_870930 = 1.0 / 30.0;
}

//----- (00709980) --------------------------------------------------------  // acclient.c:796806
void _E110_78()
{
  dbl_870938 = 1.0 / 5.0;
}

//----- (007099A0) --------------------------------------------------------  // acclient.c:796812
void sub_7099A0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870940, PFID_A8R8G8B8);
}

//----- (007099B0) --------------------------------------------------------  // acclient.c:796818
void _E115_77()
{
  dword_870978 = 1024;
}

//----- (007099C0) --------------------------------------------------------  // acclient.c:796824
void _E117_73()
{
  dword_87097C = 0x7FFF;
}

//----- (007099D0) --------------------------------------------------------  // acclient.c:796830
int _E119_27()
{
  const int result; // eax@1

  result = dword_870978;
  dword_870980 = dword_870978;
  return result;
}

//----- (007099E0) --------------------------------------------------------  // acclient.c:796840
int _E121_68()
{
  return atexit(_E122_95);
}

//----- (007099F0) --------------------------------------------------------  // acclient.c:796846
int sub_7099F0()
{
  return atexit(nullsub_1364);
}

