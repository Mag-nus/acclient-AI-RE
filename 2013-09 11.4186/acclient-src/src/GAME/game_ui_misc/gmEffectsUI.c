/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmEffectsUI
   Object     : GAME\game_ui_misc\gmEffectsUI.obj
   Functions  : 47
   Addresses  : 0044A630 - 006F1AE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044A630) --------------------------------------------------------  // acclient.c:135230
char __thiscall SmartArray<LayerStage *,1>::InsertOrderedByIndex(SmartArray<EffectInfoRegion *,1> *this, EffectInfoRegion *const *i_rData, unsigned int index)
{
  SmartArray<EffectInfoRegion *,1> *v3; // esi@1
  unsigned int v4; // ecx@1
  int v5; // eax@2
  unsigned int v6; // eax@3
  unsigned int v7; // edx@4
  unsigned int v8; // ecx@5
  int i; // eax@5
  char result; // al@7

  v3 = this;
  v4 = this->m_num;
  if ( index <= v4
    && ((v5 = v3->m_sizeAndDeallocate & 0x7FFFFFFF, v4 < v5)
     || (v6 = SmartArray<UIChildFramework *,1>::get_new_size(v5 + 1),
         SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v3, v6))) )
  {
    v7 = v3->m_num;
    if ( v7 )
    {
      v8 = (unsigned int)&v3->m_data[index];
      for ( i = (int)&v3->m_data[v7 - 1]; i >= v8; i -= 4 )
        *(_DWORD *)(i + 4) = *(_DWORD *)i;
    }
    v3->m_data[index] = *i_rData;
    ++v3->m_num;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004B74F0) --------------------------------------------------------  // acclient.c:235352
int __thiscall Enchantment::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(this + 56) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(this + 60) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(this + 68) = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(this + 72) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(this + 76) = *(_DWORD *)(a2 + 76);
  return result;
}

//----- (004B7560) --------------------------------------------------------  // acclient.c:235377
void __thiscall gmEffectsUI::PostInit(gmEffectsUI *this)
{
  gmEffectsUI *v1; // edi@1
  IInputActionCallbackVtbl *v2; // eax@1
  UIElement *v3; // eax@3
  int v4; // eax@4
  UIElement *v5; // eax@6
  int v6; // eax@7
  GlobalEventHandler *v7; // esi@9
  int v8; // edi@9
  BasePropertyDesc *v9; // ecx@10
  unsigned int v10; // edx@10
  BasePropertyValue *v11; // ecx@14
  unsigned int v12; // edx@14
  BaseProperty effectsUITypeProperty; // [sp+20h] [bp-8h]@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = v1->vfptr;
  effectsUITypeProperty.m_pcPropertyDesc = 0;
  effectsUITypeProperty.m_pcPropertyValue = 0;
  ((void (__thiscall *)(gmEffectsUI *, signed int, BaseProperty *))v2[17].OnAction)(
    v1,
    268435468,
    &effectsUITypeProperty);
  if ( effectsUITypeProperty.m_pcPropertyValue )
    ((void (__stdcall *)(_DWORD))effectsUITypeProperty.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&v1->m_effectsUIType);
  v3 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000126u);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
  else
    v4 = 0;
  v1->m_pInfoText = (UIElement_Text *)v4;
  v5 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000123u);
  if ( v5 )
    v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)5);
  else
    v6 = 0;
  v1->m_pListBox = (UIElement_ListBox *)v6;
  v7 = GlobalEventHandler::GetGlobalEventHandler();
  v8 = (int)&v1->vfptr;
  v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v8);
  v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, (unsigned int)((char *)&loc_4DD200 + 1), (NoticeHandler *)v8);
  if ( (_DWORD)effectsUITypeProperty.m_pcPropertyDesc )
  {
    v9 = effectsUITypeProperty.m_pcPropertyDesc;
    v10 = effectsUITypeProperty.m_pcPropertyDesc->m_cRef - 1;
    effectsUITypeProperty.m_pcPropertyDesc->m_cRef = v10;
    if ( !v10 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    effectsUITypeProperty.m_pcPropertyDesc = 0;
  }
  if ( effectsUITypeProperty.m_pcPropertyValue )
  {
    v11 = effectsUITypeProperty.m_pcPropertyValue;
    v12 = effectsUITypeProperty.m_pcPropertyValue->m_cRef - 1;
    effectsUITypeProperty.m_pcPropertyValue->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
  }
}

//----- (004B7670) --------------------------------------------------------  // acclient.c:235440
char __thiscall gmEffectsUI::UpdateDurations(gmEffectsUI *this, CACQualities *i_playerDesc)
{
  gmEffectsUI *v2; // edi@1
  unsigned int v3; // esi@1
  char result; // al@3

  v2 = this;
  v3 = 0;
  if ( this->m_rgTokens.m_num )
  {
    do
      ((void (__stdcall *)(CACQualities *))v2->m_rgTokens.m_data[v3++]->vfptr[4].OnQualityChanged)(i_playerDesc);
    while ( v3 < v2->m_rgTokens.m_num );
  }
  result = 1;
  v2->m_nextDurationUpdate = COERCE_DOUBLE(Timer::cur_time.Cmd) + 1.0;
  return result;
}

