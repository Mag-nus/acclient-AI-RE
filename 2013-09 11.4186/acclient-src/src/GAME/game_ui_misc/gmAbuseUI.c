/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmAbuseUI
   Object     : GAME\game_ui_misc\gmAbuseUI.obj
   Functions  : 34
   Addresses  : 004BBEB0 - 006F22E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BBEB0) --------------------------------------------------------  // acclient.c:238866
void __userpurge gmAbuseUI::gmAbuseUI(gmAbuseUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmAbuseUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pNameBox = 0;
  v4->m_pEntryBox = 0;
  v4->m_pResultText = 0;
  v4->m_pContinueButton = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmAbuseUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmAbuseUI::vftable;
}
// 7B35D0: using guessed type bool (__thiscall *gmAbuseUI::vftable)(DBCache *this);
// 7B3878: using guessed type int (__thiscall *gmAbuseUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BBF00) --------------------------------------------------------  // acclient.c:238885
gmAbuseUI *__thiscall gmAbuseUI::DynamicCast(gmAbuseUI *this, unsigned int i_eType)
{
  gmAbuseUI *result; // eax@1

  result = this;
  if ( i_eType != 268435480 )
    result = (gmAbuseUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004BBF20) --------------------------------------------------------  // acclient.c:238896
signed int gmAbuseUI::GetUIElementType()
{
  return 268435480;
}

//----- (004BBF30) --------------------------------------------------------  // acclient.c:238902
void __thiscall gmAbuseUI::PostInit(gmAbuseUI *this)
{
  gmAbuseUI *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_pNameBox = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000105u);
  v1->m_pEntryBox = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000107u);
  v1->m_pResultText = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000010Bu);
  v1->m_pContinueButton = (UIElement_Button *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000109u);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)nullsub_1891, (NoticeHandler *)&v1->vfptr);
}
// 4DD221: using guessed type int __stdcall nullsub_1891(int);

//----- (004BBFA0) --------------------------------------------------------  // acclient.c:238919
void __thiscall gmAbuseUI::~gmAbuseUI(gmAbuseUI *this)
{
  gmAbuseUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmAbuseUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmAbuseUI::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v1->m_pNameBox = 0;
  v1->m_pEntryBox = 0;
  v1->m_pResultText = 0;
  v1->m_pContinueButton = 0;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7B35D0: using guessed type bool (__thiscall *gmAbuseUI::vftable)(DBCache *this);
// 7B3878: using guessed type int (__thiscall *gmAbuseUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BC000) --------------------------------------------------------  // acclient.c:238945
void __usercall gmAbuseUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmAbuseUI *v3; // eax@1

  v3 = (gmAbuseUI *)operator new(0x60Cu);
  if ( v3 )
    gmAbuseUI::gmAbuseUI(v3, a1, _layout, _full_desc);
}

//----- (004BC030) --------------------------------------------------------  // acclient.c:238955
gmAbuseUI *__thiscall gmAbuseUI::scalar_deleting_destructor(gmAbuseUI *this, unsigned int a2)
{
  gmAbuseUI *v2; // esi@1

  v2 = this;
  gmAbuseUI::~gmAbuseUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004BC050) --------------------------------------------------------  // acclient.c:238967
void __cdecl gmAbuseUI::Register()
{
  UIElement::RegisterElementClass(0x10000018u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmAbuseUI::Create);
}

//----- (004BC070) --------------------------------------------------------  // acclient.c:238973
char __thiscall gmAbuseUI::HandleTextEntry(gmAbuseUI *this)
{
  gmAbuseUI *v1; // edi@1
  bool v2; // bl@2
  char *v3; // esi@2
  char *v4; // esi@7
  UIElement_Button *v5; // ecx@10
  char v6; // al@11
  PStringBase<unsigned short> v7; // [sp+10h] [bp-8h]@2
  PStringBase<unsigned short> result; // [sp+14h] [bp-4h]@1

  v1 = this;
  if ( *(_DWORD *)&UIElement_Text::GetText(this->m_pNameBox, &result)->m_charbuffer[-1].m_data[14] == 1 )
    goto LABEL_15;
  v2 = *(_DWORD *)&UIElement_Text::GetText(v1->m_pEntryBox, &v7)->m_charbuffer[-1].m_data[14] == 1;
  v3 = (char *)&v7.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v7.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  if ( v2 )
LABEL_15:
    v2 = 1;
  v4 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = v1->m_pContinueButton;
  if ( v2 )
  {
    ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(13);
    v6 = 1;
  }
  else
  {
    ((void (__stdcall *)(signed int))v5->vfptr[13].__vecDelDtor)(1);
    v6 = 1;
  }
  return v6;
}

