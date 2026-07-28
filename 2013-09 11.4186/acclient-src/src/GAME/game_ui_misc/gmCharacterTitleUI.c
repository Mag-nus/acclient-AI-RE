/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCharacterTitleUI
   Object     : GAME\game_ui_misc\gmCharacterTitleUI.obj
   Functions  : 39
   Addresses  : 0049A500 - 0075FDC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0049A500) --------------------------------------------------------  // acclient.c:211980
void __thiscall gmCharacterTitleUI::UpdateButtons(gmCharacterTitleUI *this)
{
  gmCharacterTitleUI *v1; // edi@1
  UIElement_ListBox *v2; // ecx@1
  unsigned int v3; // esi@1
  unsigned int v4; // eax@1
  UIElement **v5; // edx@2
  UIElement *v6; // eax@6
  unsigned int titleID; // [sp+0h] [bp-4h]@1

  titleID = (unsigned int)this;
  v1 = this;
  v2 = this->m_pTitleListBox;
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
  if ( v6
    && (titleID = 0,
        UIElement::GetAttribute_Enum(v6, 0x1000008Eu, &titleID),
        titleID != v1->m_characterTitleTable.mDisplayTitle) )
    ((void (__stdcall *)(signed int))v1->m_pDisplayButton->vfptr[13].__vecDelDtor)(1);
  else
    ((void (__stdcall *)(signed int))v1->m_pDisplayButton->vfptr[13].__vecDelDtor)(13);
}

//----- (0049A590) --------------------------------------------------------  // acclient.c:212022
int __thiscall AC1Legacy::List<unsigned long>::insert(AC1Legacy::List<unsigned long> *this, AC1Legacy::ListNode<unsigned long> *node, const unsigned int *val)
{
  AC1Legacy::List<unsigned long> *v3; // esi@1
  void *v4; // eax@1
  int result; // eax@3
  AC1Legacy::ListNode<unsigned long> *v6; // edx@5

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
        v6->next = (AC1Legacy::ListNode<unsigned long> *)v4;
        node->prev = (AC1Legacy::ListNode<unsigned long> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
      else
      {
        v3->_head = (AC1Legacy::ListNode<unsigned long> *)v4;
        node->prev = (AC1Legacy::ListNode<unsigned long> *)v4;
        ++v3->_num_elements;
        result = 1;
      }
    }
    else
    {
      v3->_head = (AC1Legacy::ListNode<unsigned long> *)v4;
      v3->_tail = (AC1Legacy::ListNode<unsigned long> *)v4;
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

//----- (0049A610) --------------------------------------------------------  // acclient.c:212072
void __thiscall gmCharacterTitleUI::PostInit(gmCharacterTitleUI *this)
{
  gmCharacterTitleUI *v1; // edi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  GlobalEventHandler *v8; // eax@10
  GlobalEventHandler *v9; // esi@10
  int v10; // edi@11

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000052Fu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    v3 = 0;
  v1->m_pDisplayTitleText = (UIElement_Text *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000535u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)1);
  else
    v5 = 0;
  v1->m_pDisplayButton = (UIElement_Button *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000532u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)5);
  else
    v7 = 0;
  v1->m_pTitleListBox = (UIElement_ListBox *)v7;
  v8 = GlobalEventHandler::GetGlobalEventHandler();
  v9 = v8;
  if ( v8 )
  {
    v10 = (int)&v1->vfptr;
    v8->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v8, (unsigned int)&loc_4DD277, (NoticeHandler *)v10);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, (unsigned int)&loc_4DD279, (NoticeHandler *)v10);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 5100152u, (NoticeHandler *)v10);
  }
}

//----- (0049A6D0) --------------------------------------------------------  // acclient.c:212117
int __thiscall gmCharacterTitleUI::ListenToElementMessage(gmCharacterTitleUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebx@1
  UIElement *v3; // edi@1
  UIElement_ListBox *v5; // esi@6
  unsigned int v6; // eax@6
  UIElement *v7; // eax@6

  v2 = i_rMsg;
  v3 = (UIElement *)this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 268436789 )
    {
      v5 = this->m_pTitleListBox;
      v6 = UIElement_ListBox::GetSelectedIndex(this->m_pTitleListBox);
      v7 = UIElement_ListBox::GetItem(v5, v6);
      if ( v7 )
      {
        i_rMsg = 0;
        UIElement::GetAttribute_Enum(v7, 0x1000008Eu, (unsigned int *)&i_rMsg);
        CM_Social::Event_SetDisplayCharacterTitle((unsigned int)i_rMsg);
      }
    }
  }
  else if ( i_rMsg->idMessage == 4 || i_rMsg->idMessage == 67 )
  {
    gmCharacterTitleUI::UpdateButtons(this);
    return UIElement::ListenToElementMessage(v3, v2);
  }
  return UIElement::ListenToElementMessage(v3, v2);
}

