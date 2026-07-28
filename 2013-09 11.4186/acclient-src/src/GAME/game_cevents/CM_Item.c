/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Item
   Object     : GAME\game_cevents\CM_Item.obj
   Functions  : 26
   Addresses  : 006A84A0 - 007222E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A84A0) --------------------------------------------------------  // acclient.c:705125
int __cdecl CM_Item::DispatchUI_AppraiseDone(UIQueueManager *ui, void *buf)
{
  int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 459 )
    result = InfoRegion::GetVitaeModifier(*((Enchantment **)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A84D0) --------------------------------------------------------  // acclient.c:705137
unsigned int __cdecl CM_Item::DispatchUI_QueryItemManaResponse(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 612 )
    result = ClientUISystem::Handle_Item__QueryItemManaResponse(
               *((_DWORD *)buf + 1),
               *((float *)buf + 2),
               *((_DWORD *)buf + 3));
  else
    result = 0;
  return result;
}

//----- (006A8510) --------------------------------------------------------  // acclient.c:705152
unsigned int __cdecl CM_Item::DispatchUI_UseDone(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pUISystem && *(_DWORD *)buf == 455 )
    result = ClientUISystem::Handle_Item__UseDone(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006A8540) --------------------------------------------------------  // acclient.c:705164
bool __cdecl CM_Item::Event_Appraise(unsigned int i_objectID)
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
  *(_DWORD *)buf = 200;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_objectID;
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

//----- (006A8610) --------------------------------------------------------  // acclient.c:705214
bool __cdecl CM_Item::Event_QueryItemMana(unsigned int i_target)
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
  *(_DWORD *)buf = 611;
  v5 = (char *)buf + 4;
  buf = v5;
  *(_DWORD *)v5 = i_target;
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

//----- (006A86E0) --------------------------------------------------------  // acclient.c:705264
char __cdecl CM_Item::SendNotice_BeginDrag(unsigned int i_itemID, unsigned int i_spellID, int i_bIsAlias)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)((char *)&loc_4DD260 + 3));
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, unsigned int, int))(*(_DWORD *)v6 + 324))(
          v6,
          i_itemID,
          i_spellID,
          i_bIsAlias);
    }
  }
  return 1;
}

//----- (006A8740) --------------------------------------------------------  // acclient.c:705294
char __cdecl CM_Item::SendNotice_EndPendingInPlayer()
{
  gmGlobalEventHandler *v0; // eax@1
  int v1; // eax@1
  int v2; // esi@2
  int v3; // edi@3
  bool v4; // zf@3

  v0 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v1 = (int)v0->vfptr->GetNoticeHandlers((NoticeRegistrar *)v0, (unsigned int)((char *)&loc_4DD25A + 3));
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 4);
    while ( v2 )
    {
      v3 = *(_DWORD *)v2;
      v4 = *(_DWORD *)v2 == 0;
      v2 = *(_DWORD *)(v2 + 4);
      if ( !v4 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v3)(v3) )
        (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 328))(v3);
    }
  }
  return 1;
}

//----- (006A8790) --------------------------------------------------------  // acclient.c:705320
char __cdecl CM_Item::SendNotice_ItemListBeginDrag(UIElement *i_itemList, int i_slotNum)
{
  gmGlobalEventHandler *v2; // eax@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // esi@3
  bool v6; // zf@3

  v2 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v3 = (int)v2->vfptr->GetNoticeHandlers((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD255 + 1));
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    while ( v4 )
    {
      v5 = *(_DWORD *)v4;
      v6 = *(_DWORD *)v4 == 0;
      v4 = *(_DWORD *)(v4 + 4);
      if ( !v6 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v5)(v5) )
        (*(void (__thiscall **)(int, UIElement *, int))(*(_DWORD *)v5 + 332))(v5, i_itemList, i_slotNum);
    }
  }
  return 1;
}

//----- (006A87F0) --------------------------------------------------------  // acclient.c:705346
char __cdecl CM_Item::SendNotice_SetGroundObject(unsigned int i_groundObj)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)&loc_4DD1F9);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 340))(v4, i_groundObj);
    }
  }
  return 1;
}

