/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmPageListUI
   Object     : GAME\game_ui_misc\gmPageListUI.obj
   Functions  : 48
   Addresses  : 00493140 - 0075F990 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00493140) --------------------------------------------------------  // acclient.c:205982
char __thiscall gmPageListUI::CheckForDoubleClick(gmPageListUI *this, const int selected_index)
{
  char result; // al@3

  if ( selected_index == this->m_LastClickIndex && COERCE_DOUBLE(Timer::cur_time.Cmd) <= this->m_LastClickTime + 1.0 )
  {
    result = 1;
    *(_QWORD *)&this->m_LastClickTime = 0i64;
    this->m_LastClickIndex = -1;
  }
  else
  {
    this->m_LastClickTime = *(double *)&Timer::cur_time;
    this->m_LastClickIndex = selected_index;
    result = 0;
  }
  return result;
}

//----- (004931A0) --------------------------------------------------------  // acclient.c:206002
PageInfo *__cdecl _STL::__uninitialized_copy(PageInfo *__first, PageInfo *__last, PageInfo *__result)
{
  PageInfo *v3; // esi@1
  PageInfo *i; // edi@1

  v3 = __first;
  for ( i = __result; v3 != __last; ++i )
  {
    if ( i )
      PageInfo::PageInfo(i, v3);
    ++v3;
  }
  return i;
}

//----- (004931D0) --------------------------------------------------------  // acclient.c:206018
PageInfo *__cdecl _STL::__copy_backward(PageInfo *__first, PageInfo *__last, PageInfo *__result)
{
  int v3; // edi@1
  PageInfo *v4; // esi@2
  signed int v5; // ebx@2
  PageInfo *result; // eax@4

  v3 = (int)__last;
  if ( __last - __first <= 0 )
  {
    result = __result;
  }
  else
  {
    v4 = __result;
    v5 = __last - __first;
    do
    {
      v3 -= 64;
      --v4;
      PageInfo::operator=(v4, v3);
      --v5;
    }
    while ( v5 );
    result = v4;
  }
  return result;
}

//----- (00493210) --------------------------------------------------------  // acclient.c:206048
PageInfo *__cdecl _STL::__copy(PageInfo *__first, PageInfo *__last, PageInfo *__result)
{
  int v3; // edi@1
  PageInfo *v4; // esi@2
  signed int v5; // ebx@2
  PageInfo *result; // eax@4

  v3 = (int)__first;
  if ( __last - __first <= 0 )
  {
    result = __result;
  }
  else
  {
    v4 = __result;
    v5 = __last - __first;
    do
    {
      PageInfo::operator=(v4, v3);
      v3 += 64;
      ++v4;
      --v5;
    }
    while ( v5 );
    result = v4;
  }
  return result;
}

//----- (004932C0) --------------------------------------------------------  // acclient.c:206101
void __cdecl _STL::__unguarded_linear_insert(PageInfo *__last, PageInfo __val, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  bool (__cdecl *v3)(PageInfo *, PageInfo *); // ebx@1
  PageInfo *v4; // edi@1
  int i; // esi@1

  v3 = __comp;
  v4 = __last;
  for ( i = (int)&__last[-1]; v3(&__val, (PageInfo *)i); i -= 64 )
  {
    PageInfo::operator=(v4, i);
    v4 = (PageInfo *)i;
  }
  PageInfo::operator=(v4, (int)&__val);
  LookFile::~LookFile((LookFile *)&__val);
}

//----- (00493320) --------------------------------------------------------  // acclient.c:206119
void __cdecl _STL::__push_heap(PageInfo *__first, int __holeIndex, int __topIndex, PageInfo __val, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  int v5; // edi@1
  int i; // esi@1

  v5 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v5 > __topIndex; i = (i - 1) / 2 )
  {
    if ( !__comp(&__first[i], &__val) )
      break;
    PageInfo::operator=(&__first[v5], (int)&__first[i]);
    v5 = i;
  }
  PageInfo::operator=(&__first[v5], (int)&__val);
  LookFile::~LookFile((LookFile *)&__val);
}

//----- (004933A0) --------------------------------------------------------  // acclient.c:206137
void __thiscall gmPageListUI::PostInit(gmPageListUI *this)
{
  gmPageListUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000583u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
  else
    v3 = 0;
  v1->m_pPageListBox = (UIElement_ListBox *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000587u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  v1->m_pSearchEditBox = (UIElement_Text *)v5;
  GlobalEventHandler::GetGlobalEventHandler();
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
}

//----- (00493410) --------------------------------------------------------  // acclient.c:206164
void __thiscall gmPageListUI::RefreshPageListbox(gmPageListUI *this)
{
  gmPageListUI *v1; // ebx@1
  PageInfo *v2; // edi@1
  unsigned int v3; // eax@2
  signed int v4; // edx@2
  int v5; // ebp@3
  UIElement *v6; // eax@4
  UIElement *v7; // eax@4
  UIElement_Text *v8; // edi@5
  PSRefBufferCharData<unsigned short> **v9; // esi@6
  char *v10; // edi@7
  char *v11; // esi@11
  char *v12; // esi@14
  int v13; // ecx@17
  PStringBase<unsigned short> column_text; // [sp+Ch] [bp-10h]@6
  unsigned int i; // [sp+10h] [bp-Ch]@2
  UIElement_Text *pPageTimerText; // [sp+14h] [bp-8h]@5
  PStringBase<unsigned short> result; // [sp+18h] [bp-4h]@6

  v1 = this;
  v2 = this->m_PageListPages._M_start;
  if ( this->m_pPageListBox->m_listItems.m_num == this->m_PageListPages._M_finish - v2 )
  {
    v3 = 0;
    v4 = this->m_PageListPages._M_finish - v2;
    i = 0;
    if ( v4 )
    {
      v5 = 0;
      do
      {
        v6 = UIElement_ListBox::GetItem(v1->m_pPageListBox, v3);
        v7 = UIElement::GetChildRecursive(v6, 0x1000058Cu);
        if ( v7 )
        {
          v8 = (UIElement_Text *)v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)12);
          pPageTimerText = v8;
          if ( v8 )
          {
            column_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
            InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
            v9 = (PSRefBufferCharData<unsigned short> **)GetTimerText(
                                                           &result,
                                                           v1->m_PageListPages._M_start[v5].m_TimerRunning,
                                                           v1->m_PageListPages._M_start[v5].m_TimerStamp);
            if ( column_text.m_charbuffer != *v9 )
            {
              v10 = (char *)&column_text.m_charbuffer[-1].m_data[6];
              if ( !InterlockedDecrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]) && v10 )
                (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
              column_text.m_charbuffer = *v9;
              InterlockedIncrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]);
              v8 = pPageTimerText;
            }
            v11 = (char *)&result.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v11 )
              (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
            UIElement_Text::SetText(v8, &column_text);
            v12 = (char *)&column_text.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]) )
            {
              if ( v12 )
                (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
            }
          }
        }
        v3 = i + 1;
        v13 = v1->m_PageListPages._M_finish - v1->m_PageListPages._M_start;
        ++v5;
        ++i;
      }
      while ( i < v13 );
    }
  }
}

