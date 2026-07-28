/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmAllegianceUI
   Object     : GAME\game_ui_misc\gmAllegianceUI.obj
   Functions  : 74
   Addresses  : 004908B0 - 0075F8F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004908B0) --------------------------------------------------------  // acclient.c:203860
void __thiscall gmAllegianceUI::ListenToGlobalMessage(gmAllegianceUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 1 && i_data_int == 39 )
    UIElement_ListBox::SetSelectedItem(this->m_pVassalListBox, 0, 1);
}

//----- (004908E0) --------------------------------------------------------  // acclient.c:203867
void __thiscall gmAllegianceUI::UpdateSwearButton(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // ebx@1
  AllegianceProfile *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // esi@5
  unsigned int v5; // eax@7
  HashBaseData<unsigned long> *v6; // eax@10
  AllegianceData vassalData; // [sp+Ch] [bp-70h]@12
  CAllegianceData patronAllegianceData; // [sp+44h] [bp-38h]@1

  v1 = this;
  v2 = (AllegianceProfile *)&ClientAllegianceSystem::GetAllegianceSystem()->m_allegianceProfile.vfptr;
  CAllegianceData::CAllegianceData(&patronAllegianceData);
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  if ( !AllegianceProfile::GetPatron(v2, v3, (AllegianceData *)&patronAllegianceData.vfptr) )
  {
    v4 = ACCWeenieObject::selectedID;
    if ( ACCWeenieObject::selectedID )
    {
      v5 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
      if ( ACCWeenieObject::selectedID != v5 )
      {
        v6 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
        if ( v6 )
        {
          if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v6->vfptr[4].__vecDelDtor)(v6) )
          {
            AllegianceData::AllegianceData(&vassalData);
            if ( !AllegianceProfile::GetData(v2, v4, &vassalData) )
            {
              ((void (__stdcall *)(signed int))v1->m_pSwearButton->vfptr[13].__vecDelDtor)(1);
              AllegianceData::~AllegianceData(&vassalData);
              AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
              return;
            }
            AllegianceData::~AllegianceData(&vassalData);
          }
        }
      }
    }
  }
  ((void (__stdcall *)(signed int))v1->m_pSwearButton->vfptr[13].__vecDelDtor)(13);
  AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
}

//----- (004909D0) --------------------------------------------------------  // acclient.c:203917
void __thiscall gmAllegianceUI::UpdateBreakButton(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // edi@1
  AllegianceProfile *v2; // esi@1
  unsigned int v3; // eax@2
  unsigned int v4; // eax@4
  UIElement_Button *v5; // ecx@4
  CAllegianceData patronAllegianceData; // [sp+8h] [bp-38h]@1

  v1 = this;
  v2 = (AllegianceProfile *)&ClientAllegianceSystem::GetAllegianceSystem()->m_allegianceProfile.vfptr;
  CAllegianceData::CAllegianceData(&patronAllegianceData);
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  v4 = AllegianceProfile::GetPatron(v2, v3, (AllegianceData *)&patronAllegianceData.vfptr);
  v5 = v1->m_pBreakButton;
  if ( v4 )
  {
    ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(1);
    AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
  }
  else
  {
    ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(13);
    AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
  }
}

//----- (00490A50) --------------------------------------------------------  // acclient.c:203948
char __thiscall gmAllegianceUI::CloseAcceptSwearConfirmationDialog(gmAllegianceUI *this, bool i_bConfirm)
{
  gmAllegianceUI *v2; // esi@1
  unsigned int v3; // ST04_4@1

  v2 = this;
  v3 = this->m_uiAcceptSwearServerContextID;
  this->m_acceptSwearContext = 0;
  CM_Character::Event_ConfirmationResponse(1, v3, i_bConfirm);
  v2->m_uiAcceptSwearServerContextID = 0;
  return 1;
}

//----- (00490A90) --------------------------------------------------------  // acclient.c:203962
char __thiscall gmAllegianceUI::CloseBreakConfirmationDialog(gmAllegianceUI *this, bool i_bConfirm)
{
  AllegianceProfile *v2; // esi@2
  unsigned int v3; // eax@3
  unsigned int v4; // eax@5
  CAllegianceData patronAllegianceData; // [sp+0h] [bp-38h]@2

  this->m_breakContext = 0;
  if ( i_bConfirm )
  {
    v2 = (AllegianceProfile *)&ClientAllegianceSystem::GetAllegianceSystem()->m_allegianceProfile.vfptr;
    CAllegianceData::CAllegianceData(&patronAllegianceData);
    if ( SmartBox::smartbox )
      v3 = SmartBox::smartbox->player_id;
    else
      v3 = 0;
    v4 = AllegianceProfile::GetPatron(v2, v3, (AllegianceData *)&patronAllegianceData.vfptr);
    CM_Allegiance::Event_BreakAllegiance(v4);
    AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
  }
  return 1;
}

//----- (00490B00) --------------------------------------------------------  // acclient.c:203986
char __thiscall gmAllegianceUI::CloseKickConfirmationDialog(gmAllegianceUI *this, bool i_bConfirm)
{
  gmAllegianceUI *v2; // esi@1

  v2 = this;
  this->m_kickContext = 0;
  if ( i_bConfirm )
    CM_Allegiance::Event_BreakAllegiance(this->m_iidPossibleKickedVassal);
  v2->m_iidPossibleKickedVassal = 0;
  return 1;
}

//----- (00490B40) --------------------------------------------------------  // acclient.c:203999
void __userpurge gmAllegianceUI::gmAllegianceUI(gmAllegianceUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmAllegianceUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->m_bAwaitingUpdate = 0;
  v4->m_iidSelectedVassal = 0;
  v4->m_iidPossibleNewPatron = 0;
  v4->m_iidPossibleKickedVassal = 0;
  v4->m_uiAcceptSwearServerContextID = 0;
  v4->m_pAllegianceName = 0;
  v4->m_pPlayerFollowers = 0;
  v4->m_pPlayerRank = 0;
  v4->m_pMonarchField = 0;
  v4->m_pMonarchLabel = 0;
  v4->m_pMonarchName = 0;
  v4->m_pMonarchFollowers = 0;
  v4->m_pPatronField = 0;
  v4->m_pPatronName = 0;
  v4->m_pVassalListBox = 0;
  v4->m_pSwearButton = 0;
  v4->m_pBreakButton = 0;
  v4->m_pKickButton = 0;
  v4->m_swearContext = 0;
  v4->m_acceptSwearContext = 0;
  v4->m_breakContext = 0;
  v4->m_kickContext = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmAllegianceUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmAllegianceUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmAllegianceUI::vftable;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7A5AAC: using guessed type void (__thiscall *gmAllegianceUI::vftable[2])(gmAllegianceUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7A5AB8: using guessed type bool (__thiscall *gmAllegianceUI::vftable)(DBCache *this);
// 7A5D60: using guessed type int (__thiscall *gmAllegianceUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00490C10) --------------------------------------------------------  // acclient.c:204040
gmAllegianceUI *__thiscall gmAllegianceUI::DynamicCast(gmAllegianceUI *this, unsigned int i_eType)
{
  gmAllegianceUI *result; // eax@1

  result = this;
  if ( i_eType != 268435500 )
    result = (gmAllegianceUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00490C30) --------------------------------------------------------  // acclient.c:204051
signed int gmAllegianceUI::GetUIElementType()
{
  return 268435500;
}

//----- (00490C40) --------------------------------------------------------  // acclient.c:204057
void __thiscall gmAllegianceUI::~gmAllegianceUI(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  char *v3; // ebx@1
  GlobalEventHandler *v4; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmAllegianceUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmAllegianceUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmAllegianceUI::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v2);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    7,
    25,
    v3);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->UnRegisterQualityHandlerForThePlayer)(
    7,
    26,
    v3);
  DialogFactory::CloseDialog(v1->m_swearContext);
  v1->m_swearContext = 0;
  DialogFactory::CloseDialog(v1->m_acceptSwearContext);
  v1->m_acceptSwearContext = 0;
  DialogFactory::CloseDialog(v1->m_breakContext);
  v1->m_breakContext = 0;
  DialogFactory::CloseDialog(v1->m_kickContext);
  v1->m_kickContext = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A5AAC: using guessed type void (__thiscall *gmAllegianceUI::vftable[2])(gmAllegianceUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7A5AB8: using guessed type bool (__thiscall *gmAllegianceUI::vftable)(DBCache *this);
// 7A5D60: using guessed type int (__thiscall *gmAllegianceUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00490D10) --------------------------------------------------------  // acclient.c:204100
void __usercall gmAllegianceUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmAllegianceUI *v3; // eax@1

  v3 = (gmAllegianceUI *)operator new(0x658u);
  if ( v3 )
    gmAllegianceUI::gmAllegianceUI(v3, a1, _layout, _full_desc);
}

//----- (00490D40) --------------------------------------------------------  // acclient.c:204110
void __thiscall gmAllegianceUI::RecvNotice_PlayerDescReceived(gmAllegianceUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  ClientUISystem *v3; // eax@2

  if ( !LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr) )
  {
    LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr) = 1;
    v3 = ClientUISystem::GetUISystem();
    ClientUISystem::IncrementBusyCount(v3);
  }
  CM_Allegiance::Event_UpdateRequest(1);
}

//----- (00490D70) --------------------------------------------------------  // acclient.c:204124
void __thiscall gmAllegianceUI::RecvNotice_SelectionChanged(gmAllegianceUI *this)
{
  gmAllegianceUI::UpdateSwearButton((gmAllegianceUI *)((char *)this - 1528));
}

//----- (00490D80) --------------------------------------------------------  // acclient.c:204130
void __thiscall gmAllegianceUI::RecvNotice_AbortConfirmationRequest(gmAllegianceUI *this, int confirmationType, unsigned int context)
{
  gmAllegianceUI *v3; // esi@1

  v3 = this;
  if ( confirmationType == 1 )
  {
    DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[18]);
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[18] = 0;
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = 0;
    gmAllegianceUI::UpdateSwearButton((gmAllegianceUI *)((char *)v3 - 1528));
  }
}

//----- (00490DB0) --------------------------------------------------------  // acclient.c:204145
void __thiscall gmAllegianceUI::OnQualityRemoved(gmAllegianceUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  ClientUISystem *v4; // eax@2

  if ( !LOBYTE(this->m_hashElementsRegisteredWith.vfptr) )
  {
    LOBYTE(this->m_hashElementsRegisteredWith.vfptr) = 1;
    v4 = ClientUISystem::GetUISystem();
    ClientUISystem::IncrementBusyCount(v4);
  }
  CM_Allegiance::Event_UpdateRequest(1);
}

