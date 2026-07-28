/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmKeyboardUI
   Object     : GAME\game_ui_misc\gmKeyboardUI.obj
   Functions  : 105
   Addresses  : 00448B90 - 00762AE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00448B90) --------------------------------------------------------  // acclient.c:133281
void __thiscall HashList<ControlSpecification,unsigned long,1>::flush(HashList<unsigned long,ActionMapValue,1> *this)
{
  HashList<unsigned long,ActionMapValue,1> *v1; // edi@1
  void *v2; // ebp@2
  DLListData *v3; // eax@3
  DLListData *v4; // ecx@4
  DLListData *v5; // ecx@6
  bool v6; // zf@6
  DLListData *v7; // ecx@10
  int v8; // edx@14
  HashList<unsigned long,ActionMapValue,1>::HashListData **v9; // eax@14
  HashList<unsigned long,ActionMapValue,1>::HashListData *v10; // ecx@14
  int v11; // ebx@14
  HashList<unsigned long,ActionMapValue,1>::HashListData *v12; // eax@14
  HashList<unsigned long,ActionMapValue,1>::HashListData *v13; // edx@20

  v1 = this;
LABEL_2:
  while ( 1 )
  {
    v2 = 0;
    if ( !v1->m_ihlIntrusive.m_hash.m_numElements )
      break;
    v3 = v1->m_ihlIntrusive.m_list.head_;
    if ( v3 )
    {
      v4 = v3->dllist_prev;
      if ( v4 )
      {
        v4->dllist_next = v3->dllist_next;
      }
      else
      {
        v5 = v3->dllist_next;
        v6 = v3->dllist_next == 0;
        v1->m_ihlIntrusive.m_list.head_ = v3->dllist_next;
        if ( !v6 )
          v5->dllist_prev = 0;
      }
      if ( v3->dllist_next )
      {
        v3->dllist_next->dllist_prev = v3->dllist_prev;
      }
      else
      {
        v7 = v1->m_ihlIntrusive.m_list.tail_->dllist_prev;
        v1->m_ihlIntrusive.m_list.tail_ = v7;
        if ( v7 )
          v7->dllist_next = 0;
      }
      v3->dllist_next = 0;
      v3->dllist_prev = 0;
      if ( v3 )
        v2 = &v3[-1];
    }
    v8 = *(_DWORD *)v2 % v1->m_ihlIntrusive.m_hash.m_numBuckets;
    v9 = v1->m_ihlIntrusive.m_hash.m_buckets;
    v10 = v9[v8];
    v11 = (int)&v9[v8];
    v12 = v9[v8];
    if ( v12 )
    {
      while ( v12->m_hashKey != *(_DWORD *)v2 )
      {
        v12 = v12->m_hashNext;
        if ( !v12 )
        {
          operator delete(v2);
          goto LABEL_2;
        }
      }
      if ( v12 )
      {
        if ( v10 == v12 )
          goto LABEL_28;
        do
        {
          v13 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v12 );
        if ( v13 )
          v13->m_hashNext = v10->m_hashNext;
        else
LABEL_28:
          *(_DWORD *)v11 = v10->m_hashNext;
        --v1->m_ihlIntrusive.m_hash.m_numElements;
      }
    }
    operator delete(v2);
  }
}

//----- (004DA850) --------------------------------------------------------  // acclient.c:265276
char __thiscall gmKeyboardUI::RestoreDefaultValues(gmKeyboardUI *this)
{
  CInputManager *v1; // esi@1
  OptionPage *v2; // edi@1

  v1 = ICIDM::s_cidm;
  v2 = (OptionPage *)this;
  if ( ICIDM::s_cidm )
  {
    ICIDM::s_cidm->vfptr->ClearKeyMap((ICIDM *)ICIDM::s_cidm);
    ((void (__thiscall *)(CInputManager *, signed int))v1->vfptr->AddKeyMap)(v1, 268435457);
    ((void (__thiscall *)(_DWORD, signed int))v1->vfptr->AddKeyMap)(v1, 1);
  }
  return OptionPage::RestoreDefaultValues(v2);
}

//----- (004DA890) --------------------------------------------------------  // acclient.c:265293
void __thiscall gmKeyboardUI::OnOptionChanged(gmKeyboardUI *this, UIOption *pOption)
{
  gmKeyboardUI *v2; // esi@1
  char v3; // al@2
  HashSetData<UIElement *> *v4; // ecx@2

  v2 = this;
  if ( this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] )
  {
    v3 = OptionPage::Changed((OptionPage *)&this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[3]);
    v4 = v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6];
    if ( v3 )
      ((void (__stdcall *)(signed int))v4->m_hashKey->m_alphaImage)(1);
    else
      ((void (__stdcall *)(signed int))v4->m_hashKey->m_alphaImage)(13);
  }
}

//----- (004DA8E0) --------------------------------------------------------  // acclient.c:265312
PStringBase<char> *__stdcall gmKeyboardUI::GetKeymapDirectory(PStringBase<char> *result)
{
  PSRefBufferCharData<char> *v2; // eax@1
  char *v3; // esi@1
  char *v4; // esi@4
  PStringBase<char> strKeymapDir; // [sp+Ch] [bp-8h]@1
  PStringBase<char> strPreferenceFile; // [sp+10h] [bp-4h]@1

  strPreferenceFile.m_charbuffer = UserPreferences::sm_strDefaultFile.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]);
  strKeymapDir.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PSUtils::get_directory(&strKeymapDir, &strPreferenceFile);
  v2 = strKeymapDir.m_charbuffer;
  result->m_charbuffer = strKeymapDir.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
  v3 = &strKeymapDir.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strKeymapDir.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return result;
}

//----- (004DA980) --------------------------------------------------------  // acclient.c:265338
StringInfo *__stdcall gmKeyboardUI::GetStringInfoFromInputMapID(StringInfo *result, unsigned int i_eInputMap)
{
  unsigned int v3; // eax@4
  StringInfo copy; // [sp+0h] [bp-90h]@1

  StringInfo::StringInfo(&copy);
  if ( i_eInputMap > 0x10000002 )
  {
    switch ( i_eInputMap )
    {
      case 0x10000003u:
        v3 = Tokenize("ID_InputMap_MeleeCombat");
        goto LABEL_24;
      case 0x10000004u:
        v3 = Tokenize("ID_InputMap_MissileCombat");
        goto LABEL_24;
      case 0x10000005u:
        v3 = Tokenize("ID_InputMap_MagicCombat");
        goto LABEL_24;
      case 0x10000006u:
        v3 = Tokenize("ID_InputMap_Emotes");
        goto LABEL_24;
      case 0x10000007u:
        v3 = Tokenize("ID_InputMap_ItemSelectionCommands");
        goto LABEL_24;
      case 0x1000000Cu:
        v3 = Tokenize("ID_InputMap_QuickslotCommands");
        goto LABEL_24;
      case 0x10000008u:
        v3 = Tokenize("ID_InputMap_CharacterOptionCommands");
        goto LABEL_24;
      case 0x10000009u:
        v3 = Tokenize("ID_InputMap_UICommands");
        goto LABEL_24;
      case 0x1000000Du:
        v3 = Tokenize("ID_InputMap_ToggleChatEntry");
        goto LABEL_24;
      case 0x1000000Au:
        v3 = Tokenize("ID_InputMap_ChatCommands");
        goto LABEL_24;
      default:
        break;
    }
  }
  else if ( i_eInputMap == 268435458 )
  {
    v3 = compute_str_hash("ID_InputMap_Combat");
LABEL_24:
    StringInfo::SetStringIDandTableEnum(&copy, v3, 7);
  }
  else
  {
    switch ( i_eInputMap )
    {
      case 4u:
        v3 = Tokenize("ID_InputMap_MovementCommands");
        goto LABEL_24;
      case 5u:
        v3 = Tokenize("ID_InputMap_CameraControls");
        goto LABEL_24;
      case 6u:
        v3 = Tokenize("ID_InputMap_CameraAlternateControls");
        goto LABEL_24;
      case 9u:
        v3 = Tokenize("ID_InputMap_DialogBoxes");
        goto LABEL_24;
      case 0xBu:
        v3 = Tokenize("ID_InputMap_DebugConsole");
        goto LABEL_24;
      case 0xCu:
        v3 = Tokenize("ID_InputMap_ProfilerUI");
        goto LABEL_24;
      case 0xDu:
        v3 = Tokenize("ID_InputMap_UIDebugger");
        goto LABEL_24;
      case 0xEu:
        v3 = Tokenize("ID_InputMap_DebugCommands");
        goto LABEL_24;
      default:
        break;
    }
  }
  StringInfo::StringInfo(result, &copy);
  StringInfo::~StringInfo(&copy);
  return result;
}

//----- (004DAB20) --------------------------------------------------------  // acclient.c:265426
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0> *v2; // esi@1
  HashTableData<unsigned long,UIElement_ListBox *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable;
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
// 7BE668: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable[5])(void *, char);

//----- (004DAB60) --------------------------------------------------------  // acclient.c:265447
IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *__thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,ActionMapValue,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
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
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (004DABA0) --------------------------------------------------------  // acclient.c:265468
IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *__thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,List<unsigned long>,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable;
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
// 7BE670: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (004DABE0) --------------------------------------------------------  // acclient.c:265489
IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *__thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::vftable;
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
// 7BE674: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::vftable[2])(void *, char);

//----- (004DAC20) --------------------------------------------------------  // acclient.c:265510
void __thiscall gmKeyboardUI::HandleCloseLoadKeymapDialog(gmKeyboardUI *this, unsigned int i_uiMenuChoice)
{
  gmKeyboardUI *v2; // esi@1
  ListNode<PStringBase<char> > *v3; // eax@2
  int v4; // ecx@4

  v2 = this;
  this->m_uiLoadKeymapDialogContext = 0;
  if ( i_uiMenuChoice != -1 )
  {
    v3 = this->m_listCachedKeymapFilenames._head;
    if ( v3 )
    {
      if ( i_uiMenuChoice < this->m_listCachedKeymapFilenames._num_elements )
      {
        v4 = 0;
        while ( v4 != i_uiMenuChoice )
        {
          if ( v3 )
            v3 = v3->next;
          ++v4;
          if ( !v3 )
            return;
        }
        if ( v3 && *(_DWORD *)&v3->data.m_charbuffer[-1].m_data[12] != 1 && Client::m_instance )
        {
          ((void (__stdcall *)(ListNode<PStringBase<char> > *))Client::m_instance->vfptr[6].IUnknown_QueryInterface)(v3);
          ((void (__thiscall *)(gmKeyboardUI *))v2->vfptr[27].__vecDelDtor)(v2);
        }
      }
    }
  }
}

//----- (004DACA0) --------------------------------------------------------  // acclient.c:265545
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::grow(IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (004DACF0) --------------------------------------------------------  // acclient.c:265565
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,UIElement_ListBox *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,UIElement_ListBox *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7BE668: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable[5])(void *, char);

//----- (004DAD80) --------------------------------------------------------  // acclient.c:265598
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<unsigned long,ActionMapValue,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<unsigned long,ActionMapValue,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);

//----- (004DAE10) --------------------------------------------------------  // acclient.c:265631
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>(IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<unsigned long,List<unsigned long>,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<unsigned long,List<unsigned long>,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7BE670: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (004DAEA0) --------------------------------------------------------  // acclient.c:265664
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7BE674: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::vftable[2])(void *, char);

