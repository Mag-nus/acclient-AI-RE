/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCharacterManagementUI
   Object     : GAME\game_ui_misc\gmCharacterManagementUI.obj
   Functions  : 46
   Addresses  : 004EBF60 - 006F74C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004EBF60) --------------------------------------------------------  // acclient.c:280837
void __thiscall gmCharacterManagementUI::RecvNotice_CharGenVerificationResponse(gmCharacterManagementUI *this, CG_VERIFICATION_RESPONSE i_rsvp)
{
  gmCharacterManagementUI *v2; // esi@1
  unsigned int v3; // ecx@4
  StringInfo siError; // [sp+4h] [bp-90h]@4

  v2 = this;
  DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9]);
  if ( i_rsvp == 3 )
  {
    StringInfo::StringInfo(&siError);
    v3 = ID_CharacterManagement_CG_VERIFICATION_RESPONSE_NAME_IN_USE;
  }
  else if ( i_rsvp == 5 )
  {
    StringInfo::StringInfo(&siError);
    v3 = ID_CharacterManagement_CG_VERIFICATION_RESPONSE_CORRUPT;
  }
  else
  {
    if ( i_rsvp != 6 )
      return;
    StringInfo::StringInfo(&siError);
    v3 = ID_CharacterManagement_CG_VERIFICATION_RESPONSE_DATABASE_DOWN;
  }
  StringInfo::SetStringIDandTableEnum(&siError, v3, 268435458);
  ((void (__thiscall *)(int, StringInfo *))v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[11][7].m_hashNext)(
    &v2[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[11],
    &siError);
  StringInfo::~StringInfo(&siError);
}

//----- (004EBFF0) --------------------------------------------------------  // acclient.c:280870
void __thiscall gmCharacterManagementUI::ResetPreviouslySelectedCharacterSlot(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  int v2; // ebx@1
  UIElement *v3; // eax@2
  UIElement *v4; // edi@2
  CPlayerSystem *v5; // eax@5
  CharGenState *v6; // eax@5
  unsigned int iidCharacter; // [sp+0h] [bp-4h]@1

  iidCharacter = (unsigned int)this;
  v1 = this;
  v2 = UIFramework::GetPersistantData();
  if ( v2 )
  {
    v3 = UIElement_ListBox::GetItem(v1->m_charListField, v1->m_uiCharListSelectedItem);
    v4 = v3;
    if ( v3 )
    {
      iidCharacter = 0;
      UIElement::GetAttribute_InstanceID(v3, 0x10000009u, &iidCharacter);
      if ( v1->m_iidSelectedCharacter == iidCharacter )
        UIElement::SetAttribute_Bool(v4, 0xEu, 0);
    }
    *(_DWORD *)(v2 + 76) = 0;
    v1->m_iidSelectedCharacter = 0;
    v1->m_uiCharListSelectedItem = -1;
    v5 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::GetCharGenState(v5);
    CharGenState::SetSlot(v6, -1);
  }
}

//----- (004EC080) --------------------------------------------------------  // acclient.c:280904
void __thiscall gmCharacterManagementUI::~gmCharacterManagementUI(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  NoticeHandler *v2; // edi@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCharacterManagementUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmCharacterManagementUI::vftable;
  UIMainFramework::RemoveRootElement((UIMainFramework *)&this->vfptr, &this->m_rootField);
  DialogFactory::CloseDialog(v1->m_errorMessageDialogContext);
  v1->m_errorMessageDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_confirmExitDialogContext);
  v1->m_confirmExitDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_deleteCharacterDialogContext);
  v1->m_deleteCharacterDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_pleaseWaitDialogContext);
  v1->m_pleaseWaitDialogContext = 0;
  DialogFactory::CloseDialog(v1->m_enteringWorldDialogContext);
  v1->m_enteringWorldDialogContext = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIMainFramework::~UIMainFramework((UIMainFramework *)&v1->vfptr);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C2E58: using guessed type bool (__thiscall *gmCharacterManagementUI::vftable)(DBCache *this);
// 7C3100: using guessed type int (__thiscall *gmCharacterManagementUI::vftable)(void *, char);

//----- (004EC120) --------------------------------------------------------  // acclient.c:280933
void __thiscall gmCharacterManagementUI::UpdateWorldName(gmCharacterManagementUI *this)
{
  UIElement *v1; // eax@1
  UIElement_Text *v2; // esi@2
  gmClient *v3; // eax@3
  PStringBase<unsigned short> *v4; // eax@3

  v1 = UIElement::GetChildRecursive(this->m_rootField, 0x1000039Bu);
  if ( v1 )
  {
    v2 = (UIElement_Text *)v1->vfptr[12].OnAction((IInputActionCallback *)v1, (InputEvent *)12);
    if ( v2 )
    {
      v3 = Client::GetInstance();
      v4 = (PStringBase<unsigned short> *)((int (__thiscall *)(gmClient *))v3->vfptr[3].QueryInterface)(v3);
      UIElement_Text::SetText(v2, v4);
    }
  }
}

//----- (004EC160) --------------------------------------------------------  // acclient.c:280954
void __thiscall gmCharacterManagementUI::SelectCharacter(gmCharacterManagementUI *this, unsigned int i_iidCharacter)
{
  unsigned int v2; // ebx@1
  gmCharacterManagementUI *v3; // esi@1
  int v4; // eax@2
  int v5; // ebp@2
  unsigned int v6; // edi@5
  UIElement *v7; // eax@6
  unsigned int v8; // ST04_4@9
  int v9; // ST04_4@9
  CPlayerSystem *v10; // eax@9
  CharGenState *v11; // eax@9

  v2 = i_iidCharacter;
  v3 = this;
  if ( this->m_iidSelectedCharacter != i_iidCharacter )
  {
    v4 = UIFramework::GetPersistantData();
    v5 = v4;
    if ( v4 )
    {
      if ( v4 != -4 )
      {
        gmCharacterManagementUI::ResetPreviouslySelectedCharacterSlot(v3);
        if ( v2 )
        {
          v6 = 0;
          if ( (signed int)v3->m_charListField->m_listItems.m_num > 0 )
          {
            while ( 1 )
            {
              v7 = UIElement_ListBox::GetItem(v3->m_charListField, v6);
              UIElement::GetAttribute_InstanceID(v7, 0x10000009u, &i_iidCharacter);
              if ( i_iidCharacter == v2 )
                break;
              ++v6;
              if ( (signed int)v6 >= (signed int)v3->m_charListField->m_listItems.m_num )
                return;
            }
            v3->m_iidSelectedCharacter = v2;
            *(_DWORD *)(v5 + 76) = v2;
            v8 = v3->m_iidSelectedCharacter;
            v3->m_uiCharListSelectedItem = v6;
            v9 = CharacterSet::GetSlot((CharacterSet *)(v5 + 4), v8);
            v10 = CPlayerSystem::GetPlayerSystem();
            CPlayerSystem::GetCharGenState(v10);
            CharGenState::SetSlot(v11, v9);
          }
        }
      }
    }
  }
}