//----- (004B76C0) --------------------------------------------------------  // acclient.c:235460
char __thiscall gmEffectsUI::SpellEffectMatchesUIType(gmEffectsUI *this, unsigned int i_spellID)
{
  gmEffectsUI *v2; // esi@1
  ClientMagicSystem *v3; // edi@1
  unsigned int v4; // eax@3
  CSpellBase spellBase; // [sp+8h] [bp-90h]@2

  v2 = this;
  v3 = ClientMagicSystem::GetMagicSystem();
  if ( v3 )
  {
    CSpellBase::CSpellBase(&spellBase);
    if ( ClientMagicSystem::InqSpellBase(v3, i_spellID, &spellBase) )
    {
      if ( (v4 = v2->m_effectsUIType, v4 == 1) && spellBase._bitfield & 4 || v4 == 2 && !(spellBase._bitfield & 4) )
      {
        CSpellBase::~CSpellBase(&spellBase);
        return 1;
      }
    }
    CSpellBase::~CSpellBase(&spellBase);
  }
  return 0;
}

//----- (004B7740) --------------------------------------------------------  // acclient.c:235486
signed int __thiscall PackableList<Enchantment>::Pack(PackableList<Enchantment> *this, void **addr, unsigned int size)
{
  PackableList<Enchantment> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<Enchantment> *i; // esi@4

  v3 = this;
  v4 = PackableList<Enchantment>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<Enchantment> *, void **, unsigned int))i->data.vfptr->Pack)(i, addr, size);
  }
  return v4;
}

//----- (004B7790) --------------------------------------------------------  // acclient.c:235508
signed int __thiscall PackableList<Enchantment>::pack_size(PackableList<Enchantment> *this)
{
  PackableLLNode<Enchantment> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<Enchantment> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (004B77D0) --------------------------------------------------------  // acclient.c:235527
void __userpurge gmEffectsUI::gmEffectsUI(gmEffectsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmEffectsUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pInfoText = 0;
  v4->m_pListBox = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmEffectsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmEffectsUI::vftable;
  v4->m_rgTokens.m_data = 0;
  v4->m_rgTokens.m_sizeAndDeallocate = 0;
  v4->m_rgTokens.m_num = 0;
  v4->m_effectsUIType = 0;
  LODWORD(v4->m_nextDurationUpdate) = 0;
  HIDWORD(v4->m_nextDurationUpdate) = 0;
  v4->m_SelectedSpell = 0;
  v4->m_bNeedToRebuild = 1;
}
// 7B15D8: using guessed type bool (__thiscall *gmEffectsUI::vftable)(DBCache *this);
// 7B1880: using guessed type int (__thiscall *gmEffectsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004B7850) --------------------------------------------------------  // acclient.c:235552
gmEffectsUI *__thiscall gmEffectsUI::DynamicCast(gmEffectsUI *this, unsigned int i_eType)
{
  gmEffectsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435483 )
    result = (gmEffectsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004B7870) --------------------------------------------------------  // acclient.c:235563
void __usercall gmEffectsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmEffectsUI *v3; // eax@1

  v3 = (gmEffectsUI *)operator new(0x628u);
  if ( v3 )
    gmEffectsUI::gmEffectsUI(v3, a1, _layout, _full_desc);
}

//----- (004B78A0) --------------------------------------------------------  // acclient.c:235573
void __cdecl gmEffectsUI::Register()
{
  UIElement::RegisterElementClass(0x1000001Bu, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmEffectsUI::Create);
}

