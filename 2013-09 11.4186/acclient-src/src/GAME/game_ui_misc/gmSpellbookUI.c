/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSpellbookUI
   Object     : GAME\game_ui_misc\gmSpellbookUI.obj
   Functions  : 52
   Addresses  : 0048AE20 - 0075F630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0048AE20) --------------------------------------------------------  // acclient.c:198441
gmSpellbookUI *__thiscall gmSpellbookUI::DynamicCast(gmSpellbookUI *this, unsigned int i_eType)
{
  gmSpellbookUI *result; // eax@1

  result = this;
  if ( i_eType != 268435502 )
    result = (gmSpellbookUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0048AE40) --------------------------------------------------------  // acclient.c:198452
signed int gmSpellbookUI::GetUIElementType()
{
  return 268435502;
}

//----- (0048AE50) --------------------------------------------------------  // acclient.c:198458
UIElement *__usercall gmSpellbookUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x638u);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmSpellbookUI::vftable;
    *((_DWORD *)v3 + 382) = &gmSpellbookUI::vftable;
    *((_DWORD *)v3 + 383) = 0;
    *((_DWORD *)v3 + 384) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A3AA0: using guessed type bool (__thiscall *gmSpellbookUI::vftable)(DBCache *this);
// 7A3D48: using guessed type int (__thiscall *gmSpellbookUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048AEB0) --------------------------------------------------------  // acclient.c:198485
bool __stdcall gmSpellbookUI::IsFilteredOut(CSpellBase *spellBase)
{
  CPlayerSystem *v2; // eax@1
  __int16 v3; // ax@1
  __int16 v4; // bx@1
  bool result; // al@3
  bool v6; // zf@12

  v2 = CPlayerSystem::GetPlayerSystem();
  v3 = PlayerModule::GetSpellbookFilters((PlayerModule *)&v2->playerModule.vfptr);
  v4 = v3;
  switch ( spellBase->_school )
  {
    case 4u:
      if ( v3 & 1 )
        goto LABEL_11;
      result = 1;
      break;
    case 3u:
      if ( v3 & 2 )
        goto LABEL_11;
      result = 1;
      break;
    case 2u:
      if ( v3 & 4 )
        goto LABEL_11;
      result = 1;
      break;
    case 1u:
      if ( v3 & 8 )
        goto LABEL_11;
      result = 1;
      break;
    case 5u:
      if ( !(HIBYTE(v3) & 0x20) )
        goto LABEL_14;
LABEL_11:
      switch ( CSpellBase::InqSpellLevelByRoughHeuristic(spellBase) )
      {
        case 1:
          v6 = (v4 & 0x10) == 0;
          goto LABEL_13;
        case 2:
          v6 = (v4 & 0x20) == 0;
          goto LABEL_13;
        case 3:
          v6 = (v4 & 0x40) == 0;
          goto LABEL_13;
        case 4:
          if ( (char)v4 < 0 )
            break;
          return 1;
        case 5:
          v6 = (HIBYTE(v4) & 1) == 0;
          goto LABEL_13;
        case 6:
          v6 = (HIBYTE(v4) & 2) == 0;
          goto LABEL_13;
        case 7:
          v6 = (HIBYTE(v4) & 4) == 0;
          goto LABEL_13;
        case 8:
          v6 = (HIBYTE(v4) & 8) == 0;
LABEL_13:
          if ( v6 )
            goto LABEL_14;
          break;
        case 9:
          if ( !(HIBYTE(v4) & 0x10) )
            goto LABEL_14;
          break;
        default:
          goto LABEL_14;
      }
      result = 0;
      break;
    default:
LABEL_14:
      result = 1;
      break;
  }
  return result;
}

//----- (0048AF90) --------------------------------------------------------  // acclient.c:198570
void __thiscall gmSpellbookUI::ResetFilterButtons(gmSpellbookUI *this)
{
  gmSpellbookUI *v1; // edi@1
  CPlayerSystem *v2; // eax@1
  __int16 v3; // si@1

  v1 = this;
  v2 = CPlayerSystem::GetPlayerSystem();
  v3 = PlayerModule::GetSpellbookFilters((PlayerModule *)&v2->playerModule.vfptr);
  ((void (__stdcall *)(signed int))v1->m_btnSchool_Creature->vfptr[13].__vecDelDtor)((v3 & 1) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnSchool_Item->vfptr[13].__vecDelDtor)((v3 & 2) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnSchool_Life->vfptr[13].__vecDelDtor)((v3 & 4) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnSchool_War->vfptr[13].__vecDelDtor)((v3 & 8) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnSchool_Void->vfptr[13].__vecDelDtor)((v3 & 0x2000) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_1->vfptr[13].__vecDelDtor)((v3 & 0x10) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_2->vfptr[13].__vecDelDtor)((v3 & 0x20) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_3->vfptr[13].__vecDelDtor)((v3 & 0x40) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_4->vfptr[13].__vecDelDtor)((v3 & 0x80) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_5->vfptr[13].__vecDelDtor)((v3 & 0x100) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_6->vfptr[13].__vecDelDtor)((v3 & 0x200) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_7->vfptr[13].__vecDelDtor)((v3 & 0x400) != 0 ? 6 : 1);
  ((void (__stdcall *)(signed int))v1->m_btnLevel_8->vfptr[13].__vecDelDtor)((v3 & 0x800) != 0 ? 6 : 1);
}

