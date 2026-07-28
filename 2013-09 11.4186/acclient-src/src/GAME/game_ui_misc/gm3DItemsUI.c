/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gm3DItemsUI
   Object     : GAME\game_ui_misc\gm3DItemsUI.obj
   Functions  : 21
   Addresses  : 004A70A0 - 00760FC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A70A0) --------------------------------------------------------  // acclient.c:222743
gm3DItemsUI *__thiscall gm3DItemsUI::DynamicCast(gm3DItemsUI *this, unsigned int i_eType)
{
  gm3DItemsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435489 )
    result = (gm3DItemsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A70C0) --------------------------------------------------------  // acclient.c:222754
signed int gm3DItemsUI::GetUIElementType()
{
  return 268435489;
}

//----- (004A70D0) --------------------------------------------------------  // acclient.c:222760
UIElement *__usercall gm3DItemsUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x604u);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gm3DItemsUI::vftable;
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *((_DWORD *)v3 + 383) = 0;
    *((_DWORD *)v3 + 384) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7AD060: using guessed type int (__thiscall *gm3DItemsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A7130) --------------------------------------------------------  // acclient.c:222786
UIElement_Field *__thiscall gm3DItemsUI::vector_deleting_destructor(gm3DItemsUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gm3DItemsUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7AD060: using guessed type int (__thiscall *gm3DItemsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A7170) --------------------------------------------------------  // acclient.c:222806
void __cdecl gm3DItemsUI::Register()
{
  UIElement::RegisterElementClass(0x10000021u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gm3DItemsUI::Create);
}

//----- (004A7190) --------------------------------------------------------  // acclient.c:222812
void __thiscall gm3DItemsUI::PostInit(gm3DItemsUI *this)
{
  gm3DItemsUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  unsigned int v4; // eax@4
  char *v5; // esi@4
  PStringBase<unsigned short> _text; // [sp+0h] [bp-4h]@1

  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_contentsText = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001C5u);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001C6u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435505);
  else
    v3 = 0;
  v1->m_itemList = (UIElement_ItemList *)v3;
  v4 = _wcslen(L"Contents of Backpack");
  PStringBase<unsigned short>::allocate_ref_buffer(&_text, v4);
  _wcscpy(_text.m_charbuffer->m_data, L"Contents of Backpack");
  UIElement_Text::SetText(v1->m_contentsText, &_text);
  v5 = (char *)&_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (006F1020) --------------------------------------------------------  // acclient.c:773207
void _E91_72()
{
  outside_val_64 = 1000.0 + 1.0;
}

//----- (006F1040) --------------------------------------------------------  // acclient.c:773213
void _E93_48()
{
  block_length_64 = 24.0 * 8.0;
}

//----- (006F1060) --------------------------------------------------------  // acclient.c:773219
void _E95_48()
{
  half_square_length_64 = 24.0 * 0.5;
}

//----- (006F1080) --------------------------------------------------------  // acclient.c:773225
int _E97_73()
{
  return atexit(_E98_85);
}

//----- (006F1090) --------------------------------------------------------  // acclient.c:773231
int _E100_66()
{
  return atexit(nullsub_847);
}

//----- (006F10A0) --------------------------------------------------------  // acclient.c:773237
int _E103_58()
{
  return atexit(_E104_73);
}

//----- (006F10B0) --------------------------------------------------------  // acclient.c:773243
void _E109_28()
{
  DEFAULT_VIEW_RADIUS_37 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F10D0) --------------------------------------------------------  // acclient.c:773249
void _E111_17()
{
  MIN_QUANTUM_37 = 1.0 / 30.0;
}

//----- (006F10F0) --------------------------------------------------------  // acclient.c:773255
void _E113_5()
{
  MAX_QUANTUM_37 = 1.0 / 5.0;
}

//----- (006F1110) --------------------------------------------------------  // acclient.c:773261
void _E115_31()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_72, PFID_A8R8G8B8);
}

//----- (006F1120) --------------------------------------------------------  // acclient.c:773267
int _E117_27()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_30, "Misc.TooltipEnable");
  return atexit(sub_760F90);
}

//----- (006F1140) --------------------------------------------------------  // acclient.c:773274
int _E120_23()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_30, "Misc.TooltipDelay");
  return atexit(sub_760FC0);
}

//----- (006F1160) --------------------------------------------------------  // acclient.c:773281
int sub_6F1160()
{
  return atexit(nullsub_845);
}

//----- (00760F90) --------------------------------------------------------  // acclient.c:888684
void __cdecl sub_760F90()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760FC0) --------------------------------------------------------  // acclient.c:888697
void __cdecl sub_760FC0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

