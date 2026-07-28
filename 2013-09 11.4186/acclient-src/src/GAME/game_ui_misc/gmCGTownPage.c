/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCGTownPage
   Object     : GAME\game_ui_misc\gmCGTownPage.obj
   Functions  : 23
   Addresses  : 0047C0D0 - 006ECD30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0047C0D0) --------------------------------------------------------  // acclient.c:185128
gmCGTownPage *__thiscall gmCGTownPage::DynamicCast(gmCGTownPage *this, unsigned int i_eType)
{
  gmCGTownPage *result; // eax@1

  result = this;
  if ( i_eType != 268435517 )
    result = (gmCGTownPage *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0047C0F0) --------------------------------------------------------  // acclient.c:185139
signed int gmCGTownPage::GetUIElementType()
{
  return 268435517;
}

//----- (0047C100) --------------------------------------------------------  // acclient.c:185145
void __thiscall gmCGSkillsPage::PostInit(gmCGTownPage *this)
{
  UIElement::PostInit((UIElement *)&this->vfptr);
  GlobalEventHandler::GetGlobalEventHandler();
}

//----- (0047C110) --------------------------------------------------------  // acclient.c:185152
UIElement *__usercall gmCGTownPage::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x61Cu);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmCGTownPage::vftable;
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *((_DWORD *)v3 + 383) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79F6E8: using guessed type int (__thiscall *gmCGTownPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047C170) --------------------------------------------------------  // acclient.c:185177
UIElement_Field *__thiscall gmCGTownPage::vector_deleting_destructor(gmCGTownPage *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCGTownPage::vftable;
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
// 79F6E8: using guessed type int (__thiscall *gmCGTownPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047C1D0) --------------------------------------------------------  // acclient.c:185201
void __cdecl gmCGTownPage::Register()
{
  UIElement::RegisterElementClass(
    0x1000003Du,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCGTownPage::Create);
}

//----- (0047C1F0) --------------------------------------------------------  // acclient.c:185209
void __thiscall gmCGTownPage::SetTownString(gmCGTownPage *this, gmCGTownPage::ETown _eTown)
{
  gmCGTownPage *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char *v5; // esi@7
  char *v6; // esi@10
  PStringBase<unsigned short> strTown; // [sp+8h] [bp-128h]@7
  PStringBase<unsigned short> strHowTo; // [sp+Ch] [bp-124h]@7
  StringInfo siTown; // [sp+10h] [bp-120h]@1
  StringInfo siHowTo; // [sp+A0h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&siHowTo);
  v3 = compute_str_hash("ID_CharGen_TownHowTo");
  StringInfo::SetStringIDandTableEnum(&siHowTo, v3, 268435458);
  StringInfo::StringInfo(&siTown);
  switch ( _eTown )
  {
    case 4:
      v4 = compute_str_hash("ID_CharGen_SanamarText");
      goto LABEL_6;
    case 1:
      v4 = compute_str_hash("ID_CharGen_HoltText");
      goto LABEL_6;
    case 3:
      v4 = compute_str_hash("ID_CharGen_YaraqText");
      goto LABEL_6;
    case 2:
      v4 = compute_str_hash("ID_CharGen_ShoushiText");
LABEL_6:
      StringInfo::SetStringIDandTableEnum(&siTown, v4, 268435458);
      break;
    default:
      break;
  }
  strTown.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  StringInfo::InqString(&siTown, &strTown, 0);
  strHowTo.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  StringInfo::InqString(&siHowTo, &strHowTo, 0);
  PStringBase<unsigned short>::sprintf_append(&strTown, L"\n\n%s\n", strHowTo.m_charbuffer);
  UIElement_Text::SetText(v2->m_pTextBox, &strTown);
  v5 = (char *)&strHowTo.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strHowTo.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = (char *)&strTown.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strTown.m_charbuffer[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  StringInfo::~StringInfo(&siTown);
  StringInfo::~StringInfo(&siHowTo);
}

//----- (0047C360) --------------------------------------------------------  // acclient.c:185264
void __userpurge gmCGTownPage::SetTown(gmCGTownPage *this@<ecx>, int a2@<edi>, gmCGTownPage::ETown _eTown)
{
  gmCGTownPage *v3; // esi@1
  IInputActionCallbackVtbl *v4; // edx@2
  void *v5; // ecx@2
  CharGenState *v6; // eax@7
  int v7; // [sp+0h] [bp-Ch]@0

  v3 = this;
  ((void (__stdcall *)(signed int))this->m_pSanamarButton->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pHoltButton->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pYaraqButton->vfptr[13].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v3->m_pShoushiButton->vfptr[13].__vecDelDtor)(1);
  switch ( _eTown )
  {
    case 4:
      ((void (__stdcall *)(signed int, int))v3->m_pSanamarButton->vfptr[13].__vecDelDtor)(6, v7);
      v4 = v3->vfptr;
      v5 = v3;
      goto LABEL_6;
    case 1:
      ((void (__stdcall *)(signed int, int))v3->m_pHoltButton->vfptr[13].__vecDelDtor)(6, v7);
      v4 = v3->vfptr;
      v5 = v3;
      goto LABEL_6;
    case 3:
      ((void (__stdcall *)(signed int, int))v3->m_pYaraqButton->vfptr[13].__vecDelDtor)(6, v7);
      v4 = v3->vfptr;
      v5 = v3;
      goto LABEL_6;
    case 2:
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435511u);
      v5 = v3->m_pShoushiButton;
      v4 = *(IInputActionCallbackVtbl **)v5;
LABEL_6:
      ((void (__thiscall *)(void *))v4[13].__vecDelDtor)(v5);
      break;
    default:
      break;
  }
  CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
  CharGenState::SetStartArea(v6, a2);
  gmCGTownPage::SetTownString(v3, _eTown);
}

//----- (0047C460) --------------------------------------------------------  // acclient.c:185310
void __usercall gmCGTownPage::Update(gmCGTownPage *this@<ecx>, int a2@<edi>)
{
  gmCGTownPage *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  gmCGTownPage::SetTown(v2, a2, (gmCGTownPage::ETown)(*(_DWORD *)(v3 + 504) + 1));
}

//----- (0047C480) --------------------------------------------------------  // acclient.c:185321
int __userpurge gmCGTownPage::ListenToElementMessage@<eax>(gmCGTownPage *this@<ecx>, int a2@<edi>, UIElementMessageInfo *i_rMsg)
{
  gmCGTownPage *v3; // esi@1
  CharGenState *v4; // eax@4
  unsigned int v5; // eax@4
  unsigned int v6; // eax@4
  char *v7; // edi@4
  char *v8; // edi@7
  int v10; // eax@11
  PStringBase<unsigned short> _result; // [sp+1Ch] [bp-128h]@4
  PStringBase<unsigned short> v12; // [sp+20h] [bp-124h]@4
  StringInfo v13; // [sp+24h] [bp-120h]@4
  StringInfo v14; // [sp+B4h] [bp-90h]@4

  v3 = this;
  switch ( i_rMsg->idElement )
  {
    case 0x1000040Bu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      if ( !CPlayerSystem::AccountHasThroneOfDestiny(this->m_pPlayerSystem) )
      {
        gmCharGenMainUI::MakeToDWarningDialog(v3->m_pMainFramework);
        CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
        gmCGTownPage::SetTown(v3, a2, (gmCGTownPage::ETown)(*(_DWORD *)(v10 + 504) + 1));
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
      ((void (__stdcall *)(signed int))v3->m_pSanamarButton->vfptr[13].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pHoltButton->vfptr[13].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pYaraqButton->vfptr[13].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pShoushiButton->vfptr[13].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v3->m_pSanamarButton->vfptr[13].__vecDelDtor)(6);
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435509u);
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      CharGenState::SetStartArea(v4, 3);
      StringInfo::StringInfo(&v14);
      v5 = compute_str_hash("ID_CharGen_TownHowTo");
      StringInfo::SetStringIDandTableEnum(&v14, v5, 268435458);
      StringInfo::StringInfo(&v13);
      v6 = compute_str_hash("ID_CharGen_SanamarText");
      StringInfo::SetStringIDandTableEnum(&v13, v6, 268435458);
      _result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      StringInfo::InqString(&v13, &_result, 0);
      v12.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      StringInfo::InqString(&v14, &v12, 0);
      PStringBase<unsigned short>::sprintf_append(&_result, L"\n\n%s\n", v12.m_charbuffer);
      UIElement_Text::SetText(v3->m_pTextBox, &_result);
      v7 = (char *)&v12.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v12.m_charbuffer[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
      v8 = (char *)&_result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&_result.m_charbuffer[-1].m_data[8]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      }
      StringInfo::~StringInfo(&v13);
      StringInfo::~StringInfo(&v14);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x1000040Du:
      if ( i_rMsg->idMessage == 1 )
        gmCGTownPage::SetTown(this, a2, ECG_TOWN_HOLTBURG);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x1000040Eu:
      if ( i_rMsg->idMessage == 1 )
        gmCGTownPage::SetTown(this, a2, ECG_TOWN_YARAQ);
      break;
    case 0x1000040Fu:
      if ( i_rMsg->idMessage == 1 )
        gmCGTownPage::SetTown(this, a2, ECG_TOWN_SHOUSHI);
      break;
    default:
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (0047C6D0) --------------------------------------------------------  // acclient.c:185401
void __userpurge gmCGTownPage::InitializePage(gmCGTownPage *this@<ecx>, int a2@<edi>, gmCharGenMainUI *_pMain)
{
  gmCGTownPage *v3; // esi@1
  UIElement *v4; // eax@1
  int v5; // eax@2
  UIElement *v6; // eax@4
  int v7; // eax@5
  UIElement *v8; // eax@7
  int v9; // eax@8
  UIElement *v10; // eax@10
  int v11; // eax@11
  UIElement *v12; // eax@13
  int v13; // eax@14
  CPlayerSystem *v14; // ecx@16
  int v15; // eax@16

  v3 = this;
  this->m_pMainFramework = _pMain;
  this->m_pPlayerSystem = CPlayerSystem::GetPlayerSystem();
  v4 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x1000040Bu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)1);
  else
    v5 = 0;
  v3->m_pSanamarButton = (UIElement_Button *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x1000040Du);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)1);
  else
    v7 = 0;
  v3->m_pHoltButton = (UIElement_Button *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x1000040Eu);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)1);
  else
    v9 = 0;
  v3->m_pYaraqButton = (UIElement_Button *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x1000040Fu);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)1);
  else
    v11 = 0;
  v3->m_pShoushiButton = (UIElement_Button *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x10000409u);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
  else
    v13 = 0;
  v14 = v3->m_pPlayerSystem;
  v3->m_pTextBox = (UIElement_Text *)v13;
  CPlayerSystem::GetCharGenState(v14);
  gmCGTownPage::SetTown(v3, a2, (gmCGTownPage::ETown)(*(_DWORD *)(v15 + 504) + 1));
}

