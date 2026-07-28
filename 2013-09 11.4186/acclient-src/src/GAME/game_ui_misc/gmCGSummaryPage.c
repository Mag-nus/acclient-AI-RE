/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCGSummaryPage
   Object     : GAME\game_ui_misc\gmCGSummaryPage.obj
   Functions  : 27
   Addresses  : 0047AC70 - 006ECC10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0047AC70) --------------------------------------------------------  // acclient.c:184129
void __userpurge gmCGSummaryPage::gmCGSummaryPage(gmCGSummaryPage *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGSummaryPage *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pPlayerSystem = 0;
  v4->m_pSummaryListbix = 0;
  v4->m_pNameText = 0;
  v4->m_pHowToText = 0;
  v4->m_pScoll = 0;
  v4->m_pViewport = 0;
  v4->m_p3DView = 0;
  v4->m_bNameEntered = 0;
  v4->m_uiErrorMessageContext = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCGSummaryPage::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmCGSummaryPage::vftable;
}
// 79ED88: using guessed type bool (__thiscall *gmCGSummaryPage::vftable)(DBCache *this);
// 79F030: using guessed type int (__thiscall *gmCGSummaryPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047ACE0) --------------------------------------------------------  // acclient.c:184153
gmCGSummaryPage *__thiscall gmCGSummaryPage::DynamicCast(gmCGSummaryPage *this, unsigned int i_eType)
{
  gmCGSummaryPage *result; // eax@1

  result = this;
  if ( i_eType != 268435518 )
    result = (gmCGSummaryPage *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0047AD00) --------------------------------------------------------  // acclient.c:184164
signed int gmCGSummaryPage::GetUIElementType()
{
  return 268435518;
}

//----- (0047AD10) --------------------------------------------------------  // acclient.c:184170
void __thiscall gmCGSummaryPage::PostInit(gmCGSummaryPage *this)
{
  gmCGSummaryPage *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100004u, (NoticeHandler *)&v1->vfptr);
  else
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100004u, 0);
}

//----- (0047AD50) --------------------------------------------------------  // acclient.c:184185
void __usercall gmCGSummaryPage::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGSummaryPage *v3; // eax@1

  v3 = (gmCGSummaryPage *)operator new(0x624u);
  if ( v3 )
    gmCGSummaryPage::gmCGSummaryPage(v3, a1, _layout, _full_desc);
}

//----- (0047AD80) --------------------------------------------------------  // acclient.c:184195
void __thiscall gmCGSummaryPage::RecvNotice_CloseDialog(gmCGSummaryPage *this, unsigned int context, PropertyCollection *data)
{
  if ( (HashSetData<UIElement *> *)context == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] )
    this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = 0;
}

