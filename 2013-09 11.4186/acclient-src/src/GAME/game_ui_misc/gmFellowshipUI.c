/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmFellowshipUI
   Object     : GAME\game_ui_misc\gmFellowshipUI.obj
   Functions  : 79
   Addresses  : 0048E310 - 0075F840 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0048E310) --------------------------------------------------------  // acclient.c:201754
unsigned int __cdecl GetPlayerID()
{
  unsigned int result; // eax@2

  if ( SmartBox::smartbox )
    result = SmartBox::smartbox->player_id;
  else
    result = 0;
  return result;
}

//----- (0048E330) --------------------------------------------------------  // acclient.c:201766
void __userpurge gmFellowshipUI::gmFellowshipUI(gmFellowshipUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFellowshipUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pFellowship = 0;
  v4->m_iidSelectedFellow = 0;
  v4->m_uiAcceptFellowRequestServerContextID = 0;
  v4->m_fellowRequestContext = 0;
  v4->m_pNotInAFellowshipFrame = 0;
  v4->m_pInAFellowshipFrame = 0;
  v4->m_pFellowshipNameEntryBox = 0;
  v4->m_pCreateFellowshipButton = 0;
  v4->m_pFellowshipName = 0;
  v4->m_pFellowsListBox = 0;
  v4->m_pFellowLeaderButton = 0;
  v4->m_pFellowQuitButton = 0;
  v4->m_pFellowOpenButton = 0;
  v4->m_pFellowRecruitButton = 0;
  v4->m_pFellowDismissButton = 0;
  v4->m_pFellowDisbandButton = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmFellowshipUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmFellowshipUI::vftable;
}
// 7A4D78: using guessed type bool (__thiscall *gmFellowshipUI::vftable)(DBCache *this);
// 7A5020: using guessed type int (__thiscall *gmFellowshipUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048E3D0) --------------------------------------------------------  // acclient.c:201797
gmFellowshipUI *__thiscall gmFellowshipUI::DynamicCast(gmFellowshipUI *this, unsigned int i_eType)
{
  gmFellowshipUI *result; // eax@1

  result = this;
  if ( i_eType != 268435501 )
    result = (gmFellowshipUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0048E3F0) --------------------------------------------------------  // acclient.c:201808
signed int gmFellowshipUI::GetUIElementType()
{
  return 268435501;
}

//----- (0048E400) --------------------------------------------------------  // acclient.c:201814
void __usercall gmFellowshipUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmFellowshipUI *v3; // eax@1

  v3 = (gmFellowshipUI *)operator new(0x63Cu);
  if ( v3 )
    gmFellowshipUI::gmFellowshipUI(v3, a1, _layout, _full_desc);
}

//----- (0048E430) --------------------------------------------------------  // acclient.c:201824
void __thiscall gmFellowshipUI::RecvNotice_AbortConfirmationRequest(gmFellowshipUI *this, int confirmationType, unsigned int context)
{
  gmFellowshipUI *v3; // esi@1

  v3 = this;
  if ( confirmationType == 4 )
  {
    DialogFactory::CloseDialog((const unsigned int)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]);
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = 0;
    v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] = 0;
  }
}

//----- (0048E460) --------------------------------------------------------  // acclient.c:201838
void __stdcall gmFellowshipUI::OnVisibilityChanged(bool i_bVisible)
{
  CM_Fellowship::Event_UpdateRequest(i_bVisible);
}

//----- (0048E470) --------------------------------------------------------  // acclient.c:201844
void __thiscall gmFellowshipUI::DismissFellow(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  Fellowship *v2; // ecx@1
  unsigned int v3; // eax@5
  StringInfo siError; // [sp+0h] [bp-90h]@3

  v2 = (Fellowship *)&this->m_pFellowship->vfptr;
  if ( v2 )
  {
    if ( Fellowship::IsFellow(v2, i_iidPlayer) )
    {
      if ( SmartBox::smartbox )
        v3 = SmartBox::smartbox->player_id;
      else
        v3 = 0;
      if ( i_iidPlayer != v3 )
      {
        CM_Fellowship::Event_Dismiss(i_iidPlayer);
        return;
      }
      StringInfo::StringInfo(&siError);
      StringInfo::SetStringIDandTableEnum(&siError, ID_Fellowship_Error_CantDismissSelf, 268435457);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    }
    else
    {
      StringInfo::StringInfo(&siError);
      StringInfo::SetStringIDandTableEnum(&siError, ID_Fellowship_Error_DismisseeNotInFellowship, 268435457);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    }
    StringInfo::~StringInfo(&siError);
  }
}

//----- (0048E530) --------------------------------------------------------  // acclient.c:201879
void __thiscall gmFellowshipUI::RecruitFellow(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@2
  unsigned int v4; // eax@7
  StringInfo siError; // [sp+4h] [bp-90h]@10

  v2 = this;
  if ( this->m_pFellowship )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(i_iidPlayer);
    if ( v3 )
    {
      if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v3->vfptr[4].__vecDelDtor)(v3) )
      {
        if ( Fellowship::IsFellow((Fellowship *)&v2->m_pFellowship->vfptr, i_iidPlayer) )
        {
          if ( SmartBox::smartbox )
            v4 = SmartBox::smartbox->player_id;
          else
            v4 = 0;
          if ( i_iidPlayer == v4 )
          {
            StringInfo::StringInfo(&siError);
            StringInfo::SetStringIDandTableEnum(&siError, ID_Fellowship_Error_CantRecruitSelf, 268435457);
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          }
          else
          {
            StringInfo::StringInfo(&siError);
            StringInfo::SetStringIDandTableEnum(&siError, ID_Fellowship_Error_PlayerAlreadyInFellowship, 268435457);
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          }
          StringInfo::~StringInfo(&siError);
        }
        else
        {
          CM_Fellowship::Event_Recruit(i_iidPlayer);
        }
      }
    }
  }
}

//----- (0048E610) --------------------------------------------------------  // acclient.c:201924
PackableHashIterator<unsigned long,Fellow> *__thiscall PackableHashIterator<unsigned long,Fellow>::vector_deleting_destructor(PackableHashIterator<unsigned long,Fellow> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,Fellow> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,Fellow>Vtbl *)PackableHashIterator<unsigned long,Fellow>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7A5158: using guessed type int (__thiscall *PackableHashIterator<unsigned long,Fellow>::vftable[2])(void *, char);

//----- (0048E630) --------------------------------------------------------  // acclient.c:201937
void __thiscall gmFellowshipUI::~gmFellowshipUI(gmFellowshipUI *this)
{
  gmFellowshipUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmFellowshipUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmFellowshipUI::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  DialogFactory::CloseDialog(v1->m_fellowRequestContext);
  v1->m_fellowRequestContext = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A4D78: using guessed type bool (__thiscall *gmFellowshipUI::vftable)(DBCache *this);
// 7A5020: using guessed type int (__thiscall *gmFellowshipUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0048E6A0) --------------------------------------------------------  // acclient.c:201963
void __cdecl gmFellowshipUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000002Du,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmFellowshipUI::Create);
}