//----- (00493590) --------------------------------------------------------  // acclient.c:206242
void __cdecl _STL::__unguarded_insertion_sort_aux(PageInfo *__first, PageInfo *__last, PageInfo *__formal, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  PageInfo *i; // esi@1
  PageInfo v5; // [sp-44h] [bp-50h]@2
  bool (__cdecl *v6)(PageInfo *, PageInfo *); // [sp-4h] [bp-10h]@2

  for ( i = __first; i != __last; ++i )
  {
    v6 = __comp;
    PageInfo::PageInfo(&v5, i);
    _STL::__unguarded_linear_insert(i, v5, v6);
  }
}

//----- (004935D0) --------------------------------------------------------  // acclient.c:206257
void __cdecl _STL::__adjust_heap(PageInfo *__first, int __holeIndex, int __len, PageInfo __val, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  int v5; // edi@1
  int v6; // esi@1
  bool i; // zf@1
  PageInfo v8; // [sp-44h] [bp-54h]@7
  bool (__cdecl *v9)(PageInfo *, PageInfo *); // [sp-4h] [bp-14h]@7

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  for ( i = v6 == __len; v6 < __len; i = v6 == __len )
  {
    if ( __comp(&__first[v6], &__first[v6 - 1]) )
      --v6;
    PageInfo::operator=(&__first[v5], (int)&__first[v6]);
    v5 = v6;
    v6 = 2 * v6 + 2;
  }
  if ( i )
  {
    PageInfo::operator=(&__first[v5], (int)&__first[v6 - 1]);
    v5 = v6 - 1;
  }
  v9 = __comp;
  PageInfo::PageInfo(&v8, &__val);
  _STL::__push_heap(__first, v5, __holeIndex, v8, v9);
  LookFile::~LookFile((LookFile *)&__val);
}

//----- (00493680) --------------------------------------------------------  // acclient.c:206287
void __thiscall gmPageListUI::AddPageToListbox(gmPageListUI *this, PageInfo *_info)
{
  gmPageListUI *v2; // esi@1
  int v3; // eax@1
  UIElement *v4; // edi@1
  UIElement *v5; // eax@1
  PageInfo *v6; // ebx@2
  UIElement_Text *v7; // esi@2
  UIElement *v8; // eax@5
  UIElement_Text *v9; // eax@6
  UIElement *v10; // eax@8
  UIElement_Text *v11; // ebp@9
  PSRefBufferCharData<unsigned short> **v12; // ebx@10
  char *v13; // esi@11
  char *v14; // esi@15
  UIElement *v15; // eax@19
  UIElement_Text *v16; // eax@20
  char *v17; // esi@22
  PStringBase<unsigned short> column_text; // [sp+14h] [bp-8h]@1
  PStringBase<unsigned short> result; // [sp+18h] [bp-4h]@10

  column_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v3 = UIElement_ListBox::AddItemFromTemplateListByID(v2->m_pPageListBox, 0x10000589u, 0);
  v4 = (UIElement *)v3;
  v5 = UIElement::GetChildRecursive((UIElement *)v3, 0x1000058Au);
  if ( v5 )
  {
    v6 = _info;
    v7 = (UIElement_Text *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)12);
    if ( v7 )
    {
      PStringBase<unsigned short>::sprintf(&column_text, L"%d", _info->m_PageNumber);
      UIElement_Text::SetText(v7, &column_text);
    }
  }
  else
  {
    v6 = _info;
  }
  v8 = UIElement::GetChildRecursive(v4, 0x1000058Bu);
  if ( v8 )
  {
    v9 = (UIElement_Text *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
    if ( v9 )
      UIElement_Text::SetText(v9, &v6->m_Title);
  }
  v10 = UIElement::GetChildRecursive(v4, 0x1000058Cu);
  if ( v10 )
  {
    v11 = (UIElement_Text *)v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
    if ( v11 )
    {
      v12 = (PSRefBufferCharData<unsigned short> **)GetTimerText(&result, v6->m_TimerRunning, v6->m_TimerStamp);
      if ( column_text.m_charbuffer != *v12 )
      {
        v13 = (char *)&column_text.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]) && v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        column_text.m_charbuffer = *v12;
        InterlockedIncrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]);
      }
      v14 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      UIElement_Text::SetText(v11, &column_text);
      v6 = _info;
    }
  }
  v15 = UIElement::GetChildRecursive(v4, 0x1000058Du);
  if ( v15 )
  {
    v16 = (UIElement_Text *)v15->vfptr[12].OnAction((IInputActionCallback *)v15, (InputEvent *)12);
    if ( v16 )
      UIElement_Text::SetText(v16, &v6->m_Label);
  }
  v17 = (char *)&column_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&column_text.m_charbuffer[-1].m_data[8]) )
  {
    if ( v17 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  }
}

