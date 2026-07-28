/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CInputManager_WIN32
   Object     : ENGINE\cinputmap_win32\CInputManager_WIN32.obj
   Functions  : 118
   Addresses  : 00685F90 - 0077FA80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00685F90) --------------------------------------------------------  // acclient.c:669646
unsigned int __thiscall ControlSpecification::operator%(ControlSpecification *this, unsigned int nBuckets)
{
  return this->m_dwKey % nBuckets;
}

//----- (00685FA0) --------------------------------------------------------  // acclient.c:669652
void __thiscall CInputManager_WIN32::InputDevice::InputDevice(CInputManager_WIN32::InputDevice *this)
{
  this->pDev = 0;
  this->guidInstance = (_GUID)INVALID_GUID_0;
  this->guidProduct = (_GUID)INVALID_GUID_0;
  this->iDeviceIndex = -1;
  this->nType = 0;
  this->bActive = 0;
}

//----- (00686010) --------------------------------------------------------  // acclient.c:669663
char __thiscall CInputManager_WIN32::InitializeKeymap(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  ActionMap *v2; // ecx@1

  v1 = this;
  ((void (*)(void))this->vfptr->ClearKeyMap)();
  v2 = v1->m_action_map;
  if ( v2 )
    ((void (*)(void))v2->vfptr[3].QueryInterface)();
  return 1;
}

//----- (00686030) --------------------------------------------------------  // acclient.c:669677
char __thiscall CInputManager_WIN32::AddDeviceToInputMap(CInputManager_WIN32 *this, CInputManager_WIN32::InputDevice *inputDevice)
{
  int v2; // eax@8
  DeviceKeyMapEntry dkme; // [sp+4h] [bp-14h]@4

  switch ( inputDevice->nType )
  {
    case 0x12u:
      dkme.dt = 2;
      break;
    case 0x13u:
      dkme.dt = 1;
      break;
    case 0x1Cu:
      dkme.dt = 4;
      break;
    default:
      dkme.dt = 3;
      break;
  }
  dkme.guid.m_data1 = inputDevice->guidInstance.Data1;
  *(_DWORD *)&dkme.guid.m_data2 = *(_DWORD *)&inputDevice->guidInstance.Data2;
  v2 = *(_DWORD *)&inputDevice->guidInstance.Data4[4];
  *(_DWORD *)&dkme.guid.m_data4[0] = *(_DWORD *)&inputDevice->guidInstance.Data4[0];
  *(_DWORD *)&dkme.guid.m_data4[4] = v2;
  inputDevice->iDeviceIndex = CMasterInputMap::AddDeviceEntry(&this->m_InputMap, &dkme);
  return 1;
}

//----- (006860B0) --------------------------------------------------------  // acclient.c:669707
char __thiscall CInputManager_WIN32::ClearKeyMap(CInputManager_WIN32 *this)
{
  CMasterInputMap::Clear(&this->m_InputMap);
  return 1;
}

//----- (006860C0) --------------------------------------------------------  // acclient.c:669714
bool __thiscall CInputManager_WIN32::IsMetaKey(CInputManager_WIN32 *this, ControlSpecification key)
{
  return CMasterInputMap::IsMetaKey(&this->m_InputMap, key);
}

