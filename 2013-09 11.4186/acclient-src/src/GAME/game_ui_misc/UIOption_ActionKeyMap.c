/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption_ActionKeyMap
   Object     : GAME\game_ui_misc\UIOption_ActionKeyMap.obj
   Functions  : 76
   Addresses  : 00431590 - 006EDA40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00431590) --------------------------------------------------------  // acclient.c:110702
void __thiscall List<CInputManager::InputMapEntry>::flush(List<QualifiedControl> *this)
{
  List<QualifiedControl> *i; // esi@1
  ListNode<QualifiedControl> *v2; // ecx@2
  ListNode<QualifiedControl> *v3; // eax@3

  for ( i = this; ; --i->_num_elements )
  {
    v2 = i->_head;
    if ( !v2 )
      break;
    v3 = v2->next;
    i->_head = v3;
    if ( v3 )
      v3->prev = 0;
    else
      i->_tail = 0;
    if ( v2 )
      operator delete(v2);
  }
}

//----- (00487060) --------------------------------------------------------  // acclient.c:194662
void __thiscall UIOption_ActionKeyMap::RecvNotice_RefreshOptionsPanel(UIOption_ActionKeyMap *this)
{
  ((void (*)(void))this->vfptr[7].RecvNotice_ServerSaysMoveItem)();
}

//----- (00487070) --------------------------------------------------------  // acclient.c:194668
void __thiscall UIOption_ActionKeyMap::CloseMapWarnDialog(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1

  v1 = this;
  if ( this->m_ctxtDialog )
  {
    DialogFactory::CloseDialog(this->m_ctxtDialog);
    v1->m_ctxtDialog = 0;
  }
}

//----- (004870A0) --------------------------------------------------------  // acclient.c:194681
void __thiscall _STL::pair<QualifiedControl,unsigned long>::pair<QualifiedControl,unsigned long>(_STL::pair<QualifiedControl,unsigned long> *this)
{
  this->first.m_key.m_dwKey = -1;
  this->first.m_metamode = 0;
  this->first.m_activation = 0;
  this->second = 0;
}

//----- (004870C0) --------------------------------------------------------  // acclient.c:194690
int __thiscall AC1Legacy::PStringBase<char>::vsprintf(AC1Legacy::PStringBase<char> *this, const char *fmt, char *args)
{
  AC1Legacy::PStringBase<char> *v3; // esi@1
  int v4; // eax@1
  AC1Legacy::PStringBase<char> v5; // ebx@1
  int v6; // edi@1

  v3 = this;
  v4 = __vscprintf(fmt, args);
  v5.m_buffer = v3->m_buffer;
  v6 = v4;
  AC1Legacy::PStringBase<char>::allocate_ref_buffer(v3, v4);
  __vsnprintf(v3->m_buffer->m_data, v6 + 1, fmt, args);
  if ( !InterlockedDecrement((volatile LONG *)&v5.m_buffer->m_cRef) && v5.m_buffer )
    v5.m_buffer->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5.m_buffer, 1u);
  return v6;
}