//----- (00493830) --------------------------------------------------------  // acclient.c:206373
PageInfo *__cdecl _STL::__unguarded_partition(PageInfo *__first, PageInfo *__last, PageInfo __pivot, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  PageInfo *v4; // ebx@1
  bool (__cdecl *v5)(PageInfo *, PageInfo *); // ebp@1
  PageInfo *v6; // edi@1
  char *v7; // esi@7
  char *v8; // esi@10
  char *v9; // esi@13
  PageInfo v11; // [sp+10h] [bp-40h]@7

  v4 = __first;
  v5 = __comp;
  v6 = __last;
  while ( 1 )
  {
    for ( ; v5(v4, &__pivot); ++v4 )
      ;
    for ( --v6; v5(&__pivot, v6); --v6 )
      ;
    if ( v4 >= v6 )
      break;
    PageInfo::PageInfo(&v11, v4);
    PageInfo::operator=(v4, (int)v6);
    PageInfo::operator=(v6, (int)&v11);
    v7 = (char *)&v11.m_Notes.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v11.m_Notes.m_charbuffer[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    v8 = (char *)&v11.m_Title.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v11.m_Title.m_charbuffer[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    v9 = (char *)&v11.m_Label.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v11.m_Label.m_charbuffer[-1].m_data[8]) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    }
    ++v4;
  }
  LookFile::~LookFile((LookFile *)&__pivot);
  return v4;
}

//----- (00493940) --------------------------------------------------------  // acclient.c:206416
void __cdecl _STL::__destroy_aux(PageInfo *__first, PageInfo *__last)
{
  PageInfo *i; // edi@1
  int v3; // esi@2
  int v4; // esi@5
  int v5; // esi@8

  for ( i = __first; i != __last; ++i )
  {
    v3 = (int)&i->m_Notes.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (int)&i->m_Title.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = (int)&i->m_Label.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
  }
}

//----- (004939C0) --------------------------------------------------------  // acclient.c:206441
void __cdecl _STL::__linear_insert(PageInfo *__first, PageInfo *__last, PageInfo __val, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  bool (__cdecl *v4)(PageInfo *, PageInfo *); // edi@1
  PageInfo v5; // [sp-44h] [bp-4Ch]@3
  bool (__cdecl **v6)(PageInfo *, PageInfo *); // [sp-8h] [bp-10h]@2
  bool (__cdecl *v7)(PageInfo *, PageInfo *); // [sp-4h] [bp-Ch]@3

  v4 = __comp;
  if ( __comp(&__val, __first) )
  {
    v6 = &__comp;
    _STL::__copy_backward(__first, __last, __last + 1);
    PageInfo::operator=(__first, (int)&__val);
    LookFile::~LookFile((LookFile *)&__val);
  }
  else
  {
    v7 = v4;
    PageInfo::PageInfo(&v5, &__val);
    _STL::__unguarded_linear_insert(__last, v5, v7);
    LookFile::~LookFile((LookFile *)&__val);
  }
}

//----- (00493A40) --------------------------------------------------------  // acclient.c:206466
void __cdecl _STL::__make_heap(PageInfo *__first, PageInfo *__last, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  int v3; // ebx@1
  int v4; // esi@2
  PageInfo *i; // edi@2
  PageInfo v6; // [sp-44h] [bp-54h]@3
  bool (__cdecl *v7)(PageInfo *, PageInfo *); // [sp-4h] [bp-14h]@3

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    for ( i = &__first[v4]; ; --i )
    {
      v7 = __comp;
      PageInfo::PageInfo(&v6, i);
      _STL::__adjust_heap(__first, v4, v3, v6, v7);
      if ( !v4 )
        break;
      --v4;
    }
  }
}

//----- (00493AA0) --------------------------------------------------------  // acclient.c:206491
void __thiscall gmPageListUI::ListenToGlobalMessage(gmPageListUI *this, unsigned int i_messageID, int i_data_int)
{
  gmPageListUI *v3; // esi@1

  v3 = this;
  if ( i_messageID == 3
    && (*((_DWORD *)&this->0 + 41) >> 1) & 1
    && COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_timeNextUpdate )
  {
    gmPageListUI::RefreshPageListbox(this);
    v3->m_timeNextUpdate = COERCE_DOUBLE(Timer::cur_time.Cmd) + 0.5;
  }
}