//----- (00490DE0) --------------------------------------------------------  // acclient.c:204159
void __thiscall AC1Legacy::PStringBase<char>::append_n_chars(AC1Legacy::PStringBase<char> *this, const char *str, unsigned int count)
{
  AC1Legacy::PStringBase<char> *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1
  unsigned int v5; // ebp@1
  unsigned int v6; // ebx@1

  v3 = this;
  v4 = this->m_buffer;
  v5 = this->m_buffer->m_len;
  v6 = count + v5;
  if ( count + v5 <= this->m_buffer->m_size )
  {
    AC1Legacy::PStringBase<char>::break_reference(this);
    v3->m_buffer->m_len = v6;
  }
  else
  {
    AC1Legacy::PStringBase<char>::allocate_ref_buffer(this, v6 - 1);
    strcpy(v3->m_buffer->m_data, v4->m_data);
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  }
  _strncpy((char *)&v3->m_buffer->m_hash + v5 + 3, str, count);
  *((_BYTE *)&v3->m_buffer->m_hash + v3->m_buffer->m_len + 3) = 0;
}

//----- (00490E70) --------------------------------------------------------  // acclient.c:204187
gmAllegianceUI *__thiscall gmAllegianceUI::vector_deleting_destructor(gmAllegianceUI *this, unsigned int a2)
{
  gmAllegianceUI *v2; // esi@1

  v2 = this;
  gmAllegianceUI::~gmAllegianceUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00490E90) --------------------------------------------------------  // acclient.c:204199
void __thiscall gmAllegianceUI::PostInit(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // edi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  int v4; // esi@3
  unsigned int v5; // eax@4
  unsigned int v6; // eax@4
  UIElement *v7; // eax@5
  int v8; // eax@6
  UIElement *v9; // eax@8
  int v10; // eax@9
  UIElement *v11; // eax@11
  int v12; // eax@12
  UIElement *v13; // eax@14
  int v14; // eax@15
  UIElement *v15; // eax@17
  int v16; // eax@18
  UIElement *v17; // eax@20
  int v18; // eax@21
  UIElement *v19; // eax@23
  int v20; // eax@24
  UIElement *v21; // eax@26
  int v22; // eax@27
  UIElement *v23; // eax@29
  int v24; // eax@30
  UIElement *v25; // eax@32
  int v26; // eax@33
  UIElement *v27; // eax@35
  int v28; // eax@36
  GlobalEventHandler *v29; // esi@38
  ClientUISystem *v30; // eax@39
  StringInfo _info; // [sp+68h] [bp-90h]@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  StringInfo::StringInfo(&_info);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000262u);
  if ( v2 )
  {
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435509);
    if ( v3 )
    {
      v4 = v3 - 32;
      if ( v3 != 32 )
      {
        UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)(v3 - 32), IgnoreAllegianceRequests_PlayerOption);
        v5 = compute_str_hash("ID_PlayerOption_IgnoreAllegianceRequests");
        StringInfo::SetStringIDandTableEnum(&_info, v5, 268435459);
        UIElement_Text::SetStringInfo((UIElement_Text *)(v4 + 32), &_info);
        v6 = compute_str_hash("ID_PlayerOption_IgnoreAllegianceRequests_Help");
        StringInfo::SetStringIDandTableEnum(&_info, v6, 268435459);
        (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v4 + 692))(v4, &_info);
      }
    }
  }
  v7 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000251u);
  if ( v7 )
    v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)12);
  else
    v8 = 0;
  v1->m_pAllegianceName = (UIElement_Text *)v8;
  v9 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000252u);
  if ( v9 )
    v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)12);
  else
    v10 = 0;
  v1->m_pPlayerFollowers = (UIElement_Text *)v10;
  v11 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000253u);
  if ( v11 )
    v12 = v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)12);
  else
    v12 = 0;
  v1->m_pPlayerRank = (UIElement_Text *)v12;
  v1->m_pMonarchField = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000255u);
  v13 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000256u);
  if ( v13 )
    v14 = v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)12);
  else
    v14 = 0;
  v1->m_pMonarchLabel = (UIElement_Text *)v14;
  v15 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000257u);
  if ( v15 )
    v16 = v15->vfptr[12].OnAction((IInputActionCallback *)v15, (InputEvent *)12);
  else
    v16 = 0;
  v1->m_pMonarchName = (UIElement_Text *)v16;
  v17 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000258u);
  if ( v17 )
    v18 = v17->vfptr[12].OnAction((IInputActionCallback *)v17, (InputEvent *)12);
  else
    v18 = 0;
  v1->m_pMonarchFollowers = (UIElement_Text *)v18;
  v1->m_pPatronField = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000025Au);
  v19 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000025Cu);
  if ( v19 )
    v20 = v19->vfptr[12].OnAction((IInputActionCallback *)v19, (InputEvent *)12);
  else
    v20 = 0;
  v1->m_pPatronName = (UIElement_Text *)v20;
  v21 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000260u);
  if ( v21 )
    v22 = v21->vfptr[12].OnAction((IInputActionCallback *)v21, (InputEvent *)5);
  else
    v22 = 0;
  v1->m_pVassalListBox = (UIElement_ListBox *)v22;
  v23 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000263u);
  if ( v23 )
    v24 = v23->vfptr[12].OnAction((IInputActionCallback *)v23, (InputEvent *)1);
  else
    v24 = 0;
  v1->m_pSwearButton = (UIElement_Button *)v24;
  v25 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000264u);
  if ( v25 )
    v26 = v25->vfptr[12].OnAction((IInputActionCallback *)v25, (InputEvent *)1);
  else
    v26 = 0;
  v1->m_pBreakButton = (UIElement_Button *)v26;
  v27 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000265u);
  if ( v27 )
    v28 = v27->vfptr[12].OnAction((IInputActionCallback *)v27, (InputEvent *)1);
  else
    v28 = 0;
  v1->m_pKickButton = (UIElement_Button *)v28;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    7,
    25,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    7,
    26,
    &v1->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  v29 = GlobalEventHandler::GetGlobalEventHandler();
  v29->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v29, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v29,
    (unsigned int)((char *)&loc_4DD200 + 1),
    (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v29,
    (unsigned int)((char *)&loc_4DD205 + 1),
    (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v29, (unsigned int)&loc_4DD207, (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v29, (unsigned int)&loc_4DD205, (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v29,
    (unsigned int)((char *)&loc_4DD207 + 1),
    (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v29,
    (unsigned int)((char *)&loc_4DD1EE + 1),
    (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v29,
    (unsigned int)((char *)&loc_4DD20C + 1),
    (NoticeHandler *)&v1->vfptr);
  v29->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v29, 100004u, (NoticeHandler *)&v1->vfptr);
  if ( !v1->m_bAwaitingUpdate )
  {
    v1->m_bAwaitingUpdate = 1;
    v30 = ClientUISystem::GetUISystem();
    ClientUISystem::IncrementBusyCount(v30);
  }
  CM_Allegiance::Event_UpdateRequest(1);
  StringInfo::~StringInfo(&_info);
}

//----- (004911F0) --------------------------------------------------------  // acclient.c:204368
void __cdecl gmAllegianceUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000002Cu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmAllegianceUI::Create);
}

//----- (00491210) --------------------------------------------------------  // acclient.c:204376
AC1Legacy::PStringBase<char> *__thiscall AC1Legacy::PStringBase<char>::operator+=(AC1Legacy::PStringBase<char> *this, AC1Legacy::PStringBase<char> *rhs)
{
  AC1Legacy::PSRefBuffer<char> *v2; // eax@1
  AC1Legacy::PStringBase<char> *v3; // esi@1
  unsigned int v4; // ecx@1

  v2 = rhs->m_buffer;
  v3 = this;
  v4 = rhs->m_buffer->m_len;
  if ( v4 != 1 && v2 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v3, v2->m_data, v4 - 1);
  return v3;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00491240) --------------------------------------------------------  // acclient.c:204392
void __thiscall gmAllegianceUI::OnVisibilityChanged(gmAllegianceUI *this, bool i_bVisible)
{
  gmAllegianceUI *v2; // ebp@1
  InterfaceSystem *v3; // eax@2
  int v4; // esi@2
  int v5; // edi@4
  PlayerDesc *v6; // esi@6
  ClientUISystem *v7; // eax@9
  ClientUISystem *v8; // eax@13
  int v9; // [sp-8h] [bp-28h]@2
  TResult result; // [sp+10h] [bp-10h]@2
  char v11; // [sp+14h] [bp-Ch]@4
  InterfacePtr<PlayerDesc> playerDesc; // [sp+18h] [bp-8h]@2

  v2 = this;
  if ( i_bVisible )
  {
    *(_DWORD *)&i_bVisible = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &PlayerDesc_ClassType_0, (Interface **)&i_bVisible);
    v4 = i_bVisible;
    v9 = i_bVisible;
    playerDesc.m_pInterface = 0;
    playerDesc.m_trStatus.m_val = 0;
    if ( i_bVisible )
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)i_bVisible + 16))(i_bVisible);
    v5 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v9, 0);
    if ( v4 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    v6 = playerDesc.m_pInterface;
    if ( (_DWORD)playerDesc.m_pInterface )
    {
      if ( v5 >= 0 )
      {
        if ( !v2->m_bAwaitingUpdate )
        {
          v2->m_bAwaitingUpdate = 1;
          v7 = ClientUISystem::GetUISystem();
          ClientUISystem::IncrementBusyCount(v7);
        }
        CM_Allegiance::Event_UpdateRequest(1);
      }
      v6->vfptr->Release((Interface *)v6);
    }
  }
  else
  {
    if ( this->m_bAwaitingUpdate )
    {
      this->m_bAwaitingUpdate = 0;
      v8 = ClientUISystem::GetUISystem();
      ClientUISystem::DecrementBusyCount(v8);
    }
    CM_Allegiance::Event_UpdateRequest(0);
  }
}