//----- (004B78C0) --------------------------------------------------------  // acclient.c:235579
unsigned int __thiscall gmEffectsUI::GetSortedInsertionPlace(gmEffectsUI *this, CSpellBase *spellBase)
{
  gmEffectsUI *v2; // esi@1
  ClientMagicSystem *v3; // ebp@1
  unsigned int v4; // edi@1
  unsigned int v5; // eax@1
  UIElement *v6; // eax@2
  EffectInfoRegion *v7; // eax@5
  unsigned int v8; // edi@6
  AC1Legacy::PStringBase<char> *v9; // eax@7
  AC1Legacy::PSRefBuffer<char> *v10; // esi@7
  AC1Legacy::PStringBase<char> *v11; // eax@10
  AC1Legacy::PSRefBuffer<char> *v12; // esi@10
  AC1Legacy::PSRefBuffer<char> *v13; // esi@16
  AC1Legacy::PSRefBuffer<char> *v14; // esi@19
  PStringBase<char> strName; // [sp+10h] [bp-B0h]@7
  PStringBase<char> strCmpName; // [sp+14h] [bp-ACh]@10
  unsigned int curPlace; // [sp+18h] [bp-A8h]@1
  AC1Legacy::PStringBase<char> result; // [sp+1Ch] [bp-A4h]@7
  gmEffectsUI *v20; // [sp+20h] [bp-A0h]@1
  int index; // [sp+24h] [bp-9Ch]@3
  unsigned int numItems; // [sp+28h] [bp-98h]@1
  AC1Legacy::PStringBase<char> v23; // [sp+2Ch] [bp-94h]@10
  CSpellBase cmpBase; // [sp+30h] [bp-90h]@1

  v2 = this;
  v20 = this;
  v3 = ClientMagicSystem::GetMagicSystem();
  CSpellBase::CSpellBase(&cmpBase);
  v5 = 0;
  numItems = v2->m_pListBox->m_listItems.m_num;
  v4 = numItems;
  curPlace = 0;
  if ( numItems )
  {
    do
    {
      v6 = UIElement_ListBox::GetItem(v2->m_pListBox, v5);
      if ( v6 )
      {
        if ( UIElement::GetAttribute_Int(v6, 0x1000003Au, &index) && index < (signed int)v2->m_rgTokens.m_num )
        {
          v7 = v2->m_rgTokens.m_data[index];
          if ( v7 )
          {
            v8 = v7->m_Spell;
            if ( ClientMagicSystem::InqSpellBase(v3, v7->m_Spell, &cmpBase) )
            {
              v9 = ClientMagicSystem::GetSpellName(v3, &result, spellBase->_meta_spell._spell->_spell_id);
              PStringBase<char>::PStringBase<char>(&strName, v9->m_buffer->m_data);
              v10 = result.m_buffer;
              if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v10 )
                v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
              v11 = ClientMagicSystem::GetSpellName(v3, &v23, v8);
              PStringBase<char>::PStringBase<char>(&strCmpName, v11->m_buffer->m_data);
              v12 = v23.m_buffer;
              if ( !InterlockedDecrement((volatile LONG *)&v23.m_buffer->m_cRef) && v12 )
                v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
              if ( strcmp(strName.m_charbuffer->m_data, strCmpName.m_charbuffer->m_data) <= 0 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strCmpName);
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strName);
                CSpellBase::~CSpellBase(&cmpBase);
                return curPlace;
              }
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strCmpName);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strName);
              v2 = v20;
            }
          }
        }
      }
      v4 = numItems;
      v5 = curPlace++ + 1;
    }
    while ( curPlace < numItems );
  }
  MetaSpell::~MetaSpell(&cmpBase._meta_spell);
  v13 = cmpBase._desc.m_buffer;
  cmpBase._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&cmpBase._desc.m_buffer->m_cRef) && v13 )
    v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
  v14 = cmpBase._name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&cmpBase._name.m_buffer->m_cRef) )
  {
    if ( v14 )
      v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
  }
  return v4;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004B7AD0) --------------------------------------------------------  // acclient.c:235672
