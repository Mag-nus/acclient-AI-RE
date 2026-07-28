/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCGHeritagePage
   Object     : GAME\game_ui_misc\gmCGHeritagePage.obj
   Functions  : 24
   Addresses  : 004830A0 - 006ED270 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004830A0) --------------------------------------------------------  // acclient.c:190937
void __userpurge gmCGHeritagePage::gmCGHeritagePage(gmCGHeritagePage *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGHeritagePage *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pPlayerSystem = 0;
  v4->m_pAluButton = 0;
  v4->m_pGhuButton = 0;
  v4->m_pShoButton = 0;
  v4->m_pViaButton = 0;
  v4->m_pShadButton = 0;
  v4->m_pPenButton = 0;
  v4->m_pGearButton = 0;
  v4->m_pUndButton = 0;
  v4->m_pEmpButton = 0;
  v4->m_pAunTButton = 0;
  v4->m_pLugButton = 0;
  v4->m_pOlthoiButton = 0;
  v4->m_pOlthoiAcidButton = 0;
  v4->m_pText = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCGHeritagePage::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
}
// 7A0A08: using guessed type int (__thiscall *gmCGHeritagePage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00483130) --------------------------------------------------------  // acclient.c:190966
gmCGHeritagePage *__thiscall gmCGHeritagePage::DynamicCast(gmCGHeritagePage *this, unsigned int i_eType)
{
  gmCGHeritagePage *result; // eax@1

  result = this;
  if ( i_eType != 268435513 )
    result = (gmCGHeritagePage *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00483150) --------------------------------------------------------  // acclient.c:190977
signed int gmCGHeritagePage::GetUIElementType()
{
  return 268435513;
}

//----- (00483160) --------------------------------------------------------  // acclient.c:190983
void __usercall gmCGHeritagePage::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGHeritagePage *v3; // eax@1

  v3 = (gmCGHeritagePage *)operator new(0x640u);
  if ( v3 )
    gmCGHeritagePage::gmCGHeritagePage(v3, a1, _layout, _full_desc);
}