//----- (0049A760) --------------------------------------------------------  // acclient.c:212151
UIElement *__thiscall gmCharacterTitleUI::FindSortedInsertPosition(gmCharacterTitleUI *this, PStringBase<unsigned short> *i_strTitle)
{
  gmCharacterTitleUI *v2; // ebx@1
  UIElement_ListBox *v3; // ecx@1
  unsigned int v4; // esi@1
  const wchar_t **v5; // ebp@2
  UIElement *v6; // eax@3
  UIElement *v7; // edi@3
  UIElement *v8; // eax@4
  UIElement_Text *v9; // eax@5
  const wchar_t **v10; // eax@7
  bool v11; // bl@7
  PStringBase<unsigned short> *v12; // esi@7
  int i; // [sp+10h] [bp-8h]@1
  gmCharacterTitleUI *v15; // [sp+14h] [bp-4h]@1

  v2 = this;
  v3 = this->m_pTitleListBox;
  v4 = 0;
  v15 = v2;
  i = 0;
  if ( (signed int)v3->m_listItems.m_num <= 0 )
    return 0;
  v5 = (const wchar_t **)i_strTitle;
  while ( 1 )
  {
    v6 = UIElement_ListBox::GetItem(v3, v4);
    v7 = v6;
    if ( v6 )
      break;
LABEL_12:
    v3 = v2->m_pTitleListBox;
    ++v4;
    i = v4;
    if ( (signed int)v4 >= (signed int)v3->m_listItems.m_num )
      return 0;
  }
  v8 = UIElement::GetChildRecursive(v6, 0x10000537u);
  if ( v8 )
    v9 = (UIElement_Text *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v10 = (const wchar_t **)UIElement_Text::GetText(v9, (PStringBase<unsigned short> *)&i_strTitle);
  v11 = _wcscmp(*v5, *v10) < 0;
  v12 = i_strTitle - 5;
  if ( !InterlockedDecrement((volatile LONG *)&i_strTitle[-4]) )
  {
    if ( v12 )
      (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v12->m_charbuffer->m_data[0])(v12, 1);
  }
  if ( !v11 )
  {
    v2 = v15;
    v4 = i;
    goto LABEL_12;
  }
  return v7;
}

//----- (0049A840) --------------------------------------------------------  // acclient.c:212211
char __thiscall gmCharacterTitleUI::AddTitleToList(gmCharacterTitleUI *this, unsigned int i_title)
{
  unsigned int v2; // edi@1
  gmCharacterTitleUI *v3; // esi@1
  UIElement *v4; // eax@3
  int v5; // eax@3
  UIElement *v6; // esi@3
  UIElement *v7; // eax@3
  UIElement_Text *v8; // eax@4
  unsigned int v9; // esi@5
  unsigned int v11; // esi@9

  v2 = i_title;
  v3 = this;
  if ( !i_title )
    return 0;
  i_title = (unsigned int)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !CharacterTitleTable::GetCharacterTitleFromID(v2, (PStringBase<unsigned short> *)&i_title)
    || (v4 = gmCharacterTitleUI::FindSortedInsertPosition(v3, (PStringBase<unsigned short> *)&i_title),
        v5 = UIElement_ListBox::AddItemFromTemplateList(v3->m_pTitleListBox, 0, v4),
        v6 = (UIElement *)v5,
        (v7 = UIElement::GetChildRecursive((UIElement *)v5, 0x10000537u)) == 0)
    || (v8 = (UIElement_Text *)v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)12)) == 0 )
  {
    v11 = i_title - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_title - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    return 0;
  }
  UIElement_Text::SetText(v8, (PStringBase<unsigned short> *)&i_title);
  UIElement::SetAttribute_Enum(v6, 0x1000008Eu, v2);
  v9 = i_title - 20;
  if ( !InterlockedDecrement((volatile LONG *)(i_title - 20 + 4)) )
  {
    if ( v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
  return 1;
}

//----- (0049A920) --------------------------------------------------------  // acclient.c:212253
List<SkillRecord *> *__thiscall AC1Legacy::List<unsigned long>::operator=(List<SkillRecord *> *this, int a2)
{
  List<SkillRecord *> *v2; // esi@1
  int i; // edi@2
  void *v4; // eax@3
  ListNode<SkillRecord *> *v5; // ecx@6

  v2 = this;
  if ( this != (List<SkillRecord *> *)a2 )
  {
    List<SkillRecord *>::flush(this);
    for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 4) )
    {
      v4 = operator new(0xCu);
      if ( v4 )
      {
        *(_DWORD *)v4 = *(_DWORD *)i;
        *((_DWORD *)v4 + 1) = 0;
        *((_DWORD *)v4 + 2) = 0;
        if ( v2->_head )
        {
          v5 = v2->_tail;
          v5->next = (ListNode<SkillRecord *> *)v4;
          *((_DWORD *)v4 + 2) = v5;
        }
        else
        {
          v2->_head = (ListNode<SkillRecord *> *)v4;
        }
        v2->_tail = (ListNode<SkillRecord *> *)v4;
        ++v2->_num_elements;
      }
      if ( !i )
        break;
    }
  }
  return v2;
}

