/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCGSkillsPage
   Object     : GAME\game_ui_misc\gmCGSkillsPage.obj
   Functions  : 47
   Addresses  : 00480360 - 006ECFD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00480360) --------------------------------------------------------  // acclient.c:188487
void __thiscall SkillFormula::SkillFormula(SkillFormula *this, SkillFormula *__that)
{
  this->vfptr = (PackObjVtbl *)&SkillFormula::vftable;
  this->_w = __that->_w;
  this->_x = __that->_x;
  this->_y = __that->_y;
  this->_z = __that->_z;
  this->_attr1 = __that->_attr1;
  this->_attr2 = __that->_attr2;
}
// 7A016C: using guessed type int (__thiscall *SkillFormula::vftable)(void *, char);

//----- (004803A0) --------------------------------------------------------  // acclient.c:188500
void __thiscall AC1Legacy::PStringBase<char>::PStringBase<char>(AC1Legacy::PStringBase<char> *this, AC1Legacy::PStringBase<char> *rhs)
{
  AC1Legacy::PSRefBuffer<char> *v2; // eax@1

  v2 = rhs->m_buffer;
  this->m_buffer = rhs->m_buffer;
  InterlockedIncrement((volatile LONG *)&v2->m_cRef);
}

//----- (004803C0) --------------------------------------------------------  // acclient.c:188510
unsigned int __thiscall UIElement_ListBox::WhatNum(UIElement_ListBox *this, UIElement *_item)
{
  unsigned int v2; // edx@1
  unsigned int result; // eax@1
  UIElement **v4; // ecx@2

  v2 = this->m_listItems.m_num;
  result = 0;
  if ( v2 )
  {
    v4 = this->m_listItems.m_data;
    while ( *v4 != _item )
    {
      ++result;
      ++v4;
      if ( result >= v2 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    result = -1;
  }
  return result;
}

//----- (004803F0) --------------------------------------------------------  // acclient.c:188538
void __thiscall gmCGSkillsPage::tagSkillRecord::tagSkillRecord(gmCGSkillsPage::tagSkillRecord *this)
{
  gmCGSkillsPage::tagSkillRecord *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->strName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->strDesc.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->strFormula.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  v1->formSkill._w = 0;
  v1->formSkill._x = 0;
  v1->formSkill._y = 0;
  v1->formSkill._attr1 = 0;
  v1->formSkill._attr2 = 0;
  v1->formSkill.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
  v1->formSkill._z = 1;
}
// 7A016C: using guessed type int (__thiscall *SkillFormula::vftable)(void *, char);

//----- (00480450) --------------------------------------------------------  // acclient.c:188566
void __thiscall gmCGSkillsPage::tagSkillRecord::~tagSkillRecord(gmCGSkillsPage::tagSkillRecord *this)
{
  gmCGSkillsPage::tagSkillRecord *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4
  int v4; // esi@7

  v1 = this;
  v2 = (char *)&this->strFormula.m_charbuffer[-1].m_data[6];
  this->formSkill.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->strDesc.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->strName.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004804C0) --------------------------------------------------------  // acclient.c:188591
void __thiscall gmCGSkillsPage::tagSkillRecord::tagSkillRecord(gmCGSkillsPage::tagSkillRecord *this, gmCGSkillsPage::tagSkillRecord *__that)
{
  gmCGSkillsPage::tagSkillRecord *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  PSRefBufferCharData<unsigned short> *v4; // eax@1
  PSRefBufferCharData<unsigned short> *v5; // eax@1

  v2 = this;
  this->pEntry = __that->pEntry;
  this->pUpCostText = __that->pUpCostText;
  this->pDownCostText = __that->pDownCostText;
  this->pSkillLevelText = __that->pSkillLevelText;
  this->pSkillUpButton = __that->pSkillUpButton;
  this->pSkillDownButton = __that->pSkillDownButton;
  v3 = __that->strName.m_charbuffer;
  this->strName.m_charbuffer = v3;
  InterlockedIncrement((volatile LONG *)&v3[-1].m_data[8]);
  v4 = __that->strDesc.m_charbuffer;
  v2->strDesc.m_charbuffer = v4;
  InterlockedIncrement((volatile LONG *)&v4[-1].m_data[8]);
  v5 = __that->strFormula.m_charbuffer;
  v2->strFormula.m_charbuffer = v5;
  InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
  v2->iSkillID = __that->iSkillID;
  v2->iSkillLevel = __that->iSkillLevel;
  v2->iTrainCost = __that->iTrainCost;
  v2->iSpecCost = __that->iSpecCost;
  v2->iMinlevel = __that->iMinlevel;
  v2->bUntrainable = __that->bUntrainable;
  v2->bUnspecializable = __that->bUnspecializable;
  v2->saCurClass = __that->saCurClass;
  v2->formSkill.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
  v2->formSkill._w = __that->formSkill._w;
  v2->formSkill._x = __that->formSkill._x;
  v2->formSkill._y = __that->formSkill._y;
  v2->formSkill._z = __that->formSkill._z;
  v2->formSkill._attr1 = __that->formSkill._attr1;
  v2->formSkill._attr2 = __that->formSkill._attr2;
}
// 7A016C: using guessed type int (__thiscall *SkillFormula::vftable)(void *, char);

//----- (00480580) --------------------------------------------------------  // acclient.c:188633
IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0> *__thiscall IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0> *v2; // esi@1
  HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>Vtbl *)&IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable;
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
// 7A0180: using guessed type int (__thiscall *IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable)(void *, char);

//----- (004805C0) --------------------------------------------------------  // acclient.c:188654
void PStringBase<unsigned short>::PStringBase<unsigned short>(PStringBase<unsigned short> *this, _Formatted __formal, const unsigned __int16 *fmt, ...)
{
  int v3; // esi@1
  va_list va; // [sp+18h] [bp+10h]@1

  va_start(va, fmt);
  v3 = __vscwprintf(fmt, va);
  PStringBase<unsigned short>::allocate_ref_buffer(this, v3);
  __vsnwprintf(this->m_charbuffer->m_data, v3 + 1, fmt, va);
}

//----- (00480600) --------------------------------------------------------  // acclient.c:188666
void __thiscall gmCGSkillsPage::SetSkillText(gmCGSkillsPage *this, gmCGSkillsPage::tagSkillRecord *tRec)
{
  gmCGSkillsPage::tagSkillRecord *v2; // esi@1
  CharGenState *v3; // eax@1
  CharGenState *v4; // ebp@1
  unsigned int v5; // eax@1
  PStringBase<unsigned short> *v6; // eax@1
  char *v7; // ebx@1
  PStringBase<unsigned short> *v8; // eax@7
  char *v9; // ebx@7
  PStringBase<unsigned short> *v10; // eax@10
  char *v11; // ebx@10
  bool v12; // al@13
  void *v13; // ebx@15
  PStringBase<unsigned short> *v14; // eax@16
  int v15; // ebx@17
  PStringBase<unsigned short> *v16; // eax@20
  char *v17; // ebx@20
  int v18; // ecx@23
  int v19; // eax@23
  bool v20; // sf@23
  unsigned __int8 v21; // of@23
  UIElement_Button *v22; // ecx@23
  UIElement_Button *v23; // ecx@27
  PSRefBufferCharData<unsigned short> *v24; // ebx@30
  PStringBase<unsigned short> *v25; // eax@31
  int v26; // ebx@32
  PStringBase<unsigned short> *v27; // eax@35
  char *v28; // ebx@35
  int v29; // ecx@38
  int v30; // eax@38
  PStringBase<unsigned short> _text; // [sp+10h] [bp-1Ch]@30
  PStringBase<unsigned short> v32; // [sp+14h] [bp-18h]@7
  PStringBase<unsigned short> v33; // [sp+18h] [bp-14h]@10
  PStringBase<unsigned short> v34; // [sp+1Ch] [bp-10h]@16
  PStringBase<unsigned short> v35; // [sp+20h] [bp-Ch]@20
  PStringBase<unsigned short> v36; // [sp+24h] [bp-8h]@31
  PStringBase<unsigned short> v37; // [sp+28h] [bp-4h]@35

  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v2 = tRec;
  v4 = v3;
  v5 = CharGenState::GetSkillScore(v3, tRec->iSkillID);
  v2->iSkillLevel = v5;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&tRec, 0, L"%d", v5);
  UIElement_Text::SetText(v2->pSkillLevelText, v6);
  v7 = (char *)&tRec[-1].formSkill._x;
  if ( !InterlockedDecrement((volatile LONG *)&tRec[-1].formSkill._y) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  if ( v2->saCurClass == 1 )
  {
    if ( v2->iTrainCost < 999 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v36, 0, L"%d", v2->iTrainCost);
      UIElement_Text::SetText(v2->pUpCostText, v25);
      v24 = v36.m_charbuffer;
    }
    else
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&_text, &word_794320);
      UIElement_Text::SetText(v2->pUpCostText, &_text);
      v24 = _text.m_charbuffer;
    }
    v26 = (int)&v24[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v26 + 4)) && v26 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v37, 0, L"%d", 0);
    UIElement_Text::SetText(v2->pDownCostText, v27);
    v28 = (char *)&v37.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v37.m_charbuffer[-1].m_data[8]) && v28 )
      (**(void (__thiscall ***)(char *, signed int))v28)(v28, 1);
    ((void (__stdcall *)(signed int))v2->pSkillDownButton->vfptr[13].__vecDelDtor)(268435482);
    v29 = v2->iTrainCost;
    v30 = v4->remainingSkillCredits;
    v21 = __OFSUB__(v30, v29);
    v20 = v30 - v29 < 0;
    v23 = v2->pSkillUpButton;
    if ( !(v20 ^ v21) )
    {
LABEL_28:
      ((void (__stdcall *)(signed int))v23->vfptr[13].__vecDelDtor)(268435483);
      return;
    }
  }
  else
  {
    if ( v2->saCurClass == 2 )
    {
      if ( v2->iSpecCost - v2->iTrainCost < 999 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v34, 0, L"%d", v2->iSpecCost - v2->iTrainCost);
        UIElement_Text::SetText(v2->pUpCostText, v14);
        v13 = v34.m_charbuffer;
      }
      else
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&tRec, &word_794320);
        UIElement_Text::SetText(v2->pUpCostText, (PStringBase<unsigned short> *)&tRec);
        v13 = tRec;
      }
      v15 = (int)((char *)v13 - 20);
      if ( !InterlockedDecrement((volatile LONG *)(v15 + 4)) && v15 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v35, 0, L"%d", v2->iTrainCost);
      UIElement_Text::SetText(v2->pDownCostText, v16);
      v17 = (char *)&v35.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v35.m_charbuffer[-1].m_data[8]) && v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      v18 = v4->remainingSkillCredits;
      v19 = v2->iSpecCost - v2->iTrainCost;
      v21 = __OFSUB__(v18, v19);
      v20 = v18 - v19 < 0;
      v22 = v2->pSkillUpButton;
      if ( v20 ^ v21 )
        ((void (__stdcall *)(signed int))v22->vfptr[13].__vecDelDtor)(268435482);
      else
        ((void (__stdcall *)(signed int))v22->vfptr[13].__vecDelDtor)(268435483);
      v12 = v2->bUntrainable;
    }
    else
    {
      if ( v2->saCurClass != 3 )
        return;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v32, 0, L"%d", 0);
      UIElement_Text::SetText(v2->pUpCostText, v8);
      v9 = (char *)&v32.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v32.m_charbuffer[-1].m_data[8]) && v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v33, 0, L"%d", v2->iSpecCost - v2->iTrainCost);
      UIElement_Text::SetText(v2->pDownCostText, v10);
      v11 = (char *)&v33.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v33.m_charbuffer[-1].m_data[8]) )
      {
        if ( v11 )
          (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
      }
      ((void (__stdcall *)(signed int))v2->pSkillUpButton->vfptr[13].__vecDelDtor)(268435482);
      v12 = v2->bUnspecializable;
    }
    v23 = v2->pSkillDownButton;
    if ( v12 )
      goto LABEL_28;
  }
  ((void (__stdcall *)(signed int))v23->vfptr[13].__vecDelDtor)(268435482);
}