//----- (00483190) --------------------------------------------------------  // acclient.c:190993
UIElement_Field *__thiscall gmCGHeritagePage::vector_deleting_destructor(gmCGHeritagePage *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCGHeritagePage::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A0A08: using guessed type int (__thiscall *gmCGHeritagePage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004831F0) --------------------------------------------------------  // acclient.c:191017
void __cdecl gmCGHeritagePage::Register()
{
  UIElement::RegisterElementClass(
    0x10000039u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCGHeritagePage::Create);
}

//----- (00483210) --------------------------------------------------------  // acclient.c:191025
void __thiscall gmCGHeritagePage::Update(gmCGHeritagePage *this)
{
  gmCGHeritagePage *v1; // esi@1
  int v2; // eax@1
  int v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@1
  unsigned int v6; // eax@1
  int v7; // edi@1
  unsigned int v8; // eax@2
  unsigned int v9; // eax@16
  unsigned int v10; // eax@31
  char *v11; // edi@31
  int v12; // [sp+34h] [bp-1BCh]@0
  PStringBase<unsigned short> _text; // [sp+3Ch] [bp-1B4h]@31
  StringInfo siSkills; // [sp+40h] [bp-1B0h]@1
  StringInfo siRace; // [sp+D0h] [bp-120h]@1
  StringInfo siHeader; // [sp+160h] [bp-90h]@1

  v1 = this;
  ((void (__stdcall *)(signed int))this->m_pAluButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pGhuButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pShoButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pViaButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pShadButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pPenButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pGearButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pUndButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pEmpButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pAunTButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pLugButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pOlthoiButton->vfptr[13].__vecDelDtor)(268435478);
  ((void (__stdcall *)(signed int))v1->m_pOlthoiAcidButton->vfptr[13].__vecDelDtor)(268435478);
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  v3 = *(_DWORD *)(v2 + 212);
  StringInfo::StringInfo(&siRace);
  StringInfo::StringInfo(&siHeader);
  StringInfo::StringInfo(&siSkills);
  v4 = compute_str_hash("ID_CharGen_Heritage_StartingSkills_Header");
  StringInfo::SetStringIDandTableEnum(&siHeader, v4, 268435458);
  UIElement_Text::SetStringInfoWithFont(v1->m_pText, &siHeader, 0, 1);
  v5 = compute_str_hash("ID_CharGen_Heritage_StartingSkills");
  StringInfo::SetStringIDandTableEnum(&siSkills, v5, 268435458);
  UIElement_Text::AppendStringInfoWithFont(v1->m_pText, &siSkills, 0, 0);
  v6 = compute_str_hash("ID_CharGen_Heritage_BonusSkills_Trained_Header");
  StringInfo::SetStringIDandTableEnum(&siHeader, v6, 268435458);
  UIElement_Text::AppendStringInfoWithFont(v1->m_pText, &siHeader, 0, 1);
  v7 = v3 - 1;
  switch ( v7 )
  {
    case 0:
      v8 = compute_str_hash("ID_CharGen_AluvianText_BonusSkills_Trained");
      goto LABEL_14;
    case 1:
      v8 = compute_str_hash("ID_CharGen_GaruText_BonusSkills_Trained");
      goto LABEL_14;
    case 2:
      v8 = compute_str_hash("ID_CharGen_ShoText_BonusSkills_Trained");
      goto LABEL_14;
    case 3:
      v8 = compute_str_hash("ID_CharGen_ViaText_BonusSkills_Trained");
      goto LABEL_14;
    case 4:
    case 9:
      v8 = compute_str_hash("ID_CharGen_ShadText_BonusSkills_Trained");
      goto LABEL_14;
    case 5:
      v8 = compute_str_hash("ID_CharGen_GearText_BonusSkills_Trained");
      goto LABEL_14;
    case 10:
      v8 = compute_str_hash("ID_CharGen_UndText_BonusSkills_Trained");
      goto LABEL_14;
    case 8:
      v8 = compute_str_hash("ID_CharGen_EmpText_BonusSkills_Trained");
      goto LABEL_14;
    case 6:
      v8 = compute_str_hash("ID_CharGen_AunTText_BonusSkills_Trained");
      goto LABEL_14;
    case 7:
      v8 = compute_str_hash("ID_CharGen_LugText_BonusSkills_Trained");
      goto LABEL_14;
    case 11:
      v8 = compute_str_hash("ID_CharGen_OlthoiText_BonusSkills_Trained");
      goto LABEL_14;
    case 12:
      v8 = compute_str_hash("ID_CharGen_OlthoiAcidText_BonusSkills_Trained");
LABEL_14:
      StringInfo::SetStringIDandTableEnum(&siSkills, v8, 268435458);
      break;
    default:
      break;
  }
  UIElement_Text::AppendStringInfoWithFont(v1->m_pText, &siSkills, 0, 0);
  switch ( v7 )
  {
    case 0:
      ((void (__stdcall *)(signed int))v1->m_pAluButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435489);
      v9 = compute_str_hash("ID_CharGen_AluvianText");
      goto LABEL_30;
    case 1:
      ((void (__stdcall *)(signed int))v1->m_pGhuButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435490);
      v9 = compute_str_hash("ID_CharGen_GaruText");
      goto LABEL_30;
    case 2:
      ((void (__stdcall *)(signed int))v1->m_pShoButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435491);
      v9 = compute_str_hash("ID_CharGen_ShoText");
      goto LABEL_30;
    case 3:
      ((void (__stdcall *)(signed int))v1->m_pViaButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435492);
      v9 = compute_str_hash("ID_CharGen_ViaText");
      goto LABEL_30;
    case 4:
      ((void (__stdcall *)(signed int, int))v1->m_pShadButton->vfptr[13].__vecDelDtor)(268435479, v12);
      ((void (__cdecl *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435544);
      goto LABEL_22;
    case 9:
      ((void (__stdcall *)(signed int, int))v1->m_pPenButton->vfptr[13].__vecDelDtor)(268435479, v12);
      ((void (__cdecl *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435545);
LABEL_22:
      v9 = compute_str_hash("ID_CharGen_ShadText");
      goto LABEL_30;
    case 5:
      ((void (__stdcall *)(signed int))v1->m_pGearButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435546);
      v9 = compute_str_hash("ID_CharGen_GearText");
      goto LABEL_30;
    case 10:
      ((void (__stdcall *)(signed int))v1->m_pUndButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435547);
      v9 = compute_str_hash("ID_CharGen_UndText");
      goto LABEL_30;
    case 8:
      ((void (__stdcall *)(signed int))v1->m_pEmpButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435548);
      v9 = compute_str_hash("ID_CharGen_EmpText");
      goto LABEL_30;
    case 6:
      ((void (__stdcall *)(signed int))v1->m_pAunTButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435551);
      v9 = compute_str_hash("ID_CharGen_AunTText");
      goto LABEL_30;
    case 7:
      ((void (__stdcall *)(signed int))v1->m_pLugButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435552);
      v9 = compute_str_hash("ID_CharGen_LugText");
      goto LABEL_30;
    case 11:
      ((void (__stdcall *)(signed int))v1->m_pOlthoiButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435549);
      v9 = compute_str_hash("ID_CharGen_OlthoiText");
      goto LABEL_30;
    case 12:
      ((void (__stdcall *)(signed int))v1->m_pOlthoiAcidButton->vfptr[13].__vecDelDtor)(268435479);
      ((void (__stdcall *)(signed int))v1->m_pBackground->vfptr[13].__vecDelDtor)(268435550);
      v9 = compute_str_hash("ID_CharGen_OlthoiAcidText");
LABEL_30:
      StringInfo::SetStringIDandTableEnum(&siRace, v9, 268435458);
      break;
    default:
      break;
  }
  v10 = _wcslen(L"\n");
  PStringBase<unsigned short>::allocate_ref_buffer(&_text, v10);
  _wcscpy(_text.m_charbuffer->m_data, L"\n");
  UIElement_Text::AppendText(v1->m_pText, &_text);
  v11 = (char *)&_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]) && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  UIElement_Text::AppendStringInfoWithFont(v1->m_pText, &siRace, 0, 0);
  StringInfo::~StringInfo(&siSkills);
  StringInfo::~StringInfo(&siHeader);
  StringInfo::~StringInfo(&siRace);
}

//----- (00483860) --------------------------------------------------------  // acclient.c:191204
int __thiscall gmCGHeritagePage::ListenToElementMessage(gmCGHeritagePage *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmCGHeritagePage *v3; // esi@1
  int v4; // eax@5
  int v5; // eax@6
  int v7; // eax@18
  CharGenState *v8; // eax@39
  unsigned int v9; // [sp-4h] [bp-Ch]@9

  v2 = i_rMsg->idElement;
  v3 = this;
  if ( i_rMsg->idElement > 0x100005A9 )
  {
    switch ( v2 )
    {
      case 0x100005BFu:
        if ( i_rMsg->idMessage == 1 )
        {
          v9 = 11;
          goto LABEL_39;
        }
        break;
      case 0x100005C4u:
        if ( i_rMsg->idMessage == 1 )
        {
          v9 = 9;
          goto LABEL_39;
        }
        break;
      case 0x100005E8u:
        if ( i_rMsg->idMessage == 1 )
        {
          v9 = 7;
          goto LABEL_39;
        }
        break;
      case 0x100005F1u:
        if ( i_rMsg->idMessage == 1 )
        {
          v9 = 8;
          goto LABEL_39;
        }
        break;
      case 0x100005C7u:
        if ( i_rMsg->idMessage == 1 )
        {
          v9 = 12;
          goto LABEL_39;
        }
        break;
      case 0x100005C8u:
        if ( i_rMsg->idMessage == 1 )
        {
          v9 = 13;
          goto LABEL_39;
        }
        break;
      default:
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    }
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  if ( i_rMsg->idElement == 268436905 )
  {
    if ( i_rMsg->idMessage == 1 )
    {
      v9 = 6;
      goto LABEL_39;
    }
  }
  else if ( v2 > 0x100003C3 )
  {
    v7 = v2 - 268436880;
    if ( v7 )
    {
      if ( v7 != 1 || i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v9 = 10;
      goto LABEL_39;
    }
    if ( i_rMsg->idMessage == 1 )
    {
      v9 = 5;
      goto LABEL_39;
    }
  }
  else if ( v2 == 268436419 )
  {
    if ( i_rMsg->idMessage == 1 )
    {
      if ( !CPlayerSystem::AccountHasThroneOfDestiny(this->m_pPlayerSystem) )
      {
        gmCharGenMainUI::MakeToDWarningDialog(v3->m_pMainFramework);
        gmCGHeritagePage::Update(v3);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
      v9 = 4;
      goto LABEL_39;
    }
  }
  else
  {
    v4 = v2 - 268436415;
    if ( v4 )
    {
      v5 = v4 - 2;
      if ( v5 )
      {
        if ( v5 != 1 || i_rMsg->idMessage != 1 )
          return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        v9 = 3;
        goto LABEL_39;
      }
      if ( i_rMsg->idMessage == 1 )
      {
        v9 = 2;
LABEL_39:
        CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
        CharGenState::SetHeritageGroup(v8, v9);
        gmCGHeritagePage::Update(v3);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
    }
    else if ( i_rMsg->idMessage == 1 )
    {
      v9 = 1;
      goto LABEL_39;
    }
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (00483A10) --------------------------------------------------------  // acclient.c:191338
void __thiscall gmCGHeritagePage::InitializePage(gmCGHeritagePage *this, gmCharGenMainUI *_pMain)
{
  gmCGHeritagePage *v2; // esi@1
  UIElement *v3; // eax@1
  int v4; // eax@2
  UIElement *v5; // eax@4
  int v6; // eax@5
  UIElement *v7; // eax@7
  int v8; // eax@8
  UIElement *v9; // eax@10
  int v10; // eax@11
  UIElement *v11; // eax@13
  int v12; // eax@14
  UIElement *v13; // eax@16
  int v14; // eax@17
  UIElement *v15; // eax@19
  int v16; // eax@20
  UIElement *v17; // eax@22
  int v18; // eax@23
  UIElement *v19; // eax@25
  int v20; // eax@26
  UIElement *v21; // eax@28
  int v22; // eax@29
  UIElement *v23; // eax@31
  int v24; // eax@32
  UIElement *v25; // eax@34
  int v26; // eax@35
  UIElement *v27; // eax@37
  int v28; // eax@38
  UIElement *v29; // eax@40
  int v30; // eax@41

  v2 = this;
  this->m_pMainFramework = _pMain;
  this->m_pPlayerSystem = CPlayerSystem::GetPlayerSystem();
  v3 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003BFu);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)1);
  else
    v4 = 0;
  v2->m_pAluButton = (UIElement_Button *)v4;
  v5 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003C1u);
  if ( v5 )
    v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)1);
  else
    v6 = 0;
  v2->m_pGhuButton = (UIElement_Button *)v6;
  v7 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003C2u);
  if ( v7 )
    v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)1);
  else
    v8 = 0;
  v2->m_pShoButton = (UIElement_Button *)v8;
  v9 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003C3u);
  if ( v9 )
    v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)1);
  else
    v10 = 0;
  v2->m_pViaButton = (UIElement_Button *)v10;
  v11 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x10000590u);
  if ( v11 )
    v12 = v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)1);
  else
    v12 = 0;
  v2->m_pShadButton = (UIElement_Button *)v12;
  v13 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x10000591u);
  if ( v13 )
    v14 = v13->vfptr[12].OnAction((IInputActionCallback *)v13, (InputEvent *)1);
  else
    v14 = 0;
  v2->m_pPenButton = (UIElement_Button *)v14;
  v15 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100005A9u);
  if ( v15 )
    v16 = v15->vfptr[12].OnAction((IInputActionCallback *)v15, (InputEvent *)1);
  else
    v16 = 0;
  v2->m_pGearButton = (UIElement_Button *)v16;
  v17 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100005BFu);
  if ( v17 )
    v18 = v17->vfptr[12].OnAction((IInputActionCallback *)v17, (InputEvent *)1);
  else
    v18 = 0;
  v2->m_pUndButton = (UIElement_Button *)v18;
  v19 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100005C4u);
  if ( v19 )
    v20 = v19->vfptr[12].OnAction((IInputActionCallback *)v19, (InputEvent *)1);
  else
    v20 = 0;
  v2->m_pEmpButton = (UIElement_Button *)v20;
  v21 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100005E8u);
  if ( v21 )
    v22 = v21->vfptr[12].OnAction((IInputActionCallback *)v21, (InputEvent *)1);
  else
    v22 = 0;
  v2->m_pAunTButton = (UIElement_Button *)v22;
  v23 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100005F1u);
  if ( v23 )
    v24 = v23->vfptr[12].OnAction((IInputActionCallback *)v23, (InputEvent *)1);
  else
    v24 = 0;
  v2->m_pLugButton = (UIElement_Button *)v24;
  v25 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100005C7u);
  if ( v25 )
    v26 = v25->vfptr[12].OnAction((IInputActionCallback *)v25, (InputEvent *)1);
  else
    v26 = 0;
  v2->m_pOlthoiButton = (UIElement_Button *)v26;
  v27 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100005C8u);
  if ( v27 )
    v28 = v27->vfptr[12].OnAction((IInputActionCallback *)v27, (InputEvent *)1);
  else
    v28 = 0;
  v2->m_pOlthoiAcidButton = (UIElement_Button *)v28;
  v29 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003C4u);
  if ( v29 )
    v30 = v29->vfptr[12].OnAction((IInputActionCallback *)v29, (InputEvent *)12);
  else
    v30 = 0;
  v2->m_pText = (UIElement_Text *)v30;
  v2->m_pBackground = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x100003BEu);
  gmCGHeritagePage::Update(v2);
}