//----- (00493AF0) --------------------------------------------------------  // acclient.c:206506
void __thiscall gmPageListUI::RebuildPageListbox(gmPageListUI *this)
{
  gmPageListUI *v1; // esi@1
  unsigned int v2; // edi@1
  int v3; // ebx@2

  v1 = this;
  UIElement_ListBox::Flush(this->m_pPageListBox);
  UIElement_ListBox::SetSelectedItem(v1->m_pPageListBox, 0, 1);
  v2 = 0;
  if ( v1->m_PageListPages._M_finish - v1->m_PageListPages._M_start )
  {
    v3 = 0;
    do
    {
      gmPageListUI::AddPageToListbox(v1, &v1->m_PageListPages._M_start[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_PageListPages._M_finish - v1->m_PageListPages._M_start );
  }
}

//----- (00493B60) --------------------------------------------------------  // acclient.c:206530
char __stdcall gmPageListUI::PageContainsString(PageInfo *page, PStringBase<unsigned short> i_search_string)
{
  PSRefBufferCharData<unsigned short> *v3; // ebx@1
  char *v4; // esi@2
  char result; // al@5
  wchar_t *v6; // eax@11
  PSRefBufferCharData<unsigned short> *v7; // ecx@12
  int v8; // esi@13
  char *v9; // esi@16
  wchar_t *v10; // eax@23
  wchar_t *v11; // eax@25
  PStringBase<unsigned short> buffer_string; // [sp+8h] [bp-8h]@6
  PStringBase<unsigned short> search_string; // [sp+Ch] [bp-4h]@6

  v3 = i_search_string.m_charbuffer;
  if ( *(_DWORD *)&i_search_string.m_charbuffer[-1].m_data[14] == 1 )
  {
    v4 = (char *)&i_search_string.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&i_search_string.m_charbuffer[-1].m_data[8])
      && v3 != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(&v3[-1].m_data[6], 1);
    result = 1;
  }
  else
  {
    search_string.m_charbuffer = i_search_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&i_search_string.m_charbuffer[-1].m_data[8]);
    buffer_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::break_reference(&search_string);
    __wcslwr(search_string.m_charbuffer->m_data);
    if ( buffer_string.m_charbuffer != page->m_Label.m_charbuffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&buffer_string.m_charbuffer[-1].m_data[8])
        && buffer_string.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))&buffer_string.m_charbuffer[-1].m_data[6])(
          &buffer_string.m_charbuffer[-1].m_data[6],
          1);
      buffer_string.m_charbuffer = page->m_Label.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&buffer_string.m_charbuffer[-1].m_data[8]);
      v3 = i_search_string.m_charbuffer;
    }
    PStringBase<unsigned short>::break_reference(&buffer_string);
    __wcslwr(buffer_string.m_charbuffer->m_data);
    v6 = _wcsstr(buffer_string.m_charbuffer->m_data, search_string.m_charbuffer->m_data);
    if ( v6 && (v7 = buffer_string.m_charbuffer, ((char *)v6 - (char *)buffer_string.m_charbuffer) >> 1 >= 0)
      || (PStringBase<unsigned short>::operator=(&buffer_string, (const unsigned __int16 *)&page->m_Title),
          PStringBase<unsigned short>::break_reference(&buffer_string),
          __wcslwr(buffer_string.m_charbuffer->m_data),
          (v10 = _wcsstr(buffer_string.m_charbuffer->m_data, search_string.m_charbuffer->m_data)) != 0)
      && (v7 = buffer_string.m_charbuffer, ((char *)v10 - (char *)buffer_string.m_charbuffer) >> 1 >= 0) )
    {
      v8 = (int)&v7[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v7[-1].m_data[8]) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      v9 = (char *)&search_string.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&search_string.m_charbuffer[-1].m_data[8]) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) && v3 != (PSRefBufferCharData<unsigned short> *)20 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))&v3[-1].m_data[6])(&v3[-1].m_data[6], 1);
      result = 1;
    }
    else
    {
      PStringBase<unsigned short>::operator=(&buffer_string, (const unsigned __int16 *)&page->m_Notes);
      PStringBase<unsigned short>::break_reference(&buffer_string);
      __wcslwr(buffer_string.m_charbuffer->m_data);
      v11 = _wcsstr(buffer_string.m_charbuffer->m_data, search_string.m_charbuffer->m_data);
      if ( v11 && ((char *)v11 - (char *)buffer_string.m_charbuffer) >> 1 >= 0 )
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&buffer_string);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&search_string);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_search_string);
        result = 1;
      }
      else
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&buffer_string);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&search_string);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_search_string);
        result = 0;
      }
    }
  }
  return result;
}

//----- (00493D70) --------------------------------------------------------  // acclient.c:206618
void __cdecl _STL::__insertion_sort(PageInfo *__first, PageInfo *__last, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  PageInfo *i; // esi@2
  PageInfo v4; // [sp-44h] [bp-54h]@3
  bool (__cdecl *v5)(PageInfo *, PageInfo *); // [sp-4h] [bp-14h]@3

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v5 = __comp;
      PageInfo::PageInfo(&v4, i);
      _STL::__linear_insert(__first, i, v4, v5);
    }
  }
}

//----- (00493DC0) --------------------------------------------------------  // acclient.c:206636
void __cdecl _STL::__final_insertion_sort(PageInfo *__first, PageInfo *__last, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFC0) <= 1024 )
  {
    _STL::__insertion_sort(__first, __last, __comp);
  }
  else
  {
    _STL::__insertion_sort(__first, __first + 16, __comp);
    _STL::__unguarded_insertion_sort_aux(__first + 16, __last, 0, __comp);
  }
}

//----- (00493E10) --------------------------------------------------------  // acclient.c:206650
void __cdecl _STL::sort_heap(PageInfo *__first, PageInfo *__last, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  signed int v3; // edi@1
  char *v4; // esi@2
  int v5; // edx@4
  char *v6; // esi@5
  int v7; // edx@7
  char *v8; // esi@8
  int v9; // edx@10
  PageInfo v10; // [sp-44h] [bp-94h]@2
  bool (__cdecl *v11)(PageInfo *, PageInfo *); // [sp-4h] [bp-54h]@2
  PageInfo rhs; // [sp+10h] [bp-40h]@2

  v3 = (char *)__last - (char *)__first;
  while ( (signed int)(v3 & 0xFFFFFFC0) > 64 )
  {
    PageInfo::PageInfo(&rhs, (PageInfo *)((char *)__first + v3 - 64));
    PageInfo::operator=((char *)&__first[-1] + v3, (int)__first);
    v11 = __comp;
    v3 -= 64;
    PageInfo::PageInfo(&v10, &rhs);
    _STL::__adjust_heap(__first, 0, v3 >> 6, v10, v11);
    v4 = (char *)&rhs.m_Notes.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_Notes.m_charbuffer[-1].m_data[8]) && v4 )
    {
      v5 = *(_DWORD *)v4;
      v11 = (bool (__cdecl *)(PageInfo *, PageInfo *))1;
      (*(void (__thiscall **)(char *, signed int))v5)(v4, 1);
    }
    v6 = (char *)&rhs.m_Title.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_Title.m_charbuffer[-1].m_data[8]) && v6 )
    {
      v7 = *(_DWORD *)v6;
      v11 = (bool (__cdecl *)(PageInfo *, PageInfo *))1;
      (*(void (__thiscall **)(char *, signed int))v7)(v6, 1);
    }
    v8 = (char *)&rhs.m_Label.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&rhs.m_Label.m_charbuffer[-1].m_data[8]) )
    {
      if ( v8 )
      {
        v9 = *(_DWORD *)v8;
        v11 = (bool (__cdecl *)(PageInfo *, PageInfo *))1;
        (*(void (__thiscall **)(char *, signed int))v9)(v8, 1);
      }
    }
  }
}