//----- (004808F0) --------------------------------------------------------  // acclient.c:188813
void __thiscall gmCGSkillsPage::UpdateCreditsMeter(gmCGSkillsPage *this)
{
  gmCGSkillsPage *v1; // esi@1
  int v2; // eax@1
  PStringBase<unsigned short> *v3; // eax@1
  char *v4; // esi@1
  PStringBase<unsigned short> v5; // [sp+0h] [bp-4h]@1

  v5.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v5, 0, L"%d", *(_DWORD *)(v2 + 440));
  UIElement_Text::SetText(v1->m_pCreditsMeter, v3);
  v4 = (char *)&v5.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v5.m_charbuffer[-1].m_data[8]) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  }
}

//----- (00480950) --------------------------------------------------------  // acclient.c:188835
void __thiscall gmCGSkillsPage::UpdateAllTrainingValues(gmCGSkillsPage *this)
{
  gmCGSkillsPage *v1; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // edi@1
  char *v5; // esi@6
  char *v6; // esi@9
  char *v7; // esi@12
  gmCGSkillsPage *v8; // [sp+Ch] [bp-78h]@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *iter; // [sp+10h] [bp-74h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-68h]@1
  gmCGSkillsPage::tagSkillRecord tRec; // [sp+28h] [bp-5Ch]@2

  v1 = this;
  v8 = this;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashSkills.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currBucket;
  for ( iter = v2->m_currHashTable; v3; v1 = v8 )
  {
    gmCGSkillsPage::tagSkillRecord::tagSkillRecord(&tRec, (gmCGSkillsPage::tagSkillRecord *)&v3->m_data);
    gmCGSkillsPage::SetSkillText(v1, &tRec);
    v3 = v3->m_hashNext;
    if ( !v3 )
    {
      while ( 1 )
      {
        ++v4;
        if ( v4 == &iter->m_buckets[iter->m_numBuckets] )
          break;
        if ( *v4 )
        {
          v3 = *v4;
          break;
        }
      }
    }
    v5 = (char *)&tRec.strFormula.m_charbuffer[-1].m_data[6];
    tRec.formSkill.vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&tRec.strFormula.m_charbuffer[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = (char *)&tRec.strDesc.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&tRec.strDesc.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (char *)&tRec.strName.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&tRec.strName.m_charbuffer[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
  gmCGSkillsPage::UpdateCreditsMeter(v1);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00480A40) --------------------------------------------------------  // acclient.c:188891
void __thiscall gmCGSkillsPage::InsertEntrySorted(gmCGSkillsPage *this, gmCGSkillsPage::tagSkillRecord *tRec, UIElement *pAfter, UIElement *pBefore)
{
  gmCGSkillsPage *v4; // esi@1
  UIElement_ListBox *v5; // edx@1
  unsigned int v6; // ecx@1
  signed int v7; // eax@1
  UIElement **v8; // edi@2
  unsigned int v9; // edi@7
  int v10; // ecx@7
  UIElement **v11; // edx@8
  int v12; // edi@13
  UIElement *v13; // eax@14
  HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *v14; // eax@14
  int v15; // eax@19
  UIElement *pAftera; // [sp+18h] [bp+8h]@13

  v4 = this;
  v5 = this->m_pSkillsListBox;
  v6 = v5->m_listItems.m_num;
  v7 = 0;
  if ( v6 )
  {
    v8 = v5->m_listItems.m_data;
    while ( *v8 != pAfter )
    {
      ++v7;
      ++v8;
      if ( v7 >= v6 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v7 = -1;
  }
  if ( pBefore )
  {
    v9 = v5->m_listItems.m_num;
    v10 = 0;
    if ( v9 )
    {
      v11 = v5->m_listItems.m_data;
      while ( *v11 != pBefore )
      {
        ++v10;
        ++v11;
        if ( v10 >= v9 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      v10 = -1;
    }
  }
  else
  {
    v10 = v5->m_listItems.m_num;
  }
  v12 = v7 + 1;
  pAftera = (UIElement *)v10;
  if ( v7 + 1 >= v10 )
  {
LABEL_22:
    UIElement_ListBox::InsertItem(v4->m_pSkillsListBox, tRec->pEntry, v12);
  }
  else
  {
    while ( 1 )
    {
      v13 = UIElement_ListBox::GetItem(v4->m_pSkillsListBox, v12);
      UIElement::GetAttribute_InstanceID(v13, 0x1000000Au, (unsigned int *)&pBefore);
      v14 = v4->m_hashSkills.m_intrusiveTable.m_buckets[(unsigned int)pBefore
                                                      % v4->m_hashSkills.m_intrusiveTable.m_numBuckets];
      if ( v14 )
      {
        while ( (UIElement *)v14->m_hashKey != pBefore )
        {
          v14 = v14->m_hashNext;
          if ( !v14 )
            goto LABEL_21;
        }
        if ( v14 )
        {
          v15 = (int)&v14->m_data;
          if ( v15 )
          {
            if ( _wcscmp(tRec->strName.m_charbuffer->m_data, *(const wchar_t **)(v15 + 24)) < 0 )
              break;
          }
        }
      }
LABEL_21:
      ++v12;
      if ( v12 >= (signed int)pAftera )
        goto LABEL_22;
    }
    UIElement_ListBox::InsertItem(v4->m_pSkillsListBox, tRec->pEntry, v12);
  }
}

//----- (00480B60) --------------------------------------------------------  // acclient.c:188995
void __thiscall IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>(IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>Vtbl *)&IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7A0180: using guessed type int (__thiscall *IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable)(void *, char);

//----- (00480BF0) --------------------------------------------------------  // acclient.c:189028
void __thiscall gmCGSkillsPage::UpdateSkillEntry(gmCGSkillsPage *this, gmCGSkillsPage::tagSkillRecord *tRec)
{
  gmCGSkillsPage *v2; // esi@1

  v2 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  UIElement_ListBox::RemoveItem(v2->m_pSkillsListBox, tRec->pEntry);
  gmCGSkillsPage::SetSkillText(v2, tRec);
  switch ( tRec->saCurClass )
  {
    case 1:
      if ( tRec->iMinlevel > 1 )
        gmCGSkillsPage::InsertEntrySorted(v2, tRec, v2->m_pUnuseableUntrainedEntry, 0);
      else
        gmCGSkillsPage::InsertEntrySorted(v2, tRec, v2->m_pUseableUntrainedEntry, v2->m_pUnuseableUntrainedEntry);
      break;
    case 2:
      gmCGSkillsPage::InsertEntrySorted(v2, tRec, v2->m_pTrainedEntry, v2->m_pUseableUntrainedEntry);
      break;
    case 3:
      gmCGSkillsPage::InsertEntrySorted(v2, tRec, v2->m_pSpecEntry, v2->m_pTrainedEntry);
      break;
  }
}

//----- (00480CA0) --------------------------------------------------------  // acclient.c:189054
void __thiscall gmCGSkillsPage::IncreaseSkillLevel(gmCGSkillsPage *this, UIElement *pEntry)
{
  gmCGSkillsPage *v2; // edi@1
  unsigned int *v3; // esi@2
  int v4; // eax@3
  int v5; // ecx@3
  unsigned int v6; // eax@3
  unsigned int _key; // [sp+0h] [bp-4h]@1

  _key = (unsigned int)this;
  v2 = this;
  if ( UIElement::GetAttribute_InstanceID(pEntry, 0x1000000Au, (unsigned int *)&pEntry) )
  {
    _key = (unsigned int)pEntry;
    v3 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
           (HashTable<unsigned long,unsigned long,0> *)&v2->m_hashSkills,
           &_key);
    if ( v3 )
    {
      CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
      v5 = v4;
      v6 = v3[15];
      if ( v6 == 1 )
      {
        if ( (signed int)v3[11] > *(_DWORD *)(v5 + 440)
          || !CharGenState::SetSkillLevel((CharGenState *)v5, v3[9], TRAINED_SKILL_ADVANCEMENT_CLASS) )
          goto LABEL_12;
        v3[15] = 2;
      }
      else
      {
        if ( v6 != 2
          || (signed int)(v3[12] - v3[11]) > *(_DWORD *)(v5 + 440)
          || !CharGenState::SetSkillLevel((CharGenState *)v5, v3[9], SPECIALIZED_SKILL_ADVANCEMENT_CLASS) )
          goto LABEL_12;
        v3[15] = 3;
      }
      gmCGSkillsPage::UpdateSkillEntry(v2, (gmCGSkillsPage::tagSkillRecord *)v3);
LABEL_12:
      gmCGSkillsPage::UpdateAllTrainingValues(v2);
      return;
    }
  }
}

//----- (00480D60) --------------------------------------------------------  // acclient.c:189100
void __thiscall gmCGSkillsPage::DecreaseSkillLevel(gmCGSkillsPage *this, UIElement *pEntry)
{
  gmCGSkillsPage *v2; // edi@1
  unsigned int *v3; // esi@2
  CharGenState *v4; // eax@3
  unsigned int v5; // edx@3
  unsigned int _key; // [sp+0h] [bp-4h]@1

  _key = (unsigned int)this;
  v2 = this;
  if ( UIElement::GetAttribute_InstanceID(pEntry, 0x1000000Au, (unsigned int *)&pEntry) )
  {
    _key = (unsigned int)pEntry;
    v3 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
           (HashTable<unsigned long,unsigned long,0> *)&v2->m_hashSkills,
           &_key);
    if ( v3 )
    {
      CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
      v5 = v3[15];
      if ( v5 == 3 && *((_BYTE *)v3 + 57) )
      {
        if ( !CharGenState::SetSkillLevel(v4, v3[9], TRAINED_SKILL_ADVANCEMENT_CLASS) )
        {
LABEL_12:
          gmCGSkillsPage::UpdateAllTrainingValues(v2);
          return;
        }
        v3[15] = 2;
      }
      else
      {
        if ( v5 != 2
          || !*((_BYTE *)v3 + 56)
          || !CharGenState::SetSkillLevel(v4, v3[9], UNTRAINED_SKILL_ADVANCEMENT_CLASS) )
          goto LABEL_12;
        v3[15] = 1;
      }
      gmCGSkillsPage::UpdateSkillEntry(v2, (gmCGSkillsPage::tagSkillRecord *)v3);
      goto LABEL_12;
    }
  }
}

//----- (00480E10) --------------------------------------------------------  // acclient.c:189145
void __thiscall gmCGSkillsPage::MakeSkillFormula(gmCGSkillsPage *this, gmCGSkillsPage::tagSkillRecord *tRec)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // eax@1
  unsigned int v5; // ecx@1
  int v6; // eax@1
  int v7; // edi@2
  int v8; // edx@3
  int v9; // esi@6
  PSRefBufferCharData<unsigned short> *v10; // eax@7
  int v11; // edi@8
  volatile LONG *v12; // ST14_4@11
  unsigned int v13; // ecx@13
  unsigned int v14; // edx@13
  unsigned int v15; // eax@13
  unsigned int v16; // ebx@13
  unsigned int v17; // ebp@13
  unsigned int v18; // esi@13
  const unsigned __int16 **v19; // eax@13
  const unsigned __int16 *v20; // eax@13
  int v21; // ecx@13
  int v22; // edi@15
  unsigned int v23; // eax@26
  PSRefBufferCharData<unsigned short> *v24; // ecx@26
  int v25; // eax@26
  int v26; // edi@28
  const unsigned __int16 **v27; // eax@32
  const unsigned __int16 *v28; // eax@35
  int v29; // ecx@35
  char *v30; // edi@37
  unsigned int v31; // eax@41
  PSRefBufferCharData<unsigned short> *v32; // ecx@41
  int v33; // eax@41
  int v34; // edi@43
  const unsigned __int16 **v35; // eax@48
  const unsigned __int16 *v36; // eax@50
  int v37; // ecx@50
  char *v38; // esi@52
  const unsigned __int16 **v39; // eax@57
  const unsigned __int16 *v40; // eax@57
  int v41; // ecx@57
  char *v42; // esi@59
  const unsigned __int16 **v43; // eax@63
  const unsigned __int16 *v44; // eax@63
  int v45; // ecx@63
  char *v46; // esi@65
  const unsigned __int16 **v47; // eax@69
  const unsigned __int16 *v48; // eax@69
  int v49; // ecx@69
  char *v50; // esi@71
  CharGenState *cg; // [sp+20h] [bp-130h]@1
  PStringBase<unsigned short> v52; // [sp+24h] [bp-12Ch]@26
  PStringBase<unsigned short> *v53; // [sp+28h] [bp-128h]@7
  int attribute1Present; // [sp+2Ch] [bp-124h]@13
  int attribute2Present; // [sp+30h] [bp-120h]@22
  SkillFormula formula; // [sp+34h] [bp-11Ch]@13
  char buf[256]; // [sp+50h] [bp-100h]@31

  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v2 = tRec->iSkillID;
  cg = (CharGenState *)v3;
  v4 = *(_DWORD *)(v3 + 584);
  v5 = *(_DWORD *)(v4 + 68);
  v6 = v4 + 56;
  if ( v5 && (v7 = *(_DWORD *)(v6 + 8)) != 0 && (v8 = *(_DWORD *)(v7 + 4 * (v2 % v5))) != 0 )
  {
    while ( v2 != *(_DWORD *)v8 )
    {
      v8 = *(_DWORD *)(v8 + 96);
      if ( !v8 )
        goto LABEL_6;
    }
    v9 = v8 + 8;
  }
  else
  {
LABEL_6:
    v9 = 0;
  }
  v10 = tRec->strFormula.m_charbuffer;
  v53 = &tRec->strFormula;
  if ( (wchar_t *)v10 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v11 = (int)&v10[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-1].m_data[8]) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v12 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    tRec->strFormula.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v12);
  }
  if ( v9 )
  {
    v13 = *(_DWORD *)(v9 + 52);
    v14 = *(_DWORD *)(v9 + 40);
    v15 = *(_DWORD *)(v9 + 48);
    v16 = *(_DWORD *)(v9 + 44);
    v17 = *(_DWORD *)(v9 + 56);
    v18 = *(_DWORD *)(v9 + 60);
    formula._z = v13;
    formula._w = v14;
    formula._y = v15;
    formula._attr2 = v18;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&attribute1Present,
      0,
      "Formula : ");
    v20 = *v19;
    v21 = *((_DWORD *)v20 - 1);
    if ( v21 != 1 )
      PStringBase<unsigned short>::append_n_chars(v53, v20, v21 - 1);
    v22 = attribute1Present - 20;
    if ( !InterlockedDecrement((volatile LONG *)(attribute1Present - 20 + 4)) && v22 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
    if ( v16 < 1 || (attribute1Present = 1, !v17) )
      attribute1Present = 0;
    if ( formula._y < 1 || (attribute2Present = 1, !v18) )
      attribute2Present = 0;
    if ( attribute1Present )
    {
      if ( attribute2Present )
      {
        v23 = _wcslen(L"(");
        PStringBase<unsigned short>::allocate_ref_buffer(&v52, v23);
        _wcscpy(v52.m_charbuffer->m_data, L"(");
        v24 = v52.m_charbuffer;
        v25 = *(_DWORD *)&v52.m_charbuffer[-1].m_data[14];
        if ( v25 != 1 )
        {
          PStringBase<unsigned short>::append_n_chars(v53, v52.m_charbuffer->m_data, v25 - 1);
          v24 = v52.m_charbuffer;
        }
        v26 = (int)&v24[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&v24[-1].m_data[8]) && v26 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
      }
      CharGenState::GetAttributeName(v17, buf);
      if ( v16 <= 1 )
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v52, 0, buf);
      else
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v52, 0, L"(%u x %s)", v16, buf);
      v28 = *v27;
      v29 = *((_DWORD *)v28 - 1);
      if ( v29 != 1 )
        PStringBase<unsigned short>::append_n_chars(v53, v28, v29 - 1);
      v30 = (char *)&v52.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v52.m_charbuffer[-1].m_data[8]) && v30 )
        (**(void (__thiscall ***)(char *, signed int))v30)(v30, 1);
      if ( !attribute2Present )
        goto LABEL_55;
      v31 = _wcslen(L" + ");
      PStringBase<unsigned short>::allocate_ref_buffer(&v52, v31);
      _wcscpy(v52.m_charbuffer->m_data, L" + ");
      v32 = v52.m_charbuffer;
      v33 = *(_DWORD *)&v52.m_charbuffer[-1].m_data[14];
      if ( v33 != 1 )
      {
        PStringBase<unsigned short>::append_n_chars(v53, v52.m_charbuffer->m_data, v33 - 1);
        v32 = v52.m_charbuffer;
      }
      v34 = (int)&v32[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v32[-1].m_data[8]) && v34 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
    }
    if ( attribute2Present )
    {
      CharGenState::GetAttributeName(formula._attr2, buf);
      if ( formula._y <= 1 )
        PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&cg, 0, buf);
      else
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&cg,
          0,
          L"(%u x %s)",
          formula._y,
          buf);
      v36 = *v35;
      v37 = *((_DWORD *)v36 - 1);
      if ( v37 != 1 )
        PStringBase<unsigned short>::append_n_chars(v53, v36, v37 - 1);
      v38 = (char *)&cg[-1].bAttribLocked[6];
      if ( !InterlockedDecrement((volatile LONG *)&cg[-1].skillTable) && v38 )
        (**(void (__thiscall ***)(char *, signed int))v38)(v38, 1);
    }