//----- (00487130) --------------------------------------------------------  // acclient.c:194709
char __thiscall List<QualifiedControl>::push_back(List<QualifiedControl> *this, QualifiedControl *val)
{
  List<QualifiedControl> *v2; // esi@1
  void *v3; // eax@1
  char result; // al@3
  ListNode<QualifiedControl> *v5; // ecx@5

  v2 = this;
  v3 = operator new(0x14u);
  if ( v3 )
  {
    *(QualifiedControl *)v3 = *val;
    *((_DWORD *)v3 + 3) = 0;
    *((_DWORD *)v3 + 4) = 0;
    if ( v2->_head )
    {
      v5 = v2->_tail;
      v5->next = (ListNode<QualifiedControl> *)v3;
      *((_DWORD *)v3 + 4) = v5;
      v2->_tail = (ListNode<QualifiedControl> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
    else
    {
      v2->_head = (ListNode<QualifiedControl> *)v3;
      v2->_tail = (ListNode<QualifiedControl> *)v3;
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

//----- (00487190) --------------------------------------------------------  // acclient.c:194748
void __thiscall _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>(_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > *this)
{
  this->first = 0;
  this->second.first.m_key.m_dwKey = -1;
  this->second.first.m_metamode = 0;
  this->second.first.m_activation = 0;
  this->second.second = 0;
}

//----- (004871B0) --------------------------------------------------------  // acclient.c:194758
ListNode<QualifiedControl> *__thiscall List<QualifiedControl>::find(List<QualifiedControl> *this, QualifiedControl *val)
{
  ListNode<QualifiedControl> *v2; // esi@1
  ListNode<QualifiedControl> *result; // eax@5

  v2 = this->_head;
  if ( v2 )
  {
    while ( !QualifiedControl::operator==(&v2->data, val) )
    {
      if ( v2 )
      {
        v2 = v2->next;
        if ( v2 )
          continue;
      }
      goto LABEL_5;
    }
    result = v2;
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (004871F0) --------------------------------------------------------  // acclient.c:194787
void __thiscall SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::Reset(SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *this)
{
  SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *v1; // esi@1
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
        *(_DWORD *)v7 = 0;
        --v5;
        --v6;
        *(_DWORD *)(v7 + 4) = -1;
        *(_DWORD *)(v7 + 8) = 0;
        *(_DWORD *)(v7 + 12) = 0;
        *(_DWORD *)(v7 + 16) = 0;
      }
      while ( v6 );
    }
  }
}

//----- (00487260) --------------------------------------------------------  // acclient.c:194831
int AC1Legacy::PStringBase<char>::sprintf(AC1Legacy::PStringBase<char> *this, const char *fmt, ...)
{
  va_list va; // [sp+Ch] [bp+Ch]@1

  va_start(va, fmt);
  return AC1Legacy::PStringBase<char>::vsprintf(this, fmt, va);
}

//----- (00487280) --------------------------------------------------------  // acclient.c:194840
void __thiscall UIOption_ActionKeyMap::Refresh(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // edi@1
  ICIDM *v2; // ecx@1
  ListNode<QualifiedControl> *v3; // ebx@2
  unsigned int v4; // ebp@2
  ICIDMVtbl *v5; // eax@6
  IInputActionCallbackVtbl *v6; // edx@7
  UIElement **v7; // ebx@7
  char *v8; // esi@10
  int v9; // edx@12
  UIElement_Button **v10; // eax@15
  UIElement_Button *v11; // esi@15
  IInputActionCallbackVtbl *v12; // edx@16
  UIElement *v13; // ecx@18
  StringInfo v14; // [sp-90h] [bp-1D4h]@7
  PStringBase<char> *v15; // [sp-8h] [bp-14Ch]@6
  PStringBase<char> v16; // [sp-4h] [bp-148h]@6
  PStringBase<char> sTemp; // [sp+10h] [bp-134h]@6
  ICIDM *inputMgr; // [sp+14h] [bp-130h]@1
  ListIterator<QualifiedControl> iter; // [sp+18h] [bp-12Ch]@2
  StringInfo siTooltip; // [sp+24h] [bp-120h]@7
  StringInfo siBinding; // [sp+B4h] [bp-90h]@7

  v1 = this;
  v2 = (ICIDM *)ICIDM::s_cidm;
  inputMgr = (ICIDM *)ICIDM::s_cidm;
  if ( ICIDM::s_cidm )
  {
    v4 = 0;
    iter._current = v1->m_qclCurrent._head;
    v3 = iter._current;
    if ( iter._current )
    {
      while ( v4 < v1->m_aKeyButtons.m_num )
      {
        v5 = v2->vfptr;
        v16.m_charbuffer = (PSRefBufferCharData<char> *)v3;
        v15 = &sTemp;
        (*((void (__stdcall **)(PStringBase<char> *, ListNode<QualifiedControl> *))&v5->OnUIElementActivationChanging + 1))(
          &sTemp,
          v3);
        if ( *(_DWORD *)&sTemp.m_charbuffer[-1].m_data[12] != 1 )
        {
          StringInfo::StringInfo(&siBinding);
          StringInfo::SetStringIDandTableEnum(&siBinding, ID_ActionKeyMap_ButtonLabel, 268435460);
          v16.m_charbuffer = sTemp.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&sTemp.m_charbuffer[-1]);
          StringInfo::AddVariable_String(&siBinding, LABEL, v16);
          UIElement_Text::SetStringInfo((UIElement_Text *)&v1->m_aKeyButtons.m_data[v4]->vfptr, &siBinding);
          v6 = v1->m_aKeyButtons.m_data[v4]->vfptr;
          v16.m_charbuffer = (PSRefBufferCharData<char> *)1;
          ((void (__stdcall *)(signed int))v6[13].__vecDelDtor)(1);
          StringInfo::StringInfo(&siTooltip);
          StringInfo::SetStringIDandTableEnum(&siTooltip, ID_ActionKeyMap_TT_ExistingBinding, 268435460);
          StringInfo::AddVariable_StringInfo(&siTooltip, VALUE_3, &siBinding);
          v7 = (UIElement **)&v1->m_aKeyButtons.m_data[v4];
          StringInfo::StringInfo(&v14, &siTooltip);
          UIElement::SetAttribute_StringInfo(*v7, 0x49u, v14);
          *((_DWORD *)&v1->m_aKeyButtons.m_data[v4++]->0 + 41) |= 0x20u;
          StringInfo::~StringInfo(&siTooltip);
          StringInfo::~StringInfo(&siBinding);
          v3 = iter._current;
        }
        if ( v3 )
        {
          iter._current = v3->next;
          v3 = iter._current;
        }
        v8 = &sTemp.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&sTemp.m_charbuffer[-1]) && v8 )
        {
          v9 = *(_DWORD *)v8;
          v16.m_charbuffer = (PSRefBufferCharData<char> *)1;
          (*(void (__thiscall **)(char *, signed int))v9)(v8, 1);
        }
        if ( !v3 )
          goto LABEL_14;
        v2 = inputMgr;
      }
    }
    else
    {
LABEL_14:
      while ( v4 < v1->m_aKeyButtons.m_num )
      {
        v10 = v1->m_aKeyButtons.m_data;
        v11 = v10[v4];
        if ( v11 )
        {
          UIElement_Text::ClearAllText((UIElement_Text *)&v10[v4]->vfptr);
          v12 = v11->vfptr;
          v16.m_charbuffer = (PSRefBufferCharData<char> *)1;
          v12[13].__vecDelDtor((IInputActionCallback *)v11, 1u);
          StringInfo::StringInfo(&siTooltip);
          StringInfo::SetStringIDandTableEnum(&siTooltip, ID_ActionKeyMap_TT_NewBinding, 268435460);
          StringInfo::StringInfo(&v14, &siTooltip);
          UIElement::SetAttribute_StringInfo((UIElement *)&v11->vfptr, 0x49u, v14);
          *((_DWORD *)&v11->0 + 41) |= 0x20u;
          StringInfo::~StringInfo(&siTooltip);
        }
        ++v4;
      }
    }
    v13 = (UIElement *)&v1->m_buttonClear->vfptr;
    if ( v13 )
    {
      LOBYTE(inputMgr) = v1->m_qclCurrent._head == 0;
      UIElement::SetAttribute_Bool(v13, 0xDu, (int)inputMgr);
    }
  }
}

//----- (004874E0) --------------------------------------------------------  // acclient.c:194954
QualifiedControl *__thiscall List<QualifiedControl>::get_data(List<QualifiedControl> *this, unsigned int pos)
{
  QualifiedControl *result; // eax@1
  int v3; // ecx@3

  result = &this->_head->data;
  if ( !result || pos >= this->_num_elements )
    goto LABEL_13;
  v3 = 0;
  while ( v3 != pos )
  {
    if ( result )
      result = (QualifiedControl *)result[1].m_key.m_dwKey;
    ++v3;
    if ( !result )
      return result;
  }
  if ( !result )
LABEL_13:
    result = 0;
  return result;
}

//----- (00487510) --------------------------------------------------------  // acclient.c:194978
signed int __thiscall SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::WhatNum(SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *this, _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > *i_rData)
{
  SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *v2; // ebx@1
  int v3; // ebp@1
  int v4; // eax@2
  int v5; // edi@3
  signed int result; // eax@6
  unsigned int index; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = 0;
  index = 0;
  if ( this->m_num )
  {
    while ( 1 )
    {
      v4 = (int)&v2->m_data[v3];
      if ( v2->m_data[v3].first == i_rData->first )
      {
        v5 = v4 + 4;
        if ( QualifiedControl::operator==((QualifiedControl *)(v4 + 4), &i_rData->second.first)
          && *(_DWORD *)(v5 + 12) == i_rData->second.second )
          break;
      }
      ++v3;
      ++index;
      if ( index >= v2->m_num )
        goto LABEL_6;
    }
    result = index;
  }
  else
  {
LABEL_6:
    result = -1;
  }
  return result;
}

//----- (00487580) --------------------------------------------------------  // acclient.c:195018
char __thiscall SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::RemoveUnOrderedByIndex(SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *this, unsigned int index)
{
  unsigned int v2; // eax@1
  unsigned int v3; // eax@2
  _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > *v4; // eax@3
  _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > *v5; // edx@3
  _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > *v6; // eax@3
  char result; // al@4

  v2 = this->m_num;
  if ( index >= v2 )
  {
    result = 0;
  }
  else
  {
    v3 = v2 - 1;
    this->m_num = v3;
    if ( index != v3 )
    {
      v4 = &this->m_data[v3];
      v5 = &this->m_data[index];
      v5->first = v4->first;
      v5->second.first.m_key.m_dwKey = v4->second.first.m_key.m_dwKey;
      v5->second.first.m_metamode = v4->second.first.m_metamode;
      v5->second.first.m_activation = v4->second.first.m_activation;
      v5->second.second = v4->second.second;
      v6 = &this->m_data[this->m_num];
      v6->first = 0;
      v6->second.first.m_key.m_dwKey = -1;
      v6->second.first.m_metamode = 0;
      v6->second.first.m_activation = 0;
      v6->second.second = 0;
    }
    result = 1;
  }
  return result;
}

//----- (004875F0) --------------------------------------------------------  // acclient.c:195058
char __thiscall SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::grow(SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *this, unsigned int i_nSize)
{
  SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *v2; // esi@1
  unsigned int v3; // edi@1
  void *v5; // eax@5
  _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > *v6; // ebx@5
  int v7; // eax@7
  int v8; // ecx@8
  int v9; // eax@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@8

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](20 * i_nSize);
    v6 = (_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(
        v5,
        0x14u,
        i_nSize,
        (void *(__thiscall *)(void *))_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>);
      if ( v2->m_data )
      {
        v7 = v2->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = (int)&v6[v7].second.first.m_activation;
          i_nSizea = v2->m_num;
          do
          {
            v9 = (int)((char *)v2->m_data + -12 - (_DWORD)v6 + v8);
            *(_DWORD *)(v8 - 12) = *(_DWORD *)v9;
            *(_DWORD *)(v8 - 8) = *(_DWORD *)(v9 + 4);
            *(_DWORD *)(v8 - 4) = *(_DWORD *)(v9 + 8);
            *(_DWORD *)v8 = *(_DWORD *)(v9 + 12);
            *(_DWORD *)(v8 + 4) = *(_DWORD *)(v9 + 16);
            v8 -= 20;
            --i_nSizea;
          }
          while ( i_nSizea );
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

//----- (004876E0) --------------------------------------------------------  // acclient.c:195121
bool __thiscall UIOption_ActionKeyMap::Changed(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // edi@1
  unsigned int v2; // eax@1
  bool result; // al@2
  unsigned int v4; // esi@3
  ListNode<QualifiedControl> *v5; // edx@4
  int v6; // eax@6
  ListNode<QualifiedControl> *v7; // ecx@11
  int v8; // eax@13

  v1 = this;
  v2 = this->m_qclSaved._num_elements;
  if ( v2 == this->m_qclCurrent._num_elements )
  {
    v4 = 0;
    if ( v2 )
    {
      while ( 1 )
      {
        v5 = v1->m_qclSaved._head;
        if ( !v5 || v4 >= v1->m_qclSaved._num_elements )
          break;
        v6 = 0;
        while ( v6 != v4 )
        {
          v5 = v5->next;
          ++v6;
          if ( !v5 )
            goto LABEL_9;
        }
        if ( !v5 )
          break;
        v7 = v1->m_qclCurrent._head;
        if ( !v7 || v4 >= v1->m_qclCurrent._num_elements )
          break;
        v8 = 0;
        while ( v8 != v4 )
        {
          v7 = v7->next;
          ++v8;
          if ( !v7 )
            return 0;
        }
        if ( !v7 )
          break;
        if ( !(unsigned __int8)QualifiedControl::IsExactlyEqual(&v7->data, &v5->data) )
          return 1;
        ++v4;
        if ( v4 >= v1->m_qclSaved._num_elements )
          return 0;
      }
    }
LABEL_9:
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00487780) --------------------------------------------------------  // acclient.c:195185
char __thiscall UIOption_ActionKeyMap::EraseBinding(UIOption_ActionKeyMap *this, int i_nBindingNumber)
{
  CInputManager *v2; // ebx@1
  UIOption_ActionKeyMap *v3; // edi@1
  QualifiedControl *v4; // eax@4
  QualifiedControl *v5; // esi@4
  unsigned int v6; // ecx@5
  unsigned int v7; // ecx@5
  IOptionChangeHandler *v8; // ecx@5
  IOptionChangeHandlerVtbl *v9; // eax@6
  char result; // al@7
  unsigned int v11; // [sp-14h] [bp-20h]@5
  unsigned int v12; // [sp-10h] [bp-1Ch]@5
  signed int v13; // [sp-8h] [bp-14h]@5
  unsigned int v14; // [sp-4h] [bp-10h]@5

  v2 = ICIDM::s_cidm;
  v3 = this;
  if ( ICIDM::s_cidm
    && i_nBindingNumber >= 0
    && i_nBindingNumber < this->m_qclCurrent._num_elements
    && (v4 = List<QualifiedControl>::get_data(&this->m_qclCurrent, i_nBindingNumber), (v5 = v4) != 0) )
  {
    v6 = v4->m_key.m_dwKey;
    v14 = v3->m_idInputMap;
    v12 = v6;
    ((void (__thiscall *)(CInputManager *, _DWORD, _DWORD, _DWORD, _DWORD))v2->vfptr->UnbindByKey)(
      v2,
      v6,
      v4->m_metamode,
      v4->m_activation,
      v14);
    v7 = v5->m_key.m_dwKey;
    v14 = v3->m_idInputMap;
    v13 = 1;
    v11 = v7;
    ((void (__thiscall *)(CInputManager *, _DWORD, _DWORD, _DWORD, signed int, _DWORD))v2->vfptr->BindAction)(
      v2,
      v7,
      v5->m_metamode,
      v5->m_activation,
      1,
      v14);
    CM_Character::SendNotice_RefreshActionKeyMapping(v5);
    v8 = v3->m_pOCH;
    if ( v8 )
    {
      v9 = v8->vfptr;
      v14 = (unsigned int)v3;
      ((void (__stdcall *)(_DWORD))v9->OnOptionChanged)(v3);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004878C0) --------------------------------------------------------  // acclient.c:195289
void __thiscall UIOption_ActionKeyMap::PostInit(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1
  UIElement *v2; // eax@2
  int v3; // eax@3
  NoticeHandlerVtbl *v4; // eax@6
  BasePropertyValue *v5; // ecx@7
  unsigned int v6; // edi@9
  BasePropertyValue *v7; // ecx@12
  UIElement *v8; // eax@14
  BasePropertyDesc *v9; // ecx@19
  unsigned int v10; // edx@19
  int v11; // edx@23
  GlobalEventHandler *v12; // eax@28
  BasePropertyDesc *v13; // ecx@32
  unsigned int v14; // esi@32
  BasePropertyValue *v15; // ecx@36
  unsigned int v16; // esi@36
  BasePropertyDesc *v17; // ecx@40
  unsigned int v18; // edx@40
  BasePropertyValue *v19; // ecx@44
  unsigned int v20; // edx@44
  unsigned int cElements; // [sp+24h] [bp-20h]@7
  unsigned int eClearButtonElementID; // [sp+28h] [bp-1Ch]@1
  unsigned int eElementID; // [sp+2Ch] [bp-18h]@12
  UIElement_Button *pButton; // [sp+30h] [bp-14h]@15
  BaseProperty propCurItem; // [sp+34h] [bp-10h]@10
  BaseProperty propArray; // [sp+3Ch] [bp-8h]@6

  v1 = this;
  UIElement_Scrollable::PostInit((UIElement_Scrollable *)this);
  eClearButtonElementID = 0;
  if ( UIElement::GetAttribute_Enum((UIElement *)v1, 0x1000002Au, &eClearButtonElementID) )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)v1, eClearButtonElementID);
    v3 = v2 ? v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)1) : 0;
    v1->m_lastCursor.m_x0 = v3;
    if ( !v3 )
      return;
  }
  v4 = v1->vfptr;
  propArray.m_pcPropertyDesc = 0;
  propArray.m_pcPropertyValue = 0;
  if ( !(unsigned __int8)((int (__thiscall *)(UIOption_ActionKeyMap *, signed int, BaseProperty *))v4[2].RecvNotice_ItemAttributesChanged)(
                           v1,
                           268435499,
                           &propArray) )
    goto LABEL_28;
  v5 = propArray.m_pcPropertyValue;
  cElements = 0;
  if ( propArray.m_pcPropertyValue )
  {
    ((void (__stdcall *)(_DWORD))propArray.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&cElements);
    v5 = propArray.m_pcPropertyValue;
  }
  v6 = 0;
  if ( cElements <= 0 )
  {
LABEL_28:
    v12 = GlobalEventHandler::GetGlobalEventHandler();
    if ( v12 )
      v12->vfptr->RegisterNoticeHandler(
        (NoticeRegistrar *)v12,
        (unsigned int)&loc_4DD242,
        (NoticeHandler *)&v1[-1].m_qcBindingBeingChanged);
    UIListener::RegisterForGlobalMessage((UIListener *)v1, 0xCu);
    goto LABEL_31;
  }
  while ( 1 )
  {
    propCurItem.m_pcPropertyDesc = 0;
    propCurItem.m_pcPropertyValue = 0;
    if ( v5 )
      break;
LABEL_27:
    ++v6;
    if ( v6 >= cElements )
      goto LABEL_28;
  }
  if ( !(unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v5->vfptr[61].__vecDelDtor)(v6, &propCurItem) )
    goto LABEL_17;
  v7 = propCurItem.m_pcPropertyValue;
  eElementID = 0;
  if ( !propCurItem.m_pcPropertyValue )
  {
LABEL_18:
    if ( (_DWORD)propCurItem.m_pcPropertyDesc )
    {
      v9 = propCurItem.m_pcPropertyDesc;
      v10 = propCurItem.m_pcPropertyDesc->m_cRef - 1;
      propCurItem.m_pcPropertyDesc->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
      v7 = propCurItem.m_pcPropertyValue;
      propCurItem.m_pcPropertyDesc = 0;
    }
    if ( v7 )
    {
      v11 = v7->m_cRef - 1;
      v7->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
      propCurItem.m_pcPropertyValue = 0;
    }
    v5 = propArray.m_pcPropertyValue;
    goto LABEL_27;
  }
  if ( !(unsigned __int8)((int (__stdcall *)(_DWORD))propCurItem.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&eElementID) )
  {
LABEL_17:
    v7 = propCurItem.m_pcPropertyValue;
    goto LABEL_18;
  }
  v8 = UIElement::GetChildRecursive((UIElement *)v1, eElementID);
  if ( v8 )
  {
    pButton = (UIElement_Button *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)1);
    if ( pButton )
    {
      SmartArray<UIElement_Button *,1>::AddToEnd(
        (SmartArray<BSPNODE *,1> *)&v1->m_lastCursor.m_y0,
        (BSPNODE *const *)&pButton);
      goto LABEL_17;
    }
  }
  if ( (_DWORD)propCurItem.m_pcPropertyDesc )
  {
    v17 = propCurItem.m_pcPropertyDesc;
    v18 = propCurItem.m_pcPropertyDesc->m_cRef - 1;
    propCurItem.m_pcPropertyDesc->m_cRef = v18;
    if ( !v18 )
      ((void (__stdcall *)(_DWORD))v17->vfptr->__vecDelDtor)(1);
    propCurItem.m_pcPropertyDesc = 0;
  }
  if ( propCurItem.m_pcPropertyValue )
  {
    v19 = propCurItem.m_pcPropertyValue;
    v20 = propCurItem.m_pcPropertyValue->m_cRef - 1;
    propCurItem.m_pcPropertyValue->m_cRef = v20;
    if ( !v20 )
      ((void (__stdcall *)(_DWORD))v19->vfptr->__vecDelDtor)(1);
    propCurItem.m_pcPropertyValue = 0;
  }
LABEL_31:
  if ( (_DWORD)propArray.m_pcPropertyDesc )
  {
    v13 = propArray.m_pcPropertyDesc;
    v14 = propArray.m_pcPropertyDesc->m_cRef - 1;
    propArray.m_pcPropertyDesc->m_cRef = v14;
    if ( !v14 )
      ((void (__stdcall *)(_DWORD))v13->vfptr->__vecDelDtor)(1);
    propArray.m_pcPropertyDesc = 0;
  }
  if ( propArray.m_pcPropertyValue )
  {
    v15 = propArray.m_pcPropertyValue;
    v16 = propArray.m_pcPropertyValue->m_cRef - 1;
    propArray.m_pcPropertyValue->m_cRef = v16;
    if ( !v16 )
      ((void (__stdcall *)(_DWORD))v15->vfptr->__vecDelDtor)(1);
  }
}