//----- (0049A990) --------------------------------------------------------  // acclient.c:212293
void __thiscall gmCharacterTitleUI::RecvNotice_AddCharacterTitle(gmCharacterTitleUI *this, unsigned int i_title)
{
  gmCharacterTitleUI *v2; // esi@1
  AC1Legacy::ListNode<unsigned long> *v3; // edx@1
  AC1Legacy::List<unsigned long> *v4; // ecx@1
  unsigned int v5; // edi@1
  AC1Legacy::ListNode<unsigned long> *v6; // eax@1

  v2 = this;
  v3 = (AC1Legacy::ListNode<unsigned long> *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
  v4 = (AC1Legacy::List<unsigned long> *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
  v5 = i_title;
  v6 = v3;
  if ( v3 )
  {
    while ( v6->data != i_title )
    {
      v6 = v6->next;
      if ( !v6 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    if ( AC1Legacy::List<unsigned long>::insert(v4, v3, &i_title) )
      gmCharacterTitleUI::AddTitleToList((gmCharacterTitleUI *)((char *)v2 - 1528), v5);
  }
}

//----- (0049A9E0) --------------------------------------------------------  // acclient.c:212324
void __thiscall CharacterTitleTable::~CharacterTitleTable(CharacterTitleTable *this)
{
  CharacterTitleTable *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->mTitleList;
  v1->vfptr = (PackObjVtbl *)&CharacterTitleTable::vftable;
  *((_DWORD *)v2 + 4) = &PList<unsigned long>::vftable;
  *((_DWORD *)v2 + 4) = &PackObj::vftable;
  *(_DWORD *)v2 = &AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)v2);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A6F94: using guessed type int (__thiscall *CharacterTitleTable::vftable)(void *, char);

//----- (0049AA10) --------------------------------------------------------  // acclient.c:212344
CharacterTitleTable *__thiscall CharacterTitleTable::scalar_deleting_destructor(CharacterTitleTable *this, unsigned int a2)
{
  CharacterTitleTable *v2; // esi@1
  char *v3; // ecx@1

  v2 = this;
  v3 = (char *)&this->mTitleList;
  v2->vfptr = (PackObjVtbl *)&CharacterTitleTable::vftable;
  *((_DWORD *)v3 + 4) = &PList<unsigned long>::vftable;
  *((_DWORD *)v3 + 4) = &PackObj::vftable;
  *(_DWORD *)v3 = &AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)v3);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A6F94: using guessed type int (__thiscall *CharacterTitleTable::vftable)(void *, char);

//----- (0049AA60) --------------------------------------------------------  // acclient.c:212367
void __userpurge gmCharacterTitleUI::gmCharacterTitleUI(gmCharacterTitleUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCharacterTitleUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCharacterTitleUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmCharacterTitleUI::vftable;
  v4->m_pDisplayButton = 0;
  v4->m_pTitleListBox = 0;
  CharacterTitleTable::CharacterTitleTable(&v4->m_characterTitleTable);
}
// 7A6FA8: using guessed type bool (__thiscall *gmCharacterTitleUI::vftable)(DBCache *this);
// 7A7250: using guessed type int (__thiscall *gmCharacterTitleUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0049AAB0) --------------------------------------------------------  // acclient.c:212385
gmCharacterTitleUI *__thiscall gmCharacterTitleUI::DynamicCast(gmCharacterTitleUI *this, unsigned int i_eType)
{
  gmCharacterTitleUI *result; // eax@1

  result = this;
  if ( i_eType != 268435526 )
    result = (gmCharacterTitleUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0049AAD0) --------------------------------------------------------  // acclient.c:212396
signed int gmCharacterTitleUI::GetUIElementType()
{
  return 268435526;
}

//----- (0049AAE0) --------------------------------------------------------  // acclient.c:212402
void __thiscall gmCharacterTitleUI::~gmCharacterTitleUI(gmCharacterTitleUI *this)
{
  gmCharacterTitleUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1
  int v4; // ecx@3

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCharacterTitleUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmCharacterTitleUI::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v4 = (int)&v1->m_characterTitleTable.mTitleList;
  v1->m_characterTitleTable.vfptr = (PackObjVtbl *)&CharacterTitleTable::vftable;
  *(_DWORD *)(v4 + 16) = &PList<unsigned long>::vftable;
  *(_DWORD *)(v4 + 16) = &PackObj::vftable;
  *(_DWORD *)v4 = &AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_characterTitleTable.mTitleList);
  v1->m_characterTitleTable.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A6F94: using guessed type int (__thiscall *CharacterTitleTable::vftable)(void *, char);
// 7A6FA8: using guessed type bool (__thiscall *gmCharacterTitleUI::vftable)(DBCache *this);
// 7A7250: using guessed type int (__thiscall *gmCharacterTitleUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0049AB50) --------------------------------------------------------  // acclient.c:212436
void __usercall gmCharacterTitleUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCharacterTitleUI *v3; // eax@1

  v3 = (gmCharacterTitleUI *)operator new(0x624u);
  if ( v3 )
    gmCharacterTitleUI::gmCharacterTitleUI(v3, a1, _layout, _full_desc);
}

//----- (0049AB80) --------------------------------------------------------  // acclient.c:212446
gmCharacterTitleUI *__thiscall gmCharacterTitleUI::vector_deleting_destructor(gmCharacterTitleUI *this, unsigned int a2)
{
  gmCharacterTitleUI *v2; // esi@1

  v2 = this;
  gmCharacterTitleUI::~gmCharacterTitleUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0049ABA0) --------------------------------------------------------  // acclient.c:212458
void __cdecl gmCharacterTitleUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000046u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCharacterTitleUI::Create);
}

