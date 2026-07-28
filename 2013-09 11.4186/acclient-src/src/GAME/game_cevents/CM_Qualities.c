/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Qualities
   Object     : GAME\game_cevents\CM_Qualities.obj
   Functions  : 59
   Addresses  : 006AE600 - 00722F90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AE600) --------------------------------------------------------  // acclient.c:711672
int __cdecl CM_Qualities::DispatchUI_PrivateRemoveBoolEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 467 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemoveBoolEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE640) --------------------------------------------------------  // acclient.c:711688
int __cdecl CM_Qualities::DispatchUI_PrivateRemoveDataIDEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 473 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemoveDataIDEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE680) --------------------------------------------------------  // acclient.c:711704
int __cdecl CM_Qualities::DispatchUI_PrivateRemoveFloatEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 469 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemoveFloatEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE6C0) --------------------------------------------------------  // acclient.c:711720
int __cdecl CM_Qualities::DispatchUI_PrivateRemoveInstanceIDEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 475 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemoveInstanceIDEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE700) --------------------------------------------------------  // acclient.c:711736
int __cdecl CM_Qualities::DispatchUI_PrivateRemoveInt64Event(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 696 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemoveInt64Event(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE740) --------------------------------------------------------  // acclient.c:711752
int __cdecl CM_Qualities::DispatchUI_PrivateRemoveIntEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 465 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemoveIntEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE780) --------------------------------------------------------  // acclient.c:711768
int __cdecl CM_Qualities::DispatchUI_PrivateRemovePositionEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 477 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemovePositionEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE7C0) --------------------------------------------------------  // acclient.c:711784
int __cdecl CM_Qualities::DispatchUI_PrivateRemoveStringEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 471 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateRemoveStringEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5));
  else
    result = 0;
  return result;
}