//----- (0048B120) --------------------------------------------------------  // acclient.c:198595
void __thiscall UIElement_ListBox::ScrollToHome(UIElement_ListBox *this)
{
  if ( this->m_listItems.m_num )
    UIElement_ListBox::ScrollToShow(this, 0);
}

//----- (0048B140) --------------------------------------------------------  // acclient.c:198602
void __thiscall CSpellBase::CSpellBase(CSpellBase *this)
{
  CSpellBase *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&CSpellBase::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_desc.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v1->_school = 0;
  v1->_iconID.id = stru_83DF0C.id;
  v1->_category = 0;
  v1->_bitfield = 0;
  v1->_base_mana = 0;
  v1->_mana_mod = 0;
  LODWORD(v1->_base_range_constant) = 0;
  LODWORD(v1->_base_range_mod) = 0;
  v1->_power = 0;
  LODWORD(v1->_spell_economy_mod) = -1082130432;
  v1->_formula_version = 0;
  LODWORD(v1->_component_loss) = 0;
  v1->_formula.vfptr = (PackObjVtbl *)&SpellFormula::vftable;
  memset(v1->_formula._comps, 0, sizeof(v1->_formula._comps));
  v1->_caster_effect = 0;
  v1->_target_effect = 0;
  v1->_fizzle_effect = 0;
  LODWORD(v1->_recovery_interval) = 0;
  HIDWORD(v1->_recovery_interval) = 0;
  LODWORD(v1->_recovery_amount) = 0;
  v1->_display_order = -1;
  v1->_non_component_target_type = 0;
  MetaSpell::MetaSpell(&v1->_meta_spell);
}
// 7A3A8C: using guessed type int (__thiscall *SpellFormula::vftable)(void *, char);
// 7A3E94: using guessed type int (__thiscall *CSpellBase::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0048B1F0) --------------------------------------------------------  // acclient.c:198645
void __thiscall CSpellBase::~CSpellBase(CSpellBase *this)
{
  CSpellBase *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4

  v1 = this;
  MetaSpell::~MetaSpell(&this->_meta_spell);
  v2 = v1->_desc.m_buffer;
  v1->_formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0048B250) --------------------------------------------------------  // acclient.c:198665
UIElement_Field *__thiscall gmSpellbookUI::vector_deleting_destructor(gmSpellbookUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmSpellbookUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmSpellbookUI::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A3AA0: using guessed type bool (__thiscall *gmSpellbookUI::vftable)(DBCache *this);
// 7A3D48: using guessed type int (__thiscall *gmSpellbookUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048B2B0) --------------------------------------------------------  // acclient.c:198690
void __thiscall gmSpellbookUI::PostInit(gmSpellbookUI *this)
{
  gmSpellbookUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  GlobalEventHandler *v4; // eax@4
  GlobalEventHandler *v5; // edi@4
  int v6; // esi@5

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000295u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435505);
  else
    v3 = 0;
  v1->m_spellList = (UIElement_ItemList *)v3;
  v1->m_selectedSpellID = 0;
  v1->m_btnSchool_Creature = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000298u);
  v1->m_btnSchool_Item = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000299u);
  v1->m_btnSchool_Life = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000029Au);
  v1->m_btnSchool_War = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000029Bu);
  v1->m_btnSchool_Void = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005C0u);
  v1->m_btnLevel_1 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000029Cu);
  v1->m_btnLevel_2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000029Du);
  v1->m_btnLevel_3 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000029Eu);
  v1->m_btnLevel_4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000029Fu);
  v1->m_btnLevel_5 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100002A0u);
  v1->m_btnLevel_6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100002A1u);
  v1->m_btnLevel_7 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100002A2u);
  v1->m_btnLevel_8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000054Eu);
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  v5 = v4;
  if ( v4 )
  {
    v6 = (int)&v1->vfptr;
    v4->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v4, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v6);
    v5->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v5, 5100127u, (NoticeHandler *)v6);
    v5->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v5, (unsigned int)&loc_4DD260, (NoticeHandler *)v6);
  }
}

//----- (0048B420) --------------------------------------------------------  // acclient.c:198733
void __cdecl gmSpellbookUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000002Eu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSpellbookUI::Create);
}

