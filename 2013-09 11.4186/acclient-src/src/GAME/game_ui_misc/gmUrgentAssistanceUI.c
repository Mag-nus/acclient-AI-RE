/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUrgentAssistanceUI
   Object     : GAME\game_ui_misc\gmUrgentAssistanceUI.obj
   Functions  : 22
   Addresses  : 004A7810 - 006F1410 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A7810) --------------------------------------------------------  // acclient.c:223142
gmUrgentAssistanceUI *__thiscall gmUrgentAssistanceUI::DynamicCast(gmUrgentAssistanceUI *this, unsigned int i_eType)
{
  gmUrgentAssistanceUI *result; // eax@1

  result = this;
  if ( i_eType != 268435487 )
    result = (gmUrgentAssistanceUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A7830) --------------------------------------------------------  // acclient.c:223153
signed int gmUrgentAssistanceUI::GetUIElementType()
{
  return 268435487;
}

//----- (004A7840) --------------------------------------------------------  // acclient.c:223159
void __thiscall gmUrgentAssistanceUI::PostInit(gmUrgentAssistanceUI *this)
{
  gmUrgentAssistanceUI *v1; // esi@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_pEntryBox = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001BAu);
  v1->m_pContinueButton = (UIElement_Button *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001BDu);
}

//----- (004A7870) --------------------------------------------------------  // acclient.c:223170
UIElement *__usercall gmUrgentAssistanceUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x604u);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmUrgentAssistanceUI::vftable;
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *((_DWORD *)v3 + 383) = 0;
    *((_DWORD *)v3 + 384) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7AD840: using guessed type int (__thiscall *gmUrgentAssistanceUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A78D0) --------------------------------------------------------  // acclient.c:223196
gmUrgentAssistanceUI *__thiscall gmUrgentAssistanceUI::vector_deleting_destructor(gmUrgentAssistanceUI *this, unsigned int a2)
{
  gmUrgentAssistanceUI *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmUrgentAssistanceUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v2->m_pEntryBox = 0;
  v2->m_pContinueButton = 0;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7AD840: using guessed type int (__thiscall *gmUrgentAssistanceUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A7920) --------------------------------------------------------  // acclient.c:223218
void __cdecl gmUrgentAssistanceUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000001Fu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmUrgentAssistanceUI::Create);
}

//----- (004A7940) --------------------------------------------------------  // acclient.c:223226
int __thiscall gmUrgentAssistanceUI::ListenToElementMessage(gmUrgentAssistanceUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIElement *v3; // esi@1
  bool v5; // bl@8
  PStringBase<unsigned short> *v6; // eax@9
  bool v7; // bl@11
  char *v8; // edi@11
  HashSetData<UIElement *> *v9; // ecx@14
  PStringBase<unsigned short> _text; // [sp+Ch] [bp-18h]@6
  AC1Legacy::PStringBase<char> i_msg; // [sp+10h] [bp-14h]@9
  PStringBase<char> v12; // [sp+14h] [bp-10h]@9
  PStringBase<unsigned short> result; // [sp+18h] [bp-Ch]@8
  PStringBase<unsigned short> v14; // [sp+1Ch] [bp-8h]@9
  PStringBase<unsigned short> v15; // [sp+20h] [bp-4h]@11

  v2 = i_rMsg;
  v3 = (UIElement *)this;
  if ( i_rMsg->idMessage == 1 )
  {
    switch ( i_rMsg->idElement )
    {
      case 0x100001B6u:
      case 0x100001C0u:
        ((void (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&_text, &word_794320);
        UIElement_Text::SetText(
          (UIElement_Text *)v3[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0],
          &_text);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_text);
        ((void (__stdcall *)(signed int))v3[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]->m_hashKey->m_alphaImage)(13);
        v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435470u);
        break;
      case 0x100001B7u:
        this->vfptr[13].__vecDelDtor((IInputActionCallback *)this, 268435471u);
        break;
      case 0x100001BDu:
        v5 = *(_DWORD *)&UIElement_Text::GetText(this->m_pEntryBox, &result)->m_charbuffer[-1].m_data[14] != 1;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        if ( v5 )
        {
          v6 = UIElement_Text::GetText(
                 (UIElement_Text *)v3[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0],
                 &v14);
          PStringBase<unsigned short>::to_spstring(v6, &v12, 0);
          AC1Legacy::PStringBase<char>::PStringBase<char>(&i_msg, v12.m_charbuffer->m_data);
          CM_Communication::Event_ChannelBroadcast(0x400u, &i_msg);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&i_msg);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v12);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v14);
          v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 268435472u);
        }
        break;
      default:
        break;
    }
  }
  else if ( i_rMsg->idMessage != 18 && i_rMsg->idMessage != 68 )
  {
    return UIElement::ListenToElementMessage((UIElement *)&this->vfptr, i_rMsg);
  }
  if ( i_rMsg->idElement == 268435898 )
  {
    v7 = *(_DWORD *)&UIElement_Text::GetText(
                       (UIElement_Text *)v3[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0],
                       &v15)->m_charbuffer[-1].m_data[14] == 1;
    v8 = (char *)&v15.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = v3[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
    if ( v7 )
      ((void (__stdcall *)(signed int))v9->m_hashKey->m_alphaImage)(13);
    else
      ((void (__stdcall *)(signed int))v9->m_hashKey->m_alphaImage)(1);
    v2 = i_rMsg;
  }
  return UIElement::ListenToElementMessage(v3, v2);
}

