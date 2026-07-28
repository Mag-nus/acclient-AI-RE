/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : APIManager
   Object     : AC\accui_misc\APIManager.obj
   Functions  : 66
   Addresses  : 00526800 - 007731B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00526800) --------------------------------------------------------  // acclient.c:342013
signed int __stdcall FileNodeName_Double::GetType()
{
  return 3;
}

//----- (005599F0) --------------------------------------------------------  // acclient.c:392854
unsigned int __stdcall ATL::_AtlGetThreadACPFake()
{
  int v0; // esi@1
  LCID v1; // eax@1
  char v2; // al@2
  char *v3; // ecx@2
  unsigned int result; // eax@5
  char szACP[7]; // [sp+4h] [bp-8h]@1

  v0 = 0;
  v1 = GetThreadLocale();
  if ( !GetLocaleInfoA(v1, 0x1004u, szACP, 7) )
    goto LABEL_9;
  v2 = szACP[0];
  v3 = szACP;
  if ( !szACP[0] )
    goto LABEL_9;
  do
  {
    ++v3;
    v0 = v2 + 10 * v0 - 48;
    v2 = *v3;
  }
  while ( *v3 );
  if ( v0 )
    result = v0;
  else
LABEL_9:
    result = GetACP();
  return result;
}

//----- (00559A50) --------------------------------------------------------  // acclient.c:392887
unsigned int __stdcall ATL::_AtlGetThreadACPThunk()
{
  LONG v0; // eax@2
  _OSVERSIONINFOA ver; // [sp+0h] [bp-94h]@1

  ver.dwOSVersionInfoSize = 148;
  GetVersionExA(&ver);
  if ( ver.dwPlatformId != 2 || (v0 = (LONG)FileNodeName_Double::GetType, ver.dwMajorVersion < 5) )
    v0 = (LONG)ATL::_AtlGetThreadACPFake;
  InterlockedExchange(&ATL::g_pfnGetThreadACP, v0);
  return ((unsigned int (__stdcall *)())ATL::g_pfnGetThreadACP)();
}
// 81FA8C: invalid function type has been ignored