//----- (0048E6C0) --------------------------------------------------------  // acclient.c:201971
void __usercall gmFellowshipUI::UpdateButtons(gmFellowshipUI *this@<ecx>, int a2@<edi>)
{
  gmFellowshipUI *v2; // esi@1
  unsigned int v3; // eax@3
  unsigned int v4; // edi@6
  HashBaseData<unsigned long> *v5; // eax@6
  int v6; // eax@8
  UIElement_Button *v7; // ecx@8
  IInputActionCallbackVtbl *v8; // edi@10
  int v9; // eax@10
  unsigned int v10; // edi@12
  unsigned int v11; // eax@14
  unsigned int v12; // eax@17
  signed int v13; // ST0C_4@19
  UIElement_Button *v14; // ecx@20
  unsigned int v15; // edi@22
  HashBaseData<unsigned long> *v16; // eax@22
  int v17; // eax@24
  UIElement_Button *v18; // ecx@24
  IInputActionCallbackVtbl *v19; // edi@26
  int v20; // eax@26
  PStringBase<unsigned short> *v21; // eax@30
  char *v22; // esi@30
  PStringBase<unsigned short> *v23; // eax@33
  char *v24; // esi@33
  PStringBase<unsigned short> result; // [sp+18h] [bp-94h]@30
  StringInfo v26; // [sp+1Ch] [bp-90h]@30

  v2 = this;
  if ( !this->m_pFellowship )
    return;
  ((void (__stdcall *)(signed int))this->m_pFellowQuitButton->vfptr[13].__vecDelDtor)(1);
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  if ( v2->m_pFellowship->_leader == v3 )
  {
    ((void (__stdcall *)(signed int, int))v2->m_pFellowDisbandButton->vfptr[13].__vecDelDtor)(1, a2);
    ((void (__stdcall *)(signed int))v2->m_pFellowOpenButton->vfptr[13].__vecDelDtor)(1);
    v4 = ACCWeenieObject::selectedID;
    v5 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
    if ( v5 && ((int (__thiscall *)(HashBaseData<unsigned long> *))v5->vfptr[4].__vecDelDtor)(v5) )
    {
      v6 = Fellowship::IsFellow((Fellowship *)&v2->m_pFellowship->vfptr, v4);
      v7 = v2->m_pFellowRecruitButton;
      if ( v6 )
      {
        ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(13);
      }
      else
      {
        v8 = v7->vfptr;
        v9 = Fellowship::IsFull((Fellowship *)&v2->m_pFellowship->vfptr);
        v8[13].__vecDelDtor((IInputActionCallback *)v2->m_pFellowRecruitButton, v9 != 0 ? 13 : 1);
      }
    }
    else
    {
      ((void (__stdcall *)(signed int))v2->m_pFellowRecruitButton->vfptr[13].__vecDelDtor)(13);
    }
    v10 = v2->m_iidSelectedFellow;
    if ( v10 )
    {
      if ( SmartBox::smartbox )
        v11 = SmartBox::smartbox->player_id;
      else
        v11 = 0;
      ((void (__stdcall *)(signed int))v2->m_pFellowDismissButton->vfptr[13].__vecDelDtor)(v10 == v11 ? 13 : 1);
      if ( SmartBox::smartbox )
        v12 = SmartBox::smartbox->player_id;
      else
        v12 = 0;
      v13 = v2->m_iidSelectedFellow == v12 ? 13 : 1;
      ((void (*)(void))v2->m_pFellowLeaderButton->vfptr[13].__vecDelDtor)();
      goto LABEL_29;
    }
    ((void (__cdecl *)(signed int))v2->m_pFellowDismissButton->vfptr[13].__vecDelDtor)(13);
    v14 = v2->m_pFellowLeaderButton;
  }
  else
  {
    ((void (__stdcall *)(signed int))v2->m_pFellowLeaderButton->vfptr[13].__vecDelDtor)(13);
    ((void (__stdcall *)(signed int))v2->m_pFellowDisbandButton->vfptr[13].__vecDelDtor)(13);
    ((void (__stdcall *)(signed int))v2->m_pFellowDismissButton->vfptr[13].__vecDelDtor)(13);
    ((void (__stdcall *)(signed int))v2->m_pFellowOpenButton->vfptr[13].__vecDelDtor)(13);
    if ( v2->m_pFellowship->_open_fellow )
    {
      v15 = ACCWeenieObject::selectedID;
      v16 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
      if ( v16 && ((int (__thiscall *)(HashBaseData<unsigned long> *))v16->vfptr[4].__vecDelDtor)(v16) )
      {
        v17 = Fellowship::IsFellow((Fellowship *)&v2->m_pFellowship->vfptr, v15);
        v18 = v2->m_pFellowRecruitButton;
        if ( v17 )
        {
          ((void (__stdcall *)(signed int))v18->vfptr[13].__vecDelDtor)(13);
        }
        else
        {
          v19 = v18->vfptr;
          v20 = Fellowship::IsFull((Fellowship *)&v2->m_pFellowship->vfptr);
          v19[13].__vecDelDtor((IInputActionCallback *)v2->m_pFellowRecruitButton, v20 != 0 ? 13 : 1);
        }
      }
      goto LABEL_29;
    }
    v14 = v2->m_pFellowRecruitButton;
  }
  ((void (__stdcall *)(signed int))v14->vfptr[13].__vecDelDtor)(13);
LABEL_29:
  if ( v2->m_pFellowship->_open_fellow )
  {
    StringInfo::StringInfo(&v26);
    StringInfo::SetStringIDandTableEnum(&v26, ID_Fellowship_CloseFellowshipButtonText, 268435457);
    v21 = StringInfo::GetString(&v26, &result, 0);
    UIElement_Text::SetText((UIElement_Text *)&v2->m_pFellowOpenButton->vfptr, v21);
    v22 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v22 )
    {
      (**(void (__thiscall ***)(char *, signed int))v22)(v22, 1);
      StringInfo::~StringInfo(&v26);
      return;
    }
  }
  else
  {
    StringInfo::StringInfo(&v26);
    StringInfo::SetStringIDandTableEnum(&v26, ID_Fellowship_OpenFellowshipButtonText, 268435457);
    v23 = StringInfo::GetString(&v26, &result, 0);
    UIElement_Text::SetText((UIElement_Text *)&v2->m_pFellowOpenButton->vfptr, v23);
    v24 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v24 )
      (**(void (__thiscall ***)(char *, signed int))v24)(v24, 1);
  }
  StringInfo::~StringInfo(&v26);
}
// 48E6C0: could not find valid save-restore pair for ebx
// 48E6C0: could not find valid save-restore pair for edi

//----- (0048E9E0) --------------------------------------------------------  // acclient.c:202112
PackableHashIterator<unsigned long,Fellow> *__thiscall PackableHashTable<unsigned long,Fellow>::begin(PackableHashTable<unsigned long,Fellow> *this, PackableHashIterator<unsigned long,Fellow> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,Fellow> **v4; // edi@2
  PackableHashData<unsigned long,Fellow> **v5; // esi@2
  PackableHashData<unsigned long,Fellow> **v6; // ecx@5
  PackableHashIterator<unsigned long,Fellow> *v7; // eax@5
  PackableHashData<unsigned long,Fellow> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<unsigned long,Fellow>Vtbl *)PackableHashIterator<unsigned long,Fellow>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,Fellow>Vtbl *)PackableHashIterator<unsigned long,Fellow>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7A5158: using guessed type int (__thiscall *PackableHashIterator<unsigned long,Fellow>::vftable[2])(void *, char);

//----- (0048EA40) --------------------------------------------------------  // acclient.c:202157
void __thiscall Fellow::~Fellow(Fellow *this)
{
  Fellow *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1

  v1 = this;
  v2 = this->_name.m_buffer;
  this->vfptr = (PackObjVtbl *)&Fellow::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);

//----- (0048EA70) --------------------------------------------------------  // acclient.c:202173
Fellow *__thiscall Fellow::vector_deleting_destructor(Fellow *this, unsigned int a2)
{
  Fellow *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v2 = this;
  v3 = this->_name.m_buffer;
  this->vfptr = (PackObjVtbl *)&Fellow::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);

