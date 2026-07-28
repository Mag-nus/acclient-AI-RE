/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption_CheckBoxSlider
   Object     : GAME\game_ui_misc\UIOption_CheckBoxSlider.obj
   Functions  : 27
   Addresses  : 00484610 - 006ED4D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00484610) --------------------------------------------------------  // acclient.c:192017
void __thiscall UIOption_CheckboxSlider::Refresh(UIOption_CheckboxSlider *this)
{
  UIOption_CheckboxSlider *v1; // esi@1
  UIOption_Checkbox *v2; // ecx@1
  UIOption_Slider *v3; // ecx@3

  v1 = this;
  v2 = this->m_pToggle;
  if ( v2 )
    ((void (*)(void))v2->vfptr[7].RecvNotice_ServerSaysMoveItem)();
  v3 = v1->m_pSlider;
  if ( v3 )
    ((void (*)(void))v3->vfptr[7].RecvNotice_ServerSaysMoveItem)();
}

//----- (00484640) --------------------------------------------------------  // acclient.c:192033
char __thiscall UIOption_CheckboxSlider::Changed(UIOption_CheckboxSlider *this)
{
  UIOption_CheckboxSlider *v1; // esi@1
  UIOption_Checkbox *v2; // ecx@1
  char v3; // bl@1
  UIOption_Slider *v4; // ecx@3

  v1 = this;
  v2 = this->m_pToggle;
  v3 = 0;
  if ( v2 )
    v3 = ((int (*)(void))v2->vfptr[7].RecvNotice_SetSelectedItem)();
  v4 = v1->m_pSlider;
  if ( v4 )
    v3 |= ((int (*)(void))v4->vfptr[7].RecvNotice_SetSelectedItem)();
  return v3;
}

//----- (00484680) --------------------------------------------------------  // acclient.c:192052
void __thiscall UIOption_CheckboxSlider::SetChangeNotification(UIOption_CheckboxSlider *this, IOptionChangeHandler *i_pOCH)
{
  UIOption_CheckboxSlider *v2; // esi@1
  UIOption_Checkbox *v3; // ecx@1
  UIOption_Slider *v4; // ecx@3

  v2 = this;
  v3 = this->m_pToggle;
  if ( v3 )
    ((void (__stdcall *)(IOptionChangeHandler *))v3->vfptr[7].RecvNotice_BeingDeleted)(i_pOCH);
  v4 = v2->m_pSlider;
  if ( v4 )
    ((void (__stdcall *)(IOptionChangeHandler *))v4->vfptr[7].RecvNotice_BeingDeleted)(i_pOCH);
}

//----- (004846C0) --------------------------------------------------------  // acclient.c:192068
char __thiscall UIOption_CheckboxSlider::Apply(UIOption_CheckboxSlider *this, int i_userRequested)
{
  UIOption_CheckboxSlider *v2; // esi@1
  UIOption_Checkbox *v3; // ecx@1
  char v4; // bl@1
  UIOption_Slider *v5; // ecx@3

  v2 = this;
  v3 = this->m_pToggle;
  v4 = 1;
  if ( v3 )
    v4 = ((int (__stdcall *)(_DWORD))v3->vfptr[7].RecvNotice_CloseDialog)(i_userRequested) & 1;
  v5 = v2->m_pSlider;
  if ( v5 )
    v4 &= ((int (__stdcall *)(_DWORD))v5->vfptr[7].RecvNotice_CloseDialog)(i_userRequested);
  return v4;
}

//----- (00484700) --------------------------------------------------------  // acclient.c:192087
char __thiscall UIOption_CheckboxSlider::SaveCurrentValue(UIOption_CheckboxSlider *this)
{
  UIOption_CheckboxSlider *v1; // esi@1
  UIOption_Checkbox *v2; // ecx@1
  UIOption_Slider *v3; // ecx@3

  v1 = this;
  v2 = this->m_pToggle;
  if ( v2 )
    ((void (*)(void))v2->vfptr[7].RecvNotice_WorldName)();
  v3 = v1->m_pSlider;
  if ( v3 )
    ((void (*)(void))v3->vfptr[7].RecvNotice_WorldName)();
  return 1;
}

//----- (00484730) --------------------------------------------------------  // acclient.c:192104
char __thiscall UIOption_CheckboxSlider::RestoreSavedValue(UIOption_CheckboxSlider *this)
{
  UIOption_CheckboxSlider *v1; // esi@1
  UIOption_Checkbox *v2; // ecx@1
  UIOption_Slider *v3; // ecx@3

  v1 = this;
  v2 = this->m_pToggle;
  if ( v2 )
    ((void (*)(void))v2->vfptr[7].RecvNotice_CharacterError)();
  v3 = v1->m_pSlider;
  if ( v3 )
    ((void (*)(void))v3->vfptr[7].RecvNotice_CharacterError)();
  return 1;
}

