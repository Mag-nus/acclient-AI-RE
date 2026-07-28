/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_UI
   Object     : GAME\game_cevents\CM_UI.obj
   Functions  : 35
   Addresses  : 00479A90 - 006EC620 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00479A90) --------------------------------------------------------  // acclient.c:182893
char __cdecl CM_UI::SendNotice_ClearChatBuffer(unsigned int i_idWindowToClear)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD250 + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 532))(v4, i_idWindowToClear);
    }
  }
  return 1;
}

//----- (00479AE0) --------------------------------------------------------  // acclient.c:182919
char __cdecl CM_UI::SendNotice_EnableChatTargetSelection(unsigned int i_eTalkFocus, int i_bEnabled)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD250 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v5 + 536))(v5, i_eTalkFocus, i_bEnabled);
    }
  }
  return 1;
}

//----- (00479B40) --------------------------------------------------------  // acclient.c:182945
char __cdecl CM_UI::SendNotice_EndCharacterSession(int i_confirm)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD1E0 + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 540))(v4, i_confirm);
    }
  }
  return 1;
}

//----- (00479B90) --------------------------------------------------------  // acclient.c:182971
char __cdecl CM_UI::SendNotice_FillComponentBuyList(SpellComponentCategory i_sp_cat, int i_max_to_buy)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD258 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, SpellComponentCategory, int))(*(_DWORD *)v5 + 544))(v5, i_sp_cat, i_max_to_buy);
    }
  }
  return 1;
}

//----- (00479BF0) --------------------------------------------------------  // acclient.c:182997
char __cdecl CM_UI::SendNotice_FontSettingsChanged(unsigned int i_nFontFace, unsigned int i_nFontSize)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD264 + 3));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v5 + 548))(v5, i_nFontFace, i_nFontSize);
    }
  }
  return 1;
}

//----- (00479C50) --------------------------------------------------------  // acclient.c:183023
char __cdecl CM_UI::SendNotice_FullMergingItem(unsigned int i_oldObject, unsigned int i_mergeTo)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD1E7 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v5 + 552))(v5, i_oldObject, i_mergeTo);
    }
  }
  return 1;
}

//----- (00479CB0) --------------------------------------------------------  // acclient.c:183049
char __cdecl CM_UI::SendNotice_GameplayOptionChanged(BaseProperty *i_prop, unsigned int i_i_nUserData)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD26D + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, BaseProperty *, unsigned int))(*(_DWORD *)v5 + 556))(v5, i_prop, i_i_nUserData);
    }
  }
  return 1;
}

//----- (00479D10) --------------------------------------------------------  // acclient.c:183075
char __cdecl CM_UI::SendNotice_LoadUI(PStringBase<char> *i_file_name)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD27F + 5));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v4 + 560))(v4, i_file_name);
    }
  }
  return 1;
}

//----- (00479D60) --------------------------------------------------------  // acclient.c:183101
char __cdecl CM_UI::SendNotice_NewParentContainer(unsigned int i_i_newContainerID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD1F5 + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 568))(v4, i_i_newContainerID);
    }
  }
  return 1;
}

//----- (00479DB0) --------------------------------------------------------  // acclient.c:183127
char __cdecl CM_UI::SendNotice_OpenContainedContainer(unsigned int i_containerID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD264 + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 572))(v4, i_containerID);
    }
  }
  return 1;
}

//----- (00479E00) --------------------------------------------------------  // acclient.c:183153
char __cdecl CM_UI::SendNotice_PlayerDescReceived(CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1F0);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, CACQualities *, CPlayerModule *))(*(_DWORD *)v5 + 576))(
          v5,
          i_playerDesc,
          i_playerModule);
    }
  }
  return 1;
}

//----- (00479E60) --------------------------------------------------------  // acclient.c:183182
char __cdecl CM_UI::SendNotice_PlayerOptionChanged(PlayerOption i_eOption)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD21E + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PlayerOption))(*(_DWORD *)v4 + 580))(v4, i_eOption);
    }
  }
  return 1;
}

//----- (00479EB0) --------------------------------------------------------  // acclient.c:183208
char __cdecl CM_UI::SendNotice_RefreshOptionsPanel()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD216 + 1));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 584))(v3);
    }
  }
  return 1;
}

//----- (00479F00) --------------------------------------------------------  // acclient.c:183234
char __cdecl CM_UI::SendNotice_SaveUI(PStringBase<char> *i_file_name)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD27F + 4));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v4 + 588))(v4, i_file_name);
    }
  }
  return 1;
}

//----- (00479F50) --------------------------------------------------------  // acclient.c:183260
char __cdecl CM_UI::SendNotice_SelectionChanged()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD1EE + 1));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 592))(v3);
    }
  }
  return 1;
}

