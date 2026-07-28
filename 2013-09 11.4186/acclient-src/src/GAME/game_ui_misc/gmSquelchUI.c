/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSquelchUI
   Object     : GAME\game_ui_misc\gmSquelchUI.obj
   Functions  : 52
   Addresses  : 0048C100 - 0075F6E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0048C100) --------------------------------------------------------  // acclient.c:199614
void __thiscall AC1Legacy::PStringBase<char>::PStringBase<char>(AC1Legacy::PStringBase<char> *this, const char *str)
{
  AC1Legacy::PStringBase<char> *v2; // edi@1
  volatile LONG *v3; // ST00_4@4

  v2 = this;
  if ( str && *str )
  {
    AC1Legacy::PStringBase<char>::allocate_ref_buffer(this, strlen(str));
    strcpy(v2->m_buffer->m_data, str);
  }
  else
  {
    v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    this->m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v3);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0048C160) --------------------------------------------------------  // acclient.c:199635
void __thiscall gmSquelchUI::PostInit(gmSquelchUI *this)
{
  gmSquelchUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  UIElement *v10; // eax@13
  int v11; // eax@14
  GlobalEventHandler *v12; // eax@16

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000054Bu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)1);
  else
    v3 = 0;
  v1->m_pSquelchCharacterButton = (UIElement_Button *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000054Cu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)1);
  else
    v5 = 0;
  v1->m_pSquelchAccountButton = (UIElement_Button *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000547u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)1);
  else
    v7 = 0;
  v1->m_pRemoveButton = (UIElement_Button *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000053Eu);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)5);
  else
    v9 = 0;
  v1->m_pSquelchListBox = (UIElement_ListBox *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000540u);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v1->m_pSquelchNameEditBox = (UIElement_Text *)v11;
  v12 = GlobalEventHandler::GetGlobalEventHandler();
  v12->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v12, 5100156u, (NoticeHandler *)&v1->vfptr);
}

//----- (0048C240) --------------------------------------------------------  // acclient.c:199687
void __thiscall gmSquelchUI::UpdateButtons(gmSquelchUI *this)
{
  gmSquelchUI *v1; // esi@1
  UIElement_ListBox *v2; // ecx@1
  unsigned int v3; // edi@1
  unsigned int v4; // eax@1
  UIElement **v5; // edx@2
  UIElement *v6; // eax@6
  UIElement *v7; // edi@6
  bool v8; // zf@6
  IInputActionCallbackVtbl *v9; // eax@6
  UIElement *v10; // eax@7
  IInputActionCallbackVtbl *v11; // edx@10

  v1 = this;
  v2 = this->m_pSquelchListBox;
  v3 = v2->m_listItems.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = v2->m_listItems.m_data;
    while ( *v5 != v2->m_pSelectedItem )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v4 = -1;
  }
  v6 = UIElement_ListBox::GetItem(v2, v4);
  v7 = v6;
  v8 = v6 == 0;
  v9 = v1->m_pRemoveButton->vfptr;
  if ( v8 )
  {
    ((void (__stdcall *)(signed int))v9[13].__vecDelDtor)(13);
  }
  else
  {
    ((void (__stdcall *)(signed int))v9[13].__vecDelDtor)(1);
    v10 = UIElement::GetChildRecursive(v7, 0x10000542u);
    if ( v10 )
      v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  }
  v11 = v1->m_pSquelchCharacterButton->vfptr;
  if ( v1->m_squelchList._num_elements >= 0x32 )
  {
    ((void (__stdcall *)(signed int))v11[13].__vecDelDtor)(13);
    ((void (__stdcall *)(signed int))v1->m_pSquelchAccountButton->vfptr[13].__vecDelDtor)(13);
  }
  else
  {
    ((void (__stdcall *)(signed int))v11[13].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pSquelchAccountButton->vfptr[13].__vecDelDtor)(1);
  }
}