//----- (00559AA0) --------------------------------------------------------  // acclient.c:392902
unsigned __int16 *__cdecl A2BSTR(const char *lp)
{
  UINT v1; // eax@2
  UINT v2; // edi@2
  int v3; // eax@2
  int v4; // ebx@2
  unsigned __int16 *v5; // eax@2
  unsigned __int16 *v6; // esi@2
  unsigned __int16 *result; // eax@4

  ((void (__stdcall *)())ATL::g_pfnGetThreadACP)();
  if ( lp )
  {
    v1 = ((unsigned int (__stdcall *)())ATL::g_pfnGetThreadACP)();
    v2 = v1;
    v3 = MultiByteToWideChar(v1, 0, lp, -1, 0, 0);
    v4 = v3;
    v5 = SysAllocStringLen(0, v3 - 1);
    v6 = v5;
    if ( v5 )
      MultiByteToWideChar(v2, 0, lp, -1, v5, v4);
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 81FA8C: invalid function type has been ignored
// 559AA0: could not find valid save-restore pair for ebx
// 559AA0: could not find valid save-restore pair for edi
// 559AA0: could not find valid save-restore pair for esi

//----- (00559B00) --------------------------------------------------------  // acclient.c:392937
IACPlugin *__cdecl APIManager::GetACPlugin()
{
  IACPlugin *result; // eax@2

  if ( APIManager::m_pCliAPI )
    result = APIManager::m_pCliAPI->m_pPlugin;
  else
    result = 0;
  return result;
}

//----- (00559B10) --------------------------------------------------------  // acclient.c:392949
HRESULT __stdcall APIManager::IAsheronsCallImpl::QueryInterface(APIManager::IAsheronsCallImpl *this, _GUID *riid, void **ppvObject)
{
  HRESULT result; // eax@2

  if ( ppvObject )
  {
    if ( !memcmp(riid, &_GUID_00000000_0000_0000_c000_000000000046, 0x10u) || !memcmp(riid, &IID_IAsheronsCall, 0x10u) )
    {
      *ppvObject = this;
      this->vfptr->AddRef((IUnknown *)this);
      result = 0;
    }
    else
    {
      *ppvObject = 0;
      result = -2147467262;
    }
  }
  else
  {
    result = -2147467261;
  }
  return result;
}

//----- (00559B70) --------------------------------------------------------  // acclient.c:392975
LONG __stdcall APIManager::IAsheronsCallImpl::AddRef(APIManager::IAsheronsCallImpl *this)
{
  return InterlockedIncrement(&this->m_cRef);
}

//----- (00559B90) --------------------------------------------------------  // acclient.c:392981
HRESULT __stdcall APIManager::IAsheronsCallImpl::IssueChatBarCommand(APIManager::IAsheronsCallImpl *this, unsigned __int16 *const txt, const int isBotOriginated)
{
  return -2147467259;
}

//----- (00559BA0) --------------------------------------------------------  // acclient.c:392987
HRESULT __stdcall APIManager::IAsheronsCallImpl::SelectItem(APIManager::IAsheronsCallImpl *this, const unsigned int objectID)
{
  ACCWeenieObject::SetSelectedObject(objectID, 0);
  return 0;
}

//----- (00559BC0) --------------------------------------------------------  // acclient.c:392994
HRESULT __stdcall APIManager::IAsheronsCallImpl::SetSelectedObjectID(APIManager::IAsheronsCallImpl *this, const unsigned int objectID)
{
  ACCWeenieObject::SetSelectedObjectID(objectID);
  return 0;
}

//----- (00559BE0) --------------------------------------------------------  // acclient.c:393001
HRESULT __stdcall APIManager::IAsheronsCallImpl::SetPreviousSelectedItemID(APIManager::IAsheronsCallImpl *this, const unsigned int objectID)
{
  ACCWeenieObject::SetPreviousSelectedObject(objectID);
  return 0;
}

//----- (00559C00) --------------------------------------------------------  // acclient.c:393008
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetSelectedItemID(APIManager::IAsheronsCallImpl *this, unsigned int *selectedID)
{
  *selectedID = ACCWeenieObject::selectedID;
  return 0;
}

//----- (00559C20) --------------------------------------------------------  // acclient.c:393015
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetPreviousSelectedItemID(APIManager::IAsheronsCallImpl *this, unsigned int *selectedID)
{
  *selectedID = ACCWeenieObject::prevSelectedID;
  return 0;
}

//----- (00559C40) --------------------------------------------------------  // acclient.c:393022
HRESULT __stdcall APIManager::IAsheronsCallImpl::ExamineObject(APIManager::IAsheronsCallImpl *this, const unsigned int objectID)
{
  ClientUISystem *v2; // eax@1

  v2 = ClientUISystem::GetUISystem();
  ClientUISystem::ExamineObject(v2, objectID);
  return 0;
}

//----- (00559C60) --------------------------------------------------------  // acclient.c:393032
HRESULT __stdcall APIManager::IAsheronsCallImpl::UseObject(APIManager::IAsheronsCallImpl *this, const unsigned int objectID)
{
  ItemHolder::UseObject(objectID, 0, 0);
  return 0;
}

//----- (00559C80) --------------------------------------------------------  // acclient.c:393039
HRESULT __thiscall APIManager::IAsheronsCallImpl::UseObjectOn(unsigned int ecx0, APIManager::IAsheronsCallImpl *this, const unsigned int useThisID, const unsigned int onThisID)
{
  APIManager::IAsheronsCallImpl *v4; // esi@1
  IUnknownVtbl *v5; // eax@1
  unsigned int curSel; // [sp+10h] [bp-4h]@1

  curSel = ecx0;
  v4 = this;
  v5 = this->vfptr;
  curSel = 0;
  ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, unsigned int *))v5[2].Release)(this, &curSel);
  ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, const unsigned int))v4->vfptr[2].QueryInterface)(v4, onThisID);
  ItemHolder::UseObject(useThisID, 1, 0);
  ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, unsigned int))v4->vfptr[2].QueryInterface)(v4, curSel);
  return 0;
}