//----- (0048EAC0) --------------------------------------------------------  // acclient.c:202192
Fellow *__thiscall Fellowship::GetFellow(Fellowship *this, unsigned int fellow)
{
  unsigned int v2; // esi@1
  PackableHashData<unsigned long,Fellow> **v3; // ecx@2
  PackableHashData<unsigned long,Fellow> *v4; // edx@3
  Fellow *result; // eax@6

  v2 = this->_fellowship_table._table_size;
  if ( v2 && (v3 = this->_fellowship_table._buckets) != 0 && (v4 = v3[fellow % v2]) != 0 )
  {
    while ( fellow != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (0048EB00) --------------------------------------------------------  // acclient.c:202219
gmFellowshipUI *__thiscall gmFellowshipUI::vector_deleting_destructor(gmFellowshipUI *this, unsigned int a2)
{
  gmFellowshipUI *v2; // esi@1

  v2 = this;
  gmFellowshipUI::~gmFellowshipUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048EB20) --------------------------------------------------------  // acclient.c:202231
void __thiscall gmFellowshipUI::UpdateFellowStats(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI *v2; // ebx@1
  CFellowship *v3; // eax@1
  unsigned int v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@2
  int v7; // edx@3
  int v8; // ebp@7
  UIElement_ListBox *v9; // ecx@8
  unsigned int v10; // edi@8
  UIElement *v11; // esi@9
  UIElement *v12; // eax@12
  UIElement_Text *v13; // ebx@13
  CFellowship *v14; // ecx@14
  double v15; // st7@16
  PSRefBufferCharData<unsigned short> *v16; // esi@17
  double v17; // st7@17
  PStringBase<unsigned short> *v18; // eax@19
  char *v19; // esi@19
  float fXPPercentage; // [sp+4h] [bp-B4h]@14
  int c; // [sp+8h] [bp-B0h]@8
  gmFellowshipUI *v22; // [sp+Ch] [bp-ACh]@1
  unsigned int iid; // [sp+10h] [bp-A8h]@10
  PStringBase<unsigned short> result[2]; // [sp+14h] [bp-A4h]@17
  __int64 v25; // [sp+1Ch] [bp-9Ch]@17
  int v26; // [sp+24h] [bp-94h]@17
  StringInfo siFellowStats; // [sp+28h] [bp-90h]@19

  v2 = this;
  v3 = this->m_pFellowship;
  v4 = v3->_fellowship_table._table_size;
  v5 = (int)&v3->_fellowship_table;
  v22 = v2;
  if ( v4 )
  {
    v6 = *(_DWORD *)(v5 + 8);
    if ( v6 )
    {
      v7 = *(_DWORD *)(v6 + 4 * (i_iidPlayer % v4));
      if ( v7 )
      {
        while ( i_iidPlayer != *(_DWORD *)v7 )
        {
          v7 = *(_DWORD *)(v7 + 52);
          if ( !v7 )
            return;
        }
        v8 = v7 + 4;
        if ( v7 != -4 )
        {
          v9 = v2->m_pFellowsListBox;
          v10 = 0;
          c = 0;
          if ( (signed int)v9->m_listItems.m_num > 0 )
          {
            do
            {
              v11 = UIElement_ListBox::GetItem(v9, v10);
              if ( v11 )
              {
                if ( UIElement::GetAttribute_InstanceID(v11, 0x1000000Du, &iid) && iid == i_iidPlayer )
                {
                  v12 = UIElement::GetChildRecursive(v11, 0x10000284u);
                  if ( v12 )
                  {
                    v13 = (UIElement_Text *)v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
                    if ( v13 )
                    {
                      v14 = v22->m_pFellowship;
                      fXPPercentage = 0.0;
                      if ( v14->_share_xp )
                      {
                        if ( v14->_even_xp_split )
                        {
                          v15 = FellowshipSystem::GetEvenSplitXPPctg(v14->_fellowship_table._currNum);
                        }
                        else
                        {
                          v16 = (PSRefBufferCharData<unsigned short> *)Fellowship::CalculateExperienceProportionSum((Fellowship *)&v14->vfptr);
                          v17 = (double)(unsigned int)FellowshipSystem::GetExperienceProportion(*(_DWORD *)(v8 + 8));
                          result[1].m_charbuffer = v16;
                          v25 = 0i64;
                          v26 = 0;
                          v10 = c;
                          v15 = v17 / (double)(unsigned int)v16;
                        }
                        fXPPercentage = v15;
                      }
                      StringInfo::StringInfo(&siFellowStats);
                      StringInfo::SetStringIDandTableEnum(&siFellowStats, ID_Fellowship_FellowStats, 268435457);
                      StringInfo::AddVariable_Int(&siFellowStats, ID_Level, *(_DWORD *)(v8 + 8));
                      StringInfo::AddVariable_Int(
                        &siFellowStats,
                        ID_Experience,
                        (signed int)(unsigned __int64)(fXPPercentage * 100.0));
                      v18 = StringInfo::GetString(&siFellowStats, result, 0);
                      UIElement_Text::SetText(v13, v18);
                      v19 = (char *)&result[0].m_charbuffer[-1].m_data[6];
                      if ( !InterlockedDecrement((volatile LONG *)&result[0].m_charbuffer[-1].m_data[8]) )
                      {
                        if ( v19 )
                          (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
                      }
                      StringInfo::~StringInfo(&siFellowStats);
                    }
                  }
                }
              }
              v9 = v22->m_pFellowsListBox;
              ++v10;
              c = v10;
            }
            while ( (signed int)v10 < (signed int)v9->m_listItems.m_num );
          }
        }
      }
    }
  }
}

//----- (0048ED60) --------------------------------------------------------  // acclient.c:202353
void __thiscall gmFellowshipUI::UpdateFellowVitals(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI *v2; // ebp@1
  CFellowship *v3; // eax@1
  unsigned int v4; // ecx@1
  int v5; // eax@1
  int v6; // esi@2
  int v7; // edx@3
  int v8; // edi@7
  UIElement_ListBox *v9; // ecx@8
  unsigned int v10; // esi@8
  UIElement *v11; // ebx@9
  UIElement *v12; // eax@14
  UIElement *v13; // esi@15
  int v14; // ebp@16
  int v15; // eax@16
  float v16; // ST14_4@16
  UIElement *v17; // eax@16
  UIElement_Text *v18; // esi@17
  PStringBase<unsigned short> *v19; // eax@18
  UIElement *v20; // eax@19
  UIElement *v21; // esi@20
  int v22; // ebp@21
  int v23; // eax@21
  float v24; // ST14_4@21
  UIElement *v25; // eax@21
  UIElement_Text *v26; // esi@22
  PStringBase<unsigned short> *v27; // eax@23
  UIElement *v28; // eax@24
  UIElement *v29; // eax@25
  UIElement *v30; // esi@25
  signed int v31; // ebx@26
  signed int v32; // edi@26
  float v33; // ST14_4@26
  UIElement *v34; // eax@26
  UIElement_Text *v35; // esi@27
  PStringBase<unsigned short> *v36; // eax@28
  int nCurMana; // [sp+28h] [bp-9Ch]@16
  int nMaxMana; // [sp+2Ch] [bp-98h]@16
  unsigned int iid; // [sp+30h] [bp-94h]@10
  StringInfo siStats; // [sp+34h] [bp-90h]@18

  v2 = this;
  v3 = this->m_pFellowship;
  v4 = v3->_fellowship_table._table_size;
  v5 = (int)&v3->_fellowship_table;
  if ( v4 )
  {
    v6 = *(_DWORD *)(v5 + 8);
    if ( v6 )
    {
      v7 = *(_DWORD *)(v6 + 4 * (i_iidPlayer % v4));
      if ( v7 )
      {
        while ( i_iidPlayer != *(_DWORD *)v7 )
        {
          v7 = *(_DWORD *)(v7 + 52);
          if ( !v7 )
            return;
        }
        v8 = v7 + 4;
        if ( v7 != -4 )
        {
          v9 = v2->m_pFellowsListBox;
          v10 = 0;
          if ( (signed int)v9->m_listItems.m_num > 0 )
          {
            while ( 1 )
            {
              v11 = UIElement_ListBox::GetItem(v9, v10);
              if ( v11 )
              {
                if ( UIElement::GetAttribute_InstanceID(v11, 0x1000000Du, &iid) && iid == i_iidPlayer )
                  break;
              }
              v9 = v2->m_pFellowsListBox;
              ++v10;
              if ( (signed int)v10 >= (signed int)v9->m_listItems.m_num )
                return;
            }
            v12 = UIElement::GetChildRecursive(v11, 0x10000285u);
            if ( v12 )
            {
              v13 = (UIElement *)v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)7);
              if ( v13 )
              {
                v14 = *(_DWORD *)(v8 + 36);
                v15 = *(_DWORD *)(v8 + 24);
                nCurMana = *(_DWORD *)(v8 + 36);
                nMaxMana = v15;
                v16 = (double)nCurMana / (double)v15;
                UIElement::SetAttribute_Float(v13, 0x69u, v16);
                v17 = UIElement::GetChildRecursive(v13, 0x10000286u);
                if ( v17 )
                {
                  v18 = (UIElement_Text *)v17->vfptr[12].OnAction((IInputActionCallback *)v17, (InputEvent *)12);
                  if ( v18 )
                  {
                    StringInfo::StringInfo(&siStats);
                    StringInfo::SetStringIDandTableEnum(&siStats, ID_Fellowship_FellowHealthStatus, 268435457);
                    StringInfo::AddVariable_Int(&siStats, ID_Cur, v14);
                    StringInfo::AddVariable_Int(&siStats, ID_Max, nMaxMana);
                    v19 = StringInfo::GetString(&siStats, (PStringBase<unsigned short> *)&nCurMana, 0);
                    UIElement_Text::SetText(v18, v19);
                    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nCurMana);
                    StringInfo::~StringInfo(&siStats);
                  }
                }
              }
            }
            v20 = UIElement::GetChildRecursive(v11, 0x10000287u);
            if ( v20 )
            {
              v21 = (UIElement *)v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)7);
              if ( v21 )
              {
                v22 = *(_DWORD *)(v8 + 40);
                v23 = *(_DWORD *)(v8 + 28);
                nCurMana = *(_DWORD *)(v8 + 40);
                nMaxMana = v23;
                v24 = (double)nCurMana / (double)v23;
                UIElement::SetAttribute_Float(v21, 0x69u, v24);
                v25 = UIElement::GetChildRecursive(v21, 0x10000288u);
                if ( v25 )
                {
                  v26 = (UIElement_Text *)v25->vfptr[12].OnAction((IInputActionCallback *)v25, (InputEvent *)12);
                  if ( v26 )
                  {
                    StringInfo::StringInfo(&siStats);
                    StringInfo::SetStringIDandTableEnum(&siStats, ID_Fellowship_FellowStaminaStatus, 268435457);
                    StringInfo::AddVariable_Int(&siStats, ID_Cur, v22);
                    StringInfo::AddVariable_Int(&siStats, ID_Max, nMaxMana);
                    v27 = StringInfo::GetString(&siStats, (PStringBase<unsigned short> *)&nCurMana, 0);
                    UIElement_Text::SetText(v26, v27);
                    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nCurMana);
                    StringInfo::~StringInfo(&siStats);
                  }
                }
              }
            }
            v28 = UIElement::GetChildRecursive(v11, 0x10000289u);
            if ( v28 )
            {
              v29 = (UIElement *)v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)7);
              v30 = v29;
              if ( v29 )
              {
                v31 = *(_DWORD *)(v8 + 44);
                v32 = *(_DWORD *)(v8 + 32);
                nCurMana = v31;
                nMaxMana = v32;
                v33 = (double)v31 / (double)v32;
                UIElement::SetAttribute_Float(v29, 0x69u, v33);
                v34 = UIElement::GetChildRecursive(v30, 0x1000028Au);
                if ( v34 )
                {
                  v35 = (UIElement_Text *)v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)12);
                  if ( v35 )
                  {
                    StringInfo::StringInfo(&siStats);
                    StringInfo::SetStringIDandTableEnum(&siStats, ID_Fellowship_FellowManaStatus, 268435457);
                    StringInfo::AddVariable_Int(&siStats, ID_Cur, v31);
                    StringInfo::AddVariable_Int(&siStats, ID_Max, v32);
                    v36 = StringInfo::GetString(&siStats, (PStringBase<unsigned short> *)&nCurMana, 0);
                    UIElement_Text::SetText(v35, v36);
                    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nCurMana);
                    StringInfo::~StringInfo(&siStats);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//----- (0048F0F0) --------------------------------------------------------  // acclient.c:202532
void __usercall gmFellowshipUI::UpdateFellowSelection(gmFellowshipUI *this@<ecx>, int a2@<edi>)
{
  _Formatted v2; // ebp@1
  gmFellowshipUI *v3; // esi@1
  unsigned int v4; // ecx@1
  unsigned int v5; // ebx@1
  UIElement *v6; // eax@2
  UIElement_ListBox *v7; // ecx@9
  unsigned int iidFellow; // [sp+10h] [bp-8h]@3
  UIElement *pOldSelectedFellowField; // [sp+14h] [bp-4h]@1

  v2 = ACCWeenieObject::selectedID;
  v3 = this;
  v4 = this->m_pFellowsListBox->m_listItems.m_num;
  v5 = 0;
  pOldSelectedFellowField = 0;
  if ( (signed int)v4 <= 0 )
  {
LABEL_8:
    UIElement_ListBox::SetSelectedItem(v3->m_pFellowsListBox, pOldSelectedFellowField, 0);
    gmFellowshipUI::UpdateButtons(v3, a2);
    return;
  }
  while ( 1 )
  {
    v6 = UIElement_ListBox::GetItem(v3->m_pFellowsListBox, v5);
    a2 = (int)v6;
    if ( !v6 )
      goto LABEL_7;
    iidFellow = 0;
    if ( !UIElement::GetAttribute_InstanceID(v6, 0x1000000Du, &iidFellow) )
      goto LABEL_7;
    if ( v2 == iidFellow )
      break;
    if ( iidFellow == v3->m_iidSelectedFellow )
      pOldSelectedFellowField = (UIElement *)a2;
LABEL_7:
    ++v5;
    if ( (signed int)v5 >= (signed int)v3->m_pFellowsListBox->m_listItems.m_num )
      goto LABEL_8;
  }
  v7 = v3->m_pFellowsListBox;
  v3->m_iidSelectedFellow = v2;
  UIElement_ListBox::SetSelectedItem(v7, (UIElement *)a2, 0);
}

//----- (0048F1C0) --------------------------------------------------------  // acclient.c:202579
void __usercall gmFellowshipUI::RecvNotice_SelectionChanged(gmFellowshipUI *this@<ecx>, int a2@<edi>)
{
  if ( this->m_hashElementsRegisteredWith.vfptr )
    gmFellowshipUI::UpdateFellowSelection((gmFellowshipUI *)((char *)this - 1528), a2);
}

//----- (0048F1E0) --------------------------------------------------------  // acclient.c:202586
void __thiscall gmFellowshipUI::AssignLeadershipToFellow(gmFellowshipUI *this, unsigned int i_iidFellow)
{
  Fellowship *v2; // ecx@1
  char *v3; // esi@3
  unsigned int v4; // eax@8
  PStringBase<unsigned short> _value; // [sp+0h] [bp-94h]@3
  StringInfo siError; // [sp+4h] [bp-90h]@3

  v2 = (Fellowship *)&this->m_pFellowship->vfptr;
  if ( v2 )
  {
    if ( Fellowship::IsFellow(v2, i_iidFellow) )
    {
      if ( SmartBox::smartbox )
        v4 = SmartBox::smartbox->player_id;
      else
        v4 = 0;
      if ( i_iidFellow != v4 )
      {
        CM_Fellowship::Event_AssignNewLeader(i_iidFellow);
        return;
      }
      StringInfo::StringInfo(&siError);
      StringInfo::SetStringIDandTableEnum(&siError, ID_Fellowship_Error_SelfAlreadyLeader, 268435457);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    }
    else
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"That person is not in the fellowship.");
      StringInfo::SetLiteralValue(&siError, &_value, 1);
      v3 = (char *)&_value.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    }
    StringInfo::~StringInfo(&siError);
  }
}

//----- (0048F2C0) --------------------------------------------------------  // acclient.c:202630
void __thiscall gmFellowshipUI::RecvNotice_CloseDialog(gmFellowshipUI *this, unsigned int context, PropertyCollection *data)
{
  PropertyCollection *v3; // esi@1
  unsigned int v4; // edx@1
  HashTableData<unsigned long,BaseProperty> **v5; // eax@1
  gmFellowshipUI *v6; // edi@1
  HashTableData<unsigned long,BaseProperty> *v7; // eax@1
  unsigned int v8; // edx@9
  HashTableData<unsigned long,BaseProperty> **v9; // eax@9
  int v10; // ecx@9
  HashTableData<unsigned long,BaseProperty> *v11; // eax@9
  int v12; // ST08_4@17
  unsigned int v13; // ST04_4@17
  int v14; // ecx@19
  int v15; // edx@19
  int v16; // edx@23
  BasePropertyDesc *v17; // ecx@26
  unsigned int v18; // edx@26
  BasePropertyValue *v19; // ecx@30
  unsigned int v20; // edx@30
  unsigned int type; // [sp+Ch] [bp-14h]@1
  int v22; // [sp+10h] [bp-10h]@9
  int v23; // [sp+14h] [bp-Ch]@9
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
    v10 = 0;
    LOBYTE(data) = 0;
    v22 = 0;
    v23 = 0;
    v11 = v9[v8];
    if ( v11 )
    {
      while ( v11->m_hashKey != 146 )
      {
        v11 = v11->m_hashNext;
        if ( !v11 )
          goto LABEL_16;
      }
      if ( v11 )
      {
        BaseProperty::operator=(&v22, (int)&v11->m_data);
        v10 = v23;
        if ( v23 )
        {
          (*(void (__stdcall **)(PropertyCollection **))(*(_DWORD *)v23 + 112))(&data);
          v10 = v23;
        }
      }
    }
LABEL_16:
    if ( v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] == (HashSetData<UIElement *> *)context )
    {
      v12 = (unsigned __int8)data;
      v13 = (unsigned int)v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
      v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = 0;
      CM_Character::Event_ConfirmationResponse(4, v13, v12);
      v10 = v23;
      v6->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] = 0;
    }
    if ( v22 )
    {
      v14 = v22;
      v15 = *(_DWORD *)(v22 + 4) - 1;
      *(_DWORD *)(v22 + 4) = v15;
      if ( !v15 )
        (**(void (__stdcall ***)(_DWORD))v14)(1);
      v10 = v23;
      v22 = 0;
    }
    if ( v10 )
    {
      v16 = *(_DWORD *)(v10 + 4) - 1;
      *(_DWORD *)(v10 + 4) = v16;
      if ( !v16 )
        (**(void (__stdcall ***)(_DWORD))v10)(1);
    }
  }
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v17 = p.m_pcPropertyDesc;
    v18 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v18;
    if ( !v18 )
      ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v19 = p.m_pcPropertyValue;
    v20 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v20;
    if ( !v20 )
      ((void (__stdcall *)(signed int))v19->vfptr->__vecDelDtor)(1);
  }
}

