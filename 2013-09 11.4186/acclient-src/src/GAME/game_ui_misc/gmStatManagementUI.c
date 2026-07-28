/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmStatManagementUI
   Object     : GAME\game_ui_misc\gmStatManagementUI.obj
   Functions  : 44
   Addresses  : 004EFBE0 - 006F7D40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004EFBE0) --------------------------------------------------------  // acclient.c:284106
int __thiscall gmStatManagementUI::ListenToElementMessage(gmStatManagementUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmStatManagementUI *v3; // esi@1
  UIElement_ListBox *v5; // ecx@6
  UIElement *v6; // eax@7
  unsigned int v7; // ecx@8
  IInputActionCallbackVtbl *v8; // eax@21

  v2 = i_rMsg->idMessage;
  v3 = this;
  if ( v2 == 24 )
  {
    if ( (gmStatManagementUI *)i_rMsg->pElement == this && i_rMsg->dwParam1 )
    {
      ((void (*)(void))this->vfptr[26].OnAction)();
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    }
  }
  else if ( v2 == 28 && (v5 = this->m_pListBox) != 0 )
  {
    v6 = UIElement_ListBox::GetItemUnderMouse(v5);
    if ( v6 )
    {
      v7 = i_rMsg->dwParam1;
      if ( v7 == 7 || v7 == 10 || v7 == 8 || v7 == 11 )
      {
        ((void (__thiscall *)(gmStatManagementUI *, UIElement *))v3->vfptr[27].OnLoseFocus)(v3, v6);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
    }
  }
  else if ( v2 == 1 )
  {
    if ( i_rMsg->idElement == 268436038 && !v3->m_bAwaitingRaise )
      ((void (__thiscall *)(gmStatManagementUI *))v3->vfptr[28].OnAction)(v3);
    if ( i_rMsg->idElement == 268436971 && !v3->m_bAwaitingRaise )
    {
      ((void (__thiscall *)(gmStatManagementUI *))v3->vfptr[28].OnLoseFocus)(v3);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    }
  }
  else if ( v2 == 268435460 )
  {
    v8 = v3->vfptr;
    v3->m_bAwaitingRaise = 0;
    if ( (unsigned __int8)((int (__thiscall *)(gmStatManagementUI *, unsigned int, unsigned int))v8[29].OnAction)(
                            v3,
                            i_rMsg->dwParam1,
                            i_rMsg->dwParam2) )
      ((void (__thiscall *)(gmStatManagementUI *))v3->vfptr[28].__vecDelDtor)(v3);
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (004EFCF0) --------------------------------------------------------  // acclient.c:284162
void __thiscall gmStatManagementUI::RecvNotice_PlayerDescReceived(gmStatManagementUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14][39].m_hashKey)(
    &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14],
    i_playerDesc);
}

//----- (004EFD10) --------------------------------------------------------  // acclient.c:284170
void __thiscall gmStatManagementUI::RecvNotice_EnchantmentsChanged(gmStatManagementUI *this)
{
  ((void (__thiscall *)(_DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14][39].m_hashNext)(&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14]);
}

//----- (004EFD30) --------------------------------------------------------  // acclient.c:284176
void __thiscall gmStatManagementUI::RecvNotice_UpdateCharacterTitleTable(gmStatManagementUI *this, CharacterTitleTable *i_titleTable)
{
  HashSetData<UIElement *> *v2; // eax@1

  v2 = this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14];
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[13] = (HashSetData<UIElement *> *)i_titleTable->mDisplayTitle;
  ((void (__thiscall *)(HashSetData<UIElement *> **))v2[39].m_hashNext)(&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14]);
}

//----- (004EFD50) --------------------------------------------------------  // acclient.c:284186
void __thiscall gmStatManagementUI::RecvNotice_SetDisplayCharacterTitle(gmStatManagementUI *this, unsigned int i_title)
{
  HashSetData<UIElement *> *v2; // edx@1

  v2 = this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14];
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[13] = (HashSetData<UIElement *> *)i_title;
  ((void (__thiscall *)(HashSetData<UIElement *> **))v2[39].m_hashNext)(&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[14]);
}

