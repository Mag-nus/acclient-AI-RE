/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmUIElement_VitaeIndicator
   Object     : GAME\game_ui_misc\gmUIElement_VitaeIndicator.obj
   Functions  : 15
   Addresses  : 004E5E60 - 006F6610 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E5E60) --------------------------------------------------------  // acclient.c:275824
gmUIElement_VitaeIndicator *__thiscall gmUIElement_VitaeIndicator::DynamicCast(gmUIElement_VitaeIndicator *this, unsigned int i_eType)
{
  gmUIElement_VitaeIndicator *result; // eax@1

  result = this;
  if ( i_eType != 268435462 && i_eType != 1 && i_eType != 12 )
    result = (gmUIElement_VitaeIndicator *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004E5EA0) --------------------------------------------------------  // acclient.c:275841
void __thiscall gmUIElement_VitaeIndicator::PostInit(gmUIElement_VitaeIndicator *this)
{
  gmUIElement_VitaeIndicator *v1; // esi@1
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
      (unsigned int)((char *)&loc_4DD213 + 2),
      (NoticeHandler *)&v1->vfptr);
  else
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD213 + 2), 0);
}

//----- (004E5F00) --------------------------------------------------------  // acclient.c:275865
UIElement *__usercall gmUIElement_VitaeIndicator::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x728u);
  if ( v3 )
  {
    UIElement_Button::UIElement_Button((UIElement_Button *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 456) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmUIElement_VitaeIndicator::vftable;
    *((_DWORD *)v3 + 386) = &UIOption_Menu::vftable;
    *((_DWORD *)v3 + 456) = &gmUIElement_VitaeIndicator::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C04C8: using guessed type bool (__thiscall *gmUIElement_VitaeIndicator::vftable)(DBCache *this);
// 7C0770: using guessed type int (__thiscall *gmUIElement_VitaeIndicator::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (004E5F60) --------------------------------------------------------  // acclient.c:275892
UIElement_Button *__thiscall gmUIElement_VitaeIndicator::vector_deleting_destructor(gmUIElement_VitaeIndicator *this, unsigned int a2)
{
  UIElement_Button *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Button *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmUIElement_VitaeIndicator::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmUIElement_VitaeIndicator::vftable;
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
// 7C04C8: using guessed type bool (__thiscall *gmUIElement_VitaeIndicator::vftable)(DBCache *this);
// 7C0770: using guessed type int (__thiscall *gmUIElement_VitaeIndicator::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (004E5FC0) --------------------------------------------------------  // acclient.c:275919
void __cdecl gmUIElement_VitaeIndicator::Register()
{
  UIElement::RegisterElementClass(
    0x10000006u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmUIElement_VitaeIndicator::Create);
}

//----- (004E5FE0) --------------------------------------------------------  // acclient.c:275927
void __thiscall gmUIElement_VitaeIndicator::Update(gmUIElement_VitaeIndicator *this)
{
  gmUIElement_VitaeIndicator *v1; // ebx@1
  InterfaceSystem *v2; // eax@1
  Interface *v3; // esi@1
  int v4; // ebp@3
  PlayerDesc *v5; // esi@5
  PlayerDesc *v6; // ecx@6
  CEnchantmentRegistry *v7; // edi@8
  int v8; // [sp-8h] [bp-7Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-64h]@1
  TResult result; // [sp+14h] [bp-60h]@1
  char v11; // [sp+18h] [bp-5Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+1Ch] [bp-58h]@1
  Enchantment vitae; // [sp+24h] [bp-50h]@8

  v1 = this;
  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_21, &_rpInterface);
  v8 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v11, v8, 0);
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
        v7 = v5->_enchantment_reg;
        Enchantment::Enchantment(&vitae);
        if ( CEnchantmentRegistry::InqVitae(v7, &vitae) )
        {
          if ( vitae._smod.val < 1.0 )
          {
            v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 1u);
            vitae._smod.vfptr = (PackObjVtbl *)&PackObj::vftable;
            vitae.vfptr = (PackObjVtbl *)&PackObj::vftable;
            v5->vfptr->Release((Interface *)v5);
            return;
          }
        }
      }
      v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 13u);
      v6 = v5;
    }
    v5->vfptr->Release((Interface *)v6);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004E60E0) --------------------------------------------------------  // acclient.c:275987
void __thiscall gmUIElement_VitaeIndicator::RecvNotice_PlayerDescReceived(gmUIElement_VitaeIndicator *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  gmUIElement_VitaeIndicator::Update((gmUIElement_VitaeIndicator *)((char *)this - 1824));
}

//----- (004E60F0) --------------------------------------------------------  // acclient.c:275993
void __thiscall gmUIElement_VitaeIndicator::RecvNotice_VitaeChanged(gmUIElement_VitaeIndicator *this)
{
  gmUIElement_VitaeIndicator::Update((gmUIElement_VitaeIndicator *)((char *)this - 1824));
}

//----- (006F6580) --------------------------------------------------------  // acclient.c:779038
void sub_6F6580()
{
  flt_8407BC = 1000.0 + 1.0;
}

//----- (006F65A0) --------------------------------------------------------  // acclient.c:779044
void _E93_92()
{
  flt_8407C0 = 24.0 * 8.0;
}

//----- (006F65C0) --------------------------------------------------------  // acclient.c:779050
void _E95_92()
{
  flt_8407C4 = 24.0 * 0.5;
}

//----- (006F65E0) --------------------------------------------------------  // acclient.c:779056
int sub_6F65E0()
{
  return atexit(nullsub_969);
}

//----- (006F65F0) --------------------------------------------------------  // acclient.c:779062
int sub_6F65F0()
{
  return atexit(nullsub_970);
}

//----- (006F6600) --------------------------------------------------------  // acclient.c:779068
int sub_6F6600()
{
  return atexit(nullsub_971);
}

//----- (006F6610) --------------------------------------------------------  // acclient.c:779074
int sub_6F6610()
{
  return atexit(nullsub_968);
}

