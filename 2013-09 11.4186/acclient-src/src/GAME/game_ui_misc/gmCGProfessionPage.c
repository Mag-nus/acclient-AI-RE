/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCGProfessionPage
   Object     : GAME\game_ui_misc\gmCGProfessionPage.obj
   Functions  : 34
   Addresses  : 00481EA0 - 006ED120 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00481EA0) --------------------------------------------------------  // acclient.c:190069
void __userpurge gmCGProfessionPage::gmCGProfessionPage(gmCGProfessionPage *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGProfessionPage *v4; // esi@1
  int v5; // eax@1
  signed int v6; // edx@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCGProfessionPage::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pPlayerSystem = 0;
  v4->m_pMainFramework = 0;
  v4->m_pAvailableValue = 0;
  v4->m_pHealthValue = 0;
  v4->m_pStaminaValue = 0;
  v4->m_pManaValue = 0;
  v4->m_pTextBox = 0;
  v4->m_pCurProfButton = 0;
  v5 = (int)v4->m_tSliderArray;
  v6 = 7;
  do
  {
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 12) = 0;
    *(_DWORD *)(v5 + 16) = 0;
    *(_BYTE *)(v5 + 20) = 0;
    v5 += 24;
    --v6;
  }
  while ( v6 );
}
// 7A0650: using guessed type int (__thiscall *gmCGProfessionPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00481F30) --------------------------------------------------------  // acclient.c:190107
gmCGProfessionPage *__thiscall gmCGProfessionPage::DynamicCast(gmCGProfessionPage *this, unsigned int i_eType)
{
  gmCGProfessionPage *result; // eax@1

  result = this;
  if ( i_eType != 268435514 )
    result = (gmCGProfessionPage *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00481F50) --------------------------------------------------------  // acclient.c:190118
signed int gmCGProfessionPage::GetUIElementType()
{
  return 268435514;
}

//----- (00481F60) --------------------------------------------------------  // acclient.c:190124
void __usercall gmCGProfessionPage::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGProfessionPage *v3; // eax@1

  v3 = (gmCGProfessionPage *)operator new(0x6C4u);
  if ( v3 )
    gmCGProfessionPage::gmCGProfessionPage(v3, a1, _layout, _full_desc);
}

//----- (00481F90) --------------------------------------------------------  // acclient.c:190134
int __stdcall gmCGProfessionPage::GetSliderIndex(UIElement *pSlider)
{
  int result; // eax@1

  result = 0;
  switch ( pSlider->m_desc.m_elementID )
  {
    case 0x100003E6u:
      result = 1;
      break;
    case 0x100003E7u:
      result = 2;
      break;
    case 0x100003E8u:
      result = 4;
      break;
    case 0x100003E9u:
      result = 3;
      break;
    case 0x100003EAu:
      result = 5;
      break;
    case 0x100003EBu:
      result = 6;
      break;
    default:
      return result;
  }
  return result;
}

//----- (00482000) --------------------------------------------------------  // acclient.c:190166
void __thiscall gmCGProfessionPage::SetLock(gmCGProfessionPage *this, UIElement *pSlider)
{
  gmCGProfessionPage *v2; // edi@1
  int v3; // esi@1
  int v4; // ebp@1
  UIElement_Scrollbar *v5; // ecx@2
  UIElement *v6; // ecx@5
  int v7; // ebx@5
  int v8; // ecx@6
  int v9; // ST04_4@9
  CharGenState *v10; // eax@9

  v2 = this;
  v3 = gmCGProfessionPage::GetSliderIndex(pSlider);
  v4 = (int)((char *)v2 + 8 * (3 * v3 + 198));
  if ( *(_BYTE *)v4 )
  {
    v5 = v2->m_tSliderArray[v3].pSlider;
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(268435480);
    ((void (__stdcall *)(signed int))v2->m_tSliderArray[v3].pLockButton->vfptr[13].__vecDelDtor)(268435480);
    *(_BYTE *)v4 = 0;
  }
  else
  {
    v6 = (UIElement *)&v2->m_tSliderArray[v3].pSlider->vfptr;
    v7 = (int)((char *)v2 + 24 * v3);
    pSlider = 0;
    if ( UIElement::GetAttribute_Float(v6, 0x86u, (float *)&pSlider) )
    {
      v8 = *(_DWORD *)(v7 + 1576);
      if ( v8 )
        (*(void (__stdcall **)(signed int))(*(_DWORD *)v8 + 156))(268435481);
    }
    (*(void (__stdcall **)(signed int))(**(_DWORD **)(v7 + 1568) + 156))(268435481);
    *(_BYTE *)v4 = 1;
  }
  v9 = *(_BYTE *)v4;
  CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
  CharGenState::LockAttribute(v10, v3, v9);
}

