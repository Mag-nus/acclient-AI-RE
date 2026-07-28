/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Dragbar
   Object     : ENGINE\uielement_types\UIElement_Dragbar.obj
   Functions  : 18
   Addresses  : 0046C6F0 - 0075E4E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046C6F0) --------------------------------------------------------  // acclient.c:169059
signed int __thiscall UIElement_Dragbar::DynamicCast(UIElement_Dragbar *this, unsigned int i_eType)
{
  return i_eType != 2 ? 0 : (unsigned int)this;
}

//----- (0046C710) --------------------------------------------------------  // acclient.c:169065
bool __thiscall UIElement_Dragbar::CheckOverOverride(UIElement_Dragbar *this)
{
  return this->m_mousePressed;
}

//----- (0046C720) --------------------------------------------------------  // acclient.c:169071
UIElement *__usercall UIElement_Dragbar::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x5F4u);
  if ( v3 )
  {
    UIElement::UIElement((UIElement *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &UIElement_Dragbar::vftable;
    *((_BYTE *)v3 + 1520) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79CAE8: using guessed type int (__thiscall *UIElement_Dragbar::vftable)(void *, char);

//----- (0046C760) --------------------------------------------------------  // acclient.c:169093
void __thiscall UIElement_Dragbar::StartMouseMoving(UIElement_Dragbar *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Dragbar *v2; // esi@1
  int v3; // eax@2

  v2 = this;
  if ( i_rMsg->dwParam1 == 7 )
  {
    v3 = ((int (*)(void))this->vfptr[13].OnAction)();
    if ( v3 )
    {
      if ( !((*(_DWORD *)(v3 + 1364) >> 19) & 1) && !((*(_DWORD *)(v3 + 1364) >> 18) & 1) )
      {
        v2->m_mousePressed = 1;
        UIElement::StartMovement((UIElement *)v3, i_rMsg->ptWindow.x, i_rMsg->ptWindow.y);
        v2->vfptr[13].__vecDelDtor((IInputActionCallback *)v2, 3u);
      }
    }
  }
}

//----- (0046C7C0) --------------------------------------------------------  // acclient.c:169115
void __thiscall UIElement_Dragbar::StopMouseMoving(UIElement_Dragbar *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Dragbar *v2; // esi@1
  IInputActionCallbackVtbl *v3; // eax@3
  UIElement *v4; // eax@3

  v2 = this;
  if ( this->m_mousePressed && i_rMsg->dwParam1 == 7 )
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(1);
    v3 = v2->vfptr;
    v2->m_mousePressed = 0;
    v4 = (UIElement *)((int (__thiscall *)(UIElement_Dragbar *))v3[13].OnAction)(v2);
    if ( v4 )
      UIElement::StopMovement(v4);
  }
}

//----- (0046C810) --------------------------------------------------------  // acclient.c:169134
UIElement_Dragbar *__thiscall UIElement_Dragbar::scalar_deleting_destructor(UIElement_Dragbar *this, unsigned int a2)
{
  UIElement_Dragbar *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Dragbar::vftable;
  UIElement::~UIElement((UIElement *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79CAE8: using guessed type int (__thiscall *UIElement_Dragbar::vftable)(void *, char);

//----- (0046C840) --------------------------------------------------------  // acclient.c:169148
void __cdecl UIElement_Dragbar::Register()
{
  UIElement::RegisterElementClass(2u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Dragbar::Create);
}

//----- (0046C850) --------------------------------------------------------  // acclient.c:169154
signed int __thiscall UIElement_Dragbar::ListenToElementMessage(UIElement_Dragbar *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Dragbar *v2; // ebx@1
  int v3; // edi@1

  v2 = this;
  v3 = ((int (*)(void))this->vfptr[13].OnAction)();
  if ( v3 && (UIElement_Dragbar *)i_rMsg->pElement == v2 )
  {
    if ( i_rMsg->idMessage == 28 )
    {
      if ( i_rMsg->dwParam1 == 7 && !((*(_DWORD *)(v3 + 1364) >> 19) & 1) && !((*(_DWORD *)(v3 + 1364) >> 18) & 1) )
      {
        UIElement_Dragbar::StartMouseMoving(v2, i_rMsg);
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
        UIElement_Dragbar::StopMouseMoving(v2, i_rMsg);
        return 2;
      }
    }
    else if ( i_rMsg->idMessage == 30 && (*(_DWORD *)(v3 + 1364) >> 18) & 1 && v2->m_mousePressed )
    {
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 76))(v3, i_rMsg->ptWindow.x, i_rMsg->ptWindow.y);
      return 2;
    }
  }
  return 2;
}

//----- (0046C940) --------------------------------------------------------  // acclient.c:169198
char __thiscall UIElement_Dragbar::InqAvailableProperties(UIElement_Dragbar *this, AvailablePropertySet *_set)
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
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 7u, v2) )
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

//----- (006EBD80) --------------------------------------------------------  // acclient.c:767662
int _E73_68()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_11, "Display.Resolution");
  return atexit(_E74_50);
}

//----- (006EBDA0) --------------------------------------------------------  // acclient.c:767669
int _E76_36()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_11, "Display.FullScreen");
  return atexit(_E77_64);
}

//----- (006EBDC0) --------------------------------------------------------  // acclient.c:767676
int _E79_34()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_11, "Display.RefreshRate");
  return atexit(_E80_35);
}

//----- (006EBDE0) --------------------------------------------------------  // acclient.c:767683
int _E82_24()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_11, "Display.SyncToRefresh");
  return atexit(_E83_24);
}

//----- (006EBE00) --------------------------------------------------------  // acclient.c:767690
int _E1_63()
{
  return atexit(_E2_63);
}

//----- (0075E450) --------------------------------------------------------  // acclient.c:886527
void __cdecl _E74_50()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E480) --------------------------------------------------------  // acclient.c:886540
void __cdecl _E77_64()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E4B0) --------------------------------------------------------  // acclient.c:886553
void __cdecl _E80_35()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E4E0) --------------------------------------------------------  // acclient.c:886566
void __cdecl _E83_24()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