//----- (006860E0) --------------------------------------------------------  // acclient.c:669720
char __thiscall CInputManager_WIN32::PollDevice(CInputManager_WIN32 *this, IDirectInputDevice8A *_pDev, bool _bAttemptAcquire)
{
  bool i; // bl@2
  int v4; // eax@3
  bool v5; // zf@8
  char result; // al@14

  if ( _pDev )
  {
    for ( i = _bAttemptAcquire; ; i = 0 )
    {
      v4 = ((int (__thiscall *)(_DWORD, _DWORD))_pDev->vfptr[8].AddRef)(this, _pDev);
      if ( v4 >= 0 )
        break;
      if ( v4 > -2147024875 )
      {
        v5 = v4 == -2147024866;
      }
      else
      {
        if ( v4 == -2147024875 || v4 == -2147220985 || v4 == -2147220983 )
          return 0;
        v5 = v4 == -2147024884;
      }
      if ( !v5 || !i || (_pDev->vfptr[2].AddRef((IUnknown *)_pDev) & 0x80000000) != 0 )
        return 0;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00686150) --------------------------------------------------------  // acclient.c:669757
void __thiscall CInputManager_WIN32::UpdateCharacter(CInputManager_WIN32 *this, int charToHandle)
{
  CInputManager_WIN32 *v2; // esi@1

  v2 = this;
  if ( !this->m_bIgnoreNextChar && this->m_textMode && this->m_fMainWindowHasFocus )
    CInputManager::CallCharacterHandler((CInputManager *)&this->vfptr, charToHandle);
  v2->m_bIgnoreNextChar = 0;
}

//----- (00686190) --------------------------------------------------------  // acclient.c:669768
signed int __stdcall CInputManager_WIN32::DITypeToControlType(unsigned int dwType)
{
  signed int result; // eax@2

  switch ( (unsigned __int8)dwType )
  {
    case 4u:
    case 8u:
      result = 1;
      break;
    case 1u:
      result = 2;
      break;
    case 2u:
      result = 3;
      break;
    case 0x10u:
      result = 4;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (00686200) --------------------------------------------------------  // acclient.c:669795
signed int __stdcall CInputManager_WIN32::DIDataToActivationType(ControlType ct, unsigned int dwData, float *o_rData)
{
  signed int result; // eax@3

  switch ( ct )
  {
    case 1:
      if ( dwData == 128 )
      {
        *(_DWORD *)o_rData = 1065353216;
        result = 1;
      }
      else
      {
        *(_DWORD *)o_rData = 0;
        result = 2;
      }
      break;
    case 2:
      result = 128;
      *o_rData = (double)(signed int)dwData;
      break;
    case 3:
      *o_rData = (double)(signed int)dwData * 0.0625;
      result = 128;
      break;
    case 4:
      if ( dwData == -1 || dwData == 1 )
      {
        *(_DWORD *)o_rData = -1082130432;
        result = 128;
      }
      else
      {
        result = 128;
        *o_rData = (double)dwData * 0.00027777778;
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (006862D0) --------------------------------------------------------  // acclient.c:669841
signed int __stdcall CInputManager_WIN32::SubControlFromData(ControlType ct, unsigned int dwData)
{
  signed int result; // eax@7

  if ( (signed int)ct < 2 )
    return 0;
  if ( (signed int)ct > 3 )
  {
    if ( ct == 4 && dwData != -1 && dwData != 1 )
    {
      if ( dwData >= 0x1C2 )
      {
        if ( dwData >= 0x546 )
        {
          if ( dwData >= 0x8CA )
            result = dwData < 0xC4E ? 6 : 3;
          else
            result = 5;
        }
        else
        {
          result = 4;
        }
      }
      else
      {
        result = 3;
      }
      return result;
    }
    return 0;
  }
  if ( (signed int)dwData <= 0 )
    result = (dwData & 0x80000000) == 0 ? 0 : 2;
  else
    result = 1;
  return result;
}

//----- (00686360) --------------------------------------------------------  // acclient.c:669881
void __thiscall CInputManager_WIN32::SyncCursorToMousePos(CInputManager_WIN32 *this)
{
  int v1; // eax@1
  int v2; // edx@1
  HWND__ *v3; // ecx@1
  tagPOINT pt; // [sp+0h] [bp-8h]@1

  v1 = this->m_ptMousePos.x;
  v2 = this->m_ptMousePos.y;
  v3 = this->m_hwnd;
  pt.x = v1;
  pt.y = v2;
  if ( ClientToScreen(v3, &pt) )
    SetCursorPos(pt.x, pt.y);
}

//----- (006863A0) --------------------------------------------------------  // acclient.c:669898
char __thiscall CInputManager_WIN32::BindAction(CInputManager_WIN32 *this, QualifiedControl i_key, unsigned int i_idAction, unsigned int i_idMap)
{
  CInputMap *v4; // eax@1
  _BYTE v5[12]; // ST04_12@2
  char result; // al@2

  v4 = CMasterInputMap::CreateInputMap(&this->m_InputMap, i_idMap);
  if ( v4 )
  {
    *(_DWORD *)v5 = i_key.m_key.m_dwKey;
    *(_QWORD *)&v5[4] = *(_QWORD *)&i_key.m_metamode;
    result = CInputMap::AddMapping(v4, i_idAction, *(QualifiedControl *)v5);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006863F0) --------------------------------------------------------  // acclient.c:669919
char __thiscall CInputManager_WIN32::FindConflictingInputMaps(CInputManager_WIN32 *this, unsigned int i_eMapID, List<unsigned long> *o_listMapIDs)
{
  ActionMap *v3; // ecx@1
  char result; // al@2

  v3 = this->m_action_map;
  if ( v3 )
    result = ActionMap::GetConflictingInputMaps(v3, i_eMapID, o_listMapIDs);
  else
    result = 0;
  return result;
}

//----- (00686410) --------------------------------------------------------  // acclient.c:669933
void __thiscall CInputManager_WIN32::SendActionToListeners(CInputManager_WIN32 *this, InputEvent *i_inEvt)
{
  CInputManager_WIN32 *v2; // esi@1

  v2 = this;
  if ( this->m_bProcessingKeyDown )
    this->m_bProcessingActionInResponseToKeyDown = 1;
  CInputManager::SendActionToListeners((CInputManager *)&this->vfptr, i_inEvt);
  v2->m_bProcessingActionInResponseToKeyDown = 0;
}

//----- (00686440) --------------------------------------------------------  // acclient.c:669945
void __thiscall SmartArray<CInputManager_WIN32::InputDevice,1>::Reset(SmartArray<CInputManager_WIN32::InputDevice,1> *this)
{
  SmartArray<CInputManager_WIN32::InputDevice,1> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ebx@5
  void *v6; // edi@6
  bool v7; // zf@6
  const void *v8; // eax@6
  int v9; // [sp+8h] [bp-34h]@5
  CInputManager_WIN32::InputDevice v10; // [sp+Ch] [bp-30h]@6

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v9 = v4 + 1;
      do
      {
        CInputManager_WIN32::InputDevice::InputDevice(&v10);
        v6 = &v1->m_data[v5];
        --v5;
        v7 = v9 == 1;
        qmemcpy(v6, v8, 0x30u);
        --v9;
      }
      while ( !v7 );
    }
  }
}

//----- (006864C0) --------------------------------------------------------  // acclient.c:669990
char __thiscall CInputManager_WIN32::AddKeyMap(CInputManager_WIN32 *this, unsigned int _actID)
{
  CInputManager_WIN32 *v2; // edi@1
  int v3; // esi@1
  char result; // al@1
  char v5; // bl@2

  v2 = this;
  v3 = DBObj::GetByEnum(_actID, 10, 0x1Du);
  result = 0;
  if ( v3 )
  {
    v5 = CMasterInputMap::Merge(&v2->m_InputMap, (CMasterInputMap *)v3, 1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
    result = v5;
  }
  return result;
}

//----- (00686500) --------------------------------------------------------  // acclient.c:670010
void __thiscall CInputManager_WIN32::AcquireAll(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  unsigned int v2; // ebp@1
  int v3; // edi@2
  IDirectInputDevice8A *v4; // ecx@3
  CInputManager_WIN32::InputDevice *v5; // edx@4
  unsigned int dwItems; // [sp+8h] [bp-4h]@4

  v1 = this;
  v2 = 0;
  if ( this->m_aDevices.m_num )
  {
    v3 = 0;
    do
    {
      v4 = v1->m_aDevices.m_data[v3].pDev;
      if ( v4 )
      {
        v4->vfptr[2].AddRef((IUnknown *)v4);
        v5 = v1->m_aDevices.m_data;
        dwItems = -1;
        ((void (__stdcall *)(IDirectInputDevice8A *, signed int, _DWORD, unsigned int *, _DWORD))v5[v3].pDev->vfptr[3].AddRef)(
          v5[v3].pDev,
          20,
          0,
          &dwItems,
          0);
      }
      v1->m_aDevices.m_data[v3].bActive = 1;
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_aDevices.m_num );
  }
}

//----- (00686570) --------------------------------------------------------  // acclient.c:670048
void __thiscall CInputManager_WIN32::UnacquireAll(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  unsigned int v2; // ebp@1
  int v3; // edi@2
  IDirectInputDevice8A *v4; // eax@3

  v1 = this;
  v2 = 0;
  if ( this->m_aDevices.m_num )
  {
    v3 = 0;
    do
    {
      v4 = v1->m_aDevices.m_data[v3].pDev;
      if ( v4 )
      {
        v4->vfptr[2].Release((IUnknown *)v1->m_aDevices.m_data[v3].pDev);
        v1->m_aDevices.m_data[v3].bActive = 0;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_aDevices.m_num );
  }
}

//----- (006865C0) --------------------------------------------------------  // acclient.c:670076
void __thiscall CInputManager_WIN32::ReleaseDevices(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  unsigned int v2; // ebx@1
  int v3; // edi@2
  IDirectInputDevice8A *v4; // eax@3

  v1 = this;
  CInputManager_WIN32::UnacquireAll(this);
  v2 = 0;
  if ( v1->m_aDevices.m_num )
  {
    v3 = 0;
    do
    {
      v4 = v1->m_aDevices.m_data[v3].pDev;
      if ( v4 )
        v4->vfptr->Release((IUnknown *)v1->m_aDevices.m_data[v3].pDev);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_aDevices.m_num );
  }
  v1->m_aDevices.m_num = 0;
}

//----- (00686610) --------------------------------------------------------  // acclient.c:670103
bool __thiscall CInputManager_WIN32::IsMetaKeyDown(CInputManager_WIN32 *this, unsigned int idKey)
{
  CInputManager_WIN32 *v2; // esi@1
  ControlSpecification v3; // ST08_4@1
  unsigned int v4; // eax@1
  bool result; // al@2

  v2 = this;
  *((_WORD *)&v3.1 + 1) = idKey;
  LOWORD(v3.m_dwKey) = LOBYTE(this->m_aDevices.m_data[this->m_nKeyboardDevice].iDeviceIndex);
  v4 = CMasterInputMap::MetaModeFromKey(&this->m_InputMap, v3);
  if ( v4 )
    result = (v4 & v2->m_metaKeyMode) != 0;
  else
    result = 0;
  return result;
}

//----- (00686680) --------------------------------------------------------  // acclient.c:670122
bool __thiscall CInputManager_WIN32::ShiftKeyDown(CInputManager_WIN32 *this)
{
  return CInputManager_WIN32::IsMetaKeyDown(this, 0x2Au);
}

//----- (00686690) --------------------------------------------------------  // acclient.c:670128
bool __thiscall CInputManager_WIN32::CtrlKeyDown(CInputManager_WIN32 *this)
{
  return CInputManager_WIN32::IsMetaKeyDown(this, 0x1Du);
}

//----- (006866A0) --------------------------------------------------------  // acclient.c:670134
bool __thiscall CInputManager_WIN32::AltKeyDown(CInputManager_WIN32 *this)
{
  return CInputManager_WIN32::IsMetaKeyDown(this, 0x38u);
}

//----- (006866B0) --------------------------------------------------------  // acclient.c:670140
void __thiscall CInputManager_WIN32::OnSwitchTextMode(CInputManager_WIN32 *this, bool mode)
{
  if ( mode )
  {
    if ( this->m_bProcessingActionInResponseToKeyDown )
      this->m_bIgnoreNextChar = 1;
  }
}

//----- (006866D0) --------------------------------------------------------  // acclient.c:670150
IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0> *__thiscall IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vector_deleting_destructor(IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0> *v2; // esi@1
  HashTableData<ControlSpecification,enum ControlType> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0>Vtbl *)IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable;
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
// 7FEF48: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable[3])(void *, char);

//----- (00686710) --------------------------------------------------------  // acclient.c:670171
IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0> *__thiscall IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::scalar_deleting_destructor(IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0> *v2; // esi@1
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>Vtbl *)IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable;
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
// 7FEF4C: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable[2])(void *, char);

//----- (00686750) --------------------------------------------------------  // acclient.c:670192
IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *__thiscall IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vector_deleting_destructor(IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v2; // esi@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>Vtbl *)&IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vftable;
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
// 7FEF50: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vftable)(void *, char);

//----- (00686790) --------------------------------------------------------  // acclient.c:670213
char __thiscall SmartArray<CInputManager_WIN32::InputDevice,1>::grow(SmartArray<CInputManager_WIN32::InputDevice,1> *this, unsigned int i_nSize)
{
  SmartArray<CInputManager_WIN32::InputDevice,1> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // eax@5
  CInputManager_WIN32::InputDevice *v6; // ebp@5
  int v7; // ecx@7
  int v8; // eax@8
  unsigned int v9; // edx@8
  const void *v10; // esi@9
  void *v11; // edi@9

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<CInputManager_WIN32::InputDevice,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](48 * i_nSize);
    v6 = (CInputManager_WIN32::InputDevice *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(
        v5,
        0x30u,
        i_nSize,
        (void *(__thiscall *)(void *))CInputManager_WIN32::InputDevice::InputDevice);
      if ( v2->m_data )
      {
        v7 = v2->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          v9 = v2->m_num;
          do
          {
            v10 = &v2->m_data[v8];
            v11 = &v6[v8];
            --v8;
            --v9;
            qmemcpy(v11, v10, 0x30u);
          }
          while ( v9 );
          v3 = i_nSize;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = v6;
      v2->m_sizeAndDeallocate = v3 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00686850) --------------------------------------------------------  // acclient.c:670275
void __thiscall SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::Reset(SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *this)
{
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ecx@5
  int v6; // edx@5
  int v7; // eax@6

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v6 = v4 + 1;
      do
      {
        v7 = (int)&v1->m_data[v5];
        --v5;
        --v6;
        *(_DWORD *)v7 = -1;
        *(_DWORD *)(v7 + 4) = 0;
        *(_DWORD *)(v7 + 8) = 0;
        *(_DWORD *)(v7 + 12) = 0;
      }
      while ( v6 );
    }
  }
}

//----- (006868B0) --------------------------------------------------------  // acclient.c:670318
signed int __thiscall CInputManager_WIN32::GetDeviceTypeFromKey(CInputManager_WIN32 *this, ControlSpecification key)
{
  unsigned int v2; // esi@1
  unsigned int v3; // eax@1
  char *v4; // edx@2
  unsigned int v5; // eax@6
  signed int result; // eax@8

  v2 = this->m_aDevices.m_num;
  v3 = 0;
  if ( v2 )
  {
    v4 = (char *)&this->m_aDevices.m_data->iDeviceIndex;
    do
    {
      if ( *(_DWORD *)v4 == (unsigned __int8)key.m_dwKey )
        break;
      ++v3;
      v4 += 48;
    }
    while ( v3 < v2 );
  }
  if ( v3 >= v2 )
  {
    result = 0;
  }
  else
  {
    v5 = this->m_aDevices.m_data[v3].nType - 18;
    if ( v5 )
    {
      if ( v5 == 1 )
        result = 1;
      else
        result = 3;
    }
    else
    {
      result = 2;
    }
  }
  return result;
}

//----- (00686920) --------------------------------------------------------  // acclient.c:670363
char __thiscall SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::grow(SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebx@1
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *v3; // esi@1
  void *v5; // eax@5
  _STL::pair<QualifiedControl,unsigned long> *v6; // edi@5
  int v7; // eax@7
  int v8; // ecx@8
  unsigned int v9; // ebx@8
  int v10; // eax@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * i_nSize);
    v6 = (_STL::pair<QualifiedControl,unsigned long> *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(
        v5,
        0x10u,
        i_nSize,
        (void *(__thiscall *)(void *))_STL::pair<QualifiedControl,unsigned long>::pair<QualifiedControl,unsigned long>);
      if ( v3->m_data )
      {
        v7 = v3->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = (int)&v6[v7].first.m_activation;
          v9 = v3->m_num;
          do
          {
            v10 = (int)((char *)v3->m_data + -8 - (_DWORD)v6 + v8);
            *(_DWORD *)(v8 - 8) = *(_DWORD *)v10;
            *(_DWORD *)(v8 - 4) = *(_DWORD *)(v10 + 4);
            *(_DWORD *)v8 = *(_DWORD *)(v10 + 8);
            *(_DWORD *)(v8 + 4) = *(_DWORD *)(v10 + 12);
            v8 -= 16;
            --v9;
          }
          while ( v9 );
          v2 = i_nSize;
        }
        if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v3->m_data);
      }
      v3->m_data = v6;
      v3->m_sizeAndDeallocate = v2 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00686A00) --------------------------------------------------------  // acclient.c:670426
IntrusiveHashIterator<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *__thiscall IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::find_iterator(IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, IntrusiveHashIterator<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *result, PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *pData)
{
  unsigned int v3; // ebx@1
  unsigned int v4; // edi@1
  unsigned int v5; // edx@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v6; // ebp@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v7; // eax@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **i; // edx@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v9; // esi@4
  IntrusiveHashIterator<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v10; // eax@11

  v3 = this->m_numBuckets;
  v4 = pData->m_hashKey.m_dwKey;
  v5 = pData->m_hashKey.m_dwKey % v3;
  v6 = this->m_buckets;
  v7 = v6[v5];
  for ( i = &v6[v5]; v7; v7 = v7->m_hashNext )
  {
    if ( v7->m_hashKey.m_dwKey == v4 )
      break;
  }
  v9 = v7;
  if ( v7 )
  {
LABEL_5:
    while ( v9 != pData )
    {
      if ( v9->m_hashKey.m_dwKey != v4 )
      {
        v10 = result;
        result->m_currHashTable = this;
        result->m_currBucket = 0;
        result->m_currElement = 0;
        return v10;
      }
      v9 = v9->m_hashNext;
      if ( !v9 )
      {
        while ( 1 )
        {
          ++i;
          if ( i == &v6[v3] )
            goto LABEL_11;
          if ( *i )
          {
            v9 = *i;
            if ( *i )
              goto LABEL_5;
            goto LABEL_11;
          }
        }
      }
    }
  }
LABEL_11:
  v10 = result;
  result->m_currElement = v9;
  result->m_currHashTable = this;
  result->m_currBucket = i;
  return v10;
}

//----- (00686A90) --------------------------------------------------------  // acclient.c:670489
char __thiscall CInputManager_WIN32::AddKeyMap(CInputManager_WIN32 *this, PStringBase<char> strFilename)
{
  CInputManager_WIN32 *v2; // edi@1
  char *v3; // ecx@3
  int v4; // eax@3
  int v5; // esi@3
  char *v6; // esi@7
  char *v8; // esi@14
  char v9; // bl@18
  char *v10; // esi@21
  PFileParser parser; // [sp+8h] [bp-168h]@3
  CMasterInputMap am; // [sp+28h] [bp-148h]@10

  v2 = this;
  if ( !PFileNode::s_fallocPool.m_firstFreeChunk )
    FallocPool::AllocateNewPool(&PFileNode::s_fallocPool);
  v3 = PFileNode::s_fallocPool.m_firstFreeChunk;
  PFileNode::s_fallocPool.m_firstFreeChunk = *(char **)PFileNode::s_fallocPool.m_firstFreeChunk;
  PFileNode::PFileNode((PFileNode *)v3);
  v5 = v4;
  PFileParser::PFileParser(&parser);
  if ( !PFileParser::LoadFromFile(&parser, (PFileNode *)v5, &strFilename, 0) )
  {
    PFileParser::~PFileParser(&parser);
    if ( v5 && !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = &strFilename.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strFilename.m_charbuffer[-1]) && v6 )
    {
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      return 0;
    }
    return 0;
  }
  CMasterInputMap::CMasterInputMap(&am);
  if ( !CMasterInputMap::FromFileNode(&am, (PFileNode *)v5) )
  {
    CMasterInputMap::~CMasterInputMap(&am);
    PFileParser::~PFileParser(&parser);
    if ( v5 && !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v8 = &strFilename.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strFilename.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    return 0;
  }
  v9 = CMasterInputMap::Merge(&v2->m_InputMap, &am, 1);
  CMasterInputMap::~CMasterInputMap(&am);
  PFileParser::~PFileParser(&parser);
  if ( v5 && !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v10 = &strFilename.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strFilename.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  return v9;
}

//----- (00686C20) --------------------------------------------------------  // acclient.c:670547
char __thiscall CInputManager_WIN32::SaveKeyMap(CInputManager_WIN32 *this, PStringBase<char> strFilename)
{
  CInputManager_WIN32 *v2; // edi@1
  char *v3; // ecx@3
  PFileNode *v4; // eax@3
  PFileNode *v5; // esi@3
  char *v6; // esi@8
  char *v8; // esi@16
  PFileParser parser; // [sp+8h] [bp-20h]@4

  v2 = this;
  if ( !PFileNode::s_fallocPool.m_firstFreeChunk )
    FallocPool::AllocateNewPool(&PFileNode::s_fallocPool);
  v3 = PFileNode::s_fallocPool.m_firstFreeChunk;
  PFileNode::s_fallocPool.m_firstFreeChunk = *(char **)PFileNode::s_fallocPool.m_firstFreeChunk;
  PFileNode::PFileNode((PFileNode *)v3);
  v5 = v4;
  if ( CMasterInputMap::ToFileNode(&v2->m_InputMap, v4) )
  {
    PFileParser::PFileParser(&parser);
    if ( PFileParser::SaveToFile(&parser, v5, &strFilename) )
    {
      PFileParser::~PFileParser(&parser);
      if ( v5 && !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
      v6 = &strFilename.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strFilename.m_charbuffer[-1]) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
      return 1;
    }
    PFileParser::~PFileParser(&parser);
  }
  if ( v5 && !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
  v8 = &strFilename.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strFilename.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  return 0;
}

//----- (00686D10) --------------------------------------------------------  // acclient.c:670591
char __thiscall SmartArray<CInputManager_WIN32::InputDevice,1>::AddToEnd(SmartArray<CInputManager_WIN32::InputDevice,1> *this, CInputManager_WIN32::InputDevice *i_rData)
{
  SmartArray<CInputManager_WIN32::InputDevice,1> *v2; // ebx@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<CInputManager_WIN32::InputDevice,1>::grow(v2, v4)) != 0) )
  {
    qmemcpy(&v2->m_data[v2->m_num++], i_rData, sizeof(v2->m_data[v2->m_num++]));
    result = 1;
  }
  return result;
}

//----- (00686D70) --------------------------------------------------------  // acclient.c:670611
char __thiscall SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::SetNElements(SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  const unsigned int v6; // edx@7
  const unsigned int v7; // ecx@8
  int v8; // eax@9

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    v6 = i_nSize;
    if ( i_nSize < this->m_num )
    {
      v7 = i_nSize;
      do
      {
        v8 = (int)&v3->m_data[v7];
        *(_DWORD *)v8 = -1;
        *(_DWORD *)(v8 + 4) = 0;
        *(_DWORD *)(v8 + 8) = 0;
        *(_DWORD *)(v8 + 12) = 0;
        ++v6;
        ++v7;
      }
      while ( v6 < v3->m_num );
    }
    goto LABEL_10;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::grow(v3, v4);
  if ( result )
  {
LABEL_10:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (00686DF0) --------------------------------------------------------  // acclient.c:670656
void __thiscall IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_up(IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, unsigned int i, PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *data)
{
  unsigned int v3; // esi@1
  unsigned int v4; // edi@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v5; // ecx@2
  unsigned int v6; // eax@2
  unsigned int v7; // edx@2
  int v8; // ebx@3
  int v9; // ebp@3
  IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *j; // [sp+0h] [bp-4h]@1

  v3 = i;
  v4 = (i - 1) >> 1;
  for ( j = this; v3; v4 = (v4 - 1) >> 1 )
  {
    v5 = j->m_array.m_data;
    v6 = v5[v4]->m_PriorityHashPriority.m_timestamp;
    v7 = data->m_PriorityHashPriority.m_timestamp;
    if ( v7 == v6 )
      break;
    v8 = v7 - v6;
    v9 = 1;
    if ( v7 < v6 )
    {
      v8 = v6 - v7;
      v9 = -1;
    }
    if ( (unsigned int)v8 > 0x7FFFFFFF )
      v9 = -v9;
    if ( v9 >= 0 )
      break;
    v5[v3] = v5[v4];
    j->m_array.m_data[v3]->m_PriorityHashArrayIndex = v3;
    v3 = v4;
  }
  j->m_array.m_data[v3] = data;
  data->m_PriorityHashArrayIndex = v3;
}

//----- (00686E80) --------------------------------------------------------  // acclient.c:670696
void __thiscall IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_down(IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, unsigned int i, PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *data)
{
  IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v3; // ebp@1
  int v4; // edi@1
  int v5; // edx@2
  int v6; // ecx@2
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v7; // ebx@3
  unsigned int v8; // edx@3
  unsigned int v9; // eax@3
  int v10; // edx@3
  int v11; // esi@4
  int v12; // ebp@4
  unsigned int v13; // eax@9
  int v14; // edx@9
  int v15; // esi@10
  int v16; // ebp@10
  bool v17; // sf@14
  unsigned int v18; // eax@18
  unsigned int v19; // edx@18
  int v20; // edx@18
  int v21; // esi@19
  int v22; // ebx@19
  IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v23; // [sp+10h] [bp-8h]@1
  unsigned int ia; // [sp+1Ch] [bp+4h]@3
  unsigned int ib; // [sp+1Ch] [bp+4h]@18

  v3 = this;
  v4 = i;
  v23 = this;
  while ( 1 )
  {
    while ( 1 )
    {
      v5 = 2 * v4 + 2;
      v6 = 2 * v4 + 1;
      if ( v5 >= v3->m_hashTable.m_numElements )
        goto LABEL_17;
      v7 = v3->m_array.m_data;
      v8 = (unsigned int)&v7[v5]->m_hashKey.m_dwKey;
      v9 = v7[v6]->m_PriorityHashPriority.m_timestamp;
      ia = v8;
      v10 = *(_DWORD *)(v8 + 8);
      if ( v10 == v9 )
        goto LABEL_17;
      v11 = v10 - v9;
      v12 = 1;
      if ( v10 < v9 )
      {
        v11 = v9 - v10;
        v12 = -1;
      }
      if ( (unsigned int)v11 > 0x7FFFFFFF )
        v12 = -v12;
      if ( v12 < 0 )
        break;
      v3 = v23;
LABEL_17:
      if ( v6 >= v3->m_hashTable.m_numElements )
        goto LABEL_26;
      v18 = data->m_PriorityHashPriority.m_timestamp;
      v19 = (unsigned int)&v3->m_array.m_data[v6]->m_hashKey.m_dwKey;
      ib = v19;
      v20 = *(_DWORD *)(v19 + 8);
      if ( v20 == v18 )
        goto LABEL_26;
      v21 = v20 - v18;
      v22 = 1;
      if ( v20 < v18 )
      {
        v21 = v18 - v20;
        v22 = -1;
      }
      if ( (unsigned int)v21 > 0x7FFFFFFF )
        v22 = -v22;
      if ( v22 >= 0 )
        goto LABEL_26;
      v3->m_array.m_data[v4] = (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *)ib;
      v3->m_array.m_data[v4]->m_PriorityHashArrayIndex = v4;
      v4 = 2 * v4 + 1;
    }
    v13 = data->m_PriorityHashPriority.m_timestamp;
    v14 = *(_DWORD *)(ia + 8);
    if ( v14 == v13 )
      break;
    v15 = v14 - v13;
    v16 = 1;
    if ( v14 < v13 )
    {
      v15 = v13 - v14;
      v16 = -1;
    }
    if ( (unsigned int)v15 > 0x7FFFFFFF )
      v16 = -v16;
    v17 = v16 < 0;
    v3 = v23;
    if ( !v17 )
      goto LABEL_26;
    v7[v4] = (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *)ia;
    v23->m_array.m_data[v4]->m_PriorityHashArrayIndex = v4;
    v4 = 2 * v4 + 2;
  }
  v3 = v23;
LABEL_26:
  v3->m_array.m_data[v4] = data;
  data->m_PriorityHashArrayIndex = v4;
}

//----- (00686FB0) --------------------------------------------------------  // acclient.c:670804
void __thiscall IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_up_or_down(IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, unsigned int i, PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *data)
{
  unsigned int v3; // edx@2
  unsigned int v4; // eax@2
  int v5; // esi@3
  int v6; // edi@3

  if ( !i )
    goto LABEL_12;
  v3 = data->m_PriorityHashPriority.m_timestamp;
  v4 = this->m_array.m_data[(i - 1) >> 1]->m_PriorityHashPriority.m_timestamp;
  if ( v3 == v4 )
    goto LABEL_12;
  v5 = v3 - v4;
  v6 = 1;
  if ( v3 < v4 )
  {
    v5 = v4 - v3;
    v6 = -1;
  }
  if ( (unsigned int)v5 > 0x7FFFFFFF )
    v6 = -v6;
  if ( v6 < 0 )
    IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_up(
      this,
      i,
      data);
  else
LABEL_12:
    IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_down(
      this,
      i,
      data);
}

//----- (00687020) --------------------------------------------------------  // acclient.c:670840
void __thiscall CInputManager_WIN32::AddDevicePointer(CInputManager_WIN32 *this, unsigned int dwDeviceType, _GUID *gInstance, _GUID *gProduct, IDirectInputDevice8A *pDevice)
{
  CInputManager_WIN32 *v5; // esi@1
  unsigned int v6; // edx@1
  int v7; // eax@1
  int v8; // edx@1
  int v9; // eax@1
  unsigned int v10; // edx@1
  int v11; // eax@1
  int v12; // edx@1
  int v13; // eax@1
  CInputManager_WIN32::InputDevice inputDevice; // [sp+4h] [bp-30h]@1

  v5 = this;
  CInputManager_WIN32::InputDevice::InputDevice(&inputDevice);
  v6 = gInstance->Data1;
  inputDevice.pDev = pDevice;
  v7 = *(_DWORD *)&gInstance->Data2;
  inputDevice.guidInstance.Data1 = v6;
  v8 = *(_DWORD *)&gInstance->Data4[0];
  *(_DWORD *)&inputDevice.guidInstance.Data2 = v7;
  v9 = *(_DWORD *)&gInstance->Data4[4];
  *(_DWORD *)&inputDevice.guidInstance.Data4[0] = v8;
  v10 = gProduct->Data1;
  *(_DWORD *)&inputDevice.guidInstance.Data4[4] = v9;
  v11 = *(_DWORD *)&gProduct->Data2;
  inputDevice.guidProduct.Data1 = v10;
  v12 = *(_DWORD *)&gProduct->Data4[0];
  *(_DWORD *)&inputDevice.guidProduct.Data2 = v11;
  v13 = *(_DWORD *)&gProduct->Data4[4];
  *(_DWORD *)&inputDevice.guidProduct.Data4[0] = v12;
  inputDevice.nType = (unsigned __int8)dwDeviceType;
  *(_DWORD *)&inputDevice.guidProduct.Data4[4] = v13;
  inputDevice.bActive = 1;
  CInputManager_WIN32::AddDeviceToInputMap(v5, &inputDevice);
  SmartArray<CInputManager_WIN32::InputDevice,1>::AddToEnd(&v5->m_aDevices, &inputDevice);
}

//----- (006870B0) --------------------------------------------------------  // acclient.c:670879
char __thiscall HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::find(HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0> *this, ControlSpecification *_key, CInputManager_WIN32::RecentControlState *_retval)
{
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *v3; // eax@1
  char result; // al@4

  v3 = this->m_intrusiveTable.m_buckets[_key->m_dwKey % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.m_dwKey != _key->m_dwKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    qmemcpy(_retval, &v3->m_data, 0x18u);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00687100) --------------------------------------------------------  // acclient.c:670907
void __thiscall List<CInputManager::InputMapEntry>::List<CInputManager::InputMapEntry>(List<CInputManager::InputMapEntry> *this, List<CInputManager::InputMapEntry> *from)
{
  List<CInputManager::InputMapEntry> *v2; // edi@1
  ListNode<CInputManager::InputMapEntry> *i; // esi@2

  v2 = this;
  this->vfptr = (List<CInputManager::InputMapEntry>Vtbl *)&List<CInputManager::InputMapEntry>::vftable;
  this->_head = 0;
  this->_tail = 0;
  this->_num_elements = 0;
  if ( this != from )
  {
    List<CInputManager::InputMapEntry>::flush((List<QualifiedControl> *)this);
    for ( i = from->_head; i; i = i->next )
    {
      List<CInputManager::InputMapEntry>::push_back(v2, &i->data);
      if ( !i )
        break;
    }
  }
}
// 79831C: using guessed type int (__thiscall *List<CInputManager::InputMapEntry>::vftable)(void *, char);

//----- (00687150) --------------------------------------------------------  // acclient.c:670931
char __thiscall PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::lookup(PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1> *this, ControlSpecification i_key, CInputManager_WIN32::ButtonHistoryEntry *o_pri)
{
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v3; // eax@1
  char result; // al@4
  int v5; // esi@6
  unsigned int v6; // edx@6
  int v7; // eax@6

  v3 = this->m_cIntrusivePriorityHash.m_hashTable.m_buckets[i_key.m_dwKey
                                                          % this->m_cIntrusivePriorityHash.m_hashTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.m_dwKey != i_key.m_dwKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    v5 = v3->m_PriorityHashPriority.ptMousePos.x;
    v6 = v3->m_PriorityHashPriority.m_timestamp;
    v7 = v3->m_PriorityHashPriority.ptMousePos.y;
    o_pri->ptMousePos.x = v5;
    o_pri->ptMousePos.y = v7;
    o_pri->m_timestamp = v6;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (006871A0) --------------------------------------------------------  // acclient.c:670968
char __thiscall IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::grow(IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (006871F0) --------------------------------------------------------  // acclient.c:670988
HRESULT __thiscall CInputManager_WIN32::AddDevice(CInputManager_WIN32 *this, unsigned int dwDeviceType, _GUID *gInstance, _GUID *gProduct)
{
  CInputManager_WIN32 *v4; // ebp@1
  unsigned int v5; // edx@1
  char *v6; // eax@2
  IDirectInput8A *v7; // eax@5
  HRESULT result; // eax@5
  int v9; // eax@6
  int v10; // edi@6
  bool v11; // sf@6
  IDirectInputDevice8A *v12; // eax@6
  int v13; // edi@7
  int v14; // eax@11
  int v15; // eax@17
  IDirectInputDevice8A *pDevice; // [sp+54h] [bp-30h]@5
  DIPROPDWORD dipdw; // [sp+58h] [bp-2Ch]@7
  DIPROPRANGE diprng; // [sp+6Ch] [bp-18h]@9

  v4 = this;
  v5 = 0;
  if ( this->m_aDevices.m_num )
  {
    v6 = (char *)&this->m_aDevices.m_data->guidInstance;
    while ( memcmp(v6, gInstance, 0x10u) )
    {
      ++v5;
      v6 += 48;
      if ( v5 >= v4->m_aDevices.m_num )
        goto LABEL_5;
    }
    return 0;
  }
LABEL_5:
  v7 = v4->m_pDI;
  pDevice = 0;
  result = ((int (__stdcall *)(IDirectInput8A *, _GUID *, IDirectInputDevice8A **, _DWORD))v7->vfptr[1].QueryInterface)(
             v7,
             gInstance,
             &pDevice,
             0);
  if ( result < 0 )
    return result;
  v9 = ((int (__stdcall *)(IDirectInputDevice8A *, HWND__ *, signed int))pDevice->vfptr[4].AddRef)(
         pDevice,
         v4->m_hwnd,
         22);
  v10 = v9;
  v11 = v9 < 0;
  v12 = pDevice;
  if ( v11 )
    goto LABEL_14;
  dipdw.diph.dwSize = 20;
  dipdw.diph.dwHeaderSize = 16;
  dipdw.diph.dwObj = 0;
  dipdw.diph.dwHow = 0;
  dipdw.dwData = 128;
  v13 = pDevice->vfptr[2].QueryInterface((IUnknown *)pDevice, (_GUID *)1, (void **)&dipdw);
  if ( v13 < 0 )
  {
    pDevice->vfptr->Release((IUnknown *)pDevice);
    return v13;
  }
  diprng.diph.dwSize = 24;
  diprng.diph.dwHeaderSize = 16;
  diprng.diph.dwObj = 0;
  diprng.diph.dwHow = 0;
  diprng.lMin = -16;
  diprng.lMax = 16;
  pDevice->vfptr[2].QueryInterface((IUnknown *)pDevice, (_GUID *)4, (void **)&diprng);
  if ( (unsigned __int8)dwDeviceType == 18 )
  {
    dipdw.dwData = 1;
    v15 = pDevice->vfptr[2].QueryInterface((IUnknown *)pDevice, (_GUID *)2, (void **)&dipdw);
    v10 = v15;
    v11 = v15 < 0;
    v12 = pDevice;
    if ( v11 )
      goto LABEL_14;
    v10 = ((int (__stdcall *)(IDirectInputDevice8A *, _UNKNOWN *))pDevice->vfptr[3].Release)(pDevice, &c_dfDIMouse2);
    if ( v10 < 0 )
      goto LABEL_13;
    v4->m_nMouseDevice = v4->m_aDevices.m_num;
    goto LABEL_20;
  }
  if ( (unsigned __int8)dwDeviceType == 19 )
  {
    v10 = ((int (__stdcall *)(IDirectInputDevice8A *, const DIDATAFORMAT *))pDevice->vfptr[3].Release)(
            pDevice,
            &c_dfDIKeyboard);
    if ( v10 < 0 )
      goto LABEL_13;
    v4->m_nKeyboardDevice = v4->m_aDevices.m_num;
    goto LABEL_20;
  }
  dipdw.dwData = 0;
  pDevice->vfptr[2].QueryInterface((IUnknown *)pDevice, (_GUID *)2, (void **)&dipdw);
  dipdw.dwData = 1500;
  v14 = pDevice->vfptr[2].QueryInterface((IUnknown *)pDevice, (_GUID *)5, (void **)&dipdw);
  v10 = v14;
  v11 = v14 < 0;
  v12 = pDevice;
  if ( v11 )
  {
LABEL_14:
    v12->vfptr->Release((IUnknown *)v12);
    return v10;
  }
  v10 = ((int (__stdcall *)(IDirectInputDevice8A *, const DIDATAFORMAT *))pDevice->vfptr[3].Release)(
          pDevice,
          &c_dfDIJoystick2);
  if ( v10 < 0 )
  {
LABEL_13:
    v12 = pDevice;
    goto LABEL_14;
  }
LABEL_20:
  CInputManager_WIN32::AddDevicePointer(v4, dwDeviceType, gInstance, gProduct, pDevice);
  return 0;
}

//----- (006873F0) --------------------------------------------------------  // acclient.c:671110
int __stdcall CInputManager_WIN32::EnumSuitableDevicesCB(DIDEVICEINSTANCEA *pDIDI, void *pContext)
{
  unsigned __int8 v2; // al@1

  v2 = LOBYTE(pDIDI->dwDevType);
  if ( v2 < 0x12u || v2 > 0x13u )
    CInputManager_WIN32::AddDevice(
      (CInputManager_WIN32 *)pContext,
      pDIDI->dwDevType,
      &pDIDI->guidInstance,
      &pDIDI->guidProduct);
  return 1;
}

//----- (00687420) --------------------------------------------------------  // acclient.c:671125
char __thiscall CInputManager_WIN32::GetPreviousControlState(CInputManager_WIN32 *this, ControlSpecification i_key, ControlType i_ct, CInputManager_WIN32::RecentControlState *o_rcsPreviousState)
{
  CInputManager_WIN32::RecentControlState *v4; // esi@1
  CInputManager_WIN32 *v5; // edi@1
  ControlType v6; // eax@2
  bool v7; // zf@2
  char result; // al@3

  v4 = o_rcsPreviousState;
  v5 = this;
  if ( HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::find(
         &this->m_hashActiveControls,
         &i_key,
         o_rcsPreviousState) )
  {
    result = 1;
  }
  else
  {
    v6 = i_ct;
    v7 = i_ct == 4;
    v4->type = i_ct;
    v4->mode = v5->m_metaKeyMode;
    if ( v7 )
    {
      v4->dwData = -1;
      v4->activation = 128;
      result = 0;
    }
    else
    {
      v4->activation = v6 != 1 ? 128 : 2;
      v4->dwData = 0;
      result = 0;
    }
  }
  return result;
}

//----- (00687490) --------------------------------------------------------  // acclient.c:671165
void __thiscall IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>(IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0>Vtbl *)IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<ControlSpecification,enum ControlType> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<ControlSpecification,enum ControlType> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FEF48: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable[3])(void *, char);

//----- (00687520) --------------------------------------------------------  // acclient.c:671198
void __thiscall IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>(IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>Vtbl *)IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FEF4C: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable[2])(void *, char);

//----- (006875B0) --------------------------------------------------------  // acclient.c:671231
void __thiscall IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>(IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>Vtbl *)&IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FEF50: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vftable)(void *, char);

//----- (00687640) --------------------------------------------------------  // acclient.c:671264
char __thiscall IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::resize_internal(IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v3; // esi@1
  char result; // al@2
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v5; // edi@3
  int v6; // ecx@4
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v7; // eax@5
  int v8; // eax@6
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v9; // ebx@7
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v10; // ecx@7
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v11; // eax@9
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v12; // edx@10
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v17; // eax@23
  int v18; // eax@23

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
        if ( v3->m_firstInterestingBucket == (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)v6 )
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
            v3->m_firstInterestingBucket = (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)v8;
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
    if ( (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey.m_dwKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00687780) --------------------------------------------------------  // acclient.c:671382
bool __thiscall CInputManager_WIN32::EnumSuitableDevices(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  bool result; // al@2

  v1 = this;
  if ( this->m_pDI )
  {
    CInputManager_WIN32::AddDevice(this, 0x13u, &GUID_SysKeyboard, &GUID_SysKeyboard);
    CInputManager_WIN32::AddDevice(v1, 0x12u, &GUID_SysMouse, &GUID_SysMouse);
    v1->m_nVirtualDevice = v1->m_aDevices.m_num;
    CInputManager_WIN32::AddDevicePointer(v1, 0x1Cu, &GUID_Virtual, &GUID_Virtual, 0);
    result = ((int (__stdcall *)(IDirectInput8A *, _DWORD, int (__stdcall *)(DIDEVICEINSTANCEA *, void *), CInputManager_WIN32 *, _DWORD))v1->m_pDI->vfptr[1].AddRef)(
               v1->m_pDI,
               0,
               CInputManager_WIN32::EnumSuitableDevicesCB,
               v1,
               0) >= 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00687800) --------------------------------------------------------  // acclient.c:671409
PStringBase<char> *__thiscall CInputManager_WIN32::GetNameFromKey_Internal(CInputManager_WIN32 *this, PStringBase<char> *result, ControlSpecification key, unsigned int i_eKeyOverrideTable)
{
  CInputManager_WIN32 *v4; // edi@1
  unsigned int v5; // eax@1
  unsigned int v6; // esi@1
  char *v7; // edx@2
  PSRefBufferCharData<char> *v8; // ebx@6
  unsigned int v9; // eax@6
  unsigned int v10; // ebx@8
  PStringBase<unsigned short> *v11; // eax@9
  char *v12; // esi@9
  unsigned int v13; // esi@12
  CInputManager_WIN32::InputDevice *v14; // ecx@15
  int v15; // edx@15
  SubControlIndex v16; // esi@21
  PStringBase<char> v17; // ST0C_4@22
  PStringBase<unsigned short> *v18; // eax@23
  char *v19; // esi@23
  unsigned int v20; // esi@26
  PSRefBufferCharData<char> *v21; // eax@30
  char *v22; // esi@30
  char *v23; // esi@33
  PStringBase<char> *v24; // eax@36
  PStringBase<char> strName; // [sp+10h] [bp-300h]@6
  unsigned int modkey; // [sp+14h] [bp-2FCh]@1
  PStringBase<char> v27; // [sp+18h] [bp-2F8h]@9
  PStringBase<char> strDIKName; // [sp+1Ch] [bp-2F4h]@6
  StringInfo siKeyName; // [sp+20h] [bp-2F0h]@22
  StringInfo siKey; // [sp+B0h] [bp-260h]@8
  StringInfo siSubControl; // [sp+140h] [bp-1D0h]@21
  DIDEVICEOBJECTINSTANCEA didoi; // [sp+1D0h] [bp-140h]@16

  v4 = this;
  modkey = key.m_dwKey >> 16;
  v5 = this->m_aDevices.m_num;
  v6 = 0;
  if ( v5 )
  {
    v7 = (char *)&this->m_aDevices.m_data->iDeviceIndex;
    do
    {
      if ( *(_DWORD *)v7 == (unsigned __int8)key.m_dwKey )
        break;
      ++v6;
      v7 += 48;
    }
    while ( v6 < v5 );
  }
  if ( v6 >= v5 )
  {
    PStringBase<char>::PStringBase<char>(result, &name);
    v24 = result;
  }
  else
  {
    strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    ControlSpecification::GetDIKName(&key, &strDIKName);
    v8 = strDIKName.m_charbuffer;
    v9 = *(_DWORD *)&strDIKName.m_charbuffer[-1].m_data[8];
    if ( v9 == -1 )
    {
      v9 = compute_str_hash(strDIKName.m_charbuffer->m_data);
      *(_DWORD *)&v8[-1].m_data[8] = v9;
    }
    v10 = v9;
    StringInfo::StringInfo(&siKey);
    StringInfo::SetStringIDandTableEnum(&siKey, v10, i_eKeyOverrideTable);
    if ( StringInfo::IsValid(&siKey, 1) )
    {
      v11 = StringInfo::GetString(&siKey, (PStringBase<unsigned short> *)&modkey, 0);
      PStringBase<unsigned short>::to_spstring(v11, &v27, 0);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&strName, (const unsigned __int16 *)&v27);
      v12 = &v27.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v27.m_charbuffer[-1]) && v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
      v13 = modkey - 20;
      if ( !InterlockedDecrement((volatile LONG *)(modkey - 20 + 4)) && v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    }
    else
    {
      v14 = v4->m_aDevices.m_data;
      v15 = (int)&v14[v6];
      if ( *(_DWORD *)v15 )
      {
        memset(&didoi, 0, sizeof(didoi));
        didoi.dwSize = 316;
        if ( (*(int (__stdcall **)(_DWORD, DIDEVICEOBJECTINSTANCEA *, unsigned int, signed int))(**(_DWORD **)v15 + 56))(
               *(_DWORD *)v15,
               &didoi,
               modkey,
               1) >= 0 )
          PStringBase<char>::set(&strName, didoi.tszName);
      }
      else if ( (unsigned __int8)key.m_dwKey == v14[v4->m_nVirtualDevice].iDeviceIndex
             && (key.m_dwKey & 0xFFFF0000) == 0x10000 )
      {
        PStringBase<char>::set(&strName, "Mouse-Look");
      }
    }
    v16 = BYTE1(key.m_dwKey);
    StringInfo::StringInfo(&siSubControl);
    if ( SubControlIndexToStringInfo(v16, &siSubControl) )
    {
      StringInfo::StringInfo(&siKeyName);
      StringInfo::SetStringIDandTableEnum(&siKeyName, ID_KeyNameWithSubControl, 3);
      v17.m_charbuffer = strName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&strName.m_charbuffer[-1]);
      StringInfo::AddVariable_String(&siKeyName, KEY_0, v17);
      StringInfo::AddVariable_StringInfo(&siKeyName, SUBCONTROL, &siSubControl);
      if ( StringInfo::IsValid(&siKeyName, 1) )
      {
        v18 = StringInfo::GetString(&siKeyName, (PStringBase<unsigned short> *)&modkey, 0);
        PStringBase<unsigned short>::to_spstring(v18, &v27, 0);
        PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&strName, (const unsigned __int16 *)&v27);
        v19 = &v27.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v27.m_charbuffer[-1]) && v19 )
          (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
        v20 = modkey - 20;
        if ( !InterlockedDecrement((volatile LONG *)(modkey - 20 + 4)) && v20 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
      }
      StringInfo::~StringInfo(&siKeyName);
    }
    v21 = strName.m_charbuffer;
    result->m_charbuffer = strName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v21[-1]);
    StringInfo::~StringInfo(&siSubControl);
    StringInfo::~StringInfo(&siKey);
    v22 = &strDIKName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strDIKName.m_charbuffer[-1]) && v22 )
      (**(void (__thiscall ***)(char *, signed int))v22)(v22, 1);
    v23 = &strName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1]) )
    {
      if ( v23 )
        (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
    }
    v24 = result;
  }
  return v24;
}

//----- (00687B50) --------------------------------------------------------  // acclient.c:671554
bool __thiscall CInputManager_WIN32::UnbindByKey(CInputManager_WIN32 *this, QualifiedControl i_key, unsigned int i_idMap)
{
  HashList<unsigned long,CInputMap *,1>::HashListData *v3; // eax@1
  bool result; // al@4
  CInputMap *v5; // eax@6
  _BYTE v6[12]; // ST00_12@7

  v3 = this->m_InputMap.m_hashSections.m_ihlIntrusive.m_hash.m_buckets[i_idMap
                                                                     % this->m_InputMap.m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != i_idMap )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 && (v5 = v3->m_data) != 0 )
  {
    *(_DWORD *)v6 = i_key.m_key.m_dwKey;
    *(_QWORD *)&v6[4] = *(_QWORD *)&i_key.m_metamode;
    result = CInputMap::UnbindByKey(v5, *(QualifiedControl *)v6);
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00687BB0) --------------------------------------------------------  // acclient.c:671586
char __thiscall CInputManager_WIN32::FindKeysForAction(CInputManager_WIN32 *this, unsigned int i_id, unsigned int i_idMap, List<QualifiedControl> *o_list)
{
  CInputMap *v4; // eax@2
  char result; // al@3

  if ( i_idMap && (v4 = CMasterInputMap::GetInputMapByID(&this->m_InputMap, i_idMap)) != 0 )
    result = CInputMap::FindKeysForAction(v4, i_id, o_list);
  else
    result = 0;
  return result;
}

//----- (00687BF0) --------------------------------------------------------  // acclient.c:671599
bool __thiscall CInputManager_WIN32::FindConflictingControls(CInputManager_WIN32 *this, QualifiedControl *i_key, unsigned int i_eMapID, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *o_controls)
{
  CInputManager_WIN32 *v4; // esi@1
  CInputMap *v5; // eax@2
  bool result; // al@3

  v4 = this;
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1>::SetNElements(o_controls, 0, 1);
  if ( i_eMapID && (v5 = CMasterInputMap::GetInputMapByID(&v4->m_InputMap, i_eMapID)) != 0 )
    result = CInputMap::FindConflictingControls(v5, i_key, o_controls);
  else
    result = 0;
  return result;
}

//----- (00687C40) --------------------------------------------------------  // acclient.c:671615
char __thiscall CInputManager_WIN32::UnbindAllByAction(CInputManager_WIN32 *this, unsigned int i_id, unsigned int i_eMapID)
{
  HashList<unsigned long,CInputMap *,1>::HashListData *v3; // eax@1
  char result; // al@4
  CInputMap *v5; // eax@6

  v3 = this->m_InputMap.m_hashSections.m_ihlIntrusive.m_hash.m_buckets[i_eMapID
                                                                     % this->m_InputMap.m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != i_eMapID )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 && (v5 = v3->m_data) != 0 )
    result = CInputMap::UnbindAllByAction(v5, i_id);
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (00687CF0) --------------------------------------------------------  // acclient.c:671679
char __thiscall IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::add(IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *data)
{
  IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v4; // eax@1
  unsigned int v5; // edx@6
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.m_dwKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_dwKey != data->m_hashKey.m_dwKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::grow(this);
    v5 = data->m_hashKey.m_dwKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00687D70) --------------------------------------------------------  // acclient.c:671723
bool __thiscall CInputManager_WIN32::OnStartup(CInputManager_WIN32 *this, int dwUserData)
{
  CInputManager_WIN32 *v2; // esi@1
  HMODULE v3; // eax@2
  PSRefBufferCharData<unsigned short> *v4; // ecx@2
  PlatformString::DisplayStringMode v5; // ecx@3
  PSRefBufferCharData<unsigned short> *v6; // ecx@3
  bool result; // al@3
  FARPROC v8; // eax@4
  PSRefBufferCharData<unsigned short> *v9; // ecx@4
  PSRefBufferCharData<unsigned short> *v10; // ecx@5
  PSRefBufferCharData<unsigned short> *v11; // ecx@5
  HMODULE v12; // eax@6
  PSRefBufferCharData<unsigned short> *v13; // ecx@6
  PSRefBufferCharData<unsigned short> *v14; // ecx@7
  PSRefBufferCharData<unsigned short> *v15; // ecx@7
  PSRefBufferCharData<unsigned short> *v16; // ecx@10
  PSRefBufferCharData<unsigned short> *v17; // ecx@12
  PSRefBufferCharData<unsigned short> *v18; // ecx@12
  ICIDMVtbl *v19; // edx@12
  PStringBase<unsigned short> v20; // [sp-18h] [bp-20h]@5
  PStringBase<unsigned short> v21; // [sp-14h] [bp-1Ch]@5
  PStringBase<unsigned short> v22; // [sp-10h] [bp-18h]@3
  PlatformString::DisplayStringMode v23; // [sp-Ch] [bp-14h]@3
  PStringBase<unsigned short> v24; // [sp-8h] [bp-10h]@3
  PlatformString::DisplayStringMode v25; // [sp-4h] [bp-Ch]@2

  v2 = this;
  if ( !CInputManager::OnStartup((CInputManager *)&this->vfptr, dwUserData) )
    return 0;
  v25 = (PlatformString::DisplayStringMode)"DINPUT8.DLL";
  v2->m_hwnd = (HWND__ *)dwUserData;
  v3 = LoadLibraryA((LPCSTR)v25);
  v2->m_hDInputDLL = v3;
  if ( !v3 )
  {
    v25 = 0;
    v24.m_charbuffer = v4;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v24, &word_794320);
    v23 = v5;
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&v23, &word_794320);
    v22.m_charbuffer = v6;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v22, L"DINPUT8.DLL");
    PlatformString::DisplayString(0x65u, v22, (PStringBase<unsigned short>)v23, v24, v25);
    (*(void (__thiscall **)(CInputManager_WIN32 *))&v2->vfptr->gap4[8])(v2);
    return 0;
  }
  v8 = GetProcAddress(v3, "DirectInput8Create");
  v2->m_pfnDirectInputCreate = (HRESULT (__stdcall *)(HINSTANCE__ *, unsigned int, _GUID *, void **, IUnknown *))v8;
  v23 = 0;
  if ( !v8 )
  {
    v22.m_charbuffer = v9;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v22, &word_794320);
    v21.m_charbuffer = v10;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v21, &word_794320);
    v20.m_charbuffer = v11;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, L"DINPUT8.DLL");
    PlatformString::DisplayString(0x66u, v20, v21, v22, v23);
LABEL_8:
    (*(void (__thiscall **)(CInputManager_WIN32 *, PStringBase<unsigned short>, PlatformString::DisplayStringMode))&v2->vfptr->gap4[8])(
      v2,
      v24.m_charbuffer,
      v25);
    return 0;
  }
  v12 = GetModuleHandleA(0);
  if ( v2->m_pfnDirectInputCreate(v12, 2048u, &IID_IDirectInput8A, (void **)&v2->m_pDI, (IUnknown *)v23) < 0 )
  {
    v23 = 0;
    v22.m_charbuffer = v13;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v22, &word_794320);
    v21.m_charbuffer = v14;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v21, &word_794320);
    v20.m_charbuffer = v15;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, &word_794320);
    PlatformString::DisplayString(0x67u, v20, v21, v22, v23);
    goto LABEL_8;
  }
  if ( CInputManager_WIN32::EnumSuitableDevices(v2) )
  {
    CInputManager_WIN32::AcquireAll(v2);
    ((void (__thiscall *)(CInputManager_WIN32 *, _DWORD, PStringBase<unsigned short>, PlatformString::DisplayStringMode))v2->vfptr->SetMouseLookMode)(
      v2,
      0,
      v24.m_charbuffer,
      v25);
    result = ((int (__thiscall *)(CInputManager_WIN32 *, signed int))v2->vfptr->AddKeyMap)(v2, 1);
  }
  else
  {
    v23 = 0;
    v22.m_charbuffer = v16;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v22, &word_794320);
    v21.m_charbuffer = v17;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v21, &word_794320);
    v20.m_charbuffer = v18;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, &word_794320);
    PlatformString::DisplayString(0x68u, v20, v21, v22, v23);
    v19 = v2->vfptr;
    v23 = 1;
    result = ((int (__thiscall *)(CInputManager_WIN32 *, signed int, PStringBase<unsigned short>, PlatformString::DisplayStringMode))v19->AddKeyMap)(
               v2,
               1,
               v24.m_charbuffer,
               v25);
  }
  return result;
}