void __thiscall PackableList<Enchantment>::Flush(PackableList<Enchantment> *this)
{
  PackableList<Enchantment> *v1; // esi@1
  PackableLLNode<Enchantment> *v2; // eax@2
  PackableLLNode<Enchantment> *v3; // ecx@3
  int v4; // edx@6
  int v5; // edx@6
  int v6; // ecx@6
  Enchantment dummyData; // [sp+8h] [bp-50h]@1

  v1 = this;
  Enchantment::Enchantment(&dummyData);
  while ( v1->head )
  {
    v2 = v1->head;
    if ( v2 )
    {
      v3 = v2->next;
      v1->head = v3;
      if ( v3 )
        v3->prev = 0;
      else
        v1->tail = 0;
      dummyData._id = v2->data._id;
      dummyData.m_SpellSetID = v2->data.m_SpellSetID;
      dummyData._spell_category = v2->data._spell_category;
      dummyData._power_level = v2->data._power_level;
      v4 = HIDWORD(v2->data._start_time);
      LODWORD(dummyData._start_time) = LODWORD(v2->data._start_time);
      HIDWORD(dummyData._start_time) = v4;
      v5 = HIDWORD(v2->data._duration);
      LODWORD(dummyData._duration) = LODWORD(v2->data._duration);
      HIDWORD(dummyData._duration) = v5;
      dummyData._caster = v2->data._caster;
      dummyData._degrade_modifier = v2->data._degrade_modifier;
      dummyData._degrade_limit = v2->data._degrade_limit;
      v6 = HIDWORD(v2->data._last_time_degraded);
      LODWORD(dummyData._last_time_degraded) = LODWORD(v2->data._last_time_degraded);
      HIDWORD(dummyData._last_time_degraded) = v6;
      dummyData._smod.type = v2->data._smod.type;
      dummyData._smod.key = v2->data._smod.key;
      dummyData._smod.val = v2->data._smod.val;
      v2->data._smod.vfptr = (PackObjVtbl *)&PackObj::vftable;
      v2->data.vfptr = (PackObjVtbl *)&PackObj::vftable;
      operator delete(v2);
      --v1->curNum;
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004B7BB0) --------------------------------------------------------  // acclient.c:235724
char __thiscall gmEffectsUI::UpdateDurations(gmEffectsUI *this)
{
  gmEffectsUI *v1; // ebp@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // ebx@3
  PlayerDesc *v5; // esi@5
  char v7; // bl@9
  int v8; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v11; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@1

  v1 = this;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_8, &_rpInterface);
  v8 = (int)_rpInterface;
  v3 = _rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v8, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v7 = gmEffectsUI::UpdateDurations(v1, (CACQualities *)&playerDesc.m_pInterface->vfptr);
  v5->vfptr->Release((Interface *)v5);
  return v7;
}

//----- (004B7C60) --------------------------------------------------------  // acclient.c:235765
char __thiscall gmEffectsUI::FlushList(gmEffectsUI *this)
{
  gmEffectsUI *v1; // eax@1
  unsigned int v2; // esi@1
  EffectInfoRegion *v3; // ecx@2
  unsigned int v4; // edx@5
  int v5; // eax@5
  unsigned int v6; // ecx@5
  gmEffectsUI *v8; // [sp+4h] [bp-4h]@1

  v8 = this;
  UIElement_ListBox::Flush(this->m_pListBox);
  v1 = v8;
  v2 = 0;
  if ( v8->m_rgTokens.m_num )
  {
    do
    {
      v3 = v1->m_rgTokens.m_data[v2];
      if ( v3 )
      {
        ((void (__stdcall *)(signed int))v3->vfptr[1].OnQualityChanged)(1);
        v1 = v8;
      }
      v1->m_rgTokens.m_data[v2] = 0;
      v1 = v8;
      ++v2;
    }
    while ( v2 < v8->m_rgTokens.m_num );
  }
  v4 = v1->m_rgTokens.m_num;
  v5 = (int)&v1->m_rgTokens;
  v6 = 0;
  if ( v4 )
  {
    do
      *(_DWORD *)(*(_DWORD *)v5 + 4 * v6++) = 0;
    while ( v6 < *(_DWORD *)(v5 + 8) );
  }
  *(_DWORD *)(v5 + 8) = 0;
  return 1;
}

//----- (004B7CF0) --------------------------------------------------------  // acclient.c:235809
int __thiscall PackableList<Enchantment>::UnPack(PackableList<Enchantment> *this, void **addr, unsigned int size)
{
  PackableList<Enchantment> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  Enchantment temp; // [sp+8h] [bp-50h]@2

  v3 = this;
  PackableList<Enchantment>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    Enchantment::Enchantment(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(Enchantment *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<Enchantment>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      result = 0;
    }
  }
  return result;
}

//----- (004B7D70) --------------------------------------------------------  // acclient.c:235850
int __thiscall PackableList<Enchantment>::InsertTail(PackableList<Enchantment> *this, Enchantment *val)
{
  PackableList<Enchantment> *v2; // esi@1
  void *v3; // edi@1
  unsigned int v4; // eax@5
  int result; // eax@5
  PackableLLNode<Enchantment> *v6; // eax@6
  unsigned int v7; // eax@6

  v2 = this;
  v3 = operator new(0x58u);
  if ( v3 )
  {
    Enchantment::Enchantment((Enchantment *)v3, val);
    *((_DWORD *)v3 + 20) = 0;
    *((_DWORD *)v3 + 21) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<Enchantment> *)v3;
    *((_DWORD *)v3 + 21) = v6;
    v7 = v2->curNum;
    v2->tail = (PackableLLNode<Enchantment> *)v3;
    result = v7 + 1;
    v2->curNum = result;
  }
  else
  {
    v4 = v2->curNum;
    v2->head = (PackableLLNode<Enchantment> *)v3;
    v2->tail = (PackableLLNode<Enchantment> *)v3;
    result = v4 + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (004B7DE0) --------------------------------------------------------  // acclient.c:235893
void __thiscall Enchantment::Enchantment(Enchantment *this, Enchantment *__that)
{
  this->vfptr = (PackObjVtbl *)&Enchantment::vftable;
  this->_id = __that->_id;
  this->m_SpellSetID = __that->m_SpellSetID;
  this->_spell_category = __that->_spell_category;
  this->_power_level = __that->_power_level;
  this->_start_time = __that->_start_time;
  this->_duration = __that->_duration;
  this->_caster = __that->_caster;
  this->_degrade_modifier = __that->_degrade_modifier;
  this->_degrade_limit = __that->_degrade_limit;
  this->_last_time_degraded = __that->_last_time_degraded;
  this->_smod.vfptr = (PackObjVtbl *)&StatMod::vftable;
  this->_smod.type = __that->_smod.type;
  this->_smod.key = __that->_smod.key;
  this->_smod.val = __that->_smod.val;
}
// 7B19B8: using guessed type int (__thiscall *StatMod::vftable)(void *, char);
// 7B19CC: using guessed type int (__thiscall *Enchantment::vftable)(void *, char);

//----- (004B7E60) --------------------------------------------------------  // acclient.c:235915
Enchantment *__thiscall Enchantment::vector_deleting_destructor(Enchantment *this, unsigned int a2)
{
  Enchantment *v2; // esi@1

  v2 = this;
  this->_smod.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004B7E90) --------------------------------------------------------  // acclient.c:235929
PackableList<Enchantment> *__thiscall PackableList<Enchantment>::vector_deleting_destructor(PackableList<Enchantment> *this, unsigned int a2)
{
  PackableList<Enchantment> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  PackableList<Enchantment>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (004B7EC0) --------------------------------------------------------  // acclient.c:235945
void __thiscall gmEffectsUI::~gmEffectsUI(gmEffectsUI *this)
{
  gmEffectsUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmEffectsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmEffectsUI::vftable;
  gmEffectsUI::FlushList(this);
  v1->m_pInfoText = 0;
  v1->m_pListBox = 0;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  if ( (v1->m_rgTokens.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_rgTokens.m_data);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7B15D8: using guessed type bool (__thiscall *gmEffectsUI::vftable)(DBCache *this);
// 7B1880: using guessed type int (__thiscall *gmEffectsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004B7F40) --------------------------------------------------------  // acclient.c:235972
void __thiscall gmEffectsUI::ListenToGlobalMessage(gmEffectsUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 3 && COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_nextDurationUpdate )
    gmEffectsUI::UpdateDurations(this);
}

//----- (004B7F70) --------------------------------------------------------  // acclient.c:235979
gmEffectsUI *__thiscall gmEffectsUI::vector_deleting_destructor(gmEffectsUI *this, unsigned int a2)
{
  gmEffectsUI *v2; // esi@1

  v2 = this;
  gmEffectsUI::~gmEffectsUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B7F90) --------------------------------------------------------  // acclient.c:235991
char __thiscall gmEffectsUI::UpdateSelection(gmEffectsUI *this)
{
  gmEffectsUI *v1; // esi@1
  unsigned int v2; // edi@1
  int v3; // eax@2
  QualityChangeHandlerVtbl *v4; // edx@2
  PStringBase<unsigned short> *v5; // eax@9
  void *v6; // esi@9
  ClientMagicSystem *v7; // eax@10
  ClientMagicSystem *v8; // ebp@10
  AC1Legacy::PStringBase<char> *v10; // eax@12
  PSRefBufferCharData<unsigned short> *v11; // edi@12
  PSRefBufferCharData<unsigned short> *v12; // edi@15
  int v13; // eax@15
  int v14; // edi@17
  AC1Legacy::PStringBase<char> *v15; // eax@20
  PSRefBufferCharData<unsigned short> *v16; // ecx@20
  int v17; // eax@20
  int v18; // edi@22
  AC1Legacy::PSRefBuffer<char> *v19; // edi@25
  PStringBase<unsigned short> *v20; // eax@28
  char *v21; // edi@28
  PStringBase<unsigned short> *v22; // eax@31
  char *v23; // esi@31
  char *v24; // esi@34
  PStringBase<unsigned short> *v25; // eax@37
  int v26; // esi@38
  PStringBase<unsigned short> result; // [sp+14h] [bp-12Ch]@9
  AC1Legacy::PStringBase<char> v28; // [sp+18h] [bp-128h]@20
  PStringBase<char> infoText; // [sp+1Ch] [bp-124h]@12
  StringInfo siSelectText; // [sp+20h] [bp-120h]@9
  StringInfo siInfoText; // [sp+B0h] [bp-90h]@28

  v1 = this;
  v2 = 0;
  if ( this->m_rgTokens.m_num )
  {
    do
    {
      v3 = ((int (*)(void))v1->m_rgTokens.m_data[v2]->vfptr[3].OnQualityChanged)();
      v4 = v1->m_rgTokens.m_data[v2]->vfptr;
      if ( v3 == v1->m_SelectedSpell )
        ((void (__stdcall *)(signed int))v4[5].OnQualityRemoved)(6);
      else
        ((void (__stdcall *)(signed int))v4[5].OnQualityRemoved)(1);
      ++v2;
    }
    while ( v2 < v1->m_rgTokens.m_num );
  }
  if ( !v1->m_pListBox || !v1->m_rgTokens.m_num )
  {
    StringInfo::StringInfo(&siSelectText);
    StringInfo::SetStringIDandTableEnum(&siSelectText, ID_Effects_Info_NoSpells, 268435457);
    v25 = StringInfo::GetString(&siSelectText, (PStringBase<unsigned short> *)&v28, 0);
    UIElement_Text::SetText(v1->m_pInfoText, v25);
    v6 = v28.m_buffer;
    goto LABEL_38;
  }
  if ( !v1->m_SelectedSpell )
  {
    StringInfo::StringInfo(&siSelectText);
    StringInfo::SetStringIDandTableEnum(&siSelectText, ID_Effects_Info_SelectASpell, 268435457);
    v5 = StringInfo::GetString(&siSelectText, &result, 0);
    UIElement_Text::SetText(v1->m_pInfoText, v5);
    v6 = result.m_charbuffer;
LABEL_38:
    v26 = (int)((char *)v6 - 20);
    if ( !InterlockedDecrement((volatile LONG *)(v26 + 4)) )
    {
      if ( v26 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
    }
    StringInfo::~StringInfo(&siSelectText);
    return 1;
  }
  v7 = ClientMagicSystem::GetMagicSystem();
  v8 = v7;
  if ( !v7 )
    return 0;
  v10 = ClientMagicSystem::GetSpellName(v7, (AC1Legacy::PStringBase<char> *)&result, v1->m_SelectedSpell);
  PStringBase<char>::PStringBase<char>(&infoText, v10->m_buffer->m_data);
  v11 = result.m_charbuffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer->m_data[2]) && v11 )
    (**(void (__thiscall ***)(PSRefBufferCharData<unsigned short> *, signed int))&v11->m_data[0])(v11, 1);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, "\n\n");
  v12 = result.m_charbuffer;
  v13 = *(_DWORD *)&result.m_charbuffer[-1].m_data[14];
  if ( v13 != 1 )
  {
    PStringBase<char>::append_n_chars(&infoText, (const char *)result.m_charbuffer, v13 - 1);
    v12 = result.m_charbuffer;
  }
  v14 = (int)&v12[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  v15 = ClientMagicSystem::GetSpellDescription(v8, &v28, v1->m_SelectedSpell);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&result, v15->m_buffer->m_data);
  v16 = result.m_charbuffer;
  v17 = *(_DWORD *)&result.m_charbuffer[-1].m_data[14];
  if ( v17 != 1 )
  {
    PStringBase<char>::append_n_chars(&infoText, (const char *)result.m_charbuffer, v17 - 1);
    v16 = result.m_charbuffer;
  }
  v18 = (int)&v16[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v16[-1].m_data[8]) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  v19 = v28.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v28.m_buffer->m_cRef) && v19 )
    v19->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v19, 1u);
  StringInfo::StringInfo(&siInfoText);
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&v28, 0, &infoText);
  StringInfo::SetLiteralValue(&siInfoText, v20, 1);
  v21 = (char *)&v28.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&v28.m_buffer[-1].m_cRef + 1) && v21 )
    (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
  v22 = StringInfo::GetString(&siInfoText, (PStringBase<unsigned short> *)&v28, 0);
  UIElement_Text::SetText(v1->m_pInfoText, v22);
  v23 = (char *)&v28.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&v28.m_buffer[-1].m_cRef + 1) && v23 )
    (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
  StringInfo::~StringInfo(&siInfoText);
  v24 = &infoText.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&infoText.m_charbuffer[-1]) && v24 )
  {
    (**(void (__thiscall ***)(char *, signed int))v24)(v24, 1);
    return 1;
  }
  return 1;
}

