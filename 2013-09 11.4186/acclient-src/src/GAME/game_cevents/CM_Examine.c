/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Examine
   Object     : GAME\game_cevents\CM_Examine.obj
   Functions  : 10
   Addresses  : 006AF640 - 00723180 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AF640) --------------------------------------------------------  // acclient.c:712726
char __cdecl CM_Examine::SendNotice_ExamineObject(unsigned int i_objid)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD1EC + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 212))(v4, i_objid);
    }
  }
  return 1;
}

//----- (006AF690) --------------------------------------------------------  // acclient.c:712752
char __cdecl CM_Examine::SendNotice_ExamineSpell(unsigned int i_spellid)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD1EE);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 216))(v4, i_spellid);
    }
  }
  return 1;
}

//----- (006AF6E0) --------------------------------------------------------  // acclient.c:712778
char __cdecl CM_Examine::SendNotice_SetAppraiseInfo(unsigned int i_objid, AppraisalProfile *i_prof)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1E7);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, unsigned int, AppraisalProfile *))(*(_DWORD *)v5 + 220))(v5, i_objid, i_prof);
    }
  }
  return 1;
}

//----- (007230F0) --------------------------------------------------------  // acclient.c:820967
void sub_7230F0()
{
  flt_8FA6EC = 1000.0 + 1.0;
}

//----- (00723110) --------------------------------------------------------  // acclient.c:820973
void sub_723110()
{
  flt_8FA6F0 = 24.0 * 8.0;
}

//----- (00723130) --------------------------------------------------------  // acclient.c:820979
void sub_723130()
{
  flt_8FA6F4 = 24.0 * 0.5;
}

//----- (00723150) --------------------------------------------------------  // acclient.c:820985
int sub_723150()
{
  return atexit(nullsub_397);
}

//----- (00723160) --------------------------------------------------------  // acclient.c:820991
int sub_723160()
{
  return atexit(nullsub_398);
}

//----- (00723170) --------------------------------------------------------  // acclient.c:820997
int sub_723170()
{
  return atexit(nullsub_399);
}

//----- (00723180) --------------------------------------------------------  // acclient.c:821003
int sub_723180()
{
  return atexit(nullsub_396);
}