LABEL_55:
    if ( attribute1Present && attribute2Present )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&cg, 0, ")");
      v40 = *v39;
      v41 = *((_DWORD *)v40 - 1);
      if ( v41 != 1 )
        PStringBase<unsigned short>::append_n_chars(v53, v40, v41 - 1);
      v42 = (char *)&cg[-1].bAttribLocked[6];
      if ( !InterlockedDecrement((volatile LONG *)&cg[-1].skillTable) && v42 )
        (**(void (__thiscall ***)(char *, signed int))v42)(v42, 1);
    }
    if ( formula._z != 1 )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&cg,
        0,
        L" / %u",
        formula._z);
      v44 = *v43;
      v45 = *((_DWORD *)v44 - 1);
      if ( v45 != 1 )
        PStringBase<unsigned short>::append_n_chars(v53, v44, v45 - 1);
      v46 = (char *)&cg[-1].bAttribLocked[6];
      if ( !InterlockedDecrement((volatile LONG *)&cg[-1].skillTable) && v46 )
        (**(void (__thiscall ***)(char *, signed int))v46)(v46, 1);
    }
    if ( formula._w )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&cg,
        0,
        L" +%u",
        formula._w);
      v48 = *v47;
      v49 = *((_DWORD *)v48 - 1);
      if ( v49 != 1 )
        PStringBase<unsigned short>::append_n_chars(v53, v48, v49 - 1);
      v50 = (char *)&cg[-1].bAttribLocked[6];
      if ( !InterlockedDecrement((volatile LONG *)&cg[-1].skillTable) )
      {
        if ( v50 )
          (**(void (__thiscall ***)(char *, signed int))v50)(v50, 1);
      }
    }
  }
}