//----- (004EC240) --------------------------------------------------------  // acclient.c:281009
void __usercall gmCharacterManagementUI::UpdateButtons(gmCharacterManagementUI *this@<ecx>, int a2@<edi>)
{
  gmCharacterManagementUI *v2; // esi@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // eax@4
  int v6; // eax@7
  UIElement *v7; // ecx@9
  int v8; // ecx@11
  bool v9; // sf@11
  unsigned __int8 v10; // of@11
  UIElement *v11; // ecx@11
  int v12; // [sp-4h] [bp-8h]@2
  int v13; // [sp+0h] [bp-4h]@0

  v2 = this;
  v3 = UIFramework::GetPersistantData();
  if ( v3 )
  {
    v12 = a2;
    v4 = v3 + 4;
    if ( v3 != -4 )
    {
      if ( UIElement_ListBox::GetSelectedIndex(v2->m_charListField) == -1
        || (v5 = CharacterSet::GetSlot((CharacterSet *)v4, v2->m_iidSelectedCharacter),
            CharacterSet::GetGreyedOutFor((CharacterSet *)v4, v5)) )
        ((void (__stdcall *)(signed int, int, int))v2->m_pEnterGameButton->vfptr[13].__vecDelDtor)(13, v12, v13);
      else
        ((void (__stdcall *)(signed int, int, int))v2->m_pEnterGameButton->vfptr[13].__vecDelDtor)(1, v12, v13);
      ((void (*)(void))v2->m_pDeleteCharacterButton->vfptr[13].__vecDelDtor)();
      v6 = CharacterSet::GetSlot((CharacterSet *)v4, v2->m_iidSelectedCharacter);
      if ( CharacterSet::GetGreyedOutFor((CharacterSet *)v4, v6)
        && UIElement_ListBox::GetSelectedIndex(v2->m_charListField) != -1 )
      {
        ((void (__stdcall *)(_DWORD))v2->m_pDeleteCharacterButton->vfptr[2].__vecDelDtor)(0);
        v7 = v2->m_pRestoreCharacterButton;
      }
      else
      {
        ((void (__stdcall *)(_DWORD))v2->m_pRestoreCharacterButton->vfptr[2].__vecDelDtor)(0);
        v7 = v2->m_pDeleteCharacterButton;
      }
      ((void (__stdcall *)(signed int))v7->vfptr[2].__vecDelDtor)(1);
      v8 = *(_DWORD *)(v4 + 20);
      v10 = __OFSUB__(v8, *(_DWORD *)(v4 + 40));
      v9 = v8 - *(_DWORD *)(v4 + 40) < 0;
      v11 = v2->m_pCreateCharacterButton;
      if ( v9 ^ v10 )
        ((void (__cdecl *)(signed int))v11->vfptr[13].__vecDelDtor)(1);
      else
        ((void (__cdecl *)(signed int))v11->vfptr[13].__vecDelDtor)(13);
    }
  }
}
// 4EC240: could not find valid save-restore pair for edi

//----- (004EC340) --------------------------------------------------------  // acclient.c:281066
gmCharacterManagementUI *__thiscall gmCharacterManagementUI::scalar_deleting_destructor(gmCharacterManagementUI *this, unsigned int a2)
{
  gmCharacterManagementUI *v2; // esi@1

  v2 = this;
  gmCharacterManagementUI::~gmCharacterManagementUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004EC360) --------------------------------------------------------  // acclient.c:281078