//----- (00687F00) --------------------------------------------------------  // acclient.c:671834
PStringBase<char> *__thiscall CInputManager_WIN32::GetNameFromKey(CInputManager_WIN32 *this, PStringBase<char> *result, ControlSpecification key)
{
  CInputManager_WIN32::GetNameFromKey_Internal(this, result, key, 4u);
  return result;
}

//----- (00687F20) --------------------------------------------------------  // acclient.c:671841
PStringBase<char> *__thiscall CInputManager_WIN32::GetNameFromMetaKey(CInputManager_WIN32 *this, PStringBase<char> *result, ControlSpecification key)
{
  CInputManager_WIN32::GetNameFromKey_Internal(this, result, key, 5u);
  return result;
}

//----- (00687F40) --------------------------------------------------------  // acclient.c:671848
PStringBase<char> *__thiscall CInputManager_WIN32::GetNameFromKey(CInputManager_WIN32 *this, PStringBase<char> *result, QualifiedControl *key)
{
  CInputManager_WIN32 *v3; // edi@1
  unsigned int v4; // ecx@1
  unsigned int v5; // ebx@2
  char *v6; // esi@6
  PStringBase<char> *v7; // edi@13
  char *v8; // esi@13
  PStringBase<unsigned short> *v9; // eax@16
  unsigned int v10; // esi@16
  ListNode<PStringBase<char> > *v11; // esi@19
  PSRefBufferCharData<char> *v12; // ebx@19
  int v13; // eax@21
  int v14; // ecx@23
  PSRefBufferCharData<char> *v15; // eax@26
  char *v16; // esi@26
  PStringBase<char> strTemp; // [sp+18h] [bp-B0h]@5
  PStringBase<char> strRetval; // [sp+1Ch] [bp-ACh]@19
  PStringBase<char> strKeyName; // [sp+20h] [bp-A8h]@12
  ControlSpecification csTemp; // [sp+24h] [bp-A4h]@4
  List<PStringBase<char> > lKeyStrings; // [sp+28h] [bp-A0h]@1
  StringInfo siDelimiter; // [sp+38h] [bp-90h]@16

  v3 = this;
  v4 = key->m_metamode;
  lKeyStrings.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  lKeyStrings._head = 0;
  lKeyStrings._tail = 0;
  lKeyStrings._num_elements = 0;
  if ( v4 )
  {
    v5 = 1;
    do
    {
      if ( v5 & key->m_metamode )
      {
        CMasterInputMap::KeyFromMetaMode(&v3->m_InputMap, &csTemp, v5);
        if ( csTemp.m_dwKey != -1 )
        {
          ((void (__thiscall *)(CInputManager_WIN32 *, PStringBase<char> *, unsigned int))v3->vfptr->GetNameFromMetaKey)(
            v3,
            &strTemp,
            csTemp.m_dwKey);
          if ( *(_DWORD *)&strTemp.m_charbuffer[-1].m_data[12] == 1 )
          {
            v6 = &strTemp.m_charbuffer[-2].m_data[12];
          }
          else
          {
            List<PStringBase<char>>::push_back(&lKeyStrings, &strTemp);
            v6 = &strTemp.m_charbuffer[-2].m_data[12];
          }
          if ( !InterlockedDecrement((volatile LONG *)v6 + 1) && v6 )
            (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
        }
      }
      v5 *= 2;
    }
    while ( v5 );
  }
  v3->vfptr->GetNameFromKey((ICIDM *)v3, &strKeyName, (QualifiedControl *)key->m_key.m_dwKey);
  if ( *(_DWORD *)&strKeyName.m_charbuffer[-1].m_data[12] == 1 )
  {
    v7 = result;
    PStringBase<char>::PStringBase<char>(result, &name);
    v8 = &strKeyName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strKeyName.m_charbuffer[-1]) && v8 )
    {
LABEL_34:
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      goto LABEL_35;
    }
  }
  else
  {
    List<PStringBase<char>>::push_back(&lKeyStrings, &strKeyName);
    StringInfo::StringInfo(&siDelimiter);
    StringInfo::SetStringIDandTableEnum(&siDelimiter, ID_KeyDescDelimiter, 3);
    v9 = StringInfo::GetString(&siDelimiter, (PStringBase<unsigned short> *)&csTemp, 0);
    PStringBase<unsigned short>::to_spstring(v9, &strTemp, 0);
    v10 = csTemp.m_dwKey - 20;
    if ( !InterlockedDecrement((volatile LONG *)(csTemp.m_dwKey - 20 + 4)) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    strRetval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v11 = lKeyStrings._head;
    v12 = strTemp.m_charbuffer;
    if ( lKeyStrings._head )
    {
      do
      {
        if ( *(_DWORD *)&strRetval.m_charbuffer[-1].m_data[12] != 1 )
        {
          v13 = *(_DWORD *)&v12[-1].m_data[12];
          if ( v13 != 1 )
            PStringBase<char>::append_n_chars(&strRetval, v12->m_data, v13 - 1);
        }
        v14 = *(_DWORD *)&v11->data.m_charbuffer[-1].m_data[12];
        if ( v14 != 1 )
          PStringBase<char>::append_n_chars(&strRetval, v11->data.m_charbuffer->m_data, v14 - 1);
        v11 = v11->next;
      }
      while ( v11 );
    }
    v15 = strRetval.m_charbuffer;
    v7 = result;
    result->m_charbuffer = strRetval.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v15[-1]);
    v16 = &strRetval.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strRetval.m_charbuffer[-1]) && v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v12[-1]) && v12 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v12[-2].m_data[12])(&v12[-2].m_data[12], 1);
    StringInfo::~StringInfo(&siDelimiter);
    v8 = &strKeyName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strKeyName.m_charbuffer[-1]) && v8 )
      goto LABEL_34;
  }