//----- (004EFD70) --------------------------------------------------------  // acclient.c:284196
void __thiscall gmStatManagementUI::OnQualityRemoved(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  ((void (__thiscall *)(_DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[13][39].m_hashNext)(&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[13]);
}

//----- (004EFD90) --------------------------------------------------------  // acclient.c:284202
void __thiscall gmStatManagementUI::PostInit(gmStatManagementUI *this)
{
  gmStatManagementUI *v1; // edi@1
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
  GlobalEventHandler *v22; // esi@31

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000231u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    v3 = 0;
  v1->m_pNameText = (UIElement_Text *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000232u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  v1->m_pHeritageText = (UIElement_Text *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000233u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
  else
    v7 = 0;
  v1->m_pPKStatusText = (UIElement_Text *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000023Bu);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v1->m_pLevelText = (UIElement_Text *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000235u);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v1->m_pTotalXPText = (UIElement_Text *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000238u);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
  else
    v13 = 0;
  v1->m_pXPToLevelText = (UIElement_Text *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005C5u);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)12);
  else
    v15 = 0;
  v1->m_pLuminanceLabelText = (UIElement_Text *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005C6u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)12);
  else
    v17 = 0;
  v1->m_pLuminanceText = (UIElement_Text *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000236u);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)7);
  else
    v19 = 0;
  v1->m_pXPToLevelMeter = (UIElement_Meter *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000023Du);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)5);
  else
    v21 = 0;
  v1->m_pListBox = (UIElement_ListBox *)v21;
  v22 = GlobalEventHandler::GetGlobalEventHandler();
  v22->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v22, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  v22->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v22,
    (unsigned int)((char *)&loc_4DD200 + 1),
    (NoticeHandler *)&v1->vfptr);
  v22->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v22, (unsigned int)&loc_4DD277, (NoticeHandler *)&v1->vfptr);
  v22->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v22, 5100152u, (NoticeHandler *)&v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    25,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    24,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    30,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    134,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    188,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    1,
    113,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    14,
    1,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    14,
    2,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    14,
    6,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    14,
    7,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    5,
    1,
    &v1->vfptr);
}

//----- (004F0020) --------------------------------------------------------  // acclient.c:284344
char __thiscall gmStatManagementUI::Update(gmStatManagementUI *this, CACQualities *i_playerDesc)
{
  gmStatManagementUI *v2; // esi@1
  char result; // al@2
  unsigned int v4; // edi@3

  v2 = this;
  if ( (*((_DWORD *)&this->0 + 41) >> 1) & 1 )
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[26].OnLoseFocus)(i_playerDesc);
    v2->vfptr[27].__vecDelDtor((IInputActionCallback *)v2, (unsigned int)i_playerDesc);
    v2->vfptr[27].OnAction((IInputActionCallback *)v2, (InputEvent *)i_playerDesc);
    v4 = 0;
    if ( v2->m_rgTokens.m_num )
    {
      do
        ((void (__stdcall *)(CACQualities *))v2->m_rgTokens.m_data[v4++]->vfptr[4].OnQualityChanged)(i_playerDesc);
      while ( v4 < v2->m_rgTokens.m_num );
    }
    ((void (__thiscall *)(gmStatManagementUI *))v2->vfptr[28].__vecDelDtor)(v2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004F00A0) --------------------------------------------------------  // acclient.c:284374