//----- (004B8290) --------------------------------------------------------  // acclient.c:236123
char __thiscall gmEffectsUI::SetSelectedSpell(gmEffectsUI *this, UIElement *_selectedUI)
{
  gmEffectsUI *v2; // edi@1
  int v3; // esi@1
  IInputActionCallbackVtbl *v4; // eax@2
  BasePropertyDesc *v5; // ecx@5
  unsigned int v6; // edx@5
  BasePropertyValue *v7; // ecx@9
  unsigned int v8; // edx@9
  BaseProperty infoProperty; // [sp+10h] [bp-8h]@2

  v2 = this;
  v3 = 0;
  if ( _selectedUI )
  {
    v4 = _selectedUI->vfptr;
    infoProperty.m_pcPropertyDesc = 0;
    infoProperty.m_pcPropertyValue = 0;
    ((void (__stdcall *)(signed int, BaseProperty *))v4[17].OnAction)(268435514, &infoProperty);
    _selectedUI = 0;
    if ( infoProperty.m_pcPropertyValue )
      ((void (__stdcall *)(_DWORD))infoProperty.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&_selectedUI);
    v3 = ((int (*)(void))v2->m_rgTokens.m_data[(_DWORD)_selectedUI]->vfptr[3].OnQualityChanged)();
    if ( (_DWORD)infoProperty.m_pcPropertyDesc )
    {
      v5 = infoProperty.m_pcPropertyDesc;
      v6 = infoProperty.m_pcPropertyDesc->m_cRef - 1;
      infoProperty.m_pcPropertyDesc->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      infoProperty.m_pcPropertyDesc = 0;
    }
    if ( infoProperty.m_pcPropertyValue )
    {
      v7 = infoProperty.m_pcPropertyValue;
      v8 = infoProperty.m_pcPropertyValue->m_cRef - 1;
      infoProperty.m_pcPropertyValue->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    }
  }
  if ( v2->m_SelectedSpell == v3 )
    v3 = 0;
  v2->m_SelectedSpell = v3;
  return gmEffectsUI::UpdateSelection(v2);
}