//----- (0048F440) --------------------------------------------------------  // acclient.c:202755
void __thiscall gmFellowshipUI::Update(gmFellowshipUI *this)
{
  gmFellowshipUI *v1; // ebp@1
  CFellowship *v2; // eax@3
  CFellowship *v3; // eax@4
  ClientFellowshipSystem *v4; // eax@7
  CFellowship *v5; // ecx@8
  CFellowship *v6; // eax@11
  PStringBase<unsigned short> *v7; // eax@12
  LONG (__stdcall *v8)(volatile LONG *); // edi@12
  char *v9; // esi@12
  PStringBase<unsigned short> *v10; // eax@15
  char *v11; // esi@15
  PackableHashData<unsigned long,Fellow> *v12; // ebx@18
  int v13; // eax@20
  UIElement *v14; // esi@20
  UIElement *v15; // eax@21
  IInputActionCallbackVtbl *v16; // edx@22
  AC1Legacy::PSRefBuffer<char> *v17; // esi@23
  unsigned int v18; // ecx@23
  ReferenceCountTemplate<268435456,0>Vtbl *v19; // edx@25
  PStringBase<unsigned short> *v20; // eax@26
  char *v21; // esi@26
  int v22; // edx@28
  unsigned int v23; // eax@33
  unsigned int v24; // [sp+8h] [bp-150h]@11
  UIElement_Text *pFellowName; // [sp+1Ch] [bp-13Ch]@12
  unsigned int iidFellow; // [sp+20h] [bp-138h]@21
  PStringBase<unsigned short> result; // [sp+24h] [bp-134h]@26
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+28h] [bp-130h]@18
  StringInfo siFellowName; // [sp+38h] [bp-120h]@23
  StringInfo siFellowshipName; // [sp+C8h] [bp-90h]@12

  v1 = this;
  if ( ClientFellowshipSystem::GetFellowshipSystem()->m_pFellowship )
  {
    if ( !v1->m_pFellowship )
    {
      v2 = (CFellowship *)operator new(0x44u);
      if ( v2 )
        CFellowship::CFellowship(v2);
      else
        v3 = 0;
      v1->m_pFellowship = v3;
    }
    v4 = ClientFellowshipSystem::GetFellowshipSystem();
    Fellowship::operator=((int)v1->m_pFellowship, (int)v4->m_pFellowship);
  }
  else
  {
    v5 = v1->m_pFellowship;
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    v1->m_pFellowship = 0;
  }
  v6 = v1->m_pFellowship;
  v24 = 3;
  if ( v6 )
  {
    UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, v24);
    ((void (__stdcall *)(_DWORD))v1->m_pNotInAFellowshipFrame->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(signed int))v1->m_pInAFellowshipFrame->vfptr[2].__vecDelDtor)(1);
    StringInfo::StringInfo(&siFellowshipName);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&pFellowName,
      0,
      v1->m_pFellowship->_name.m_buffer->m_data);
    StringInfo::SetLiteralValue(&siFellowshipName, v7, 1);
    v8 = InterlockedDecrement;
    v9 = (char *)&pFellowName[-1].m_lastCursor.m_y1;
    if ( !InterlockedDecrement((volatile LONG *)&pFellowName[-1].m_downloadQueue) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    v10 = StringInfo::GetString(&siFellowshipName, (PStringBase<unsigned short> *)&pFellowName, 0);
    UIElement_Text::SetText(v1->m_pFellowshipName, v10);
    v11 = (char *)&pFellowName[-1].m_lastCursor.m_y1;
    if ( !InterlockedDecrement((volatile LONG *)&pFellowName[-1].m_downloadQueue) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    UIElement_ListBox::Flush(v1->m_pFellowsListBox);
    PackableHashTable<unsigned long,Fellow>::begin(&v1->m_pFellowship->_fellowship_table, &iter);
    v12 = iter._current;
    while ( v12 )
    {
      v13 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pFellowsListBox, 0, 0);
      v14 = (UIElement *)v13;
      if ( v13 )
      {
        v8 = (LONG (__stdcall *)(volatile LONG *))v12->_key;
        iidFellow = (unsigned int)v8;
        UIElement::SetAttribute_InstanceID((UIElement *)v13, 0x1000000Du, (unsigned int)v8);
        v15 = UIElement::GetChildRecursive(v14, 0x10000283u);
        if ( v15 )
        {
          v16 = v15->vfptr;
          v24 = 12;
          pFellowName = (UIElement_Text *)v16[12].OnAction((IInputActionCallback *)v15, (InputEvent *)12);
          if ( pFellowName )
          {
            StringInfo::StringInfo(&siFellowName);
            StringInfo::SetStringIDandTableEnum(&siFellowName, ID_Fellowship_FellowName, 268435457);
            v17 = v12->_data._name.m_buffer;
            InterlockedIncrement((volatile LONG *)&v17->m_cRef);
            v24 = v18;
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&v24,
              0,
              v17->m_data);
            StringInfo::AddVariable_String(&siFellowName, ID_Name, (PStringBase<unsigned short>)v24);
            if ( !InterlockedDecrement((volatile LONG *)&v17->m_cRef) && v17 )
            {
              v19 = v17->vfptr;
              v24 = 1;
              v19->__vecDelDtor(v17, 1);
            }
            v20 = StringInfo::GetString(&siFellowName, &result, 0);
            UIElement_Text::SetText(pFellowName, v20);
            v21 = (char *)&result.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
            {
              if ( v21 )
              {
                v22 = *(_DWORD *)v21;
                v24 = 1;
                (*(void (__thiscall **)(char *, signed int))v22)(v21, 1);
              }
            }
            StringInfo::~StringInfo(&siFellowName);
            v8 = (LONG (__stdcall *)(volatile LONG *))iidFellow;
          }
        }
        gmFellowshipUI::UpdateFellowStats(v1, (unsigned int)v8);
        gmFellowshipUI::UpdateFellowVitals(v1, (unsigned int)v8);
      }
      if ( v12->_next )
      {
        v12 = v12->_next;
      }
      else
      {
        v23 = v12->_hashVal + 1;
        if ( v23 >= iter._table_size )
        {
LABEL_36:
          v12 = 0;
        }
        else
        {
          while ( !iter._buckets[v23] )
          {
            ++v23;
            if ( v23 >= iter._table_size )
              goto LABEL_36;
          }
          v12 = iter._buckets[v23];
        }
      }
    }
    gmFellowshipUI::UpdateFellowSelection(v1, (int)v8);
    StringInfo::~StringInfo(&siFellowshipName);
  }
  else
  {
    UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, v24);
    ((void (__stdcall *)(_DWORD))v1->m_pInAFellowshipFrame->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(signed int))v1->m_pNotInAFellowshipFrame->vfptr[2].__vecDelDtor)(1);
  }
}