LABEL_35:
  lKeyStrings.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  List<PStringBase<char>>::flush(&lKeyStrings);
  return v7;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (006881C0) --------------------------------------------------------  // acclient.c:671974
char __thiscall HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::set(HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0> *this, ControlSpecification *_key, CInputManager_WIN32::RecentControlState *_data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v3; // ebx@1
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *v4; // eax@1
  void *v5; // eax@4
  char result; // al@5

  v3 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable;
  v4 = this->m_intrusiveTable.m_buckets[_key->m_dwKey % this->m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_dwKey != _key->m_dwKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    qmemcpy(&v4->m_data, _data, sizeof(v4->m_data));
    result = 1;
  }
  else
  {
LABEL_4:
    v5 = operator new(0x20u);
    if ( v5 )
    {
      *(_DWORD *)v5 = _key->m_dwKey;
      *((_DWORD *)v5 + 1) = 0;
      qmemcpy((char *)v5 + 8, _data, 0x18u);
      IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
        v3,
        (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v5);
      result = 1;
    }
    else
    {
      IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
        v3,
        0);
      result = 1;
    }
  }
  return result;
}

//----- (00688250) --------------------------------------------------------  // acclient.c:672022
char __thiscall IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::insert(IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *i_pData)
{
  IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v2; // edi@1
  char result; // al@1
  unsigned int v4; // ebx@2
  int v5; // eax@2
  unsigned int v6; // eax@3

  v2 = this;
  result = IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::add(
             &this->m_hashTable,
             i_pData);
  if ( result )
  {
    v4 = v2->m_array.m_num;
    i_pData->m_PriorityHashArrayIndex = v4;
    v5 = v2->m_array.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( v2->m_array.m_num < v5
      || (v6 = SmartArray<UIChildFramework *,1>::get_new_size(v5 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v2->m_array, v6)) )
      v2->m_array.m_data[v2->m_array.m_num++] = i_pData;
    IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_up(
      v2,
      v4,
      i_pData);
    result = 1;
  }
  return result;
}

