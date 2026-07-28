/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmSpewBoxUI
   Object     : GAME\game_ui_misc\gmSpewBoxUI.obj
   Functions  : 28
   Addresses  : 004D57C0 - 00761DA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D57C0) --------------------------------------------------------  // acclient.c:261091
int __thiscall gmSpewBoxUI::ListenToElementMessage(gmSpewBoxUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // edi@1

  v2 = (UIElement *)this;
  if ( i_rMsg->idElement == 268435530 && i_rMsg->idMessage == 268435459 )
    UIElement_ListBox::DeleteItem(this->m_listBox, i_rMsg->pElement);
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004D5800) --------------------------------------------------------  // acclient.c:261102
void __thiscall SmartArray<StringInfo,1>::Reset(SmartArray<StringInfo,1> *this)
{
  SmartArray<StringInfo,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  StringInfo *v4; // ecx@2
  PSRefBufferCharData<char> *v5; // eax@3
  void *v6; // ebp@3
  StringInfo *v7; // esi@3
  int v8; // eax@3
  int v9; // ebx@4
  int v10; // eax@9
  int v11; // esi@10
  int v12; // ebx@10
  int v13; // eax@11
  StringInfo v14; // [sp+Ch] [bp-90h]@11

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      v5 = v4[-1].m_strComment.m_charbuffer;
      v6 = &v4[-1].m_strComment;
      v7 = &v4[(_DWORD)v5];
      v8 = (int)&v5[-1].m_data[15];
      if ( v8 >= 0 )
      {
        v9 = v8 + 1;
        do
        {
          --v7;
          StringInfo::~StringInfo(v7);
          --v9;
        }
        while ( v9 );
      }
      operator delete[](v6);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v10 = (v2 & 0x7FFFFFFF) - 1;
    if ( v10 >= 0 )
    {
      v11 = v10;
      v12 = v10 + 1;
      do
      {
        StringInfo::StringInfo(&v14);
        StringInfo::operator=(&v1->m_data[v11], v13);
        StringInfo::~StringInfo(&v14);
        --v11;
        --v12;
      }
      while ( v12 );
    }
  }
}

//----- (004D58C0) --------------------------------------------------------  // acclient.c:261169
void __thiscall SmartArray<StringInfo,1>::~SmartArray<StringInfo,1>(SmartArray<StringInfo,1> *this)
{
  StringInfo *v1; // ecx@2
  PSRefBufferCharData<char> *v2; // eax@3
  void *v3; // ebx@3
  StringInfo *v4; // esi@3
  int v5; // eax@3
  int v6; // edi@4

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
    {
      v2 = v1[-1].m_strComment.m_charbuffer;
      v3 = &v1[-1].m_strComment;
      v4 = &v1[(_DWORD)v2];
      v5 = (int)&v2[-1].m_data[15];
      if ( v5 >= 0 )
      {
        v6 = v5 + 1;
        do
        {
          --v4;
          StringInfo::~StringInfo(v4);
          --v6;
        }
        while ( v6 );
      }
      operator delete[](v3);
    }
  }
}