//----- (00487AF0) --------------------------------------------------------  // acclient.c:195453
List<unsigned long> *__thiscall List<unsigned long>::scalar_deleting_destructor(List<unsigned long> *this, unsigned int a2)
{
  List<unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (00487B20) --------------------------------------------------------  // acclient.c:195467
char __thiscall UIOption_ActionKeyMap::SetBinding(UIOption_ActionKeyMap *this, QualifiedControl i_qc, int i_nBindingNumber)
{
  UIOption_ActionKeyMap *v3; // ebx@1
  int v4; // eax@1
  unsigned int v5; // ebp@1
  CInputManager *v6; // esi@7
  char *v7; // esi@9
  unsigned int v8; // edx@10
  unsigned int v9; // eax@11
  ICIDMVtbl *v10; // edx@11
  int v11; // edi@14
  unsigned int v12; // ecx@15
  unsigned int v13; // edx@15
  unsigned int v14; // ebx@15
  QualifiedControl *v15; // eax@23
  QualifiedControl *v16; // edi@23
  unsigned int v17; // ecx@24
  unsigned int v18; // ecx@25
  signed int v19; // edx@26
  ICIDMVtbl *v20; // eax@26
  ListNode<QualifiedControl> *i; // edi@26
  signed int v22; // ecx@28
  unsigned int v23; // edx@28
  ListNode<QualifiedControl> *v24; // edi@30
  unsigned int v25; // edx@31
  unsigned int v26; // edx@32
  signed int v27; // ecx@33
  int v28; // edx@37
  IOptionChangeHandler *v30; // ecx@39
  IOptionChangeHandlerVtbl *v31; // edx@40
  char v32; // bl@41
  char *v33; // esi@41
  int v34; // edx@43
  unsigned int v35; // [sp+Ch] [bp-58h]@25
  unsigned int v36; // [sp+10h] [bp-54h]@15
  unsigned int v37; // [sp+14h] [bp-50h]@11
  signed int v38; // [sp+18h] [bp-4Ch]@11
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *v39; // [sp+1Ch] [bp-48h]@9
  PStringBase<char> sTemp; // [sp+30h] [bp-34h]@8
  unsigned int mapID; // [sp+34h] [bp-30h]@11
  UIOption_ActionKeyMap *v42; // [sp+38h] [bp-2Ch]@1
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> aControlMappings; // [sp+3Ch] [bp-28h]@11
  ListIterator<unsigned long> iter; // [sp+48h] [bp-1Ch]@10
  List<unsigned long> listMapIDs; // [sp+54h] [bp-10h]@10

  v3 = this;
  v4 = this->m_qclCurrent._num_elements;
  v5 = 0;
  v42 = this;
  if ( i_nBindingNumber <= v4 )
  {
    if ( i_nBindingNumber < 0 )
      i_nBindingNumber = 0;
  }
  else
  {
    i_nBindingNumber = v4;
  }
  if ( i_qc.m_key.m_dwKey == -1 )
    return 0;
  if ( !i_qc.m_activation )
    return 0;
  v6 = ICIDM::s_cidm;
  if ( !ICIDM::s_cidm )
    return 0;
  (*(void (__thiscall **)(CInputManager *, PStringBase<char> *, QualifiedControl *))((void (__thiscall **)(_DWORD, _DWORD, _DWORD))&ICIDM::s_cidm->vfptr->OnUIElementActivationChanging
                                                                                   + 1))(
    ICIDM::s_cidm,
    &sTemp,
    &i_qc);
  if ( *(_DWORD *)&sTemp.m_charbuffer[-1].m_data[12] == 1 )
  {
    v7 = &sTemp.m_charbuffer[-2].m_data[12];
    v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)&sTemp.m_charbuffer[-1];
    goto LABEL_35;
  }
  v8 = v3->m_idInputMap;
  listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  listMapIDs._head = 0;
  listMapIDs._tail = 0;
  listMapIDs._num_elements = 0;
  v6->vfptr->FindConflictingInputMaps((ICIDM *)v6, v8, &listMapIDs);
  for ( iter._current = listMapIDs._head; iter._current; iter._current = iter._current->next )
  {
    v9 = iter._current->data;
    v10 = v6->vfptr;
    v39 = &aControlMappings;
    v38 = v9;
    mapID = v9;
    v37 = (unsigned int)&v3->m_qcBindingBeingChanged.m_key.m_dwKey;
    aControlMappings.m_data = 0;
    aControlMappings.m_sizeAndDeallocate = 0;
    aControlMappings.m_num = 0;
    if ( v10->FindConflictingControls((ICIDM *)v6, &v3->m_qcBindingBeingChanged, v9, &aControlMappings)
      && aControlMappings.m_num > 0 )
    {
      if ( aControlMappings.m_num )
      {
        v11 = 0;
        do
        {
          v12 = aControlMappings.m_data[v11].first.m_key.m_dwKey;
          v13 = aControlMappings.m_data[v11].first.m_metamode;
          v14 = aControlMappings.m_data[v11].first.m_activation;
          v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)mapID;
          v36 = v12;
          v37 = v13;
          v38 = v14;
          ((void (__thiscall *)(CInputManager *, unsigned int, unsigned int, unsigned int, unsigned int))v6->vfptr->UnbindByKey)(
            v6,
            v12,
            v13,
            v14,
            mapID);
          ++v5;
          ++v11;
        }
        while ( v5 < aControlMappings.m_num );
        v3 = v42;
      }
      v5 = 0;
    }
    if ( (aControlMappings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](aControlMappings.m_data);
  }
  if ( i_nBindingNumber < 0 || i_nBindingNumber >= v3->m_qclCurrent._num_elements )
  {
    if ( v3->m_qclCurrent._num_elements >= v3->m_aKeyButtons.m_num )
    {
      v24 = v3->m_qclCurrent._head;
      if ( !v24 )
      {
        listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
        List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
        v7 = &sTemp.m_charbuffer[-2].m_data[12];
        v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)&sTemp.m_charbuffer[-1];
LABEL_35:
        if ( !InterlockedDecrement((volatile LONG *)v39) )
        {
          if ( v7 )
          {
            v28 = *(_DWORD *)v7;
            v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)1;
            (*(void (__thiscall **)(char *, signed int))v28)(v7, 1);
          }
        }
        return 0;
      }
      v25 = v24->data.m_key.m_dwKey;
      v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3->m_idInputMap;
      v36 = v25;
      ((void (__thiscall *)(CInputManager *, unsigned int, unsigned int, unsigned int, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *))v6->vfptr->UnbindByKey)(
        v6,
        v25,
        v24->data.m_metamode,
        v24->data.m_activation,
        v39);
      if ( !QualifiedControl::IsConflicting(&i_qc, &v24->data) )
      {
        v26 = v24->data.m_key.m_dwKey;
        v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3->m_idInputMap;
        v38 = 1;
        v35 = v26;
        v36 = v24->data.m_metamode;
        v37 = v24->data.m_activation;
        ((void (__thiscall *)(CInputManager *, unsigned int, unsigned int, unsigned int, signed int, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *))v6->vfptr->BindAction)(
          v6,
          v26,
          v36,
          v37,
          1,
          v39);
      }
    }
    v27 = v3->m_idInputAction;
    v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3->m_idInputMap;
    v38 = v27;
    v36 = i_qc.m_metamode;
    v37 = i_qc.m_activation;
    ((void (__thiscall *)(CInputManager *, unsigned int, unsigned int, unsigned int, signed int, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *))v6->vfptr->BindAction)(
      v6,
      i_qc.m_key.m_dwKey,
      i_qc.m_metamode,
      i_qc.m_activation,
      v27,
      v39);
    List<QualifiedControl>::push_back(&v3->m_qclCurrent, &i_qc);
  }
  else
  {
    v15 = List<QualifiedControl>::get_data(&v3->m_qclCurrent, i_nBindingNumber);
    v16 = v15;
    if ( v15 )
    {
      v17 = v15->m_key.m_dwKey;
      v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3->m_idInputMap;
      v36 = v17;
      ((void (__thiscall *)(CInputManager *, unsigned int, unsigned int, unsigned int, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *))v6->vfptr->UnbindByKey)(
        v6,
        v17,
        v15->m_metamode,
        v15->m_activation,
        v39);
      if ( !QualifiedControl::IsConflicting(&i_qc, v16) )
      {
        v18 = v16->m_key.m_dwKey;
        v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3->m_idInputMap;
        v38 = 1;
        v35 = v18;
        v36 = v16->m_metamode;
        v37 = v16->m_activation;
        ((void (__thiscall *)(CInputManager *, unsigned int, unsigned int, unsigned int, signed int, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *))v6->vfptr->BindAction)(
          v6,
          v18,
          v36,
          v37,
          1,
          v39);
      }
      *v16 = i_qc;
      v19 = v3->m_idInputAction;
      v20 = v6->vfptr;
      v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3->m_idInputMap;
      v38 = v19;
      v20->UnbindAllByAction((ICIDM *)v6, v19, (unsigned int)v39);
      for ( i = v3->m_qclCurrent._head; i; i = i->next )
      {
        v22 = v3->m_idInputAction;
        v23 = i->data.m_key.m_dwKey;
        v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3->m_idInputMap;
        v38 = v22;
        v35 = v23;
        ((void (__thiscall *)(CInputManager *, unsigned int, unsigned int, unsigned int, signed int, SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *))v6->vfptr->BindAction)(
          v6,
          v23,
          i->data.m_metamode,
          i->data.m_activation,
          v22,
          v39);
      }
    }
  }
  v30 = v3->m_pOCH;
  if ( v30 )
  {
    v31 = v30->vfptr;
    v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)v3;
    ((void (__stdcall *)(UIOption_ActionKeyMap *))v31->OnOptionChanged)(v3);
  }
  v32 = CM_Character::SendNotice_RefreshActionKeyMapping(&i_qc);
  listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
  v33 = &sTemp.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&sTemp.m_charbuffer[-1]) && v33 )
  {
    v34 = *(_DWORD *)v33;
    v39 = (SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> *)1;
    (*(void (__thiscall **)(char *, signed int))v34)(v33, 1);
  }
  return v32;
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (00487ED0) --------------------------------------------------------  // acclient.c:195731
char __thiscall UIOption_ActionKeyMap::ClearAllBindings(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1
  unsigned int v2; // edi@2

  v1 = this;
  if ( this->m_qclCurrent._head )
  {
    v2 = 0;
    if ( this->m_qclCurrent._num_elements )
    {
      do
        UIOption_ActionKeyMap::EraseBinding(v1, v2++);
      while ( v2 < v1->m_qclCurrent._num_elements );
    }
    List<CInputManager::InputMapEntry>::flush(&v1->m_qclCurrent);
    ((void (__thiscall *)(UIOption_ActionKeyMap *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  }
  return 1;
}

//----- (00487F20) --------------------------------------------------------  // acclient.c:195753
List<QualifiedControl> *__thiscall List<QualifiedControl>::operator=(List<QualifiedControl> *this, int a2)
{
  List<QualifiedControl> *v2; // edi@1
  int i; // esi@2
  void *v4; // eax@3
  ListNode<QualifiedControl> *v5; // ecx@6

  v2 = this;
  if ( this != (List<QualifiedControl> *)a2 )
  {
    List<CInputManager::InputMapEntry>::flush(this);
    for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 12) )
    {
      v4 = operator new(0x14u);
      if ( v4 )
      {
        *(_DWORD *)v4 = *(_DWORD *)i;
        *((_DWORD *)v4 + 1) = *(_DWORD *)(i + 4);
        *((_DWORD *)v4 + 2) = *(_DWORD *)(i + 8);
        *((_DWORD *)v4 + 3) = 0;
        *((_DWORD *)v4 + 4) = 0;
        if ( v2->_head )
        {
          v5 = v2->_tail;
          v5->next = (ListNode<QualifiedControl> *)v4;
          *((_DWORD *)v4 + 4) = v5;
        }
        else
        {
          v2->_head = (ListNode<QualifiedControl> *)v4;
        }
        v2->_tail = (ListNode<QualifiedControl> *)v4;
        ++v2->_num_elements;
      }
      if ( !i )
        break;
    }
  }
  return v2;
}

//----- (00487F90) --------------------------------------------------------  // acclient.c:195795
List<QualifiedControl> *__thiscall List<QualifiedControl>::vector_deleting_destructor(List<QualifiedControl> *this, unsigned int a2)
{
  List<QualifiedControl> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
  List<CInputManager::InputMapEntry>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A2BE8: using guessed type int (__thiscall *List<QualifiedControl>::vftable)(void *, char);

//----- (00487FC0) --------------------------------------------------------  // acclient.c:195809
void __thiscall ClientSystem::AddTextToScroll(ClientSystem *this, const char *i_text, unsigned int i_ltt, bool i_sendToAPI, unsigned int i_nOverrideDestination)
{
  ClientSystem *v5; // esi@1
  const char *v6; // esi@1

  v5 = this;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_text, 0, i_text);
  ClientSystem::AddTextToScroll(v5, (PStringBase<unsigned short> *)&i_text, i_ltt, i_sendToAPI, i_nOverrideDestination);
  v6 = i_text - 20;
  if ( !InterlockedDecrement((volatile LONG *)i_text - 4) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}

//----- (00488020) --------------------------------------------------------  // acclient.c:195826
void __thiscall UIOption_ActionKeyMap::UIOption_ActionKeyMap(UIOption_ActionKeyMap *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_ActionKeyMap *v3; // esi@1

  v3 = this;
  UIOption::UIOption((UIOption *)&this->vfptr);
  UIElement_Text::UIElement_Text((UIElement_Text *)&v3->vfptr, (int)&v3->vfptr, _layout, _full_desc);
  v3->m_buttonClear = 0;
  v3->vfptr = (NoticeHandlerVtbl *)&UIOption_ActionKeyMap::vftable;
  v3->vfptr = (IInputActionCallbackVtbl *)&UIOption_ActionKeyMap::vftable;
  v3->vfptr = (CInputHandlerVtbl *)&UIOption_ActionKeyMap::vftable;
  v3->m_aKeyButtons.m_data = 0;
  v3->m_aKeyButtons.m_sizeAndDeallocate = 0;
  v3->m_aKeyButtons.m_num = 0;
  v3->m_idInputAction = 0;
  v3->m_idInputMap = 0;
  v3->m_qclDefaults._head = 0;
  v3->m_qclDefaults._tail = 0;
  v3->m_qclDefaults._num_elements = 0;
  v3->m_qclDefaults.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
  v3->m_qclSaved.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
  v3->m_qclSaved._head = 0;
  v3->m_qclSaved._tail = 0;
  v3->m_qclSaved._num_elements = 0;
  v3->m_qclCurrent.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
  v3->m_qclCurrent._head = 0;
  v3->m_qclCurrent._tail = 0;
  v3->m_qclCurrent._num_elements = 0;
  v3->m_qcBindingBeingChanged.m_metamode = 0;
  v3->m_qcBindingBeingChanged.m_activation = 0;
  v3->m_qcBindingBeingChanged.m_key.m_dwKey = -1;
  v3->m_ctxtDialog = 0;
  v3->m_ctxtOverwriteBindingDialog = 0;
  v3->m_ctxtCantOverwriteBindingDialog = 0;
  v3->m_skipConfirmation = 0;
  v3->m_nBindingBeingChanged = -1;
}
// 7A2BE8: using guessed type int (__thiscall *List<QualifiedControl>::vftable)(void *, char);
// 7A2BEC: using guessed type void (__thiscall *UIOption_ActionKeyMap::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7A2C08: using guessed type void *UIOption_ActionKeyMap::vftable;
// 7A2D48: using guessed type bool (__thiscall *UIOption_ActionKeyMap::vftable)(DBCache *this);

//----- (00488100) --------------------------------------------------------  // acclient.c:195869
signed int __thiscall UIOption_ActionKeyMap::DynamicCast(UIOption_ActionKeyMap *this, unsigned int i_eType)
{
  signed int result; // eax@3

  if ( i_eType == 268435508 )
  {
    if ( this )
      result = (signed int)&this->vfptr;
    else
      result = 0;
  }
  else
  {
    result = (signed int)&this->vfptr;
    if ( i_eType != 12 )
      result = i_eType != 10 ? 0 : result;
  }
  return result;
}

//----- (00488140) --------------------------------------------------------  // acclient.c:195890
signed int UIOption_ActionKeyMap::GetUIElementType()
{
  return 268435508;
}

//----- (00488150) --------------------------------------------------------  // acclient.c:195896
UIOption_ActionKeyMap *__thiscall UIOption_ActionKeyMap::vector_deleting_destructor(UIOption_ActionKeyMap *this, unsigned int a2)
{
  return UIOption_ActionKeyMap::vector_deleting_destructor((UIOption_ActionKeyMap *)((char *)this - 32), a2);
}

//----- (00488160) --------------------------------------------------------  // acclient.c:195902
signed int __thiscall UIOption_ActionKeyMap::DynamicCast(UIOption_ActionKeyMap *this, unsigned int a2)
{
  return UIOption_ActionKeyMap::DynamicCast((UIOption_ActionKeyMap *)((char *)this - 32), a2);
}

//----- (00488170) --------------------------------------------------------  // acclient.c:195908
void __thiscall UIOption_ActionKeyMap::~UIOption_ActionKeyMap(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1
  UIListener *v2; // edi@1
  char *v3; // ebx@1
  GlobalEventHandler *v4; // eax@1

  v1 = this;
  v2 = (UIListener *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption_ActionKeyMap::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIOption_ActionKeyMap::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_ActionKeyMap::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, (NoticeHandler *)v1);
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputHandler)(v3, 32);
  UIListener::UnRegisterForGlobalMessage(v2, 0xCu);
  v1->m_qclCurrent.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
  List<CInputManager::InputMapEntry>::flush(&v1->m_qclCurrent);
  v1->m_qclSaved.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
  List<CInputManager::InputMapEntry>::flush(&v1->m_qclSaved);
  v1->m_qclDefaults.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
  List<CInputManager::InputMapEntry>::flush(&v1->m_qclDefaults);
  if ( (v1->m_aKeyButtons.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_aKeyButtons.m_data);
  UIElement_Text::~UIElement_Text((UIElement_Text *)v2);
  UIOption::~UIOption((UIOption *)&v1->vfptr);
}
// 7A2BE8: using guessed type int (__thiscall *List<QualifiedControl>::vftable)(void *, char);
// 7A2BEC: using guessed type void (__thiscall *UIOption_ActionKeyMap::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7A2C08: using guessed type void *UIOption_ActionKeyMap::vftable;
// 7A2D48: using guessed type bool (__thiscall *UIOption_ActionKeyMap::vftable)(DBCache *this);

//----- (00488230) --------------------------------------------------------  // acclient.c:195944
UIElement *__cdecl UIOption_ActionKeyMap::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_ActionKeyMap *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (UIOption_ActionKeyMap *)operator new(0x798u);
  if ( v2 && (UIOption_ActionKeyMap::UIOption_ActionKeyMap(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 32);
  else
    result = 0;
  return result;
}

//----- (00488260) --------------------------------------------------------  // acclient.c:195959
char __thiscall UIOption_ActionKeyMap::SaveCurrentValue(UIOption_ActionKeyMap *this)
{
  List<QualifiedControl>::operator=(&this->m_qclSaved, (int)&this->m_qclCurrent);
  return 1;
}

//----- (00488280) --------------------------------------------------------  // acclient.c:195966
char __thiscall UIOption_ActionKeyMap::RestoreSavedValue(UIOption_ActionKeyMap *this)
{
  CInputManager *v1; // edi@1
  UIOption_ActionKeyMap *v2; // ebx@1
  unsigned int v3; // edx@2
  unsigned int v4; // ecx@2
  ListNode<QualifiedControl> *v5; // esi@2
  ListNode<QualifiedControl> *v6; // ebp@4
  unsigned int v7; // ecx@10
  unsigned int v8; // ecx@10
  signed int v9; // edx@13
  ICIDMVtbl *v10; // eax@13
  unsigned int v11; // ebp@14
  ListNode<QualifiedControl> *i; // esi@14
  unsigned int v13; // ecx@16
  ListNode<QualifiedControl> *j; // esi@18
  signed int v15; // edx@20
  unsigned int v16; // ecx@20
  ListNode<unsigned long> *v17; // eax@21
  void *v18; // ecx@23
  ListNode<QualifiedControl> *v19; // eax@29
  void *v20; // ecx@31
  char result; // al@37
  unsigned int v22; // [sp-14h] [bp-50h]@10
  unsigned int v23; // [sp-10h] [bp-4Ch]@10
  signed int v24; // [sp-8h] [bp-44h]@10
  void *v25; // [sp-4h] [bp-40h]@2
  ListIterator<unsigned long> mapIter; // [sp+10h] [bp-2Ch]@13
  List<unsigned long> listMapIDs; // [sp+1Ch] [bp-20h]@13
  List<QualifiedControl> qclTemp; // [sp+2Ch] [bp-10h]@2

  v1 = ICIDM::s_cidm;
  v2 = this;
  if ( ICIDM::s_cidm )
  {
    v3 = this->m_idInputMap;
    v25 = &qclTemp;
    v4 = this->m_idInputAction;
    qclTemp.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
    qclTemp._head = 0;
    qclTemp._tail = 0;
    qclTemp._num_elements = 0;
    ICIDM::s_cidm->vfptr->FindKeysForAction((ICIDM *)ICIDM::s_cidm, v4, v3, &qclTemp);
    v5 = v2->m_qclCurrent._head;
    while ( v5 )
    {
      v6 = qclTemp._head;
      if ( qclTemp._head )
      {
        while ( !QualifiedControl::operator==(&v6->data, &v5->data) )
        {
          if ( v6 )
          {
            v6 = v6->next;
            if ( v6 )
              continue;
          }
          goto LABEL_11;
        }
        if ( v6 )
        {
          v7 = v5->data.m_key.m_dwKey;
          v25 = (void *)v2->m_idInputMap;
          v23 = v7;
          ((void (__thiscall *)(CInputManager *, _DWORD, _DWORD, _DWORD, void *))v1->vfptr->UnbindByKey)(
            v1,
            v7,
            v5->data.m_metamode,
            v5->data.m_activation,
            v25);
          v8 = v5->data.m_key.m_dwKey;
          v25 = (void *)v2->m_idInputMap;
          v24 = 1;
          v22 = v8;
          ((void (__thiscall *)(CInputManager *, _DWORD, _DWORD, _DWORD, signed int, void *))v1->vfptr->BindAction)(
            v1,
            v8,
            v5->data.m_metamode,
            v5->data.m_activation,
            1,
            v25);
        }
      }
LABEL_11:
      if ( v5 )
        v5 = v5->next;
    }
    v9 = v2->m_idInputMap;
    v25 = &listMapIDs;
    listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    listMapIDs._head = 0;
    listMapIDs._tail = 0;
    listMapIDs._num_elements = 0;
    v10 = v1->vfptr;
    v24 = v9;
    v10->FindConflictingInputMaps((ICIDM *)v1, v9, &listMapIDs);
    for ( mapIter._current = listMapIDs._head; mapIter._current; mapIter._current = mapIter._current->next )
    {
      v11 = mapIter._current->data;
      for ( i = v2->m_qclSaved._head; i; i = i->next )
      {
        v13 = i->data.m_key.m_dwKey;
        v25 = (void *)v11;
        v23 = v13;
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, unsigned int))v1->vfptr->UnbindByKey)(
          v1,
          v13,
          i->data.m_metamode,
          i->data.m_activation,
          v11);
      }
    }
    for ( j = v2->m_qclSaved._head; j; j = j->next )
    {
      v15 = v2->m_idInputAction;
      v25 = (void *)v2->m_idInputMap;
      v16 = j->data.m_key.m_dwKey;
      v24 = v15;
      v22 = v16;
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v1->vfptr->BindAction)(
        v1,
        v16,
        j->data.m_metamode,
        j->data.m_activation,
        v15,
        v25);
    }
    List<QualifiedControl>::operator=(&v2->m_qclCurrent, (int)&v2->m_qclSaved);
    ((void (__thiscall *)(UIOption_ActionKeyMap *))v2->vfptr[7].RecvNotice_ServerSaysMoveItem)(v2);
    v17 = listMapIDs._head;
    listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    while ( v17 )
    {
      v18 = v17;
      v17 = v17->next;
      listMapIDs._head = v17;
      if ( v17 )
      {
        v17->prev = 0;
        v17 = listMapIDs._head;
      }
      else
      {
        listMapIDs._tail = 0;
      }
      if ( v18 )
      {
        operator delete(v18);
        v17 = listMapIDs._head;
      }
      --listMapIDs._num_elements;
    }
    v19 = qclTemp._head;
    qclTemp.vfptr = (List<QualifiedControl>Vtbl *)&List<QualifiedControl>::vftable;
    while ( v19 )
    {
      v20 = v19;
      v19 = v19->next;
      qclTemp._head = v19;
      if ( v19 )
      {
        v19->prev = 0;
        v19 = qclTemp._head;
      }
      else
      {
        qclTemp._tail = 0;
      }
      if ( v20 )
      {
        operator delete(v20);
        v19 = qclTemp._head;
      }
      --qclTemp._num_elements;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);
// 7A2BE8: using guessed type int (__thiscall *List<QualifiedControl>::vftable)(void *, char);

//----- (004884F0) --------------------------------------------------------  // acclient.c:196153
char __thiscall UIOption_ActionKeyMap::RestoreDefaultValue(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1

  v1 = this;
  List<QualifiedControl>::operator=(&this->m_qclCurrent, (int)&this->m_qclDefaults);
  ((void (__thiscall *)(UIOption_ActionKeyMap *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00488520) --------------------------------------------------------  // acclient.c:196164
void __thiscall UIOption_ActionKeyMap::RefreshMappings(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1
  char *v2; // edi@1

  v1 = this;
  v2 = (char *)&this->m_qclCurrent;
  List<CInputManager::InputMapEntry>::flush(&this->m_qclCurrent);
  if ( ICIDM::s_cidm )
  {
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->FindKeysForAction)(
      v1->m_idInputAction,
      v1->m_idInputMap,
      v2);
    ((void (__thiscall *)(UIOption_ActionKeyMap *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  }
}

//----- (00488570) --------------------------------------------------------  // acclient.c:196183
void __thiscall UIOption_ActionKeyMap::RecvNotice_RefreshActionKeyMapping(UIOption_ActionKeyMap *this, QualifiedControl *_qcMapped)
{
  UIOption_ActionKeyMap *v2; // esi@1

  v2 = this;
  if ( _qcMapped->m_key.m_dwKey != -1 && _qcMapped->m_activation )
  {
    if ( List<QualifiedControl>::find(&this->m_qclCurrent, _qcMapped) )
      UIOption_ActionKeyMap::RefreshMappings(v2);
  }
}

//----- (004885A0) --------------------------------------------------------  // acclient.c:196196
void __thiscall UIOption_ActionKeyMap::RecvNotice_CloseDialog(UIOption_ActionKeyMap *this, unsigned int _context, PropertyCollection *_data)
{
  UIOption_ActionKeyMap *v3; // esi@1
  unsigned int v4; // edx@2
  HashTableData<unsigned long,BaseProperty> **v5; // eax@2
  BasePropertyValue *v6; // ecx@2
  HashTableData<unsigned long,BaseProperty> *v7; // eax@2
  bool v8; // zf@9
  _BYTE v9[12]; // ST00_12@10
  BasePropertyDesc *v10; // ecx@12
  unsigned int v11; // edx@12
  int v12; // edx@16
  BaseProperty p; // [sp+Ch] [bp-8h]@2

  v3 = this;
  if ( _context == this->m_ctxtOverwriteBindingDialog )
  {
    v4 = 0x92 % _data->m_hashProperties.m_intrusiveTable.m_numBuckets;
    v5 = _data->m_hashProperties.m_intrusiveTable.m_buckets;
    v6 = 0;
    LOBYTE(_context) = 0;
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    v7 = v5[v4];
    if ( v7 )
    {
      while ( v7->m_hashKey != 146 )
      {
        v7 = v7->m_hashNext;
        if ( !v7 )
          goto LABEL_9;
      }
      if ( v7 )
      {
        BaseProperty::operator=(&p, (int)&v7->m_data);
        v6 = p.m_pcPropertyValue;
        if ( p.m_pcPropertyValue )
        {
          ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&_context);
          v6 = p.m_pcPropertyValue;
        }
      }
    }
LABEL_9:
    v8 = (_BYTE)_context == 0;
    v3->m_ctxtOverwriteBindingDialog = 0;
    if ( !v8 )
    {
      *(_DWORD *)v9 = v3->m_qcBindingBeingChanged.m_key.m_dwKey;
      *(_QWORD *)&v9[4] = *(_QWORD *)&v3->m_qcBindingBeingChanged.m_metamode;
      UIOption_ActionKeyMap::SetBinding(v3, *(QualifiedControl *)v9, v3->m_nBindingBeingChanged);
      v6 = p.m_pcPropertyValue;
    }
    v3->m_qcBindingBeingChanged.m_key.m_dwKey = -1;
    v3->m_qcBindingBeingChanged.m_metamode = 0;
    v3->m_qcBindingBeingChanged.m_activation = 0;
    v3->m_nBindingBeingChanged = -1;
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v10 = p.m_pcPropertyDesc;
      v11 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      v6 = p.m_pcPropertyValue;
      p.m_pcPropertyDesc = 0;
    }
    if ( v6 )
    {
      v12 = v6->m_cRef - 1;
      v6->m_cRef = v12;
      if ( !v12 )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
    }
  }
  else if ( _context == this->m_ctxtCantOverwriteBindingDialog )
  {
    this->m_ctxtCantOverwriteBindingDialog = 0;
    this->m_qcBindingBeingChanged.m_key.m_dwKey = -1;
    this->m_qcBindingBeingChanged.m_metamode = 0;
    this->m_qcBindingBeingChanged.m_activation = 0;
    this->m_nBindingBeingChanged = -1;
  }
}

//----- (004886F0) --------------------------------------------------------  // acclient.c:196282
void __thiscall UIOption_ActionKeyMap::SetMouseTurningDefaults(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1
  bool v2; // zf@2
  CInputHandlerVtbl *v3; // eax@4
  AC1Legacy::PSRefBuffer<char> *v4; // ebx@4
  const char *v5; // ST00_4@4
  ClientSystem *v6; // eax@4
  CInputHandlerVtbl *v7; // edx@9
  AC1Legacy::PSRefBuffer<char> *v8; // ebx@9
  const char *v9; // ST00_4@9
  ClientSystem *v10; // eax@9
  AC1Legacy::PStringBase<char> txtmsg; // [sp+14h] [bp-14h]@4
  unsigned int id; // [sp+18h] [bp-10h]@4
  QualifiedControl mouse_turn_qc; // [sp+1Ch] [bp-Ch]@4

  v1 = this;
  if ( ICIDM::s_cidm )
  {
    v2 = this->m_idInputAction == 51;
    this->m_skipConfirmation = 1;
    if ( v2 && this->m_idInputMap == 5 )
    {
      v3 = this->vfptr;
      mouse_turn_qc.m_key.m_dwKey = 524545;
      mouse_turn_qc.m_metamode = 0;
      mouse_turn_qc.m_activation = 2;
      id = 0;
      v3->KeyHitHandler((CInputHandler *)&this->vfptr, &mouse_turn_qc, &id);
      v1->m_qcBindingBeingChanged.m_key.m_dwKey = -1;
      v1->m_qcBindingBeingChanged.m_metamode = 0;
      v1->m_qcBindingBeingChanged.m_activation = 0;
      v1->m_nBindingBeingChanged = -1;
      txtmsg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::sprintf(
        &txtmsg,
        "The key for Camera Zoom In has been changed to the mouse wheel up.");
      v4 = txtmsg.m_buffer;
      v5 = txtmsg.m_buffer->m_data;
      v6 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v6, v5, 7u, 1, 0);
      if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
      {
        if ( v4 )
          v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
      }
    }
    if ( v1->m_idInputAction == 52 && v1->m_idInputMap == 5 )
    {
      v7 = v1->vfptr;
      mouse_turn_qc.m_key.m_dwKey = 524801;
      mouse_turn_qc.m_metamode = 0;
      mouse_turn_qc.m_activation = 2;
      id = 0;
      v7->KeyHitHandler((CInputHandler *)&v1->vfptr, &mouse_turn_qc, &id);
      v1->m_qcBindingBeingChanged.m_key.m_dwKey = -1;
      v1->m_qcBindingBeingChanged.m_metamode = 0;
      v1->m_qcBindingBeingChanged.m_activation = 0;
      v1->m_nBindingBeingChanged = -1;
      txtmsg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::sprintf(
        &txtmsg,
        "The key for Camera Zoom Out has been changed to the mouse wheel down.");
      v8 = txtmsg.m_buffer;
      v9 = txtmsg.m_buffer->m_data;
      v10 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v10, v9, 7u, 1, 0);
      if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) )
      {
        if ( v8 )
          v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
      }
    }
    v1->m_skipConfirmation = 0;
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004888A0) --------------------------------------------------------  // acclient.c:196363
UIOption_ActionKeyMap *__thiscall UIOption_ActionKeyMap::vector_deleting_destructor(UIOption_ActionKeyMap *this, unsigned int a2)
{
  UIOption_ActionKeyMap *v2; // esi@1

  v2 = this;
  UIOption_ActionKeyMap::~UIOption_ActionKeyMap(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004888C0) --------------------------------------------------------  // acclient.c:196375
void __cdecl UIOption_ActionKeyMap::Register()
{
  UIElement::RegisterElementClass(0x10000034u, UIOption_ActionKeyMap::Create);
}

//----- (004888E0) --------------------------------------------------------  // acclient.c:196381
void __thiscall UIOption_ActionKeyMap::Init(UIOption_ActionKeyMap *this, unsigned int i_idAction, unsigned int i_idInputMap, StringInfo *i_siName, StringInfo *i_siDescription, List<QualifiedControl> *i_qclDefaults)
{
  unsigned int v6; // eax@1
  UIOption_ActionKeyMap *v7; // esi@1
  char *v8; // edi@1
  StringInfo *v9; // edi@3
  IInputActionCallbackVtbl *v10; // eax@5
  int v11; // esi@5
  unsigned int v12; // esi@6
  int v13; // edx@8
  StringInfo v14; // [sp-88h] [bp-98h]@5
  signed int v15; // [sp+4h] [bp-Ch]@8

  v6 = i_idAction;
  v7 = this;
  this->m_idInputMap = i_idInputMap;
  v8 = (char *)&this->m_qclCurrent;
  this->m_idInputAction = v6;
  List<CInputManager::InputMapEntry>::flush(&this->m_qclCurrent);
  if ( ICIDM::s_cidm )
  {
    ((void (__stdcall *)(unsigned int, unsigned int, char *))ICIDM::s_cidm->vfptr->FindKeysForAction)(
      v7->m_idInputAction,
      v7->m_idInputMap,
      v8);
    ((void (__thiscall *)(UIOption_ActionKeyMap *))v7->vfptr[7].RecvNotice_ServerSaysMoveItem)(v7);
  }
  List<QualifiedControl>::operator=(&v7->m_qclDefaults, (int)i_qclDefaults);
  ((void (__thiscall *)(UIOption_ActionKeyMap *, StringInfo *))v7->vfptr[7].RecvNotice_ItemAttributesChanged)(
    v7,
    i_siName);
  v9 = i_siDescription;
  if ( StringInfo::IsValid(i_siDescription, 1) )
  {
    StringInfo::GetString(v9, (PStringBase<unsigned short> *)&i_idAction, 0);
    if ( *(_DWORD *)(i_idAction - 4) != 1 )
    {
      v10 = v7->vfptr;
      v11 = (int)&v7->vfptr;
      ((void (__thiscall *)(int, signed int))v10[22].OnLoseFocus)(v11, 1);
      StringInfo::StringInfo(&v14, v9);
      UIElement::SetAttribute_StringInfo((UIElement *)v11, 0x49u, v14);
      *(_DWORD *)(v11 + 164) |= 0x20u;
    }
    v12 = i_idAction - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_idAction - 20 + 4)) )
    {
      if ( v12 )
      {
        v13 = *(_DWORD *)v12;
        v15 = 1;
        (*(void (__thiscall **)(unsigned int, signed int))v13)(v12, 1);
      }
    }
  }
}