//----- (006882C0) --------------------------------------------------------  // acclient.c:672053
HashSetData<IDClass<_tagDataID,32,0> > *__thiscall IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::remove(IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *this, ControlSpecification key)
{
  IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v2; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // edi@1
  unsigned int v5; // eax@2
  unsigned int v6; // ecx@2
  int v7; // ecx@3

  v2 = this;
  v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)this,
         (IDClass<_tagDataID,32,0> *)&key);
  v4 = v3;
  if ( v3 )
  {
    v5 = (unsigned int)&v3[2].m_hashNext->m_hashKey.id;
    v6 = v2->m_array.m_num;
    if ( v5 < v6 )
    {
      v7 = v6 - 1;
      v2->m_array.m_num = v7;
      if ( v5 != v7 )
      {
        v2->m_array.m_data[v5] = v2->m_array.m_data[v7];
        v2->m_array.m_data[v2->m_array.m_num] = 0;
      }
    }
    if ( v5 < v2->m_hashTable.m_numElements )
      IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_up_or_down(
        v2,
        v5,
        v2->m_array.m_data[v5]);
  }
  return v4;
}

//----- (00688320) --------------------------------------------------------  // acclient.c:672091
void __thiscall CInputManager_WIN32::OnShutdown(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  IDirectInput8A *v2; // eax@1

  v1 = this;
  List<CInputManager::InputMapEntry>::flush((List<QualifiedControl> *)&this->m_inputMapList);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashActiveControls.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashControlToType.m_intrusiveTable);
  CInputManager_WIN32::ReleaseDevices(v1);
  v2 = v1->m_pDI;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v1->m_pDI);
    v1->m_pDI = 0;
  }
}

//----- (00688370) --------------------------------------------------------  // acclient.c:672110
HashTable<ControlSpecification,enum ControlType,0> *__thiscall HashTable<ControlSpecification,enum  ControlType,0>::vector_deleting_destructor(HashTable<ControlSpecification,enum ControlType,0> *this, unsigned int a2)
{
  HashTable<ControlSpecification,enum ControlType,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<ControlSpecification,enum ControlType,0>Vtbl *)HashTable<ControlSpecification,enum  ControlType,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FEF48: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable[3])(void *, char);
// 7FEF60: using guessed type int (__thiscall *HashTable<ControlSpecification,enum  ControlType,0>::vftable[2])(void *, char);

//----- (006883D0) --------------------------------------------------------  // acclient.c:672136
HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0> *__thiscall HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vector_deleting_destructor(HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0> *this, unsigned int a2)
{
  HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>Vtbl *)&HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FEF4C: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable[2])(void *, char);
// 7FEF64: using guessed type int (__thiscall *HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vftable)(void *, char);

//----- (00688430) --------------------------------------------------------  // acclient.c:672162
void __thiscall PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::~PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>(PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1> *this)
{
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1> *v1; // esi@1
  void *v2; // eax@3

  v1 = this;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)this);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_cIntrusivePriorityHash.m_array);
  if ( (v1->m_cIntrusivePriorityHash.m_array.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_cIntrusivePriorityHash.m_array.m_data);
  v2 = v1->m_cIntrusivePriorityHash.m_hashTable.m_buckets;
  v1->m_cIntrusivePriorityHash.m_hashTable.vfptr = (IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>Vtbl *)&IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vftable;
  if ( v2 != v1->m_cIntrusivePriorityHash.m_hashTable.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_cIntrusivePriorityHash.m_hashTable.m_buckets = 0;
  v1->m_cIntrusivePriorityHash.m_hashTable.m_firstInterestingBucket = 0;
  v1->m_cIntrusivePriorityHash.m_hashTable.m_numBuckets = 0;
  v1->m_cIntrusivePriorityHash.m_hashTable.m_numElements = 0;
}
// 7FEF50: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vftable)(void *, char);

//----- (00688490) --------------------------------------------------------  // acclient.c:672184
void __thiscall PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::insert(PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1> *this, ControlSpecification key, CInputManager_WIN32::ButtonHistoryEntry pri)
{
  IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *v3; // esi@1
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *v4; // eax@1
  void *v5; // eax@4

  v3 = (IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *)this;
  v4 = this->m_cIntrusivePriorityHash.m_hashTable.m_buckets[key.m_dwKey
                                                          % this->m_cIntrusivePriorityHash.m_hashTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.m_dwKey != key.m_dwKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    v4->m_PriorityHashPriority = pri;
    IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_up_or_down(
      &this->m_cIntrusivePriorityHash,
      v4->m_PriorityHashArrayIndex,
      v4);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x18u);
    if ( v5 )
    {
      *(_DWORD *)v5 = key.m_dwKey;
      *((_DWORD *)v5 + 1) = 0;
      *(CInputManager_WIN32::ButtonHistoryEntry *)((char *)v5 + 8) = pri;
      *((_DWORD *)v5 + 5) = 0;
      IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::insert(
        v3,
        (PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *)v5);
    }
    else
    {
      IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::insert(
        v3,
        0);
    }
  }
}

//----- (00688540) --------------------------------------------------------  // acclient.c:672233
void __thiscall CInputManager_WIN32::CInputManager_WIN32(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1

  v1 = this;
  CInputManager::CInputManager((CInputManager *)&this->vfptr);
  v1->vfptr = (ICIDMVtbl *)&CInputManager_WIN32::vftable;
  v1->m_pfnDirectInputCreate = 0;
  v1->m_hDInputDLL = 0;
  v1->m_pDI = 0;
  v1->m_hwnd = 0;
  v1->m_aDevices.m_data = 0;
  v1->m_aDevices.m_sizeAndDeallocate = 0;
  v1->m_aDevices.m_num = 0;
  v1->m_nKeyboardDevice = -1;
  v1->m_nMouseDevice = -1;
  v1->m_nVirtualDevice = -1;
  v1->m_hashControlToType.vfptr = (HashTable<ControlSpecification,enum ControlType,0>Vtbl *)HashTable<ControlSpecification,enum  ControlType,0>::vftable;
  IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>(
    &v1->m_hashControlToType.m_intrusiveTable,
    0x17u);
  v1->m_hashActiveControls.vfptr = (HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>Vtbl *)&HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vftable;
  IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>(
    &v1->m_hashActiveControls.m_intrusiveTable,
    0x17u);
  CMasterInputMap::CMasterInputMap(&v1->m_InputMap);
  v1->m_metaKeyMode = 0;
  IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>(
    &v1->m_ButtonHistory.m_cIntrusivePriorityHash.m_hashTable,
    0x17u);
  v1->m_ButtonHistory.m_cIntrusivePriorityHash.m_array.m_data = 0;
  v1->m_ButtonHistory.m_cIntrusivePriorityHash.m_array.m_sizeAndDeallocate = 0;
  v1->m_ButtonHistory.m_cIntrusivePriorityHash.m_array.m_num = 0;
  v1->m_eMouseLookBehavior = 1;
  v1->m_fMainWindowHasFocus = 1;
  v1->m_cSetCapture = 0;
  v1->m_bProcessingKeyDown = 0;
  v1->m_bProcessingActionInResponseToKeyDown = 0;
  v1->m_bIgnoreNextChar = 0;
  v1->m_ptNonMousePointerMovement.x = 0;
  v1->m_ptNonMousePointerMovement.y = 0;
  CoInitialize(0);
}
// 7FEF60: using guessed type int (__thiscall *HashTable<ControlSpecification,enum  ControlType,0>::vftable[2])(void *, char);
// 7FEF64: using guessed type int (__thiscall *HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vftable)(void *, char);
// 7FEFA0: using guessed type int (__thiscall *CInputManager_WIN32::vftable)(void *, char);

//----- (00688630) --------------------------------------------------------  // acclient.c:672281
void __thiscall CInputManager_WIN32::ConfigureMouseLookMode(CInputManager_WIN32 *this, MouseLookBehavior i_eBehavior, int i_x, int i_y)
{
  this->m_eMouseLookBehavior = i_eBehavior;
  if ( i_eBehavior == 2 )
  {
    this->m_ptMousePosBeforeMouseLookMode.x = i_x;
    this->m_ptMousePosBeforeMouseLookMode.y = i_y;
  }
}

//----- (00688660) --------------------------------------------------------  // acclient.c:672292
unsigned __int32 CInputManager_WIN32::GetDoubleClickDelay()
{
  return CInputManager_WIN32::sm_timeDoubleClick;
}
// 8F7C68: using guessed type unsigned __int32 CInputManager_WIN32::sm_timeDoubleClick;

//----- (00688670) --------------------------------------------------------  // acclient.c:672299
unsigned __int32 CInputManager_WIN32::GetTapDelay()
{
  return CInputManager_WIN32::sm_timeTap;
}
// 8F7C6C: using guessed type unsigned __int32 CInputManager_WIN32::sm_timeTap;

//----- (00688680) --------------------------------------------------------  // acclient.c:672306
char __thiscall CInputManager_WIN32::SetMouseXY(CInputManager_WIN32 *this, int i_xWindow, int i_yWindow)
{
  HWND__ *v3; // ST00_4@2
  char result; // al@4
  tagPOINT Point; // [sp+0h] [bp-8h]@2

  if ( this->m_fWantMouseLookMode )
  {
    result = 0;
  }
  else
  {
    this->m_ptMousePos.x = i_xWindow;
    Point.x = i_xWindow;
    this->m_ptMousePos.y = i_yWindow;
    v3 = this->m_hwnd;
    Point.y = i_yWindow;
    if ( ClientToScreen(v3, &Point) )
      SetCursorPos(Point.x, Point.y);
    result = 1;
  }
  return result;
}