//----- (004DAF30) --------------------------------------------------------  // acclient.c:265697
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<unsigned long,ActionMapValue,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<unsigned long,ActionMapValue,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<unsigned long,ActionMapValue,1>::HashListData **v8; // edi@7
  HashList<unsigned long,ActionMapValue,1>::HashListData *v9; // ecx@7
  HashList<unsigned long,ActionMapValue,1>::HashListData *v10; // eax@9
  HashList<unsigned long,ActionMapValue,1>::HashListData *v11; // edx@10
  HashList<unsigned long,ActionMapValue,1>::HashListData *v12; // eax@17
  HashList<unsigned long,ActionMapValue,1>::HashListData *v13; // edi@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashList<unsigned long,ActionMapValue,1>::HashListData **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashList<unsigned long,ActionMapValue,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::add_internal(
          v2,
          v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004DB000) --------------------------------------------------------  // acclient.c:265794
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<unsigned long,List<unsigned long>,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<unsigned long,List<unsigned long>,1>::HashListData **v8; // ecx@7
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v9; // edi@7
  _BYTE v10[12]; // ST08_12@9
  unsigned int v11; // ST10_4@12
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v12; // edi@12
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v13; // ebp@13
  unsigned int *v14; // ebx@14
  unsigned int *v15; // eax@14
  int v16; // eax@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        *(_QWORD *)&v10[4] = __PAIR__((unsigned int)v9, (unsigned int)v8);
        *(_DWORD *)v10 = v2;
        IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
          (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v2,
          *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v10);
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v11 = _numBuckets;
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      v11);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v2->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::resize_internal(
            v2,
            *v15);
        }
        v16 = (int)&v2->m_buckets[v12->m_hashKey % v2->m_numBuckets];
        v12->m_hashNext = *(HashList<unsigned long,List<unsigned long>,1>::HashListData **)v16;
        *(_DWORD *)v16 = v12;
        if ( (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v16 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v16;
        ++v2->m_numElements;
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004DB130) --------------------------------------------------------  // acclient.c:265899
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v8; // edi@7
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v9; // ecx@7
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v10; // eax@9
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v11; // edx@10
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v12; // eax@17
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v13; // edi@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::add_internal(
          v2,
          v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004DB200) --------------------------------------------------------  // acclient.c:265996
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::grow(IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (004DB250) --------------------------------------------------------  // acclient.c:266016
CInputMap *__thiscall CMasterInputMap::GetInputMapByID(CMasterInputMap *this, unsigned int id)
{
  HashList<unsigned long,CInputMap *,1>::HashListData *v2; // eax@1
  CInputMap *result; // eax@4

  v2 = this->m_hashSections.m_ihlIntrusive.m_hash.m_buckets[id % this->m_hashSections.m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != id )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = v2->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (004DB290) --------------------------------------------------------  // acclient.c:266039
void __thiscall gmKeyboardUI::UpdateKeymapFilenameLabel(gmKeyboardUI *this)
{
  gmKeyboardUI *v1; // esi@1
  char *v2; // esi@3
  PStringBase<unsigned short> strKeymapFile; // [sp+0h] [bp-4h]@1

  strKeymapFile.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  if ( this->m_pKeyboardCurrentKeymapLabel )
  {
    if ( Client::m_instance )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&strKeymapFile, 0, &Client::m_instance->m_strKeymapFile);
      UIElement_Text::SetText(v1->m_pKeyboardCurrentKeymapLabel, &strKeymapFile);
      v2 = (char *)&strKeymapFile.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strKeymapFile.m_charbuffer[-1].m_data[8]) )
      {
        if ( v2 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
      }
    }
  }
}

//----- (004DB2F0) --------------------------------------------------------  // acclient.c:266064
UIOption_ActionKeyMap *__thiscall gmKeyboardUI::AddActionKeyMap(gmKeyboardUI *this, UIElement_ListBox *i_pListBox, unsigned int i_idAction, unsigned int i_idInputMap, StringInfo *i_siName, StringInfo *i_siDescription, List<QualifiedControl> i_qclDefaults)
{
  OptionPage *v7; // edi@1
  UIOption_ActionKeyMap *result; // eax@2
  UIOption_ActionKeyMap *v9; // esi@3
  int v10; // eax@3
  int v11; // eax@4

  v7 = (OptionPage *)this;
  if ( i_pListBox )
  {
    v9 = 0;
    v10 = UIElement_ListBox::AddItemFromTemplateList(i_pListBox, 1u, 0);
    if ( v10 )
    {
      v11 = (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v10 + 148))(v10, 268435508);
      if ( v11 )
      {
        v9 = (UIOption_ActionKeyMap *)(v11 - 32);
        if ( v11 != 32 )
        {
          UIOption_ActionKeyMap::Init(v9, i_idAction, i_idInputMap, i_siName, i_siDescription, &i_qclDefaults);
          OptionPage::RegisterOption(v7, (UIOption *)&v9->vfptr);
        }
      }
      else
      {
        v9 = 0;
      }
    }
    i_qclDefaults.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
    List<CInputManager::InputMapEntry>::flush(&i_qclDefaults);
    result = v9;
  }
  else
  {
    i_qclDefaults.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
    List<CInputManager::InputMapEntry>::flush(&i_qclDefaults);
    result = 0;
  }
  return result;
}
// 7A2BE8: using guessed type int (__thiscall *List<QualifiedControl>::vftable)(void *, char);

//----- (004DB380) --------------------------------------------------------  // acclient.c:266109
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::add(IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this, HashList<unsigned long,List<unsigned long>,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<unsigned long,List<unsigned long>,1>::HashListData **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (004DB400) --------------------------------------------------------  // acclient.c:266153
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::grow(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::resize_internal(
           v2,
           *v3);
}

//----- (004DB450) --------------------------------------------------------  // acclient.c:266173
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::add_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this, HashList<unsigned long,ActionMapValue,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,ActionMapValue,1>::HashListData **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::grow(this);
  v3 = &v2->m_buckets[data->m_hashKey % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (004DB490) --------------------------------------------------------  // acclient.c:266190
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::place_at_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this, HashList<unsigned long,List<unsigned long>,1>::HashListData *pMoving)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v3; // eax@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[pMoving->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != pMoving->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::add(
      &this->m_hash,
      pMoving);
  DLListBase::InsertAfter(&v2->m_list, (DLListData *)&pMoving->dllist_next, v2->m_list.tail_);
  return 1;
}

//----- (004DB4F0) --------------------------------------------------------  // acclient.c:266217
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::add(IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this, HashList<unsigned long,ActionMapValue,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<unsigned long,ActionMapValue,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<unsigned long,ActionMapValue,1>::HashListData **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<unsigned long,ActionMapValue,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (004DB570) --------------------------------------------------------  // acclient.c:266261
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::place_at_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this, HashList<unsigned long,ActionMapValue,1>::HashListData *pMoving)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,ActionMapValue,1>::HashListData *v3; // eax@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[pMoving->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != pMoving->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::add(
      &this->m_hash,
      pMoving);
  DLListBase::InsertAfter(&v2->m_list, (DLListData *)&pMoving->dllist_next, v2->m_list.tail_);
  return 1;
}

//----- (004DB5D0) --------------------------------------------------------  // acclient.c:266288
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::push_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this, HashList<unsigned long,List<unsigned long>,1>::HashListData *val)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v3; // eax@1
  char result; // al@4

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::add(
      &this->m_hash,
      val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (004DB630) --------------------------------------------------------  // acclient.c:266321
char __thiscall HashList<unsigned long,List<unsigned long>,1>::move_to_tail(HashList<unsigned long,List<unsigned long>,1> *this, const unsigned int *keyToMove)
{
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[*keyToMove % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey != *keyToMove )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::place_at_tail(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (004DB680) --------------------------------------------------------  // acclient.c:266346
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::add_internal(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this, HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::grow(this);
  v3 = &v2->m_buckets[data->m_hashKey % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (004DB6C0) --------------------------------------------------------  // acclient.c:266363
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::push_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this, HashList<unsigned long,ActionMapValue,1>::HashListData *val)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,ActionMapValue,1>::HashListData *v3; // eax@1
  char result; // al@4

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::add(
      &this->m_hash,
      val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (004DB720) --------------------------------------------------------  // acclient.c:266396
char __thiscall HashList<unsigned long,ActionMapValue,1>::move_to_tail(HashList<unsigned long,ActionMapValue,1> *this, const unsigned int *keyToMove)
{
  HashList<unsigned long,ActionMapValue,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[*keyToMove % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey != *keyToMove )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::place_at_tail(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (004DB770) --------------------------------------------------------  // acclient.c:266421
void __thiscall gmKeyboardUI::PostInit(gmKeyboardUI *this)
{
  gmKeyboardUI *v1; // esi@1
  GlobalEventHandler *v2; // eax@1
  int v3; // ecx@3
  UIElement *v4; // eax@6
  UIElement *v5; // eax@7
  UIElement_ListBox *v6; // eax@8
  UIElement *v7; // eax@12
  UIElement *v8; // eax@13
  UIElement_ListBox *v9; // eax@14
  UIElement *v10; // eax@18
  UIElement *v11; // eax@19
  UIElement_ListBox *v12; // eax@20
  UIElement *v13; // eax@24
  UIElement *v14; // eax@25
  UIElement_ListBox *v15; // eax@26
  UIElement *v16; // eax@30
  UIElement *v17; // eax@31
  UIElement_ListBox *v18; // eax@32
  UIElement *v19; // eax@36
  UIElement *v20; // eax@37
  UIElement_ListBox *v21; // eax@38
  UIElement *v22; // eax@43
  int v23; // eax@44
  UIElement *v24; // eax@48
  int v25; // eax@49
  UIElement *v26; // eax@53
  int v27; // eax@54
  UIElement *v28; // eax@58
  int v29; // eax@59
  UIElement *v30; // eax@63
  int v31; // eax@64
  UIElement *v32; // eax@68
  int v33; // eax@69
  UIElement *v34; // eax@73
  int v35; // eax@74
  unsigned int eElementID; // [sp+8h] [bp-Ch]@5
  UIElement_ListBox *pListBox; // [sp+Ch] [bp-8h]@10
  unsigned int eListBoxID; // [sp+10h] [bp-4h]@5

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100004u, (NoticeHandler *)v3);
    eElementID = 0;
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000018u, &eListBoxID) )
    {
      v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000049Du);
      if ( v4 )
      {
        v5 = UIElement::GetChildRecursive(v4, eListBoxID);
        v6 = (UIElement_ListBox *)(v5 ? v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)5) : 0);
        pListBox = v6;
        if ( v6 )
          HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
            (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_hashMappingListBoxes,
            &Movement,
            (RenderVertexStreamD3D *const *)&pListBox);
      }
      v7 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000049Fu);
      if ( v7 )
      {
        v8 = UIElement::GetChildRecursive(v7, eListBoxID);
        v9 = (UIElement_ListBox *)(v8 ? v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)5) : 0);
        pListBox = v9;
        if ( v9 )
          HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
            (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_hashMappingListBoxes,
            &Camera,
            (RenderVertexStreamD3D *const *)&pListBox);
      }
      v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100004A1u);
      if ( v10 )
      {
        v11 = UIElement::GetChildRecursive(v10, eListBoxID);
        v12 = (UIElement_ListBox *)(v11 ? v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)5) : 0);
        pListBox = v12;
        if ( v12 )
          HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
            (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_hashMappingListBoxes,
            &Combat,
            (RenderVertexStreamD3D *const *)&pListBox);
      }
      v13 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100004A3u);
      if ( v13 )
      {
        v14 = UIElement::GetChildRecursive(v13, eListBoxID);
        v15 = (UIElement_ListBox *)(v14 ? v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)5) : 0);
        pListBox = v15;
        if ( v15 )
          HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
            (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_hashMappingListBoxes,
            &UI,
            (RenderVertexStreamD3D *const *)&pListBox);
      }
      v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000211u);
      if ( v16 )
      {
        v17 = UIElement::GetChildRecursive(v16, eListBoxID);
        v18 = (UIElement_ListBox *)(v17 ? v17->vfptr[12].OnAction((IInputActionCallback *)v17, (InputEvent *)5) : 0);
        pListBox = v18;
        if ( v18 )
          HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
            (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_hashMappingListBoxes,
            &CharacterSettings,
            (RenderVertexStreamD3D *const *)&pListBox);
      }
      v19 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100004A5u);
      if ( v19 )
      {
        v20 = UIElement::GetChildRecursive(v19, eListBoxID);
        v21 = (UIElement_ListBox *)(v20 ? v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)5) : 0);
        pListBox = v21;
        if ( v21 )
          HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
            (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_hashMappingListBoxes,
            &Emote_0,
            (RenderVertexStreamD3D *const *)&pListBox);
      }
    }
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000001Eu, &eElementID) )
    {
      v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eElementID);
      if ( v22 )
        v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)1);
      else
        v23 = 0;
      v1->m_pKeyboardLoadKeymapButton = (UIElement_Button *)v23;
    }
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000001Fu, &eElementID) )
    {
      v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eElementID);
      if ( v24 )
        v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)1);
      else
        v25 = 0;
      v1->m_pKeyboardSaveKeymapButton = (UIElement_Button *)v25;
    }
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000001Du, &eElementID) )
    {
      v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eElementID);
      if ( v26 )
        v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)12);
      else
        v27 = 0;
      v1->m_pKeyboardCurrentKeymapLabel = (UIElement_Text *)v27;
    }
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000001Bu, &eElementID) )
    {
      v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eElementID);
      if ( v28 )
        v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)1);
      else
        v29 = 0;
      v1->m_pKeyboardResetToDefaultsButton = (UIElement_Button *)v29;
    }
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000001Cu, &eElementID) )
    {
      v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eElementID);
      if ( v30 )
        v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)1);
      else
        v31 = 0;
      v1->m_pKeyboardRevertToSavedButton = (UIElement_Button *)v31;
    }
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000019u, &eElementID) )
    {
      v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eElementID);
      if ( v32 )
        v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)1);
      else
        v33 = 0;
      v1->m_pKeyboardOKButton = (UIElement_Button *)v33;
    }
    if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000001Au, &eElementID) )
    {
      v34 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eElementID);
      if ( v34 )
        v35 = v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)1);
      else
        v35 = 0;
      v1->m_pKeyboardCancelButton = (UIElement_Button *)v35;
    }
    ((void (__thiscall *)(gmKeyboardUI *))v1->vfptr[27].__vecDelDtor)(v1);
  }
}

