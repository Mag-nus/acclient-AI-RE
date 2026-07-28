/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_ResizeBar
   Object     : ENGINE\uielement_types\UIElement_ResizeBar.obj
   Functions  : 9
   Addresses  : 0046B780 - 006EBC50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046B780) --------------------------------------------------------  // acclient.c:168061
signed int __thiscall UIElement_Resizebar::DynamicCast(UIElement_Resizebar *this, unsigned int i_eType)
{
  return i_eType != 9 ? 0 : (unsigned int)this;
}

//----- (0046B7A0) --------------------------------------------------------  // acclient.c:168067
UIElement *__usercall UIElement_Resizebar::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x5F4u);
  if ( v3 )
  {
    UIElement::UIElement((UIElement *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &UIElement_Resizebar::vftable;
    *((_BYTE *)v3 + 1520) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79C6A8: using guessed type int (__thiscall *UIElement_Resizebar::vftable)(void *, char);

//----- (0046B7E0) --------------------------------------------------------  // acclient.c:168089
void __thiscall UIElement_Resizebar::StartMouseResizing(UIElement_Resizebar *this, tagPOINT *i_ptWindow)
{
  UIElement_Resizebar *v2; // esi@1
  UIElement *v3; // edi@1
  int v4; // eax@3
  UIElement_Resizebar *top; // [sp+0h] [bp-4h]@1

  top = this;
  v2 = this;
  v3 = (UIElement *)((int (*)(void))this->vfptr[13].OnAction)();
  UIElement::GetAttribute_Bool((UIElement *)&v2->vfptr, 0x2Cu, (bool *)&top + 2);
  UIElement::GetAttribute_Bool((UIElement *)&v2->vfptr, 0x2Bu, (bool *)&top + 3);
  UIElement::GetAttribute_Bool((UIElement *)&v2->vfptr, 0x2Du, (bool *)&top);
  UIElement::GetAttribute_Bool((UIElement *)&v2->vfptr, 0x2Au, (bool *)&top + 1);
  if ( BYTE2(top) )
  {
    if ( (_BYTE)top )
      v4 = 3;
    else
      v4 = (BYTE1(top) != 0) + 4;
  }
  else if ( BYTE3(top) )
  {
    if ( (_BYTE)top )
      v4 = 1;
    else
      v4 = 8 - (BYTE1(top) != 0);
  }
  else if ( (_BYTE)top )
  {
    v4 = 2;
  }
  else
  {
    if ( !BYTE1(top) )
      return;
    v4 = 6;
  }
  v2->m_mousePressed = 1;
  UIElement::StartResizing(v3, (BorderLocation)v4, i_ptWindow->x, i_ptWindow->y);
  v2->vfptr[13].__vecDelDtor((IInputActionCallback *)v2, 3u);
}

//----- (0046B8C0) --------------------------------------------------------  // acclient.c:168133
void __thiscall UIElement_Resizebar::StopMouseResizing(UIElement_Resizebar *this)
{
  UIElement_Resizebar *v1; // esi@1
  IInputActionCallbackVtbl *v2; // edx@1
  UIElement *v3; // eax@1

  v1 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(1);
  v2 = v1->vfptr;
  v1->m_mousePressed = 0;
  v3 = (UIElement *)((int (__thiscall *)(UIElement_Resizebar *))v2[13].OnAction)(v1);
  if ( v3 )
    UIElement::StopResizing(v3);
}

//----- (0046B8F0) --------------------------------------------------------  // acclient.c:168149
UIElement_Resizebar *__thiscall UIElement_Resizebar::vector_deleting_destructor(UIElement_Resizebar *this, unsigned int a2)
{
  UIElement_Resizebar *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Resizebar::vftable;
  UIElement::~UIElement((UIElement *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79C6A8: using guessed type int (__thiscall *UIElement_Resizebar::vftable)(void *, char);

//----- (0046B920) --------------------------------------------------------  // acclient.c:168163
void __cdecl UIElement_Resizebar::Register()
{
  UIElement::RegisterElementClass(9u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Resizebar::Create);
}

//----- (0046B930) --------------------------------------------------------  // acclient.c:168169
signed int __thiscall UIElement_Resizebar::ListenToElementMessage(UIElement_Resizebar *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Resizebar *v2; // ebx@1
  int v3; // edi@1

  v2 = this;
  v3 = ((int (*)(void))this->vfptr[13].OnAction)();
  if ( v3 && (UIElement_Resizebar *)i_rMsg->pElement == v2 )
  {
    if ( i_rMsg->idMessage == 28 )
    {
      if ( i_rMsg->dwParam1 == 7 && !((*(_DWORD *)(v3 + 1364) >> 19) & 1) && !((*(_DWORD *)(v3 + 1364) >> 18) & 1) )
      {
        UIElement_Resizebar::StartMouseResizing(v2, &i_rMsg->ptWindow);
        (*(void (__thiscall **)(int, int, int, unsigned int))(*(_DWORD *)v3 + 96))(
          v3,
          i_rMsg->ptWindow.x,
          i_rMsg->ptWindow.y,
          i_rMsg->dwParam1);
      }
    }
    else if ( i_rMsg->idMessage == 29 )
    {
      if ( i_rMsg->dwParam1 == 7 && v2->m_mousePressed )
      {
        (*(void (__thiscall **)(int, int, int, signed int))(*(_DWORD *)v3 + 100))(
          v3,
          i_rMsg->ptWindow.x,
          i_rMsg->ptWindow.y,
          7);
        UIElement_Resizebar::StopMouseResizing(v2);
        return 2;
      }
    }
    else if ( i_rMsg->idMessage == 30 && (*(_DWORD *)(v3 + 1364) >> 19) & 1 && v2->m_mousePressed )
    {
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 76))(v3, i_rMsg->ptWindow.x, i_rMsg->ptWindow.y);
      return 2;
    }
  }
  return 2;
}

//----- (0046BA20) --------------------------------------------------------  // acclient.c:168213
char __thiscall UIElement_Resizebar::InqAvailableProperties(UIElement_Resizebar *this, AvailablePropertySet *_set)
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
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0x10u, v2) )
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

//----- (006EBC50) --------------------------------------------------------  // acclient.c:767580
int _E1_60()
{
  return atexit(_E2_60);
}