//----- (0047ADA0) --------------------------------------------------------  // acclient.c:184202
UIElement_Field *__thiscall gmCGSummaryPage::scalar_deleting_destructor(gmCGSummaryPage *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCGSummaryPage::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmCGSummaryPage::vftable;
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
// 79ED88: using guessed type bool (__thiscall *gmCGSummaryPage::vftable)(DBCache *this);
// 79F030: using guessed type int (__thiscall *gmCGSummaryPage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047AE00) --------------------------------------------------------  // acclient.c:184227
void __cdecl gmCGSummaryPage::Register()
{
  UIElement::RegisterElementClass(
    0x1000003Eu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCGSummaryPage::Create);
}

//----- (0047AE20) --------------------------------------------------------  // acclient.c:184235
void __thiscall gmCGSummaryPage::SetHowToText(gmCGSummaryPage *this)
{
  gmCGSummaryPage *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // eax@1
  int v4; // eax@1
  int v5; // esi@1
  int v6; // eax@1
  int v7; // edi@1
  unsigned int v8; // eax@3
  int v9; // eax@37
  int v10; // eax@40
  int v11; // eax@43
  char *v12; // esi@46
  char *v13; // esi@49
  PStringBase<unsigned short> strTemp; // [sp+Ch] [bp-1B8h]@36
  PStringBase<unsigned short> strSummary; // [sp+10h] [bp-1B4h]@36
  StringInfo siName; // [sp+14h] [bp-1B0h]@1
  StringInfo siHowToEnd; // [sp+A4h] [bp-120h]@1
  StringInfo siHowTo; // [sp+134h] [bp-90h]@1

  v1 = this;
  StringInfo::StringInfo(&siHowTo);
  v2 = compute_str_hash("ID_CharGen_SummaryHowTo");
  StringInfo::SetStringIDandTableEnum(&siHowTo, v2, 268435458);
  StringInfo::StringInfo(&siHowToEnd);
  v3 = compute_str_hash("ID_CharGen_SummaryHowToEnd");
  StringInfo::SetStringIDandTableEnum(&siHowToEnd, v3, 268435458);
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  v5 = *(_DWORD *)(v4 + 216);
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  v7 = *(_DWORD *)(v6 + 212);
  StringInfo::StringInfo(&siName);
  switch ( v7 )
  {
    case 1:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_AluFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_AluMaleNames");
      goto LABEL_35;
    case 2:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_GharuFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_GharuMaleNames");
      goto LABEL_35;
    case 3:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_ShoFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_ShoMaleNames");
      goto LABEL_35;
    case 4:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_ViaFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_ViaMaleNames");
      goto LABEL_35;
    case 5:
    case 10:
      if ( v5 == 2 )
        v8 = compute_str_hash("ID_CharGen_ShadFemaleNames");
      else
        v8 = compute_str_hash("ID_CharGen_ShadMaleNames");
      goto LABEL_35;
    case 6:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_GearFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_GearMaleNames");
      goto LABEL_35;
    case 11:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_UndFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_UndMaleNames");
      goto LABEL_35;
    case 9:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_EmpFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_EmpMaleNames");
      goto LABEL_35;
    case 7:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_AunTFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_AunTMaleNames");
      goto LABEL_35;
    case 8:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_LugFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_LugMaleNames");
      goto LABEL_35;
    case 12:
    case 13:
      if ( v5 == 2 )
        v8 = Tokenize("ID_CharGen_OlthoiFemaleNames");
      else
        v8 = Tokenize("ID_CharGen_OlthoiMaleNames");
LABEL_35:
      StringInfo::SetStringIDandTableEnum(&siName, v8, 268435458);
      break;
    default:
      break;
  }
  strSummary.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  strTemp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( StringInfo::InqString(&siHowTo, &strTemp, 0) )
  {
    v9 = *(_DWORD *)&strTemp.m_charbuffer[-1].m_data[14];
    if ( v9 != 1 )
      PStringBase<unsigned short>::append_n_chars(&strSummary, strTemp.m_charbuffer->m_data, v9 - 1);
    if ( StringInfo::InqString(&siName, &strTemp, 0) )
    {
      v10 = *(_DWORD *)&strTemp.m_charbuffer[-1].m_data[14];
      if ( v10 != 1 )
        PStringBase<unsigned short>::append_n_chars(&strSummary, strTemp.m_charbuffer->m_data, v10 - 1);
      if ( StringInfo::InqString(&siHowToEnd, &strTemp, 0) )
      {
        v11 = *(_DWORD *)&strTemp.m_charbuffer[-1].m_data[14];
        if ( v11 != 1 )
          PStringBase<unsigned short>::append_n_chars(&strSummary, strTemp.m_charbuffer->m_data, v11 - 1);
        UIElement_Text::SetText(v1->m_pHowToText, &strSummary);
      }
    }
  }
  v12 = (char *)&strTemp.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strTemp.m_charbuffer[-1].m_data[8]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  v13 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  StringInfo::~StringInfo(&siName);
  StringInfo::~StringInfo(&siHowToEnd);
  StringInfo::~StringInfo(&siHowTo);
}

//----- (0047B160) --------------------------------------------------------  // acclient.c:184378
void __thiscall PStringBase<unsigned short>::append_int32(PStringBase<unsigned short> *this, int num)
{
  PStringBase<unsigned short> *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // ecx@1
  int v4; // eax@1
  int v5; // esi@3
  PStringBase<unsigned short> buf; // [sp+0h] [bp-4h]@1

  buf.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&buf, L"%ld", num);
  v3 = buf.m_charbuffer;
  v4 = *(_DWORD *)&buf.m_charbuffer[-1].m_data[14];
  if ( v4 != 1 )
  {
    PStringBase<unsigned short>::append_n_chars(v2, buf.m_charbuffer->m_data, v4 - 1);
    v3 = buf.m_charbuffer;
  }
  v5 = (int)&v3[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (0047B1D0) --------------------------------------------------------  // acclient.c:184406
void __thiscall gmCGSummaryPage::SetSummaryText(gmCGSummaryPage *this)
{
  gmCGSummaryPage *v1; // ebx@1
  UIElement_ListBox *v2; // ecx@1
  int v3; // eax@1
  int v4; // ebp@1
  signed int v5; // esi@1
  unsigned int v6; // eax@1
  const wchar_t *v7; // esi@3
  unsigned int v8; // eax@5
  int v9; // eax@6
  UIElement *v10; // eax@6
  UIElement_Text *v11; // eax@7
  char *v12; // esi@9
  unsigned int v13; // esi@13
  unsigned int v14; // eax@13
  const wchar_t *v15; // esi@14
  unsigned int v16; // eax@16
  int v17; // eax@17
  UIElement *v18; // eax@17
  UIElement_Text *v19; // eax@18
  unsigned int v20; // esi@19
  unsigned int v21; // eax@19
  int v22; // eax@21
  UIElement *v23; // eax@21
  UIElement_Text *v24; // eax@22
  signed int v25; // esi@23
  unsigned int v26; // eax@23
  int v27; // eax@26
  UIElement *v28; // eax@26
  UIElement_Text *v29; // eax@27
  int v30; // eax@28
  UIElement *v31; // eax@28
  UIElement_Text *v32; // eax@29
  int v33; // esi@30
  signed int v34; // ebx@30
  int v35; // eax@42
  UIElement *v36; // edi@42
  UIElement *v37; // eax@42
  UIElement_Text *v38; // eax@43
  UIElement *v39; // eax@44
  UIElement_Text *v40; // edi@45
  int v41; // edi@47
  char *v42; // esi@49
  int v43; // eax@61
  UIElement *v44; // eax@61
  UIElement_Text *v45; // eax@62
  char *v46; // esi@64
  ListNode<SkillRecord *> *v47; // ebp@68
  char *v48; // esi@71
  char *v49; // esi@76
  unsigned int v50; // ecx@80
  SkillRecord *v51; // esi@80
  int v52; // ebx@81
  int v53; // edx@82
  int v54; // edi@85
  CharGenState *v55; // ebx@86
  SKILL_ADVANCEMENT_CLASS v56; // eax@86
  int v57; // edi@94
  int v58; // eax@94
  UIElement *v59; // esi@94
  UIElement *v60; // eax@94
  UIElement_Text *v61; // eax@95
  UIElement *v62; // eax@96
  UIElement_Text *v63; // esi@97
  char *v64; // esi@99
  int v65; // eax@102
  bool v66; // sf@102
  unsigned __int8 v67; // of@102
  char *v68; // esi@104
  LONG v69; // eax@104
  char *v70; // esi@105
  PStringBase<unsigned short> strSummary; // [sp+38h] [bp-1Ch]@1
  PStringBase<unsigned short> strValue; // [sp+3Ch] [bp-18h]@31
  int iSkillLevel; // [sp+40h] [bp-14h]@56
  int i; // [sp+44h] [bp-10h]@38
  gmCGSummaryPage *v75; // [sp+48h] [bp-Ch]@1
  CharGenState *cg; // [sp+4Ch] [bp-8h]@1
  int iVal; // [sp+50h] [bp-4h]@30

  v1 = this;
  v2 = this->m_pSummaryListbix;
  v75 = v1;
  UIElement_ListBox::Flush(v2);
  strSummary.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
  v4 = v3;
  v5 = *(_DWORD *)(v3 + 384);
  cg = (CharGenState *)v3;
  v6 = _wcslen(L"Profession: ");
  PStringBase<unsigned short>::append_n_chars(&strSummary, L"Profession: ", v6);
  if ( v5 >= 0 && v5 <= 6 )
  {
    v7 = (&pcProfessions)[2 * v5];
    if ( v7 )
    {
      if ( *v7 )
      {
        v8 = _wcslen(v7);
        PStringBase<unsigned short>::append_n_chars(&strSummary, v7, v8);
      }
    }
  }
  v9 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pSummaryListbix, 0, 0);
  v10 = UIElement::GetChildRecursive((UIElement *)v9, 0x100002F9u);
  if ( !v10 )
    goto LABEL_109;
  v11 = (UIElement_Text *)v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  if ( !v11 )
    goto LABEL_109;
  UIElement_Text::SetText(v11, &strSummary);
  if ( (wchar_t *)strSummary.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v12 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    strSummary.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  }
  v13 = *(_DWORD *)(v4 + 216);
  v14 = _wcslen(L"Gender: ");
  PStringBase<unsigned short>::append_n_chars(&strSummary, L"Gender: ", v14);
  if ( v13 <= 2 )
  {
    v15 = (&pcGender)[2 * v13];
    if ( v15 )
    {
      if ( *v15 )
      {
        v16 = _wcslen(v15);
        PStringBase<unsigned short>::append_n_chars(&strSummary, v15, v16);
      }
    }
  }
  v17 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pSummaryListbix, 0, 0);
  v18 = UIElement::GetChildRecursive((UIElement *)v17, 0x100002F9u);
  if ( !v18 )
    goto LABEL_109;
  v19 = (UIElement_Text *)v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)12);
  if ( !v19 )
    goto LABEL_109;
  UIElement_Text::SetText(v19, &strSummary);
  PStringBase<unsigned short>::clear(&strSummary);
  v20 = *(_DWORD *)(v4 + 212);
  v21 = _wcslen(L"Heritage: ");
  PStringBase<unsigned short>::append_n_chars(&strSummary, L"Heritage: ", v21);
  if ( v20 <= 4 )
    PStringBase<unsigned short>::append_string(&strSummary, (&pcHeritage)[2 * v20]);
  v22 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pSummaryListbix, 0, 0);
  v23 = UIElement::GetChildRecursive((UIElement *)v22, 0x100002F9u);
  if ( v23 && (v24 = (UIElement_Text *)v23->vfptr[12].OnAction((IInputActionCallback *)v23, (InputEvent *)12)) != 0 )
  {
    UIElement_Text::SetText(v24, &strSummary);
    PStringBase<unsigned short>::clear(&strSummary);
    v25 = *(_DWORD *)(v4 + 504);
    v26 = _wcslen(L"Starting Town: ");
    PStringBase<unsigned short>::append_n_chars(&strSummary, L"Starting Town: ", v26);
    if ( v25 >= 0 && v25 <= 3 )
      PStringBase<unsigned short>::append_string(&strSummary, (&pcTown)[2 * v25]);
    v27 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pSummaryListbix, 0, 0);
    v28 = UIElement::GetChildRecursive((UIElement *)v27, 0x100002F9u);
    if ( v28 )
    {
      v29 = (UIElement_Text *)v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)12);
      if ( v29 )
      {
        UIElement_Text::SetText(v29, &strSummary);
        PStringBase<unsigned short>::clear(&strSummary);
        PStringBase<unsigned short>::append_string(&strSummary, L"Attributes");
        v30 = UIElement_ListBox::AddItemFromTemplateList(v1->m_pSummaryListbix, 1u, 0);
        v31 = UIElement::GetChildRecursive((UIElement *)v30, 0x100000FEu);
        if ( v31 )
        {
          v32 = (UIElement_Text *)v31->vfptr[12].OnAction((IInputActionCallback *)v31, (InputEvent *)12);
          if ( v32 )
          {
            UIElement_Text::SetText(v32, &strSummary);
            PStringBase<unsigned short>::clear(&strSummary);
            v33 = iVal;
            v34 = 0;
            while ( 1 )
            {
              strValue.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
              InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
              PStringBase<unsigned short>::clear(&strSummary);
              PStringBase<unsigned short>::clear(&strValue);
              switch ( v34 )
              {
                case 0:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Strength");
                  v33 = *(_DWORD *)(v4 + 388);
                  break;
                case 1:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Endurance");
                  v33 = *(_DWORD *)(v4 + 392);
                  break;
                case 2:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Coordination");
                  v33 = *(_DWORD *)(v4 + 396);
                  break;
                case 3:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Quickness");
                  v33 = *(_DWORD *)(v4 + 400);
                  break;
                case 4:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Focus");
                  v33 = *(_DWORD *)(v4 + 404);
                  break;
                case 5:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Self");
                  v33 = *(_DWORD *)(v4 + 408);
                  break;
                case 6:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Health");
                  i = CharGenState::GetAttribute((CharGenState *)v4, 2u);
                  v33 = (unsigned __int64)((double)i * 0.5 + 0.5);
                  break;
                case 7:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Stamina");
                  v33 = CharGenState::GetAttribute((CharGenState *)v4, 2u);
                  break;
                case 8:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Mana");
                  v33 = CharGenState::GetAttribute((CharGenState *)v4, 6u);
                  break;
                case 9:
                  PStringBase<unsigned short>::append_string(&strSummary, L"Skill Credits");
                  v33 = *(_DWORD *)(v4 + 440);
                  break;
                default:
                  break;
              }
              v35 = UIElement_ListBox::AddItemFromTemplateList(v75->m_pSummaryListbix, 2u, 0);
              v36 = (UIElement *)v35;
              v37 = UIElement::GetChildRecursive((UIElement *)v35, 0x100002FCu);
              if ( !v37 )
                break;
              v38 = (UIElement_Text *)v37->vfptr[12].OnAction((IInputActionCallback *)v37, (InputEvent *)12);
              if ( !v38 )
                break;
              UIElement_Text::SetText(v38, &strSummary);
              v39 = UIElement::GetChildRecursive(v36, 0x100002FDu);
              if ( !v39 )
                break;
              v40 = (UIElement_Text *)v39->vfptr[12].OnAction((IInputActionCallback *)v39, (InputEvent *)12);
              if ( !v40 )
                break;
              PStringBase<unsigned short>::append_int32(&strValue, v33);
              UIElement_Text::SetText(v40, &strValue);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strValue);
              ++v34;
              if ( v34 >= 10 )
              {
                v41 = 0;
                iVal = *(_DWORD *)(v4 + 584) + 56;
                i = 0;
                while ( 1 )
                {
                  if ( (wchar_t *)strSummary.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
                  {
                    v42 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
                    if ( !InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]) && v42 )
                      (**(void (__thiscall ***)(char *, signed int))v42)(v42, 1);
                    strSummary.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                  }
                  switch ( v41 )
                  {
                    case 0:
                      PStringBase<unsigned short>::append_string(&strSummary, L"Specialized Skills");
                      iSkillLevel = 3;
                      break;
                    case 1:
                      PStringBase<unsigned short>::append_string(&strSummary, L"Trained Skills");
                      iSkillLevel = 2;
                      break;
                    case 2:
                      PStringBase<unsigned short>::append_string(&strSummary, L"Useable Untrained Skills");
                      goto LABEL_60;
                    case 3:
                      PStringBase<unsigned short>::append_string(&strSummary, L"Unuseable Untrained Skills");
LABEL_60:
                      iSkillLevel = 1;
                      break;
                    default:
                      break;
                  }
                  v43 = UIElement_ListBox::AddItemFromTemplateList(v75->m_pSummaryListbix, 1u, 0);
                  v44 = UIElement::GetChildRecursive((UIElement *)v43, 0x100000FEu);
                  if ( !v44
                    || (v45 = (UIElement_Text *)v44->vfptr[12].OnAction((IInputActionCallback *)v44, (InputEvent *)12)) == 0 )
                  {
                    v68 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
                    v69 = InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]);
                    goto LABEL_110;
                  }
                  UIElement_Text::SetText(v45, &strSummary);
                  if ( (wchar_t *)strSummary.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
                  {
                    v46 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
                    if ( !InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]) && v46 )
                      (**(void (__thiscall ***)(char *, signed int))v46)(v46, 1);
                    strSummary.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                  }
                  v47 = cg->skillRecordList._head;
                  while ( v47 )
                  {
                    strValue.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                    if ( (wchar_t *)strSummary.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
                    {
                      v48 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
                      if ( !InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]) && v48 )
                        (**(void (__thiscall ***)(char *, signed int))v48)(v48, 1);
                      strSummary.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                    }
                    if ( (wchar_t *)strValue.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
                    {
                      v49 = (char *)&strValue.m_charbuffer[-1].m_data[6];
                      if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1].m_data[8]) && v49 )
                        (**(void (__thiscall ***)(char *, signed int))v49)(v49, 1);
                      strValue.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
                      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
                    }
                    v50 = *(_DWORD *)(iVal + 12);
                    v51 = v47->data;
                    if ( v50
                      && (v52 = *(_DWORD *)(iVal + 8)) != 0
                      && (v53 = *(_DWORD *)(v52 + 4 * (v51->id % v50))) != 0 )
                    {
                      while ( v51->id != *(_DWORD *)v53 )
                      {
                        v53 = *(_DWORD *)(v53 + 96);
                        if ( !v53 )
                          goto LABEL_85;
                      }
                      v54 = v53 + 8;
                    }
                    else
                    {
LABEL_85:
                      v54 = 0;
                    }
                    v55 = cg;
                    v56 = CharGenState::GetSkillLevel(cg, v51->id);
                    if ( v56 == iSkillLevel )
                    {
                      if ( i > 1 )
                      {
                        if ( i == 2 )
                        {
                          if ( *(_DWORD *)(v54 + 32) > 1 )
                            goto LABEL_99;
                        }
                        else if ( i == 3 && *(_DWORD *)(v54 + 32) <= 1 )
                        {
                          goto LABEL_99;
                        }
                      }
                      PStringBase<unsigned short>::sprintf_append(&strSummary, L"%hs", v51);
                      v57 = CharGenState::GetSkillScore(v55, v51->id);
                      v58 = UIElement_ListBox::AddItemFromTemplateList(v75->m_pSummaryListbix, 2u, 0);
                      v59 = (UIElement *)v58;
                      v60 = UIElement::GetChildRecursive((UIElement *)v58, 0x100002FCu);
                      if ( !v60
                        || (v61 = (UIElement_Text *)v60->vfptr[12].OnAction(
                                                      (IInputActionCallback *)v60,
                                                      (InputEvent *)12)) == 0
                        || (UIElement_Text::SetText(v61, &strSummary),
                            (v62 = UIElement::GetChildRecursive(v59, 0x100002FDu)) == 0)
                        || (v63 = (UIElement_Text *)v62->vfptr[12].OnAction(
                                                      (IInputActionCallback *)v62,
                                                      (InputEvent *)12)) == 0 )
                      {
                        v70 = (char *)&strValue.m_charbuffer[-1].m_data[6];
                        if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1].m_data[8]) && v70 )
                          (**(void (__thiscall ***)(char *, signed int))v70)(v70, 1);
                        v68 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
                        v69 = InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]);
                        goto LABEL_110;
                      }
                      PStringBase<unsigned short>::append_int32(&strValue, v57);
                      UIElement_Text::SetText(v63, &strValue);
                    }