//----- (0049ABC0) --------------------------------------------------------  // acclient.c:212466
char __thiscall gmCharacterTitleUI::Refresh(gmCharacterTitleUI *this)
{
  gmCharacterTitleUI *v1; // esi@1
  unsigned int v2; // edi@1
  char *v3; // edi@3
  AC1Legacy::ListNode<unsigned long> *v4; // edi@6
  AC1Legacy::ListNode<unsigned long> *v5; // eax@9
  void *v6; // ecx@11
  char *v7; // esi@17
  PStringBase<unsigned short> strTitle; // [sp+Ch] [bp-1Ch]@1
  PStringBase<unsigned short> _text; // [sp+10h] [bp-18h]@3
  PList<unsigned long> list; // [sp+14h] [bp-14h]@6

  strTitle.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v1 = this;
  v2 = this->m_characterTitleTable.mDisplayTitle;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( CharacterTitleTable::GetCharacterTitleFromID(v2, &strTitle) )
  {
    UIElement_Text::SetText(v1->m_pDisplayTitleText, &strTitle);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_text, L"Unknown");
    UIElement_Text::SetText(v1->m_pDisplayTitleText, &_text);
    v3 = (char *)&_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
  UIElement_ListBox::Flush(v1->m_pTitleListBox);
  UIElement_ListBox::SetSelectedItem(v1->m_pTitleListBox, 0, 1);
  list.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
  list._head = 0;
  list._tail = 0;
  list._num_elements = 0;
  AC1Legacy::List<unsigned long>::operator=((List<SkillRecord *> *)&list, (int)&v1->m_characterTitleTable.mTitleList);
  v4 = list._head;
  list.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&PList<unsigned long>::vftable;
  list.vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
  while ( v4 )
  {
    gmCharacterTitleUI::AddTitleToList(v1, v4->data);
    v4 = v4->next;
  }
  gmCharacterTitleUI::UpdateButtons(v1);
  v5 = list._head;
  list.vfptr = (PackObjVtbl *)&PackObj::vftable;
  list.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
  while ( v5 )
  {
    v6 = v5;
    v5 = v5->next;
    list._head = v5;
    if ( v5 )
    {
      v5->prev = 0;
      v5 = list._head;
    }
    else
    {
      list._tail = 0;
    }
    if ( v6 )
    {
      operator delete(v6);
      v5 = list._head;
    }
    --list._num_elements;
  }
  v7 = (char *)&strTitle.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strTitle.m_charbuffer[-1].m_data[8]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);

//----- (0049AD30) --------------------------------------------------------  // acclient.c:212546
void __thiscall gmCharacterTitleUI::RecvNotice_UpdateCharacterTitleTable(gmCharacterTitleUI *this, CharacterTitleTable *i_titleTable)
{
  gmCharacterTitleUI *v2; // esi@1

  v2 = this;
  CharacterTitleTable::operator=(
    (int)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1],
    (int)i_titleTable);
  gmCharacterTitleUI::Refresh((gmCharacterTitleUI *)((char *)v2 - 1528));
}

