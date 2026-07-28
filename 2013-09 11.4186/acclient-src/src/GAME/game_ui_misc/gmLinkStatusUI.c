/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmLinkStatusUI
   Object     : GAME\game_ui_misc\gmLinkStatusUI.obj
   Functions  : 33
   Addresses  : 004AAD10 - 006F1790 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004AAD10) --------------------------------------------------------  // acclient.c:226258
void __userpurge gmLinkStatusUI::gmLinkStatusUI(gmLinkStatusUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmLinkStatusUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pMainText = 0;
  LODWORD(v4->m_nextUpdateTime) = 0;
  LODWORD(v4->m_lastPingRequestTime) = 0;
  LODWORD(v4->m_pingRoundTripTime) = 0;
  v4->m_bPleaseRequestPing = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmLinkStatusUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmLinkStatusUI::vftable;
  HIDWORD(v4->m_nextUpdateTime) = -1074790400;
  HIDWORD(v4->m_lastPingRequestTime) = -1074790400;
  HIDWORD(v4->m_pingRoundTripTime) = -1074790400;
}
// 7AE860: using guessed type bool (__thiscall *gmLinkStatusUI::vftable)(DBCache *this);
// 7AEB08: using guessed type int (__thiscall *gmLinkStatusUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004AAD80) --------------------------------------------------------  // acclient.c:226281
gmLinkStatusUI *__thiscall gmLinkStatusUI::DynamicCast(gmLinkStatusUI *this, unsigned int i_eType)
{
  gmLinkStatusUI *result; // eax@1

  result = this;
  if ( i_eType != 268435485 )
    result = (gmLinkStatusUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004AADA0) --------------------------------------------------------  // acclient.c:226292
signed int gmLinkStatusUI::GetUIElementType()
{
  return 268435485;
}

//----- (004AADB0) --------------------------------------------------------  // acclient.c:226298
void __thiscall gmLinkStatusUI::PostInit(gmLinkStatusUI *this)
{
  gmLinkStatusUI *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_pMainText = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000169u);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD21D, (NoticeHandler *)&v1->vfptr);
}

//----- (004AADF0) --------------------------------------------------------  // acclient.c:226311
void __usercall gmLinkStatusUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmLinkStatusUI *v3; // eax@1

  v3 = (gmLinkStatusUI *)operator new(0x620u);
  if ( v3 )
    gmLinkStatusUI::gmLinkStatusUI(v3, a1, _layout, _full_desc);
}

//----- (004AAE20) --------------------------------------------------------  // acclient.c:226321
gmLinkStatusUI *__thiscall gmLinkStatusUI::scalar_deleting_destructor(gmLinkStatusUI *this, unsigned int a2)
{
  gmLinkStatusUI *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmLinkStatusUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmLinkStatusUI::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  v2->m_pMainText = 0;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7AE860: using guessed type bool (__thiscall *gmLinkStatusUI::vftable)(DBCache *this);
// 7AEB08: using guessed type int (__thiscall *gmLinkStatusUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004AAE80) --------------------------------------------------------  // acclient.c:226347
void __cdecl gmLinkStatusUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000001Du,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmLinkStatusUI::Create);
}