//----- (0048C300) --------------------------------------------------------  // acclient.c:199750
UIElement *__thiscall gmSquelchUI::FindSortedInsertPosition(gmSquelchUI *this, PStringBase<unsigned short> *_name, bool _online)
{
  gmSquelchUI *v3; // ebx@1
  UIElement_ListBox *v4; // ecx@1
  unsigned int v5; // esi@1
  const wchar_t **v6; // ebp@2
  UIElement *v7; // eax@3
  UIElement *v8; // edi@3
  UIElement *v9; // eax@4
  UIElement_Text *v10; // eax@5
  const wchar_t **v11; // eax@7
  bool v12; // bl@7
  PStringBase<unsigned short> *v13; // esi@7
  int i; // [sp+10h] [bp-8h]@1
  gmSquelchUI *v16; // [sp+14h] [bp-4h]@1

  v3 = this;
  v4 = this->m_pSquelchListBox;
  v5 = 0;
  v16 = v3;
  i = 0;
  if ( (signed int)v4->m_listItems.m_num <= 0 )
    return 0;
  v6 = (const wchar_t **)_name;
  while ( 1 )
  {
    v7 = UIElement_ListBox::GetItem(v4, v5);
    v8 = v7;
    if ( v7 )
      break;
LABEL_12:
    v4 = v3->m_pSquelchListBox;
    ++v5;
    i = v5;
    if ( (signed int)v5 >= (signed int)v4->m_listItems.m_num )
      return 0;
  }
  v9 = UIElement::GetChildRecursive(v7, 0x10000542u);
  if ( v9 )
    v10 = (UIElement_Text *)v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)12);
  else
    v10 = 0;
  v11 = (const wchar_t **)UIElement_Text::GetText(v10, (PStringBase<unsigned short> *)&_name);
  v12 = _wcscmp(*v6, *v11) < 0;
  v13 = _name - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_name[-4]) )
  {
    if ( v13 )
      (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v13->m_charbuffer->m_data[0])(v13, 1);
  }
  if ( !v12 )
  {
    v3 = v16;
    v5 = i;
    goto LABEL_12;
  }
  return v8;
}

