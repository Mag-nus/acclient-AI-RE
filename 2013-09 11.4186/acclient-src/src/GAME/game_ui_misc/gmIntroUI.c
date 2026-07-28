/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmIntroUI
   Object     : GAME\game_ui_misc\gmIntroUI.obj
   Functions  : 16
   Addresses  : 004ED9F0 - 006F7560 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004ED9F0) --------------------------------------------------------  // acclient.c:282294
void __thiscall gmIntroUI::NextFrame(gmIntroUI *this)
{
  gmIntroUI *v1; // esi@1
  ListNode<unsigned long> *v2; // eax@1
  ListNode<unsigned long> *v3; // ecx@2
  unsigned int v4; // edi@5

  v1 = this;
  v2 = this->m_listStates._head;
  if ( v2 )
  {
    v3 = v2->next;
    v1->m_listStates._head = v3;
    if ( v3 )
      v3->prev = 0;
    else
      v1->m_listStates._tail = 0;
    v4 = v2->data;
    operator delete(v2);
    --v1->m_listStates._num_elements;
    ((void (__stdcall *)(_DWORD))v1->m_introField->vfptr[13].__vecDelDtor)(v4);
  }
  else
  {
    UIFramework::QueueUIMode(0x1000000Au);
  }
}

//----- (004EDA50) --------------------------------------------------------  // acclient.c:282323
signed int __thiscall gmIntroUI::ListenToElementMessage(gmIntroUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIFramework *v3; // esi@1
  signed int result; // eax@2

  v2 = i_rMsg->idMessage;
  v3 = (UIFramework *)this;
  if ( v2 == 268435469 )
  {
    gmIntroUI::NextFrame(this);
    result = UIFramework::ListenToElementMessage(v3, i_rMsg);
  }
  else
  {
    if ( v2 == 268435457 )
      UIFramework::QueueUIMode(0x1000000Au);
    result = UIFramework::ListenToElementMessage(v3, i_rMsg);
  }
  return result;
}

//----- (004EDAA0) --------------------------------------------------------  // acclient.c:282346
void __thiscall gmIntroUI::CharacterHandler(gmIntroUI *this, wchar_t _Char)
{
  gmIntroUI *v2; // esi@1

  v2 = this;
  if ( _Char == 27 )
    UIFramework::QueueUIMode(0x1000000Au);
  gmIntroUI::NextFrame((gmIntroUI *)((char *)v2 - 152));
}

