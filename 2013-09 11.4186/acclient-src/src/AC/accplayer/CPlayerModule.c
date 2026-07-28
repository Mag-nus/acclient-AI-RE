/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPlayerModule
   Object     : AC\accplayer\CPlayerModule.obj
   Functions  : 26
   Addresses  : 005269F0 - 0070B1C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005269F0) --------------------------------------------------------  // acclient.c:342171
signed int ProjectileSpell::IsProjectileSpell()
{
  return 1;
}

//----- (0059A5E0) --------------------------------------------------------  // acclient.c:452744
void __thiscall CPlayerModule::~CPlayerModule(CPlayerModule *this)
{
  HIDWORD(this[-1].m_timeFirstDirtied) = &CPlayerModule::vftable;
  this->vfptr = (InterfaceVtbl *)&CPlayerModule::vftable;
  PlayerModule::~PlayerModule((PlayerModule *)(this != (CPlayerModule *)4 ? (unsigned int)this : 0));
}
// 7E531C: using guessed type int (__stdcall *CPlayerModule::vftable)(char);
// 7E5338: using guessed type __int32 (__stdcall *CPlayerModule::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0059A600) --------------------------------------------------------  // acclient.c:452754
char __stdcall CPlayerModule::IsAutoSaveOption(PlayerOption i_po)
{
  char result; // al@2

  switch ( i_po )
  {
    case 0u:
    case 1u:
    case 2u:
    case 0xFu:
    case 0x10u:
    case 0x11u:
    case 0x12u:
    case 0x19u:
    case 0x1Bu:
    case 0x23u:
    case 0x24u:
    case 0x25u:
    case 0x26u:
    case 0x27u:
    case 0x2Au:
    case 0x2Bu:
    case 0x2Eu:
    case 0x2Fu:
    case 0x31u:
    case 0x32u:
    case 0x33u:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0059A660) --------------------------------------------------------  // acclient.c:452791
void __thiscall CPlayerModule::SaveToServer(CPlayerModule *this, bool i_bForceUpdate)
{
  CPlayerModule *v2; // esi@1

  v2 = this;
  if ( this->m_bDirty || i_bForceUpdate )
    CM_Character::Event_CharacterOptionsEvent((PlayerModule *)&this->vfptr);
  v2->m_bDirty = 0;
}

//----- (0059A690) --------------------------------------------------------  // acclient.c:452802
void __thiscall CPlayerModule::OnInitialize(CPlayerModule *this)
{
  PlayerModule *v1; // esi@1
  unsigned __int8 v2; // al@1
  char v3; // al@1
  char v4; // ST00_1@1
  ClientCombatSystem *v5; // eax@1

  v1 = (PlayerModule *)&this->vfptr;
  this->m_bDirty = 0;
  LODWORD(this->m_timeFirstDirtied) = 0;
  HIDWORD(this->m_timeFirstDirtied) = -1074790400;
  v2 = PlayerModule::PersistentAtDay((PlayerModule *)&this->vfptr);
  LScape::SetDay(v2);
  LScape::m_fFogEnabled = (unsigned __int8)PlayerModule::DisableDistanceFog(v1) == 0;
  v3 = PlayerModule::DisableMostWeatherEffects(v1);
  SmartBox::EnableWeather(v3 == 0);
  v4 = PlayerModule::ViewCombatTarget(v1);
  v5 = ClientCombatSystem::GetCombatSystem();
  ClientCombatSystem::TrackTarget(v5, v4);
}
// 81CBE8: using guessed type bool LScape::m_fFogEnabled;

//----- (0059A710) --------------------------------------------------------  // acclient.c:452826
void __thiscall CPlayerModule::UseTime(CPlayerModule *this)
{
  CPlayerModule *v1; // esi@1

  v1 = this;
  if ( this->m_bDirty )
  {
    if ( this->m_timeFirstDirtied + 480.0 <= COERCE_DOUBLE(Timer::cur_time.Cmd) )
    {
      CM_Character::Event_CharacterOptionsEvent((PlayerModule *)&this->vfptr);
      v1->m_bDirty = 0;
    }
  }
}

//----- (0059A750) --------------------------------------------------------  // acclient.c:452842
void __thiscall CPlayerModule::CPlayerModule(CPlayerModule *this)
{
  CPlayerModule *v1; // esi@1
  char *v2; // edi@1

  v1 = this;
  v2 = (char *)&this->vfptr;
  PlayerModule::PlayerModule((PlayerModule *)&this->vfptr);
  *(_DWORD *)v2 = &CPlayerModule::vftable;
  v1->m_bDirty = 0;
  LODWORD(v1->m_timeFirstDirtied) = 0;
  v1->vfptr = (InterfaceVtbl *)&CPlayerModule::vftable;
  HIDWORD(v1->m_timeFirstDirtied) = -1074790400;
}
// 7E531C: using guessed type int (__stdcall *CPlayerModule::vftable)(char);
// 7E5338: using guessed type __int32 (__stdcall *CPlayerModule::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0059A790) --------------------------------------------------------  // acclient.c:452860
void *__fastcall CPlayerModule::scalar_deleting_destructor(int a1, int a2, char a3)
{
  void *v3; // esi@1

  v3 = (void *)(a1 - 4);
  *(_DWORD *)a1 = &CPlayerModule::vftable;
  *(_DWORD *)(a1 - 4) = &CPlayerModule::vftable;
  PlayerModule::~PlayerModule((PlayerModule *)(a1 != 4 ? a1 : 0));
  if ( a3 & 1 )
    operator delete(v3);
  return v3;
}
// 7E531C: using guessed type int (__stdcall *CPlayerModule::vftable)(char);
// 7E5338: using guessed type __int32 (__stdcall *CPlayerModule::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0059A7D0) --------------------------------------------------------  // acclient.c:452876
TResult *__thiscall CPlayerModule::QueryInterface(CPlayerModule *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S124_13 & 1 )
  {
    v4 = Offsets_14[0].key;
  }
  else
  {
    v4 = (_GUID *)&CPlayerModule_InterfaceType_97;
    _S124_13 |= 1u;
    Offsets_14[0].key = (_GUID *)&CPlayerModule_InterfaceType_97;
    dword_871178 = 0;
    dword_87117C = (int)&stru_7E5308;
    dword_871180 = 0;
    dword_871184 = 0;
    dword_871188 = 0;
  }
  v5 = (int)Offsets_14;
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
// 871178: using guessed type int dword_871178;
// 87117C: using guessed type int dword_87117C;
// 871180: using guessed type int dword_871180;
// 871184: using guessed type int dword_871184;
// 871188: using guessed type int dword_871188;

//----- (0059A890) --------------------------------------------------------  // acclient.c:452939
void __thiscall CPlayerModule::OnChanged(CPlayerModule *this, BaseProperty *i_prop, unsigned int i_nUserData)
{
  CPlayerModule *v3; // esi@1
  unsigned int v4; // eax@2

  v3 = this;
  CM_UI::SendNotice_GameplayOptionChanged(i_prop, i_nUserData);
  if ( !LOBYTE(v3->m_TimeStampFormat.m_buffer) )
  {
    LOBYTE(v3->m_TimeStampFormat.m_buffer) = 1;
    v4 = Timer::cur_time.Param;
    *((_DWORD *)&v3->m_bDirty + 1) = Timer::cur_time.Cmd;
    LODWORD(v3->m_timeFirstDirtied) = v4;
  }
}

//----- (0059A8E0) --------------------------------------------------------  // acclient.c:452956
void __thiscall CPlayerModule::OnChanged(CPlayerModule *this, PlayerOption i_po)
{
  PlayerModule *v2; // esi@1
  unsigned __int8 v3; // al@2
  char v4; // al@3
  char v5; // ST04_1@5
  ClientCombatSystem *v6; // eax@5
  int v7; // ecx@10
  bool v8; // al@11
  unsigned int v9; // edx@13

  v2 = (PlayerModule *)this;
  CM_UI::SendNotice_PlayerOptionChanged(i_po);
  switch ( i_po )
  {
    case 5u:
      v3 = PlayerModule::PersistentAtDay(v2);
      LScape::SetDay(v3);
      break;
    case 4u:
      v4 = PlayerModule::DisableMostWeatherEffects(v2);
      SmartBox::EnableWeather(v4 == 0);
      break;
    case 0x30u:
      LScape::m_fFogEnabled = (unsigned __int8)PlayerModule::DisableDistanceFog(v2) == 0;
      break;
    case 7u:
      v5 = PlayerModule::ViewCombatTarget(v2);
      v6 = ClientCombatSystem::GetCombatSystem();
      ClientCombatSystem::TrackTarget(v6, v5);
      break;
    case 2u:
      if ( (unsigned __int8)PlayerModule::IgnoreFellowshipRequests(v2) )
        PlayerModule::SetFellowshipAutoAcceptRequests(v2, 0);
      break;
    case 0x12u:
      if ( (unsigned __int8)PlayerModule::FellowshipAutoAcceptRequests(v2) )
        PlayerModule::SetIgnoreFellowshipRequests(v2, 0);
      break;
    default:
      break;
  }
  if ( CPlayerModule::IsAutoSaveOption(i_po) )
  {
    v8 = PlayerModule::GetOption(v2, i_po);
    CM_Character::Event_PlayerOptionChangedEvent(i_po, v8);
  }
  else if ( !*(_BYTE *)(v7 + 424) )
  {
    *(_BYTE *)(v7 + 424) = 1;
    v9 = Timer::cur_time.Param;
    *(_DWORD *)(v7 + 432) = Timer::cur_time.Cmd;
    *(_DWORD *)(v7 + 436) = v9;
  }
}
// 81CBE8: using guessed type bool LScape::m_fFogEnabled;

//----- (0070B080) --------------------------------------------------------  // acclient.c:798218
void sub_70B080()
{
  flt_8711B0 = 1000.0 + 1.0;
}

//----- (0070B0A0) --------------------------------------------------------  // acclient.c:798224
void sub_70B0A0()
{
  flt_8711B4 = 24.0 * 8.0;
}

//----- (0070B0C0) --------------------------------------------------------  // acclient.c:798230
void sub_70B0C0()
{
  flt_8711B8 = 24.0 * 0.5;
}

//----- (0070B0E0) --------------------------------------------------------  // acclient.c:798236
int sub_70B0E0()
{
  return atexit(nullsub_1437);
}

//----- (0070B0F0) --------------------------------------------------------  // acclient.c:798242
int sub_70B0F0()
{
  return atexit(nullsub_1438);
}

//----- (0070B100) --------------------------------------------------------  // acclient.c:798248
int sub_70B100()
{
  return atexit(nullsub_1439);
}

//----- (0070B110) --------------------------------------------------------  // acclient.c:798254
void sub_70B110()
{
  flt_8711BC = 0.00019999999 * 3.0 + 0.1;
}

//----- (0070B130) --------------------------------------------------------  // acclient.c:798260
void _E108_98()
{
  dbl_8711C0 = 1.0 / 30.0;
}

//----- (0070B150) --------------------------------------------------------  // acclient.c:798266
void _E110_81()
{
  dbl_8711C8 = 1.0 / 5.0;
}

//----- (0070B170) --------------------------------------------------------  // acclient.c:798272
void sub_70B170()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8711D0, PFID_A8R8G8B8);
}

//----- (0070B180) --------------------------------------------------------  // acclient.c:798278
void _E115_83()
{
  dword_871208 = 1024;
}

//----- (0070B190) --------------------------------------------------------  // acclient.c:798284
void _E117_77()
{
  dword_87120C = 0x7FFF;
}

//----- (0070B1A0) --------------------------------------------------------  // acclient.c:798290
int _E119_30()
{
  const int result; // eax@1

  result = dword_871208;
  dword_871210 = dword_871208;
  return result;
}

//----- (0070B1B0) --------------------------------------------------------  // acclient.c:798300
int _E121_70()
{
  return atexit(_E122_97);
}

//----- (0070B1C0) --------------------------------------------------------  // acclient.c:798306
int sub_70B1C0()
{
  return atexit(nullsub_1436);
}