//----- (006886E0) --------------------------------------------------------  // acclient.c:672331
void __thiscall CInputManager_WIN32::~CInputManager_WIN32(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  IDirectInput8A *v2; // eax@1
  void *v3; // eax@5
  void *v4; // eax@7

  v1 = this;
  this->vfptr = (ICIDMVtbl *)&CInputManager_WIN32::vftable;
  List<CInputManager::InputMapEntry>::flush((List<QualifiedControl> *)&this->m_inputMapList);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashActiveControls.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashControlToType.m_intrusiveTable);
  CInputManager_WIN32::ReleaseDevices(v1);
  v2 = v1->m_pDI;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v1->m_pDI);
    v1->m_pDI = 0;
  }
  if ( v1->m_hDInputDLL )
  {
    FreeLibrary(v1->m_hDInputDLL);
    v1->m_hDInputDLL = 0;
    CoUninitialize();
  }
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::~PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>(&v1->m_ButtonHistory);
  CMasterInputMap::~CMasterInputMap(&v1->m_InputMap);
  v1->m_hashActiveControls.vfptr = (HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>Vtbl *)&HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashActiveControls.m_intrusiveTable);
  v3 = v1->m_hashActiveControls.m_intrusiveTable.m_buckets;
  v1->m_hashActiveControls.m_intrusiveTable.vfptr = (IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>Vtbl *)IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable;
  if ( v3 != v1->m_hashActiveControls.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_hashActiveControls.m_intrusiveTable.m_buckets = 0;
  v1->m_hashActiveControls.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashActiveControls.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashActiveControls.m_intrusiveTable.m_numElements = 0;
  v1->m_hashControlToType.vfptr = (HashTable<ControlSpecification,enum ControlType,0>Vtbl *)HashTable<ControlSpecification,enum  ControlType,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashControlToType.m_intrusiveTable);
  v4 = v1->m_hashControlToType.m_intrusiveTable.m_buckets;
  v1->m_hashControlToType.m_intrusiveTable.vfptr = (IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum ControlType> *,0>Vtbl *)IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable;
  if ( v4 != v1->m_hashControlToType.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_hashControlToType.m_intrusiveTable.m_buckets = 0;
  v1->m_hashControlToType.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashControlToType.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashControlToType.m_intrusiveTable.m_numElements = 0;
  if ( (v1->m_aDevices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_aDevices.m_data);
  CInputManager::~CInputManager((CInputManager *)&v1->vfptr);
}
// 7FEF48: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable[3])(void *, char);
// 7FEF4C: using guessed type int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable[2])(void *, char);
// 7FEF60: using guessed type int (__thiscall *HashTable<ControlSpecification,enum  ControlType,0>::vftable[2])(void *, char);
// 7FEF64: using guessed type int (__thiscall *HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vftable)(void *, char);
// 7FEFA0: using guessed type int (__thiscall *CInputManager_WIN32::vftable)(void *, char);

//----- (00688800) --------------------------------------------------------  // acclient.c:672389
char __thiscall CInputManager_WIN32::FireInputEvent(CInputManager_WIN32 *this, ControlSpecification key, ControlType ct, unsigned int dwData, unsigned int dwTimestamp)
{
  ControlSpecification v5; // ebp@1
  ControlType v6; // edi@1
  CInputManager_WIN32 *v7; // esi@1
  unsigned int v8; // ecx@1
  ControlType v9; // ST08_4@1
  ActionState *i; // eax@2
  signed int v11; // eax@6
  int v12; // ecx@6
  int v13; // edx@6
  unsigned int v14; // ebx@6
  HashSetData<IDClass<_tagDataID,32,0> > *v15; // eax@9
  int v16; // edi@13
  _BYTE v17[12]; // ST04_12@21
  unsigned int v18; // eax@22
  unsigned int v19; // ecx@23
  PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData **v20; // edx@28
  void *v21; // ebp@31
  _BYTE v22[12]; // ST04_12@32
  int v23; // eax@33
  int v24; // eax@34
  HashSetData<IDClass<_tagDataID,32,0> > *v25; // eax@42
  unsigned int v26; // eax@46
  unsigned int v27; // edi@50
  ListNode<CInputManager::InputMapEntry> *v28; // eax@52
  unsigned int v29; // edi@56
  int v30; // ebp@56
  int v31; // ebx@56
  IInputActionCallback *v32; // edx@60
  HashList<unsigned long,CInputMap *,1>::HashListData *v33; // edx@78
  CInputMap *v34; // ecx@83
  bool bStoreKey; // [sp+11h] [bp-CBh]@6
  bool bFirePreviousRelease; // [sp+12h] [bp-CAh]@44
  bool fFoundAMatch; // [sp+13h] [bp-C9h]@51
  unsigned int cat; // [sp+14h] [bp-C8h]@6
  unsigned int idBestMatch; // [sp+18h] [bp-C4h]@50
  float rData; // [sp+1Ch] [bp-C0h]@6
  QualifiedControl keyMatch; // [sp+20h] [bp-BCh]@16
  ActionState *pPreviousActionState; // [sp+2Ch] [bp-B0h]@1
  tagPOINT ptEffectiveMouseLocation; // [sp+30h] [bp-ACh]@6
  CInputManager_WIN32::ButtonHistoryEntry hist; // [sp+38h] [bp-A4h]@13
  unsigned int modeToUse; // [sp+44h] [bp-98h]@6
  List<CInputManager::InputMapEntry> inputMapList; // [sp+48h] [bp-94h]@19
  unsigned int inputMapBestMatch; // [sp+58h] [bp-84h]@50
  tagPOINT pt; // [sp+5Ch] [bp-80h]@70
  QualifiedControl keyInput; // [sp+64h] [bp-78h]@50
  CInputManager_WIN32::RecentControlState rcsCurrent; // [sp+70h] [bp-6Ch]@1
  QualifiedControl keyBestMatch; // [sp+88h] [bp-54h]@50
  InputEvent ie; // [sp+94h] [bp-48h]@60

  v5.m_dwKey = key.m_dwKey;
  v6 = ct;
  v7 = this;
  v8 = Timer::cur_time.Param;
  v9 = ct;
  LODWORD(v7->m_ttLastInputEvent) = Timer::cur_time.Cmd;
  HIDWORD(v7->m_ttLastInputEvent) = v8;
  pPreviousActionState = 0;
  if ( CInputManager_WIN32::GetPreviousControlState(v7, v5, v9, &rcsCurrent) )
  {
    for ( i = v7->m_hashActionStates.m_buckets[rcsCurrent.idActionMatched % v7->m_hashActionStates.m_numBuckets];
          i;
          i = i->m_hashNext )
    {
      if ( i->m_hashKey == rcsCurrent.idActionMatched )
        break;
    }
    pPreviousActionState = i;
  }
  rData = 0.0;
  v11 = CInputManager_WIN32::DIDataToActivationType(v6, dwData, &rData);
  v12 = v7->m_ptMousePos.x;
  v13 = v7->m_ptMousePos.y;
  v14 = v11 | 0x80000000;
  cat = v11 | 0x80000000;
  modeToUse = v7->m_metaKeyMode;
  ptEffectiveMouseLocation.x = v12;
  ptEffectiveMouseLocation.y = v13;
  bStoreKey = 0;
  if ( v6 == 1 )
  {
    if ( v11 & 2 )
    {
      modeToUse = rcsCurrent.mode;
      if ( rcsCurrent.activation & 8 )
      {
        v14 = v11 | 0x80000010;
        cat = v11 | 0x80000010;
        v15 = IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::remove(
                &v7->m_ButtonHistory.m_cIntrusivePriorityHash,
                v5);
        if ( v15 )
          operator delete(v15);
        if ( rcsCurrent.activation & 0x20 )
        {
          v14 |= 0x40u;
          cat = v14;
        }
      }
      v16 = (int)&v7->m_ButtonHistory;
      hist.m_timestamp = 0;
      if ( PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::lookup(
             &v7->m_ButtonHistory,
             v5,
             &hist)
        && dwTimestamp - hist.m_timestamp <= CInputManager_WIN32::sm_timeTap )
      {
        v14 |= 4u;
        cat = v14;
      }
    }
    else
    {
      v16 = (int)&v7->m_ButtonHistory;
      bStoreKey = 1;
      keyMatch.m_key.m_dwKey = 0;
      if ( PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::lookup(
             &v7->m_ButtonHistory,
             v5,
             (CInputManager_WIN32::ButtonHistoryEntry *)&keyMatch) )
      {
        if ( !(rcsCurrent.activation & 0x10)
          && dwTimestamp - keyMatch.m_key.m_dwKey <= CInputManager_WIN32::sm_timeDoubleClick )
        {
          ptEffectiveMouseLocation = *(tagPOINT *)&keyMatch.m_metamode;
          inputMapList._tail = (ListNode<CInputManager::InputMapEntry> *)keyMatch.m_metamode;
          inputMapList.vfptr = (List<CInputManager::InputMapEntry>Vtbl *)keyMatch.m_metamode;
          inputMapList._num_elements = keyMatch.m_activation;
          inputMapList._head = (ListNode<CInputManager::InputMapEntry> *)keyMatch.m_activation;
          v14 |= 8u;
          cat = v14;
          InflateRect((LPRECT)&inputMapList, CInputManager_WIN32::sm_cxDblClick, CInputManager_WIN32::sm_cyDblClick);
          if ( PtInRect((const RECT *)&inputMapList, v7->m_ptMousePos) )
          {
            v14 |= 0x20u;
            cat = v14;
          }
        }
      }
      *(_DWORD *)v17 = dwTimestamp;
      v5.m_dwKey = key.m_dwKey;
      *(_QWORD *)&v17[4] = v7->m_ptMousePos;
      PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::insert(
        &v7->m_ButtonHistory,
        key,
        *(CInputManager_WIN32::ButtonHistoryEntry *)v17);
    }
    v18 = CMasterInputMap::MetaModeFromKey(&v7->m_InputMap, v5);
    if ( v18 )
    {
      v19 = v7->m_metaKeyMode;
      if ( v14 & 1 )
        v7->m_metaKeyMode = v18 | v19;
      else
        v7->m_metaKeyMode = ~v18 & v19;
    }
    while ( *(_DWORD *)(v16 + 108) )
    {
      v20 = *(PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData ***)(v16 + 112);
      if ( !*v20 || dwTimestamp - (*v20)->m_PriorityHashPriority.m_timestamp < 0x1388 || !*(_DWORD *)(v16 + 108) )
        break;
      v21 = *v20;
      IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::find_iterator(
        (IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *)v16,
        (IntrusiveHashIterator<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *)&hist,
        *v20);
      if ( hist.ptMousePos.y )
      {
        *(_QWORD *)v22 = *(_QWORD *)&hist;
        *(_DWORD *)&v22[8] = hist.ptMousePos.y;
        IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
          (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v16,
          *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v22);
      }
      v23 = *(_DWORD *)(v16 + 120);
      if ( v23 )
      {
        v24 = v23 - 1;
        *(_DWORD *)(v16 + 120) = v24;
        if ( v24 )
        {
          **(_DWORD **)(v16 + 112) = *(_DWORD *)(*(_DWORD *)(v16 + 112) + 4 * v24);
          *(_DWORD *)(*(_DWORD *)(v16 + 112) + 4 * *(_DWORD *)(v16 + 120)) = 0;
        }
      }
      if ( *(_DWORD *)(v16 + 108) )
        IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::bubble_down(
          (IntrusivePriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1> *)v16,
          0,
          **(PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData ***)(v16 + 112));
      if ( v21 )
        operator delete(v21);
      v5.m_dwKey = key.m_dwKey;
    }
    if ( !bStoreKey )
    {
      v25 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
              (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&v7->m_hashActiveControls.m_intrusiveTable,
              (IDClass<_tagDataID,32,0> *)&key);
      if ( v25 )
        operator delete(v25);
    }
  }
  else
  {
    bStoreKey = 1;
  }
  bFirePreviousRelease = 0;
  if ( v14 & 2 )
  {
    if ( pPreviousActionState )
    {
      v26 = pPreviousActionState->m_toggle;
      if ( v26 == 1 || v26 == 5 || v26 == 4 )
        bFirePreviousRelease = 1;
    }
  }
  keyInput.m_metamode = modeToUse;
  keyBestMatch.m_metamode = modeToUse;
  v27 = 0;
  idBestMatch = 0;
  inputMapBestMatch = 0;
  keyInput.m_key.m_dwKey = v5.m_dwKey;
  keyInput.m_activation = v14;
  keyBestMatch.m_key.m_dwKey = v5.m_dwKey;
  keyBestMatch.m_activation = v14;
  hist.ptMousePos.x = 0;
  if ( !CInputManager::CallKeyHitHandler((CInputManager *)&v7->vfptr, &keyInput, &idBestMatch) )
  {
    fFoundAMatch = 0;
    List<CInputManager::InputMapEntry>::List<CInputManager::InputMapEntry>(&inputMapList, &v7->m_inputMapList);
LABEL_52:
    while ( 1 )
    {
      v28 = inputMapList._head;
      if ( !inputMapList._head )
        break;
      inputMapList._head = inputMapList._head->next;
      if ( inputMapList._head )
        inputMapList._head->prev = 0;
      else
        inputMapList._tail = 0;
      v29 = v28->data.m_mapID;
      v30 = (int)v28->data.m_pcCallback;
      v31 = v28->data.m_nPriority;
      operator delete(v28);
      --inputMapList._num_elements;
      if ( v29 == 1 )
      {
        if ( (unsigned __int8)key.m_dwKey == v7->m_aDevices.m_data[v7->m_nKeyboardDevice].iDeviceIndex )
          break;
      }
      else
      {
        if ( v29 == 2 )
          break;
        v33 = v7->m_InputMap.m_hashSections.m_ihlIntrusive.m_hash.m_buckets[v29
                                                                          % v7->m_InputMap.m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets];
        if ( v33 )
        {
          while ( v33->m_hashKey != v29 )
          {
            v33 = v33->m_hashNext;
            if ( !v33 )
              goto LABEL_52;
          }
          if ( v33 )
          {
            v34 = v33->m_data;
            if ( v34 )
            {
              keyMatch.m_metamode = 0;
              keyMatch.m_activation = 0;
              keyMatch.m_key.m_dwKey = -1;
              if ( CInputMap::FindBestMatch(v34, &keyInput, (unsigned int *)&pt, &keyMatch) )
              {
                if ( !fFoundAMatch || QualifiedControl::IsBetterMatch(&keyInput, &keyBestMatch, &keyMatch) )
                {
                  idBestMatch = pt.x;
                  inputMapBestMatch = v29;
                  keyBestMatch = keyMatch;
                  fFoundAMatch = 1;
                  hist.m_timestamp = v29;
                  hist.ptMousePos.x = v30;
                  hist.ptMousePos.y = v31;
                }
              }
            }
          }
        }
      }
    }
    inputMapList.vfptr = (List<CInputManager::InputMapEntry>Vtbl *)&List<CInputManager::InputMapEntry>::vftable;
    List<CInputManager::InputMapEntry>::flush((List<QualifiedControl> *)&inputMapList);
    v14 = cat;
    v27 = inputMapBestMatch;
    v5.m_dwKey = key.m_dwKey;
  }
  if ( bFirePreviousRelease )
  {
    InputEvent::InputEvent(&ie);
    ie.m_InputAction = rcsCurrent.idActionMatched;
    ie.m_InputMapID = rcsCurrent.idInputMapMatched;
    ie.m_InputKey.m_activation = rcsCurrent.activation;
    ie.m_InputKey.m_metamode = rcsCurrent.mode;
    ie.m_InputTimestamp = dwTimestamp;
    ie.m_ptMousePos.y = ptEffectiveMouseLocation.y;
    ie.m_ptMousePos.x = ptEffectiveMouseLocation.x;
    v32 = pPreviousActionState->m_pcCallback;
    ie.m_InputKey.m_key.m_dwKey = v5.m_dwKey;
    LODWORD(ie.m_InputExtent) = 0;
    ie.m_pcCallback = v32;
    CInputManager::DeactivateActionKey((CInputManager *)&v7->vfptr, &ie);
  }
  if ( idBestMatch && idBestMatch != 1 )
  {
    if ( idBestMatch == 2 )
    {
      v7->m_ptNonMousePointerMovement.x += dwData;
    }
    else if ( idBestMatch == 3 )
    {
      v7->m_ptNonMousePointerMovement.y += dwData;
    }
    else if ( !KeyStone::IsHelpFocused()
           && (idBestMatch != 7 && idBestMatch != 8 && idBestMatch != 10 && idBestMatch != 11
            || !GetCursorPos(&pt)
            || !ScreenToClient(v7->m_hwnd, &pt)
            || !KeyStone::IsOverKeystoneWindow(pt)) )
    {
      if ( !(keyBestMatch.m_activation & 0xA9) && rData == 0.0 )
        rData = 1.0;
      InputEvent::InputEvent(&ie);
      ie.m_InputAction = idBestMatch;
      ie.m_InputKey = keyInput;
      ie.m_InputExtent = rData;
      ie.m_ptMousePos = ptEffectiveMouseLocation;
      ie.m_InputTimestamp = dwTimestamp;
      ie.m_InputMapID = v27;
      ie.m_pcCallback = (IInputActionCallback *)hist.ptMousePos.x;
      CInputManager::FireActionEvent((CInputManager *)&v7->vfptr, &ie);
    }
  }
  if ( bStoreKey )
  {
    rcsCurrent.type = ct;
    rcsCurrent.mode = modeToUse;
    rcsCurrent.dwData = dwData;
    rcsCurrent.activation = v14;
    rcsCurrent.idActionMatched = idBestMatch;
    rcsCurrent.idInputMapMatched = v27;
    HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::set(
      &v7->m_hashActiveControls,
      &key,
      &rcsCurrent);
  }
  return 1;
}
// 795344: using guessed type float FLOAT_0_0;
// 79831C: using guessed type int (__thiscall *List<CInputManager::InputMapEntry>::vftable)(void *, char);
// 8F7C68: using guessed type unsigned __int32 CInputManager_WIN32::sm_timeDoubleClick;
// 8F7C6C: using guessed type unsigned __int32 CInputManager_WIN32::sm_timeTap;

//----- (00688FC0) --------------------------------------------------------  // acclient.c:672754
CInputManager_WIN32 *__thiscall CInputManager_WIN32::scalar_deleting_destructor(CInputManager_WIN32 *this, unsigned int a2)
{
  CInputManager_WIN32 *v2; // esi@1

  v2 = this;
  CInputManager_WIN32::~CInputManager_WIN32(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00688FE0) --------------------------------------------------------  // acclient.c:672766
char __thiscall CInputManager_WIN32::ProcessDeviceData(CInputManager_WIN32 *this, unsigned int nDevice, DIDEVICEOBJECTDATA *dod)
{
  unsigned int v3; // ebp@1
  CInputManager_WIN32 *v4; // esi@1
  CInputManager_WIN32::InputDevice *v5; // ecx@1
  unsigned int v6; // edi@1
  int v7; // edx@1
  HashTableData<ControlSpecification,enum ControlType> **v8; // eax@1
  HashTableData<ControlSpecification,enum ControlType> *v9; // eax@1
  IDirectInputDevice8A *v10; // ecx@4
  ControlType v11; // ebp@5
  unsigned int v12; // eax@7
  signed int v14; // ebp@15
  unsigned int v15; // edx@15
  signed int v16; // eax@15
  unsigned int v17; // ST0C_4@17
  signed int v18; // eax@22
  int v19; // ebp@23
  ControlType ct; // [sp+10h] [bp-15Ch]@5
  ControlSpecification keyPrevious; // [sp+14h] [bp-158h]@1
  CInputManager_WIN32::RecentControlState previousState; // [sp+18h] [bp-154h]@7
  DIDEVICEOBJECTINSTANCEA doi; // [sp+30h] [bp-13Ch]@4

  v3 = dod->dwOfs;
  v4 = this;
  v5 = &this->m_aDevices.m_data[nDevice];
  v6 = (dod->dwOfs << 16) | v5->iDeviceIndex & 0xFF;
  v7 = ((dod->dwOfs << 16) | (unsigned __int64)(v5->iDeviceIndex & 0xFF))
     % v4->m_hashControlToType.m_intrusiveTable.m_numBuckets;
  v8 = v4->m_hashControlToType.m_intrusiveTable.m_buckets;
  keyPrevious.m_dwKey = (dod->dwOfs << 16) | v5->iDeviceIndex & 0xFF;
  v9 = v8[v7];
  if ( !v9 )
    goto LABEL_4;
  while ( v9->m_hashKey.m_dwKey != v6 )
  {
    v9 = v9->m_hashNext;
    if ( !v9 )
      goto LABEL_4;
  }
  if ( v9 )
  {
    v11 = v9->m_data;
    ct = v9->m_data;
  }
  else
  {
LABEL_4:
    v10 = v5->pDev;
    doi.dwSize = 316;
    if ( ((int (__stdcall *)(IDirectInputDevice8A *, DIDEVICEOBJECTINSTANCEA *, unsigned int, signed int))v10->vfptr[4].Release)(
           v10,
           &doi,
           v3,
           1) < 0 )
      return 0;
    ct = CInputManager_WIN32::DITypeToControlType(doi.dwType);
    HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
      (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v4->m_hashControlToType,
      &keyPrevious.m_dwKey,
      (RenderVertexStreamD3D *const *)&ct);
    v11 = ct;
  }
  if ( v11 == ct_Invalid )
    return 0;
  CInputManager_WIN32::GetPreviousControlState(v4, (ControlSpecification)v6, v11, &previousState);
  v12 = dod->dwData;
  if ( previousState.dwData == v12 )
  {
    if ( v11 != 2 )
      return 0;
  }
  else if ( v11 != 2 )
  {
    if ( (signed int)v11 <= 2 || (signed int)v11 > 4 )
      return CInputManager_WIN32::FireInputEvent(v4, (ControlSpecification)v6, v11, dod->dwData, dod->dwTimeStamp);
    v14 = CInputManager_WIN32::SubControlFromData(v11, v12);
    v16 = CInputManager_WIN32::SubControlFromData(ct, v15);
    if ( v16 != v14 )
    {
      if ( v16 )
      {
        v17 = dod->dwTimeStamp;
        keyPrevious.m_dwKey = v6 ^ (unsigned __int16)((v6 ^ ((_WORD)v16 << 8)) & 0xFF00);
        CInputManager_WIN32::FireInputEvent(v4, keyPrevious, ct_Button, 0, v17);
        CInputManager_WIN32::FireInputEvent(v4, keyPrevious, ct, 0, dod->dwTimeStamp);
      }
      if ( !v14 )
        goto LABEL_24;
      CInputManager_WIN32::FireInputEvent(
        v4,
        (ControlSpecification)(v6 ^ (unsigned __int16)((v6 ^ ((_WORD)v14 << 8)) & 0xFF00)),
        ct_Button,
        0x80u,
        dod->dwTimeStamp);
    }
    if ( v14 )
      CInputManager_WIN32::FireInputEvent(
        v4,
        (ControlSpecification)(v6 ^ (unsigned __int16)((v6 ^ ((_WORD)v14 << 8)) & 0xFF00)),
        ct,
        abs(dod->dwData),
        dod->dwTimeStamp);
LABEL_24:
    v11 = ct;
    return CInputManager_WIN32::FireInputEvent(v4, (ControlSpecification)v6, v11, dod->dwData, dod->dwTimeStamp);
  }
  v18 = CInputManager_WIN32::SubControlFromData(ct_RelAxis, v12);
  if ( v18 )
  {
    v19 = v6 ^ (unsigned __int16)((v6 ^ ((_WORD)v18 << 8)) & 0xFF00);
    CInputManager_WIN32::FireInputEvent(
      v4,
      (ControlSpecification)(v6 ^ (unsigned __int16)((v6 ^ ((_WORD)v18 << 8)) & 0xFF00)),
      ct_Button,
      0x80u,
      dod->dwTimeStamp);
    CInputManager_WIN32::FireInputEvent(v4, (ControlSpecification)v19, ct_Button, 0, dod->dwTimeStamp);
    goto LABEL_24;
  }
  return CInputManager_WIN32::FireInputEvent(v4, (ControlSpecification)v6, v11, dod->dwData, dod->dwTimeStamp);
}

//----- (00689210) --------------------------------------------------------  // acclient.c:672890
void __thiscall CInputManager_WIN32::OnSwitchMouseMode(CInputManager_WIN32 *this, bool fEnterMouseLook)
{
  bool v2; // bl@1
  CInputManager_WIN32 *v3; // esi@1
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@5
  MouseLookBehavior v7; // eax@8
  int v8; // eax@11
  int v9; // ecx@11
  int v10; // eax@15
  int v11; // eax@16
  unsigned int v12; // eax@19
  ControlSpecification v13; // ST00_4@19
  unsigned int fEnterMouseLooka; // [sp+Ch] [bp+4h]@19

  v2 = fEnterMouseLook;
  v3 = this;
  if ( fEnterMouseLook )
  {
    if ( this->m_fClientIsActive )
    {
      if ( this->m_eMouseLookBehavior == 1 )
      {
        v4 = this->m_ptMousePos.x;
        v5 = this->m_ptMousePos.y;
        v3->m_ptMousePosBeforeMouseLookMode.x = v4;
        v3->m_ptMousePosBeforeMouseLookMode.y = v5;
      }
      v6 = v3->m_cSetCapture + 1;
      v3->m_cSetCapture = v6;
      if ( v6 == 1 )
        SetCapture(v3->m_hwnd);
      Device::ShowCursor(0);
    }
  }
  else
  {
    v7 = this->m_eMouseLookBehavior;
    if ( v7 )
    {
      if ( (signed int)v7 > 0 && (signed int)v7 <= 2 )
      {
        v8 = this->m_ptMousePosBeforeMouseLookMode.x;
        v9 = this->m_ptMousePosBeforeMouseLookMode.y;
        v3->m_ptMousePos.x = v8;
        v3->m_ptMousePos.y = v9;
      }
    }
    else
    {
      this->m_ptMousePos.x = RenderDevice::GetDisplayWidth(RenderDevice::render_device) >> 1;
      v3->m_ptMousePos.y = RenderDevice::GetDisplayHeight(RenderDevice::render_device) >> 1;
    }
    if ( v3->m_fClientIsActive )
      CInputManager_WIN32::SyncCursorToMousePos(v3);
    v10 = v3->m_cSetCapture;
    if ( v10 )
    {
      v11 = v10 - 1;
      v3->m_cSetCapture = v11;
      if ( !v11 )
        ReleaseCapture();
    }
    Device::ShowCursor(1);
  }
  CInputManager::OnSwitchMouseMode((CInputManager *)&v3->vfptr, fEnterMouseLook);
  fEnterMouseLooka = v3->m_aDevices.m_data[v3->m_nVirtualDevice].iDeviceIndex;
  v12 = GetTickCount();
  LOWORD(v13.m_dwKey) = (unsigned __int8)fEnterMouseLooka;
  *((_WORD *)&v13.1 + 1) = 1;
  CInputManager_WIN32::FireInputEvent(v3, v13, ct_Button, v2 != 0 ? 0x80 : 0, v12);
}

//----- (00689340) --------------------------------------------------------  // acclient.c:672965
void __thiscall CInputManager_WIN32::GenerateKeyboardEvent(CInputManager_WIN32 *this, tagMSG *i_msg)
{
  int v2; // eax@1
  CInputManager_WIN32 *v3; // esi@1
  signed int v4; // ecx@2
  char v5; // al@2
  int v6; // ecx@6
  int v7; // edi@6
  unsigned int v8; // eax@6
  bool v9; // al@8
  unsigned int v10; // ebp@10
  CInputManager_WIN32::RecentControlState previousState; // [sp+10h] [bp-18h]@13

  v2 = i_msg->lParam;
  v3 = this;
  if ( (i_msg->lParam & 0xC0000000) != 0x40000000 )
  {
    v4 = (unsigned __int8)((unsigned int)v2 >> 16);
    v5 = BYTE3(v2) & 1;
    if ( v4 == 69 )
    {
      v5 = v5 == 0;
    }
    else if ( v4 == 54 )
    {
      v4 = 42;
    }
    v6 = v4 | (v5 != 0 ? 0x80 : 0);
    v7 = (v6 << 16) | v3->m_aDevices.m_data[v3->m_nKeyboardDevice].iDeviceIndex & 0xFF;
    v8 = i_msg->message;
    v9 = v8 == 256 || v8 == 260;
    v10 = v9 != 0 ? 0x80 : 0;
    if ( !v9 && v6 == 183 )
      CInputManager_WIN32::FireInputEvent(v3, (ControlSpecification)v7, ct_Button, 0x80u, i_msg->time);
    CInputManager_WIN32::GetPreviousControlState(v3, (ControlSpecification)v7, ct_Button, &previousState);
    if ( previousState.dwData != v10 )
      CInputManager_WIN32::FireInputEvent(v3, (ControlSpecification)v7, ct_Button, v10, i_msg->time);
  }
}

//----- (00689440) --------------------------------------------------------  // acclient.c:673006
void __thiscall CInputManager_WIN32::GenerateMouseButtonEvent(CInputManager_WIN32 *this, int iButton, bool fUp, unsigned int dwTime)
{
  CInputManager_WIN32 *v4; // edi@1
  int v5; // eax@2
  unsigned int v6; // esi@4
  int v7; // eax@7
  int v8; // eax@8
  CInputManager_WIN32::RecentControlState previousState; // [sp+10h] [bp-18h]@4

  v4 = this;
  if ( !fUp )
  {
    v5 = this->m_cSetCapture + 1;
    this->m_cSetCapture = v5;
    if ( v5 == 1 )
      SetCapture(this->m_hwnd);
  }
  v6 = v4->m_aDevices.m_data[v4->m_nMouseDevice].iDeviceIndex & 0xFF | ((iButton + 12) << 16) & 0xFFFF0000;
  CInputManager_WIN32::GetPreviousControlState(v4, (ControlSpecification)v6, ct_Button, &previousState);
  if ( previousState.dwData != (unsigned __int8)(fUp != 0 ? 0 : 0x80) )
    CInputManager_WIN32::FireInputEvent(v4, (ControlSpecification)v6, ct_Button, fUp != 0 ? 0 : 0x80, dwTime);
  if ( fUp )
  {
    v7 = v4->m_cSetCapture;
    if ( v7 )
    {
      v8 = v7 - 1;
      v4->m_cSetCapture = v8;
      if ( !v8 )
        ReleaseCapture();
    }
  }
}

//----- (00689510) --------------------------------------------------------  // acclient.c:673041
void __thiscall CInputManager_WIN32::GenerateMouseWheelEvent(CInputManager_WIN32 *this, int iDeltaZ, unsigned int dwTime)
{
  CInputManager_WIN32 *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@2
  ControlSpecification v6; // edi@4

  v3 = this;
  v4 = this->m_aDevices.m_data[this->m_nMouseDevice].iDeviceIndex & 0xFF | 0x80000;
  if ( iDeltaZ <= 0 )
    v5 = v4 & 0xFFFF02FF | 0x200;
  else
    v5 = v4 & 0xFFFF01FF | 0x100;
  v6.m_dwKey = v5;
  CInputManager_WIN32::FireInputEvent(this, (ControlSpecification)v5, ct_Button, 0x80u, dwTime);
  CInputManager_WIN32::FireInputEvent(v3, v6, ct_Button, 0, dwTime);
}

//----- (00689590) --------------------------------------------------------  // acclient.c:673060
void __thiscall CInputManager_WIN32::ReleasePressedKeys(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // ebx@1
  int v2; // ecx@2
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **v3; // eax@3
  int v4; // eax@4
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **v5; // ebp@5
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *v6; // eax@5
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *v7; // edx@7
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **v8; // ecx@7
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *v9; // ecx@10
  HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *v10; // edx@11
  unsigned int v11; // eax@15
  unsigned int v12; // edi@17
  ActionState *v13; // esi@17
  int v14; // edx@22
  IInputActionCallback *v15; // eax@22
  CommandInterpreter *v16; // ecx@25
  ControlSpecification v17; // ST00_4@29
  DWORD dwTime; // [sp+10h] [bp-68h]@1
  unsigned int key; // [sp+14h] [bp-64h]@7
  CInputManager_WIN32::RecentControlState state; // [sp+18h] [bp-60h]@7
  InputEvent ie; // [sp+30h] [bp-48h]@22

  v1 = this;
  dwTime = timeGetTime();
  while ( v1->m_hashActiveControls.m_intrusiveTable.m_numElements )
  {
    v2 = (int)&v1->m_hashActiveControls.m_intrusiveTable.m_buckets[v1->m_hashActiveControls.m_intrusiveTable.m_numBuckets];
    if ( v1->m_hashActiveControls.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_hashActiveControls.m_intrusiveTable.m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_hashActiveControls.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_hashActiveControls.m_intrusiveTable.m_firstInterestingBucket;
      v5 = v1->m_hashActiveControls.m_intrusiveTable.m_firstInterestingBucket;
    }
    key = v6->m_hashKey.m_dwKey;
    v7 = v6->m_hashNext;
    qmemcpy(&state, &v6->m_data, sizeof(state));
    v8 = v5;
    if ( !v7 )
    {
      do
        ++v8;
      while ( v8 != &v1->m_hashActiveControls.m_intrusiveTable.m_buckets[v1->m_hashActiveControls.m_intrusiveTable.m_numBuckets]
           && !*v8 );
    }
    v9 = *v5;
    if ( *v5 == v6 )
      goto LABEL_32;
    do
    {
      v10 = v9;
      v9 = v9->m_hashNext;
    }
    while ( v9 != v6 );
    if ( v10 )
      v10->m_hashNext = v9->m_hashNext;
    else
LABEL_32:
      *v5 = v9->m_hashNext;
    --v1->m_hashActiveControls.m_intrusiveTable.m_numElements;
    operator delete(v6);
    v11 = CMasterInputMap::MetaModeFromKey(&v1->m_InputMap, (ControlSpecification)key);
    if ( v11 )
      v1->m_metaKeyMode &= ~v11;
    v12 = state.idActionMatched;
    v13 = v1->m_hashActionStates.m_buckets[state.idActionMatched % v1->m_hashActionStates.m_numBuckets];
    if ( v13 )
    {
      while ( v13->m_hashKey != state.idActionMatched )
      {
        v13 = v13->m_hashNext;
        if ( !v13 )
          goto LABEL_23;
      }
      if ( v13 )
      {
        InputEvent::InputEvent(&ie);
        ie.m_InputKey.m_metamode = state.mode;
        ie.m_ptMousePos.x = v1->m_ptMousePos.x;
        ie.m_InputKey.m_activation = state.activation;
        v14 = v1->m_ptMousePos.y;
        ie.m_InputTimestamp = dwTime;
        v15 = v13->m_pcCallback;
        ie.m_InputAction = v12;
        ie.m_InputKey.m_key.m_dwKey = key;
        LODWORD(ie.m_InputExtent) = 0;
        ie.m_ptMousePos.y = v14;
        ie.m_pcCallback = v15;
        CInputManager::FireActionEvent((CInputManager *)&v1->vfptr, &ie);
      }
    }
LABEL_23:
    ;
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashActiveControls.m_intrusiveTable);
  if ( SmartBox::smartbox )
  {
    v16 = SmartBox::smartbox->cmdinterp;
    if ( v16 )
      ((void (*)(void))v16->vfptr[9].OnAction)();
  }
  if ( v1->m_fInMouseLookMode )
  {
    if ( v1->m_aDevices.m_num )
    {
      LOWORD(v17.m_dwKey) = (unsigned __int8)v1->m_aDevices.m_data[v1->m_nVirtualDevice].iDeviceIndex;
      *((_WORD *)&v17.1 + 1) = 1;
      CInputManager_WIN32::FireInputEvent(v1, v17, ct_Button, 0x80u, dwTime);
    }
  }
}

//----- (006897A0) --------------------------------------------------------  // acclient.c:673189
void __thiscall CInputManager_WIN32::GetInput(CInputManager_WIN32 *this)
{
  CInputManager_WIN32 *v1; // esi@1
  unsigned int v2; // eax@3
  int v3; // ebx@3
  unsigned int v4; // edi@4
  CInputManager_WIN32::InputDevice *v5; // edx@5
  CInputManager_WIN32::InputDevice *v6; // ecx@8
  IDirectInputDevice8A *v7; // eax@8
  CInputManager_WIN32::InputDevice *v8; // eax@10
  CInputManager_WIN32::InputDevice *v9; // eax@13
  IDirectInputDevice8A *v10; // ecx@13
  int v11; // eax@13
  int v12; // eax@14
  unsigned int v13; // ebp@20
  DIDEVICEOBJECTDATA *v14; // ebx@21
  unsigned int v15; // eax@24
  int v16; // ebp@28
  int v17; // eax@28
  int v18; // eax@30
  ICMDCommandEnum v19; // edx@35
  bool v20; // cl@35
  int v21; // edi@36
  int v22; // eax@36
  HWND v23; // ST0C_4@36
  tagPOINT ptMouse; // [sp+14h] [bp-A0Ch]@3
  unsigned int dwItems; // [sp+1Ch] [bp-A04h]@14
  DIDEVICEOBJECTDATA adod[128]; // [sp+20h] [bp-A00h]@14

  v1 = this;
  if ( !(_S139_6 & 1) )
  {
    _S139_6 |= 1u;
    ptPreviousMousePos.x = this->m_ptMousePos.x;
    ptPreviousMousePos.y = this->m_ptMousePos.y;
  }
  v2 = this->m_aDevices.m_num;
  v3 = 0;
  ptMouse.x = 0;
  if ( v2 )
  {
    v4 = 0;
    do
    {
      v5 = v1->m_aDevices.m_data;
      if ( v5[v4].bActive && CInputManager_WIN32::PollDevice(v1, v5[v4].pDev, 1) )
      {
        if ( v3 == v1->m_nKeyboardDevice )
        {
          v6 = v1->m_aDevices.m_data;
          ptMouse.x = -1;
          v6[v4].pDev->vfptr[8].AddRef((IUnknown *)v6[v4].pDev);
          v7 = v1->m_aDevices.m_data[v4].pDev;
        }
        else
        {
          if ( v3 != v1->m_nMouseDevice )
          {
            if ( v3 != v1->m_nVirtualDevice )
            {
              v9 = v1->m_aDevices.m_data;
              v10 = v9[v4].pDev;
              v11 = (int)&v9[v4];
              if ( v10 )
              {
                dwItems = 128;
                v12 = (*(int (__stdcall **)(_DWORD, signed int, DIDEVICEOBJECTDATA *, unsigned int *, _DWORD))(**(_DWORD **)v11 + 40))(
                        *(_DWORD *)v11,
                        20,
                        adod,
                        &dwItems,
                        0);
                if ( v12 >= 0 )
                {
                  if ( v1->m_fMainWindowHasFocus )
                  {
                    v13 = 0;
                    if ( dwItems )
                    {
                      v14 = adod;
                      do
                      {
                        CInputManager_WIN32::ProcessDeviceData(v1, ptMouse.x, v14);
                        ++v13;
                        ++v14;
                      }
                      while ( v13 < dwItems );
                      v3 = ptMouse.x;
                    }
                  }
                }
                else if ( v12 == -2147024884 )
                {
                  v1->m_aDevices.m_data[v4].pDev->vfptr[2].AddRef((IUnknown *)v1->m_aDevices.m_data[v4].pDev);
                }
                else if ( v12 == -2147024866 )
                {
                  v1->m_aDevices.m_data[v4].pDev->vfptr[2].AddRef((IUnknown *)v1->m_aDevices.m_data[v4].pDev);
                }
              }
            }
            goto LABEL_24;
          }
          v8 = v1->m_aDevices.m_data;
          ptMouse.x = -1;
          v8[v4].pDev->vfptr[8].AddRef((IUnknown *)v8[v4].pDev);
          v7 = v1->m_aDevices.m_data[v4].pDev;
        }
        ((void (__stdcall *)(IDirectInputDevice8A *, signed int, _DWORD, tagPOINT *, _DWORD))v7->vfptr[3].AddRef)(
          v7,
          20,
          0,
          &ptMouse,
          0);
      }
LABEL_24:
      v15 = v1->m_aDevices.m_num;
      ++v3;
      ++v4;
      ptMouse.x = v3;
    }
    while ( v3 < v15 );
  }
  if ( v1->m_ptNonMousePointerMovement.x || v1->m_ptNonMousePointerMovement.y )
  {
    if ( GetCursorPos(&ptMouse) )
    {
      v16 = v1->m_ptNonMousePointerMovement.y;
      ptMouse.x += v1->m_ptNonMousePointerMovement.x;
      ptMouse.y += v16;
      SetCursorPos(ptMouse.x, ptMouse.y);
      v17 = v1->m_ptMousePos.y;
      v1->m_ptMousePos.x += v1->m_ptNonMousePointerMovement.x;
      v1->m_ptMousePos.y = v1->m_ptNonMousePointerMovement.y + v17;
    }
    v1->m_ptNonMousePointerMovement.x = 0;
    v1->m_ptNonMousePointerMovement.y = 0;
  }
  v18 = v1->m_ptMousePos.x;
  if ( ptPreviousMousePos.x != v18 || ptPreviousMousePos.y != v1->m_ptMousePos.y )
  {
    v19 = (signed int)Timer::cur_time.Cmd;
    HIDWORD(v1->m_ttLastInputEvent) = Timer::cur_time.Param;
    v20 = v1->m_fInMouseLookMode;
    LODWORD(v1->m_ttLastInputEvent) = v19;
    if ( v20 )
    {
      CInputManager::CallMouseLookHandler(
        (CInputManager *)&v1->vfptr,
        v18 - ptPreviousMousePos.x,
        v1->m_ptMousePos.y - ptPreviousMousePos.y);
      v21 = RenderDevice::GetDisplayHeight(RenderDevice::render_device) >> 1;
      v22 = RenderDevice::GetDisplayWidth(RenderDevice::render_device) >> 1;
      v1->m_ptMousePos.x = v22;
      ptMouse.x = v22;
      v23 = v1->m_hwnd;
      v1->m_ptMousePos.y = v21;
      ptMouse.y = v21;
      if ( ClientToScreen(v23, &ptMouse) )
        SetCursorPos(ptMouse.x, ptMouse.y);
    }
    else
    {
      CInputManager::CallMouseMoveHandler((CInputManager *)&v1->vfptr, v18, v1->m_ptMousePos.y);
    }
    ptPreviousMousePos.x = v1->m_ptMousePos.x;
    ptPreviousMousePos.y = v1->m_ptMousePos.y;
  }
  else if ( v1->m_fInMouseLookMode )
  {
    if ( v1->m_ttLastInputEvent + 0.2 < COERCE_DOUBLE(Timer::cur_time.Cmd) )
      CInputManager::CallMouseLookHandler((CInputManager *)&v1->vfptr, 0, 0);
  }
}

//----- (00689AA0) --------------------------------------------------------  // acclient.c:673365
void __thiscall CInputManager_WIN32::Activate(CInputManager_WIN32 *this, bool fActive)
{
  CInputManager_WIN32 *v2; // esi@1

  v2 = this;
  if ( fActive != this->m_fClientIsActive )
  {
    this->m_fClientIsActive = fActive;
    if ( fActive )
    {
      CInputManager_WIN32::AcquireAll(this);
    }
    else
    {
      CInputManager_WIN32::UnacquireAll(this);
      CInputManager_WIN32::ReleasePressedKeys(v2);
    }
    CInputManager::CallFocusSwitchHandler((CInputManager *)&v2->vfptr, v2->m_fClientIsActive);
    if ( v2->m_fWantMouseLookMode )
    {
      v2->vfptr[1].__vecDelDtor((ICIDM *)v2, v2->m_fClientIsActive);
    }
    else if ( v2->m_fClientIsActive )
    {
      Device::ShowCursor(1);
    }
  }
}

//----- (00689B20) --------------------------------------------------------  // acclient.c:673395
void __thiscall CInputManager_WIN32::UseTime(CInputManager_WIN32 *this)
{
  CInputManager *v1; // esi@1

  v1 = (CInputManager *)this;
  CInputManager_WIN32::GetInput(this);
  CInputManager::UseTime(v1);
}

//----- (00689B30) --------------------------------------------------------  // acclient.c:673405
int __thiscall CInputManager_WIN32::OnMessage(CInputManager_WIN32 *this, tagMSG *i_msg, bool *o_fHandled)
{
  tagMSG *v3; // eax@1
  bool *v4; // edi@1
  CInputManager_WIN32 *v5; // esi@1
  unsigned int v6; // ecx@1
  unsigned int v7; // edx@1
  bool v8; // al@5
  int result; // eax@6
  bool v10; // al@8
  char v11; // bl@15
  int v12; // ST18_4@16
  int v13; // edx@17

  v3 = i_msg;
  v4 = o_fHandled;
  v5 = this;
  *o_fHandled = 1;
  v6 = v3->message;
  v7 = v3->message;
  if ( v7 > 0x106 )
  {
    switch ( v7 )
    {
      case 0x201u:
      case 0x202u:
      case 0x203u:
        CInputManager_WIN32::GenerateMouseButtonEvent(v5, 0, v6 == 514, v3->time);
        v5->m_bProcessingKeyDown = 0;
        result = 0;
        break;
      case 0x204u:
      case 0x205u:
      case 0x206u:
        CInputManager_WIN32::GenerateMouseButtonEvent(v5, 1, v6 == 517, v3->time);
        v5->m_bProcessingKeyDown = 0;
        result = 0;
        break;
      case 0x207u:
      case 0x208u:
      case 0x209u:
        CInputManager_WIN32::GenerateMouseButtonEvent(v5, 2, v6 == 520, v3->time);
        v5->m_bProcessingKeyDown = 0;
        result = 0;
        break;
      case 0x20Bu:
      case 0x20Cu:
      case 0x20Du:
        CInputManager_WIN32::GenerateMouseButtonEvent(v5, HIWORD(v3->wParam) + 2, v6 == 524, v3->time);
        v5->m_bProcessingKeyDown = 0;
        result = 1;
        break;
      case 0x200u:
        v5->m_ptMousePos.x = LOWORD(v3->lParam);
        v5->m_ptMousePos.y = HIWORD(v3->lParam);
        v5->m_bProcessingKeyDown = 0;
        result = 0;
        break;
      case 0x2A3u:
        if ( !UIElementManager::s_pInstance )
          goto LABEL_33;
        UIElementManager::MouseLeaveEvent(UIElementManager::s_pInstance);
        v5->m_bProcessingKeyDown = 0;
        result = 0;
        break;
      case 0x20Au:
        CInputManager_WIN32::GenerateMouseWheelEvent(v5, HIWORD(v3->wParam), v3->time);
        v5->m_bProcessingKeyDown = 0;
        result = 0;
        break;
      case 0x219u:
        if ( v3->wParam == 7 )
          CInputManager_WIN32::EnumSuitableDevices(v5);
        v5->m_bProcessingKeyDown = 0;
        result = 1;
        break;
      default:
        goto LABEL_32;
    }
  }
  else if ( v7 == 262 )
  {
$L128934:
    v11 = LOBYTE(v3->wParam);
    LOBYTE(o_fHandled) = LOBYTE(v3->wParam);
    if ( prevLeadByte )
    {
      LOBYTE(o_fHandled) = prevLeadByte;
      *(_WORD *)((char *)&o_fHandled + 1) = (unsigned __int8)v11;
      MultiByteToWideChar(0, 1u, (LPCSTR)&o_fHandled, -1, (LPWSTR)&i_msg, 1);
      CInputManager_WIN32::UpdateCharacter(v5, v12);
      v5->m_bProcessingKeyDown = 0;
      result = 0;
      prevLeadByte = 0;
    }
    else if ( IsDBCSLeadByte((BYTE)o_fHandled) )
    {
      v5->m_bProcessingKeyDown = 0;
      result = 0;
      prevLeadByte = v11;
    }
    else
    {
      LOWORD(v13) = (unsigned __int8)v11;
      CInputManager_WIN32::UpdateCharacter(v5, v13);
      v5->m_bProcessingKeyDown = 0;
      result = 0;
    }
  }
  else
  {
    switch ( v7 )
    {
      case 7u:
        if ( v5->m_fMainWindowHasFocus == 1 )
          goto LABEL_33;
        v8 = v5->m_fWantMouseLookMode;
        v5->m_fMainWindowHasFocus = 1;
        if ( !v8 )
          goto LABEL_33;
        v5->vfptr[1].__vecDelDtor((ICIDM *)v5, 1u);
        v5->m_bProcessingKeyDown = 0;
        return 0;
      case 8u:
        if ( !v5->m_fMainWindowHasFocus )
          goto LABEL_33;
        CInputManager_WIN32::ReleasePressedKeys(v5);
        v10 = v5->m_fWantMouseLookMode;
        v5->m_fMainWindowHasFocus = 0;
        if ( !v10 )
          goto LABEL_33;
        v5->vfptr[1].__vecDelDtor((ICIDM *)v5, 0);
        v5->m_bProcessingKeyDown = 0;
        return 0;
      case 0x100u:
      case 0x104u:
        v5->m_bProcessingKeyDown = 1;
        v5->m_bIgnoreNextChar = 0;
        goto $L128933;
      case 0x101u:
      case 0x105u:
$L128933:
        CInputManager_WIN32::GenerateKeyboardEvent(v5, v3);
        v5->m_bProcessingKeyDown = 0;
        return 0;
      case 0x1Fu:
        if ( v5->m_cSetCapture )
        {
          v5->m_cSetCapture = 0;
          ReleaseCapture();
        }
        CInputManager_WIN32::ReleasePressedKeys(v5);
        v5->m_bProcessingKeyDown = 0;
        return 0;
      case 0x102u:
        goto $L128934;
      default:
        break;
    }
LABEL_32:
    *v4 = 0;
LABEL_33:
    v5->m_bProcessingKeyDown = 0;
    result = 0;
  }
  return result;
}

//----- (00715950) --------------------------------------------------------  // acclient.c:808588
int sub_715950()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_48, "Misc.TooltipEnable");
  return atexit(sub_77F990);
}