//----- (0048C3E0) --------------------------------------------------------  // acclient.c:199810
char __thiscall gmSquelchUI::AddSquelchDisplay(gmSquelchUI *this, PStringBase<unsigned short> *_name, unsigned int _squelchID, bool _is_account)
{
  gmSquelchUI *v4; // esi@1
  UIElement *v5; // eax@1
  int v6; // eax@1
  UIElement *v7; // esi@1
  UIElement *v8; // eax@1
  UIElement_Text *v9; // eax@2
  UIElement_Text *v10; // edi@2
  char result; // al@4

  v4 = this;
  v5 = gmSquelchUI::FindSortedInsertPosition(this, _name, _is_account);
  v6 = UIElement_ListBox::AddItemFromTemplateList(v4->m_pSquelchListBox, 0, v5);
  v7 = (UIElement *)v6;
  v8 = UIElement::GetChildRecursive((UIElement *)v6, 0x10000542u);
  if ( v8
    && (v9 = (UIElement_Text *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12), (v10 = v9) != 0) )
  {
    UIElement_Text::SetText(v9, _name);
    UIElement::SetAttribute_InstanceID(v7, 0x1000008Fu, _squelchID);
    if ( _is_account )
    {
      v10->vfptr[13].__vecDelDtor((IInputActionCallback *)v10, 268435543u);
      result = 1;
    }
    else
    {
      v10->vfptr[13].__vecDelDtor((IInputActionCallback *)v10, 268435542u);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0048C480) --------------------------------------------------------  // acclient.c:199850
PList<unsigned long> *__thiscall PList<unsigned long>::vector_deleting_destructor(PList<unsigned long> *this, unsigned int a2)
{
  return PList<unsigned long>::vector_deleting_destructor((PList<unsigned long> *)((char *)this - 16), a2);
}

//----- (0048C490) --------------------------------------------------------  // acclient.c:199856
unsigned int __thiscall PList<unsigned long>::Pack(PList<unsigned long> *this, void **addr, unsigned int size)
{
  PList<unsigned long> *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edi@2
  AC1Legacy::ListNode<unsigned long> *i; // edx@2
  char *v7; // esi@4

  v3 = this;
  result = ((int (*)(void))this->vfptr[2].__vecDelDtor)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3[-1].vfptr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    for ( i = v3[-1]._tail; i; i = i->next )
    {
      if ( size >= 4 )
      {
        *(_DWORD *)v5 = i->data;
        v7 = (char *)*addr + 4;
        *addr = v7;
        v5 = v7;
      }
      if ( !i )
        break;
    }
  }
  return result;
}

//----- (0048C4F0) --------------------------------------------------------  // acclient.c:199888
signed int __thiscall PList<unsigned long>::GetPackSize(PList<unsigned long> *this)
{
  AC1Legacy::ListNode<unsigned long> *v1; // ecx@1
  signed int result; // eax@1

  v1 = this[-1]._tail;
  for ( result = 4; v1; v1 = v1->next )
  {
    result += 4;
    if ( !v1 )
      break;
  }
  return result;
}

//----- (0048C510) --------------------------------------------------------  // acclient.c:199904
int __thiscall PList<unsigned long>::UnPack(PList<unsigned long> *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  int result; // eax@2
  void **v5; // esi@3
  void *v6; // ebp@3
  AC1Legacy::List<unsigned long> *v7; // ebx@3
  int v8; // ecx@3
  void ***v9; // edx@4
  int v10; // eax@4
  unsigned int num; // [sp+0h] [bp-4h]@3

  v3 = size;
  if ( size >= 4 )
  {
    v5 = addr;
    v6 = *addr;
    v7 = (AC1Legacy::List<unsigned long> *)&this[-1]._head;
    List<SkillRecord *>::flush((List<SkillRecord *> *)&this[-1]._head);
    v8 = *(_DWORD *)*v5;
    num = *(_DWORD *)*v5;
    *v5 = (char *)*v5 + 4;
    size = 0;
    if ( v8 )
    {
      while ( 1 )
      {
        v9 = (void ***)*v5;
        v10 = (_BYTE *)*v5 - (_BYTE *)v6;
        if ( v3 <= v10 )
          break;
        if ( v3 - v10 < 4 )
          break;
        addr = *v9;
        *v5 = v9 + 1;
        if ( !AC1Legacy::List<unsigned long>::push_back(v7, (const unsigned int *)&addr) )
          break;
        ++size;
        if ( size >= num )
          goto LABEL_8;
      }
      result = 0;
    }
    else
    {
LABEL_8:
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0048C5B0) --------------------------------------------------------  // acclient.c:199961
int __thiscall AC1Legacy::List<unsigned long>::push_back(AC1Legacy::List<unsigned long> *this, const unsigned int *val)
{
  AC1Legacy::List<unsigned long> *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@3
  AC1Legacy::ListNode<unsigned long> *v5; // ecx@5

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    *(_DWORD *)v3 = *val;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    if ( v2->_head )
    {
      v5 = v2->_tail;
      v5->next = (AC1Legacy::ListNode<unsigned long> *)v3;
      *((_DWORD *)v3 + 2) = v5;
      v2->_tail = (AC1Legacy::ListNode<unsigned long> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
    else
    {
      v2->_head = (AC1Legacy::ListNode<unsigned long> *)v3;
      v2->_tail = (AC1Legacy::ListNode<unsigned long> *)v3;
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

//----- (0048C610) --------------------------------------------------------  // acclient.c:200000
AC1Legacy::List<unsigned long> *__thiscall AC1Legacy::List<unsigned long>::vector_deleting_destructor(AC1Legacy::List<unsigned long> *this, unsigned int a2)
{
  AC1Legacy::List<unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);

//----- (0048C640) --------------------------------------------------------  // acclient.c:200014
PList<unsigned long> *__thiscall PList<unsigned long>::vector_deleting_destructor(PList<unsigned long> *this, unsigned int a2)
{
  PList<unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;

//----- (0048C680) --------------------------------------------------------  // acclient.c:200032
void __thiscall FriendData::~FriendData(FriendData *this)
{
  FriendData *v1; // esi@1
  char *v2; // ecx@1
  int v3; // ecx@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1

  v1 = this;
  v2 = (char *)&this->m_friendOfList;
  v1->vfptr = (PackObjVtbl *)&FriendData::vftable;
  *((_DWORD *)v2 + 4) = &PList<unsigned long>::vftable;
  *((_DWORD *)v2 + 4) = &PackObj::vftable;
  *(_DWORD *)v2 = &AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)v2);
  v3 = (int)&v1->m_friendsList;
  *(_DWORD *)(v3 + 16) = &PList<unsigned long>::vftable;
  *(_DWORD *)(v3 + 16) = &PackObj::vftable;
  *(_DWORD *)v3 = &AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_friendsList);
  v4 = v1->m_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A4128: using guessed type int (__thiscall *FriendData::vftable)(void *, char);

//----- (0048C6F0) --------------------------------------------------------  // acclient.c:200062
FriendData *__thiscall FriendData::vector_deleting_destructor(FriendData *this, unsigned int a2)
{
  FriendData *v2; // esi@1

  v2 = this;
  FriendData::~FriendData(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048C710) --------------------------------------------------------  // acclient.c:200074
char __thiscall gmSquelchUI::RefreshSquelchDisplay(gmSquelchUI *this)
{
  gmSquelchUI *v1; // edi@1
  bool v2; // ST0C_1@2
  PStringBase<unsigned short> *v3; // eax@2
  char *v4; // esi@2
  AC1Legacy::PSRefBuffer<char> *v5; // esi@6
  AC1Legacy::PStringBase<char> squelch_name; // [sp+Ch] [bp-Ch]@1
  int is_account; // [sp+10h] [bp-8h]@1
  PStringBase<unsigned short> v9; // [sp+14h] [bp-4h]@2

  v1 = this;
  UIElement_ListBox::Flush(this->m_pSquelchListBox);
  UIElement_ListBox::SetSelectedItem(v1->m_pSquelchListBox, 0, 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&squelch_name, &name);
  gmCCommunicationSystem::StartSquelchIteration();
  while ( gmCCommunicationSystem::NextSquelchIteration(&squelch_name, &is_account) )
  {
    v2 = is_account != 0;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v9, 0, squelch_name.m_buffer->m_data);
    gmSquelchUI::AddSquelchDisplay(v1, v3, 0, v2);
    v4 = (char *)&v9.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v9.m_charbuffer[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  }
  gmSquelchUI::UpdateButtons(v1);
  v5 = squelch_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&squelch_name.m_buffer->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  return 1;
}

//----- (0048C7F0) --------------------------------------------------------  // acclient.c:200107
void __thiscall PStringBase<char>::PStringBase<char>(PStringBase<char> *this, _WidthConvert __formal, PStringBase<unsigned short> *str)
{
  PStringBase<char> *v3; // esi@1
  volatile LONG *v4; // ST04_4@1
  PSRefBufferCharData<char> *v5; // eax@1
  int v6; // ecx@1
  PStringBase<unsigned short> *v7; // edi@3

  v3 = this;
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = PStringBase<unsigned short>::to_spstring(str, (PStringBase<char> *)&str, 0)->m_charbuffer;
  v6 = *(_DWORD *)&v5[-1].m_data[12];
  if ( v6 != 1 )
    PStringBase<char>::append_n_chars(v3, v5->m_data, v6 - 1);
  v7 = str - 5;
  if ( !InterlockedDecrement((volatile LONG *)&str[-4]) )
  {
    if ( v7 )
      (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v7->m_charbuffer->m_data[0])(v7, 1);
  }
}

//----- (0048C860) --------------------------------------------------------  // acclient.c:200132
int __thiscall gmSquelchUI::ListenToElementMessage(gmSquelchUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebp@1
  gmSquelchUI *v3; // esi@1
  int v4; // eax@2
  bool v5; // bl@4
  char *v6; // edi@4
  IInputActionCallbackVtbl *v7; // eax@7
  PStringBase<unsigned short> *v8; // eax@13
  PStringBase<unsigned short> *v9; // eax@14
  UIElement_ListBox *v10; // edi@15
  unsigned int v11; // eax@15
  UIElement *v12; // eax@15
  int v13; // eax@16
  int v14; // edi@16
  PStringBase<unsigned short> *v15; // eax@16
  AC1Legacy::PStringBase<char> *v16; // ecx@17
  AC1Legacy::PStringBase<char> i_character_name; // [sp+8h] [bp-20h]@13
  AC1Legacy::PStringBase<char> v18; // [sp+Ch] [bp-1Ch]@14
  AC1Legacy::PStringBase<char> v19; // [sp+10h] [bp-18h]@17
  AC1Legacy::PStringBase<char> v20; // [sp+14h] [bp-14h]@18
  PStringBase<unsigned short> result; // [sp+18h] [bp-10h]@4
  PStringBase<unsigned short> v22; // [sp+1Ch] [bp-Ch]@13
  PStringBase<unsigned short> v23; // [sp+20h] [bp-8h]@14
  PStringBase<unsigned short> v24; // [sp+24h] [bp-4h]@16

  v2 = i_rMsg;
  v3 = this;
  switch ( i_rMsg->idMessage )
  {
    case 4u:
    case 0x43u:
      gmSquelchUI::UpdateButtons(this);
      v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      break;
    case 0x12u:
    case 0x44u:
      if ( this->m_squelchList._num_elements >= 0x32 )
        goto LABEL_21;
      v5 = *(_DWORD *)&UIElement_Text::GetText(this->m_pSquelchNameEditBox, &result)->m_charbuffer[-1].m_data[14] == 1;
      v6 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = v3->m_pSquelchCharacterButton->vfptr;
      if ( v5 )
      {
        ((void (__stdcall *)(signed int))v7[13].__vecDelDtor)(13);
        ((void (__stdcall *)(signed int))v3->m_pSquelchAccountButton->vfptr[13].__vecDelDtor)(13);
        v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      }
      else
      {
        ((void (__stdcall *)(signed int))v7[13].__vecDelDtor)(1);
        ((void (__stdcall *)(signed int))v3->m_pSquelchAccountButton->vfptr[13].__vecDelDtor)(1);
        v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      }
      break;
    case 1u:
      if ( i_rMsg->idElement == 268436807 )
      {
        v10 = this->m_pSquelchListBox;
        v11 = UIElement_ListBox::GetSelectedIndex(this->m_pSquelchListBox);
        v12 = UIElement_ListBox::GetItem(v10, v11);
        if ( !v12 )
          goto LABEL_21;
        v13 = UIElement::GetChildRecursiveTemplate<UIElement_Text>(v12, 0x10000542u);
        v14 = v13;
        v15 = UIElement_Text::GetText((UIElement_Text *)v13, &v24);
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_rMsg, 0, v15);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v24);
        if ( *(_DWORD *)(v14 + 1024) == 268435543 )
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>(&v19, (const char *)i_rMsg);
          CM_Communication::Event_ModifyAccountSquelch(0, &v19);
          v16 = &v19;
        }
        else
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>(&v20, (const char *)i_rMsg);
          CM_Communication::Event_ModifyCharacterSquelch(0, 0, &v20, 1u);
          v16 = &v20;
        }
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)v16);
      }
      else if ( i_rMsg->idElement == 268436811 )
      {
        v9 = UIElement_Text::GetText(this->m_pSquelchNameEditBox, &v23);
        PStringBase<unsigned short>::to_spstring(v9, (PStringBase<char> *)&i_rMsg, 0);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v23);
        AC1Legacy::PStringBase<char>::PStringBase<char>(&v18, (const char *)i_rMsg);
        CM_Communication::Event_ModifyCharacterSquelch(1, 0, &v18, 1u);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v18);
        UIElement_Text::ClearAllText(v3->m_pSquelchNameEditBox);
        ((void (__stdcall *)(signed int))v3->m_pSquelchCharacterButton->vfptr[13].__vecDelDtor)(13);
      }
      else
      {
        if ( i_rMsg->idElement != 268436812 )
          goto LABEL_21;
        v8 = UIElement_Text::GetText(this->m_pSquelchNameEditBox, &v22);
        PStringBase<unsigned short>::to_spstring(v8, (PStringBase<char> *)&i_rMsg, 0);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v22);
        AC1Legacy::PStringBase<char>::PStringBase<char>(&i_character_name, (const char *)i_rMsg);
        CM_Communication::Event_ModifyAccountSquelch(1, &i_character_name);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&i_character_name);
        UIElement_Text::ClearAllText(v3->m_pSquelchNameEditBox);
        ((void (__stdcall *)(_DWORD))v3->m_pSquelchAccountButton->vfptr[13].__vecDelDtor)(13);
      }
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_rMsg);
      goto LABEL_21;
    default:
