/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUIElement_BurdenIndicator
   Object     : GAME\game_ui_misc\gmUIElement_BurdenIndicator.obj
   Functions  : 16
   Addresses  : 004E6B40 - 006F69E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E6B40) --------------------------------------------------------  // acclient.c:276632
gmUIElement_BurdenIndicator *__thiscall gmUIElement_BurdenIndicator::DynamicCast(gmUIElement_BurdenIndicator *this, unsigned int i_eType)
{
  gmUIElement_BurdenIndicator *result; // eax@1

  result = this;
  if ( i_eType != 268435457 && i_eType != 1 && i_eType != 12 )
    result = (gmUIElement_BurdenIndicator *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E6B70) --------------------------------------------------------  // acclient.c:276643
signed int gmEffectsUI::GetUIElementType()
{
  return 268435483;
}

//----- (004E6B80) --------------------------------------------------------  // acclient.c:276649
void __thiscall gmUIElement_BurdenIndicator::PostInit(gmUIElement_BurdenIndicator *this)
{
  gmUIElement_BurdenIndicator *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@2

  v1 = this;
  UIElement_Button::PostInit((UIElement_Button *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v3 = (int)&v1->vfptr;
  else
    v3 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v3);
  if ( v1 )
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD21E + 2),
      (NoticeHandler *)&v1->vfptr);
  else
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD21E + 2), 0);
}

//----- (004E6BE0) --------------------------------------------------------  // acclient.c:276673
UIElement *__usercall gmUIElement_BurdenIndicator::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x728u);
  if ( v3 )
  {
    UIElement_Button::UIElement_Button((UIElement_Button *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 456) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmUIElement_BurdenIndicator::vftable;
    *((_DWORD *)v3 + 386) = &UIOption_Menu::vftable;
    *((_DWORD *)v3 + 456) = &gmUIElement_BurdenIndicator::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7C18A0: using guessed type bool (__thiscall *gmUIElement_BurdenIndicator::vftable)(DBCache *this);
// 7C1B48: using guessed type int (__thiscall *gmUIElement_BurdenIndicator::vftable)(void *, char);

//----- (004E6C60) --------------------------------------------------------  // acclient.c:276700
UIElement_Button *__thiscall gmUIElement_BurdenIndicator::vector_deleting_destructor(gmUIElement_BurdenIndicator *this, unsigned int a2)
{
  UIElement_Button *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Button *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_BurdenIndicator::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmUIElement_BurdenIndicator::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Button::~UIElement_Button(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7C18A0: using guessed type bool (__thiscall *gmUIElement_BurdenIndicator::vftable)(DBCache *this);
// 7C1B48: using guessed type int (__thiscall *gmUIElement_BurdenIndicator::vftable)(void *, char);

//----- (004E6CC0) --------------------------------------------------------  // acclient.c:276727
void __cdecl gmUIElement_BurdenIndicator::Register()
{
  UIElement::RegisterElementClass(
    0x10000001u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmUIElement_BurdenIndicator::Create);
}

//----- (004E6CE0) --------------------------------------------------------  // acclient.c:276735
void __thiscall gmUIElement_BurdenIndicator::Update(gmUIElement_BurdenIndicator *this)
{
  gmUIElement_BurdenIndicator *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // ebp@3
  PlayerDesc *v5; // esi@5
  int v6; // [sp-8h] [bp-30h]@1
  Interface *_rpInterface; // [sp+10h] [bp-18h]@1
  float fCurLoad; // [sp+14h] [bp-14h]@8
  TResult result; // [sp+18h] [bp-10h]@1
  char v10; // [sp+1Ch] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+20h] [bp-8h]@1

  v1 = this;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_23, &_rpInterface);
  v6 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v10, v6, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    if ( v4 < 0 )
    {
      spPlayerDesc.m_pInterface->vfptr->Release((Interface *)spPlayerDesc.m_pInterface);
      return;
    }
    if ( CACQualities::InqLoad((CACQualities *)&spPlayerDesc.m_pInterface->vfptr, &fCurLoad) )
    {
      if ( fCurLoad < 1.0 )
      {
        v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 14u);
        v5->vfptr->Release((Interface *)v5);
        return;
      }
      if ( fCurLoad >= 2.0 )
      {
        v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 16u);
        v5->vfptr->Release((Interface *)v5);
        return;
      }
      v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 15u);
    }
    else
    {
      v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 14u);
    }
    v5->vfptr->Release((Interface *)v5);
  }
}

//----- (004E6DF0) --------------------------------------------------------  // acclient.c:276795
void __thiscall gmUIElement_BurdenIndicator::RecvNotice_LoadChanged(gmUIElement_BurdenIndicator *this, float fNewLoad)
{
  gmUIElement_BurdenIndicator::Update((gmUIElement_BurdenIndicator *)((char *)this - 1824));
}

//----- (004E6E00) --------------------------------------------------------  // acclient.c:276801
void __thiscall gmUIElement_BurdenIndicator::RecvNotice_PlayerDescReceived(gmUIElement_BurdenIndicator *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmUIElement_BurdenIndicator::Update((gmUIElement_BurdenIndicator *)((char *)this - 1824));
}

//----- (006F6950) --------------------------------------------------------  // acclient.c:779300
void sub_6F6950()
{
  flt_8408F4 = 1000.0 + 1.0;
}

//----- (006F6970) --------------------------------------------------------  // acclient.c:779306
void _E93_97()
{
  flt_8408F8 = 24.0 * 8.0;
}

//----- (006F6990) --------------------------------------------------------  // acclient.c:779312
void _E95_97()
{
  flt_8408FC = 24.0 * 0.5;
}

//----- (006F69B0) --------------------------------------------------------  // acclient.c:779318
int sub_6F69B0()
{
  return atexit(nullsub_948);
}

//----- (006F69C0) --------------------------------------------------------  // acclient.c:779324
int sub_6F69C0()
{
  return atexit(nullsub_949);
}

//----- (006F69D0) --------------------------------------------------------  // acclient.c:779330
int sub_6F69D0()
{
  return atexit(nullsub_950);
}

//----- (006F69E0) --------------------------------------------------------  // acclient.c:779336
int sub_6F69E0()
{
  return atexit(nullsub_947);
}