//----- (004889D0) --------------------------------------------------------  // acclient.c:196439
void __thiscall UIOption_ActionKeyMap::ListenToGlobalMessage(UIOption_ActionKeyMap *this, unsigned int i_messageID, int i_data_int)
{
  UIElement_Text *v3; // esi@1

  v3 = (UIElement_Text *)this;
  if ( i_messageID == 12 )
    UIOption_ActionKeyMap::SetMouseTurningDefaults((UIOption_ActionKeyMap *)((char *)this - 32));
  UIElement_Text::ListenToGlobalMessage(v3, i_messageID, i_data_int);
}

//----- (00488A00) --------------------------------------------------------  // acclient.c:196450
bool __thiscall UIOption_ActionKeyMap::OpenMapWarnDialog(UIOption_ActionKeyMap *this, StringInfo *_siMsg)
{
  UIOption_ActionKeyMap *v2; // esi@1
  unsigned __int32 v3; // eax@11
  bool v4; // bl@11
  BasePropertyDesc *v5; // ecx@12
  unsigned int v6; // edi@12
  BasePropertyValue *v7; // ecx@16
  unsigned int v8; // edx@16
  bool result; // al@19
  BaseProperty p; // [sp+14h] [bp-84h]@3
  unsigned int _key; // [sp+1Ch] [bp-7Ch]@5
  PropertyCollection pc; // [sp+20h] [bp-78h]@3

  v2 = this;
  if ( !StringInfo::IsValid(_siMsg, 1) || v2->m_ctxtDialog )
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
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(2);
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
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(268435457);
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
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(_siMsg);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v3 = DialogFactory::MakeDialogInCurrentUI(&pc);
    v2->m_ctxtDialog = v3;
    v4 = v3 != 0;
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v5 = p.m_pcPropertyDesc;
      v6 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v7 = p.m_pcPropertyValue;
      v8 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    result = v4;
  }
  return result;
}