//----- (004BC130) --------------------------------------------------------  // acclient.c:239012
char __thiscall gmAbuseUI::SetPageThreeText(gmAbuseUI *this, const unsigned int token)
{
  gmAbuseUI *v2; // esi@1
  PStringBase<unsigned short> *v3; // eax@1
  char *v4; // esi@1
  PStringBase<unsigned short> result; // [sp+4h] [bp-94h]@1
  StringInfo siText; // [sp+8h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&siText);
  StringInfo::SetStringIDandTableEnum(&siText, token, 268435457);
  v3 = StringInfo::GetString(&siText, &result, 0);
  UIElement_Text::SetText(v2->m_pResultText, v3);
  v4 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  StringInfo::~StringInfo(&siText);
  return 1;
}

//----- (004BC1B0) --------------------------------------------------------  // acclient.c:239033
void __thiscall gmAbuseUI::RecvNotice_AbuseReportResponse(gmAbuseUI *this, unsigned int error)
{
  switch ( error )
  {
    case 0x4B8u:
      gmAbuseUI::SetPageThreeText((gmAbuseUI *)((char *)this - 1528), ID_Abuse_Response_NoSuchCharacter);
      break;
    case 0x4B9u:
      gmAbuseUI::SetPageThreeText((gmAbuseUI *)((char *)this - 1528), ID_Abuse_Response_Self);
      break;
    case 0x4BAu:
      gmAbuseUI::SetPageThreeText((gmAbuseUI *)((char *)this - 1528), ID_Abuse_Response_Success);
      break;
  }
}

//----- (004BC200) --------------------------------------------------------  // acclient.c:239050
char __thiscall gmAbuseUI::Reset(gmAbuseUI *this)
{
  gmAbuseUI *v1; // esi@1
  char *v2; // edi@1
  char *v3; // edi@4
  PStringBase<unsigned short> _text; // [sp+10h] [bp-4h]@1

  v1 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(0);
  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  UIElement_Text::SetText(v1->m_pNameBox, &_text);
  v2 = (char *)&_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  _text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  UIElement_Text::SetText(v1->m_pEntryBox, &_text);
  v3 = (char *)&_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  ((void (__stdcall *)(signed int))v1->m_pContinueButton->vfptr[13].__vecDelDtor)(13);
  v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435464u);
  return 1;
}

//----- (004BC2C0) --------------------------------------------------------  // acclient.c:239077
char __thiscall gmAbuseUI::HandleSelection(gmAbuseUI *this)
{
  gmAbuseUI *v1; // ebx@1
  unsigned int v2; // ecx@2
  HashBaseData<unsigned long> *v3; // esi@5
  const char *v4; // eax@7
  AC1Legacy::PSRefBuffer<char> *v5; // edi@7
  PStringBase<unsigned short> *v6; // eax@7
  char *v7; // esi@7
  AC1Legacy::PStringBase<char> strCharName; // [sp+0h] [bp-4h]@1

  strCharName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)this;
  v1 = this;
  if ( SmartBox::smartbox )
    v2 = SmartBox::smartbox->player_id;
  else
    v2 = 0;
  if ( ACCWeenieObject::selectedID != v2 )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(ACCWeenieObject::selectedID);
    if ( v3 )
    {
      if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v3->vfptr[4].__vecDelDtor)(v3) )
      {
        v4 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v3, NAME_APPROPRIATE, 0);
        AC1Legacy::PStringBase<char>::PStringBase<char>(&strCharName, v4);
        v5 = strCharName.m_buffer;
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&strCharName,
          0,
          strCharName.m_buffer->m_data);
        UIElement_Text::SetText(v1->m_pNameBox, v6);
        v7 = (char *)&strCharName.m_buffer[-1].m_cRef;
        if ( !InterlockedDecrement((volatile LONG *)&strCharName.m_buffer[-1].m_cRef + 1) && v7 )
          (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
        if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
          v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
      }
    }
  }
  return 1;
}