//----- (00481250) --------------------------------------------------------  // acclient.c:189378
void __thiscall gmCGSkillsPage::ShowSkillsText(gmCGSkillsPage *this, UIElement *pEntry)
{
  gmCGSkillsPage *v2; // edi@1
  unsigned int *v3; // esi@3
  CharGenState *v4; // eax@4
  CharGenState *v5; // ebx@4
  const unsigned __int16 *v6; // eax@4
  int v7; // ecx@4
  unsigned int v8; // eax@6
  const unsigned __int16 *v9; // eax@6
  int v10; // ecx@6
  unsigned int v11; // eax@8
  SKILL_ADVANCEMENT_CLASS v12; // eax@8
  const unsigned __int16 *v13; // esi@12
  int v14; // eax@12
  unsigned int v15; // eax@14
  char *v16; // esi@14
  char *v17; // esi@17
  PStringBase<unsigned short> strTitle; // [sp+8h] [bp-8h]@4
  unsigned int iID; // [sp+Ch] [bp-4h]@2

  v2 = this;
  if ( pEntry
    && UIElement::GetAttribute_InstanceID(pEntry, 0x1000000Au, &iID)
    && (pEntry = (UIElement *)iID,
        (v3 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                (HashTable<unsigned long,unsigned long,0> *)&v2->m_hashSkills,
                (const unsigned int *)&pEntry)) != 0) )
  {
    CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
    v5 = v4;
    pEntry = (UIElement *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    strTitle.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    gmCGSkillsPage::MakeSkillFormula(v2, (gmCGSkillsPage::tagSkillRecord *)v3);
    v6 = (const unsigned __int16 *)v3[6];
    v7 = *((_DWORD *)v6 - 1);
    if ( v7 != 1 )
      PStringBase<unsigned short>::append_n_chars(&strTitle, v6, v7 - 1);
    v8 = CharGenState::GetSkillScore(v5, v3[9]);
    PStringBase<unsigned short>::sprintf_append(&strTitle, L" (%d)\n", v8);
    v9 = (const unsigned __int16 *)v3[7];
    v10 = *((_DWORD *)v9 - 1);
    if ( v10 != 1 )
      PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&pEntry, v9, v10 - 1);
    v11 = _wcslen(L"\n");
    PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&pEntry, L"\n", v11);
    v12 = CharGenState::GetSkillLevel(v5, v3[9]);
    if ( v12 == 2 )
    {
      PStringBase<unsigned short>::append_string((PStringBase<unsigned short> *)&pEntry, L"Training Bonus  +5\n");
    }
    else if ( v12 == 3 )
    {
      PStringBase<unsigned short>::append_string((PStringBase<unsigned short> *)&pEntry, L"Specialization Bonus  +10\n");
    }
    v13 = (const unsigned __int16 *)v3[8];
    v14 = *((_DWORD *)v13 - 1);
    if ( v14 != 1 )
      PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&pEntry, v13, v14 - 1);
    v15 = _wcslen(L"\n");
    PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&pEntry, L"\n", v15);
    UIElement_Text::SetText(v2->m_pInfoBoxTitle, &strTitle);
    UIElement_Text::SetText(v2->m_pInfoBoxText, (PStringBase<unsigned short> *)&pEntry);
    v16 = (char *)&strTitle.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strTitle.m_charbuffer[-1].m_data[8]) && v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    v17 = (char *)&pEntry[-1].m_hashListeners.m_intrusiveTable.m_numElements;
    if ( !InterlockedDecrement((volatile LONG *)&pEntry[-1].m_iterListeners) )
    {
      if ( v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
    }
  }
  else
  {
    UIElement_Text::ClearAllText(v2->m_pInfoBoxTitle);
    UIElement_Text::ClearAllText(v2->m_pInfoBoxText);
  }
}
// 7A0204: using guessed type wchar_t aTrainingBonus5[20];