//----- (004DBB40) --------------------------------------------------------  // acclient.c:266616
HashTable<unsigned long,UIElement_ListBox *,0> *__thiscall HashTable<unsigned long,UIElement_ListBox *,0>::vector_deleting_destructor(HashTable<unsigned long,UIElement_ListBox *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,UIElement_ListBox *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,UIElement_ListBox *,0>Vtbl *)&HashTable<unsigned long,UIElement_ListBox *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable;
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
// 7BE668: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable[5])(void *, char);
// 7BE678: using guessed type int (__thiscall *HashTable<unsigned long,UIElement_ListBox *,0>::vftable)(void *, char);

//----- (004DBBA0) --------------------------------------------------------  // acclient.c:266642
char __thiscall HashList<unsigned long,List<unsigned long>,1>::push_tail(HashList<unsigned long,List<unsigned long>,1> *this, const unsigned int *key, List<unsigned long> *val)
{
  HashList<unsigned long,List<unsigned long>,1> *v3; // edi@1
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  void *v6; // esi@4
  int v7; // ecx@5
  char result; // al@7
  char keya; // [sp+10h] [bp+4h]@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[*key % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != *key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<unsigned long,List<unsigned long>,1>::move_to_tail(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x20u);
    v6 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = 0;
      v7 = (int)((char *)v5 + 16);
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *(_DWORD *)v7 = List<unsigned long>::vftable;
      *(_DWORD *)(v7 + 4) = 0;
      *(_DWORD *)(v7 + 8) = 0;
      *(_DWORD *)(v7 + 12) = 0;
      AC1Legacy::List<unsigned long>::operator=((List<SkillRecord *> *)v5 + 1, (int)val);
    }
    else
    {
      v6 = 0;
    }
    result = IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::push_tail(
               &v3->m_ihlIntrusive,
               (HashList<unsigned long,List<unsigned long>,1>::HashListData *)v6);
    keya = result;
    if ( !result )
    {
      if ( v6 )
      {
        *((_DWORD *)v6 + 4) = List<unsigned long>::vftable;
        List<SkillRecord *>::flush((List<SkillRecord *> *)v6 + 1);
        operator delete(v6);
        result = keya;
      }
    }
  }
  return result;
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (004DBC60) --------------------------------------------------------  // acclient.c:266708
char __thiscall HashList<unsigned long,ActionMapValue,1>::push_tail(HashList<unsigned long,ActionMapValue,1> *this, const unsigned int *key, ActionMapValue *val)
{
  HashList<unsigned long,ActionMapValue,1> *v3; // edi@1
  HashList<unsigned long,ActionMapValue,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  HashList<unsigned long,ActionMapValue,1>::HashListData *v6; // esi@5
  char result; // al@7
  char v8; // bl@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[*key % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != *key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<unsigned long,ActionMapValue,1>::move_to_tail(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x20u);
    if ( v5 )
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_OWORD *)v5 + 1) = *val;
      v6 = (HashList<unsigned long,ActionMapValue,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v8 = IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::push_tail(
           &v3->m_ihlIntrusive,
           v6);
    if ( !v8 )
    {
      if ( v6 )
        operator delete(v6);
    }
    result = v8;
  }
  return result;
}

//----- (004DBD10) --------------------------------------------------------  // acclient.c:266762
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents(IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *v1; // edi@1
  int v2; // ecx@2
  HashList<unsigned long,List<unsigned long>,1>::HashListData **v3; // eax@3
  int v4; // eax@4
  HashList<unsigned long,List<unsigned long>,1>::HashListData **v5; // edx@5
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v6; // esi@5
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v7; // eax@7
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v8; // ecx@8
  ListNode<unsigned long> *v9; // ecx@14
  ListNode<unsigned long> *v10; // eax@15

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashList<unsigned long,List<unsigned long>,1>::HashListData **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_25;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_25:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v6->m_data.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
      while ( 1 )
      {
        v9 = v6->m_data._head;
        if ( !v9 )
          break;
        v10 = v9->next;
        v6->m_data._head = v10;
        if ( v10 )
          v10->prev = 0;
        else
          v6->m_data._tail = 0;
        if ( v9 )
          operator delete(v9);
        --v6->m_data._num_elements;
      }
      operator delete(v6);
    }
  }
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (004DBDD0) --------------------------------------------------------  // acclient.c:266840
char __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::add(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this, HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *data)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (004DBE50) --------------------------------------------------------  // acclient.c:266884
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::place_at_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this, HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *pMoving)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v3; // eax@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[pMoving->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != pMoving->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::add(
      &this->m_hash,
      pMoving);
  DLListBase::InsertAfter(&v2->m_list, (DLListData *)&pMoving->dllist_next, v2->m_list.tail_);
  return 1;
}

//----- (004DBEB0) --------------------------------------------------------  // acclient.c:266911
void __userpurge gmKeyboardUI::gmKeyboardUI(gmKeyboardUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmKeyboardUI *v4; // esi@1

  v4 = this;
  OptionPage::OptionPage((OptionPage *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmKeyboardUI::vftable;
  v4->vfptr = (IOptionChangeHandlerVtbl *)&gmKeyboardUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmKeyboardUI::vftable;
  v4->m_pKeyboardLoadKeymapButton = 0;
  v4->m_pKeyboardSaveKeymapButton = 0;
  v4->m_pKeyboardCurrentKeymapLabel = 0;
  v4->m_pKeyboardResetToDefaultsButton = 0;
  v4->m_pKeyboardRevertToSavedButton = 0;
  v4->m_pKeyboardOKButton = 0;
  v4->m_pKeyboardCancelButton = 0;
  v4->m_hashMappingListBoxes.vfptr = (HashTable<unsigned long,UIElement_ListBox *,0>Vtbl *)&HashTable<unsigned long,UIElement_ListBox *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>(
    &v4->m_hashMappingListBoxes.m_intrusiveTable,
    0x17u);
  v4->m_uiLoadKeymapDialogContext = 0;
  v4->m_uiSaveKeymapDialogContext = 0;
  v4->m_uiCantOverwriteReadOnlyKeymapDialogContext = 0;
  v4->m_uiOverwriteKeymapDialogContext = 0;
  v4->m_listCachedKeymapFilenames._head = 0;
  v4->m_listCachedKeymapFilenames._tail = 0;
  v4->m_listCachedKeymapFilenames._num_elements = 0;
  v4->m_listCachedKeymapFilenames.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);
// 7BE678: using guessed type int (__thiscall *HashTable<unsigned long,UIElement_ListBox *,0>::vftable)(void *, char);
// 7BE680: using guessed type bool (__thiscall *gmKeyboardUI::vftable)(DBCache *this);
// 7BE928: using guessed type void (__thiscall *gmKeyboardUI::vftable)(gmKeyboardUI *this, const struct UIOption *);
// 7BE930: using guessed type int (__thiscall *gmKeyboardUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DBF70) --------------------------------------------------------  // acclient.c:266949
signed int __thiscall gmKeyboardUI::DynamicCast(gmKeyboardUI *this, unsigned int i_eType)
{
  return i_eType != 268435470 ? 0 : (unsigned int)this;
}

//----- (004DBF90) --------------------------------------------------------  // acclient.c:266955
signed int gmKeyboardUI::GetUIElementType()
{
  return 268435470;
}

//----- (004DBFA0) --------------------------------------------------------  // acclient.c:266961
void __thiscall gmKeyboardUI::~gmKeyboardUI(gmKeyboardUI *this)
{
  gmKeyboardUI *v1; // esi@1
  NoticeHandler *v2; // ebx@1
  void *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmKeyboardUI::vftable;
  this->vfptr = (IOptionChangeHandlerVtbl *)&gmKeyboardUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmKeyboardUI::vftable;
  DialogFactory::CloseDialog(this->m_uiLoadKeymapDialogContext);
  v1->m_uiLoadKeymapDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_uiSaveKeymapDialogContext);
  v1->m_uiSaveKeymapDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_uiCantOverwriteReadOnlyKeymapDialogContext);
  v1->m_uiCantOverwriteReadOnlyKeymapDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_uiOverwriteKeymapDialogContext);
  v1->m_uiOverwriteKeymapDialogContext = 0;
  v1->m_listCachedKeymapFilenames.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  List<PStringBase<char>>::flush(&v1->m_listCachedKeymapFilenames);
  v1->m_hashMappingListBoxes.vfptr = (HashTable<unsigned long,UIElement_ListBox *,0>Vtbl *)&HashTable<unsigned long,UIElement_ListBox *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashMappingListBoxes.m_intrusiveTable);
  v3 = v1->m_hashMappingListBoxes.m_intrusiveTable.m_buckets;
  v1->m_hashMappingListBoxes.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable;
  if ( v3 != v1->m_hashMappingListBoxes.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_hashMappingListBoxes.m_intrusiveTable.m_buckets = 0;
  v1->m_hashMappingListBoxes.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashMappingListBoxes.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashMappingListBoxes.m_intrusiveTable.m_numElements = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  OptionPage::~OptionPage((OptionPage *)&v1->vfptr);
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);
// 7BE668: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable[5])(void *, char);
// 7BE678: using guessed type int (__thiscall *HashTable<unsigned long,UIElement_ListBox *,0>::vftable)(void *, char);
// 7BE680: using guessed type bool (__thiscall *gmKeyboardUI::vftable)(DBCache *this);
// 7BE928: using guessed type void (__thiscall *gmKeyboardUI::vftable)(gmKeyboardUI *this, const struct UIOption *);
// 7BE930: using guessed type int (__thiscall *gmKeyboardUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DC080) --------------------------------------------------------  // acclient.c:267005
void __usercall gmKeyboardUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmKeyboardUI *v3; // eax@1

  v3 = (gmKeyboardUI *)operator new(0x6B4u);
  if ( v3 )
    gmKeyboardUI::gmKeyboardUI(v3, a1, _layout, _full_desc);
}