//----- (004B8350) --------------------------------------------------------  // acclient.c:236171
char __thiscall gmEffectsUI::RebuildList(gmEffectsUI *this, CACQualities *i_playerDesc)
{
  gmEffectsUI *v2; // esi@1
  PackObjVtbl *v3; // ebp@1
  char result; // al@2
  PackableLLNode<Enchantment> *v5; // ebx@3
  int v6; // ebp@6
  ClientMagicSystem *v7; // edi@7
  unsigned int v8; // eax@9
  unsigned int v9; // edi@9
  int v10; // ebx@10
  EffectInfoRegion *v11; // eax@12
  EffectInfoRegion *v12; // eax@13
  unsigned __int64 v13; // st7@15
  PackableList<Enchantment> affectors; // [sp+18h] [bp-ACh]@1
  EffectInfoRegion *i_rData; // [sp+28h] [bp-9Ch]@13
  PackableLLIter<Enchantment> iter; // [sp+2Ch] [bp-98h]@4
  CSpellBase spellBase; // [sp+34h] [bp-90h]@8

  v2 = this;
  gmEffectsUI::FlushList(this);
  v3 = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  affectors.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  affectors.head = 0;
  affectors.tail = 0;
  affectors.curNum = 0;
  if ( CACQualities::GetEnchantmentsInEffect(i_playerDesc, &affectors) )
  {
    v5 = affectors.head;
    if ( affectors.head )
    {
      iter._current = affectors.head;
      while ( v5 )
      {
        v6 = v5->data._id & 0xFFFF;
        if ( gmEffectsUI::SpellEffectMatchesUIType(v2, v6) )
        {
          v7 = ClientMagicSystem::GetMagicSystem();
          if ( !v7 )
          {
            affectors.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
            PackableList<Enchantment>::Flush(&affectors);
            return 0;
          }
          CSpellBase::CSpellBase(&spellBase);
          if ( ClientMagicSystem::InqSpellBase(v7, v6, &spellBase) )
          {
            v8 = gmEffectsUI::GetSortedInsertionPlace(v2, &spellBase);
            v9 = v8;
            if ( v8 < v2->m_rgTokens.m_num )
            {
              do
              {
                v10 = v8 + 1;
                InfoRegion::SetID((InfoRegion *)&v2->m_rgTokens.m_data[v8]->vfptr, v8 + 1);
                v8 = v10;
              }
              while ( v10 < v2->m_rgTokens.m_num );
              v5 = iter._current;
            }
            v11 = (EffectInfoRegion *)operator new(0x18u);
            if ( v11 )
            {
              EffectInfoRegion::EffectInfoRegion(v11, v2->m_pListBox, v9, v6, 0);
              i_rData = v12;
            }
            else
            {
              i_rData = 0;
            }
            SmartArray<LayerStage *,1>::InsertOrderedByIndex(&v2->m_rgTokens, &i_rData, v9);
            *(double *)&v13 = v5->data._duration + v5->data._start_time - COERCE_DOUBLE(Timer::cur_time.Cmd);
            ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v2->m_rgTokens.m_data[v9]->vfptr[6].OnQualityChanged)(
              v2->m_rgTokens.m_data[v9],
              v13,
              v13 >> 32);
          }
          CSpellBase::~CSpellBase(&spellBase);
        }
        iter._current = v5->next;
        v5 = iter._current;
        v3 = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      }
      if ( v2->m_SelectedSpell && !CACQualities::IsEnchanted(i_playerDesc, v2->m_SelectedSpell) )
        v2->m_SelectedSpell = 0;
      gmEffectsUI::UpdateSelection(v2);
    }
    affectors.vfptr = v3;
    PackableList<Enchantment>::Flush(&affectors);
    result = 1;
  }
  else
  {
    affectors.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
    PackableList<Enchantment>::Flush(&affectors);
    result = 0;
  }
  return result;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (004B8530) --------------------------------------------------------  // acclient.c:236273