//----- (004820D0) --------------------------------------------------------  // acclient.c:190209
void __thiscall gmCGProfessionPage::ClearLocks(gmCGProfessionPage *this)
{
  gmCGProfessionPage *v1; // edi@1
  CharGenState *v2; // eax@1
  int v3; // esi@1
  signed int v4; // ebx@1

  v1 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  CharGenState::ResetAttributeLock(v2);
  v3 = (int)&v1->m_tSliderArray[1];
  v4 = 6;
  do
  {
    if ( *(_BYTE *)(v3 + 20) )
      gmCGProfessionPage::SetLock(v1, *(UIElement **)v3);
    v3 += 24;
    --v4;
  }
  while ( v4 );
}

//----- (00482110) --------------------------------------------------------  // acclient.c:190232
void __thiscall PStringBase<unsigned short>::to_float(PStringBase<unsigned short> *this)
{
  PSRefBufferCharData<unsigned short> *v1; // esi@1

  v1 = this->m_charbuffer;
  *__errno() = 0;
  _wcstod(v1->m_data, 0);
}

//----- (00482130) --------------------------------------------------------  // acclient.c:190242
UIElement_Field *__thiscall gmCGProfessionPage::vector_deleting_destructor(gmCGProfessionPage *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCGProfessionPage::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
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
// 7A0650: using guessed type int (__thiscall *gmCGProfessionPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00482190) --------------------------------------------------------  // acclient.c:190266
void __cdecl gmCGProfessionPage::Register()
{
  UIElement::RegisterElementClass(
    0x1000003Au,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCGProfessionPage::Create);
}

//----- (004821B0) --------------------------------------------------------  // acclient.c:190274
void __thiscall gmCGProfessionPage::UpdateProfession(gmCGProfessionPage *this)
{
  gmCGProfessionPage *v1; // edi@1
  UIElement_Button *v2; // ecx@1
  UIElement *v3; // esi@3
  int v4; // eax@3
  int v5; // ebx@3
  UIElement *v6; // ebx@4
  unsigned int v7; // eax@4
  int v8; // eax@12
  StringInfo siProf; // [sp+Ch] [bp-90h]@3

  v1 = this;
  v2 = this->m_pCurProfButton;
  if ( v2 )
    ((void (__stdcall *)(signed int))v2->vfptr[13].__vecDelDtor)(268435478);
  v3 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003D8u);
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  v5 = *(_DWORD *)(v4 + 384);
  StringInfo::StringInfo(&siProf);
  switch ( v5 )
  {
    case 0:
      v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003D9u);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435499u);
      v7 = compute_str_hash("ID_CharGen_CustomText");
      goto LABEL_11;
    case 1:
      v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003DAu);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435500u);
      v7 = compute_str_hash("ID_CharGen_BowText");
      goto LABEL_11;
    case 3:
      v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003DBu);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435501u);
      v7 = compute_str_hash("ID_CharGen_LifeText");
      goto LABEL_11;
    case 4:
      v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003DCu);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435502u);
      v7 = compute_str_hash("ID_CharGen_WarText");
      goto LABEL_11;
    case 5:
      v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003DDu);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435503u);
      v7 = compute_str_hash("ID_CharGen_WayText");
      goto LABEL_11;
    case 6:
      v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003DEu);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435504u);
      v7 = compute_str_hash("ID_CharGen_SoldierText");
      goto LABEL_11;
    case 2:
      v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100003DFu);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435505u);
      v7 = compute_str_hash("ID_CharGen_SwashText");
