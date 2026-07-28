/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : InfoRegion
   Object     : GAME\game_ui_misc\InfoRegion.obj
   Functions  : 47
   Addresses  : 004F0E70 - 006F7E60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F0E70) --------------------------------------------------------  // acclient.c:285115
void __thiscall InfoRegion::~InfoRegion(InfoRegion *this)
{
  this->vfptr = (QualityChangeHandlerVtbl *)InfoRegion::vftable;
  (*(void (__stdcall **)(_DWORD))&QualityRegistrar::s_pQR->vfptr->gap14[0])(this);
}
// 7C3FF0: using guessed type void (__thiscall *InfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (004F0EB0) --------------------------------------------------------  // acclient.c:285135
void __thiscall InfoRegion::OnQualityRemoved(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  InfoRegion *v4; // esi@1
  unsigned int v5; // eax@1

  v4 = this;
  v5 = ((int (*)(void))this->vfptr[3].OnQualityChanged)();
  UIElement::BroadcastElementMessage(v4->m_pElement, 0x10000004u, v4->m_StatType, v5);
  ((void (__thiscall *)(InfoRegion *))v4->vfptr[4].OnQualityRemoved)(v4);
}

//----- (004F0EE0) --------------------------------------------------------  // acclient.c:285147
bool __thiscall InfoRegion::SetState(InfoRegion *this, unsigned int _state)
{
  UIElement *v2; // ecx@1
  bool result; // al@2

  v2 = this->m_pElement;
  if ( v2 )
    result = ((int (__stdcall *)(unsigned int))v2->vfptr[13].__vecDelDtor)(_state);
  else
    result = 0;
  return result;
}

//----- (004F0F00) --------------------------------------------------------  // acclient.c:285161
char __thiscall AttributeInfoRegion::GetLabel(AttributeInfoRegion *this, PStringBase<unsigned short> *i_name)
{
  return SkillSystem::InqAttributeName(this->m_Attribute, i_name);
}

//----- (004F0F20) --------------------------------------------------------  // acclient.c:285167
char __thiscall AttributeInfoRegion::GetTooltip(AttributeInfoRegion *this, PStringBase<unsigned short> *i_name)
{
  return SkillSystem::InqAttributeDescription(this->m_Attribute, i_name);
}

//----- (004F0F40) --------------------------------------------------------  // acclient.c:285173
char __thiscall Attribute2ndInfoRegion::GetLabel(Attribute2ndInfoRegion *this, PStringBase<unsigned short> *i_name)
{
  return SkillSystem::InqAttribute2ndName(this->m_CurAttribute, i_name);
}

//----- (004F0F60) --------------------------------------------------------  // acclient.c:285179
char __thiscall Attribute2ndInfoRegion::GetTooltip(Attribute2ndInfoRegion *this, PStringBase<unsigned short> *i_name)
{
  return SkillSystem::InqAttribute2ndDescription(this->m_CurAttribute, i_name);
}

//----- (004F0F80) --------------------------------------------------------  // acclient.c:285185
char __thiscall SkillInfoRegion::GetLabel(SkillInfoRegion *this, PStringBase<unsigned short> *i_name)
{
  return SkillSystem::InqSkillName(this->m_Skill, i_name);
}