char __thiscall gmEffectsUI::Update(gmEffectsUI *this, CACQualities *i_playerDesc)
{
  char result; // al@2

  if ( (*((_DWORD *)&this->0 + 41) >> 1) & 1 )
  {
    if ( this->m_bNeedToRebuild )
    {
      gmEffectsUI::RebuildList(this, i_playerDesc);
      result = 1;
    }
    else
    {
      gmEffectsUI::UpdateDurations(this, i_playerDesc);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004B8570) --------------------------------------------------------  // acclient.c:236298
void __thiscall gmEffectsUI::RecvNotice_PlayerDescReceived(gmEffectsUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  unsigned int v3; // eax@1
  char *v4; // ecx@1

  LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
  v3 = (unsigned int)this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[7];
  v4 = (char *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9];
  if ( (v3 >> 1) & 1 )
  {
    if ( v4[1572] )
      gmEffectsUI::RebuildList((gmEffectsUI *)v4, i_playerDesc);
    else
      gmEffectsUI::UpdateDurations((gmEffectsUI *)v4, i_playerDesc);
  }
}

//----- (004B85B0) --------------------------------------------------------  // acclient.c:236316
char __thiscall gmEffectsUI::Update(gmEffectsUI *this)
{
  gmEffectsUI *v1; // ebp@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // esi@2
  int v4; // ebx@4
  PlayerDesc *v5; // esi@6
  char v7; // bl@10
  int v8; // [sp-8h] [bp-2Ch]@2
  Interface *_rpInterface; // [sp+10h] [bp-14h]@2
  TResult result; // [sp+14h] [bp-10h]@2
  char v11; // [sp+18h] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@2

  v1 = this;
  if ( !((*((_DWORD *)&this->0 + 41) >> 1) & 1) )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_8, &_rpInterface);
  v3 = _rpInterface;
  v8 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v8, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v7 = gmEffectsUI::Update(v1, (CACQualities *)&playerDesc.m_pInterface->vfptr);
  v5->vfptr->Release((Interface *)v5);
  return v7;
}

//----- (004B8660) --------------------------------------------------------  // acclient.c:236359
UIElementMessageListenResult __thiscall gmEffectsUI::ListenToElementMessage(gmEffectsUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmEffectsUI *v3; // esi@1
  UIElementMessageListenResult result; // eax@4
  UIElement_ListBox *v5; // ecx@7
  UIElement *v6; // eax@9

  v2 = i_rMsg->idMessage;
  v3 = this;
  if ( v2 != 24 )
  {
    if ( v2 == 28 )
    {
      v5 = this->m_pListBox;
      if ( v5 )
      {
        if ( i_rMsg->idElement == 268435747 )
        {
          v6 = UIElement_ListBox::GetItemUnderMouse(v5);
          if ( i_rMsg->dwParam1 == 7 )
            gmEffectsUI::SetSelectedSpell(v3, v6);
        }
      }
    }
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  if ( (gmEffectsUI *)i_rMsg->pElement != this )
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  if ( i_rMsg->dwParam1 )
  {
    UIListener::RegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    gmEffectsUI::Update(v3);
    result = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  else
  {
    UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    result = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  return result;
}

//----- (004B86E0) --------------------------------------------------------  // acclient.c:236403
void __thiscall gmEffectsUI::RecvNotice_EnchantmentsChanged(gmEffectsUI *this)
{
  LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8]) = 1;
  gmEffectsUI::Update((gmEffectsUI *)((char *)this - 1528));
}

//----- (006F1950) --------------------------------------------------------  // acclient.c:773867
void _E91_78()
{
  outside_val_70 = 1000.0 + 1.0;
}

//----- (006F1970) --------------------------------------------------------  // acclient.c:773873
void _E93_54()
{
  block_length_70 = 24.0 * 8.0;
}

//----- (006F1990) --------------------------------------------------------  // acclient.c:773879
void _E95_54()
{
  half_square_length_70 = 24.0 * 0.5;
}

//----- (006F19B0) --------------------------------------------------------  // acclient.c:773885
int _E97_79()
{
  return atexit(_E98_91);
}

//----- (006F19C0) --------------------------------------------------------  // acclient.c:773891
int _E100_72()
{
  return atexit(nullsub_805);
}

//----- (006F19D0) --------------------------------------------------------  // acclient.c:773897
int _E103_64()
{
  return atexit(_E104_79);
}

//----- (006F19E0) --------------------------------------------------------  // acclient.c:773903
void _E109_30()
{
  DEFAULT_VIEW_RADIUS_42 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F1A00) --------------------------------------------------------  // acclient.c:773909
void _E111_19()
{
  MIN_QUANTUM_42 = 1.0 / 30.0;
}

//----- (006F1A20) --------------------------------------------------------  // acclient.c:773915
void _E113_7()
{
  MAX_QUANTUM_42 = 1.0 / 5.0;
}

//----- (006F1A40) --------------------------------------------------------  // acclient.c:773921
void _E115_34()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_77, PFID_A8R8G8B8);
}

//----- (006F1A50) --------------------------------------------------------  // acclient.c:773927
int _E118_37()
{
  return atexit(_E119_75);
}

//----- (006F1A60) --------------------------------------------------------  // acclient.c:773933
unsigned int _E121_39()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Effects_Title_Positive");
  ID_Effects_Title_Positive = result;
  return result;
}

//----- (006F1A80) --------------------------------------------------------  // acclient.c:773943
unsigned int _E123_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Effects_Title_Negative");
  ID_Effects_Title_Negative = result;
  return result;
}

//----- (006F1AA0) --------------------------------------------------------  // acclient.c:773953
unsigned int _E125_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Effects_Info_NoSpells");
  ID_Effects_Info_NoSpells = result;
  return result;
}

//----- (006F1AC0) --------------------------------------------------------  // acclient.c:773963
unsigned int _E127_31()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Effects_Info_SelectASpell");
  ID_Effects_Info_SelectASpell = result;
  return result;
}

//----- (006F1AE0) --------------------------------------------------------  // acclient.c:773973
int sub_6F1AE0()
{
  return atexit(nullsub_803);
}