//----- (00488BF0) --------------------------------------------------------  // acclient.c:196546
bool __thiscall UIOption_ActionKeyMap::OpenOverwriteBindingDialog(UIOption_ActionKeyMap *this, SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *i_aConflictingBindings)
{
  UIOption_ActionKeyMap *v2; // ebp@1
  unsigned int v3; // eax@1
  CInputManager *v4; // esi@2
  ActionMap *v5; // ebx@3
  char *v6; // esi@4
  bool v7; // zf@5
  SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> *v8; // edi@12
  unsigned int v9; // esi@13
  unsigned int v10; // edi@13
  void *v12; // ecx@15
  void *v13; // ecx@15
  unsigned int v14; // ecx@16
  int v15; // eax@19
  unsigned int v16; // ebp@19
  unsigned int v17; // edi@19
  ICIDMVtbl *v18; // eax@20
  PStringBase<char> *v19; // eax@20
  int v20; // edi@20
  PSRefBufferCharData<unsigned short> *v21; // edi@23
  PStringBase<unsigned short> *v22; // eax@23
  PSRefBufferCharData<char> *v23; // ebp@23
  int v24; // eax@23
  int v25; // ebp@25
  char *v26; // ebp@28
  int v27; // edi@31
  char *v28; // edi@34
  char *v29; // edi@37
  bool v30; // cf@40
  char *v31; // esi@42
  ReferenceCountTemplate<1048576,1>Vtbl *v32; // eax@46
  unsigned __int32 v33; // eax@47
  bool v34; // bl@47
  BasePropertyDesc *v35; // ecx@48
  unsigned int v36; // edx@48
  ReferenceCountTemplate<1048576,1>Vtbl *v37; // eax@49
  BasePropertyValue *v38; // ecx@52
  unsigned int v39; // esi@52
  ReferenceCountTemplate<1048576,1>Vtbl *v40; // edx@53
  char *v41; // esi@55
  int v42; // edx@57
  char *v43; // esi@59
  char *v44; // esi@62
  char *v45; // esi@65
  void *v46; // [sp+2Ch] [bp-1FCh]@15
  BaseProperty p; // [sp+40h] [bp-1E8h]@6
  PStringBase<unsigned short> strName; // [sp+48h] [bp-1E0h]@13
  PStringBase<char> strConflictingBindings; // [sp+4Ch] [bp-1DCh]@13
  unsigned int i; // [sp+50h] [bp-1D8h]@8
  PStringBase<char> strKey; // [sp+54h] [bp-1D4h]@3
  PStringBase<unsigned short> strDescription; // [sp+58h] [bp-1D0h]@19
  unsigned int v53; // [sp+5Ch] [bp-1CCh]@17
  PStringBase<unsigned short> result; // [sp+60h] [bp-1C8h]@23
  UIOption_ActionKeyMap *v55; // [sp+64h] [bp-1C4h]@1
  ICIDM *inputMgr; // [sp+68h] [bp-1C0h]@2
  int v57; // [sp+6Ch] [bp-1BCh]@20
  ActionMap *pActionMap; // [sp+70h] [bp-1B8h]@3
  PStringBase<char> v59; // [sp+74h] [bp-1B4h]@23
  PStringBase<unsigned short> strConflictingKey; // [sp+78h] [bp-1B0h]@20
  _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > conflict; // [sp+7Ch] [bp-1ACh]@19
  StringInfo v62; // [sp+90h] [bp-198h]@12
  PropertyCollection pc; // [sp+120h] [bp-108h]@6
  StringInfo siConflictingBinding; // [sp+198h] [bp-90h]@23

  v2 = this;
  v3 = this->m_ctxtOverwriteBindingDialog;
  v55 = this;
  if ( v3 )
    return 0;
  v4 = ICIDM::s_cidm;
  inputMgr = (ICIDM *)ICIDM::s_cidm;
  if ( !ICIDM::s_cidm )
    return 0;
  (*(void (__thiscall **)(CInputManager *, PStringBase<char> *, QualifiedControl *))((void (__thiscall **)(_DWORD, _DWORD, _DWORD))&ICIDM::s_cidm->vfptr->OnUIElementActivationChanging
                                                                                   + 1))(
    ICIDM::s_cidm,
    &strKey,
    &this->m_qcBindingBeingChanged);
  v5 = v4->vfptr->GetActionMap((ICIDM *)v4);
  pActionMap = v5;
  if ( !v5 )
  {
    v6 = &strKey.m_charbuffer[-2].m_data[12];
    if ( InterlockedDecrement((volatile LONG *)&strKey.m_charbuffer[-1]) )
      return 0;
    v7 = v6 == 0;
LABEL_70:
    if ( !v7 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    return 0;
  }
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  i = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &i,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC3u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(268435457);
  }
  i = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &i,
    &p);
  BaseProperty::SetPropertyName(&p, 0xACu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
  }
  i = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &i,
    &p);
  StringInfo::StringInfo(&v62);
  v8 = i_aConflictingBindings;
  if ( i_aConflictingBindings->m_num == 1 )
  {
    v9 = i_aConflictingBindings->m_data->first;
    v10 = i_aConflictingBindings->m_data->second.second;
    strName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    strConflictingBindings.m_charbuffer = (PSRefBufferCharData<char> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( !ActionMap::GetDescripValues(v5, v10, v9, &strName, (PStringBase<unsigned short> *)&strConflictingBindings) )
    {
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strConflictingBindings);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strName);
      StringInfo::~StringInfo(&v62);
      BaseProperty::~BaseProperty(&p);
      PropertyCollection::~PropertyCollection(&pc);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strKey);
      return 0;
    }
    StringInfo::SetStringIDandTableEnum(&v62, ID_ActionKeyMap_OverwriteExistingBinding, 268435460);
    v46 = v12;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v46,
      &strKey);
    StringInfo::AddVariable_String(&v62, KEY, (PStringBase<char>)v46);
    v46 = v13;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v46,
      (PStringBase<char> *)&strName);
    StringInfo::AddVariable_String(&v62, ACTION, (PStringBase<unsigned short>)v46);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strConflictingBindings);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strName);
    v2 = v55;
  }
  else
  {
    strConflictingBindings.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v14 = i_aConflictingBindings->m_num;
    i = 0;
    if ( v14 )
    {
      v53 = 0;
      while ( 1 )
      {
        v15 = (int)&v8->m_data[v53 / 0x14];
        conflict.first = v8->m_data[v53 / 0x14].first;
        conflict.second.first.m_key.m_dwKey = *(_DWORD *)(v15 + 4);
        conflict.second.first.m_metamode = *(_DWORD *)(v15 + 8);
        conflict.second.first.m_activation = *(_DWORD *)(v15 + 12);
        conflict.second.second = *(_DWORD *)(v15 + 16);
        v16 = conflict.second.second;
        strName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
        v17 = conflict.first;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        strDescription.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        if ( !ActionMap::GetDescripValues(v5, v16, v17, &strName, &strDescription) )
          break;
        v18 = inputMgr->vfptr;
        v46 = 0;
        v19 = (PStringBase<char> *)(*((int (__stdcall **)(int *, _STL::pair<QualifiedControl,unsigned long> *))&v18->OnUIElementActivationChanging
                                    + 1))(
                                     &v57,
                                     &conflict.second);
        PStringBase<char>::to_wpstring(v19, &strConflictingKey, 0);
        v20 = v57 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v57 - 20 + 4)) && v20 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
        StringInfo::StringInfo(&siConflictingBinding);
        StringInfo::SetStringIDandTableEnum(&siConflictingBinding, ID_ActionKeyMap_Binding, 268435460);
        v46 = strName.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&strName.m_charbuffer[-1].m_data[8]);
        StringInfo::AddVariable_String(&siConflictingBinding, ACTION, (PStringBase<unsigned short>)v46);
        v21 = strConflictingKey.m_charbuffer;
        v46 = strConflictingKey.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&strConflictingKey.m_charbuffer[-1].m_data[8]);
        StringInfo::AddVariable_String(&siConflictingBinding, KEY, (PStringBase<unsigned short>)v46);
        v22 = StringInfo::GetString(&siConflictingBinding, &result, 0);
        PStringBase<unsigned short>::to_spstring(v22, &v59, 0);
        v23 = v59.m_charbuffer;
        v24 = *(_DWORD *)&v59.m_charbuffer[-1].m_data[12];
        if ( v24 != 1 )
          PStringBase<char>::append_n_chars(&strConflictingBindings, v59.m_charbuffer->m_data, v24 - 1);
        v25 = (int)&v23[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v25 + 4)) && v25 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
        v26 = (char *)&result.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v26 )
          (**(void (__thiscall ***)(char *, signed int))v26)(v26, 1);
        PStringBase<char>::append_n_chars(&strConflictingBindings, "\n", strlen("\n"));
        StringInfo::~StringInfo(&siConflictingBinding);
        v27 = (int)&v21[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)(v27 + 4)) && v27 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
        v28 = (char *)&strDescription.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&strDescription.m_charbuffer[-1].m_data[8]) && v28 )
          (**(void (__thiscall ***)(char *, signed int))v28)(v28, 1);
        v29 = (char *)&strName.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1].m_data[8]) && v29 )
          (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
        v30 = i++ + 1 < i_aConflictingBindings->m_num;
        v53 += 20;
        if ( !v30 )
        {
          v2 = v55;
          goto LABEL_42;
        }
        v5 = pActionMap;
        v8 = i_aConflictingBindings;
      }
      v43 = (char *)&strDescription.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strDescription.m_charbuffer[-1].m_data[8]) && v43 )
        (**(void (__thiscall ***)(char *, signed int))v43)(v43, 1);
      v44 = (char *)&strName.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1].m_data[8]) && v44 )
        (**(void (__thiscall ***)(char *, signed int))v44)(v44, 1);
      v45 = &strConflictingBindings.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strConflictingBindings.m_charbuffer[-1]) && v45 )
        (**(void (__thiscall ***)(char *, signed int))v45)(v45, 1);
      StringInfo::~StringInfo(&v62);
      BaseProperty::~BaseProperty(&p);
      PropertyCollection::~PropertyCollection(&pc);
      v6 = &strKey.m_charbuffer[-2].m_data[12];
      if ( InterlockedDecrement((volatile LONG *)&strKey.m_charbuffer[-1]) )
        return 0;
      v7 = v6 == 0;
      goto LABEL_70;
    }