//----- (00481430) --------------------------------------------------------  // acclient.c:189462
void __thiscall IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::delete_contents(IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0> *this)
{
  IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> **v5; // edx@5
  HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *v6; // edi@5
  HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *v7; // eax@7
  HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_17:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      gmCGSkillsPage::tagSkillRecord::~tagSkillRecord(&v6->m_data);
      operator delete(v6);
    }
  }
}

//----- (004814C0) --------------------------------------------------------  // acclient.c:189522
int __thiscall gmCGSkillsPage::ListenToElementMessage(gmCGSkillsPage *this, UIElementMessageInfo *i_rMsg)
{
  gmCGSkillsPage *v2; // esi@1
  UIElement_ListBox *v3; // ebx@5
  unsigned int v4; // eax@5
  UIElement *v5; // eax@5
  UIElement *v7; // ebx@7

  v2 = this;
  if ( i_rMsg->idElement == 268436228 )
  {
    if ( i_rMsg->idMessage != 1 )
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    v7 = (UIElement *)((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)();
    gmCGSkillsPage::IncreaseSkillLevel(v2, v7);
    goto LABEL_10;
  }
  if ( i_rMsg->idElement == 268436229 )
  {
    if ( i_rMsg->idMessage != 1 )
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    v7 = (UIElement *)((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)();
    gmCGSkillsPage::DecreaseSkillLevel(v2, v7);
LABEL_10:
    UIElement_ListBox::SetSelectedItem(v2->m_pSkillsListBox, v7, 1);
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  if ( i_rMsg->idElement == 268436471 && i_rMsg->idMessage == 4 )
  {
    v3 = this->m_pSkillsListBox;
    v4 = UIElement_ListBox::GetSelectedIndex(this->m_pSkillsListBox);
    v5 = UIElement_ListBox::GetItem(v3, v4);
    gmCGSkillsPage::ShowSkillsText(v2, v5);
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
}

//----- (00481570) --------------------------------------------------------  // acclient.c:189561
char __thiscall HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::add(HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0> *this, const unsigned int *_key, gmCGSkillsPage::tagSkillRecord *_data)
{
  HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0> *v3; // edi@1
  void *v4; // esi@1
  char result; // al@7

  v3 = this;
  v4 = operator new(0x64u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    gmCGSkillsPage::tagSkillRecord::tagSkillRecord((gmCGSkillsPage::tagSkillRecord *)((char *)v4 + 8), _data);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      gmCGSkillsPage::tagSkillRecord::~tagSkillRecord((gmCGSkillsPage::tagSkillRecord *)((char *)v4 + 8));
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}

//----- (004815E0) --------------------------------------------------------  // acclient.c:189598
HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0> *__thiscall HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::scalar_deleting_destructor(HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0> *this, unsigned int a2)
{
  HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>Vtbl *)HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::vftable;
  IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable;
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
// 7A0180: using guessed type int (__thiscall *IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable)(void *, char);
// 7A023C: using guessed type int (__thiscall *HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::vftable[2])(void *, char);

//----- (00481640) --------------------------------------------------------  // acclient.c:189624
void __userpurge gmCGSkillsPage::gmCGSkillsPage(gmCGSkillsPage *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGSkillsPage *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCGSkillsPage::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  gmCGSkillsPage::tagSkillRecord::tagSkillRecord(&v4->m_tConstInit);
  v4->m_pPlayerSystem = 0;
  v4->m_pSkillsListBox = 0;
  v4->m_hashSkills.vfptr = (HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>Vtbl *)HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::vftable;
  IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>(
    &v4->m_hashSkills.m_intrusiveTable,
    0x17u);
}
// 7A023C: using guessed type int (__thiscall *HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::vftable[2])(void *, char);
// 7A0240: using guessed type int (__thiscall *gmCGSkillsPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004816B0) --------------------------------------------------------  // acclient.c:189646
gmCGSkillsPage *__thiscall gmCGSkillsPage::DynamicCast(gmCGSkillsPage *this, unsigned int i_eType)
{
  gmCGSkillsPage *result; // eax@1

  result = this;
  if ( i_eType != 268435515 )
    result = (gmCGSkillsPage *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004816D0) --------------------------------------------------------  // acclient.c:189657
signed int gmCGSkillsPage::GetUIElementType()
{
  return 268435515;
}

//----- (004816E0) --------------------------------------------------------  // acclient.c:189663
void __thiscall gmCGSkillsPage::~gmCGSkillsPage(gmCGSkillsPage *this)
{
  gmCGSkillsPage *v1; // edi@1
  NoticeHandler *v2; // ebx@1
  GlobalEventHandler *v3; // eax@1
  void *v4; // eax@3

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCGSkillsPage::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v1->m_hashSkills.vfptr = (HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>Vtbl *)HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::vftable;
  IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::delete_contents(&v1->m_hashSkills.m_intrusiveTable);
  v4 = v1->m_hashSkills.m_intrusiveTable.m_buckets;
  v1->m_hashSkills.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>Vtbl *)&IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable;
  if ( v4 != v1->m_hashSkills.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_hashSkills.m_intrusiveTable.m_buckets = 0;
  v1->m_hashSkills.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashSkills.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashSkills.m_intrusiveTable.m_numElements = 0;
  gmCGSkillsPage::tagSkillRecord::~tagSkillRecord(&v1->m_tConstInit);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A0180: using guessed type int (__thiscall *IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable)(void *, char);
// 7A023C: using guessed type int (__thiscall *HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::vftable[2])(void *, char);
// 7A0240: using guessed type int (__thiscall *gmCGSkillsPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00481770) --------------------------------------------------------  // acclient.c:189698
void __usercall gmCGSkillsPage::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGSkillsPage *v3; // eax@1

  v3 = (gmCGSkillsPage *)operator new(0x6F4u);
  if ( v3 )
    gmCGSkillsPage::gmCGSkillsPage(v3, a1, _layout, _full_desc);
}

//----- (004817A0) --------------------------------------------------------  // acclient.c:189708
gmCGSkillsPage *__thiscall gmCGSkillsPage::scalar_deleting_destructor(gmCGSkillsPage *this, unsigned int a2)
{
  gmCGSkillsPage *v2; // esi@1

  v2 = this;
  gmCGSkillsPage::~gmCGSkillsPage(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004817C0) --------------------------------------------------------  // acclient.c:189720
void __cdecl gmCGSkillsPage::Register()
{
  UIElement::RegisterElementClass(
    0x1000003Bu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCGSkillsPage::Create);
}

//----- (004817E0) --------------------------------------------------------  // acclient.c:189728
void __thiscall gmCGSkillsPage::DoSkillRecords(gmCGSkillsPage *this)
{
  gmCGSkillsPage *v1; // ebx@1
  UIElement_ListBox *v2; // ecx@1
  wchar_t *v3; // edi@2
  int v4; // eax@2
  int v5; // esi@2
  UIElement *v6; // eax@2
  UIElement_Text *v7; // ebp@3
  unsigned int v8; // eax@6
  unsigned int v9; // eax@6
  unsigned int v10; // eax@8
  unsigned int v11; // eax@8
  unsigned int v12; // eax@10
  unsigned int v13; // eax@10
  unsigned int v14; // eax@11
  unsigned int v15; // eax@11
  bool v16; // sf@15
  unsigned __int8 v17; // of@15
  int v18; // eax@16
  ListNode<SkillRecord *> *v19; // ecx@16
  PackableHashTable<unsigned long,SkillBase> *v20; // edx@16
  unsigned int v21; // ecx@19
  SkillRecord *v22; // ebp@19
  PackableHashData<unsigned long,SkillBase> **v23; // edi@20
  PackableHashData<unsigned long,SkillBase> *v24; // edx@21
  int v25; // esi@24
  int v26; // eax@25
  UIElement *v27; // edi@25
  UIElement *v28; // eax@26
  UIElement *v29; // eax@28
  UIElement *v30; // eax@30
  UIElement *v31; // eax@32
  UIElement *v32; // eax@34
  UIElement *v33; // eax@36
  UIElement_Button *v34; // ebx@37
  const unsigned __int16 *v35; // eax@38
  char *v36; // edi@38
  unsigned int v37; // eax@41
  unsigned int v38; // ecx@41
  unsigned int v39; // edx@41
  unsigned int v40; // edi@41
  unsigned int v41; // ebx@41
  int v42; // esi@41
  const unsigned __int16 *v43; // eax@41
  char *v44; // edi@41
  unsigned int v45; // edx@51
  char *v46; // eax@52
  int v47; // edi@53
  int i; // [sp+2Ch] [bp-184h]@1
  int ia; // [sp+2Ch] [bp-184h]@16
  UIElement_Text *pSkillName; // [sp+30h] [bp-180h]@27
  PackableHashTable<unsigned long,SkillBase> *skillBaseTable; // [sp+34h] [bp-17Ch]@16
  PStringBase<unsigned short> v52; // [sp+38h] [bp-178h]@38
  UIElement_Text *pSkillDown; // [sp+3Ch] [bp-174h]@33
  UIElement_Text *pSkillLevel; // [sp+40h] [bp-170h]@29
  gmCGSkillsPage *v55; // [sp+44h] [bp-16Ch]@1
  UIElement_Text *pSkillUp; // [sp+48h] [bp-168h]@31
  UIElement_Button *pSkillDownButton; // [sp+4Ch] [bp-164h]@35
  PStringBase<unsigned short> v58; // [sp+50h] [bp-160h]@41
  ListIterator<SkillRecord *> iter; // [sp+54h] [bp-15Ch]@16
  gmCGSkillsPage::tagSkillRecord tRec; // [sp+60h] [bp-150h]@2
  HeritageGroup_CG HeritageCG; // [sp+F0h] [bp-C0h]@2

  v1 = this;
  v2 = this->m_pSkillsListBox;
  v55 = v1;
  UIElement_ListBox::Flush(v2);
  i = 0;
  do
  {
    v3 = PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    StringInfo::StringInfo((StringInfo *)&HeritageCG);
    StringInfo::StringInfo((StringInfo *)&tRec);
    v4 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pSkillsListBox, 0, 0);
    v5 = v4;
    v6 = UIElement::GetChildRecursive((UIElement *)v4, 0x100002F6u);
    if ( v6 )
      v7 = (UIElement_Text *)v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
    else
      v7 = 0;
    if ( i )
    {
      if ( i == 1 )
      {
        v10 = compute_str_hash("ID_CharGen_Trained");
        StringInfo::SetStringIDandTableEnum((StringInfo *)&HeritageCG, v10, 268435458);
        v11 = compute_str_hash("ID_CharGen_Trained_Tooltip");
        StringInfo::SetStringIDandTableEnum((StringInfo *)&tRec, v11, 268435458);
        v1->m_pTrainedEntry = (UIElement *)v5;
      }
      else if ( i == 2 )
      {
        v12 = compute_str_hash("ID_CharGen_UseableUntrained");
        StringInfo::SetStringIDandTableEnum((StringInfo *)&HeritageCG, v12, 268435458);
        v13 = compute_str_hash("ID_CharGen_UseableUntrained_Tooltip");
        StringInfo::SetStringIDandTableEnum((StringInfo *)&tRec, v13, 268435458);
        v1->m_pUseableUntrainedEntry = (UIElement *)v5;
      }
      else
      {
        v14 = compute_str_hash("ID_CharGen_UnuseableUntrained");
        StringInfo::SetStringIDandTableEnum((StringInfo *)&HeritageCG, v14, 268435458);
        v15 = compute_str_hash("ID_CharGen_UnuseableUntrained_Tooltip");
        StringInfo::SetStringIDandTableEnum((StringInfo *)&tRec, v15, 268435458);
        v1->m_pUnuseableUntrainedEntry = (UIElement *)v5;
      }
    }
    else
    {
      v8 = compute_str_hash("ID_CharGen_Specialized");
      StringInfo::SetStringIDandTableEnum((StringInfo *)&HeritageCG, v8, 268435458);
      v9 = compute_str_hash("ID_CharGen_Specialized_Tooltip");
      StringInfo::SetStringIDandTableEnum((StringInfo *)&tRec, v9, 268435458);
      v1->m_pSpecEntry = (UIElement *)v5;
    }
    UIElement_Text::SetStringInfo(v7, (StringInfo *)&HeritageCG);
    UIElement::SetTooltip((UIElement *)&v7->vfptr, (StringInfo *)&tRec);
    StringInfo::~StringInfo((StringInfo *)&tRec);
    StringInfo::~StringInfo((StringInfo *)&HeritageCG);
    if ( !InterlockedDecrement((volatile LONG *)v3 - 4) && v3 != (wchar_t *)20 )
      (*(void (__thiscall **)(wchar_t *, signed int))*((void (__thiscall ***)(_DWORD, _DWORD))v3 - 5))(v3 - 10, 1);
    v17 = __OFSUB__(i + 1, 4);
    v16 = i++ - 3 < 0;
  }
  while ( v16 ^ v17 );
  IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::delete_contents(&v1->m_hashSkills.m_intrusiveTable);
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  v19 = *(ListNode<SkillRecord *> **)(v18 + 452);
  v20 = (PackableHashTable<unsigned long,SkillBase> *)(*(_DWORD *)(v18 + 584) + 56);
  ia = v18;
  skillBaseTable = (PackableHashTable<unsigned long,SkillBase> *)(*(_DWORD *)(v18 + 584) + 56);
  iter._current = v19;
  while ( iter._current )
  {
    v21 = v20->_table_size;
    v22 = iter._current->data;
    if ( v21 && (v23 = v20->_buckets) != 0 && (v24 = v23[v22->id % v21]) != 0 )
    {
      while ( v22->id != v24->_key )
      {
        v24 = v24->_next;
        if ( !v24 )
          goto LABEL_24;
      }
      v25 = (int)&v24->_data;
    }
    else
    {
LABEL_24:
      v25 = 0;
    }
    v26 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pSkillsListBox, 1u, 0);
    v27 = (UIElement *)v26;
    if ( v26 )
    {
      (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v26 + 156))(v26, 1);
      UIElement::SetAttribute_InstanceID(v27, 0x1000000Au, v22->id);
      v28 = UIElement::GetChildRecursive(v27, 0x10000301u);
      if ( !v28 )
        return;
      pSkillName = (UIElement_Text *)v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)12);
      if ( !pSkillName )
        return;
      v29 = UIElement::GetChildRecursive(v27, 0x10000302u);
      if ( !v29 )
        return;
      pSkillLevel = (UIElement_Text *)v29->vfptr[12].OnAction((IInputActionCallback *)v29, (InputEvent *)12);
      if ( !pSkillLevel )
        return;
      v30 = UIElement::GetChildRecursive(v27, 0x10000303u);
      if ( !v30 )
        return;
      pSkillUp = (UIElement_Text *)v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)12);
      if ( !pSkillUp )
        return;
      v31 = UIElement::GetChildRecursive(v27, 0x10000306u);
      if ( !v31 )
        return;
      pSkillDown = (UIElement_Text *)v31->vfptr[12].OnAction((IInputActionCallback *)v31, (InputEvent *)12);
      if ( !pSkillDown )
        return;
      v32 = UIElement::GetChildRecursive(v27, 0x10000305u);
      if ( !v32 )
        return;
      pSkillDownButton = (UIElement_Button *)v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)1);
      if ( !pSkillDownButton )
        return;
      v33 = UIElement::GetChildRecursive(v27, 0x10000304u);
      if ( !v33 )
        return;
      v34 = (UIElement_Button *)v33->vfptr[12].OnAction((IInputActionCallback *)v33, (InputEvent *)1);
      if ( !v34 )
        return;
      gmCGSkillsPage::tagSkillRecord::tagSkillRecord(&tRec);
      tRec.pUpCostText = pSkillUp;
      tRec.pDownCostText = pSkillDown;
      tRec.pEntry = v27;
      tRec.pSkillLevelText = pSkillLevel;
      tRec.pSkillDownButton = pSkillDownButton;
      tRec.pSkillUpButton = v34;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v52, 0, v22->name);
      PStringBase<unsigned short>::operator=(&tRec.strName, v35);
      v36 = (char *)&v52.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v52.m_charbuffer[-1].m_data[8]) && v36 )
        (**(void (__thiscall ***)(char *, signed int))v36)(v36, 1);
      tRec.saCurClass = CharGenState::GetSkillLevel((CharGenState *)ia, v22->id);
      tRec.iSkillID = v22->id;
      tRec.iSkillLevel = CharGenState::GetSkillScore((CharGenState *)ia, tRec.iSkillID);
      tRec.iTrainCost = *(_DWORD *)(v25 + 16);
      tRec.iSpecCost = *(_DWORD *)(v25 + 20);
      tRec.iMinlevel = *(_DWORD *)(v25 + 32);
      v37 = *(_DWORD *)(v25 + 40);
      v38 = *(_DWORD *)(v25 + 44);
      v39 = *(_DWORD *)(v25 + 48);
      v40 = *(_DWORD *)(v25 + 52);
      v41 = *(_DWORD *)(v25 + 60);
      tRec.formSkill._attr1 = *(_DWORD *)(v25 + 56);
      tRec.formSkill._w = v37;
      tRec.formSkill._x = v38;
      tRec.formSkill._y = v39;
      tRec.formSkill._z = v40;
      tRec.formSkill._attr2 = v41;
      v42 = *(_DWORD *)(v25 + 4);
      InterlockedIncrement((volatile LONG *)(v42 + 4));
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v58, 0, (const char *)(v42 + 20));
      PStringBase<unsigned short>::operator=(&tRec.strDesc, v43);
      v44 = (char *)&v58.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v58.m_charbuffer[-1].m_data[8]) && v44 )
        (**(void (__thiscall ***)(char *, signed int))v44)(v44, 1);
      if ( !InterlockedDecrement((volatile LONG *)(v42 + 4)) && v42 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v42)(v42, 1);
      tRec.bUnspecializable = 1;
      tRec.bUntrainable = 1;
      if ( !tRec.iTrainCost )
        tRec.bUntrainable = 0;
      if ( !tRec.iSpecCost )
        tRec.bUnspecializable = 0;
      ACCharGenData::GetHG(*(ACCharGenData **)(ia + 596), &HeritageCG, *(_DWORD *)(ia + 212));
      v45 = 0;
      if ( HeritageCG.mSkillList.m_num )
      {
        v46 = (char *)&HeritageCG.mSkillList.m_data->normalCost;
        while ( 1 )
        {
          v47 = *((_DWORD *)v46 + 1);
          if ( *((_DWORD *)v46 - 1) == tRec.iSkillID )
            break;
          ++v45;
          v46 += 16;
          if ( v45 >= HeritageCG.mSkillList.m_num )
            goto LABEL_61;
        }
        if ( !*(_DWORD *)v46 )
        {
          tRec.iSpecCost -= tRec.iTrainCost;
          tRec.iTrainCost = 0;
          tRec.bUntrainable = 0;
        }
        if ( !v47 )
        {
          tRec.iSpecCost = 0;
          tRec.bUnspecializable = 0;
        }
      }
