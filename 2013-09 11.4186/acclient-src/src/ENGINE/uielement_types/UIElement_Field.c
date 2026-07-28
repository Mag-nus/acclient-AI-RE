/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Field
   Object     : ENGINE\uielement_types\UIElement_Field.obj
   Functions  : 14
   Addresses  : 004722B0 - 0075E930 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004722B0) --------------------------------------------------------  // acclient.c:174836
void __userpurge UIElement_Field::UIElement_Field(UIElement_Field *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Field *v4; // esi@1

  v4 = this;
  UIElement::UIElement((UIElement *)&this->vfptr, a2, _layout, _full_desc);
  v4->m_rolloverStateChange = 0;
  v4->m_oldState = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Field::vftable;
}
// 79D368: using guessed type int (__thiscall *UIElement_Field::vftable)(void *, char);

//----- (004722E0) --------------------------------------------------------  // acclient.c:174849
signed int __thiscall UIElement_Field::DynamicCast(UIElement_Field *this, unsigned int i_eType)
{
  return i_eType != 3 ? 0 : (unsigned int)this;
}

//----- (00472300) --------------------------------------------------------  // acclient.c:174855
void __thiscall UIElement_Field::~UIElement_Field(UIElement_Field *this)
{
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Field::vftable;
  UIElement::~UIElement((UIElement *)&this->vfptr);
}
// 79D368: using guessed type int (__thiscall *UIElement_Field::vftable)(void *, char);

//----- (00472310) --------------------------------------------------------  // acclient.c:174863
UIElement *__usercall UIElement_Field::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x5F8u);
  if ( v3 )
  {
    UIElement::UIElement((UIElement *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &UIElement_Field::vftable;
    *((_BYTE *)v3 + 1520) = 0;
    *((_DWORD *)v3 + 381) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79D368: using guessed type int (__thiscall *UIElement_Field::vftable)(void *, char);

//----- (00472360) --------------------------------------------------------  // acclient.c:174886
void __thiscall UIElement_Field::MouseOverTop(UIElement_Field *this, bool _overTop)
{
  bool v2; // bl@1
  UIElement_Field *v3; // esi@1
  UIElement *v4; // edi@5
  signed int v5; // ecx@9
  unsigned int v6; // eax@11
  UIElement_Field *v7; // [sp-2h] [bp-4h]@1

  v7 = this;
  v2 = _overTop;
  v3 = this;
  UIElement::MouseOverTop((UIElement *)&this->vfptr, _overTop);
  if ( v2 )
  {
    if ( UIElementManager::s_pInstance )
    {
      v4 = UIElementManager::s_pInstance->m_dragElement;
      if ( v4 )
      {
        UIElement::GetAttribute_Bool((UIElement *)&v3->vfptr, 0x36u, &_overTop);
        if ( _overTop )
        {
          UIElement::GetAttribute_Bool((UIElement *)&v3->vfptr, 0x70u, (bool *)&v7 + 2);
          if ( BYTE2(v7) )
          {
            UIElement::GetAttribute_Bool((UIElement *)&v3->vfptr, 0x38u, (bool *)&v7 + 3);
            if ( !v3->m_dragDropCallback(v4, (UIElement *)v3) || (v5 = 9, BYTE3(v7)) )
              v5 = 10;
            v6 = v3->m_state;
            if ( v5 != v6 )
            {
              if ( !v3->m_rolloverStateChange )
              {
                v3->m_rolloverStateChange = 1;
                v3->m_oldState = v6;
              }
              v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, v5);
            }
          }
        }
      }
    }
  }
  else if ( v3->m_rolloverStateChange )
  {
    v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, v3->m_oldState);
    v3->m_rolloverStateChange = 0;
  }
}

//----- (00472450) --------------------------------------------------------  // acclient.c:174938
char __thiscall UIElement_Field::CatchDroppedItem(UIElement_Field *this, DragDropInfo *i_pcDDI)
{
  UIElement_Field *v2; // esi@1

  v2 = this;
  if ( this->m_rolloverStateChange )
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(this->m_oldState);
    v2->m_rolloverStateChange = 0;
  }
  return UIElement::CatchDroppedItem((UIElement *)&v2->vfptr, i_pcDDI);
}

//----- (00472490) --------------------------------------------------------  // acclient.c:174952
UIElement_Field *__thiscall UIElement_Field::scalar_deleting_destructor(UIElement_Field *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Field::vftable;
  UIElement::~UIElement((UIElement *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D368: using guessed type int (__thiscall *UIElement_Field::vftable)(void *, char);

//----- (004724C0) --------------------------------------------------------  // acclient.c:174966
void __cdecl UIElement_Field::Register()
{
  UIElement::RegisterElementClass(3u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Field::Create);
}

//----- (004724D0) --------------------------------------------------------  // acclient.c:174972
char __thiscall UIElement_Field::InqAvailableProperties(UIElement_Field *this, AvailablePropertySet *_set)
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
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 9u, v2) )
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

//----- (006EC0D0) --------------------------------------------------------  // acclient.c:767865
int _E73_74()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_13, "Misc.TooltipEnable");
  return atexit(_E74_56);
}

//----- (006EC0F0) --------------------------------------------------------  // acclient.c:767872
int _E76_42()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_13, "Misc.TooltipDelay");
  return atexit(_E77_70);
}

//----- (006EC110) --------------------------------------------------------  // acclient.c:767879
int _E1_69()
{
  return atexit(_E2_69);
}

//----- (0075E900) --------------------------------------------------------  // acclient.c:886826
void __cdecl _E74_56()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E930) --------------------------------------------------------  // acclient.c:886839
void __cdecl _E77_70()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

