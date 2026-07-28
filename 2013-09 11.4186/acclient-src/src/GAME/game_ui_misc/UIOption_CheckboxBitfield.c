/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption_CheckboxBitfield
   Object     : GAME\game_ui_misc\UIOption_CheckboxBitfield.obj
   Functions  : 17
   Addresses  : 00486340 - 006ED6B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00486340) --------------------------------------------------------  // acclient.c:193864
IInputActionCallbackVtbl **__thiscall UIOption_CheckboxBitfield::DynamicCast(UIOption_CheckboxBitfield *this, unsigned int i_eType)
{
  IInputActionCallbackVtbl **result; // eax@3

  if ( i_eType == 268435523 )
  {
    if ( this )
      result = &this->vfptr;
    else
      result = 0;
  }
  else
  {
    result = (IInputActionCallbackVtbl **)UIOption_Checkbox::DynamicCast((UIOption_Checkbox *)&this->vfptr, i_eType);
  }
  return result;
}

//----- (00486370) --------------------------------------------------------  // acclient.c:193883
signed int __thiscall UIOption_Checkbox::DynamicCast(UIOption_Checkbox *this, unsigned int i_eType)
{
  signed int result; // eax@3

  if ( i_eType == 268435509 )
  {
    if ( this )
      result = (signed int)&this->vfptr;
    else
      result = 0;
  }
  else
  {
    result = (signed int)&this->vfptr;
    if ( i_eType != 1 && i_eType != 12 )
      result = i_eType != 10 ? 0 : result;
  }
  return result;
}

//----- (004863B0) --------------------------------------------------------  // acclient.c:193904
signed int UIOption_CheckboxBitfield::GetUIElementType()
{
  return 268435523;
}