//----- (00559CD0) --------------------------------------------------------  // acclient.c:393057
HRESULT __thiscall APIManager::IAsheronsCallImpl::UseEquippedItem(unsigned int ecx0, APIManager::IAsheronsCallImpl *this, const unsigned int useThisID, const unsigned int onThisID)
{
  APIManager::IAsheronsCallImpl *v4; // esi@1
  IUnknownVtbl *v5; // eax@1
  unsigned int curSel; // [sp+10h] [bp-4h]@1

  curSel = ecx0;
  v4 = this;
  v5 = this->vfptr;
  curSel = 0;
  ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, unsigned int *))v5[2].Release)(this, &curSel);
  ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, const unsigned int))v4->vfptr[2].QueryInterface)(v4, onThisID);
  ItemHolder::UseObject(useThisID, 1, 1);
  ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, unsigned int))v4->vfptr[2].QueryInterface)(v4, curSel);
  return 0;
}

//----- (00559D20) --------------------------------------------------------  // acclient.c:393075
HRESULT __stdcall APIManager::IAsheronsCallImpl::ChangeCombatMode(APIManager::IAsheronsCallImpl *this, eCombatMode newCombatMode)
{
  HRESULT result; // eax@5

  if ( newCombatMode == 1 || newCombatMode == 2 || newCombatMode == 4 || newCombatMode == 8 )
  {
    if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
      result = 0;
    else
      result = -2147467259;
  }
  else
  {
    result = -2147418113;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (00559D70) --------------------------------------------------------  // acclient.c:393095
BOOL __stdcall APIManager::IAsheronsCallImpl::MoveItemExternal(APIManager::IAsheronsCallImpl *this, const unsigned int objectID, const unsigned int draggedOnID, const int dropIfGiveFails)
{
  return ItemHolder::AttemptPlaceIn3D(objectID, draggedOnID, dropIfGiveFails) == 0;
}

//----- (00559D90) --------------------------------------------------------  // acclient.c:393101
BOOL __stdcall APIManager::IAsheronsCallImpl::MoveItemInternal(APIManager::IAsheronsCallImpl *this, const unsigned int objectID, const unsigned int containerID, const int place, const int attemptAutoMerge)
{
  return ItemHolder::AttemptToPlaceInContainer(objectID, containerID, 0, attemptAutoMerge, place) == 0;
}

//----- (00559DC0) --------------------------------------------------------  // acclient.c:393107
HRESULT __fastcall APIManager::IAsheronsCallImpl::CastSpell(eCombatMode a1, int a2, APIManager::IAsheronsCallImpl *this, const unsigned int spellID, const unsigned int targetID)
{
  ClientUISystem *v5; // eax@2
  APIManager::IAsheronsCallImpl *v6; // esi@3
  IUnknownVtbl *v7; // eax@3
  IUnknownVtbl *v8; // edx@4
  HRESULT result; // eax@4
  eCombatMode curCombatMode; // [sp+10h] [bp-4h]@1

  curCombatMode = a1;
  if ( APIManager::m_UIReady
    && (v5 = ClientUISystem::GetUISystem(), (curCombatMode = v5 != 0) != 0)
    && (v6 = this,
        v7 = this->vfptr,
        curCombatMode = 0,
        ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, eCombatMode *))v7[5].QueryInterface)(this, &curCombatMode),
        curCombatMode == 8) )
  {
    v8 = v6->vfptr;
    this = 0;
    ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, APIManager::IAsheronsCallImpl **))v8[2].Release)(v6, &this);
    ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, const unsigned int))v6->vfptr[2].QueryInterface)(v6, targetID);
    ((void (__stdcall *)(APIManager::IAsheronsCallImpl *, APIManager::IAsheronsCallImpl *))v6->vfptr[2].QueryInterface)(
      v6,
      this);
    result = 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (00559E40) --------------------------------------------------------  // acclient.c:393143
HRESULT __stdcall APIManager::IAsheronsCallImpl::SetSelectedStackCount(APIManager::IAsheronsCallImpl *this, int *isOpen)
{
  return -2147467259;
}

//----- (00559E50) --------------------------------------------------------  // acclient.c:393149
HRESULT __stdcall APIManager::IAsheronsCallImpl::DecrementBusyCount(APIManager::IAsheronsCallImpl *this)
{
  return -2147467259;
}

