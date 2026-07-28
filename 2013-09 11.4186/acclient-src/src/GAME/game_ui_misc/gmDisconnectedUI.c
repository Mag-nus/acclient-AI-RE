/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmDisconnectedUI
   Object     : GAME\game_ui_misc\gmDisconnectedUI.obj
   Functions  : 22
   Addresses  : 004E9970 - 007635D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E9970) --------------------------------------------------------  // acclient.c:279062
void __thiscall gmDisconnectedUI::~gmDisconnectedUI(gmDisconnectedUI *this)
{
  gmDisconnectedUI *v1; // esi@1
  NoticeHandler *v2; // edi@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmDisconnectedUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  UIListener::UnRegisterForElementMessage((UIListener *)&this->vfptr, 0x10000418u, 1u);
  UIMainFramework::RemoveRootElement((UIMainFramework *)&v1->vfptr, &v1->m_disconnectedField);
  v1->m_errorText = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIMainFramework::~UIMainFramework((UIMainFramework *)&v1->vfptr);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C22B8: using guessed type int (__thiscall *gmDisconnectedUI::vftable)(void *, char);

//----- (004E99C0) --------------------------------------------------------  // acclient.c:279082
signed int __thiscall gmDisconnectedUI::ListenToElementMessage(gmDisconnectedUI *this, UIElementMessageInfo *i_rMsg)
{
  UIFramework *v2; // esi@1

  v2 = (UIFramework *)this;
  if ( i_rMsg->idElement == 268436504 && i_rMsg->idMessage == 1 )
    UIFramework::QueueUIMode(0x10000009u);
  return UIFramework::ListenToElementMessage(v2, i_rMsg);
}

//----- (004E99F0) --------------------------------------------------------  // acclient.c:279093
void __thiscall gmDisconnectedUI::SetErrorMsg(gmDisconnectedUI *this, StringInfo *err)
{
  UIElement_Text *v2; // ecx@1

  v2 = this->m_errorText;
  if ( v2 )
    UIElement_Text::SetStringInfo(v2, err);
}

//----- (004E9A10) --------------------------------------------------------  // acclient.c:279103
void __thiscall gmDisconnectedUI::gmDisconnectedUI(gmDisconnectedUI *this)
{
  gmDisconnectedUI *v1; // esi@1
  int v2; // eax@1
  UIElement *v3; // eax@2

  v1 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmDisconnectedUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->m_disconnectedField = 0;
  v1->m_errorText = 0;
  v2 = UIMainFramework::CreateAndAddRootElement((UIMainFramework *)&v1->vfptr, 0x10000003u, 0x10000416u);
  v1->m_disconnectedField = (UIElement *)v2;
  if ( v2 )
  {
    v3 = UIElement::GetChildRecursive((UIElement *)v2, 0x10000417u);
    if ( v3 )
      v1->m_errorText = (UIElement_Text *)v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
    else
      v1->m_errorText = 0;
  }
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C22B8: using guessed type int (__thiscall *gmDisconnectedUI::vftable)(void *, char);

//----- (004E9AA0) --------------------------------------------------------  // acclient.c:279131
gmDisconnectedUI *__thiscall gmDisconnectedUI::scalar_deleting_destructor(gmDisconnectedUI *this, unsigned int a2)
{
  gmDisconnectedUI *v2; // esi@1

  v2 = this;
  gmDisconnectedUI::~gmDisconnectedUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E9AC0) --------------------------------------------------------  // acclient.c:279143
void __cdecl gmDisconnectedUI::Create()
{
  gmDisconnectedUI *v0; // eax@1

  v0 = (gmDisconnectedUI *)operator new(0xA4u);
  if ( v0 )
    gmDisconnectedUI::gmDisconnectedUI(v0);
}

//----- (004E9AE0) --------------------------------------------------------  // acclient.c:279153
void __cdecl gmDisconnectedUI::Register(unsigned int mode)
{
  UIFlow::RegisterFrameworkClass(mode, (UIMainFramework *(__cdecl *)())gmDisconnectedUI::Create);
}

//----- (006F6C00) --------------------------------------------------------  // acclient.c:779472
void sub_6F6C00()
{
  flt_8409C0 = 1000.0 + 1.0;
}

//----- (006F6C20) --------------------------------------------------------  // acclient.c:779478
void sub_6F6C20()
{
  flt_8409C4 = 24.0 * 8.0;
}

//----- (006F6C40) --------------------------------------------------------  // acclient.c:779484
void sub_6F6C40()
{
  flt_8409C8 = 24.0 * 0.5;
}

//----- (006F6C60) --------------------------------------------------------  // acclient.c:779490
int sub_6F6C60()
{
  return atexit(nullsub_494);
}

//----- (006F6C70) --------------------------------------------------------  // acclient.c:779496
int sub_6F6C70()
{
  return atexit(nullsub_495);
}

//----- (006F6C80) --------------------------------------------------------  // acclient.c:779502
int sub_6F6C80()
{
  return atexit(nullsub_496);
}

//----- (006F6C90) --------------------------------------------------------  // acclient.c:779508
int _E106_74()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_15, "Display.Resolution");
  return atexit(_E107_77);
}

//----- (006F6CB0) --------------------------------------------------------  // acclient.c:779515
int _E109_45()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_15, "Display.FullScreen");
  return atexit(sub_763570);
}

//----- (006F6CD0) --------------------------------------------------------  // acclient.c:779522
int _E112_66()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_15, "Display.RefreshRate");
  return atexit(_E113_52);
}

//----- (006F6CF0) --------------------------------------------------------  // acclient.c:779529
int _E115_49()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_15, "Display.SyncToRefresh");
  return atexit(_E116_44);
}

//----- (006F6D10) --------------------------------------------------------  // acclient.c:779536
int sub_6F6D10()
{
  return atexit(nullsub_493);
}

//----- (00763540) --------------------------------------------------------  // acclient.c:889990
void __cdecl _E107_77()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763570) --------------------------------------------------------  // acclient.c:890003
void __cdecl sub_763570()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007635A0) --------------------------------------------------------  // acclient.c:890016
void __cdecl _E113_52()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007635D0) --------------------------------------------------------  // acclient.c:890029
void __cdecl _E116_44()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