//----- (004EDAD0) --------------------------------------------------------  // acclient.c:282357
char __thiscall gmIntroUI::OnAction(gmIntroUI *this, InputEvent *i_evt)
{
  char result; // al@2

  if ( i_evt->m_fStart )
  {
    if ( i_evt->m_InputAction == 39 )
    {
      UIFramework::QueueUIMode(0x1000000Au);
      result = 1;
    }
    else
    {
      gmIntroUI::NextFrame(this);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004EDB00) --------------------------------------------------------  // acclient.c:282382
void __thiscall gmIntroUI::gmIntroUI(gmIntroUI *this)
{
  gmIntroUI *v1; // edi@1
  int v2; // ebp@1
  int v3; // eax@1
  BasePropertyValue *v4; // ecx@2
  unsigned int v5; // esi@4
  BasePropertyValue *v6; // ecx@7
  BasePropertyDesc *v7; // ecx@12
  unsigned int v8; // edx@12
  int v9; // edx@16
  CInputManager *v10; // esi@21
  ListNode<unsigned long> *v11; // eax@23
  ListNode<unsigned long> *v12; // ecx@24
  unsigned int v13; // esi@27
  BasePropertyDesc *v14; // ecx@30
  unsigned int v15; // edx@30
  BasePropertyValue *v16; // ecx@33
  unsigned int v17; // edx@34
  unsigned int cElements; // [sp+38h] [bp-18h]@2
  unsigned int eStateID; // [sp+3Ch] [bp-14h]@7
  BaseProperty propCurItem; // [sp+40h] [bp-10h]@5
  BaseProperty propArray; // [sp+48h] [bp-8h]@1

  v1 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v1->vfptr = (CInputHandlerVtbl *)&CInputHandler::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmIntroUI::vftable;
  v1->vfptr = (CInputHandlerVtbl *)&gmIntroUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->m_introField = 0;
  v2 = (int)&v1->m_listStates;
  *(_DWORD *)v2 = List<unsigned long>::vftable;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  v3 = UIMainFramework::CreateAndAddRootElement((UIMainFramework *)&v1->vfptr, 0x10000002u, 0x10000419u);
  v1->m_introField = (UIElement *)v3;
  propArray.m_pcPropertyDesc = 0;
  propArray.m_pcPropertyValue = 0;
  if ( (unsigned __int8)(*(int (__thiscall **)(int, signed int, BaseProperty *))(*(_DWORD *)v3 + 208))(
                          v3,
                          268435527,
                          &propArray) )
  {
    v4 = propArray.m_pcPropertyValue;
    cElements = 0;
    if ( propArray.m_pcPropertyValue )
    {
      ((void (__stdcall *)(_DWORD))propArray.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&cElements);
      v4 = propArray.m_pcPropertyValue;
    }
    v5 = 0;
    if ( cElements > 0 )
    {
      while ( 1 )
      {
        propCurItem.m_pcPropertyDesc = 0;
        propCurItem.m_pcPropertyValue = 0;
        if ( v4 )
          break;
LABEL_20:
        ++v5;
        if ( v5 >= cElements )
          goto LABEL_21;
      }
      if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v4->vfptr[61].__vecDelDtor)(
                              v5,
                              &propCurItem) )
      {
        v6 = propCurItem.m_pcPropertyValue;
        eStateID = 0;
        if ( !propCurItem.m_pcPropertyValue )
        {
LABEL_11:
          if ( (_DWORD)propCurItem.m_pcPropertyDesc )
          {
            v7 = propCurItem.m_pcPropertyDesc;
            v8 = propCurItem.m_pcPropertyDesc->m_cRef - 1;
            propCurItem.m_pcPropertyDesc->m_cRef = v8;
            if ( !v8 )
              ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
            v6 = propCurItem.m_pcPropertyValue;
            propCurItem.m_pcPropertyDesc = 0;
          }
          if ( v6 )
          {
            v9 = v6->m_cRef - 1;
            v6->m_cRef = v9;
            if ( !v9 )
              ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
            propCurItem.m_pcPropertyValue = 0;
          }
          v4 = propArray.m_pcPropertyValue;
          goto LABEL_20;
        }
        if ( (unsigned __int8)((int (__stdcall *)(_DWORD))propCurItem.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&eStateID) )
          List<PFileNode *>::push_back(
            (List<UIElement_UIItem *> *)&v1->m_listStates,
            (UIElement_UIItem *const *)&eStateID);
      }
      v6 = propCurItem.m_pcPropertyValue;
      goto LABEL_11;
    }
  }
LABEL_21:
  v10 = ICIDM::s_cidm;
  if ( ICIDM::s_cidm )
  {
    ICIDM::s_cidm->vfptr->RegisterInputMap((ICIDM *)ICIDM::s_cidm, 9u, (IInputActionCallback *)v1, 3000);
    v10->vfptr->RegisterInputMap((ICIDM *)v10, 3u, (IInputActionCallback *)v1, 3000);
    v10->vfptr->SetTextMode((ICIDM *)v10, 1);
    v10->vfptr->RegisterInputHandler((ICIDM *)v10, (CInputHandler *)&v1->vfptr, 2u);
  }
  v11 = v1->m_listStates._head;
  if ( v11 )
  {
    v12 = v11->next;
    v1->m_listStates._head = v12;
    if ( v12 )
      v12->prev = 0;
    else
      v1->m_listStates._tail = 0;
    v13 = v11->data;
    operator delete(v11);
    --v1->m_listStates._num_elements;
    ((void (__stdcall *)(_DWORD))v1->m_introField->vfptr[13].__vecDelDtor)(v13);
  }
  else
  {
    UIFramework::QueueUIMode(0x1000000Au);
  }
  if ( (_DWORD)propArray.m_pcPropertyDesc )
  {
    v14 = propArray.m_pcPropertyDesc;
    v15 = propArray.m_pcPropertyDesc->m_cRef - 1;
    propArray.m_pcPropertyDesc->m_cRef = v15;
    if ( !v15 )
      ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
    propArray.m_pcPropertyDesc = 0;
  }
  v16 = propArray.m_pcPropertyValue;
  if ( propArray.m_pcPropertyValue )
  {
    v17 = propArray.m_pcPropertyValue->m_cRef - 1;
    propArray.m_pcPropertyValue->m_cRef = v17;
    if ( !v17 )
      ((void (__stdcall *)(_DWORD))v16->vfptr->__vecDelDtor)(1);
  }
}
// 79BA88: using guessed type void (__thiscall *CInputHandler::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3308: using guessed type void (__thiscall *gmIntroUI::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7C3320: using guessed type int (__thiscall *gmIntroUI::vftable)(void *, char);