//----- (004AAEA0) --------------------------------------------------------  // acclient.c:226355
char __thiscall gmLinkStatusUI::Update(gmLinkStatusUI *this)
{
  gmLinkStatusUI *v1; // esi@1
  PStringBase<unsigned short> *v2; // eax@1
  int v3; // edi@1
  gmClient *v4; // eax@4
  PSRefBufferCharData<char> *v5; // ecx@4
  PStringBase<char> v7; // [sp+Ch] [bp-1C0h]@4
  float packetLossPercent; // [sp+18h] [bp-1B4h]@1
  StringInfo siStaticText; // [sp+1Ch] [bp-1B0h]@1
  StringInfo siPingText; // [sp+ACh] [bp-120h]@4
  StringInfo siPacketLossText; // [sp+13Ch] [bp-90h]@4

  v1 = this;
  StringInfo::StringInfo(&siStaticText);
  StringInfo::SetStringIDandTableEnum(&siStaticText, ID_LinkStatus_Info, 268435457);
  v2 = StringInfo::GetString(&siStaticText, (PStringBase<unsigned short> *)&packetLossPercent, 0);
  UIElement_Text::SetText(v1->m_pMainText, v2);
  v3 = LODWORD(packetLossPercent) - 20;
  if ( !InterlockedDecrement((volatile LONG *)(LODWORD(packetLossPercent) - 20 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  StringInfo::SetStringIDandTableEnum(&siStaticText, ID_LinkStatus_Colors, 268435457);
  UIElement_Text::AppendStringInfo(v1->m_pMainText, &siStaticText);
  StringInfo::SetStringIDandTableEnum(&siStaticText, ID_LinkStatus_Disconnect, 268435457);
  UIElement_Text::AppendStringInfo(v1->m_pMainText, &siStaticText);
  v4 = Client::GetInstance();
  packetLossPercent = LinkStatusHolder::GetPacketLossPercentage((LinkStatusHolder *)&v4->vfptr);
  StringInfo::StringInfo(&siPacketLossText);
  StringInfo::SetStringIDandTableEnum(&siPacketLossText, ID_LinkStatus_PacketLoss, 268435457);
  StringInfo::AddVariable_Float(&siPacketLossText, ID_PacketLoss, packetLossPercent, 2u);
  v7.m_charbuffer = (PSRefBufferCharData<char> *)&siPacketLossText;
  UIElement_Text::AppendStringInfo(v1->m_pMainText, &siPacketLossText);
  StringInfo::StringInfo(&siPingText);
  StringInfo::SetStringIDandTableEnum(&siPingText, ID_LinkStatus_Ping, 268435457);
  if ( v1->m_pingRoundTripTime <= 0.0 )
  {
    v7.m_charbuffer = v5;
    PStringBase<char>::PStringBase<char>(&v7, "????");
    StringInfo::AddVariable_String(&siPingText, ID_Ping, v7);
  }
  else
  {
    StringInfo::AddVariable_Float(&siPingText, ID_Ping, v1->m_pingRoundTripTime * 1000.0, 0);
  }
  UIElement_Text::AppendStringInfo(v1->m_pMainText, &siPingText);
  if ( v1->m_bPleaseRequestPing || COERCE_DOUBLE(Timer::cur_time.Cmd) - v1->m_lastPingRequestTime >= 120.0 )
  {
    v1->m_lastPingRequestTime = *(double *)&Timer::cur_time;
    CM_Character::Event_RequestPing();
    v1->m_bPleaseRequestPing = 0;
  }
  StringInfo::~StringInfo(&siPingText);
  StringInfo::~StringInfo(&siPacketLossText);
  StringInfo::~StringInfo(&siStaticText);
  return 1;
}

//----- (004AB0B0) --------------------------------------------------------  // acclient.c:226413
int __thiscall gmLinkStatusUI::ListenToElementMessage(gmLinkStatusUI *this, UIElementMessageInfo *i_rMsg)
{
  gmLinkStatusUI *v2; // esi@1

  v2 = this;
  if ( i_rMsg->idMessage == 24 && (gmLinkStatusUI *)i_rMsg->pElement == this )
  {
    if ( i_rMsg->dwParam1 )
    {
      UIListener::RegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
      v2->m_bPleaseRequestPing = 1;
      gmLinkStatusUI::Update(v2);
      return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
    }
    UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    v2->m_bPleaseRequestPing = 0;
  }
  return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
}

//----- (004AB110) --------------------------------------------------------  // acclient.c:226434
void __thiscall gmLinkStatusUI::ListenToGlobalMessage(gmLinkStatusUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 3
    && (*((_DWORD *)&this->0 + 41) >> 1) & 1
    && COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_nextUpdateTime )
  {
    this->m_nextUpdateTime = COERCE_DOUBLE(Timer::cur_time.Cmd) + 5.0;
    gmLinkStatusUI::Update(this);
  }
}

//----- (004AB150) --------------------------------------------------------  // acclient.c:226446
void __thiscall gmLinkStatusUI::RecvNotice_Ping(gmLinkStatusUI *this)
{
  unsigned int v1; // eax@1
  unsigned int v2; // edx@2
  char *v3; // ecx@2

  v1 = (unsigned int)this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[5] >> 1;
  *(double *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = COERCE_DOUBLE(Timer::cur_time.Cmd)
                                                                                       - *(double *)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
  if ( v1 & 1 )
  {
    LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5]) = 1;
    v2 = (unsigned int)this[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[5];
    v3 = (char *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7];
    if ( (v2 >> 1) & 1 )
    {
      if ( COERCE_DOUBLE(Timer::cur_time.Cmd) >= *((double *)v3 + 192) )
      {
        *((double *)v3 + 192) = COERCE_DOUBLE(Timer::cur_time.Cmd) + 5.0;
        gmLinkStatusUI::Update((gmLinkStatusUI *)v3);
      }
    }
  }
}

//----- (006F1570) --------------------------------------------------------  // acclient.c:773577
void _E91_76()
{
  outside_val_68 = 1000.0 + 1.0;
}

//----- (006F1590) --------------------------------------------------------  // acclient.c:773583
void _E93_52()
{
  block_length_68 = 24.0 * 8.0;
}

//----- (006F15B0) --------------------------------------------------------  // acclient.c:773589
void _E95_52()
{
  half_square_length_68 = 24.0 * 0.5;
}

//----- (006F15D0) --------------------------------------------------------  // acclient.c:773595
int _E97_77()
{
  return atexit(_E98_89);
}

//----- (006F15E0) --------------------------------------------------------  // acclient.c:773601
int _E100_70()
{
  return atexit(nullsub_815);
}

//----- (006F15F0) --------------------------------------------------------  // acclient.c:773607
int _E103_62()
{
  return atexit(_E104_77);
}

//----- (006F1600) --------------------------------------------------------  // acclient.c:773613
void _E106_47()
{
  LOWEST_DATA_RATE_78 = 1024;
}

//----- (006F1610) --------------------------------------------------------  // acclient.c:773619
void _E108_34()
{
  HIGHEST_DATA_RATE_78 = 0x7FFF;
}

//----- (006F1620) --------------------------------------------------------  // acclient.c:773625
int _E110_25()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_78;
  INITIAL_MAX_DATA_RATE_26 = LOWEST_DATA_RATE_78;
  return result;
}

//----- (006F1630) --------------------------------------------------------  // acclient.c:773635
void _E112_42()
{
  DEFAULT_VIEW_RADIUS_40 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F1650) --------------------------------------------------------  // acclient.c:773641
void _E114_27()
{
  MIN_QUANTUM_40 = 1.0 / 30.0;
}

//----- (006F1670) --------------------------------------------------------  // acclient.c:773647
void _E116_7()
{
  MAX_QUANTUM_40 = 1.0 / 5.0;
}

//----- (006F1690) --------------------------------------------------------  // acclient.c:773653
void _E118_35()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_75, PFID_A8R8G8B8);
}

