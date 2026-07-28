/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSpellComponentUI
   Object     : GAME\game_ui_misc\gmSpellComponentUI.obj
   Functions  : 48
   Addresses  : 00489B90 - 006EDC70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00489B90) --------------------------------------------------------  // acclient.c:197326
__int32 __thiscall PStringBase<unsigned short>::to_int32(PStringBase<unsigned short> *this)
{
  PSRefBufferCharData<unsigned short> *v1; // esi@1

  v1 = this->m_charbuffer;
  *__errno() = 0;
  return _wcstol(v1->m_data, 0, 0);
}

//----- (00489BB0) --------------------------------------------------------  // acclient.c:197336
void __thiscall SpellComponentBase::SpellComponentBase(SpellComponentBase *this)
{
  SpellComponentBase *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&SpellComponentBase::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  SpellComponentBase::Init(v1);
}
// 7A33CC: using guessed type int (__thiscall *SpellComponentBase::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00489BF0) --------------------------------------------------------  // acclient.c:197356
void __thiscall SpellComponentBase::~SpellComponentBase(SpellComponentBase *this)
{
  SpellComponentBase *v1; // edi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@4

  v1 = this;
  v2 = this->_text.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00489C40) --------------------------------------------------------  // acclient.c:197374
void __thiscall gmSpellComponentUI::RecvNotice_SelectionChanged(gmSpellComponentUI *this)
{
  unsigned int v1; // ebx@1
  unsigned int v2; // ebp@1
  gmSpellComponentUI *v3; // esi@1
  CPlayerSystem *v4; // eax@2
  ComponentTracker *v5; // eax@2
  bool v6; // zf@3
  HashSet<UIElement *>Vtbl *v7; // eax@3
  UIElement *v8; // eax@6
  UIElement *v9; // edi@6
  UIElement_ListBox *v10; // ecx@11
  UIElement_ListBox *v11; // ecx@13
  IDClass<_tagDataID,32,0> selCompClassID; // [sp+10h] [bp-8h]@3
  IDClass<_tagDataID,32,0> didComponentClass; // [sp+14h] [bp-4h]@7

  v1 = ACCWeenieObject::selectedID;
  v2 = 0;
  v3 = this;
  if ( ACCWeenieObject::selectedID == Formatted )
  {
LABEL_13:
    v11 = (UIElement_ListBox *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
    LOBYTE(v3->m_ptTilingOffset.x) = 0;
    UIElement_ListBox::SetSelectedItem(v11, 0, 1);
    v3->m_hashElementsRegisteredWith.vfptr = 0;
    return;
  }
  v4 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::GetComponentTracker(v4);
  if ( !v5 )
    return;
  selCompClassID.id = clsID.id;
  v6 = ComponentTracker::ObjectIsOwnedComponent(v5, v1, &selCompClassID) == 0;
  v7 = v3->m_hashElementsRegisteredWith.vfptr;
  if ( v6 )
  {
    if ( !v7 )
      return;
    goto LABEL_13;
  }
  if ( (HashSet<UIElement *>Vtbl *)v1 != v7
    && (signed int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[388].__vecDelDtor > 0 )
  {
    while ( 1 )
    {
      v8 = UIElement_ListBox::GetItem((UIElement_ListBox *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr, v2);
      v9 = v8;
      if ( v8->m_desc.m_elementID == 268436583
        && UIElement::GetAttribute_DataID(v8, 0x1000004Cu, &didComponentClass)
        && selCompClassID.id == didComponentClass.id )
        break;
      ++v2;
      if ( (signed int)v2 >= (signed int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[388].__vecDelDtor )
        return;
    }
    v10 = (UIElement_ListBox *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
    LOBYTE(v3->m_ptTilingOffset.x) = 0;
    UIElement_ListBox::SetSelectedItem(v10, v9, 1);
    v3->m_hashElementsRegisteredWith.vfptr = (HashSet<UIElement *>Vtbl *)v1;
  }
}

//----- (00489D30) --------------------------------------------------------  // acclient.c:197438
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vector_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0> *v2; // esi@1
  HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable;
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
// 7A33E0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable[2])(void *, char);

//----- (00489DC0) --------------------------------------------------------  // acclient.c:197479
SpellComponentBase *__thiscall SpellComponentBase::scalar_deleting_destructor(SpellComponentBase *this, unsigned int a2)
{
  SpellComponentBase *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@4

  v2 = this;
  v3 = this->_text.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = v2->_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00489E20) --------------------------------------------------------  // acclient.c:197500
int __thiscall SpellComponentBase::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@1
  int v4; // eax@5
  int v5; // ebx@6
  int v6; // eax@10

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v4;
    InterlockedIncrement((volatile LONG *)(v4 + 4));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  v5 = *(_DWORD *)(v2 + 28);
  if ( v5 != *(_DWORD *)(a2 + 28) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(v2 + 28) = v6;
    InterlockedIncrement((volatile LONG *)(v6 + 4));
  }
  *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
  return v2;
}

//----- (00489EC0) --------------------------------------------------------  // acclient.c:197537
int __thiscall SpellComponentTable::InqSpellComponentBase(SpellComponentTable *this, const unsigned int key, SpellComponentBase *sbase)
{
  unsigned int v3; // esi@1
  PackableHashData<unsigned long,SpellComponentBase> **v4; // ecx@2
  PackableHashData<unsigned long,SpellComponentBase> *v5; // edx@3
  int result; // eax@6

  v3 = this->_spellComponentBaseHash._table_size;
  if ( !v3 )
    goto LABEL_12;
  v4 = this->_spellComponentBaseHash._buckets;
  if ( !v4 )
    goto LABEL_12;
  v5 = v4[key % v3];
  if ( !v5 )
    goto LABEL_12;
  while ( key != v5->_key )
  {
    v5 = v5->_next;
    if ( !v5 )
      return 0;
  }
  if ( v5 != (PackableHashData<unsigned long,SpellComponentBase> *)-4 )
  {
    SpellComponentBase::operator=((int)sbase, (int)&v5->_data);
    result = 1;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  return result;
}

//----- (00489F20) --------------------------------------------------------  // acclient.c:197573
void __stdcall gmSpellComponentUI::MakeIcon(IDClass<_tagDataID,32,0> didComponent, UIElement *pIconElement)
{
  ClientMagicSystem *v3; // eax@2
  SpellComponentTable *v4; // esi@2
  const unsigned int v5; // edi@3
  unsigned int v6; // esi@4
  ClientMagicSystem *v7; // eax@5
  Graphic *v8; // esi@6
  Graphic *v9; // eax@7
  Graphic *v10; // eax@8
  SpellComponentBase sCB; // [sp+4h] [bp-24h]@3

  if ( pIconElement )
  {
    v3 = ClientMagicSystem::GetMagicSystem();
    v4 = ClientMagicSystem::GetSpellComponentTable(v3);
    if ( v4 )
    {
      v5 = SpellComponentTable::WCIDtoSCID(didComponent);
      SpellComponentBase::SpellComponentBase(&sCB);
      if ( SpellComponentTable::InqSpellComponentBase(v4, v5, &sCB) )
      {
        v6 = sCB._iconID.id;
        if ( sCB._iconID.id != clsID.id )
        {
          UIRegion::ClearImage((UIRegion *)&pIconElement->vfptr);
          v7 = ClientMagicSystem::GetMagicSystem();
          if ( v7 )
          {
            v8 = ClientMagicSystem::GetSpellComponentIcon(v7, (IDClass<_tagDataID,32,0>)v6);
            if ( v8 )
            {
              UIRegion::SetBlitMode((UIRegion *)&pIconElement->vfptr, Blit_3Alpha);
              v9 = (Graphic *)operator new(0xCu);
              if ( v9 )
                Graphic::Graphic(v9, v8);
              else
                v10 = 0;
              UIRegion::SetImage((UIRegion *)&pIconElement->vfptr, v10);
            }
          }
        }
      }
      SpellComponentBase::~SpellComponentBase(&sCB);
    }
  }
}

//----- (00489FE0) --------------------------------------------------------  // acclient.c:197622
void __thiscall gmSpellComponentUI::UpdateBuyRates(gmSpellComponentUI *this, IDClass<_tagDataID,32,0> clsID)
{
  gmSpellComponentUI *v2; // ebx@1
  CPlayerSystem *v3; // eax@3
  unsigned int v4; // ebp@3
  UIElement_ListBox *v5; // ecx@3
  unsigned int v6; // edi@3
  UIElement *v7; // eax@4
  UIElement *v8; // esi@4
  CPlayerSystem *v9; // eax@11
  int v10; // eax@11
  int v11; // eax@13
  CPlayerSystem *v12; // eax@16
  CPlayerSystem *v13; // eax@16
  int v14; // eax@16
  UIElement *v15; // eax@16
  UIElement_Text *v16; // eax@17
  char *v17; // esi@19
  PStringBase<unsigned short> strAmount; // [sp+4h] [bp-4h]@1

  strAmount.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  if ( CPlayerSystem::GetPlayerSystem()->player_desc_received )
  {
    if ( v2->m_pComponentListBox )
    {
      v3 = CPlayerSystem::GetPlayerSystem();
      v4 = clsID.id;
      PlayerModule::GetDesiredCompLevel((PlayerModule *)&v3->playerModule.vfptr, clsID);
      v5 = v2->m_pComponentListBox;
      v6 = 0;
      if ( (signed int)v5->m_listItems.m_num > 0 )
      {
        while ( 1 )
        {
          v7 = UIElement_ListBox::GetItem(v5, v6);
          v8 = v7;
          if ( v7 )
          {
            if ( v7->m_desc.m_elementID == 268436583
              && UIElement::GetAttribute_DataID(v7, 0x1000004Cu, &clsID)
              && (v4 == ::clsID.id || clsID.id == v4) )
              break;
          }
          v5 = v2->m_pComponentListBox;
          ++v6;
          if ( (signed int)v6 >= (signed int)v5->m_listItems.m_num )
            return;
        }
        v9 = CPlayerSystem::GetPlayerSystem();
        v10 = PlayerModule::GetDesiredCompLevel((PlayerModule *)&v9->playerModule.vfptr, clsID);
        if ( v10 < 0 || v10 > 5000 )
        {
          CM_Character::Event_SetDesiredComponentLevel(clsID, 0);
          v12 = CPlayerSystem::GetPlayerSystem();
          PlayerModule::SetDesiredCompLevel((PlayerModule *)&v12->playerModule.vfptr, clsID, 0);
          v13 = CPlayerSystem::GetPlayerSystem();
          v14 = PlayerModule::GetDesiredCompLevel((PlayerModule *)&v13->playerModule.vfptr, clsID);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&strAmount, 0, L"%d", v14);
          v15 = UIElement::GetChildRecursive(v8, 0x1000046Bu);
          if ( v15 )
          {
            v16 = (UIElement_Text *)v15->vfptr[12].OnAction((IInputActionCallback *)v15, (InputEvent *)12);
            if ( v16 )
              UIElement_Text::SetText(v16, &strAmount);
          }
          v17 = (char *)&strAmount.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&strAmount.m_charbuffer[-1].m_data[8]) && v17 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
        }
        else
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&strAmount, 0, L"%d", v10);
          v11 = UIElement::GetChildRecursiveTemplate<UIElement_Text>(v8, 0x1000046Bu);
          if ( v11 )
            UIElement_Text::SetText((UIElement_Text *)v11, &strAmount);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strAmount);
        }
      }
    }
  }
}