//----- (00491330) --------------------------------------------------------  // acclient.c:204450
void __thiscall gmAllegianceUI::UpdatePlayerData(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  int v3; // edi@3
  PlayerDesc *v4; // ecx@5
  ClientAllegianceSystem *v5; // eax@7
  int v6; // edi@7
  int v7; // esi@10
  int v8; // edi@10
  int v9; // ecx@18
  PStringBase<unsigned short> *v10; // eax@18
  unsigned int v11; // edi@18
  int v12; // edx@20
  unsigned int v13; // edx@21
  PStringBase<unsigned short> *v14; // eax@21
  unsigned int v15; // edi@21
  int v16; // eax@23
  unsigned int v17; // edi@24
  int v18; // ecx@26
  PStringBase<unsigned short> *v19; // eax@26
  unsigned int v20; // edi@26
  int v21; // edx@28
  UIElement_Text *v22; // ebx@29
  IInputActionCallbackVtbl *v23; // eax@29
  AC1Legacy::PSRefBuffer<char> *v24; // edi@29
  ReferenceCountTemplate<268435456,0>Vtbl *v25; // edx@31
  int v26; // ecx@32
  PStringBase<unsigned short> *v27; // eax@32
  unsigned int v28; // edi@32
  int v29; // eax@34
  UIElement_Text *v30; // ebx@35
  IInputActionCallbackVtbl *v31; // edx@35
  AC1Legacy::PSRefBuffer<char> *v32; // edi@35
  ReferenceCountTemplate<268435456,0>Vtbl *v33; // eax@37
  AC1Legacy::PSRefBuffer<char> *v34; // edi@38
  ReferenceCountTemplate<268435456,0>Vtbl *v35; // edx@40
  __int64 v36; // [sp+0h] [bp-21Ch]@1
  AC1Legacy::PStringBase<char> strPlayerTitle; // [sp+18h] [bp-204h]@1
  TResult result; // [sp+1Ch] [bp-200h]@1
  AC1Legacy::PStringBase<char> strAllegianceName; // [sp+20h] [bp-1FCh]@10
  int iRankBuffed; // [sp+24h] [bp-1F8h]@24
  AllegianceProfile *allegianceProf; // [sp+28h] [bp-1F4h]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+2Ch] [bp-1F0h]@1
  CAllegianceData playerAllegianceData; // [sp+34h] [bp-1E8h]@10
  StringInfo siRank; // [sp+6Ch] [bp-1B0h]@26
  StringInfo siFollowers; // [sp+FCh] [bp-120h]@21
  StringInfo siName; // [sp+18Ch] [bp-90h]@18

  v1 = this;
  strPlayerTitle.m_buffer = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_0, (Interface **)&strPlayerTitle);
  v36 = 0i64;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  v3 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&allegianceProf, v36, SHIDWORD(v36));
  v4 = playerDesc.m_pInterface;
  if ( (_DWORD)playerDesc.m_pInterface )
  {
    if ( v3 >= 0 )
    {
      v5 = ClientAllegianceSystem::GetAllegianceSystem();
      v6 = (int)&v5->m_allegianceProfile;
      allegianceProf = (AllegianceProfile *)&v5->m_allegianceProfile.vfptr;
      if ( SmartBox::smartbox )
        strPlayerTitle.m_buffer = (AC1Legacy::PSRefBuffer<char> *)SmartBox::smartbox->player_id;
      else
        strPlayerTitle.m_buffer = 0;
      CAllegianceData::CAllegianceData(&playerAllegianceData);
      v7 = AC1Legacy::PStringBase<char>::s_NullBuffer;
      strAllegianceName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v8 = *(_DWORD *)(v6 + 44);
      InterlockedIncrement((volatile LONG *)(v8 + 4));
      if ( v7 != v8 )
      {
        if ( !InterlockedDecrement((volatile LONG *)&strAllegianceName.m_buffer->m_cRef) && strAllegianceName.m_buffer )
          ((void (__stdcall *)(signed int))strAllegianceName.m_buffer->vfptr->__vecDelDtor)(1);
        strAllegianceName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v8;
        InterlockedIncrement((volatile LONG *)(v8 + 4));
      }
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      StringInfo::StringInfo(&siName);
      StringInfo::SetStringIDandTableEnum(&siName, ID_Allegiance_CharacterName, 268435457);
      HIDWORD(v36) = v9;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v36 + 1, strAllegianceName.m_buffer->m_data);
      StringInfo::AddVariable_String(&siName, ID_Name_0, HIDWORD(v36));
      v10 = StringInfo::GetString(&siName, (PStringBase<unsigned short> *)&result, 0);
      UIElement_Text::SetText(v1->m_pAllegianceName, v10);
      v11 = result.m_val - 20;
      if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v11 )
      {
        v12 = *(_DWORD *)v11;
        HIDWORD(v36) = 1;
        (*(void (__thiscall **)(unsigned int, signed int))v12)(v11, 1);
      }
      StringInfo::StringInfo(&siFollowers);
      StringInfo::SetStringIDandTableEnum(&siFollowers, ID_Allegiance_Followers, 268435457);
      v13 = allegianceProf->_total_vassals;
      StringInfo::AddVariable_Int(&siFollowers, ID_Followers, (unsigned int)v36);
      v14 = StringInfo::GetString(&siFollowers, (PStringBase<unsigned short> *)&result, 0);
      UIElement_Text::SetText(v1->m_pPlayerFollowers, v14);
      v15 = result.m_val - 20;
      if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v15 )
      {
        v16 = *(_DWORD *)v15;
        HIDWORD(v36) = 1;
        (*(void (__thiscall **)(unsigned int, signed int))v16)(v15, 1);
      }
      AllegianceProfile::GetData(
        allegianceProf,
        (unsigned int)strPlayerTitle.m_buffer,
        (AllegianceData *)&playerAllegianceData.vfptr);
      v17 = playerAllegianceData._rank;
      iRankBuffed = 0;
      CBaseQualities::InqInt((CBaseQualities *)&playerDesc.m_pInterface->vfptr, 0x1Eu, &iRankBuffed, 0, 0);
      if ( iRankBuffed == -1 || iRankBuffed == v17 )
      {
        StringInfo::StringInfo(&siRank);
        StringInfo::SetStringIDandTableEnum(&siRank, ID_Allegiance_Rank, 268435457);
        strPlayerTitle.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
        AllegianceData::GetTitle((AllegianceData *)&playerAllegianceData.vfptr, &strPlayerTitle);
        HIDWORD(v36) = v26;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v36 + 1, strPlayerTitle.m_buffer->m_data);
        StringInfo::AddVariable_String(&siRank, ID_Title, HIDWORD(v36));
        StringInfo::AddVariable_Int(&siRank, ID_Rank, (signed int)v17);
        v27 = StringInfo::GetString(&siRank, (PStringBase<unsigned short> *)v36, 0);
        UIElement_Text::SetText(v1->m_pPlayerRank, v27);
        v28 = result.m_val - 20;
        if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v28 )
        {
          v29 = *(_DWORD *)v28;
          HIDWORD(v36) = 1;
          (*(void (__thiscall **)(unsigned int, signed int))v29)(v28, 1);
        }
        v30 = v1->m_pPlayerRank;
        v31 = v30->vfptr;
        HIDWORD(v36) = 1;
        v31[13].__vecDelDtor((IInputActionCallback *)v30, 1u);
        v32 = strPlayerTitle.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&strPlayerTitle.m_buffer->m_cRef) && v32 )
        {
          v33 = v32->vfptr;
          HIDWORD(v36) = 1;
          v33->__vecDelDtor(v32, 1);
        }
      }
      else
      {
        StringInfo::StringInfo(&siRank);
        StringInfo::SetStringIDandTableEnum(&siRank, ID_Allegiance_RankBuffed, 268435457);
        strPlayerTitle.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
        AllegianceData::GetTitle((AllegianceData *)&playerAllegianceData.vfptr, &strPlayerTitle);
        HIDWORD(v36) = v18;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v36 + 1, strPlayerTitle.m_buffer->m_data);
        StringInfo::AddVariable_String(&siRank, ID_Title, HIDWORD(v36));
        StringInfo::AddVariable_Int(&siRank, ID_Rank, iRankBuffed);
        HIDWORD(v36) = (unsigned __int64)(signed int)(iRankBuffed - v17) >> 32;
        StringInfo::AddVariable_Int(&siRank, ID_RankBuff, v36);
        v19 = StringInfo::GetString(&siRank, (PStringBase<unsigned short> *)v36, 0);
        UIElement_Text::SetText(v1->m_pPlayerRank, v19);
        v20 = result.m_val - 20;
        if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v20 )
        {
          v21 = *(_DWORD *)v20;
          HIDWORD(v36) = 1;
          (*(void (__thiscall **)(unsigned int, signed int))v21)(v20, 1);
        }
        v22 = v1->m_pPlayerRank;
        v23 = v22->vfptr;
        HIDWORD(v36) = 268435476;
        v23[13].__vecDelDtor((IInputActionCallback *)v22, 268435476u);
        v24 = strPlayerTitle.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&strPlayerTitle.m_buffer->m_cRef) && v24 )
        {
          v25 = v24->vfptr;
          HIDWORD(v36) = 1;
          v25->__vecDelDtor(v24, 1);
        }
      }
      StringInfo::~StringInfo(&siRank);
      StringInfo::~StringInfo(&siFollowers);
      StringInfo::~StringInfo(&siName);
      v34 = strAllegianceName.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&strAllegianceName.m_buffer->m_cRef) )
      {
        if ( v34 )
        {
          v35 = v34->vfptr;
          HIDWORD(v36) = 1;
          v35->__vecDelDtor(v34, 1);
        }
      }
      AllegianceData::~AllegianceData((AllegianceData *)&playerAllegianceData.vfptr);
      v4 = playerDesc.m_pInterface;
    }
    ((void (*)(void))v4->vfptr->Release)();
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004917C0) --------------------------------------------------------  // acclient.c:204656
void __thiscall gmAllegianceUI::UpdatePatronData(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // esi@1
  InterfaceSystem *v2; // eax@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  int v4; // ebp@3
  AllegianceProfile *v5; // ebp@8
  unsigned int v6; // eax@9
  unsigned int v7; // eax@11
  unsigned int v8; // edi@11
  int v9; // ecx@13
  PStringBase<unsigned short> *v10; // eax@13
  unsigned int v11; // edi@13
  int v12; // eax@15
  unsigned int v13; // eax@16
  UIElement *v14; // ecx@16
  IInputActionCallbackVtbl *v15; // edx@17
  IInputActionCallbackVtbl *v16; // eax@18
  unsigned int v17; // eax@20
  UIElement *v18; // eax@22
  IInputActionCallbackVtbl *v19; // edx@23
  UIElement_Text *v20; // esi@23
  PStringBase<unsigned short> *v21; // eax@25
  unsigned int v22; // esi@25
  int v23; // edx@27
  AC1Legacy::PSRefBuffer<char> *v24; // esi@28
  int v25; // eax@28
  ReferenceCountTemplate<268435456,0>Vtbl *v26; // edx@30
  char *v27; // esi@35
  int v28; // [sp-8h] [bp-1F4h]@1
  unsigned int v29; // [sp-8h] [bp-1F4h]@22
  int v30; // [sp-4h] [bp-1F0h]@1
  AC1Legacy::PStringBase<char> strPatronName; // [sp+10h] [bp-1DCh]@1
  TResult result; // [sp+14h] [bp-1D8h]@1
  unsigned int iidPatron; // [sp+18h] [bp-1D4h]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-1D0h]@1
  CAllegianceData patronAllegianceData; // [sp+24h] [bp-1C8h]@8
  CAllegianceData playerAllegianceData; // [sp+5Ch] [bp-190h]@19
  CAllegianceData monarchAllegianceData; // [sp+94h] [bp-158h]@8
  StringInfo siXPProduced; // [sp+CCh] [bp-120h]@22
  StringInfo siName; // [sp+15Ch] [bp-90h]@13

  v1 = this;
  strPatronName.m_buffer = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_0, (Interface **)&strPatronName);
  v28 = (int)strPatronName.m_buffer;
  v30 = 0;
  v3 = strPatronName.m_buffer;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( strPatronName.m_buffer )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))strPatronName.m_buffer->vfptr[4].__vecDelDtor)(strPatronName.m_buffer);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&iidPatron, v28, v30);
  if ( v3 )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))v3->vfptr[5].__vecDelDtor)(v3);
  if ( (_DWORD)playerDesc.m_pInterface )
  {
    if ( v4 >= 0 )
    {
      v5 = (AllegianceProfile *)&ClientAllegianceSystem::GetAllegianceSystem()->m_allegianceProfile.vfptr;
      CAllegianceData::CAllegianceData(&monarchAllegianceData);
      strPatronName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AllegianceProfile::GetMonarch(
                                                                 v5,
                                                                 (AllegianceData *)&monarchAllegianceData.vfptr);
      CAllegianceData::CAllegianceData(&patronAllegianceData);
      if ( SmartBox::smartbox )
        v6 = SmartBox::smartbox->player_id;
      else
        v6 = 0;
      v7 = AllegianceProfile::GetPatron(v5, v6, (AllegianceData *)&patronAllegianceData.vfptr);
      v8 = v7;
      iidPatron = v7;
      if ( v7 && (AC1Legacy::PSRefBuffer<char> *)v7 != strPatronName.m_buffer )
      {
        ((void (__stdcall *)(signed int))v1->m_pPatronField->vfptr[2].__vecDelDtor)(1);
        strPatronName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
        AllegianceData::GetFullName((AllegianceData *)&patronAllegianceData.vfptr, &strPatronName);
        StringInfo::StringInfo(&siName);
        StringInfo::SetStringIDandTableEnum(&siName, ID_Allegiance_CharacterName, 268435457);
        v30 = v9;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v30, strPatronName.m_buffer->m_data);
        StringInfo::AddVariable_String(&siName, ID_Name_0, (PStringBase<char>)v30);
        v10 = StringInfo::GetString(&siName, (PStringBase<unsigned short> *)&result, 0);
        UIElement_Text::SetText(v1->m_pPatronName, v10);
        v11 = result.m_val - 20;
        if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v11 )
        {
          v12 = *(_DWORD *)v11;
          v30 = 1;
          (*(void (__thiscall **)(unsigned int, signed int))v12)(v11, 1);
        }
        v13 = AllegianceData::IsLoggedIn((AllegianceData *)&patronAllegianceData.vfptr);
        v14 = v1->m_pPatronField;
        if ( v13 )
        {
          v15 = v14->vfptr;
          v30 = 1;
          ((void (__stdcall *)(signed int))v15[13].__vecDelDtor)(1);
        }
        else
        {
          v16 = v14->vfptr;
          v30 = 13;
          ((void (__stdcall *)(signed int))v16[13].__vecDelDtor)(13);
        }
        CAllegianceData::CAllegianceData(&playerAllegianceData);
        if ( SmartBox::smartbox )
          v17 = SmartBox::smartbox->player_id;
        else
          v17 = 0;
        AllegianceProfile::GetData(v5, v17, (AllegianceData *)&playerAllegianceData.vfptr);
        StringInfo::StringInfo(&siXPProduced);
        StringInfo::SetStringIDandTableEnum(&siXPProduced, ID_Allegiance_VassalExperiencePassedUp, 268435457);
        StringInfo::AddVariable_Int(&siXPProduced, ID_Value, v29);
        v18 = UIElement::GetChildRecursive(v1->m_pPatronField, 0x10000492u);
        if ( v18 )
        {
          v19 = v18->vfptr;
          v30 = 12;
          v20 = (UIElement_Text *)v19[12].OnAction((IInputActionCallback *)v18, (InputEvent *)12);
        }
        else
        {
          v20 = 0;
        }
        v21 = StringInfo::GetString(&siXPProduced, (PStringBase<unsigned short> *)&result, 0);
        UIElement_Text::SetText(v20, v21);
        v22 = result.m_val - 20;
        if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v22 )
        {
          v23 = *(_DWORD *)v22;
          v30 = 1;
          (*(void (__thiscall **)(unsigned int, signed int))v23)(v22, 1);
        }
        StringInfo::~StringInfo(&siXPProduced);
        AllegianceData::~AllegianceData((AllegianceData *)&playerAllegianceData.vfptr);
        StringInfo::~StringInfo(&siName);
        v24 = strPatronName.m_buffer;
        v25 = InterlockedDecrement((volatile LONG *)&strPatronName.m_buffer->m_cRef);
        if ( !v25 && v24 )
        {
          v26 = v24->vfptr;
          v30 = 1;
          v25 = v26->__vecDelDtor(v24, 1);
        }
        v8 = iidPatron;
      }
      else
      {
        ((void (__stdcall *)(_DWORD))v1->m_pPatronField->vfptr[2].__vecDelDtor)(0);
        PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&strPatronName, L" ");
        UIElement_Text::SetText(v1->m_pPatronName, (PStringBase<unsigned short> *)&strPatronName);
        v27 = (char *)&strPatronName.m_buffer[-1].m_cRef;
        v25 = InterlockedDecrement((volatile LONG *)&strPatronName.m_buffer[-1].m_cRef + 1);
        if ( !v25 && v27 )
          v25 = (**(int (__thiscall ***)(char *, signed int))v27)(v27, 1);
      }
      LOBYTE(v25) = v8 && (v25 = AllegianceData::IsLoggedIn((AllegianceData *)&patronAllegianceData.vfptr)) != 0;
      gmCCommunicationSystem::SetTalkFocusEnabled(4u, v25);
      AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
      AllegianceData::~AllegianceData((AllegianceData *)&monarchAllegianceData.vfptr);
      ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
    }
    else
    {
      ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00491B40) --------------------------------------------------------  // acclient.c:204830