//----- (004F0FA0) --------------------------------------------------------  // acclient.c:285191
int __thiscall SkillInfoRegion::GetVitaeModifier(SkillInfoRegion *this, CACQualities *i_playerDesc)
{
  SkillInfoRegion *v2; // esi@1
  unsigned int v3; // ST00_4@3
  int result; // eax@3
  int iStatVal; // [sp+8h] [bp-58h]@3
  float tmp; // [sp+Ch] [bp-54h]@3
  Enchantment vitae; // [sp+10h] [bp-50h]@1

  v2 = this;
  Enchantment::Enchantment(&vitae);
  if ( CACQualities::InqVitae(i_playerDesc, &vitae) && vitae._smod.val < 1.0 )
  {
    v3 = v2->m_Skill;
    iStatVal = 0;
    CACQualities::InqSkill(i_playerDesc, v3, &iStatVal, 1);
    tmp = (double)iStatVal;
    Enchantment::Enchant(&vitae, &tmp);
    result = (unsigned __int64)(tmp + 0.5) - iStatVal;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004F1060) --------------------------------------------------------  // acclient.c:285233
InfoRegion *__thiscall InfoRegion::vector_deleting_destructor(InfoRegion *this, unsigned int a2)
{
  InfoRegion *v2; // esi@1

  v2 = this;
  this->vfptr = (QualityChangeHandlerVtbl *)InfoRegion::vftable;
  (*(void (__stdcall **)(InfoRegion *))&QualityRegistrar::s_pQR->vfptr->gap14[0])(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C3FF0: using guessed type void (__thiscall *InfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (004F1090) --------------------------------------------------------  // acclient.c:285247
void __thiscall InfoRegion::SetID(InfoRegion *this, int i_id)
{
  InfoRegion *v2; // esi@1
  BasePropertyDesc *v3; // ecx@4
  unsigned int v4; // edx@4
  BasePropertyValue *v5; // ecx@8
  unsigned int v6; // edx@8
  BaseProperty statProperty; // [sp+Ch] [bp-8h]@1

  v2 = this;
  statProperty.m_pcPropertyDesc = 0;
  statProperty.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&statProperty, 0x1000003Au);
  if ( statProperty.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&statProperty);
    ((void (__stdcall *)(_DWORD))statProperty.m_pcPropertyValue->vfptr[31].__vecDelDtor)(i_id);
  }
  ((void (__stdcall *)(BaseProperty *))v2->m_pElement->vfptr[17].OnLoseFocus)(&statProperty);
  if ( (_DWORD)statProperty.m_pcPropertyDesc )
  {
    v3 = statProperty.m_pcPropertyDesc;
    v4 = statProperty.m_pcPropertyDesc->m_cRef - 1;
    statProperty.m_pcPropertyDesc->m_cRef = v4;
    if ( !v4 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    statProperty.m_pcPropertyDesc = 0;
  }
  if ( statProperty.m_pcPropertyValue )
  {
    v5 = statProperty.m_pcPropertyValue;
    v6 = statProperty.m_pcPropertyValue->m_cRef - 1;
    statProperty.m_pcPropertyValue->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  }
}

//----- (004F1130) --------------------------------------------------------  // acclient.c:285286
int __thiscall Attribute2ndInfoRegion::GetVitaeModifier(Attribute2ndInfoRegion *this, CACQualities *i_playerDesc)
{
  Attribute2ndInfoRegion *v2; // esi@1
  unsigned int v3; // ST00_4@3
  int result; // eax@3
  unsigned int uStatVal; // [sp+8h] [bp-58h]@3
  float tmp; // [sp+Ch] [bp-54h]@3
  Enchantment vitae; // [sp+10h] [bp-50h]@1

  v2 = this;
  Enchantment::Enchantment(&vitae);
  if ( CACQualities::InqVitae(i_playerDesc, &vitae) && vitae._smod.val < 1.0 )
  {
    v3 = v2->m_MaxAttribute;
    uStatVal = 0;
    CACQualities::InqAttribute2nd(i_playerDesc, v3, &uStatVal, 1);
    tmp = (double)uStatVal;
    Enchantment::Enchant(&vitae, &tmp);
    result = (unsigned __int64)(tmp + 0.5) - uStatVal;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004F11D0) --------------------------------------------------------  // acclient.c:285314
int __thiscall Attribute2ndTable::InqAttribute2ndBase(Attribute2ndTable *this, unsigned int key, Attribute2ndBase *sbase)
{
  int result; // eax@4

  switch ( key )
  {
    case 1u:
      sbase->_formula._w = this->_max_health._formula._w;
      sbase->_formula._x = this->_max_health._formula._x;
      sbase->_formula._y = this->_max_health._formula._y;
      sbase->_formula._z = this->_max_health._formula._z;
      sbase->_formula._attr1 = this->_max_health._formula._attr1;
      sbase->_formula._attr2 = this->_max_health._formula._attr2;
      result = 1;
      break;
    case 3u:
      sbase->_formula._w = this->_max_stamina._formula._w;
      sbase->_formula._x = this->_max_stamina._formula._x;
      sbase->_formula._y = this->_max_stamina._formula._y;
      sbase->_formula._z = this->_max_stamina._formula._z;
      sbase->_formula._attr1 = this->_max_stamina._formula._attr1;
      sbase->_formula._attr2 = this->_max_stamina._formula._attr2;
      result = 1;
      break;
    case 5u:
      sbase->_formula._w = this->_max_mana._formula._w;
      sbase->_formula._x = this->_max_mana._formula._x;
      sbase->_formula._y = this->_max_mana._formula._y;
      sbase->_formula._z = this->_max_mana._formula._z;
      sbase->_formula._attr1 = this->_max_mana._formula._attr1;
      sbase->_formula._attr2 = this->_max_mana._formula._attr2;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (004F1290) --------------------------------------------------------  // acclient.c:285355
void __thiscall SkillBase::SkillBase(SkillBase *this)
{
  SkillBase *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  unsigned int v4; // ecx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&SkillBase::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_description.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = stru_840E64.id;
  v1->_trained_cost = 0;
  v1->_specialized_cost = 0;
  v1->_category = 0;
  v1->_chargen_use = 0;
  v1->_min_level = 0;
  v1->_iconID.id = v4;
  v1->_formula._w = 0;
  v1->_formula._x = 0;
  v1->_formula._y = 0;
  v1->_formula._attr1 = 0;
  v1->_formula._attr2 = 0;
  v1->_formula.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
  v1->_formula._z = 1;
  LODWORD(v1->_upper_bound) = 0;
  HIDWORD(v1->_upper_bound) = 0;
  LODWORD(v1->_lower_bound) = 0;
  HIDWORD(v1->_lower_bound) = 0;
  LODWORD(v1->_learn_mod) = 0;
  HIDWORD(v1->_learn_mod) = 0;
}
// 7A016C: using guessed type int (__thiscall *SkillFormula::vftable)(void *, char);
// 7C4020: using guessed type int (__thiscall *SkillBase::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004F1310) --------------------------------------------------------  // acclient.c:285396
void __thiscall SkillBase::~SkillBase(SkillBase *this)
{
  SkillBase *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4

  v1 = this;
  v2 = this->_name.m_buffer;
  this->_formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->_description.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004F1360) --------------------------------------------------------  // acclient.c:285415
int __thiscall SkillBase::operator=(int this, int a2)
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
  v5 = *(_DWORD *)(v2 + 8);
  if ( v5 != *(_DWORD *)(a2 + 8) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v6;
    InterlockedIncrement((volatile LONG *)(v6 + 4));
  }
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(v2 + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(v2 + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(v2 + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(v2 + 52) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(v2 + 56) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(v2 + 60) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(v2 + 64) = *(_DWORD *)(a2 + 64);
  *(_DWORD *)(v2 + 68) = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(v2 + 72) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(v2 + 76) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(v2 + 80) = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(v2 + 84) = *(_DWORD *)(a2 + 84);
  return v2;
}

//----- (004F1450) --------------------------------------------------------  // acclient.c:285464
void __thiscall InfoRegion::InfoRegion(InfoRegion *this, UIElement_ListBox *i_pParent, int i_insertIndex, int i_internalID, StatType i_statType, unsigned int i_stat, IDClass<_tagDataID,32,0> i_iconID)
{
  InfoRegion *v7; // esi@1
  UIElement *v8; // eax@3
  UIElement *v9; // eax@6
  int v10; // eax@7
  UIElement *v11; // ecx@9
  UIElement *v12; // eax@9
  int v13; // eax@10
  UIRegion *v14; // eax@13

  v7 = this;
  this->vfptr = (QualityChangeHandlerVtbl *)InfoRegion::vftable;
  this->m_StatType = i_statType;
  this->m_pElement = 0;
  this->m_pLabelText = 0;
  this->m_pValueText = 0;
  if ( i_pParent )
  {
    v8 = (UIElement *)(i_insertIndex == -1 ? UIElement_ListBox::AddItemFromTemplateList(i_pParent, 0, 0) : UIElement_ListBox::AddItemFromTemplateList(i_pParent, 0, i_insertIndex));
    v7->m_pElement = v8;
    if ( v8 )
    {
      v9 = UIElement::GetChildRecursive(v8, 0x1000012Au);
      if ( v9 )
        v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)12);
      else
        v10 = 0;
      v11 = v7->m_pElement;
      v7->m_pLabelText = (UIElement_Text *)v10;
      v12 = UIElement::GetChildRecursive(v11, 0x1000012Bu);
      if ( v12 )
        v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
      else
        v13 = 0;
      v7->m_pValueText = (UIElement_Text *)v13;
      if ( i_iconID.id != stru_840E64.id )
      {
        v14 = (UIRegion *)UIElement::GetChildRecursive(v7->m_pElement, 0x10000129u);
        if ( v14 )
          UIRegion::SetImageByDID(v14, i_iconID, 3u);
      }
      InfoRegion::SetID(v7, i_internalID);
    }
  }
}
// 7C3FF0: using guessed type void (__thiscall *InfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (004F1530) --------------------------------------------------------  // acclient.c:285513
void __thiscall AttributeInfoRegion::AttributeInfoRegion(AttributeInfoRegion *this, UIElement_ListBox *i_pParent, int i_internalID, unsigned int i_attrib, IDClass<_tagDataID,32,0> i_iconID, bool i_bRegisterForUpdates)
{
  AttributeInfoRegion *v6; // esi@1
  UIElement_Text *v7; // eax@1
  char *v8; // edi@4
  char *v9; // edi@10
  PStringBase<unsigned short> strTooltip; // [sp+10h] [bp-94h]@2
  StringInfo _text; // [sp+14h] [bp-90h]@9

  v6 = this;
  InfoRegion::InfoRegion(
    (InfoRegion *)&this->vfptr,
    i_pParent,
    -1,
    i_internalID,
    Attribute_StatType,
    i_attrib,
    i_iconID);
  v7 = v6->m_pLabelText;
  v6->vfptr = (QualityChangeHandlerVtbl *)AttributeInfoRegion::vftable;
  v6->m_Attribute = i_attrib;
  if ( v7 )
  {
    strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( SkillSystem::InqAttributeName(v6->m_Attribute, &strTooltip) )
      UIElement_Text::SetText(v6->m_pLabelText, &strTooltip);
    v8 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
  if ( v6->m_pElement )
  {
    strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( SkillSystem::InqAttributeDescription(v6->m_Attribute, &strTooltip) )
    {
      StringInfo::StringInfo(&_text);
      StringInfo::SetLiteralValue(&_text, &strTooltip, 1);
      UIElement::SetTooltip(v6->m_pElement, &_text);
      ((void (__stdcall *)(signed int))v6->m_pElement->vfptr[22].OnLoseFocus)(1);
      StringInfo::~StringInfo(&_text);
    }
    v9 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
  if ( i_bRegisterForUpdates )
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
      8,
      v6->m_Attribute,
      v6);
}
// 7C4034: using guessed type void (__thiscall *AttributeInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (004F1680) --------------------------------------------------------  // acclient.c:285569
void __thiscall Attribute2ndInfoRegion::Attribute2ndInfoRegion(Attribute2ndInfoRegion *this, UIElement_ListBox *i_pParent, int i_internalID, unsigned int i_attrib, bool i_bShowPercent, IDClass<_tagDataID,32,0> i_iconID, bool i_bRegisterForUpdates)
{
  Attribute2ndInfoRegion *v7; // esi@1
  UIElement_Text *v8; // eax@1
  char *v9; // edi@4
  char *v10; // edi@10
  int v11; // edi@14
  unsigned int v12; // ST10_4@15
  PStringBase<unsigned short> strTooltip; // [sp+20h] [bp-B4h]@2
  Attribute2ndBase sbase; // [sp+24h] [bp-B0h]@15
  StringInfo _text; // [sp+44h] [bp-90h]@9

  v7 = this;
  InfoRegion::InfoRegion(
    (InfoRegion *)&this->vfptr,
    i_pParent,
    -1,
    i_internalID,
    Attribute_2nd_StatType,
    i_attrib,
    i_iconID);
  v7->m_bShowPercent = i_bShowPercent;
  v8 = v7->m_pLabelText;
  v7->m_CurAttribute = i_attrib;
  v7->vfptr = (QualityChangeHandlerVtbl *)Attribute2ndInfoRegion::vftable;
  v7->m_MaxAttribute = i_attrib - 1;
  if ( v8 )
  {
    strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( SkillSystem::InqAttribute2ndName(v7->m_CurAttribute, &strTooltip) )
      UIElement_Text::SetText(v7->m_pLabelText, &strTooltip);
    v9 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
  if ( v7->m_pElement )
  {
    strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( SkillSystem::InqAttribute2ndDescription(v7->m_CurAttribute, &strTooltip) )
    {
      StringInfo::StringInfo(&_text);
      StringInfo::SetLiteralValue(&_text, &strTooltip, 1);
      UIElement::SetTooltip(v7->m_pElement, &_text);
      ((void (__stdcall *)(signed int))v7->m_pElement->vfptr[22].OnLoseFocus)(1);
      StringInfo::~StringInfo(&_text);
    }
    v10 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  }
  if ( i_bRegisterForUpdates )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
      9,
      v7->m_CurAttribute,
      v7);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
      9,
      v7->m_MaxAttribute,
      v7);
    v11 = DBObj::GetByEnum(1, 2, 0x10000003u);
    if ( v11 )
    {
      v12 = v7->m_MaxAttribute;
      sbase.vfptr = (PackObjVtbl *)&Attribute2ndBase::vftable;
      sbase._formula.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
      sbase._formula._w = 0;
      sbase._formula._x = 0;
      sbase._formula._y = 0;
      sbase._formula._z = 1;
      sbase._formula._attr1 = 0;
      sbase._formula._attr2 = 0;
      Attribute2ndTable::InqAttribute2ndBase((Attribute2ndTable *)v11, v12, &sbase);
      if ( sbase._formula._attr1 )
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
          9,
          sbase._formula._attr1,
          v7);
      if ( sbase._formula._attr2 )
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
          9,
          sbase._formula._attr2,
          v7);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
    }
  }
}
// 7A016C: using guessed type int (__thiscall *SkillFormula::vftable)(void *, char);
// 7C3FDC: using guessed type int (__thiscall *Attribute2ndBase::vftable)(void *, char);
// 7C4064: using guessed type void (__thiscall *Attribute2ndInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (004F1890) --------------------------------------------------------  // acclient.c:285669
SkillBase *__thiscall SkillBase::vector_deleting_destructor(SkillBase *this, unsigned int a2)
{
  SkillBase *v2; // esi@1

  v2 = this;
  SkillBase::~SkillBase(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004F18B0) --------------------------------------------------------  // acclient.c:285681
int __thiscall SkillTable::InqSkillBase(SkillTable *this, unsigned int key, SkillBase *sbase)
{
  unsigned int v3; // esi@1
  PackableHashData<unsigned long,SkillBase> **v4; // ecx@2
  PackableHashData<unsigned long,SkillBase> *v5; // edx@3
  int result; // eax@6

  v3 = this->_skillBaseHash._table_size;
  if ( !v3 )
    goto LABEL_12;
  v4 = this->_skillBaseHash._buckets;
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
  if ( v5 != (PackableHashData<unsigned long,SkillBase> *)-8 )
  {
    SkillBase::operator=((int)sbase, (int)&v5->_data);
    result = 1;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  return result;
}

//----- (004F1910) --------------------------------------------------------  // acclient.c:285717
char __thiscall AttributeInfoRegion::Update(AttributeInfoRegion *this, CACQualities *i_playerDesc)
{
  AttributeInfoRegion *v2; // esi@1
  CACQualities *v3; // edi@2
  unsigned int v4; // ST00_4@2
  unsigned int v5; // ST00_4@2
  int v6; // eax@2
  char *v7; // esi@6
  PStringBase<unsigned short> strValueText; // [sp+4h] [bp-8h]@2
  unsigned int uStatVal; // [sp+8h] [bp-4h]@2

  v2 = this;
  if ( this->m_pValueText )
  {
    v3 = i_playerDesc;
    v4 = this->m_Attribute;
    uStatVal = 0;
    CACQualities::InqAttribute(i_playerDesc, v4, &uStatVal, 1);
    v5 = v2->m_Attribute;
    i_playerDesc = 0;
    CACQualities::InqAttribute(v3, v5, (unsigned int *)&i_playerDesc, 0);
    strValueText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&strValueText, L"%d", i_playerDesc);
    v6 = 0;
    if ( uStatVal >= (unsigned int)i_playerDesc )
    {
      if ( uStatVal > (unsigned int)i_playerDesc )
        v6 = 2;
    }
    else
    {
      v6 = 1;
    }
    UIElement_Text::SetTextWithFont(v2->m_pValueText, &strValueText, 0, v6);
    v7 = (char *)&strValueText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strValueText.m_charbuffer[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
  return 1;
}

//----- (004F19E0) --------------------------------------------------------  // acclient.c:285760
char __thiscall Attribute2ndInfoRegion::Update(Attribute2ndInfoRegion *this, CACQualities *i_playerDesc)
{
  Attribute2ndInfoRegion *v2; // esi@1
  CACQualities *v3; // edi@2
  unsigned int v4; // ST04_4@2
  unsigned int v5; // ST04_4@2
  unsigned int v6; // ST04_4@2
  int v7; // ebx@2
  int v8; // eax@2
  unsigned int v9; // ecx@2
  char *v10; // esi@6
  PStringBase<unsigned short> strValueText; // [sp+4h] [bp-Ch]@2
  unsigned int uStatValCurrent; // [sp+8h] [bp-8h]@2
  unsigned int uStatVal; // [sp+Ch] [bp-4h]@2

  v2 = this;
  if ( this->m_pValueText )
  {
    v3 = i_playerDesc;
    v4 = this->m_MaxAttribute;
    uStatVal = 0;
    CACQualities::InqAttribute2nd(i_playerDesc, v4, &uStatVal, 1);
    v5 = v2->m_MaxAttribute;
    i_playerDesc = 0;
    CACQualities::InqAttribute2nd(v3, v5, (unsigned int *)&i_playerDesc, 0);
    v6 = v2->m_CurAttribute;
    uStatValCurrent = 0;
    CACQualities::InqAttribute2nd(v3, v6, &uStatValCurrent, 0);
    strValueText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&strValueText, L"%d/%d", uStatValCurrent, i_playerDesc);
    v7 = 0;
    v8 = ((int (__thiscall *)(Attribute2ndInfoRegion *, CACQualities *))v2->vfptr[5].OnQualityChanged)(v2, v3);
    v9 = (unsigned int)((char *)i_playerDesc - v8);
    i_playerDesc = (CACQualities *)v9;
    if ( uStatVal >= v9 )
    {
      if ( uStatVal > v9 )
        v7 = 2;
    }
    else
    {
      v7 = 1;
    }
    UIElement_Text::SetTextWithFont(v2->m_pValueText, &strValueText, 0, v7);
    v10 = (char *)&strValueText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strValueText.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  }
  return 1;
}

//----- (004F1AE0) --------------------------------------------------------  // acclient.c:285813
char __thiscall SkillInfoRegion::Update(SkillInfoRegion *this, CACQualities *i_playerDesc)
{
  CACQualities *v2; // edi@1
  SkillInfoRegion *v3; // esi@1
  unsigned int v4; // ecx@1
  SKILL_ADVANCEMENT_CLASS v5; // eax@1
  char result; // al@3
  unsigned int v7; // eax@5
  unsigned int v8; // ST00_4@5
  unsigned int v9; // ST00_4@5
  int v10; // ebx@5
  int v11; // eax@5
  char *v12; // esi@9
  PStringBase<unsigned short> strValueText; // [sp+Ch] [bp-10h]@9
  SKILL_ADVANCEMENT_CLASS newAdvancementClass; // [sp+10h] [bp-Ch]@1
  int iStatVal; // [sp+14h] [bp-8h]@5
  int baseLevel; // [sp+18h] [bp-4h]@5

  v2 = i_playerDesc;
  v3 = this;
  v4 = this->m_Skill;
  newAdvancementClass = 0;
  CACQualities::InqSkillAdvancementClass(i_playerDesc, v4, &newAdvancementClass);
  v5 = newAdvancementClass;
  if ( v3->m_AdvancementClass != newAdvancementClass && (v3->m_AdvancementClass = newAdvancementClass, v5) )
  {
    CM_Train::SendNotice_SkillAdvancementClassChanged();
    result = 1;
  }
  else
  {
    if ( v3->m_pValueText )
    {
      v7 = v3->m_Skill;
      baseLevel = 0;
      CACQualities::InqSkillBaseLevel(v2, v7, &baseLevel, 0);
      v8 = v3->m_Skill;
      iStatVal = 0;
      CACQualities::InqSkill(v2, v8, &iStatVal, 1);
      v9 = v3->m_Skill;
      i_playerDesc = 0;
      CACQualities::InqSkill(v2, v9, (int *)&i_playerDesc, 0);
      v10 = 0;
      v11 = ((int (__thiscall *)(SkillInfoRegion *, CACQualities *))v3->vfptr[5].OnQualityChanged)(v3, v2);
      if ( iStatVal >= (signed int)((char *)i_playerDesc - v11) )
      {
        if ( iStatVal > (signed int)((char *)i_playerDesc - v11) )
          v10 = 2;
      }
      else
      {
        v10 = 1;
      }
      strValueText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      PStringBase<unsigned short>::sprintf(&strValueText, L"%d", i_playerDesc);
      UIElement_Text::SetTextWithFont(v3->m_pValueText, &strValueText, 0, v10);
      v12 = (char *)&strValueText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strValueText.m_charbuffer[-1].m_data[8]) )
      {
        if ( v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
      }
    }
    result = 1;
  }
  return result;
}

//----- (004F1C00) --------------------------------------------------------  // acclient.c:285883
char __thiscall EffectInfoRegion::Update(EffectInfoRegion *this, long double duration)
{
  EffectInfoRegion *v2; // esi@1
  CPlayerSystem *v3; // eax@1
  char result; // al@2
  unsigned int v5; // ecx@6
  unsigned int v6; // ett@6
  char *v7; // esi@9
  unsigned int v8; // [sp-Ch] [bp-10h]@6
  unsigned int v9; // [sp-8h] [bp-Ch]@6
  PStringBase<unsigned short> durationString; // [sp+0h] [bp-4h]@1

  durationString.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  v3 = CPlayerSystem::GetPlayerSystem();
  if ( v3 )
  {
    if ( (unsigned __int8)PlayerModule::SpellDuration((PlayerModule *)&v3->playerModule.vfptr) && v2->m_pValueText )
    {
      durationString.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      if ( duration >= 0.0 )
      {
        v5 = (unsigned int)(unsigned __int64)duration / 0xE10;
        v6 = (unsigned int)(unsigned __int64)duration % 0xE10;
        v9 = v6 % 0x3C;
        v8 = v6 / 0x3C;
        if ( v5 )
          PStringBase<unsigned short>::sprintf(&durationString, L"%d:%02d:%02d", v5, v8, v9);
        else
          PStringBase<unsigned short>::sprintf(&durationString, L"%d:%02d", v8, v9);
      }
      UIElement_Text::SetText(v2->m_pValueText, &durationString);
      v7 = (char *)&durationString.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&durationString.m_charbuffer[-1].m_data[8]) )
      {
        if ( v7 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      }
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004F1CE0) --------------------------------------------------------  // acclient.c:285933
char __thiscall InfoRegion::Update(InfoRegion *this)
{
  InfoRegion *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // ebp@3
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
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_25, &_rpInterface);
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
  v7 = ((int (__thiscall *)(InfoRegion *, PlayerDesc *))v1->vfptr[4].OnQualityChanged)(v1, playerDesc.m_pInterface);
  v5->vfptr->Release((Interface *)v5);
  return v7;
}

//----- (004F1D90) --------------------------------------------------------  // acclient.c:285974
char __thiscall AttributeInfoRegion::Update(AttributeInfoRegion *this, AppraisalProfile *i_prof)
{
  AttributeInfoRegion *v2; // edi@1
  int v3; // ebx@1
  AppraisalProfile *v4; // ebp@2
  CreatureAppraisalProfile *v5; // esi@2
  unsigned int v6; // ST04_4@3
  char *v7; // esi@10
  unsigned int uStatVal; // [sp+8h] [bp-8h]@3
  int raised; // [sp+Ch] [bp-4h]@7

  v2 = this;
  v3 = 0;
  if ( this->m_pValueText )
  {
    v4 = i_prof;
    v5 = (CreatureAppraisalProfile *)HookAppraisalProfile::GetValidLocations((ChatDisplayInfo *)i_prof);
    if ( v5 )
    {
      v6 = v2->m_Attribute;
      uStatVal = 0;
      CreatureAppraisalProfile::InqAttribute(v5, v6, &uStatVal);
      i_prof = (AppraisalProfile *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      if ( uStatVal )
        PStringBase<unsigned short>::sprintf((PStringBase<unsigned short> *)&i_prof, L"%d", uStatVal);
      else
        PStringBase<unsigned short>::set((PStringBase<unsigned short> *)&i_prof, L"???");
      if ( v4->success_flag )
      {
        if ( CreatureAppraisalProfile::InqAttributeEnchantmentMod(v5, v2->m_Attribute, &raised) )
          v3 = (raised == 0) + 1;
      }
      else
      {
        v3 = 3;
      }
      UIElement_Text::SetTextWithFont(v2->m_pValueText, (PStringBase<unsigned short> *)&i_prof, 0, v3);
      v7 = (char *)&i_prof[-1].base_armor_wrist;
      if ( !InterlockedDecrement(&i_prof[-1].base_armor_hand) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
  }
  return 1;
}

//----- (004F1E80) --------------------------------------------------------  // acclient.c:286021
char __thiscall Attribute2ndInfoRegion::Update(Attribute2ndInfoRegion *this, AppraisalProfile *i_prof)
{
  Attribute2ndInfoRegion *v2; // esi@1
  AppraisalProfile *v3; // ebp@2
  CreatureAppraisalProfile *v4; // ebx@2
  int v5; // eax@5
  bool v6; // cl@5
  int v7; // edi@12
  char *v8; // esi@16
  unsigned int uMaximum; // [sp+4h] [bp-Ch]@4
  unsigned int uCurrent; // [sp+8h] [bp-8h]@3
  int raised; // [sp+Ch] [bp-4h]@13

  v2 = this;
  if ( !this->m_pValueText )
    return 1;
  v3 = i_prof;
  v4 = (CreatureAppraisalProfile *)HookAppraisalProfile::GetValidLocations((ChatDisplayInfo *)i_prof);
  if ( !v4 )
    return 1;
  i_prof = (AppraisalProfile *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !CreatureAppraisalProfile::InqAttribute2nd(v4, v2->m_CurAttribute, &uCurrent)
    || !CreatureAppraisalProfile::InqAttribute2nd(v4, v2->m_MaxAttribute, &uMaximum) )
    goto LABEL_22;
  v5 = MulDiv(100, uCurrent, uMaximum);
  v6 = v2->m_bShowPercent;
  if ( v3->success_flag )
  {
    if ( v6 )
      PStringBase<unsigned short>::sprintf(
        (PStringBase<unsigned short> *)&i_prof,
        L"%d/%d (%d %%)",
        uCurrent,
        uMaximum,
        v5);
    else
      PStringBase<unsigned short>::sprintf((PStringBase<unsigned short> *)&i_prof, L"%d/%d", uCurrent, uMaximum);
    goto LABEL_12;
  }
  if ( v6 )
    PStringBase<unsigned short>::sprintf((PStringBase<unsigned short> *)&i_prof, L"%d %%", v5);
  else
LABEL_22:
    PStringBase<unsigned short>::set((PStringBase<unsigned short> *)&i_prof, L"???");
LABEL_12:
  v7 = 0;
  if ( v3->success_flag )
  {
    if ( CreatureAppraisalProfile::InqAttribute2ndEnchantmentMod(v4, v2->m_MaxAttribute, &raised) )
      v7 = (raised == 0) + 1;
  }
  else
  {
    v7 = 3;
  }
  UIElement_Text::SetTextWithFont(v2->m_pValueText, (PStringBase<unsigned short> *)&i_prof, 0, v7);
  v8 = (char *)&i_prof[-1].base_armor_wrist;
  if ( !InterlockedDecrement(&i_prof[-1].base_armor_hand) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  return 1;
}

//----- (004F1FE0) --------------------------------------------------------  // acclient.c:286085
char __thiscall SkillInfoRegion::GetTooltip(SkillInfoRegion *this, PStringBase<unsigned short> *i_name)
{
  SkillInfoRegion *v2; // ebx@1
  PSRefBufferCharData<unsigned short> **v3; // edi@2
  PSRefBufferCharData<unsigned short> *v4; // eax@2
  int v5; // esi@3
  PSRefBufferCharData<unsigned short> *v6; // eax@6
  LONG (__stdcall *v7)(volatile LONG *); // edi@7
  char *v8; // esi@7
  char *v9; // esi@10
  PSRefBufferCharData<unsigned short> *v10; // ecx@14
  int v11; // eax@14
  int v12; // esi@16
  char *v13; // esi@19
  PStringBase<unsigned short> desc; // [sp+10h] [bp-10h]@14
  PStringBase<unsigned short> formula; // [sp+14h] [bp-Ch]@1
  PStringBase<unsigned short> rhs; // [sp+18h] [bp-8h]@2
  PStringBase<unsigned short> result; // [sp+1Ch] [bp-4h]@2

  formula.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( SkillSystem::InqSkillFormula(v2->m_Skill, &formula) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&rhs, L"\n");
    v3 = (PSRefBufferCharData<unsigned short> **)PStringBase<unsigned short>::operator+(&formula, &result, &rhs);
    v4 = i_name->m_charbuffer;
    if ( i_name->m_charbuffer != *v3 )
    {
      v5 = (int)&v4[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v4[-1].m_data[8]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6 = *v3;
      i_name->m_charbuffer = *v3;
      InterlockedIncrement((volatile LONG *)&v6[-1].m_data[8]);
    }
    v7 = InterlockedDecrement;
    v8 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    v9 = (char *)&rhs.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  }
  else
  {
    v7 = InterlockedDecrement;
  }
  desc.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  SkillSystem::InqSkillDescription(v2->m_Skill, &desc);
  v10 = desc.m_charbuffer;
  v11 = *(_DWORD *)&desc.m_charbuffer[-1].m_data[14];
  if ( v11 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(i_name, desc.m_charbuffer->m_data, v11 - 1);
    v10 = desc.m_charbuffer;
  }
  v12 = (int)&v10[-1].m_data[6];
  if ( !v7((volatile LONG *)&v10[-1].m_data[8]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  v13 = (char *)&formula.m_charbuffer[-1].m_data[6];
  if ( !v7((volatile LONG *)&formula.m_charbuffer[-1].m_data[8]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  return 1;
}

//----- (004F2140) --------------------------------------------------------  // acclient.c:286153
void __thiscall SkillInfoRegion::SkillInfoRegion(SkillInfoRegion *this, UIElement_ListBox *i_pParent, int i_insertIndex, int i_internalID, unsigned int i_skill, IDClass<_tagDataID,32,0> i_iconID, bool i_bRegisterForUpdates)
{
  SkillInfoRegion *v7; // esi@1
  UIElement_Text *v8; // eax@1
  char *v9; // edi@4
  char *v10; // edi@10
  int v11; // edi@14
  InterfaceSystem *v12; // eax@20
  PSRefBufferCharData<unsigned short> *v13; // edi@20
  int v14; // ebp@22
  PlayerDesc *v15; // edi@24
  int v16; // [sp+18h] [bp-BCh]@20
  PStringBase<unsigned short> strTooltip; // [sp+30h] [bp-A4h]@2
  InterfacePtr<PlayerDesc> playerDesc; // [sp+34h] [bp-A0h]@20
  char v19; // [sp+3Ch] [bp-98h]@22
  TResult result; // [sp+40h] [bp-94h]@20
  SkillBase sbase; // [sp+44h] [bp-90h]@9

  v7 = this;
  InfoRegion::InfoRegion(
    (InfoRegion *)&this->vfptr,
    i_pParent,
    i_insertIndex,
    i_internalID,
    Skill_StatType,
    i_skill,
    i_iconID);
  v8 = v7->m_pLabelText;
  v7->vfptr = (QualityChangeHandlerVtbl *)SkillInfoRegion::vftable;
  v7->m_Skill = i_skill;
  v7->m_AdvancementClass = 0;
  if ( v8 )
  {
    strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( SkillSystem::InqSkillName(v7->m_Skill, &strTooltip) )
      UIElement_Text::SetText(v7->m_pLabelText, &strTooltip);
    v9 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  }
  if ( v7->m_pElement )
  {
    strTooltip.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( SkillInfoRegion::GetTooltip(v7, &strTooltip) )
    {
      StringInfo::StringInfo((StringInfo *)&sbase);
      StringInfo::SetLiteralValue((StringInfo *)&sbase, &strTooltip, 1);
      UIElement::SetTooltip(v7->m_pElement, (StringInfo *)&sbase);
      ((void (__stdcall *)(signed int))v7->m_pElement->vfptr[22].OnLoseFocus)(1);
      StringInfo::~StringInfo((StringInfo *)&sbase);
    }
    v10 = (char *)&strTooltip.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strTooltip.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  }
  if ( i_bRegisterForUpdates )
  {
    ((void (__stdcall *)(signed int, unsigned int, SkillInfoRegion *))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
      4,
      v7->m_Skill,
      v7);
    v11 = DBObj::GetByEnum(4, 2, 0x10000004u);
    if ( v11 )
    {
      SkillBase::SkillBase(&sbase);
      SkillTable::InqSkillBase((SkillTable *)v11, v7->m_Skill, &sbase);
      if ( sbase._formula._attr1 )
        ((void (__stdcall *)(signed int, unsigned int, SkillInfoRegion *))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
          4,
          sbase._formula._attr1,
          v7);
      if ( sbase._formula._attr2 )
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
          4,
          sbase._formula._attr2,
          v7);
      SkillBase::~SkillBase(&sbase);
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
    }
  }
  strTooltip.m_charbuffer = 0;
  v12 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v12, &result, &PlayerDesc_ClassType_25, (Interface **)&strTooltip);
  v13 = strTooltip.m_charbuffer;
  v16 = (int)strTooltip.m_charbuffer;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( strTooltip.m_charbuffer )
    (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&strTooltip.m_charbuffer->m_data[0] + 16))(strTooltip.m_charbuffer);
  v14 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v19, v16, 0);
  if ( v13 )
    (*(void (__thiscall **)(PSRefBufferCharData<unsigned short> *))(*(_DWORD *)&v13->m_data[0] + 20))(v13);
  v15 = playerDesc.m_pInterface;
  if ( (_DWORD)playerDesc.m_pInterface )
  {
    if ( v14 >= 0 )
      CACQualities::InqSkillAdvancementClass(
        (CACQualities *)&playerDesc.m_pInterface->vfptr,
        v7->m_Skill,
        &v7->m_AdvancementClass);
    v15->vfptr->Release((Interface *)v15);
  }
}
// 7C40F4: using guessed type void (__thiscall *SkillInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (004F2390) --------------------------------------------------------  // acclient.c:286261
double __thiscall EffectInfoRegion::GetDuration(EffectInfoRegion *this, CACQualities *i_playerDesc)
{
  EffectInfoRegion *v2; // esi@1
  PackableLLNode<Enchantment> *i; // eax@2
  long double v4; // ST0C_8@6
  PackableList<Enchantment> affectors; // [sp+10h] [bp-60h]@1
  Enchantment enchantment; // [sp+20h] [bp-50h]@6

  v2 = this;
  affectors.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  affectors.head = 0;
  affectors.tail = 0;
  affectors.curNum = 0;
  if ( CACQualities::GetEnchantmentsInEffect(i_playerDesc, &affectors) )
  {
    for ( i = affectors.head; i; i = i->next )
    {
      if ( v2->m_Spell == (i->data._id & 0xFFFF) )
      {
        Enchantment::Enchantment(&enchantment, &i->data);
        affectors.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
        v4 = enchantment._start_time + enchantment._duration - COERCE_DOUBLE(Timer::cur_time.Cmd);
        PackableList<Enchantment>::Flush(&affectors);
        return v4;
      }
    }
  }
  affectors.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  PackableList<Enchantment>::Flush(&affectors);
  return 0.0;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (004F2440) --------------------------------------------------------  // acclient.c:286295
char __thiscall EffectInfoRegion::GetLabel(EffectInfoRegion *this, PStringBase<unsigned short> *i_name)
{
  EffectInfoRegion *v2; // esi@1
  ClientMagicSystem *v3; // eax@1
  char v4; // al@2
  AC1Legacy::PStringBase<char> *v5; // eax@3
  AC1Legacy::PSRefBuffer<char> *v6; // esi@3
  PSRefBufferCharData<unsigned short> *v7; // eax@6
  int v8; // esi@7
  PSRefBufferCharData<unsigned short> *v9; // eax@10
  char *v10; // esi@11
  PStringBase<unsigned short> strName; // [sp+8h] [bp-8h]@3
  AC1Legacy::PStringBase<char> result; // [sp+Ch] [bp-4h]@3

  v2 = this;
  v3 = ClientMagicSystem::GetMagicSystem();
  if ( v3 )
  {
    v5 = ClientMagicSystem::GetSpellName(v3, &result, v2->m_Spell);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&strName, 0, v5->m_buffer->m_data);
    v6 = result.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    v7 = i_name->m_charbuffer;
    if ( i_name->m_charbuffer != strName.m_charbuffer )
    {
      v8 = (int)&v7[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v7[-1].m_data[8]) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      v9 = strName.m_charbuffer;
      i_name->m_charbuffer = strName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v9[-1].m_data[8]);
    }
    v10 = (char *)&strName.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1].m_data[8]) )
    {
      if ( v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    }
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  return v4;
}

//----- (004F2500) --------------------------------------------------------  // acclient.c:286344
char __thiscall EffectInfoRegion::Update(EffectInfoRegion *this, CACQualities *i_playerDesc)
{
  EffectInfoRegion *v2; // esi@1
  CPlayerSystem *v3; // eax@1
  char result; // al@2
  double v5; // st7@5

  v2 = this;
  v3 = CPlayerSystem::GetPlayerSystem();
  if ( v3 )
  {
    if ( (unsigned __int8)PlayerModule::SpellDuration((PlayerModule *)&v3->playerModule.vfptr) )
    {
      v5 = EffectInfoRegion::GetDuration(v2, i_playerDesc);
      result = ((int (__thiscall *)(EffectInfoRegion *, _DWORD, _DWORD))v2->vfptr[6].OnQualityChanged)(
                 v2,
                 LODWORD(v5),
                 *(unsigned __int64 *)&v5 >> 32);
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004F2560) --------------------------------------------------------  // acclient.c:286376
void __thiscall EffectInfoRegion::EffectInfoRegion(EffectInfoRegion *this, UIElement_ListBox *i_pParent, int i_internalID, unsigned int i_spell, bool i_bRegisterForUpdates)
{
  unsigned int v5; // ebx@1
  EffectInfoRegion *v6; // esi@1
  UIElement_Text *v7; // eax@1
  unsigned int v8; // edi@4
  UIRegion *v9; // edi@7
  ClientMagicSystem *v10; // eax@8
  Graphic *v11; // ebx@8
  Graphic *v12; // eax@9
  Graphic *v13; // eax@10

  v5 = i_spell;
  v6 = this;
  InfoRegion::InfoRegion((InfoRegion *)&this->vfptr, i_pParent, i_internalID, i_internalID, 0, i_spell, stru_840E64);
  v7 = v6->m_pLabelText;
  v6->vfptr = (QualityChangeHandlerVtbl *)EffectInfoRegion::vftable;
  v6->m_Spell = v5;
  if ( v7 )
  {
    i_spell = (unsigned int)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( EffectInfoRegion::GetLabel(v6, (PStringBase<unsigned short> *)&i_spell) )
      UIElement_Text::SetText(v6->m_pLabelText, (PStringBase<unsigned short> *)&i_spell);
    v8 = i_spell - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_spell - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
  v9 = (UIRegion *)UIElement::GetChildRecursive(v6->m_pElement, 0x10000129u);
  if ( v9 )
  {
    v10 = ClientMagicSystem::GetMagicSystem();
    v11 = ClientMagicSystem::GetSpellIcon(v10, v5);
    if ( v11 )
    {
      UIRegion::SetBlitMode(v9, Blit_3Alpha);
      v12 = (Graphic *)operator new(0xCu);
      if ( v12 )
      {
        Graphic::Graphic(v12, v11);
        UIRegion::SetImage(v9, v13);
      }
      else
      {
        UIRegion::SetImage(v9, 0);
      }
    }
  }
}
// 7C4124: using guessed type void (__thiscall *EffectInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);

//----- (004F2660) --------------------------------------------------------  // acclient.c:286434
EffectInfoRegion *__thiscall Attribute2ndInfoRegion::scalar_deleting_destructor(EffectInfoRegion *this, unsigned int a2)
{
  EffectInfoRegion *v2; // esi@1

  v2 = this;
  InfoRegion::~InfoRegion((InfoRegion *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006F7D50) --------------------------------------------------------  // acclient.c:780687
void sub_6F7D50()
{
  flt_840E68 = 1000.0 + 1.0;
}

//----- (006F7D70) --------------------------------------------------------  // acclient.c:780693
void sub_6F7D70()
{
  flt_840E6C = 24.0 * 8.0;
}

//----- (006F7D90) --------------------------------------------------------  // acclient.c:780699
void sub_6F7D90()
{
  flt_840E70 = 24.0 * 0.5;
}

//----- (006F7DB0) --------------------------------------------------------  // acclient.c:780705
int sub_6F7DB0()
{
  return atexit(nullsub_1025);
}

//----- (006F7DC0) --------------------------------------------------------  // acclient.c:780711
int sub_6F7DC0()
{
  return atexit(nullsub_1026);
}

//----- (006F7DD0) --------------------------------------------------------  // acclient.c:780717
int sub_6F7DD0()
{
  return atexit(nullsub_1027);
}

//----- (006F7DE0) --------------------------------------------------------  // acclient.c:780723
void _E106_81()
{
  DEFAULT_VIEW_RADIUS_84 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F7E00) --------------------------------------------------------  // acclient.c:780729
void _E108_63()
{
  MIN_QUANTUM_84 = 1.0 / 30.0;
}

//----- (006F7E20) --------------------------------------------------------  // acclient.c:780735
void _E110_53()
{
  MAX_QUANTUM_84 = 1.0 / 5.0;
}

//----- (006F7E40) --------------------------------------------------------  // acclient.c:780741
void _E112_73()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840E88, PFID_A8R8G8B8);
}

//----- (006F7E50) --------------------------------------------------------  // acclient.c:780747
int _E115_54()
{
  return atexit(_E116_47);
}

//----- (006F7E60) --------------------------------------------------------  // acclient.c:780753
int sub_6F7E60()
{
  return atexit(nullsub_1029);
}