//----- (0048A190) --------------------------------------------------------  // acclient.c:197706
void __usercall gmSpellComponentUI::PostInit(gmSpellComponentUI *this@<ecx>, int a2@<esi>, int a3)
{
  signed int v3; // eax@4
  UIElement *v4; // eax@7
  int v5; // eax@8
  GlobalEventHandler *v6; // esi@10
  int v7; // eax@12
  int v8; // eax@15
  int v9; // eax@18
  int v10; // [sp+14h] [bp-8h]@1
  UIElement *v11; // [sp+18h] [bp-4h]@1

  v10 = a2;
  v11 = (UIElement *)this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  if ( ((unsigned int)v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] & 0x7FFFFFFF) >= 7 )
  {
    v3 = 7;
    if ( v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4] > (HashSetData<UIElement *> *)7 )
    {
      do
        *((_DWORD *)&v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]->m_hashKey + v3++) = 0;
      while ( (HashSetData<UIElement *> *)v3 < v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4] );
    }
  }
  else if ( !SmartArray<int,1>::grow(
               (SmartArray<QuickButton *,1> *)&v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2],
               7u) )
  {
    goto LABEL_7;
  }
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4] = (HashSetData<UIElement *> *)7;
LABEL_7:
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]->m_hashKey = (UIElement *)ID_SpellComp_Category_Scarabs;
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]->m_hashNext = (HashSetData<UIElement *> *)ID_SpellComp_Category_Herbs;
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][1].m_hashKey = (UIElement *)ID_SpellComp_Category_Gems;
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][1].m_hashNext = (HashSetData<UIElement *> *)ID_SpellComp_Category_Alchemical;
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][2].m_hashKey = (UIElement *)ID_SpellComp_Category_Talismans;
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][2].m_hashNext = (HashSetData<UIElement *> *)ID_SpellComp_Category_Tapers;
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][3].m_hashKey = (UIElement *)ID_SpellComp_Category_Peas;
  v4 = UIElement::GetChildRecursive(v11, 0x10000464u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)5);
  else
    v5 = 0;
  v11[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = (HashSetData<UIElement *> *)v5;
  v6 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v6 )
  {
    if ( v11 )
      v7 = (int)&v11[1].m_hashElementsRegisteredWith.m_intrusiveTable;
    else
      v7 = 0;
    ((void (__thiscall *)(GlobalEventHandler *, _UNKNOWN *, int, int, UIElement *))v6->vfptr->RegisterNoticeHandler)(
      v6,
      &loc_4DD255,
      v7,
      v10,
      v11);
    if ( a3 )
      v8 = a3 + 1528;
    else
      v8 = 0;
    v6->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v6, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v8);
    if ( a3 )
      v9 = a3 + 1528;
    else
      v9 = 0;
    v11 = (UIElement *)v9;
    ((void (__thiscall *)(GlobalEventHandler *))v6->vfptr->RegisterNoticeHandler)(v6);
  }
  if ( CPlayerSystem::GetPlayerSystem()->player_desc_received )
    gmSpellComponentUI::UpdateBuyRates((gmSpellComponentUI *)v11, clsID);
}
// 48A190: could not find valid save-restore pair for esi