void __thiscall gmCharacterManagementUI::RecvNotice_WorldName(gmCharacterManagementUI *this, AC1Legacy::PStringBase<char> *i_strName)
{
  UIElement *v2; // eax@1
  UIElement_Text *v3; // esi@2
  gmClient *v4; // eax@3
  PStringBase<unsigned short> *v5; // eax@3

  v2 = UIElement::GetChildRecursive((UIElement *)this->m_hashElementsRegisteredWith.vfptr, 0x1000039Bu);
  if ( v2 )
  {
    v3 = (UIElement_Text *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
    if ( v3 )
    {
      v4 = Client::GetInstance();
      v5 = (PStringBase<unsigned short> *)((int (__thiscall *)(gmClient *))v4->vfptr[3].QueryInterface)(v4);
      UIElement_Text::SetText(v3, v5);
    }
  }
}

//----- (004EC3A0) --------------------------------------------------------  // acclient.c:281099
void __thiscall gmCharacterManagementUI::RebuildCharacterList(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // ebp@1
  int v2; // eax@1
  CharacterSet *v3; // ebx@3
  PSRefBufferCharData<unsigned short> *v4; // eax@4
  int v5; // ecx@4
  void *v6; // esi@4
  int v7; // eax@6
  UIRegion *v8; // ecx@6
  int v9; // esi@6
  signed int v10; // eax@6
  bool v11; // sf@6
  unsigned __int8 v12; // of@6
  int *v13; // eax@6
  bool v14; // zf@8
  unsigned int v15; // esi@9
  int v16; // eax@9
  int v17; // edi@10
  int v18; // ebx@11
  int v19; // ST2C_4@11
  int v20; // eax@11
  CharacterSet *v21; // ebx@13
  char *v22; // eax@13
  int v23; // eax@13
  CPlayerSystem *v24; // eax@21
  int v25; // eax@21
  char *v26; // esi@23
  BasePropertyDesc *v27; // ecx@27
  unsigned int v28; // edx@27
  BasePropertyValue *v29; // ecx@31
  unsigned int v30; // edi@31
  int v31; // ecx@34
  PSRefBufferCharData<unsigned short> *v32; // eax@35
  UIElement_ListBox *v33; // ecx@35
  UIElement *v34; // edi@35
  UIElement *v35; // esi@36
  int v36; // eax@37
  int v37; // eax@41
  unsigned int v38; // esi@42
  UIElement *v39; // eax@43
  int v40; // ebx@43
  UIElement_Text *v41; // edi@43
  UIElement *v42; // eax@43
  UIElement_Text *v43; // eax@43
  const wchar_t **v44; // eax@43
  int v45; // edi@43
  UIElement *v46; // eax@50
  UIElement_ListBox *v47; // ecx@53
  unsigned int v48; // esi@53
  signed int i; // ebx@53
  int v50; // eax@55
  UIElement *v51; // eax@59
  bool bSwapped; // [sp+40h] [bp-46h]@42
  bool v53; // [sp+41h] [bp-45h]@43
  int slotNum; // [sp+42h] [bp-44h]@4
  CharacterSet *charSet; // [sp+46h] [bp-40h]@3
  PStringBase<unsigned short> wstrCharName; // [sp+4Ah] [bp-3Ch]@4
  UIElement_Text *pSelectedCharacterOverride; // [sp+4Eh] [bp-38h]@4
  UIElement_Text *pPreviouslySelectedEntry; // [sp+52h] [bp-34h]@4
  int slotSize; // [sp+56h] [bp-30h]@8
  unsigned int iidCharacter; // [sp+5Ah] [bp-2Ch]@1
  BaseProperty p; // [sp+5Eh] [bp-28h]@11
  BaseProperty v62; // [sp+66h] [bp-20h]@16
  BaseProperty subP; // [sp+6Eh] [bp-18h]@14
  int v64; // [sp+76h] [bp-10h]@14
  int v65; // [sp+7Ah] [bp-Ch]@14
  int v66; // [sp+7Eh] [bp-8h]@14
  int v67; // [sp+82h] [bp-4h]@14

  v1 = this;
  iidCharacter = this->m_iidSelectedCharacter;
  gmCharacterManagementUI::ResetPreviouslySelectedCharacterSlot(this);
  UIElement_ListBox::Flush(v1->m_charListField);
  v2 = UIFramework::GetPersistantData();
  if ( v2 )
  {
    if ( *(_BYTE *)(v2 + 72) )
    {
      v3 = (CharacterSet *)(v2 + 4);
      charSet = (CharacterSet *)(v2 + 4);
      if ( v2 != -4 )
      {
        v4 = *(PSRefBufferCharData<unsigned short> **)(v2 + 44);
        v5 = v3->set_.m_num;
        pSelectedCharacterOverride = 0;
        pPreviouslySelectedEntry = 0;
        wstrCharName.m_charbuffer = v4;
        slotNum = v5;
        v6 = &wstrCharName;
        if ( v5 >= (signed int)v4 )
          v6 = &slotNum;
        v7 = UIRegion::GetHeight((UIRegion *)&v1->m_charListField->vfptr) / *(_DWORD *)v6;
        v8 = (UIRegion *)&v1->m_charListField->vfptr;
        v9 = v7;
        wstrCharName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v7;
        v10 = UIRegion::GetHeight(v8);
        v12 = __OFSUB__(v10 / 20, v9);
        v11 = v10 / 20 - v9 < 0;
        slotNum = v10 / 20;
        v13 = (int *)&wstrCharName;
        if ( !(v11 ^ v12) )
          v13 = &slotNum;
        v14 = v3->set_.m_num == 0;
        v11 = (v3->set_.m_num & 0x80000000) != 0;
        slotSize = *v13;
        slotNum = 0;
        if ( !v11 && !v14 )
        {
          do
          {
            v15 = CharacterSet::GetGID(v3, slotNum);
            v16 = UIElement_ListBox::AddItemFromTemplateList(v1->m_charListField, 0, 0);
            if ( !v16 )
              break;
            v17 = (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v16 + 148))(v16, 12);
            if ( !v17 )
              break;
            v18 = *(_DWORD *)v17;
            v19 = slotSize;
            v20 = UIRegion::GetWidth((UIRegion *)v17);
            (*(void (__thiscall **)(int, int, int))(v18 + 48))(v17, v20, v19);
            (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v17 + 272))(v17, 1);
            *(_DWORD *)(v17 + 1364) |= (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)";
            p.m_pcPropertyDesc = 0;
            p.m_pcPropertyValue = 0;
            BaseProperty::SetPropertyName(&p, 0x10000009u);
            if ( p.m_pcPropertyValue )
            {
              BaseProperty::CheckCopyOnWrite(&p);
              ((void (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[51].__vecDelDtor)(v15);
            }
            (*(void (__thiscall **)(int, BaseProperty *))(*(_DWORD *)v17 + 212))(v17, &p);
            v21 = charSet;
            v22 = CharacterSet::GetName(charSet, slotNum);
            PStringBase<unsigned short>::PStringBase<unsigned short>(&wstrCharName, 0, v22);
            UIElement_Text::SetText((UIElement_Text *)v17, &wstrCharName);
            v23 = CharacterSet::GetSlot(v21, v15);
            if ( CharacterSet::GetGreyedOutFor(v21, v23) )
            {
              subP.m_pcPropertyDesc = 0;
              subP.m_pcPropertyValue = 0;
              BaseProperty::SetPropertyName(&subP, 0x19u);
              v64 = 1065353216;
              v65 = 0;
              v66 = 0;
              v67 = 1065353216;
              if ( subP.m_pcPropertyValue )
              {
                BaseProperty::CheckCopyOnWrite(&subP);
                ((void (__stdcall *)(int *))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&v64);
              }
              v62.m_pcPropertyDesc = 0;
              v62.m_pcPropertyValue = 0;
              BaseProperty::SetPropertyName(&v62, 0x1Bu);
              if ( v62.m_pcPropertyValue )
              {
                BaseProperty::CheckCopyOnWrite(&v62);
                ((void (__stdcall *)(BaseProperty *))v62.m_pcPropertyValue->vfptr[63].__vecDelDtor)(&subP);
              }
              (*(void (__thiscall **)(int, BaseProperty *))(*(_DWORD *)v17 + 212))(v17, &v62);
              BaseProperty::~BaseProperty(&v62);
              BaseProperty::~BaseProperty(&subP);
            }
            if ( v15 == iidCharacter )
              pPreviouslySelectedEntry = (UIElement_Text *)v17;
            v24 = CPlayerSystem::GetPlayerSystem();
            CPlayerSystem::GetCharGenState(v24);
            if ( slotNum == *(_DWORD *)(v25 + 520) )
              pSelectedCharacterOverride = (UIElement_Text *)v17;
            v26 = (char *)&wstrCharName.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&wstrCharName.m_charbuffer[-1].m_data[8]) && v26 )
              (**(void (__thiscall ***)(char *, signed int))v26)(v26, 1);
            if ( (_DWORD)p.m_pcPropertyDesc )
            {
              v27 = p.m_pcPropertyDesc;
              v28 = p.m_pcPropertyDesc->m_cRef - 1;
              p.m_pcPropertyDesc->m_cRef = v28;
              if ( !v28 )
                ((void (__stdcall *)(signed int))v27->vfptr->__vecDelDtor)(1);
              p.m_pcPropertyDesc = 0;
            }
            if ( p.m_pcPropertyValue )
            {
              v29 = p.m_pcPropertyValue;
              v30 = p.m_pcPropertyValue->m_cRef - 1;
              p.m_pcPropertyValue->m_cRef = v30;
              if ( !v30 )
                ((void (__stdcall *)(signed int))v29->vfptr->__vecDelDtor)(1);
              p.m_pcPropertyValue = 0;
            }
            v31 = v21->set_.m_num;
            v3 = charSet;
            ++slotNum;
          }
          while ( slotNum < v31 );
        }
        v32 = (PSRefBufferCharData<unsigned short> *)UIElement_ListBox::GetItem(v1->m_charListField, 0);
        v33 = v1->m_charListField;
        wstrCharName.m_charbuffer = v32;
        v34 = 0;
        if ( (signed int)v33->m_listItems.m_num > 0 )
        {
          while ( 1 )
          {
            v35 = UIElement_ListBox::GetItem(v33, (unsigned int)v34);
            UIElement::GetAttribute_InstanceID(v35, 0x10000009u, &iidCharacter);
            if ( iidCharacter )
            {
              v36 = CharacterSet::GetSlot(v3, iidCharacter);
              if ( !CharacterSet::GetGreyedOutFor(v3, v36) )
                break;
            }
            v33 = v1->m_charListField;
            v34 = (UIElement *)((char *)v34 + 1);
            if ( (signed int)v34 >= (signed int)v33->m_listItems.m_num )
              goto LABEL_41;
          }
          wstrCharName.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v35;
        }
LABEL_41:
        v37 = v1->m_charListField->m_listItems.m_num - 1;
        slotNum = v1->m_charListField->m_listItems.m_num - 1;
        do
        {
          v38 = 0;
          bSwapped = 0;
          if ( v37 > 0 )
          {
            do
            {
              v39 = UIElement_ListBox::GetItem(v1->m_charListField, v38);
              v40 = v38 + 1;
              v41 = (UIElement_Text *)v39->vfptr[12].OnAction((IInputActionCallback *)v39, (InputEvent *)12);
              v42 = UIElement_ListBox::GetItem(v1->m_charListField, v38 + 1);
              v43 = (UIElement_Text *)v42->vfptr[12].OnAction((IInputActionCallback *)v42, (InputEvent *)12);
              iidCharacter = (unsigned int)UIElement_Text::GetText(v43, (PStringBase<unsigned short> *)&p);
              v44 = (const wchar_t **)UIElement_Text::GetText(v41, (PStringBase<unsigned short> *)&slotSize);
              v53 = _wcscmp(*v44, *(const wchar_t **)iidCharacter) > 0;
              v45 = slotSize - 20;
              if ( !InterlockedDecrement((volatile LONG *)(slotSize - 20 + 4)) && v45 )
                (**(void (__thiscall ***)(_DWORD, _DWORD))v45)(v45, 1);
              v34 = (UIElement *)&p.m_pcPropertyDesc[-1].m_bRecorded;
              if ( !InterlockedDecrement((volatile LONG *)&p.m_pcPropertyDesc[-1].m_nMinElements) && v34 )
                v34->vfptr->__vecDelDtor((IInputActionCallback *)v34, 1u);
              if ( v53 )
              {
                v46 = UIElement_ListBox::RemoveItem(v1->m_charListField, v38 + 1);
                UIElement_ListBox::InsertItem(v1->m_charListField, v46, v38);
                bSwapped = 1;
              }
              v37 = slotNum;
              ++v38;
            }
            while ( v40 < slotNum );
          }
          --v37;
          slotNum = v37;
        }
        while ( bSwapped );
        v47 = v1->m_charListField;
        v48 = 0;
        for ( i = 0; i < (signed int)v47->m_listItems.m_num; ++i )
        {
          v34 = UIElement_ListBox::GetItem(v47, v48);
          UIElement::GetAttribute_InstanceID(v34, 0x10000009u, (unsigned int *)&p);
          if ( (_DWORD)p.m_pcPropertyDesc )
          {
            v50 = CharacterSet::GetSlot(charSet, (unsigned int)p.m_pcPropertyDesc);
            if ( CharacterSet::GetGreyedOutFor(charSet, v50) )
            {
              UIElement_ListBox::RemoveItem(v1->m_charListField, v34);
              UIElement_ListBox::InsertItem(v1->m_charListField, v34, v1->m_charListField->m_listItems.m_num);
            }
            else
            {
              ++v48;
            }
          }
          v47 = v1->m_charListField;
        }
        v51 = (UIElement *)pSelectedCharacterOverride;
        if ( !pSelectedCharacterOverride )
        {
          v51 = (UIElement *)pPreviouslySelectedEntry;
          if ( !pPreviouslySelectedEntry )
            v51 = (UIElement *)wstrCharName.m_charbuffer;
        }
        UIElement_ListBox::SetSelectedItem(v1->m_charListField, v51, 1);
        gmCharacterManagementUI::UpdateButtons(v1, (int)v34);
      }
    }
  }
}

