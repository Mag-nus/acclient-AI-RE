/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUIElement_EffectsIndicator
   Object     : GAME\game_ui_misc\gmUIElement_EffectsIndicator.obj
   Functions  : 16
   Addresses  : 004E68A0 - 006F6940 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E68A0) --------------------------------------------------------  // acclient.c:276457
void __userpurge gmUIElement_EffectsIndicator::gmUIElement_EffectsIndicator(gmUIElement_EffectsIndicator *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmUIElement_EffectsIndicator *v4; // esi@1

  v4 = this;
  UIElement_Button::UIElement_Button((UIElement_Button *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_EffectsIndicator::vftable;
  v4->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmUIElement_EffectsIndicator::vftable;
  v4->m_eEffectTypeIndicator = 0;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7C1440: using guessed type bool (__thiscall *gmUIElement_EffectsIndicator::vftable)(DBCache *this);
// 7C16E8: using guessed type int (__thiscall *gmUIElement_EffectsIndicator::vftable)(void *, char);

//----- (004E68F0) --------------------------------------------------------  // acclient.c:276475
gmUIElement_EffectsIndicator *__thiscall gmUIElement_EffectsIndicator::DynamicCast(gmUIElement_EffectsIndicator *this, unsigned int i_eType)
{
  gmUIElement_EffectsIndicator *result; // eax@1

  result = this;
  if ( i_eType != 268435458 && i_eType != 1 && i_eType != 12 )
    result = (gmUIElement_EffectsIndicator *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E6930) --------------------------------------------------------  // acclient.c:276492
void __thiscall gmUIElement_EffectsIndicator::PostInit(gmUIElement_EffectsIndicator *this)
{
  gmUIElement_EffectsIndicator *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@2

  v1 = this;
  UIElement_Button::PostInit((UIElement_Button *)&this->vfptr);
  UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000000Cu, &v1->m_eEffectTypeIndicator);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v3 = (int)&v1->vfptr;
  else
    v3 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v3);
  if ( v1 )
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD200 + 1),
      (NoticeHandler *)&v1->vfptr);
  else
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD200 + 1), 0);
}

//----- (004E69A0) --------------------------------------------------------  // acclient.c:276517
void __usercall gmUIElement_EffectsIndicator::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmUIElement_EffectsIndicator *v3; // eax@1

  v3 = (gmUIElement_EffectsIndicator *)operator new(0x728u);
  if ( v3 )
    gmUIElement_EffectsIndicator::gmUIElement_EffectsIndicator(v3, a1, _layout, _full_desc);
}

//----- (004E69D0) --------------------------------------------------------  // acclient.c:276527
UIElement_Button *__thiscall gmUIElement_EffectsIndicator::vector_deleting_destructor(gmUIElement_EffectsIndicator *this, unsigned int a2)
{
  UIElement_Button *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Button *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_EffectsIndicator::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmUIElement_EffectsIndicator::vftable;
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
// 7C1440: using guessed type bool (__thiscall *gmUIElement_EffectsIndicator::vftable)(DBCache *this);
// 7C16E8: using guessed type int (__thiscall *gmUIElement_EffectsIndicator::vftable)(void *, char);

//----- (004E6A30) --------------------------------------------------------  // acclient.c:276554
void __cdecl gmUIElement_EffectsIndicator::Register()
{
  UIElement::RegisterElementClass(
    0x10000002u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmUIElement_EffectsIndicator::Create);
}

//----- (004E6A50) --------------------------------------------------------  // acclient.c:276562
void __thiscall gmUIElement_EffectsIndicator::Update(gmUIElement_EffectsIndicator *this)
{
  gmUIElement_EffectsIndicator *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // ebp@3
  PlayerDesc *v5; // esi@5
  PlayerDesc *v6; // ecx@6
  unsigned int v7; // eax@8
  CEnchantmentRegistry *v8; // edx@8
  unsigned int v9; // ecx@8
  int v10; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v13; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+1Ch] [bp-8h]@1

  v1 = this;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_22, &_rpInterface);
  v10 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v13, v10, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v5 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    v6 = spPlayerDesc.m_pInterface;
    if ( v4 >= 0 )
    {
      if ( CACQualities::HasEnchantmentRegistry((CACQualities *)&spPlayerDesc.m_pInterface->vfptr) )
      {
        v7 = v1->m_eEffectTypeIndicator;
        v8 = v5->_enchantment_reg;
        v9 = 0;
        if ( v7 == 1 || !v7 )
          v9 = v8->m_cHelpfulEnchantments;
        if ( v7 == 2 || !v7 )
          v9 += v8->m_cHarmfulEnchantments;
        v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, v9 > 0 ? 1 : 13);
      }
      else
      {
        v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 13u);
      }
      v6 = v5;
    }
    v5->vfptr->Release((Interface *)v6);
  }
}

//----- (004E6B20) --------------------------------------------------------  // acclient.c:276620
void __thiscall gmUIElement_EffectsIndicator::RecvNotice_PlayerDescReceived(gmUIElement_EffectsIndicator *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmUIElement_EffectsIndicator::Update((gmUIElement_EffectsIndicator *)((char *)this - 1824));
}

//----- (004E6B30) --------------------------------------------------------  // acclient.c:276626
void __thiscall gmUIElement_EffectsIndicator::RecvNotice_EnchantmentsChanged(gmUIElement_EffectsIndicator *this)
{
  gmUIElement_EffectsIndicator::Update((gmUIElement_EffectsIndicator *)((char *)this - 1824));
}

//----- (006F68B0) --------------------------------------------------------  // acclient.c:779258
void sub_6F68B0()
{
  flt_8408C8 = 1000.0 + 1.0;
}

//----- (006F68D0) --------------------------------------------------------  // acclient.c:779264
void _E93_96()
{
  flt_8408CC = 24.0 * 8.0;
}

//----- (006F68F0) --------------------------------------------------------  // acclient.c:779270
void _E95_96()
{
  flt_8408D0 = 24.0 * 0.5;
}

//----- (006F6910) --------------------------------------------------------  // acclient.c:779276
int sub_6F6910()
{
  return atexit(nullsub_952);
}

//----- (006F6920) --------------------------------------------------------  // acclient.c:779282
int sub_6F6920()
{
  return atexit(nullsub_953);
}

//----- (006F6930) --------------------------------------------------------  // acclient.c:779288
int sub_6F6930()
{
  return atexit(nullsub_954);
}

//----- (006F6940) --------------------------------------------------------  // acclient.c:779294
int sub_6F6940()
{
  return atexit(nullsub_951);
}

