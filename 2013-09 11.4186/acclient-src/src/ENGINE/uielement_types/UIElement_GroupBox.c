/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_GroupBox
   Object     : ENGINE\uielement_types\UIElement_GroupBox.obj
   Functions  : 13
   Addresses  : 0046AC00 - 0075E0F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046AC00) --------------------------------------------------------  // acclient.c:167303
signed int __thiscall UIElement_GroupBox::DynamicCast(UIElement_GroupBox *this, unsigned int i_eType)
{
  return i_eType != 17 ? 0 : (unsigned int)this;
}

//----- (0046AC20) --------------------------------------------------------  // acclient.c:167309
UIElement *__usercall UIElement_GroupBox::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x5F4u);
  if ( v3 )
  {
    UIElement::UIElement((UIElement *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &UIElement_GroupBox::vftable;
    *((_DWORD *)v3 + 380) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79C290: using guessed type int (__thiscall *UIElement_GroupBox::vftable)(void *, char);

//----- (0046AC60) --------------------------------------------------------  // acclient.c:167331
void __thiscall UIElement_GroupBox::PostInit(UIElement_GroupBox *this)
{
  UIElement *v1; // esi@1
  unsigned int idSelected; // [sp+0h] [bp-4h]@1

  idSelected = (unsigned int)this;
  v1 = (UIElement *)this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  UIElement::GetAttribute_Enum(v1, 0xB0u, &idSelected);
  if ( idSelected )
    UIElement::SetAttribute_Enum(v1, 0xB1u, idSelected);
}

//----- (0046ACA0) --------------------------------------------------------  // acclient.c:167345
void __thiscall UIElement_GroupBox::OnSetAttribute(UIElement_GroupBox *this, BaseProperty *_attribute)
{
  UIElement_GroupBox *v2; // esi@1
  unsigned int v3; // eax@2
  UIElement *v4; // eax@3
  BasePropertyValue *v5; // ecx@5
  UIElement *v6; // eax@7

  v2 = this;
  if ( BaseProperty::GetPropertyName(_attribute) == (BasePropertyDesc *)177 )
  {
    v3 = v2->m_idSelectedButton;
    if ( v3 )
    {
      v4 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, v3);
      if ( v4 )
        v4->vfptr[13].__vecDelDtor((IInputActionCallback *)v4, 1u);
    }
    v5 = _attribute->m_pcPropertyValue;
    if ( v5 )
      ((void (__stdcall *)(int))v5->vfptr[42].__vecDelDtor)(&v2->m_idSelectedButton);
    v6 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, v2->m_idSelectedButton);
    if ( v6 )
      v6->vfptr[13].__vecDelDtor((IInputActionCallback *)v6, 6u);
  }
  UIElement::OnSetAttribute((UIElement *)&v2->vfptr, (int)_attribute, _attribute);
}

//----- (0046AD20) --------------------------------------------------------  // acclient.c:167374
int __thiscall UIElement_GroupBox::ListenToElementMessage(UIElement_GroupBox *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIElement *v3; // esi@1
  unsigned int idSelected; // [sp+0h] [bp-4h]@1

  idSelected = (unsigned int)this;
  v2 = i_rMsg;
  v3 = (UIElement *)this;
  if ( i_rMsg->idMessage == 1 )
  {
    UIElement::GetAttribute_Enum((UIElement *)&this->vfptr, 0xB1u, &idSelected);
    if ( idSelected == v2->idElement )
    {
      ((void (__stdcall *)(signed int))v2->pElement->vfptr[13].__vecDelDtor)(6);
      UIElement::GetAttribute_Bool(v3, 0xC1u, (bool *)&i_rMsg);
      if ( !(_BYTE)i_rMsg )
        return 2;
    }
    else
    {
      UIElement::SetAttribute_Enum(v3, 0xB1u, v2->idElement);
    }
  }
  return UIElement::ListenToElementMessage(v3, v2);
}

//----- (0046ADA0) --------------------------------------------------------  // acclient.c:167402
UIElement_GroupBox *__thiscall UIElement_GroupBox::vector_deleting_destructor(UIElement_GroupBox *this, unsigned int a2)
{
  UIElement_GroupBox *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_GroupBox::vftable;
  UIElement::~UIElement((UIElement *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79C290: using guessed type int (__thiscall *UIElement_GroupBox::vftable)(void *, char);

//----- (0046ADD0) --------------------------------------------------------  // acclient.c:167416
void __cdecl UIElement_GroupBox::Register()
{
  UIElement::RegisterElementClass(
    0x11u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_GroupBox::Create);
}

//----- (0046ADE0) --------------------------------------------------------  // acclient.c:167424
char __thiscall UIElement_GroupBox::InqAvailableProperties(UIElement_GroupBox *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement::InqAvailableProperties((UIElement *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0xBu, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006EB9E0) --------------------------------------------------------  // acclient.c:767431
int _E73_65()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_6, "Misc.TooltipEnable");
  return atexit(_E74_49);
}

//----- (006EBA00) --------------------------------------------------------  // acclient.c:767438
int _E76_35()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_6, "Misc.TooltipDelay");
  return atexit(_E77_63);
}

//----- (006EBA20) --------------------------------------------------------  // acclient.c:767445
int _E1_57()
{
  return atexit(_E2_57);
}

//----- (0075E0C0) --------------------------------------------------------  // acclient.c:886306
void __cdecl _E74_49()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E0F0) --------------------------------------------------------  // acclient.c:886319
void __cdecl _E77_63()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