//----- (004EC8F0) --------------------------------------------------------  // acclient.c:281395
void __thiscall gmCharacterManagementUI::gmCharacterManagementUI(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  int v2; // eax@1
  UIElement *v3; // eax@2
  int v4; // eax@3
  UIElement *v5; // ecx@5
  UIElement *v6; // eax@5
  UIElement *v7; // ecx@5
  UIElement *v8; // eax@5
  UIElement *v9; // ecx@5
  UIElement *v10; // eax@5
  UIElement *v11; // ecx@5
  GlobalEventHandler *v12; // eax@5
  GlobalEventHandler *v13; // edi@5
  int v14; // eax@6

  v1 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmCharacterManagementUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmCharacterManagementUI::vftable;
  v1->m_rootField = 0;
  v1->m_charListField = 0;
  v1->m_pCreateCharacterButton = 0;
  v1->m_pEnterGameButton = 0;
  v1->m_pDeleteCharacterButton = 0;
  v1->m_pRestoreCharacterButton = 0;
  v1->m_uiCharListSelectedItem = -1;
  v1->m_iidSelectedCharacter = 0;
  v1->m_errorMessageDialogContext = 0;
  v1->m_confirmExitDialogContext = 0;
  v1->m_deleteCharacterDialogContext = 0;
  v1->m_pleaseWaitDialogContext = 0;
  v1->m_enteringWorldDialogContext = 0;
  v2 = UIMainFramework::CreateAndAddRootElement((UIMainFramework *)&v1->vfptr, 0x10000005u, 0x1000039Au);
  v1->m_rootField = (UIElement *)v2;
  if ( v2 )
  {
    v3 = UIElement::GetChildRecursive((UIElement *)v2, 0x1000039Du);
    v4 = v3 ? v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)5) : 0;
    v5 = v1->m_rootField;
    v1->m_charListField = (UIElement_ListBox *)v4;
    v6 = UIElement::GetChildRecursive(v5, 0x100003A0u);
    v7 = v1->m_rootField;
    v1->m_pCreateCharacterButton = v6;
    v8 = UIElement::GetChildRecursive(v7, 0x100003A2u);
    v9 = v1->m_rootField;
    v1->m_pEnterGameButton = v8;
    v10 = UIElement::GetChildRecursive(v9, 0x1000039Fu);
    v11 = v1->m_rootField;
    v1->m_pDeleteCharacterButton = v10;
    v1->m_pRestoreCharacterButton = UIElement::GetChildRecursive(v11, 0x1000039Eu);
    v12 = GlobalEventHandler::GetGlobalEventHandler();
    v13 = v12;
    if ( v12 )
    {
      v12->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v12, 100004u, (NoticeHandler *)&v1->vfptr);
      v13->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v13, 100002u, (NoticeHandler *)&v1->vfptr);
      v13->vfptr->RegisterNoticeHandler(
        (NoticeRegistrar *)v13,
        (unsigned int)((char *)&loc_4DD1E0 + 1),
        (NoticeHandler *)&v1->vfptr);
      v13->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v13, (unsigned int)&byte_4DD22C, (NoticeHandler *)&v1->vfptr);
      gmCharacterManagementUI::UpdateWorldName(v1);
      v14 = UIFramework::GetPersistantData();
      if ( v14 && *(_BYTE *)(v14 + 72) )
      {
        v1->m_iidSelectedCharacter = *(_DWORD *)(v14 + 76);
        gmCharacterManagementUI::RebuildCharacterList(v1);
      }
      if ( ICIDM::s_cidm )
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(9, v1, 3000);
    }
  }
}
// 4DD22C: using guessed type char byte_4DD22C;
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C2E58: using guessed type bool (__thiscall *gmCharacterManagementUI::vftable)(DBCache *this);
// 7C3100: using guessed type int (__thiscall *gmCharacterManagementUI::vftable)(void *, char);