//----- (0048F730) --------------------------------------------------------  // acclient.c:202923
void __thiscall gmFellowshipUI::CreateFellowship(gmFellowshipUI *this)
{
  gmFellowshipUI *v1; // ebp@1
  PStringBase<unsigned short> *v2; // eax@1
  PSRefBufferCharData<char> *v3; // edi@1
  PSRefBufferCharData<char> *v4; // eax@1
  signed int v5; // edx@1
  char v6; // cl@2
  int v7; // edi@3
  char *v8; // edi@6
  PStringBase<unsigned short> *v9; // eax@9
  char *v10; // edi@9
  CPlayerSystem *v11; // eax@12
  unsigned __int8 v12; // bl@12
  PStringBase<unsigned short> *v13; // eax@12
  int v14; // eax@12
  PSRefBufferCharData<unsigned short> *v15; // ebx@12
  int v16; // ST04_4@12
  AC1Legacy::PStringBase<char> *v17; // eax@12
  PSRefBufferCharData<char> *v18; // edi@12
  char *v19; // edi@18
  PStringBase<char> v20; // [sp+10h] [bp-30h]@1
  PStringBase<unsigned short> result; // [sp+14h] [bp-2Ch]@1
  PStringBase<unsigned short> v22; // [sp+18h] [bp-28h]@12
  char FellName[34]; // [sp+1Ch] [bp-24h]@1

  v1 = this;
  v2 = UIElement_Text::GetText(this->m_pFellowshipNameEntryBox, &result);
  PStringBase<unsigned short>::to_spstring(v2, &v20, 0);
  v3 = v20.m_charbuffer;
  v4 = v20.m_charbuffer;
  v5 = FellName - (char *)v20.m_charbuffer;
  do
  {
    v6 = v4->m_data[0];
    v4->m_data[v5] = v4->m_data[0];
    v4 = (PSRefBufferCharData<char> *)((char *)v4 + 1);
  }
  while ( v6 );
  v7 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  v8 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  ACCharGenData::FormatName(FellName);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&result, 0, FellName);
  UIElement_Text::SetText(v1->m_pFellowshipNameEntryBox, v9);
  v10 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  v11 = CPlayerSystem::GetPlayerSystem();
  v12 = PlayerModule::FellowshipShareXP((PlayerModule *)&v11->playerModule.vfptr);
  v13 = UIElement_Text::GetText(v1->m_pFellowshipNameEntryBox, &v22);
  PStringBase<unsigned short>::to_spstring(v13, (PStringBase<char> *)&result, 0);
  v14 = v12;
  v15 = result.m_charbuffer;
  v16 = v14;
  AC1Legacy::PStringBase<char>::PStringBase<char>(
    (AC1Legacy::PStringBase<char> *)&v20,
    (const char *)result.m_charbuffer);
  CM_Fellowship::Event_Create(v17, v16);
  v18 = v20.m_charbuffer;
  if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer->m_data[4]) && v18 )
    (**(void (__thiscall ***)(PSRefBufferCharData<char> *, signed int))&v18->m_data[0])(v18, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v15[-1].m_data[8]) && v15 != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))&v15[-1].m_data[6])(&v15[-1].m_data[6], 1);
  v19 = (char *)&v22.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v22.m_charbuffer[-1].m_data[8]) )
  {
    if ( v19 )
      (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
  }
}

//----- (0048F8A0) --------------------------------------------------------  // acclient.c:202999
void __thiscall gmFellowshipUI::FellowshipDisbanded(gmFellowshipUI *this)
{
  gmFellowshipUI *v1; // edi@1
  CFellowship *v2; // ecx@1
  unsigned int v3; // eax@3
  ClientSystem *v4; // eax@6
  Fellow *v5; // eax@7
  ClientSystem *v6; // eax@7
  char *v7; // esi@7
  CFellowship *v8; // ecx@10
  PStringBase<unsigned short> msg; // [sp+0h] [bp-4h]@1

  msg.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  v2 = this->m_pFellowship;
  if ( v2 )
  {
    v1->m_iidSelectedFellow = 0;
    if ( SmartBox::smartbox )
      v3 = SmartBox::smartbox->player_id;
    else
      v3 = 0;
    if ( v2->_leader == v3 )
    {
      v4 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v4, "You have disbanded your Fellowship.\n", 0, 1, 0);
    }
    else
    {
      v5 = Fellowship::GetFellow((Fellowship *)&v2->vfptr, v2->_leader);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &msg,
        0,
        L"%hs has disbanded your Fellowship.\n",
        v5->_name.m_buffer->m_data);
      v6 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v6, &msg, 0, 1, 0);
      v7 = (char *)&msg.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
    v8 = v1->m_pFellowship;
    if ( v8 )
      ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    v1->m_pFellowship = 0;
    gmFellowshipUI::Update(v1);
  }
}

//----- (0048F970) --------------------------------------------------------  // acclient.c:203049
void __thiscall gmFellowshipUI::FellowDismissed(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI *v2; // esi@1
  CFellowship *v3; // ecx@1
  unsigned int v4; // eax@3
  unsigned int v5; // edi@5
  Fellow *v6; // eax@6
  ClientSystem *v7; // eax@6
  CFellowship *v8; // ecx@6
  unsigned int v9; // esi@8
  CFellowship *v10; // ebx@12
  Fellow *v11; // eax@12
  unsigned int v12; // ecx@15
  ClientSystem *v13; // eax@20
  Fellowship *v14; // ecx@20
  int v15; // [sp-8h] [bp-10h]@17

  v2 = this;
  v3 = this->m_pFellowship;
  if ( v3 )
  {
    v2->m_iidSelectedFellow = 0;
    if ( SmartBox::smartbox )
      v4 = SmartBox::smartbox->player_id;
    else
      v4 = 0;
    v5 = i_iidPlayer;
    if ( v4 == i_iidPlayer )
    {
      v2->m_iidSelectedFellow = 0;
      v6 = Fellowship::GetFellow((Fellowship *)&v3->vfptr, v3->_leader);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&i_iidPlayer,
        0,
        L"%hs has dismissed you from the Fellowship.\n",
        v6->_name.m_buffer->m_data);
      v7 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v7, (PStringBase<unsigned short> *)&i_iidPlayer, 0, 1, 0);
      v8 = v2->m_pFellowship;
      if ( v8 )
        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      v2->m_pFellowship = 0;
      gmFellowshipUI::Update(v2);
      v9 = i_iidPlayer - 20;
      if ( !InterlockedDecrement((volatile LONG *)(i_iidPlayer - 20 + 4)) )
      {
        if ( v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      }
    }
    else if ( Fellowship::IsFellow((Fellowship *)&v3->vfptr, i_iidPlayer) )
    {
      v10 = v2->m_pFellowship;
      v11 = Fellowship::GetFellow((Fellowship *)&v2->m_pFellowship->vfptr, v5);
      if ( v2->m_iidSelectedFellow == v5 )
        v2->m_iidSelectedFellow = 0;
      if ( SmartBox::smartbox )
        v12 = SmartBox::smartbox->player_id;
      else
        v12 = 0;
      v15 = (int)v11->_name.m_buffer->m_data;
      if ( v10->_leader == v12 )
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&i_iidPlayer,
          0,
          L"You dismiss %hs from your Fellowship.\n",
          v15);
      else
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&i_iidPlayer,
          0,
          L"%hs has been dismissed from the Fellowship.\n",
          v15);
      v13 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v13, (PStringBase<unsigned short> *)&i_iidPlayer, 0, 1, 0);
      v14 = (Fellowship *)&ClientFellowshipSystem::GetFellowshipSystem()->m_pFellowship->vfptr;
      if ( v14 )
        Fellowship::RemoveFellow(v14, v5);
      gmFellowshipUI::Update(v2);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_iidPlayer);
    }
  }
}
// 7A5298: using guessed type wchar_t aYouDismissHsFr[39];