//----- (0048A320) --------------------------------------------------------  // acclient.c:197783
void __thiscall gmSpellComponentUI::RecvNotice_PlayerDescReceived(gmSpellComponentUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmSpellComponentUI::UpdateBuyRates((gmSpellComponentUI *)((char *)this - 1528), clsID);
}

//----- (0048A340) --------------------------------------------------------  // acclient.c:197789
char __thiscall HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::find(HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0> *this, IDClass<_tagDataID,32,0> *_key, SpellComponentRegion **_retval)
{
  HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *v3; // eax@1
  char result; // al@4

  v3 = this->m_intrusiveTable.m_buckets[_key->id % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey.id != _key->id )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    *_retval = v3->m_data;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0048A390) --------------------------------------------------------  // acclient.c:197817
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7A33E0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable[2])(void *, char);

//----- (0048A420) --------------------------------------------------------  // acclient.c:197850
UIElementMessageListenResult __thiscall gmSpellComponentUI::ListenToElementMessage(gmSpellComponentUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebp@1
  unsigned int v3; // eax@1
  gmSpellComponentUI *v4; // ebx@1
  int v5; // eax@5
  UIElement *v6; // edi@5
  UIElement_Text *v7; // esi@8
  PStringBase<unsigned short> *v8; // eax@9
  __int32 v9; // ebx@9
  CPlayerSystem *v10; // eax@11
  UIElementMessageListenResult v11; // eax@11
  CPlayerSystem *v12; // eax@12
  int v13; // eax@12
  int v14; // eax@12
  UIElement *v15; // ecx@17
  unsigned int v16; // eax@18
  unsigned int v17; // [sp-8h] [bp-24h]@19
  PStringBase<unsigned short> strAmount; // [sp+10h] [bp-Ch]@12
  SpellComponentRegion *pRegion; // [sp+14h] [bp-8h]@1
  PStringBase<unsigned short> result; // [sp+18h] [bp-4h]@9

  v2 = i_rMsg;
  v3 = i_rMsg->idMessage;
  v4 = this;
  pRegion = (SpellComponentRegion *)this;
  if ( v3 == 4 )
  {
    if ( !i_rMsg->dwParam1 )
      return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
    if ( this->m_bBroadcastSelection )
    {
      v15 = this->m_pComponentListBox->m_pSelectedItem;
      if ( v15 )
      {
        v16 = v15->m_desc.m_elementID;
        if ( v16 == 268436582 )
        {
          v17 = 0;
        }
        else
        {
          if ( v16 != 268436583
            || !UIElement::GetAttribute_DataID(v15, 0x1000004Cu, (IDClass<_tagDataID,32,0> *)&i_rMsg)
            || !HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::find(
                  &v4->m_hashComponentRegions,
                  (IDClass<_tagDataID,32,0> *)&i_rMsg,
                  &pRegion)
            || !pRegion )
            goto LABEL_26;
          v17 = pRegion->objectID;
        }
        ACCWeenieObject::SetSelectedObject(v17, 0);
      }
    }
LABEL_26:
    v4->m_bBroadcastSelection = 1;
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  }
  if ( v3 != 47 )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  if ( i_rMsg->dwParam1 )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  if ( i_rMsg->idElement != 268436587 )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  v5 = ((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)();
  v6 = (UIElement *)v5;
  if ( !v5 )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  if ( *(_DWORD *)(v5 + 740) != 268436583 )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  if ( !UIElement::GetAttribute_DataID((UIElement *)v5, 0x1000004Cu, (IDClass<_tagDataID,32,0> *)&i_rMsg) )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  v7 = (UIElement_Text *)((int (__stdcall *)(signed int))v2->pElement->vfptr[12].OnAction)(12);
  if ( !v7 )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  v8 = UIElement_Text::GetText(v7, &result);
  v9 = PStringBase<unsigned short>::to_int32(v8);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
  if ( v9 < 0 || v9 > 5000 )
  {
    v12 = CPlayerSystem::GetPlayerSystem();
    v13 = PlayerModule::GetDesiredCompLevel((PlayerModule *)&v12->playerModule.vfptr, (IDClass<_tagDataID,32,0>)i_rMsg);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&strAmount, 0, L"%d", v13);
    UIElement_Text::SetText(v7, &strAmount);
    v14 = UIElement::GetChildRecursiveTemplate<UIElement_Text>(v6, 0x1000046Bu);
    if ( v14 )
      UIElement_Text::SetText((UIElement_Text *)v14, &strAmount);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strAmount);
    v11 = UIElement::ListenToElementMessage((UIElement *)pRegion, v2);
  }
  else
  {
    CM_Character::Event_SetDesiredComponentLevel((IDClass<_tagDataID,32,0>)i_rMsg, v9);
    v10 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetDesiredCompLevel((PlayerModule *)&v10->playerModule.vfptr, (IDClass<_tagDataID,32,0>)i_rMsg, v9);
    v11 = UIElement::ListenToElementMessage((UIElement *)pRegion, v2);
  }
  return v11;
}

