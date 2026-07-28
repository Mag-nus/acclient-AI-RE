/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmBookUI
   Object     : GAME\game_ui_misc\gmBookUI.obj
   Functions  : 42
   Addresses  : 004BAA50 - 006F2110 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BAA50) --------------------------------------------------------  // acclient.c:237787
void __thiscall gmBookUI::OnObjectRangeExit(gmBookUI *this, unsigned int _objectID)
{
  if ( (HashSetData<UIElement *> *)_objectID == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4] )
    ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12][3].m_hashKey)(
      &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[12],
      0);
}

//----- (004BAA80) --------------------------------------------------------  // acclient.c:237796
void __userpurge gmBookUI::gmBookUI(gmBookUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmBookUI *v4; // esi@1
  volatile LONG *v5; // ST04_4@1
  volatile LONG *v6; // ST04_4@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&ObjectRangeHandler::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmBookUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmBookUI::vftable;
  v4->vfptr = (ObjectRangeHandlerVtbl *)&gmBookUI::vftable;
  v4->m_nextButton = 0;
  v4->m_prevButton = 0;
  v4->m_titleText = 0;
  v4->m_pageText = 0;
  v4->m_pageMenu = 0;
  v4->m_menuSelectionPageNumText = 0;
  v4->bookID = 0;
  v4->maxNumPages = 0;
  v4->pageDataList = 0;
  v4->curPage = -1;
  v4->requestPending = 0;
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v4->inscription.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v5);
  v4->scribeID = 0;
  v6 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v4->scribeName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v6);
}
// 7B2EEC: using guessed type void *ObjectRangeHandler::vftable;
// 7B2EF4: using guessed type void (__thiscall *gmBookUI::vftable)(gmBookUI *this, unsigned __int32);
// 7B2F00: using guessed type bool (__thiscall *gmBookUI::vftable)(DBCache *this);
// 7B31A8: using guessed type int (__thiscall *gmBookUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004BAB50) --------------------------------------------------------  // acclient.c:237836
gmBookUI *__thiscall gmBookUI::DynamicCast(gmBookUI *this, unsigned int i_eType)
{
  gmBookUI *result; // eax@1

  result = this;
  if ( i_eType != 268435481 )
    result = (gmBookUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004BAB70) --------------------------------------------------------  // acclient.c:237847
signed int gmBookUI::GetUIElementType()
{
  return 268435481;
}

//----- (004BAB80) --------------------------------------------------------  // acclient.c:237853
void __thiscall gmBookUI::~gmBookUI(gmBookUI *this)
{
  gmBookUI *v1; // esi@1
  NoticeHandler *v2; // ebx@1
  ObjectRangeHandler *v3; // ST04_4@1
  CPlayerSystem *v4; // eax@1
  GlobalEventHandler *v5; // eax@1
  AC1Legacy::PSRefBuffer<char> *v6; // edi@3
  AC1Legacy::PSRefBuffer<char> *v7; // edi@6

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (ObjectRangeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmBookUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmBookUI::vftable;
  this->vfptr = (ObjectRangeHandlerVtbl *)&gmBookUI::vftable;
  v4 = CPlayerSystem::GetPlayerSystem();
  CPlayerSystem::UnregisterAllObjectRangeHandlers(v4, v3);
  v5 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v5 )
    v5->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v5, v2);
  v6 = v1->scribeName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  v7 = v1->inscription.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7B2EF4: using guessed type void (__thiscall *gmBookUI::vftable)(gmBookUI *this, unsigned __int32);
// 7B2F00: using guessed type bool (__thiscall *gmBookUI::vftable)(DBCache *this);
// 7B31A8: using guessed type int (__thiscall *gmBookUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BAC20) --------------------------------------------------------  // acclient.c:237890
void __usercall gmBookUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmBookUI *v3; // eax@1

  v3 = (gmBookUI *)operator new(0x638u);
  if ( v3 )
    gmBookUI::gmBookUI(v3, a1, _layout, _full_desc);
}

//----- (004BAC50) --------------------------------------------------------  // acclient.c:237900
void __stdcall gmBookUI::SetEditable(UIElement_Text *text, int editable)
{
  int v3; // edx@2
  BasePropertyDesc *v4; // ecx@4
  unsigned int v5; // edx@4
  BasePropertyValue *v6; // ecx@8
  unsigned int v7; // edx@8
  BaseProperty p; // [sp+Ch] [bp-8h]@1

  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x16u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    v3 = editable;
    LOBYTE(v3) = editable != 0;
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(v3);
  }
  ((void (__stdcall *)(_DWORD))text->vfptr[17].OnLoseFocus)(&p);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v4 = p.m_pcPropertyDesc;
    v5 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v6 = p.m_pcPropertyValue;
    v7 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  }
}

//----- (004BACF0) --------------------------------------------------------  // acclient.c:237940
void __thiscall PageData::SetPageText(PageData *this, AC1Legacy::PStringBase<char> *_pageText)
{
  PageData *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@5

  v2 = this;
  v3 = this->pageText.m_buffer;
  if ( v3 != _pageText->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    }
    v4 = _pageText->m_buffer;
    v2->pageText.m_buffer = _pageText->m_buffer;
    InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  }
}