//----- (0048FAE0) --------------------------------------------------------  // acclient.c:203135
void __thiscall gmFellowshipUI::FellowQuit(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI *v2; // esi@1
  CFellowship *v3; // ecx@1
  unsigned int v4; // eax@3
  unsigned int v5; // edi@5
  ClientSystem *v6; // eax@6
  CFellowship *v7; // ecx@6
  unsigned int v8; // esi@8
  Fellow *v9; // eax@12
  ClientSystem *v10; // eax@12
  Fellowship *v11; // ecx@12
  LONG v12; // eax@8

  v2 = this;
  v3 = this->m_pFellowship;
  if ( v3 )
  {
    if ( SmartBox::smartbox )
      v4 = SmartBox::smartbox->player_id;
    else
      v4 = 0;
    v5 = i_iidPlayer;
    if ( v4 == i_iidPlayer )
    {
      v2->m_iidSelectedFellow = 0;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&i_iidPlayer,
        0,
        L"You are no longer a member of the %hs Fellowship.\n",
        v3->_name.m_buffer->m_data);
      v6 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v6, (PStringBase<unsigned short> *)&i_iidPlayer, 0, 1, 0);
      v7 = v2->m_pFellowship;
      if ( v7 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
      v2->m_pFellowship = 0;
      gmFellowshipUI::Update(v2);
      v8 = i_iidPlayer - 20;
      v12 = InterlockedDecrement((volatile LONG *)(i_iidPlayer - 20 + 4));
    }
    else
    {
      if ( !Fellowship::IsFellow((Fellowship *)&v3->vfptr, i_iidPlayer) )
        return;
      if ( v2->m_iidSelectedFellow == v5 )
        v2->m_iidSelectedFellow = 0;
      v9 = Fellowship::GetFellow((Fellowship *)&v2->m_pFellowship->vfptr, v5);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&i_iidPlayer,
        0,
        L"%hs has left your Fellowship.\n",
        v9->_name.m_buffer->m_data);
      v10 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v10, (PStringBase<unsigned short> *)&i_iidPlayer, 0, 1, 0);
      v11 = (Fellowship *)&ClientFellowshipSystem::GetFellowshipSystem()->m_pFellowship->vfptr;
      if ( v11 )
        Fellowship::RemoveFellow(v11, v5);
      gmFellowshipUI::Update(v2);
      v8 = i_iidPlayer - 20;
      v12 = InterlockedDecrement((volatile LONG *)(i_iidPlayer - 20 + 4));
    }
    if ( !v12 )
    {
      if ( v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    }
  }
}

//----- (0048FC20) --------------------------------------------------------  // acclient.c:203206
void __thiscall gmFellowshipUI::FellowAdded(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI *v2; // esi@1
  ClientSystem *v3; // eax@1
  char *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // esi@4
  PStringBase<unsigned short> msg; // [sp+8h] [bp-34h]@1
  Fellow fellow; // [sp+Ch] [bp-30h]@1

  v2 = this;
  gmFellowshipUI::Update(this);
  Fellow::Fellow(&fellow);
  Fellowship::InqFellow((Fellowship *)&v2->m_pFellowship->vfptr, i_iidPlayer, &fellow);
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    &msg,
    0,
    L"%hs is now a member of your Fellowship.\n",
    fellow._name.m_buffer->m_data);
  v3 = (ClientSystem *)ClientUISystem::GetUISystem();
  ClientSystem::AddTextToScroll(v3, &msg, 0, 1, 0);
  v4 = (char *)&msg.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = fellow._name.m_buffer;
  fellow.vfptr = (PackObjVtbl *)&Fellow::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&fellow._name.m_buffer->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);

//----- (0048FCD0) --------------------------------------------------------  // acclient.c:203240
void __thiscall gmFellowshipUI::FellowUpdated(gmFellowshipUI *this, unsigned int i_iidPlayer, Fellow *i_fellow, unsigned int i_eUpdateType)
{
  gmFellowshipUI *v4; // esi@1

  v4 = this;
  switch ( i_eUpdateType )
  {
    case 3u:
      Fellowship::UpdateFellow((Fellowship *)&this->m_pFellowship->vfptr, i_iidPlayer, i_fellow);
      gmFellowshipUI::UpdateFellowVitals(v4, i_iidPlayer);
      break;
    case 2u:
      Fellowship::UpdateFellow((Fellowship *)&this->m_pFellowship->vfptr, i_iidPlayer, i_fellow);
      gmFellowshipUI::UpdateFellowStats(v4, i_iidPlayer);
      break;
    case 1u:
      gmFellowshipUI::Update(this);
      break;
  }
}