//----- (004DC0B0) --------------------------------------------------------  // acclient.c:267015
char __thiscall gmKeyboardUI::MakeLoadKeymapDialog(gmKeyboardUI *this)
{
  gmKeyboardUI *v1; // edi@1
  unsigned int v2; // eax@1
  char v3; // al@2
  ListNode<PStringBase<char> > *v4; // ebp@11
  PSRefBufferCharData<char> *v5; // edi@13
  volatile LONG *v6; // ST14_4@13
  BasePropertyDesc *v7; // ecx@17
  unsigned int v8; // edx@17
  BasePropertyValue *v9; // ecx@21
  unsigned int v10; // edx@21
  PSRefBufferCharData<unsigned short> *v11; // eax@24
  int v12; // ecx@24
  char *v13; // esi@26
  unsigned int v14; // esi@29
  BasePropertyDesc *v15; // ecx@37
  unsigned int v16; // edx@37
  BasePropertyValue *v17; // ecx@41
  unsigned int v18; // esi@41
  unsigned __int32 v19; // eax@48
  PSRefBufferCharData<char> *v20; // esi@48
  int v21; // esi@48
  BasePropertyDesc *v22; // ecx@52
  unsigned int v23; // edx@52
  BasePropertyValue *v24; // ecx@56
  unsigned int v25; // esi@56
  BaseProperty p; // [sp+28h] [bp-1C8h]@3
  int choice; // [sp+30h] [bp-1C0h]@5
  unsigned int _key; // [sp+34h] [bp-1BCh]@16
  BaseProperty propDefaultChoice; // [sp+38h] [bp-1B8h]@14
  BaseProperty subP; // [sp+40h] [bp-1B0h]@24
  unsigned int v31; // [sp+48h] [bp-1A8h]@1
  PStringBase<char> strKeymapFilePathMask; // [sp+4Ch] [bp-1A4h]@11
  PStringBase<unsigned short> result; // [sp+50h] [bp-1A0h]@24
  PStringBase<char> strKeymap; // [sp+54h] [bp-19Ch]@13
  PropertyCollection pc; // [sp+58h] [bp-198h]@3
  StringInfo v36; // [sp+D0h] [bp-120h]@24
  StringInfo info; // [sp+160h] [bp-90h]@9

  v1 = this;
  v2 = this->m_uiLoadKeymapDialogContext;
  v31 = (unsigned int)this;
  if ( v2 )
  {
    v3 = 0;
  }
  else
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(7);
    }
    choice = (int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&choice,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC3u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(268435457);
    }
    choice = (int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&choice,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    choice = (int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&choice,
      &p);
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_KeyMapLoadKeymap_Label, 268435460);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    choice = (int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      (const unsigned int *)&choice,
      &p);
    BaseProperty::SetPropertyName(&p, 0xA6u);
    gmKeyboardUI::GetKeymapDirectory(&strKeymapFilePathMask);
    PStringBase<char>::append_n_chars(&strKeymapFilePathMask, "\\*.keymap", strlen("\\*.keymap"));
    List<PStringBase<char>>::flush(&v1->m_listCachedKeymapFilenames);
    PSUtils::find_files(&strKeymapFilePathMask, &v1->m_listCachedKeymapFilenames, 0, 0);
    v4 = v1->m_listCachedKeymapFilenames._head;
    choice = 0;
    while ( v4 )
    {
      PSUtils::strip_directory(&v4->data);
      v6 = (volatile LONG *)&v4->data.m_charbuffer[-1];
      strKeymap.m_charbuffer = v4->data.m_charbuffer;
      v5 = strKeymap.m_charbuffer;
      InterlockedIncrement(v6);
      if ( !__stricmp(v5->m_data, Client::m_instance->m_strKeymapFile.m_charbuffer->m_data) )
      {
        propDefaultChoice.m_pcPropertyDesc = 0;
        propDefaultChoice.m_pcPropertyValue = 0;
        BaseProperty::SetPropertyName(&propDefaultChoice, 0xABu);
        if ( propDefaultChoice.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&propDefaultChoice);
          ((void (__stdcall *)(int))propDefaultChoice.m_pcPropertyValue->vfptr[31].__vecDelDtor)(choice);
        }
        _key = (unsigned int)BaseProperty::GetPropertyName(&propDefaultChoice);
        HashTable<unsigned long,BaseProperty,1>::add(
          (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
          &_key,
          &propDefaultChoice);
        if ( (_DWORD)propDefaultChoice.m_pcPropertyDesc )
        {
          v7 = propDefaultChoice.m_pcPropertyDesc;
          v8 = propDefaultChoice.m_pcPropertyDesc->m_cRef - 1;
          propDefaultChoice.m_pcPropertyDesc->m_cRef = v8;
          if ( !v8 )
            ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
          propDefaultChoice.m_pcPropertyDesc = 0;
        }
        if ( propDefaultChoice.m_pcPropertyValue )
        {
          v9 = propDefaultChoice.m_pcPropertyValue;
          v10 = propDefaultChoice.m_pcPropertyValue->m_cRef - 1;
          propDefaultChoice.m_pcPropertyValue->m_cRef = v10;
          if ( !v10 )
            ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
          propDefaultChoice.m_pcPropertyValue = 0;
        }
      }
      subP.m_pcPropertyDesc = 0;
      subP.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&subP, 0xA7u);
      StringInfo::StringInfo(&v36);
      _key = (unsigned int)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      v11 = PStringBase<char>::to_wpstring(&strKeymap, &result, 0)->m_charbuffer;
      v12 = *(_DWORD *)&v11[-1].m_data[14];
      if ( v12 != 1 )
        PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&_key, v11->m_data, v12 - 1);
      v13 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v13 )
        (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
      StringInfo::SetLiteralValue(&v36, (PStringBase<unsigned short> *)&_key, 1);
      v14 = _key - 20;
      if ( !InterlockedDecrement((volatile LONG *)(_key - 20 + 4)) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      if ( subP.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&subP);
        ((void (__stdcall *)(StringInfo *))subP.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v36);
      }
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(BaseProperty *))p.m_pcPropertyValue->vfptr[63].__vecDelDtor)(&subP);
      }
      ++choice;
      StringInfo::~StringInfo(&v36);
      if ( (_DWORD)subP.m_pcPropertyDesc )
      {
        v15 = subP.m_pcPropertyDesc;
        v16 = subP.m_pcPropertyDesc->m_cRef - 1;
        subP.m_pcPropertyDesc->m_cRef = v16;
        if ( !v16 )
          ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
        subP.m_pcPropertyDesc = 0;
      }
      if ( subP.m_pcPropertyValue )
      {
        v17 = subP.m_pcPropertyValue;
        v18 = subP.m_pcPropertyValue->m_cRef - 1;
        subP.m_pcPropertyValue->m_cRef = v18;
        if ( !v18 )
          ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
        subP.m_pcPropertyValue = 0;
      }
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
        (**(void (__thiscall ***)(char *, signed int))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
      v4 = v4->next;
      v1 = (gmKeyboardUI *)v31;
    }
    v31 = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &v31,
      &p);
    v19 = DialogFactory::MakeDialogInCurrentUI(&pc);
    v20 = strKeymapFilePathMask.m_charbuffer;
    v1->m_uiLoadKeymapDialogContext = v19;
    v21 = (int)&v20[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v21 + 4)) && v21 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    StringInfo::~StringInfo(&info);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v22 = p.m_pcPropertyDesc;
      v23 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v23;
      if ( !v23 )
        ((void (__stdcall *)(signed int))v22->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v24 = p.m_pcPropertyValue;
      v25 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v25;
      if ( !v25 )
        ((void (__stdcall *)(signed int))v24->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    v3 = 1;
  }
  return v3;
}

//----- (004DC5B0) --------------------------------------------------------  // acclient.c:267250
char __thiscall gmKeyboardUI::MakeSaveKeymapDialog(gmKeyboardUI *this)
{
  gmKeyboardUI *v1; // esi@1
  char result; // al@2
  BasePropertyDesc *v3; // ecx@12
  unsigned int v4; // esi@12
  BasePropertyValue *v5; // ecx@16
  unsigned int v6; // edx@16
  BaseProperty p; // [sp+14h] [bp-114h]@3
  unsigned int _key; // [sp+1Ch] [bp-10Ch]@5
  PropertyCollection pc; // [sp+20h] [bp-108h]@3
  StringInfo info; // [sp+98h] [bp-90h]@9

  v1 = this;
  if ( this->m_uiSaveKeymapDialogContext )
  {
    result = 0;
  }
  else
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(5);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC3u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(268435457);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_KeyMapSaveKeymap_Label, 268435460);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v1->m_uiSaveKeymapDialogContext = DialogFactory::MakeDialogInCurrentUI(&pc);
    StringInfo::~StringInfo(&info);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v3 = p.m_pcPropertyDesc;
      v4 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v4;
      if ( !v4 )
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v5 = p.m_pcPropertyValue;
      v6 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    result = 1;
  }
  return result;
}

//----- (004DC7B0) --------------------------------------------------------  // acclient.c:267346
char __thiscall gmKeyboardUI::MakeCantOverwriteReadOnlyKeymapDialog(gmKeyboardUI *this, PStringBase<char> i_strKeymapFilename)
{
  gmKeyboardUI *v2; // esi@1
  char result; // al@5
  BasePropertyDesc *v4; // ecx@15
  unsigned int v5; // edx@15
  BasePropertyValue *v6; // ecx@19
  unsigned int v7; // esi@19
  BaseProperty p; // [sp+14h] [bp-114h]@6
  unsigned int _key; // [sp+1Ch] [bp-10Ch]@8
  PropertyCollection pc; // [sp+20h] [bp-108h]@6
  StringInfo info; // [sp+98h] [bp-90h]@12

  v2 = this;
  if ( this->m_uiCantOverwriteReadOnlyKeymapDialogContext )
  {
    if ( !InterlockedDecrement((volatile LONG *)&i_strKeymapFilename.m_charbuffer[-1])
      && i_strKeymapFilename.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&i_strKeymapFilename.m_charbuffer[-2].m_data[12])(
        &i_strKeymapFilename.m_charbuffer[-2].m_data[12],
        1);
    result = 0;
  }
  else
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(3);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC3u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(268435457);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_KeyMapCantOverwriteReadOnlyKeymap_Label, 268435460);
    InterlockedIncrement((volatile LONG *)&i_strKeymapFilename.m_charbuffer[-1]);
    StringInfo::AddVariable_String(&info, KEYMAP, i_strKeymapFilename);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v2->m_uiCantOverwriteReadOnlyKeymapDialogContext = DialogFactory::MakeDialogInCurrentUI(&pc);
    StringInfo::~StringInfo(&info);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    if ( !InterlockedDecrement((volatile LONG *)&i_strKeymapFilename.m_charbuffer[-1])
      && i_strKeymapFilename.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&i_strKeymapFilename.m_charbuffer[-2].m_data[12])(
        &i_strKeymapFilename.m_charbuffer[-2].m_data[12],
        1);
    result = 1;
  }
  return result;
}

//----- (004DCA20) --------------------------------------------------------  // acclient.c:267454
char __thiscall gmKeyboardUI::MakeOverwriteKeymapDialog(gmKeyboardUI *this, PStringBase<char> i_strKeymapFilename)
{
  gmKeyboardUI *v2; // esi@1
  char *v3; // esi@2
  char result; // al@5
  PStringBase<char> v5; // ST08_4@14
  BasePropertyDesc *v6; // ecx@17
  unsigned int v7; // esi@17
  BasePropertyValue *v8; // ecx@21
  unsigned int v9; // edx@21
  char *v10; // esi@24
  BaseProperty p; // [sp+18h] [bp-114h]@6
  unsigned int _key; // [sp+20h] [bp-10Ch]@8
  PropertyCollection pc; // [sp+24h] [bp-108h]@6
  StringInfo info; // [sp+9Ch] [bp-90h]@14

  v2 = this;
  if ( this->m_uiOverwriteKeymapDialogContext )
  {
    v3 = &i_strKeymapFilename.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&i_strKeymapFilename.m_charbuffer[-1]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    result = 0;
  }
  else
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC3u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(268435457);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0x10000020u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[41].__vecDelDtor)(&i_strKeymapFilename);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_KeyMapOverwriteKeymap_Label, 268435460);
    v5.m_charbuffer = i_strKeymapFilename.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&i_strKeymapFilename.m_charbuffer[-1]);
    StringInfo::AddVariable_String(&info, KEYMAP, v5);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v2->m_uiOverwriteKeymapDialogContext = DialogFactory::MakeDialogInCurrentUI(&pc);
    StringInfo::~StringInfo(&info);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v6 = p.m_pcPropertyDesc;
      v7 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v8 = p.m_pcPropertyValue;
      v9 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    v10 = &i_strKeymapFilename.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&i_strKeymapFilename.m_charbuffer[-1]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    result = 1;
  }
  return result;
}

//----- (004DCCE0) --------------------------------------------------------  // acclient.c:267576
HashList<unsigned long,ActionMapValue,1> *__thiscall HashList<unsigned long,ActionMapValue,1>::operator=(HashList<unsigned long,ActionMapValue,1> *this, int a2)
{
  HashList<unsigned long,ActionMapValue,1> *v2; // edi@1
  int v3; // esi@1
  int v4; // ecx@2
  int v5; // esi@6

  v2 = this;
  HashList<ControlSpecification,unsigned long,1>::flush(this);
  v3 = 0;
  if ( *(_DWORD *)(a2 + 108) )
  {
    v4 = *(_DWORD *)(a2 + 112);
    if ( v4 )
      v3 = v4 - 8;
    else
      v3 = 0;
  }
  for ( ; v3; v3 = v5 - 8 )
  {
    HashList<unsigned long,ActionMapValue,1>::push_tail(v2, (const unsigned int *)v3, (ActionMapValue *)(v3 + 16));
    v5 = *(_DWORD *)(v3 + 8);
    if ( !v5 )
      break;
  }
  return v2;
}

//----- (004DCD40) --------------------------------------------------------  // acclient.c:267605
void __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents(IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *this)
{
  DLListData *v1; // eax@1
  DLListData *v2; // edx@2
  DLListData *v3; // edx@4
  bool v4; // zf@4
  DLListData *v5; // edx@8

  do
  {
    v1 = this->m_list.head_;
    if ( !v1 )
      break;
    v2 = v1->dllist_prev;
    if ( v2 )
    {
      v2->dllist_next = v1->dllist_next;
    }
    else
    {
      v3 = v1->dllist_next;
      v4 = v1->dllist_next == 0;
      this->m_list.head_ = v1->dllist_next;
      if ( !v4 )
        v3->dllist_prev = 0;
    }
    if ( v1->dllist_next )
    {
      v1->dllist_next->dllist_prev = v1->dllist_prev;
    }
    else
    {
      v5 = this->m_list.tail_->dllist_prev;
      this->m_list.tail_ = v5;
      if ( v5 )
        v5->dllist_next = 0;
    }
    v1->dllist_next = 0;
    v1->dllist_prev = 0;
  }
  while ( v1 );
  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents(&this->m_hash);
}