//----- (00493EE0) --------------------------------------------------------  // acclient.c:206700
void __cdecl _STL::__partial_sort(PageInfo *__first, PageInfo *__middle, PageInfo *__last, PageInfo *__formal, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  bool (__cdecl *v5)(PageInfo *, PageInfo *); // esi@1
  PageInfo *i; // ebx@1
  char *v7; // esi@3
  int v8; // eax@5
  char *v9; // esi@6
  int v10; // edx@8
  char *v11; // esi@9
  int v12; // edx@11
  PageInfo v13; // [sp-44h] [bp-94h]@3
  int v14; // [sp-8h] [bp-58h]@1
  bool (__cdecl *v15)(PageInfo *, PageInfo *); // [sp-4h] [bp-54h]@1
  PageInfo rhs; // [sp+10h] [bp-40h]@3

  v5 = __comp;
  v15 = 0;
  v14 = 0;
  _STL::__make_heap(__first, __middle, __comp);
  for ( i = __middle; i < __last; ++i )
  {
    if ( v5(i, __first) )
    {
      PageInfo::PageInfo(&rhs, i);
      PageInfo::operator=(i, (int)__first);
      v15 = v5;
      PageInfo::PageInfo(&v13, &rhs);
      _STL::__adjust_heap(__first, 0, __middle - __first, v13, v15);
      v7 = (char *)&rhs.m_Notes.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&rhs.m_Notes.m_charbuffer[-1].m_data[8]) && v7 )
      {
        v8 = *(_DWORD *)v7;
        v15 = (bool (__cdecl *)(PageInfo *, PageInfo *))1;
        (*(void (__thiscall **)(char *, signed int))v8)(v7, 1);
      }
      v9 = (char *)&rhs.m_Title.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&rhs.m_Title.m_charbuffer[-1].m_data[8]) && v9 )
      {
        v10 = *(_DWORD *)v9;
        v15 = (bool (__cdecl *)(PageInfo *, PageInfo *))1;
        (*(void (__thiscall **)(char *, signed int))v10)(v9, 1);
      }
      v11 = (char *)&rhs.m_Label.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&rhs.m_Label.m_charbuffer[-1].m_data[8]) && v11 )
      {
        v12 = *(_DWORD *)v11;
        v15 = (bool (__cdecl *)(PageInfo *, PageInfo *))1;
        (*(void (__thiscall **)(char *, signed int))v12)(v11, 1);
      }
      v5 = __comp;
    }
  }
  _STL::sort_heap(__first, __middle, v5);
}

