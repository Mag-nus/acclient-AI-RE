/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFloatyCombatPanelUI
   Object     : GAME\game_ui_misc\gmFloatyCombatPanelUI.obj
   Functions  : 19
   Addresses  : 004D5390 - 006F47C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D5390) --------------------------------------------------------  // acclient.c:260854
void __userpurge gmFloatyCombatPanelUI::gmFloatyCombatPanelUI(gmFloatyCombatPanelUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyCombatPanelUI *v4; // esi@1

  v4 = this;
  gmCombatPanelUI::gmCombatPanelUI((gmCombatPanelUI *)&this->vfptr, a2, _layout, _full_desc);
  v4->m_eWindowID = 0;
  v4->m_pTopBorder = 0;
  v4->m_pLeftBorder = 0;
  v4->m_pBottomBorder = 0;
  v4->m_pRightBorder = 0;
  v4->m_pTopLeftCorner = 0;
  v4->m_pTopRightCorner = 0;
  v4->m_pBottomLeftCorner = 0;
  v4->m_pBottomRightCorner = 0;
  v4->m_pTopBorder_Locked = 0;
  v4->m_pLeftBorder_Locked = 0;
  v4->m_pBottomBorder_Locked = 0;
  v4->m_pRightBorder_Locked = 0;
  v4->m_pTopLeftCorner_Locked = 0;
  v4->m_pTopRightCorner_Locked = 0;
  v4->m_pBottomLeftCorner_Locked = 0;
  v4->m_pBottomRightCorner_Locked = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmFloatyCombatPanelUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmFloatyCombatPanelUI::vftable;
}
// 7BC880: using guessed type bool (__thiscall *gmFloatyCombatPanelUI::vftable)(DBCache *this);
// 7BCB28: using guessed type int (__thiscall *gmFloatyCombatPanelUI::vftable)(void *, char);

//----- (004D5430) --------------------------------------------------------  // acclient.c:260884
gmFloatyCombatPanelUI *__thiscall gmFloatyCombatPanelUI::DynamicCast(gmFloatyCombatPanelUI *this, unsigned int i_eType)
{
  gmFloatyCombatPanelUI *result; // eax@1

  result = this;
  if ( i_eType != 268435540 && i_eType != 268435541 )
    result = (gmFloatyCombatPanelUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004D5460) --------------------------------------------------------  // acclient.c:260895
signed int gmFloatyCombatPanelUI::GetUIElementType()
{
  return 268435540;
}

//----- (004D5470) --------------------------------------------------------  // acclient.c:260901
void __usercall gmFloatyCombatPanelUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFloatyCombatPanelUI *v3; // eax@1

  v3 = (gmFloatyCombatPanelUI *)operator new(0x654u);
  if ( v3 )
    gmFloatyCombatPanelUI::gmFloatyCombatPanelUI(v3, a1, _layout, _full_desc);
}