//----- (004BC380) --------------------------------------------------------  // acclient.c:239121
char __thiscall gmAbuseUI::ReportAbuse(gmAbuseUI *this)
{
  gmAbuseUI *v1; // ebp@1
  bool v2; // bl@2
  char *v3; // edi@2
  char *v4; // edi@7
  char *v5; // edi@11
  char v6; // al@14
  PStringBase<unsigned short> *v7; // eax@15
  PStringBase<unsigned short> *v8; // eax@15
  PSRefBufferCharData<char> *v9; // ebx@15
  PSRefBufferCharData<unsigned short> *v10; // edi@15
  char *v11; // edi@21
  PSRefBufferCharData<unsigned short> *v12; // edi@24
  char *v13; // edi@27
  char *v14; // edi@30
  PStringBase<unsigned short> _value; // [sp+10h] [bp-A8h]@11
  PStringBase<unsigned short> result; // [sp+14h] [bp-A4h]@1
  PStringBase<unsigned short> v17; // [sp+18h] [bp-A0h]@2
  PStringBase<char> v18; // [sp+1Ch] [bp-9Ch]@15
  PStringBase<unsigned short> v19; // [sp+20h] [bp-98h]@15
  PStringBase<unsigned short> v20; // [sp+24h] [bp-94h]@15
  StringInfo siError; // [sp+28h] [bp-90h]@11

  v1 = this;
  if ( *(_DWORD *)&UIElement_Text::GetText(this->m_pNameBox, &result)->m_charbuffer[-1].m_data[14] == 1 )
    goto LABEL_36;
  v2 = *(_DWORD *)&UIElement_Text::GetText(v1->m_pEntryBox, &v17)->m_charbuffer[-1].m_data[14] == 1;
  v3 = (char *)&v17.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v17.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  if ( v2 )
LABEL_36:
    v2 = 1;
  v4 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  if ( v2 )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"Please specify character and complaint.");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v5 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    v6 = 0;
  }
  else
  {
    v7 = UIElement_Text::GetText(v1->m_pEntryBox, &v19);
    PStringBase<unsigned short>::to_spstring(v7, (PStringBase<char> *)&v17, 0);
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&result,
      (const char *)v17.m_charbuffer);
    v8 = UIElement_Text::GetText(v1->m_pNameBox, &v20);
    PStringBase<unsigned short>::to_spstring(v8, &v18, 0);
    v9 = v18.m_charbuffer;
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&_value, v18.m_charbuffer->m_data);
    CM_Character::Event_AbuseLogRequest(
      (AC1Legacy::PStringBase<char> *)&_value,
      1,
      (AC1Legacy::PStringBase<char> *)&result);
    v10 = _value.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer->m_data[2]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v10->m_data[0])(v10, 1);
    if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v9 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v9[-2].m_data[12])(&v9[-2].m_data[12], 1);
    v11 = (char *)&v20.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v20.m_charbuffer[-1].m_data[8]) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v12 = result.m_charbuffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer->m_data[2]) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v12->m_data[0])(v12, 1);
    v13 = (char *)&v17.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v17.m_charbuffer[-1].m_data[8]) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    v14 = (char *)&v19.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v19.m_charbuffer[-1].m_data[8]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435466u);
    gmAbuseUI::SetPageThreeText(v1, ID_Abuse_PageThree_WaitText);
    v6 = 1;
  }
  return v6;
}