//----- (004ECA90) --------------------------------------------------------  // acclient.c:281477
void __cdecl gmCharacterManagementUI::Create()
{
  gmCharacterManagementUI *v0; // eax@1

  v0 = (gmCharacterManagementUI *)operator new(0xD0u);
  if ( v0 )
    gmCharacterManagementUI::gmCharacterManagementUI(v0);
}

//----- (004ECAB0) --------------------------------------------------------  // acclient.c:281487
void __thiscall gmCharacterManagementUI::Update(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  v2 = UIFramework::GetPersistantData();
  if ( v2 )
  {
    if ( *(_BYTE *)(v2 + 72) )
    {
      gmCharacterManagementUI::UpdateWorldName(v1);
      gmCharacterManagementUI::RebuildCharacterList(v1);
      DialogFactory::CloseDialog(v1->m_pleaseWaitDialogContext);
      v1->m_pleaseWaitDialogContext = 0;
    }
  }
}

//----- (004ECAF0) --------------------------------------------------------  // acclient.c:281507
void __cdecl gmCharacterManagementUI::Register(unsigned int mode)
{
  UIFlow::RegisterFrameworkClass(mode, (UIMainFramework *(__cdecl *)())gmCharacterManagementUI::Create);
}

//----- (004ECB10) --------------------------------------------------------  // acclient.c:281513
char __thiscall gmCharacterManagementUI::MakeErrorMessageDialog(gmCharacterManagementUI *this, StringInfo *siError)
{
  gmCharacterManagementUI *v2; // esi@1
  char result; // al@2
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BaseProperty p; // [sp+10h] [bp-84h]@3
  unsigned int _key; // [sp+18h] [bp-7Ch]@5
  PropertyCollection pc; // [sp+1Ch] [bp-78h]@3

  v2 = this;
  if ( this->m_errorMessageDialogContext )
  {
    result = 0;
  }
  else
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(3);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
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
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(siError);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v2->m_errorMessageDialogContext = DialogFactory::MakeDialog((UIFramework *)&v2->vfptr, &pc);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    result = 1;
  }
  return result;
}

//----- (004ECCA0) --------------------------------------------------------  // acclient.c:281594
char __thiscall gmCharacterManagementUI::MakeDeleteCharacterConfirmationDialog(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // edi@1
  char result; // al@2
  int v3; // eax@3
  CharacterSet *v4; // esi@3
  int v5; // eax@3
  char *v6; // eax@3
  PStringBase<unsigned short> v7; // ST04_4@7
  BasePropertyDesc *v8; // ecx@10
  unsigned int v9; // esi@10
  BasePropertyValue *v10; // ecx@14
  unsigned int v11; // edx@14
  char *v12; // esi@17
  BaseProperty p; // [sp+10h] [bp-118h]@3
  unsigned int _key; // [sp+18h] [bp-110h]@5
  PStringBase<unsigned short> strCharacterName; // [sp+1Ch] [bp-10Ch]@3
  PropertyCollection pc; // [sp+20h] [bp-108h]@3
  StringInfo info; // [sp+98h] [bp-90h]@7

  v1 = this;
  if ( this->m_deleteCharacterDialogContext )
  {
    result = 0;
  }
  else
  {
    v3 = UIFramework::GetPersistantData();
    v4 = (CharacterSet *)(v3 + 4);
    v5 = CharacterSet::GetSlot((CharacterSet *)(v3 + 4), v1->m_iidSelectedCharacter);
    v6 = CharacterSet::GetName(v4, v5);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&strCharacterName, 0, v6);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(5);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_CharacterManagement_DeleteCharacterConfirmation, 268435458);
    v7.m_charbuffer = strCharacterName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strCharacterName.m_charbuffer[-1].m_data[8]);
    StringInfo::AddVariable_String(&info, ID_Player_1, v7);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v1->m_deleteCharacterDialogContext = DialogFactory::MakeDialog((UIFramework *)&v1->vfptr, &pc);
    StringInfo::~StringInfo(&info);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v8 = p.m_pcPropertyDesc;
      v9 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v9;
      if ( !v9 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v10 = p.m_pcPropertyValue;
      v11 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    v12 = (char *)&strCharacterName.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strCharacterName.m_charbuffer[-1].m_data[8]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    }
    result = 1;
  }
  return result;
}