LABEL_11:
      StringInfo::SetStringIDandTableEnum(&siProf, v7, 268435458);
      if ( !v6 )
        goto LABEL_13;
      v8 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)1);
      break;
    default:
LABEL_13:
      v8 = 0;
      break;
  }
  v1->m_pCurProfButton = (UIElement_Button *)v8;
  (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v8 + 156))(v8, 268435479);
  UIElement_Text::SetStringInfo(v1->m_pTextBox, &siProf);
  StringInfo::~StringInfo(&siProf);
}

//----- (004823B0) --------------------------------------------------------  // acclient.c:190348
int __thiscall UIElement::GetChildRecursiveTemplate<UIElement_Scrollbar>(UIElement *this, unsigned int _ID)
{
  UIElement *v2; // eax@1
  int result; // eax@2

  v2 = UIElement::GetChildRecursive(this, _ID);
  if ( v2 )
    result = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)11);
  else
    result = 0;
  return result;
}

//----- (004823E0) --------------------------------------------------------  // acclient.c:190362
void __thiscall PStringBase<unsigned short>::append_uint32(PStringBase<unsigned short> *this, unsigned int num)
{
  PStringBase<unsigned short> *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // ecx@1
  int v4; // eax@1
  int v5; // esi@3
  PStringBase<unsigned short> buf; // [sp+0h] [bp-4h]@1

  buf.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&buf, L"%lu", num);
  v3 = buf.m_charbuffer;
  v4 = *(_DWORD *)&buf.m_charbuffer[-1].m_data[14];
  if ( v4 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(v2, buf.m_charbuffer->m_data, v4 - 1);
    v3 = buf.m_charbuffer;
  }
  v5 = (int)&v3[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (00482450) --------------------------------------------------------  // acclient.c:190390
void __thiscall gmCGProfessionPage::UpdateAttributeValues(gmCGProfessionPage *this)
{
  gmCGProfessionPage *v1; // ebp@1
  CPlayerSystem *v2; // ecx@1
  CharGenState *v3; // eax@1
  unsigned int v4; // ebx@1
  int v5; // ebp@1
  int v6; // eax@2
  int v7; // edi@2
  PSRefBufferCharData<unsigned short> *v8; // ecx@2
  int v9; // eax@2
  int v10; // edi@4
  float _val; // ST10_4@7
  char *v12; // edi@7
  CharGenState *v13; // ebx@11
  int v14; // edi@11
  PSRefBufferCharData<unsigned short> *v15; // ecx@11
  int v16; // eax@11
  int v17; // edi@13
  char *v18; // edi@17
  int v19; // eax@21
  int v20; // edi@21
  PSRefBufferCharData<unsigned short> *v21; // ecx@21
  int v22; // eax@21
  int v23; // edi@23
  char *v24; // edi@27
  int v25; // edi@31
  PSRefBufferCharData<unsigned short> *v26; // ecx@31
  int v27; // eax@31
  int v28; // edi@33
  char *v29; // edi@37
  int v30; // edi@41
  PSRefBufferCharData<unsigned short> *v31; // ecx@41
  int v32; // eax@41
  int v33; // esi@43
  gmCGProfessionPage *v34; // esi@46
  char *v35; // esi@46
  PStringBase<unsigned short> strVal; // [sp+24h] [bp-18h]@11
  gmCGProfessionPage *v37; // [sp+28h] [bp-14h]@1
  PStringBase<unsigned short> v38; // [sp+2Ch] [bp-10h]@2
  PStringBase<unsigned short> _text; // [sp+30h] [bp-Ch]@2
  CharGenState *cg; // [sp+34h] [bp-8h]@1
  int iVal; // [sp+38h] [bp-4h]@2

  v1 = this;
  v2 = this->m_pPlayerSystem;
  v37 = v1;
  CPlayerSystem::GetCharGenState(v2);
  cg = v3;
  v4 = 1;
  v5 = (int)&v1->m_tSliderArray[1].pSlider;
  do
  {
    v6 = CharGenState::GetAttribute(cg, v4);
    v7 = v6;
    _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    iVal = v6;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    v38.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&v38, L"%ld", v7);
    v8 = v38.m_charbuffer;
    v9 = *(_DWORD *)&v38.m_charbuffer[-1].m_data[14];
    if ( v9 != 1 )
    {
      PStringBase<unsigned short>::append_n_chars(&_text, v38.m_charbuffer->m_data, v9 - 1);
      v8 = v38.m_charbuffer;
    }
    v10 = (int)&v8[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v8[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    UIElement_Text::SetText(*(UIElement_Text **)(v5 + 4), &_text);
    _val = (double)iVal * 0.0099999998;
    UIElement::SetAttribute_Float(*(UIElement **)v5, 0x86u, _val);
    v12 = (char *)&_text.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    ++v4;
    v5 += 24;
  }
  while ( v4 < 7 );
  strVal.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v13 = cg;
  v14 = cg->remainingAtrbCredits;
  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&_text, L"%lu", v14);
  v15 = _text.m_charbuffer;
  v16 = *(_DWORD *)&_text.m_charbuffer[-1].m_data[14];
  if ( v16 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(&strVal, _text.m_charbuffer->m_data, v16 - 1);
    v15 = _text.m_charbuffer;
  }
  v17 = (int)&v15[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v15[-1].m_data[8]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  UIElement_Text::SetText(v37->m_pAvailableValue, &strVal);
  if ( (wchar_t *)strVal.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v18 = (char *)&strVal.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strVal.m_charbuffer[-1].m_data[8]) && v18 )
      (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    strVal.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  }
  v19 = CharGenState::GetAttribute(v13, 2u);
  iVal = v19;
  v20 = (unsigned __int64)((double)v19 * 0.5 + 0.5);
  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&_text, L"%lu", v20);
  v21 = _text.m_charbuffer;
  v22 = *(_DWORD *)&_text.m_charbuffer[-1].m_data[14];
  if ( v22 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(&strVal, _text.m_charbuffer->m_data, v22 - 1);
    v21 = _text.m_charbuffer;
  }
  v23 = (int)&v21[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v21[-1].m_data[8]) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  UIElement_Text::SetText(v37->m_pHealthValue, &strVal);
  if ( (wchar_t *)strVal.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v24 = (char *)&strVal.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strVal.m_charbuffer[-1].m_data[8]) && v24 )
      (**(void (__thiscall ***)(char *, signed int))v24)(v24, 1);
    strVal.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  }
  v25 = CharGenState::GetAttribute(v13, 2u);
  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&_text, L"%lu", v25);
  v26 = _text.m_charbuffer;
  v27 = *(_DWORD *)&_text.m_charbuffer[-1].m_data[14];
  if ( v27 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(&strVal, _text.m_charbuffer->m_data, v27 - 1);
    v26 = _text.m_charbuffer;
  }
  v28 = (int)&v26[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v26[-1].m_data[8]) && v28 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
  UIElement_Text::SetText(v37->m_pStaminaValue, &strVal);
  if ( (wchar_t *)strVal.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v29 = (char *)&strVal.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strVal.m_charbuffer[-1].m_data[8]) && v29 )
      (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
    strVal.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  }
  v30 = CharGenState::GetAttribute(v13, 6u);
  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&_text, L"%lu", v30);
  v31 = _text.m_charbuffer;
  v32 = *(_DWORD *)&_text.m_charbuffer[-1].m_data[14];
  if ( v32 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(&strVal, _text.m_charbuffer->m_data, v32 - 1);
    v31 = _text.m_charbuffer;
  }
  v33 = (int)&v31[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v31[-1].m_data[8]) && v33 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v33)(v33, 1);
  v34 = v37;
  UIElement_Text::SetText(v37->m_pManaValue, &strVal);
  CharGenState::FitTemplateToCharacter(v13);
  gmCGProfessionPage::UpdateProfession(v34);
  v35 = (char *)&strVal.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strVal.m_charbuffer[-1].m_data[8]) )
  {
    if ( v35 )
      (**(void (__thiscall ***)(char *, signed int))v35)(v35, 1);
  }
}