LABEL_99:
                    v47 = v47->next;
                    v64 = (char *)&strValue.m_charbuffer[-1].m_data[6];
                    if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1].m_data[8]) )
                    {
                      if ( v64 )
                        (**(void (__thiscall ***)(char *, signed int))v64)(v64, 1);
                    }
                  }
                  v65 = i + 1;
                  v67 = __OFSUB__(i + 1, 4);
                  v66 = i++ - 3 < 0;
                  if ( !(v66 ^ v67) )
                    goto LABEL_109;
                  v41 = v65;
                }
              }
            }
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strValue);
          }
        }
      }
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strSummary);
  }
  else
  {
LABEL_109:
    v68 = (char *)&strSummary.m_charbuffer[-1].m_data[6];
    v69 = InterlockedDecrement((volatile LONG *)&strSummary.m_charbuffer[-1].m_data[8]);
LABEL_110:
    if ( !v69 && v68 )
      (**(void (__thiscall ***)(char *, signed int))v68)(v68, 1);
  }
}
// 79F430: using guessed type wchar_t aUseableUntrain[25];

//----- (0047BAA0) --------------------------------------------------------  // acclient.c:184831
void __thiscall gmCGSummaryPage::Update(gmCGSummaryPage *this)
{
  gmCGSummaryPage *v1; // esi@1
  int v2; // eax@2
  CharGenState *v3; // edi@2
  int v4; // eax@2
  gmCG3DView *v5; // ecx@7
  unsigned int v6; // eax@8
  AC1Legacy::Vector3 *v7; // [sp-Ch] [bp-B8h]@3
  AC1Legacy::Vector3 *v8; // [sp-8h] [bp-B4h]@3
  AC1Legacy::Vector3 _vectDirection; // [sp+4h] [bp-A8h]@3
  AC1Legacy::Vector3 _vectPosition; // [sp+10h] [bp-9Ch]@3
  StringInfo siName; // [sp+1Ch] [bp-90h]@8

  v1 = this;
  if ( UIElement::IsVisible((UIElement *)&this->vfptr) )
  {
    CPlayerSystem::GetCharGenState(v1->m_pPlayerSystem);
    v3 = (CharGenState *)v2;
    v4 = *(_DWORD *)(v2 + 212);
    if ( v4 == 12 )
    {
      v8 = &_vectPosition;
      LODWORD(_vectPosition.y) = 0;
      LODWORD(_vectPosition.z) = 0;
      LODWORD(_vectDirection.y) = -1066192077;
      LODWORD(_vectDirection.z) = 1066611507;
      v7 = &_vectDirection;
    }
    else
    {
      LODWORD(_vectDirection.z) = 0;
      LODWORD(_vectDirection.y) = 0;
      if ( v4 == 13 )
      {
        v8 = &_vectDirection;
        LODWORD(_vectPosition.y) = -1061788058;
        LODWORD(_vectPosition.z) = 1070805811;
        v7 = &_vectPosition;
      }
      else
      {
        v8 = &_vectDirection;
        LODWORD(_vectPosition.y) = -1071644672;
        LODWORD(_vectPosition.z) = 1064514355;
        v7 = &_vectPosition;
      }
    }
    v5 = v1->m_p3DView;
    LODWORD(_vectDirection.x) = 0;
    LODWORD(_vectPosition.x) = 0;
    gmCG3DView::SetCamera(v5, v7, v8);
    CharGenState::FitTemplateToCharacter(v3);
    gmCGSummaryPage::SetSummaryText(v1);
    gmCGSummaryPage::SetHowToText(v1);
    gmCG3DView::Update(v1->m_p3DView);
    ((void (*)(void))v1->m_pNameText->vfptr[21].OnLoseFocus)();
    if ( !v1->m_bNameEntered )
    {
      StringInfo::StringInfo(&siName);
      v6 = compute_str_hash("ID_CharGen_NamePrompt");
      StringInfo::SetStringIDandTableEnum(&siName, v6, 268435458);
      UIElement_Text::SetStringInfo(v1->m_pNameText, &siName);
      UIElement_Text::SelectAll(v1->m_pNameText);
      StringInfo::~StringInfo(&siName);
    }
  }
}