//----- (004D5910) --------------------------------------------------------  // acclient.c:261204
char __thiscall SmartArray<StringInfo,1>::grow(SmartArray<StringInfo,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<StringInfo,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  StringInfo *v9; // ecx@12
  PSRefBufferCharData<char> *v10; // eax@13
  void *v11; // edx@13
  StringInfo *v12; // esi@13
  int v13; // eax@13
  int v14; // [sp+Ch] [bp-4h]@13
  unsigned int i_nSizea; // [sp+14h] [bp+4h]@9
  unsigned int i_nSizeb; // [sp+14h] [bp+4h]@14

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<StringInfo,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](144 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x90u,
        i_nSize,
        (void *(__thiscall *)(void *))StringInfo::StringInfo);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              StringInfo::operator=((StringInfo *)(v8 * 144 + v6), (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v9 = v3->m_data;
            if ( v3->m_data )
            {
              v10 = v9[-1].m_strComment.m_charbuffer;
              v11 = &v9[-1].m_strComment;
              v12 = &v9[(_DWORD)v10];
              v13 = (int)&v10[-1].m_data[15];
              v14 = (int)&v9[-1].m_strComment;
              if ( v13 >= 0 )
              {
                i_nSizeb = v13 + 1;
                do
                {
                  --v12;
                  StringInfo::~StringInfo(v12);
                  --i_nSizeb;
                }
                while ( i_nSizeb );
                v11 = (void *)v14;
              }
              operator delete[](v11);
            }
          }
        }
        v3->m_data = (StringInfo *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (004D5A30) --------------------------------------------------------  // acclient.c:261295
void __userpurge gmSpewBoxUI::gmSpewBoxUI(gmSpewBoxUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSpewBoxUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmSpewBoxUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmSpewBoxUI::vftable;
  v4->m_spewBoxPending.m_data = 0;
  v4->m_spewBoxPending.m_sizeAndDeallocate = 0;
  v4->m_spewBoxPending.m_num = 0;
}
// 7BCCB0: using guessed type bool (__thiscall *gmSpewBoxUI::vftable)(DBCache *this);
// 7BCF58: using guessed type int (__thiscall *gmSpewBoxUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004D5A80) --------------------------------------------------------  // acclient.c:261313
gmSpewBoxUI *__thiscall gmSpewBoxUI::DynamicCast(gmSpewBoxUI *this, unsigned int i_eType)
{
  gmSpewBoxUI *result; // eax@1

  result = this;
  if ( i_eType != 268435478 )
    result = (gmSpewBoxUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004D5AA0) --------------------------------------------------------  // acclient.c:261324
signed int gmSpewBoxUI::GetUIElementType()
{
  return 268435478;
}

//----- (004D5AB0) --------------------------------------------------------  // acclient.c:261330
void __thiscall gmSpewBoxUI::PostInit(gmSpewBoxUI *this)
{
  gmSpewBoxUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement_ListBox *v4; // ecx@5
  BasePropertyValue *v5; // ecx@6
  BasePropertyDesc *v6; // ecx@12
  unsigned int v7; // edx@12
  bool v8; // zf@16
  GlobalEventHandler *v9; // eax@18
  BaseProperty prop; // [sp+18h] [bp-8h]@5

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  ((void (__thiscall *)(gmSpewBoxUI *, signed int))v1->vfptr[2].OnLoseFocus)(v1, 1);
  ((void (__thiscall *)(gmSpewBoxUI *, _DWORD))v1->vfptr[22].OnLoseFocus)(v1, 0);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000049u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
  else
    v3 = 0;
  v1->m_listBox = (UIElement_ListBox *)v3;
  if ( !v3 )
    goto LABEL_18;
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 272))(v3, 0);
  v4 = v1->m_listBox;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( !(unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v4->vfptr[17].OnAction)(268435496, &prop) )
    goto LABEL_10;
  v5 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( !(unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&v1->m_maxConcurrentItems) )
    {
      v5 = prop.m_pcPropertyValue;
      goto LABEL_9;
    }
LABEL_10:
    v5 = prop.m_pcPropertyValue;
    goto LABEL_11;
  }
LABEL_9:
  v1->m_maxConcurrentItems = 1;
LABEL_11:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v6 = prop.m_pcPropertyDesc;
    v7 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    v5 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v5 )
  {
    v8 = v5->m_cRef-- == 1;
    if ( v8 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  }
LABEL_18:
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  v9 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v9 )
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, 100022u, (NoticeHandler *)&v1->vfptr);
}

//----- (004D5BD0) --------------------------------------------------------  // acclient.c:261400
void __thiscall gmSpewBoxUI::~gmSpewBoxUI(gmSpewBoxUI *this)
{
  gmSpewBoxUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmSpewBoxUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmSpewBoxUI::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v1->m_listBox = 0;
  SmartArray<StringInfo,1>::~SmartArray<StringInfo,1>(&v1->m_spewBoxPending);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7BCCB0: using guessed type bool (__thiscall *gmSpewBoxUI::vftable)(DBCache *this);
// 7BCF58: using guessed type int (__thiscall *gmSpewBoxUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004D5C30) --------------------------------------------------------  // acclient.c:261425
void __usercall gmSpewBoxUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmSpewBoxUI *v3; // eax@1

  v3 = (gmSpewBoxUI *)operator new(0x610u);
  if ( v3 )
    gmSpewBoxUI::gmSpewBoxUI(v3, a1, _layout, _full_desc);
}