//----- (004BC5C0) --------------------------------------------------------  // acclient.c:239213
int __thiscall gmAbuseUI::ListenToElementMessage(gmAbuseUI *this, UIElementMessageInfo *i_rMsg)
{
  gmAbuseUI *v2; // esi@1

  v2 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    switch ( i_rMsg->idElement )
    {
      case 0x10000101u:
      case 0x1000010Cu:
        gmAbuseUI::Reset(this);
        break;
      case 0x10000102u:
        ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(268435465);
        gmAbuseUI::HandleSelection(v2);
        break;
      case 0x10000109u:
        gmAbuseUI::ReportAbuse(this);
        break;
      default:
        break;
    }
  }
  else if ( i_rMsg->idMessage != 18 && i_rMsg->idMessage != 68 )
  {
    return UIElement::ListenToElementMessage((UIElement *)&this->vfptr, i_rMsg);
  }
  if ( i_rMsg->idElement == 268435717 || i_rMsg->idElement == 268435719 )
    gmAbuseUI::HandleTextEntry(v2);
  return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
}

//----- (006F2120) --------------------------------------------------------  // acclient.c:774455
void _E91_81()
{
  outside_val_73 = 1000.0 + 1.0;
}

//----- (006F2140) --------------------------------------------------------  // acclient.c:774461
void _E93_57()
{
  block_length_73 = 24.0 * 8.0;
}

//----- (006F2160) --------------------------------------------------------  // acclient.c:774467
void _E95_57()
{
  half_square_length_73 = 24.0 * 0.5;
}

//----- (006F2180) --------------------------------------------------------  // acclient.c:774473
int _E97_82()
{
  return atexit(_E98_94);
}

//----- (006F2190) --------------------------------------------------------  // acclient.c:774479
int _E100_75()
{
  return atexit(nullsub_786);
}

//----- (006F21A0) --------------------------------------------------------  // acclient.c:774485
int _E103_67()
{
  return atexit(_E104_82);
}

//----- (006F21B0) --------------------------------------------------------  // acclient.c:774491
void _E106_50()
{
  DEFAULT_VIEW_RADIUS_44 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F21D0) --------------------------------------------------------  // acclient.c:774497
void _E108_37()
{
  MIN_QUANTUM_44 = 1.0 / 30.0;
}

//----- (006F21F0) --------------------------------------------------------  // acclient.c:774503
void _E110_28()
{
  MAX_QUANTUM_44 = 1.0 / 5.0;
}

//----- (006F2210) --------------------------------------------------------  // acclient.c:774509
void _E112_45()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_79, PFID_A8R8G8B8);
}

//----- (006F2220) --------------------------------------------------------  // acclient.c:774515
void _E115_35()
{
  LOWEST_DATA_RATE_81 = 1024;
}

//----- (006F2230) --------------------------------------------------------  // acclient.c:774521
void _E117_29()
{
  HIGHEST_DATA_RATE_81 = 0x7FFF;
}

//----- (006F2240) --------------------------------------------------------  // acclient.c:774527
int _E119_14()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_81;
  INITIAL_MAX_DATA_RATE_29 = LOWEST_DATA_RATE_81;
  return result;
}

//----- (006F2250) --------------------------------------------------------  // acclient.c:774537
int _E121_40()
{
  return atexit(_E122_74);
}

//----- (006F2260) --------------------------------------------------------  // acclient.c:774543
unsigned int _E127_32()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Abuse_PageThree_WaitText");
  ID_Abuse_PageThree_WaitText = result;
  return result;
}

//----- (006F2280) --------------------------------------------------------  // acclient.c:774553
unsigned int _E129_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Abuse_Response_NoSuchCharacter");
  ID_Abuse_Response_NoSuchCharacter = result;
  return result;
}

//----- (006F22A0) --------------------------------------------------------  // acclient.c:774563
unsigned int _E131_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Abuse_Response_Self");
  ID_Abuse_Response_Self = result;
  return result;
}

//----- (006F22C0) --------------------------------------------------------  // acclient.c:774573
unsigned int _E133_22()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Abuse_Response_Success");
  ID_Abuse_Response_Success = result;
  return result;
}

//----- (006F22E0) --------------------------------------------------------  // acclient.c:774583
int sub_6F22E0()
{
  return atexit(nullsub_784);
}