char __thiscall gmStatManagementUI::UpdatePKStatus(gmStatManagementUI *this, CACQualities *i_playerDesc)
{
  gmStatManagementUI *v2; // edi@1
  unsigned int v3; // eax@2
  HashBaseData<unsigned long> *v4; // esi@4
  const unsigned int v5; // ecx@6
  PStringBase<unsigned short> *v6; // eax@11
  char *v7; // esi@11
  unsigned int v9; // [sp-8h] [bp-A4h]@8
  PStringBase<unsigned short> result; // [sp+8h] [bp-94h]@11
  StringInfo siText; // [sp+Ch] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&siText);
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  v4 = ClientObjMaintSystem::GetWeenieObject(v3);
  if ( !v4 )
    goto LABEL_17;
  if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[8].__vecDelDtor)(v4) )
  {
    v5 = ID_StatManagement_Header_PKStatus_PK;
LABEL_10:
    v9 = v5;
    goto LABEL_11;
  }
  if ( !((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[9].__vecDelDtor)(v4) )
  {
LABEL_17:
    v5 = ID_StatManagement_Header_PKStatus_NPK;
    goto LABEL_10;
  }
  v9 = ID_StatManagement_Header_PKStatus_PKL;
LABEL_11:
  StringInfo::SetStringIDandTableEnum(&siText, v9, 268435457);
  v6 = StringInfo::GetString(&siText, &result, 0);
  UIElement_Text::SetText(v2->m_pPKStatusText, v6);
  v7 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (004F0170) --------------------------------------------------------  // acclient.c:284421
int __thiscall gmStatManagementUI::GetFooterTitleLabel(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x1000024Eu);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
  else
    result = 0;
  return result;
}

//----- (004F01C0) --------------------------------------------------------  // acclient.c:284450
int __thiscall gmStatManagementUI::GetFooterLineOneLabel(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x10000242u);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
  else
    result = 0;
  return result;
}

//----- (004F0210) --------------------------------------------------------  // acclient.c:284479
int __thiscall gmStatManagementUI::GetFooterLineOneValue(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x10000243u);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
  else
    result = 0;
  return result;
}

//----- (004F0260) --------------------------------------------------------  // acclient.c:284508
int __thiscall gmStatManagementUI::GetFooterMeter(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x10000247u);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)7);
  else
    result = 0;
  return result;
}

//----- (004F02B0) --------------------------------------------------------  // acclient.c:284537
int __thiscall gmStatManagementUI::GetFooterLineTwoLabel(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x10000244u);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
  else
    result = 0;
  return result;
}

//----- (004F0300) --------------------------------------------------------  // acclient.c:284566
int __thiscall gmStatManagementUI::GetFooterLineTwoValue(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x10000245u);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
  else
    result = 0;
  return result;
}

//----- (004F0350) --------------------------------------------------------  // acclient.c:284595
int __thiscall gmStatManagementUI::GetFooterButton(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x10000246u);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)1);
  else
    result = 0;
  return result;
}

//----- (004F03A0) --------------------------------------------------------  // acclient.c:284624
int __thiscall gmStatManagementUI::GetFooter10Button(gmStatManagementUI *this)
{
  unsigned int v1; // eax@1
  UIElement *v2; // eax@2
  UIElement *v3; // eax@6
  int result; // eax@7

  v1 = this->m_state;
  if ( v1 == 268435474 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000241u);
  }
  else if ( v1 == 268435475 )
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000247u);
  }
  else
  {
    v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x10000240u);
  }
  v3 = UIElement::GetChildRecursive(v2, 0x100005EBu);
  if ( v3 )
    result = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)1);
  else
    result = 0;
  return result;
}

