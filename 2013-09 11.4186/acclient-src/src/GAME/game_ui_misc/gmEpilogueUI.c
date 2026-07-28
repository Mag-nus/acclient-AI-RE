/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmEpilogueUI
   Object     : GAME\game_ui_misc\gmEpilogueUI.obj
   Functions  : 29
   Addresses  : 004E9B00 - 007636E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E9B00) --------------------------------------------------------  // acclient.c:279159
void __thiscall gmEpilogueUI::gmEpilogueUI(gmEpilogueUI *this)
{
  gmEpilogueUI *v1; // esi@1
  CPlayerSystem *v2; // eax@1

  v1 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmEpilogueUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->m_epilogueField = 0;
  UIListener::RegisterForElementMessage((UIListener *)&v1->vfptr, 0x10000399u, 0x10000002u);
  v1->m_epilogueField = (UIElement *)UIMainFramework::CreateAndAddRootElement(
                                       (UIMainFramework *)&v1->vfptr,
                                       0x10000037u,
                                       0x10000399u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  v2 = CPlayerSystem::GetPlayerSystem();
  if ( v2 )
  {
    if ( *(_WORD *)&SharedNet::s_pNet[1].receivers_[454] )
      CPlayerSystem::LogOffCharacter(v2, 1);
  }
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C2408: using guessed type int (__thiscall *gmEpilogueUI::vftable)(void *, char);

//----- (004E9B90) --------------------------------------------------------  // acclient.c:279187
void __cdecl gmEpilogueUI::Create()
{
  gmEpilogueUI *v0; // eax@1

  v0 = (gmEpilogueUI *)operator new(0xA0u);
  if ( v0 )
    gmEpilogueUI::gmEpilogueUI(v0);
}

//----- (004E9BB0) --------------------------------------------------------  // acclient.c:279197
gmEpilogueUI *__thiscall gmEpilogueUI::vector_deleting_destructor(gmEpilogueUI *this, unsigned int a2)
{
  gmEpilogueUI *v2; // esi@1
  NoticeHandler *v3; // edi@1

  v2 = this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmEpilogueUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 1u);
  UIMainFramework::RemoveRootElement((UIMainFramework *)&v2->vfptr, &v2->m_epilogueField);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  v2->vfptr = (IInputActionCallbackVtbl *)&gmUIMainFramework::vftable;
  UIMainFramework::~UIMainFramework((UIMainFramework *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C1CA0: using guessed type int (__thiscall *gmUIMainFramework::vftable)(void *, char);
// 7C2408: using guessed type int (__thiscall *gmEpilogueUI::vftable)(void *, char);

//----- (004E9C10) --------------------------------------------------------  // acclient.c:279221
void __cdecl gmEpilogueUI::Register(unsigned int _mode)
{
  UIFlow::RegisterFrameworkClass(_mode, (UIMainFramework *(__cdecl *)())gmEpilogueUI::Create);
}

//----- (004E9C30) --------------------------------------------------------  // acclient.c:279227
void __stdcall gmEpilogueUI::ListenToGlobalMessage(unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 1 )
    Device::Done();
}

//----- (004E9C40) --------------------------------------------------------  // acclient.c:279234
UIElementMessageListenResult __stdcall gmEpilogueUI::ListenToElementMessage(unsigned int i_elementID, UIElement *i_element, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 268435458 )
    Device::Done();
  return 0;
}

//----- (006F6D20) --------------------------------------------------------  // acclient.c:779542
void sub_6F6D20()
{
  flt_840A00 = 1000.0 + 1.0;
}

//----- (006F6D40) --------------------------------------------------------  // acclient.c:779548
void sub_6F6D40()
{
  flt_840A04 = 24.0 * 8.0;
}

//----- (006F6D60) --------------------------------------------------------  // acclient.c:779554
void sub_6F6D60()
{
  flt_840A08 = 24.0 * 0.5;
}

//----- (006F6D80) --------------------------------------------------------  // acclient.c:779560
int sub_6F6D80()
{
  return atexit(nullsub_541);
}

//----- (006F6D90) --------------------------------------------------------  // acclient.c:779566
int sub_6F6D90()
{
  return atexit(nullsub_542);
}

//----- (006F6DA0) --------------------------------------------------------  // acclient.c:779572
int sub_6F6DA0()
{
  return atexit(nullsub_543);
}

//----- (006F6DB0) --------------------------------------------------------  // acclient.c:779578
int _E106_75()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_16, "Display.Resolution");
  return atexit(_E107_78);
}

//----- (006F6DD0) --------------------------------------------------------  // acclient.c:779585
int _E109_46()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_16, "Display.FullScreen");
  return atexit(sub_763680);
}

//----- (006F6DF0) --------------------------------------------------------  // acclient.c:779592
int _E112_67()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_16, "Display.RefreshRate");
  return atexit(_E113_53);
}

//----- (006F6E10) --------------------------------------------------------  // acclient.c:779599
int _E115_50()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_16, "Display.SyncToRefresh");
  return atexit(_E116_45);
}

//----- (006F6E30) --------------------------------------------------------  // acclient.c:779606
void _E118_51()
{
  dword_840A1C = 1024;
}

//----- (006F6E40) --------------------------------------------------------  // acclient.c:779612
void _E120_41()
{
  dword_840A20 = 0x7FFF;
}

//----- (006F6E50) --------------------------------------------------------  // acclient.c:779618
int _E122_22()
{
  const int result; // eax@1

  result = dword_840A1C;
  INITIAL_MAX_DATA_RATE_50 = dword_840A1C;
  return result;
}

//----- (006F6E60) --------------------------------------------------------  // acclient.c:779628
void _E124_48()
{
  DEFAULT_VIEW_RADIUS_78 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F6E80) --------------------------------------------------------  // acclient.c:779634
void _E126_24()
{
  MIN_QUANTUM_78 = 1.0 / 30.0;
}

//----- (006F6EA0) --------------------------------------------------------  // acclient.c:779640
void _E128_8()
{
  MAX_QUANTUM_78 = 1.0 / 5.0;
}

//----- (006F6EC0) --------------------------------------------------------  // acclient.c:779646
void _E130_36()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840A40, PFID_A8R8G8B8);
}

//----- (006F6ED0) --------------------------------------------------------  // acclient.c:779652
int _E132_21()
{
  return atexit(_E133_82);
}

//----- (006F6EE0) --------------------------------------------------------  // acclient.c:779658
int sub_6F6EE0()
{
  return atexit(nullsub_540);
}

//----- (00763650) --------------------------------------------------------  // acclient.c:890042
void __cdecl _E107_78()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763680) --------------------------------------------------------  // acclient.c:890055
void __cdecl sub_763680()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007636B0) --------------------------------------------------------  // acclient.c:890068
void __cdecl _E113_53()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007636E0) --------------------------------------------------------  // acclient.c:890081
void __cdecl _E116_45()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