//----- (0048FD40) --------------------------------------------------------  // acclient.c:203262
void __thiscall gmFellowshipUI::PostInit(gmFellowshipUI *this)
{
  gmFellowshipUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  int v4; // edi@3
  unsigned int v5; // eax@5
  unsigned int v6; // eax@5
  UIElement *v7; // eax@5
  int v8; // eax@6
  int v9; // edi@7
  unsigned int v10; // eax@9
  unsigned int v11; // eax@9
  UIElement *v12; // eax@9
  int v13; // eax@10
  int v14; // edi@11
  unsigned int v15; // eax@13
  unsigned int v16; // eax@13
  UIElement *v17; // eax@13
  int v18; // eax@14
  int v19; // edi@15
  unsigned int v20; // eax@17
  unsigned int v21; // eax@17
  UIElement *v22; // eax@17
  int v23; // eax@18
  UIElement *v24; // eax@20
  int v25; // eax@21
  UIElement *v26; // eax@23
  int v27; // eax@24
  UIElement *v28; // eax@26
  int v29; // eax@27
  UIElement *v30; // eax@29
  int v31; // eax@30
  UIElement *v32; // eax@32
  int v33; // eax@33
  UIElement *v34; // eax@35
  int v35; // eax@36
  UIElement *v36; // eax@38
  int v37; // eax@39
  UIElement *v38; // eax@41
  int v39; // eax@42
  UIElement *v40; // eax@44
  int v41; // eax@45
  GlobalEventHandler *v42; // edi@47
  StringInfo _info; // [sp+58h] [bp-90h]@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  StringInfo::StringInfo(&_info);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000270u);
  if ( v2 && (v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)268435509)) != 0 )
    v4 = v3 - 32;
  else
    v4 = 0;
  UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)v4, IgnoreFellowshipRequests_PlayerOption);
  v5 = compute_str_hash("ID_PlayerOption_IgnoreFellowshipRequests");
  StringInfo::SetStringIDandTableEnum(&_info, v5, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)(v4 + 32), &_info);
  v6 = compute_str_hash("ID_PlayerOption_IgnoreFellowshipRequests_Help");
  StringInfo::SetStringIDandTableEnum(&_info, v6, 268435459);
  (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v4 + 692))(v4, &_info);
  v7 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000271u);
  if ( v7 && (v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)268435509)) != 0 )
    v9 = v8 - 32;
  else
    v9 = 0;
  UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)v9, FellowshipAutoAcceptRequests_PlayerOption);
  v10 = compute_str_hash("ID_PlayerOption_FellowshipAutoAcceptRequests");
  StringInfo::SetStringIDandTableEnum(&_info, v10, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)(v9 + 32), &_info);
  v11 = compute_str_hash("ID_PlayerOption_FellowshipAutoAcceptRequests_Help");
  StringInfo::SetStringIDandTableEnum(&_info, v11, 268435459);
  (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v9 + 692))(v9, &_info);
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000272u);
  if ( v12 && (v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)268435509)) != 0 )
    v14 = v13 - 32;
  else
    v14 = 0;
  UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)v14, FellowshipShareXP_PlayerOption);
  v15 = compute_str_hash("ID_PlayerOption_FellowshipShareXP");
  StringInfo::SetStringIDandTableEnum(&_info, v15, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)(v14 + 32), &_info);
  v16 = compute_str_hash("ID_PlayerOption_FellowshipShareXP_Help");
  StringInfo::SetStringIDandTableEnum(&_info, v16, 268435459);
  (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v14 + 692))(v14, &_info);
  v17 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000273u);
  if ( v17 && (v18 = v17->vfptr[12].OnAction((IInputActionCallback *)v17, (InputEvent *)268435509)) != 0 )
    v19 = v18 - 32;
  else
    v19 = 0;
  UIOption_Checkbox::SetPlayerOption((UIOption_Checkbox *)v19, FellowshipShareLoot_PlayerOption);
  v20 = compute_str_hash("ID_PlayerOption_FellowshipShareLoot");
  StringInfo::SetStringIDandTableEnum(&_info, v20, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)(v19 + 32), &_info);
  v21 = compute_str_hash("ID_PlayerOption_FellowshipShareLoot_Help");
  StringInfo::SetStringIDandTableEnum(&_info, v21, 268435459);
  (*(void (__thiscall **)(int, StringInfo *))(*(_DWORD *)v19 + 692))(v19, &_info);
  v1->m_pNotInAFellowshipFrame = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000026Bu);
  v1->m_pInAFellowshipFrame = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000275u);
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000026Fu);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)12);
  else
    v23 = 0;
  v1->m_pFellowshipNameEntryBox = (UIElement_Text *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000274u);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)1);
  else
    v25 = 0;
  v1->m_pCreateFellowshipButton = (UIElement_Button *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000276u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)12);
  else
    v27 = 0;
  v1->m_pFellowshipName = (UIElement_Text *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000279u);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)5);
  else
    v29 = 0;
  v1->m_pFellowsListBox = (UIElement_ListBox *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000027Bu);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)1);
  else
    v31 = 0;
  v1->m_pFellowLeaderButton = (UIElement_Button *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000027Cu);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)1);
  else
    v33 = 0;
  v1->m_pFellowQuitButton = (UIElement_Button *)v33;
  v34 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000027Du);
  if ( v34 )
    v35 = v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)1);
  else
    v35 = 0;
  v1->m_pFellowOpenButton = (UIElement_Button *)v35;
  v36 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000027Eu);
  if ( v36 )
    v37 = v36->vfptr[12].OnAction((IInputActionCallback *)v36, (InputEvent *)1);
  else
    v37 = 0;
  v1->m_pFellowRecruitButton = (UIElement_Button *)v37;
  v38 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000027Fu);
  if ( v38 )
    v39 = v38->vfptr[12].OnAction((IInputActionCallback *)v38, (InputEvent *)1);
  else
    v39 = 0;
  v1->m_pFellowDismissButton = (UIElement_Button *)v39;
  v40 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000280u);
  if ( v40 )
    v41 = v40->vfptr[12].OnAction((IInputActionCallback *)v40, (InputEvent *)1);
  else
    v41 = 0;
  v1->m_pFellowDisbandButton = (UIElement_Button *)v41;
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  v42 = GlobalEventHandler::GetGlobalEventHandler();
  v42->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v42, (unsigned int)&loc_4DD20F, (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v42,
    (unsigned int)((char *)&loc_4DD20F + 1),
    (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v42, (unsigned int)&loc_4DD211, (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v42, 5100102u, (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v42,
    (unsigned int)((char *)&loc_4DD211 + 1),
    (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v42, (unsigned int)&loc_4DD213, (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v42,
    (unsigned int)((char *)&loc_4DD213 + 1),
    (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler(
    (NoticeRegistrar *)v42,
    (unsigned int)((char *)&loc_4DD1EE + 1),
    (NoticeHandler *)&v1->vfptr);
  v42->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v42, 100004u, (NoticeHandler *)&v1->vfptr);
  gmFellowshipUI::Update(v1);
  StringInfo::~StringInfo(&_info);
}

//----- (004901C0) --------------------------------------------------------  // acclient.c:203449
UIElementMessageListenResult __userpurge gmFellowshipUI::ListenToElementMessage@<eax>(gmFellowshipUI *this@<ecx>, int a2@<edi>, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v3; // ebp@1
  gmFellowshipUI *v4; // esi@1
  UIElement_ListBox *v5; // edi@2
  unsigned int v6; // eax@2
  UIElement *v7; // eax@2
  Target_Mode v8; // ST04_4@5
  unsigned int v9; // ST00_4@5
  ClientUISystem *v10; // eax@5
  UIElementMessageListenResult v11; // eax@6
  bool v12; // bl@8
  char *v13; // edi@8
  UIElement_Button *v14; // ecx@11
  CFellowship *v15; // edi@17
  unsigned int v16; // eax@19
  CFellowship *v17; // eax@22
  PStringBase<unsigned short> result; // [sp+8h] [bp-4h]@8

  v3 = i_rMsg;
  v4 = this;
  switch ( i_rMsg->idMessage )
  {
    case 4u:
    case 0x43u:
      v5 = this->m_pFellowsListBox;
      v6 = UIElement_ListBox::GetSelectedIndex(this->m_pFellowsListBox);
      v7 = UIElement_ListBox::GetItem(v5, v6);
      if ( v7 )
      {
        UIElement::GetAttribute_InstanceID(v7, 0x1000000Du, (unsigned int *)&i_rMsg);
        if ( i_rMsg )
        {
          ACCWeenieObject::SetSelectedObject((unsigned int)i_rMsg, 0);
          if ( ClientUISystem::GetUISystem()->targetMode )
          {
            v8 = ClientUISystem::GetUISystem()->targetMode;
            v9 = (unsigned int)i_rMsg;
            v10 = ClientUISystem::GetUISystem();
            ClientUISystem::ExecuteTargetModeForItem(v10, v9, v8);
          }
        }
        v4->m_iidSelectedFellow = (unsigned int)i_rMsg;
        gmFellowshipUI::UpdateButtons(v4, (int)v5);
        v11 = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
      }
      else
      {
        v4->m_iidSelectedFellow = 0;
        gmFellowshipUI::UpdateButtons(v4, (int)v5);
        v11 = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
      }
      break;
    case 0x12u:
    case 0x44u:
      v12 = *(_DWORD *)&UIElement_Text::GetText(this->m_pFellowshipNameEntryBox, &result)->m_charbuffer[-1].m_data[14] == 1;
      v13 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v13 )
        (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
      v14 = v4->m_pCreateFellowshipButton;
      if ( v12 )
      {
        ((void (__stdcall *)(signed int))v14->vfptr[13].__vecDelDtor)(13);
        v11 = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
      }
      else
      {
        ((void (__stdcall *)(signed int))v14->vfptr[13].__vecDelDtor)(1);
        v11 = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
      }
      break;
    case 1u:
      switch ( i_rMsg->idElement )
      {
        case 0x10000274u:
          gmFellowshipUI::CreateFellowship(this);
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
        case 0x1000027Bu:
          gmFellowshipUI::AssignLeadershipToFellow(this, this->m_iidSelectedFellow);
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
        case 0x1000027Cu:
          v15 = this->m_pFellowship;
          if ( v15 )
          {
            if ( v15->_leader == GetPlayerID() )
            {
              v16 = Fellowship::GetNonLeaderFellowID((Fellowship *)&v15->vfptr);
              if ( v16 )
                gmFellowshipUI::AssignLeadershipToFellow(v4, v16);
            }
          }
          CM_Fellowship::Event_Quit(0);
          goto LABEL_27;
        case 0x1000027Du:
          v17 = this->m_pFellowship;
          if ( !v17 )
            goto LABEL_27;
          v17->_open_fellow = v17->_open_fellow == 0;
          CM_Fellowship::Event_ChangeFellowOpeness(this->m_pFellowship->_open_fellow);
          gmFellowshipUI::UpdateButtons(v4, a2);
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
        case 0x1000027Eu:
          gmFellowshipUI::RecruitFellow(this, ACCWeenieObject::selectedID);
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
        case 0x1000027Fu:
          gmFellowshipUI::DismissFellow(this, this->m_iidSelectedFellow);
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
        case 0x10000280u:
          CM_Fellowship::Event_Quit(1);
          break;
        default:
          goto LABEL_27;
      }
      goto LABEL_27;
    default:
LABEL_27:
      v11 = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v3);
      break;
  }
  return v11;
}

//----- (00490490) --------------------------------------------------------  // acclient.c:203572
void __thiscall gmFellowshipUI::RecvNotice_FellowshipUpdate(gmFellowshipUI *this, CFellowship *i_fellowship)
{
  gmFellowshipUI *v2; // edi@1
  HashSet<UIElement *>Vtbl *v3; // eax@1
  char v4; // bl@1
  CFellowship *v5; // eax@5
  HashSet<UIElement *>Vtbl *v6; // eax@6
  HashSet<UIElement *>Vtbl *v7; // esi@9
  unsigned int v8; // eax@11
  ClientSystem *v9; // eax@15
  char *v10; // esi@15
  Fellow *v11; // eax@17
  int v12; // ecx@17
  ClientSystem *v13; // eax@19
  LONG v14; // eax@15

  v2 = this;
  v3 = this->m_hashElementsRegisteredWith.vfptr;
  v4 = 0;
  if ( !v3 || !v3[5].__vecDelDtor )
    v4 = 1;
  if ( !v3 )
  {
    v5 = (CFellowship *)operator new(0x44u);
    if ( v5 )
      CFellowship::CFellowship(v5);
    else
      v6 = 0;
    v2->m_hashElementsRegisteredWith.vfptr = v6;
  }
  Fellowship::operator=((int)v2->m_hashElementsRegisteredWith.vfptr, (int)i_fellowship);
  v7 = v2->m_hashElementsRegisteredWith.vfptr;
  if ( v7 )
  {
    if ( SmartBox::smartbox )
      v8 = SmartBox::smartbox->player_id;
    else
      v8 = 0;
    if ( v7[7].__vecDelDtor == (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))v8 )
    {
      if ( v4 )
      {
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&i_fellowship,
          0,
          L"You have created the Fellowship of %hs.\n",
          (char *)v7[6].__vecDelDtor + 20);
        v9 = (ClientSystem *)ClientUISystem::GetUISystem();
        ClientSystem::AddTextToScroll(v9, (PStringBase<unsigned short> *)&i_fellowship, 0, 1, 0);
        v10 = (char *)&i_fellowship[-1]._fellows_departed;
        v14 = InterlockedDecrement(&i_fellowship[-1]._fellows_departed.m_fThrowawayDuplicateKeysOnUnPack);
LABEL_20:
        if ( !v14 )
        {
          if ( v10 )
            (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
        }
        goto LABEL_23;
      }
    }
    else if ( v4 )
    {
      v11 = Fellowship::GetFellow((Fellowship *)v7, (unsigned int)v7[7].__vecDelDtor);
      v12 = (int)L"an open";
      if ( !v7[10].__vecDelDtor )
        v12 = (int)L"a closed";
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&i_fellowship,
        0,
        L"You have been recruited into the %hs fellowship, %hs fellowship led by %hs.\n",
        (char *)v7[6].__vecDelDtor + 20,
        v12,
        v11->_name.m_buffer->m_data);
      v13 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v13, (PStringBase<unsigned short> *)&i_fellowship, 0, 1, 0);
      v10 = (char *)&i_fellowship[-1]._fellows_departed;
      v14 = InterlockedDecrement(&i_fellowship[-1]._fellows_departed.m_fThrowawayDuplicateKeysOnUnPack);
      goto LABEL_20;
    }
LABEL_23:
    gmFellowshipUI::Update((gmFellowshipUI *)((char *)v2 - 1528));
  }
}
// 7A5634: using guessed type wchar_t aAClosed[9];
// 7A5648: using guessed type wchar_t aAnOpen[8];

//----- (004905D0) --------------------------------------------------------  // acclient.c:203659
void __thiscall gmFellowshipUI::RecvNotice_FellowshipDisbanded(gmFellowshipUI *this)
{
  gmFellowshipUI::FellowshipDisbanded((gmFellowshipUI *)((char *)this - 1528));
}

//----- (004905E0) --------------------------------------------------------  // acclient.c:203665
void __thiscall gmFellowshipUI::RecvNotice_FellowQuit(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI::FellowQuit((gmFellowshipUI *)((char *)this - 1528), i_iidPlayer);
}

//----- (004905F0) --------------------------------------------------------  // acclient.c:203671
void __thiscall gmFellowshipUI::RecvNotice_FellowDismissed(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI::FellowDismissed((gmFellowshipUI *)((char *)this - 1528), i_iidPlayer);
}

//----- (00490600) --------------------------------------------------------  // acclient.c:203677
void __thiscall gmFellowshipUI::RecvNotice_FellowAdded(gmFellowshipUI *this, unsigned int i_iidPlayer)
{
  gmFellowshipUI::FellowAdded((gmFellowshipUI *)((char *)this - 1528), i_iidPlayer);
}

//----- (00490610) --------------------------------------------------------  // acclient.c:203683
void __thiscall gmFellowshipUI::RecvNotice_FellowUpdated(gmFellowshipUI *this, unsigned int i_iidPlayer, Fellow *i_fellow, unsigned int i_uiUpdateType)
{
  gmFellowshipUI::FellowUpdated((gmFellowshipUI *)((char *)this - 1528), i_iidPlayer, i_fellow, i_uiUpdateType);
}

//----- (00490620) --------------------------------------------------------  // acclient.c:203689
char __thiscall gmFellowshipUI::MakeFellowRequestDialog(gmFellowshipUI *this, PStringBase<char> i_strRequestor, unsigned int i_uiServerContextID)
{
  gmFellowshipUI *v3; // esi@1
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
  if ( this->m_fellowRequestContext )
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
  StringInfo::SetStringIDandTableEnum(&info, ID_Fellowship_FellowshipRequest, 268435457);
  v24.m_charbuffer = v5;
  PStringBase<char>::PStringBase<char>(&v24, i_strRequestor.m_charbuffer->m_data);
  StringInfo::AddVariable_String(&info, ID_Player, v24);
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
  v3->m_fellowRequestContext = v8;
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
  v3->m_uiAcceptFellowRequestServerContextID = i_uiServerContextID;
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

//----- (00490880) --------------------------------------------------------  // acclient.c:203844
void __thiscall gmFellowshipUI::RecvNotice_FellowshipRequest(gmFellowshipUI *this, AC1Legacy::PStringBase<char> *i_strRequestor, unsigned int i_uiContextID)
{
  AC1Legacy::PSRefBuffer<char> *v3; // eax@1
  gmFellowshipUI *v4; // esi@1
  unsigned int v5; // [sp-8h] [bp-Ch]@1
  unsigned int v6; // [sp-4h] [bp-8h]@1

  v3 = i_strRequestor->m_buffer;
  v4 = this;
  v6 = i_uiContextID;
  v5 = i_uiContextID;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v5, v3->m_data);
  gmFellowshipUI::MakeFellowRequestDialog((gmFellowshipUI *)((char *)v4 - 1528), (PStringBase<char>)v5, v6);
}

//----- (006EE130) --------------------------------------------------------  // acclient.c:770051
void _E91_55()
{
  outside_val_47 = 1000.0 + 1.0;
}

//----- (006EE150) --------------------------------------------------------  // acclient.c:770057
void _E93_31()
{
  block_length_47 = 24.0 * 8.0;
}

//----- (006EE170) --------------------------------------------------------  // acclient.c:770063
void _E95_31()
{
  half_square_length_47 = 24.0 * 0.5;
}

//----- (006EE190) --------------------------------------------------------  // acclient.c:770069
int _E97_56()
{
  return atexit(_E98_68);
}

//----- (006EE1A0) --------------------------------------------------------  // acclient.c:770075
int _E100_49()
{
  return atexit(_E101_86);
}

//----- (006EE1B0) --------------------------------------------------------  // acclient.c:770081
int _E103_41()
{
  return atexit(_E104_56);
}

//----- (006EE1C0) --------------------------------------------------------  // acclient.c:770087
void _E106_31()
{
  DEFAULT_VIEW_RADIUS_25 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EE1E0) --------------------------------------------------------  // acclient.c:770093
void _E108_22()
{
  MIN_QUANTUM_25 = 1.0 / 30.0;
}

//----- (006EE200) --------------------------------------------------------  // acclient.c:770099
void _E110_13()
{
  MAX_QUANTUM_25 = 1.0 / 5.0;
}

//----- (006EE220) --------------------------------------------------------  // acclient.c:770105
void _E112_27()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_60, PFID_A8R8G8B8);
}