//----- (004BAD40) --------------------------------------------------------  // acclient.c:237962
gmBookUI *__thiscall gmBookUI::scalar_deleting_destructor(gmBookUI *this, unsigned int a2)
{
  gmBookUI *v2; // esi@1

  v2 = this;
  gmBookUI::~gmBookUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004BAD60) --------------------------------------------------------  // acclient.c:237974
void __thiscall gmBookUI::PostInit(gmBookUI *this)
{
  gmBookUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  UIElement *v7; // eax@8
  UIElement *v8; // eax@11
  int v9; // eax@12
  GlobalEventHandler *v10; // edi@15
  int v11; // esi@15

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000010Fu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    v3 = 0;
  v1->m_titleText = (UIElement_Text *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000111u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  v1->m_pageText = (UIElement_Text *)v5;
  v1->m_nextButton = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000115u);
  v1->m_prevButton = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000114u);
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000470u);
  if ( v6 )
    v7 = (UIElement *)v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)6);
  else
    v7 = 0;
  v1->m_pageMenu = (UIElement_Menu *)v7;
  if ( v7 )
  {
    v8 = UIElement::GetChildRecursive(v7, 0x1000047Bu);
    if ( v8 )
      v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
    else
      v9 = 0;
    v1->m_menuSelectionPageNumText = (UIElement_Text *)v9;
  }
  v10 = GlobalEventHandler::GetGlobalEventHandler();
  v11 = (int)&v1->vfptr;
  v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, (unsigned int)&loc_4DD1E9, (NoticeHandler *)v11);
  v10->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v10,
    (unsigned int)((char *)&loc_4DD1E9 + 1),
    (NoticeHandler *)v11);
  v10->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v10,
    (unsigned int)((char *)&loc_4DD1E9 + 2),
    (NoticeHandler *)v11);
  v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, (unsigned int)&loc_4DD1EC, (NoticeHandler *)v11);
}

//----- (004BAE70) --------------------------------------------------------  // acclient.c:238034
void __cdecl gmBookUI::Register()
{
  UIElement::RegisterElementClass(0x10000019u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmBookUI::Create);
}

//----- (004BAE90) --------------------------------------------------------  // acclient.c:238040
void __thiscall gmBookUI::AddPageInfo(gmBookUI *this, int _pageNum, StringInfo *_text)
{
  int v3; // edi@1
  UIElement *v4; // eax@1
  UIElement *v5; // eax@2
  UIElement_Text *v6; // esi@3
  PStringBase<unsigned short> *v7; // eax@4
  int v8; // esi@4

  v3 = _pageNum;
  v4 = UIElement_Menu::ReplaceTextItem(this->m_pageMenu, _text, _pageNum);
  if ( v4 )
  {
    v5 = UIElement::GetChildRecursive(v4, 0x10000479u);
    if ( v5 )
    {
      v6 = (UIElement_Text *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)12);
      if ( v6 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&_pageNum,
          0,
          L"Page %d",
          v3 + 1);
        UIElement_Text::SetText(v6, v7);
        v8 = _pageNum - 20;
        if ( !InterlockedDecrement((volatile LONG *)(_pageNum - 20 + 4)) )
        {
          if ( v8 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        }
      }
    }
  }
}

//----- (004BAF20) --------------------------------------------------------  // acclient.c:238077
void __thiscall gmBookUI::UpdateMenuSelectionInfo(gmBookUI *this, int _index)
{
  gmBookUI *v2; // esi@1
  PStringBase<unsigned short> *v3; // eax@2
  int v4; // esi@2

  v2 = this;
  if ( this->m_menuSelectionPageNumText )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&_index,
      0,
      L"Page %d",
      _index + 1);
    UIElement_Text::SetText(v2->m_menuSelectionPageNumText, v3);
    v4 = _index - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_index - 20 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
  }
}