//----- (0048B440) --------------------------------------------------------  // acclient.c:198741
unsigned int __thiscall gmSpellbookUI::GetSortedInsertionPlace(gmSpellbookUI *this, CSpellBase *spellBase)
{
  gmSpellbookUI *v2; // edi@1
  ClientMagicSystem *v3; // ebx@1
  unsigned int v4; // ebp@1
  unsigned int v5; // esi@1
  UIElement *v6; // eax@2
  int v7; // eax@3
  AC1Legacy::PSRefBuffer<char> *v8; // esi@7
  AC1Legacy::PSRefBuffer<char> *v9; // esi@10
  unsigned int result; // eax@13
  CSpellBase cmpBase; // [sp+10h] [bp-90h]@1

  v2 = this;
  v3 = ClientMagicSystem::GetMagicSystem();
  CSpellBase::CSpellBase(&cmpBase);
  v4 = v2->m_spellList->m_listItems.m_num;
  v5 = 0;
  if ( v4 )
  {
    while ( 1 )
    {
      v6 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->m_spellList->vfptr, v5);
      if ( v6 )
      {
        v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435506);
        if ( v7 )
        {
          if ( ClientMagicSystem::InqSpellBase(v3, *(_DWORD *)(v7 + 1536), &cmpBase)
            && spellBase->_display_order < cmpBase._display_order )
            break;
        }
      }
      ++v5;
      if ( v5 >= v4 )
        goto LABEL_7;
    }
    CSpellBase::~CSpellBase(&cmpBase);
    result = v5;
  }
  else
  {
LABEL_7:
    MetaSpell::~MetaSpell(&cmpBase._meta_spell);
    v8 = cmpBase._desc.m_buffer;
    cmpBase._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&cmpBase._desc.m_buffer->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    v9 = cmpBase._name.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&cmpBase._name.m_buffer->m_cRef) )
    {
      if ( v9 )
        v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    }
    result = v4;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0048B540) --------------------------------------------------------  // acclient.c:198802
void __thiscall gmSpellbookUI::SetSelected(gmSpellbookUI *this, unsigned int _selectedSpellID)
{
  gmSpellbookUI *v2; // esi@1
  unsigned int v3; // edi@1
  UIElement *v4; // eax@2
  int v5; // eax@3

  v2 = this;
  v3 = 0;
  if ( (signed int)this->m_spellList->m_listItems.m_num <= 0 )
  {
    this->m_selectedSpellID = _selectedSpellID;
  }
  else
  {
    do
    {
      v4 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v2->m_spellList->vfptr, v3);
      if ( v4 )
      {
        v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        if ( v5 )
        {
          if ( _selectedSpellID && *(_DWORD *)(v5 + 1536) == _selectedSpellID )
          {
            UIElement_UIItem::SetSelectedState((UIElement_UIItem *)v5, 1);
            UIElement_ListBox::ScrollToView((UIElement_ListBox *)&v2->m_spellList->vfptr, v3);
          }
          else
          {
            UIElement_UIItem::SetSelectedState((UIElement_UIItem *)v5, 0);
          }
        }
      }
      ++v3;
    }
    while ( (signed int)v3 < (signed int)v2->m_spellList->m_listItems.m_num );
    v2->m_selectedSpellID = _selectedSpellID;
  }
}

//----- (0048B5E0) --------------------------------------------------------  // acclient.c:198844
void __thiscall gmSpellbookUI::UpdateFilter(gmSpellbookUI *this, unsigned int buttonID)
{
  gmSpellbookUI *v2; // esi@1
  UIElement *v3; // eax@1
  bool v4; // bl@2
  signed int v5; // esi@3
  CPlayerSystem *v6; // eax@28
  unsigned int v7; // eax@28
  int v8; // edi@29
  CPlayerSystem *v9; // eax@32

  v2 = this;
  v3 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, buttonID);
  if ( v3 )
  {
    v4 = v3->m_state == 6;
    if ( v3 == v2->m_btnSchool_Creature )
    {
      v5 = 1;
    }
    else if ( v3 == v2->m_btnSchool_Item )
    {
      v5 = 2;
    }
    else if ( v3 == v2->m_btnSchool_Life )
    {
      v5 = 4;
    }
    else if ( v3 == v2->m_btnSchool_War )
    {
      v5 = 8;
    }
    else if ( v3 == v2->m_btnSchool_Void )
    {
      v5 = 0x2000;
    }
    else if ( v3 == v2->m_btnLevel_1 )
    {
      v5 = 16;
    }
    else if ( v3 == v2->m_btnLevel_2 )
    {
      v5 = 32;
    }
    else if ( v3 == v2->m_btnLevel_3 )
    {
      v5 = 64;
    }
    else if ( v3 == v2->m_btnLevel_4 )
    {
      v5 = 128;
    }
    else if ( v3 == v2->m_btnLevel_5 )
    {
      v5 = 256;
    }
    else if ( v3 == v2->m_btnLevel_6 )
    {
      v5 = 512;
    }
    else if ( v3 == v2->m_btnLevel_7 )
    {
      v5 = 1024;
    }
    else
    {
      if ( v3 != v2->m_btnLevel_8 )
        return;
      v5 = 2048;
    }
    v6 = CPlayerSystem::GetPlayerSystem();
    v7 = PlayerModule::GetSpellbookFilters((PlayerModule *)&v6->playerModule.vfptr);
    if ( v4 )
      v8 = v5 | v7;
    else
      v8 = v7 & ~v5;
    if ( v8 != v7 )
    {
      v9 = CPlayerSystem::GetPlayerSystem();
      Client::SetPortA((PlayerModule *)&v9->playerModule.vfptr, v8);
      CM_Character::Event_SpellbookFilterEvent(v8);
    }
  }
}