//----- (00559E60) --------------------------------------------------------  // acclient.c:393155
HRESULT __stdcall APIManager::IAsheronsCallImpl::IsStandingStill(APIManager::IAsheronsCallImpl *this, int *isStandingStill)
{
  CommandInterpreter *v2; // ecx@2
  HRESULT result; // eax@3

  if ( SmartBox::smartbox && (v2 = SmartBox::smartbox->cmdinterp) != 0 )
  {
    *isStandingStill = ((int (*)(void))v2->vfptr[15].OnAction)();
    result = 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}

//----- (00559E90) --------------------------------------------------------  // acclient.c:393173
HRESULT __stdcall APIManager::IAsheronsCallImpl::StopCompletely(APIManager::IAsheronsCallImpl *this)
{
  CommandInterpreter *v1; // ecx@2
  HRESULT result; // eax@4

  if ( SmartBox::smartbox && (v1 = SmartBox::smartbox->cmdinterp) != 0 && ((int (*)(void))v1->vfptr[15].OnLoseFocus)() )
    result = 0;
  else
    result = -2147467259;
  return result;
}

//----- (00559EC0) --------------------------------------------------------  // acclient.c:393186
HRESULT __stdcall APIManager::IAsheronsCallImpl::TurnToHeading(APIManager::IAsheronsCallImpl *this, const float heading)
{
  HRESULT result; // eax@5

  if ( heading >= 0.0 && heading < 360.0 && SmartBox::smartbox && SmartBox::smartbox->cmdinterp )
  {
    this->vfptr[7].Release((IUnknown *)this);
    ((void (__stdcall *)(_DWORD, _DWORD))SmartBox::smartbox->cmdinterp->vfptr[16].OnAction)(LODWORD(heading), 0);
    result = 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}

//----- (00559F30) --------------------------------------------------------  // acclient.c:393204
HRESULT __stdcall APIManager::IAsheronsCallImpl::SetAutoRun(APIManager::IAsheronsCallImpl *this, const int val)
{
  CommandInterpreter *v2; // ecx@2
  HRESULT result; // eax@5

  if ( SmartBox::smartbox && (v2 = SmartBox::smartbox->cmdinterp) != 0 )
  {
    ((void (__stdcall *)(const int, signed int))v2->vfptr[17].__vecDelDtor)(val, 1);
    if ( !val )
      this->vfptr[7].Release((IUnknown *)this);
    result = 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}

//----- (00559F70) --------------------------------------------------------  // acclient.c:393224
HRESULT __stdcall CBaseInputPin::GetAllocatorRequirements(APIManager::IAsheronsCallImpl *this, int *outdoors)
{
  return -2147467263;
}

//----- (00559F80) --------------------------------------------------------  // acclient.c:393230
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetCurCoords(APIManager::IAsheronsCallImpl *this, long double *coordX, long double *coordY)
{
  CPlayerSystem *v3; // eax@3
  HRESULT result; // eax@4

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 && (v3 = CPlayerSystem::GetPlayerSystem()) != 0 )
    result = CPlayerSystem::InqPlayerCoords(v3, coordX, coordY) == 0;
  else
    result = -2147467259;
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (00559FD0) --------------------------------------------------------  // acclient.c:393244
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetCurLoc(APIManager::IAsheronsCallImpl *this, unsigned int *landblock, float *x, float *y, float *z, float *heading)
{
  int v6; // ST00_4@2

  if ( APIManager::m_UIReady )
    v6 = ClientUISystem::GetUISystem() != 0;
  return -2147467259;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A000) --------------------------------------------------------  // acclient.c:393255
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetPlayerID(APIManager::IAsheronsCallImpl *this, unsigned int *id)
{
  HRESULT result; // eax@4

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
  {
    if ( SmartBox::smartbox )
    {
      *id = SmartBox::smartbox->player_id;
      result = 0;
    }
    else
    {
      result = 0;
      *id = 0;
    }
  }
  else
  {
    result = -2147467259;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A050) --------------------------------------------------------  // acclient.c:393281
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetVendorID(APIManager::IAsheronsCallImpl *this, unsigned int *id)
{
  HRESULT result; // eax@3

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
    result = 0;
  else
    result = -2147467259;
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A080) --------------------------------------------------------  // acclient.c:393294
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetGroundContainerID(APIManager::IAsheronsCallImpl *this, unsigned int *id)
{
  HRESULT result; // eax@3

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
  {
    *id = ClientUISystem::GetUISystem()->groundObject;
    result = 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A0C0) --------------------------------------------------------  // acclient.c:393312
HRESULT __stdcall APIManager::IAsheronsCallImpl::TradeWindow_Clear(APIManager::IAsheronsCallImpl *this)
{
  CM_Trade::Event_ResetTrade();
  return 0;
}

//----- (0055A0D0) --------------------------------------------------------  // acclient.c:393319
HRESULT __stdcall APIManager::IAsheronsCallImpl::EndCharacterSession(APIManager::IAsheronsCallImpl *this)
{
  CPlayerSystem *v1; // eax@3
  HRESULT result; // eax@3

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
  {
    v1 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::LogOffCharacter(v1, 0);
    result = 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A110) --------------------------------------------------------  // acclient.c:393339
HRESULT __stdcall APIManager::IAsheronsCallImpl::BeginCharacterSession(APIManager::IAsheronsCallImpl *this, unsigned int iidCharacter)
{
  CPlayerSystem *v2; // eax@3
  HRESULT result; // eax@3

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
  {
    v2 = CPlayerSystem::GetPlayerSystem();
    result = CPlayerSystem::LogOnCharacter(v2, iidCharacter) == 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A150) --------------------------------------------------------  // acclient.c:393358
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetScreenDimensions(APIManager::IAsheronsCallImpl *this, int *area3DWidth, int *area3DHeight)
{
  *area3DWidth = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
  *area3DHeight = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
  return 0;
}

//----- (0055A180) --------------------------------------------------------  // acclient.c:393366
HRESULT __stdcall APIManager::IAsheronsCallImpl::ItemIsKnown(APIManager::IAsheronsCallImpl *this, const unsigned int itemID, int *isKnown)
{
  HRESULT result; // eax@3

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
  {
    *isKnown = ClientObjMaintSystem::GetWeenieObject(itemID) != 0;
    result = 0;
  }
  else
  {
    result = 0;
    *isKnown = 0;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A1D0) --------------------------------------------------------  // acclient.c:393385
LONG __stdcall APIManager::IAsheronsCallImpl::Release(APIManager::IAsheronsCallImpl *this)
{
  LONG v1; // edi@1

  v1 = InterlockedDecrement(&this->m_cRef);
  if ( !v1 && this )
  {
    this->vfptr = (IUnknownVtbl *)&APIManager::IAsheronsCallImpl::vftable;
    operator delete(this);
  }
  return v1;
}
// 7CC0F8: using guessed type __int32 (__stdcall *APIManager::IAsheronsCallImpl::vftable)(APIManager::IAsheronsCallImpl *this, _GUID *riid, void **ppvObject);

//----- (0055A200) --------------------------------------------------------  // acclient.c:393400
HRESULT __stdcall APIManager::IAsheronsCallImpl::GetItemName(APIManager::IAsheronsCallImpl *this, const unsigned int itemID, unsigned __int16 **itemName)
{
  HashBaseData<unsigned long> *v3; // esi@3
  HashBaseData<unsigned long>Vtbl *v4; // esi@4
  HRESULT result; // eax@7

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(itemID);
    if ( v3 )
    {
      ((void (__stdcall *)())ATL::g_pfnGetThreadACP)();
      v4 = v3[13].vfptr;
      InterlockedIncrement((volatile LONG *)&v4[1]);
      *itemName = A2BSTR((const char *)&v4[5]);
      if ( !InterlockedDecrement((volatile LONG *)&v4[1]) )
      {
        if ( v4 )
          (*(void (__thiscall **)(HashBaseData<unsigned long>Vtbl *, signed int))v4->__vecDelDtor)(v4, 1);
      }
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = -2147467259;
  }
  return result;
}
// 81FA8C: invalid function type has been ignored
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A290) --------------------------------------------------------  // acclient.c:393437
IAsheronsCall *__thiscall APIManager::GetAsheronsCallImpl(APIManager *this)
{
  APIManager *v1; // esi@1
  IAsheronsCall *result; // eax@1

  v1 = this;
  result = this->m_pAsheronsCallImpl;
  if ( !result )
  {
    result = (IAsheronsCall *)operator new(8u);
    if ( result )
    {
      result->vfptr = (IUnknownVtbl *)&APIManager::IAsheronsCallImpl::vftable;
      v1->m_pAsheronsCallImpl = result;
    }
    else
    {
      result = 0;
      v1->m_pAsheronsCallImpl = 0;
    }
  }
  return result;
}
// 7CC0F8: using guessed type __int32 (__stdcall *APIManager::IAsheronsCallImpl::vftable)(APIManager::IAsheronsCallImpl *this, _GUID *riid, void **ppvObject);

//----- (0055A2C0) --------------------------------------------------------  // acclient.c:393463
int __cdecl APIManager::Init()
{
  bool v0; // al@1
  char *v1; // esi@1
  bool v2; // bl@1
  int v3; // esi@5
  bool v4; // zf@6
  HMODULE v5; // eax@7
  char *v6; // esi@8
  FARPROC v8; // esi@11
  APIManager *v9; // eax@17
  int v10; // [sp+4h] [bp-18h]@0
  PStringBase<char> pluginPath; // [sp+Ch] [bp-10h]@1
  PStringBase<char> _opt; // [sp+10h] [bp-Ch]@1

  pluginPath.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::PStringBase<char>(&_opt, "ACPlugin");
  v0 = ClientRegKey::GetClientOptions(&_opt, &pluginPath);
  v1 = &_opt.m_charbuffer[-2].m_data[12];
  v2 = v0 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&_opt.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(char *, signed int))v1)(v1, 1);
  if ( v2 )
  {
    v3 = (int)&pluginPath.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&pluginPath.m_charbuffer[-1]) )
    {
      v4 = v3 == 0;
      goto LABEL_14;
    }
    return 0;
  }
  v5 = LoadLibraryA(pluginPath.m_charbuffer->m_data);
  if ( !v5 )
  {
    v6 = &pluginPath.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&pluginPath.m_charbuffer[-1]) && v6 )
    {
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      return 0;
    }
    return 0;
  }
  v8 = GetProcAddress(v5, "CreateACPlugin");
  if ( !v8 )
  {
    v3 = v10 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v10 - 20 + 4)) )
    {
      v4 = v10 == 20;
LABEL_14:
      if ( !v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    return 0;
  }
  v9 = APIManager::m_pCliAPI;
  if ( !APIManager::m_pCliAPI )
  {
    v9 = (APIManager *)operator new(8u);
    if ( v9 )
    {
      v9->m_pPlugin = 0;
      v9->m_pAsheronsCallImpl = 0;
    }
    else
    {
      v9 = 0;
    }
    APIManager::m_pCliAPI = v9;
  }
  pluginPath.m_charbuffer = 0;
  _opt.m_charbuffer = (PSRefBufferCharData<char> *)APIManager::GetAsheronsCallImpl(v9);
  ((void (__cdecl *)(PStringBase<char> *, PStringBase<char> *))v8)(&_opt, &pluginPath);
  if ( !APIManager::m_pCliAPI->m_pPlugin )
    APIManager::m_pCliAPI->m_pPlugin = (IACPlugin *)pluginPath.m_charbuffer;
  if ( !InterlockedDecrement((volatile LONG *)(v10 - 20 + 4)) && v10 != 20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))(v10 - 20))(v10 - 20, 1);
  return 1;
}