LABEL_21:
      v4 = UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      break;
  }
  return v4;
}

//----- (0048CB60) --------------------------------------------------------  // acclient.c:200251
void __thiscall gmSquelchUI::RecvNotice_UpdateSquelchPanel(gmSquelchUI *this)
{
  gmSquelchUI::RefreshSquelchDisplay((gmSquelchUI *)((char *)this - 1528));
}

//----- (0048CB70) --------------------------------------------------------  // acclient.c:200257
void __thiscall AC1Legacy::List<FriendData>::flush(AC1Legacy::List<FriendData> *this)
{
  AC1Legacy::List<FriendData> *v1; // ebx@1
  int v2; // esi@3
  int v3; // eax@4
  AC1Legacy::ListNode<unsigned long> *v4; // eax@10
  void *v5; // ecx@12
  AC1Legacy::ListNode<unsigned long> *v6; // eax@18
  void *v7; // ecx@20
  AC1Legacy::PSRefBuffer<char> *v8; // esi@26
  FriendData v9; // [sp+10h] [bp-3Ch]@3

  v1 = this;
  while ( v1->_head )
  {
    FriendData::FriendData(&v9);
    v2 = (int)v1->_head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 60);
      v1->_head = (AC1Legacy::ListNode<FriendData> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 64) = 0;
      else
        v1->_tail = 0;
      FriendData::operator=((int)&v9, v2);
      if ( v2 )
      {
        FriendData::~FriendData((FriendData *)v2);
        operator delete((void *)v2);
      }
      --v1->_num_elements;
    }
    v4 = v9.m_friendOfList._head;
    v9.vfptr = (PackObjVtbl *)&FriendData::vftable;
    v9.m_friendOfList.vfptr = (PackObjVtbl *)&PackObj::vftable;
    v9.m_friendOfList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
    while ( v4 )
    {
      v5 = v4;
      v4 = v4->next;
      v9.m_friendOfList._head = v4;
      if ( v4 )
      {
        v4->prev = 0;
        v4 = v9.m_friendOfList._head;
      }
      else
      {
        v9.m_friendOfList._tail = 0;
      }
      if ( v5 )
      {
        operator delete(v5);
        v4 = v9.m_friendOfList._head;
      }
      --v9.m_friendOfList._num_elements;
    }
    v6 = v9.m_friendsList._head;
    v9.m_friendsList.vfptr = (PackObjVtbl *)&PackObj::vftable;
    v9.m_friendsList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
    while ( v6 )
    {
      v7 = v6;
      v6 = v6->next;
      v9.m_friendsList._head = v6;
      if ( v6 )
      {
        v6->prev = 0;
        v6 = v9.m_friendsList._head;
      }
      else
      {
        v9.m_friendsList._tail = 0;
      }
      if ( v7 )
      {
        operator delete(v7);
        v6 = v9.m_friendsList._head;
      }
      --v9.m_friendsList._num_elements;
    }
    v8 = v9.m_name.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&v9.m_name.m_buffer->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    v9.vfptr = (PackObjVtbl *)&PackObj::vftable;
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4128: using guessed type int (__thiscall *FriendData::vftable)(void *, char);