//----- (00482830) --------------------------------------------------------  // acclient.c:190572
void __thiscall gmCGProfessionPage::Update(gmCGProfessionPage *this)
{
  gmCGProfessionPage *v1; // esi@1
  CharGenState *v2; // eax@1

  v1 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  CharGenState::FitTemplateToCharacter(v2);
  gmCGProfessionPage::UpdateProfession(v1);
  gmCGProfessionPage::UpdateAttributeValues(v1);
}

//----- (00482860) --------------------------------------------------------  // acclient.c:190585
void __thiscall gmCGProfessionPage::UpdateToDefaultAttributes(gmCGProfessionPage *this)
{
  gmCGProfessionPage *v1; // esi@1
  CharGenState *v2; // eax@1

  v1 = this;
  gmCGProfessionPage::ClearLocks(this);
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  CharGenState::FitTemplateToCharacter(v2);
  gmCGProfessionPage::UpdateProfession(v1);
  gmCGProfessionPage::UpdateAttributeValues(v1);
}

//----- (00482890) --------------------------------------------------------  // acclient.c:190599
void __thiscall gmCGProfessionPage::SetAttribValue(gmCGProfessionPage *this, UIElement *pSlider, int iPos)
{
  CharGenState *v3; // eax@1
  CharGenState *v4; // esi@1
  int v5; // ebx@1
  int v6; // edi@1
  int v7; // ebp@1
  int v8; // edi@3
  gmCGProfessionPage *v9; // [sp+10h] [bp-4h]@1

  v9 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v4 = v3;
  v5 = gmCGProfessionPage::GetSliderIndex(pSlider);
  v6 = iPos;
  v7 = iPos - CharGenState::GetAttribute(v4, v5);
  if ( v7 >= 0 && v7 > CharGenState::GetAbsRemainingCredits(v4, v5) )
  {
    v8 = CharGenState::GetAttribute(v4, v5);
    v6 = CharGenState::GetAbsRemainingCredits(v4, v5) + v8;
  }
  switch ( v5 )
  {
    case 1:
      CharGenState::SetStrength(v4, v6, 1);
      gmCGProfessionPage::UpdateAttributeValues(v9);
      break;
    case 2:
      CharGenState::SetEndurance(v4, v6, 1);
      gmCGProfessionPage::UpdateAttributeValues(v9);
      break;
    case 4:
      CharGenState::SetCoordination(v4, v6, 1);
      gmCGProfessionPage::UpdateAttributeValues(v9);
      break;
    case 3:
      CharGenState::SetQuickness(v4, v6, 1);
      gmCGProfessionPage::UpdateAttributeValues(v9);
      break;
    case 5:
      CharGenState::SetFocus(v4, v6, 1);
      gmCGProfessionPage::UpdateAttributeValues(v9);
      break;
    case 6:
      CharGenState::SetSelf(v4, v6, 1);
      goto LABEL_11;
    default:
LABEL_11:
      gmCGProfessionPage::UpdateAttributeValues(v9);
      break;
  }
}

