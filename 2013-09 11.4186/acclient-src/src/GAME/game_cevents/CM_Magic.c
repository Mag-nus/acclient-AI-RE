/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Magic
   Object     : GAME\game_cevents\CM_Magic.obj
   Functions  : 44
   Addresses  : 006A2F20 - 00721B40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A2F20) --------------------------------------------------------  // acclient.c:699721
unsigned int __cdecl CM_Magic::DispatchUI_DispelEnchantment(UIQueueManager *ui, void *buf)
{
  ClientMagicSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pMagicSystem) != 0 && *(_DWORD *)buf == 711 )
    result = ClientMagicSystem::Handle_Magic__DispelEnchantment(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A2F50) --------------------------------------------------------  // acclient.c:699734
unsigned int __cdecl CM_Magic::DispatchUI_PurgeBadEnchantments(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMagicSystem && *(_DWORD *)buf == 786 )
    result = ClientMagicSystem::Handle_Magic__PurgeBadEnchantments();
  else
    result = 0;
  return result;
}

//----- (006A2F80) --------------------------------------------------------  // acclient.c:699746
unsigned int __cdecl CM_Magic::DispatchUI_PurgeEnchantments(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMagicSystem && *(_DWORD *)buf == 710 )
    result = ClientMagicSystem::Handle_Magic__PurgeEnchantments();
  else
    result = 0;
  return result;
}

//----- (006A2FB0) --------------------------------------------------------  // acclient.c:699758
unsigned int __cdecl CM_Magic::DispatchUI_RemoveEnchantment(UIQueueManager *ui, void *buf)
{
  ClientMagicSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pMagicSystem) != 0 && *(_DWORD *)buf == 707 )
    result = ClientMagicSystem::Handle_Magic__RemoveEnchantment(v2, *((_DWORD *)buf + 1), 1);
  else
    result = 0;
  return result;
}

//----- (006A2FE0) --------------------------------------------------------  // acclient.c:699771
unsigned int __cdecl CM_Magic::DispatchUI_RemoveSpell(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMagicSystem && *(_DWORD *)buf == 424 )
    result = ClientMagicSystem::Handle_Magic__RemoveSpell(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A3010) --------------------------------------------------------  // acclient.c:699783
unsigned int __cdecl CM_Magic::DispatchUI_UpdateSpell(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pMagicSystem && *(_DWORD *)buf == 705 )
    result = ClientMagicSystem::Handle_Magic__UpdateSpell(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A3040) --------------------------------------------------------  // acclient.c:699795
bool __cdecl CM_Magic::Event_CastTargetedSpell(unsigned int i_target, unsigned int i_spell_id)
{
  signed int v2; // eax@1
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // edi@1
  char *v6; // eax@1
  char *v7; // eax@1
  bool v8; // zf@1
  unsigned int v9; // ecx@1
  int v10; // edx@4
  int v11; // eax@6
  int v12; // ecx@7
  bool v13; // bl@9
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = OrderHdr::Pack(&hdr, &buf, 0);
  v3 = v2 + 12;
  v4 = operator new[](v2 + 12);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 74;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_target;
  v7 = (char *)buf + 4;
  v9 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v8 = v9 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v9 = (((_BYTE)v9 - 1) | 0xFFFFFFFC) + 1;
    v8 = v9 == 0;
  }
  if ( !v8 )
  {
    v10 = 4 - v9;
    if ( 4 != v9 )
    {
      do
      {
        *v7 = 0;
        v7 = (char *)buf + 1;
        --v10;
        buf = (char *)buf + 1;
      }
      while ( v10 );
    }
  }
  *(_DWORD *)v7 = i_spell_id;
  buf = (char *)buf + 4;
  v11 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v12 = 4 - v11;
    if ( 4 != v11 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v12;
        buf = (char *)buf + 1;
      }
      while ( v12 );
    }
  }
  v13 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v13 )
    Proto_UI::UICounterFailedSend();
  return v13;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A3150) --------------------------------------------------------  // acclient.c:699874
bool __cdecl CM_Magic::Event_CastUntargetedSpell(unsigned int i_spell_id)
{
  signed int v1; // eax@1
  int v2; // esi@1
  void *v3; // eax@1
  char *v4; // edi@1
  char *v5; // eax@1
  int v6; // eax@1
  int v7; // ecx@2
  bool v8; // bl@4
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v1 = OrderHdr::Pack(&hdr, &buf, 0);
  v2 = v1 + 8;
  v3 = operator new[](v1 + 8);
  buf = v3;
  v4 = (char *)v3;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 72;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_spell_id;
  buf = (char *)buf + 4;
  v6 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v7 = 4 - v6;
    if ( 4 != v6 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v7;
        buf = (char *)buf + 1;
      }
      while ( v7 );
    }
  }
  v8 = Proto_UI::SendToWeenie(v4, v2);
  if ( !v8 )
    Proto_UI::UICounterFailedSend();
  return v8;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A3220) --------------------------------------------------------  // acclient.c:699924