//----- (00493FE0) --------------------------------------------------------  // acclient.c:206756
void __userpurge gmPageListUI::gmPageListUI(gmPageListUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmPageListUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmPageListUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_PageListPages._M_start = 0;
  v4->m_PageListPages._M_finish = 0;
  v4->m_PageListPages._M_end_of_storage._M_data = 0;
  v4->m_pPageListBox = 0;
  v4->m_pSearchEditBox = 0;
  v4->m_SortCriteria = 0;
  v4->m_ReverseSort = 0;
  LODWORD(v4->m_LastClickTime) = 0;
  HIDWORD(v4->m_LastClickTime) = 0;
  LODWORD(v4->m_timeNextUpdate) = 0;
  HIDWORD(v4->m_timeNextUpdate) = 0;
  v4->m_LastClickIndex = -1;
}
// 7A60E8: using guessed type int (__thiscall *gmPageListUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00494070) --------------------------------------------------------  // acclient.c:206782
gmPageListUI *__thiscall gmPageListUI::DynamicCast(gmPageListUI *this, unsigned int i_eType)
{
  gmPageListUI *result; // eax@1

  result = this;
  if ( i_eType != 268435529 )
    result = (gmPageListUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00494090) --------------------------------------------------------  // acclient.c:206793
signed int gmPageListUI::GetUIElementType()
{
  return 268435529;
}

//----- (004940A0) --------------------------------------------------------  // acclient.c:206799
void __thiscall gmPageListUI::~gmPageListUI(gmPageListUI *this)
{
  gmPageListUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1
  void *v4; // eax@3
  gmPageListUI *v5; // [sp+2h] [bp-4h]@1

  v5 = this;
  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmPageListUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  _STL::__destroy_aux(v1->m_PageListPages._M_start, v1->m_PageListPages._M_finish);
  v4 = v1->m_PageListPages._M_start;
  if ( v4 )
    _STL::__node_alloc<1,0>::deallocate(
      v4,
      (signed int)((char *)v1->m_PageListPages._M_end_of_storage._M_data - (char *)v4) >> 6 << 6);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A60E8: using guessed type int (__thiscall *gmPageListUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00494130) --------------------------------------------------------  // acclient.c:206830
void __usercall gmPageListUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmPageListUI *v3; // eax@1

  v3 = (gmPageListUI *)operator new(0x630u);
  if ( v3 )
    gmPageListUI::gmPageListUI(v3, a1, _layout, _full_desc);
}

//----- (00494160) --------------------------------------------------------  // acclient.c:206840
void __thiscall _STL::vector<PageInfo,_STL::allocator<PageInfo>>::_M_insert_overflow(_STL::vector<PageInfo,_STL::allocator<PageInfo> > *this, PageInfo *__position, PageInfo *__x, _STL::__false_type *__formal, unsigned int __fill_len, bool __atend)
{
  _STL::vector<PageInfo,_STL::allocator<PageInfo> > *v6; // ebx@1
  void *v7; // ecx@1
  int v8; // ecx@3
  bool v9; // zf@3
  const unsigned int v10; // ecx@3
  PageInfo *v11; // esi@8
  PageInfo *v12; // ebp@8
  PageInfo *i; // edi@8
  unsigned int v14; // edi@12
  PageInfo *v15; // ecx@25
  const unsigned int v16; // eax@25
  unsigned int v17; // [sp-4h] [bp-14h]@4
  PageInfo *__new_start; // [sp+8h] [bp-8h]@1
  const unsigned int __len; // [sp+Ch] [bp-4h]@3

  v6 = this;
  __new_start = (PageInfo *)(this->_M_finish - this->_M_start);
  v7 = &__fill_len;
  if ( (unsigned int)__new_start >= __fill_len )
    v7 = &__new_start;
  v8 = *(_DWORD *)v7;
  v9 = (PageInfo *)((char *)__new_start + v8) == 0;
  v10 = (const unsigned int)((char *)__new_start + v8);
  __len = v10;
  if ( v9 )
  {
    __new_start = 0;
  }
  else
  {
    v17 = v10 << 6;
    if ( v10 << 6 <= 0x80 )
      __new_start = (PageInfo *)_STL::__node_alloc<1,0>::_M_allocate(v17);
    else
      __new_start = (PageInfo *)operator new(v17);
  }
  v11 = __new_start;
  v12 = __position;
  for ( i = v6->_M_start; i != __position; ++v11 )
  {
    if ( v11 )
      PageInfo::PageInfo(v11, i);
    ++i;
  }
  v14 = __fill_len;
  if ( __fill_len == 1 )
  {
    if ( v11 )
      PageInfo::PageInfo(v11, __x);
    ++v11;
  }
  else if ( __fill_len )
  {
    do
    {
      if ( v11 )
        PageInfo::PageInfo(v11, __x);
      ++v11;
      --v14;
    }
    while ( v14 );
    v12 = __position;
  }
  if ( !__atend )
    v11 = _STL::__uninitialized_copy(v12, v6->_M_finish, v11);
  _STL::__destroy_aux(v6->_M_start, v6->_M_finish);
  if ( v6->_M_start )
    _STL::__node_alloc<1,0>::deallocate(v6->_M_start, (v6->_M_end_of_storage._M_data - v6->_M_start) << 6);
  v15 = __new_start;
  v16 = __len << 6;
  v6->_M_finish = v11;
  v6->_M_start = v15;
  v6->_M_end_of_storage._M_data = (PageInfo *)((char *)v15 + v16);
}

//----- (004942A0) --------------------------------------------------------  // acclient.c:206918
gmPageListUI *__thiscall gmPageListUI::vector_deleting_destructor(gmPageListUI *this, unsigned int a2)
{
  gmPageListUI *v2; // esi@1

  v2 = this;
  gmPageListUI::~gmPageListUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004942C0) --------------------------------------------------------  // acclient.c:206930
void __cdecl gmPageListUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000049u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmPageListUI::Create);
}

//----- (004942E0) --------------------------------------------------------  // acclient.c:206938
int __thiscall _STL::vector<PageInfo,_STL::allocator<PageInfo>>::insert(_STL::vector<PageInfo,_STL::allocator<PageInfo> > *this, PageInfo *__position, PageInfo *__x)
{
  _STL::vector<PageInfo,_STL::allocator<PageInfo> > *v3; // esi@1
  PageInfo *v4; // edx@1
  PageInfo *v5; // ecx@1
  signed int v6; // edi@1
  PageInfo *v7; // ecx@5
  int result; // eax@5
  PageInfo __x_copy; // [sp+Ch] [bp-40h]@8

  v3 = this;
  v4 = this->_M_start;
  v5 = this->_M_finish;
  v6 = __position - v4;
  if ( v5 == v3->_M_end_of_storage._M_data )
  {
    _STL::vector<PageInfo,_STL::allocator<PageInfo>>::_M_insert_overflow(
      v3,
      __position,
      __x,
      (_STL::__false_type *)&__x,
      1u,
      0);
    result = (int)&v3->_M_start[v6];
  }
  else if ( __position == v5 )
  {
    if ( v5 )
      PageInfo::PageInfo(v5, __x);
    v7 = v3->_M_start;
    ++v3->_M_finish;
    result = (int)&v7[v6];
  }
  else
  {
    if ( v5 )
      PageInfo::PageInfo(v5, v5 - 1);
    ++v3->_M_finish;
    PageInfo::PageInfo(&__x_copy, __x);
    _STL::__copy_backward(__position, v3->_M_finish - 2, v3->_M_finish - 1);
    PageInfo::operator=(__position, (int)&__x_copy);
    LookFile::~LookFile((LookFile *)&__x_copy);
    result = (int)&v3->_M_start[v6];
  }
  return result;
}