//----- (0048CC90) --------------------------------------------------------  // acclient.c:200350
FriendDataList *__thiscall FriendDataList::vector_deleting_destructor(FriendDataList *this, unsigned int a2)
{
  return PList<FriendData>::scalar_deleting_destructor((FriendDataList *)((char *)this - 16), a2);
}

//----- (0048CCA0) --------------------------------------------------------  // acclient.c:200356
unsigned int __thiscall PList<FriendData>::Pack(PList<FriendData> *this, void **addr, unsigned int size)
{
  PList<FriendData> *v3; // esi@1
  unsigned int v4; // ebp@1
  AC1Legacy::ListNode<FriendData> *i; // esi@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr[2].__vecDelDtor)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3[-1].vfptr;
    *addr = (char *)*addr + 4;
    for ( i = v3[-1]._tail; i; i = i->next )
      ((void (__thiscall *)(AC1Legacy::ListNode<FriendData> *, void **, unsigned int))i->data.vfptr->Pack)(
        i,
        addr,
        size);
  }
  return v4;
}

//----- (0048CCF0) --------------------------------------------------------  // acclient.c:200378
signed int __thiscall PList<FriendData>::GetPackSize(PList<FriendData> *this)
{
  AC1Legacy::ListNode<FriendData> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *foo; // [sp+0h] [bp-4h]@1

  foo = this;
  v1 = this[-1]._tail;
  v2 = 4;
  for ( foo = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(AC1Legacy::ListNode<FriendData> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &foo, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (0048CD30) --------------------------------------------------------  // acclient.c:200397
int __thiscall PList<FriendData>::UnPack(PList<FriendData> *this, void **addr, unsigned int size)
{
  int result; // eax@2
  void **v4; // esi@3
  void *v5; // ebx@3
  AC1Legacy::List<FriendData> *v6; // ebp@3
  unsigned int v7; // edi@3
  unsigned int v8; // eax@4
  signed int v9; // ecx@5
  FriendData tmp; // [sp+8h] [bp-3Ch]@3
  void **addra; // [sp+48h] [bp+4h]@3

  if ( size >= 4 )
  {
    v4 = addr;
    v5 = *addr;
    v6 = (AC1Legacy::List<FriendData> *)&this[-1]._head;
    AC1Legacy::List<FriendData>::flush((AC1Legacy::List<FriendData> *)&this[-1]._head);
    v7 = *(_DWORD *)*addr;
    *v4 = (char *)*v4 + 4;
    FriendData::FriendData(&tmp);
    addra = 0;
    if ( v7 )
    {
      while ( 1 )
      {
        v8 = (_BYTE *)*v4 - (_BYTE *)v5;
        v9 = size <= v8 ? 0 : size - v8;
        if ( !((int (__thiscall *)(FriendData *, void **, signed int))tmp.vfptr->UnPack)(&tmp, v4, v9)
          || !AC1Legacy::List<FriendData>::push_back(v6, &tmp) )
          break;
        addra = (void **)((char *)addra + 1);
        if ( (unsigned int)addra >= v7 )
          goto LABEL_10;
      }
      FriendData::~FriendData(&tmp);
      result = 0;
    }
    else
    {
LABEL_10:
      FriendData::~FriendData(&tmp);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0048CDF0) --------------------------------------------------------  // acclient.c:200450
int __thiscall AC1Legacy::List<FriendData>::push_back(AC1Legacy::List<FriendData> *this, FriendData *val)
{
  AC1Legacy::List<FriendData> *v2; // edi@1
  void *v3; // esi@1
  int v4; // eax@3
  int result; // eax@3
  AC1Legacy::ListNode<FriendData> *v6; // eax@5
  int v7; // eax@5

  v2 = this;
  v3 = operator new(0x44u);
  if ( v3 )
  {
    FriendData::FriendData((FriendData *)v3, val);
    *((_DWORD *)v3 + 15) = 0;
    *((_DWORD *)v3 + 16) = 0;
    if ( v2->_head )
    {
      v6 = v2->_tail;
      v6->next = (AC1Legacy::ListNode<FriendData> *)v3;
      *((_DWORD *)v3 + 16) = v6;
      v7 = v2->_num_elements + 1;
      v2->_tail = (AC1Legacy::ListNode<FriendData> *)v3;
      v2->_num_elements = v7;
      result = 1;
    }
    else
    {
      v4 = v2->_num_elements + 1;
      v2->_head = (AC1Legacy::ListNode<FriendData> *)v3;
      v2->_tail = (AC1Legacy::ListNode<FriendData> *)v3;
      v2->_num_elements = v4;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0048CE60) --------------------------------------------------------  // acclient.c:200493
AC1Legacy::List<FriendData> *__thiscall AC1Legacy::List<FriendData>::scalar_deleting_destructor(AC1Legacy::List<FriendData> *this, unsigned int a2)
{
  AC1Legacy::List<FriendData> *v2; // esi@1

  v2 = this;
  this->vfptr = (AC1Legacy::List<FriendData>Vtbl *)AC1Legacy::List<FriendData>::vftable;
  AC1Legacy::List<FriendData>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A410C: using guessed type int (__thiscall *AC1Legacy::List<FriendData>::vftable[2])(void *, char);

//----- (0048CE90) --------------------------------------------------------  // acclient.c:200507
FriendDataList *__thiscall PList<FriendData>::scalar_deleting_destructor(FriendDataList *this, unsigned int a2)
{
  FriendDataList *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PList<FriendData>::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (AC1Legacy::List<FriendData>Vtbl *)AC1Legacy::List<FriendData>::vftable;
  AC1Legacy::List<FriendData>::flush((AC1Legacy::List<FriendData> *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A410C: using guessed type int (__thiscall *AC1Legacy::List<FriendData>::vftable[2])(void *, char);
// 7A413C: using guessed type void *PList<FriendData>::vftable;

//----- (0048CED0) --------------------------------------------------------  // acclient.c:200525
void __userpurge gmSquelchUI::gmSquelchUI(gmSquelchUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSquelchUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pSquelchCharacterButton = 0;
  v4->m_pSquelchAccountButton = 0;
  v4->m_pRemoveButton = 0;
  v4->m_pSquelchListBox = 0;
  v4->m_pSquelchNameEditBox = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSquelchUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSquelchUI::vftable;
  v4->m_squelchList._head = 0;
  v4->m_squelchList._tail = 0;
  v4->m_squelchList._num_elements = 0;
  v4->m_squelchList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v4->m_squelchList.vfptr = (AC1Legacy::List<FriendData>Vtbl *)&FriendDataList::vftable;
  v4->m_squelchList.vfptr = (PackObjVtbl *)&PList<FriendData>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A413C: using guessed type void *PList<FriendData>::vftable;
// 7A4150: using guessed type int (__thiscall *FriendDataList::vftable)(void *, char);
// 7A4158: using guessed type bool (__thiscall *gmSquelchUI::vftable)(DBCache *this);
// 7A4400: using guessed type int (__thiscall *gmSquelchUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048CF60) --------------------------------------------------------  // acclient.c:200554
gmSquelchUI *__thiscall gmSquelchUI::DynamicCast(gmSquelchUI *this, unsigned int i_eType)
{
  gmSquelchUI *result; // eax@1

  result = this;
  if ( i_eType != 268435527 )
    result = (gmSquelchUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0048CF80) --------------------------------------------------------  // acclient.c:200565
signed int gmSquelchUI::GetUIElementType()
{
  return 268435527;
}

//----- (0048CF90) --------------------------------------------------------  // acclient.c:200571
void __thiscall gmSquelchUI::~gmSquelchUI(gmSquelchUI *this)
{
  gmSquelchUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1
  int v4; // ecx@3

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmSquelchUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmSquelchUI::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v4 = (int)&v1->m_squelchList;
  *(_DWORD *)(v4 + 16) = &PList<FriendData>::vftable;
  *(_DWORD *)(v4 + 16) = &PackObj::vftable;
  *(_DWORD *)v4 = AC1Legacy::List<FriendData>::vftable;
  AC1Legacy::List<FriendData>::flush((AC1Legacy::List<FriendData> *)&v1->m_squelchList.vfptr);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A410C: using guessed type int (__thiscall *AC1Legacy::List<FriendData>::vftable[2])(void *, char);
// 7A413C: using guessed type void *PList<FriendData>::vftable;
// 7A4158: using guessed type bool (__thiscall *gmSquelchUI::vftable)(DBCache *this);
// 7A4400: using guessed type int (__thiscall *gmSquelchUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048CFF0) --------------------------------------------------------  // acclient.c:200602
void __usercall gmSquelchUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSquelchUI *v3; // eax@1

  v3 = (gmSquelchUI *)operator new(0x624u);
  if ( v3 )
    gmSquelchUI::gmSquelchUI(v3, a1, _layout, _full_desc);
}

//----- (0048D020) --------------------------------------------------------  // acclient.c:200612
gmSquelchUI *__thiscall gmSquelchUI::scalar_deleting_destructor(gmSquelchUI *this, unsigned int a2)
{
  gmSquelchUI *v2; // esi@1

  v2 = this;
  gmSquelchUI::~gmSquelchUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048D040) --------------------------------------------------------  // acclient.c:200624
void __cdecl gmSquelchUI::Register()
{
  UIElement::RegisterElementClass(0x10000047u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSquelchUI::Create);
}

//----- (006EDE10) --------------------------------------------------------  // acclient.c:769835
void _E91_53()
{
  outside_val_45 = 1000.0 + 1.0;
}

//----- (006EDE30) --------------------------------------------------------  // acclient.c:769841
void _E93_29()
{
  block_length_45 = 24.0 * 8.0;
}

//----- (006EDE50) --------------------------------------------------------  // acclient.c:769847
void _E95_29()
{
  half_square_length_45 = 24.0 * 0.5;
}

//----- (006EDE70) --------------------------------------------------------  // acclient.c:769853
int _E97_54()
{
  return atexit(_E98_66);
}

//----- (006EDE80) --------------------------------------------------------  // acclient.c:769859
int _E100_47()
{
  return atexit(_E101_84);
}

//----- (006EDE90) --------------------------------------------------------  // acclient.c:769865
int _E103_39()
{
  return atexit(_E104_54);
}

//----- (006EDEA0) --------------------------------------------------------  // acclient.c:769871
void _E106_29()
{
  DEFAULT_VIEW_RADIUS_23 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EDEC0) --------------------------------------------------------  // acclient.c:769877
void _E108_20()
{
  MIN_QUANTUM_23 = 1.0 / 30.0;
}

//----- (006EDEE0) --------------------------------------------------------  // acclient.c:769883
void _E110_11()
{
  MAX_QUANTUM_23 = 1.0 / 5.0;
}

//----- (006EDF00) --------------------------------------------------------  // acclient.c:769889
void _E112_25()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_58, PFID_A8R8G8B8);
}

//----- (006EDF10) --------------------------------------------------------  // acclient.c:769895
void _E115_18()
{
  LOWEST_DATA_RATE_66 = 1024;
}

//----- (006EDF20) --------------------------------------------------------  // acclient.c:769901
void _E117_15()
{
  HIGHEST_DATA_RATE_66 = 0x7FFF;
}

//----- (006EDF30) --------------------------------------------------------  // acclient.c:769907
int _E119_4()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_66;
  INITIAL_MAX_DATA_RATE_14 = LOWEST_DATA_RATE_66;
  return result;
}

//----- (006EDF40) --------------------------------------------------------  // acclient.c:769917
int _E121_25()
{
  return atexit(_E122_62);
}

//----- (006EDF50) --------------------------------------------------------  // acclient.c:769923
int _E124_23()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_17, "Misc.TooltipEnable");
  return atexit(_E125_33);
}

//----- (006EDF70) --------------------------------------------------------  // acclient.c:769930
int _E127_19()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_17, "Misc.TooltipDelay");
  return atexit(_E128_34);
}

//----- (006EDF90) --------------------------------------------------------  // acclient.c:769937
int sub_6EDF90()
{
  return atexit(nullsub_910);
}

//----- (0075F6B0) --------------------------------------------------------  // acclient.c:887289
void __cdecl _E125_33()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F6E0) --------------------------------------------------------  // acclient.c:887302
void __cdecl _E128_34()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