//----- (004F03F0) --------------------------------------------------------  // acclient.c:284653
void __userpurge gmStatManagementUI::gmStatManagementUI(gmStatManagementUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmStatManagementUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->m_pNameText = 0;
  v4->m_pHeritageText = 0;
  v4->m_pPKStatusText = 0;
  v4->m_pLevelText = 0;
  v4->m_pTotalXPText = 0;
  v4->m_pXPToLevelText = 0;
  v4->m_pLuminanceLabelText = 0;
  v4->m_pLuminanceText = 0;
  v4->m_pXPToLevelMeter = 0;
  v4->m_pListBox = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmStatManagementUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmAttributeUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmStatManagementUI::vftable;
  v4->m_rgTokens.m_data = 0;
  v4->m_rgTokens.m_sizeAndDeallocate = 0;
  v4->m_rgTokens.m_num = 0;
  v4->m_bAwaitingRaise = 0;
  v4->m_titleID = 0;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7A7B50: using guessed type bool (__thiscall *gmAttributeUI::vftable)(DBCache *this);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3C5C: using guessed type void (__thiscall *gmStatManagementUI::vftable[2])(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7C3C68: using guessed type int (__thiscall *gmStatManagementUI::vftable)(void *, char);

//----- (004F04A0) --------------------------------------------------------  // acclient.c:284687
char __thiscall gmStatManagementUI::Update(gmStatManagementUI *this)
{
  gmStatManagementUI *v1; // ebp@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // esi@2
  int v4; // ebx@4
  PlayerDesc *v5; // esi@6
  char v7; // bl@10
  int v8; // [sp-8h] [bp-2Ch]@2
  Interface *_rpInterface; // [sp+10h] [bp-14h]@2
  TResult result; // [sp+14h] [bp-10h]@2
  char v11; // [sp+18h] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@2

  v1 = this;
  if ( !((*((_DWORD *)&this->0 + 41) >> 1) & 1) )
    return 0;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_24, &_rpInterface);
  v3 = _rpInterface;
  v8 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v8, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = playerDesc.m_pInterface;
  if ( !(_DWORD)playerDesc.m_pInterface )
    return 0;
  if ( v4 < 0 )
  {
    playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    return 0;
  }
  v7 = (int)v1->vfptr[26].__vecDelDtor((IInputActionCallback *)v1, (unsigned int)playerDesc.m_pInterface);
  v5->vfptr->Release((Interface *)v5);
  return v7;
}

//----- (004F0550) --------------------------------------------------------  // acclient.c:284730
char __thiscall gmStatManagementUI::FlushList(gmStatManagementUI *this)
{
  gmStatManagementUI *v1; // eax@1
  unsigned int v2; // esi@1
  InfoRegion *v3; // ecx@2
  unsigned int v4; // edx@5
  int v5; // eax@5
  unsigned int v6; // ecx@5
  gmStatManagementUI *v8; // [sp+4h] [bp-4h]@1

  v8 = this;
  UIElement_ListBox::Flush(this->m_pListBox);
  v1 = v8;
  v2 = 0;
  if ( v8->m_rgTokens.m_num )
  {
    do
    {
      v3 = v1->m_rgTokens.m_data[v2];
      if ( v3 )
      {
        ((void (__stdcall *)(signed int))v3->vfptr[1].OnQualityChanged)(1);
        v1 = v8;
      }
      v1->m_rgTokens.m_data[v2] = 0;
      v1 = v8;
      ++v2;
    }
    while ( v2 < v8->m_rgTokens.m_num );
  }
  v4 = v1->m_rgTokens.m_num;
  v5 = (int)&v1->m_rgTokens;
  v6 = 0;
  if ( v4 )
  {
    do
      *(_DWORD *)(*(_DWORD *)v5 + 4 * v6++) = 0;
    while ( v6 < *(_DWORD *)(v5 + 8) );
  }
  *(_DWORD *)(v5 + 8) = 0;
  return 1;
}

//----- (004F05E0) --------------------------------------------------------  // acclient.c:284774
void __thiscall gmStatManagementUI::~gmStatManagementUI(gmStatManagementUI *this)
{
  gmStatManagementUI *v1; // edi@1
  NoticeHandler *v2; // ebp@1
  char *v3; // esi@1
  GlobalEventHandler *v4; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmStatManagementUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmAttributeUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmStatManagementUI::vftable;
  gmStatManagementUI::FlushList(this);
  v1->m_pNameText = 0;
  v1->m_pHeritageText = 0;
  v1->m_pPKStatusText = 0;
  v1->m_pLevelText = 0;
  v1->m_pTotalXPText = 0;
  v1->m_pXPToLevelText = 0;
  v1->m_pLuminanceLabelText = 0;
  v1->m_pLuminanceText = 0;
  v1->m_pXPToLevelMeter = 0;
  v1->m_pListBox = 0;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v2);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    25,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    24,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    30,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    134,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    188,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    1,
    113,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    14,
    1,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    14,
    2,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    14,
    6,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    14,
    7,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    5,
    1,
    v3);
  if ( (v1->m_rgTokens.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_rgTokens.m_data);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A7B50: using guessed type bool (__thiscall *gmAttributeUI::vftable)(DBCache *this);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3C5C: using guessed type void (__thiscall *gmStatManagementUI::vftable[2])(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7C3C68: using guessed type int (__thiscall *gmStatManagementUI::vftable)(void *, char);

//----- (004F0750) --------------------------------------------------------  // acclient.c:284857
gmStatManagementUI *__thiscall gmStatManagementUI::vector_deleting_destructor(gmStatManagementUI *this, unsigned int a2)
{
  gmStatManagementUI *v2; // esi@1

  v2 = this;
  gmStatManagementUI::~gmStatManagementUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004F0770) --------------------------------------------------------  // acclient.c:284869
char __thiscall gmStatManagementUI::UpdateCharacterInfo(gmStatManagementUI *this, CACQualities *i_playerDesc)
{
  gmStatManagementUI *v2; // ebp@1
  unsigned int v3; // eax@2
  char *v4; // eax@4
  AC1Legacy::PSRefBuffer<char> *v5; // esi@4
  AC1Legacy::PSRefBuffer<char> *v6; // edi@5
  CBaseQualities *v7; // esi@12
  PStringBase<unsigned short> *v8; // eax@12
  char *v9; // edi@12
  PStringBase<unsigned short> *v10; // eax@15
  char *v11; // edi@15
  char *v12; // edi@19
  CACQualities **v13; // eax@24
  char *v14; // esi@26
  char *v15; // esi@29
  AC1Legacy::PSRefBuffer<char> *v16; // esi@32
  AC1Legacy::PSRefBuffer<char> *v17; // esi@35
  unsigned int heritage; // [sp+10h] [bp-58h]@12
  unsigned int gender; // [sp+14h] [bp-54h]@12
  PStringBase<unsigned short> strTitle; // [sp+18h] [bp-50h]@18
  AC1Legacy::PStringBase<char> genderHeritageStr; // [sp+1Ch] [bp-4Ch]@15
  AC1Legacy::PStringBase<char> fullNameStr; // [sp+20h] [bp-48h]@12
  int rank; // [sp+24h] [bp-44h]@12
  int charLevel; // [sp+28h] [bp-40h]@23
  AC1Legacy::PStringBase<char> v26; // [sp+2Ch] [bp-3Ch]@4
  CAllegianceData alleg_data; // [sp+30h] [bp-38h]@1

  v2 = this;
  CAllegianceData::CAllegianceData(&alleg_data);
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  v4 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v3, 0, 0);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v26, v4);
  v5 = v26.m_buffer;
  if ( alleg_data._name.m_buffer != v26.m_buffer )
  {
    v6 = alleg_data._name.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&alleg_data._name.m_buffer->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    alleg_data._name.m_buffer = v5;
    InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  v7 = (CBaseQualities *)&i_playerDesc->vfptr;
  gender = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x71u, (int *)&gender, 0, 0);
  alleg_data._gender = gender;
  heritage = 0;
  CBaseQualities::InqInt(v7, 0xBCu, (int *)&heritage, 0, 0);
  alleg_data._hg = heritage;
  rank = 0;
  CBaseQualities::InqInt(v7, 0x1Eu, &rank, 1, 0);
  alleg_data._rank = rank;
  fullNameStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AllegianceData::GetFullName((AllegianceData *)&alleg_data.vfptr, &fullNameStr);
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&i_playerDesc,
    0,
    fullNameStr.m_buffer->m_data);
  UIElement_Text::SetText(v2->m_pNameText, v8);
  v9 = (char *)&i_playerDesc[-1]._create_list;
  if ( !InterlockedDecrement((volatile LONG *)&i_playerDesc[-1]._pageDataList) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  genderHeritageStr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AppraisalSystem::InqGenderHeritageDisplay(gender, heritage, 0, &genderHeritageStr);
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&i_playerDesc,
    0,
    genderHeritageStr.m_buffer->m_data);
  UIElement_Text::SetText(v2->m_pHeritageText, v10);
  v11 = (char *)&i_playerDesc[-1]._create_list;
  if ( !InterlockedDecrement((volatile LONG *)&i_playerDesc[-1]._pageDataList) && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  strTitle.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( CharacterTitleTable::GetCharacterTitleFromID(v2->m_titleID, &strTitle) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_playerDesc, L" ");
    UIElement_Text::AppendText(v2->m_pHeritageText, (PStringBase<unsigned short> *)&i_playerDesc);
    v12 = (char *)&i_playerDesc[-1]._create_list;
    if ( !InterlockedDecrement((volatile LONG *)&i_playerDesc[-1]._pageDataList) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    UIElement_Text::AppendText(v2->m_pHeritageText, &strTitle);
  }
  charLevel = 0;
  if ( CBaseQualities::InqInt(v7, 0x19u, &charLevel, 0, 0) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_playerDesc,
      0,
      L"%d",
      charLevel);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_playerDesc, L"???");
    v13 = &i_playerDesc;
  }
  UIElement_Text::SetText(v2->m_pLevelText, (PStringBase<unsigned short> *)v13);
  v14 = (char *)&i_playerDesc[-1]._create_list;
  if ( !InterlockedDecrement((volatile LONG *)&i_playerDesc[-1]._pageDataList) && v14 )
    (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  v15 = (char *)&strTitle.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strTitle.m_charbuffer[-1].m_data[8]) && v15 )
    (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
  v16 = genderHeritageStr.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&genderHeritageStr.m_buffer->m_cRef) && v16 )
    v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
  v17 = fullNameStr.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&fullNameStr.m_buffer->m_cRef) && v17 )
    v17->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v17, 1u);
  AllegianceData::~AllegianceData((AllegianceData *)&alleg_data.vfptr);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004F0A70) --------------------------------------------------------  // acclient.c:284992