LABEL_42:
    StringInfo::SetStringIDandTableEnum(&v62, ID_ActionKeyMap_OverwriteExistingBindings, 268435460);
    v46 = strKey.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strKey.m_charbuffer[-1]);
    StringInfo::AddVariable_String(&v62, KEY, (PStringBase<char>)v46);
    v46 = strConflictingBindings.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strConflictingBindings.m_charbuffer[-1]);
    StringInfo::AddVariable_String(&v62, BINDINGS, (PStringBase<char>)v46);
    v31 = &strConflictingBindings.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strConflictingBindings.m_charbuffer[-1]) && v31 )
      (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
  }
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    v32 = p.m_pcPropertyValue->vfptr;
    v46 = &v62;
    ((void (__stdcall *)(StringInfo *))v32[49].__vecDelDtor)(&v62);
  }
  result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&result,
    &p);
  v33 = DialogFactory::MakeDialogInCurrentUI(&pc);
  v2->m_ctxtOverwriteBindingDialog = v33;
  v34 = v33 != 0;
  StringInfo::~StringInfo(&v62);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v35 = p.m_pcPropertyDesc;
    v36 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v36;
    if ( !v36 )
    {
      v37 = v35->vfptr;
      v46 = (void *)1;
      ((void (__stdcall *)(signed int))v37->__vecDelDtor)(1);
    }
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v38 = p.m_pcPropertyValue;
    v39 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v39;
    if ( !v39 )
    {
      v40 = v38->vfptr;
      v46 = (void *)1;
      ((void (__stdcall *)(signed int))v40->__vecDelDtor)(1);
    }
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  v41 = &strKey.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strKey.m_charbuffer[-1]) && v41 )
  {
    v42 = *(_DWORD *)v41;
    v46 = (void *)1;
    (*(void (__thiscall **)(char *, signed int))v42)(v41, 1);
  }
  return v34;
}