//----- (0048B710) --------------------------------------------------------  // acclient.c:198930
signed int __thiscall PackableList<unsigned long>::Pack(PackableList<unsigned long> *this, void **addr, unsigned int size)
{
  PackableList<unsigned long> *v3; // esi@1
  signed int result; // eax@1
  PackableLLNode<unsigned long> *i; // ecx@4

  v3 = this;
  result = PackableList<unsigned long>::pack_size(this);
  if ( size >= result )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
    {
      if ( size >= 4 )
      {
        *(_DWORD *)*addr = i->data;
        *addr = (char *)*addr + 4;
      }
    }
  }
  return result;
}

//----- (0048B760) --------------------------------------------------------  // acclient.c:198958
signed int __thiscall PackableList<unsigned long>::pack_size(PackableList<unsigned long> *this)
{
  PackableLLNode<unsigned long> *v1; // ecx@1
  signed int result; // eax@1

  v1 = this->head;
  for ( result = 4; v1; result += 4 )
    v1 = v1->next;
  return result;
}

//----- (0048B780) --------------------------------------------------------  // acclient.c:198970
CSpellBase *__thiscall CSpellBase::scalar_deleting_destructor(CSpellBase *this, unsigned int a2)
{
  CSpellBase *v2; // esi@1

  v2 = this;
  CSpellBase::~CSpellBase(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048B7A0) --------------------------------------------------------  // acclient.c:198982
void __thiscall gmSpellbookUI::AddSpell(gmSpellbookUI *this, unsigned int _spellID)
{
  gmSpellbookUI *v2; // esi@1
  ClientMagicSystem *v3; // edi@1
  int v4; // eax@4
  CSpellBase spellBase; // [sp+8h] [bp-90h]@2

  v2 = this;
  v3 = ClientMagicSystem::GetMagicSystem();
  if ( v3 )
  {
    CSpellBase::CSpellBase(&spellBase);
    if ( ClientMagicSystem::InqSpellBase(v3, _spellID, &spellBase) && !gmSpellbookUI::IsFilteredOut(&spellBase) )
    {
      v4 = gmSpellbookUI::GetSortedInsertionPlace(v2, &spellBase);
      UIElement_ItemList::ItemList_InsertSpellShortcut(v2->m_spellList, _spellID, v4);
    }
    CSpellBase::~CSpellBase(&spellBase);
  }
}

//----- (0048B820) --------------------------------------------------------  // acclient.c:199004
int __thiscall InterfacePtr<PlayerDesc>::_QueryInterface(void *this, int a2, int a3, int a4)
{
  int v4; // edi@1
  void *v5; // esi@1
  int v6; // eax@2
  signed int v7; // ebx@2
  int v8; // ecx@2
  int v10; // ebp@6
  int v11; // ecx@9
  char v12; // [sp+10h] [bp-4h]@2

  v4 = a3;
  v5 = this;
  if ( a3 )
  {
    v6 = *(_DWORD *)a3;
    a3 = 0;
    v7 = *(_DWORD *)(*(int (__thiscall **)(int, char *, Turbine_GUID *, int *))(v6 + 12))(
                      v4,
                      &v12,
                      &PlayerDesc_InterfaceType_10,
                      &a3);
    v8 = *(_DWORD *)v5;
    if ( v7 < 0 )
    {
      if ( v8 )
        (*(void (**)(void))(*(_DWORD *)v8 + 20))();
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)a2 = v7;
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
      return a2;
    }
    v10 = a3;
    if ( v8 )
      (*(void (**)(void))(*(_DWORD *)v8 + 20))();
    *(_DWORD *)v5 = v10;
    *((_DWORD *)v5 + 1) = 0;
  }
  else
  {
    v11 = *(_DWORD *)this;
    if ( *(_DWORD *)v5 )
    {
      *(_DWORD *)v5 = 0;
      (*(void (**)(void))(*(_DWORD *)v11 + 20))();
      *((_DWORD *)v5 + 1) = 0;
    }
    v7 = -2147467262;
  }
  *(_DWORD *)a2 = v7;
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
  return a2;
}