void __thiscall gmAllegianceUI::UpdateMonarchData(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // esi@1
  InterfaceSystem *v2; // eax@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  int v4; // ebx@3
  char *v5; // ebx@8
  unsigned int v6; // edi@8
  unsigned int v7; // eax@9
  unsigned int v8; // eax@14
  PStringBase<unsigned short> *v9; // eax@17
  UIElement *v10; // edi@17
  unsigned int v11; // eax@18
  int v12; // edi@20
  PStringBase<unsigned short> *v13; // eax@20
  PStringBase<unsigned short> *v14; // eax@21
  UIElement *v15; // eax@21
  int v16; // ecx@22
  PStringBase<unsigned short> *v17; // eax@22
  char *v18; // edi@22
  int v19; // edx@24
  int v20; // ecx@25
  PStringBase<unsigned short> *v21; // eax@25
  char *v22; // edi@25
  int v23; // edx@27
  unsigned int v24; // eax@28
  UIElement *v25; // esi@28
  IInputActionCallbackVtbl *v26; // eax@29
  IInputActionCallbackVtbl *v27; // edx@30
  AC1Legacy::PSRefBuffer<char> *v28; // esi@31
  ReferenceCountTemplate<268435456,0>Vtbl *v29; // edx@33
  int v30; // eax@34
  char *v31; // edi@35
  char *v32; // esi@38
  int v33; // [sp-4h] [bp-314h]@1
  unsigned int v34; // [sp-4h] [bp-314h]@20
  unsigned int v35; // [sp-4h] [bp-314h]@25
  int v36; // [sp+0h] [bp-310h]@1
  AC1Legacy::PStringBase<char> strMonarchName; // [sp+14h] [bp-2FCh]@1
  PStringBase<unsigned short> result; // [sp+18h] [bp-2F8h]@3
  unsigned int iidMonarch; // [sp+1Ch] [bp-2F4h]@1
  InterfacePtr<PlayerDesc> playerDesc; // [sp+20h] [bp-2F0h]@1
  CAllegianceData monarchAllegianceData; // [sp+28h] [bp-2E8h]@8
  CAllegianceData playerAllegianceData; // [sp+60h] [bp-2B0h]@17
  StringInfo v43; // [sp+98h] [bp-278h]@17
  CAllegianceData patronAllegianceData; // [sp+128h] [bp-1E8h]@13
  StringInfo siFollowers; // [sp+160h] [bp-1B0h]@25
  StringInfo siName; // [sp+1F0h] [bp-120h]@22
  StringInfo siXPProduced; // [sp+280h] [bp-90h]@20

  v1 = this;
  strMonarchName.m_buffer = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, (TResult *)&iidMonarch, &PlayerDesc_ClassType_0, (Interface **)&strMonarchName);
  v33 = (int)strMonarchName.m_buffer;
  v36 = 0;
  v3 = strMonarchName.m_buffer;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( strMonarchName.m_buffer )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))strMonarchName.m_buffer->vfptr[4].__vecDelDtor)(strMonarchName.m_buffer);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&result, v33, v36);
  if ( v3 )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))v3->vfptr[5].__vecDelDtor)(v3);
  if ( (_DWORD)playerDesc.m_pInterface )
  {
    if ( v4 >= 0 )
    {
      v5 = (char *)&ClientAllegianceSystem::GetAllegianceSystem()->m_allegianceProfile;
      CAllegianceData::CAllegianceData(&monarchAllegianceData);
      v6 = AllegianceProfile::GetMonarch((AllegianceProfile *)v5, (AllegianceData *)&monarchAllegianceData.vfptr);
      iidMonarch = v6;
      if ( SmartBox::smartbox )
        v7 = SmartBox::smartbox->player_id;
      else
        v7 = 0;
      if ( v6 != v7 && v6 )
      {
        ((void (__stdcall *)(signed int))v1->m_pMonarchField->vfptr[2].__vecDelDtor)(1);
        CAllegianceData::CAllegianceData(&patronAllegianceData);
        if ( SmartBox::smartbox )
          v8 = SmartBox::smartbox->player_id;
        else
          v8 = 0;
        if ( AllegianceProfile::GetPatron((AllegianceProfile *)v5, v8, (AllegianceData *)&patronAllegianceData.vfptr) == v6 )
        {
          StringInfo::StringInfo(&v43);
          StringInfo::SetStringIDandTableEnum(&v43, ID_Allegiance_PatronSlashMonarchLabel, 268435457);
          v9 = StringInfo::GetString(&v43, &result, 0);
          UIElement_Text::SetText(v1->m_pMonarchLabel, v9);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          v10 = UIElement::GetChildRecursive(v1->m_pMonarchField, 0x10000490u);
          v10->vfptr[2].__vecDelDtor((IInputActionCallback *)v10, 1u);
          CAllegianceData::CAllegianceData(&playerAllegianceData);
          if ( SmartBox::smartbox )
            v11 = SmartBox::smartbox->player_id;
          else
            v11 = 0;
          AllegianceProfile::GetData((AllegianceProfile *)v5, v11, (AllegianceData *)&playerAllegianceData.vfptr);
          StringInfo::StringInfo(&siXPProduced);
          StringInfo::SetStringIDandTableEnum(&siXPProduced, ID_Allegiance_VassalExperiencePassedUp, 268435457);
          StringInfo::AddVariable_Int(&siXPProduced, ID_Value, v34);
          v12 = UIElement::GetChildRecursiveTemplate<UIElement_Text>(v10, 0x10000492u);
          v13 = StringInfo::GetString(&siXPProduced, &result, 0);
          UIElement_Text::SetText((UIElement_Text *)v12, v13);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          StringInfo::~StringInfo(&siXPProduced);
          AllegianceData::~AllegianceData((AllegianceData *)&playerAllegianceData.vfptr);
        }
        else
        {
          StringInfo::StringInfo(&v43);
          StringInfo::SetStringIDandTableEnum(&v43, ID_Allegiance_MonarchLabel, 268435457);
          v14 = StringInfo::GetString(&v43, &result, 0);
          UIElement_Text::SetText(v1->m_pMonarchLabel, v14);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          v15 = UIElement::GetChildRecursive(v1->m_pMonarchField, 0x10000490u);
          v15->vfptr[2].__vecDelDtor((IInputActionCallback *)v15, 0);
        }
        StringInfo::~StringInfo(&v43);
        strMonarchName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
        AllegianceData::GetFullName((AllegianceData *)&monarchAllegianceData.vfptr, &strMonarchName);
        StringInfo::StringInfo(&siName);
        StringInfo::SetStringIDandTableEnum(&siName, ID_Allegiance_CharacterName, 268435457);
        v36 = v16;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v36, strMonarchName.m_buffer->m_data);
        StringInfo::AddVariable_String(&siName, ID_Name_0, (PStringBase<char>)v36);
        v17 = StringInfo::GetString(&siName, &result, 0);
        UIElement_Text::SetText(v1->m_pMonarchName, v17);
        v18 = (char *)&result.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v18 )
        {
          v19 = *(_DWORD *)v18;
          v36 = 1;
          (*(void (__thiscall **)(char *, signed int))v19)(v18, 1);
        }
        StringInfo::StringInfo(&siFollowers);
        StringInfo::SetStringIDandTableEnum(&siFollowers, ID_Allegiance_Followers, 268435457);
        v20 = *((_DWORD *)v5 + 68) - 1;
        StringInfo::AddVariable_Int(&siFollowers, ID_Followers, v35);
        v21 = StringInfo::GetString(&siFollowers, &result, 0);
        UIElement_Text::SetText(v1->m_pMonarchFollowers, v21);
        v22 = (char *)&result.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v22 )
        {
          v23 = *(_DWORD *)v22;
          v36 = 1;
          (*(void (__thiscall **)(char *, signed int))v23)(v22, 1);
        }
        v24 = AllegianceData::IsLoggedIn((AllegianceData *)&monarchAllegianceData.vfptr);
        v25 = v1->m_pMonarchField;
        if ( v24 )
        {
          v26 = v25->vfptr;
          v36 = 1;
          v26[13].__vecDelDtor((IInputActionCallback *)v25, 1u);
        }
        else
        {
          v27 = v25->vfptr;
          v36 = 13;
          v27[13].__vecDelDtor((IInputActionCallback *)v25, 13u);
        }
        StringInfo::~StringInfo(&siFollowers);
        StringInfo::~StringInfo(&siName);
        v28 = strMonarchName.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&strMonarchName.m_buffer->m_cRef) && v28 )
        {
          v29 = v28->vfptr;
          v36 = 1;
          v29->__vecDelDtor(v28, 1);
        }
        AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
      }
      else
      {
        ((void (__stdcall *)(_DWORD))v1->m_pMonarchField->vfptr[2].__vecDelDtor)(0);
        PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&strMonarchName, L" ");
        UIElement_Text::SetText(v1->m_pMonarchName, (PStringBase<unsigned short> *)&strMonarchName);
        v31 = (char *)&strMonarchName.m_buffer[-1].m_cRef;
        if ( !InterlockedDecrement((volatile LONG *)&strMonarchName.m_buffer[-1].m_cRef + 1) && v31 )
          (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
        PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&strMonarchName, L" ");
        UIElement_Text::SetText(v1->m_pMonarchFollowers, (PStringBase<unsigned short> *)&strMonarchName);
        v32 = (char *)&strMonarchName.m_buffer[-1].m_cRef;
        v30 = InterlockedDecrement((volatile LONG *)&strMonarchName.m_buffer[-1].m_cRef + 1);
        if ( !v30 && v32 )
          v30 = (**(int (__thiscall ***)(char *, signed int))v32)(v32, 1);
      }
      LOBYTE(v30) = iidMonarch
                 && (!SmartBox::smartbox ? (v30 = 0) : (v30 = SmartBox::smartbox->player_id),
                     iidMonarch != v30
                  && (v30 = AllegianceData::IsLoggedIn((AllegianceData *)&monarchAllegianceData.vfptr)) != 0);
      gmCCommunicationSystem::SetTalkFocusEnabled(5u, v30);
      AllegianceData::~AllegianceData((AllegianceData *)&monarchAllegianceData.vfptr);
      ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
    }
    else
    {
      ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00492050) --------------------------------------------------------  // acclient.c:205037