//----- (004863C0) --------------------------------------------------------  // acclient.c:193910
UIElement *__cdecl UIOption_CheckboxBitfield::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v2; // esi@1
  UIElement *result; // eax@2

  v2 = operator new(0x758u);
  if ( v2 )
  {
    UIOption_Checkbox::UIOption_Checkbox((UIOption_Checkbox *)v2, _layout, _full_desc);
    result = (UIElement *)((char *)v2 + 32);
    *(_DWORD *)v2 = &UIOption_CheckboxBitfield::vftable;
    *((_DWORD *)v2 + 394) = &UIOption_Menu::vftable;
    *((_DWORD *)v2 + 468) = 0;
    *((_DWORD *)v2 + 8) = &UIOption_CheckboxBitfield::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A2150: using guessed type void *UIOption_CheckboxBitfield::vftable;
// 7A2290: using guessed type bool (__thiscall *UIOption_CheckboxBitfield::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00486410) --------------------------------------------------------  // acclient.c:193936
UIOption_CheckboxBitfield *__thiscall UIOption_CheckboxBitfield::vector_deleting_destructor(UIOption_CheckboxBitfield *this, unsigned int a2)
{
  return UIOption_CheckboxBitfield::vector_deleting_destructor((UIOption_CheckboxBitfield *)((char *)this - 32), a2);
}

//----- (00486420) --------------------------------------------------------  // acclient.c:193942
IInputActionCallbackVtbl **__thiscall UIOption_CheckboxBitfield::DynamicCast(UIOption_CheckboxBitfield *this, unsigned int a2)
{
  return UIOption_CheckboxBitfield::DynamicCast((UIOption_CheckboxBitfield *)((char *)this - 32), a2);
}

//----- (00486430) --------------------------------------------------------  // acclient.c:193948
UIOption_CheckboxBitfield *__thiscall UIOption_CheckboxBitfield::vector_deleting_destructor(UIOption_CheckboxBitfield *this, unsigned int a2)
{
  UIOption_CheckboxBitfield *v2; // esi@1

  v2 = this;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption_CheckboxBitfield::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIOption_CheckboxBitfield::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  UIOption_Checkbox::~UIOption_Checkbox((UIOption_Checkbox *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A2150: using guessed type void *UIOption_CheckboxBitfield::vftable;
// 7A2290: using guessed type bool (__thiscall *UIOption_CheckboxBitfield::vftable)(DBCache *this);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00486470) --------------------------------------------------------  // acclient.c:193966
void __cdecl UIOption_CheckboxBitfield::Register()
{
  UIElement::RegisterElementClass(0x10000043u, UIOption_CheckboxBitfield::Create);
}

//----- (00486490) --------------------------------------------------------  // acclient.c:193972
char __thiscall UIOption_CheckboxBitfield::Apply(UIOption_CheckboxBitfield *this, int _userRequested)
{
  UIOption_CheckboxBitfield *v2; // edi@1
  unsigned int v3; // eax@1
  int v4; // ebx@1
  InterfaceSystem *v5; // eax@2
  Interface *v6; // esi@2
  PlayerModule *v7; // esi@6
  unsigned int v8; // ST04_4@6
  int v9; // ebx@11
  const unsigned int v10; // ST08_4@13
  BasePropertyDesc *v11; // ecx@16
  unsigned int v12; // esi@16
  BasePropertyValue *v13; // ecx@20
  unsigned int v14; // edx@20
  BasePropertyDesc *v15; // ecx@24
  unsigned int v16; // esi@24
  BasePropertyValue *v17; // ecx@28
  unsigned int v18; // edx@28
  const char *v19; // eax@33
  PStringBase<char> *v20; // edi@33
  bool v21; // bl@33
  Interface *v22; // esi@33
  int v23; // eax@37
  int v25; // [sp-8h] [bp-40h]@2
  int i_bitfield; // [sp+10h] [bp-28h]@1
  Interface *_rpInterface; // [sp+14h] [bp-24h]@2
  TResult result; // [sp+18h] [bp-20h]@1
  char v29; // [sp+1Ch] [bp-1Ch]@4
  BaseProperty prop; // [sp+20h] [bp-18h]@13
  BaseProperty baseProp; // [sp+28h] [bp-10h]@6
  InterfacePtr<CPlayerModule> spPM; // [sp+30h] [bp-8h]@2

  v2 = this;
  v3 = this->m_propName;
  v4 = 0;
  result.m_val = (unsigned int)this;
  i_bitfield = 0;
  if ( v3 )
  {
    _rpInterface = 0;
    v5 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v5, &result, &CPlayerModule_ClassType_1, &_rpInterface);
    v25 = (int)_rpInterface;
    v6 = _rpInterface;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&v29, v25, 0);
    if ( v6 )
      v6->vfptr->Release(v6);
    v7 = (PlayerModule *)&spPM.m_pInterface->vfptr;
    v8 = v2->m_propName;
    baseProp.m_pcPropertyDesc = 0;
    baseProp.m_pcPropertyValue = 0;
    if ( PlayerModule::InqOption((PlayerModule *)&spPM.m_pInterface->vfptr, v8, &baseProp) )
    {
      if ( baseProp.m_pcPropertyValue )
        ((void (__stdcall *)(int *))baseProp.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&i_bitfield);
      v4 = i_bitfield;
    }
    if ( v2->m_current )
      v9 = v2->m_bitmask | v4;
    else
      v9 = ~v2->m_bitmask & v4;
    v10 = v2->m_propName;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&prop, v10);
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      ((void (__stdcall *)(int))prop.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v9);
    }
    PlayerModule::SetOption(v7, &prop);
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v11 = prop.m_pcPropertyDesc;
      v12 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v12;
      if ( !v12 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      prop.m_pcPropertyDesc = 0;
    }
    if ( prop.m_pcPropertyValue )
    {
      v13 = prop.m_pcPropertyValue;
      v14 = prop.m_pcPropertyValue->m_cRef - 1;
      prop.m_pcPropertyValue->m_cRef = v14;
      if ( !v14 )
        ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
      prop.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)baseProp.m_pcPropertyDesc )
    {
      v15 = baseProp.m_pcPropertyDesc;
      v16 = baseProp.m_pcPropertyDesc->m_cRef - 1;
      baseProp.m_pcPropertyDesc->m_cRef = v16;
      if ( !v16 )
        ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
      baseProp.m_pcPropertyDesc = 0;
    }
    if ( baseProp.m_pcPropertyValue )
    {
      v17 = baseProp.m_pcPropertyValue;
      v18 = baseProp.m_pcPropertyValue->m_cRef - 1;
      baseProp.m_pcPropertyValue->m_cRef = v18;
      if ( !v18 )
        ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
      baseProp.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)spPM.m_pInterface )
      ((void (*)(void))spPM.m_pInterface->vfptr->Release)();
LABEL_40:
    v2->vfptr[7].RecvNotice_CreateObject((NoticeHandler *)v2, _userRequested);
    return 1;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_rpInterface, &name);
  v19 = v2->m_prefName.m_charbuffer->m_data;
  v20 = &v2->m_prefName;
  v21 = __stricmp(v19, (const char *)_rpInterface) != 0;
  v22 = _rpInterface - 5;
  if ( !InterlockedDecrement((volatile LONG *)&_rpInterface[-4]) && v22 )
    ((void (__thiscall *)(Interface *, signed int))v22->vfptr->IUnknown_QueryInterface)(v22, 1);
  if ( v21 )
  {
    UIPreferences::InqPreferenceValue(v20, &i_bitfield);
    v23 = *(_DWORD *)(result.m_val + 1872);
    if ( !*(_BYTE *)(result.m_val + 1858) )
      v23 = ~v23;
    UIPreferences::ModifyPreference(v20, i_bitfield & v23);
    v2 = (UIOption_CheckboxBitfield *)result.m_val;
    goto LABEL_40;
  }
  return 0;
}