//----- (004BAF80) --------------------------------------------------------  // acclient.c:238102
void __thiscall gmBookUI::UpdateMenu(gmBookUI *this)
{
  void *v1; // edi@1
  UIElement_Menu *v2; // ecx@1
  InterfaceSystem *v3; // eax@2
  Interface *v4; // esi@2
  int v5; // esi@6
  char *v6; // edi@8
  AC1Legacy::PStringBase<char> *v7; // eax@12
  char *v8; // edi@12
  AC1Legacy::PStringBase<char> *v9; // eax@15
  LONG v10; // eax@8
  int v11; // edi@19
  char *v12; // esi@21
  int i; // esi@24
  int v14; // [sp-8h] [bp-C4h]@2
  PStringBase<unsigned short> v15; // [sp+Ch] [bp-B0h]@1
  Interface *_rpInterface; // [sp+10h] [bp-ACh]@2
  int pNum; // [sp+14h] [bp-A8h]@4
  TResult result; // [sp+18h] [bp-A4h]@2
  PStringBase<unsigned short> menuText; // [sp+1Ch] [bp-A0h]@12
  PStringBase<unsigned short> _value; // [sp+20h] [bp-9Ch]@15
  InterfacePtr<PlayerDesc> spPD; // [sp+24h] [bp-98h]@2
  StringInfo siMenuText; // [sp+2Ch] [bp-90h]@2

  v1 = this;
  v2 = this->m_pageMenu;
  v15.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v1;
  UIElement_Menu::Flush(v2);
  if ( *((_DWORD *)v1 + 392) )
  {
    StringInfo::StringInfo(&siMenuText);
    _rpInterface = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &PlayerDesc_ClassType_10, &_rpInterface);
    v4 = _rpInterface;
    v14 = (int)_rpInterface;
    spPD.m_pInterface = 0;
    spPD.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    result.m_val = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&pNum, v14, 0);
    if ( v4 )
      v4->vfptr->Release(v4);
    v5 = *(_DWORD *)(*((_DWORD *)v1 + 392) + 4);
    pNum = 0;
    if ( v5 )
    {
      while ( 1 )
      {
        if ( StructPropertyValue::GetHash((PageData *)v5)->m_buffer->m_len == 1 )
        {
          _rpInterface = (Interface *)PStringBase<unsigned short>::s_NullBuffer;
          InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
          StringInfo::SetLiteralValue(&siMenuText, (PStringBase<unsigned short> *)&_rpInterface, 1);
          v6 = (char *)&_rpInterface[-5];
          v10 = InterlockedDecrement((volatile LONG *)&_rpInterface[-4]);
        }
        else
        {
          if ( (_DWORD)spPD.m_pInterface
            && (result.m_val & 0x80000000) == 0
            && PlayerDesc::PlayerIsPSR(spPD.m_pInterface) )
          {
            v7 = StructPropertyValue::GetHash((PageData *)v5);
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              &menuText,
              0,
              L"- %hs <%hs>",
              v7->m_buffer->m_data,
              *(_DWORD *)(v5 + 12) + 20);
            StringInfo::SetLiteralValue(&siMenuText, &menuText, 1);
            v8 = (char *)&menuText.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&menuText.m_charbuffer[-1].m_data[8]) && v8 )
              (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
            goto LABEL_19;
          }
          v9 = StructPropertyValue::GetHash((PageData *)v5);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, 0, L"- %hs", v9->m_buffer->m_data);
          StringInfo::SetLiteralValue(&siMenuText, &_value, 1);
          v6 = (char *)&_value.m_charbuffer[-1].m_data[6];
          v10 = InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]);
        }
        if ( !v10 && v6 )
          (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
LABEL_19:
        v11 = pNum;
        gmBookUI::AddPageInfo((gmBookUI *)v15.m_charbuffer, pNum, &siMenuText);
        v5 = *(_DWORD *)(v5 + 32);
        pNum = v11 + 1;
        if ( !v5 )
        {
          v1 = v15.m_charbuffer;
          break;
        }
      }
    }
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, L"(blank)");
    StringInfo::SetLiteralValue(&siMenuText, &v15, 1);
    v12 = (char *)&v15.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1].m_data[8]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    for ( i = *(_DWORD *)(*((_DWORD *)v1 + 392) + 12); i < *((_DWORD *)v1 + 391); ++i )
      gmBookUI::AddPageInfo((gmBookUI *)v1, i, &siMenuText);
    if ( (_DWORD)spPD.m_pInterface )
      ((void (*)(void))spPD.m_pInterface->vfptr->Release)();
    StringInfo::~StringInfo(&siMenuText);
  }
}

//----- (004BB1E0) --------------------------------------------------------  // acclient.c:238213
void __thiscall gmBookUI::DisplayPageData(gmBookUI *this, PageData *_pd)
{
  PageData *v2; // ebx@1
  gmBookUI *v3; // edi@1
  PStringBase<unsigned short> *v4; // eax@1
  char *v5; // esi@1
  unsigned int v6; // eax@5

  v2 = _pd;
  v3 = this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&_pd,
    0,
    _pd->pageText.m_buffer->m_data);
  UIElement_Text::SetText(v3->m_pageText, v4);
  v5 = (char *)&_pd[-1].textIncluded;
  if ( !InterlockedDecrement(&_pd[-1].ignoreAuthor) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  if ( SmartBox::smartbox )
    v6 = SmartBox::smartbox->player_id;
  else
    v6 = 0;
  if ( v2->authorID == v6 || v2->ignoreAuthor )
  {
    gmBookUI::SetEditable(v3->m_pageText, 1);
  }
  else
  {
    UIElement_Text::Deselect(v3->m_pageText);
    gmBookUI::SetEditable(v3->m_pageText, 0);
  }
}