//----- (0048A620) --------------------------------------------------------  // acclient.c:197952
void __thiscall gmSpellComponentUI::SyncComponentRegionWithData(gmSpellComponentUI *this, UIElement *pListBoxEntry, ComponentData *i_pData)
{
  UIElement *v3; // ebx@1
  gmSpellComponentUI *v4; // esi@1
  UIElement *v5; // ecx@2
  SpellComponentRegion *v6; // esi@3
  ComponentData *v7; // edi@3
  unsigned int v8; // eax@5
  UIElement *v9; // eax@7
  UIElement_Text *v10; // esi@8
  PStringBase<unsigned short> *v11; // eax@9
  char *v12; // esi@9
  SpellComponentRegion *region; // [sp+0h] [bp-4h]@1

  region = (SpellComponentRegion *)this;
  v3 = pListBoxEntry;
  v4 = this;
  if ( pListBoxEntry )
  {
    v5 = pListBoxEntry;
    pListBoxEntry = (UIElement *)clsID.id;
    UIElement::GetAttribute_DataID(v5, 0x1000004Cu, (IDClass<_tagDataID,32,0> *)&pListBoxEntry);
    if ( HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::find(
           &v4->m_hashComponentRegions,
           (IDClass<_tagDataID,32,0> *)&pListBoxEntry,
           &region) )
    {
      v6 = region;
      v7 = i_pData;
      if ( v6->objectID != ComponentData::GetFirstObjectID(i_pData) )
        v6->objectID = ComponentData::GetFirstObjectID(v7);
      v8 = v7->numItems;
      if ( v6->numItems != v8 )
        v6->numItems = v8;
      v9 = UIElement::GetChildRecursive(v3, 0x1000046Au);
      if ( v9 )
      {
        v10 = (UIElement_Text *)v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)12);
        if ( v10 )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (PStringBase<unsigned short> *)&i_pData,
            0,
            L"%d",
            v7->numItems);
          UIElement_Text::SetText(v10, v11);
          v12 = (char *)&i_pData[-1].objects.m_intrusiveTable.m_buckets;
          if ( !InterlockedDecrement((volatile LONG *)&i_pData[-1].objects.m_intrusiveTable.m_firstInterestingBucket) )
          {
            if ( v12 )
              (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
          }
        }
      }
    }
  }
}