//----- (004943C0) --------------------------------------------------------  // acclient.c:206986
void __cdecl _STL::__introsort_loop(PageInfo *__first, PageInfo *__last, PageInfo *__formal, int __depth_limit, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  PageInfo *v5; // ebx@1
  PageInfo *v6; // esi@3
  bool v7; // zf@3
  PageInfo *v8; // esi@11
  PageInfo v9; // [sp-44h] [bp-54h]@11
  bool (__cdecl *v10)(PageInfo *, PageInfo *); // [sp-4h] [bp-14h]@3

  v5 = __last;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFC0) > 1024 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v6 = &__first[(v5 - __first) / 2];
      v7 = __comp(__first, &__first[(v5 - __first) / 2]) == 0;
      v10 = (bool (__cdecl *)(PageInfo *, PageInfo *))&v5[-1];
      if ( v7 )
      {
        if ( __comp(__first, (PageInfo *)v10) )
        {
          v6 = __first;
        }
        else if ( __comp(v6, v5 - 1) )
        {
          v6 = v5 - 1;
        }
      }
      else if ( !__comp(v6, (PageInfo *)v10) )
      {
        v6 = v5 - 1;
        if ( !__comp(__first, v5 - 1) )
          v6 = __first;
      }
      v10 = __comp;
      PageInfo::PageInfo(&v9, v6);
      v8 = _STL::__unguarded_partition(__first, v5, v9, v10);
      _STL::__introsort_loop(v8, v5, 0, __depth_limit, __comp);
      v5 = v8;
      if ( (signed int)(((char *)v8 - (char *)__first) & 0xFFFFFFC0) <= 1024 )
        return;
    }
    _STL::__partial_sort(__first, v5, v5, 0, __comp);
  }
}

//----- (004944B0) --------------------------------------------------------  // acclient.c:207034
void __thiscall gmPageListUI::RebuildPageList(gmPageListUI *this, const bool i_search)
{
  PStringBase<unsigned short> v2; // edi@1
  gmPageListUI *v3; // ebx@1
  PStringBase<unsigned short> *v4; // esi@2
  int v5; // edi@3
  char *v6; // esi@7
  PageInfo *v7; // esi@10
  int v8; // esi@10
  int v9; // edi@15
  unsigned int i; // [sp+10h] [bp-8h]@10
  PStringBase<unsigned short> result; // [sp+14h] [bp-4h]@2

  v2.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( i_search )
  {
    v4 = UIElement_Text::GetText(v3->m_pSearchEditBox, &result);
    if ( v2.m_charbuffer != v4->m_charbuffer )
    {
      v5 = (int)&v2.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v2.m_charbuffer = v4->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v4->m_charbuffer[-1].m_data[8]);
    }
    v6 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  }
  v7 = _STL::__copy(v3->m_PageListPages._M_finish, v3->m_PageListPages._M_finish, v3->m_PageListPages._M_start);
  _STL::__destroy_aux(v7, v3->m_PageListPages._M_finish);
  v3->m_PageListPages._M_finish = v7;
  v8 = 0;
  i = 0;
  if ( g_JournalPages._M_finish - g_JournalPages._M_start )
  {
    do
    {
      if ( !i_search
        || (InterlockedIncrement((volatile LONG *)&v2.m_charbuffer[-1].m_data[8]),
            gmPageListUI::PageContainsString(&g_JournalPages._M_start[v8], v2)) )
        _STL::vector<PageInfo,_STL::allocator<PageInfo>>::insert(
          &v3->m_PageListPages,
          v3->m_PageListPages._M_finish,
          &g_JournalPages._M_start[v8]);
      ++v8;
      ++i;
    }
    while ( i < g_JournalPages._M_finish - g_JournalPages._M_start );
  }
  v9 = (int)&v2.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
  {
    if ( v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
}

//----- (00494610) --------------------------------------------------------  // acclient.c:207095
void __cdecl _STL::sort(PageInfo *__first, PageInfo *__last, bool (__cdecl *__comp)(PageInfo *, PageInfo *))
{
  signed int v3; // eax@2
  int i; // ecx@2

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    _STL::__introsort_loop(__first, __last, 0, 2 * i, __comp);
    _STL::__final_insertion_sort(__first, __last, __comp);
  }
}

//----- (00494660) --------------------------------------------------------  // acclient.c:207111
void __thiscall gmPageListUI::SortPageList(gmPageListUI *this)
{
  gmPageListUI *v1; // esi@1
  bool v2; // al@3

  v1 = this;
  if ( this->m_SortCriteria == 1 )
  {
    if ( this->m_ReverseSort )
    {
      _STL::sort(this->m_PageListPages._M_start, this->m_PageListPages._M_finish, PageInfoReverseSortTitle);
      gmPageListUI::RebuildPageListbox(v1);
    }
    else
    {
      _STL::sort(this->m_PageListPages._M_start, this->m_PageListPages._M_finish, PageInfoSortTitle);
      gmPageListUI::RebuildPageListbox(v1);
    }
  }
  else if ( this->m_SortCriteria == 2 )
  {
    if ( this->m_ReverseSort )
    {
      _STL::sort(this->m_PageListPages._M_start, this->m_PageListPages._M_finish, PageInfoReverseSortLabel);
      gmPageListUI::RebuildPageListbox(v1);
    }
    else
    {
      _STL::sort(this->m_PageListPages._M_start, this->m_PageListPages._M_finish, PageInfoSortLabel);
      gmPageListUI::RebuildPageListbox(v1);
    }
  }
  else
  {
    v2 = this->m_ReverseSort;
    if ( this->m_SortCriteria == 3 )
    {
      if ( v2 )
      {
        _STL::sort(this->m_PageListPages._M_start, this->m_PageListPages._M_finish, PageInfoReverseSortTimer);
        gmPageListUI::RebuildPageListbox(v1);
      }
      else
      {
        _STL::sort(this->m_PageListPages._M_start, this->m_PageListPages._M_finish, PageInfoSortTimer);
        gmPageListUI::RebuildPageListbox(v1);
      }
    }
    else if ( v2 )
    {
      _STL::sort(this->m_PageListPages._M_start, this->m_PageListPages._M_finish, PageInfoReverseSortPageNumber);
      gmPageListUI::RebuildPageListbox(v1);
    }
    else
    {
      _STL::sort(
        this->m_PageListPages._M_start,
        this->m_PageListPages._M_finish,
        (bool (__cdecl *)(PageInfo *, PageInfo *))PageInfoSortPageNumber);
      gmPageListUI::RebuildPageListbox(v1);
    }
  }
}

