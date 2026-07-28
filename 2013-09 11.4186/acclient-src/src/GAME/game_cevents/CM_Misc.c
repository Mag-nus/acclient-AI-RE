/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Misc
   Object     : GAME\game_cevents\CM_Misc.obj
   Functions  : 21
   Addresses  : 006AF4E0 - 007230E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AF4E0) --------------------------------------------------------  // acclient.c:712625
unsigned int __cdecl CM_Misc::DispatchUI_PortalStorm(UIQueueManager *ui, void *buf)
{
  ClientUISystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pUISystem) != 0 && *(_DWORD *)buf == 715 )
    result = ClientUISystem::Handle_Misc__PortalStorm(v2);
  else
    result = 0;
  return result;
}

//----- (006AF510) --------------------------------------------------------  // acclient.c:712638
unsigned int __cdecl CM_Misc::DispatchUI_PortalStormBrewing(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 713 )
    result = ClientUISystem::Handle_Misc__PortalStormBrewing(*((float *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006AF540) --------------------------------------------------------  // acclient.c:712650
unsigned int __cdecl CM_Misc::DispatchUI_PortalStormImminent(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 714 )
    result = ClientUISystem::Handle_Misc__PortalStormImminent(*((float *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006AF570) --------------------------------------------------------  // acclient.c:712662
unsigned int __cdecl CM_Misc::DispatchUI_PortalStormSubsided(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 716 )
    result = ClientUISystem::Handle_Misc__PortalStormSubsided();
  else
    result = 0;
  return result;
}

//----- (006AF5A0) --------------------------------------------------------  // acclient.c:712674
char __cdecl CM_Misc::SendNotice_PlayerPortalStormed()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD21C);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 432))(v3);
    }
  }
  return 1;
}

//----- (006AF5F0) --------------------------------------------------------  // acclient.c:712700
char __cdecl CM_Misc::SendNotice_PortalStormLevel(float i_fExtent)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD21A + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 436))(v4, LODWORD(i_fExtent));
    }
  }
  return 1;
}

//----- (00722FA0) --------------------------------------------------------  // acclient.c:820873
void sub_722FA0()
{
  flt_8FA668 = 1000.0 + 1.0;
}

//----- (00722FC0) --------------------------------------------------------  // acclient.c:820879
void sub_722FC0()
{
  flt_8FA66C = 24.0 * 8.0;
}

//----- (00722FE0) --------------------------------------------------------  // acclient.c:820885
void sub_722FE0()
{
  flt_8FA670 = 24.0 * 0.5;
}

//----- (00723000) --------------------------------------------------------  // acclient.c:820891
int sub_723000()
{
  return atexit(nullsub_437);
}

//----- (00723010) --------------------------------------------------------  // acclient.c:820897
int sub_723010()
{
  return atexit(nullsub_438);
}

//----- (00723020) --------------------------------------------------------  // acclient.c:820903
int sub_723020()
{
  return atexit(nullsub_439);
}

//----- (00723030) --------------------------------------------------------  // acclient.c:820909
void sub_723030()
{
  flt_8FA674 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00723050) --------------------------------------------------------  // acclient.c:820915
void sub_723050()
{
  dbl_8FA678 = 1.0 / 30.0;
}

//----- (00723070) --------------------------------------------------------  // acclient.c:820921
void _E110_98()
{
  dbl_8FA680 = 1.0 / 5.0;
}

//----- (00723090) --------------------------------------------------------  // acclient.c:820927
void sub_723090()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA688, PFID_A8R8G8B8);
}

//----- (007230A0) --------------------------------------------------------  // acclient.c:820933
void sub_7230A0()
{
  dword_8FA6C0 = 1024;
}

//----- (007230B0) --------------------------------------------------------  // acclient.c:820939
void sub_7230B0()
{
  dword_8FA6C4 = 0x7FFF;
}

//----- (007230C0) --------------------------------------------------------  // acclient.c:820945
int _E119_50()
{
  const int result; // eax@1

  result = dword_8FA6C0;
  dword_8FA6C8 = dword_8FA6C0;
  return result;
}

//----- (007230D0) --------------------------------------------------------  // acclient.c:820955
int sub_7230D0()
{
  return atexit(nullsub_435);
}

//----- (007230E0) --------------------------------------------------------  // acclient.c:820961
int sub_7230E0()
{
  return atexit(nullsub_436);
}