//----- (006ECC20) --------------------------------------------------------  // acclient.c:768576
void _E91_39()
{
  outside_val_31 = 1000.0 + 1.0;
}

//----- (006ECC40) --------------------------------------------------------  // acclient.c:768582
void _E93_15()
{
  block_length_31 = 24.0 * 8.0;
}

//----- (006ECC60) --------------------------------------------------------  // acclient.c:768588
void _E95_15()
{
  half_square_length_31 = 24.0 * 0.5;
}

//----- (006ECC80) --------------------------------------------------------  // acclient.c:768594
int _E97_40()
{
  return atexit(_E98_52);
}

//----- (006ECC90) --------------------------------------------------------  // acclient.c:768600
int _E100_33()
{
  return atexit(_E101_70);
}

//----- (006ECCA0) --------------------------------------------------------  // acclient.c:768606
int _E103_25()
{
  return atexit(_E104_40);
}

//----- (006ECCB0) --------------------------------------------------------  // acclient.c:768612
void _E106_21()
{
  DEFAULT_VIEW_RADIUS_15 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006ECCD0) --------------------------------------------------------  // acclient.c:768618
void _E108_13()
{
  MIN_QUANTUM_15 = 1.0 / 30.0;
}

//----- (006ECCF0) --------------------------------------------------------  // acclient.c:768624
void _E110_4()
{
  MAX_QUANTUM_15 = 1.0 / 5.0;
}

//----- (006ECD10) --------------------------------------------------------  // acclient.c:768630
void _E112_17()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_50, PFID_A8R8G8B8);
}

//----- (006ECD20) --------------------------------------------------------  // acclient.c:768636
int _E114_16()
{
  return atexit(nullsub_518);
}

//----- (006ECD30) --------------------------------------------------------  // acclient.c:768642
int _E1_91()
{
  return atexit(_E2_91);
}