char __thiscall gmStatManagementUI::UpdateExperience(gmStatManagementUI *this, CACQualities *i_playerDesc)
{
  AC1Legacy::PSRefBuffer<char> *v2; // eax@1
  int v3; // eax@5
  unsigned int v4; // edx@5
  unsigned int v5; // edi@5
  int v6; // esi@5
  __int64 v7; // rax@5
  unsigned int v8; // ebx@5
  unsigned int v9; // ebp@5
  unsigned int v10; // esi@5
  int v11; // kr00_4@5
  PStringBase<unsigned short> *v12; // eax@9
  gmStatManagementUI *v13; // edi@9
  PStringBase<unsigned short> *v14; // eax@15
  PStringBase<unsigned short> *v15; // eax@23
  char *v16; // edi@23
  AC1Legacy::PSRefBuffer<char> *v17; // edi@26
  float v18; // ST24_4@32
  AC1Legacy::PStringBase<char> text; // [sp+28h] [bp-108h]@1
  unsigned __int64 myXPToLevel; // [sp+2Ch] [bp-104h]@5
  PStringBase<unsigned short> result; // [sp+34h] [bp-FCh]@9
  unsigned __int64 myXPTotal; // [sp+38h] [bp-F8h]@1
  int charLevel; // [sp+40h] [bp-F0h]@5
  gmStatManagementUI *v25; // [sp+44h] [bp-ECh]@1
  unsigned __int64 myMaxLuminance; // [sp+48h] [bp-E8h]@1
  unsigned __int64 myLuminance; // [sp+50h] [bp-E0h]@1
  unsigned __int64 myXPTowardsNextLevel; // [sp+58h] [bp-D8h]@5
  char formatted_maxluminance[32]; // [sp+60h] [bp-D0h]@23
  char formatted_luminance[32]; // [sp+80h] [bp-B0h]@23
  StringInfo siText; // [sp+A0h] [bp-90h]@9

  v25 = this;
  myXPTotal = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&i_playerDesc->vfptr, 1u, (__int64 *)&myXPTotal);
  myLuminance = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&i_playerDesc->vfptr, 6u, (__int64 *)&myLuminance);
  myMaxLuminance = 0i64;
  CBaseQualities::InqInt64((CBaseQualities *)&i_playerDesc->vfptr, 7u, (__int64 *)&myMaxLuminance);
  v2 = (AC1Legacy::PSRefBuffer<char> *)CPlayerSystem::GetPlayerSystem();
  text.m_buffer = v2;
  if ( v2 && !CPlayerSystem::AccountHasThroneOfDestiny((CPlayerSystem *)v2) && myXPTotal > 0xFFFFFFFF )
    myXPTotal = 0xFFFFFFFFi64;
  charLevel = 0;
  CBaseQualities::InqInt((CBaseQualities *)&i_playerDesc->vfptr, 0x19u, &charLevel, 0, 0);
  v3 = ExperienceSystem::ExperienceToLevel(charLevel);
  v5 = v4;
  v6 = v3;
  LODWORD(v7) = ExperienceSystem::ExperienceToLevel(charLevel + 1);
  v8 = v7 - v6;
  v9 = (v7 - __PAIR__(v5, v6)) >> 32;
  v11 = myXPTotal - v6;
  v10 = (myXPTotal - __PAIR__(v5, v6)) >> 32;
  LODWORD(myXPTowardsNextLevel) = v11;
  myXPToLevel = v7 - myXPTotal;
  if ( text.m_buffer && !CPlayerSystem::AccountHasThroneOfDestiny((CPlayerSystem *)text.m_buffer) && charLevel == 126 )
    myXPToLevel = 0i64;
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Header_TotalXPValue, 268435457);
  StringInfo::AddVariable_Int(&siText, ID_TotalExperience, myXPTotal);
  v12 = StringInfo::GetString(&siText, (PStringBase<unsigned short> *)&text, 0);
  v13 = v25;
  UIElement_Text::SetText(v25->m_pTotalXPText, v12);
  result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)&text.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&text.m_buffer[-1].m_cRef + 1) && result.m_charbuffer )
    (**(void (__stdcall ***)(_DWORD))&result.m_charbuffer->m_data[0])(1);
  if ( myXPToLevel )
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Header_XPToLevelMeterValue, 268435457);
    StringInfo::AddVariable_Int(&siText, ID_ExperienceToLevel, myXPToLevel);
  }
  else
  {
    StringInfo::SetStringIDandTableEnum(&siText, ID_StatManagement_Header_XPToLevelMeterInfinity_1, 268435457);
  }
  v14 = StringInfo::GetString(&siText, &result, 0);
  UIElement_Text::SetText(v13->m_pXPToLevelText, v14);
  text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && text.m_buffer )
    ((void (__stdcall *)(signed int))text.m_buffer->vfptr->__vecDelDtor)(1);
  if ( charLevel >= 200 && myMaxLuminance )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&text, L"Luminance:");
    UIElement_Text::SetText(v13->m_pLuminanceLabelText, (PStringBase<unsigned short> *)&text);
    result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)&text.m_buffer[-1].m_cRef;
    if ( !InterlockedDecrement((volatile LONG *)&text.m_buffer[-1].m_cRef + 1) && result.m_charbuffer )
      (**(void (__stdcall ***)(_DWORD))&result.m_charbuffer->m_data[0])(1);
    text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    ExperienceSystem::XPToString(myLuminance, formatted_luminance);
    ExperienceSystem::XPToString(myMaxLuminance, formatted_maxluminance);
    AC1Legacy::PStringBase<char>::sprintf(&text, "%s / %s", formatted_luminance, formatted_maxluminance);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&result, 0, text.m_buffer->m_data);
    UIElement_Text::SetText(v13->m_pLuminanceText, v15);
    v16 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    v17 = text.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&text.m_buffer->m_cRef) && v17 )
      v17->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v17, 1u);
    v13 = v25;
  }
  else
  {
    UIElement_Text::ClearAllText(v13->m_pLuminanceLabelText);
    UIElement_Text::ClearAllText(v13->m_pLuminanceText);
  }
  if ( v9 || v8 > 0 )
  {
    myXPToLevel = __PAIR__(v9, 0) & 0x8000000000000000ui64;
    v18 = (double)__PAIR__(v10, (unsigned int)myXPTowardsNextLevel) / (double)__PAIR__(v9, v8);
    UIElement::SetAttribute_Float((UIElement *)&v13->m_pXPToLevelMeter->vfptr, 0x69u, v18);
  }
  else
  {
    UIElement::SetAttribute_Float((UIElement *)&v13->m_pXPToLevelMeter->vfptr, 0x69u, 0.0);
  }
  StringInfo::~StringInfo(&siText);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006F7B30) --------------------------------------------------------  // acclient.c:780535