//----- (004DCDA0) --------------------------------------------------------  // acclient.c:267650
void __thiscall HashList<unsigned long,List<unsigned long>,1>::flush(HashList<unsigned long,List<unsigned long>,1> *this)
{
  HashList<unsigned long,List<unsigned long>,1> *v1; // ebp@1
  int v2; // esi@2
  DLListData *v3; // eax@3
  DLListData *v4; // ecx@4
  DLListData *v5; // ecx@6
  bool v6; // zf@6
  DLListData *v7; // ecx@10
  int v8; // edx@14
  HashList<unsigned long,List<unsigned long>,1>::HashListData **v9; // eax@14
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v10; // ecx@14
  int v11; // ebx@14
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v12; // eax@14
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v13; // edx@20
  int v14; // ecx@26
  int v15; // eax@27

  v1 = this;
  while ( 1 )
  {
    v2 = 0;
    if ( !v1->m_ihlIntrusive.m_hash.m_numElements )
      break;
    v3 = v1->m_ihlIntrusive.m_list.head_;
    if ( v3 )
    {
      v4 = v3->dllist_prev;
      if ( v4 )
      {
        v4->dllist_next = v3->dllist_next;
      }
      else
      {
        v5 = v3->dllist_next;
        v6 = v3->dllist_next == 0;
        v1->m_ihlIntrusive.m_list.head_ = v3->dllist_next;
        if ( !v6 )
          v5->dllist_prev = 0;
      }
      if ( v3->dllist_next )
      {
        v3->dllist_next->dllist_prev = v3->dllist_prev;
      }
      else
      {
        v7 = v1->m_ihlIntrusive.m_list.tail_->dllist_prev;
        v1->m_ihlIntrusive.m_list.tail_ = v7;
        if ( v7 )
          v7->dllist_next = 0;
      }
      v3->dllist_next = 0;
      v3->dllist_prev = 0;
      if ( v3 )
        v2 = (int)&v3[-1];
    }
    v8 = *(_DWORD *)v2 % v1->m_ihlIntrusive.m_hash.m_numBuckets;
    v9 = v1->m_ihlIntrusive.m_hash.m_buckets;
    v10 = v9[v8];
    v11 = (int)&v9[v8];
    v12 = v9[v8];
    if ( v12 )
    {
      while ( v12->m_hashKey != *(_DWORD *)v2 )
      {
        v12 = v12->m_hashNext;
        if ( !v12 )
          goto LABEL_25;
      }
      if ( v12 )
      {
        if ( v10 == v12 )
          goto LABEL_36;
        do
        {
          v13 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v12 );
        if ( v13 )
          v13->m_hashNext = v10->m_hashNext;
        else
LABEL_36:
          *(_DWORD *)v11 = v10->m_hashNext;
        --v1->m_ihlIntrusive.m_hash.m_numElements;
      }
    }
LABEL_25:
    *(_DWORD *)(v2 + 16) = List<unsigned long>::vftable;
    while ( 1 )
    {
      v14 = *(_DWORD *)(v2 + 20);
      if ( !v14 )
        break;
      v15 = *(_DWORD *)(v14 + 4);
      *(_DWORD *)(v2 + 20) = v15;
      if ( v15 )
        *(_DWORD *)(v15 + 8) = 0;
      else
        *(_DWORD *)(v2 + 24) = 0;
      if ( v14 )
        operator delete((void *)v14);
      --*(_DWORD *)(v2 + 28);
    }
    operator delete((void *)v2);
  }
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (004DCEA0) --------------------------------------------------------  // acclient.c:267760
char __thiscall HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::move_to_tail(HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1> *this, const unsigned int *keyToMove)
{
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[*keyToMove % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey != *keyToMove )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::place_at_tail(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (004DCEF0) --------------------------------------------------------  // acclient.c:267785
char __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::push_tail(IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this, HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *val)
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v2; // esi@1
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v3; // eax@1
  char result; // al@4

  v2 = this;
  v3 = v2->m_hash.m_buckets[val->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::add(
      &this->m_hash,
      val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (004DCF50) --------------------------------------------------------  // acclient.c:267818
gmKeyboardUI *__thiscall gmKeyboardUI::vector_deleting_destructor(gmKeyboardUI *this, unsigned int a2)
{
  gmKeyboardUI *v2; // esi@1

  v2 = this;
  gmKeyboardUI::~gmKeyboardUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004DCF70) --------------------------------------------------------  // acclient.c:267830
void __cdecl gmKeyboardUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000000Eu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmKeyboardUI::Create);
}

//----- (004DCF90) --------------------------------------------------------  // acclient.c:267838
void __thiscall gmKeyboardUI::SaveKeymap(gmKeyboardUI *this, PStringBase<char> *i_strKeymapFilename, bool bOverwriteConfirmation)
{
  gmKeyboardUI *v3; // edi@1
  PStringBase<char> *v4; // eax@1
  bool v5; // al@1
  char *v6; // esi@1
  bool v7; // bl@1
  char *v8; // esi@4
  PStringBase<char> v9; // ST0C_4@11
  PStringBase<char> v10; // ST0C_4@13
  CInputManager *v11; // esi@16
  PSRefBufferCharData<char> *v12; // ST0C_4@16
  char *v13; // esi@17
  PStringBase<char> *v14; // esi@20
  PStringBase<char> strKeymapFilepath; // [sp+10h] [bp-Ch]@9
  PStringBase<char> rhs; // [sp+14h] [bp-8h]@1
  PStringBase<char> result; // [sp+18h] [bp-4h]@1

  i_strKeymapFilename = (PStringBase<char> *)i_strKeymapFilename->m_charbuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)&i_strKeymapFilename[-4]);
  PStringBase<char>::PStringBase<char>(&rhs, ".keymap");
  v4 = PSUtils::get_extension(&result, (PStringBase<char> *)&i_strKeymapFilename);
  v5 = PStringBase<char>::operator!=(v4, &rhs);
  v6 = &result.m_charbuffer[-2].m_data[12];
  v7 = v5;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v8 = &rhs.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  if ( v7 )
    PStringBase<char>::append_n_chars((PStringBase<char> *)&i_strKeymapFilename, ".keymap", strlen(".keymap"));
  gmKeyboardUI::GetKeymapDirectory(&strKeymapFilepath);
  PSUtils::path_append(&strKeymapFilepath, (PStringBase<char> *)&i_strKeymapFilename);
  if ( (unsigned __int8)PSUtils::check_access(&strKeymapFilepath, 0) )
  {
    if ( !(unsigned __int8)PSUtils::check_access(&strKeymapFilepath, 2) )
    {
      v9.m_charbuffer = (PSRefBufferCharData<char> *)i_strKeymapFilename;
      InterlockedIncrement((volatile LONG *)&i_strKeymapFilename[-4]);
      gmKeyboardUI::MakeCantOverwriteReadOnlyKeymapDialog(v3, v9);
      goto LABEL_17;
    }
    if ( bOverwriteConfirmation )
    {
      v10.m_charbuffer = (PSRefBufferCharData<char> *)i_strKeymapFilename;
      InterlockedIncrement((volatile LONG *)&i_strKeymapFilename[-4]);
      gmKeyboardUI::MakeOverwriteKeymapDialog(v3, v10);
      goto LABEL_17;
    }
  }
  if ( Client::m_instance && ICIDM::s_cidm )
  {
    gmClient::SetKeyMapFileName(Client::m_instance, (PStringBase<char> *)&i_strKeymapFilename);
    v11 = ICIDM::s_cidm;
    v12 = strKeymapFilepath.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strKeymapFilepath.m_charbuffer[-1]);
    ((void (__thiscall *)(CInputManager *, PSRefBufferCharData<char> *))v11->vfptr->SaveKeyMap)(v11, v12);
    gmKeyboardUI::UpdateKeymapFilenameLabel(v3);
    UserPreferences::Save();
  }
LABEL_17:
  v13 = &strKeymapFilepath.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strKeymapFilepath.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  v14 = i_strKeymapFilename - 5;
  if ( !InterlockedDecrement((volatile LONG *)&i_strKeymapFilename[-4]) )
  {
    if ( v14 )
      (*(void (__thiscall **)(_DWORD, _DWORD))&v14->m_charbuffer->m_data[0])(v14, 1);
  }
}

//----- (004DD160) --------------------------------------------------------  // acclient.c:267913
void __thiscall gmKeyboardUI::HandleCloseSaveKeymapDialog(gmKeyboardUI *this, PStringBase<char> *i_strKeymapFilename)
{
  gmKeyboardUI *v2; // esi@1

  v2 = this;
  this->m_uiSaveKeymapDialogContext = 0;
  if ( PStringBase<char>::operator!=(i_strKeymapFilename, &PStringBase<char>::null_string) )
    gmKeyboardUI::SaveKeymap(v2, i_strKeymapFilename, 1);
}

//----- (004DD1A0) --------------------------------------------------------  // acclient.c:267924
void __thiscall gmKeyboardUI::HandleCloseOverwriteKeymapDialog(gmKeyboardUI *this, bool i_bConfirm, PStringBase<char> *i_strKeymapFilename)
{
  this->m_uiOverwriteKeymapDialogContext = 0;
  if ( i_bConfirm )
    gmKeyboardUI::SaveKeymap(this, i_strKeymapFilename, 0);
}

//----- (004DD1D0) --------------------------------------------------------  // acclient.c:267932
int __thiscall HashList<unsigned long,List<unsigned long>,1>::operator=(HashList<unsigned long,List<unsigned long>,1> *this, int a2)
{
  HashList<unsigned long,List<unsigned long>,1> *v2; // edi@1
  int v3; // esi@1
  int v4; // ecx@2
  int v5; // esi@6

  v2 = this;
  HashList<unsigned long,List<unsigned long>,1>::flush(this);
  v3 = 0;
  if ( *(_DWORD *)(a2 + 108) )
  {
    v4 = *(_DWORD *)(a2 + 112);
    if ( v4 )
      v3 = v4 - 8;
    else
      v3 = 0;
  }
  for ( ; v3; v3 = v5 - 8 )
  {
    HashList<unsigned long,List<unsigned long>,1>::push_tail(
      v2,
      (const unsigned int *)v3,
      (List<unsigned long> *)(v3 + 16));
    v5 = *(_DWORD *)(v3 + 8);
    if ( !v5 )
      break;
  }
  return nullsub_1891(a2);
}
// 4DD221: using guessed type int __stdcall nullsub_1891(int);

//----- (004DD230) --------------------------------------------------------  // acclient.c:267965
int __thiscall gmKeyboardUI::ListenToElementMessage(gmKeyboardUI *this, UIElementMessageInfo *i_rMsg)
{
  gmKeyboardUI *v2; // esi@1
  UIElement *v3; // eax@5
  UIElement_Button *v4; // ecx@5
  UIElement_Button *v6; // ecx@11
  UIElement *v7; // eax@16

  v2 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( DialogFactory::IsDialogOpen(0x10000001u) )
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    v7 = i_rMsg->pElement;
    if ( (UIElement_Button *)v7 == v2->m_pKeyboardLoadKeymapButton )
    {
      gmKeyboardUI::MakeLoadKeymapDialog(v2);
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    }
    if ( (UIElement_Button *)v7 == v2->m_pKeyboardSaveKeymapButton )
    {
      gmKeyboardUI::MakeSaveKeymapDialog(v2);
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    }
    if ( (UIElement_Button *)v7 == v2->m_pKeyboardResetToDefaultsButton )
    {
      ((void (__thiscall *)(gmKeyboardUI *))v2->vfptr[26].OnAction)(v2);
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    }
    if ( (UIElement_Button *)v7 != v2->m_pKeyboardRevertToSavedButton )
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
LABEL_23:
    ((void (__thiscall *)(gmKeyboardUI *))v2->vfptr[26].OnLoseFocus)(v2);
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  if ( i_rMsg->idMessage != 25 || DialogFactory::IsDialogOpen(0x10000001u) || i_rMsg->dwParam1 != 7 )
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  v3 = i_rMsg->pElement;
  v4 = v2->m_pKeyboardOKButton;
  if ( (UIElement_Button *)v3 != v4 )
  {
    v6 = v2->m_pKeyboardCancelButton;
    if ( (UIElement_Button *)v3 != v6 || !v6 || v6->m_state == 13 )
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    goto LABEL_23;
  }
  if ( !v4 || v4->m_state == 13 )
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  if ( OptionPage::Changed((OptionPage *)&v2->vfptr) )
    gmKeyboardUI::SaveKeymap(v2, &Client::m_instance->m_strKeymapFile, 0);
  ((void (__thiscall *)(gmKeyboardUI *))v2->vfptr[26].__vecDelDtor)(v2);
  return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
}

//----- (004DD370) --------------------------------------------------------  // acclient.c:268020
void __thiscall gmKeyboardUI::RecvNotice_CloseDialog(gmKeyboardUI *this, unsigned int context, PropertyCollection *data)
{
  PropertyCollection *v3; // esi@1
  unsigned int v4; // edx@1
  HashTableData<unsigned long,BaseProperty> **v5; // eax@1
  gmKeyboardUI *v6; // edi@1
  HashTableData<unsigned long,BaseProperty> *v7; // eax@1
  unsigned int v8; // edx@9
  HashTableData<unsigned long,BaseProperty> **v9; // ecx@9
  HashTableData<unsigned long,BaseProperty> *v10; // eax@9
  unsigned int v11; // edx@18
  HashTableData<unsigned long,BaseProperty> **v12; // eax@18
  HashTableData<unsigned long,BaseProperty> *v13; // eax@18
  char *v14; // esi@27
  unsigned int v15; // edx@32
  HashTableData<unsigned long,BaseProperty> **v16; // ecx@32
  HashTableData<unsigned long,BaseProperty> *v17; // eax@32
  HashTableData<unsigned long,BaseProperty> *v18; // eax@39
  char *v19; // esi@48
  BasePropertyDesc *v20; // ecx@53
  unsigned int v21; // edx@53
  BasePropertyValue *v22; // ecx@57
  unsigned int v23; // edx@57
  unsigned int type; // [sp+Ch] [bp-18h]@1
  int choice; // [sp+10h] [bp-14h]@32
  BaseProperty v26; // [sp+14h] [bp-10h]@9
  BaseProperty p; // [sp+1Ch] [bp-8h]@1

  v3 = data;
  v4 = 0x8E % data->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v5 = data->m_hashProperties.m_intrusiveTable.m_buckets;
  type = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v6 = this;
  v7 = v5[v4];
  if ( v7 )
  {
    while ( v7->m_hashKey != 142 )
    {
      v7 = v7->m_hashNext;
      if ( !v7 )
        goto LABEL_8;
    }
    if ( v7 )
    {
      BaseProperty::operator=(&p, (int)&v7->m_data);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&type);
    }
  }