//----- (00484760) --------------------------------------------------------  // acclient.c:192121
char __thiscall UIOption_CheckboxSlider::RestoreDefaultValue(UIOption_CheckboxSlider *this)
{
  UIOption_CheckboxSlider *v1; // esi@1
  UIOption_Checkbox *v2; // ecx@1
  UIOption_Slider *v3; // ecx@3

  v1 = this;
  v2 = this->m_pToggle;
  if ( v2 )
    ((void (*)(void))v2->vfptr[7].RecvNotice_ServerDied)();
  v3 = v1->m_pSlider;
  if ( v3 )
    ((void (*)(void))v3->vfptr[7].RecvNotice_ServerDied)();
  return 1;
}

//----- (00484790) --------------------------------------------------------  // acclient.c:192138
void __thiscall UIOption_CheckboxSlider::SetDefaultValue(UIOption_CheckboxSlider *this, int fToggleDefault, float rSliderDefault)
{
  UIOption_CheckboxSlider *v3; // esi@1
  UIOption_Checkbox *v4; // ecx@1
  UIOption_Slider *v5; // ecx@3

  v3 = this;
  v4 = this->m_pToggle;
  if ( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr[7].RecvNotice_DisplayFinalStringInfo)(fToggleDefault);
  v5 = v3->m_pSlider;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr[7].RecvNotice_DisplayFinalStringInfo)(LODWORD(rSliderDefault));
}

//----- (004847D0) --------------------------------------------------------  // acclient.c:192154
void __thiscall UIOption_CheckboxSlider::SetUIPreference(UIOption_CheckboxSlider *this, PStringBase<char> *strToggleName, PStringBase<char> *strSliderName)
{
  UIOption_CheckboxSlider *v3; // esi@1
  UIOption_Checkbox *v4; // ecx@1
  UIOption_Slider *v5; // ecx@3

  v3 = this;
  v4 = this->m_pToggle;
  if ( v4 )
    UIOption_Checkbox::SetUIPreference(v4, strToggleName);
  v5 = v3->m_pSlider;
  if ( v5 )
    UIOption_Slider::SetUIPreference(v5, strSliderName);
}

//----- (00484800) --------------------------------------------------------  // acclient.c:192170
void __thiscall UIOption_CheckboxSlider::SetTooltip(UIOption_CheckboxSlider *this, StringInfo *i_siTooltip)
{
  UIElement::SetTooltip((UIElement *)&this->vfptr, i_siTooltip);
}

//----- (00484810) --------------------------------------------------------  // acclient.c:192176
int __thiscall UIOption_CheckboxSlider::ListenToElementMessage(UIOption_CheckboxSlider *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIOption_CheckboxSlider *v3; // esi@1
  char v4; // al@1
  HashSetData<UIListener *> **v5; // ecx@2
  unsigned int v6; // ecx@4

  v2 = i_rMsg;
  v3 = this;
  v4 = 1;
  if ( i_rMsg->idMessage == 1 )
  {
    v5 = this->m_hashListeners.m_intrusiveTable.m_firstInterestingBucket;
    LOBYTE(i_rMsg) = 1;
    if ( v5 )
    {
      UIElement::GetAttribute_Bool((UIElement *)(v5 + 8), 0xEu, (bool *)&i_rMsg);
      v4 = (char)i_rMsg;
    }
    v6 = v3->m_hashListeners.m_intrusiveTable.m_numBuckets;
    if ( v6 )
      (*(void (__thiscall **)(int, signed int))(*(_DWORD *)(v6 + 32) + 156))(v6 + 32, v4 != 0 ? 1 : 13);
  }
  return UIElement::ListenToElementMessage((UIElement *)v3, v2);
}

//----- (00484880) --------------------------------------------------------  // acclient.c:192204
void __thiscall UIOption_CheckboxSlider::UIOption_CheckboxSlider(UIOption_CheckboxSlider *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_CheckboxSlider *v3; // esi@1
  volatile LONG *v4; // ST04_4@1

  v3 = this;
  UIOption::UIOption((UIOption *)&this->vfptr);
  UIElement::UIElement((UIElement *)&v3->vfptr, (int)&v3->vfptr, _layout, _full_desc);
  v3->m_pToggle = 0;
  v3->m_pSlider = 0;
  v3->vfptr = (NoticeHandlerVtbl *)&UIOption_CheckboxSlider::vftable;
  v3->vfptr = (IInputActionCallbackVtbl *)&UIOption_CheckboxSlider::vftable;
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v3->m_prefName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
}
// 7A1398: using guessed type void *UIOption_CheckboxSlider::vftable;
// 7A14D0: using guessed type bool (__thiscall *UIOption_CheckboxSlider::vftable)(DBCache *this);