void sub_6F7B30()
{
  flt_840DD0 = 1000.0 + 1.0;
}

//----- (006F7B50) --------------------------------------------------------  // acclient.c:780541
void sub_6F7B50()
{
  flt_840DD4 = 24.0 * 8.0;
}

//----- (006F7B70) --------------------------------------------------------  // acclient.c:780547
void sub_6F7B70()
{
  flt_840DD8 = 24.0 * 0.5;
}

//----- (006F7B90) --------------------------------------------------------  // acclient.c:780553
int sub_6F7B90()
{
  return atexit(nullsub_864);
}

//----- (006F7BA0) --------------------------------------------------------  // acclient.c:780559
int sub_6F7BA0()
{
  return atexit(nullsub_865);
}

//----- (006F7BB0) --------------------------------------------------------  // acclient.c:780565
int sub_6F7BB0()
{
  return atexit(nullsub_866);
}

//----- (006F7BC0) --------------------------------------------------------  // acclient.c:780571
void _E109_48()
{
  DEFAULT_VIEW_RADIUS_83 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F7BE0) --------------------------------------------------------  // acclient.c:780577
void _E111_33()
{
  MIN_QUANTUM_83 = 1.0 / 30.0;
}

//----- (006F7C00) --------------------------------------------------------  // acclient.c:780583
void _E113_20()
{
  MAX_QUANTUM_83 = 1.0 / 5.0;
}