//----- (0048A710) --------------------------------------------------------  // acclient.c:198011
HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0> *__thiscall HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::scalar_deleting_destructor(HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0> *this, unsigned int a2)
{
  HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable;
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
// 7A33E0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable[2])(void *, char);
// 7A33E4: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::vftable)(void *, char);

//----- (0048A770) --------------------------------------------------------  // acclient.c:198037
void __userpurge gmSpellComponentUI::gmSpellComponentUI(gmSpellComponentUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSpellComponentUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSpellComponentUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSpellComponentUI::vftable;
  v4->selObjectID = 0;
  v4->m_pComponentListBox = 0;
  v4->m_aCategoryTitles.m_data = 0;
  v4->m_aCategoryTitles.m_sizeAndDeallocate = 0;
  v4->m_aCategoryTitles.m_num = 0;
  v4->m_hashComponentRegions.vfptr = (HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>(
    &v4->m_hashComponentRegions.m_intrusiveTable,
    0x17u);
  v4->m_bBroadcastSelection = 1;
}
// 7A33E4: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::vftable)(void *, char);
// 7A33E8: using guessed type bool (__thiscall *gmSpellComponentUI::vftable)(DBCache *this);
// 7A3690: using guessed type int (__thiscall *gmSpellComponentUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048A7F0) --------------------------------------------------------  // acclient.c:198063
gmSpellComponentUI *__thiscall gmSpellComponentUI::DynamicCast(gmSpellComponentUI *this, unsigned int i_eType)
{
  gmSpellComponentUI *result; // eax@1

  result = this;
  if ( i_eType != 268435503 )
    result = (gmSpellComponentUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0048A810) --------------------------------------------------------  // acclient.c:198074
signed int gmSpellComponentUI::GetUIElementType()
{
  return 268435503;
}

//----- (0048A820) --------------------------------------------------------  // acclient.c:198080
void __thiscall gmSpellComponentUI::~gmSpellComponentUI(gmSpellComponentUI *this)
{
  gmSpellComponentUI *v1; // edi@1
  UIElement_ListBox *v2; // ecx@1
  GlobalEventHandler *v3; // eax@3
  void *v4; // eax@5

  v1 = this;
  v2 = this->m_pComponentListBox;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmSpellComponentUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmSpellComponentUI::vftable;
  if ( v2 )
    UIElement_ListBox::Flush(v2);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, (NoticeHandler *)&v1->vfptr);
  v1->m_hashComponentRegions.vfptr = (HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashComponentRegions.m_intrusiveTable);
  v4 = v1->m_hashComponentRegions.m_intrusiveTable.m_buckets;
  v1->m_hashComponentRegions.m_intrusiveTable.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable;
  if ( v4 != v1->m_hashComponentRegions.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_hashComponentRegions.m_intrusiveTable.m_buckets = 0;
  v1->m_hashComponentRegions.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashComponentRegions.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashComponentRegions.m_intrusiveTable.m_numElements = 0;
  if ( (v1->m_aCategoryTitles.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_aCategoryTitles.m_data);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A33E0: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable[2])(void *, char);
// 7A33E4: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::vftable)(void *, char);
// 7A33E8: using guessed type bool (__thiscall *gmSpellComponentUI::vftable)(DBCache *this);
// 7A3690: using guessed type int (__thiscall *gmSpellComponentUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048A8E0) --------------------------------------------------------  // acclient.c:198119
void __usercall gmSpellComponentUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSpellComponentUI *v3; // eax@1

  v3 = (gmSpellComponentUI *)operator new(0x688u);
  if ( v3 )
    gmSpellComponentUI::gmSpellComponentUI(v3, a1, _layout, _full_desc);
}

//----- (0048A910) --------------------------------------------------------  // acclient.c:198129
void __thiscall gmSpellComponentUI::UpdateComponents(gmSpellComponentUI *this, ComponentTrackerUpdate _change)
{
  gmSpellComponentUI *v2; // esi@1
  CPlayerSystem *v3; // eax@1
  int v4; // eax@1
  unsigned int v5; // ebx@2
  int v6; // edi@2
  int v7; // eax@2
  int v8; // ebp@4
  UIElement *v9; // eax@4
  int v10; // eax@10
  UIElement *v11; // edi@11
  PStringBase<unsigned short> *v12; // eax@11
  char *v13; // edi@11
  UIElement *v14; // eax@24
  UIElement *v15; // edi@24
  void *v16; // eax@28
  void *v17; // edi@28
  void *v18; // ebx@28
  void *v19; // eax@31
  unsigned int v20; // ecx@32
  int v21; // ecx@33
  int v22; // eax@33
  int v23; // eax@42
  UIElement *v24; // edi@42
  UIElement *v25; // eax@43
  UIElement_Text *v26; // ebx@44
  char *v27; // ebx@45
  UIElement *v28; // eax@48
  UIElement *v29; // eax@48
  int v30; // eax@49
  UIElement *i; // edi@54
  unsigned int v32; // edx@59
  HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> **v33; // eax@59
  HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *v34; // ecx@59
  int v35; // edi@59
  HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *v36; // eax@59
  HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *v37; // edx@65
  bool v38; // sf@72
  unsigned __int8 v39; // of@72
  int curIndex; // [sp+Ch] [bp-B4h]@2
  IDClass<_tagDataID,32,0> didComponentClass; // [sp+10h] [bp-B0h]@25
  int catNum; // [sp+14h] [bp-ACh]@2
  int eComponentCategory; // [sp+18h] [bp-A8h]@5
  int _val; // [sp+1Ch] [bp-A4h]@15
  int v45; // [sp+20h] [bp-A0h]@2
  PStringBase<unsigned short> strCompName; // [sp+24h] [bp-9Ch]@45
  IDClass<_tagDataID,32,0> v47; // [sp+28h] [bp-98h]@56
  PStringBase<unsigned short> result; // [sp+2Ch] [bp-94h]@11
  StringInfo v49; // [sp+30h] [bp-90h]@11

  v2 = this;
  v3 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::GetComponentTracker(v3);
  if ( v4 )
  {
    v5 = 0;
    v6 = 0;
    v7 = v4 + 4;
    curIndex = 0;
    catNum = 0;
    v45 = v7;
    while ( 1 )
    {
      v8 = **(_DWORD **)v7;
      v9 = UIElement_ListBox::GetItem(v2->m_pComponentListBox, v5);
      if ( v8 )
      {
        eComponentCategory = 8;
        if ( v9 && !UIElement::GetAttribute_Int(v9, 0x1000004Du, &eComponentCategory) )
          eComponentCategory = 8;
        if ( eComponentCategory == v6 )
        {
          ++v5;
          curIndex = v5;
        }
        else
        {
          v10 = UIElement_ListBox::AddItemFromTemplateList(v2->m_pComponentListBox, 0, v5);
          if ( v10 )
          {
            v11 = (UIElement *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v10 + 148))(v10, 12);
            eComponentCategory = catNum;
            UIElement::SetAttribute_Int(v11, 0x1000004Du, catNum);
            StringInfo::StringInfo(&v49);
            StringInfo::SetStringIDandTableEnum(&v49, v2->m_aCategoryTitles.m_data[catNum], 268435457);
            v12 = StringInfo::GetString(&v49, &result, 0);
            UIElement_Text::SetText((UIElement_Text *)v11, v12);
            v13 = (char *)&result.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v13 )
              (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
            ++v5;
            curIndex = v5;
            StringInfo::~StringInfo(&v49);
          }
        }
      }
      else
      {
        _val = 8;
        if ( v9 && !UIElement::GetAttribute_Int(v9, 0x1000004Du, &_val) )
          _val = 8;
        if ( _val == v6 )
          UIElement_ListBox::DeleteItem(v2->m_pComponentListBox, v5);
      }
      if ( _change == 1 )
      {
        if ( v8 )
        {
          while ( 1 )
          {
            v14 = UIElement_ListBox::GetItem(v2->m_pComponentListBox, v5);
            v15 = v14;
            if ( v14
              && (UIElement::GetAttribute_DataID(v14, 0x1000004Cu, &didComponentClass),
                  v15->m_desc.m_elementID != 268436582)
              && didComponentClass.id == *(_DWORD *)(v8 + 8) )
            {
              gmSpellComponentUI::SyncComponentRegionWithData(v2, v15, (ComponentData *)v8);
              curIndex = v5 + 1;
            }
            else
            {
              v16 = operator new(0x10u);
              v17 = v16;
              v18 = 0;
              if ( v16 )
              {
                *((_DWORD *)v16 + 3) = 0;
                *(_DWORD *)v16 = *(_DWORD *)(v8 + 8);
                *((_DWORD *)v16 + 1) = ComponentData::GetFirstObjectID((ComponentData *)v8);
                *((_DWORD *)v17 + 3) = *(_DWORD *)(v8 + 136);
                *((_DWORD *)v17 + 2) = *(_DWORD *)(v8 + 16);
              }
              else
              {
                v17 = 0;
              }
              didComponentClass.id = *(_DWORD *)(v8 + 8);
              v19 = operator new(0xCu);
              if ( v19 )
              {
                v20 = didComponentClass.id;
                *((_DWORD *)v19 + 1) = 0;
                *(_DWORD *)v19 = v20;
                *((_DWORD *)v19 + 2) = v17;
                v18 = v19;
              }
              v21 = (int)&v2->m_hashComponentRegions.m_intrusiveTable.m_buckets[*(_DWORD *)v18
                                                                              % v2->m_hashComponentRegions.m_intrusiveTable.m_numBuckets];
              v22 = *(_DWORD *)v21;
              if ( !*(_DWORD *)v21 )
                goto LABEL_38;
              while ( *(_DWORD *)v22 != *(_DWORD *)v18 )
              {
                v22 = *(_DWORD *)(v22 + 4);
                if ( !v22 )
                  goto LABEL_38;
              }
              if ( v22 )
              {
                operator delete(v18);
              }
              else
              {
LABEL_38:
                *((_DWORD *)v18 + 1) = *(_DWORD *)v21;
                *(_DWORD *)v21 = v18;
                if ( (HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> **)v21 < v2->m_hashComponentRegions.m_intrusiveTable.m_firstInterestingBucket )
                  v2->m_hashComponentRegions.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> **)v21;
                ++v2->m_hashComponentRegions.m_intrusiveTable.m_numElements;
              }
              v23 = UIElement_ListBox::AddItemFromTemplateList(v2->m_pComponentListBox, 1u, curIndex);
              v24 = (UIElement *)v23;
              if ( v23 )
              {
                UIElement::SetAttribute_DataID((UIElement *)v23, 0x1000004Cu, didComponentClass);
                v25 = UIElement::GetChildRecursive(v24, 0x10000469u);
                if ( v25 )
                {
                  v26 = (UIElement_Text *)v25->vfptr[12].OnAction((IInputActionCallback *)v25, (InputEvent *)12);
                  if ( v26 )
                  {
                    PStringBase<unsigned short>::PStringBase<unsigned short>(
                      &strCompName,
                      0,
                      (const char *)(*(_DWORD *)(v8 + 12) + 20));
                    UIElement_Text::SetText(v26, &strCompName);
                    v27 = (char *)&strCompName.m_charbuffer[-1].m_data[6];
                    if ( !InterlockedDecrement((volatile LONG *)&strCompName.m_charbuffer[-1].m_data[8]) )
                    {
                      if ( v27 )
                        (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
                    }
                  }
                }
                v28 = UIElement::GetChildRecursive(v24, 0x10000468u);
                gmSpellComponentUI::MakeIcon(didComponentClass, v28);
                gmSpellComponentUI::SyncComponentRegionWithData(v2, v24, (ComponentData *)v8);
                gmSpellComponentUI::UpdateBuyRates(v2, didComponentClass);
                v29 = UIElement::GetChildRecursive(v24, 0x1000046Bu);
                if ( v29 )
                {
                  v30 = v29->vfptr[12].OnAction((IInputActionCallback *)v29, (InputEvent *)12);
                  if ( v30 )
                    *(_DWORD *)(v30 + 1696) = NumberInputFilter;
                }
                ++curIndex;
              }
            }
            v8 = *(_DWORD *)v8;
            if ( !v8 )
              break;
            v5 = curIndex;
          }
        }
      }
      else
      {
        for ( i = UIElement_ListBox::GetItem(v2->m_pComponentListBox, v5);
              i;
              i = UIElement_ListBox::GetItem(v2->m_pComponentListBox, curIndex) )
        {
          if ( i->m_desc.m_elementID != 268436583 )
            break;
          v47.id = clsID.id;
          UIElement::GetAttribute_DataID(i, 0x1000004Cu, &v47);
          if ( v8 && v47.id == *(_DWORD *)(v8 + 8) )
          {
            gmSpellComponentUI::SyncComponentRegionWithData(v2, i, (ComponentData *)v8);
            v8 = *(_DWORD *)v8;
            ++curIndex;
          }
          else
          {
            v32 = v47.id % v2->m_hashComponentRegions.m_intrusiveTable.m_numBuckets;
            v33 = v2->m_hashComponentRegions.m_intrusiveTable.m_buckets;
            v34 = v33[v32];
            v35 = (int)&v33[v32];
            v36 = v33[v32];
            if ( v36 )
            {
              while ( v36->m_hashKey.id != v47.id )
              {
                v36 = v36->m_hashNext;
                if ( !v36 )
                  goto LABEL_70;
              }
              if ( v36 )
              {
                if ( v34 == v36 )
                  goto LABEL_76;
                do
                {
                  v37 = v34;
                  v34 = v34->m_hashNext;
                }
                while ( v34 != v36 );
                if ( v37 )
                  v37->m_hashNext = v34->m_hashNext;
                else
LABEL_76:
                  *(_DWORD *)v35 = v34->m_hashNext;
                --v2->m_hashComponentRegions.m_intrusiveTable.m_numElements;
                operator delete(v36);
              }
            }
LABEL_70:
            UIElement_ListBox::DeleteItem(v2->m_pComponentListBox, curIndex);
          }
        }
      }
      v7 = v45 + 4;
      v39 = __OFSUB__(catNum + 1, 7);
      v38 = catNum++ - 6 < 0;
      v45 += 4;
      if ( !(v38 ^ v39) )
        break;
      v5 = curIndex;
      v6 = catNum;
    }
    ((void (__thiscall *)(int))v2->vfptr[6].RecvNotice_ItemAttributesChanged)(&v2->vfptr);
  }
}

//----- (0048ADD0) --------------------------------------------------------  // acclient.c:198415
gmSpellComponentUI *__thiscall gmSpellComponentUI::scalar_deleting_destructor(gmSpellComponentUI *this, unsigned int a2)
{
  gmSpellComponentUI *v2; // esi@1

  v2 = this;
  gmSpellComponentUI::~gmSpellComponentUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048ADF0) --------------------------------------------------------  // acclient.c:198427
void __cdecl gmSpellComponentUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000002Fu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSpellComponentUI::Create);
}