//----- (00715970) --------------------------------------------------------  // acclient.c:808595
int _E76_98()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_48, "Misc.TooltipDelay");
  return atexit(sub_77F9C0);
}

//----- (00715990) --------------------------------------------------------  // acclient.c:808602
void sub_715990()
{
  LODWORD(dword_8F7BE4) = 1053364187;
}

//----- (007159A0) --------------------------------------------------------  // acclient.c:808608
void sub_7159A0()
{
  flt_8F7BE8 = 1000.0 + 1.0;
}

//----- (007159C0) --------------------------------------------------------  // acclient.c:808614
void _E99_43()
{
  flt_8F7BEC = 24.0 * 8.0;
}

//----- (007159E0) --------------------------------------------------------  // acclient.c:808620
void _E101_42()
{
  flt_8F7BF0 = 24.0 * 0.5;
}

//----- (00715A00) --------------------------------------------------------  // acclient.c:808626
void sub_715A00()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F7BF8, PFID_A8R8G8B8);
}

//----- (00715A10) --------------------------------------------------------  // acclient.c:808632
int _E105_57()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_38, "Display.Resolution");
  return atexit(sub_77F9F0);
}

//----- (00715A30) --------------------------------------------------------  // acclient.c:808639
int sub_715A30()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_38, "Display.FullScreen");
  return atexit(sub_77FA20);
}

