/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUIElement_LinkStatusIndicator
   Object     : GAME\game_ui_misc\gmUIElement_LinkStatusIndicator.obj
   Functions  : 25
   Addresses  : 004E6510 - 006F68A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E6510) --------------------------------------------------------  // acclient.c:276267
void __userpurge gmUIElement_LinkStatusIndicator::gmUIElement_LinkStatusIndicator(gmUIElement_LinkStatusIndicator *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmUIElement_LinkStatusIndicator *v4; // esi@1

  v4 = this;
  UIElement_Button::UIElement_Button((UIElement_Button *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_eLinkState = 0;
  LODWORD(v4->m_ttLastUpdate) = 0;
  HIDWORD(v4->m_ttLastUpdate) = 0;
  LODWORD(v4->m_ttLastFlash) = 0;
  HIDWORD(v4->m_ttLastFlash) = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_LinkStatusIndicator::vftable;
  v4->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7C1288: using guessed type int (__thiscall *gmUIElement_LinkStatusIndicator::vftable)(void *, char);

//----- (004E6570) --------------------------------------------------------  // acclient.c:276288
gmUIElement_LinkStatusIndicator *__thiscall gmUIElement_LinkStatusIndicator::DynamicCast(gmUIElement_LinkStatusIndicator *this, unsigned int i_eType)
{
  gmUIElement_LinkStatusIndicator *result; // eax@1

  result = this;
  if ( i_eType != 268435459 && i_eType != 1 && i_eType != 12 )
    result = (gmUIElement_LinkStatusIndicator *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E65B0) --------------------------------------------------------  // acclient.c:276305
void __usercall gmUIElement_LinkStatusIndicator::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmUIElement_LinkStatusIndicator *v3; // eax@1

  v3 = (gmUIElement_LinkStatusIndicator *)operator new(0x738u);
  if ( v3 )
    gmUIElement_LinkStatusIndicator::gmUIElement_LinkStatusIndicator(v3, a1, _layout, _full_desc);
}

//----- (004E65E0) --------------------------------------------------------  // acclient.c:276315
void __thiscall gmUIElement_LinkStatusIndicator::SetLinkState(gmUIElement_LinkStatusIndicator *this, unsigned int i_eLinkState)
{
  gmUIElement_LinkStatusIndicator *v2; // esi@1
  unsigned int v3; // edx@5

  v2 = this;
  if ( this->m_eLinkState != i_eLinkState )
  {
    this->m_eLinkState = i_eLinkState;
    switch ( i_eLinkState )
    {
      case 1u:
        ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(17);
        break;
      case 2u:
        ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(18);
        break;
      case 3u:
        ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(19);
        v3 = i_key.m_dwKey;
        LODWORD(v2->m_ttLastFlash) = Timer::cur_time.Cmd;
        HIDWORD(v2->m_ttLastFlash) = v3;
        break;
      case 4u:
        ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(20);
        break;
      default:
        return;
    }
  }
}

//----- (004E6670) --------------------------------------------------------  // acclient.c:276348
UIElement_Button *__thiscall gmUIElement_LinkStatusIndicator::vector_deleting_destructor(gmUIElement_LinkStatusIndicator *this, unsigned int a2)
{
  UIElement_Button *v2; // esi@1
  NoticeHandler *v3; // edi@1

  v2 = (UIElement_Button *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_LinkStatusIndicator::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Button::~UIElement_Button(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7C1288: using guessed type int (__thiscall *gmUIElement_LinkStatusIndicator::vftable)(void *, char);

//----- (004E66D0) --------------------------------------------------------  // acclient.c:276371
void __thiscall gmUIElement_LinkStatusIndicator::PostInit(gmUIElement_LinkStatusIndicator *this)
{
  gmUIElement_LinkStatusIndicator *v1; // esi@1

  v1 = this;
  UIElement_Button::PostInit((UIElement_Button *)&this->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  if ( v1->m_eLinkState != 1 )
  {
    v1->m_eLinkState = 1;
    v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 17u);
  }
}

//----- (004E6710) --------------------------------------------------------  // acclient.c:276386
void __cdecl gmUIElement_LinkStatusIndicator::Register()
{
  UIElement::RegisterElementClass(
    0x10000003u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmUIElement_LinkStatusIndicator::Create);
}

//----- (004E6730) --------------------------------------------------------  // acclient.c:276394
void __thiscall gmUIElement_LinkStatusIndicator::UpdateLinkState(gmUIElement_LinkStatusIndicator *this)
{
  gmUIElement_LinkStatusIndicator *v1; // esi@1
  gmClient *v2; // eax@1
  long double v3; // st7@1
  unsigned int v4; // ecx@1
  int bConnected; // [sp+0h] [bp-4h]@1

  v1 = this;
  bConnected = 0;
  v2 = Client::GetInstance();
  v3 = LinkStatusHolder::GetConnectionStatus((LinkStatusHolder *)&v2->vfptr, &bConnected);
  v4 = 1;
  if ( v3 <= 5.0 && bConnected )
    goto LABEL_6;
  if ( v3 <= 20.0 && bConnected )
  {
    v4 = 2;
LABEL_6:
    gmUIElement_LinkStatusIndicator::SetLinkState(v1, v4);
    return;
  }
  if ( v3 <= 40.0 && bConnected )
    gmUIElement_LinkStatusIndicator::SetLinkState(v1, 3u);
  else
    gmUIElement_LinkStatusIndicator::SetLinkState(v1, 4u);
}

//----- (004E67C0) --------------------------------------------------------  // acclient.c:276423
void __thiscall gmUIElement_LinkStatusIndicator::UseTime(gmUIElement_LinkStatusIndicator *this)
{
  gmUIElement_LinkStatusIndicator *v1; // esi@1
  double ttCurTime; // [sp+4h] [bp-8h]@1

  v1 = this;
  ttCurTime = *(double *)&Timer::cur_time;
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - this->m_ttLastUpdate > 4.0 )
  {
    gmUIElement_LinkStatusIndicator::UpdateLinkState(this);
    v1->m_ttLastUpdate = ttCurTime;
  }
  if ( v1->m_eLinkState == 3 && ttCurTime - v1->m_ttLastFlash >= 0.75 )
  {
    if ( v1->m_state == 18 )
      v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 19u);
    else
      v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 18u);
    v1->m_ttLastFlash = ttCurTime;
  }
}

//----- (004E6870) --------------------------------------------------------  // acclient.c:276446
void __thiscall gmUIElement_LinkStatusIndicator::ListenToGlobalMessage(gmUIElement_LinkStatusIndicator *this, unsigned int i_messageID, int i_data_int)
{
  UIElement_Button *v3; // esi@1

  v3 = (UIElement_Button *)this;
  if ( i_messageID == 3 )
    gmUIElement_LinkStatusIndicator::UseTime(this);
  UIElement_Button::ListenToGlobalMessage(v3, i_messageID, i_data_int);
}

//----- (006F6760) --------------------------------------------------------  // acclient.c:779164
void sub_6F6760()
{
  flt_840840 = 1000.0 + 1.0;
}

//----- (006F6780) --------------------------------------------------------  // acclient.c:779170
void _E93_95()
{
  flt_840844 = 24.0 * 8.0;
}

//----- (006F67A0) --------------------------------------------------------  // acclient.c:779176
void _E95_95()
{
  flt_840848 = 24.0 * 0.5;
}

//----- (006F67C0) --------------------------------------------------------  // acclient.c:779182
int sub_6F67C0()
{
  return atexit(nullsub_957);
}

//----- (006F67D0) --------------------------------------------------------  // acclient.c:779188
int sub_6F67D0()
{
  return atexit(nullsub_958);
}

//----- (006F67E0) --------------------------------------------------------  // acclient.c:779194
int sub_6F67E0()
{
  return atexit(nullsub_959);
}

//----- (006F67F0) --------------------------------------------------------  // acclient.c:779200
void _E106_72()
{
  dword_84084C = 1024;
}

//----- (006F6800) --------------------------------------------------------  // acclient.c:779206
void _E108_57()
{
  dword_840850 = 0x7FFF;
}

//----- (006F6810) --------------------------------------------------------  // acclient.c:779212
int _E110_47()
{
  const int result; // eax@1

  result = dword_84084C;
  INITIAL_MAX_DATA_RATE_49 = dword_84084C;
  return result;
}

//----- (006F6820) --------------------------------------------------------  // acclient.c:779222
void _E112_64()
{
  DEFAULT_VIEW_RADIUS_76 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F6840) --------------------------------------------------------  // acclient.c:779228
void _E114_33()
{
  MIN_QUANTUM_76 = 1.0 / 30.0;
}

//----- (006F6860) --------------------------------------------------------  // acclient.c:779234
void _E116_12()
{
  MAX_QUANTUM_76 = 1.0 / 5.0;
}

//----- (006F6880) --------------------------------------------------------  // acclient.c:779240
void _E118_50()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840870, PFID_A8R8G8B8);
}

//----- (006F6890) --------------------------------------------------------  // acclient.c:779246
int _E120_39()
{
  return atexit(nullsub_955);
}

//----- (006F68A0) --------------------------------------------------------  // acclient.c:779252
int sub_6F68A0()
{
  return atexit(nullsub_956);
}