//----- (0048AE10) --------------------------------------------------------  // acclient.c:198435
void __thiscall gmSpellComponentUI::RecvNotice_UpdateSpellComponents(gmSpellComponentUI *this, int i_change)
{
  gmSpellComponentUI::UpdateComponents((gmSpellComponentUI *)((char *)this - 1528), (ComponentTrackerUpdate)i_change);
}

//----- (006EDA50) --------------------------------------------------------  // acclient.c:769563
void _E91_51()
{
  outside_val_43 = 1000.0 + 1.0;
}

//----- (006EDA70) --------------------------------------------------------  // acclient.c:769569
void _E93_27()
{
  block_length_43 = 24.0 * 8.0;
}

//----- (006EDA90) --------------------------------------------------------  // acclient.c:769575
void _E95_27()
{
  half_square_length_43 = 24.0 * 0.5;
}

//----- (006EDAB0) --------------------------------------------------------  // acclient.c:769581
int _E97_52()
{
  return atexit(_E98_64);
}

//----- (006EDAC0) --------------------------------------------------------  // acclient.c:769587
int _E100_45()
{
  return atexit(_E101_82);
}

//----- (006EDAD0) --------------------------------------------------------  // acclient.c:769593
int _E103_37()
{
  return atexit(_E104_52);
}