//----- (0048B8D0) --------------------------------------------------------  // acclient.c:199061
void __thiscall gmSpellbookUI::RecvNotice_SpellAdded(gmSpellbookUI *this, unsigned int i_eSpellID)
{
  gmSpellbookUI *v2; // esi@1
  ClientMagicSystem *v3; // edi@1
  CSpellBase spellBase; // [sp+Ch] [bp-90h]@2

  v2 = (gmSpellbookUI *)((char *)this - 1528);
  gmSpellbookUI::AddSpell((gmSpellbookUI *)((char *)this - 1528), i_eSpellID);
  v3 = ClientMagicSystem::GetMagicSystem();
  if ( v3 )
  {
    CSpellBase::CSpellBase(&spellBase);
    if ( ClientMagicSystem::InqSpellBase(v3, i_eSpellID, &spellBase) && !gmSpellbookUI::IsFilteredOut(&spellBase) )
    {
      gmSpellbookUI::SetSelected(v2, i_eSpellID);
      v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 1u);
    }
    CSpellBase::~CSpellBase(&spellBase);
  }
}

//----- (0048B950) --------------------------------------------------------  // acclient.c:199083
void __thiscall PackableList<unsigned long>::Flush(PackableList<unsigned long> *this)
{
  PackableList<unsigned long> *v1; // esi@1
  PackableLLNode<unsigned long> *v2; // ecx@2
  PackableLLNode<unsigned long> *v3; // eax@3

  v1 = this;
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
      if ( v2 )
        operator delete(v2);
      --v1->curNum;
    }
  }
}

//----- (0048B9A0) --------------------------------------------------------  // acclient.c:199109
void __thiscall InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(InterfacePtr<PlayerDesc> *this, InterfacePtr<Interface> *_ptr)
{
  InterfacePtr<Interface> *v2; // edx@1
  InterfacePtr<PlayerDesc> *v3; // esi@1
  int v4; // [sp-8h] [bp-Ch]@1

  v2 = _ptr;
  v3 = this;
  this->m_pInterface = 0;
  this->m_trStatus.m_val = 0;
  v4 = (int)v2->m_pInterface;
  if ( v2->m_pInterface )
    v2->m_pInterface->vfptr->AddRef(v2->m_pInterface);
  v3->m_trStatus.m_val = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(v3, (int)&_ptr, v4, 0);
}

