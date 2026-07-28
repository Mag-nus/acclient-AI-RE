/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUIElement_MiniGameIndicator
   Object     : GAME\game_ui_misc\gmUIElement_MiniGameIndicator.obj
   Functions  : 14
   Addresses  : 004E6350 - 006F6750 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E6350) --------------------------------------------------------  // acclient.c:276151
gmUIElement_MiniGameIndicator *__thiscall gmUIElement_MiniGameIndicator::DynamicCast(gmUIElement_MiniGameIndicator *this, unsigned int i_eType)
{
  gmUIElement_MiniGameIndicator *result; // eax@1

  result = this;
  if ( i_eType != 268435460 && i_eType != 1 && i_eType != 12 )
    result = (gmUIElement_MiniGameIndicator *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E6390) --------------------------------------------------------  // acclient.c:276168
void __thiscall gmUIElement_MiniGameIndicator::PostInit(gmUIElement_MiniGameIndicator *this)
{
  gmUIElement_MiniGameIndicator *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@2

  v1 = this;
  UIElement_Button::PostInit((UIElement_Button *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v3 = (int)&v1->vfptr;
  else
    v3 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD218 + 1), (NoticeHandler *)v3);
  if ( v1 )
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD21A, (NoticeHandler *)&v1->vfptr);
  else
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD21A, 0);
}

//----- (004E63F0) --------------------------------------------------------  // acclient.c:276189
UIElement *__usercall gmUIElement_MiniGameIndicator::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x728u);
  if ( v3 )
  {
    UIElement_Button::UIElement_Button((UIElement_Button *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 456) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmUIElement_MiniGameIndicator::vftable;
    *((_DWORD *)v3 + 386) = &UIOption_Menu::vftable;
    *((_DWORD *)v3 + 456) = &gmUIElement_MiniGameIndicator::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C0D48: using guessed type bool (__thiscall *gmUIElement_MiniGameIndicator::vftable)(DBCache *this);
// 7C0FF0: using guessed type int (__thiscall *gmUIElement_MiniGameIndicator::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (004E6450) --------------------------------------------------------  // acclient.c:276216
void __thiscall gmUIElement_MiniGameIndicator::RecvNotice_BeginGame(gmUIElement_MiniGameIndicator *this, unsigned int iidGame)
{
  this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[39].__vecDelDtor(
    &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable,
    1u);
}

//----- (004E6470) --------------------------------------------------------  // acclient.c:276224
void __thiscall gmUIElement_MiniGameIndicator::RecvNotice_EndGame(gmUIElement_MiniGameIndicator *this)
{
  this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.vfptr[39].__vecDelDtor(
    &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable,
    13u);
}

//----- (004E6490) --------------------------------------------------------  // acclient.c:276232
UIElement_Button *__thiscall gmUIElement_MiniGameIndicator::vector_deleting_destructor(gmUIElement_MiniGameIndicator *this, unsigned int a2)
{
  UIElement_Button *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Button *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_MiniGameIndicator::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmUIElement_MiniGameIndicator::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Button::~UIElement_Button(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C0D48: using guessed type bool (__thiscall *gmUIElement_MiniGameIndicator::vftable)(DBCache *this);
// 7C0FF0: using guessed type int (__thiscall *gmUIElement_MiniGameIndicator::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (004E64F0) --------------------------------------------------------  // acclient.c:276259
void __cdecl gmUIElement_MiniGameIndicator::Register()
{
  UIElement::RegisterElementClass(
    0x10000004u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmUIElement_MiniGameIndicator::Create);
}

//----- (006F66C0) --------------------------------------------------------  // acclient.c:779122
void sub_6F66C0()
{
  flt_840814 = 1000.0 + 1.0;
}

//----- (006F66E0) --------------------------------------------------------  // acclient.c:779128
void _E93_94()
{
  flt_840818 = 24.0 * 8.0;
}

//----- (006F6700) --------------------------------------------------------  // acclient.c:779134
void _E95_94()
{
  flt_84081C = 24.0 * 0.5;
}

//----- (006F6720) --------------------------------------------------------  // acclient.c:779140
int sub_6F6720()
{
  return atexit(nullsub_961);
}

//----- (006F6730) --------------------------------------------------------  // acclient.c:779146
int sub_6F6730()
{
  return atexit(nullsub_962);
}

//----- (006F6740) --------------------------------------------------------  // acclient.c:779152
int sub_6F6740()
{
  return atexit(nullsub_963);
}

//----- (006F6750) --------------------------------------------------------  // acclient.c:779158
int sub_6F6750()
{
  return atexit(nullsub_960);
}

