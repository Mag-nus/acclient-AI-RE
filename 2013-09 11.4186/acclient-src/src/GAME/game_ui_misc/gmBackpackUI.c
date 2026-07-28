/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmBackpackUI
   Object     : GAME\game_ui_misc\gmBackpackUI.obj
   Functions  : 25
   Addresses  : 004A6D70 - 00760F20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A6D70) --------------------------------------------------------  // acclient.c:222554
void __userpurge gmBackpackUI::gmBackpackUI(gmBackpackUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmBackpackUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_burdenText = 0;
  v4->m_burdenMeter = 0;
  v4->m_topContainer = 0;
  v4->m_containerList = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmBackpackUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmBackpackUI::vftable;
}
// 7ACB90: using guessed type bool (__thiscall *gmBackpackUI::vftable)(DBCache *this);
// 7ACE38: using guessed type int (__thiscall *gmBackpackUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A6DC0) --------------------------------------------------------  // acclient.c:222573
gmBackpackUI *__thiscall gmBackpackUI::DynamicCast(gmBackpackUI *this, unsigned int i_eType)
{
  gmBackpackUI *result; // eax@1

  result = this;
  if ( i_eType != 268435490 )
    result = (gmBackpackUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A6DE0) --------------------------------------------------------  // acclient.c:222584
signed int gmBackpackUI::GetUIElementType()
{
  return 268435490;
}

//----- (004A6DF0) --------------------------------------------------------  // acclient.c:222590
void __usercall gmBackpackUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmBackpackUI *v3; // eax@1

  v3 = (gmBackpackUI *)operator new(0x60Cu);
  if ( v3 )
    gmBackpackUI::gmBackpackUI(v3, a1, _layout, _full_desc);
}

//----- (004A6E20) --------------------------------------------------------  // acclient.c:222600
UIElement_Field *__thiscall gmBackpackUI::vector_deleting_destructor(gmBackpackUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmBackpackUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmBackpackUI::vftable;
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
// 7ACB90: using guessed type bool (__thiscall *gmBackpackUI::vftable)(DBCache *this);
// 7ACE38: using guessed type int (__thiscall *gmBackpackUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A6E80) --------------------------------------------------------  // acclient.c:222625
void __cdecl gmBackpackUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000022u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmBackpackUI::Create);
}

//----- (004A6EA0) --------------------------------------------------------  // acclient.c:222633
void __thiscall gmBackpackUI::SetLoadLevel(gmBackpackUI *this, long double _level)
{
  gmBackpackUI *v2; // esi@1
  UIElement *v3; // ecx@6
  float _val; // ST14_4@7
  double v5; // st7@8
  char *v6; // esi@8
  PStringBase<unsigned short> burdenText; // [sp+Ch] [bp-4h]@1
  double _levela; // [sp+14h] [bp+4h]@1

  burdenText.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  _levela = _level * 0.3333333333333333;
  if ( _levela >= 0.0 )
  {
    if ( _levela <= 1.0 )
      goto LABEL_6;
    HIDWORD(_levela) = 1072693248;
  }
  else
  {
    HIDWORD(_levela) = 0;
  }
  LODWORD(_levela) = 0;
LABEL_6:
  v3 = (UIElement *)&this->m_burdenMeter->vfptr;
  if ( v3 )
  {
    _val = _levela;
    UIElement::SetAttribute_Float(v3, 0x69u, _val);
  }
  v5 = _floor(_levela * 300.0);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&burdenText, 0, L"%d%%", (unsigned __int64)v5);
  UIElement_Text::SetText(v2->m_burdenText, &burdenText);
  v6 = (char *)&burdenText.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&burdenText.m_charbuffer[-1].m_data[8]) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  }
}