LABEL_8:
  switch ( type )
  {
    case 7u:
      v8 = 0xAB % v3->m_hashProperties.m_intrusiveTable.m_numBuckets;
      v9 = v3->m_hashProperties.m_intrusiveTable.m_buckets;
      data = (PropertyCollection *)-1;
      v26.m_pcPropertyDesc = 0;
      v26.m_pcPropertyValue = 0;
      v10 = v9[v8];
      if ( !v10 )
        goto LABEL_16;
      while ( v10->m_hashKey != 171 )
      {
        v10 = v10->m_hashNext;
        if ( !v10 )
          goto LABEL_16;
      }
      if ( v10 )
      {
        BaseProperty::operator=(&v26, (int)&v10->m_data);
        if ( v26.m_pcPropertyValue )
          ((void (__stdcall *)(PropertyCollection **))v26.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&data);
      }
LABEL_16:
      if ( v6->m_zlevel == context )
        gmKeyboardUI::HandleCloseLoadKeymapDialog((gmKeyboardUI *)((char *)v6 - 1536), (unsigned int)data);
      goto LABEL_51;
    case 5u:
      data = (PropertyCollection *)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v11 = 0x9C % v3->m_hashProperties.m_intrusiveTable.m_numBuckets;
      v12 = v3->m_hashProperties.m_intrusiveTable.m_buckets;
      v26.m_pcPropertyDesc = 0;
      v26.m_pcPropertyValue = 0;
      v13 = v12[v11];
      if ( !v13 )
        goto LABEL_25;
      while ( v13->m_hashKey != 156 )
      {
        v13 = v13->m_hashNext;
        if ( !v13 )
          goto LABEL_25;
      }
      if ( v13 )
      {
        BaseProperty::operator=(&v26, (int)&v13->m_data);
        if ( v26.m_pcPropertyValue )
          ((void (__stdcall *)(PropertyCollection **))v26.m_pcPropertyValue->vfptr[40].__vecDelDtor)(&data);
      }
LABEL_25:
      if ( v6->m_image == (Graphic *)context )
        gmKeyboardUI::HandleCloseSaveKeymapDialog((gmKeyboardUI *)((char *)v6 - 1536), (PStringBase<char> *)&data);
      BaseProperty::~BaseProperty(&v26);
      v14 = (char *)&data[-1].m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[22];
      if ( !InterlockedDecrement((volatile LONG *)&data[-1].m_hashProperties.m_intrusiveTable.m_buckets) && v14 )
        (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
      goto LABEL_52;
    case 3u:
      if ( v6->m_alphaImage == (Graphic *)context )
        v6->m_alphaImage = 0;
      goto LABEL_52;
    case 1u:
      v15 = 0x92 % v3->m_hashProperties.m_intrusiveTable.m_numBuckets;
      v16 = v3->m_hashProperties.m_intrusiveTable.m_buckets;
      LOBYTE(choice) = 0;
      v26.m_pcPropertyDesc = 0;
      v26.m_pcPropertyValue = 0;
      v17 = v16[v15];
      if ( !v17 )
        goto LABEL_39;
      break;
    default:
      goto LABEL_52;
  }
  while ( v17->m_hashKey != 146 )
  {
    v17 = v17->m_hashNext;
    if ( !v17 )
      goto LABEL_39;
  }
  if ( v17 )
  {
    BaseProperty::operator=(&v26, (int)&v17->m_data);
    if ( v26.m_pcPropertyValue )
      ((void (__stdcall *)(int *))v26.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&choice);
  }
LABEL_39:
  data = (PropertyCollection *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v18 = v3->m_hashProperties.m_intrusiveTable.m_buckets[0x10000020 % v3->m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v18 )
  {
    while ( v18->m_hashKey != 268435488 )
    {
      v18 = v18->m_hashNext;
      if ( !v18 )
        goto LABEL_46;
    }
    if ( v18 )
    {
      BaseProperty::operator=(&v26, (int)&v18->m_data);
      if ( v26.m_pcPropertyValue )
        ((void (__stdcall *)(PropertyCollection **))v26.m_pcPropertyValue->vfptr[40].__vecDelDtor)(&data);
    }
  }
LABEL_46:
  if ( LODWORD(v6->m_alphaBlendMod) == context )
    gmKeyboardUI::HandleCloseOverwriteKeymapDialog(
      (gmKeyboardUI *)((char *)v6 - 1536),
      choice,
      (PStringBase<char> *)&data);
  v19 = (char *)&data[-1].m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[22];
  if ( !InterlockedDecrement((volatile LONG *)&data[-1].m_hashProperties.m_intrusiveTable.m_buckets) && v19 )
    (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
LABEL_51:
  BaseProperty::~BaseProperty(&v26);
LABEL_52:
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v20 = p.m_pcPropertyDesc;
    v21 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v21;
    if ( !v21 )
      ((void (__stdcall *)(signed int))v20->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v22 = p.m_pcPropertyValue;
    v23 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v23;
    if ( !v23 )
      ((void (__stdcall *)(signed int))v22->vfptr->__vecDelDtor)(1);
  }
}

//----- (004DD6B0) --------------------------------------------------------  // acclient.c:268209
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::delete_contents(IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this)
{
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *v1; // edi@1
  int v2; // ecx@2
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v3; // eax@3
  int v4; // eax@4
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v5; // edx@5
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v6; // ebx@5
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v7; // eax@7
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v8; // ecx@8
  void *v9; // eax@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_19;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_19:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents(&v6->m_data.m_ihlIntrusive);
      v9 = v6->m_data.m_ihlIntrusive.m_hash.m_buckets;
      v6->m_data.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable;
      if ( v9 != v6->m_data.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
        operator delete[](v9);
      v6->m_data.m_ihlIntrusive.m_hash.m_buckets = 0;
      v6->m_data.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
      v6->m_data.m_ihlIntrusive.m_hash.m_numBuckets = 0;
      v6->m_data.m_ihlIntrusive.m_hash.m_numElements = 0;
      operator delete(v6);
    }
  }
}
// 7BE670: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (004DD760) --------------------------------------------------------  // acclient.c:268279
char __thiscall HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::push_tail(HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1> *this, const unsigned int *key, HashList<unsigned long,List<unsigned long>,1> *val)
{
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1> *v3; // edi@1
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  void *v6; // esi@4
  char result; // al@7
  void *v8; // eax@11
  char keya; // [sp+14h] [bp+4h]@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[*key % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != *key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::move_to_tail(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x88u);
    v6 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>(
        (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)((char *)v5 + 16),
        val->m_ihlIntrusive.m_hash.m_numBuckets);
      *((_DWORD *)v6 + 32) = 0;
      *((_DWORD *)v6 + 33) = 0;
      HashList<unsigned long,List<unsigned long>,1>::operator=(
        (HashList<unsigned long,List<unsigned long>,1> *)((char *)v6 + 16),
        (int)val);
    }
    else
    {
      v6 = 0;
    }
    result = IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::push_tail(
               &v3->m_ihlIntrusive,
               (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *)v6);
    keya = result;
    if ( !result && v6 )
    {
      IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)((char *)v6 + 16));
      v8 = (void *)*((_DWORD *)v6 + 28);
      *((_DWORD *)v6 + 4) = IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable;
      if ( v8 != (char *)v6 + 20 )
        operator delete[](v8);
      *((_DWORD *)v6 + 28) = 0;
      *((_DWORD *)v6 + 29) = 0;
      *((_DWORD *)v6 + 30) = 0;
      *((_DWORD *)v6 + 31) = 0;
      operator delete(v6);
      result = keya;
    }
  }
  return result;
}
// 7BE670: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable[3])(void *, char);

//----- (004DD850) --------------------------------------------------------  // acclient.c:268351
void __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::delete_contents(IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1> *this)
{
  DLListData *v1; // eax@1
  DLListData *v2; // edx@2
  DLListData *v3; // edx@4
  bool v4; // zf@4
  DLListData *v5; // edx@8

  do
  {
    v1 = this->m_list.head_;
    if ( !v1 )
      break;
    v2 = v1->dllist_prev;
    if ( v2 )
    {
      v2->dllist_next = v1->dllist_next;
    }
    else
    {
      v3 = v1->dllist_next;
      v4 = v1->dllist_next == 0;
      this->m_list.head_ = v1->dllist_next;
      if ( !v4 )
        v3->dllist_prev = 0;
    }
    if ( v1->dllist_next )
    {
      v1->dllist_next->dllist_prev = v1->dllist_prev;
    }
    else
    {
      v5 = this->m_list.tail_->dllist_prev;
      this->m_list.tail_ = v5;
      if ( v5 )
        v5->dllist_next = 0;
    }
    v1->dllist_next = 0;
    v1->dllist_prev = 0;
  }
  while ( v1 );
  IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::delete_contents(&this->m_hash);
}