//----- (004BB280) --------------------------------------------------------  // acclient.c:238247
int __thiscall gmBookUI::PageTextBlank(gmBookUI *this)
{
  gmBookUI *v1; // edi@1
  PStringBase<unsigned short> *v2; // eax@1
  char *v3; // esi@1
  unsigned int v4; // esi@4
  signed int v5; // ecx@4
  char v6; // al@5
  char *v7; // esi@9
  int v8; // eax@12
  char *v9; // esi@13
  PStringBase<unsigned short> result; // [sp+Ch] [bp-8h]@1
  PStringBase<char> pstrPageText; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = UIElement_Text::GetText(this->m_pageText, &result);
  PStringBase<unsigned short>::to_spstring(v2, &pstrPageText, 0);
  v3 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = v1->m_pageText->m_glyphList.m_glyphList._num_elements;
  v5 = 0;
  if ( (signed int)v4 <= 0 )
  {
LABEL_9:
    v7 = &pstrPageText.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&pstrPageText.m_charbuffer[-1]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    }
    v8 = 1;
  }
  else
  {
    while ( 1 )
    {
      v6 = pstrPageText.m_charbuffer->m_data[v5];
      if ( v6 != 32 && v6 != 10 && v6 )
        break;
      ++v5;
      if ( v5 >= (signed int)v4 )
        goto LABEL_9;
    }
    v9 = &pstrPageText.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&pstrPageText.m_charbuffer[-1]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    v8 = 0;
  }
  return v8;
}

//----- (004BB340) --------------------------------------------------------  // acclient.c:238300
int __thiscall gmBookUI::CloseCurPage(gmBookUI *this)
{
  gmBookUI *v1; // esi@1
  PageDataList *v2; // ecx@2
  PageData *v3; // edi@4
  unsigned int v4; // eax@6
  PStringBase<unsigned short> *v6; // eax@13
  AC1Legacy::PStringBase<char> *v7; // eax@13
  PStringBase<char> narrowText; // [sp+8h] [bp-Ch]@13
  PStringBase<unsigned short> result; // [sp+Ch] [bp-8h]@13
  AC1Legacy::PStringBase<char> v10; // [sp+10h] [bp-4h]@13

  v1 = this;
  if ( this->bookID )
  {
    v2 = this->pageDataList;
    if ( v2 )
    {
      if ( !v1->requestPending )
      {
        v3 = PageDataList::Get(v2, v1->curPage);
        if ( v3 )
        {
          v4 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
          if ( v3->authorID == v4 || v3->ignoreAuthor )
          {
            if ( gmBookUI::PageTextBlank(v1) && v3->authorID == GetPlayerID() )
            {
              CM_Writing::Event_BookDeletePage(v1->bookID, v1->curPage);
              PageDataList::Delete(v1->pageDataList, v1->curPage);
              gmBookUI::UpdateMenu(v1);
              return 1;
            }
            v6 = UIElement_Text::GetText(v1->m_pageText, &result);
            PStringBase<unsigned short>::to_spstring(v6, &narrowText, 0);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
            AC1Legacy::PStringBase<char>::PStringBase<char>(&v10, narrowText.m_charbuffer->m_data);
            PageData::SetPageText(v3, v7);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v10);
            CM_Writing::Event_BookModifyPage(v1->bookID, v1->curPage, &v3->pageText);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&narrowText);
          }
        }
      }
    }
  }
  return 0;
}