//----- (004ECED0) --------------------------------------------------------  // acclient.c:281700
char __thiscall gmCharacterManagementUI::MakePleaseWaitDialog(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  char result; // al@2
  BasePropertyDesc *v3; // ecx@10
  unsigned int v4; // esi@10
  BasePropertyValue *v5; // ecx@14
  unsigned int v6; // edx@14
  BaseProperty p; // [sp+10h] [bp-114h]@3
  unsigned int _key; // [sp+18h] [bp-10Ch]@5
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@3
  StringInfo info; // [sp+94h] [bp-90h]@3

  v1 = this;
  if ( this->m_pleaseWaitDialogContext )
  {
    result = 0;
  }
  else
  {
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_CharacterManagement_PleaseWait, 268435458);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(2);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
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
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v1->m_pleaseWaitDialogContext = DialogFactory::MakeDialog((UIFramework *)&v1->vfptr, &pc);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v3 = p.m_pcPropertyDesc;
      v4 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v4;
      if ( !v4 )
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v5 = p.m_pcPropertyValue;
      v6 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&info);
    result = 1;
  }
  return result;
}

//----- (004ED090) --------------------------------------------------------  // acclient.c:281785
char __thiscall gmCharacterManagementUI::MakeEnteringWorldDialog(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  char result; // al@2
  BasePropertyDesc *v3; // ecx@10
  unsigned int v4; // esi@10
  BasePropertyValue *v5; // ecx@14
  unsigned int v6; // edx@14
  BaseProperty p; // [sp+10h] [bp-114h]@3
  unsigned int _key; // [sp+18h] [bp-10Ch]@5
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@3
  StringInfo info; // [sp+94h] [bp-90h]@3

  v1 = this;
  if ( this->m_enteringWorldDialogContext )
  {
    result = 0;
  }
  else
  {
    StringInfo::StringInfo(&info);
    StringInfo::SetStringIDandTableEnum(&info, ID_Character_EnteringWorld, 268435458);
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(2);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
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
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v1->m_enteringWorldDialogContext = DialogFactory::MakeDialog((UIFramework *)&v1->vfptr, &pc);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v3 = p.m_pcPropertyDesc;
      v4 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v4;
      if ( !v4 )
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v5 = p.m_pcPropertyValue;
      v6 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    StringInfo::~StringInfo(&info);
    result = 1;
  }
  return result;
}

//----- (004ED250) --------------------------------------------------------  // acclient.c:281870
char __thiscall gmCharacterManagementUI::MakeConfirmExitDialog(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  char result; // al@2
  unsigned int v3; // eax@7
  BasePropertyDesc *v4; // ecx@10
  unsigned int v5; // edx@10
  BasePropertyValue *v6; // ecx@14
  unsigned int v7; // esi@14
  BaseProperty p; // [sp+10h] [bp-114h]@3
  unsigned int _key; // [sp+18h] [bp-10Ch]@5
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@3
  StringInfo info; // [sp+94h] [bp-90h]@7

  v1 = this;
  if ( this->m_confirmExitDialogContext )
  {
    result = 0;
  }
  else
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xACu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    StringInfo::StringInfo(&info);
    v3 = compute_str_hash("ID_CharacterManagement_ConfirmExit");
    StringInfo::SetStringIDandTableEnum(&info, v3, 268435458);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v1->m_confirmExitDialogContext = DialogFactory::MakeDialog((UIFramework *)&v1->vfptr, &pc);
    StringInfo::~StringInfo(&info);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v4 = p.m_pcPropertyDesc;
      v5 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v6 = p.m_pcPropertyValue;
      v7 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
    result = 1;
  }
  return result;
}

//----- (004ED410) --------------------------------------------------------  // acclient.c:281957
char __thiscall gmCharacterManagementUI::OnAction(gmCharacterManagementUI *this, InputEvent *i_evt)
{
  char result; // al@1

  result = 0;
  if ( i_evt->m_InputAction == 39 )
  {
    gmCharacterManagementUI::MakeConfirmExitDialog(this);
    result = 1;
  }
  return result;
}

//----- (004ED440) --------------------------------------------------------  // acclient.c:281971
void __thiscall gmCharacterManagementUI::EnterGame(gmCharacterManagementUI *this)
{
  gmCharacterManagementUI *v1; // esi@1
  CPlayerSystem *v2; // ebx@1
  int v3; // eax@3
  CharacterSet *v4; // edi@3
  int v5; // eax@3

  v1 = this;
  v2 = CPlayerSystem::GetPlayerSystem();
  if ( v2 && v1->m_iidSelectedCharacter )
  {
    v3 = UIFramework::GetPersistantData();
    v4 = (CharacterSet *)(v3 + 4);
    v5 = CharacterSet::GetSlot((CharacterSet *)(v3 + 4), v1->m_iidSelectedCharacter);
    if ( !CharacterSet::GetGreyedOutFor(v4, v5) )
    {
      gmCharacterManagementUI::MakeEnteringWorldDialog(v1);
      CPlayerSystem::LogOnCharacter(v2, v1->m_iidSelectedCharacter);
    }
  }
}

//----- (004ED4A0) --------------------------------------------------------  // acclient.c:281995
void __thiscall gmCharacterManagementUI::CloseDeleteCharacterDialog(gmCharacterManagementUI *this, PStringBase<char> *i_strResponse)
{
  gmCharacterManagementUI *v2; // ebp@1
  PStringBase<unsigned short> *v3; // eax@2
  char *v4; // esi@2
  bool v5; // bl@2
  char *v6; // esi@5
  unsigned int v7; // esi@9
  CPlayerSystem *v8; // eax@9
  PStringBase<unsigned short> result; // [sp+4h] [bp-98h]@2
  PStringBase<char> v10; // [sp+8h] [bp-94h]@2
  StringInfo info; // [sp+Ch] [bp-90h]@1

  v2 = this;
  this->m_deleteCharacterDialogContext = 0;
  StringInfo::StringInfo(&info);
  StringInfo::SetStringIDandTableEnum(&info, ID_CharacterManagement_DeleteCharacterResponse, 268435458);
  if ( StringInfo::IsValid(&info, 1) )
  {
    v3 = StringInfo::GetString(&info, &result, 0);
    PStringBase<unsigned short>::to_spstring(v3, &v10, 0);
    v4 = &v10.m_charbuffer[-2].m_data[12];
    v5 = __stricmp(i_strResponse->m_charbuffer->m_data, v10.m_charbuffer->m_data) == 0;
    if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v6 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    if ( v5 )
    {
      v7 = *(_DWORD *)(UIFramework::GetPersistantData() + 76);
      gmCharacterManagementUI::MakePleaseWaitDialog(v2);
      v8 = CPlayerSystem::GetPlayerSystem();
      CPlayerSystem::DeleteCharacter(v8, v7);
    }
  }
  StringInfo::~StringInfo(&info);
}