//----- (004829C0) --------------------------------------------------------  // acclient.c:190653
UIElementMessageListenResult __userpurge gmCGProfessionPage::ListenToElementMessage@<eax>(gmCGProfessionPage *this@<ecx>, double a2@<st0>, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v3; // esi@1
  UIElement *v4; // edi@1
  UIElement *v5; // eax@3
  UIElementMessageListenResult v6; // eax@3
  int v7; // ebx@5
  UIElement *v8; // eax@7
  unsigned int v9; // eax@8
  UIElement *v10; // ecx@9
  UIElement_Text *v11; // eax@10
  UIElement_Text *v12; // ebx@11
  UIElement *v13; // ebp@11
  PStringBase<unsigned short> *v14; // eax@11
  unsigned __int32 v15; // eax@11
  int v16; // ebx@12
  UIElement_Text *v17; // ebx@18
  UIElement *v18; // ebp@18
  int v19; // ebx@18
  float _Number; // ST04_4@19
  CharGenState *v21; // eax@35
  int v22; // [sp+8h] [bp-20h]@22
  PStringBase<unsigned short> result; // [sp+20h] [bp-8h]@11
  float fPos; // [sp+24h] [bp-4h]@19

  v3 = i_rMsg;
  v4 = (UIElement *)this;
  switch ( i_rMsg->idElement )
  {
    case 0x100002ECu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage(v4, v3);
      v5 = (UIElement *)((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)();
      gmCGProfessionPage::SetLock((gmCGProfessionPage *)v4, v5);
      return UIElement::ListenToElementMessage(v4, v3);
    case 0x100002EEu:
      if ( i_rMsg->idMessage != 10 )
        return UIElement::ListenToElementMessage(v4, v3);
      v7 = (unsigned __int64)((double)i_rMsg->dwParam1 * 0.1);
      if ( v7 < 10 )
        v7 = 10;
      v8 = (UIElement *)((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)();
      gmCGProfessionPage::SetAttribValue((gmCGProfessionPage *)v4, v8, v7);
      return UIElement::ListenToElementMessage(v4, v3);
    case 0x100002EFu:
      v9 = i_rMsg->idMessage;
      if ( v9 == 47 )
      {
        v10 = i_rMsg->pElement;
        if ( i_rMsg->dwParam1 )
        {
          v11 = (UIElement_Text *)((int (__stdcall *)(signed int))v10->vfptr[12].OnAction)(12);
          UIElement_Text::SelectAll(v11);
          v6 = UIElement::ListenToElementMessage(v4, v3);
        }
        else
        {
          v12 = (UIElement_Text *)((int (__stdcall *)(signed int))v10->vfptr[12].OnAction)(12);
          v13 = (UIElement *)((int (*)(void))v3->pElement->vfptr[13].OnAction)();
          v14 = UIElement_Text::GetText(v12, &result);
          v15 = PStringBase<unsigned short>::to_uint32(v14);
          if ( v15 <= 0x64 )
          {
            v16 = 10;
            if ( v15 >= 0xA )
              v16 = v15;
          }
          else
          {
            v16 = 100;
          }
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          gmCGProfessionPage::SetAttribValue((gmCGProfessionPage *)v4, v13, v16);
          v6 = UIElement::ListenToElementMessage(v4, v3);
        }
      }
      else
      {
        if ( v9 != 18 && v9 != 68 )
          return UIElement::ListenToElementMessage(v4, v3);
        v17 = (UIElement_Text *)((int (__stdcall *)(signed int))i_rMsg->pElement->vfptr[12].OnAction)(12);
        v18 = (UIElement *)((int (*)(void))v3->pElement->vfptr[13].OnAction)();
        UIElement_Text::GetText(v17, (PStringBase<unsigned short> *)&i_rMsg);
        v19 = UIElement::GetChildRecursiveTemplate<UIElement_Scrollbar>(v18, 0x100002EEu);
        if ( v19 )
        {
          PStringBase<unsigned short>::to_float((PStringBase<unsigned short> *)&i_rMsg);
          _Number = a2 * 0.0099999998;
          fPos = MathLib::Clamp(_Number, 0.1, 1.0);
          UIElement::SetAttribute_Float((UIElement *)v19, 0x85u, fPos);
        }
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_rMsg);
        v6 = UIElement::ListenToElementMessage(v4, v3);
      }
      return v6;
    case 0x100003D9u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage(v4, v3);
      v22 = 0;
      goto LABEL_35;
    case 0x100003DAu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage(v4, v3);
      v22 = 1;
      goto LABEL_35;
    case 0x100003DBu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage(v4, v3);
      v22 = 3;
      goto LABEL_35;
    case 0x100003DCu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage(v4, v3);
      v22 = 4;
      goto LABEL_35;
    case 0x100003DDu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage(v4, v3);
      v22 = 5;
      goto LABEL_35;
    case 0x100003DEu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage(v4, v3);
      v22 = 6;
      goto LABEL_35;
    case 0x100003DFu:
      if ( i_rMsg->idMessage == 1 )
      {
        v22 = 2;
LABEL_35:
        CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
        CharGenState::SetTemplate(v21, v22, 1);
        gmCGProfessionPage::UpdateToDefaultAttributes((gmCGProfessionPage *)v4);
      }
      break;
    default:
      return UIElement::ListenToElementMessage(v4, v3);
  }
  return UIElement::ListenToElementMessage(v4, v3);
}

//----- (00482D50) --------------------------------------------------------  // acclient.c:190795
void __thiscall gmCGProfessionPage::InitializePage(gmCGProfessionPage *this, gmCharGenMainUI *_pMain)
{
  gmCGProfessionPage *v2; // edi@1
  int v3; // esi@1
  UIElement *v4; // eax@2
  int v5; // eax@3
  UIElement *v6; // ecx@5
  UIElement *v7; // eax@5
  int v8; // eax@6
  UIElement *v9; // eax@8
  int v10; // eax@9
  UIElement *v11; // ecx@11
  UIElement *v12; // eax@11
  int v13; // eax@12
  unsigned int v14; // ecx@14
  unsigned int v15; // ST00_4@14
  PSRefBufferCharData<unsigned short> *v16; // eax@14
  int v17; // ecx@14
  char *v18; // ebx@16
  char *v19; // ebx@19
  char *v20; // ebx@22
  UIElement *v21; // eax@26
  UIElement *v22; // eax@27
  int v23; // eax@28
  UIElement *v24; // eax@30
  UIElement *v25; // eax@31
  int v26; // eax@32
  UIElement *v27; // eax@34
  UIElement *v28; // eax@35
  int v29; // eax@36
  UIElement *v30; // eax@38
  UIElement *v31; // eax@39
  int v32; // eax@40
  UIElement *v33; // eax@42
  int v34; // eax@43
  PStringBase<unsigned short> strName; // [sp+10h] [bp-2Ch]@14
  unsigned int i; // [sp+14h] [bp-28h]@1
  PStringBase<unsigned short> result; // [sp+18h] [bp-24h]@14
  char pName[32]; // [sp+1Ch] [bp-20h]@14

  v2 = this;
  this->m_pMainFramework = _pMain;
  this->m_pPlayerSystem = CPlayerSystem::GetPlayerSystem();
  v3 = (int)&v2->m_tSliderArray[1];
  v2->m_tSliderArray[1].pAttribField = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E6u);
  v2->m_tSliderArray[2].pAttribField = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E7u);
  v2->m_tSliderArray[3].pAttribField = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E9u);
  v2->m_tSliderArray[4].pAttribField = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E8u);
  v2->m_tSliderArray[5].pAttribField = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003EAu);
  v2->m_tSliderArray[6].pAttribField = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003EBu);
  i = 1;
  do
  {
    v4 = UIElement::GetChildRecursive(*(UIElement **)v3, 0x100002ECu);
    if ( v4 )
      v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)1);
    else
      v5 = 0;
    v6 = *(UIElement **)v3;
    *(_DWORD *)(v3 + 4) = v5;
    v7 = UIElement::GetChildRecursive(v6, 0x100002EDu);
    if ( v7 )
      v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)12);
    else
      v8 = 0;
    *(_DWORD *)(v3 + 8) = v8;
    *(_DWORD *)(v8 + 1696) = NumberInputFilter;
    v9 = UIElement::GetChildRecursive(*(UIElement **)v3, 0x100002EEu);
    if ( v9 )
      v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)11);
    else
      v10 = 0;
    v11 = *(UIElement **)v3;
    *(_DWORD *)(v3 + 12) = v10;
    v12 = UIElement::GetChildRecursive(v11, 0x100002EFu);
    if ( v12 )
      v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
    else
      v13 = 0;
    v14 = i;
    *(_DWORD *)(v3 + 16) = v13;
    v15 = v14;
    CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
    CharGenState::GetAttributeName(v15, pName);
    strName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    _pMain = (gmCharGenMainUI *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::set((PStringBase<char> *)&_pMain, pName);
    v16 = PStringBase<char>::to_wpstring((PStringBase<char> *)&_pMain, &result, 0)->m_charbuffer;
    v17 = *(_DWORD *)&v16[-1].m_data[14];
    if ( v17 != 1 )
      PStringBase<unsigned short>::append_n_chars(&strName, v16->m_data, v17 - 1);
    v18 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v18 )
      (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    UIElement_Text::SetText(*(UIElement_Text **)(v3 + 8), &strName);
    (*(void (__stdcall **)(signed int))(**(_DWORD **)(v3 + 4) + 156))(268435480);
    v19 = (char *)&_pMain[-1].m_uiPleaseWaitContext;
    if ( !InterlockedDecrement((volatile LONG *)&_pMain[-1].m_uiErrorMessageContext) && v19 )
      (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
    v20 = (char *)&strName.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1].m_data[8]) && v20 )
      (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
    v3 += 24;
    ++i;
  }
  while ( i < 7 );
  v21 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E2u);
  if ( v21 && (v22 = UIElement::GetChildRecursive(v21, 0x100002F1u)) != 0 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)12);
  else
    v23 = 0;
  v2->m_pAvailableValue = (UIElement_Text *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E3u);
  if ( v24 && (v25 = UIElement::GetChildRecursive(v24, 0x100002F3u)) != 0 )
    v26 = v25->vfptr[12].OnAction((IInputActionCallback *)v25, (InputEvent *)12);
  else
    v26 = 0;
  v2->m_pHealthValue = (UIElement_Text *)v26;
  v27 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E4u);
  if ( v27 && (v28 = UIElement::GetChildRecursive(v27, 0x100002F3u)) != 0 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)12);
  else
    v29 = 0;
  v2->m_pStaminaValue = (UIElement_Text *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E5u);
  if ( v30 && (v31 = UIElement::GetChildRecursive(v30, 0x100002F3u)) != 0 )
    v32 = v31->vfptr[12].OnAction((IInputActionCallback *)v31, (InputEvent *)12);
  else
    v32 = 0;
  v2->m_pManaValue = (UIElement_Text *)v32;
  v33 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003E0u);
  if ( v33 )
    v34 = v33->vfptr[12].OnAction((IInputActionCallback *)v33, (InputEvent *)12);
  else
    v34 = 0;
  v2->m_pTextBox = (UIElement_Text *)v34;
  gmCGProfessionPage::UpdateProfession(v2);
}