//----- (004BB470) --------------------------------------------------------  // acclient.c:238350
void __thiscall gmBookUI::BookPageDataResponseEvent(gmBookUI *this, unsigned int _bookID, int _pageNum, PageData *_pageData)
{
  gmBookUI *v4; // esi@1
  unsigned int v5; // eax@1
  PageData *v6; // eax@3
  int v7; // eax@4
  int v8; // edi@4
  PageData *v9; // eax@6

  v4 = this;
  v5 = this->bookID;
  if ( _bookID == v5 && v5 )
  {
    v6 = (PageData *)operator new(0x24u);
    if ( v6 )
    {
      PageData::PageData(v6);
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    PageData::operator=(v8, (int)_pageData);
    v9 = PageDataList::Remove(v4->pageDataList, _pageNum);
    if ( v9 )
      v9->vfptr->__vecDelDtor((PackObj *)v9, 1u);
    PageDataList::Insert(v4->pageDataList, (PageData *)v8, _pageNum);
    if ( _pageNum == v4->curPage )
      gmBookUI::DisplayPageData(v4, (PageData *)v8);
    v4->requestPending = 0;
  }
}

//----- (004BB500) --------------------------------------------------------  // acclient.c:238385
void __thiscall gmBookUI::CloseBook(gmBookUI *this)
{
  gmBookUI *v1; // esi@1
  PageDataList *v2; // ecx@1

  v1 = this;
  gmBookUI::CloseCurPage(this);
  v2 = v1->pageDataList;
  v1->bookID = 0;
  v1->maxNumPages = 0;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->pageDataList = 0;
  v1->curPage = -1;
  AC1Legacy::PStringBase<char>::set(&v1->inscription, &name);
  v1->scribeID = 0;
  AC1Legacy::PStringBase<char>::set(&v1->scribeName, &name);
  v1->requestPending = 0;
}

//----- (004BB570) --------------------------------------------------------  // acclient.c:238406
void __userpurge gmBookUI::SetCurPage(gmBookUI *this@<ecx>, int a2@<edi>, int _curPage)
{
  gmBookUI *v3; // esi@1
  PageDataList *v4; // ecx@1
  int v5; // edi@3
  PageData *v6; // ebx@6
  int v7; // eax@6
  int v8; // ecx@7
  PageDataList *v9; // ecx@16
  PageData *v10; // eax@16
  int v11; // edi@22
  UIElement *v12; // eax@23
  UIElement *v13; // ecx@24
  int v14; // ecx@27
  int v15; // eax@27
  bool v16; // sf@27
  unsigned __int8 v17; // of@27
  UIElement *v18; // ecx@27
  ACCWeenieObject *v19; // eax@30
  int v20; // edi@30
  UIElement *v21; // eax@31
  int v22; // [sp-8h] [bp-A4h]@3
  PStringBase<unsigned short> errorText; // [sp+4h] [bp-98h]@30
  CaseInsensitiveStringBase<PStringBase<char> > v24; // [sp+8h] [bp-94h]@30
  StringInfo siError; // [sp+Ch] [bp-90h]@30

  v3 = this;
  v4 = this->pageDataList;
  if ( !v4 )
    return;
  if ( v3->requestPending )
    return;
  v22 = a2;
  v5 = _curPage;
  if ( _curPage < 0 || _curPage >= v3->maxNumPages || _curPage == v3->curPage )
    return;
  v6 = PageDataList::Get(v4, v3->curPage);
  v7 = v3->pageDataList->numPages;
  if ( _curPage <= v7 )
  {
    v8 = v3->curPage;
    if ( v8 != v7 - 1
      || v8 == -1
      || _curPage <= v8
      || !gmBookUI::PageTextBlank(v3)
      || !v6
      || v6->authorID != GetPlayerID() )
    {
      if ( gmBookUI::CloseCurPage(v3) && _curPage > v3->curPage )
        v5 = _curPage - 1;
      v9 = v3->pageDataList;
      v3->curPage = v5;
      v10 = PageDataList::Get(v9, v5);
      if ( v10 )
      {
        if ( v10->textIncluded )
        {
          gmBookUI::DisplayPageData(v3, v10);
LABEL_22:
          v11 = v3->curPage;
          if ( UIElement_Menu::GetSelectedIndex(v3->m_pageMenu) != v11 )
          {
            v12 = UIElement_Menu::GetItem(v3->m_pageMenu, v11);
            UIElement_Menu::SetSelectedItem(v3->m_pageMenu, v12, 1);
          }
          v13 = v3->m_prevButton;
          if ( v3->curPage > 0 )
            ((void (__stdcall *)(signed int, int))v13->vfptr[13].__vecDelDtor)(1, v22);
          else
            ((void (__stdcall *)(signed int, int))v13->vfptr[13].__vecDelDtor)(13, v22);
          v14 = v3->curPage;
          v15 = v3->maxNumPages - 1;
          v17 = __OFSUB__(v14, v15);
          v16 = v14 - v15 < 0;
          v18 = v3->m_nextButton;
          if ( v16 ^ v17 )
            ((void (__cdecl *)(signed int))v18->vfptr[13].__vecDelDtor)(1);
          else
            ((void (__cdecl *)(signed int))v18->vfptr[13].__vecDelDtor)(13);
          return;
        }
        UIElement_Text::ClearAllText(v3->m_pageText);
        UIElement_Text::Deselect(v3->m_pageText);
        gmBookUI::SetEditable(v3->m_pageText, 0);
        CM_Writing::Event_BookPageData(v3->bookID, v3->curPage);
      }
      else
      {
        UIElement_Text::ClearAllText(v3->m_pageText);
        UIElement_Text::Deselect(v3->m_pageText);
        gmBookUI::SetEditable(v3->m_pageText, 0);
        CM_Writing::Event_BookAddPage(v3->bookID);
      }
      v3->requestPending = 1;
      goto LABEL_22;
    }
  }
  v19 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)&v24, (PStringBase<unsigned short> *)v3->bookID, 2u, 0);
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    &errorText,
    0,
    L"The %s is already open to a blank page",
    v19->vfptr);
  PStringBase<char>::~PStringBase<char>(&v24);
  StringInfo::StringInfo(&siError);
  StringInfo::SetLiteralValue(&siError, &errorText, 1);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  v20 = v3->curPage;
  if ( UIElement_Menu::GetSelectedIndex(v3->m_pageMenu) != v20 )
  {
    v21 = UIElement_Menu::GetItem(v3->m_pageMenu, v20);
    UIElement_Menu::SetSelectedItem(v3->m_pageMenu, v21, 1);
  }
  StringInfo::~StringInfo(&siError);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
}
// 4BB570: could not find valid save-restore pair for edi

//----- (004BB810) --------------------------------------------------------  // acclient.c:238525
void __thiscall gmBookUI::RecvNotice_BookPageDataResponse(gmBookUI *this, unsigned int i_bookID, int i_pageNum, PageData *i_pageData)
{
  gmBookUI::BookPageDataResponseEvent((gmBookUI *)((char *)this - 1528), i_bookID, i_pageNum, i_pageData);
}