void __thiscall gmAllegianceUI::RecvNotice_EnchantmentsChanged(gmAllegianceUI *this)
{
  gmAllegianceUI::UpdatePlayerData((gmAllegianceUI *)((char *)this - 1528));
}

//----- (00492060) --------------------------------------------------------  // acclient.c:205043
void __thiscall gmAllegianceUI::RecvNotice_CloseDialog(gmAllegianceUI *this, unsigned int context, PropertyCollection *data)
{
  PropertyCollection *v3; // esi@1
  unsigned int v4; // edx@1
  HashTableData<unsigned long,BaseProperty> **v5; // eax@1
  gmAllegianceUI *v6; // edi@1
  HashTableData<unsigned long,BaseProperty> *v7; // eax@1
  unsigned int v8; // edx@9
  HashTableData<unsigned long,BaseProperty> **v9; // ecx@9
  HashTableData<unsigned long,BaseProperty> *v10; // eax@9
  bool v11; // zf@17
  int v12; // ecx@27
  int v13; // edx@27
  int v14; // ecx@31
  int v15; // edx@31
  BasePropertyDesc *v16; // ecx@34
  unsigned int v17; // edx@34
  BasePropertyValue *v18; // ecx@38
  unsigned int v19; // edx@38
  unsigned int type; // [sp+Ch] [bp-14h]@1
  int v21; // [sp+10h] [bp-10h]@9
  int v22; // [sp+14h] [bp-Ch]@9
  BaseProperty p; // [sp+18h] [bp-8h]@1

  v3 = data;
  v4 = 0x8E % data->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v5 = data->m_hashProperties.m_intrusiveTable.m_buckets;
  type = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v6 = this;
  v7 = v5[v4];
  if ( v7 )
  {
    while ( v7->m_hashKey != 142 )
    {
      v7 = v7->m_hashNext;
      if ( !v7 )
        goto LABEL_8;
    }
    if ( v7 )
    {
      BaseProperty::operator=(&p, (int)&v7->m_data);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&type);
    }
  }
LABEL_8:
  if ( type == 1 )
  {
    v8 = 0x92 % v3->m_hashProperties.m_intrusiveTable.m_numBuckets;
    v9 = v3->m_hashProperties.m_intrusiveTable.m_buckets;
    LOBYTE(data) = 0;
    v21 = 0;
    v22 = 0;
    v10 = v9[v8];
    if ( v10 )
    {
      while ( v10->m_hashKey != 146 )
      {
        v10 = v10->m_hashNext;
        if ( !v10 )
          goto LABEL_16;
      }
      if ( v10 )
      {
        BaseProperty::operator=(&v21, (int)&v10->m_data);
        if ( v22 )
          (*(void (__stdcall **)(PropertyCollection **))(*(_DWORD *)v22 + 112))(&data);
      }
    }
LABEL_16:
    if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[17] == (HashSetData<UIElement *> *)context )
    {
      v11 = (_BYTE)data == 0;
      v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[17] = 0;
      if ( !v11 )
        CM_Allegiance::Event_SwearAllegiance((unsigned int)v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]);
      v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = 0;
    }
    else if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[18] == (HashSetData<UIElement *> *)context )
    {
      gmAllegianceUI::CloseAcceptSwearConfirmationDialog((gmAllegianceUI *)((char *)v6 - 1528), (bool)data);
    }
    else if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[19] == (HashSetData<UIElement *> *)context )
    {
      gmAllegianceUI::CloseBreakConfirmationDialog((gmAllegianceUI *)((char *)v6 - 1528), (bool)data);
    }
    else if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[20] == (HashSetData<UIElement *> *)context )
    {
      gmAllegianceUI::CloseKickConfirmationDialog((gmAllegianceUI *)((char *)v6 - 1528), (bool)data);
    }
    if ( v21 )
    {
      v12 = v21;
      v13 = *(_DWORD *)(v21 + 4) - 1;
      *(_DWORD *)(v21 + 4) = v13;
      if ( !v13 )
        (**(void (__stdcall ***)(_DWORD))v12)(1);
      v21 = 0;
    }
    if ( v22 )
    {
      v14 = v22;
      v15 = *(_DWORD *)(v22 + 4) - 1;
      *(_DWORD *)(v22 + 4) = v15;
      if ( !v15 )
        (**(void (__stdcall ***)(_DWORD))v14)(1);
    }
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v16 = p.m_pcPropertyDesc;
    v17 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v17;
    if ( !v17 )
      ((void (__stdcall *)(signed int))v16->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v18 = p.m_pcPropertyValue;
    v19 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v19;
    if ( !v19 )
      ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
  }
}

//----- (00492220) --------------------------------------------------------  // acclient.c:205173
void __stdcall gmAllegianceUI::RecvNotice_AllegianceLogin(unsigned int i_iidMember, bool i_bNowLoggedIn)
{
  ClientAllegianceSystem *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // ebx@3
  int v5; // esi@6
  int v6; // eax@6
  ClientSystem *v7; // esi@11
  int v8; // esi@11
  CAllegianceData member_data; // [sp+Ch] [bp-38h]@1

  v3 = ClientAllegianceSystem::GetAllegianceSystem();
  CAllegianceData::CAllegianceData(&member_data);
  if ( AllegianceProfile::GetData(
         (AllegianceProfile *)&v3->m_allegianceProfile.vfptr,
         i_iidMember,
         (AllegianceData *)&member_data.vfptr) )
  {
    v4 = member_data._name.m_buffer;
    i_iidMember = (unsigned int)member_data._name.m_buffer;
    InterlockedIncrement((volatile LONG *)&member_data._name.m_buffer->m_cRef);
    if ( i_bNowLoggedIn )
      AC1Legacy::PStringBase<char>::PStringBase<char>(
        (AC1Legacy::PStringBase<char> *)&i_bNowLoggedIn,
        " is logged in.\n");
    else
      AC1Legacy::PStringBase<char>::PStringBase<char>(
        (AC1Legacy::PStringBase<char> *)&i_bNowLoggedIn,
        " has logged out.\n");
    v5 = i_bNowLoggedIn;
    v6 = *(_DWORD *)(i_bNowLoggedIn + 8);
    if ( v6 != 1 && i_bNowLoggedIn != AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      AC1Legacy::PStringBase<char>::append_n_chars(
        (AC1Legacy::PStringBase<char> *)&i_iidMember,
        (const char *)(i_bNowLoggedIn + 20),
        v6 - 1);
      v4 = (AC1Legacy::PSRefBuffer<char> *)i_iidMember;
    }
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v7 = (ClientSystem *)ClientUISystem::GetUISystem();
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&i_bNowLoggedIn,
      0,
      v4->m_data);
    ClientSystem::AddTextToScroll(v7, (PStringBase<unsigned short> *)&i_bNowLoggedIn, 0, 1, 0);
    v8 = i_bNowLoggedIn - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_bNowLoggedIn - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    }
    AllegianceData::~AllegianceData((AllegianceData *)&member_data.vfptr);
  }
  else
  {
    AllegianceData::~AllegianceData((AllegianceData *)&member_data.vfptr);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00492340) --------------------------------------------------------  // acclient.c:205237