//----- (004A6F70) --------------------------------------------------------  // acclient.c:222676
void __thiscall gmBackpackUI::PostInit(gmBackpackUI *this)
{
  gmBackpackUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  GlobalEventHandler *v8; // eax@10
  GlobalEventHandler *v9; // edi@10
  int v10; // esi@11

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_burdenText = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001D8u);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001D9u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)7);
  else
    v3 = 0;
  v1->m_burdenMeter = (UIElement_Meter *)v3;
  gmBackpackUI::SetLoadLevel(v1, 0.0);
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001C9u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)268435505);
  else
    v5 = 0;
  v1->m_topContainer = (UIElement_ItemList *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001CAu);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435505);
  else
    v7 = 0;
  v1->m_containerList = (UIElement_ItemList *)v7;
  v8 = GlobalEventHandler::GetGlobalEventHandler();
  v9 = v8;
  if ( v8 )
  {
    v10 = (int)&v1->vfptr;
    v8->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v8,
      (unsigned int)((char *)&loc_4DD21E + 2),
      (NoticeHandler *)v10);
    v9->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v9, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v10);
  }
}

//----- (004A7040) --------------------------------------------------------  // acclient.c:222725
void __thiscall gmBackpackUI::RecvNotice_PlayerDescReceived(gmBackpackUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmBackpackUI *v3; // esi@1
  float fNewLoad; // [sp+Ch] [bp-4h]@1

  v3 = this;
  fNewLoad = 0.0;
  CACQualities::InqLoad(i_playerDesc, &fNewLoad);
  gmBackpackUI::SetLoadLevel((gmBackpackUI *)((char *)v3 - 1528), fNewLoad);
}

//----- (004A7080) --------------------------------------------------------  // acclient.c:222737
void __thiscall gmBackpackUI::RecvNotice_LoadChanged(gmBackpackUI *this, float fNewLoad)
{
  gmBackpackUI::SetLoadLevel((gmBackpackUI *)((char *)this - 1528), fNewLoad);
}

//----- (006F0ED0) --------------------------------------------------------  // acclient.c:773127
void _E91_71()
{
  outside_val_63 = 1000.0 + 1.0;
}

//----- (006F0EF0) --------------------------------------------------------  // acclient.c:773133
void _E93_47()
{
  block_length_63 = 24.0 * 8.0;
}

//----- (006F0F10) --------------------------------------------------------  // acclient.c:773139
void _E95_47()
{
  half_square_length_63 = 24.0 * 0.5;
}

//----- (006F0F30) --------------------------------------------------------  // acclient.c:773145
int _E97_72()
{
  return atexit(_E98_84);
}

//----- (006F0F40) --------------------------------------------------------  // acclient.c:773151
int _E100_65()
{
  return atexit(nullsub_843);
}

//----- (006F0F50) --------------------------------------------------------  // acclient.c:773157
int _E103_57()
{
  return atexit(_E104_72);
}

//----- (006F0F60) --------------------------------------------------------  // acclient.c:773163
void _E109_27()
{
  DEFAULT_VIEW_RADIUS_36 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F0F80) --------------------------------------------------------  // acclient.c:773169
void _E111_16()
{
  MIN_QUANTUM_36 = 1.0 / 30.0;
}

//----- (006F0FA0) --------------------------------------------------------  // acclient.c:773175
void _E113_4()
{
  MAX_QUANTUM_36 = 1.0 / 5.0;
}

//----- (006F0FC0) --------------------------------------------------------  // acclient.c:773181
void _E115_30()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_71, PFID_A8R8G8B8);
}

//----- (006F0FD0) --------------------------------------------------------  // acclient.c:773187
int _E117_26()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_29, "Misc.TooltipEnable");
  return atexit(sub_760EF0);
}

//----- (006F0FF0) --------------------------------------------------------  // acclient.c:773194
int _E120_22()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_29, "Misc.TooltipDelay");
  return atexit(sub_760F20);
}

//----- (006F1010) --------------------------------------------------------  // acclient.c:773201
int sub_6F1010()
{
  return atexit(nullsub_841);
}

//----- (00760EF0) --------------------------------------------------------  // acclient.c:888658
void __cdecl sub_760EF0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760F20) --------------------------------------------------------  // acclient.c:888671
void __cdecl sub_760F20()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