//----- (0049AD50) --------------------------------------------------------  // acclient.c:212558
void __thiscall gmCharacterTitleUI::RecvNotice_SetDisplayCharacterTitle(gmCharacterTitleUI *this, unsigned int i_title)
{
  unsigned int v2; // edx@1
  gmCharacterTitleUI *v3; // edi@1
  HashSetData<UIElement *> *v4; // eax@1
  AC1Legacy::List<unsigned long> *v5; // ecx@4
  AC1Legacy::ListNode<unsigned long> *v6; // esi@4
  HashSetData<UIElement *> *v7; // eax@4

  v2 = i_title;
  v3 = this;
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = (HashSetData<UIElement *> *)i_title;
  v4 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
  if ( v4 )
  {
    while ( v4->m_hashKey != (UIElement *)v2 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v5 = (AC1Legacy::List<unsigned long> *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
    v6 = (AC1Legacy::ListNode<unsigned long> *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
    v7 = v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4];
    i_title = v2;
    if ( v7 )
    {
      while ( v7->m_hashKey != (UIElement *)v2 )
      {
        v7 = v7->m_hashNext;
        if ( !v7 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      AC1Legacy::List<unsigned long>::insert(v5, v6, &i_title);
    }
  }
  gmCharacterTitleUI::Refresh((gmCharacterTitleUI *)((char *)v3 - 1528));
}

//----- (006EEE60) --------------------------------------------------------  // acclient.c:770997
void _E91_60()
{
  outside_val_52 = 1000.0 + 1.0;
}

//----- (006EEE80) --------------------------------------------------------  // acclient.c:771003
void _E93_36()
{
  block_length_52 = 24.0 * 8.0;
}

//----- (006EEEA0) --------------------------------------------------------  // acclient.c:771009
void _E95_36()
{
  half_square_length_52 = 24.0 * 0.5;
}

//----- (006EEEC0) --------------------------------------------------------  // acclient.c:771015
int _E97_61()
{
  return atexit(_E98_73);
}

//----- (006EEED0) --------------------------------------------------------  // acclient.c:771021
int _E100_54()
{
  return atexit(_E101_91);
}

//----- (006EEEE0) --------------------------------------------------------  // acclient.c:771027
int _E103_46()
{
  return atexit(_E104_61);
}

//----- (006EEEF0) --------------------------------------------------------  // acclient.c:771033
void _E106_36()
{
  DEFAULT_VIEW_RADIUS_29 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EEF10) --------------------------------------------------------  // acclient.c:771039
void _E108_26()
{
  MIN_QUANTUM_29 = 1.0 / 30.0;
}

//----- (006EEF30) --------------------------------------------------------  // acclient.c:771045
void _E110_17()
{
  MAX_QUANTUM_29 = 1.0 / 5.0;
}

//----- (006EEF50) --------------------------------------------------------  // acclient.c:771051
void _E112_31()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_64, PFID_A8R8G8B8);
}

//----- (006EEF60) --------------------------------------------------------  // acclient.c:771057
void _E115_24()
{
  LOWEST_DATA_RATE_72 = 1024;
}

//----- (006EEF70) --------------------------------------------------------  // acclient.c:771063
void _E117_21()
{
  HIGHEST_DATA_RATE_72 = 0x7FFF;
}

//----- (006EEF80) --------------------------------------------------------  // acclient.c:771069
int _E119_10()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_72;
  INITIAL_MAX_DATA_RATE_20 = LOWEST_DATA_RATE_72;
  return result;
}

//----- (006EEF90) --------------------------------------------------------  // acclient.c:771079
int _E121_31()
{
  return atexit(_E122_68);
}

//----- (006EEFA0) --------------------------------------------------------  // acclient.c:771085
int _E124_29()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_24, "Misc.TooltipEnable");
  return atexit(_E125_39);
}

//----- (006EEFC0) --------------------------------------------------------  // acclient.c:771092
int _E127_25()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_24, "Misc.TooltipDelay");
  return atexit(_E128_40);
}

//----- (006EEFE0) --------------------------------------------------------  // acclient.c:771099
int sub_6EEFE0()
{
  return atexit(nullsub_858);
}

//----- (0075FD90) --------------------------------------------------------  // acclient.c:887601
void __cdecl _E125_39()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FDC0) --------------------------------------------------------  // acclient.c:887614
void __cdecl _E128_40()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