//----- (00486700) --------------------------------------------------------  // acclient.c:194111
bool __thiscall UIOption_CheckboxBitfield::GetValue(UIOption_CheckboxBitfield *this)
{
  UIOption_CheckboxBitfield *v1; // ebp@1
  unsigned int v2; // eax@1
  InterfaceSystem *v3; // eax@2
  Interface *v4; // esi@2
  CPlayerModule *v5; // esi@6
  unsigned int v6; // ST04_4@6
  char v7; // al@6
  BasePropertyValue *v8; // ecx@6
  BasePropertyDesc *v9; // ecx@11
  unsigned int v10; // edx@11
  int v11; // edx@15
  Interface *v12; // esi@20
  int v14; // [sp-8h] [bp-40h]@2
  bool v15; // [sp+13h] [bp-25h]@20
  int i_bitfield; // [sp+14h] [bp-24h]@1
  unsigned int bitfield; // [sp+18h] [bp-20h]@1
  Interface *_rpInterface; // [sp+1Ch] [bp-1Ch]@2
  TResult result; // [sp+20h] [bp-18h]@2
  char v20; // [sp+24h] [bp-14h]@4
  BaseProperty baseProp; // [sp+28h] [bp-10h]@6
  InterfacePtr<CPlayerModule> spPM; // [sp+30h] [bp-8h]@2

  v1 = this;
  v2 = this->m_propName;
  i_bitfield = 0;
  bitfield = 0;
  if ( v2 )
  {
    _rpInterface = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &CPlayerModule_ClassType_1, &_rpInterface);
    v14 = (int)_rpInterface;
    v4 = _rpInterface;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&v20, v14, 0);
    if ( v4 )
      v4->vfptr->Release(v4);
    v5 = spPM.m_pInterface;
    v6 = v1->m_propName;
    baseProp.m_pcPropertyDesc = 0;
    baseProp.m_pcPropertyValue = 0;
    v7 = PlayerModule::InqOption((PlayerModule *)&spPM.m_pInterface->vfptr, v6, &baseProp);
    v8 = baseProp.m_pcPropertyValue;
    if ( v7 )
    {
      if ( baseProp.m_pcPropertyValue )
      {
        ((void (__stdcall *)(int *))baseProp.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&i_bitfield);
        v8 = baseProp.m_pcPropertyValue;
      }
      bitfield = i_bitfield;
    }
    if ( (_DWORD)baseProp.m_pcPropertyDesc )
    {
      v9 = baseProp.m_pcPropertyDesc;
      v10 = baseProp.m_pcPropertyDesc->m_cRef - 1;
      baseProp.m_pcPropertyDesc->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
      v8 = baseProp.m_pcPropertyValue;
      baseProp.m_pcPropertyDesc = 0;
    }
    if ( v8 )
    {
      v11 = v8->m_cRef - 1;
      v8->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
      baseProp.m_pcPropertyValue = 0;
    }
    if ( v5 )
      v5->vfptr->Release((Interface *)v5);
  }
  else
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_rpInterface, &name);
    v15 = __stricmp(v1->m_prefName.m_charbuffer->m_data, (const char *)_rpInterface) != 0;
    v12 = _rpInterface - 5;
    if ( !InterlockedDecrement((volatile LONG *)&_rpInterface[-4]) && v12 )
      ((void (__thiscall *)(Interface *, signed int))v12->vfptr->IUnknown_QueryInterface)(v12, 1);
    if ( v15 )
    {
      UIPreferences::InqPreferenceValue(&v1->m_prefName, &i_bitfield);
      bitfield = i_bitfield;
    }
  }
  return (bitfield & v1->m_bitmask) == v1->m_bitmask;
}

//----- (006ED620) --------------------------------------------------------  // acclient.c:769255
void _E91_48()
{
  outside_val_40 = 1000.0 + 1.0;
}

//----- (006ED640) --------------------------------------------------------  // acclient.c:769261
void _E93_24()
{
  block_length_40 = 24.0 * 8.0;
}

//----- (006ED660) --------------------------------------------------------  // acclient.c:769267
void _E95_24()
{
  half_square_length_40 = 24.0 * 0.5;
}

//----- (006ED680) --------------------------------------------------------  // acclient.c:769273
int _E97_49()
{
  return atexit(_E98_61);
}

//----- (006ED690) --------------------------------------------------------  // acclient.c:769279
int _E100_42()
{
  return atexit(_E101_79);
}

//----- (006ED6A0) --------------------------------------------------------  // acclient.c:769285
int _E103_34()
{
  return atexit(_E104_49);
}

//----- (006ED6B0) --------------------------------------------------------  // acclient.c:769291
int sub_6ED6B0()
{
  return atexit(nullsub_1005);
}