//----- (006F12D0) --------------------------------------------------------  // acclient.c:773389
void _E91_74()
{
  outside_val_66 = 1000.0 + 1.0;
}

//----- (006F12F0) --------------------------------------------------------  // acclient.c:773395
void _E93_50()
{
  block_length_66 = 24.0 * 8.0;
}

//----- (006F1310) --------------------------------------------------------  // acclient.c:773401
void _E95_50()
{
  half_square_length_66 = 24.0 * 0.5;
}

//----- (006F1330) --------------------------------------------------------  // acclient.c:773407
int _E97_75()
{
  return atexit(_E98_87);
}

//----- (006F1340) --------------------------------------------------------  // acclient.c:773413
int _E100_68()
{
  return atexit(nullsub_825);
}

//----- (006F1350) --------------------------------------------------------  // acclient.c:773419
int _E103_60()
{
  return atexit(_E104_75);
}

//----- (006F1360) --------------------------------------------------------  // acclient.c:773425
void _E106_46()
{
  DEFAULT_VIEW_RADIUS_38 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F1380) --------------------------------------------------------  // acclient.c:773431
void _E108_33()
{
  MIN_QUANTUM_38 = 1.0 / 30.0;
}

//----- (006F13A0) --------------------------------------------------------  // acclient.c:773437
void _E110_24()
{
  MAX_QUANTUM_38 = 1.0 / 5.0;
}

//----- (006F13C0) --------------------------------------------------------  // acclient.c:773443
void _E112_41()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_73, PFID_A8R8G8B8);
}

//----- (006F13D0) --------------------------------------------------------  // acclient.c:773449
void _E115_32()
{
  LOWEST_DATA_RATE_76 = 1024;
}

//----- (006F13E0) --------------------------------------------------------  // acclient.c:773455
void _E117_28()
{
  HIGHEST_DATA_RATE_76 = 0x7FFF;
}

//----- (006F13F0) --------------------------------------------------------  // acclient.c:773461
int _E119_13()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_76;
  INITIAL_MAX_DATA_RATE_24 = LOWEST_DATA_RATE_76;
  return result;
}

//----- (006F1400) --------------------------------------------------------  // acclient.c:773471
int _E121_37()
{
  return atexit(_E122_72);
}

//----- (006F1410) --------------------------------------------------------  // acclient.c:773477
int sub_6F1410()
{
  return atexit(nullsub_823);
}