//----- (00489300) --------------------------------------------------------  // acclient.c:196871
bool __thiscall UIOption_ActionKeyMap::OpenCantOverwriteBindingDialog(UIOption_ActionKeyMap *this)
{
  UIOption_ActionKeyMap *v1; // esi@1
  bool result; // al@3
  PStringBase<char> v3; // ST08_4@10
  unsigned __int32 v4; // eax@12
  bool v5; // bl@12
  BasePropertyDesc *v6; // ecx@13
  unsigned int v7; // esi@13
  BasePropertyValue *v8; // ecx@17
  unsigned int v9; // edx@17
  char *v10; // esi@20
  BaseProperty p; // [sp+1Ch] [bp-118h]@4
  unsigned int _key; // [sp+24h] [bp-110h]@6
  PStringBase<char> strKey; // [sp+28h] [bp-10Ch]@4
  PropertyCollection pc; // [sp+2Ch] [bp-108h]@4
  StringInfo v15; // [sp+A4h] [bp-90h]@10

  v1 = this;
  if ( !this->m_ctxtCantOverwriteBindingDialog && ICIDM::s_cidm )
  {
    (*(void (__stdcall **)(PStringBase<char> *, QualifiedControl *))((void (__stdcall **)(_DWORD, _DWORD))&ICIDM::s_cidm->vfptr->OnUIElementActivationChanging
                                                                   + 1))(
      &strKey,
      &this->m_qcBindingBeingChanged);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(3);
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
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(268435457);
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
      ((void (__stdcall *)(signed int))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    StringInfo::StringInfo(&v15);
    StringInfo::SetStringIDandTableEnum(&v15, ID_ActionKeyMap_NonUserBindableBinding, 268435460);
    v3.m_charbuffer = strKey.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strKey.m_charbuffer[-1]);
    StringInfo::AddVariable_String(&v15, KEY, v3);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(StringInfo *))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v15);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v4 = DialogFactory::MakeDialogInCurrentUI(&pc);
    v1->m_ctxtCantOverwriteBindingDialog = v4;
    v5 = v4 != 0;
    StringInfo::~StringInfo(&v15);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v6 = p.m_pcPropertyDesc;
      v7 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v8 = p.m_pcPropertyValue;
      v9 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    v10 = &strKey.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strKey.m_charbuffer[-1]) )
    {
      if ( v10 )
        (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    }
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00489570) --------------------------------------------------------  // acclient.c:196987
char __thiscall UIOption_ActionKeyMap::KeyHitHandler(UIOption_ActionKeyMap *this, QualifiedControl *i_key, unsigned int *o_idAction)
{
  QualifiedControl *v3; // esi@1
  bool v4; // zf@1
  CInputManager *v5; // ebp@2
  int v6; // eax@3
  int v7; // ebx@3
  int v8; // edi@3
  ICIDMVtbl *v9; // edx@8
  UIOption_ActionKeyMap *v10; // eax@10
  int v11; // ebx@10
  DLListData *v12; // esi@10
  int v13; // edi@10
  unsigned int v14; // eax@15
  unsigned int v15; // eax@16
  ICIDMVtbl *v16; // edx@16
  int v17; // esi@18
  unsigned int v18; // eax@20
  unsigned int v19; // eax@21
  unsigned int v20; // eax@28
  unsigned int j; // esi@29
  UIOption_ActionKeyMap *v22; // esi@34
  ActionMap *v23; // edi@36
  unsigned int v25; // ebx@39
  int v26; // esi@40
  int v27; // ecx@49
  _BYTE v28[12]; // ST00_12@49
  void *v29; // [sp+Ch] [bp-68h]@3
  UIOption_ActionKeyMap *v30; // [sp+20h] [bp-54h]@1
  unsigned int i; // [sp+24h] [bp-50h]@17
  unsigned int mapID; // [sp+28h] [bp-4Ch]@16
  SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> >,1> aConflictingMappings; // [sp+2Ch] [bp-48h]@15
  SmartArray<_STL::pair<QualifiedControl,unsigned long>,1> aCurMappings; // [sp+38h] [bp-3Ch]@16
  ListIterator<unsigned long> mapIter; // [sp+44h] [bp-30h]@15
  List<unsigned long> listMapIDs; // [sp+50h] [bp-24h]@15
  _STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long> > conflict; // [sp+60h] [bp-14h]@19
  QualifiedControl *i_keya; // [sp+78h] [bp+4h]@8

  v3 = i_key;
  v4 = (i_key->m_activation & 0x81) == 0;
  v30 = this;
  if ( !v4 )
    return 1;
  v5 = ICIDM::s_cidm;
  if ( !ICIDM::s_cidm )
    return 1;
  v29 = this;
  v6 = ((int (__thiscall *)(CInputManager *, unsigned int))ICIDM::s_cidm->vfptr->GetDeviceTypeFromKey)(
         ICIDM::s_cidm,
         i_key->m_key.m_dwKey);
  v7 = *((_WORD *)&i_key->m_key.1 + 1);
  v8 = v6;
  if ( v6 == 2 && (!*((_WORD *)&i_key->m_key.1 + 1) || v7 == 4 || v7 == 12 && !i_key->m_metamode) )
    return 1;
  v9 = v5->vfptr;
  v29 = (void *)32;
  v9->UnregisterInputHandler(
    (ICIDM *)v5,
    (CInputHandler *)(v30 != (UIOption_ActionKeyMap *)1576 ? (unsigned int)v30 : 0),
    32u);
  i_keya = (QualifiedControl *)&v30[-1].m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[7];
  UIOption_ActionKeyMap::CloseMapWarnDialog((UIOption_ActionKeyMap *)((char *)v30 - 1576));
  if ( v8 == 1 && v7 == 1 )
    return 1;
  v10 = v30;
  v11 = (int)&v30->m_mouseDownTable.m_intrusiveTable;
  *(_DWORD *)v11 = v3->m_key.m_dwKey;
  *(_DWORD *)(v11 + 4) = v3->m_metamode;
  *(_DWORD *)(v11 + 8) = v3->m_activation;
  v10->m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[1] = (HashSetData<unsigned long> *)3;
  v12 = v10->m_children.m_ihlIntrusive.m_list.head_;
  v13 = 0;
  if ( v12 )
  {
    do
    {
      if ( (unsigned __int8)QualifiedControl::IsExactlyEqual((QualifiedControl *)v12, (QualifiedControl *)v11) )
        return 1;
      if ( !v12 )
        break;
      v12 = v12[1].dllist_prev;
    }
    while ( v12 );
    v10 = v30;
  }
  v14 = (unsigned int)v10->m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[17];
  v29 = &listMapIDs;
  aConflictingMappings.m_data = 0;
  aConflictingMappings.m_sizeAndDeallocate = 0;
  aConflictingMappings.m_num = 0;
  listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  listMapIDs._head = 0;
  listMapIDs._tail = 0;
  listMapIDs._num_elements = 0;
  v5->vfptr->FindConflictingInputMaps((ICIDM *)v5, v14, &listMapIDs);
  mapIter._current = listMapIDs._head;
  if ( listMapIDs._head )
  {
    while ( 1 )
    {
      v15 = mapIter._current->data;
      v16 = v5->vfptr;
      v29 = &aCurMappings;
      mapID = v15;
      aCurMappings.m_data = 0;
      aCurMappings.m_sizeAndDeallocate = 0;
      aCurMappings.m_num = 0;
      if ( v16->FindConflictingControls((ICIDM *)v5, (QualifiedControl *)v11, v15, &aCurMappings) )
      {
        v5->vfptr->GetActionMap((ICIDM *)v5);
        i = 0;
        if ( aCurMappings.m_num > 0 )
          break;
      }
LABEL_25:
      if ( (aCurMappings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](aCurMappings.m_data);
      mapIter._current = mapIter._current->next;
      if ( !mapIter._current )
        goto LABEL_28;
    }
    v17 = 0;
    while ( 1 )
    {
      conflict.first = mapID;
      conflict.second.first.m_key.m_dwKey = aCurMappings.m_data[v17].first.m_key.m_dwKey;
      conflict.second.first.m_metamode = aCurMappings.m_data[v17].first.m_metamode;
      conflict.second.first.m_activation = aCurMappings.m_data[v17].first.m_activation;
      conflict.second.second = aCurMappings.m_data[v17].second;
      if ( SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::WhatNum(
             &aConflictingMappings,
             &conflict) == -1 )
      {
        v18 = aConflictingMappings.m_num;
        if ( aConflictingMappings.m_num < (aConflictingMappings.m_sizeAndDeallocate & 0x7FFFFFFF) )
          goto LABEL_23;
        v19 = SmartArray<UIChildFramework *,1>::get_new_size((aConflictingMappings.m_sizeAndDeallocate & 0x7FFFFFFF) + 1);
        if ( SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::grow(
               &aConflictingMappings,
               v19) )
          break;
      }
LABEL_24:
      ++v17;
      ++i;
      if ( i >= aCurMappings.m_num )
        goto LABEL_25;
    }
    v18 = aConflictingMappings.m_num;
LABEL_23:
    aConflictingMappings.m_data[v18] = conflict;
    ++aConflictingMappings.m_num;
    goto LABEL_24;
  }
LABEL_28:
  v20 = aConflictingMappings.m_num;
  if ( !aConflictingMappings.m_num )
  {
    v22 = v30;
LABEL_49:
    v27 = *(_DWORD *)v11;
    v29 = v22->m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[2];
    *(_DWORD *)v28 = v27;
    *(_QWORD *)&v28[4] = *(_QWORD *)(v11 + 4);
    UIOption_ActionKeyMap::SetBinding((UIOption_ActionKeyMap *)i_keya, *(QualifiedControl *)v28, (int)v29);
    *(_DWORD *)v11 = -1;
    *(_DWORD *)(v11 + 4) = 0;
    *(_DWORD *)(v11 + 8) = 0;
    v22->m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[2] = (HashSetData<unsigned long> *)-1;
    listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
    if ( (aConflictingMappings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](aConflictingMappings.m_data);
    return 1;
  }
  for ( j = 0; j < aConflictingMappings.m_num; v20 = aConflictingMappings.m_num )
  {
    if ( aConflictingMappings.m_data[v13].second.second == 1 )
    {
      SmartArray<_STL::pair<unsigned long,_STL::pair<QualifiedControl,unsigned long>>,1>::RemoveUnOrderedByIndex(
        &aConflictingMappings,
        j);
    }
    else
    {
      ++j;
      ++v13;
    }
  }
  v22 = v30;
  if ( v30->m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[6] || v20 <= 0 )
    goto LABEL_49;
  v23 = v5->vfptr->GetActionMap((ICIDM *)v5);
  if ( !v23 )
  {
    listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
    if ( (aConflictingMappings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      operator delete[](aConflictingMappings.m_data);
      return 0;
    }
    return 0;
  }
  v25 = 0;
  if ( aConflictingMappings.m_num )
  {
    v26 = 0;
    while ( ActionMap::IsUserBindable(
              v23,
              aConflictingMappings.m_data[v26].second.second,
              aConflictingMappings.m_data[v26].first) )
    {
      ++v25;
      ++v26;
      if ( v25 >= aConflictingMappings.m_num )
        goto LABEL_43;
    }
    UIOption_ActionKeyMap::OpenCantOverwriteBindingDialog((UIOption_ActionKeyMap *)i_keya);
    listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
    List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
    if ( (aConflictingMappings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](aConflictingMappings.m_data);
    return 0;
  }
LABEL_43:
  UIOption_ActionKeyMap::OpenOverwriteBindingDialog((UIOption_ActionKeyMap *)i_keya, &aConflictingMappings);
  listMapIDs.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&listMapIDs);
  if ( (aConflictingMappings.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    operator delete[](aConflictingMappings.m_data);
    return 1;
  }
  return 1;
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);

//----- (004899D0) --------------------------------------------------------  // acclient.c:197226
bool __thiscall UIOption_ActionKeyMap::InitiateBinding(UIOption_ActionKeyMap *this, int i_nBindingNumber)
{
  UIOption_ActionKeyMap *v2; // esi@1
  unsigned int v3; // eax@1
  PSRefBufferCharData<unsigned short> *v4; // ecx@1
  bool v5; // bl@1
  ICIDMVtbl *v6; // eax@3
  PStringBase<unsigned short> v8; // [sp-4h] [bp-9Ch]@1
  StringInfo info; // [sp+8h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&info);
  v3 = compute_str_hash("ID_ActionKeyMap_MapInstructions");
  StringInfo::SetStringIDandTableEnum(&info, v3, 268435460);
  v8.m_charbuffer = v4;
  UIElement_Text::GetText((UIElement_Text *)&v2->vfptr, &v8);
  StringInfo::AddVariable_String(&info, ACTION, v8);
  v2->m_nBindingBeingChanged = i_nBindingNumber;
  v5 = UIOption_ActionKeyMap::OpenMapWarnDialog(v2, &info);
  if ( !v5 )
    goto LABEL_4;
  if ( ICIDM::s_cidm )
  {
    v6 = ICIDM::s_cidm->vfptr;
    v8.m_charbuffer = (PSRefBufferCharData<unsigned short> *)32;
    ((void (__stdcall *)(int, signed int))v6->RegisterInputHandler)(&v2->vfptr, 32);
LABEL_4:
    StringInfo::~StringInfo(&info);
    return v5;
  }
  StringInfo::~StringInfo(&info);
  return 0;
}

//----- (00489A80) --------------------------------------------------------  // acclient.c:197261
int __thiscall UIOption_ActionKeyMap::ListenToElementMessage(UIOption_ActionKeyMap *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebx@1
  unsigned int v3; // eax@1
  UIOption_ActionKeyMap *v4; // esi@1
  UIElement *v5; // edi@3
  int v7; // edx@5
  int v8; // eax@5
  int v9; // ecx@6
  int v10; // edi@14
  int v11; // eax@14
  int v12; // edx@15

  v2 = i_rMsg;
  v3 = i_rMsg->idMessage;
  v4 = this;
  if ( v3 != 1 )
  {
    if ( v3 == 25 && !DialogFactory::IsDialogOpen(0x10000001u) && i_rMsg->dwParam1 == 8 )
    {
      v10 = v4->m_lastCursor.m_y1;
      v11 = 0;
      if ( v10 )
      {
        v12 = v4->m_lastCursor.m_y0;
        while ( i_rMsg->pElement != *(UIElement **)v12
             || *(_DWORD *)(*(_DWORD *)v12 + 1024) == 13
             || v11 >= v4->m_qclDefaults._num_elements )
        {
          ++v11;
          v12 += 4;
          if ( v11 >= (unsigned int)v10 )
            return UIElement_Text::ListenToElementMessage((UIElement_Text *)v4, i_rMsg);
        }
        UIOption_ActionKeyMap::EraseBinding((UIOption_ActionKeyMap *)((char *)v4 - 32), v11);
        v2 = i_rMsg;
      }
    }
    return UIElement_Text::ListenToElementMessage((UIElement_Text *)v4, v2);
  }
  if ( DialogFactory::IsDialogOpen(0x10000001u) )
    return UIElement_Text::ListenToElementMessage((UIElement_Text *)v4, v2);
  v5 = i_rMsg->pElement;
  if ( v5 == (UIElement *)v4->m_lastCursor.m_x0 )
  {
    UIOption_ActionKeyMap::ClearAllBindings((UIOption_ActionKeyMap *)((char *)v4 - 32));
    return UIElement_Text::ListenToElementMessage((UIElement_Text *)v4, i_rMsg);
  }
  v7 = v4->m_lastCursor.m_y1;
  v8 = 0;
  if ( !v7 )
    return UIElement_Text::ListenToElementMessage((UIElement_Text *)v4, v2);
  v9 = v4->m_lastCursor.m_y0;
  while ( v5 != *(UIElement **)v9 )
  {
    ++v8;
    v9 += 4;
    if ( v8 >= (unsigned int)v7 )
      return UIElement_Text::ListenToElementMessage((UIElement_Text *)v4, i_rMsg);
  }
  UIOption_ActionKeyMap::InitiateBinding((UIOption_ActionKeyMap *)((char *)v4 - 32), v8);
  return UIElement_Text::ListenToElementMessage((UIElement_Text *)v4, i_rMsg);
}

//----- (006ED760) --------------------------------------------------------  // acclient.c:769339
void _E91_50()
{
  outside_val_42 = 1000.0 + 1.0;
}

//----- (006ED780) --------------------------------------------------------  // acclient.c:769345
void _E93_26()
{
  block_length_42 = 24.0 * 8.0;
}

//----- (006ED7A0) --------------------------------------------------------  // acclient.c:769351
void _E95_26()
{
  half_square_length_42 = 24.0 * 0.5;
}

//----- (006ED7C0) --------------------------------------------------------  // acclient.c:769357
int _E97_51()
{
  return atexit(_E98_63);
}

//----- (006ED7D0) --------------------------------------------------------  // acclient.c:769363
int _E100_44()
{
  return atexit(_E101_81);
}

//----- (006ED7E0) --------------------------------------------------------  // acclient.c:769369
int _E103_36()
{
  return atexit(_E104_51);
}

//----- (006ED7F0) --------------------------------------------------------  // acclient.c:769375
void _E106_27()
{
  DEFAULT_VIEW_RADIUS_20 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006ED810) --------------------------------------------------------  // acclient.c:769381
void _E108_18()
{
  MIN_QUANTUM_20 = 1.0 / 30.0;
}

//----- (006ED830) --------------------------------------------------------  // acclient.c:769387
void _E110_9()
{
  MAX_QUANTUM_20 = 1.0 / 5.0;
}

//----- (006ED850) --------------------------------------------------------  // acclient.c:769393
void _E112_23()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_55, PFID_A8R8G8B8);
}

//----- (006ED860) --------------------------------------------------------  // acclient.c:769399
void _E115_15()
{
  LOWEST_DATA_RATE_63 = 1024;
}

//----- (006ED870) --------------------------------------------------------  // acclient.c:769405
void _E117_13()
{
  HIGHEST_DATA_RATE_63 = 0x7FFF;
}

//----- (006ED880) --------------------------------------------------------  // acclient.c:769411
int _E119_2()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_63;
  INITIAL_MAX_DATA_RATE_11 = LOWEST_DATA_RATE_63;
  return result;
}

//----- (006ED890) --------------------------------------------------------  // acclient.c:769421
int _E121_23()
{
  return atexit(_E122_60);
}

//----- (006ED8A0) --------------------------------------------------------  // acclient.c:769427
unsigned int _E124_21()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_Binding");
  ID_ActionKeyMap_Binding = result;
  return result;
}