//----- (004D5C60) --------------------------------------------------------  // acclient.c:261435
void __thiscall PStringBase<unsigned short>::trim(PStringBase<unsigned short> *this, bool pre, bool post, PStringBase<unsigned short> filter)
{
  PStringBase<unsigned short> *v4; // ebx@1
  PSRefBufferCharData<unsigned short> *v5; // edi@1
  unsigned int v6; // esi@1
  wchar_t i; // ax@2
  wchar_t *v8; // ebx@7
  PStringBase<unsigned short> v9; // eax@11
  char *v10; // esi@13
  LONG v11; // eax@13
  PSRefBufferCharData<unsigned short> *v12; // ebp@14
  PSRefBufferCharData<unsigned short> *v13; // eax@14
  int v14; // ebx@15
  volatile LONG *v15; // ST04_4@18
  PStringBase<unsigned short> *v16; // [sp+10h] [bp-4h]@1

  v4 = this;
  v5 = this->m_charbuffer;
  v6 = *(_DWORD *)&this->m_charbuffer[-1].m_data[14] - 1;
  v16 = this;
  if ( pre )
  {
    for ( i = v5->m_data[0]; i; --v6 )
    {
      if ( !_wcschr(filter.m_charbuffer->m_data, i) )
        break;
      i = v5->m_data[1];
      v5 = (PSRefBufferCharData<unsigned short> *)((char *)v5 + 2);
    }
  }
  if ( post && v6 )
  {
    v8 = &v5->m_data[v6 - 1];
    do
    {
      if ( !_wcschr(filter.m_charbuffer->m_data, *v8) )
        break;
      --v6;
      --v8;
    }
    while ( v6 );
    v4 = v16;
  }
  v9.m_charbuffer = v4->m_charbuffer;
  if ( v5 != v4->m_charbuffer || v6 != *(_DWORD *)&v9.m_charbuffer[-1].m_data[14] - 1 )
  {
    v12 = v4->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v9.m_charbuffer[-1].m_data[8]);
    v13 = v4->m_charbuffer;
    if ( (wchar_t *)v4->m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
    {
      v14 = (int)&v13[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v13[-1].m_data[8]) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      v15 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
      v16->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement(v15);
      v4 = v16;
    }
    if ( v6 )
      PStringBase<unsigned short>::append_n_chars(v4, v5->m_data, v6);
    if ( !InterlockedDecrement((volatile LONG *)&v12[-1].m_data[8]) && v12 != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v12[-1].m_data[6])(&v12[-1].m_data[6], 1);
    v10 = (char *)&filter.m_charbuffer[-1].m_data[6];
    v11 = InterlockedDecrement((volatile LONG *)&filter.m_charbuffer[-1].m_data[8]);
  }
  else
  {
    v10 = (char *)&filter.m_charbuffer[-1].m_data[6];
    v11 = InterlockedDecrement((volatile LONG *)&filter.m_charbuffer[-1].m_data[8]);
  }
  if ( !v11 )
  {
    if ( v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  }
}

//----- (004D5DB0) --------------------------------------------------------  // acclient.c:261514
gmSpewBoxUI *__thiscall gmSpewBoxUI::vector_deleting_destructor(gmSpewBoxUI *this, unsigned int a2)
{
  gmSpewBoxUI *v2; // esi@1

  v2 = this;
  gmSpewBoxUI::~gmSpewBoxUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D5DD0) --------------------------------------------------------  // acclient.c:261526
void __cdecl gmSpewBoxUI::Register()
{
  UIElement::RegisterElementClass(0x10000016u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmSpewBoxUI::Create);
}

//----- (004D5DF0) --------------------------------------------------------  // acclient.c:261532
void __thiscall gmSpewBoxUI::Update(gmSpewBoxUI *this)
{
  gmSpewBoxUI *v1; // edi@1
  unsigned int v2; // eax@2
  char v3; // bl@2
  int v4; // eax@4
  int v5; // esi@5
  PStringBase<unsigned short> v6; // ST08_4@6
  int v7; // ebx@6
  int v8; // ST08_4@6
  int v9; // eax@6
  int v10; // ebx@6
  int v11; // ST08_4@6
  int v12; // eax@6
  UIElement_ListBox *v13; // ecx@6
  UIElement *v14; // eax@7
  UIElement_Text *v15; // eax@7
  PSRefBufferCharData<unsigned short> *v16; // eax@8
  bool v17; // bl@9
  int v18; // ecx@10
  int v19; // ebx@10
  char *v20; // ebp@15
  UIElement_ListBox *v21; // ecx@20
  int v22; // eax@20
  char *v23; // esi@22
  bool v24; // cf@25
  UIElement_ListBox *v25; // ecx@27
  PStringBase<unsigned short> spew_text; // [sp+1Ch] [bp-14h]@6
  unsigned int v27; // [sp+20h] [bp-10h]@3
  unsigned int index; // [sp+24h] [bp-Ch]@2
  PStringBase<unsigned short> result; // [sp+28h] [bp-8h]@8
  UIElement_Text *pText; // [sp+2Ch] [bp-4h]@7

  v1 = this;
  if ( this->m_listBox )
  {
    v2 = this->m_spewBoxPending.m_num;
    v3 = 0;
    index = 0;
    if ( v2 )
    {
      v27 = 0;
      do
      {
        v4 = UIElementManager::CreateChildElementByEnum(UIElementManager::s_pInstance, 0, 0x10000012u, 0x1000004Au);
        if ( v4 )
        {
          v5 = (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v4 + 148))(v4, 12);
          if ( v5 )
          {
            StringInfo::GetString(&v1->m_spewBoxPending.m_data[v27 / 0x90], &spew_text, 0);
            v6.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::whitespace_string;
            InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4);
            PStringBase<unsigned short>::trim(&spew_text, 0, 1, v6);
            UIElement_Text::SetText((UIElement_Text *)v5, &spew_text);
            v7 = *(_DWORD *)v5;
            v8 = UIRegion::GetHeight((UIRegion *)v5);
            v9 = UIRegion::GetWidth((UIRegion *)&v1->m_listBox->vfptr);
            (*(void (__thiscall **)(int, int, int))(v7 + 48))(v5, v9, v8);
            UIElement_Text::RecalculateGlyphList((UIElement_Text *)v5);
            v10 = *(_DWORD *)v5;
            v11 = *(_DWORD *)(v5 + 1540);
            v12 = UIRegion::GetWidth((UIRegion *)&v1->m_listBox->vfptr);
            (*(void (__thiscall **)(int, int, int))(v10 + 48))(v5, v12, v11);
            v13 = v1->m_listBox;
            if ( (signed int)v13->m_listItems.m_num >= 1 )
            {
              v14 = UIElement_ListBox::GetItem(v13, 0);
              v15 = (UIElement_Text *)v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)12);
              pText = v15;
              if ( v15 )
              {
                v16 = UIElement_Text::GetText(v15, &result)->m_charbuffer;
                if ( *(_DWORD *)&spew_text.m_charbuffer[-1].m_data[14] == *(_DWORD *)&v16[-1].m_data[14] )
                {
                  v18 = *(_DWORD *)&spew_text.m_charbuffer[-1].m_data[12];
                  v19 = *(_DWORD *)&v16[-1].m_data[12];
                  if ( v18 == v19 || v18 == -1 || v19 == -1 )
                    v17 = _wcscmp(spew_text.m_charbuffer->m_data, v16->m_data) == 0;
                  else
                    v17 = 0;
                }
                else
                {
                  v17 = 0;
                }
                v20 = (char *)&result.m_charbuffer[-1].m_data[6];
                if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v20 )
                  (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
                if ( v17 )
                  UIElement_ListBox::DeleteItem(v1->m_listBox, (UIElement *)&pText->vfptr);
              }
            }
            UIElement_ListBox::InsertItem(v1->m_listBox, (UIElement *)v5, 0);
            v21 = v1->m_listBox;
            v22 = v21->m_listItems.m_num;
            if ( v22 > v1->m_maxConcurrentItems )
              UIElement_ListBox::DeleteItem(v21, v22 - 1);
            v23 = (char *)&spew_text.m_charbuffer[-1].m_data[6];
            v3 = 1;
            if ( !InterlockedDecrement((volatile LONG *)&spew_text.m_charbuffer[-1].m_data[8]) && v23 )
              (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
          }
        }
        v24 = index++ + 1 < v1->m_spewBoxPending.m_num;
        v27 += 144;
      }
      while ( v24 );
      if ( v3 )
      {
        v25 = v1->m_listBox;
        if ( v25->m_listItems.m_num )
          UIElement_ListBox::ScrollToShow(v25, 0);
        v1->m_spewBoxPending.m_num = 0;
      }
    }
  }
}