//----- (004947C0) --------------------------------------------------------  // acclient.c:207176
int __thiscall gmPageListUI::ListenToElementMessage(gmPageListUI *this, UIElementMessageInfo *i_rMsg)
{
  gmPageListUI *v2; // esi@1
  unsigned int v3; // eax@4
  unsigned int v4; // edi@4
  JournalSortCriteria v6; // eax@10
  unsigned int v7; // eax@19

  v2 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    switch ( i_rMsg->idElement )
    {
      case 0x1000057Fu:
        if ( this->m_SortCriteria == ePageNumber )
          goto LABEL_15;
        this->m_SortCriteria = 0;
        this->m_ReverseSort = 0;
        goto LABEL_22;
      case 0x10000580u:
        v6 = 1;
        if ( this->m_SortCriteria != 1 )
          goto LABEL_16;
        this->m_ReverseSort = this->m_ReverseSort == 0;
        goto LABEL_22;
      case 0x10000581u:
        v6 = 3;
        if ( this->m_SortCriteria != 3 )
          goto LABEL_16;
        this->m_ReverseSort = this->m_ReverseSort == 0;
        goto LABEL_22;
      case 0x10000582u:
        v6 = 2;
        if ( this->m_SortCriteria == 2 )
        {
LABEL_15:
          this->m_ReverseSort = this->m_ReverseSort == 0;
        }
        else
        {
LABEL_16:
          this->m_SortCriteria = v6;
          this->m_ReverseSort = 0;
        }
        goto LABEL_22;
      case 0x10000586u:
        gmPageListUI::RebuildPageList(this, 1);
        goto LABEL_22;
      case 0x10000588u:
        UIElement_Text::ClearAllText(this->m_pSearchEditBox);
        gmPageListUI::RebuildPageList(v2, 0);
        gmPageListUI::SortPageList(v2);
        goto $L138578;
      case 0x10000585u:
$L138578:
        v7 = UIElement_ListBox::GetSelectedIndex(v2->m_pPageListBox);
        if ( v7 != -1 && g_JournalPanel )
        {
          gmJournalUI::DeletePage(g_JournalPanel, v2->m_PageListPages._M_start[v7].m_PageNumber);
          gmPageListUI::RebuildPageList(v2, 0);
LABEL_22:
          gmPageListUI::SortPageList(v2);
        }
        break;
      default:
        return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    }
  }
  else if ( i_rMsg->idMessage != 4 && i_rMsg->idMessage == 67 )
  {
    v3 = UIElement_ListBox::GetSelectedIndex(this->m_pPageListBox);
    v4 = v3;
    if ( v3 != -1 )
    {
      if ( gmPageListUI::CheckForDoubleClick(v2, v3) )
      {
        gmJournalUI::GotoPage(g_JournalPanel, v2->m_PageListPages._M_start[v4].m_PageNumber);
        ((void (__stdcall *)(_DWORD))g_JournalPanel->vfptr[2].__vecDelDtor)(1);
        return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
      }
    }
  }
  return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
}

//----- (00494980) --------------------------------------------------------  // acclient.c:207262
void __thiscall gmPageListUI::OnVisibilityChanged(gmPageListUI *this, bool i_bVisible)
{
  gmPageListUI *v2; // esi@1

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( i_bVisible )
  {
    gmPageListUI::RebuildPageList(v2, v2->m_pSearchEditBox->m_glyphList.m_glyphList._num_elements != 0);
    gmPageListUI::SortPageList(v2);
  }
}

//----- (006EE8F0) --------------------------------------------------------  // acclient.c:770637
void _E91_57()
{
  outside_val_49 = 1000.0 + 1.0;
}

//----- (006EE910) --------------------------------------------------------  // acclient.c:770643
void _E93_33()
{
  block_length_49 = 24.0 * 8.0;
}

//----- (006EE930) --------------------------------------------------------  // acclient.c:770649
void _E95_33()
{
  half_square_length_49 = 24.0 * 0.5;
}

//----- (006EE950) --------------------------------------------------------  // acclient.c:770655
int _E97_58()
{
  return atexit(_E98_70);
}

//----- (006EE960) --------------------------------------------------------  // acclient.c:770661
int _E100_51()
{
  return atexit(_E101_88);
}

//----- (006EE970) --------------------------------------------------------  // acclient.c:770667
int _E103_43()
{
  return atexit(_E104_58);
}

//----- (006EE980) --------------------------------------------------------  // acclient.c:770673
int _E106_33()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_21, "Misc.TooltipEnable");
  return atexit(_E107_71);
}

//----- (006EE9A0) --------------------------------------------------------  // acclient.c:770680
int _E109_21()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_21, "Misc.TooltipDelay");
  return atexit(sub_75F990);
}

//----- (006EE9C0) --------------------------------------------------------  // acclient.c:770687
int sub_6EE9C0()
{
  return atexit(nullsub_880);
}

//----- (0075F960) --------------------------------------------------------  // acclient.c:887393
void __cdecl _E107_71()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F990) --------------------------------------------------------  // acclient.c:887406
void __cdecl sub_75F990()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