void __thiscall gmAllegianceUI::UpdateVassalsData(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // ebp@1
  InterfaceSystem *v2; // eax@1
  unsigned int v3; // esi@1
  int v4; // edi@3
  ClientAllegianceSystem *v5; // eax@8
  UIElement_ListBox *v6; // ecx@8
  AllegianceProfile *v7; // esi@8
  unsigned int v8; // eax@9
  unsigned int v9; // esi@11
  int v10; // eax@14
  UIElement *v11; // edi@14
  UIElement *v12; // eax@15
  UIElement_Text *v13; // esi@16
  PStringBase<unsigned short> *v14; // eax@17
  char *v15; // esi@17
  UIElement *v16; // eax@20
  UIElement_Text *v17; // esi@21
  PStringBase<unsigned short> *v18; // eax@22
  char *v19; // esi@22
  UIElement *v20; // eax@25
  int v21; // esi@26
  AC1Legacy::PSRefBuffer<char> *v22; // esi@30
  AC1Legacy::PSRefBuffer<char> *v23; // esi@36
  LONG v24; // eax@36
  int v25; // [sp+4h] [bp-104h]@1
  unsigned int iidVassal; // [sp+1Ch] [bp-ECh]@1
  AC1Legacy::PStringBase<char> strVassalName; // [sp+20h] [bp-E8h]@17
  int vassals_on; // [sp+24h] [bp-E4h]@8
  PStringBase<unsigned short> result; // [sp+28h] [bp-E0h]@3
  AllegianceProfile *allegianceProf; // [sp+2Ch] [bp-DCh]@1
  InterfacePtr<PlayerDesc> playerDesc; // [sp+30h] [bp-D8h]@1
  PStringBase<unsigned short> v32; // [sp+38h] [bp-D0h]@17
  gmAllegianceUI *v33; // [sp+3Ch] [bp-CCh]@1
  CAllegianceData vassalAllegianceData; // [sp+40h] [bp-C8h]@8
  StringInfo siXPProduced; // [sp+78h] [bp-90h]@22

  v1 = this;
  v33 = this;
  iidVassal = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, (TResult *)&allegianceProf, &PlayerDesc_ClassType_0, (Interface **)&iidVassal);
  v25 = iidVassal;
  v3 = iidVassal;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( iidVassal )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)iidVassal + 16))(iidVassal);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&result, v25, 0);
  if ( v3 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 20))(v3);
  if ( !(_DWORD)playerDesc.m_pInterface )
    return;
  if ( v4 < 0 )
  {
    ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
    return;
  }
  v5 = ClientAllegianceSystem::GetAllegianceSystem();
  v6 = v1->m_pVassalListBox;
  v7 = (AllegianceProfile *)&v5->m_allegianceProfile.vfptr;
  allegianceProf = (AllegianceProfile *)&v5->m_allegianceProfile.vfptr;
  UIElement_ListBox::Flush(v6);
  v1->m_iidSelectedVassal = 0;
  LOBYTE(vassals_on) = 0;
  CAllegianceData::CAllegianceData(&vassalAllegianceData);
  if ( SmartBox::smartbox )
    v8 = SmartBox::smartbox->player_id;
  else
    v8 = 0;
  v9 = AllegianceProfile::GetFirstVassal(v7, v8, (AllegianceData *)&vassalAllegianceData.vfptr);
  iidVassal = v9;
  if ( !v9 )
    goto LABEL_41;
  while ( 1 )
  {
    if ( AllegianceData::IsLoggedIn((AllegianceData *)&vassalAllegianceData.vfptr) )
      LOBYTE(vassals_on) = 1;
    v10 = UIElement_ListBox::AddItemFromTemplateList(v33->m_pVassalListBox, 0, 0);
    v11 = (UIElement *)v10;
    if ( !v10 )
      goto LABEL_34;
    UIElement::SetAttribute_InstanceID((UIElement *)v10, 0x10000001u, v9);
    v12 = UIElement::GetChildRecursive(v11, 0x10000268u);
    if ( !v12 )
      goto LABEL_41;
    v13 = (UIElement_Text *)v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
    if ( !v13 )
      goto LABEL_41;
    strVassalName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AllegianceData::GetFullName((AllegianceData *)&vassalAllegianceData.vfptr, &strVassalName);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v32, 0, strVassalName.m_buffer->m_data);
    UIElement_Text::SetText(v13, v14);
    v15 = (char *)&v32.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v32.m_charbuffer[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
    v16 = UIElement::GetChildRecursive(v11, 0x10000269u);
    if ( !v16 || (v17 = (UIElement_Text *)v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)12)) == 0 )
    {
      v23 = strVassalName.m_buffer;
      v24 = InterlockedDecrement((volatile LONG *)&strVassalName.m_buffer->m_cRef);
      goto LABEL_38;
    }
    StringInfo::StringInfo(&siXPProduced);
    StringInfo::SetStringIDandTableEnum(&siXPProduced, ID_Allegiance_VassalExperiencePassedUp, 268435457);
    StringInfo::AddVariable_Int(&siXPProduced, ID_Value, vassalAllegianceData._cp_tithed);
    v18 = StringInfo::GetString(&siXPProduced, &result, 0);
    UIElement_Text::SetText(v17, v18);
    v19 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v19 )
      (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
    v20 = UIElement::GetChildRecursive(v11, 0x100004AAu);
    if ( !v20 )
      break;
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)12);
    if ( !v21 )
      break;
    if ( AllegianceData::IsLoggedIn((AllegianceData *)&vassalAllegianceData.vfptr) )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v21 + 24))(v21, 0);
    else
      (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v21 + 24))(v21, 1);
    iidVassal = AllegianceProfile::GetNextVassal(
                  allegianceProf,
                  iidVassal,
                  (AllegianceData *)&vassalAllegianceData.vfptr);
    StringInfo::~StringInfo(&siXPProduced);
    v22 = strVassalName.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strVassalName.m_buffer->m_cRef) )
    {
      if ( v22 )
        v22->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v22, 1u);
    }
    v9 = iidVassal;
LABEL_34:
    if ( !v9 )
      goto LABEL_41;
  }
  StringInfo::~StringInfo(&siXPProduced);
  v23 = strVassalName.m_buffer;
  v24 = InterlockedDecrement((volatile LONG *)&strVassalName.m_buffer->m_cRef);
LABEL_38:
  if ( !v24 && v23 )
    v23->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v23, 1u);
LABEL_41:
  gmCCommunicationSystem::SetTalkFocusEnabled(6u, vassals_on);
  AllegianceData::~AllegianceData((AllegianceData *)&vassalAllegianceData.vfptr);
  ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00492670) --------------------------------------------------------  // acclient.c:205390
void __thiscall gmAllegianceUI::Update(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // esi@1
  ClientUISystem *v2; // eax@2
  InterfaceSystem *v3; // eax@3
  Interface *v4; // edi@3
  int v5; // ebp@5
  PlayerDesc *v6; // edi@7
  UIElement_Button *v7; // ecx@10
  int v8; // [sp-8h] [bp-2Ch]@3
  Interface *_rpInterface; // [sp+10h] [bp-14h]@3
  TResult result; // [sp+14h] [bp-10h]@3
  char v11; // [sp+18h] [bp-Ch]@5
  InterfacePtr<PlayerDesc> playerDesc; // [sp+1Ch] [bp-8h]@3

  v1 = this;
  if ( this->m_bAwaitingUpdate )
  {
    this->m_bAwaitingUpdate = 0;
    v2 = ClientUISystem::GetUISystem();
    ClientUISystem::DecrementBusyCount(v2);
  }
  _rpInterface = 0;
  v3 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v3, &result, &PlayerDesc_ClassType_0, &_rpInterface);
  v4 = _rpInterface;
  v8 = (int)_rpInterface;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v5 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&v11, v8, 0);
  if ( v4 )
    v4->vfptr->Release(v4);
  v6 = playerDesc.m_pInterface;
  if ( (_DWORD)playerDesc.m_pInterface )
  {
    if ( v5 >= 0 )
    {
      gmAllegianceUI::UpdatePlayerData(v1);
      gmAllegianceUI::UpdateMonarchData(v1);
      gmAllegianceUI::UpdatePatronData(v1);
      gmAllegianceUI::UpdateVassalsData(v1);
      gmAllegianceUI::UpdateSwearButton(v1);
      gmAllegianceUI::UpdateBreakButton(v1);
      v7 = v1->m_pKickButton;
      if ( v1->m_iidSelectedVassal )
      {
        ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(1);
        v6->vfptr->Release((Interface *)v6);
      }
      else
      {
        ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(13);
        v6->vfptr->Release((Interface *)v6);
      }
    }
    else
    {
      playerDesc.m_pInterface->vfptr->Release((Interface *)playerDesc.m_pInterface);
    }
  }
}

//----- (00492780) --------------------------------------------------------  // acclient.c:205455
void __thiscall gmAllegianceUI::RecvNotice_AllegianceUpdate(gmAllegianceUI *this, CAllegianceProfile *i_prof, unsigned int i_uiRank)
{
  gmAllegianceUI::Update((gmAllegianceUI *)((char *)this - 1528));
}

//----- (00492790) --------------------------------------------------------  // acclient.c:205461
void __thiscall gmAllegianceUI::RecvNotice_AllegianceUpdateAborted(gmAllegianceUI *this, unsigned int i_etype)
{
  if ( LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr) )
    gmAllegianceUI::Update((gmAllegianceUI *)((char *)this - 1528));
}