//----- (004ED5A0) --------------------------------------------------------  // acclient.c:282035
signed int __thiscall gmCharacterManagementUI::ListenToElementMessage(gmCharacterManagementUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebx@1
  gmCharacterManagementUI *v3; // esi@1
  int v4; // edi@3
  UIElement *v6; // ecx@15

  v2 = i_rMsg;
  v3 = this;
  switch ( i_rMsg->idElement )
  {
    case 0x1000039Du:
      if ( i_rMsg->idMessage != 4 )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      gmCharacterManagementUI::ResetPreviouslySelectedCharacterSlot(this);
      v4 = v2->dwParam2;
      i_rMsg = 0;
      if ( v4 )
      {
        UIElement::SetAttribute_Bool((UIElement *)v4, 0xEu, 1);
        UIElement::GetAttribute_InstanceID((UIElement *)v4, 0x10000009u, (unsigned int *)&i_rMsg);
      }
      gmCharacterManagementUI::SelectCharacter(v3, (unsigned int)i_rMsg);
      gmCharacterManagementUI::UpdateButtons(v3, v4);
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
    case 0x100003A2u:
      if ( i_rMsg->idMessage != 1 )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      gmCharacterManagementUI::EnterGame(this);
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
    case 0x100003A5u:
      if ( i_rMsg->idMessage != 26 )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      gmCharacterManagementUI::EnterGame(this);
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
    case 0x1000039Fu:
      if ( i_rMsg->idMessage != 1 || !this->m_charListField->m_pSelectedItem )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      gmCharacterManagementUI::MakeDeleteCharacterConfirmationDialog(this);
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
    case 0x1000039Eu:
      if ( i_rMsg->idMessage != 1 )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      if ( !CPlayerSystem::GetPlayerSystem() )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      v6 = v3->m_charListField->m_pSelectedItem;
      if ( !v6 )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      UIElement::GetAttribute_InstanceID(v6, 0x10000009u, (unsigned int *)&i_rMsg);
      UIFramework::GetPersistantData();
      gmCharacterManagementUI::MakePleaseWaitDialog(v3);
      CPlayerSystem::RestoreCharacter((unsigned int)i_rMsg);
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
    case 0x100003A3u:
      if ( i_rMsg->idMessage == 1 )
        UIFramework::QueueUIMode(0x10000005u);
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
    case 0x100003A4u:
      if ( i_rMsg->idMessage != 1 )
        return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
      gmCharacterManagementUI::MakeConfirmExitDialog(this);
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
    case 0x100003A0u:
      if ( i_rMsg->idMessage == 1 )
        UIFramework::QueueUIMode(0x1000000Bu);
      break;
    default:
      return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
  }
  return UIFramework::ListenToElementMessage((UIFramework *)&v3->vfptr, v2);
}

//----- (004ED760) --------------------------------------------------------  // acclient.c:282108
void __thiscall gmCharacterManagementUI::RecvNotice_CloseDialog(gmCharacterManagementUI *this, unsigned int context, PropertyCollection *data)
{
  PropertyCollection *v3; // esi@1
  unsigned int v4; // edx@1
  HashTableData<unsigned long,BaseProperty> **v5; // eax@1
  gmCharacterManagementUI *v6; // edi@1
  BasePropertyValue *v7; // ecx@1
  HashTableData<unsigned long,BaseProperty> *v8; // eax@1
  unsigned int v9; // ebp@8
  unsigned int v10; // edx@11
  HashTableData<unsigned long,BaseProperty> **v11; // eax@11
  HashTableData<unsigned long,BaseProperty> *v12; // eax@11
  unsigned int v13; // edx@23
  HashTableData<unsigned long,BaseProperty> **v14; // eax@23
  BasePropertyValue *v15; // ecx@23
  HashTableData<unsigned long,BaseProperty> *v16; // eax@23
  BasePropertyDesc *v17; // ecx@33
  unsigned int v18; // esi@33
  int v19; // edx@37
  unsigned int v20; // esi@40
  BasePropertyDesc *v21; // ecx@45
  unsigned int v22; // edx@45
  int v23; // edx@49
  unsigned int type; // [sp+10h] [bp-14h]@1
  BaseProperty v25; // [sp+14h] [bp-10h]@11
  BaseProperty p; // [sp+1Ch] [bp-8h]@1

  v3 = data;
  v4 = 0x8E % data->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v5 = data->m_hashProperties.m_intrusiveTable.m_buckets;
  v6 = this;
  v7 = 0;
  type = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v8 = v5[v4];
  if ( v8 )
  {
    while ( v8->m_hashKey != 142 )
    {
      v8 = v8->m_hashNext;
      if ( !v8 )
        goto LABEL_8;
    }
    if ( v8 )
    {
      BaseProperty::operator=(&p, (int)&v8->m_data);
      v7 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&type);
        v7 = p.m_pcPropertyValue;
      }
    }
  }
LABEL_8:
  v9 = context;
  switch ( type )
  {
    case 3u:
      if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] == (HashSetData<UIElement *> *)context )
        v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = 0;
      goto LABEL_44;
    case 1u:
      v10 = 0x92 % v3->m_hashProperties.m_intrusiveTable.m_numBuckets;
      v11 = v3->m_hashProperties.m_intrusiveTable.m_buckets;
      LOBYTE(context) = 0;
      v25.m_pcPropertyDesc = 0;
      v25.m_pcPropertyValue = 0;
      v12 = v11[v10];
      if ( !v12 )
        goto LABEL_18;
      while ( v12->m_hashKey != 146 )
      {
        v12 = v12->m_hashNext;
        if ( !v12 )
          goto LABEL_18;
      }
      if ( v12 )
      {
        BaseProperty::operator=(&v25, (int)&v12->m_data);
        if ( v25.m_pcPropertyValue )
          ((void (__stdcall *)(_DWORD))v25.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&context);
      }
LABEL_18:
      if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] == (HashSetData<UIElement *> *)v9 )
      {
        if ( (_BYTE)context )
          UIFramework::QueueUIMode(0x10000009u);
        v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = 0;
      }
      BaseProperty::~BaseProperty(&v25);
      goto $L152172;
    case 5u:
$L152172:
      context = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v13 = 0x9C % v3->m_hashProperties.m_intrusiveTable.m_numBuckets;
      v14 = v3->m_hashProperties.m_intrusiveTable.m_buckets;
      v15 = 0;
      v25.m_pcPropertyDesc = 0;
      v25.m_pcPropertyValue = 0;
      v16 = v14[v13];
      if ( !v16 )
        goto LABEL_30;
      break;
    default:
      goto LABEL_44;
    case 2u:
      if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9] == (HashSetData<UIElement *> *)context )
      {
        v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[9] = 0;
      }
      else if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[10] == (HashSetData<UIElement *> *)context )
      {
        v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[10] = 0;
      }
      goto LABEL_44;
  }
  while ( v16->m_hashKey != 156 )
  {
    v16 = v16->m_hashNext;
    if ( !v16 )
      goto LABEL_30;
  }
  if ( v16 )
  {
    BaseProperty::operator=(&v25, (int)&v16->m_data);
    v15 = v25.m_pcPropertyValue;
    if ( v25.m_pcPropertyValue )
    {
      ((void (__stdcall *)(_DWORD))v25.m_pcPropertyValue->vfptr[40].__vecDelDtor)(&context);
      v15 = v25.m_pcPropertyValue;
    }
  }