bool __cdecl CM_Magic::Event_RemoveSpell(unsigned int i_spell_id)
{
  signed int v1; // eax@1
  int v2; // esi@1
  void *v3; // eax@1
  char *v4; // edi@1
  char *v5; // eax@1
  int v6; // eax@1
  int v7; // ecx@2
  bool v8; // bl@4
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v1 = OrderHdr::Pack(&hdr, &buf, 0);
  v2 = v1 + 8;
  v3 = operator new[](v1 + 8);
  buf = v3;
  v4 = (char *)v3;
  OrderHdr::Pack(&hdr, &buf, v2);
  *(_DWORD *)buf = 424;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_spell_id;
  buf = (char *)buf + 4;
  v6 = (signed int)buf % 4;
  if ( (signed int)buf % 4 )
  {
    v7 = 4 - v6;
    if ( 4 != v6 )
    {
      do
      {
        *(_BYTE *)buf = 0;
        --v7;
        buf = (char *)buf + 1;
      }
      while ( v7 );
    }
  }
  v8 = Proto_UI::SendToWeenie(v4, v2);
  if ( !v8 )
    Proto_UI::UICounterFailedSend();
  return v8;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006A32F0) --------------------------------------------------------  // acclient.c:699974
unsigned int __cdecl CM_Magic::DispatchUI_UpdateEnchantment(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  int v4; // ecx@4
  void *v5; // esi@4
  ClientMagicSystem *v6; // ecx@6
  Enchantment enchant; // [sp+4h] [bp-50h]@6

  if ( ui && ui->m_pMagicSystem )
  {
    v4 = *(_DWORD *)buf;
    v5 = buf;
    buf = (char *)buf + 4;
    if ( v4 == 706 )
    {
      Enchantment::Enchantment(&enchant);
      Enchantment::UnPack(&enchant, &buf, size + (_BYTE *)v5 - (_BYTE *)buf);
      v6 = ui->m_pMagicSystem;
      result = ClientMagicSystem::Handle_Magic__UpdateEnchantment(&enchant);
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

//----- (006A3370) --------------------------------------------------------  // acclient.c:700007
char __cdecl CM_Magic::SendNotice_AddSpellShortcut(unsigned int i_spellID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD200 + 2));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 360))(v4, i_spellID);
    }
  }
  return 1;
}

//----- (006A33C0) --------------------------------------------------------  // acclient.c:700033
char __cdecl CM_Magic::SendNotice_CastCurrentSpell()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD24B + 3));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 364))(v3);
    }
  }
  return 1;
}

//----- (006A3410) --------------------------------------------------------  // acclient.c:700059
char __cdecl CM_Magic::SendNotice_CastQuickslotSpell(int i_slot)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD24B + 4));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 368))(v4, i_slot);
    }
  }
  return 1;
}

//----- (006A3460) --------------------------------------------------------  // acclient.c:700085
char __cdecl CM_Magic::SendNotice_EnchantmentsChanged()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD200 + 1));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 372))(v3);
    }
  }
  return 1;
}

//----- (006A34B0) --------------------------------------------------------  // acclient.c:700111
char __cdecl CM_Magic::SendNotice_FirstSpellSelection()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD26A);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 376))(v3);
    }
  }
  return 1;
}

//----- (006A3500) --------------------------------------------------------  // acclient.c:700137
char __cdecl CM_Magic::SendNotice_FirstSpellTab()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD264 + 4));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 380))(v3);
    }
  }
  return 1;
}

//----- (006A3550) --------------------------------------------------------  // acclient.c:700163
char __cdecl CM_Magic::SendNotice_LastSpellSelection()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD264 + 5));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 384))(v3);
    }
  }
  return 1;
}

//----- (006A35A0) --------------------------------------------------------  // acclient.c:700189
char __cdecl CM_Magic::SendNotice_LastSpellTab()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD26A + 1));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 388))(v3);
    }
  }
  return 1;
}

//----- (006A35F0) --------------------------------------------------------  // acclient.c:700215
char __cdecl CM_Magic::SendNotice_NextSpellSelection()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD24B + 1));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 392))(v3);
    }
  }
  return 1;
}

//----- (006A3640) --------------------------------------------------------  // acclient.c:700241
char __cdecl CM_Magic::SendNotice_NextSpellTab()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD245 + 5));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 396))(v3);
    }
  }
  return 1;
}

//----- (006A3690) --------------------------------------------------------  // acclient.c:700267
char __cdecl CM_Magic::SendNotice_PrevSpellSelection()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD24B + 2));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 400))(v3);
    }
  }
  return 1;
}

//----- (006A36E0) --------------------------------------------------------  // acclient.c:700293
char __cdecl CM_Magic::SendNotice_PrevSpellTab()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)&loc_4DD24B);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 404))(v3);
    }
  }
  return 1;
}

//----- (006A3730) --------------------------------------------------------  // acclient.c:700319
char __cdecl CM_Magic::SendNotice_SpellAdded(unsigned int i_eSpellID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD25A + 5));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 416))(v4, i_eSpellID);
    }
  }
  return 1;
}