//----- (006A8840) --------------------------------------------------------  // acclient.c:705372
char __cdecl CM_Item::SendNotice_ShowPendingInPlayer(unsigned int i_i_itemID)
{
  gmGlobalEventHandler *v1; // eax@1
  int v2; // eax@1
  int v3; // esi@2
  int v4; // edi@3
  bool v5; // zf@3

  v1 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v2 = (int)v1->vfptr->GetNoticeHandlers((NoticeRegistrar *)v1, (unsigned int)((char *)&loc_4DD25A + 1));
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 4);
    while ( v3 )
    {
      v4 = *(_DWORD *)v3;
      v5 = *(_DWORD *)v3 == 0;
      v3 = *(_DWORD *)(v3 + 4);
      if ( !v5 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v4)(v4) )
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v4 + 344))(v4, i_i_itemID);
    }
  }
  return 1;
}

//----- (006A8890) --------------------------------------------------------  // acclient.c:705398
char __cdecl CM_Item::SendNotice_UpdateItemMana(unsigned int i_iidItem, float i_mana, int i_bSuccess)
{
  gmGlobalEventHandler *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@2
  int v6; // esi@3
  bool v7; // zf@3

  v3 = gmGlobalEventHandler::gmGetGlobalEventHandler();
  v4 = (int)v3->vfptr->GetNoticeHandlers((NoticeRegistrar *)v3, (unsigned int)&loc_4DD1F5);
  if ( v4 )
  {
    v5 = *(_DWORD *)(v4 + 4);
    while ( v5 )
    {
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)v5 == 0;
      v5 = *(_DWORD *)(v5 + 4);
      if ( !v7 && !(unsigned __int8)(**(int (__thiscall ***)(_DWORD))v6)(v6) )
        (*(void (__thiscall **)(int, unsigned int, _DWORD, int))(*(_DWORD *)v6 + 352))(
          v6,
          i_iidItem,
          LODWORD(i_mana),
          i_bSuccess);
    }
  }
  return 1;
}

//----- (007221A0) --------------------------------------------------------  // acclient.c:819885
void sub_7221A0()
{
  flt_8FA0D8 = 1000.0 + 1.0;
}

//----- (007221C0) --------------------------------------------------------  // acclient.c:819891
void sub_7221C0()
{
  flt_8FA0DC = 24.0 * 8.0;
}

//----- (007221E0) --------------------------------------------------------  // acclient.c:819897
void sub_7221E0()
{
  flt_8FA0E0 = 24.0 * 0.5;
}

//----- (00722200) --------------------------------------------------------  // acclient.c:819903
int sub_722200()
{
  return atexit(nullsub_422);
}

//----- (00722210) --------------------------------------------------------  // acclient.c:819909
int sub_722210()
{
  return atexit(nullsub_423);
}

//----- (00722220) --------------------------------------------------------  // acclient.c:819915
int sub_722220()
{
  return atexit(nullsub_424);
}

//----- (00722230) --------------------------------------------------------  // acclient.c:819921
void sub_722230()
{
  flt_8FA0E4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00722250) --------------------------------------------------------  // acclient.c:819927
void sub_722250()
{
  dbl_8FA0E8 = 1.0 / 30.0;
}

//----- (00722270) --------------------------------------------------------  // acclient.c:819933
void _E110_89()
{
  dbl_8FA0F0 = 1.0 / 5.0;
}

//----- (00722290) --------------------------------------------------------  // acclient.c:819939
void sub_722290()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA0F8, PFID_A8R8G8B8);
}

//----- (007222A0) --------------------------------------------------------  // acclient.c:819945
void sub_7222A0()
{
  dword_8FA130 = 1024;
}

//----- (007222B0) --------------------------------------------------------  // acclient.c:819951
void _E117_96()
{
  dword_8FA134 = 0x7FFF;
}

//----- (007222C0) --------------------------------------------------------  // acclient.c:819957
int _E119_41()
{
  const int result; // eax@1

  result = dword_8FA130;
  dword_8FA138 = dword_8FA130;
  return result;
}

//----- (007222D0) --------------------------------------------------------  // acclient.c:819967
int sub_7222D0()
{
  return atexit(nullsub_420);
}

//----- (007222E0) --------------------------------------------------------  // acclient.c:819973
int sub_7222E0()
{
  return atexit(nullsub_421);
}