//----- (00715A50) --------------------------------------------------------  // acclient.c:808646
int _E111_60()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_38, "Display.RefreshRate");
  return atexit(sub_77FA50);
}

//----- (00715A70) --------------------------------------------------------  // acclient.c:808653
int _E114_66()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_38, "Display.SyncToRefresh");
  return atexit(sub_77FA80);
}

//----- (00715A90) --------------------------------------------------------  // acclient.c:808660
void _E117_84()
{
  flt_8F7C40 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00715AB0) --------------------------------------------------------  // acclient.c:808666
void _E119_33()
{
  dbl_8F7C48 = 1.0 / 30.0;
}

//----- (00715AD0) --------------------------------------------------------  // acclient.c:808672
void _E121_77()
{
  dbl_8F7C50 = 1.0 / 5.0;
}

//----- (00715AF0) --------------------------------------------------------  // acclient.c:808678
unsigned int _E123_48()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_KeyDescDelimiter");
  ID_KeyDescDelimiter = result;
  return result;
}

//----- (00715B10) --------------------------------------------------------  // acclient.c:808688
unsigned int _E125_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_KeyNameWithSubControl");
  ID_KeyNameWithSubControl = result;
  return result;
}

//----- (00715B30) --------------------------------------------------------  // acclient.c:808698
unsigned int _E127_64()
{
  unsigned int result; // eax@1

  result = compute_str_hash("KEY");
  KEY_0 = result;
  return result;
}

//----- (00715B50) --------------------------------------------------------  // acclient.c:808708
unsigned int _E129_49()
{
  unsigned int result; // eax@1

  result = compute_str_hash("SUBCONTROL");
  SUBCONTROL = result;
  return result;
}

//----- (00715B70) --------------------------------------------------------  // acclient.c:808718
UINT _E131_9()
{
  UINT result; // eax@1

  result = GetDoubleClickTime();
  CInputManager_WIN32::sm_timeDoubleClick = result;
  return result;
}
// 8F7C68: using guessed type unsigned __int32 CInputManager_WIN32::sm_timeDoubleClick;

//----- (00715B80) --------------------------------------------------------  // acclient.c:808729
unsigned __int32 _E133_50()
{
  unsigned __int32 result; // eax@1

  result = CInputManager_WIN32::sm_timeDoubleClick >> 1;
  CInputManager_WIN32::sm_timeTap = CInputManager_WIN32::sm_timeDoubleClick >> 1;
  return result;
}
// 8F7C68: using guessed type unsigned __int32 CInputManager_WIN32::sm_timeDoubleClick;
// 8F7C6C: using guessed type unsigned __int32 CInputManager_WIN32::sm_timeTap;

//----- (00715B90) --------------------------------------------------------  // acclient.c:808741
int _E135_57()
{
  int result; // eax@1

  result = GetSystemMetrics(36) / 2;
  CInputManager_WIN32::sm_cxDblClick = result;
  return result;
}

//----- (00715BB0) --------------------------------------------------------  // acclient.c:808751
int _E137_10()
{
  int result; // eax@1

  result = GetSystemMetrics(37) / 2;
  CInputManager_WIN32::sm_cyDblClick = result;
  return result;
}

//----- (00715BD0) --------------------------------------------------------  // acclient.c:808761
int sub_715BD0()
{
  return atexit(nullsub_236);
}

//----- (0077F990) --------------------------------------------------------  // acclient.c:918220
void __cdecl sub_77F990()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F9C0) --------------------------------------------------------  // acclient.c:918233
void __cdecl sub_77F9C0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F9F0) --------------------------------------------------------  // acclient.c:918246
void __cdecl sub_77F9F0()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FA20) --------------------------------------------------------  // acclient.c:918259
void __cdecl sub_77FA20()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FA50) --------------------------------------------------------  // acclient.c:918272
void __cdecl sub_77FA50()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077FA80) --------------------------------------------------------  // acclient.c:918285
void __cdecl sub_77FA80()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