//----- (006ED130) --------------------------------------------------------  // acclient.c:768930
void _E91_43()
{
  outside_val_35 = 1000.0 + 1.0;
}

//----- (006ED150) --------------------------------------------------------  // acclient.c:768936
void _E93_19()
{
  block_length_35 = 24.0 * 8.0;
}

//----- (006ED170) --------------------------------------------------------  // acclient.c:768942
void _E95_19()
{
  half_square_length_35 = 24.0 * 0.5;
}

//----- (006ED190) --------------------------------------------------------  // acclient.c:768948
int _E97_44()
{
  return atexit(_E98_56);
}

//----- (006ED1A0) --------------------------------------------------------  // acclient.c:768954
int _E100_37()
{
  return atexit(_E101_74);
}

//----- (006ED1B0) --------------------------------------------------------  // acclient.c:768960
int _E103_29()
{
  return atexit(_E104_44);
}

//----- (006ED1C0) --------------------------------------------------------  // acclient.c:768966
void _E106_25()
{
  DEFAULT_VIEW_RADIUS_19 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006ED1E0) --------------------------------------------------------  // acclient.c:768972
void _E108_17()
{
  MIN_QUANTUM_19 = 1.0 / 30.0;
}

//----- (006ED200) --------------------------------------------------------  // acclient.c:768978
void _E110_8()
{
  MAX_QUANTUM_19 = 1.0 / 5.0;
}

//----- (006ED220) --------------------------------------------------------  // acclient.c:768984
void _E112_21()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_54, PFID_A8R8G8B8);
}

//----- (006ED230) --------------------------------------------------------  // acclient.c:768990
int _E114_20()
{
  return atexit(nullsub_498);
}

//----- (006ED240) --------------------------------------------------------  // acclient.c:768996
void _E118_26()
{
  LOWEST_DATA_RATE_62 = 1024;
}

//----- (006ED250) --------------------------------------------------------  // acclient.c:769002
void _E120_17()
{
  HIGHEST_DATA_RATE_62 = 0x7FFF;
}

//----- (006ED260) --------------------------------------------------------  // acclient.c:769008
int _E122_6()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_62;
  INITIAL_MAX_DATA_RATE_10 = LOWEST_DATA_RATE_62;
  return result;
}

//----- (006ED270) --------------------------------------------------------  // acclient.c:769018
int _E1_95()
{
  return atexit(_E2_95);
}