//----- (0055A430) --------------------------------------------------------  // acclient.c:393546
void __cdecl APIManager::SetUIReady(int isReady)
{
  if ( !isReady && APIManager::m_pCliAPI && APIManager::m_pCliAPI->m_pAsheronsCallImpl )
    APIManager::GetAsheronsCallImpl(APIManager::m_pCliAPI);
  APIManager::m_UIReady = isReady;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (0055A460) --------------------------------------------------------  // acclient.c:393555
int __cdecl APIManager::APIIsReady()
{
  char *v0; // esi@3
  IAsheronsCall *v1; // eax@3
  int result; // eax@9

  if ( !APIManager::m_pCliAPI || !APIManager::m_pCliAPI->m_pPlugin )
    goto LABEL_13;
  v0 = (char *)&APIManager::m_pCliAPI->m_pAsheronsCallImpl;
  v1 = APIManager::m_pCliAPI->m_pAsheronsCallImpl;
  if ( !v1 )
  {
    v1 = (IAsheronsCall *)operator new(8u);
    if ( v1 )
      v1->vfptr = (IUnknownVtbl *)&APIManager::IAsheronsCallImpl::vftable;
    else
      v1 = 0;
    *(_DWORD *)v0 = v1;
  }
  if ( v1 )
    result = 1;
  else
LABEL_13:
    result = 0;
  return result;
}
// 7CC0F8: using guessed type __int32 (__stdcall *APIManager::IAsheronsCallImpl::vftable)(APIManager::IAsheronsCallImpl *this, _GUID *riid, void **ppvObject);

//----- (0055A4A0) --------------------------------------------------------  // acclient.c:393584
HRESULT __stdcall APIManager::IAsheronsCallImpl::WriteToChat(APIManager::IAsheronsCallImpl *this, unsigned __int16 *const txt, eChatTypes type)
{
  unsigned int v3; // ST04_4@3
  ClientSystem *v4; // eax@3
  unsigned __int16 *const v5; // esi@3
  HRESULT result; // eax@6

  if ( APIManager::m_UIReady && ClientUISystem::GetUISystem() != 0 )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&txt, txt);
    v3 = type;
    v4 = (ClientSystem *)ClientUISystem::GetUISystem();
    ClientSystem::AddTextToScroll(v4, (PStringBase<unsigned short> *)&txt, v3, 0, 0);
    v5 = txt - 10;
    if ( !InterlockedDecrement((volatile LONG *)txt - 4) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(unsigned __int16 *const , signed int))v5)(v5, 1);
    }
    result = 0;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}
