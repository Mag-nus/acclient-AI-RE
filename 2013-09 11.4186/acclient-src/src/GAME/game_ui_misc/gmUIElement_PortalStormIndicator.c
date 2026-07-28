/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUIElement_PortalStormIndicator
   Object     : GAME\game_ui_misc\gmUIElement_PortalStormIndicator.obj
   Functions  : 17
   Addresses  : 004E6100 - 006F66B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E6100) --------------------------------------------------------  // acclient.c:275999
void __userpurge gmUIElement_PortalStormIndicator::gmUIElement_PortalStormIndicator(gmUIElement_PortalStormIndicator *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmUIElement_PortalStormIndicator *v4; // esi@1

  v4 = this;
  UIElement_Button::UIElement_Button((UIElement_Button *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  LODWORD(v4->m_ttLastPortalStormWarningTime) = 0;
  HIDWORD(v4->m_ttLastPortalStormWarningTime) = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_PortalStormIndicator::vftable;
  v4->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmUIElement_PortalStormIndicator::vftable;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C0910: using guessed type bool (__thiscall *gmUIElement_PortalStormIndicator::vftable)(DBCache *this);
// 7C0BB8: using guessed type int (__thiscall *gmUIElement_PortalStormIndicator::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (004E6150) --------------------------------------------------------  // acclient.c:276018
gmUIElement_PortalStormIndicator *__thiscall gmUIElement_PortalStormIndicator::DynamicCast(gmUIElement_PortalStormIndicator *this, unsigned int i_eType)
{
  gmUIElement_PortalStormIndicator *result; // eax@1

  result = this;
  if ( i_eType != 268435461 && i_eType != 1 && i_eType != 12 )
    result = (gmUIElement_PortalStormIndicator *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E6190) --------------------------------------------------------  // acclient.c:276035
void __thiscall gmUIElement_PortalStormIndicator::PostInit(gmUIElement_PortalStormIndicator *this)
{
  gmUIElement_PortalStormIndicator *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  UIElement_Button::PostInit((UIElement_Button *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD21A + 1),
      (NoticeHandler *)&v1->vfptr);
  else
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD21A + 1), 0);
}

//----- (004E61D0) --------------------------------------------------------  // acclient.c:276053
void __thiscall gmUIElement_PortalStormIndicator::~gmUIElement_PortalStormIndicator(gmUIElement_PortalStormIndicator *this)
{
  UIElement_Button *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = (UIElement_Button *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_PortalStormIndicator::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmUIElement_PortalStormIndicator::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Button::~UIElement_Button(v1);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C0910: using guessed type bool (__thiscall *gmUIElement_PortalStormIndicator::vftable)(DBCache *this);
// 7C0BB8: using guessed type int (__thiscall *gmUIElement_PortalStormIndicator::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (004E6220) --------------------------------------------------------  // acclient.c:276078
void __usercall gmUIElement_PortalStormIndicator::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmUIElement_PortalStormIndicator *v3; // eax@1

  v3 = (gmUIElement_PortalStormIndicator *)operator new(0x730u);
  if ( v3 )
    gmUIElement_PortalStormIndicator::gmUIElement_PortalStormIndicator(v3, a1, _layout, _full_desc);
}

//----- (004E6250) --------------------------------------------------------  // acclient.c:276088
void __thiscall gmUIElement_PortalStormIndicator::Update(gmUIElement_PortalStormIndicator *this, float i_fExtent)
{
  gmUIElement_PortalStormIndicator *v2; // esi@1
  IInputActionCallbackVtbl *v3; // eax@1
  unsigned int v4; // edx@2

  v2 = this;
  v3 = this->vfptr;
  if ( i_fExtent <= 0.0 )
  {
    ((void (__stdcall *)(signed int))v3[13].__vecDelDtor)(13);
    LODWORD(v2->m_ttLastPortalStormWarningTime) = 0;
    HIDWORD(v2->m_ttLastPortalStormWarningTime) = 0;
    UIListener::UnRegisterForGlobalMessage((UIListener *)&v2->vfptr, 3u);
  }
  else
  {
    ((void (__stdcall *)(signed int))v3[13].__vecDelDtor)(1);
    v4 = Timer::cur_time.Param;
    LODWORD(v2->m_ttLastPortalStormWarningTime) = Timer::cur_time.Cmd;
    HIDWORD(v2->m_ttLastPortalStormWarningTime) = v4;
    UIListener::RegisterForGlobalMessage((UIListener *)&v2->vfptr, 3u);
  }
}

//----- (004E62C0) --------------------------------------------------------  // acclient.c:276114
gmUIElement_PortalStormIndicator *__thiscall gmUIElement_PortalStormIndicator::vector_deleting_destructor(gmUIElement_PortalStormIndicator *this, unsigned int a2)
{
  gmUIElement_PortalStormIndicator *v2; // esi@1

  v2 = this;
  gmUIElement_PortalStormIndicator::~gmUIElement_PortalStormIndicator(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E62E0) --------------------------------------------------------  // acclient.c:276126
void __cdecl gmUIElement_PortalStormIndicator::Register()
{
  UIElement::RegisterElementClass(
    0x10000005u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmUIElement_PortalStormIndicator::Create);
}

//----- (004E6300) --------------------------------------------------------  // acclient.c:276134
void __thiscall gmUIElement_PortalStormIndicator::ListenToGlobalMessage(gmUIElement_PortalStormIndicator *this, unsigned int i_messageID, int i_data_int)
{
  UIElement_Button *v3; // esi@1

  v3 = (UIElement_Button *)this;
  if ( i_messageID == 3 && COERCE_DOUBLE(Timer::cur_time.Cmd) - this->m_ttLastPortalStormWarningTime >= 120.0 )
    gmUIElement_PortalStormIndicator::Update(this, 0.0);
  UIElement_Button::ListenToGlobalMessage(v3, i_messageID, i_data_int);
}

//----- (004E6340) --------------------------------------------------------  // acclient.c:276145
void __thiscall gmUIElement_PortalStormIndicator::RecvNotice_PortalStormLevel(gmUIElement_PortalStormIndicator *this, float i_fExtent)
{
  gmUIElement_PortalStormIndicator::Update((gmUIElement_PortalStormIndicator *)((char *)this - 1824), i_fExtent);
}

//----- (006F6620) --------------------------------------------------------  // acclient.c:779080
void sub_6F6620()
{
  flt_8407E8 = 1000.0 + 1.0;
}

//----- (006F6640) --------------------------------------------------------  // acclient.c:779086
void _E93_93()
{
  flt_8407EC = 24.0 * 8.0;
}

//----- (006F6660) --------------------------------------------------------  // acclient.c:779092
void _E95_93()
{
  flt_8407F0 = 24.0 * 0.5;
}

//----- (006F6680) --------------------------------------------------------  // acclient.c:779098
int sub_6F6680()
{
  return atexit(nullsub_965);
}

//----- (006F6690) --------------------------------------------------------  // acclient.c:779104
int sub_6F6690()
{
  return atexit(nullsub_966);
}

//----- (006F66A0) --------------------------------------------------------  // acclient.c:779110
int sub_6F66A0()
{
  return atexit(nullsub_967);
}

//----- (006F66B0) --------------------------------------------------------  // acclient.c:779116
int sub_6F66B0()
{
  return atexit(nullsub_964);
}