//----- (0047BBF0) --------------------------------------------------------  // acclient.c:184901
void __thiscall gmCGSummaryPage::InitializePage(gmCGSummaryPage *this, gmCharGenMainUI *_pMain)
{
  gmCGSummaryPage *v2; // esi@1
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
  gmCG3DView *v13; // eax@16
  gmCG3DView *v14; // eax@17
  gmCG3DView *v15; // ecx@21
  AC1Legacy::Vector3 _vectDirection; // [sp+4h] [bp-18h]@21
  AC1Legacy::Vector3 _vectPosition; // [sp+10h] [bp-Ch]@21

  v2 = this;
  this->m_pMainFramework = _pMain;
  this->m_pPlayerSystem = CPlayerSystem::GetPlayerSystem();
  v3 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x10000400u);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)5);
  else
    v4 = 0;
  v2->m_pSummaryListbix = (UIElement_ListBox *)v4;
  v5 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x10000402u);
  if ( v5 )
    v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)12);
  else
    v6 = 0;
  v2->m_pNameText = (UIElement_Text *)v6;
  *(_DWORD *)(v6 + 1696) = NameInputFilter;
  v7 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x10000404u);
  if ( v7 )
    v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)12);
  else
    v8 = 0;
  v2->m_pHowToText = (UIElement_Text *)v8;
  v9 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x10000401u);
  if ( v9 )
    v10 = v9->vfptr[12].OnAction((IInputActionCallback *)v9, (InputEvent *)11);
  else
    v10 = 0;
  v2->m_pScoll = (UIElement_Scrollbar *)v10;
  v11 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x10000406u);
  if ( v11 )
    v12 = v11->vfptr[12].OnAction((IInputActionCallback *)v11, (InputEvent *)13);
  else
    v12 = 0;
  v2->m_pViewport = (UIElement_Viewport *)v12;
  v13 = (gmCG3DView *)operator new(0x60u);
  if ( v13 )
    gmCG3DView::gmCG3DView(v13);
  else
    v14 = 0;
  v2->m_p3DView = v14;
  if ( v14 )
    gmCG3DView::Initialize(v14, v2->m_pViewport);
  v15 = v2->m_p3DView;
  LODWORD(_vectDirection.x) = 0;
  LODWORD(_vectDirection.y) = 0;
  LODWORD(_vectDirection.z) = 0;
  LODWORD(_vectPosition.x) = 0;
  LODWORD(_vectPosition.y) = -1071644672;
  LODWORD(_vectPosition.z) = 1064514355;
  gmCG3DView::SetCamera(v15, &_vectPosition, &_vectDirection);
  gmCG3DView::SetPlayerHeading(v2->m_p3DView, 180.0);
  gmCG3DView::StartAnimation(v2->m_p3DView);
  if ( UIElement::IsVisible((UIElement *)&v2->vfptr) )
    gmCGSummaryPage::Update(v2);
}