//----- (006ED8C0) --------------------------------------------------------  // acclient.c:769437
unsigned int _E126_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_ButtonLabel");
  ID_ActionKeyMap_ButtonLabel = result;
  return result;
}

//----- (006ED8E0) --------------------------------------------------------  // acclient.c:769447
unsigned int _E128_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_MapInstructions");
  ID_ActionKeyMap_MapInstructions = result;
  return result;
}

//----- (006ED900) --------------------------------------------------------  // acclient.c:769457
unsigned int _E130_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_NonUserBindableBinding");
  ID_ActionKeyMap_NonUserBindableBinding = result;
  return result;
}

//----- (006ED920) --------------------------------------------------------  // acclient.c:769467
unsigned int _E132_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_OverwriteExistingBinding");
  ID_ActionKeyMap_OverwriteExistingBinding = result;
  return result;
}

//----- (006ED940) --------------------------------------------------------  // acclient.c:769477
unsigned int _E134_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_OverwriteExistingBindings");
  ID_ActionKeyMap_OverwriteExistingBindings = result;
  return result;
}

//----- (006ED960) --------------------------------------------------------  // acclient.c:769487
unsigned int _E136_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_TT_ExistingBinding");
  ID_ActionKeyMap_TT_ExistingBinding = result;
  return result;
}

//----- (006ED980) --------------------------------------------------------  // acclient.c:769497
unsigned int _E138_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ActionKeyMap_TT_NewBinding");
  ID_ActionKeyMap_TT_NewBinding = result;
  return result;
}

//----- (006ED9A0) --------------------------------------------------------  // acclient.c:769507
unsigned int _E140_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ACTION");
  ACTION = result;
  return result;
}

//----- (006ED9C0) --------------------------------------------------------  // acclient.c:769517
unsigned int _E142_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("BINDINGS");
  BINDINGS = result;
  return result;
}

//----- (006ED9E0) --------------------------------------------------------  // acclient.c:769527
unsigned int _E144_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("KEY");
  KEY = result;
  return result;
}

//----- (006EDA00) --------------------------------------------------------  // acclient.c:769537
unsigned int _E146_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("LABEL");
  LABEL = result;
  return result;
}

//----- (006EDA20) --------------------------------------------------------  // acclient.c:769547
unsigned int _E148_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("VALUE");
  VALUE_3 = result;
  return result;
}

//----- (006EDA40) --------------------------------------------------------  // acclient.c:769557
int sub_6EDA40()
{
  return atexit(nullsub_997);
}