//----- (004848E0) --------------------------------------------------------  // acclient.c:192224
IInputActionCallbackVtbl **__thiscall UIOption_CheckboxSlider::DynamicCast(UIOption_CheckboxSlider *this, unsigned int i_eType)
{
  IInputActionCallbackVtbl **result; // eax@3

  if ( i_eType == 268435510 && this )
    result = &this->vfptr;
  else
    result = 0;
  return result;
}

//----- (00484900) --------------------------------------------------------  // acclient.c:192236
signed int UIOption_CheckboxSlider::GetUIElementType()
{
  return 268435510;
}

//----- (00484910) --------------------------------------------------------  // acclient.c:192242
UIOption *__thiscall UIOption_CheckboxSlider::vector_deleting_destructor(UIOption_CheckboxSlider *this, unsigned int a2)
{
  return UIOption_CheckboxSlider::scalar_deleting_destructor((UIOption_CheckboxSlider *)((char *)this - 28), a2);
}

//----- (00484920) --------------------------------------------------------  // acclient.c:192248
IInputActionCallbackVtbl **__thiscall UIOption_CheckboxSlider::DynamicCast(UIOption_CheckboxSlider *this, unsigned int a2)
{
  return UIOption_CheckboxSlider::DynamicCast((UIOption_CheckboxSlider *)((char *)this - 28), a2);
}

//----- (00484930) --------------------------------------------------------  // acclient.c:192254
UIElement *__cdecl UIOption_CheckboxSlider::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_CheckboxSlider *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (UIOption_CheckboxSlider *)operator new(0x618u);
  if ( v2 && (UIOption_CheckboxSlider::UIOption_CheckboxSlider(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 28);
  else
    result = 0;
  return result;
}

//----- (00484960) --------------------------------------------------------  // acclient.c:192269
void __thiscall UIOption_CheckboxSlider::PostInit(UIOption_CheckboxSlider *this)
{
  UIOption_CheckboxSlider *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  int v4; // eax@3
  UIElement *v5; // eax@5
  int v6; // eax@6

  v1 = this;
  UIElement::PostInit((UIElement *)this);
  v2 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000219u);
  if ( v2 && (v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435509)) != 0 )
    v4 = v3 - 32;
  else
    v4 = 0;
  v1->m_hashListeners.m_intrusiveTable.m_firstInterestingBucket = (HashSetData<UIListener *> **)v4;
  v5 = UIElement::GetChildRecursive((UIElement *)v1, 0x1000021Cu);
  if ( v5 && (v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435511)) != 0 )
    v1->m_hashListeners.m_intrusiveTable.m_numBuckets = v6 - 32;
  else
    v1->m_hashListeners.m_intrusiveTable.m_numBuckets = 0;
}

//----- (004849D0) --------------------------------------------------------  // acclient.c:192294
UIOption *__thiscall UIOption_CheckboxSlider::scalar_deleting_destructor(UIOption_CheckboxSlider *this, unsigned int a2)
{
  UIOption *v2; // edi@1
  char *v3; // esi@1
  UIElement *v4; // ebx@1

  v2 = (UIOption *)this;
  v3 = &this->m_prefName.m_charbuffer[-2].m_data[12];
  v4 = (UIElement *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption_CheckboxSlider::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIOption_CheckboxSlider::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v3 + 1) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  UIElement::~UIElement(v4);
  UIOption::~UIOption(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A1398: using guessed type void *UIOption_CheckboxSlider::vftable;
// 7A14D0: using guessed type bool (__thiscall *UIOption_CheckboxSlider::vftable)(DBCache *this);

//----- (00484A30) --------------------------------------------------------  // acclient.c:192317
void __cdecl UIOption_CheckboxSlider::Register()
{
  UIElement::RegisterElementClass(0x10000036u, UIOption_CheckboxSlider::Create);
}

//----- (006ED440) --------------------------------------------------------  // acclient.c:769129
void _E91_45()
{
  outside_val_37 = 1000.0 + 1.0;
}

//----- (006ED460) --------------------------------------------------------  // acclient.c:769135
void _E93_21()
{
  block_length_37 = 24.0 * 8.0;
}

//----- (006ED480) --------------------------------------------------------  // acclient.c:769141
void _E95_21()
{
  half_square_length_37 = 24.0 * 0.5;
}

//----- (006ED4A0) --------------------------------------------------------  // acclient.c:769147
int _E97_46()
{
  return atexit(_E98_58);
}

//----- (006ED4B0) --------------------------------------------------------  // acclient.c:769153
int _E100_39()
{
  return atexit(_E101_76);
}

//----- (006ED4C0) --------------------------------------------------------  // acclient.c:769159
int _E103_31()
{
  return atexit(_E104_46);
}

//----- (006ED4D0) --------------------------------------------------------  // acclient.c:769165
int _E1_97()
{
  return atexit(_E2_97);
}