//----- (006EDAE0) --------------------------------------------------------  // acclient.c:769599
void _E106_28()
{
  DEFAULT_VIEW_RADIUS_21 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EDB00) --------------------------------------------------------  // acclient.c:769605
void _E108_19()
{
  MIN_QUANTUM_21 = 1.0 / 30.0;
}

//----- (006EDB20) --------------------------------------------------------  // acclient.c:769611
void _E110_10()
{
  MAX_QUANTUM_21 = 1.0 / 5.0;
}

//----- (006EDB40) --------------------------------------------------------  // acclient.c:769617
void _E112_24()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_56, PFID_A8R8G8B8);
}

//----- (006EDB50) --------------------------------------------------------  // acclient.c:769623
void _E115_16()
{
  LOWEST_DATA_RATE_64 = 1024;
}

//----- (006EDB60) --------------------------------------------------------  // acclient.c:769629
void _E117_14()
{
  HIGHEST_DATA_RATE_64 = 0x7FFF;
}

//----- (006EDB70) --------------------------------------------------------  // acclient.c:769635
int _E119_3()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_64;
  INITIAL_MAX_DATA_RATE_12 = LOWEST_DATA_RATE_64;
  return result;
}

//----- (006EDB80) --------------------------------------------------------  // acclient.c:769645
int _E121_24()
{
  return atexit(_E122_61);
}