//----- (004927B0) --------------------------------------------------------  // acclient.c:205468
char __thiscall gmAllegianceUI::MakeSwearConfirmationDialog(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // edi@1
  char *v2; // eax@2
  AC1Legacy::PSRefBuffer<char> *v3; // esi@2
  PSRefBufferCharData<char> *v4; // ecx@3
  ReferenceCountTemplate<1048576,1>Vtbl *v5; // edx@4
  ReferenceCountTemplate<1048576,1>Vtbl *v6; // edx@6
  unsigned __int32 v7; // eax@7
  ReferenceCountTemplate<268435456,0>Vtbl *v8; // edx@10
  ReferenceCountTemplate<268435456,0>Vtbl *v10; // edx@13
  PStringBase<char> v11; // [sp-4h] [bp-120h]@3
  BaseProperty p; // [sp+8h] [bp-114h]@3
  AC1Legacy::PStringBase<char> strCharName; // [sp+10h] [bp-10Ch]@2
  PropertyCollection pc; // [sp+14h] [bp-108h]@3
  StringInfo info; // [sp+8Ch] [bp-90h]@3

  v1 = this;
  if ( this->m_swearContext )
    return 0;
  v2 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)ACCWeenieObject::selectedID, 2u, 0);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&strCharName, v2);
  v3 = strCharName.m_buffer;
  if ( strCharName.m_buffer->m_len == 1 )
  {
LABEL_9:
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    {
      v8 = v3->vfptr;
      v11.m_charbuffer = (PSRefBufferCharData<char> *)1;
      v8->__vecDelDtor(v3, 1);
    }
    return 0;
  }
  StringInfo::StringInfo(&info);
  StringInfo::SetStringIDandTableEnum(&info, ID_Allegiance_SwearConfirmation, 268435457);
  v11.m_charbuffer = v4;
  PStringBase<char>::PStringBase<char>(&v11, v3->m_data);
  StringInfo::AddVariable_String(&info, ID_Player_0, v11);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    v5 = p.m_pcPropertyValue->vfptr;
    v11.m_charbuffer = (PSRefBufferCharData<char> *)1;
    ((void (__stdcall *)(signed int))v5[43].__vecDelDtor)(1);
  }
  strCharName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&strCharName,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    v6 = p.m_pcPropertyValue->vfptr;
    v11.m_charbuffer = (PSRefBufferCharData<char> *)&info;
    ((void (__stdcall *)(StringInfo *))v6[49].__vecDelDtor)(&info);
  }
  strCharName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    (const unsigned int *)&strCharName,
    &p);
  v7 = DialogFactory::MakeDialogInCurrentUI(&pc);
  v1->m_swearContext = v7;
  if ( !v7 )
  {
    BaseProperty::~BaseProperty(&p);
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&info);
    goto LABEL_9;
  }
  v1->m_iidPossibleNewPatron = ACCWeenieObject::selectedID;
  BaseProperty::~BaseProperty(&p);
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&info);
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
  {
    v10 = v3->vfptr;
    v11.m_charbuffer = (PSRefBufferCharData<char> *)1;
    v10->__vecDelDtor(v3, 1);
  }
  return 1;
}

//----- (00492990) --------------------------------------------------------  // acclient.c:205559
char __thiscall gmAllegianceUI::MakeAcceptSwearConfirmationDialog(gmAllegianceUI *this, PStringBase<char> i_strRequestor, unsigned int i_uiServerContextID)
{
  gmAllegianceUI *v3; // esi@1
  char *v4; // esi@2
  PSRefBufferCharData<char> *v5; // ecx@3
  ReferenceCountTemplate<1048576,1>Vtbl *v6; // edx@4
  ReferenceCountTemplate<1048576,1>Vtbl *v7; // edx@6
  unsigned __int32 v8; // eax@7
  BasePropertyDesc *v9; // ecx@9
  unsigned int v10; // esi@9
  ReferenceCountTemplate<1048576,1>Vtbl *v11; // edx@10
  BasePropertyValue *v12; // ecx@13
  unsigned int v13; // edx@13
  ReferenceCountTemplate<1048576,1>Vtbl *v14; // eax@14
  int v15; // edx@19
  BasePropertyDesc *v17; // ecx@22
  unsigned int v18; // esi@22
  ReferenceCountTemplate<1048576,1>Vtbl *v19; // edx@23
  BasePropertyValue *v20; // ecx@26
  unsigned int v21; // edx@26
  ReferenceCountTemplate<1048576,1>Vtbl *v22; // eax@27
  int v23; // edx@31
  PStringBase<char> v24; // [sp-4h] [bp-124h]@2
  BaseProperty p; // [sp+Ch] [bp-114h]@3
  unsigned int _key; // [sp+14h] [bp-10Ch]@5
  PropertyCollection pc; // [sp+18h] [bp-108h]@3
  StringInfo info; // [sp+90h] [bp-90h]@3

  v3 = this;
  if ( this->m_acceptSwearContext )
  {
    v4 = &i_strRequestor.m_charbuffer[-2].m_data[12];
    v24.m_charbuffer = i_strRequestor.m_charbuffer - 1;
LABEL_17:
    if ( !InterlockedDecrement((volatile LONG *)v24.m_charbuffer) )
    {
      if ( v4 )
      {
        v15 = *(_DWORD *)v4;
        v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char *, signed int))v15)(v4, 1);
      }
    }
    return 0;
  }
  StringInfo::StringInfo(&info);
  StringInfo::SetStringIDandTableEnum(&info, ID_Allegiance_AcceptSwearConfirmation, 268435457);
  v24.m_charbuffer = v5;
  PStringBase<char>::PStringBase<char>(&v24, i_strRequestor.m_charbuffer->m_data);
  StringInfo::AddVariable_String(&info, ID_Player_0, v24);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    v6 = p.m_pcPropertyValue->vfptr;
    v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
    ((void (__stdcall *)(signed int))v6[43].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    v7 = p.m_pcPropertyValue->vfptr;
    v24.m_charbuffer = (PSRefBufferCharData<char> *)&info;
    ((void (__stdcall *)(StringInfo *))v7[49].__vecDelDtor)(&info);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  v8 = DialogFactory::MakeDialogInCurrentUI(&pc);
  v3->m_acceptSwearContext = v8;
  if ( !v8 )
  {
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v9 = p.m_pcPropertyDesc;
      v10 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v10;
      if ( !v10 )
      {
        v11 = v9->vfptr;
        v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
        ((void (__stdcall *)(signed int))v11->__vecDelDtor)(1);
      }
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v12 = p.m_pcPropertyValue;
      v13 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v13;
      if ( !v13 )
      {
        v14 = v12->vfptr;
        v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
        ((void (__stdcall *)(signed int))v14->__vecDelDtor)(1);
      }
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&info);
    v4 = &i_strRequestor.m_charbuffer[-2].m_data[12];
    v24.m_charbuffer = i_strRequestor.m_charbuffer - 1;
    goto LABEL_17;
  }
  v3->m_uiAcceptSwearServerContextID = i_uiServerContextID;
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v17 = p.m_pcPropertyDesc;
    v18 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v18;
    if ( !v18 )
    {
      v19 = v17->vfptr;
      v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
      ((void (__stdcall *)(signed int))v19->__vecDelDtor)(1);
    }
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v20 = p.m_pcPropertyValue;
    v21 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v21;
    if ( !v21 )
    {
      v22 = v20->vfptr;
      v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
      ((void (__stdcall *)(signed int))v22->__vecDelDtor)(1);
    }
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&info);
  if ( !InterlockedDecrement((volatile LONG *)&i_strRequestor.m_charbuffer[-1])
    && i_strRequestor.m_charbuffer != (PSRefBufferCharData<char> *)20 )
  {
    v23 = *(_DWORD *)&i_strRequestor.m_charbuffer[-2].m_data[12];
    v24.m_charbuffer = (PSRefBufferCharData<char> *)1;
    (*(void (__thiscall **)(char *, signed int))v23)(&i_strRequestor.m_charbuffer[-2].m_data[12], 1);
  }
  return 1;
}

//----- (00492BF0) --------------------------------------------------------  // acclient.c:205714
char __thiscall gmAllegianceUI::MakeBreakConfirmationDialog(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // ebp@1
  AllegianceProfile *v2; // esi@2
  unsigned int v3; // eax@3
  AC1Legacy::PSRefBuffer<char> *v4; // esi@6
  volatile LONG *v5; // edi@6
  PSRefBufferCharData<char> *v7; // ecx@10
  ReferenceCountTemplate<1048576,1>Vtbl *v8; // edx@11
  ReferenceCountTemplate<1048576,1>Vtbl *v9; // edx@13
  unsigned __int32 v10; // eax@14
  PStringBase<char> v11; // [sp-4h] [bp-160h]@10
  BaseProperty p; // [sp+Ch] [bp-150h]@10
  unsigned int _key; // [sp+14h] [bp-148h]@12
  AC1Legacy::PStringBase<char> strCharName; // [sp+18h] [bp-144h]@6
  CAllegianceData patronAllegianceData; // [sp+1Ch] [bp-140h]@2
  PropertyCollection pc; // [sp+54h] [bp-108h]@10
  StringInfo info; // [sp+CCh] [bp-90h]@10

  v1 = this;
  if ( this->m_breakContext )
    return 0;
  v2 = (AllegianceProfile *)&ClientAllegianceSystem::GetAllegianceSystem()->m_allegianceProfile.vfptr;
  CAllegianceData::CAllegianceData(&patronAllegianceData);
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  if ( !AllegianceProfile::GetPatron(v2, v3, (AllegianceData *)&patronAllegianceData.vfptr) )
  {
LABEL_16:
    AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
    return 0;
  }
  v4 = patronAllegianceData._name.m_buffer;
  v5 = (volatile LONG *)&patronAllegianceData._name.m_buffer->m_cRef;
  strCharName.m_buffer = patronAllegianceData._name.m_buffer;
  InterlockedIncrement((volatile LONG *)&patronAllegianceData._name.m_buffer->m_cRef);
  if ( v4->m_len != 1 )
  {
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_Allegiance_BreakConfirmation, 268435457);
    v11.m_charbuffer = v7;
    PStringBase<char>::PStringBase<char>(&v11, v4->m_data);
    StringInfo::AddVariable_String(&info, ID_Player_0, v11);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      v8 = p.m_pcPropertyValue->vfptr;
      v11.m_charbuffer = (PSRefBufferCharData<char> *)1;
      ((void (__stdcall *)(signed int))v8[43].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      v9 = p.m_pcPropertyValue->vfptr;
      v11.m_charbuffer = (PSRefBufferCharData<char> *)&info;
      ((void (__stdcall *)(StringInfo *))v9[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v10 = DialogFactory::MakeDialogInCurrentUI(&pc);
    v1->m_breakContext = v10;
    if ( v10 )
    {
      BaseProperty::~BaseProperty(&p);
      PropertyCollection::~PropertyCollection(&pc);
      StringInfo::~StringInfo(&info);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&strCharName);
      AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
      return 1;
    }
    BaseProperty::~BaseProperty(&p);
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&info);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&strCharName);
    goto LABEL_16;
  }
  if ( !InterlockedDecrement(v5) )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  AllegianceData::~AllegianceData((AllegianceData *)&patronAllegianceData.vfptr);
  return 0;
}