//----- (004D6040) --------------------------------------------------------  // acclient.c:261652
char __thiscall SmartArray<StringInfo,1>::AddToEnd(SmartArray<StringInfo,1> *this, StringInfo *i_rData)
{
  SmartArray<StringInfo,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<StringInfo,1>::grow(v2, v4)) != 0) )
  {
    StringInfo::operator=(&v2->m_data[v2->m_num++], (int)i_rData);
    result = 1;
  }
  return result;
}

//----- (004D6090) --------------------------------------------------------  // acclient.c:261672
void __thiscall gmSpewBoxUI::ListenToGlobalMessage(gmSpewBoxUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 3 )
    gmSpewBoxUI::Update(this);
}

//----- (004D60A0) --------------------------------------------------------  // acclient.c:261679
void __thiscall gmSpewBoxUI::RecvNotice_DisplayFinalStringInfo(gmSpewBoxUI *this, unsigned int i_type, StringInfo *i_siMsg, StringInfo *i_siPrefix, unsigned int i_idDestinationOverride)
{
  if ( i_type == 26 )
    SmartArray<StringInfo,1>::AddToEnd(
      (SmartArray<StringInfo,1> *)&this->m_hashElementsRegisteredWith.m_intrusiveTable,
      i_siMsg);
}

//----- (006F47D0) --------------------------------------------------------  // acclient.c:777122
void sub_6F47D0()
{
  flt_8400A8 = 1000.0 + 1.0;
}