//----- (0048B9E0) --------------------------------------------------------  // acclient.c:199126
void __thiscall PackableList<unsigned long>::~PackableList<unsigned long>(PackableList<unsigned long> *this)
{
  PackableList<unsigned long> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  PackableList<unsigned long>::Flush(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (0048BA00) --------------------------------------------------------  // acclient.c:199139
int __thiscall PackableList<unsigned long>::UnPack(PackableList<unsigned long> *this, void **addr, unsigned int size)
{
  PackableList<unsigned long> *v3; // ebx@1
  int v4; // edi@2
  void *v5; // eax@3
  int result; // eax@4
  unsigned int temp; // [sp+0h] [bp-4h]@1

  temp = (unsigned int)this;
  v3 = this;
  PackableList<unsigned long>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    if ( v4 > 0 )
    {
      do
      {
        v5 = *addr;
        temp = *(_DWORD *)*addr;
        *addr = (char *)v5 + 4;
        PackableList<unsigned long>::InsertTail(v3, &temp);
        --v4;
      }
      while ( v4 );
    }
    result = 1;
  }
  return result;
}

//----- (0048BA60) --------------------------------------------------------  // acclient.c:199176
int __thiscall PackableList<unsigned long>::InsertTail(PackableList<unsigned long> *this, const unsigned int *val)
{
  PackableList<unsigned long> *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@5
  PackableLLNode<unsigned long> *v5; // ecx@6

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    *(_DWORD *)v3 = *val;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v5 = v2->tail;
    v5->next = (PackableLLNode<unsigned long> *)v3;
    *((_DWORD *)v3 + 2) = v5;
    v2->tail = (PackableLLNode<unsigned long> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  else
  {
    v2->head = (PackableLLNode<unsigned long> *)v3;
    v2->tail = (PackableLLNode<unsigned long> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (0048BAC0) --------------------------------------------------------  // acclient.c:199215
PackableList<unsigned long> *__thiscall PackableList<unsigned long>::vector_deleting_destructor(PackableList<unsigned long> *this, unsigned int a2)
{
  PackableList<unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  PackableList<unsigned long>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (0048BAF0) --------------------------------------------------------  // acclient.c:199231
void __thiscall gmSpellbookUI::UpdateFromPlayerDesc(gmSpellbookUI *this)
{
  gmSpellbookUI *v1; // ebp@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  CACQualities *v4; // ebx@5
  int v5; // eax@8
  Interface *v6; // ecx@8
  PackableLLNode<unsigned long> *i; // esi@9
  int v8; // [sp-8h] [bp-3Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-24h]@1
  TResult result; // [sp+14h] [bp-20h]@1
  char v11; // [sp+18h] [bp-1Ch]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-18h]@1
  PackableList<unsigned long> list; // [sp+24h] [bp-10h]@9

  v1 = this;
  UIElement_ItemList::ItemList_Flush(this->m_spellList);
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType, &_rpInterface);
  v8 = (int)_rpInterface;
  v3 = _rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  _rpInterface = *(Interface **)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v8, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = (CACQualities *)playerDesc.m_pInterface;
  if ( (_DWORD)playerDesc.m_pInterface )
  {
    if ( (signed int)_rpInterface >= 0 )
    {
      v5 = CACQualities::HasSpellBook((CACQualities *)&playerDesc.m_pInterface->vfptr);
      v6 = (Interface *)v4;
      if ( v5 )
      {
        list.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
        list.head = 0;
        list.tail = 0;
        list.curNum = 0;
        CACQualities::TranscribeSpells(v4, &list);
        for ( i = list.head; i; i = i->next )
          gmSpellbookUI::AddSpell(v1, i->data);
        gmSpellbookUI::ResetFilterButtons(v1);
        list.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
        PackableList<unsigned long>::Flush(&list);
        list.vfptr = (PackObjVtbl *)&PackObj::vftable;
        v6 = (Interface *)v4;
      }
      v4->vfptr->Release(v6);
    }
    else
    {
      playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (0048BC00) --------------------------------------------------------  // acclient.c:199295
void __thiscall gmSpellbookUI::RecvNotice_SpellRemoved(gmSpellbookUI *this, unsigned int i_eSpellID)
{
  gmSpellbookUI::UpdateFromPlayerDesc((gmSpellbookUI *)((char *)this - 1528));
}

//----- (0048BC10) --------------------------------------------------------  // acclient.c:199301
void __cdecl gmSpellbookUI::DeleteSpellDialogCallback(PropertyCollection *i_rcResults)
{
  PropertyCollection *v1; // esi@1
  unsigned int v2; // edx@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@1
  BasePropertyValue *v5; // ecx@6
  unsigned int v6; // edx@9
  HashTableData<unsigned long,BaseProperty> **v7; // eax@9
  HashTableData<unsigned long,BaseProperty> *v8; // eax@9
  BasePropertyDesc *v9; // ecx@19
  unsigned int v10; // edx@19
  int v11; // edx@23
  int v12; // [sp+8h] [bp-Ch]@1
  BaseProperty p; // [sp+Ch] [bp-8h]@1

  v1 = i_rcResults;
  v2 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v3 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  BYTE3(v12) = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v4 = v3[v2];
  if ( v4 )
  {
    while ( v4->m_hashKey != 146 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        return;
    }
    if ( v4 )
    {
      BaseProperty::operator=(&p, (int)&v4->m_data);
      v5 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(char *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)((char *)&v12 + 3);
        v5 = p.m_pcPropertyValue;
      }
      if ( BYTE3(v12) )
      {
        v6 = 0x1000003F % v1->m_hashProperties.m_intrusiveTable.m_numBuckets;
        v7 = v1->m_hashProperties.m_intrusiveTable.m_buckets;
        i_rcResults = 0;
        v8 = v7[v6];
        if ( v8 )
        {
          while ( v8->m_hashKey != 268435519 )
          {
            v8 = v8->m_hashNext;
            if ( !v8 )
              goto LABEL_18;
          }
          if ( v8 )
          {
            BaseProperty::operator=(&p, (int)&v8->m_data);
            v5 = p.m_pcPropertyValue;
            if ( p.m_pcPropertyValue )
            {
              ((void (__stdcall *)(PropertyCollection **))p.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&i_rcResults);
              v5 = p.m_pcPropertyValue;
            }
            if ( i_rcResults )
            {
              CM_Magic::Event_RemoveSpell((unsigned int)i_rcResults);
              v5 = p.m_pcPropertyValue;
            }
          }
        }
      }
LABEL_18:
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v9 = p.m_pcPropertyDesc;
        v10 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v10;
        if ( !v10 )
          ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
        v5 = p.m_pcPropertyValue;
        p.m_pcPropertyDesc = 0;
      }
      if ( v5 )
      {
        v11 = v5->m_cRef - 1;
        v5->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (0048BD40) --------------------------------------------------------  // acclient.c:199395
void __thiscall gmSpellbookUI::RecvNotice_PlayerDescReceived(gmSpellbookUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmSpellbookUI::UpdateFromPlayerDesc((gmSpellbookUI *)((char *)this - 1528));
}

//----- (0048BD50) --------------------------------------------------------  // acclient.c:199401
char __thiscall gmSpellbookUI::DeleteSpell(gmSpellbookUI *this)
{
  gmSpellbookUI *v1; // edi@1
  char v2; // al@2
  ClientMagicSystem *v3; // esi@3
  AC1Legacy::PStringBase<char> *v4; // eax@5
  AC1Legacy::PSRefBuffer<char> *v5; // esi@5
  AC1Legacy::PSRefBuffer<char> *v6; // ebx@8
  PStringBase<unsigned short> *v7; // eax@8
  char *v8; // esi@8
  unsigned int v9; // esi@15
  BasePropertyDesc *v10; // ecx@18
  unsigned int v11; // edx@18
  BasePropertyValue *v12; // ecx@22
  unsigned int v13; // esi@22
  BaseProperty p; // [sp+18h] [bp-118h]@11
  AC1Legacy::PStringBase<char> result; // [sp+20h] [bp-110h]@5
  AC1Legacy::PStringBase<char> msg; // [sp+24h] [bp-10Ch]@5
  PropertyCollection pc; // [sp+28h] [bp-108h]@11
  StringInfo v18; // [sp+A0h] [bp-90h]@8

  v1 = this;
  if ( this->m_selectedSpellID )
  {
    v3 = ClientMagicSystem::GetMagicSystem();
    if ( v3 )
    {
      msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v4 = ClientMagicSystem::GetSpellName(v3, &result, v1->m_selectedSpellID);
      AC1Legacy::PStringBase<char>::sprintf(
        &msg,
        "Are you sure you want to remove %s from your spellbook? You will no longer be able to cast this spell unless you learn it again!",
        v4->m_buffer->m_data);
      v5 = result.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v5 )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
      StringInfo::StringInfo(&v18);
      v6 = msg.m_buffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&result,
        0,
        msg.m_buffer->m_data);
      StringInfo::SetLiteralValue(&v18, v7, 1);
      v8 = (char *)&result.m_buffer[-1].m_cRef;
      if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer[-1].m_cRef + 1) && v8 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      PropertyCollection::PropertyCollection(&pc);
      p.m_pcPropertyDesc = 0;
      p.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&p, 0x8Eu);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
      }
      result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
      HashTable<unsigned long,BaseProperty,1>::add(
        (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
        (const unsigned int *)&result,
        &p);
      BaseProperty::SetPropertyName(&p, 0xC5u);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v18);
      }
      result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
      HashTable<unsigned long,BaseProperty,1>::add(
        (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
        (const unsigned int *)&result,
        &p);
      BaseProperty::SetPropertyName(&p, 0x1000003Fu);
      v9 = v1->m_selectedSpellID;
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v9);
      }
      result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
      HashTable<unsigned long,BaseProperty,1>::add(
        (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
        (const unsigned int *)&result,
        &p);
      DialogFactory::MakeCallbackDialogInCurrentUI(&pc, gmSpellbookUI::DeleteSpellDialogCallback);
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v10 = p.m_pcPropertyDesc;
        v11 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyDesc = 0;
      }
      if ( p.m_pcPropertyValue )
      {
        v12 = p.m_pcPropertyValue;
        v13 = p.m_pcPropertyValue->m_cRef - 1;
        p.m_pcPropertyValue->m_cRef = v13;
        if ( !v13 )
          ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyValue = 0;
      }
      PropertyCollection::~PropertyCollection(&pc);
      StringInfo::~StringInfo(&v18);
      if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
      {
        if ( v6 )
          v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
      }
      v2 = 1;
    }
    else
    {
      v2 = 0;
    }
  }
  else
  {
    v2 = 0;
  }
  return v2;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0048BFD0) --------------------------------------------------------  // acclient.c:199527
int __thiscall gmSpellbookUI::ListenToElementMessage(gmSpellbookUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmSpellbookUI *v3; // esi@1
  UIElement *v4; // eax@4
  int v5; // eax@5
  unsigned int v6; // ecx@6
  unsigned int v7; // eax@8
  unsigned int v9; // eax@11
  unsigned int v10; // eax@14
  UIElement_ItemList *v11; // ecx@21

  v2 = i_rMsg->idMessage;
  v3 = this;
  if ( v2 != 28 )
  {
    if ( v2 != 1 )
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    v10 = i_rMsg->idElement;
    if ( i_rMsg->idElement > 0x1000054E )
    {
      if ( v10 != 268436928 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    }
    else if ( i_rMsg->idElement != 268436814 )
    {
      if ( v10 < 0x10000298 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      if ( v10 > 0x100002A2 )
      {
        if ( v10 == 268436133 )
        {
          gmSpellbookUI::DeleteSpell(this);
          return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
    }
    gmSpellbookUI::UpdateFilter(this, i_rMsg->idElement);
    gmSpellbookUI::UpdateFromPlayerDesc(v3);
    v11 = v3->m_spellList;
    if ( v11 && v11->m_listItems.m_num )
      UIElement_ListBox::ScrollToShow((UIElement_ListBox *)&v11->vfptr, 0);
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  if ( this->m_spellList )
  {
    if ( UIElement::IsAncestorOfMe(i_rMsg->pElement, (UIElement *)&this->m_spellList->vfptr) )
    {
      v4 = UIElement_ListBox::GetItemUnderMouse((UIElement_ListBox *)&v3->m_spellList->vfptr);
      if ( v4 )
      {
        v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435506);
        if ( v5 )
        {
          v6 = i_rMsg->dwParam1;
          if ( v6 == 7 )
            goto LABEL_27;
          if ( v6 == 10 )
          {
            v7 = *(_DWORD *)(v5 + 1536);
            if ( v7 )
            {
              CM_Magic::SendNotice_AddSpellShortcut(v7);
              return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
            }
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          }
          if ( v6 == 8 )
          {
LABEL_27:
            v9 = *(_DWORD *)(v5 + 1536);
            if ( v9 )
            {
              gmSpellbookUI::SetSelected(v3, v9);
              return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
            }
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          }
        }
      }
    }
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (004C97A0) --------------------------------------------------------  // acclient.c:251022
BOOL __thiscall InterfacePtr<PlayerDesc>::IsValid(InterfacePtr<PlayerDesc> *this)
{
  return this->m_pInterface && (this->m_trStatus.m_val & 0x80000000) == 0;
}

//----- (006EDC80) --------------------------------------------------------  // acclient.c:769727
void _E91_52()
{
  outside_val_44 = 1000.0 + 1.0;
}

//----- (006EDCA0) --------------------------------------------------------  // acclient.c:769733
void _E93_28()
{
  block_length_44 = 24.0 * 8.0;
}

//----- (006EDCC0) --------------------------------------------------------  // acclient.c:769739
void _E95_28()
{
  half_square_length_44 = 24.0 * 0.5;
}

//----- (006EDCE0) --------------------------------------------------------  // acclient.c:769745
int _E97_53()
{
  return atexit(_E98_65);
}

//----- (006EDCF0) --------------------------------------------------------  // acclient.c:769751
int _E100_46()
{
  return atexit(_E101_83);
}

//----- (006EDD00) --------------------------------------------------------  // acclient.c:769757
int _E103_38()
{
  return atexit(_E104_53);
}

//----- (006EDD10) --------------------------------------------------------  // acclient.c:769763
void _E109_20()
{
  DEFAULT_VIEW_RADIUS_22 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EDD30) --------------------------------------------------------  // acclient.c:769769
void _E111_13()
{
  MIN_QUANTUM_22 = 1.0 / 30.0;
}

//----- (006EDD50) --------------------------------------------------------  // acclient.c:769775
void _E113_1()
{
  MAX_QUANTUM_22 = 1.0 / 5.0;
}

//----- (006EDD70) --------------------------------------------------------  // acclient.c:769781
void _E115_17()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_57, PFID_A8R8G8B8);
}

//----- (006EDD80) --------------------------------------------------------  // acclient.c:769787
void _E118_28()
{
  LOWEST_DATA_RATE_65 = 1024;
}

//----- (006EDD90) --------------------------------------------------------  // acclient.c:769793
void _E120_18()
{
  HIGHEST_DATA_RATE_65 = 0x7FFF;
}

//----- (006EDDA0) --------------------------------------------------------  // acclient.c:769799
int _E122_7()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_65;
  INITIAL_MAX_DATA_RATE_13 = LOWEST_DATA_RATE_65;
  return result;
}

//----- (006EDDB0) --------------------------------------------------------  // acclient.c:769809
int _E124_22()
{
  return atexit(_E125_32);
}

//----- (006EDDC0) --------------------------------------------------------  // acclient.c:769815
int _E127_18()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_16, "Misc.TooltipEnable");
  return atexit(_E128_33);
}

//----- (006EDDE0) --------------------------------------------------------  // acclient.c:769822
int _E130_19()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_16, "Misc.TooltipDelay");
  return atexit(_E131_29);
}

//----- (006EDE00) --------------------------------------------------------  // acclient.c:769829
int sub_6EDE00()
{
  return atexit(nullsub_885);
}

//----- (0075F600) --------------------------------------------------------  // acclient.c:887263
void __cdecl _E128_33()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F630) --------------------------------------------------------  // acclient.c:887276
void __cdecl _E131_29()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