//----- (004EDD40) --------------------------------------------------------  // acclient.c:282540
void __thiscall gmIntroUI::~gmIntroUI(gmIntroUI *this)
{
  gmIntroUI *v1; // esi@1
  char *v2; // ebx@1
  NoticeHandler *v3; // ebp@1
  CInputManager *v4; // edi@1

  v1 = this;
  v2 = (char *)&this->vfptr;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmIntroUI::vftable;
  this->vfptr = (CInputHandlerVtbl *)&gmIntroUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  UIMainFramework::RemoveRootElement((UIMainFramework *)&this->vfptr, &this->m_introField);
  v4 = ICIDM::s_cidm;
  if ( ICIDM::s_cidm )
  {
    ICIDM::s_cidm->vfptr->UnregisterCallback((ICIDM *)ICIDM::s_cidm, (IInputActionCallback *)v1);
    v4->vfptr->SetTextMode((ICIDM *)v4, 0);
    v4->vfptr->UnregisterInputHandler((ICIDM *)v4, (CInputHandler *)v2, 2u);
  }
  v1->m_listStates.vfptr = (List<unsigned long>Vtbl *)List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->m_listStates);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIMainFramework::~UIMainFramework((UIMainFramework *)&v1->vfptr);
}
// 7A2BE4: using guessed type int (__thiscall *List<unsigned long>::vftable[2])(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3308: using guessed type void (__thiscall *gmIntroUI::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7C3320: using guessed type int (__thiscall *gmIntroUI::vftable)(void *, char);

//----- (004EDDD0) --------------------------------------------------------  // acclient.c:282573
void __cdecl gmIntroUI::Create()
{
  gmIntroUI *v0; // eax@1

  v0 = (gmIntroUI *)operator new(0xB4u);
  if ( v0 )
    gmIntroUI::gmIntroUI(v0);
}

//----- (004EDDF0) --------------------------------------------------------  // acclient.c:282583
gmIntroUI *__thiscall gmIntroUI::scalar_deleting_destructor(gmIntroUI *this, unsigned int a2)
{
  gmIntroUI *v2; // esi@1

  v2 = this;
  gmIntroUI::~gmIntroUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004EDE10) --------------------------------------------------------  // acclient.c:282595
void __cdecl gmIntroUI::Register(unsigned int _mode)
{
  UIFlow::RegisterFrameworkClass(_mode, (UIMainFramework *(__cdecl *)())gmIntroUI::Create);
}

//----- (006F74D0) --------------------------------------------------------  // acclient.c:780067
void sub_6F74D0()
{
  flt_840C10 = 1000.0 + 1.0;
}

//----- (006F74F0) --------------------------------------------------------  // acclient.c:780073
void sub_6F74F0()
{
  flt_840C14 = 24.0 * 8.0;
}

//----- (006F7510) --------------------------------------------------------  // acclient.c:780079
void sub_6F7510()
{
  flt_840C18 = 24.0 * 0.5;
}

//----- (006F7530) --------------------------------------------------------  // acclient.c:780085
int sub_6F7530()
{
  return atexit(nullsub_485);
}

//----- (006F7540) --------------------------------------------------------  // acclient.c:780091
int sub_6F7540()
{
  return atexit(nullsub_486);
}

//----- (006F7550) --------------------------------------------------------  // acclient.c:780097
int sub_6F7550()
{
  return atexit(nullsub_487);
}

//----- (006F7560) --------------------------------------------------------  // acclient.c:780103
int sub_6F7560()
{
  return atexit(nullsub_484);
}

