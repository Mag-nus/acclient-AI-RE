/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmIndicatorsUI
   Object     : GAME\game_ui_misc\gmIndicatorsUI.obj
   Functions  : 14
   Addresses  : 004BF990 - 006F26C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BF990) --------------------------------------------------------  // acclient.c:242061
void __userpurge gmIndicatorsUI::gmIndicatorsUI(gmIndicatorsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmIndicatorsUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmIndicatorsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
}
// 7B47E0: using guessed type int (__thiscall *gmIndicatorsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BF9D0) --------------------------------------------------------  // acclient.c:242075
gmIndicatorsUI *__thiscall gmIndicatorsUI::DynamicCast(gmIndicatorsUI *this, unsigned int i_eType)
{
  gmIndicatorsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435466 )
    result = (gmIndicatorsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004BFA10) --------------------------------------------------------  // acclient.c:242092
void __thiscall gmIndicatorsUI::~gmIndicatorsUI(gmIndicatorsUI *this)
{
  UIElement_Field *v1; // esi@1
  NoticeHandler *v2; // ecx@1

  v1 = (UIElement_Field *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmIndicatorsUI::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field(v1);
}
// 7B47E0: using guessed type int (__thiscall *gmIndicatorsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BFA40) --------------------------------------------------------  // acclient.c:242109
UIElement *__usercall gmIndicatorsUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x5FCu);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmIndicatorsUI::vftable;
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7B47E0: using guessed type int (__thiscall *gmIndicatorsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BFA90) --------------------------------------------------------  // acclient.c:242133
int __thiscall gmIndicatorsUI::ListenToElementMessage(gmIndicatorsUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // edi@1

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 1 && i_rMsg->idElement == 268435706 )
    CM_UI::SendNotice_EndCharacterSession(1);
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004BFAC0) --------------------------------------------------------  // acclient.c:242144
UIElement_Field *__thiscall gmIndicatorsUI::scalar_deleting_destructor(gmIndicatorsUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmIndicatorsUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7B47E0: using guessed type int (__thiscall *gmIndicatorsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BFB00) --------------------------------------------------------  // acclient.c:242164
void __cdecl gmIndicatorsUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000000Au,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmIndicatorsUI::Create);
}

//----- (006F2630) --------------------------------------------------------  // acclient.c:774821
void _E91_84()
{
  outside_val_76 = 1000.0 + 1.0;
}

//----- (006F2650) --------------------------------------------------------  // acclient.c:774827
void _E93_60()
{
  block_length_76 = 24.0 * 8.0;
}

//----- (006F2670) --------------------------------------------------------  // acclient.c:774833
void _E95_60()
{
  half_square_length_76 = 24.0 * 0.5;
}

//----- (006F2690) --------------------------------------------------------  // acclient.c:774839
int _E97_85()
{
  return atexit(_E98_97);
}

//----- (006F26A0) --------------------------------------------------------  // acclient.c:774845
int _E100_78()
{
  return atexit(nullsub_770);
}

//----- (006F26B0) --------------------------------------------------------  // acclient.c:774851
int _E103_70()
{
  return atexit(_E104_85);
}

//----- (006F26C0) --------------------------------------------------------  // acclient.c:774857
int sub_6F26C0()
{
  return atexit(nullsub_768);
}

