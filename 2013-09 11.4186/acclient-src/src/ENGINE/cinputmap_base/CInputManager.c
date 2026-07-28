/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CInputManager
   Object     : ENGINE\cinputmap_base\CInputManager.obj
   Functions  : 92
   Addresses  : 00430C40 - 00728890 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00430C40) --------------------------------------------------------  // acclient.c:109922
ICIDM *__thiscall ICIDM::vector_deleting_destructor(ICIDM *this, unsigned int a2)
{
  ICIDM *v2; // esi@1

  v2 = this;
  this->vfptr = (ICIDMVtbl *)&ICIDM::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 798268: using guessed type int (__thiscall *ICIDM::vftable)(void *, char);

//----- (00430C60) --------------------------------------------------------  // acclient.c:109935
bool __thiscall CInputManager::OnStartup(CInputManager *this, int dwUserData)
{
  CInputManager *v2; // esi@1
  ActionMap *v3; // ecx@1
  int v4; // eax@3

  v2 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr->Activate)(Device::m_bIsActiveApp);
  v3 = v2->m_action_map;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v2->m_action_map = 0;
  }
  v4 = DBObj::GetByEnum(1, 8, 0x27u);
  v2->m_action_map = (ActionMap *)v4;
  return v4 != 0;
}
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00430CB0) --------------------------------------------------------  // acclient.c:109956
bool __thiscall CInputManager::SetActionMap(CInputManager *this, unsigned int _actID)
{
  CInputManager *v2; // esi@1
  ActionMap *v3; // ecx@1
  int v4; // eax@3

  v2 = this;
  v3 = this->m_action_map;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v2->m_action_map = 0;
  }
  v4 = DBObj::GetByEnum(_actID, 8, 0x27u);
  v2->m_action_map = (ActionMap *)v4;
  return v4 != 0;
}

//----- (00430CF0) --------------------------------------------------------  // acclient.c:109975
void __thiscall CInputManager::OnSwitchMouseMode(CInputManager *this, bool fEnterMouseLook)
{
  this->m_fInMouseLookMode = fEnterMouseLook;
}

//----- (00430D00) --------------------------------------------------------  // acclient.c:109981
bool __thiscall CInputManager::CallKeyHitHandler(CInputManager *this, QualifiedControl *i_key, unsigned int *o_idAction)
{
  CInputHandler *v3; // ecx@1
  bool result; // al@2

  v3 = this->m_pKeyHitHandler;
  if ( v3 )
    result = ((int (__stdcall *)(QualifiedControl *, unsigned int *))v3->vfptr->KeyHitHandler)(i_key, o_idAction);
  else
    result = 0;
  return result;
}

//----- (00430D20) --------------------------------------------------------  // acclient.c:109995
void __thiscall CInputManager::StartAction(CInputManager *this, InputEvent *i_inEvt)
{
  i_inEvt->m_fStart = 1;
  (*(void (__stdcall **)(_DWORD))&this->vfptr[1].gap4[4])(i_inEvt);
}

//----- (00430D40) --------------------------------------------------------  // acclient.c:110002
void __thiscall InputEvent::InputEvent(InputEvent *this)
{
  this->m_InputAction = 0;
  this->m_InputMapID = 0;
  this->m_InputKey.m_key.m_dwKey = -1;
  this->m_InputKey.m_metamode = 0;
  this->m_InputKey.m_activation = 0;
  LODWORD(this->m_InputExtent) = -1073741824;
  this->m_InputTimestamp = 0;
  this->m_ToggleType = 0;
  *(_QWORD *)&this->m_timeActionBegan = 0i64;
  this->m_cRepeatDelta = 0;
  this->m_cRepeatTotal = 0;
  this->m_pcCallback = 0;
}

//----- (00430D80) --------------------------------------------------------  // acclient.c:110019
void __thiscall SmartArray<ActionState::SingleKeyInfo,1>::Reset(SmartArray<ActionState::SingleKeyInfo,1> *this)
{
  SmartArray<ActionState::SingleKeyInfo,1> *v1; // esi@1
  unsigned int v2; // ecx@1
  int i; // ecx@4
  int v4; // eax@5
  int v5; // [sp+8h] [bp-4h]@0

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v1->m_num = 0;
  if ( (v2 & 0x80000000) == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; *(_DWORD *)(v4 + 4) = v5 )
    {
      v4 = (int)&v1->m_data[i--];
      *(_DWORD *)v4 = -1;
    }
  }
}

//----- (00430DF0) --------------------------------------------------------  // acclient.c:110047
double __thiscall ActionState::GetExtent(ActionState *this)
{
  unsigned int v1; // esi@1
  signed int v2; // edi@1
  signed int v3; // edx@2
  ActionState::SingleKeyInfo *v4; // ebx@3
  long double *v5; // ecx@3
  long double v6; // st7@4
  double v7; // st7@8
  float result; // [sp+0h] [bp-4h]@1

  v1 = this->m_rgKeys.m_num;
  v2 = -1;
  result = -2.0;
  if ( !v1 )
    goto LABEL_12;
  v3 = 0;
  if ( !v1 )
    goto LABEL_12;
  v4 = this->m_rgKeys.m_data;
  v5 = (long double *)&v4->extent;
  do
  {
    v6 = fabs(*(float *)v5);
    if ( v6 > result )
    {
      result = v6;
      v2 = v3;
    }
    ++v3;
    ++v5;
  }
  while ( v3 < v1 );
  if ( v2 >= 0 )
    v7 = v4[v2].extent;
  else
LABEL_12:
    v7 = 0.0;
  return v7;
}

//----- (00430E50) --------------------------------------------------------  // acclient.c:110089
void __thiscall InputEvent::InputEvent(InputEvent *this, ActionState *as)
{
  InputEvent *v2; // esi@1

  v2 = this;
  this->m_InputAction = as->m_hashKey;
  this->m_InputMapID = 0;
  this->m_InputKey.m_key.m_dwKey = -1;
  this->m_InputKey.m_metamode = 0;
  this->m_InputKey.m_activation = 0;
  this->m_InputExtent = ActionState::GetExtent(as);
  v2->m_InputTimestamp = 0;
  v2->m_ToggleType = as->m_toggle;
  v2->m_timeActionBegan = as->m_timeActionBegan;
  v2->m_cRepeatDelta = 1;
  v2->m_cRepeatTotal = as->m_cRepeatCount;
  v2->m_pcCallback = as->m_pcCallback;
}

//----- (00430EB0) --------------------------------------------------------  // acclient.c:110109
IntrusiveHashTable<unsigned long,ActionState *,1> *__thiscall IntrusiveHashTable<unsigned long,ActionState *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,ActionState *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,ActionState *,1> *v2; // esi@1
  ActionState **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,ActionState *,1>Vtbl *)&IntrusiveHashTable<unsigned long,ActionState *,1>::vftable;
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
// 798330: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,ActionState *,1>::vftable)(void *, char);

//----- (00430EF0) --------------------------------------------------------  // acclient.c:110130
void __userpurge UserPreferences::RegisterPreference(float *_pVariable@<eax>, void *a2@<ecx>, PStringBase<char> *_Name, PStringBase<char> *_Description, void (__cdecl *_OnChangedCallbackFP)(PStringBase<char> *), const unsigned int _NumChoices, PStringBase<char> *_pChoiceStrings, const unsigned int *_pChoiceValues)
{
  PStringBase<char> *v8; // esi@1
  GlobalRegistryInstance *v9; // eax@3
  GlobalRegistryInstance *v10; // eax@4
  int v11; // eax@9

  v8 = _Name;
  if ( a2 )
    GlobalRegistry::RegisterVariableInternal(
      a2,
      GRVDataType_Float32,
      _Name,
      _Description,
      _OnChangedCallbackFP,
      _NumChoices,
      _pChoiceStrings,
      _pChoiceValues);
  v9 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v10 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v10 )
      GlobalRegistryInstance::GlobalRegistryInstance(v10);
    else
      v9 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v9;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v9, v8, (GRPObject **)&_Name) )
  {
    v11 = (*(int (**)(void))&_Name->m_charbuffer[4].m_data[4])();
    if ( v11 )
      *(_BYTE *)(v11 + 40) = 1;
  }
}