//----- (004BB820) --------------------------------------------------------  // acclient.c:238531
void __thiscall gmBookUI::BookAddPageResponseEvent(gmBookUI *this, unsigned int _bookID, int _pageNum, int _success)
{
  char v4; // bl@1
  gmBookUI *v5; // esi@1
  unsigned int v6; // eax@1
  InterfacePtr<Interface> *v7; // eax@5
  PageData *v8; // edi@7
  AC1Legacy::PStringBase<char> *v9; // eax@8
  AC1Legacy::PStringBase<char> *v10; // ST0C_4@8
  AC1Legacy::PStringBase<char> *v11; // eax@8
  AC1Legacy::PStringBase<char> *v12; // ST08_4@8
  unsigned int v13; // eax@8
  int v14; // eax@8
  int v15; // edi@8
  AC1Legacy::PStringBase<char> *v16; // eax@14
  AC1Legacy::PStringBase<char> pcName; // [sp+8h] [bp-ACh]@5
  PStringBase<unsigned short> strAuthor; // [sp+Ch] [bp-A8h]@14
  InterfacePtr<Interface> result; // [sp+10h] [bp-A4h]@1
  AC1Legacy::PStringBase<char> v20; // [sp+18h] [bp-9Ch]@8
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-98h]@5
  StringInfo siMenuText; // [sp+24h] [bp-90h]@14

  v4 = 0;
  v5 = this;
  result.m_pInterface = 0;
  v6 = this->bookID;
  if ( _bookID != v6 || !v6 )
    return;
  if ( !_success )
  {
LABEL_22:
    CM_Writing::Event_BookData(v6);
    return;
  }
  if ( _pageNum != this->curPage )
  {
    this->curPage = _pageNum;
    goto LABEL_22;
  }
  pcName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v7 = GetClassObject(&result, &PlayerDesc_ClassType_10);
  InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&playerDesc, v7);
  if ( (_DWORD)result.m_pInterface )
    ((void (*)(void))result.m_pInterface->vfptr->Release)();
  CBaseQualities::InqString((CBaseQualities *)&playerDesc.m_pInterface->vfptr, 1u, &pcName);
  v8 = (PageData *)operator new(0x24u);
  if ( v8 )
  {
    v4 = 3;
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&result, &name);
    v10 = v9;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v20, &name);
    v12 = v11;
    v13 = GetPlayerID();
    PageData::PageData(v8, v13, &pcName, v12, v10, 0);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  if ( v4 & 2 )
  {
    v4 &= 0xFDu;
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v20);
  }
  if ( v4 & 1 )
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&result);
  PageDataList::Insert(v5->pageDataList, (PageData *)v15, _pageNum);
  v16 = StructPropertyValue::GetHash((PageData *)v15);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&strAuthor, 0, L"- %hs", v16->m_buffer->m_data);
  StringInfo::StringInfo(&siMenuText);
  StringInfo::SetLiteralValue(&siMenuText, &strAuthor, 1);
  gmBookUI::AddPageInfo(v5, _pageNum, &siMenuText);
  if ( _pageNum == v5->curPage )
  {
    gmBookUI::DisplayPageData(v5, (PageData *)v15);
  }
  else if ( !PageDataList::Get(v5->pageDataList, v5->curPage) )
  {
    gmBookUI::SetCurPage(v5, v15, _pageNum);
  }
  v5->requestPending = 0;
  StringInfo::~StringInfo(&siMenuText);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strAuthor);
  if ( (_DWORD)playerDesc.m_pInterface )
    ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
  CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&pcName);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004BBA10) --------------------------------------------------------  // acclient.c:238624
int __userpurge gmBookUI::ListenToElementMessage@<eax>(gmBookUI *this@<ecx>, int a2@<edi>, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v3; // esi@1
  unsigned int v4; // eax@1
  gmBookUI *v5; // ebp@1
  UIElement *v7; // ecx@8
  PageDataList *v8; // ecx@8
  PageData *v9; // eax@10
  PageData *v10; // ebx@10
  AC1Legacy::PStringBase<char> *v11; // eax@15
  int v12; // eax@20
  int v13; // eax@20
  bool bEditable; // [sp+Fh] [bp-99h]@8
  PStringBase<unsigned short> errorText; // [sp+10h] [bp-98h]@15
  PStringBase<unsigned short> _value; // [sp+14h] [bp-94h]@17
  StringInfo siError; // [sp+18h] [bp-90h]@15

  v3 = i_rMsg;
  v4 = i_rMsg->idMessage;
  v5 = this;
  if ( v4 == 1 )
  {
    if ( i_rMsg->idElement == 268435732 )
    {
      gmBookUI::SetCurPage(this, a2, this->curPage - 1);
      return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
    }
    if ( i_rMsg->idElement == 268435733 )
    {
      gmBookUI::SetCurPage(this, a2, this->curPage + 1);
      return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
    }
    return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
  }
  if ( v4 != 25 )
  {
    if ( v4 == 7 && i_rMsg->idElement == 268436592 )
    {
      v12 = UIElement_Menu::GetSelectedIndex(this->m_pageMenu);
      gmBookUI::SetCurPage(v5, a2, v12);
      v13 = UIElement_Menu::GetSelectedIndex(v5->m_pageMenu);
      gmBookUI::UpdateMenuSelectionInfo(v5, v13);
    }
    return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
  }
  if ( i_rMsg->idElement != 268435729 )
    return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
  v7 = (UIElement *)&this->m_pageText->vfptr;
  bEditable = 0;
  UIElement::GetAttribute_Bool(v7, 0x16u, &bEditable);
  v8 = v5->pageDataList;
  if ( !v8 )
    return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
  if ( bEditable )
    return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
  v9 = PageDataList::Get(v8, v5->curPage);
  v10 = v9;
  if ( !v9 )
    return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
  if ( v9->ignoreAuthor )
  {
    gmBookUI::SetEditable(v5->m_pageText, 1);
    return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
  }
  if ( StructPropertyValue::GetHash(v9)->m_buffer->m_len > 1 )
  {
    if ( memcmp(StructPropertyValue::GetHash(v10)->m_buffer->m_data, " ", 2u) )
    {
      v11 = StructPropertyValue::GetHash(v10);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"Only %hs can change this page",
        v11->m_buffer->m_data);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, i_rMsg);
    }
    v3 = i_rMsg;
  }
  StringInfo::StringInfo(&siError);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You cannot change this page");
  StringInfo::SetLiteralValue(&siError, &_value, 1);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
  StringInfo::~StringInfo(&siError);
  return UIElement::ListenToElementMessage((UIElement *)&v5->vfptr, v3);
}