//----- (004DD8B0) --------------------------------------------------------  // acclient.c:268396
void __thiscall gmKeyboardUI::InitOptions(gmKeyboardUI *this)
{
  gmKeyboardUI *v1; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // ebx@1
  int v6; // esi@7
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v7; // eax@8
  int v8; // eax@9
  HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *v9; // ebx@12
  unsigned int v10; // ebp@13
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v11; // eax@13
  int v12; // ecx@17
  unsigned int v13; // esi@18
  ActionMap *v14; // ebx@18
  unsigned int v15; // esi@19
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *v16; // edx@19
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *i; // edx@27
  int v18; // ebx@30
  HashList<unsigned long,List<unsigned long>,1>::HashListData *j; // edx@30
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v20; // esi@33
  ListNode<unsigned long> *v21; // eax@34
  void *v22; // ecx@36
  int k; // edx@42
  void *v24; // eax@46
  ListNode<unsigned long> *v25; // ecx@49
  DLListData *v26; // eax@51
  DLListData *v27; // eax@56
  unsigned int v28; // ebx@58
  int v29; // eax@59
  int v30; // esi@59
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v31; // eax@60
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v32; // ebp@64
  unsigned int v33; // ebx@65
  HashTableData<unsigned long,UIElement_ListBox *> *v34; // edx@65
  HashList<unsigned long,List<unsigned long>,1>::HashListData *v35; // eax@71
  unsigned int v36; // ebx@76
  int v37; // eax@76
  int v38; // edx@77
  UIElement_Text *v39; // esi@77
  PStringBase<unsigned short> *v40; // eax@79
  char *v41; // esi@79
  int v42; // eax@81
  ListNode<unsigned long> *v43; // eax@83
  ListNode<unsigned long> *v44; // ebp@83
  unsigned int v45; // esi@85
  char *v46; // esi@86
  int v47; // edx@87
  int v48; // eax@87
  int v49; // edx@87
  CInputMap *v50; // ecx@92
  ListNode<QualifiedControl> *v51; // eax@94
  void *v52; // ecx@96
  int v53; // edx@105
  char *v54; // esi@106
  int v55; // edx@108
  void *v56; // ecx@112
  DLListData *v57; // eax@118
  DLListData *v58; // eax@123
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **v59; // eax@127
  bool v60; // zf@127
  int (__thiscall **v61)(void *, char); // [sp-10h] [bp-314h]@94
  int v62; // [sp-Ch] [bp-310h]@94
  int v63; // [sp-8h] [bp-30Ch]@94
  unsigned int v64; // [sp-4h] [bp-308h]@13
  PStringBase<unsigned short> strName; // [sp+10h] [bp-2F4h]@18
  List<unsigned long> listInputActions; // [sp+14h] [bp-2F0h]@34
  unsigned int eMapID; // [sp+24h] [bp-2E0h]@13
  gmKeyboardUI *v68; // [sp+28h] [bp-2DCh]@1
  UIElement_ListBox *pListBox; // [sp+2Ch] [bp-2D8h]@19
  PStringBase<unsigned short> strDescription; // [sp+30h] [bp-2D4h]@85
  HashListIterator<HashList<unsigned long,List<unsigned long>,1> > mapHashIter; // [sp+34h] [bp-2D0h]@17
  List<QualifiedControl> qclDefaults; // [sp+3Ch] [bp-2C8h]@87
  ActionMap *pActionMap; // [sp+4Ch] [bp-2B8h]@7
  HashListIterator<HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1> > mapTableIter; // [sp+50h] [bp-2B4h]@12
  HashListIterator<HashList<unsigned long,List<unsigned long>,1> > hashIter; // [sp+58h] [bp-2ACh]@1
  HashList<unsigned long,List<unsigned long>,1> mapHash; // [sp+64h] [bp-2A0h]@13
  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1> hashActionClasses; // [sp+DCh] [bp-228h]@8
  StringInfo siInputMap; // [sp+154h] [bp-1B0h]@24
  StringInfo siDescription; // [sp+1E4h] [bp-120h]@87
  StringInfo siName; // [sp+274h] [bp-90h]@87

  v1 = this;
  v68 = this;
  gmKeyboardUI::UpdateKeymapFilenameLabel(this);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_UIOptionArray);
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_hashMappingListBoxes.m_intrusiveTable,
         (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&hashIter);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      UIElement_ListBox::Flush((UIElement_ListBox *)v3->m_data.vfptr);
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v3 = *v5;
        if ( *v5 )
          goto LABEL_2;
        break;
      }
    }
  }
  if ( ICIDM::s_cidm )
  {
    v6 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetActionMap)();
    pActionMap = (ActionMap *)v6;
    if ( v6 )
    {
      IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>(
        &hashActionClasses.m_ihlIntrusive.m_hash,
        0);
      hashActionClasses.m_ihlIntrusive.m_list.head_ = 0;
      hashActionClasses.m_ihlIntrusive.m_list.tail_ = 0;
      v7 = 0;
      if ( *(_DWORD *)(v6 + 156) > 0u )
      {
        v8 = *(_DWORD *)(v6 + 160);
        if ( v8 )
          v7 = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *)(v8 - 8);
        else
          v7 = 0;
      }
      v9 = v7;
      mapTableIter.m_iter.m_pData = v7;
      mapTableIter.m_iter.m_pHashList = (IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1> *)(v6 + 48);
      if ( v7 )
      {
        do
        {
          v10 = v9->m_hashKey;
          v64 = v9->m_data.m_ihlIntrusive.m_hash.m_numBuckets;
          eMapID = v10;
          IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>(
            (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)&mapHash,
            v64);
          mapHash.m_ihlIntrusive.m_list.head_ = 0;
          mapHash.m_ihlIntrusive.m_list.tail_ = 0;
          HashList<unsigned long,ActionMapValue,1>::operator=(
            (HashList<unsigned long,ActionMapValue,1> *)&mapHash,
            (int)&v9->m_data);
          v11 = 0;
          if ( mapHash.m_ihlIntrusive.m_hash.m_numElements > 0 )
          {
            if ( mapHash.m_ihlIntrusive.m_list.head_ )
              v11 = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)&mapHash.m_ihlIntrusive.m_list.head_[-1];
            else
              v11 = 0;
          }
          v12 = (int)v11;
          mapHashIter.m_iter.m_pData = v11;
          mapHashIter.m_iter.m_pHashList = (IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)&mapHash;
          if ( v11 )
          {
            do
            {
              v13 = *(_DWORD *)v12;
              v14 = pActionMap;
              strName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v13;
              if ( ActionMap::IsUserBindable(pActionMap, v13, v10) )
              {
                v15 = ActionMap::GetActionClass(v14, v13, v10);
                pListBox = (UIElement_ListBox *)v15;
                v16 = hashActionClasses.m_ihlIntrusive.m_hash.m_buckets[v15
                                                                      % hashActionClasses.m_ihlIntrusive.m_hash.m_numBuckets];
                if ( !v16 )
                  goto LABEL_24;
                while ( v16->m_hashKey != v15 )
                {
                  v16 = v16->m_hashNext;
                  if ( !v16 )
                    goto LABEL_24;
                }
                if ( !v16 )
                {
LABEL_24:
                  IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>(
                    (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)&siInputMap,
                    0);
                  siInputMap.m_variables.m_intrusiveTable.m_buckets = 0;
                  siInputMap.m_variables.m_intrusiveTable.m_firstInterestingBucket = 0;
                  HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::push_tail(
                    &hashActionClasses,
                    (const unsigned int *)&pListBox,
                    (HashList<unsigned long,List<unsigned long>,1> *)&siInputMap);
                  IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)&siInputMap);
                  siInputMap.m_strToken.m_charbuffer = (PSRefBufferCharData<char> *)IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable;
                  if ( (unsigned int *)siInputMap.m_variables.m_intrusiveTable.m_aInplaceBuckets[19] != &siInputMap.m_stringID )
                    operator delete[](siInputMap.m_variables.m_intrusiveTable.m_aInplaceBuckets[19]);
                  siInputMap.m_variables.m_intrusiveTable.m_aInplaceBuckets[19] = 0;
                  siInputMap.m_variables.m_intrusiveTable.m_aInplaceBuckets[20] = 0;
                  siInputMap.m_variables.m_intrusiveTable.m_aInplaceBuckets[21] = 0;
                  siInputMap.m_variables.m_intrusiveTable.m_aInplaceBuckets[22] = 0;
                }
                for ( i = hashActionClasses.m_ihlIntrusive.m_hash.m_buckets[v15
                                                                          % hashActionClasses.m_ihlIntrusive.m_hash.m_numBuckets];
                      i;
                      i = i->m_hashNext )
                {
                  if ( i->m_hashKey == v15 )
                    break;
                }
                v18 = (int)&i->m_data;
                for ( j = i->m_data.m_ihlIntrusive.m_hash.m_buckets[v10 % i->m_data.m_ihlIntrusive.m_hash.m_numBuckets];
                      j;
                      j = j->m_hashNext )
                {
                  if ( j->m_hashKey == v10 )
                    break;
                }
                v20 = j;
                hashIter.m_iter.m_pHashList = (IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)v18;
                if ( !j )
                {
                  listInputActions.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
                  listInputActions._head = 0;
                  listInputActions._tail = 0;
                  listInputActions._num_elements = 0;
                  HashList<unsigned long,List<unsigned long>,1>::push_tail(
                    (HashList<unsigned long,List<unsigned long>,1> *)v18,
                    &eMapID,
                    &listInputActions);
                  v21 = listInputActions._head;
                  listInputActions.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
                  while ( v21 )
                  {
                    v22 = v21;
                    v21 = v21->next;
                    listInputActions._head = v21;
                    if ( v21 )
                    {
                      v21->prev = 0;
                      v21 = listInputActions._head;
                    }
                    else
                    {
                      listInputActions._tail = 0;
                    }
                    if ( v22 )
                    {
                      operator delete(v22);
                      v21 = listInputActions._head;
                    }
                    --listInputActions._num_elements;
                  }
                  for ( k = *(_DWORD *)(*(_DWORD *)(v18 + 96) + 4 * (v10 % *(_DWORD *)(v18 + 104)));
                        k;
                        k = *(_DWORD *)(k + 4) )
                  {
                    if ( *(_DWORD *)k == v10 )
                      break;
                  }
                  v20 = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)k;
                  hashIter.m_iter.m_pHashList = (IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)v18;
                }
                v24 = operator new(0xCu);
                if ( v24 )
                {
                  *(_DWORD *)v24 = strName.m_charbuffer;
                  *((_DWORD *)v24 + 1) = 0;
                  *((_DWORD *)v24 + 2) = 0;
                  if ( v20->m_data._head )
                  {
                    v25 = v20->m_data._tail;
                    v25->next = (ListNode<unsigned long> *)v24;
                    *((_DWORD *)v24 + 2) = v25;
                  }
                  else
                  {
                    v20->m_data._head = (ListNode<unsigned long> *)v24;
                  }
                  v20->m_data._tail = (ListNode<unsigned long> *)v24;
                  ++v20->m_data._num_elements;
                }
              }
              v26 = mapHashIter.m_iter.m_pData->dllist_next;
              if ( !v26 )
                break;
              v12 = (int)&v26[-1];
              mapHashIter.m_iter.m_pData = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)&v26[-1];
            }
            while ( v26 != (DLListData *)8 );
            v9 = mapTableIter.m_iter.m_pData;
          }
          IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents((IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *)&mapHash);
          mapHash.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable;
          if ( (HashList<unsigned long,List<unsigned long>,1>::HashListData **)mapHash.m_ihlIntrusive.m_hash.m_buckets != mapHash.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
            operator delete[](mapHash.m_ihlIntrusive.m_hash.m_buckets);
          v27 = v9->dllist_next;
          mapHash.m_ihlIntrusive.m_hash.m_buckets = 0;
          mapHash.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
          mapHash.m_ihlIntrusive.m_hash.m_numBuckets = 0;
          mapHash.m_ihlIntrusive.m_hash.m_numElements = 0;
          if ( !v27 )
            break;
          v9 = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *)&v27[-1];
          mapTableIter.m_iter.m_pData = (HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *)&v27[-1];
        }
        while ( v27 != (DLListData *)8 );
      }
      v28 = DBObj::GetByEnum(268435457, 10, 0x1Du);
      eMapID = v28;
      if ( v28 )
      {
        v29 = DBObj::GetByEnum(1, 10, 0x1Du);
        v30 = v29;
        if ( !v29 )
        {
          IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::delete_contents(&hashActionClasses.m_ihlIntrusive);
          v59 = hashActionClasses.m_ihlIntrusive.m_hash.m_buckets;
          v60 = hashActionClasses.m_ihlIntrusive.m_hash.m_buckets == (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)hashActionClasses.m_ihlIntrusive.m_hash.m_aInplaceBuckets;
LABEL_128:
          hashActionClasses.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::vftable;
          if ( !v60 )
            operator delete[](v59);
          return;
        }
        CMasterInputMap::Merge((CMasterInputMap *)v28, (CMasterInputMap *)v29, 0);
        (*(void (__thiscall **)(int))(*(_DWORD *)v30 + 20))(v30);
        v31 = 0;
        if ( hashActionClasses.m_ihlIntrusive.m_hash.m_numElements > 0 )
        {
          if ( hashActionClasses.m_ihlIntrusive.m_list.head_ )
            v31 = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)&hashActionClasses.m_ihlIntrusive.m_list.head_[-1];
          else
            v31 = 0;
        }
        v32 = v31;
        hashIter.m_iter.m_pData = v31;
        hashIter.m_iter.m_pHashList = (IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)&hashActionClasses;
        if ( v31 )
        {
          do
          {
            v33 = v32->m_hashKey;
            IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>(
              &mapHash.m_ihlIntrusive.m_hash,
              (unsigned int)&v32[3].m_data._tail->data);
            mapHash.m_ihlIntrusive.m_list.head_ = 0;
            mapHash.m_ihlIntrusive.m_list.tail_ = 0;
            HashList<unsigned long,List<unsigned long>,1>::operator=(&mapHash, (int)&v32->m_data);
            v34 = v68->m_hashMappingListBoxes.m_intrusiveTable.m_buckets[v33
                                                                       % v68->m_hashMappingListBoxes.m_intrusiveTable.m_numBuckets];
            if ( !v34 )
              goto LABEL_68;
            while ( v34->m_hashKey != v33 )
            {
              v34 = v34->m_hashNext;
              if ( !v34 )
                goto LABEL_68;
            }
            if ( v34 )
            {
              pListBox = v34->m_data;
              v35 = 0;
              if ( mapHash.m_ihlIntrusive.m_hash.m_numElements > 0 )
              {
                if ( mapHash.m_ihlIntrusive.m_list.head_ )
                  v35 = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)&mapHash.m_ihlIntrusive.m_list.head_[-1];
                else
                  v35 = 0;
              }
              mapHashIter.m_iter.m_pData = v35;
              mapHashIter.m_iter.m_pHashList = (IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1> *)&mapHash;
              if ( v35 )
              {
                do
                {
                  v36 = mapHashIter.m_iter.m_pData->m_hashKey;
                  listInputActions.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
                  listInputActions._head = 0;
                  listInputActions._tail = 0;
                  listInputActions._num_elements = 0;
                  AC1Legacy::List<unsigned long>::operator=(
                    (List<SkillRecord *> *)&listInputActions,
                    (int)&mapHashIter.m_iter.m_pData->m_data);
                  v37 = UIElement_ListBox::AddItemFromTemplateList(pListBox, 0, 0);
                  if ( v37 )
                  {
                    v38 = *(_DWORD *)v37;
                    v64 = 12;
                    v39 = (UIElement_Text *)(*(int (__thiscall **)(int, signed int))(v38 + 148))(v37, 12);
                    if ( v39 )
                    {
                      gmKeyboardUI::GetStringInfoFromInputMapID(&siInputMap, v36);
                      if ( StringInfo::IsValid(&siInputMap, 1) )
                      {
                        v40 = StringInfo::GetString(&siInputMap, (PStringBase<unsigned short> *)&mapTableIter, 0);
                        UIElement_Text::SetText(v39, v40);
                        v41 = (char *)&mapTableIter.m_iter.m_pData[-1].m_data.m_ihlIntrusive.m_hash.m_firstInterestingBucket;
                        if ( !InterlockedDecrement((volatile LONG *)&mapTableIter.m_iter.m_pData[-1].m_data.m_ihlIntrusive.m_hash.m_numBuckets) )
                        {
                          if ( v41 )
                          {
                            v42 = *(_DWORD *)v41;
                            v64 = 1;
                            (*(void (__thiscall **)(char *, signed int))v42)(v41, 1);
                          }
                        }
                      }
                      StringInfo::~StringInfo(&siInputMap);
                    }
                  }
                  v43 = listInputActions._head;
                  v44 = listInputActions._head;
                  while ( v44 )
                  {
                    v45 = v44->data;
                    strName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                    strDescription.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                    if ( ActionMap::GetDescripValues(pActionMap, v45, v36, &strName, &strDescription) )
                    {
                      StringInfo::StringInfo(&siName);
                      StringInfo::SetLiteralValue(&siName, &strName, 1);
                      StringInfo::StringInfo(&siDescription);
                      StringInfo::SetLiteralValue(&siDescription, &strDescription, 1);
                      v47 = v36 % *(_DWORD *)(eMapID + 304);
                      v48 = *(_DWORD *)(eMapID + 296);
                      qclDefaults.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
                      qclDefaults._head = 0;
                      qclDefaults._tail = 0;
                      qclDefaults._num_elements = 0;
                      v49 = *(_DWORD *)(v48 + 4 * v47);
                      if ( v49 )
                      {
                        while ( *(_DWORD *)v49 != v36 )
                        {
                          v49 = *(_DWORD *)(v49 + 4);
                          if ( !v49 )
                            goto LABEL_94;
                        }
                        if ( v49 )
                        {
                          v50 = *(CInputMap **)(v49 + 16);
                          if ( v50 )
                            CInputMap::FindKeysForAction(v50, v45, &qclDefaults);
                        }
                      }
LABEL_94:
                      v61 = &List<QualifiedControl>::vftable;
                      v62 = 0;
                      v63 = 0;
                      v64 = 0;
                      List<QualifiedControl>::operator=((List<QualifiedControl> *)&v61, (int)&qclDefaults);
                      gmKeyboardUI::AddActionKeyMap(
                        v68,
                        pListBox,
                        v45,
                        v36,
                        &siName,
                        &siDescription,
                        *(List<QualifiedControl> *)&v61);
                      v51 = qclDefaults._head;
                      qclDefaults.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
                      while ( v51 )
                      {
                        v52 = v51;
                        v51 = v51->next;
                        qclDefaults._head = v51;
                        if ( v51 )
                        {
                          v51->prev = 0;
                          v51 = qclDefaults._head;
                        }
                        else
                        {
                          qclDefaults._tail = 0;
                        }
                        if ( v52 )
                        {
                          operator delete(v52);
                          v51 = qclDefaults._head;
                        }
                        --qclDefaults._num_elements;
                      }
                      StringInfo::~StringInfo(&siDescription);
                      StringInfo::~StringInfo(&siName);
                      v46 = (char *)&strDescription.m_charbuffer[-1].m_data[6];
                      v64 = (unsigned int)&strDescription.m_charbuffer[-1].m_data[8];
                    }
                    else
                    {
                      v46 = (char *)&strDescription.m_charbuffer[-1].m_data[6];
                      v64 = (unsigned int)&strDescription.m_charbuffer[-1].m_data[8];
                    }
                    if ( !InterlockedDecrement((volatile LONG *)v64) && v46 )
                    {
                      v53 = *(_DWORD *)v46;
                      v64 = 1;
                      (*(void (__thiscall **)(char *, signed int))v53)(v46, 1);
                    }
                    v54 = (char *)&strName.m_charbuffer[-1].m_data[6];
                    if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1].m_data[8]) && v54 )
                    {
                      v55 = *(_DWORD *)v54;
                      v64 = 1;
                      (*(void (__thiscall **)(char *, signed int))v55)(v54, 1);
                    }
                    v44 = v44->next;
                    v43 = listInputActions._head;
                  }
                  listInputActions.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
                  while ( v43 )
                  {
                    v56 = v43;
                    v43 = v43->next;
                    listInputActions._head = v43;
                    if ( v43 )
                    {
                      v43->prev = 0;
                      v43 = listInputActions._head;
                    }
                    else
                    {
                      listInputActions._tail = 0;
                    }
                    if ( v56 )
                    {
                      operator delete(v56);
                      v43 = listInputActions._head;
                    }
                    --listInputActions._num_elements;
                  }
                  v57 = mapHashIter.m_iter.m_pData->dllist_next;
                  if ( !v57 )
                    break;
                  mapHashIter.m_iter.m_pData = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)&v57[-1];
                }
                while ( v57 != (DLListData *)8 );
              }
              IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents(&mapHash.m_ihlIntrusive);
              mapHash.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable;
              if ( (HashList<unsigned long,List<unsigned long>,1>::HashListData **)mapHash.m_ihlIntrusive.m_hash.m_buckets != mapHash.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
                operator delete[](mapHash.m_ihlIntrusive.m_hash.m_buckets);
              v32 = hashIter.m_iter.m_pData;
            }
            else
            {
LABEL_68:
              IntrusiveHashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::delete_contents(&mapHash.m_ihlIntrusive);
              mapHash.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable;
              if ( (HashList<unsigned long,List<unsigned long>,1>::HashListData **)mapHash.m_ihlIntrusive.m_hash.m_buckets != mapHash.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
                operator delete[](mapHash.m_ihlIntrusive.m_hash.m_buckets);
            }
            v58 = v32->dllist_next;
            mapHash.m_ihlIntrusive.m_hash.m_buckets = 0;
            mapHash.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
            mapHash.m_ihlIntrusive.m_hash.m_numBuckets = 0;
            mapHash.m_ihlIntrusive.m_hash.m_numElements = 0;
            if ( !v58 )
              break;
            v32 = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)&v58[-1];
            hashIter.m_iter.m_pData = (HashList<unsigned long,List<unsigned long>,1>::HashListData *)&v58[-1];
          }
          while ( v58 != (DLListData *)8 );
          v28 = eMapID;
        }
        (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v28 + 20))(v28);
        ((void (*)(void))v68->vfptr[26].__vecDelDtor)();
      }
      IntrusiveHashList<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::delete_contents(&hashActionClasses.m_ihlIntrusive);
      v59 = hashActionClasses.m_ihlIntrusive.m_hash.m_buckets;
      v60 = hashActionClasses.m_ihlIntrusive.m_hash.m_buckets == (HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData **)hashActionClasses.m_ihlIntrusive.m_hash.m_aInplaceBuckets;
      goto LABEL_128;
    }
  }
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);
// 7A2BE8: using guessed type int (__thiscall *List<QualifiedControl>::vftable)(void *, char);
// 7BE66C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char);
// 7BE670: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable[3])(void *, char);
// 7BE674: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::vftable[2])(void *, char);