//----- (00430F70) --------------------------------------------------------  // acclient.c:110167
char __thiscall SmartArray<ActionState::SingleKeyInfo,1>::grow(SmartArray<ActionState::SingleKeyInfo,1> *this, unsigned int i_nSize)
{
  SmartArray<ActionState::SingleKeyInfo,1> *v2; // edi@1
  void *v4; // eax@5
  ActionState::SingleKeyInfo *v5; // esi@5
  int i; // edx@7
  int v7; // ecx@8
  unsigned int v8; // ebp@8
  int v9; // eax@8

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<ActionState::SingleKeyInfo,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize);
    v5 = (ActionState::SingleKeyInfo *)v4;
    if ( v4 )
    {
      vector_constructor_iterator(
        v4,
        8u,
        i_nSize,
        (void *(__thiscall *)(void *))ActionState::SingleKeyInfo::SingleKeyInfo);
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; LODWORD(v5[v7].extent) = *(_DWORD *)(v9 + 4) )
        {
          v7 = i;
          v8 = v2->m_data[i].key.m_dwKey;
          v9 = (int)&v2->m_data[i--];
          v5[v7].key.m_dwKey = v8;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = v5;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00431030) --------------------------------------------------------  // acclient.c:110217
char __thiscall List<CInputHandler *>::insert(List<CInputHandler *> *this, ListNode<CInputHandler *> *node, CInputHandler *const *val)
{
  List<CInputHandler *> *v3; // esi@1
  void *v4; // eax@1
  char result; // al@3
  ListNode<CInputHandler *> *v6; // edx@5

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = *val;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = 0;
    if ( v3->_head )
    {
      *((_DWORD *)v4 + 1) = node;
      *((_DWORD *)v4 + 2) = node->prev;
      v6 = node->prev;
      if ( v6 )
      {
        v6->next = (ListNode<CInputHandler *> *)v4;
        node->prev = (ListNode<CInputHandler *> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
      else
      {
        v3->_head = (ListNode<CInputHandler *> *)v4;
        node->prev = (ListNode<CInputHandler *> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
    }
    else
    {
      v3->_head = (ListNode<CInputHandler *> *)v4;
      v3->_tail = (ListNode<CInputHandler *> *)v4;
      ++v3->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004310B0) --------------------------------------------------------  // acclient.c:110267
char __thiscall List<CInputManager::InputMapEntry>::push_back(List<CInputManager::InputMapEntry> *this, CInputManager::InputMapEntry *val)
{
  List<CInputManager::InputMapEntry> *v2; // esi@1
  void *v3; // eax@1
  char result; // al@3
  ListNode<CInputManager::InputMapEntry> *v5; // ecx@5

  v2 = this;
  v3 = operator new(0x14u);
  if ( v3 )
  {
    *(CInputManager::InputMapEntry *)v3 = *val;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
    if ( v2->_head )
    {
      v5 = v2->_tail;
      v5->next = (ListNode<CInputManager::InputMapEntry> *)v3;
      *((_DWORD *)v3 + 4) = v5;
      v2->_tail = (ListNode<CInputManager::InputMapEntry> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
    else
    {
      v2->_head = (ListNode<CInputManager::InputMapEntry> *)v3;
      v2->_tail = (ListNode<CInputManager::InputMapEntry> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00431120) --------------------------------------------------------  // acclient.c:110306
char __thiscall List<CInputManager::InputMapEntry>::insert(List<CInputManager::InputMapEntry> *this, ListNode<CInputManager::InputMapEntry> *node, CInputManager::InputMapEntry *val)
{
  List<CInputManager::InputMapEntry> *v3; // esi@1
  void *v4; // eax@1
  char result; // al@3
  ListNode<CInputManager::InputMapEntry> *v6; // edx@5

  v3 = this;
  v4 = operator new(0x14u);
  if ( v4 )
  {
    *(CInputManager::InputMapEntry *)v4 = *val;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 4) = 0;
    if ( v3->_head )
    {
      *((_DWORD *)v4 + 3) = node;
      *((_DWORD *)v4 + 4) = node->prev;
      v6 = node->prev;
      if ( v6 )
      {
        v6->next = (ListNode<CInputManager::InputMapEntry> *)v4;
        node->prev = (ListNode<CInputManager::InputMapEntry> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
      else
      {
        v3->_head = (ListNode<CInputManager::InputMapEntry> *)v4;
        node->prev = (ListNode<CInputManager::InputMapEntry> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
    }
    else
    {
      v3->_head = (ListNode<CInputManager::InputMapEntry> *)v4;
      v3->_tail = (ListNode<CInputManager::InputMapEntry> *)v4;
      ++v3->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004311B0) --------------------------------------------------------  // acclient.c:110356
void __thiscall CInputManager::CallCharacterHandler(CInputManager *this, int charToHandle)
{
  ListNode<CInputHandler *> *v2; // esi@3
  CInputHandlerVtbl *v3; // eax@4

  if ( this->m_characterList._head )
  {
    if ( this->m_textMode == 1 )
    {
      v2 = this->m_characterList._head;
      while ( v2 )
      {
        v3 = v2->data->vfptr;
        v2 = v2->next;
        ((void (__stdcall *)(_DWORD))v3->CharacterHandler)(charToHandle);
      }
    }
  }
}

//----- (004311F0) --------------------------------------------------------  // acclient.c:110377
void __thiscall CInputManager::CallMouseMoveHandler(CInputManager *this, int cx, int cy)
{
  ListNode<CInputHandler *> *v3; // esi@1
  CInputHandlerVtbl *v4; // eax@2

  v3 = this->m_mouseMoveList._head;
  while ( v3 )
  {
    v4 = v3->data->vfptr;
    v3 = v3->next;
    ((void (__stdcall *)(int, int))v4->MouseMoveHandler)(cx, cy);
  }
}

//----- (00431220) --------------------------------------------------------  // acclient.c:110392
void __thiscall CInputManager::CallMouseLookHandler(CInputManager *this, int dxpos, int dypos)
{
  ListNode<CInputHandler *> *v3; // esi@1
  CInputHandlerVtbl *v4; // eax@2

  v3 = this->m_mouseLookList._head;
  while ( v3 )
  {
    v4 = v3->data->vfptr;
    v3 = v3->next;
    ((void (__stdcall *)(int, int))v4->MouseLookHandler)(dxpos, dypos);
  }
}

//----- (00431250) --------------------------------------------------------  // acclient.c:110407
void __thiscall CInputManager::CallFocusSwitchHandler(CInputManager *this, int have_focus)
{
  ListNode<CInputHandler *> *v2; // eax@1
  int v3; // edi@2
  int v4; // edi@3
  ListNode<CInputHandler *> *v5; // esi@5
  CInputHandlerVtbl *v6; // edx@6

  v2 = this->m_focusSwitchList._head;
  this->m_lastFocus = have_focus;
  if ( v2 )
  {
    v3 = (this->m_textMode != 0) + 1;
    if ( this->m_fWantMouseLookMode )
      v4 = v3 | 4;
    else
      v4 = v3 | 0x10;
    v5 = this->m_focusSwitchList._head;
    while ( v5 )
    {
      v6 = v5->data->vfptr;
      v5 = v5->next;
      ((void (__stdcall *)(_DWORD, int))v6->FocusSwitchHandler)(have_focus, v4);
    }
  }
}

//----- (004312A0) --------------------------------------------------------  // acclient.c:110435
void __thiscall CInputManager::SendActionToListeners(CInputManager *this, InputEvent *i_inEvt)
{
  CInputManager *v2; // esi@1
  IInputActionCallback *v3; // ecx@1
  ListNode<CInputHandler *> *v4; // esi@4
  CInputHandlerVtbl *v5; // edx@5

  v2 = this;
  v3 = i_inEvt->m_pcCallback;
  if ( !v3 || !(unsigned __int8)((int (__stdcall *)(InputEvent *))v3->vfptr->OnAction)(i_inEvt) )
  {
    if ( v2->m_lastFocus )
    {
      v4 = v2->m_actionList._head;
      while ( v4 )
      {
        v5 = v4->data->vfptr;
        v4 = v4->next;
        ((void (__stdcall *)(_DWORD))v5->ActionHandler)(i_inEvt);
      }
    }
  }
}

//----- (004312E0) --------------------------------------------------------  // acclient.c:110460
char __thiscall List<CInputManager::InputMapEntry>::remove(List<CInputManager::InputMapEntry> *this, ListNode<CInputManager::InputMapEntry> *node)
{
  ListNode<CInputManager::InputMapEntry> *v2; // edx@1
  List<CInputManager::InputMapEntry> *v3; // esi@1
  ListNode<CInputManager::InputMapEntry> *v4; // ecx@2
  ListNode<CInputManager::InputMapEntry> *v6; // ecx@5

  v2 = 0;
  v3 = this;
  if ( !node )
    return 0;
  v4 = this->_head;
  if ( !v4 )
    return 0;
  if ( node != v4 )
  {
    node->prev->next = node->next;
    v6 = node->next;
    if ( !v6 )
    {
      v3->_tail = node->prev;
      goto LABEL_11;
    }
    v2 = node->prev;
    goto LABEL_9;
  }
  v6 = node->next;
  v3->_head = v6;
  if ( v6 )
  {
LABEL_9:
    v6->prev = v2;
    goto LABEL_11;
  }
  v3->_tail = 0;
LABEL_11:
  operator delete(node);
  --v3->_num_elements;
  return 1;
}

//----- (004313C0) --------------------------------------------------------  // acclient.c:110544
void __thiscall CInputManager::SetMouseLookMode(CInputManager *this, int fEnterMouseLook)
{
  CInputManager *v2; // esi@1
  ICIDMVtbl *v3; // edx@2

  v2 = this;
  if ( (_BYTE)fEnterMouseLook != this->m_fWantMouseLookMode )
  {
    v3 = this->vfptr;
    this->m_fWantMouseLookMode = fEnterMouseLook;
    ((void (__stdcall *)(_DWORD))v3[1].__vecDelDtor)(fEnterMouseLook);
  }
  CInputManager::CallFocusSwitchHandler(v2, v2->m_lastFocus);
}

//----- (004313F0) --------------------------------------------------------  // acclient.c:110560
void __thiscall CInputManager::SetTextMode(CInputManager *this, int mode)
{
  CInputManager *v2; // esi@1
  ICIDMVtbl *v3; // edx@2

  v2 = this;
  if ( (_BYTE)mode != this->m_textMode )
  {
    v3 = this->vfptr;
    this->m_textMode = mode;
    (*(void (__stdcall **)(_DWORD))&v3[1].gap4[0])(mode);
  }
  CInputManager::CallFocusSwitchHandler(v2, v2->m_lastFocus);
}

//----- (00431420) --------------------------------------------------------  // acclient.c:110576
signed int __thiscall ActionState::RemoveKeyPress(ActionState *this, InputEvent *io_inEvt)
{
  signed int v2; // esi@1
  char v3; // bl@1
  unsigned int v4; // edx@1
  ActionState::SingleKeyInfo *v5; // edi@2
  long double v6; // st7@5
  signed int v7; // edi@8
  unsigned int v8; // eax@13
  int v9; // edx@14
  ActionState::SingleKeyInfo *v10; // eax@15
  ActionState::SingleKeyInfo *v11; // eax@15
  float fNewMaxExtent; // [sp+Ch] [bp-10h]@1
  int idxMaxExtent; // [sp+10h] [bp-Ch]@1
  float v15; // [sp+18h] [bp-4h]@0

  v2 = -1;
  v3 = 0;
  v4 = 0;
  idxMaxExtent = -1;
  fNewMaxExtent = -2.0;
  if ( this->m_rgKeys.m_num )
  {
    v5 = this->m_rgKeys.m_data;
    do
    {
      if ( io_inEvt->m_InputKey.m_key.m_dwKey == v5->key.m_dwKey )
      {
        v3 = 1;
        v2 = v4;
      }
      else
      {
        v6 = fabs(v5->extent);
        if ( v6 > fNewMaxExtent )
        {
          fNewMaxExtent = v6;
          idxMaxExtent = v4;
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_rgKeys.m_num );
  }
  v7 = 2;
  if ( v3 )
  {
    if ( idxMaxExtent < 0 )
    {
      v7 = 3;
      this->m_pcCallback = 0;
    }
    else if ( fNewMaxExtent < fabs(this->m_rgKeys.m_data[v2].extent) )
    {
      io_inEvt->m_InputExtent = fNewMaxExtent;
      v7 = 1;
    }
    v8 = this->m_rgKeys.m_num;
    if ( v2 < v8 )
    {
      v9 = v8 - 1;
      this->m_rgKeys.m_num = v8 - 1;
      if ( v2 != v8 - 1 )
      {
        v10 = this->m_rgKeys.m_data;
        v10[v2].key.m_dwKey = v10[v9].key.m_dwKey;
        v10[v2].extent = v10[v9].extent;
        v11 = &this->m_rgKeys.m_data[this->m_rgKeys.m_num];
        v11->key.m_dwKey = -1;
        v11->extent = v15;
      }
    }
  }
  return v7;
}

//----- (00431510) --------------------------------------------------------  // acclient.c:110654
char __thiscall List<CInputManager::InputMapEntry>::insert_sort(List<CInputManager::InputMapEntry> *this, CInputManager::InputMapEntry *val)
{
  ListNode<CInputManager::InputMapEntry> *v2; // eax@1
  char result; // al@4

  v2 = this->_head;
  if ( !v2 )
    goto LABEL_10;
  while ( val->m_nPriority < v2->data.m_nPriority )
  {
    v2 = v2->next;
    if ( !v2 )
      return List<CInputManager::InputMapEntry>::push_back(this, val);
  }
  if ( v2 )
    result = List<CInputManager::InputMapEntry>::insert(this, v2, val);
  else
LABEL_10:
    result = List<CInputManager::InputMapEntry>::push_back(this, val);
  return result;
}

//----- (00431550) --------------------------------------------------------  // acclient.c:110677
bool __thiscall List<CInputManager::InputMapEntry>::contains(List<CInputManager::InputMapEntry> *this, CInputManager::InputMapEntry *val)
{
  ListNode<CInputManager::InputMapEntry> *v2; // eax@1

  v2 = this->_head;
  if ( v2 )
  {
    while ( v2->data.m_mapID != val->m_mapID
         || v2->data.m_pcCallback != val->m_pcCallback
         || v2->data.m_nPriority != val->m_nPriority )
    {
      v2 = v2->next;
      if ( !v2 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v2 = 0;
  }
  return v2 != 0;
}

//----- (004315D0) --------------------------------------------------------  // acclient.c:110725
char __thiscall CInputManager::UnregisterInputHandler(CInputManager *this, CInputHandler *handler, unsigned int modes)
{
  CInputManager *v3; // esi@1
  ListNode<CInputHandler *> *v4; // eax@2
  List<NoticeHandler *> *v5; // ecx@2
  ListNode<NoticeHandler *> *v6; // edx@2
  ListNode<CInputHandler *> *v7; // eax@9
  ListNode<NoticeHandler *> *v8; // edx@9
  ListNode<CInputHandler *> *v9; // eax@16
  ListNode<NoticeHandler *> *v10; // edx@16
  ListNode<CInputHandler *> *v11; // eax@23
  ListNode<NoticeHandler *> *v12; // edx@23
  ListNode<CInputHandler *> *v13; // eax@30
  ListNode<NoticeHandler *> *v14; // edx@30

  v3 = this;
  if ( modes & 1 )
  {
    v4 = this->m_actionList._head;
    v5 = (List<NoticeHandler *> *)&this->m_actionList;
    v6 = 0;
    if ( v4 )
    {
      do
      {
        if ( v4->data == handler )
          v6 = (ListNode<NoticeHandler *> *)v4;
        v4 = v4->next;
      }
      while ( v4 );
      if ( v6 )
        List<NoticeHandler *>::remove(v5, v6);
    }
  }
  if ( modes & 2 )
  {
    v7 = v3->m_characterList._head;
    v8 = 0;
    if ( v7 )
    {
      do
      {
        if ( v7->data == handler )
          v8 = (ListNode<NoticeHandler *> *)v7;
        v7 = v7->next;
      }
      while ( v7 );
      if ( v8 )
        List<NoticeHandler *>::remove((List<NoticeHandler *> *)&v3->m_characterList, v8);
    }
  }
  if ( modes & 0x10 )
  {
    v9 = v3->m_mouseMoveList._head;
    v10 = 0;
    if ( v9 )
    {
      do
      {
        if ( v9->data == handler )
          v10 = (ListNode<NoticeHandler *> *)v9;
        v9 = v9->next;
      }
      while ( v9 );
      if ( v10 )
        List<NoticeHandler *>::remove((List<NoticeHandler *> *)&v3->m_mouseMoveList, v10);
    }
  }
  if ( modes & 4 )
  {
    v11 = v3->m_mouseLookList._head;
    v12 = 0;
    if ( v11 )
    {
      do
      {
        if ( v11->data == handler )
          v12 = (ListNode<NoticeHandler *> *)v11;
        v11 = v11->next;
      }
      while ( v11 );
      if ( v12 )
        List<NoticeHandler *>::remove((List<NoticeHandler *> *)&v3->m_mouseLookList, v12);
    }
  }
  if ( modes & 8 )
  {
    v13 = v3->m_focusSwitchList._head;
    v14 = 0;
    if ( v13 )
    {
      do
      {
        if ( v13->data == handler )
          v14 = (ListNode<NoticeHandler *> *)v13;
        v13 = v13->next;
      }
      while ( v13 );
      if ( v14 )
        List<NoticeHandler *>::remove((List<NoticeHandler *> *)&v3->m_focusSwitchList, v14);
    }
  }
  if ( modes & 0x20 )
  {
    if ( v3->m_pKeyHitHandler != handler )
      return 0;
    v3->m_pKeyHitHandler = 0;
  }
  return 1;
}

//----- (004316D0) --------------------------------------------------------  // acclient.c:110837
char __thiscall CInputManager::UnregisterInputMap(CInputManager *this, unsigned int i_id, IInputActionCallback *i_pcCallback)
{
  ListNode<CInputManager::InputMapEntry> *v3; // esi@1
  List<CInputManager::InputMapEntry> *v4; // edi@1
  char result; // al@1
  ListNode<CInputManager::InputMapEntry> *v6; // eax@5

  v3 = this->m_inputMapList._head;
  v4 = &this->m_inputMapList;
  result = 0;
  while ( v3 )
  {
    if ( v3->data.m_mapID != i_id || v3->data.m_pcCallback != i_pcCallback )
    {
      v3 = v3->next;
    }
    else
    {
      v6 = v3;
      v3 = v3->next;
      List<CInputManager::InputMapEntry>::remove(v4, v6);
      result = 1;
    }
  }
  return result;
}

//----- (00431710) --------------------------------------------------------  // acclient.c:110865
void __thiscall CInputManager::UnregisterCallback(CInputManager *this, IInputActionCallback *i_pcCallback)
{
  CInputManager *v2; // edi@1
  int v3; // eax@1
  IInputActionCallback *v4; // ebp@1
  unsigned int v5; // edx@2
  IInputActionCallback *v6; // ecx@2
  ListNode<CInputManager::InputMapEntry> *v7; // esi@9
  IInputActionCallback *v8; // eax@11
  int v9; // ecx@11
  ListNode<CInputManager::InputMapEntry> *v10; // ecx@12
  bool v11; // zf@12
  int v12; // eax@12
  ListNode<CInputManager::InputMapEntry> *v13; // edx@13
  ListNode<CInputManager::InputMapEntry> *v14; // eax@19
  CInputManager::InputMapEntry entry; // [sp+10h] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashActionStates,
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&entry);
  v3 = entry.m_nPriority;
  v4 = i_pcCallback;
  if ( entry.m_nPriority )
  {
    v5 = entry.m_mapID;
    v6 = entry.m_pcCallback;
    do
    {
LABEL_3:
      if ( *(IInputActionCallback **)(v3 + 24) == i_pcCallback )
        *(_DWORD *)(v3 + 24) = 0;
      v3 = *(_DWORD *)(v3 + 4);
    }
    while ( v3 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == (IInputActionCallback *)(*(_DWORD *)(v5 + 96) + 4 * *(_DWORD *)(v5 + 104)) )
        break;
      if ( v6->vfptr )
      {
        v3 = (int)v6->vfptr;
        if ( v6->vfptr )
          goto LABEL_3;
        break;
      }
    }
  }
  v7 = v2->m_inputMapList._head;
  while ( v7 )
  {
    v8 = v7->data.m_pcCallback;
    v9 = v7->data.m_nPriority;
    entry.m_mapID = v7->data.m_mapID;
    entry.m_nPriority = v9;
    if ( v8 == v4 )
    {
      v10 = v7;
      v11 = v7 == 0;
      v12 = (int)&v7->next;
      v7 = v7->next;
      if ( !v11 )
      {
        v13 = v2->m_inputMapList._head;
        if ( v13 )
        {
          if ( v10 == v13 )
          {
            v2->m_inputMapList._head = v7;
            if ( v7 )
              v7->prev = 0;
            else
              v2->m_inputMapList._tail = 0;
            operator delete(v10);
            --v2->m_inputMapList._num_elements;
          }
          else
          {
            v10->prev->next = *(ListNode<CInputManager::InputMapEntry> **)v12;
            v14 = *(ListNode<CInputManager::InputMapEntry> **)v12;
            if ( v14 )
              v14->prev = v10->prev;
            else
              v2->m_inputMapList._tail = v10->prev;
            operator delete(v10);
            v4 = i_pcCallback;
            --v2->m_inputMapList._num_elements;
          }
        }
      }
    }
    else
    {
      v7 = v7->next;
    }
  }
}

//----- (00431810) --------------------------------------------------------  // acclient.c:110965
void __thiscall CInputManager::RegisterPreferences(CInputManager *this)
{
  CInputManager *v1; // esi@1
  char *v2; // edi@1
  char *v3; // edi@4
  char *v4; // edi@7
  char *v5; // esi@10
  PStringBase<char> _Description; // [sp+Ch] [bp-4h]@1

  _Description.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  PStringBase<char>::PStringBase<char>(&_Description, "Mouse sensitivity when user is in mouse look mode.");
  UserPreferences::RegisterPreference(
    (float *)&_Description,
    &v1->m_MouseLookSensitivity,
    &Input_MouseLookSensitivity_0,
    &_Description,
    0,
    0,
    0,
    0);
  v2 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Mouse look smoothing amount.");
  UserPreferences::RegisterPreference(
    (float *)&_Description,
    &v1->m_MouseLookSmoothingAmount,
    &Input_MouseLookSmoothingAmount_0,
    &_Description,
    0,
    0,
    0,
    0);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Invert mouse look vertical rotation?");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &v1->m_InvertMouseLookYAxis,
    &Input_InvertMouseLookYAxis_0,
    &_Description,
    0,
    0,
    0,
    0);
  v4 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Turn your character with the camera turn button?");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &v1->m_UseMouseTurning,
    &Input_UseMouseTurning_0,
    &_Description,
    0,
    0,
    0,
    0);
  v5 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (00431950) --------------------------------------------------------  // acclient.c:111034
bool __thiscall CInputManager::IsActionInProgress(CInputManager *this, unsigned int i_action)
{
  ActionState *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_hashActionStates.m_buckets[i_action % this->m_hashActionStates.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey == i_action )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (00431990) --------------------------------------------------------  // acclient.c:111056
char __thiscall SmartArray<ActionState::SingleKeyInfo,1>::add(SmartArray<ActionState::SingleKeyInfo,1> *this, ActionState::SingleKeyInfo *_data)
{
  SmartArray<ActionState::SingleKeyInfo,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<ActionState::SingleKeyInfo,1>::grow(v2, v4)) != 0) )
  {
    v2->m_data[v2->m_num++] = *_data;
    result = 1;
  }
  return result;
}

//----- (004319E0) --------------------------------------------------------  // acclient.c:111076
List<CInputHandler *> *__thiscall List<CInputHandler *>::vector_deleting_destructor(List<CInputHandler *> *this, unsigned int a2)
{
  List<CInputHandler *> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 798318: using guessed type int (__thiscall *List<CInputHandler *>::vftable[2])(void *, char);

//----- (00431A10) --------------------------------------------------------  // acclient.c:111090
List<CInputManager::InputMapEntry> *__thiscall List<CInputManager::InputMapEntry>::vector_deleting_destructor(List<CInputManager::InputMapEntry> *this, unsigned int a2)
{
  List<CInputManager::InputMapEntry> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<CInputManager::InputMapEntry>Vtbl *)&List<CInputManager::InputMapEntry>::vftable;
  List<CInputManager::InputMapEntry>::flush((List<QualifiedControl> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79831C: using guessed type int (__thiscall *List<CInputManager::InputMapEntry>::vftable)(void *, char);

//----- (00431A40) --------------------------------------------------------  // acclient.c:111104
void __thiscall CInputManager::~CInputManager(CInputManager *this)
{
  CInputManager *v1; // esi@1
  ActionMap *v2; // ecx@1
  void *v3; // eax@3

  v1 = this;
  this->vfptr = (ICIDMVtbl *)&CInputManager::vftable;
  UserPreferences::UnregisterPreference(&Input_MouseLookSensitivity_0);
  UserPreferences::UnregisterPreference(&Input_MouseLookSmoothingAmount_0);
  UserPreferences::UnregisterPreference(&Input_InvertMouseLookYAxis_0);
  UserPreferences::UnregisterPreference(&Input_UseMouseTurning_0);
  v2 = v1->m_action_map;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_action_map = 0;
  }
  v3 = v1->m_hashActionStates.m_buckets;
  v1->m_hashActionStates.vfptr = (IntrusiveHashTable<unsigned long,ActionState *,1>Vtbl *)&IntrusiveHashTable<unsigned long,ActionState *,1>::vftable;
  if ( v3 != v1->m_hashActionStates.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_hashActionStates.m_buckets = 0;
  v1->m_hashActionStates.m_firstInterestingBucket = 0;
  v1->m_hashActionStates.m_numBuckets = 0;
  v1->m_hashActionStates.m_numElements = 0;
  v1->m_inputMapList.vfptr = (List<CInputManager::InputMapEntry>Vtbl *)&List<CInputManager::InputMapEntry>::vftable;
  List<CInputManager::InputMapEntry>::flush((List<QualifiedControl> *)&v1->m_inputMapList);
  v1->m_focusSwitchList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_focusSwitchList);
  v1->m_mouseMoveList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_mouseMoveList);
  v1->m_mouseLookList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_mouseLookList);
  v1->m_characterList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_characterList);
  v1->m_actionList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_actionList);
  v1->vfptr = (ICIDMVtbl *)&ICIDM::vftable;
}
// 798268: using guessed type int (__thiscall *ICIDM::vftable)(void *, char);
// 798318: using guessed type int (__thiscall *List<CInputHandler *>::vftable[2])(void *, char);
// 79831C: using guessed type int (__thiscall *List<CInputManager::InputMapEntry>::vftable)(void *, char);
// 798330: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,ActionState *,1>::vftable)(void *, char);
// 7983E8: using guessed type int (__thiscall *CInputManager::vftable)(void *, char);

//----- (00431B30) --------------------------------------------------------  // acclient.c:111151
bool __thiscall CInputManager::GetMouseLookMode(CInputManager *this)
{
  return this->m_fWantMouseLookMode;
}

//----- (00431B40) --------------------------------------------------------  // acclient.c:111157
bool __thiscall CInputManager::GetTextMode(CInputManager *this)
{
  return this->m_textMode;
}

//----- (00431B50) --------------------------------------------------------  // acclient.c:111163
ActionMap *__thiscall CInputManager::GetActionMap(CInputManager *this)
{
  return this->m_action_map;
}

//----- (00431B60) --------------------------------------------------------  // acclient.c:111169
long double __thiscall CInputManager::GetLastInputTimestamp(CInputManager *this)
{
  return this->m_ttLastInputEvent;
}

//----- (00431B70) --------------------------------------------------------  // acclient.c:111175
char __thiscall CInputManager::RegisterInputMap(CInputManager *this, unsigned int i_id, IInputActionCallback *i_pcCallback, int i_nPriority)
{
  List<CInputManager::InputMapEntry> *v4; // esi@1
  char result; // al@2
  CInputManager::InputMapEntry inputMapEntry; // [sp+4h] [bp-Ch]@1

  v4 = &this->m_inputMapList;
  inputMapEntry.m_mapID = i_id;
  inputMapEntry.m_pcCallback = i_pcCallback;
  inputMapEntry.m_nPriority = i_nPriority;
  if ( List<CInputManager::InputMapEntry>::contains(&this->m_inputMapList, &inputMapEntry) )
    result = 0;
  else
    result = List<CInputManager::InputMapEntry>::insert_sort(v4, &inputMapEntry);
  return result;
}

//----- (00431BC0) --------------------------------------------------------  // acclient.c:111193
void __thiscall CInputManager::UseTime(CInputManager *this)
{
  CInputManager *v1; // ebp@1
  unsigned int v2; // ST00_4@1
  ActionState *v3; // esi@1
  ActionState **v4; // edi@2
  unsigned int v5; // eax@3
  unsigned int v6; // eax@6
  unsigned int v7; // ebx@12
  unsigned int v8; // ecx@13
  ActionState *v9; // esi@13
  int v10; // edx@20
  unsigned int v11; // edi@20
  int v12; // edx@20
  IInputActionCallback *v13; // ecx@20
  ICIDMVtbl *v14; // edx@20
  long double v15; // st7@21
  unsigned int v16; // ecx@22
  unsigned int v17; // eax@22
  unsigned int v18; // edi@23
  ICIDMVtbl *v19; // edx@23
  SmartArray<unsigned long,1> aActiveActions; // [sp+14h] [bp-B4h]@1
  long double timeNow; // [sp+20h] [bp-A8h]@1
  IntrusiveHashIterator<unsigned long,ActionState *,1> cur; // [sp+2Ch] [bp-9Ch]@1
  InputEvent inEvt; // [sp+38h] [bp-90h]@20
  InputEvent v24; // [sp+80h] [bp-48h]@23

  v1 = this;
  v2 = this->m_hashActionStates.m_numElements;
  timeNow = *(double *)&Timer::cur_time;
  aActiveActions.m_data = 0;
  aActiveActions.m_sizeAndDeallocate = 0;
  aActiveActions.m_num = 0;
  SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&aActiveActions, v2);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_hashActionStates,
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&cur);
  v3 = cur.m_currElement;
  if ( cur.m_currElement )
  {
    v4 = cur.m_currBucket;
    do
    {
LABEL_3:
      v5 = v3->m_toggle;
      if ( v5 >= 4 && v5 <= 5 )
      {
        if ( aActiveActions.m_num < (aActiveActions.m_sizeAndDeallocate & 0x7FFFFFFF)
          || (v6 = SmartArray<UIChildFramework *,1>::get_new_size((aActiveActions.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&aActiveActions, v6)) )
          aActiveActions.m_data[aActiveActions.m_num++] = v3->m_hashKey;
      }
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &cur.m_currHashTable->m_buckets[cur.m_currHashTable->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v3 = *v4;
        if ( *v4 )
          goto LABEL_3;
        break;
      }
    }
  }
  v7 = aActiveActions.m_num;
  while ( v7 )
  {
    v8 = aActiveActions.m_data[v7-- - 1];
    v9 = v1->m_hashActionStates.m_buckets[v8 % v1->m_hashActionStates.m_numBuckets];
    if ( v9 )
    {
      while ( v9->m_hashKey != v8 )
      {
        v9 = v9->m_hashNext;
        if ( !v9 )
          goto LABEL_24;
      }
      if ( v9 )
      {
        if ( v9->m_toggle == 4 )
        {
          v15 = CInputManager::sm_timeKeyRepeatDelay + v9->m_timeActionBegan;
          if ( timeNow >= v15 )
          {
            v16 = v9->m_cRepeatCount;
            v17 = (unsigned __int64)((timeNow - v15) / CInputManager::sm_timeKeyRepeatSpeed) + 1;
            if ( v17 > v16 )
            {
              v18 = v17 - v16;
              v9->m_cRepeatCount = v17;
              InputEvent::InputEvent(&v24, v9);
              v19 = v1->vfptr;
              v24.m_cRepeatDelta = v18;
              v24.m_fStart = 1;
              (*(void (__thiscall **)(CInputManager *, InputEvent *))&v19[1].gap4[4])(v1, &v24);
            }
          }
        }
        else if ( v9->m_toggle == 5 )
        {
          v10 = v9->m_cRepeatCount + 1;
          inEvt.m_InputAction = v9->m_hashKey;
          v9->m_cRepeatCount = v10;
          v11 = v10;
          inEvt.m_InputMapID = 0;
          inEvt.m_InputKey.m_key.m_dwKey = -1;
          inEvt.m_InputKey.m_metamode = 0;
          inEvt.m_InputKey.m_activation = 0;
          inEvt.m_InputExtent = ActionState::GetExtent(v9);
          v12 = LODWORD(v9->m_timeActionBegan);
          v13 = v9->m_pcCallback;
          HIDWORD(inEvt.m_timeActionBegan) = HIDWORD(v9->m_timeActionBegan);
          LODWORD(inEvt.m_timeActionBegan) = v12;
          v14 = v1->vfptr;
          inEvt.m_pcCallback = v13;
          inEvt.m_InputTimestamp = 0;
          inEvt.m_ToggleType = 5;
          inEvt.m_cRepeatDelta = 1;
          inEvt.m_cRepeatTotal = v11;
          inEvt.m_fStart = 1;
          (*(void (__thiscall **)(CInputManager *, InputEvent *))&v14[1].gap4[4])(v1, &inEvt);
        }
      }
    }
LABEL_24:
    ;
  }
  if ( (aActiveActions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](aActiveActions.m_data);
}
// 817A78: using guessed type double CInputManager::sm_timeKeyRepeatDelay;
// 817A80: using guessed type double CInputManager::sm_timeKeyRepeatSpeed;

//----- (00431E00) --------------------------------------------------------  // acclient.c:111332
signed int __thiscall ActionState::AddKeyPress(ActionState *this, InputEvent *io_inEvt)
{
  ActionState *v2; // esi@1
  unsigned int v3; // eax@1
  ICMDCommandEnum v4; // eax@2
  unsigned int v5; // edx@2
  signed int result; // eax@2
  char v7; // bl@3
  unsigned int v8; // edx@3
  int v9; // ecx@4
  long double v10; // st7@4
  unsigned int v11; // eax@12
  unsigned int v12; // ecx@12
  unsigned int v13; // ebx@12
  int v14; // esi@12
  int v15; // eax@12
  unsigned int v16; // eax@13
  int v17; // eax@14
  float v18; // ecx@14
  ActionState::SingleKeyInfo ski; // [sp+Ch] [bp-10h]@2
  float v20; // [sp+18h] [bp-4h]@12

  v2 = this;
  v3 = this->m_rgKeys.m_num;
  if ( v3 )
  {
    v7 = 0;
    v8 = 0;
    ski.key.m_dwKey = -1073741824;
    if ( !v3 )
      goto LABEL_19;
    do
    {
      v9 = (int)&v2->m_rgKeys.m_data[v8];
      v10 = fabs(*(float *)(v9 + 4));
      if ( v10 > *(float *)&ski.key.m_dwKey )
        *(float *)&ski.key.m_dwKey = v10;
      if ( io_inEvt->m_InputKey.m_key.m_dwKey == *(_DWORD *)v9 )
      {
        if ( *(float *)(v9 + 4) != io_inEvt->m_InputExtent )
          *(_DWORD *)(v9 + 4) = LODWORD(io_inEvt->m_InputExtent);
        v7 = 1;
      }
      ++v8;
    }
    while ( v8 < v2->m_rgKeys.m_num );
    if ( !v7 )
    {
LABEL_19:
      v11 = v2->m_rgKeys.m_sizeAndDeallocate;
      v12 = v2->m_rgKeys.m_num;
      v13 = io_inEvt->m_InputKey.m_key.m_dwKey;
      v14 = (int)&v2->m_rgKeys;
      v15 = v11 & 0x7FFFFFFF;
      v20 = io_inEvt->m_InputExtent;
      if ( v12 < v15
        || (v16 = SmartArray<UIChildFramework *,1>::get_new_size(v15 + 1),
            SmartArray<ActionState::SingleKeyInfo,1>::grow((SmartArray<ActionState::SingleKeyInfo,1> *)v14, v16)) )
      {
        v17 = *(_DWORD *)v14 + 8 * *(_DWORD *)(v14 + 8);
        v18 = v20;
        *(_DWORD *)v17 = v13;
        *(float *)(v17 + 4) = v18;
        ++*(_DWORD *)(v14 + 8);
      }
    }
    result = 1;
    if ( *(float *)&ski.key.m_dwKey >= fabs(io_inEvt->m_InputExtent) )
      result = 2;
  }
  else
  {
    v4 = (signed int)Timer::cur_time.Cmd;
    *(_QWORD *)&io_inEvt->m_timeActionBegan = Timer::cur_time;
    LODWORD(this->m_timeActionBegan) = v4;
    HIDWORD(this->m_timeActionBegan) = HIDWORD(io_inEvt->m_timeActionBegan);
    this->m_toggle = io_inEvt->m_ToggleType;
    v5 = io_inEvt->m_InputKey.m_key.m_dwKey;
    ski.extent = io_inEvt->m_InputExtent;
    ski.key.m_dwKey = v5;
    SmartArray<ActionState::SingleKeyInfo,1>::add(&this->m_rgKeys, &ski);
    v2->m_pcCallback = io_inEvt->m_pcCallback;
    result = 0;
  }
  return result;
}

//----- (00431F30) --------------------------------------------------------  // acclient.c:111420
char __thiscall IntrusiveHashTable<unsigned long,ActionState *,1>::grow(IntrusiveHashTable<unsigned long,ActionState *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,ActionState *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,ActionState *,1>::resize_internal(v2, *v3);
}

//----- (00431F80) --------------------------------------------------------  // acclient.c:111438
CInputManager *__thiscall CInputManager::scalar_deleting_destructor(CInputManager *this, unsigned int a2)
{
  CInputManager *v2; // esi@1

  v2 = this;
  CInputManager::~CInputManager(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00431FA0) --------------------------------------------------------  // acclient.c:111450
char __thiscall CInputManager::RegisterInputHandler(CInputManager *this, CInputHandler *handler, unsigned int modes)
{
  char v3; // bl@1
  CInputManager *v4; // edi@1
  ListNode<CInputHandler *> *v5; // edx@2
  List<CInputHandler *> *v6; // ecx@2
  ListNode<CInputHandler *> *v7; // eax@2
  ListNode<CInputHandler *> *v8; // edx@7
  ListNode<CInputHandler *> *v9; // eax@7
  ListNode<CInputHandler *> *v10; // edx@12
  ListNode<CInputHandler *> *v11; // eax@12
  ListNode<CInputHandler *> *v12; // edx@17
  ListNode<CInputHandler *> *v13; // eax@17
  ListNode<CInputHandler *> *v14; // edx@22
  ListNode<CInputHandler *> *v15; // eax@22
  CInputHandler *v16; // eax@27

  v3 = modes;
  v4 = this;
  if ( modes & 1 )
  {
    v5 = this->m_actionList._head;
    v6 = &this->m_actionList;
    v7 = v4->m_actionList._head;
    modes = (unsigned int)handler;
    if ( v7 )
    {
      while ( v7->data != handler )
      {
        v7 = v7->next;
        if ( !v7 )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      List<CInputHandler *>::insert(v6, v5, (CInputHandler *const *)&modes);
    }
  }
  if ( v3 & 2 )
  {
    v8 = v4->m_characterList._head;
    v9 = v4->m_characterList._head;
    modes = (unsigned int)handler;
    if ( v9 )
    {
      while ( v9->data != handler )
      {
        v9 = v9->next;
        if ( !v9 )
          goto LABEL_10;
      }
    }
    else
    {
LABEL_10:
      List<CInputHandler *>::insert(&v4->m_characterList, v8, (CInputHandler *const *)&modes);
    }
  }
  if ( v3 & 0x10 )
  {
    v10 = v4->m_mouseMoveList._head;
    v11 = v4->m_mouseMoveList._head;
    modes = (unsigned int)handler;
    if ( v11 )
    {
      while ( v11->data != handler )
      {
        v11 = v11->next;
        if ( !v11 )
          goto LABEL_15;
      }
    }
    else
    {
LABEL_15:
      List<CInputHandler *>::insert(&v4->m_mouseMoveList, v10, (CInputHandler *const *)&modes);
    }
  }
  if ( v3 & 4 )
  {
    v12 = v4->m_mouseLookList._head;
    v13 = v4->m_mouseLookList._head;
    modes = (unsigned int)handler;
    if ( v13 )
    {
      while ( v13->data != handler )
      {
        v13 = v13->next;
        if ( !v13 )
          goto LABEL_20;
      }
    }
    else
    {
LABEL_20:
      List<CInputHandler *>::insert(&v4->m_mouseLookList, v12, (CInputHandler *const *)&modes);
    }
  }
  if ( v3 & 8 )
  {
    v14 = v4->m_focusSwitchList._head;
    v15 = v4->m_focusSwitchList._head;
    modes = (unsigned int)handler;
    if ( v15 )
    {
      while ( v15->data != handler )
      {
        v15 = v15->next;
        if ( !v15 )
          goto LABEL_25;
      }
    }
    else
    {
LABEL_25:
      List<CInputHandler *>::insert(&v4->m_focusSwitchList, v14, (CInputHandler *const *)&modes);
    }
  }
  if ( v3 & 0x20 )
  {
    v16 = v4->m_pKeyHitHandler;
    if ( v16 && v16 != handler )
      return 0;
    v4->m_pKeyHitHandler = handler;
  }
  return 1;
}

//----- (004320C0) --------------------------------------------------------  // acclient.c:111581
void __thiscall IntrusiveHashTable<unsigned long,ActionState *,1>::IntrusiveHashTable<unsigned long,ActionState *,1>(IntrusiveHashTable<unsigned long,ActionState *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,ActionState *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,ActionState *,1>Vtbl *)&IntrusiveHashTable<unsigned long,ActionState *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (ActionState **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (ActionState **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 798330: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,ActionState *,1>::vftable)(void *, char);

//----- (00432150) --------------------------------------------------------  // acclient.c:111614
char __thiscall IntrusiveHashTable<unsigned long,ActionState *,1>::resize_internal(IntrusiveHashTable<unsigned long,ActionState *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,ActionState *,1> *v3; // esi@1
  char result; // al@2
  ActionState *v5; // edi@3
  int v6; // ecx@4
  ActionState **v7; // eax@5
  int v8; // eax@6
  ActionState **v9; // ebx@7
  ActionState *v10; // ecx@7
  ActionState *v11; // eax@9
  ActionState *v12; // edx@10
  ActionState *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  ActionState **v17; // eax@23
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
        if ( v3->m_firstInterestingBucket == (ActionState **)v6 )
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
            v3->m_firstInterestingBucket = (ActionState **)v8;
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
    if ( (ActionState **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<unsigned long,ActionState *,1>::resize_internal(v3, *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (ActionState **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (ActionState **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00432290) --------------------------------------------------------  // acclient.c:111730
void __thiscall CInputManager::CInputManager(CInputManager *this)
{
  CInputManager *v1; // esi@1
  unsigned int dwValue; // [sp+Ch] [bp-8h]@1
  unsigned int v3; // [sp+10h] [bp-4h]@7

  v1 = this;
  this->vfptr = (ICIDMVtbl *)&CInputManager::vftable;
  *(_QWORD *)&this->m_ttLastInputEvent = 0i64;
  this->m_fWantMouseLookMode = 0;
  this->m_fInMouseLookMode = 0;
  this->m_textMode = 0;
  this->m_lastFocus = 0;
  this->m_actionList._head = 0;
  this->m_actionList._tail = 0;
  this->m_actionList._num_elements = 0;
  this->m_actionList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  this->m_characterList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  this->m_characterList._head = 0;
  this->m_characterList._tail = 0;
  this->m_characterList._num_elements = 0;
  this->m_mouseLookList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  this->m_mouseLookList._head = 0;
  this->m_mouseLookList._tail = 0;
  this->m_mouseLookList._num_elements = 0;
  this->m_mouseMoveList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  this->m_mouseMoveList._head = 0;
  this->m_mouseMoveList._tail = 0;
  this->m_mouseMoveList._num_elements = 0;
  this->m_focusSwitchList.vfptr = (List<CInputHandler *>Vtbl *)List<CInputHandler *>::vftable;
  this->m_focusSwitchList._head = 0;
  this->m_focusSwitchList._tail = 0;
  this->m_focusSwitchList._num_elements = 0;
  this->m_inputMapList.vfptr = (List<CInputManager::InputMapEntry>Vtbl *)&List<CInputManager::InputMapEntry>::vftable;
  this->m_inputMapList._head = 0;
  this->m_inputMapList._tail = 0;
  this->m_inputMapList._num_elements = 0;
  this->m_pKeyHitHandler = 0;
  LODWORD(this->m_MouseLookSensitivity) = 1048576000;
  LODWORD(this->m_MouseLookSmoothingAmount) = 0;
  this->m_InvertMouseLookYAxis = 0;
  this->m_UseMouseTurning = 0;
  this->m_action_map = 0;
  IntrusiveHashTable<unsigned long,ActionState *,1>::IntrusiveHashTable<unsigned long,ActionState *,1>(
    &this->m_hashActionStates,
    0xAu);
  CInputManager::RegisterPreferences(v1);
  if ( SystemParametersInfoA(0x16u, 0, &dwValue, 0) )
    CInputManager::sm_timeKeyRepeatDelay = ((double)dwValue + 1.0) * 0.25;
  if ( SystemParametersInfoA(0xAu, 0, &dwValue, 0) )
  {
    if ( dwValue <= 0x1F )
    {
      if ( dwValue <= 0 )
      {
        *(_QWORD *)&CInputManager::sm_timeKeyRepeatSpeed = 4600877379321698714i64;
      }
      else
      {
        v3 = dwValue;
        CInputManager::sm_timeKeyRepeatSpeed = 0.4 - (double)dwValue * 0.01182795698924731;
      }
    }
    else
    {
      *(_QWORD *)&CInputManager::sm_timeKeyRepeatSpeed = 4584964660638322961i64;
    }
  }
}
// 798318: using guessed type int (__thiscall *List<CInputHandler *>::vftable[2])(void *, char);
// 79831C: using guessed type int (__thiscall *List<CInputManager::InputMapEntry>::vftable)(void *, char);
// 7983E8: using guessed type int (__thiscall *CInputManager::vftable)(void *, char);
// 817A78: using guessed type double CInputManager::sm_timeKeyRepeatDelay;
// 817A80: using guessed type double CInputManager::sm_timeKeyRepeatSpeed;

//----- (00432400) --------------------------------------------------------  // acclient.c:111806
char __thiscall IntrusiveHashTable<unsigned long,ActionState *,1>::add(IntrusiveHashTable<unsigned long,ActionState *,1> *this, ActionState *data)
{
  IntrusiveHashTable<unsigned long,ActionState *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  ActionState *v4; // eax@1
  unsigned int v5; // edx@6
  ActionState **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
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
      IntrusiveHashTable<unsigned long,ActionState *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (ActionState **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (ActionState **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00432480) --------------------------------------------------------  // acclient.c:111850
void __thiscall CInputManager::ToggleActionKey(CInputManager *this, InputEvent *i_inEvt)
{
  CInputManager *v2; // edi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // ebp@1
  void *v4; // eax@5

  v2 = this;
  v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_hashActionStates,
         (IDClass<_tagDataID,32,0> *)i_inEvt);
  if ( v3 )
  {
    i_inEvt->m_fStart = 0;
    (*(void (__thiscall **)(CInputManager *, InputEvent *))&v2->vfptr[1].gap4[4])(v2, i_inEvt);
    if ( (v3[4].m_hashKey.id & 0x80000000) == 0x80000000 )
      operator delete[](v3[3].m_hashNext);
    operator delete(v3);
  }
  else
  {
    v4 = operator new(0x28u);
    if ( v4 )
    {
      *(_DWORD *)v4 = i_inEvt->m_InputAction;
      *((_DWORD *)v4 + 1) = 0;
      *((_DWORD *)v4 + 2) = 0;
      *((_DWORD *)v4 + 3) = 0;
      *((_DWORD *)v4 + 4) = 0;
      *((_DWORD *)v4 + 6) = 0;
      *((_DWORD *)v4 + 7) = 0;
      *((_DWORD *)v4 + 8) = 0;
      *((_DWORD *)v4 + 9) = 0;
    }
    else
    {
      v4 = 0;
    }
    IntrusiveHashTable<unsigned long,ActionState *,1>::add(&v2->m_hashActionStates, (ActionState *)v4);
    i_inEvt->m_fStart = 1;
    (*(void (__thiscall **)(_DWORD, _DWORD))&v2->vfptr[1].gap4[4])(v2, i_inEvt);
  }
}

//----- (00432530) --------------------------------------------------------  // acclient.c:111894
void __thiscall CInputManager::DeactivateActionKey(CInputManager *this, InputEvent *i_inEvt)
{
  CInputManager *v2; // ebx@1
  ActionState *v3; // esi@1
  int v4; // eax@6

  v2 = this;
  v3 = v2->m_hashActionStates.m_buckets[i_inEvt->m_InputAction % v2->m_hashActionStates.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey != i_inEvt->m_InputAction )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      v4 = ActionState::RemoveKeyPress(v3, i_inEvt) - 1;
      if ( v4 )
      {
        if ( v4 == 2 )
        {
          IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
            (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&v2->m_hashActionStates,
            (IDClass<_tagDataID,32,0> *)i_inEvt);
          i_inEvt->m_fStart = 0;
          (*(void (__thiscall **)(CInputManager *, InputEvent *))&v2->vfptr[1].gap4[4])(v2, i_inEvt);
          if ( (v3->m_rgKeys.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
            operator delete[](v3->m_rgKeys.m_data);
          operator delete(v3);
        }
      }
      else
      {
        i_inEvt->m_fStart = 1;
        (*(void (__thiscall **)(CInputManager *, InputEvent *))&v2->vfptr[1].gap4[4])(v2, i_inEvt);
      }
    }
  }
}

//----- (004325E0) --------------------------------------------------------  // acclient.c:111937
void __thiscall CInputManager::TurnOffRunLock(CInputManager *this)
{
  CInputManager *v1; // edi@1
  ActionState *v2; // eax@1
  ActionState *v3; // esi@1
  ICIDMVtbl *v4; // eax@2
  InputEvent evt; // [sp+8h] [bp-48h]@2

  v1 = this;
  v2 = (ActionState *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
                        (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_hashActionStates,
                        &MovementRunLock);
  v3 = v2;
  if ( v2 )
  {
    InputEvent::InputEvent(&evt, v2);
    v4 = v1->vfptr;
    LODWORD(evt.m_InputExtent) = 0;
    evt.m_fStart = 0;
    (*(void (__thiscall **)(CInputManager *, InputEvent *))&v4[1].gap4[4])(v1, &evt);
    if ( (v3->m_rgKeys.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](v3->m_rgKeys.m_data);
    operator delete(v3);
  }
}

//----- (00432650) --------------------------------------------------------  // acclient.c:111964
void __thiscall CInputManager::ActivateActionKey(CInputManager *this, InputEvent *i_inEvt)
{
  IntrusiveHashTable<unsigned long,ActionState *,1> *v2; // edi@1
  ActionState *i; // eax@1
  ActionState *v4; // esi@4
  void *v5; // eax@5
  signed int v6; // eax@9
  CInputManager *v7; // esi@11
  unsigned int v8; // eax@14
  CInputManager *v9; // [sp+10h] [bp-4h]@1

  v2 = &this->m_hashActionStates;
  v9 = this;
  for ( i = this->m_hashActionStates.m_buckets[i_inEvt->m_InputAction % this->m_hashActionStates.m_numBuckets];
        i;
        i = i->m_hashNext )
  {
    if ( i->m_hashKey == i_inEvt->m_InputAction )
      break;
  }
  v4 = i;
  if ( !i )
  {
    v5 = operator new(0x28u);
    if ( v5 )
    {
      *(_DWORD *)v5 = i_inEvt->m_InputAction;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = 0;
      *((_DWORD *)v5 + 6) = 0;
      *((_DWORD *)v5 + 7) = 0;
      *((_DWORD *)v5 + 8) = 0;
      *((_DWORD *)v5 + 9) = 0;
      v4 = (ActionState *)v5;
    }
    else
    {
      v4 = 0;
    }
    IntrusiveHashTable<unsigned long,ActionState *,1>::add(v2, v4);
  }
  v6 = ActionState::AddKeyPress(v4, i_inEvt);
  if ( v6 )
  {
    if ( v6 != 1 )
      return;
  }
  else
  {
    v8 = i_inEvt->m_InputAction;
    if ( i_inEvt->m_InputAction == 41 || v8 == 42 || v8 == 43 )
    {
      v7 = v9;
      CInputManager::TurnOffRunLock(v9);
      goto LABEL_12;
    }
  }
  v7 = v9;
LABEL_12:
  i_inEvt->m_fStart = 1;
  (*(void (__thiscall **)(CInputManager *, InputEvent *))&v7->vfptr[1].gap4[4])(v7, i_inEvt);
}

//----- (00432720) --------------------------------------------------------  // acclient.c:112030
void __thiscall CInputManager::FireActionEvent(CInputManager *this, InputEvent *i_inEvt)
{
  CInputManager *v2; // edi@1
  ActionMap *v3; // ecx@1
  unsigned int v4; // eax@2
  unsigned int v5; // eax@4

  v2 = this;
  v3 = this->m_action_map;
  if ( v3 )
  {
    v4 = ActionMap::GetToggleType(v3, i_inEvt->m_InputAction, i_inEvt->m_InputMapID);
    i_inEvt->m_ToggleType = v4;
    if ( !v4 )
      i_inEvt->m_ToggleType = 3;
    v5 = i_inEvt->m_ToggleType;
    if ( i_inEvt->m_InputExtent == 0.0 )
    {
      if ( v5 == 1 || v5 > 3 && v5 <= 5 )
        CInputManager::DeactivateActionKey(v2, i_inEvt);
    }
    else
    {
      switch ( v5 )
      {
        case 2u:
          CInputManager::ToggleActionKey(v2, i_inEvt);
          break;
        case 3u:
          CInputManager::StartAction(v2, i_inEvt);
          break;
        case 1u:
          CInputManager::ActivateActionKey(v2, i_inEvt);
          if ( !(i_inEvt->m_InputKey.m_activation & 0xA9) )
            CInputManager::DeactivateActionKey(v2, i_inEvt);
          break;
        default:
          CInputManager::ActivateActionKey(v2, i_inEvt);
          break;
      }
    }
  }
}
// 795344: using guessed type float FLOAT_0_0;

//----- (00676B80) --------------------------------------------------------  // acclient.c:653356
void __thiscall ActionState::SingleKeyInfo::SingleKeyInfo(ActionState::SingleKeyInfo *this)
{
  this->key.m_dwKey = -1;
}

//----- (006C5A10) --------------------------------------------------------  // acclient.c:733945
int _E73_25()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_2, "Display.Resolution");
  return atexit(_E74_27);
}

//----- (006C5A30) --------------------------------------------------------  // acclient.c:733952
int _E76_15()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_2, "Display.FullScreen");
  return atexit(_E77_43);
}

//----- (006C5A50) --------------------------------------------------------  // acclient.c:733959
int _E79_15()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_2, "Display.RefreshRate");
  return atexit(_E80_17);
}

//----- (006C5A70) --------------------------------------------------------  // acclient.c:733966
int _E82_6()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_2, "Display.SyncToRefresh");
  return atexit(_E83_7);
}

//----- (006C5A90) --------------------------------------------------------  // acclient.c:733973
void _E85_3()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_3, PFID_A8R8G8B8);
}

//----- (006C5AA0) --------------------------------------------------------  // acclient.c:733979
int _E103_5()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSensitivity_0, "Input.MouseLookSensitivity");
  return atexit(_E104_28);
}

//----- (006C5AC0) --------------------------------------------------------  // acclient.c:733986
int _E106_7()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSmoothingAmount_0, "Input.MouseLookSmoothingAmount");
  return atexit(_E107_60);
}

//----- (006C5AE0) --------------------------------------------------------  // acclient.c:733993
int _E109_4()
{
  PStringBase<char>::PStringBase<char>(&Input_InvertMouseLookYAxis_0, "Input.InvertMouseLookYAxis");
  return atexit(sub_7286B0);
}

//----- (006C5B00) --------------------------------------------------------  // acclient.c:734000
int _E112_6()
{
  PStringBase<char>::PStringBase<char>(&Input_UseMouseTurning_0, "Input.UseMouseTurning");
  return atexit(_E113_40);
}

//----- (006C5B20) --------------------------------------------------------  // acclient.c:734007
int _E115_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_3, "None");
  return atexit(_E116_32);
}

//----- (006C5B40) --------------------------------------------------------  // acclient.c:734014
int _E118_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_3, "Speed");
  return atexit(_E119_57);
}

//----- (006C5B60) --------------------------------------------------------  // acclient.c:734021
int _E121_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_3, "Noise");
  return atexit(_E122_44);
}

//----- (006C5B80) --------------------------------------------------------  // acclient.c:734028
int _E124_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_3, "Sine");
  return atexit(_E125_20);
}

//----- (006C5BA0) --------------------------------------------------------  // acclient.c:734035
int _E127_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_3, "Square");
  return atexit(_E128_21);
}