//----- (006F16A0) --------------------------------------------------------  // acclient.c:773659
int _E121_38()
{
  return atexit(_E122_73);
}

//----- (006F16B0) --------------------------------------------------------  // acclient.c:773665
unsigned int _E124_35()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_LinkStatus_Colors");
  ID_LinkStatus_Colors = result;
  return result;
}

//----- (006F16D0) --------------------------------------------------------  // acclient.c:773675
unsigned int _E126_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_LinkStatus_Disconnect");
  ID_LinkStatus_Disconnect = result;
  return result;
}

//----- (006F16F0) --------------------------------------------------------  // acclient.c:773685
unsigned int _E128_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_LinkStatus_Info");
  ID_LinkStatus_Info = result;
  return result;
}

//----- (006F1710) --------------------------------------------------------  // acclient.c:773695
unsigned int _E130_25()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_LinkStatus_PacketLoss");
  ID_LinkStatus_PacketLoss = result;
  return result;
}

//----- (006F1730) --------------------------------------------------------  // acclient.c:773705
unsigned int _E132_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_LinkStatus_Ping");
  ID_LinkStatus_Ping = result;
  return result;
}

//----- (006F1750) --------------------------------------------------------  // acclient.c:773715
unsigned int _E134_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PACKET_LOSS");
  ID_PacketLoss = result;
  return result;
}

//----- (006F1770) --------------------------------------------------------  // acclient.c:773725
unsigned int _E136_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PING");
  ID_Ping = result;
  return result;
}

//----- (006F1790) --------------------------------------------------------  // acclient.c:773735
int sub_6F1790()
{
  return atexit(nullsub_813);
}