//----- (006A0020) --------------------------------------------------------  // acclient.c:696427
void __thiscall IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1> *this)
{
  DLListData *v1; // eax@1
  DLListData *v2; // edx@2
  DLListData *v3; // edx@4
  bool v4; // zf@4
  DLListData *v5; // edx@8

  do
  {
    v1 = this->m_list.head_;
    if ( !v1 )
      break;
    v2 = v1->dllist_prev;
    if ( v2 )
    {
      v2->dllist_next = v1->dllist_next;
    }
    else
    {
      v3 = v1->dllist_next;
      v4 = v1->dllist_next == 0;
      this->m_list.head_ = v1->dllist_next;
      if ( !v4 )
        v3->dllist_prev = 0;
    }
    if ( v1->dllist_next )
    {
      v1->dllist_next->dllist_prev = v1->dllist_prev;
    }
    else
    {
      v5 = this->m_list.tail_->dllist_prev;
      this->m_list.tail_ = v5;
      if ( v5 )
        v5->dllist_next = 0;
    }
    v1->dllist_next = 0;
    v1->dllist_prev = 0;
  }
  while ( v1 );
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)this);
}

//----- (006F5780) --------------------------------------------------------  // acclient.c:777969
void sub_6F5780()
{
  flt_840490 = 1000.0 + 1.0;
}

//----- (006F57A0) --------------------------------------------------------  // acclient.c:777975
void _E93_87()
{
  flt_840494 = 24.0 * 8.0;
}

//----- (006F57C0) --------------------------------------------------------  // acclient.c:777981
void _E95_87()
{
  flt_840498 = 24.0 * 0.5;
}

//----- (006F57E0) --------------------------------------------------------  // acclient.c:777987
int sub_6F57E0()
{
  return atexit(nullsub_628);
}

//----- (006F57F0) --------------------------------------------------------  // acclient.c:777993
int sub_6F57F0()
{
  return atexit(nullsub_629);
}

//----- (006F5800) --------------------------------------------------------  // acclient.c:777999
int _E103_97()
{
  return atexit(nullsub_630);
}

//----- (006F5810) --------------------------------------------------------  // acclient.c:778005
int _E106_70()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_39, "None");
  return atexit(_E107_76);
}

//----- (006F5830) --------------------------------------------------------  // acclient.c:778012
int _E109_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_39, "Speed");
  return atexit(sub_762990);
}

//----- (006F5850) --------------------------------------------------------  // acclient.c:778019
int _E112_62()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_39, "Noise");
  return atexit(_E113_51);
}

//----- (006F5870) --------------------------------------------------------  // acclient.c:778026
int _E115_46()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_39, "Sine");
  return atexit(_E116_43);
}

//----- (006F5890) --------------------------------------------------------  // acclient.c:778033
int _E118_48()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_39, "Square");
  return atexit(_E119_76);
}

//----- (006F58B0) --------------------------------------------------------  // acclient.c:778040
int _E121_46()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_39, "Bounce");
  return atexit(_E122_77);
}

//----- (006F58D0) --------------------------------------------------------  // acclient.c:778047
int _E124_44()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_39, "Perlin");
  return atexit(_E125_50);
}

//----- (006F58F0) --------------------------------------------------------  // acclient.c:778054
int _E127_38()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_39, "Fractal");
  return atexit(_E128_48);
}

//----- (006F5910) --------------------------------------------------------  // acclient.c:778061
int _E130_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_39, "FrameLoop");
  return atexit(_E131_37);
}

//----- (006F5930) --------------------------------------------------------  // acclient.c:778068
void _E133_25()
{
  LOWEST_DATA_RATE_96 = 1024;
}

//----- (006F5940) --------------------------------------------------------  // acclient.c:778074
void _E135_20()
{
  HIGHEST_DATA_RATE_96 = 0x7FFF;
}

//----- (006F5950) --------------------------------------------------------  // acclient.c:778080
int _E137_5()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_96;
  INITIAL_MAX_DATA_RATE_44 = LOWEST_DATA_RATE_96;
  return result;
}

//----- (006F5960) --------------------------------------------------------  // acclient.c:778090
void _E139_20()
{
  DEFAULT_VIEW_RADIUS_71 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F5980) --------------------------------------------------------  // acclient.c:778096
void _E141_19()
{
  MIN_QUANTUM_71 = 1.0 / 30.0;
}

//----- (006F59A0) --------------------------------------------------------  // acclient.c:778102
void _E143_4()
{
  MAX_QUANTUM_71 = 1.0 / 5.0;
}

//----- (006F59C0) --------------------------------------------------------  // acclient.c:778108
void _E145_19()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8404E0, PFID_A8R8G8B8);
}

//----- (006F59D0) --------------------------------------------------------  // acclient.c:778114
int _E148_20()
{
  return atexit(_E149_24);
}

//----- (006F59E0) --------------------------------------------------------  // acclient.c:778120
unsigned int _E151_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_KeyMapCantOverwriteReadOnlyKeymap_Label");
  ID_KeyMapCantOverwriteReadOnlyKeymap_Label = result;
  return result;
}

//----- (006F5A00) --------------------------------------------------------  // acclient.c:778130
unsigned int _E153_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_KeyMapLoadKeymap_Label");
  ID_KeyMapLoadKeymap_Label = result;
  return result;
}

//----- (006F5A20) --------------------------------------------------------  // acclient.c:778140
unsigned int _E155_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_KeyMapOverwriteKeymap_Label");
  ID_KeyMapOverwriteKeymap_Label = result;
  return result;
}

//----- (006F5A40) --------------------------------------------------------  // acclient.c:778150
unsigned int _E157_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_KeyMapSaveKeymap_Label");
  ID_KeyMapSaveKeymap_Label = result;
  return result;
}

//----- (006F5A60) --------------------------------------------------------  // acclient.c:778160
unsigned int _E159_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("KEYMAP");
  KEYMAP = result;
  return result;
}

//----- (006F5A80) --------------------------------------------------------  // acclient.c:778170
int sub_6F5A80()
{
  return atexit(nullsub_627);
}

//----- (00762960) --------------------------------------------------------  // acclient.c:889717
void __cdecl _E107_76()
{
  char *v0; // esi@1

  v0 = &waveform_None_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762990) --------------------------------------------------------  // acclient.c:889730
void __cdecl sub_762990()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007629C0) --------------------------------------------------------  // acclient.c:889743
void __cdecl _E113_51()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007629F0) --------------------------------------------------------  // acclient.c:889756
void __cdecl _E116_43()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762A20) --------------------------------------------------------  // acclient.c:889769
void __cdecl _E119_76()
{
  char *v0; // esi@1

  v0 = &waveform_Square_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762A50) --------------------------------------------------------  // acclient.c:889782
void __cdecl _E122_77()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762A80) --------------------------------------------------------  // acclient.c:889795
void __cdecl _E125_50()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762AB0) --------------------------------------------------------  // acclient.c:889808
void __cdecl _E128_48()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762AE0) --------------------------------------------------------  // acclient.c:889821
void __cdecl _E131_37()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