//----- (004BBC60) --------------------------------------------------------  // acclient.c:238717
void __thiscall gmBookUI::OnVisibilityChanged(gmBookUI *this, bool i_bVisible)
{
  gmBookUI *v2; // esi@1
  CPlayerSystem *v3; // eax@3

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( (v2->m_nFlags >> 17) & 1 )
  {
    if ( !i_bVisible )
    {
      v3 = CPlayerSystem::GetPlayerSystem();
      CPlayerSystem::UnregisterAllObjectRangeHandlers(v3, (ObjectRangeHandler *)&v2->vfptr);
      gmBookUI::CloseBook(v2);
    }
  }
}

//----- (004BBCA0) --------------------------------------------------------  // acclient.c:238736
void __thiscall gmBookUI::OpenBook(gmBookUI *this, unsigned int _bookID, int _maxNumPages, PageDataList *_pageDataList, AC1Legacy::PStringBase<char> *_inscription, unsigned int _scribeID, AC1Legacy::PStringBase<char> *_scribeName)
{
  gmBookUI *v7; // esi@1
  unsigned int v8; // eax@1
  unsigned int v9; // ebx@1
  int v10; // edi@1
  int v11; // ecx@5
  PageDataList *v12; // eax@5
  int v13; // eax@6
  int v14; // ST2C_4@8
  unsigned int v15; // eax@8
  bool v16; // sf@8
  unsigned __int8 v17; // of@8
  int *v18; // eax@8
  AC1Legacy::PStringBase<char> *v19; // ebx@12
  AC1Legacy::PSRefBuffer<char> *v20; // edi@12
  AC1Legacy::PSRefBuffer<char> *v21; // eax@16
  AC1Legacy::PStringBase<char> *v22; // ebx@17
  AC1Legacy::PSRefBuffer<char> *v23; // edi@17
  AC1Legacy::PSRefBuffer<char> *v24; // eax@21
  char *v25; // eax@23
  PStringBase<unsigned short> *v26; // eax@25
  unsigned int v27; // edi@25
  HashBaseData<unsigned long> *v28; // eax@28
  HashBaseData<unsigned long> *v29; // edi@28
  long double _range; // ST10_8@30
  unsigned int v31; // ST0C_4@30
  CPlayerSystem *v32; // eax@30
  int pageToOpen; // [sp+40h] [bp-4h]@1

  v7 = this;
  ((void (__stdcall *)(signed int))this->vfptr[2].__vecDelDtor)(1);
  v8 = v7->bookID;
  v9 = _bookID;
  v10 = 0;
  pageToOpen = 0;
  if ( v8 == _bookID )
  {
    v10 = v7->curPage;
    pageToOpen = v7->curPage;
  }
  if ( v8 )
    gmBookUI::CloseBook(v7);
  v11 = _maxNumPages;
  v7->bookID = v9;
  v7->maxNumPages = v11;
  v12 = (PageDataList *)operator new(0x1Cu);
  if ( v12 )
    PageDataList::PageDataList(v12);
  else
    v13 = 0;
  v14 = (int)_pageDataList;
  v7->pageDataList = (PageDataList *)v13;
  PageDataList::operator=(v13, v14);
  gmBookUI::UpdateMenu(v7);
  v15 = v7->pageDataList->numPages - 1;
  _bookID = v15;
  v17 = __OFSUB__(v15, v10);
  v16 = ((v15 - v10) & 0x80000000) != 0;
  _maxNumPages = 0;
  v18 = (int *)&_bookID;
  if ( !(v16 ^ v17) )
    v18 = &pageToOpen;
  if ( *v18 < 0 )
    v18 = &_maxNumPages;
  gmBookUI::SetCurPage(v7, v10, *v18);
  v19 = _inscription;
  v20 = v7->inscription.m_buffer;
  if ( v20 != _inscription->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v20->m_cRef) && v20 )
      v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
    v21 = v19->m_buffer;
    v7->inscription.m_buffer = v19->m_buffer;
    InterlockedIncrement((volatile LONG *)&v21->m_cRef);
  }
  v22 = _scribeName;
  v7->scribeID = _scribeID;
  v23 = v7->scribeName.m_buffer;
  if ( v23 != v22->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v23->m_cRef) && v23 )
      v23->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v23, 1u);
    v24 = v22->m_buffer;
    v7->scribeName.m_buffer = v22->m_buffer;
    InterlockedIncrement((volatile LONG *)&v24->m_cRef);
  }
  if ( v7->scribeID )
    v25 = v7->inscription.m_buffer->m_data;
  else
    v25 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v7->bookID, 2u, 0);
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&_bookID, 0, v25);
  UIElement_Text::SetText(v7->m_titleText, v26);
  v27 = _bookID - 20;
  if ( !InterlockedDecrement((volatile LONG *)(_bookID - 20 + 4)) && v27 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
  v28 = ClientObjMaintSystem::GetWeenieObject(v7->bookID);
  v29 = v28;
  if ( v28 )
  {
    if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v28) )
    {
      _range = *(float *)&v29[18].hash_next;
      v31 = v7->bookID;
      v32 = CPlayerSystem::GetPlayerSystem();
      CPlayerSystem::RegisterObjectRangeHandler(v32, (ObjectRangeHandler *)&v7->vfptr, v31, _range, 1, 0, 1.0, 0.0);
    }
  }
}