//----- (006EDB90) --------------------------------------------------------  // acclient.c:769651
unsigned int _E127_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SpellComp_Category_Alchemical");
  ID_SpellComp_Category_Alchemical = result;
  return result;
}

//----- (006EDBB0) --------------------------------------------------------  // acclient.c:769661
unsigned int _E129_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SpellComp_Category_Gems");
  ID_SpellComp_Category_Gems = result;
  return result;
}

//----- (006EDBD0) --------------------------------------------------------  // acclient.c:769671
unsigned int _E131_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SpellComp_Category_Herbs");
  ID_SpellComp_Category_Herbs = result;
  return result;
}

//----- (006EDBF0) --------------------------------------------------------  // acclient.c:769681
unsigned int _E133_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SpellComp_Category_Peas");
  ID_SpellComp_Category_Peas = result;
  return result;
}

//----- (006EDC10) --------------------------------------------------------  // acclient.c:769691
unsigned int _E135_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SpellComp_Category_Scarabs");
  ID_SpellComp_Category_Scarabs = result;
  return result;
}

//----- (006EDC30) --------------------------------------------------------  // acclient.c:769701
unsigned int _E137_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SpellComp_Category_Talismans");
  ID_SpellComp_Category_Talismans = result;
  return result;
}

//----- (006EDC50) --------------------------------------------------------  // acclient.c:769711
unsigned int _E139_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_SpellComp_Category_Tapers");
  ID_SpellComp_Category_Tapers = result;
  return result;
}

//----- (006EDC70) --------------------------------------------------------  // acclient.c:769721
int sub_6EDC70()
{
  return atexit(nullsub_890);
}

