/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_CharGen
   Object     : GAME\game_cevents\CM_CharGen.obj
   Functions  : 9
   Addresses  : 006AF740 - 00723230 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AF740) --------------------------------------------------------  // acclient.c:712804
char __cdecl CM_CharGen::SendNotice_CharGenVerificationResponse(CG_VERIFICATION_RESPONSE i_rsvp)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&byte_4DD22C);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, CG_VERIFICATION_RESPONSE))(*(_DWORD *)v4 + 116))(v4, i_rsvp);
    }
  }
  return 1;
}
// 4DD22C: using guessed type char byte_4DD22C;

//----- (00723190) --------------------------------------------------------  // acclient.c:821009
int sub_723190()
{
  return atexit(nullsub_378);
}

//----- (007231A0) --------------------------------------------------------  // acclient.c:821015
int sub_7231A0()
{
  return atexit(nullsub_379);
}

//----- (007231B0) --------------------------------------------------------  // acclient.c:821021
int sub_7231B0()
{
  return atexit(nullsub_380);
}

//----- (007231C0) --------------------------------------------------------  // acclient.c:821027
void _E98_20()
{
  LODWORD(dword_8FA718) = 1053364187;
}

//----- (007231D0) --------------------------------------------------------  // acclient.c:821033
void sub_7231D0()
{
  flt_8FA71C = 1000.0 + 1.0;
}

//----- (007231F0) --------------------------------------------------------  // acclient.c:821039
void _E102_41()
{
  flt_8FA720 = 24.0 * 8.0;
}

//----- (00723210) --------------------------------------------------------  // acclient.c:821045
void _E104_21()
{
  flt_8FA724 = 24.0 * 0.5;
}

//----- (00723230) --------------------------------------------------------  // acclient.c:821051
int sub_723230()
{
  return atexit(nullsub_377);
}