//----- (00479FA0) --------------------------------------------------------  // acclient.c:183286
char __cdecl CM_UI::SendNotice_SetChatWindowTitle(unsigned int i_idWindowToSet, StringInfo *i_siTitle)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD26D + 3));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, StringInfo *))(*(_DWORD *)v5 + 596))(v5, i_idWindowToSet, i_siTitle);
    }
  }
  return 1;
}

//----- (0047A000) --------------------------------------------------------  // acclient.c:183312
char __cdecl CM_UI::SendNotice_SetDisplayInventory(int i_display)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD1F0 + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 600))(v4, i_display);
    }
  }
  return 1;
}

//----- (0047A050) --------------------------------------------------------  // acclient.c:183338
char __cdecl CM_UI::SendNotice_SetFramerateDisplay(int i_bVisible)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD1FF);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 604))(v4, i_bVisible);
    }
  }
  return 1;
}

//----- (0047A0A0) --------------------------------------------------------  // acclient.c:183364
char __cdecl CM_UI::SendNotice_SetPanelVisibility(unsigned int i_ePanelID, int i_bVisible)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD1F7 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, int))(*(_DWORD *)v5 + 608))(v5, i_ePanelID, i_bVisible);
    }
  }
  return 1;
}

//----- (0047A100) --------------------------------------------------------  // acclient.c:183390
char __cdecl CM_UI::SendNotice_SplitStack(unsigned int i_i_iidItem)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD242 + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 612))(v4, i_i_iidItem);
    }
  }
  return 1;
}

//----- (0047A150) --------------------------------------------------------  // acclient.c:183416
char __cdecl CM_UI::SendNotice_StackSliderChanged(unsigned int i_splitSize, unsigned int i_maxSplitSize)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)&loc_4DD264);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v5 + 616))(v5, i_splitSize, i_maxSplitSize);
    }
  }
  return 1;
}

//----- (0047A1B0) --------------------------------------------------------  // acclient.c:183442
char __cdecl CM_UI::SendNotice_StartTell(PStringBase<unsigned short> *i_strName)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD26D + 4));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PStringBase<unsigned short> *))(*(_DWORD *)v4 + 620))(v4, i_strName);
    }
  }
  return 1;
}

//----- (0047A200) --------------------------------------------------------  // acclient.c:183468
char __cdecl CM_UI::SendNotice_ToggleChatEntry(int i_bActive)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD26D);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 624))(v4, i_bActive);
    }
  }
  return 1;
}

//----- (0047A250) --------------------------------------------------------  // acclient.c:183494
char __cdecl CM_UI::SendNotice_UpdateRadarVisibility(int i_bRadarVisible)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD25A + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 632))(v4, i_bRadarVisible);
    }
  }
  return 1;
}

//----- (0047A2A0) --------------------------------------------------------  // acclient.c:183520
char __cdecl CM_UI::SendNotice_UpdateSquelchPanel()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD279 + 3));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 636))(v3);
    }
  }
  return 1;
}

//----- (0047A2F0) --------------------------------------------------------  // acclient.c:183546
char __cdecl CM_UI::SendNotice_UpdateToolbarSelectionDisplay()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD25A + 4));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 640))(v3);
    }
  }
  return 1;
}

//----- (0047A340) --------------------------------------------------------  // acclient.c:183572
char __cdecl CM_UI::SendNotice_UserPreferenceChanged(PStringBase<char> *i_strPref)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD21E);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v4 + 644))(v4, i_strPref);
    }
  }
  return 1;
}

//----- (0047A390) --------------------------------------------------------  // acclient.c:183598
char __cdecl CM_UI::SendNotice_UserPreferenceChanged_Menu(PStringBase<char> *i_strPref, unsigned int i_oldValue, unsigned int i_newValue)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD275 + 1));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, PStringBase<char> *, unsigned int, unsigned int))(*(_DWORD *)v6 + 648))(
          v6,
          i_strPref,
          i_oldValue,
          i_newValue);
    }
  }
  return 1;
}

//----- (006EC590) --------------------------------------------------------  // acclient.c:768208
void _E91_36()
{
  outside_val_28 = 1000.0 + 1.0;
}

//----- (006EC5B0) --------------------------------------------------------  // acclient.c:768214
void _E93_12()
{
  block_length_28 = 24.0 * 8.0;
}

//----- (006EC5D0) --------------------------------------------------------  // acclient.c:768220
void _E95_12()
{
  half_square_length_28 = 24.0 * 0.5;
}

//----- (006EC5F0) --------------------------------------------------------  // acclient.c:768226
int _E97_37()
{
  return atexit(_E98_49);
}

//----- (006EC600) --------------------------------------------------------  // acclient.c:768232
int _E100_30()
{
  return atexit(_E101_67);
}

//----- (006EC610) --------------------------------------------------------  // acclient.c:768238
int _E103_22()
{
  return atexit(_E104_37);
}

//----- (006EC620) --------------------------------------------------------  // acclient.c:768244
int _E1_88()
{
  return atexit(_E2_88);
}