//----- (006ECFE0) --------------------------------------------------------  // acclient.c:768836
void _E91_42()
{
  outside_val_34 = 1000.0 + 1.0;
}

//----- (006ED000) --------------------------------------------------------  // acclient.c:768842
void _E93_18()
{
  block_length_34 = 24.0 * 8.0;
}

//----- (006ED020) --------------------------------------------------------  // acclient.c:768848
void _E95_18()
{
  half_square_length_34 = 24.0 * 0.5;
}

//----- (006ED040) --------------------------------------------------------  // acclient.c:768854
int _E97_43()
{
  return atexit(_E98_55);
}

//----- (006ED050) --------------------------------------------------------  // acclient.c:768860
int _E100_36()
{
  return atexit(_E101_73);
}

//----- (006ED060) --------------------------------------------------------  // acclient.c:768866
int _E103_28()
{
  return atexit(_E104_43);
}

//----- (006ED070) --------------------------------------------------------  // acclient.c:768872
void _E106_24()
{
  DEFAULT_VIEW_RADIUS_18 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006ED090) --------------------------------------------------------  // acclient.c:768878
void _E108_16()
{
  MIN_QUANTUM_18 = 1.0 / 30.0;
}

//----- (006ED0B0) --------------------------------------------------------  // acclient.c:768884
void _E110_7()
{
  MAX_QUANTUM_18 = 1.0 / 5.0;
}

//----- (006ED0D0) --------------------------------------------------------  // acclient.c:768890
void _E112_20()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_53, PFID_A8R8G8B8);
}

//----- (006ED0E0) --------------------------------------------------------  // acclient.c:768896
int _E114_19()
{
  return atexit(nullsub_503);
}

//----- (006ED0F0) --------------------------------------------------------  // acclient.c:768902
void _E118_25()
{
  LOWEST_DATA_RATE_61 = 1024;
}

//----- (006ED100) --------------------------------------------------------  // acclient.c:768908
void _E120_16()
{
  HIGHEST_DATA_RATE_61 = 0x7FFF;
}

//----- (006ED110) --------------------------------------------------------  // acclient.c:768914
int _E122_5()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_61;
  INITIAL_MAX_DATA_RATE_9 = LOWEST_DATA_RATE_61;
  return result;
}

//----- (006ED120) --------------------------------------------------------  // acclient.c:768924
int _E1_94()
{
  return atexit(_E2_94);
}