//----- (00492E10) --------------------------------------------------------  // acclient.c:205812
char __thiscall gmAllegianceUI::MakeKickConfirmationDialog(gmAllegianceUI *this)
{
  gmAllegianceUI *v1; // ebx@1
  ClientAllegianceSystem *v2; // esi@2
  AC1Legacy::PSRefBuffer<char> *v3; // esi@3
  volatile LONG *v4; // edi@3
  PSRefBufferCharData<char> *v6; // ecx@7
  ReferenceCountTemplate<1048576,1>Vtbl *v7; // edx@8
  ReferenceCountTemplate<1048576,1>Vtbl *v8; // edx@10
  unsigned __int32 v9; // eax@11
  PStringBase<char> v10; // [sp-4h] [bp-160h]@7
  BaseProperty p; // [sp+Ch] [bp-150h]@7
  unsigned int _key; // [sp+14h] [bp-148h]@9
  AC1Legacy::PStringBase<char> strCharName; // [sp+18h] [bp-144h]@3
  CAllegianceData vassalAllegianceData; // [sp+1Ch] [bp-140h]@2
  PropertyCollection pc; // [sp+54h] [bp-108h]@7
  StringInfo info; // [sp+CCh] [bp-90h]@7

  v1 = this;
  if ( this->m_kickContext )
    return 0;
  v2 = ClientAllegianceSystem::GetAllegianceSystem();
  CAllegianceData::CAllegianceData(&vassalAllegianceData);
  if ( !AllegianceProfile::GetData(
          (AllegianceProfile *)&v2->m_allegianceProfile.vfptr,
          v1->m_iidSelectedVassal,
          (AllegianceData *)&vassalAllegianceData.vfptr) )
  {
LABEL_13:
    AllegianceData::~AllegianceData((AllegianceData *)&vassalAllegianceData.vfptr);
    return 0;
  }
  v3 = vassalAllegianceData._name.m_buffer;
  v4 = (volatile LONG *)&vassalAllegianceData._name.m_buffer->m_cRef;
  strCharName.m_buffer = vassalAllegianceData._name.m_buffer;
  InterlockedIncrement((volatile LONG *)&vassalAllegianceData._name.m_buffer->m_cRef);
  if ( v3->m_len != 1 )
  {
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_Allegiance_KickConfirmation, 268435457);
    v10.m_charbuffer = v6;
    PStringBase<char>::PStringBase<char>(&v10, v3->m_data);
    StringInfo::AddVariable_String(&info, ID_Player_0, v10);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      v7 = p.m_pcPropertyValue->vfptr;
      v10.m_charbuffer = (PSRefBufferCharData<char> *)1;
      ((void (__stdcall *)(signed int))v7[43].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      v8 = p.m_pcPropertyValue->vfptr;
      v10.m_charbuffer = (PSRefBufferCharData<char> *)&info;
      ((void (__stdcall *)(StringInfo *))v8[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v9 = DialogFactory::MakeDialogInCurrentUI(&pc);
    v1->m_kickContext = v9;
    if ( v9 )
    {
      v1->m_iidPossibleKickedVassal = v1->m_iidSelectedVassal;
      BaseProperty::~BaseProperty(&p);
      PropertyCollection::~PropertyCollection(&pc);
      StringInfo::~StringInfo(&info);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&strCharName);
      AllegianceData::~AllegianceData((AllegianceData *)&vassalAllegianceData.vfptr);
      return 1;
    }
    BaseProperty::~BaseProperty(&p);
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&info);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&strCharName);
    goto LABEL_13;
  }
  if ( !InterlockedDecrement(v4) )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  AllegianceData::~AllegianceData((AllegianceData *)&vassalAllegianceData.vfptr);
  return 0;
}

//----- (00493030) --------------------------------------------------------  // acclient.c:205909
UIElementMessageListenResult __thiscall gmAllegianceUI::ListenToElementMessage(gmAllegianceUI *this, UIElementMessageInfo *i_rMsg)
{
  gmAllegianceUI *v2; // esi@1
  UIElement_ListBox *v3; // edi@3
  unsigned int v4; // eax@3
  UIElement *v5; // eax@3
  int v6; // edi@3
  UIElement_Button *v7; // ecx@6
  UIElementMessageListenResult result; // eax@7

  v2 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 268436067 )
    {
      gmAllegianceUI::MakeSwearConfirmationDialog(this);
    }
    else
    {
      if ( i_rMsg->idElement == 268436068 )
      {
        gmAllegianceUI::MakeBreakConfirmationDialog(this);
        return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
      }
      if ( i_rMsg->idElement == 268436069 )
      {
        gmAllegianceUI::MakeKickConfirmationDialog(this);
        return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
      }
    }
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  if ( i_rMsg->idMessage != 4 )
    return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  v3 = this->m_pVassalListBox;
  v4 = UIElement_ListBox::GetSelectedIndex(this->m_pVassalListBox);
  v5 = UIElement_ListBox::GetItem(v3, v4);
  v6 = (int)&v2->m_iidSelectedVassal;
  if ( v5 )
    UIElement::GetAttribute_InstanceID(v5, 0x10000001u, &v2->m_iidSelectedVassal);
  else
    *(_DWORD *)v6 = 0;
  v7 = v2->m_pKickButton;
  if ( *(_DWORD *)v6 )
  {
    ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(1);
    result = UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  else
  {
    ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(13);
    result = UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  return result;
}

//----- (00493110) --------------------------------------------------------  // acclient.c:205966
void __thiscall gmAllegianceUI::RecvNotice_SwearAllegianceRequest(gmAllegianceUI *this, AC1Legacy::PStringBase<char> *i_strRequestor, unsigned int i_uiContext)
{
  AC1Legacy::PSRefBuffer<char> *v3; // eax@1
  gmAllegianceUI *v4; // esi@1
  unsigned int v5; // [sp-8h] [bp-Ch]@1
  unsigned int v6; // [sp-4h] [bp-8h]@1

  v3 = i_strRequestor->m_buffer;
  v4 = this;
  v6 = i_uiContext;
  v5 = i_uiContext;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v5, v3->m_data);
  gmAllegianceUI::MakeAcceptSwearConfirmationDialog((gmAllegianceUI *)((char *)v4 - 1528), (PStringBase<char>)v5, v6);
}

//----- (006EE520) --------------------------------------------------------  // acclient.c:770349
void _E91_56()
{
  outside_val_48 = 1000.0 + 1.0;
}

//----- (006EE540) --------------------------------------------------------  // acclient.c:770355
void _E93_32()
{
  block_length_48 = 24.0 * 8.0;
}

//----- (006EE560) --------------------------------------------------------  // acclient.c:770361
void _E95_32()
{
  half_square_length_48 = 24.0 * 0.5;
}

//----- (006EE580) --------------------------------------------------------  // acclient.c:770367
int _E97_57()
{
  return atexit(_E98_69);
}

//----- (006EE590) --------------------------------------------------------  // acclient.c:770373
int _E100_50()
{
  return atexit(_E101_87);
}

//----- (006EE5A0) --------------------------------------------------------  // acclient.c:770379
int _E103_42()
{
  return atexit(_E104_57);
}

//----- (006EE5B0) --------------------------------------------------------  // acclient.c:770385
void _E106_32()
{
  DEFAULT_VIEW_RADIUS_26 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EE5D0) --------------------------------------------------------  // acclient.c:770391
void _E108_23()
{
  MIN_QUANTUM_26 = 1.0 / 30.0;
}

//----- (006EE5F0) --------------------------------------------------------  // acclient.c:770397
void _E110_14()
{
  MAX_QUANTUM_26 = 1.0 / 5.0;
}

//----- (006EE610) --------------------------------------------------------  // acclient.c:770403
void _E112_28()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_61, PFID_A8R8G8B8);
}

//----- (006EE620) --------------------------------------------------------  // acclient.c:770409
void _E115_21()
{
  LOWEST_DATA_RATE_69 = 1024;
}

//----- (006EE630) --------------------------------------------------------  // acclient.c:770415
void _E117_18()
{
  HIGHEST_DATA_RATE_69 = 0x7FFF;
}

//----- (006EE640) --------------------------------------------------------  // acclient.c:770421
int _E119_7()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_69;
  INITIAL_MAX_DATA_RATE_17 = LOWEST_DATA_RATE_69;
  return result;
}

//----- (006EE650) --------------------------------------------------------  // acclient.c:770431
int _E121_28()
{
  return atexit(_E122_65);
}

//----- (006EE660) --------------------------------------------------------  // acclient.c:770437
int _E124_26()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_20, "Misc.TooltipEnable");
  return atexit(_E125_36);
}

//----- (006EE680) --------------------------------------------------------  // acclient.c:770444
int _E127_22()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_20, "Misc.TooltipDelay");
  return atexit(_E128_37);
}

//----- (006EE6A0) --------------------------------------------------------  // acclient.c:770451
unsigned int _E133_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_AcceptSwearConfirmation");
  ID_Allegiance_AcceptSwearConfirmation = result;
  return result;
}

//----- (006EE6C0) --------------------------------------------------------  // acclient.c:770461
unsigned int _E135_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_BreakConfirmation");
  ID_Allegiance_BreakConfirmation = result;
  return result;
}

//----- (006EE6E0) --------------------------------------------------------  // acclient.c:770471
unsigned int _E137_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_CharacterName");
  ID_Allegiance_CharacterName = result;
  return result;
}

//----- (006EE700) --------------------------------------------------------  // acclient.c:770481
unsigned int _E139_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_Followers");
  ID_Allegiance_Followers = result;
  return result;
}

//----- (006EE720) --------------------------------------------------------  // acclient.c:770491
unsigned int _E141_16()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_KickConfirmation");
  ID_Allegiance_KickConfirmation = result;
  return result;
}

//----- (006EE740) --------------------------------------------------------  // acclient.c:770501
unsigned int _E143_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_MonarchLabel");
  ID_Allegiance_MonarchLabel = result;
  return result;
}

//----- (006EE760) --------------------------------------------------------  // acclient.c:770511
unsigned int _E145_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_PatronSlashMonarchLabel");
  ID_Allegiance_PatronSlashMonarchLabel = result;
  return result;
}

//----- (006EE780) --------------------------------------------------------  // acclient.c:770521
unsigned int _E147_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_Rank");
  ID_Allegiance_Rank = result;
  return result;
}

//----- (006EE7A0) --------------------------------------------------------  // acclient.c:770531
unsigned int _E149_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_RankBuffed");
  ID_Allegiance_RankBuffed = result;
  return result;
}

//----- (006EE7C0) --------------------------------------------------------  // acclient.c:770541
unsigned int _E151_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_SwearConfirmation");
  ID_Allegiance_SwearConfirmation = result;
  return result;
}

//----- (006EE7E0) --------------------------------------------------------  // acclient.c:770551
unsigned int _E153_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Allegiance_VassalExperiencePassedUp");
  ID_Allegiance_VassalExperiencePassedUp = result;
  return result;
}

//----- (006EE800) --------------------------------------------------------  // acclient.c:770561
unsigned int _E155_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("NAME");
  ID_Name_0 = result;
  return result;
}

//----- (006EE820) --------------------------------------------------------  // acclient.c:770571
unsigned int _E157_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PLAYER");
  ID_Player_0 = result;
  return result;
}

//----- (006EE840) --------------------------------------------------------  // acclient.c:770581
unsigned int _E159_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("RANK");
  ID_Rank = result;
  return result;
}

//----- (006EE860) --------------------------------------------------------  // acclient.c:770591
unsigned int _E161_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("RANKBUFF");
  ID_RankBuff = result;
  return result;
}

//----- (006EE880) --------------------------------------------------------  // acclient.c:770601
unsigned int _E163_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("TITLE");
  ID_Title = result;
  return result;
}

//----- (006EE8A0) --------------------------------------------------------  // acclient.c:770611
unsigned int _E165_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("FOLLOWERS");
  ID_Followers = result;
  return result;
}

//----- (006EE8C0) --------------------------------------------------------  // acclient.c:770621
unsigned int _E167_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("VALUE");
  ID_Value = result;
  return result;
}

//----- (006EE8E0) --------------------------------------------------------  // acclient.c:770631
int sub_6EE8E0()
{
  return atexit(nullsub_895);
}

//----- (0075F8C0) --------------------------------------------------------  // acclient.c:887367
void __cdecl _E125_36()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F8F0) --------------------------------------------------------  // acclient.c:887380
void __cdecl _E128_37()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