//----- (004BBE90) --------------------------------------------------------  // acclient.c:238847
void __thiscall gmBookUI::RecvNotice_BookAddPageResponse(gmBookUI *this, unsigned int i_bookID, int i_pageNum, int i_success)
{
  gmBookUI::BookAddPageResponseEvent((gmBookUI *)((char *)this - 1528), i_bookID, i_pageNum, i_success);
}

//----- (004BBEA0) --------------------------------------------------------  // acclient.c:238853
void __thiscall gmBookUI::RecvNotice_OpenBook(gmBookUI *this, unsigned int i_bookID, int i_maxNumPages, PageDataList *i_pageDataList, AC1Legacy::PStringBase<char> *i_inscription, unsigned int i_scribeID, AC1Legacy::PStringBase<char> *i_scribeName)
{
  gmBookUI::OpenBook(
    (gmBookUI *)((char *)this - 1528),
    i_bookID,
    i_maxNumPages,
    i_pageDataList,
    i_inscription,
    i_scribeID,
    i_scribeName);
}

//----- (006F1FD0) --------------------------------------------------------  // acclient.c:774361
void _E91_80()
{
  outside_val_72 = 1000.0 + 1.0;
}

//----- (006F1FF0) --------------------------------------------------------  // acclient.c:774367
void _E93_56()
{
  block_length_72 = 24.0 * 8.0;
}

//----- (006F2010) --------------------------------------------------------  // acclient.c:774373
void _E95_56()
{
  half_square_length_72 = 24.0 * 0.5;
}

//----- (006F2030) --------------------------------------------------------  // acclient.c:774379
int _E97_81()
{
  return atexit(_E98_93);
}

//----- (006F2040) --------------------------------------------------------  // acclient.c:774385
int _E100_74()
{
  return atexit(nullsub_796);
}

//----- (006F2050) --------------------------------------------------------  // acclient.c:774391
int _E103_66()
{
  return atexit(_E104_81);
}

//----- (006F2060) --------------------------------------------------------  // acclient.c:774397
void _E107_5()
{
  LOWEST_DATA_RATE_80 = 1024;
}

//----- (006F2070) --------------------------------------------------------  // acclient.c:774403
void _E109_31()
{
  HIGHEST_DATA_RATE_80 = 0x7FFF;
}

//----- (006F2080) --------------------------------------------------------  // acclient.c:774409
int _E111_20()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_80;
  INITIAL_MAX_DATA_RATE_28 = LOWEST_DATA_RATE_80;
  return result;
}

//----- (006F2090) --------------------------------------------------------  // acclient.c:774419
int _E113_8()
{
  return atexit(_E114_75);
}

//----- (006F20A0) --------------------------------------------------------  // acclient.c:774425
void _E116_9()
{
  DEFAULT_VIEW_RADIUS_43 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F20C0) --------------------------------------------------------  // acclient.c:774431
void _E118_39()
{
  MIN_QUANTUM_43 = 1.0 / 30.0;
}

//----- (006F20E0) --------------------------------------------------------  // acclient.c:774437
void _E120_27()
{
  MAX_QUANTUM_43 = 1.0 / 5.0;
}

//----- (006F2100) --------------------------------------------------------  // acclient.c:774443
void _E122_13()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_78, PFID_A8R8G8B8);
}

//----- (006F2110) --------------------------------------------------------  // acclient.c:774449
int sub_6F2110()
{
  return atexit(nullsub_794);
}