LABEL_30:
  if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8] == (HashSetData<UIElement *> *)v9 )
  {
    gmCharacterManagementUI::CloseDeleteCharacterDialog(
      (gmCharacterManagementUI *)((char *)v6 - 152),
      (PStringBase<char> *)&context);
    v15 = v25.m_pcPropertyValue;
  }
  if ( (_DWORD)v25.m_pcPropertyDesc )
  {
    v17 = v25.m_pcPropertyDesc;
    v18 = v25.m_pcPropertyDesc->m_cRef - 1;
    v25.m_pcPropertyDesc->m_cRef = v18;
    if ( !v18 )
      ((void (__stdcall *)(_DWORD))v17->vfptr->__vecDelDtor)(1);
    v15 = v25.m_pcPropertyValue;
    v25.m_pcPropertyDesc = 0;
  }
  if ( v15 )
  {
    v19 = v15->m_cRef - 1;
    v15->m_cRef = v19;
    if ( !v19 )
      ((void (__stdcall *)(_DWORD))v15->vfptr->__vecDelDtor)(1);
    v25.m_pcPropertyValue = 0;
  }
  v20 = context - 20;
  if ( !InterlockedDecrement((volatile LONG *)(context - 20 + 4)) && v20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
  v7 = p.m_pcPropertyValue;
LABEL_44:
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v21 = p.m_pcPropertyDesc;
    v22 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v22;
    if ( !v22 )
      ((void (__stdcall *)(_DWORD))v21->vfptr->__vecDelDtor)(1);
    v7 = p.m_pcPropertyValue;
    p.m_pcPropertyDesc = 0;
  }
  if ( v7 )
  {
    v23 = v7->m_cRef - 1;
    v7->m_cRef = v23;
    if ( !v23 )
      ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
  }
}

//----- (006F7280) --------------------------------------------------------  // acclient.c:779893
void sub_6F7280()
{
  flt_840B68 = 1000.0 + 1.0;
}

//----- (006F72A0) --------------------------------------------------------  // acclient.c:779899
void sub_6F72A0()
{
  flt_840B6C = 24.0 * 8.0;
}

//----- (006F72C0) --------------------------------------------------------  // acclient.c:779905
void sub_6F72C0()
{
  flt_840B70 = 24.0 * 0.5;
}

//----- (006F72E0) --------------------------------------------------------  // acclient.c:779911
int sub_6F72E0()
{
  return atexit(nullsub_490);
}

//----- (006F72F0) --------------------------------------------------------  // acclient.c:779917
int sub_6F72F0()
{
  return atexit(nullsub_491);
}

//----- (006F7300) --------------------------------------------------------  // acclient.c:779923
int sub_6F7300()
{
  return atexit(nullsub_492);
}

//----- (006F7310) --------------------------------------------------------  // acclient.c:779929
void _E106_77()
{
  dword_840B74 = 1024;
}

//----- (006F7320) --------------------------------------------------------  // acclient.c:779935
void _E108_60()
{
  dword_840B78 = 0x7FFF;
}

//----- (006F7330) --------------------------------------------------------  // acclient.c:779941
int _E110_50()
{
  const int result; // eax@1

  result = dword_840B74;
  INITIAL_MAX_DATA_RATE_52 = dword_840B74;
  return result;
}

//----- (006F7340) --------------------------------------------------------  // acclient.c:779951
void _E112_69()
{
  DEFAULT_VIEW_RADIUS_80 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F7360) --------------------------------------------------------  // acclient.c:779957
void _E114_36()
{
  MIN_QUANTUM_80 = 1.0 / 30.0;
}

//----- (006F7380) --------------------------------------------------------  // acclient.c:779963
void _E116_14()
{
  MAX_QUANTUM_80 = 1.0 / 5.0;
}

//----- (006F73A0) --------------------------------------------------------  // acclient.c:779969
void _E118_53()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840B98, PFID_A8R8G8B8);
}

//----- (006F73B0) --------------------------------------------------------  // acclient.c:779975
int _E120_43()
{
  return atexit(nullsub_488);
}

//----- (006F73C0) --------------------------------------------------------  // acclient.c:779981
unsigned int _E123_22()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterManagement_CG_VERIFICATION_RESPONSE_NAME_IN_USE");
  ID_CharacterManagement_CG_VERIFICATION_RESPONSE_NAME_IN_USE = result;
  return result;
}

//----- (006F73E0) --------------------------------------------------------  // acclient.c:779991
unsigned int _E125_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterManagement_CG_VERIFICATION_RESPONSE_CORRUPT");
  ID_CharacterManagement_CG_VERIFICATION_RESPONSE_CORRUPT = result;
  return result;
}

//----- (006F7400) --------------------------------------------------------  // acclient.c:780001
unsigned int _E127_40()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterManagement_CG_VERIFICATION_RESPONSE_DATABASE_DOWN");
  ID_CharacterManagement_CG_VERIFICATION_RESPONSE_DATABASE_DOWN = result;
  return result;
}

//----- (006F7420) --------------------------------------------------------  // acclient.c:780011
unsigned int _E129_21()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Character_EnteringWorld");
  ID_Character_EnteringWorld = result;
  return result;
}

//----- (006F7440) --------------------------------------------------------  // acclient.c:780021
unsigned int _E131_4()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterManagement_DeleteCharacterConfirmation");
  ID_CharacterManagement_DeleteCharacterConfirmation = result;
  return result;
}

//----- (006F7460) --------------------------------------------------------  // acclient.c:780031
unsigned int _E133_28()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterManagement_DeleteCharacterResponse");
  ID_CharacterManagement_DeleteCharacterResponse = result;
  return result;
}

//----- (006F7480) --------------------------------------------------------  // acclient.c:780041
unsigned int _E135_21()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CharacterManagement_PleaseWait");
  ID_CharacterManagement_PleaseWait = result;
  return result;
}

//----- (006F74A0) --------------------------------------------------------  // acclient.c:780051
unsigned int _E137_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PLAYER");
  ID_Player_1 = result;
  return result;
}

//----- (006F74C0) --------------------------------------------------------  // acclient.c:780061
int sub_6F74C0()
{
  return atexit(nullsub_489);
}