LABEL_61:
      UIElement_Text::SetText(pSkillName, &tRec.strName);
      v1 = v55;
      gmCGSkillsPage::UpdateSkillEntry(v55, &tRec);
      pSkillName = (UIElement_Text *)tRec.iSkillID;
      HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::add(
        &v1->m_hashSkills,
        (const unsigned int *)&pSkillName,
        &tRec);
      iter._current = iter._current->next;
      HeritageGroup_CG::~HeritageGroup_CG(&HeritageCG);
      gmCGSkillsPage::tagSkillRecord::~tagSkillRecord(&tRec);
    }
    v20 = skillBaseTable;
  }
}

//----- (00481DC0) --------------------------------------------------------  // acclient.c:190012
void __thiscall gmCGSkillsPage::Update(gmCGSkillsPage *this)
{
  gmCGSkillsPage *v1; // esi@1

  v1 = this;
  gmCGSkillsPage::DoSkillRecords(this);
  gmCGSkillsPage::UpdateAllTrainingValues(v1);
}

//----- (00481DD0) --------------------------------------------------------  // acclient.c:190022
void __thiscall gmCGSkillsPage::InitializePage(gmCGSkillsPage *this, gmCharGenMainUI *_pMain)
{
  gmCGSkillsPage *v2; // esi@1
  CPlayerSystem *v3; // eax@1
  UIElement *v4; // eax@1
  int v5; // eax@2
  UIElement *v6; // eax@4
  int v7; // eax@5
  UIElement *v8; // eax@7
  int v9; // eax@8
  UIElement *v10; // eax@10
  int v11; // eax@11

  v2 = this;
  this->m_pMainFramework = _pMain;
  v3 = CPlayerSystem::GetPlayerSystem();
  v2->m_pPlayerSystem = v3;
  CPlayerSystem::GetCharGenState(v3);
  v4 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003F7u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)5);
  else
    v5 = 0;
  v2->m_pSkillsListBox = (UIElement_ListBox *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100002F3u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
  else
    v7 = 0;
  v2->m_pCreditsMeter = (UIElement_Text *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003FBu);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v2->m_pInfoBoxTitle = (UIElement_Text *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003FCu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v2->m_pInfoBoxText = (UIElement_Text *)v11;
  gmCGSkillsPage::DoSkillRecords(v2);
  gmCGSkillsPage::UpdateCreditsMeter(v2);
}

//----- (006ECE90) --------------------------------------------------------  // acclient.c:768742
void _E91_41()
{
  outside_val_33 = 1000.0 + 1.0;
}

//----- (006ECEB0) --------------------------------------------------------  // acclient.c:768748
void _E93_17()
{
  block_length_33 = 24.0 * 8.0;
}

//----- (006ECED0) --------------------------------------------------------  // acclient.c:768754
void _E95_17()
{
  half_square_length_33 = 24.0 * 0.5;
}

//----- (006ECEF0) --------------------------------------------------------  // acclient.c:768760
int _E97_42()
{
  return atexit(_E98_54);
}

//----- (006ECF00) --------------------------------------------------------  // acclient.c:768766
int _E100_35()
{
  return atexit(_E101_72);
}

//----- (006ECF10) --------------------------------------------------------  // acclient.c:768772
int _E103_27()
{
  return atexit(_E104_42);
}

//----- (006ECF20) --------------------------------------------------------  // acclient.c:768778
void _E106_23()
{
  DEFAULT_VIEW_RADIUS_17 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006ECF40) --------------------------------------------------------  // acclient.c:768784
void _E108_15()
{
  MIN_QUANTUM_17 = 1.0 / 30.0;
}

//----- (006ECF60) --------------------------------------------------------  // acclient.c:768790
void _E110_6()
{
  MAX_QUANTUM_17 = 1.0 / 5.0;
}

//----- (006ECF80) --------------------------------------------------------  // acclient.c:768796
void _E112_19()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_52, PFID_A8R8G8B8);
}

//----- (006ECF90) --------------------------------------------------------  // acclient.c:768802
int _E114_18()
{
  return atexit(nullsub_508);
}

//----- (006ECFA0) --------------------------------------------------------  // acclient.c:768808
void _E118_24()
{
  LOWEST_DATA_RATE_60 = 1024;
}

//----- (006ECFB0) --------------------------------------------------------  // acclient.c:768814
void _E120_15()
{
  HIGHEST_DATA_RATE_60 = 0x7FFF;
}

//----- (006ECFC0) --------------------------------------------------------  // acclient.c:768820
int _E122_4()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_60;
  INITIAL_MAX_DATA_RATE_8 = LOWEST_DATA_RATE_60;
  return result;
}

//----- (006ECFD0) --------------------------------------------------------  // acclient.c:768830
int _E1_93()
{
  return atexit(_E2_93);
}