// 870048: using guessed type int APIManager::m_UIReady;

//----- (00707E70) --------------------------------------------------------  // acclient.c:795136
void sub_707E70()
{
  flt_870068 = 1000.0 + 1.0;
}

//----- (00707E90) --------------------------------------------------------  // acclient.c:795142
void sub_707E90()
{
  flt_87006C = 24.0 * 8.0;
}

//----- (00707EB0) --------------------------------------------------------  // acclient.c:795148
void sub_707EB0()
{
  flt_870070 = 24.0 * 0.5;
}

//----- (00707ED0) --------------------------------------------------------  // acclient.c:795154
int _E102_31()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_40;
  dword_870074 = LOWEST_DATA_RATE_40;
  return result;
}

//----- (00707EE0) --------------------------------------------------------  // acclient.c:795164
int _E104_15()
{
  return atexit(_E105_67);
}

//----- (00707EF0) --------------------------------------------------------  // acclient.c:795170
int _E107_38()
{
  return atexit(nullsub_1313);
}

//----- (00707F00) --------------------------------------------------------  // acclient.c:795176
int _E110_67()
{
  return atexit(_E111_70);
}

//----- (00707F10) --------------------------------------------------------  // acclient.c:795182
int _E113_23()
{
  return atexit(_E114_77);
}