//----- (004D54A0) --------------------------------------------------------  // acclient.c:260911
gmFloatyCombatPanelUI *__thiscall gmFloatyCombatPanelUI::scalar_deleting_destructor(gmFloatyCombatPanelUI *this, unsigned int a2)
{
  gmFloatyCombatPanelUI *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmFloatyCombatPanelUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFloatyCombatPanelUI::vftable;
  gmCombatPanelUI::~gmCombatPanelUI((gmCombatPanelUI *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BC880: using guessed type bool (__thiscall *gmFloatyCombatPanelUI::vftable)(DBCache *this);
// 7BCB28: using guessed type int (__thiscall *gmFloatyCombatPanelUI::vftable)(void *, char);

//----- (004D54D0) --------------------------------------------------------  // acclient.c:260927
void __cdecl gmFloatyCombatPanelUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000054u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmFloatyCombatPanelUI::Create);
}

//----- (004D54F0) --------------------------------------------------------  // acclient.c:260935
void __thiscall gmFloatyCombatPanelUI::PostInit(gmFloatyCombatPanelUI *this)
{
  gmFloatyCombatPanelUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  UIElement *v10; // eax@13
  int v11; // eax@14
  UIElement *v12; // eax@16
  int v13; // eax@17
  UIElement *v14; // eax@19
  int v15; // eax@20
  UIElement *v16; // eax@22
  int v17; // eax@23
  UIElement *v18; // eax@25
  int v19; // eax@26
  UIElement *v20; // eax@28
  int v21; // eax@29
  UIElement *v22; // eax@31
  int v23; // eax@32
  UIElement *v24; // eax@34
  int v25; // eax@35
  UIElement *v26; // eax@37
  int v27; // eax@38
  UIElement *v28; // eax@40
  int v29; // eax@41
  UIElement *v30; // eax@43
  int v31; // eax@44
  UIElement *v32; // eax@46
  int v33; // eax@47
  GlobalEventHandler *v34; // eax@49
  GlobalEventHandler *v35; // edi@49

  v1 = this;
  gmCombatPanelUI::PostInit((gmCombatPanelUI *)&this->vfptr);
  UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000007Eu, &v1->m_eWindowID);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006AEu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)2);
  else
    v3 = 0;
  v1->m_pTopBorder = (UIElement *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B0u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)9);
  else
    v5 = 0;
  v1->m_pLeftBorder = (UIElement *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B2u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)9);
  else
    v7 = 0;
  v1->m_pBottomBorder = (UIElement *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B4u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)9);
  else
    v9 = 0;
  v1->m_pRightBorder = (UIElement *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006ADu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)9);
  else
    v11 = 0;
  v1->m_pTopLeftCorner = (UIElement *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006AFu);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)9);
  else
    v13 = 0;
  v1->m_pTopRightCorner = (UIElement *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B1u);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)9);
  else
    v15 = 0;
  v1->m_pBottomLeftCorner = (UIElement *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006B3u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)9);
  else
    v17 = 0;
  v1->m_pBottomRightCorner = (UIElement *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006A6u);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)3);
  else
    v19 = 0;
  v1->m_pTopBorder_Locked = (UIElement *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006A8u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)3);
  else
    v21 = 0;
  v1->m_pLeftBorder_Locked = (UIElement *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006AAu);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)3);
  else
    v23 = 0;
  v1->m_pBottomBorder_Locked = (UIElement *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006ACu);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)3);
  else
    v25 = 0;
  v1->m_pRightBorder_Locked = (UIElement *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006A5u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)3);
  else
    v27 = 0;
  v1->m_pTopLeftCorner_Locked = (UIElement *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006A7u);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)3);
  else
    v29 = 0;
  v1->m_pTopRightCorner_Locked = (UIElement *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006A9u);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)3);
  else
    v31 = 0;
  v1->m_pBottomLeftCorner_Locked = (UIElement *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006ABu);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)3);
  else
    v33 = 0;
  v1->m_pBottomRightCorner_Locked = (UIElement *)v33;
  v34 = GlobalEventHandler::GetGlobalEventHandler();
  v35 = v34;
  if ( v34 )
  {
    v34->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v34,
      (unsigned int)((char *)&loc_4DD1F7 + 1),
      (NoticeHandler *)&v1->vfptr);
    v35->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v35,
      (unsigned int)((char *)&loc_4DD1F9 + 2),
      (NoticeHandler *)&v1->vfptr);
    v35->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v35, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  }
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xDu);
  ((void (__thiscall *)(gmFloatyCombatPanelUI *))v1->vfptr[26].__vecDelDtor)(v1);
}

//----- (006F46B0) --------------------------------------------------------  // acclient.c:777050
void sub_6F46B0()
{
  outside_val_98 = 1000.0 + 1.0;
}

//----- (006F46D0) --------------------------------------------------------  // acclient.c:777056
void _E93_82()
{
  block_length_98 = 24.0 * 8.0;
}

//----- (006F46F0) --------------------------------------------------------  // acclient.c:777062
void _E95_82()
{
  half_square_length_98 = 24.0 * 0.5;
}

//----- (006F4710) --------------------------------------------------------  // acclient.c:777068
int sub_6F4710()
{
  return atexit(nullsub_656);
}

//----- (006F4720) --------------------------------------------------------  // acclient.c:777074
int sub_6F4720()
{
  return atexit(nullsub_657);
}

//----- (006F4730) --------------------------------------------------------  // acclient.c:777080
int _E103_92()
{
  return atexit(nullsub_658);
}

//----- (006F4740) --------------------------------------------------------  // acclient.c:777086
void _E106_65()
{
  DEFAULT_VIEW_RADIUS_67 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F4760) --------------------------------------------------------  // acclient.c:777092
void _E108_52()
{
  MIN_QUANTUM_67 = 1.0 / 30.0;
}

//----- (006F4780) --------------------------------------------------------  // acclient.c:777098
void _E110_43()
{
  MAX_QUANTUM_67 = 1.0 / 5.0;
}

//----- (006F47A0) --------------------------------------------------------  // acclient.c:777104
void _E112_59()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840050, PFID_A8R8G8B8);
}

//----- (006F47B0) --------------------------------------------------------  // acclient.c:777110
int _E117_44()
{
  return atexit(nullsub_654);
}

//----- (006F47C0) --------------------------------------------------------  // acclient.c:777116
int sub_6F47C0()
{
  return atexit(nullsub_655);
}