//----- (006AE800) --------------------------------------------------------  // acclient.c:711800
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateAttribute(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // edi@1
  void *v4; // ecx@3
  char *v5; // eax@3
  bool v6; // zf@3
  int result; // eax@4
  char v8; // dl@5
  unsigned int v9; // esi@5
  Attribute value; // [sp+4h] [bp-10h]@5
  char uia; // [sp+18h] [bp+4h]@5

  v3 = ui;
  if ( ui
    && ui->m_pObjMaintSystem
    && (v4 = buf, v5 = (char *)buf + 4, v6 = *(_DWORD *)buf == 739, buf = (char *)buf + 4, v6) )
  {
    v8 = *v5;
    buf = v5 + 1;
    v9 = *(_DWORD *)(v5 + 1);
    buf = v5 + 5;
    uia = v8;
    value.vfptr = (PackObjVtbl *)&Attribute::vftable;
    value._level_from_cp = 0;
    value._init_level = 0;
    value._cp_spent = 0;
    Attribute::UnPack(&value, &buf, size + (_BYTE *)v4 - (v5 + 5));
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttribute(v3->m_pObjMaintSystem, uia, v9, &value);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);

//----- (006AE8A0) --------------------------------------------------------  // acclient.c:711838
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateAttribute2nd(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  void *v4; // ecx@3
  char *v5; // eax@3
  bool v6; // zf@3
  int result; // eax@4
  char v8; // dl@5
  unsigned int v9; // esi@5
  SecondaryAttribute value; // [sp+8h] [bp-14h]@5
  char uia; // [sp+20h] [bp+4h]@5

  v3 = ui;
  if ( ui
    && ui->m_pObjMaintSystem
    && (v4 = buf, v5 = (char *)buf + 4, v6 = *(_DWORD *)buf == 743, buf = (char *)buf + 4, v6) )
  {
    v8 = *v5;
    buf = v5 + 1;
    v9 = *(_DWORD *)(v5 + 1);
    uia = v8;
    buf = v5 + 5;
    value._level_from_cp = 0;
    value._init_level = 0;
    value._cp_spent = 0;
    value.vfptr = (PackObjVtbl *)&SecondaryAttribute::vftable;
    value._current_level = 0;
    SecondaryAttribute::UnPack(&value, &buf, size + (_BYTE *)v4 - (v5 + 5));
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttribute2nd(v3->m_pObjMaintSystem, uia, v9, &value);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (006AE930) --------------------------------------------------------  // acclient.c:711877
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateAttribute2ndLevel(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 745 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttribute2ndLevel(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AE970) --------------------------------------------------------  // acclient.c:711894
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateAttributeLevel(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 741 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateAttributeLevel(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AE9B0) --------------------------------------------------------  // acclient.c:711911
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateBool(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 721 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateBool(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AE9F0) --------------------------------------------------------  // acclient.c:711928
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateFloat(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 723 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateFloat(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(long double *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEA50) --------------------------------------------------------  // acclient.c:711945
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateInstanceID(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 729 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateInstanceID(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEA90) --------------------------------------------------------  // acclient.c:711962
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateInt(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 717 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateInt(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEAD0) --------------------------------------------------------  // acclient.c:711979
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateInt64(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 719 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateInt64(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_QWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEB20) --------------------------------------------------------  // acclient.c:711996
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateSkill(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  void *v4; // ecx@3
  char *v5; // eax@3
  bool v6; // zf@3
  int result; // eax@4
  char v8; // dl@5
  unsigned int v9; // edi@5
  Skill value; // [sp+8h] [bp-20h]@5
  char uia; // [sp+2Ch] [bp+4h]@5

  v3 = ui;
  if ( ui
    && ui->m_pObjMaintSystem
    && (v4 = buf, v5 = (char *)buf + 4, v6 = *(_DWORD *)buf == 733, buf = (char *)buf + 4, v6) )
  {
    v8 = *v5;
    buf = v5 + 1;
    v9 = *(_DWORD *)(v5 + 1);
    uia = v8;
    buf = v5 + 5;
    value.vfptr = (PackObjVtbl *)&Skill::vftable;
    value._sac = 0;
    value._pp = 0;
    value._init_level = 0;
    value._level_from_pp = 0;
    value._resistance_of_last_check = 0;
    *(_QWORD *)&value._last_used_time = 0i64;
    Skill::UnPack(&value, &buf, size + (_BYTE *)v4 - (v5 + 5));
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateSkill(v3->m_pObjMaintSystem, uia, v9, &value);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (006AEBD0) --------------------------------------------------------  // acclient.c:712037
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateSkillAC(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 737 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateSkillAC(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(SKILL_ADVANCEMENT_CLASS *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEC10) --------------------------------------------------------  // acclient.c:712054
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateSkillLevel(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 735 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateSkillLevel(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEC50) --------------------------------------------------------  // acclient.c:712071
int __cdecl CM_Qualities::DispatchUI_RemoveBoolEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 468 )
    result = ClientObjMaintSystem::Handle_Qualities__RemoveBoolEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEC90) --------------------------------------------------------  // acclient.c:712088
int __cdecl CM_Qualities::DispatchUI_RemoveDataIDEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 474 )
    result = ClientObjMaintSystem::Handle_Qualities__RemoveDataIDEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AECD0) --------------------------------------------------------  // acclient.c:712105
int __cdecl CM_Qualities::DispatchUI_RemoveFloatEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 470 )
    result = ClientObjMaintSystem::Handle_Qualities__RemoveFloatEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AED10) --------------------------------------------------------  // acclient.c:712122
int __cdecl CM_Qualities::DispatchUI_RemoveInstanceIDEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 476 )
    result = ClientObjMaintSystem::Handle_Qualities__RemoveInstanceIDEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AED50) --------------------------------------------------------  // acclient.c:712139
int __cdecl CM_Qualities::DispatchUI_RemoveInt64Event(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 697 )
    result = ClientObjMaintSystem::Handle_Qualities__RemoveInt64Event(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AED90) --------------------------------------------------------  // acclient.c:712156
int __cdecl CM_Qualities::DispatchUI_RemoveIntEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 466 )
    result = ClientObjMaintSystem::Handle_Qualities__RemoveIntEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEDD0) --------------------------------------------------------  // acclient.c:712173
int __cdecl CM_Qualities::DispatchUI_RemovePositionEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 478 )
    result = ClientObjMaintSystem::Handle_Qualities__RemovePositionEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEE10) --------------------------------------------------------  // acclient.c:712190
int __cdecl CM_Qualities::DispatchUI_RemoveStringEvent(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 472 )
    result = ClientObjMaintSystem::Handle_Qualities__RemoveStringEvent(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AEE50) --------------------------------------------------------  // acclient.c:712207
int __cdecl CM_Qualities::DispatchUI_UpdateAttribute(UIQueueManager *ui, void *buf, unsigned int size)
{
  int result; // eax@3
  void *v4; // ecx@4
  char *v5; // eax@4
  bool v6; // zf@4
  char v7; // bl@6
  unsigned int v8; // esi@6
  unsigned int v9; // edi@6
  Attribute value; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pObjMaintSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 740;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      v7 = *v5;
      buf = v5 + 1;
      v8 = *(_DWORD *)(v5 + 1);
      buf = v5 + 5;
      v9 = *(_DWORD *)(v5 + 5);
      buf = v5 + 9;
      value.vfptr = (PackObjVtbl *)&Attribute::vftable;
      value._level_from_cp = 0;
      value._init_level = 0;
      value._cp_spent = 0;
      Attribute::UnPack(&value, &buf, size + (_BYTE *)v4 - (v5 + 9));
      result = ClientObjMaintSystem::Handle_Qualities__UpdateAttribute(ui->m_pObjMaintSystem, v7, v8, v9, &value);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7B14: using guessed type int (__thiscall *Attribute::vftable)(void *, char);

//----- (006AEEF0) --------------------------------------------------------  // acclient.c:712253
int __cdecl CM_Qualities::DispatchUI_UpdateAttribute2nd(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebx@1
  void *v4; // ecx@3
  char *v5; // eax@3
  bool v6; // zf@3
  int result; // eax@4
  char v8; // dl@5
  unsigned int v9; // esi@5
  unsigned int v10; // edi@5
  SecondaryAttribute value; // [sp+8h] [bp-14h]@5
  char uia; // [sp+20h] [bp+4h]@5

  v3 = ui;
  if ( ui
    && ui->m_pObjMaintSystem
    && (v4 = buf, v5 = (char *)buf + 4, v6 = *(_DWORD *)buf == 744, buf = (char *)buf + 4, v6) )
  {
    v8 = *v5;
    buf = v5 + 1;
    v9 = *(_DWORD *)(v5 + 1);
    buf = v5 + 5;
    v10 = *(_DWORD *)(v5 + 5);
    value._level_from_cp = 0;
    value._init_level = 0;
    value._cp_spent = 0;
    value._current_level = 0;
    buf = v5 + 9;
    uia = v8;
    value.vfptr = (PackObjVtbl *)&SecondaryAttribute::vftable;
    SecondaryAttribute::UnPack(&value, &buf, size + (_BYTE *)v4 - (v5 + 9));
    result = ClientObjMaintSystem::Handle_Qualities__UpdateAttribute2nd(v3->m_pObjMaintSystem, uia, v9, v10, &value);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7B30: using guessed type int (__thiscall *SecondaryAttribute::vftable)(void *, char);

//----- (006AEF90) --------------------------------------------------------  // acclient.c:712295
int __cdecl CM_Qualities::DispatchUI_UpdateAttribute2ndLevel(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 746 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateAttribute2ndLevel(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(_DWORD *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AEFE0) --------------------------------------------------------  // acclient.c:712313
int __cdecl CM_Qualities::DispatchUI_UpdateAttributeLevel(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 742 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateAttributeLevel(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(_DWORD *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF030) --------------------------------------------------------  // acclient.c:712331
int __cdecl CM_Qualities::DispatchUI_UpdateBool(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 722 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateBool(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(_DWORD *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF080) --------------------------------------------------------  // acclient.c:712349
int __cdecl CM_Qualities::DispatchUI_UpdateFloat(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 724 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateFloat(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(long double *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF0E0) --------------------------------------------------------  // acclient.c:712367
int __cdecl CM_Qualities::DispatchUI_UpdateInstanceID(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 730 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateInstanceID(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(_DWORD *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF130) --------------------------------------------------------  // acclient.c:712385
int __cdecl CM_Qualities::DispatchUI_UpdateInt(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 718 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateInt(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(_DWORD *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF180) --------------------------------------------------------  // acclient.c:712403
int __cdecl CM_Qualities::DispatchUI_UpdateInt64(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 720 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateInt64(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(_QWORD *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF1D0) --------------------------------------------------------  // acclient.c:712421
int __cdecl CM_Qualities::DispatchUI_UpdateSkill(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  void *v4; // ecx@3
  char *v5; // eax@3
  bool v6; // zf@3
  int result; // eax@4
  char v8; // dl@5
  unsigned int v9; // edi@5
  unsigned int v10; // ebx@5
  Skill value; // [sp+8h] [bp-20h]@5
  char uia; // [sp+2Ch] [bp+4h]@5

  v3 = ui;
  if ( ui
    && ui->m_pObjMaintSystem
    && (v4 = buf, v5 = (char *)buf + 4, v6 = *(_DWORD *)buf == 734, buf = (char *)buf + 4, v6) )
  {
    v8 = *v5;
    buf = v5 + 1;
    v9 = *(_DWORD *)(v5 + 1);
    buf = v5 + 5;
    v10 = *(_DWORD *)(v5 + 5);
    value._sac = 0;
    value._pp = 0;
    value._init_level = 0;
    value._level_from_pp = 0;
    value._resistance_of_last_check = 0;
    buf = v5 + 9;
    uia = v8;
    value.vfptr = (PackObjVtbl *)&Skill::vftable;
    *(_QWORD *)&value._last_used_time = 0i64;
    Skill::UnPack(&value, &buf, size + (_BYTE *)v4 - (v5 + 9));
    result = ClientObjMaintSystem::Handle_Qualities__UpdateSkill(v3->m_pObjMaintSystem, uia, v9, v10, &value);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7408: using guessed type int (__thiscall *Skill::vftable)(void *, char);

//----- (006AF280) --------------------------------------------------------  // acclient.c:712465
int __cdecl CM_Qualities::DispatchUI_UpdateSkillAC(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 738 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateSkillAC(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(SKILL_ADVANCEMENT_CLASS *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF2D0) --------------------------------------------------------  // acclient.c:712483
int __cdecl CM_Qualities::DispatchUI_UpdateSkillLevel(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 736 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateSkillLevel(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(_DWORD *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF320) --------------------------------------------------------  // acclient.c:712501
int __cdecl CM_Qualities::DispatchUI_PrivateUpdateDataID(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 727 )
    result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdateDataID(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(IDClass<_tagDataID,32,0> *)((char *)buf + 9));
  else
    result = 0;
  return result;
}

//----- (006AF360) --------------------------------------------------------  // acclient.c:712518
int __cdecl CM_Qualities::DispatchUI_PrivateUpdatePosition(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebx@1
  int result; // eax@3
  int v5; // ecx@4
  void *v6; // esi@4
  char *v7; // eax@4
  char v8; // cl@6
  unsigned int v9; // edi@6
  Position value; // [sp+4h] [bp-48h]@6
  char uia; // [sp+50h] [bp+4h]@6

  v3 = ui;
  if ( ui && ui->m_pObjMaintSystem )
  {
    v5 = *(_DWORD *)buf;
    v6 = buf;
    v7 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v5 == 731 )
    {
      v8 = *v7;
      buf = v7 + 1;
      v9 = *(_DWORD *)(v7 + 1);
      uia = v8;
      buf = v7 + 5;
      Position::Position(&value);
      Position::UnPack(&value, &buf, size + (_BYTE *)v6 - (_BYTE *)buf);
      result = ClientObjMaintSystem::Handle_Qualities__PrivateUpdatePosition(v3->m_pObjMaintSystem, uia, v9, &value);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006AF3F0) --------------------------------------------------------  // acclient.c:712561
int __cdecl CM_Qualities::DispatchUI_UpdateDataID(UIQueueManager *ui, void *buf)
{
  ClientObjMaintSystem *v2; // ecx@2
  int result; // eax@4

  if ( ui && (v2 = ui->m_pObjMaintSystem) != 0 && *(_DWORD *)buf == 728 )
    result = ClientObjMaintSystem::Handle_Qualities__UpdateDataID(
               v2,
               *((_BYTE *)buf + 4),
               *(_DWORD *)((char *)buf + 5),
               *(_DWORD *)((char *)buf + 9),
               *(IDClass<_tagDataID,32,0> *)((char *)buf + 13));
  else
    result = 0;
  return result;
}

//----- (006AF440) --------------------------------------------------------  // acclient.c:712579
int __cdecl CM_Qualities::DispatchUI_UpdatePosition(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  int result; // eax@3
  int v5; // ecx@4
  void *v6; // esi@4
  char *v7; // eax@4
  char v8; // cl@6
  unsigned int v9; // edi@6
  unsigned int v10; // ebx@6
  Position value; // [sp+4h] [bp-48h]@6
  char uia; // [sp+50h] [bp+4h]@6

  v3 = ui;
  if ( ui && ui->m_pObjMaintSystem )
  {
    v5 = *(_DWORD *)buf;
    v6 = buf;
    v7 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v5 == 732 )
    {
      v8 = *v7;
      buf = v7 + 1;
      v9 = *(_DWORD *)(v7 + 1);
      buf = v7 + 5;
      v10 = *(_DWORD *)(v7 + 5);
      uia = v8;
      buf = v7 + 9;
      Position::Position(&value);
      Position::UnPack(&value, &buf, size + (_BYTE *)v6 - (_BYTE *)buf);
      result = ClientObjMaintSystem::Handle_Qualities__UpdatePosition(v3->m_pObjMaintSystem, uia, v9, v10, &value);
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00722E50) --------------------------------------------------------  // acclient.c:820779
void sub_722E50()
{
  flt_8FA5E0 = 1000.0 + 1.0;
}

//----- (00722E70) --------------------------------------------------------  // acclient.c:820785
void sub_722E70()
{
  flt_8FA5E4 = 24.0 * 8.0;
}

//----- (00722E90) --------------------------------------------------------  // acclient.c:820791
void sub_722E90()
{
  flt_8FA5E8 = 24.0 * 0.5;
}

//----- (00722EB0) --------------------------------------------------------  // acclient.c:820797
int sub_722EB0()
{
  return atexit(nullsub_444);
}

//----- (00722EC0) --------------------------------------------------------  // acclient.c:820803
int sub_722EC0()
{
  return atexit(nullsub_445);
}

//----- (00722ED0) --------------------------------------------------------  // acclient.c:820809
int sub_722ED0()
{
  return atexit(nullsub_446);
}

//----- (00722EE0) --------------------------------------------------------  // acclient.c:820815
void sub_722EE0()
{
  flt_8FA5EC = 0.00019999999 * 3.0 + 0.1;
}

//----- (00722F00) --------------------------------------------------------  // acclient.c:820821
void sub_722F00()
{
  dbl_8FA5F0 = 1.0 / 30.0;
}

//----- (00722F20) --------------------------------------------------------  // acclient.c:820827
void _E110_97()
{
  dbl_8FA5F8 = 1.0 / 5.0;
}

//----- (00722F40) --------------------------------------------------------  // acclient.c:820833
void sub_722F40()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA600, PFID_A8R8G8B8);
}

//----- (00722F50) --------------------------------------------------------  // acclient.c:820839
void sub_722F50()
{
  dword_8FA638 = 1024;
}

//----- (00722F60) --------------------------------------------------------  // acclient.c:820845
void sub_722F60()
{
  dword_8FA63C = 0x7FFF;
}

//----- (00722F70) --------------------------------------------------------  // acclient.c:820851
int _E119_49()
{
  const int result; // eax@1

  result = dword_8FA638;
  dword_8FA640 = dword_8FA638;
  return result;
}

//----- (00722F80) --------------------------------------------------------  // acclient.c:820861
int sub_722F80()
{
  return atexit(nullsub_442);
}

//----- (00722F90) --------------------------------------------------------  // acclient.c:820867
int sub_722F90()
{
  return atexit(nullsub_443);
}