//----- (0047BD80) --------------------------------------------------------  // acclient.c:184977
void __thiscall gmCGSummaryPage::DoNameLimitDialog(gmCGSummaryPage *this)
{
  gmCGSummaryPage *v1; // esi@1
  unsigned int v2; // eax@2
  BasePropertyDesc *v3; // ecx@9
  unsigned int v4; // esi@9
  BasePropertyValue *v5; // ecx@13
  unsigned int v6; // edx@13
  BaseProperty p; // [sp+10h] [bp-114h]@2
  unsigned int _key; // [sp+18h] [bp-10Ch]@4
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@2
  StringInfo siError; // [sp+94h] [bp-90h]@2

  v1 = this;
  if ( !this->m_uiErrorMessageContext )
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    StringInfo::StringInfo(&siError);
    v2 = compute_str_hash("ID_CharGen_NameTooLong");
    StringInfo::SetStringIDandTableEnum(&siError, v2, 268435458);
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
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&siError);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    v1->m_uiErrorMessageContext = DialogFactory::MakeDialog((UIFramework *)&v1->m_pMainFramework->vfptr, &pc);
    StringInfo::~StringInfo(&siError);
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
  }
}

//----- (0047BF40) --------------------------------------------------------  // acclient.c:185057
int __thiscall gmCGSummaryPage::ListenToElementMessage(gmCGSummaryPage *this, UIElementMessageInfo *i_rMsg)
{
  gmCGSummaryPage *v2; // esi@1
  unsigned int v3; // eax@2
  UIElement_Text *v4; // ecx@4
  bool v5; // bl@4
  char *v6; // edi@4
  bool v7; // bl@8
  char *v8; // edi@8
  int v9; // eax@12
  PStringBase<unsigned short> *v10; // eax@12
  char *v11; // edi@12
  PStringBase<unsigned short> *v12; // eax@16
  PSRefBufferCharData<char> *v13; // ST08_4@16
  CharGenState *v14; // eax@16
  char *v15; // edi@16
  char *v16; // edi@19
  PStringBase<unsigned short> result; // [sp+4h] [bp-14h]@4
  PStringBase<unsigned short> v19; // [sp+8h] [bp-10h]@8
  PStringBase<unsigned short> v20; // [sp+Ch] [bp-Ch]@12
  PStringBase<char> v21; // [sp+10h] [bp-8h]@16
  PStringBase<unsigned short> v22; // [sp+14h] [bp-4h]@16

  v2 = this;
  if ( i_rMsg->idElement == 268436482 )
  {
    v3 = i_rMsg->idMessage;
    if ( v3 == 18 || v3 == 68 )
    {
      v4 = this->m_pNameText;
      v2->m_bNameEntered = 1;
      v5 = *(_DWORD *)&UIElement_Text::GetText(v4, &result)->m_charbuffer[-1].m_data[14] != 1;
      v6 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      if ( v5 )
      {
        v7 = *(_DWORD *)&UIElement_Text::GetText(v2->m_pNameText, &v19)->m_charbuffer[-1].m_data[14] > 0x21u;
        v8 = (char *)&v19.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&v19.m_charbuffer[-1].m_data[8]) && v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
        if ( v7 )
        {
          CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
          PStringBase<unsigned short>::PStringBase<unsigned short>(&v20, 0, (const char *)(v9 + 464));
          UIElement_Text::SetText(v2->m_pNameText, v10);
          v11 = (char *)&v20.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1].m_data[8]) && v11 )
            (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
          gmCGSummaryPage::DoNameLimitDialog(v2);
        }
        else
        {
          v12 = UIElement_Text::GetText(v2->m_pNameText, &v22);
          v13 = PStringBase<unsigned short>::to_spstring(v12, &v21, 0)->m_charbuffer;
          CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
          CharGenState::SetName(v14, v13->m_data);
          v15 = &v21.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v21.m_charbuffer[-1]) && v15 )
            (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
          v16 = (char *)&v22.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&v22.m_charbuffer[-1].m_data[8]) && v16 )
            (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
        }
      }
    }
  }
  return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
}