//----- (006C5BC0) --------------------------------------------------------  // acclient.c:734042
int _E130_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_3, "Bounce");
  return atexit(_E131_17);
}

//----- (006C5BE0) --------------------------------------------------------  // acclient.c:734049
int _E133_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_3, "Perlin");
  return atexit(_E134_16);
}

//----- (006C5C00) --------------------------------------------------------  // acclient.c:734056
int _E136_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_3, "Fractal");
  return atexit(_E137_16);
}

//----- (006C5C20) --------------------------------------------------------  // acclient.c:734063
int _E139_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_3, "FrameLoop");
  return atexit(_E140_11);
}

//----- (006C5C40) --------------------------------------------------------  // acclient.c:734070
unsigned int _E142_3()
{
  unsigned int result; // eax@1

  result = Logger::CreateLoggingCategory("InputManager");
  lcat_InputManager = result;
  return result;
}
// 837080: using guessed type unsigned __int32 lcat_InputManager;

//----- (00728590) --------------------------------------------------------  // acclient.c:826190
void __cdecl _E74_27()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007285C0) --------------------------------------------------------  // acclient.c:826203
void __cdecl _E77_43()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007285F0) --------------------------------------------------------  // acclient.c:826216
void __cdecl _E80_17()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728620) --------------------------------------------------------  // acclient.c:826229
void __cdecl _E83_7()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728650) --------------------------------------------------------  // acclient.c:826242
void __cdecl _E104_28()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSensitivity_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSensitivity_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728680) --------------------------------------------------------  // acclient.c:826255
void __cdecl _E107_60()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSmoothingAmount_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSmoothingAmount_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007286B0) --------------------------------------------------------  // acclient.c:826268
void __cdecl sub_7286B0()
{
  char *v0; // esi@1

  v0 = &Input_InvertMouseLookYAxis_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_InvertMouseLookYAxis_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007286E0) --------------------------------------------------------  // acclient.c:826281
void __cdecl _E113_40()
{
  char *v0; // esi@1

  v0 = &Input_UseMouseTurning_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_UseMouseTurning_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728710) --------------------------------------------------------  // acclient.c:826294
void __cdecl _E116_32()
{
  char *v0; // esi@1

  v0 = &waveform_None_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728740) --------------------------------------------------------  // acclient.c:826307
void __cdecl _E119_57()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728770) --------------------------------------------------------  // acclient.c:826320
void __cdecl _E122_44()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007287A0) --------------------------------------------------------  // acclient.c:826333
void __cdecl _E125_20()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007287D0) --------------------------------------------------------  // acclient.c:826346
void __cdecl _E128_21()
{
  char *v0; // esi@1

  v0 = &waveform_Square_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728800) --------------------------------------------------------  // acclient.c:826359
void __cdecl _E131_17()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728830) --------------------------------------------------------  // acclient.c:826372
void __cdecl _E134_16()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728860) --------------------------------------------------------  // acclient.c:826385
void __cdecl _E137_16()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728890) --------------------------------------------------------  // acclient.c:826398
void __cdecl _E140_11()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