//----- (006EE230) --------------------------------------------------------  // acclient.c:770111
void _E115_20()
{
  LOWEST_DATA_RATE_68 = 1024;
}

//----- (006EE240) --------------------------------------------------------  // acclient.c:770117
void _E117_17()
{
  HIGHEST_DATA_RATE_68 = 0x7FFF;
}

//----- (006EE250) --------------------------------------------------------  // acclient.c:770123
int _E119_6()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_68;
  INITIAL_MAX_DATA_RATE_16 = LOWEST_DATA_RATE_68;
  return result;
}

//----- (006EE260) --------------------------------------------------------  // acclient.c:770133
int _E121_27()
{
  return atexit(_E122_64);
}

//----- (006EE270) --------------------------------------------------------  // acclient.c:770139
int _E124_25()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_19, "Misc.TooltipEnable");
  return atexit(_E125_35);
}

//----- (006EE290) --------------------------------------------------------  // acclient.c:770146
int _E127_21()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_19, "Misc.TooltipDelay");
  return atexit(_E128_36);
}

//----- (006EE2B0) --------------------------------------------------------  // acclient.c:770153
unsigned int _E133_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_CloseFellowshipButtonText");
  ID_Fellowship_CloseFellowshipButtonText = result;
  return result;
}

//----- (006EE2D0) --------------------------------------------------------  // acclient.c:770163
unsigned int _E135_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_Error_CantDismissSelf");
  ID_Fellowship_Error_CantDismissSelf = result;
  return result;
}

//----- (006EE2F0) --------------------------------------------------------  // acclient.c:770173
unsigned int _E137_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_Error_CantRecruitSelf");
  ID_Fellowship_Error_CantRecruitSelf = result;
  return result;
}

//----- (006EE310) --------------------------------------------------------  // acclient.c:770183
unsigned int _E139_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_Error_DismisseeNotInFellowship");
  ID_Fellowship_Error_DismisseeNotInFellowship = result;
  return result;
}

//----- (006EE330) --------------------------------------------------------  // acclient.c:770193
unsigned int _E141_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_Error_PlayerAlreadyInFellowship");
  ID_Fellowship_Error_PlayerAlreadyInFellowship = result;
  return result;
}

//----- (006EE350) --------------------------------------------------------  // acclient.c:770203
unsigned int _E143_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_Error_SelfAlreadyLeader");
  ID_Fellowship_Error_SelfAlreadyLeader = result;
  return result;
}

//----- (006EE370) --------------------------------------------------------  // acclient.c:770213
unsigned int _E145_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_FellowHealthStatus");
  ID_Fellowship_FellowHealthStatus = result;
  return result;
}

//----- (006EE390) --------------------------------------------------------  // acclient.c:770223
unsigned int _E147_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_FellowManaStatus");
  ID_Fellowship_FellowManaStatus = result;
  return result;
}

//----- (006EE3B0) --------------------------------------------------------  // acclient.c:770233
unsigned int _E149_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_FellowName");
  ID_Fellowship_FellowName = result;
  return result;
}

//----- (006EE3D0) --------------------------------------------------------  // acclient.c:770243
unsigned int _E151_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_FellowshipRequest");
  ID_Fellowship_FellowshipRequest = result;
  return result;
}

//----- (006EE3F0) --------------------------------------------------------  // acclient.c:770253
unsigned int _E153_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_FellowStaminaStatus");
  ID_Fellowship_FellowStaminaStatus = result;
  return result;
}

//----- (006EE410) --------------------------------------------------------  // acclient.c:770263
unsigned int _E155()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_FellowStats");
  ID_Fellowship_FellowStats = result;
  return result;
}

//----- (006EE430) --------------------------------------------------------  // acclient.c:770273
unsigned int _E157_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Fellowship_OpenFellowshipButtonText");
  ID_Fellowship_OpenFellowshipButtonText = result;
  return result;
}

//----- (006EE450) --------------------------------------------------------  // acclient.c:770283
unsigned int _E159_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("CUR");
  ID_Cur = result;
  return result;
}

//----- (006EE470) --------------------------------------------------------  // acclient.c:770293
unsigned int _E161()
{
  unsigned int result; // eax@1

  result = compute_str_hash("EXPERIENCE");
  ID_Experience = result;
  return result;
}

//----- (006EE490) --------------------------------------------------------  // acclient.c:770303
unsigned int _E163_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("LEVEL");
  ID_Level = result;
  return result;
}

//----- (006EE4B0) --------------------------------------------------------  // acclient.c:770313
unsigned int _E165_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("MAX");
  ID_Max = result;
  return result;
}

//----- (006EE4D0) --------------------------------------------------------  // acclient.c:770323
unsigned int _E167()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PLAYER");
  ID_Player = result;
  return result;
}

//----- (006EE4F0) --------------------------------------------------------  // acclient.c:770333
unsigned int _E169_10()
{
  unsigned int result; // eax@1

  result = compute_str_hash("NAME");
  ID_Name = result;
  return result;
}

//----- (006EE510) --------------------------------------------------------  // acclient.c:770343
int sub_6EE510()
{
  return atexit(nullsub_900);
}

//----- (0075F810) --------------------------------------------------------  // acclient.c:887341
void __cdecl _E125_35()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075F840) --------------------------------------------------------  // acclient.c:887354
void __cdecl _E128_36()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