//----- (006ECB00) --------------------------------------------------------  // acclient.c:768504
void _E91_38()
{
  outside_val_30 = 1000.0 + 1.0;
}

//----- (006ECB20) --------------------------------------------------------  // acclient.c:768510
void _E93_14()
{
  block_length_30 = 24.0 * 8.0;
}

//----- (006ECB40) --------------------------------------------------------  // acclient.c:768516
void _E95_14()
{
  half_square_length_30 = 24.0 * 0.5;
}

//----- (006ECB60) --------------------------------------------------------  // acclient.c:768522
int _E97_39()
{
  return atexit(_E98_51);
}

//----- (006ECB70) --------------------------------------------------------  // acclient.c:768528
int _E100_32()
{
  return atexit(_E101_69);
}

//----- (006ECB80) --------------------------------------------------------  // acclient.c:768534
int _E103_24()
{
  return atexit(_E104_39);
}

//----- (006ECB90) --------------------------------------------------------  // acclient.c:768540
void _E106_20()
{
  DEFAULT_VIEW_RADIUS_14 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006ECBB0) --------------------------------------------------------  // acclient.c:768546
void _E108_12()
{
  MIN_QUANTUM_14 = 1.0 / 30.0;
}

//----- (006ECBD0) --------------------------------------------------------  // acclient.c:768552
void _E110_3()
{
  MAX_QUANTUM_14 = 1.0 / 5.0;
}

//----- (006ECBF0) --------------------------------------------------------  // acclient.c:768558
void _E112_16()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_49, PFID_A8R8G8B8);
}

//----- (006ECC00) --------------------------------------------------------  // acclient.c:768564
int _E114_15()
{
  return atexit(nullsub_523);
}

//----- (006ECC10) --------------------------------------------------------  // acclient.c:768570
int _E1_90()
{
  return atexit(_E2_90);
}