//----- (006F7C20) --------------------------------------------------------  // acclient.c:780589
void _E115_53()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840DF0, PFID_A8R8G8B8);
}

//----- (006F7C30) --------------------------------------------------------  // acclient.c:780595
int _E117_50()
{
  return atexit(nullsub_862);
}

//----- (006F7C40) --------------------------------------------------------  // acclient.c:780601
unsigned int _E120_46()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_PKStatus_NPK");
  ID_StatManagement_Header_PKStatus_NPK = result;
  return result;
}

//----- (006F7C60) --------------------------------------------------------  // acclient.c:780611
unsigned int _E122_25()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_PKStatus_PK");
  ID_StatManagement_Header_PKStatus_PK = result;
  return result;
}

//----- (006F7C80) --------------------------------------------------------  // acclient.c:780621
unsigned int _E124_51()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_PKStatus_PKL");
  ID_StatManagement_Header_PKStatus_PKL = result;
  return result;
}

//----- (006F7CA0) --------------------------------------------------------  // acclient.c:780631
unsigned int _E126_28()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_TotalXPValue");
  ID_StatManagement_Header_TotalXPValue = result;
  return result;
}

//----- (006F7CC0) --------------------------------------------------------  // acclient.c:780641
unsigned int _E128_10()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_XPToLevelMeterValue");
  ID_StatManagement_Header_XPToLevelMeterValue = result;
  return result;
}

//----- (006F7CE0) --------------------------------------------------------  // acclient.c:780651
unsigned int _E130_38()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_StatManagement_Header_XPToLevelMeterInfinity");
  ID_StatManagement_Header_XPToLevelMeterInfinity_1 = result;
  return result;
}

//----- (006F7D00) --------------------------------------------------------  // acclient.c:780661
unsigned int _E132_23()
{
  unsigned int result; // eax@1

  result = compute_str_hash("TOTAL_EXPERIENCE");
  ID_TotalExperience = result;
  return result;
}

//----- (006F7D20) --------------------------------------------------------  // acclient.c:780671
unsigned int _E134_7()
{
  unsigned int result; // eax@1

  result = compute_str_hash("EXPERIENCE_TO_LEVEL");
  ID_ExperienceToLevel = result;
  return result;
}

//----- (006F7D40) --------------------------------------------------------  // acclient.c:780681
int sub_6F7D40()
{
  return atexit(nullsub_863);
}