//----- (006A3780) --------------------------------------------------------  // acclient.c:700345
char __cdecl CM_Magic::SendNotice_SpellRemoved(unsigned int i_eSpellID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD260);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 420))(v4, i_eSpellID);
    }
  }
  return 1;
}

//----- (006A37D0) --------------------------------------------------------  // acclient.c:700371
char __cdecl CM_Magic::SendNotice_UpdateSpellComponents(int i_change)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD255);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 424))(v4, i_change);
    }
  }
  return 1;
}

//----- (006A3820) --------------------------------------------------------  // acclient.c:700397
char __cdecl CM_Magic::SendNotice_VitaeChanged()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD213 + 2));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 428))(v3);
    }
  }
  return 1;
}

//----- (006A3870) --------------------------------------------------------  // acclient.c:700423
unsigned int __cdecl CM_Magic::DispatchUI_DispelMultipleEnchantments(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  unsigned int v7; // esi@6
  PackableList<unsigned long> list; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pMagicSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 712;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      list.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
      list.head = 0;
      list.tail = 0;
      list.curNum = 0;
      PackableList<unsigned long>::UnPack(&list, &buf, size + (_BYTE *)v4 - v5);
      v7 = ClientMagicSystem::Handle_Magic__DispelMultipleEnchantments(ui->m_pMagicSystem, &list);
      list.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
      PackableList<unsigned long>::Flush(&list);
      result = v7;
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
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (006A3900) --------------------------------------------------------  // acclient.c:700464
unsigned int __cdecl CM_Magic::DispatchUI_RemoveMultipleEnchantments(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  unsigned int v7; // esi@6
  PackableList<unsigned long> list; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pMagicSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 709;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      list.head = 0;
      list.tail = 0;
      list.curNum = 0;
      list.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
      PackableList<unsigned long>::UnPack(&list, &buf, size + (_BYTE *)v4 - v5);
      v7 = ClientMagicSystem::Handle_Magic__RemoveMultipleEnchantments(ui->m_pMagicSystem, &list, 1);
      list.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
      PackableList<unsigned long>::Flush(&list);
      result = v7;
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
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (006A3990) --------------------------------------------------------  // acclient.c:700505
unsigned int __cdecl CM_Magic::DispatchUI_UpdateMultipleEnchantments(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  ClientMagicSystem *v7; // ecx@6
  unsigned int v8; // esi@6
  PackableList<Enchantment> list; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pMagicSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 708;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      list.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      list.head = 0;
      list.tail = 0;
      list.curNum = 0;
      PackableList<Enchantment>::UnPack(&list, &buf, size + (_BYTE *)v4 - v5);
      v7 = ui->m_pMagicSystem;
      v8 = ClientMagicSystem::Handle_Magic__UpdateMultipleEnchantments(&list);
      list.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      PackableList<Enchantment>::Flush(&list);
      result = v8;
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
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (00721A00) --------------------------------------------------------  // acclient.c:819349
void sub_721A00()
{
  flt_8F9DE8 = 1000.0 + 1.0;
}

//----- (00721A20) --------------------------------------------------------  // acclient.c:819355
void sub_721A20()
{
  flt_8F9DEC = 24.0 * 8.0;
}

//----- (00721A40) --------------------------------------------------------  // acclient.c:819361
void sub_721A40()
{
  flt_8F9DF0 = 24.0 * 0.5;
}

//----- (00721A60) --------------------------------------------------------  // acclient.c:819367
int sub_721A60()
{
  return atexit(nullsub_432);
}

//----- (00721A70) --------------------------------------------------------  // acclient.c:819373
int sub_721A70()
{
  return atexit(nullsub_433);
}

//----- (00721A80) --------------------------------------------------------  // acclient.c:819379
int sub_721A80()
{
  return atexit(nullsub_434);
}

//----- (00721A90) --------------------------------------------------------  // acclient.c:819385
void sub_721A90()
{
  flt_8F9DF4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00721AB0) --------------------------------------------------------  // acclient.c:819391
void sub_721AB0()
{
  dbl_8F9DF8 = 1.0 / 30.0;
}

//----- (00721AD0) --------------------------------------------------------  // acclient.c:819397
void _E110_84()
{
  dbl_8F9E00 = 1.0 / 5.0;
}

//----- (00721AF0) --------------------------------------------------------  // acclient.c:819403
void sub_721AF0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9E08, PFID_A8R8G8B8);
}

//----- (00721B00) --------------------------------------------------------  // acclient.c:819409
void sub_721B00()
{
  dword_8F9E40 = 1024;
}

//----- (00721B10) --------------------------------------------------------  // acclient.c:819415
void _E117_91()
{
  dword_8F9E44 = 0x7FFF;
}

//----- (00721B20) --------------------------------------------------------  // acclient.c:819421
int _E119_36()
{
  const int result; // eax@1

  result = dword_8F9E40;
  dword_8F9E48 = dword_8F9E40;
  return result;
}

//----- (00721B30) --------------------------------------------------------  // acclient.c:819431
int _E121_96()
{
  return atexit(nullsub_430);
}

//----- (00721B40) --------------------------------------------------------  // acclient.c:819437
int sub_721B40()
{
  return atexit(nullsub_431);
}