//----- (00707F20) --------------------------------------------------------  // acclient.c:795188
void _E116_23()
{
  flt_870078 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00707F40) --------------------------------------------------------  // acclient.c:795194
void _E118_73()
{
  dbl_870080 = 1.0 / 30.0;
}

//----- (00707F60) --------------------------------------------------------  // acclient.c:795200
void _E120_65()
{
  dbl_870088 = 1.0 / 5.0;
}

//----- (00707F80) --------------------------------------------------------  // acclient.c:795206
void _E122_28()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870090, PFID_A8R8G8B8);
}

//----- (00707F90) --------------------------------------------------------  // acclient.c:795212
int _E127_53()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_31, "Display.Resolution");
  return atexit(_E128_59);
}

//----- (00707FB0) --------------------------------------------------------  // acclient.c:795219
int _E130_49()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_31, "Display.FullScreen");
  return atexit(_E131_51);
}

//----- (00707FD0) --------------------------------------------------------  // acclient.c:795226
int _E133_41()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_31, "Display.RefreshRate");
  return atexit(_E134_35);
}

//----- (00707FF0) --------------------------------------------------------  // acclient.c:795233
int _E136_27()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_31, "Display.SyncToRefresh");
  return atexit(_E137_34);
}

//----- (00708010) --------------------------------------------------------  // acclient.c:795240
int sub_708010()
{
  return atexit(nullsub_1311);
}

//----- (00773120) --------------------------------------------------------  // acclient.c:906877
void __cdecl _E128_59()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773150) --------------------------------------------------------  // acclient.c:906890
void __cdecl _E131_51()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00773180) --------------------------------------------------------  // acclient.c:906903
void __cdecl _E134_35()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007731B0) --------------------------------------------------------  // acclient.c:906916
void __cdecl _E137_34()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