//----- (006F47F0) --------------------------------------------------------  // acclient.c:777128
void _E93_83()
{
  flt_8400AC = 24.0 * 8.0;
}

//----- (006F4810) --------------------------------------------------------  // acclient.c:777134
void _E95_83()
{
  flt_8400B0 = 24.0 * 0.5;
}

//----- (006F4830) --------------------------------------------------------  // acclient.c:777140
int sub_6F4830()
{
  return atexit(nullsub_646);
}

//----- (006F4840) --------------------------------------------------------  // acclient.c:777146
int sub_6F4840()
{
  return atexit(nullsub_647);
}

//----- (006F4850) --------------------------------------------------------  // acclient.c:777152
int _E103_93()
{
  return atexit(nullsub_648);
}

//----- (006F4860) --------------------------------------------------------  // acclient.c:777158
int _E106_66()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_35, "Misc.TooltipEnable");
  return atexit(_E107_75);
}

//----- (006F4880) --------------------------------------------------------  // acclient.c:777165
int _E109_41()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_35, "Misc.TooltipDelay");
  return atexit(sub_761DA0);
}

//----- (006F48A0) --------------------------------------------------------  // acclient.c:777172
int sub_6F48A0()
{
  return atexit(nullsub_645);
}

//----- (00761D70) --------------------------------------------------------  // acclient.c:888918
void __cdecl _E107_75()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00761DA0) --------------------------------------------------------  // acclient.c:888931
void __cdecl sub_761DA0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

