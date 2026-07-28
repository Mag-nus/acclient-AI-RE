/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement
   Object     : ENGINE\uielement_system\UIElement.obj
   Functions  : 181
   Addresses  : 0045F860 - 0075DB30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0045F860) --------------------------------------------------------  // acclient.c:156237
void __thiscall Box2D::Box2D(Box2D *this, int _x, int _y, int _width, int _height)
{
  this->m_x0 = _x;
  this->m_x1 = _x + _width - 1;
  this->m_y0 = _y;
  this->m_y1 = _y + _height - 1;
}

//----- (0045F890) --------------------------------------------------------  // acclient.c:156246
void __thiscall UIRegion::MouseOver(UIRegion *this, bool _over)
{
  *((_DWORD *)this + 41) ^= ((unsigned __int8)*((_DWORD *)this + 41) ^ (unsigned __int8)(16 * _over)) & 0x10;
}

//----- (0045F8B0) --------------------------------------------------------  // acclient.c:156252
void __thiscall UIRegion::MouseOverTop(UIRegion *this, bool _overTop)
{
  *((_DWORD *)this + 41) ^= ((unsigned __int8)*((_DWORD *)this + 41) ^ _overTop) & 1;
}

//----- (0045F8D0) --------------------------------------------------------  // acclient.c:156258
void __thiscall UIRegion::SetTooltipOn(UIRegion *this, bool _on)
{
  *((_DWORD *)this + 41) ^= ((unsigned __int8)*((_DWORD *)this + 41) ^ (unsigned __int8)(32 * _on)) & 0x20;
}

//----- (0045F8F0) --------------------------------------------------------  // acclient.c:156264
void __thiscall UIElement::SetDragable(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int8)this->m_nFlags ^ (unsigned __int8)(2 * _b)) & 2;
}

//----- (0045F910) --------------------------------------------------------  // acclient.c:156270
void __thiscall UIElement::SetActivateOnShow(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int8)this->m_nFlags ^ (unsigned __int8)(8 * _b)) & 8;
}

//----- (0045F930) --------------------------------------------------------  // acclient.c:156276
void __thiscall UIElement::SetSaveLocation(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int8)this->m_nFlags ^ (unsigned __int8)(16 * _b)) & 0x10;
}

//----- (0045F950) --------------------------------------------------------  // acclient.c:156282
void __thiscall UIElement::SetSaveSize(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int8)this->m_nFlags ^ (unsigned __int8)(32 * _b)) & 0x20;
}

//----- (0045F970) --------------------------------------------------------  // acclient.c:156288
void __thiscall UIElement::SetNotifyOnResize(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int16)this->m_nFlags ^ (unsigned __int16)(_b << 9)) & 0x200;
}

//----- (0045F990) --------------------------------------------------------  // acclient.c:156294
void __thiscall UIElement::SetNotifyOnMove(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int16)this->m_nFlags ^ (unsigned __int16)(_b << 10)) & 0x400;
}

//----- (0045F9B0) --------------------------------------------------------  // acclient.c:156300
void __thiscall UIElement::SetContextMenu(UIElement *this, bool _b)
{
  this->m_nFlags ^= (unsigned __int8)((this->m_nFlags ^ (_b << 7)) & 0x80);
}

//----- (0045F9D0) --------------------------------------------------------  // acclient.c:156306
void __thiscall UIElement::SetNotifyOnCreate(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int16)this->m_nFlags ^ (unsigned __int16)(_b << 12)) & 0x1000;
}

//----- (0045F9F0) --------------------------------------------------------  // acclient.c:156312
BOOL __thiscall Vector3::operator!=(Vector3 *this, Vector3 *_rhs)
{
  return fabs(this->x - _rhs->x) > 0.00019999999
      || fabs(this->y - _rhs->y) > 0.00019999999
      || fabs(this->z - _rhs->z) > 0.00019999999;
}

//----- (0045FA50) --------------------------------------------------------  // acclient.c:156320
UIElement *__thiscall UIElement::GetRootElement(UIElement *this)
{
  UIElement *v1; // esi@1
  int v2; // eax@1
  UIElement *result; // eax@4

  v1 = this;
  v2 = ((int (*)(void))this->vfptr[13].OnAction)();
  if ( (v1->m_nFlags >> 21) & 1 )
  {
LABEL_4:
    result = v1;
  }
  else
  {
    while ( v2 )
    {
      v1 = (UIElement *)v2;
      v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 160))(v2);
      if ( (v1->m_nFlags >> 21) & 1 )
        goto LABEL_4;
    }
    result = 0;
  }
  return result;
}

//----- (0045FAA0) --------------------------------------------------------  // acclient.c:156348
int __thiscall UIElement::GetAncestorByID(UIElement *this, const unsigned int i_ID)
{
  int result; // eax@1

  for ( result = ((int (*)(void))this->vfptr[13].OnAction)();
        result;
        result = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)result + 160))(result) )
  {
    if ( *(_DWORD *)(result + 740) == i_ID )
      break;
  }
  return result;
}

//----- (0045FAD0) --------------------------------------------------------  // acclient.c:156363
bool __thiscall UIElement::IsAncestorOfMe(UIElement *this, UIElement *i_pAncestor)
{
  int v2; // eax@1
  bool v3; // zf@1

  v2 = ((int (*)(void))this->vfptr[13].OnAction)();
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( (UIElement *)v2 == i_pAncestor )
        break;
      v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 160))(v2);
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (0045FB00) --------------------------------------------------------  // acclient.c:156385
bool __thiscall UIElement::RegisterInputMaps(UIElement *this, int i_nPriority)
{
  UIElement *v2; // esi@1
  bool result; // al@2
  int v4; // eax@4
  unsigned int v5; // eax@5

  v2 = this;
  if ( ICIDM::s_cidm )
  {
    if ( ((int (*)(void))this->vfptr[13].OnAction)() )
    {
      v4 = ((int (__thiscall *)(UIElement *))v2->vfptr[13].OnAction)(v2);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 176))(v4, i_nPriority - 1);
    }
    v5 = v2->m_idInputMap;
    if ( v5 )
      result = ((int (__stdcall *)(unsigned int, UIElement *, int))ICIDM::s_cidm->vfptr->RegisterInputMap)(
                 v5,
                 v2,
                 i_nPriority);
    else
      result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045FB70) --------------------------------------------------------  // acclient.c:156417
bool __thiscall UIElement::UnregisterInputMaps(UIElement *this)
{
  UIElement *v1; // esi@1
  int v2; // eax@3
  unsigned int v3; // eax@4
  bool result; // al@5

  v1 = this;
  if ( !ICIDM::s_cidm )
    goto LABEL_9;
  if ( ((int (*)(void))this->vfptr[13].OnAction)() )
  {
    v2 = ((int (__thiscall *)(UIElement *))v1->vfptr[13].OnAction)(v1);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 180))(v2);
  }
  v3 = v1->m_idInputMap;
  if ( v3 )
    result = ((int (__stdcall *)(unsigned int, UIElement *))ICIDM::s_cidm->vfptr->UnregisterInputMap)(v3, v1);
  else
LABEL_9:
    result = 0;
  return result;
}

//----- (0045FBC0) --------------------------------------------------------  // acclient.c:156442
bool __thiscall UIElement::OnAction(UIElement *this, InputEvent *i_evt)
{
  UIElement *v2; // esi@1
  int v3; // eax@2
  bool result; // al@2

  v2 = this;
  if ( ((int (*)(void))this->vfptr[13].OnAction)() )
  {
    v3 = ((int (__thiscall *)(UIElement *))v2->vfptr[13].OnAction)(v2);
    result = (*(int (__thiscall **)(int, UIElement *, InputEvent *))(*(_DWORD *)v3 + 184))(v3, v2, i_evt);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045FC00) --------------------------------------------------------  // acclient.c:156462
bool __thiscall UIElement::OnChildAction(UIElement *this, UIElement *i_pChild, InputEvent *i_evt)
{
  UIElement *v3; // esi@1
  int v4; // eax@2
  bool result; // al@2

  v3 = this;
  if ( ((int (*)(void))this->vfptr[13].OnAction)() )
  {
    v4 = ((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3);
    result = (*(int (__thiscall **)(int, UIElement *, InputEvent *))(*(_DWORD *)v4 + 184))(v4, i_pChild, i_evt);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045FC30) --------------------------------------------------------  // acclient.c:156482
char __stdcall UIElement::DefElementMessageHandler(UIElementMessageInfo *i_rMsg)
{
  char result; // al@2

  if ( UIElementManager::s_pInstance )
    result = UIElementManager::BroadcastElementMessage(
               UIElementManager::s_pInstance,
               i_rMsg->idElement,
               i_rMsg->pElement,
               i_rMsg->idMessage,
               i_rMsg->dwParam1);
  else
    result = 0;
  return result;
}

//----- (0045FC60) --------------------------------------------------------  // acclient.c:156499
int __thiscall UIElement::CompareZLevel(UIElement *this, UIRegion *i_pRegion)
{
  UIElement *v2; // esi@1
  int result; // eax@1
  unsigned int v4; // eax@2
  IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>Vtbl *v5; // ecx@2

  v2 = this;
  result = UIRegion::CompareZLevel((UIRegion *)&this->vfptr, i_pRegion);
  if ( !result )
  {
    v4 = v2->m_desc.m_uiReadOrder;
    v5 = i_pRegion[2].m_children.m_ihlIntrusive.m_hash.vfptr;
    if ( v4 >= (unsigned int)v5 )
      result = (v4 == (_DWORD)v5) - 1;
    else
      result = 1;
  }
  return result;
}

//----- (0045FCA0) --------------------------------------------------------  // acclient.c:156521
void __thiscall UIElement::StartResizing(UIElement *this, BorderLocation _border, int _xInitialMouse, int _yInitialMouse)
{
  UIElement *v4; // esi@1
  int v5; // eax@3
  int v6; // eax@3
  int v7; // ecx@3
  int v8; // edx@3
  int v9; // edx@4
  char v10; // cl@4
  IInputActionCallbackVtbl *v11; // eax@6

  v4 = this;
  if ( !((this->m_nFlags >> 19) & 1) && !((this->m_nFlags >> 18) & 1) )
  {
    v5 = this->m_box.m_y0;
    this->m_DragStartX = this->m_box.m_x0;
    this->m_DragStartY = v5;
    this->m_DragStartHeight = UIRegion::GetHeight((UIRegion *)&this->vfptr);
    v6 = UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    v7 = _xInitialMouse;
    v8 = _yInitialMouse;
    v4->m_DragStartWidth = v6;
    v4->m_mouseInitialX = v7;
    v4->m_mouseInitialY = v8;
    if ( _border )
    {
      v9 = v4->m_nFlags | 0x80000;
      v10 = LOBYTE(v4->m_nFlags);
      v4->m_currentBorder = _border;
      v4->m_nFlags = v9;
      if ( v10 & 1 )
      {
        if ( ((unsigned int)v9 >> 16) & 1 )
        {
          v11 = v4->vfptr;
          _xInitialMouse = 0;
          ((void (__thiscall *)(UIElement *, int *))v11[23].OnLoseFocus)(v4, &_xInitialMouse);
          v4->vfptr[23].OnAction((IInputActionCallback *)v4, (InputEvent *)_xInitialMouse);
        }
      }
    }
  }
}

//----- (0045FD60) --------------------------------------------------------  // acclient.c:156566
void __thiscall UIElement::StopResizing(UIElement *this)
{
  UIElement *v1; // esi@1
  unsigned int v2; // edx@1
  char v3; // cl@1
  IInputActionCallbackVtbl *v4; // eax@3
  UIObject *pcNewObject; // [sp+4h] [bp-4h]@1

  pcNewObject = (UIObject *)this;
  v1 = this;
  v2 = this->m_nFlags & 0xFFF7FFFF;
  v3 = LOBYTE(this->m_nFlags);
  v1->m_nFlags = v2;
  if ( v3 & 1 )
  {
    if ( (v2 >> 16) & 1 )
    {
      v4 = v1->vfptr;
      pcNewObject = 0;
      ((void (__thiscall *)(UIElement *, UIObject **))v4[23].OnLoseFocus)(v1, &pcNewObject);
      v1->vfptr[23].OnAction((IInputActionCallback *)v1, (InputEvent *)pcNewObject);
    }
  }
}

//----- (0045FDB0) --------------------------------------------------------  // acclient.c:156592
void __thiscall UIElement::StartMovement(UIElement *this, int _xInitialMouse, int _yInitialMouse)
{
  UIElement *v3; // esi@1
  int v4; // ecx@3
  int v5; // edx@3

  v3 = this;
  if ( !((this->m_nFlags >> 19) & 1) && !((this->m_nFlags >> 18) & 1) )
  {
    v4 = this->m_box.m_x0;
    v3->m_mouseInitialX = _xInitialMouse;
    v5 = v3->m_box.m_y0;
    v3->m_DragStartX = v4;
    v3->m_mouseInitialY = _yInitialMouse;
    v3->m_DragStartY = v5;
    v3->m_DragStartHeight = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
    v3->m_DragStartWidth = UIRegion::GetWidth((UIRegion *)&v3->vfptr);
    v3->m_nFlags |= 0x40000u;
  }
}

//----- (0045FE20) --------------------------------------------------------  // acclient.c:156614
void __thiscall UIElement::StopMovement(UIElement *this)
{
  this->m_nFlags &= 0xFFFBFFFF;
}

//----- (0045FE30) --------------------------------------------------------  // acclient.c:156620
void __thiscall UIElement::MouseMoveElement(UIElement *this, int _xWindow, int _yWindow)
{
  UIRegion *v3; // esi@1
  char v4; // al@2
  signed int v5; // ebx@4
  signed int v6; // edi@4
  UIRegion *v7; // eax@7
  int v8; // ebp@7
  UIRegion *v9; // eax@12
  int v10; // ebp@12
  UIRegion *v11; // eax@13
  int v12; // ebx@13
  UIRegion *v13; // eax@16
  int v14; // ebp@16
  UIRegion *v15; // eax@17
  int v16; // edi@17

  v3 = (UIRegion *)this;
  if ( ICIDM::s_cidm )
    v4 = ((int (*)(void))ICIDM::s_cidm->vfptr->ShiftKeyDown)();
  else
    v4 = 0;
  v5 = _xWindow
     + (char *)v3[2].m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[4]
     - (char *)v3[2].m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[8];
  v6 = _yWindow
     + (char *)v3[2].m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[5]
     - (char *)v3[2].m_mouseDownTable.m_intrusiveTable.m_aInplaceBuckets[9];
  if ( v4 )
  {
    if ( v5 % 10 )
      v5 -= v5 % 10;
    v7 = (UIRegion *)((int (__thiscall *)(UIRegion *))v3->vfptr[13].OnAction)(v3);
    v8 = UIRegion::GetHeight(v7);
    if ( v6 < v8 - UIRegion::GetHeight(v3) && v6 % 10 )
      v6 -= v6 % 10;
  }
  if ( v5 < 0 )
    v5 = 0;
  v9 = (UIRegion *)((int (__thiscall *)(UIRegion *))v3->vfptr[13].OnAction)(v3);
  v10 = UIRegion::GetWidth(v9);
  if ( v5 > v10 - UIRegion::GetWidth(v3) )
  {
    v11 = (UIRegion *)((int (__thiscall *)(UIRegion *))v3->vfptr[13].OnAction)(v3);
    v12 = UIRegion::GetWidth(v11);
    v5 = v12 - UIRegion::GetWidth(v3);
  }
  if ( v6 < 0 )
    v6 = 0;
  v13 = (UIRegion *)((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3);
  v14 = UIRegion::GetHeight(v13);
  if ( v6 > v14 - UIRegion::GetHeight(v3) )
  {
    v15 = (UIRegion *)((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3);
    v16 = UIRegion::GetHeight(v15);
    v6 = v16 - UIRegion::GetHeight(v3);
  }
  ((void (__thiscall *)(UIRegion *, signed int, signed int))v3->vfptr[3].OnLoseFocus)(v3, v5, v6);
}

//----- (0045FF50) --------------------------------------------------------  // acclient.c:156681
void __thiscall UIElement::SetCursor(UIElement *this, IDClass<_tagDataID,32,0> _cursorDID, int _hotX, int _hotY)
{
  this->m_cursorDID.id = _cursorDID.id;
  this->m_cursorHotX = _hotX;
  this->m_cursorHotY = _hotY;
  UIElementManager::CheckCursor(UIElementManager::s_pInstance);
}

//----- (0045FF80) --------------------------------------------------------  // acclient.c:156690
void __thiscall UIElement::UnSetCursor(UIElement *this)
{
  this->m_cursorDID.id = INVALID_DID_53.id;
  this->m_cursorHotX = 0;
  this->m_cursorHotY = 0;
  UIElementManager::CheckCursor(UIElementManager::s_pInstance);
}

//----- (0045FFB0) --------------------------------------------------------  // acclient.c:156699
char __thiscall UIElement::InqImageSize(UIElement *this, int *width, int *height)
{
  Graphic *v3; // esi@1
  char result; // al@2

  v3 = this->m_image;
  if ( v3 )
  {
    *width = Graphic::GetWidth(this->m_image);
    *height = Graphic::GetHeight(v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045FFF0) --------------------------------------------------------  // acclient.c:156719
void __thiscall UIElement::CenterAt(UIElement *this, const int _x, const int _y)
{
  UIRegion *v3; // esi@1
  IInputActionCallbackVtbl *v4; // edi@1
  int v5; // ST04_4@1
  signed int v6; // eax@1

  v3 = (UIRegion *)this;
  v4 = this->vfptr;
  v5 = _y - UIRegion::GetHeight((UIRegion *)&this->vfptr) / 2;
  v6 = UIRegion::GetWidth(v3);
  ((void (__thiscall *)(UIRegion *, int, int))v4[3].OnLoseFocus)(v3, _x - v6 / 2, v5);
}

//----- (00460030) --------------------------------------------------------  // acclient.c:156734
void __thiscall UIElement::GetOriginalPosition(UIElement *this, Box2D *_position, int *_zlevel)
{
  int v3; // edx@1
  int v4; // esi@1
  int v5; // ebx@1
  int v6; // [sp+10h] [bp+0h]@1

  v3 = this->m_desc.m_y;
  v4 = this->m_desc.m_x;
  v5 = this->m_desc.m_height + v3 - 1;
  if ( (int *)_position == &v6 )
  {
    *_zlevel = this->m_desc.m_zLevel;
  }
  else
  {
    _position->m_x1 = this->m_desc.m_width + v4 - 1;
    _position->m_x0 = v4;
    _position->m_y0 = v3;
    _position->m_y1 = v5;
    *_zlevel = this->m_desc.m_zLevel;
  }
}

//----- (004600A0) --------------------------------------------------------  // acclient.c:156759
void __thiscall UIElement::GetCurrentPosition(UIElement *this, Box2D *_position, int *_zlevel)
{
  if ( _position == &this->m_box )
  {
    *_zlevel = this->m_zlevel;
  }
  else
  {
    _position->m_x0 = this->m_box.m_x0;
    _position->m_x1 = this->m_box.m_x1;
    _position->m_y0 = this->m_box.m_y0;
    _position->m_y1 = this->m_box.m_y1;
    *_zlevel = this->m_zlevel;
  }
}

//----- (004600F0) --------------------------------------------------------  // acclient.c:156776
unsigned int __thiscall UIElement::GetShouldOwnObject(UIElement *this)
{
  return (this->m_nFlags >> 14) & 1;
}

//----- (00460100) --------------------------------------------------------  // acclient.c:156782
void __thiscall UIElement::SetIsRootElement(UIElement *this, bool _b)
{
  UIElement *v2; // esi@1
  IInputActionCallbackVtbl *v3; // edx@1
  UIElement *v4; // edi@1

  v2 = this;
  v3 = this->vfptr;
  this->m_nFlags ^= (this->m_nFlags ^ (_b << 21)) & 0x200000;
  v4 = UIElementManager::s_pInstance->m_pRootElement;
  if ( ((int (*)(void))v3[13].OnAction)() == (_DWORD)v4 )
  {
    if ( !_b )
      ((void (__thiscall *)(UIElement *, _DWORD))v2->vfptr[5].OnLoseFocus)(v2, 0);
  }
  else if ( _b )
  {
    ((void (__thiscall *)(_DWORD, UIElement *))v2->vfptr[5].OnLoseFocus)(v2, v4);
  }
}

//----- (00460170) --------------------------------------------------------  // acclient.c:156804
void __thiscall UIElement::AddToDeleteQueue(UIElement *this)
{
  if ( UIElementManager::s_pInstance )
    UIElementManager::AddElementToDeleteQueue(UIElementManager::s_pInstance, this);
}

//----- (00460190) --------------------------------------------------------  // acclient.c:156811
void __cdecl UIElement::RegisterElementClass(unsigned int _type, UIElement *(__cdecl *_createMethod)(LayoutDesc *, ElementDesc *))
{
  if ( UIElementManager::s_pInstance )
    UIElementManager::RegisterElementClass(UIElementManager::s_pInstance, _type, _createMethod);
}

//----- (004601B0) --------------------------------------------------------  // acclient.c:156818
BOOL __thiscall UIElement::GetShouldBeMouseVisible(UIElement *this)
{
  return (this->m_nFlags >> 7) & 1 || StringInfo::IsValid(&this->m_TTText, 1);
}

//----- (004601E0) --------------------------------------------------------  // acclient.c:156824
char __thiscall UIElement::TakeFocus(UIElement *this)
{
  UIElement *v1; // esi@1
  UIElement *v2; // eax@1
  UIElement *v3; // edi@1
  unsigned int v4; // ecx@2
  char result; // al@2

  v1 = this;
  v2 = UIElement::GetRootElement(this);
  v3 = v2;
  if ( v2 )
  {
    v1->m_nFlags |= 0x400000u;
    v4 = v2->m_nFlags >> 20;
    result = 0;
    if ( v4 & 1 )
    {
      UIElementManager::SetFocusElement(UIElementManager::s_pInstance, v1);
      result = 1;
    }
    v3->m_pFocusElement = v1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00460230) --------------------------------------------------------  // acclient.c:156855
bool __thiscall UIElement::GetHasFocus(UIElement *this)
{
  bool result; // al@2

  if ( UIElementManager::s_pInstance )
    result = UIElementManager::s_pInstance->m_focusElement == this;
  else
    result = 0;
  return result;
}

//----- (00460250) --------------------------------------------------------  // acclient.c:156867
UIElement *__thiscall UIElement::GetFocusDescendant(UIElement *this)
{
  return this->m_pFocusElement;
}

//----- (00460260) --------------------------------------------------------  // acclient.c:156873
void __thiscall UIElement::UpdateMouseVisibility(UIElement *this)
{
  UIElement *v1; // esi@1

  v1 = this;
  v1->m_bIsMouseVisible = this->m_bShouldBeMouseVisible || (unsigned __int8)((int (*)(void))this->vfptr[24].OnAction)();
}

//----- (00460290) --------------------------------------------------------  // acclient.c:156882
void __thiscall UIElement::SetClampGameViewEdge(UIElement *this, unsigned int i_eEdge)
{
  UIObject *v2; // edx@2

  if ( i_eEdge )
  {
    v2 = this->m_object;
    this->m_eClampGameView = i_eEdge;
    if ( v2 || this->m_parent )
      UIRegion::SetClampGameViewEdge((UIRegion *)&this->vfptr, i_eEdge);
  }
}

//----- (004602C0) --------------------------------------------------------  // acclient.c:156896
char __thiscall UIElement::IsVisible(UIElement *this)
{
  UIElement *v1; // esi@1
  char result; // al@2
  UIElement *v3; // edi@3
  int v4; // eax@5
  char v5; // bl@5

  v1 = this;
  if ( UIElementManager::s_pInstance )
  {
    v3 = UIElementManager::s_pInstance->m_pRootElement;
    if ( v3 )
    {
      v4 = ((int (*)(void))this->vfptr[13].OnAction)();
      v5 = (*((_DWORD *)&v1->0 + 41) >> 1) & 1;
      if ( !v5 )
        goto LABEL_8;
      while ( v4 )
      {
        v5 = (*(_DWORD *)(v4 + 164) >> 1) & 1;
        v1 = (UIElement *)v4;
        v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 160))(v4);
        if ( !v5 )
          goto LABEL_8;
      }
      if ( v5 && v1 == v3 )
        result = 1;
      else
LABEL_8:
        result = 0;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00460330) --------------------------------------------------------  // acclient.c:156941
char __thiscall UIElement::BroadcastElementMessage(UIElement *this, unsigned int i_idMessage, unsigned int i_dwParam1, unsigned int i_dwParam2)
{
  char result; // al@1
  UIElementMessageInfo msg; // [sp+0h] [bp-28h]@1

  msg.idElement = this->m_desc.m_elementID;
  msg.pElement = this;
  msg.idMessage = i_idMessage;
  msg.dwParam2 = i_dwParam2;
  result = 0;
  msg.dwParam1 = i_dwParam1;
  msg.tsSerialNumber.m_timestamp = 0;
  msg.ptWindow.x = 0;
  msg.ptWindow.y = 0;
  msg.ptElement.x = 0;
  msg.ptElement.y = 0;
  if ( UIElementManager::s_pInstance )
    result = UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
  return result;
}

//----- (00460390) --------------------------------------------------------  // acclient.c:156963
bool __thiscall UIElement::SetAttribute_Enum(UIElement *this, unsigned int _attribute, unsigned int _val)
{
  UIElement *v3; // esi@1
  BasePropertyDesc *v4; // ecx@7
  unsigned int v5; // edx@7
  BasePropertyValue *v6; // ecx@11
  unsigned int v7; // edx@11
  bool retval; // [sp+11h] [bp-9h]@1
  BaseProperty prop; // [sp+12h] [bp-8h]@1

  v3 = this;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, _attribute) )
  {
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      if ( (unsigned __int8)((int (__stdcall *)(unsigned int))prop.m_pcPropertyValue->vfptr[43].__vecDelDtor)(_val) )
      {
        if ( (unsigned __int8)((int (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[17].OnLoseFocus)(v3, &prop) )
          retval = 1;
      }
    }
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v4 = prop.m_pcPropertyDesc;
    v5 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v6 = prop.m_pcPropertyValue;
    v7 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460450) --------------------------------------------------------  // acclient.c:157010
bool __thiscall UIElement::SetAttribute_InstanceID(UIElement *this, unsigned int _attribute, unsigned int _val)
{
  UIElement *v3; // esi@1
  BasePropertyDesc *v4; // ecx@7
  unsigned int v5; // edx@7
  BasePropertyValue *v6; // ecx@11
  unsigned int v7; // edx@11
  bool retval; // [sp+11h] [bp-9h]@1
  BaseProperty prop; // [sp+12h] [bp-8h]@1

  v3 = this;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, _attribute) )
  {
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      if ( (unsigned __int8)((int (__stdcall *)(unsigned int))prop.m_pcPropertyValue->vfptr[51].__vecDelDtor)(_val) )
      {
        if ( (unsigned __int8)((int (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[17].OnLoseFocus)(v3, &prop) )
          retval = 1;
      }
    }
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v4 = prop.m_pcPropertyDesc;
    v5 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v6 = prop.m_pcPropertyValue;
    v7 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460510) --------------------------------------------------------  // acclient.c:157057
bool __thiscall UIElement::SetAttribute_StringInfo(UIElement *this, unsigned int _attribute, StringInfo _val)
{
  UIElement *v3; // esi@1
  BasePropertyDesc *v4; // ecx@7
  unsigned int v5; // esi@7
  BasePropertyValue *v6; // ecx@11
  unsigned int v7; // edx@11
  bool retval; // [sp+11h] [bp-9h]@1
  BaseProperty prop; // [sp+12h] [bp-8h]@1

  v3 = this;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, _attribute) )
  {
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      if ( (unsigned __int8)((int (__stdcall *)(StringInfo *))prop.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&_val) )
      {
        if ( (unsigned __int8)((int (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[17].OnLoseFocus)(v3, &prop) )
          retval = 1;
      }
    }
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v4 = prop.m_pcPropertyDesc;
    v5 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v6 = prop.m_pcPropertyValue;
    v7 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyValue = 0;
  }
  StringInfo::~StringInfo(&_val);
  return retval;
}

//----- (004605D0) --------------------------------------------------------  // acclient.c:157106
bool __thiscall UIElement::SetAttribute_Int(UIElement *this, unsigned int _attribute, int _val)
{
  UIElement *v3; // esi@1
  BasePropertyDesc *v4; // ecx@7
  unsigned int v5; // edx@7
  BasePropertyValue *v6; // ecx@11
  unsigned int v7; // edx@11
  bool retval; // [sp+11h] [bp-9h]@1
  BaseProperty prop; // [sp+12h] [bp-8h]@1

  v3 = this;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, _attribute) )
  {
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      if ( (unsigned __int8)((int (__stdcall *)(int))prop.m_pcPropertyValue->vfptr[31].__vecDelDtor)(_val) )
      {
        if ( (unsigned __int8)((int (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[17].OnLoseFocus)(v3, &prop) )
          retval = 1;
      }
    }
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v4 = prop.m_pcPropertyDesc;
    v5 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v6 = prop.m_pcPropertyValue;
    v7 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460680) --------------------------------------------------------  // acclient.c:157153
bool __thiscall UIElement::SetAttribute_Float(UIElement *this, unsigned int _attribute, float _val)
{
  UIElement *v3; // esi@1
  BasePropertyDesc *v4; // ecx@7
  unsigned int v5; // edx@7
  BasePropertyValue *v6; // ecx@11
  unsigned int v7; // edx@11
  bool retval; // [sp+11h] [bp-9h]@1
  BaseProperty prop; // [sp+12h] [bp-8h]@1

  v3 = this;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, _attribute) )
  {
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      if ( (unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[35].__vecDelDtor)(LODWORD(_val)) )
      {
        if ( (unsigned __int8)((int (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[17].OnLoseFocus)(v3, &prop) )
          retval = 1;
      }
    }
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v4 = prop.m_pcPropertyDesc;
    v5 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v6 = prop.m_pcPropertyValue;
    v7 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460740) --------------------------------------------------------  // acclient.c:157200
bool __thiscall UIElement::SetAttribute_Bool(UIElement *this, unsigned int _attribute, int _val)
{
  UIElement *v3; // esi@1
  BasePropertyDesc *v4; // ecx@7
  unsigned int v5; // edx@7
  BasePropertyValue *v6; // ecx@11
  unsigned int v7; // edx@11
  bool retval; // [sp+11h] [bp-9h]@1
  BaseProperty prop; // [sp+12h] [bp-8h]@1

  v3 = this;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, _attribute) )
  {
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      if ( (unsigned __int8)((int (__stdcall *)(int))prop.m_pcPropertyValue->vfptr[29].__vecDelDtor)(_val) )
      {
        if ( (unsigned __int8)((int (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[17].OnLoseFocus)(v3, &prop) )
          retval = 1;
      }
    }
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v4 = prop.m_pcPropertyDesc;
    v5 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v6 = prop.m_pcPropertyValue;
    v7 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (004607F0) --------------------------------------------------------  // acclient.c:157247
bool __thiscall UIElement::SetAttribute_DataID(UIElement *this, unsigned int _attribute, IDClass<_tagDataID,32,0> _val)
{
  UIElement *v3; // esi@1
  BasePropertyDesc *v4; // ecx@7
  unsigned int v5; // edx@7
  BasePropertyValue *v6; // ecx@11
  unsigned int v7; // edx@11
  bool retval; // [sp+11h] [bp-9h]@1
  BaseProperty prop; // [sp+12h] [bp-8h]@1

  v3 = this;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, _attribute) )
  {
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      if ( (unsigned __int8)((int (__stdcall *)(unsigned int))prop.m_pcPropertyValue->vfptr[45].__vecDelDtor)(_val.id) )
      {
        if ( (unsigned __int8)((int (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[17].OnLoseFocus)(v3, &prop) )
          retval = 1;
      }
    }
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v4 = prop.m_pcPropertyDesc;
    v5 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v6 = prop.m_pcPropertyValue;
    v7 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (004608B0) --------------------------------------------------------  // acclient.c:157294
bool __thiscall UIElement::GetAttribute_Enum(UIElement *this, unsigned int _attribute, unsigned int *_val)
{
  IInputActionCallbackVtbl *v3; // eax@1
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  int v7; // edx@11
  bool retval; // [sp+15h] [bp-9h]@1
  BaseProperty prop; // [sp+16h] [bp-8h]@1

  v3 = this->vfptr;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v3[17].OnAction)(_attribute, &prop) )
  {
    v4 = prop.m_pcPropertyValue;
    if ( !prop.m_pcPropertyValue )
      goto LABEL_6;
    if ( (unsigned __int8)((int (__stdcall *)(unsigned int *))prop.m_pcPropertyValue->vfptr[42].__vecDelDtor)(_val) )
      retval = 1;
    goto LABEL_5;
  }
  if ( !BaseProperty::SetPropertyName(&prop, _attribute) )
    goto LABEL_17;
  v4 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(unsigned int *))prop.m_pcPropertyValue->vfptr[42].__vecDelDtor)(_val) )
    {
LABEL_5:
      v4 = prop.m_pcPropertyValue;
      goto LABEL_6;
    }
LABEL_17:
    v4 = prop.m_pcPropertyValue;
  }
  *_val = 0;
LABEL_6:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v5 = prop.m_pcPropertyDesc;
    v6 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    v4 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v4 )
  {
    v7 = v4->m_cRef - 1;
    v4->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460980) --------------------------------------------------------  // acclient.c:157354
bool __thiscall UIElement::GetAttribute_InstanceID(UIElement *this, unsigned int _attribute, unsigned int *_val)
{
  IInputActionCallbackVtbl *v3; // eax@1
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  int v7; // edx@11
  bool retval; // [sp+15h] [bp-9h]@1
  BaseProperty prop; // [sp+16h] [bp-8h]@1

  v3 = this->vfptr;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v3[17].OnAction)(_attribute, &prop) )
  {
    v4 = prop.m_pcPropertyValue;
    if ( !prop.m_pcPropertyValue )
      goto LABEL_6;
    if ( (unsigned __int8)((int (__stdcall *)(unsigned int *))prop.m_pcPropertyValue->vfptr[50].__vecDelDtor)(_val) )
      retval = 1;
    goto LABEL_5;
  }
  if ( !BaseProperty::SetPropertyName(&prop, _attribute) )
    goto LABEL_17;
  v4 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(unsigned int *))prop.m_pcPropertyValue->vfptr[50].__vecDelDtor)(_val) )
    {
LABEL_5:
      v4 = prop.m_pcPropertyValue;
      goto LABEL_6;
    }
LABEL_17:
    v4 = prop.m_pcPropertyValue;
  }
  *_val = 0;
LABEL_6:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v5 = prop.m_pcPropertyDesc;
    v6 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    v4 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v4 )
  {
    v7 = v4->m_cRef - 1;
    v4->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460A50) --------------------------------------------------------  // acclient.c:157414
bool __thiscall UIElement::GetAttribute_Int(UIElement *this, unsigned int _attribute, int *_val)
{
  IInputActionCallbackVtbl *v3; // eax@1
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  int v7; // edx@11
  bool retval; // [sp+15h] [bp-9h]@1
  BaseProperty prop; // [sp+16h] [bp-8h]@1

  v3 = this->vfptr;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v3[17].OnAction)(_attribute, &prop) )
  {
    v4 = prop.m_pcPropertyValue;
    if ( !prop.m_pcPropertyValue )
      goto LABEL_6;
    if ( (unsigned __int8)((int (__stdcall *)(int *))prop.m_pcPropertyValue->vfptr[30].__vecDelDtor)(_val) )
      retval = 1;
    goto LABEL_5;
  }
  if ( !BaseProperty::SetPropertyName(&prop, _attribute) )
    goto LABEL_17;
  v4 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(int *))prop.m_pcPropertyValue->vfptr[30].__vecDelDtor)(_val) )
    {
LABEL_5:
      v4 = prop.m_pcPropertyValue;
      goto LABEL_6;
    }
LABEL_17:
    v4 = prop.m_pcPropertyValue;
  }
  *_val = 0;
LABEL_6:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v5 = prop.m_pcPropertyDesc;
    v6 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    v4 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v4 )
  {
    v7 = v4->m_cRef - 1;
    v4->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460B10) --------------------------------------------------------  // acclient.c:157474
bool __thiscall UIElement::GetAttribute_Float(UIElement *this, unsigned int _attribute, float *_val)
{
  IInputActionCallbackVtbl *v3; // eax@1
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  int v7; // edx@11
  bool retval; // [sp+15h] [bp-9h]@1
  BaseProperty prop; // [sp+16h] [bp-8h]@1

  v3 = this->vfptr;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v3[17].OnAction)(_attribute, &prop) )
  {
    v4 = prop.m_pcPropertyValue;
    if ( !prop.m_pcPropertyValue )
      goto LABEL_6;
    if ( (unsigned __int8)((int (__stdcall *)(float *))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(_val) )
      retval = 1;
    goto LABEL_5;
  }
  if ( !BaseProperty::SetPropertyName(&prop, _attribute) )
    goto LABEL_17;
  v4 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(float *))prop.m_pcPropertyValue->vfptr[34].__vecDelDtor)(_val) )
    {
LABEL_5:
      v4 = prop.m_pcPropertyValue;
      goto LABEL_6;
    }
LABEL_17:
    v4 = prop.m_pcPropertyValue;
  }
  *(_DWORD *)_val = 0;
LABEL_6:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v5 = prop.m_pcPropertyDesc;
    v6 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    v4 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v4 )
  {
    v7 = v4->m_cRef - 1;
    v4->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460BE0) --------------------------------------------------------  // acclient.c:157534
bool __thiscall UIElement::GetAttribute_Bool(UIElement *this, unsigned int _attribute, bool *_val)
{
  IInputActionCallbackVtbl *v3; // eax@1
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  int v7; // edx@11
  bool retval; // [sp+15h] [bp-9h]@1
  BaseProperty prop; // [sp+16h] [bp-8h]@1

  v3 = this->vfptr;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v3[17].OnAction)(_attribute, &prop) )
  {
    v4 = prop.m_pcPropertyValue;
    if ( !prop.m_pcPropertyValue )
      goto LABEL_6;
    if ( (unsigned __int8)((int (__stdcall *)(bool *))prop.m_pcPropertyValue->vfptr[28].__vecDelDtor)(_val) )
      retval = 1;
    goto LABEL_5;
  }
  if ( !BaseProperty::SetPropertyName(&prop, _attribute) )
    goto LABEL_17;
  v4 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(bool *))prop.m_pcPropertyValue->vfptr[28].__vecDelDtor)(_val) )
    {
LABEL_5:
      v4 = prop.m_pcPropertyValue;
      goto LABEL_6;
    }
LABEL_17:
    v4 = prop.m_pcPropertyValue;
  }
  *_val = 0;
LABEL_6:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v5 = prop.m_pcPropertyDesc;
    v6 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    v4 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v4 )
  {
    v7 = v4->m_cRef - 1;
    v4->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460CA0) --------------------------------------------------------  // acclient.c:157594
bool __thiscall UIElement::GetAttribute_DataID(UIElement *this, unsigned int _attribute, IDClass<_tagDataID,32,0> *_val)
{
  IInputActionCallbackVtbl *v3; // eax@1
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  int v7; // edx@11
  bool retval; // [sp+15h] [bp-9h]@1
  BaseProperty prop; // [sp+16h] [bp-8h]@1

  v3 = this->vfptr;
  retval = 0;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v3[17].OnAction)(_attribute, &prop) )
  {
    v4 = prop.m_pcPropertyValue;
    if ( !prop.m_pcPropertyValue )
      goto LABEL_6;
    if ( (unsigned __int8)((int (__stdcall *)(IDClass<_tagDataID,32,0> *))prop.m_pcPropertyValue->vfptr[44].__vecDelDtor)(_val) )
      retval = 1;
    goto LABEL_5;
  }
  if ( !BaseProperty::SetPropertyName(&prop, _attribute) )
    goto LABEL_17;
  v4 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(IDClass<_tagDataID,32,0> *))prop.m_pcPropertyValue->vfptr[44].__vecDelDtor)(_val) )
    {
LABEL_5:
      v4 = prop.m_pcPropertyValue;
      goto LABEL_6;
    }
LABEL_17:
    v4 = prop.m_pcPropertyValue;
  }
  _val->id = INVALID_DID_53.id;
LABEL_6:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v5 = prop.m_pcPropertyDesc;
    v6 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    v4 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v4 )
  {
    v7 = v4->m_cRef - 1;
    v4->m_cRef = v7;
    if ( !v7 )
      ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  }
  return retval;
}

//----- (00460D70) --------------------------------------------------------  // acclient.c:157654
int __thiscall UIElement::StartTooltipAtMouse(UIElement *this, long double i_tTooltipDuration)
{
  int v2; // ebx@1
  UIElement *v3; // esi@1
  IInputActionCallbackVtbl *v4; // eax@4
  char v5; // al@4
  BasePropertyValue *v6; // ecx@4
  BasePropertyDesc *v7; // ecx@8
  unsigned int v8; // edi@8
  bool v9; // zf@12
  unsigned int v10; // eax@16
  LayoutDesc *v11; // ecx@17
  int v13; // esi@22
  float i_secCustomDuration; // ST14_4@24
  BaseProperty prop; // [sp+20h] [bp-A0h]@4
  IDClass<_tagDataID,32,0> layoutID; // [sp+28h] [bp-98h]@16
  unsigned int tooltipID; // [sp+2Ch] [bp-94h]@15
  StringInfo info; // [sp+30h] [bp-90h]@2

  v2 = (int)UIElementManager::s_pInstance;
  v3 = this;
  if ( !UIElementManager::s_pInstance )
    return 0;
  StringInfo::StringInfo(&info);
  if ( StringInfo::IsValid(&v3->m_TTText, 1) )
  {
    StringInfo::operator=(&info, (int)&v3->m_TTText);
  }
  else
  {
    v4 = v3->vfptr;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    v5 = ((int (__thiscall *)(UIElement *, signed int, BaseProperty *))v4[17].OnAction)(v3, 73, &prop);
    v6 = prop.m_pcPropertyValue;
    if ( v5 && prop.m_pcPropertyValue )
    {
      ((void (__stdcall *)(StringInfo *))prop.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&info);
      v6 = prop.m_pcPropertyValue;
    }
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v7 = prop.m_pcPropertyDesc;
      v8 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
      v6 = prop.m_pcPropertyValue;
      prop.m_pcPropertyDesc = 0;
    }
    if ( v6 )
    {
      v9 = v6->m_cRef-- == 1;
      if ( v9 )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
    }
  }
  if ( !StringInfo::IsValid(&info, 1) || !UIElement::GetAttribute_Enum(v3, 0x47u, &tooltipID) )
    goto LABEL_28;
  layoutID.id = INVALID_DID_53.id;
  UIElement::GetAttribute_DataID(v3, 0x48u, &layoutID);
  v10 = layoutID.id;
  if ( layoutID.id == INVALID_DID_53.id )
  {
    v11 = v3->m_layout;
    if ( v11 )
    {
      v10 = v11->m_DID.id;
      layoutID.id = v11->m_DID.id;
    }
    if ( v10 == INVALID_DID_53.id )
    {
LABEL_28:
      StringInfo::~StringInfo(&info);
      return 0;
    }
  }
  UIElementManager::StartTooltip((UIElementManager *)v2, v2, &info, v3, tooltipID, (IDClass<_tagDataID,32,0>)v10, 0);
  v13 = *(_DWORD *)(v2 + 760);
  if ( v13 )
  {
    if ( i_tTooltipDuration != 0.0 )
    {
      i_secCustomDuration = i_tTooltipDuration;
      UIElementManager::SetDurationForCurrentTooltip((UIElementManager *)v2, i_secCustomDuration);
    }
  }
  StringInfo::~StringInfo(&info);
  return v13;
}

//----- (00460F10) --------------------------------------------------------  // acclient.c:157746
void __thiscall UIElement::MouseDown(UIElement *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  int v4; // ebx@1
  UIElement *v5; // esi@1
  int v6; // edi@1
  UIElementManager *v7; // ecx@1
  UIElementMessageInfo msg; // [sp+10h] [bp-28h]@1
  unsigned int _yWindowa; // [sp+40h] [bp+8h]@1

  v4 = _yWindow;
  v5 = this;
  UIRegion::MouseDown((UIRegion *)&this->vfptr, _xWindow, _yWindow, _button);
  _yWindowa = v5->m_desc.m_elementID;
  v6 = v4 - UIRegion::GetScreenY0((UIRegion *)&v5->vfptr);
  msg.dwParam1 = _button;
  msg.ptElement.x = _xWindow - UIRegion::GetScreenX0((UIRegion *)&v5->vfptr);
  v7 = UIElementManager::s_pInstance;
  msg.idElement = _yWindowa;
  msg.pElement = v5;
  msg.idMessage = 28;
  msg.dwParam2 = 0;
  msg.tsSerialNumber.m_timestamp = 0;
  msg.ptWindow.x = _xWindow;
  msg.ptWindow.y = v4;
  msg.ptElement.y = v6;
  if ( UIElementManager::s_pInstance )
  {
    UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
    v7 = UIElementManager::s_pInstance;
  }
  if ( (v5->m_nFlags >> 7) & 1 && _button == 8 )
  {
    msg.idMessage = 39;
    if ( v7 )
      UIElementManager::BroadcastElementMessage(v7, &msg);
  }
}

//----- (00460FE0) --------------------------------------------------------  // acclient.c:157785
void __thiscall UIElement::MouseTap(UIElement *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  UIElement *v4; // esi@1
  unsigned int v5; // ebx@1
  UIElementMessageInfo msg; // [sp+10h] [bp-28h]@1

  v4 = this;
  v5 = this->m_desc.m_elementID;
  msg.ptElement.y = _yWindow - UIRegion::GetScreenY0((UIRegion *)&this->vfptr);
  msg.pElement = v4;
  msg.dwParam1 = _button;
  msg.ptElement.x = _xWindow - UIRegion::GetScreenX0((UIRegion *)&v4->vfptr);
  msg.ptWindow.y = _yWindow;
  msg.idElement = v5;
  msg.idMessage = 64;
  msg.dwParam2 = 0;
  msg.tsSerialNumber.m_timestamp = 0;
  msg.ptWindow.x = _xWindow;
  if ( UIElementManager::s_pInstance )
    UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
}

//----- (00461060) --------------------------------------------------------  // acclient.c:157808
char __thiscall UIElement::KeyUp(UIElement *this, unsigned int _button)
{
  unsigned int v2; // eax@1
  char result; // al@1
  UIElementMessageInfo msg; // [sp+0h] [bp-28h]@1

  v2 = this->m_desc.m_elementID;
  msg.pElement = this;
  msg.idElement = v2;
  result = 0;
  msg.dwParam1 = _button;
  msg.idMessage = 66;
  msg.dwParam2 = 0;
  msg.tsSerialNumber.m_timestamp = 0;
  msg.ptWindow.x = 0;
  msg.ptWindow.y = 0;
  msg.ptElement.x = 0;
  msg.ptElement.y = 0;
  if ( UIElementManager::s_pInstance )
    result = UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
  return result;
}

//----- (004610C0) --------------------------------------------------------  // acclient.c:157832
char __thiscall UIElement::KeyDown(UIElement *this, unsigned int _button, float i_fExtent)
{
  unsigned int v3; // eax@1
  char result; // al@1
  UIElementMessageInfo msg; // [sp+0h] [bp-28h]@1

  v3 = this->m_desc.m_elementID;
  msg.pElement = this;
  msg.idElement = v3;
  msg.idMessage = 65;
  msg.dwParam1 = _button;
  msg.dwParam2 = (unsigned __int64)(i_fExtent * 1000.0);
  result = 0;
  msg.tsSerialNumber.m_timestamp = 0;
  msg.ptWindow.x = 0;
  msg.ptWindow.y = 0;
  msg.ptElement.x = 0;
  msg.ptElement.y = 0;
  if ( UIElementManager::s_pInstance )
    result = UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
  return result;
}

//----- (00461130) --------------------------------------------------------  // acclient.c:157856
void __userpurge UIElement::MouseResizeElement(UIElement *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, int _xWindow, int _yWindow)
{
  UIElement *v6; // ebx@1
  int v7; // edx@5
  signed int v8; // ebp@5
  int v9; // esi@5
  int v10; // edi@5
  signed int v11; // esi@5
  bool v12; // dl@5
  bool v13; // zf@28
  UIRegion *v14; // eax@45
  int v15; // eax@45
  UIRegion *v16; // eax@46
  UIRegion *v17; // eax@47
  UIRegion *v18; // eax@48
  int v19; // [sp-Ch] [bp-30h]@5
  int v20; // [sp-8h] [bp-2Ch]@5
  int v21; // [sp-4h] [bp-28h]@5
  bool has_max_width; // [sp+5h] [bp-1Fh]@5
  char shiftdown; // [sp+7h] [bp-1Dh]@3
  int newRight; // [sp+8h] [bp-1Ch]@5
  int min_width; // [sp+Ch] [bp-18h]@5
  int iDeltaY; // [sp+10h] [bp-14h]@5
  int min_height; // [sp+14h] [bp-10h]@5
  int max_height; // [sp+18h] [bp-Ch]@5
  int iDeltaX; // [sp+1Ch] [bp-8h]@5
  int max_width; // [sp+20h] [bp-4h]@5
  bool _xWindowa; // [sp+28h] [bp+4h]@5
  bool has_min_height; // [sp+2Ch] [bp+8h]@5

  v6 = this;
  if ( this->m_currentBorder )
  {
    if ( ICIDM::s_cidm )
      shiftdown = ((int (*)(void))ICIDM::s_cidm->vfptr->ShiftKeyDown)();
    else
      shiftdown = 0;
    v7 = v6->m_mouseInitialY;
    v21 = a2;
    v8 = v6->m_DragStartX;
    v20 = a4;
    v9 = v6->m_DragStartHeight;
    iDeltaX = _xWindow - v6->m_mouseInitialX;
    v19 = a3;
    v10 = v6->m_DragStartY;
    iDeltaY = _yWindow - v7;
    newRight = v8 + v6->m_DragStartWidth;
    v11 = v10 + v9;
    has_min_height = UIElement::GetAttribute_Int(v6, 0x3Fu, &min_width);
    has_max_width = UIElement::GetAttribute_Int(v6, 0x3Du, &max_width);
    _xWindowa = UIElement::GetAttribute_Int(v6, 0x3Eu, &min_height);
    v12 = UIElement::GetAttribute_Int(v6, 0x3Cu, &max_height);
    switch ( v6->m_currentBorder )
    {
      case 1:
        v8 += iDeltaX;
        if ( has_min_height && newRight - v8 < min_width )
          v8 = newRight - min_width;
        if ( has_max_width && newRight - v8 > max_width )
          v8 = newRight - max_width;
        break;
      case 8:
        v8 += iDeltaX;
        if ( has_min_height && newRight - v8 < min_width )
          v8 = newRight - min_width;
        if ( has_max_width && newRight - v8 > max_width )
          v8 = newRight - max_width;
        break;
      case 7:
        v11 = v6->m_DragStartHeight + v10 + iDeltaY;
        v8 += iDeltaX;
        if ( has_min_height && newRight - v8 < min_width )
          v8 = newRight - min_width;
        if ( has_max_width && newRight - v8 > max_width )
          v8 = newRight - max_width;
        if ( _xWindowa && v11 - v10 < min_height )
          v11 = min_height + v10;
        v13 = v12 == 0;
        goto LABEL_35;
      case 6:
        v11 = v6->m_DragStartHeight + v10 + iDeltaY;
        goto LABEL_31;
      case 5:
        v11 = v6->m_DragStartHeight + v10 + iDeltaY;
LABEL_31:
        if ( _xWindowa && v11 - v10 < min_height )
          v11 = min_height + v10;
        v13 = v12 == 0;
LABEL_35:
        if ( !v13 && v11 - v10 > max_height )
          v11 = max_height + v10;
        break;
      case 3:
      case 2:
        break;
    }
    if ( shiftdown )
    {
      if ( v8 % 10 )
        v8 -= v8 % 10;
      if ( v11 % 10 )
        v11 -= v11 % 10;
    }
    if ( v8 < 0 )
      v8 = 0;
    v14 = (UIRegion *)((int (__thiscall *)(UIElement *, int, int, int))v6->vfptr[13].OnAction)(v6, v19, v20, v21);
    v15 = UIRegion::GetWidth(v14);
    if ( min_height > v15 )
    {
      v16 = (UIRegion *)((int (__thiscall *)(UIElement *))v6->vfptr[13].OnAction)(v6);
      min_height = UIRegion::GetWidth(v16);
    }
    v17 = (UIRegion *)((int (__thiscall *)(UIElement *))v6->vfptr[13].OnAction)(v6);
    if ( v11 > UIRegion::GetHeight(v17) )
    {
      v18 = (UIRegion *)((int (__thiscall *)(UIElement *))v6->vfptr[13].OnAction)(v6);
      UIRegion::GetHeight(v18);
    }
    v6->vfptr[4].__vecDelDtor((IInputActionCallback *)v6, min_height - v8);
    ((void (__thiscall *)(UIElement *))v6->vfptr[3].OnLoseFocus)(v6);
  }
}
// 461130: could not find valid save-restore pair for ebp
// 461130: could not find valid save-restore pair for edi
// 461130: could not find valid save-restore pair for esi

//----- (004615A0) --------------------------------------------------------  // acclient.c:157983
void __thiscall UIElement::MouseOver(UIElement *this, bool _over)
{
  *((_DWORD *)&this->0 + 41) ^= ((unsigned __int8)*((_DWORD *)&this->0 + 41) ^ (unsigned __int8)(16 * _over)) & 0x10;
  UIElement::BroadcastElementMessage(this, 0x1Fu, _over, 0);
}

//----- (004615D0) --------------------------------------------------------  // acclient.c:157990
void __thiscall UIElement::MouseOverTop(UIElement *this, bool _overTop)
{
  *((_DWORD *)&this->0 + 41) ^= (_overTop ^ (unsigned __int8)*((_DWORD *)&this->0 + 41)) & 1;
  UIElement::BroadcastElementMessage(this, 0x1Bu, _overTop, 0);
}

//----- (00461600) --------------------------------------------------------  // acclient.c:157997
char __thiscall UIElement::DragItem(UIElement *this, UIElement **_elem)
{
  UIElement *v3; // eax@3
  UIElementManager *v4; // edi@4
  LayoutDesc *v5; // esi@5
  unsigned int v6; // esi@6
  UIElement *v7; // ecx@7
  bool no_drag_out; // [sp+Fh] [bp-1C9h]@1
  UIElement *v9; // [sp+10h] [bp-1C8h]@1
  ElementDesc cDescCopy; // [sp+14h] [bp-1C4h]@6

  v9 = this;
  UIElement::GetAttribute_Bool(this, 0x39u, &no_drag_out);
  if ( no_drag_out )
    return 0;
  v3 = *_elem;
  if ( *_elem )
  {
    v4 = UIElementManager::s_pInstance;
    if ( UIElementManager::s_pInstance )
    {
      v5 = v3->m_layout;
      if ( v5 )
      {
        ElementDesc::ElementDesc(&cDescCopy, &v3->m_desc);
        cDescCopy.m_leftEdge = 0;
        cDescCopy.m_topEdge = 0;
        cDescCopy.m_rightEdge = 0;
        cDescCopy.m_bottomEdge = 0;
        v6 = (unsigned int)UIElementManager::CreateChildElement(v4, 0, v5, &cDescCopy);
        if ( v6 )
        {
          (*(void (__thiscall **)(unsigned int, UIElement *))(*(_DWORD *)v6 + 240))(v6, *_elem);
          v7 = v9;
          *_elem = (UIElement *)v6;
          UIElement::BroadcastElementMessage(v7, 0x14u, v6, 0);
          ElementDesc::~ElementDesc(&cDescCopy);
          return 1;
        }
        ElementDesc::~ElementDesc(&cDescCopy);
      }
    }
  }
  return 0;
}

//----- (004616F0) --------------------------------------------------------  // acclient.c:158044
int __thiscall UIElement::GetDragAndDropCatcher(UIElement *this, UIElement *_elem)
{
  UIElement *v2; // edi@1
  UIElement *v3; // esi@1
  int result; // eax@5
  int v5; // eax@7
  UIElement *v6; // [sp-2h] [bp-4h]@1

  v6 = this;
  v2 = _elem;
  v3 = this;
  if ( !_elem || _elem == this )
    goto LABEL_11;
  UIElement::GetAttribute_Bool(this, 0x36u, (bool *)&_elem);
  UIElement::GetAttribute_Bool(v3, 0x38u, (bool *)&v6 + 3);
  if ( (_BYTE)_elem && !BYTE3(v6) )
    return v3->m_dragDropCallback(v2, v3) != 0 ? (unsigned int)v3 : 0;
  if ( ((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3) )
  {
    v5 = ((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3);
    result = (*(int (__thiscall **)(int, UIElement *))(*(_DWORD *)v5 + 236))(v5, v2);
  }
  else
  {
LABEL_11:
    result = 0;
  }
  return result;
}

//----- (00461780) --------------------------------------------------------  // acclient.c:158075
char __thiscall UIElement::CatchDroppedItem(UIElement *this, DragDropInfo *i_pcDDI)
{
  UIElement::BroadcastElementMessage(this, 0x15u, (unsigned int)i_pcDDI, 0);
  return 1;
}

//----- (004617A0) --------------------------------------------------------  // acclient.c:158082
void __thiscall UIElement::DragAndDropComplete(UIElement *this, DragDropInfo *i_pcDDI)
{
  UIElement::BroadcastElementMessage(this, (i_pcDDI->success != 0) + 21, (unsigned int)i_pcDDI, 0);
}

//----- (004617C0) --------------------------------------------------------  // acclient.c:158088
void __thiscall UIElement::SetTooltip(UIElement *this, StringInfo *_text)
{
  UIElement *v2; // edi@1
  StringInfo *v3; // esi@1

  v2 = this;
  v3 = &this->m_TTText;
  if ( !StringInfo::operator==(&this->m_TTText, _text) )
  {
    StringInfo::operator=(v3, (int)_text);
    if ( UIElementManager::s_pInstance )
    {
      if ( UIElementManager::s_pInstance->m_pTooltipOwner == v2 && UIElementManager::s_pInstance->m_pTooltipElement )
        UIElementManager::ResetTooltip(UIElementManager::s_pInstance);
      v2->m_bIsMouseVisible = v2->m_bShouldBeMouseVisible
                           || (unsigned __int8)((int (__thiscall *)(UIElement *))v2->vfptr[24].OnAction)(v2);
    }
  }
}

//----- (00461840) --------------------------------------------------------  // acclient.c:158109
char __thiscall UIElement::MakeUIObject(UIElement *this, UIObject **o_pcUIObject)
{
  UIElement *v2; // edi@1
  UIRectangleObject *v3; // eax@4
  int v4; // eax@5
  UIObject **v5; // esi@6
  UISurfaceObject *v6; // eax@7
  UISurfaceObject *v7; // eax@8
  UISurface *v8; // eax@10
  int v9; // eax@11
  int v10; // esi@11
  unsigned int v11; // ebx@13
  unsigned int v12; // ebp@13
  StateDesc *v13; // eax@17
  unsigned int v14; // eax@19
  Graphic *v15; // ecx@23
  int v16; // eax@27
  UIObject *v18; // ebx@30
  int v19; // ebp@30
  unsigned int v20; // ebx@32
  ReferenceCountTemplate<1048576,1>Vtbl *v21; // ebp@32
  int v22; // ST10_4@32
  int v23; // eax@32
  unsigned int eObjectMode; // [sp+10h] [bp-34h]@13
  UISurfaceObject *pcObject; // [sp+14h] [bp-30h]@8
  SurfaceWindow window; // [sp+18h] [bp-2Ch]@30
  UIObject **o_pcUIObjecta; // [sp+48h] [bp+4h]@32

  v2 = this;
  if ( !((this->m_nFlags >> 14) & 1) )
    return 0;
  if ( (this->m_nFlags >> 19) & 1 && this->m_nFlags & 1 )
  {
    v3 = (UIRectangleObject *)operator new(0x60u);
    if ( !v3 )
      return 0;
    UIRectangleObject::UIRectangleObject(v3);
    if ( !v4 )
      return 0;
    v5 = o_pcUIObject;
    *(_OWORD *)(v4 + 80) = RGBAColor_White_34;
    *o_pcUIObject = (UIObject *)v4;
  }
  else
  {
    v6 = (UISurfaceObject *)operator new(0x130u);
    if ( v6 )
    {
      UISurfaceObject::UISurfaceObject(v6);
      pcObject = v7;
    }
    else
    {
      pcObject = 0;
    }
    v8 = (UISurface *)operator new(0x28u);
    if ( !v8 )
      return 0;
    UISurface::UISurface(v8);
    v10 = v9;
    if ( !v9 || !pcObject )
      return 0;
    v11 = UIRegion::GetWidth((UIRegion *)&v2->vfptr);
    v12 = UIRegion::GetHeight((UIRegion *)&v2->vfptr);
    if ( !UIElement::GetAttribute_Enum(v2, 0xCDu, &eObjectMode) )
      goto LABEL_35;
    if ( eObjectMode == 1 || eObjectMode == 2 )
    {
      if ( v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)16) )
        goto LABEL_35;
      v13 = v2->m_curStateDesc;
      if ( v13 && (v11 = v13->m_width) != 0 && (v14 = v13->m_height) != 0 )
      {
        v12 = v14;
      }
      else
      {
        v11 = v2->m_desc.m_width;
        v12 = v2->m_desc.m_height;
      }
      if ( eObjectMode == 2 )
      {
        v15 = v2->m_image;
        if ( v15 )
        {
          v11 = Graphic::GetWidth(v15);
          v12 = Graphic::GetHeight(v2->m_image);
        }
        if ( !(unsigned __int8)UISurface::IsPowerOfTwo(v11, v12) )
LABEL_35:
          eObjectMode = 3;
      }
    }
    if ( !UISurface::CreateSurface((UISurface *)v10, v11, v12, 1u) )
    {
      ReferenceCountTemplate<1048576,1>::Release((ReferenceCountTemplate<1048576,1> *)v10);
      ReferenceCountTemplate<1048576,1>::Release((ReferenceCountTemplate<1048576,1> *)&pcObject->vfptr);
      return 0;
    }
    v18 = (UIObject *)pcObject;
    LOBYTE(v16) = eObjectMode == 2;
    ((void (__thiscall *)(UISurfaceObject *, int, int))pcObject->vfptr[14].__vecDelDtor)(pcObject, v10, v16);
    UISurface::PrepareSurface((UISurface *)v10);
    v19 = *(_DWORD *)(*(_DWORD *)(v10 + 12) + 164);
    UISurface::PrepareSurface((UISurface *)v10);
    pcObject = *(UISurfaceObject **)(*(_DWORD *)(v10 + 12) + 160);
    UISurface::PrepareSurface((UISurface *)v10);
    SurfaceWindow::SurfaceWindow(
      &window,
      *(RenderSurface **)(v10 + 12),
      0,
      0,
      (const unsigned int)((char *)&pcObject[-1].m_virtualZRot + 7),
      v19 - 1);
    SurfaceWindow::Fill(&window, &RGBAColor_Null_2);
    ReferenceCountTemplate<1048576,1>::Release((ReferenceCountTemplate<1048576,1> *)v10);
    v5 = o_pcUIObject;
    *o_pcUIObject = v18;
    window.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
    SurfaceWindow::End(&window);
  }
  if ( !*v5 )
    return 0;
  (*v5)->m_bTemporary = (v2->m_nFlags >> 15) & 1;
  v20 = (*v5)->m_nVirtualY;
  v21 = (*v5)->vfptr;
  o_pcUIObjecta = (UIObject **)(*v5)->m_nVirtualX;
  v22 = UIRegion::GetHeight((UIRegion *)&v2->vfptr);
  v23 = UIRegion::GetWidth((UIRegion *)&v2->vfptr);
  ((void (__thiscall *)(UIObject *, UIObject **, unsigned int, int, int))v21[3].__vecDelDtor)(
    *v5,
    o_pcUIObjecta,
    v20,
    v23,
    v22);
  return 1;
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00461AC0) --------------------------------------------------------  // acclient.c:158249
char __thiscall UIElement::SetUIObject(UIElement *this, UIObject *i_pcUIObject)
{
  UIElement *v2; // esi@1
  UIObject *v3; // eax@1
  UIObject *v4; // edi@1
  UIObject *v5; // ecx@3
  bool v6; // zf@4
  int v7; // ebx@8
  int v8; // ST0C_4@8
  unsigned int v9; // ST04_4@8
  unsigned int v10; // eax@8
  int v11; // eax@10
  ReferenceCountTemplate<1048576,1>Vtbl *i_pcUIObjecta; // [sp+Ch] [bp+4h]@8

  v2 = this;
  v3 = this->m_object;
  v4 = i_pcUIObject;
  if ( i_pcUIObject != v3 )
  {
    this->m_nFlags &= 0xFFFEFFFF;
    if ( v3 )
    {
      v3->m_pOwner = 0;
      RenderUI::UnlinkObject(this->m_object);
      v5 = v2->m_object;
      if ( v5 )
      {
        v6 = v5->m_cRef-- == 1;
        if ( v6 )
          ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
        v2->m_object = 0;
      }
    }
    if ( i_pcUIObject )
    {
      v7 = UIRegion::GetWidth((UIRegion *)&v2->vfptr);
      v8 = UIRegion::GetHeight((UIRegion *)&v2->vfptr);
      i_pcUIObjecta = i_pcUIObject->vfptr;
      v9 = UIRegion::GetScreenY0((UIRegion *)&v2->vfptr);
      v10 = UIRegion::GetScreenX0((UIRegion *)&v2->vfptr);
      ((void (__thiscall *)(UIObject *, unsigned int, unsigned int, int, int))i_pcUIObjecta[3].__vecDelDtor)(
        v4,
        v10,
        v9,
        v7,
        v8);
      v4->m_bVisible = (*((_DWORD *)&v2->0 + 41) >> 1) & 1;
      if ( v4->m_eClampGameView )
        RenderUI::RecalculateClampedPosition();
      v4->m_nDepth = v2->m_zlevel;
      v11 = HIDWORD(Timer::local_time);
      LODWORD(v4->m_tTouchTime) = LODWORD(Timer::local_time);
      HIDWORD(v4->m_tTouchTime) = v11;
      RenderUI::LinkObject(v4);
      v2->m_nFlags |= 0x10000u;
      v2->m_object = v4;
      v4->m_pOwner = (UIRegion *)v2;
      v2->vfptr[3].__vecDelDtor((IInputActionCallback *)v2, v2->m_eClampGameView);
      UIRegion::MakeRootDirtyHere((UIRegion *)&v2->vfptr);
    }
  }
  return 1;
}

//----- (00461BD0) --------------------------------------------------------  // acclient.c:158314
void __thiscall UIElement::SetShouldOwnObject(UIElement *this, bool _b)
{
  UIElement *v2; // esi@1
  bool v3; // zf@1
  int v4; // edx@4
  unsigned int eObjectMode; // [sp+0h] [bp-4h]@1

  eObjectMode = (unsigned int)this;
  v2 = this;
  v3 = _b == 0;
  this->m_nFlags ^= ((unsigned __int16)this->m_nFlags ^ (unsigned __int16)(_b << 14)) & 0x4000;
  if ( !v3 && UIElement::GetAttribute_Enum(this, 0xCDu, &eObjectMode) )
    v2->m_nFlags ^= ((unsigned __int16)v2->m_nFlags ^ (unsigned __int16)((eObjectMode != 0) << 14)) & 0x4000;
  v4 = *((_DWORD *)&v2->0 + 41) >> 1;
  *(_DWORD *)&_b = 0;
  if ( v4 & 1 && (v2->m_nFlags >> 14) & 1 )
    ((void (__thiscall *)(UIElement *, bool *))v2->vfptr[23].OnLoseFocus)(v2, &_b);
  v2->vfptr[23].OnAction((IInputActionCallback *)v2, (InputEvent *)_b);
}

//----- (00461C80) --------------------------------------------------------  // acclient.c:158335
char __thiscall UIElement::Activate(UIElement *this)
{
  UIElement *v1; // esi@1
  char v2; // bl@1
  UIElement *v3; // eax@3
  char result; // al@4
  UIElementManager *v5; // edi@6
  int v6; // eax@8
  UIElement *v7; // esi@10

  v1 = this;
  v2 = ~(unsigned __int8)(this->m_nFlags >> 20) & 1;
  if ( !UIElement::IsVisible(this) )
    return 0;
  if ( !((v1->m_nFlags >> 21) & 1) )
  {
    v3 = UIElement::GetRootElement(v1);
    if ( v3 )
      return ((int (__thiscall *)(UIElement *))v3->vfptr[21].__vecDelDtor)(v3);
    return 0;
  }
  v1->m_nFlags |= 0x100000u;
  ((void (__thiscall *)(UIElement *, _DWORD))v1->vfptr[14].OnLoseFocus)(v1, 0);
  v5 = UIElementManager::s_pInstance;
  if ( UIElementManager::s_pInstance )
  {
    UIElementManager::ActivationAlert(UIElementManager::s_pInstance, v1, 1);
    UIElementManager::RegisterActivatable(v5, v1);
    if ( ((int (__thiscall *)(UIElement *))v1->vfptr[13].OnAction)(v1) )
    {
      v6 = ((int (__thiscall *)(UIElement *))v1->vfptr[13].OnAction)(v1);
      (*(void (__thiscall **)(int, UIElement *))(*(_DWORD *)v6 + 72))(v6, v1);
    }
    if ( v2 )
    {
      UIElement::BroadcastElementMessage(v1, 0x29u, 0, 0);
      v7 = v1->m_pFocusElement;
      if ( v7 )
        UIElementManager::SetFocusElement(v5, v7);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00461D50) --------------------------------------------------------  // acclient.c:158385
char __thiscall UIElement::Deactivate(UIElement *this)
{
  UIElement *v1; // esi@1
  unsigned int v2; // eax@1
  UIElement *v3; // eax@2
  char result; // al@3
  char v5; // bl@5
  UIElementManager *v6; // edi@5

  v1 = this;
  v2 = this->m_nFlags;
  if ( (this->m_nFlags >> 21) & 1 )
  {
    this->m_nFlags = v2 & 0xFFEFFFFF;
    v5 = (v2 >> 20) & 1;
    ((void (__thiscall *)(UIElement *))this->vfptr[15].__vecDelDtor)(this);
    v6 = UIElementManager::s_pInstance;
    if ( UIElementManager::s_pInstance )
    {
      UIElementManager::ActivationAlert(UIElementManager::s_pInstance, v1, 0);
      if ( v5 )
      {
        UIElement::BroadcastElementMessage(v1, 0x2Au, 0, 0);
        if ( v1->m_pFocusElement )
          UIElementManager::SetFocusElement(v6, 0);
      }
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v3 = UIElement::GetRootElement(this);
    if ( v3 )
      result = ((int (__thiscall *)(UIElement *))v3->vfptr[21].OnAction)(v3);
    else
      result = 0;
  }
  return result;
}

//----- (00461DE0) --------------------------------------------------------  // acclient.c:158430
char __thiscall UIElement::RelinquishFocus(UIElement *this)
{
  UIElement *v1; // esi@1
  UIElement *v2; // eax@1

  v1 = this;
  v2 = UIElement::GetRootElement(this);
  if ( v2 )
  {
    v2->m_pFocusElement = 0;
    v1->m_nFlags &= 0xFFBFFFFF;
    if ( UIElementManager::s_pInstance )
    {
      if ( UIElementManager::s_pInstance->m_focusElement == v1 )
        UIElementManager::SetFocusElement(UIElementManager::s_pInstance, 0);
    }
  }
  return 1;
}

//----- (00461E30) --------------------------------------------------------  // acclient.c:158451
void __thiscall UIElement::SetMouseVisible(UIElement *this, bool i_bShouldBeMouseVisible)
{
  UIElement *v2; // esi@1
  bool v3; // bl@1
  bool v4; // al@3
  UIElementManager *v5; // ebx@6
  CInputManager *v6; // edi@8
  int v7; // ebp@8
  int v8; // edi@8
  Box2D *v9; // eax@8
  Box2D result; // [sp+8h] [bp-10h]@8

  v2 = this;
  v3 = this->m_bIsMouseVisible;
  this->m_bShouldBeMouseVisible = i_bShouldBeMouseVisible;
  v4 = i_bShouldBeMouseVisible || (unsigned __int8)((int (*)(void))this->vfptr[24].OnAction)();
  v2->m_bIsMouseVisible = v4;
  if ( v3 != v4 )
  {
    v5 = UIElementManager::s_pInstance;
    if ( UIElementManager::s_pInstance )
    {
      if ( ICIDM::s_cidm )
      {
        if ( (v6 = ICIDM::s_cidm,
              v7 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)(),
              v8 = v6->vfptr->GetMouseX((ICIDM *)v6),
              v9 = UIRegion::GetScreenClipBox((UIRegion *)&v2->vfptr, &result),
              v8 >= v9->m_x0)
          && v8 <= v9->m_x1
          && v7 >= v9->m_y0
          && v7 <= v9->m_y1
          || *((_BYTE *)&v2->0 + 164) & 1 )
          v5->m_bPerformMouseHitTest = 1;
      }
    }
  }
}

//----- (00461ED0) --------------------------------------------------------  // acclient.c:158491
void __thiscall UIElement::GetCurrentUIObjectMode(UIElement *this, unsigned int *i_eMode)
{
  UIElement *v2; // esi@1
  int v3; // eax@3
  unsigned int eObjectMode; // [sp+4h] [bp-4h]@1

  eObjectMode = (unsigned int)this;
  v2 = this;
  if ( (this->m_nFlags >> 14) & 1 )
  {
LABEL_5:
    if ( v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)16) )
    {
      *i_eMode = 3;
    }
    else if ( UIElement::GetAttribute_Enum(v2, 0xCDu, &eObjectMode) )
    {
      *i_eMode = eObjectMode;
    }
    else
    {
      *i_eMode = 3;
    }
  }
  else
  {
    while ( v2->m_parent )
    {
      v3 = ((int (__thiscall *)(UIElement *))v2->vfptr[13].OnAction)(v2);
      if ( !v3 )
        break;
      v2 = (UIElement *)v3;
      if ( (*(_DWORD *)(v3 + 1364) >> 14) & 1 )
        goto LABEL_5;
    }
  }
}

//----- (00461F60) --------------------------------------------------------  // acclient.c:158530
Vector3 *__thiscall UIElement::GetObjectScale(UIElement *this, Vector3 *result)
{
  UIElement *v2; // esi@1
  UIObject *v3; // eax@3
  UIRegion *v4; // ecx@4
  Vector3 *v5; // eax@6
  unsigned int eMode; // [sp+0h] [bp-4h]@1

  v2 = this;
  eMode = 3;
  UIElement::GetCurrentUIObjectMode(this, &eMode);
  if ( eMode != 2
    && eMode != 3
    && ((v3 = v2->m_object) != 0 || (v4 = v2->m_parent) != 0 && (v3 = UIRegion::GetObjectA(v4)) != 0) )
  {
    result->x = v3->m_vScale.x;
    result->y = v3->m_vScale.y;
    result->z = v3->m_vScale.z;
    v5 = result;
  }
  else
  {
    v5 = result;
    COERCE_VECTOR3(result->x) = Vector3_OneVector___2;
  }
  return v5;
}

//----- (00461FE0) --------------------------------------------------------  // acclient.c:158559
char __thiscall UIElement::UpdateObjectScale(UIElement *this)
{
  UIElement *v1; // edi@1
  UIObject *v2; // eax@1
  char v3; // bl@1
  UIRegion *v4; // ecx@2
  UIObject *v5; // esi@4
  float v6; // ecx@7
  float v7; // edx@7
  float v8; // eax@7
  int v9; // esi@7
  signed int v10; // eax@9
  double v11; // st7@11
  float v12; // edx@14
  float fScaleX; // [sp+Ch] [bp-2Ch]@8
  float fScaleY; // [sp+10h] [bp-28h]@5
  int v16; // [sp+14h] [bp-24h]@7
  int tmp; // [sp+18h] [bp-20h]@7
  Vector3 vNewScale; // [sp+1Ch] [bp-1Ch]@7
  int v19; // [sp+28h] [bp-10h]@7
  Vector3 vCurScale; // [sp+2Ch] [bp-Ch]@7

  v1 = this;
  v2 = this->m_object;
  v3 = 0;
  if ( !v2 )
  {
    v4 = this->m_parent;
    if ( !v4 )
      return v3;
    v2 = UIRegion::GetObjectA(v4);
  }
  v5 = v2;
  if ( !v2 )
    return v3;
  LODWORD(fScaleY) = 3;
  UIElement::GetCurrentUIObjectMode(v1, (unsigned int *)&fScaleY);
  if ( LODWORD(fScaleY) != 2 && LODWORD(fScaleY) != 3 )
  {
    v6 = v5->m_vScale.x;
    v7 = v5->m_vScale.y;
    v8 = v5->m_vScale.z;
    v9 = (int)&v5->m_vScale;
    vCurScale.x = v6;
    vCurScale.y = v7;
    vCurScale.z = v8;
    LODWORD(vNewScale.x) = 0;
    LODWORD(vNewScale.y) = 0;
    LODWORD(vNewScale.z) = 0;
    v19 = 0;
    UIElement::GetOriginalPosition(v1, (Box2D *)&vNewScale, &tmp);
    v16 = LODWORD(vNewScale.z) - (_DWORD)vNewScale.x + 1;
    if ( LODWORD(vNewScale.z) - (_DWORD)vNewScale.x == -1 )
    {
      fScaleX = 0.0;
    }
    else
    {
      v10 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
      fScaleX = (double)v10 / (double)v16;
    }
    tmp = v19 - LODWORD(vNewScale.y) + 1;
    if ( v19 - LODWORD(vNewScale.y) == -1 )
    {
      v11 = 0.0;
    }
    else
    {
      v16 = UIRegion::GetHeight((UIRegion *)&v1->vfptr);
      v11 = (double)v16 / (double)tmp;
    }
    fScaleY = v11;
    vNewScale.y = v11;
    vNewScale.x = fScaleX;
    LODWORD(vNewScale.z) = 1065353216;
    if ( (unsigned __int8)Vector3::operator!=(&vCurScale, &vNewScale) )
    {
      vNewScale.x = fScaleX;
      v12 = fScaleY;
      vNewScale.y = fScaleY;
      LODWORD(vNewScale.z) = 1065353216;
      *(float *)v9 = fScaleX;
      *(float *)(v9 + 4) = v12;
      *(_DWORD *)(v9 + 8) = 1065353216;
      v3 = 1;
    }
    return v3;
  }
  return 0;
}

//----- (00462140) --------------------------------------------------------  // acclient.c:158651
Box2D *__thiscall UIElement::GetSurfaceBox(UIElement *this, Box2D *result)
{
  Box2D *v2; // eax@2
  char *v3; // ecx@3

  if ( *((_BYTE *)&this->1 + 2) & 1 )
  {
    UIRegion::GetSurfaceBox((UIRegion *)&this->vfptr, result);
    v2 = result;
  }
  else
  {
    v2 = result;
    v3 = (char *)&this->m_surfaceBox;
    if ( (char *)result != v3 )
    {
      result->m_x0 = *(_DWORD *)v3;
      result->m_x1 = *((_DWORD *)v3 + 2);
      result->m_y0 = *((_DWORD *)v3 + 1);
      result->m_y1 = *((_DWORD *)v3 + 3);
    }
  }
  return v2;
}

//----- (00462190) --------------------------------------------------------  // acclient.c:158677
char __thiscall UIElement::UpdateSurfaceBox(UIElement *this, const bool i_bPositionUpdate)
{
  UIElement *v2; // esi@1
  int v3; // ebp@2
  int v4; // edi@2
  int v5; // ebx@2
  unsigned __int64 v6; // rax@3
  signed int v7; // eax@4
  int surfY; // [sp+4h] [bp-10h]@2
  Vector3 vObjectScale; // [sp+8h] [bp-Ch]@2

  v2 = this;
  if ( !((this->m_nFlags >> 14) & 1) )
  {
    UIElement::GetObjectScale(this, &vObjectScale);
    v3 = v2->m_surfaceBox.m_x0;
    v4 = v2->m_surfaceBox.m_x1 - v2->m_surfaceBox.m_x0 + 1;
    v5 = v2->m_surfaceBox.m_y1 - v2->m_surfaceBox.m_y0 + 1;
    surfY = v2->m_surfaceBox.m_y0;
    if ( i_bPositionUpdate )
    {
      v3 = (unsigned __int64)((double)v2->m_box.m_x0 / vObjectScale.x);
      v6 = (unsigned __int64)((double)v2->m_box.m_y0 / vObjectScale.y);
    }
    else
    {
      v7 = UIRegion::GetWidth((UIRegion *)&v2->vfptr);
      v4 = (unsigned __int64)((double)v7 / vObjectScale.x);
      LODWORD(v6) = UIRegion::GetHeight((UIRegion *)&v2->vfptr);
      v5 = (unsigned __int64)((double)(signed int)v6 / vObjectScale.y);
      LODWORD(v6) = surfY;
    }
    v2->m_surfaceBox.m_y0 = v6;
    v2->m_surfaceBox.m_x0 = v3;
    v2->m_surfaceBox.m_x1 = v3 + v4 - 1;
    v2->m_surfaceBox.m_y1 = v2->m_surfaceBox.m_y0 + v5 - 1;
  }
  return 1;
}

//----- (00462270) --------------------------------------------------------  // acclient.c:158718
IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *__thiscall IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *v2; // esi@1
  HashSetData<UIListener *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>Vtbl *)IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79BF18: using guessed type int (__thiscall *IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable[3])(void *, char);

//----- (004622B0) --------------------------------------------------------  // acclient.c:158739
void __thiscall UIElement::SetVisible(UIElement *this, int _visible)
{
  UIElementManager *v2; // edi@1
  UIElement *v3; // esi@1
  char v4; // bl@1
  char oldvisible; // [sp+1h] [bp-1h]@1

  v2 = UIElementManager::s_pInstance;
  v3 = this;
  oldvisible = UIElement::IsVisible(this);
  v4 = (*((_DWORD *)&v3->0 + 41) >> 1) & 1;
  UIRegion::SetVisible((UIRegion *)&v3->vfptr, _visible);
  LOBYTE(_visible) = UIElement::IsVisible(v3);
  if ( ((*((_DWORD *)&v3->0 + 41) >> 1) & 1) != v4 )
    UIElement::BroadcastElementMessage(v3, 0x18u, (*((_DWORD *)&v3->0 + 41) >> 1) & 1, 0);
  if ( oldvisible != (_BYTE)_visible )
  {
    if ( (v3->m_nFlags >> 6) & 1 )
    {
      if ( v2 )
        UIElementManager::BroadcastGlobalMessage(v2, 7u, 0);
    }
    ((void (__thiscall *)(UIElement *, int))v3->vfptr[20].OnLoseFocus)(v3, _visible);
  }
}
// 4622B0: could not find valid save-restore pair for ebx
// 4622B0: could not find valid save-restore pair for edi
// 4622B0: could not find valid save-restore pair for esi

//----- (00462340) --------------------------------------------------------  // acclient.c:158769
int __thiscall UIElement::ListenToElementMessage(UIElement *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIElement *v3; // esi@1
  unsigned int v4; // eax@3
  unsigned int v6; // eax@8
  unsigned int v7; // ecx@8
  int v8; // eax@21

  v2 = i_rMsg;
  v3 = this;
  if ( i_rMsg->pElement == this )
  {
    switch ( i_rMsg->idMessage )
    {
      case 0x29u:
        v4 = this->m_state;
        if ( v4 && v4 != 1 )
          return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
        ((void (__stdcall *)(signed int))this->vfptr[13].__vecDelDtor)(5);
        return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
      case 0x2Au:
        if ( this->m_state != 5 )
          return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
        ((void (__stdcall *)(signed int))this->vfptr[13].__vecDelDtor)(1);
        return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
      case 0x2Fu:
        v6 = i_rMsg->dwParam1;
        v7 = this->m_state;
        if ( !v6 )
          goto LABEL_14;
        if ( !v7 || v7 == 1 || v7 == 5 )
        {
          v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 4u);
          return ((int (__thiscall *)(_DWORD, _DWORD, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
        }
        if ( v6 )
          return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
LABEL_14:
        if ( v7 != 4 )
          return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
        v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 4 * ((v3->m_nFlags >> 20) & 1) | 1);
        return ((int (__thiscall *)(_DWORD, _DWORD, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
      case 0x31u:
        i_rMsg = 0;
        UIElement::GetAttribute_Enum(this, 0x58u, (unsigned int *)&i_rMsg);
        if ( i_rMsg == (UIElementMessageInfo *)1 )
        {
          v8 = *((_DWORD *)&v3->0 + 41) >> 1;
          LOBYTE(v8) = ~(_BYTE)v8;
          v3->vfptr[2].__vecDelDtor((IInputActionCallback *)v3, v8 & 0xFFFFFF01);
        }
        else
        {
          if ( i_rMsg == (UIElementMessageInfo *)2 )
          {
            v3->vfptr[2].__vecDelDtor((IInputActionCallback *)v3, 1u);
            return ((int (__thiscall *)(_DWORD, _DWORD, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
          }
          if ( (UIElementMessageInfo *)((char *)&i_rMsg[-1].tsSerialNumber.m_timestamp + 2) == (UIElementMessageInfo *)1 )
            v3->vfptr[2].__vecDelDtor((IInputActionCallback *)v3, 0);
        }
        break;
      default:
        return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
    }
  }
  return ((int (__thiscall *)(UIElement *, UIElementMessageInfo *, _DWORD))v3->vfptr[24].OnLoseFocus)(v3, v2, 0);
}

//----- (004624D0) --------------------------------------------------------  // acclient.c:158840
char __thiscall UIElement::InqAvailableProperties(UIElement *this, AvailablePropertySet *_set)
{
  char v2; // bl@1
  MasterProperty *v3; // esi@1
  char result; // al@2
  MasterPropertyGrabber mpr; // [sp+0h] [bp-4h]@1

  mpr.m_object = (MasterProperty *)this;
  v2 = 1;
  MasterPropertyGrabber::MasterPropertyGrabber(&mpr);
  v3 = mpr.m_object;
  if ( mpr.m_object )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup(mpr.m_object, 8u, _set) )
      v2 = 0;
    v3->vfptr->Release((Interface *)v3);
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00462520) --------------------------------------------------------  // acclient.c:158866
bool __thiscall UIElement::MouseHover(UIElement *this, int _xWindow, int _yWindow)
{
  UIElement *v3; // esi@1
  unsigned int v4; // ebp@6
  int v5; // edi@6
  bool bRet; // [sp+Bh] [bp-29h]@1
  UIElementMessageInfo msg; // [sp+Ch] [bp-28h]@6

  v3 = this;
  bRet = 0;
  if ( (*((_DWORD *)&this->0 + 41) >> 5) & 1
    && UIElementManager::s_pInstance
    && UIElementManager::s_pInstance->m_tooltipEnable )
  {
    UIElement::StartTooltipAtMouse(this, 0.0);
    bRet = 1;
  }
  if ( *((_BYTE *)&v3->1 + 3) & 1 )
  {
    v4 = v3->m_desc.m_elementID;
    v5 = _yWindow - UIRegion::GetScreenY0((UIRegion *)&v3->vfptr);
    msg.ptElement.x = _xWindow - UIRegion::GetScreenX0((UIRegion *)&v3->vfptr);
    msg.ptElement.y = v5;
    msg.idElement = v4;
    msg.pElement = v3;
    msg.idMessage = 32;
    msg.dwParam1 = 0;
    msg.dwParam2 = 0;
    msg.tsSerialNumber.m_timestamp = 0;
    msg.ptWindow.x = _xWindow;
    msg.ptWindow.y = _yWindow;
    if ( UIElementManager::s_pInstance )
      UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
  }
  return bRet;
}

//----- (004625E0) --------------------------------------------------------  // acclient.c:158904
void __thiscall UIElement::ClearTooltip(UIElement *this)
{
  UIElement *v1; // esi@1
  bool v2; // al@3
  StringInfo foo; // [sp+4h] [bp-90h]@1

  v1 = this;
  StringInfo::StringInfo(&foo);
  UIElement::SetTooltip(v1, &foo);
  v2 = v1->m_bShouldBeMouseVisible || (unsigned __int8)((int (__thiscall *)(UIElement *))v1->vfptr[24].OnAction)(v1);
  v1->m_bIsMouseVisible = v2;
  StringInfo::~StringInfo(&foo);
}

//----- (00462640) --------------------------------------------------------  // acclient.c:158919
char __usercall UIElement::UpdateForParentSizeChange@<al>(UIElement *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4)
{
  UIElement *v4; // esi@1
  int v5; // ebp@1
  IInputActionCallbackVtbl *v6; // eax@2
  UIElement *v7; // edi@2
  int v8; // edi@4
  int v9; // eax@4
  int v10; // ecx@4
  LayoutDesc *v11; // eax@5
  int v12; // eax@5
  unsigned int v13; // ebx@5
  unsigned int v14; // eax@5
  int v15; // eax@6
  int v16; // ecx@6
  int v17; // ebx@6
  double v18; // st7@10
  int v19; // ebx@21
  unsigned __int64 v20; // rax@28
  int v21; // edi@35
  int v22; // eax@42
  int v23; // ecx@42
  int v24; // edx@42
  int v25; // ebp@50
  int v26; // ebx@50
  int v27; // eax@51
  int v28; // edi@51
  float tmp; // [sp+10h] [bp-50h]@7
  int v31; // [sp+14h] [bp-4Ch]@6
  int _zlevel; // [sp+18h] [bp-48h]@4
  int zLevel; // [sp+1Ch] [bp-44h]@2
  Box2D currentPosition; // [sp+20h] [bp-40h]@2
  Box2D originalPosition; // [sp+30h] [bp-30h]@2
  Box2D currentParent; // [sp+40h] [bp-20h]@2
  Box2D originalParent; // [sp+50h] [bp-10h]@2
  int retaddr; // [sp+60h] [bp+0h]@4

  v4 = this;
  v5 = 0;
  if ( !this->m_layout )
    return 0;
  originalPosition.m_x0 = 0;
  originalPosition.m_y0 = 0;
  originalPosition.m_x1 = 0;
  originalPosition.m_y1 = 0;
  UIElement::GetOriginalPosition(this, &originalPosition, &zLevel);
  currentPosition = originalPosition;
  v6 = v4->vfptr;
  originalParent.m_x0 = 0;
  originalParent.m_y0 = 0;
  originalParent.m_x1 = 0;
  originalParent.m_y1 = 0;
  currentParent.m_x0 = 0;
  currentParent.m_y0 = 0;
  currentParent.m_x1 = 0;
  currentParent.m_y1 = 0;
  v7 = (UIElement *)((int (__thiscall *)(UIElement *, int, int))v6[13].OnAction)(v4, a3, a2);
  if ( !v7 || (v4->m_nFlags >> 21) & 1 )
  {
    v11 = v4->m_layout;
    v8 = v11->m_displayWidth - 1;
    v12 = v11->m_displayHeight - 1;
    originalParent.m_y1 = 0;
    a4 = v12;
    v13 = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
    v14 = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
    v10 = 0;
    originalParent.m_x0 = v14 - 1;
    currentParent.m_x1 = 0;
    v9 = v13 - 1;
  }
  else
  {
    UIElement::GetOriginalPosition(v7, (Box2D *)((char *)&originalParent + 8), &_zlevel);
    UIElement::GetCurrentPosition(v7, (Box2D *)((char *)&currentParent + 8), &_zlevel);
    v8 = retaddr;
    v5 = originalParent.m_x1;
    v9 = originalParent.m_y0;
    v10 = currentParent.m_y1;
  }
  v15 = v9 - v10;
  v16 = originalParent.m_y1 + v15 - a4;
  v17 = v5 + originalParent.m_x0 - v8 - currentParent.m_x1;
  _zlevel = v15;
  v31 = originalParent.m_y1 + v15 - a4;
  zLevel = v8 - v5 + 1;
  if ( v8 - v5 == -1 )
    tmp = 0.0;
  else
    tmp = (double)(originalParent.m_x0 - currentParent.m_x1 + 1) / (double)zLevel;
  currentPosition.m_x0 = a4 - originalParent.m_y1 + 1;
  if ( a4 - originalParent.m_y1 == -1 )
  {
    v18 = 0.0;
  }
  else
  {
    zLevel = v15 + 1;
    v18 = (double)(v15 + 1) / (double)currentPosition.m_x0;
  }
  switch ( v4->m_desc.m_leftEdge )
  {
    case 2u:
      currentPosition.m_x1 = v17 + originalPosition.m_x1;
      break;
    case 3u:
      currentPosition.m_x1 = (originalParent.m_x0 - currentParent.m_x1 + 1) / 2
                           - (currentParent.m_x0 - originalPosition.m_x1 + 1) / 2;
      break;
    case 4u:
      v16 = originalParent.m_y1 + v15 - a4;
      currentPosition.m_x1 = (unsigned __int64)((double)originalPosition.m_x1 * tmp);
      break;
  }
  switch ( v4->m_desc.m_rightEdge )
  {
    case 1u:
      originalPosition.m_x0 = v17 + currentParent.m_x0;
      break;
    case 3u:
      originalPosition.m_x0 = (originalParent.m_x0 - currentParent.m_x1 + 1) / 2
                            + (currentParent.m_x0 - originalPosition.m_x1 + 1) / 2
                            - 1;
      break;
    case 4u:
      v16 = originalParent.m_y1 + v15 - a4;
      v19 = (unsigned __int64)((double)currentParent.m_x0 * tmp);
      goto LABEL_25;
  }
  v19 = originalPosition.m_x0;
LABEL_25:
  if ( v4->m_desc.m_topEdge == 2 )
  {
    LODWORD(v20) = v16 + originalPosition.m_y1;
  }
  else if ( v4->m_desc.m_topEdge == 3 )
  {
    LODWORD(v20) = (_zlevel + 1) / 2 - (currentParent.m_y0 - originalPosition.m_y1 + 1) / 2;
  }
  else
  {
    if ( v4->m_desc.m_topEdge != 4 )
      goto LABEL_32;
    v20 = (unsigned __int64)((double)originalPosition.m_y1 * v18);
    v16 = v31;
  }
  currentPosition.m_y1 = v20;
LABEL_32:
  switch ( v4->m_desc.m_bottomEdge )
  {
    case 1u:
      originalPosition.m_y0 = v16 + currentParent.m_y0;
      break;
    case 3u:
      originalPosition.m_y0 = (currentParent.m_y0 - originalPosition.m_y1 + 1) / 2 + (_zlevel + 1) / 2 - 1;
      break;
    case 4u:
      v21 = (unsigned __int64)((double)currentParent.m_y0 * v18);
      goto LABEL_39;
  }
  v21 = originalPosition.m_y0;
LABEL_39:
  if ( UIRegion::GetWidth((UIRegion *)&v4->vfptr)
    || UIRegion::GetHeight((UIRegion *)&v4->vfptr)
    || (v4->m_nFlags >> 17) & 1 )
  {
    v22 = v4->m_box.m_y0;
    v23 = v4->m_box.m_x1;
    v24 = v4->m_box.m_y1;
    if ( !v4->m_desc.m_leftEdge )
      currentPosition.m_x1 = v4->m_box.m_x0;
    if ( !v4->m_desc.m_topEdge )
      currentPosition.m_y1 = v22;
    if ( !v4->m_desc.m_rightEdge )
    {
      originalPosition.m_x0 = v23;
      v19 = v23;
    }
    if ( !v4->m_desc.m_bottomEdge )
    {
      originalPosition.m_y0 = v24;
      v21 = v24;
    }
  }
  v25 = currentPosition.m_y1;
  ((void (__thiscall *)(UIElement *))v4->vfptr[3].OnLoseFocus)(v4);
  ((void (__thiscall *)(UIElement *, int, int))v4->vfptr[4].__vecDelDtor)(
    v4,
    v19 - currentPosition.m_x0 + 1,
    v21 - v25 + 1);
  v26 = zLevel;
  if ( zLevel != v4->m_zlevel )
  {
    v27 = ((int (__thiscall *)(UIElement *))v4->vfptr[13].OnAction)(v4);
    v28 = v27;
    v4->m_zlevel = v26;
    if ( v27 )
    {
      (*(void (__thiscall **)(int, UIElement *))(*(_DWORD *)v27 + 112))(v27, v4);
      (*(void (__thiscall **)(int, UIElement *))(*(_DWORD *)v28 + 108))(v28, v4);
    }
  }
  return 1;
}
// 462640: could not find valid save-restore pair for ebx
// 462640: could not find valid save-restore pair for edi

//----- (00462A00) --------------------------------------------------------  // acclient.c:159127
int __thiscall CTimestamp<unsigned long,0>::operator<(CTimestamp<unsigned long,0> *this, CTimestamp<unsigned long,0> *rhs)
{
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int result; // eax@2
  int v5; // edx@3
  int v6; // esi@3

  v2 = rhs->m_timestamp;
  v3 = this->m_timestamp;
  if ( v3 == rhs->m_timestamp )
  {
    result = 0;
  }
  else
  {
    v5 = v3 - v2;
    v6 = 1;
    if ( v3 < v2 )
    {
      v5 = v2 - v3;
      v6 = -1;
    }
    if ( (unsigned int)v5 > 0x7FFFFFFF )
      v6 = -v6;
    result = v6 < 0;
  }
  return result;
}

//----- (00462A50) --------------------------------------------------------  // acclient.c:159158
void __thiscall UIElement::SetParent(UIElement *this, UIRegion *_parent)
{
  UIElement *v2; // esi@1
  int v3; // edi@1
  unsigned int v4; // ebp@1
  UIElement *v5; // eax@2
  unsigned int v6; // eax@8
  int v7; // [sp+0h] [bp-14h]@0
  int nOldScreenY; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = ((int (*)(void))this->vfptr[13].OnAction)();
  v4 = UIRegion::GetScreenX0((UIRegion *)&v2->vfptr);
  nOldScreenY = UIRegion::GetScreenY0((UIRegion *)&v2->vfptr);
  if ( (UIRegion *)v3 != _parent )
  {
    v5 = UIElement::GetRootElement(v2);
    if ( v5 )
    {
      v3 = (int)v5->m_pFocusElement;
      if ( v3 )
      {
        if ( (UIElement *)v3 == v2 || UIElement::IsAncestorOfMe((UIElement *)v3, v2) )
          (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 264))(v3);
      }
    }
    UIRegion::SetParent((UIRegion *)&v2->vfptr, _parent);
    if ( (v2->m_nFlags >> 11) & 1 )
    {
      v6 = ((int (__thiscall *)(UIElement *))v2->vfptr[13].OnAction)(v2);
      UIElement::BroadcastElementMessage(v2, 0x26u, v6, 0);
    }
    UIElement::UpdateForParentSizeChange(v2, (int)_parent, v3, v7);
    if ( v4 != UIRegion::GetScreenX0((UIRegion *)&v2->vfptr)
      || nOldScreenY != UIRegion::GetScreenY0((UIRegion *)&v2->vfptr) )
      ((void (__thiscall *)(UIElement *))v2->vfptr[23].__vecDelDtor)(v2);
    v2->vfptr[3].__vecDelDtor((IInputActionCallback *)v2, v2->m_eClampGameView);
  }
}

//----- (00462B20) --------------------------------------------------------  // acclient.c:159199
int __thiscall UIElement::ForwardElementMessage(UIElement *this, UIElementMessageInfo *i_rMsg, UIElementMessageListenResult i_eStatus)
{
  UIElement *v3; // esi@1
  UIElementMessageListenResult v4; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // eax@1
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *v6; // ecx@1
  HashSetData<UIListener *> **v7; // edx@1
  HashSetData<UIListener *> *v8; // eax@1
  HashSetData<UIListener *> *v9; // eax@2
  UIListener *v10; // ecx@3
  HashSetData<UIListener *> *v11; // eax@3
  int v12; // edx@4
  int v13; // ebx@5
  unsigned int v14; // edx@8
  unsigned int v15; // edi@8
  int v16; // eax@9
  int v17; // ebx@9
  UIElementMessageListenResult v18; // eax@14
  int v19; // eax@17
  int v20; // eax@19
  int v21; // ebx@20
  int v22; // eax@21
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v3 = this;
  v4 = i_eStatus;
  v5 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashListeners.m_intrusiveTable,
         &result);
  v6 = (IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *)v5->m_currHashTable;
  v7 = (HashSetData<UIListener *> **)v5->m_currBucket;
  v8 = (HashSetData<UIListener *> *)v5->m_currElement;
  v3->m_iterListeners.m_iter.m_currHashTable = v6;
  v3->m_iterListeners.m_iter.m_currElement = v8;
  v3->m_iterListeners.m_iter.m_currBucket = v7;
  if ( i_eStatus == 2 )
    goto LABEL_26;
  while ( 1 )
  {
    v9 = v3->m_iterListeners.m_iter.m_currElement;
    if ( !v9 )
      break;
    v10 = v9->m_hashKey;
    v11 = v9->m_hashNext;
    v3->m_iterListeners.m_iter.m_currElement = v11;
    if ( !v11 )
    {
      v12 = (int)&v3->m_iterListeners.m_iter.m_currHashTable->m_buckets[v3->m_iterListeners.m_iter.m_currHashTable->m_numBuckets];
      while ( 1 )
      {
        v13 = (int)(v3->m_iterListeners.m_iter.m_currBucket + 1);
        v3->m_iterListeners.m_iter.m_currBucket = (HashSetData<UIListener *> **)v13;
        if ( v13 == v12 )
          break;
        if ( *(_DWORD *)v13 )
        {
          v3->m_iterListeners.m_iter.m_currElement = *(HashSetData<UIListener *> **)v13;
          break;
        }
      }
    }
    v14 = i_rMsg->tsSerialNumber.m_timestamp;
    v15 = v10->m_tsSerialNumberLastListenedTo.m_timestamp;
    if ( v15 != v14 )
    {
      v16 = v15 - v14;
      v17 = 1;
      if ( v15 < v14 )
      {
        v16 = v14 - v15;
        v17 = -1;
      }
      if ( (unsigned int)v16 > 0x7FFFFFFF )
        v17 = -v17;
      if ( v17 < 0 )
      {
        v10->m_tsSerialNumberLastListenedTo.m_timestamp = v14;
        v18 = ((int (__stdcall *)(UIElementMessageInfo *))v10->vfptr[1].__vecDelDtor)(i_rMsg);
        if ( v18 )
          i_eStatus = v18;
      }
    }
    v4 = i_eStatus;
    if ( i_eStatus == 2 )
      return i_eStatus;
  }
  if ( v4 == 2 )
    goto LABEL_26;
  v20 = ((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3);
  if ( !v20 )
  {
    if ( v4 == lrDefault
      && (unsigned __int8)v3->vfptr[25].__vecDelDtor((IInputActionCallback *)v3, (unsigned int)i_rMsg) )
      i_eStatus = 1;
    goto LABEL_26;
  }
  v21 = v20 + 120;
  if ( !(unsigned __int8)CTimestamp<unsigned long,0>::operator<(
                           (CTimestamp<unsigned long,0> *)(v20 + 120),
                           &i_rMsg->tsSerialNumber)
    || (*(_DWORD *)v21 = i_rMsg->tsSerialNumber.m_timestamp,
        v22 = ((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3),
        (v19 = (*(int (__thiscall **)(int, UIElementMessageInfo *))(*(_DWORD *)v22 + 12))(v22, i_rMsg)) == 0) )
LABEL_26:
    v19 = i_eStatus;
  return v19;
}

//----- (00462C90) --------------------------------------------------------  // acclient.c:159308
void __thiscall UIElement::Initialize(UIElement *this)
{
  int v1; // esi@1
  int v2; // edx@1
  int v3; // ST04_4@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // edi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // ebx@1
  bool v8; // al@8
  int v9; // ecx@10
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1

  v1 = (int)this;
  MediaMachine::Reset(&this->m_mediaMachine, &this->m_desc.m_media);
  v2 = *(_DWORD *)v1;
  v3 = *(_DWORD *)(v1 + 760);
  *(_DWORD *)(v1 + 1364) |= 0x20000u;
  (*(void (__thiscall **)(int, int))(v2 + 156))(v1, v3);
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v1 + 616),
         &result);
  v5 = v4->m_currElement;
  v6 = v4->m_currHashTable;
  v7 = v4->m_currBucket;
  if ( v5 )
  {
    do
    {
LABEL_2:
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v1 + 200))(v1, &v5->m_data);
      v5 = v5->m_hashNext;
    }
    while ( v5 );
    while ( 1 )
    {
      ++v7;
      if ( v7 == &v6->m_buckets[v6->m_numBuckets] )
        break;
      if ( *v7 )
      {
        v5 = *v7;
        if ( *v7 )
          goto LABEL_2;
        break;
      }
    }
  }
  v8 = *(_BYTE *)(v1 + 1348) || (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v1 + 292))(v1);
  v9 = *(_DWORD *)(v1 + 1364) >> 12;
  *(_BYTE *)(v1 + 1349) = v8;
  if ( v9 & 1 )
  {
    if ( UIElementManager::s_pInstance )
      UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 6u, v1);
  }
}

//----- (00462D80) --------------------------------------------------------  // acclient.c:159367
void __userpurge UIElement::OnSetAttribute(UIElement *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  BaseProperty *v3; // esi@1
  int v4; // edi@1
  BasePropertyDesc *v5; // eax@1
  BasePropertyValue *v6; // ecx@2
  BasePropertyValue *v7; // ecx@5
  BasePropertyValue *v8; // ecx@8
  BasePropertyValue *v9; // ecx@11
  BasePropertyValue *v10; // ecx@14
  BasePropertyValue *v11; // ecx@17
  BasePropertyValue *v12; // ecx@20
  BasePropertyValue *v13; // ecx@23
  BasePropertyValue *v14; // ecx@26
  BasePropertyValue *v15; // ecx@29
  BasePropertyValue *v16; // ecx@32
  BasePropertyValue *v17; // ecx@35
  BasePropertyValue *v18; // ecx@38
  BasePropertyValue *v19; // ecx@41
  BasePropertyValue *v20; // ecx@45
  BasePropertyValue *v21; // ecx@48
  BasePropertyValue *v22; // ecx@51
  BasePropertyValue *v23; // ecx@54
  BasePropertyValue *v24; // ecx@57
  BasePropertyValue *v25; // ecx@59
  BasePropertyValue *v26; // ecx@63
  int v27; // ecx@65
  BasePropertyValue *v28; // ecx@66
  int v29; // edx@68
  BasePropertyValue *v30; // ecx@69
  int v31; // [sp+10h] [bp-18h]@0
  BaseProperty bpY; // [sp+18h] [bp-10h]@57
  tagPOINT pt; // [sp+20h] [bp-8h]@57

  v3 = _attribute;
  v4 = (int)this;
  v5 = BaseProperty::GetPropertyName(_attribute);
  switch ( v5 )
  {
    case 0x3Bu:
      v6 = v3->m_pcPropertyValue;
      if ( v6 )
        v5 = (BasePropertyDesc *)((int (__stdcall *)(BaseProperty **))v6->vfptr[28].__vecDelDtor)(&_attribute);
      LOBYTE(v5) = (_BYTE)_attribute == 0;
      (*(void (__thiscall **)(int, BasePropertyDesc *))(*(_DWORD *)v4 + 24))(v4, v5);
      break;
    case 0x40u:
      v7 = v3->m_pcPropertyValue;
      LOBYTE(_attribute) = 0;
      if ( v7 )
        ((void (__stdcall *)(BaseProperty **))v7->vfptr[28].__vecDelDtor)(&_attribute);
      (*(void (__thiscall **)(int, BaseProperty *))(*(_DWORD *)v4 + 28))(v4, _attribute);
      break;
    case 0x4Bu:
      v8 = v3->m_pcPropertyValue;
      if ( v8 )
        ((void (__stdcall *)(BaseProperty **))v8->vfptr[28].__vecDelDtor)(&_attribute);
      UIRegion::SetTooltipOn((UIRegion *)v4, (bool)_attribute);
      break;
    case 0x44u:
      v9 = v3->m_pcPropertyValue;
      if ( v9 )
        ((void (__stdcall *)(BaseProperty **))v9->vfptr[28].__vecDelDtor)(&_attribute);
      *(_DWORD *)(v4 + 1364) ^= ((unsigned __int8)*(_DWORD *)(v4 + 1364) ^ (unsigned __int8)_attribute) & 1;
      break;
    case 0x3Au:
      v10 = v3->m_pcPropertyValue;
      if ( v10 )
        ((void (__stdcall *)(BaseProperty **))v10->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetDragable((UIElement *)v4, (bool)_attribute);
      break;
    case 0x33u:
      v11 = v3->m_pcPropertyValue;
      if ( v11 )
        ((void (__stdcall *)(BaseProperty **))v11->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetActivatable((UIElement *)v4, (bool)_attribute);
      break;
    case 0x34u:
      v12 = v3->m_pcPropertyValue;
      if ( v12 )
        ((void (__stdcall *)(BaseProperty **))v12->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetActivateOnShow((UIElement *)v4, (bool)_attribute);
      break;
    case 0x45u:
      v13 = v3->m_pcPropertyValue;
      if ( v13 )
        ((void (__stdcall *)(BaseProperty **))v13->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetSaveLocation((UIElement *)v4, (bool)_attribute);
      break;
    case 0x46u:
      v14 = v3->m_pcPropertyValue;
      if ( v14 )
        ((void (__stdcall *)(BaseProperty **))v14->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetSaveSize((UIElement *)v4, (bool)_attribute);
      break;
    case 0x41u:
      v15 = v3->m_pcPropertyValue;
      if ( v15 )
        ((void (__stdcall *)(BaseProperty **))v15->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetNotifyOnResize((UIElement *)v4, (bool)_attribute);
      break;
    case 0x42u:
      v16 = v3->m_pcPropertyValue;
      if ( v16 )
        ((void (__stdcall *)(BaseProperty **))v16->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetNotifyOnMove((UIElement *)v4, (bool)_attribute);
      break;
    case 0x37u:
      v17 = v3->m_pcPropertyValue;
      if ( v17 )
        ((void (__stdcall *)(BaseProperty **))v17->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetContextMenu((UIElement *)v4, (bool)_attribute);
      UIElement::UpdateMouseVisibility((UIElement *)v4);
      break;
    case 0x43u:
      v18 = v3->m_pcPropertyValue;
      if ( v18 )
        ((void (__stdcall *)(BaseProperty **))v18->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement::SetNotifyOnCreate((UIElement *)v4, (bool)_attribute);
      break;
    case 0x4Du:
      v19 = v3->m_pcPropertyValue;
      if ( v19 )
        ((void (__stdcall *)(BaseProperty **))v19->vfptr[34].__vecDelDtor)(&_attribute);
      UIRegion::SetAlphaBlendMod((UIRegion *)v4, *(float *)&_attribute);
      break;
    case 0x4Eu:
      BaseProperty::InqEnum(v3, (unsigned int *)(v4 + 1516));
      break;
    case 0x51u:
      v20 = v3->m_pcPropertyValue;
      LOBYTE(_attribute) = 0;
      if ( v20 )
        ((void (__stdcall *)(BaseProperty **))v20->vfptr[28].__vecDelDtor)(&_attribute);
      (*(void (__thiscall **)(int, BaseProperty *))(*(_DWORD *)v4 + 32))(v4, _attribute);
      break;
    case 0x52u:
      v21 = v3->m_pcPropertyValue;
      _attribute = 0;
      if ( v21 )
        ((void (__stdcall *)(BaseProperty **))v21->vfptr[42].__vecDelDtor)(&_attribute);
      (*(void (__thiscall **)(int, BaseProperty *))(*(_DWORD *)v4 + 36))(v4, _attribute);
      break;
    case 0xCDu:
      v22 = v3->m_pcPropertyValue;
      _attribute = (BaseProperty *)3;
      if ( v22 )
        ((void (__stdcall *)(BaseProperty **))v22->vfptr[42].__vecDelDtor)(&_attribute);
      UIElement::SetShouldOwnObject((UIElement *)v4, _attribute != 0);
      UIElement::UpdateForParentSizeChange((UIElement *)v4, a2, v4, v31);
      break;
    case 0x53u:
      v23 = v3->m_pcPropertyValue;
      LOBYTE(_attribute) = 0;
      if ( v23 )
        ((void (__stdcall *)(BaseProperty **))v23->vfptr[28].__vecDelDtor)(&_attribute);
      *(_DWORD *)(v4 + 164) |= 0x80u;
      UIRegion::MakeRootDirtyHere((UIRegion *)v4);
      break;
    case 0x56u:
      v24 = v3->m_pcPropertyValue;
      pt.x = 0;
      pt.y = 0;
      bpY.m_pcPropertyDesc = 0;
      bpY.m_pcPropertyValue = 0;
      if ( v24 )
      {
        if ( (unsigned __int8)((int (__stdcall *)(signed int, tagPOINT *))v24->vfptr[70].__vecDelDtor)(84, &pt) )
        {
          v25 = v3->m_pcPropertyValue;
          if ( v25 )
          {
            if ( (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v25->vfptr[70].__vecDelDtor)(85, &bpY) )
            {
              (*(void (__thiscall **)(int, tagPOINT *))(*(_DWORD *)v4 + 200))(v4, &pt);
              (*(void (__thiscall **)(int, BaseProperty *))(*(_DWORD *)v4 + 200))(v4, &bpY);
            }
          }
        }
      }
      BaseProperty::~BaseProperty(&bpY);
      BaseProperty::~BaseProperty((BaseProperty *)&pt);
      break;
    case 0x54u:
      v26 = v3->m_pcPropertyValue;
      if ( v26 && (unsigned __int8)((int (__stdcall *)(BaseProperty **))v26->vfptr[30].__vecDelDtor)(&_attribute) )
      {
        v27 = *(_DWORD *)(v4 + 140);
        pt.y = *(_DWORD *)(v4 + 144);
        pt.x = (int)_attribute;
        UIRegion::SetTilingOffset((UIRegion *)v4, &pt);
      }
      break;
    case 0x55u:
      v28 = v3->m_pcPropertyValue;
      if ( v28 && (unsigned __int8)((int (__stdcall *)(BaseProperty **))v28->vfptr[30].__vecDelDtor)(&_attribute) )
      {
        v29 = *(_DWORD *)(v4 + 144);
        pt.x = *(_DWORD *)(v4 + 140);
        pt.y = (int)_attribute;
        UIRegion::SetTilingOffset((UIRegion *)v4, &pt);
      }
      break;
    case 0x57u:
      v30 = v3->m_pcPropertyValue;
      if ( v30 && (unsigned __int8)((int (__stdcall *)(BaseProperty **))v30->vfptr[42].__vecDelDtor)(&_attribute) )
        UIElementManager::RegisterElementForInputAction(
          UIElementManager::s_pInstance,
          (unsigned int)_attribute,
          (UIElement *)v4);
      break;
    default:
      return;
  }
}

//----- (00463310) --------------------------------------------------------  // acclient.c:159584
void __userpurge UIElement::MouseMove(UIElement *this@<ecx>, int a2@<edi>, int _xWindow, int _yWindow)
{
  int v4; // ebp@1
  UIElement *v5; // esi@1
  int v6; // edi@7
  UIElementMessageInfo msg; // [sp+Ch] [bp-28h]@7
  int _yWindowa; // [sp+3Ch] [bp+8h]@7

  v4 = _yWindow;
  v5 = this;
  if ( (this->m_nFlags >> 19) & 1 )
  {
    UIElement::MouseResizeElement(this, _yWindow, a2, (int)this, _xWindow, _yWindow);
  }
  else if ( (this->m_nFlags >> 18) & 1 )
  {
    UIElement::MouseMoveElement(this, _xWindow, _yWindow);
  }
  if ( v5->m_mouseDownTable.m_intrusiveTable.m_numElements || (v5->m_nFlags >> 13) & 1 )
  {
    _yWindowa = v5->m_desc.m_elementID;
    v6 = v4 - UIRegion::GetScreenY0((UIRegion *)&v5->vfptr);
    msg.idElement = _yWindowa;
    msg.ptElement.x = _xWindow - UIRegion::GetScreenX0((UIRegion *)&v5->vfptr);
    msg.ptElement.y = v6;
    msg.pElement = v5;
    msg.idMessage = 30;
    msg.dwParam1 = 0;
    msg.dwParam2 = 0;
    msg.tsSerialNumber.m_timestamp = 0;
    msg.ptWindow.x = _xWindow;
    msg.ptWindow.y = v4;
    if ( UIElementManager::s_pInstance )
      UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
  }
}

//----- (004633E0) --------------------------------------------------------  // acclient.c:159622
void __thiscall UIElement::MoveTo(UIElement *this, const int _x, const int _y)
{
  UIElement *v3; // esi@1
  UIObject *v4; // edi@2
  UIRegion *v5; // ecx@3
  UIRegion *v6; // eax@6
  unsigned int v7; // ebx@6
  UIRegion *v8; // eax@6
  unsigned int v9; // eax@6
  int v10; // edi@10
  unsigned int v11; // eax@10
  int v12; // ebx@10
  UIElementManager *v13; // ecx@12
  int v14; // edx@17
  int v15; // eax@17
  int nOldScreenX; // [sp+Ch] [bp-30h]@1
  int nOldScreenY; // [sp+10h] [bp-2Ch]@1
  UIElementMessageInfo msg; // [sp+14h] [bp-28h]@17

  v3 = this;
  nOldScreenX = UIRegion::GetScreenX0((UIRegion *)&this->vfptr);
  nOldScreenY = UIRegion::GetScreenY0((UIRegion *)&v3->vfptr);
  UIRegion::MoveTo((UIRegion *)&v3->vfptr, _x, _y);
  if ( *((_BYTE *)&v3->1 + 2) & 1 )
  {
    v4 = v3->m_object;
    if ( v4 || (v5 = v3->m_parent) != 0 && (v4 = UIRegion::GetObjectA(v5)) != 0 )
    {
      if ( ((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3) )
      {
        v6 = (UIRegion *)((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3);
        v7 = UIRegion::GetScreenX0(v6);
        v8 = (UIRegion *)((int (__thiscall *)(_DWORD))v3->vfptr[13].OnAction)(v3);
        v9 = UIRegion::GetScreenY0(v8);
      }
      else
      {
        v7 = 0;
        v9 = 0;
      }
      ((void (__thiscall *)(UIObject *, int, int, _DWORD, _DWORD))v4->vfptr[3].__vecDelDtor)(
        v4,
        v7 + v3->m_box.m_x0,
        v9 + v3->m_box.m_y0,
        v4->m_nVirtualWidth,
        v4->m_nVirtualHeight);
    }
  }
  else
  {
    UIElement::UpdateSurfaceBox(v3, 1);
    UIRegion::ForceUpdate((UIRegion *)&v3->vfptr, 1u);
  }
  v10 = UIRegion::GetScreenX0((UIRegion *)&v3->vfptr);
  v11 = UIRegion::GetScreenY0((UIRegion *)&v3->vfptr);
  v12 = v11;
  if ( nOldScreenX != v10 || nOldScreenY != v11 )
  {
    v13 = UIElementManager::s_pInstance;
    if ( (v3->m_nFlags >> 4) & 1 && UIElementManager::s_pInstance )
    {
      UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 7u, 0);
      v13 = UIElementManager::s_pInstance;
    }
    if ( (v3->m_nFlags >> 10) & 1 || v3->m_mouseDownTable.m_intrusiveTable.m_numElements )
    {
      v14 = v3->m_box.m_x0;
      msg.idElement = v3->m_desc.m_elementID;
      v15 = v3->m_box.m_y0;
      msg.pElement = v3;
      msg.idMessage = 37;
      msg.dwParam1 = 0;
      msg.dwParam2 = 0;
      msg.tsSerialNumber.m_timestamp = 0;
      msg.ptWindow.x = v10;
      msg.ptWindow.y = v12;
      msg.ptElement.x = v14;
      msg.ptElement.y = v15;
      if ( v13 )
        UIElementManager::BroadcastElementMessage(v13, &msg);
    }
    ((void (__thiscall *)(UIElement *))v3->vfptr[23].__vecDelDtor)(v3);
  }
}

//----- (00463570) --------------------------------------------------------  // acclient.c:159708
bool __thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::contains(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, UIRegion *const *val)
{
  HashList<UIRegion *,UIRegion *,1>::HashListData *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_hash.m_buckets[(((unsigned int)*val >> 8) | (unsigned __int64)((unsigned int)*val << 24))
                            % this->m_hash.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey == (UIRegion *)*val )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (004635B0) --------------------------------------------------------  // acclient.c:159731
UIElement *__thiscall UIElement::GetLastChildElement(UIElement *this)
{
  int v1; // eax@1
  DLListData *v2; // ecx@2
  UIElement *result; // eax@6

  v1 = 0;
  if ( this->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v2 = this->m_children.m_ihlIntrusive.m_list.tail_;
    if ( v2 )
      v1 = (int)&v2[-1];
    else
      v1 = 0;
  }
  if ( v1 )
    result = *(UIElement **)(v1 + 16);
  else
    result = 0;
  return result;
}

//----- (00463620) --------------------------------------------------------  // acclient.c:159776
char __thiscall HashTable<unsigned long,BaseProperty,1>::find(HashTable<unsigned long,BaseProperty,1> *this, const unsigned int *_key, BaseProperty *_retval)
{
  HashTableData<unsigned long,BaseProperty> *v3; // eax@1
  char result; // al@4

  v3 = this->m_intrusiveTable.m_buckets[*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != *_key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    BaseProperty::operator=(_retval, (int)&v3->m_data);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00463670) --------------------------------------------------------  // acclient.c:159804
char __thiscall IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::grow(IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::resize_internal(v2, *v3);
}

//----- (004636C0) --------------------------------------------------------  // acclient.c:159822
bool __thiscall UIRegion::IsMouseDown(UIRegion *this, unsigned int _button)
{
  HashSetData<unsigned long> *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_mouseDownTable.m_intrusiveTable.m_buckets[_button % this->m_mouseDownTable.m_intrusiveTable.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey == _button )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (00463700) --------------------------------------------------------  // acclient.c:159844
void __thiscall UIElement::OnVisibilityChanged(UIElement *this, bool i_bVisibleNow)
{
  UIElementManager *v2; // ebp@1
  UIElement *v3; // esi@1
  IInputActionCallbackVtbl *v4; // edx@8
  int i; // edi@9
  UIElement *v6; // ecx@10
  int v7; // edi@12
  CInputManager *v8; // edi@20
  int v9; // ebx@20
  int v10; // edi@20
  Box2D *v11; // eax@20
  int v12; // [sp+0h] [bp-24h]@0
  UIObject *pcNewObject; // [sp+10h] [bp-14h]@8
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+14h] [bp-10h]@9

  v2 = UIElementManager::s_pInstance;
  v3 = this;
  if ( i_bVisibleNow )
  {
    if ( (this->m_nFlags >> 14) & 1 )
    {
      v4 = this->vfptr;
      pcNewObject = 0;
      ((void (__stdcall *)(UIObject **))v4[23].OnLoseFocus)(&pcNewObject);
      v3->vfptr[23].OnAction((IInputActionCallback *)v3, (InputEvent *)pcNewObject);
      if ( UIElement::UpdateObjectScale(v3) )
      {
        HashList<UIRegion *,UIRegion *,1>::begin(&v3->m_children, &iter);
        for ( i = (signed int)iter.m_iter.m_pData; i; i = v7 - 8 )
        {
          v6 = *(UIElement **)(i + 16);
          if ( v6 )
            UIElement::UpdateForParentSizeChange(v6, 0, i, v12);
          v7 = *(_DWORD *)(i + 8);
          if ( !v7 )
            break;
        }
      }
    }
    if ( (v3->m_nFlags >> 3) & 1 )
      ((void (__thiscall *)(UIElement *))v3->vfptr[21].__vecDelDtor)(v3);
    i_bVisibleNow = 0;
    if ( UIElement::GetAttribute_Bool(v3, 0x35u, &i_bVisibleNow) && i_bVisibleNow )
      ((void (__thiscall *)(UIElement *))v3->vfptr[21].OnLoseFocus)(v3);
  }
  else
  {
    UIElementManager::UnregisterActivatable(UIElementManager::s_pInstance, this);
    if ( (v3->m_nFlags >> 20) & 1 )
    {
      ((void (__thiscall *)(UIElement *))v3->vfptr[21].OnAction)(v3);
      if ( (v3->m_nFlags >> 21) & 1 )
        UIElementManager::ActivateNext(v2, 0);
    }
    if ( (v3->m_nFlags >> 14) & 1 )
      v3->vfptr[23].OnAction((IInputActionCallback *)v3, 0);
  }
  if ( ICIDM::s_cidm )
  {
    if ( (v8 = ICIDM::s_cidm,
          v9 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)(),
          v10 = v8->vfptr->GetMouseX((ICIDM *)v8),
          v11 = UIRegion::GetScreenClipBox((UIRegion *)&v3->vfptr, (Box2D *)&iter),
          v10 >= v11->m_x0)
      && v10 <= v11->m_x1
      && v9 >= v11->m_y0
      && v9 <= v11->m_y1
      || *((_BYTE *)&v3->0 + 164) & 1 )
      v2->m_bPerformMouseHitTest = 1;
  }
}

//----- (00463870) --------------------------------------------------------  // acclient.c:159918
void __thiscall UIElement::PostInit(UIElement *this)
{
  int v1; // esi@1
  DLListData *v2; // ecx@2
  int v3; // esi@8

  v1 = 0;
  if ( this->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v2 = this->m_children.m_ihlIntrusive.m_list.head_;
    if ( v2 )
      v1 = (int)&v2[-1];
    else
      v1 = 0;
  }
  for ( ; v1; v1 = v3 - 8 )
  {
    if ( *(_DWORD *)v1 )
      (*(void (**)(void))(**(_DWORD **)v1 + 192))();
    v3 = *(_DWORD *)(v1 + 8);
    if ( !v3 )
      break;
  }
}

//----- (004638D0) --------------------------------------------------------  // acclient.c:159944
char __thiscall UIElement::InqProperty(UIElement *this, const unsigned int _name, BaseProperty *_property)
{
  BaseProperty *v3; // ebp@1
  const unsigned int v4; // edi@1
  UIElement *v5; // esi@1
  char result; // al@2
  StateDesc *v7; // ecx@3
  bool v8; // zf@5

  v3 = _property;
  v4 = _name;
  v5 = this;
  if ( HashTable<unsigned long,BaseProperty,1>::find(
         (HashTable<unsigned long,BaseProperty,1> *)&this->m_instanceProperties.m_hashProperties.vfptr,
         &_name,
         _property)
    || (v7 = v5->m_curStateDesc) != 0 && StateDesc::InqProperty(v7, v4, v3) )
  {
    result = 1;
  }
  else
  {
    v8 = StateDesc::InqProperty((StateDesc *)&v5->m_desc.vfptr, v4, v3) == 0;
    result = 1;
    if ( v8 )
      result = 0;
  }
  return result;
}

//----- (00463940) --------------------------------------------------------  // acclient.c:159975
void __thiscall UIElement::MouseUp(UIElement *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  UIElement *v4; // esi@1
  HashSetData<unsigned long> *i; // eax@1
  int v6; // ebp@4
  int v7; // edi@4
  int v8; // ecx@4
  signed int v9; // eax@4
  UIElementManager *v10; // ecx@4
  bool bWasDown; // [sp+7h] [bp-29h]@4
  UIElementMessageInfo msg; // [sp+8h] [bp-28h]@4
  unsigned int _yWindowa; // [sp+38h] [bp+8h]@4

  v4 = this;
  for ( i = v4->m_mouseDownTable.m_intrusiveTable.m_buckets[_button % v4->m_mouseDownTable.m_intrusiveTable.m_numBuckets];
        i;
        i = i->m_hashNext )
  {
    if ( i->m_hashKey == _button )
      break;
  }
  v6 = _yWindow;
  bWasDown = i != 0;
  UIRegion::MouseUp((UIRegion *)&this->vfptr, _xWindow, _yWindow, _button);
  _yWindowa = v4->m_desc.m_elementID;
  v7 = v6 - UIRegion::GetScreenY0((UIRegion *)&v4->vfptr);
  v8 = _xWindow - UIRegion::GetScreenX0((UIRegion *)&v4->vfptr);
  v9 = _button;
  msg.ptElement.y = v7;
  msg.idElement = _yWindowa;
  msg.ptElement.x = v8;
  v10 = UIElementManager::s_pInstance;
  msg.ptWindow.y = v6;
  msg.ptWindow.x = _xWindow;
  msg.pElement = v4;
  msg.idMessage = 29;
  msg.dwParam1 = _button;
  msg.dwParam2 = 0;
  msg.tsSerialNumber.m_timestamp = 0;
  if ( UIElementManager::s_pInstance )
  {
    UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
    v9 = msg.dwParam1;
    v10 = UIElementManager::s_pInstance;
  }
  if ( *((_BYTE *)&v4->0 + 164) & 1 && bWasDown )
  {
    if ( v9 == 10 )
    {
      v9 = 7;
    }
    else if ( v9 == 11 )
    {
      v9 = 8;
    }
    else
    {
      if ( v9 != 12 )
        goto LABEL_16;
      v9 = 9;
    }
    if ( (v4->m_nFlags >> 23) & 1 )
    {
      msg.idMessage = 26;
      goto LABEL_17;
    }
LABEL_16:
    msg.idMessage = 25;
    msg.dwParam1 = v9;
LABEL_17:
    if ( v10 )
      UIElementManager::BroadcastElementMessage(v10, &msg);
  }
}

//----- (00463A70) --------------------------------------------------------  // acclient.c:160051
UIElement *__thiscall UIElement::GetChild(UIElement *this, unsigned int _ID)
{
  char *v2; // edx@1
  unsigned int v3; // esi@1
  UIElement *result; // eax@1
  int v5; // ecx@1
  int v6; // ecx@2
  int v7; // edx@6
  int v8; // ecx@8

  v2 = (char *)&this->m_children;
  v3 = this->m_children.m_ihlIntrusive.m_hash.m_numElements;
  result = 0;
  v5 = 0;
  if ( v3 )
  {
    v6 = *((_DWORD *)v2 + 28);
    if ( v6 )
      v5 = v6 - 8;
    else
      v5 = 0;
  }
  if ( v5 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)(v5 + 16);
      if ( v7 )
      {
        if ( *(_DWORD *)(v7 + 740) == _ID )
          break;
      }
      v8 = *(_DWORD *)(v5 + 8);
      if ( v8 )
      {
        v5 = v8 - 8;
        if ( v5 )
          continue;
      }
      return result;
    }
    result = *(UIElement **)(v5 + 16);
  }
  return result;
}

//----- (00463AD0) --------------------------------------------------------  // acclient.c:160098
UIElement *__thiscall UIElement::GetChildRecursive(UIElement *this, unsigned int _ID)
{
  UIElement *v2; // edi@1
  UIElement *result; // eax@1
  UIElement *v4; // ebp@1
  int v5; // esi@2
  DLListData *v6; // ecx@3
  UIElement *v7; // ecx@7
  int v8; // esi@9

  v2 = this;
  result = UIElement::GetChild(this, _ID);
  v4 = result;
  if ( !result )
  {
    v5 = 0;
    if ( v2->m_children.m_ihlIntrusive.m_hash.m_numElements )
    {
      v6 = v2->m_children.m_ihlIntrusive.m_list.head_;
      if ( v6 )
        v5 = (int)&v6[-1];
      else
        v5 = 0;
    }
    if ( v5 )
    {
      while ( 1 )
      {
        v7 = *(UIElement **)(v5 + 16);
        if ( v7 )
        {
          result = UIElement::GetChildRecursive(v7, _ID);
          if ( result )
            break;
        }
        v8 = *(_DWORD *)(v5 + 8);
        if ( v8 )
        {
          v5 = v8 - 8;
          if ( v5 )
            continue;
        }
        goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      result = v4;
    }
  }
  return result;
}

//----- (00463B50) --------------------------------------------------------  // acclient.c:160153
void __thiscall UIElement::SetMediaImage(UIElement *this, IDClass<_tagDataID,32,0> _imageID, unsigned int _drawMode)
{
  UIElement *v3; // ebx@1
  MD_Data_Image *v4; // eax@1
  int v5; // eax@2
  MediaDesc *v6; // edi@2
  int v7; // eax@3
  unsigned int v8; // eax@4

  v3 = this;
  v4 = (MD_Data_Image *)operator new(0x10u);
  if ( v4 )
  {
    MD_Data_Image::MD_Data_Image(v4);
    v6 = (MediaDesc *)v5;
    if ( v5 )
    {
      *(_DWORD *)(v5 + 12) = _drawMode;
      *(_DWORD *)(v5 + 8) = _imageID.id;
      MediaMachine::Cleanup(&v3->m_mediaMachine);
      v7 = v3->m_mediaMachine.m_array.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v3->m_mediaMachine.m_array.m_num < v7
        || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1),
            SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v3->m_mediaMachine.m_array, v8)) )
        v3->m_mediaMachine.m_array.m_data[v3->m_mediaMachine.m_array.m_num++] = v6;
      v3->m_mediaMachine.m_curIndex = 0;
      MediaMachine::Update(&v3->m_mediaMachine);
    }
  }
}

//----- (00463BE0) --------------------------------------------------------  // acclient.c:160185
void __thiscall UIElement::SetMediaImageForState(UIElement *this, IDClass<_tagDataID,32,0> _imageDID, unsigned int _drawMode, unsigned int _stateID)
{
  UIElement *v4; // esi@1
  StateDesc *v5; // eax@1

  v4 = this;
  v5 = ElementDesc::AccessStateDesc(&this->m_desc, _stateID);
  if ( v5 )
  {
    StateDesc::SetMediaImage(v5, _imageDID, _drawMode);
    if ( v4->m_state == _stateID )
      UIElement::SetMediaImage(v4, _imageDID, _drawMode);
  }
}

//----- (00463C30) --------------------------------------------------------  // acclient.c:160201
void __userpurge UIElement::ResizeTo(UIElement *this@<ecx>, int a2@<edi>, const int _width, const int _height)
{
  UIElement *v4; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v5; // eax@1
  int v6; // ebx@1
  int v7; // ebp@1
  UIObject *v8; // edi@15
  UIRegion *v9; // ecx@16
  ReferenceCountTemplate<1048576,1>Vtbl *v10; // ebp@23
  int v11; // ST0C_4@23
  int v12; // eax@23
  unsigned int v13; // edi@29
  int v14; // ebp@29
  int v15; // eax@29
  int v16; // edi@31
  DLListData *v17; // edi@32
  UIElement *v18; // ecx@36
  int v19; // edi@38
  int v20; // eax@40
  int v21; // [sp-4h] [bp-54h]@15
  int nMaxHeight; // [sp+Ch] [bp-44h]@1
  int nMinHeight; // [sp+10h] [bp-40h]@4
  int nMaxWidth; // [sp+14h] [bp-3Ch]@7
  int nMinWidth; // [sp+18h] [bp-38h]@10
  int nOldWidth; // [sp+1Ch] [bp-34h]@1
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+20h] [bp-30h]@1
  UIElementMessageInfo msg; // [sp+28h] [bp-28h]@29

  v4 = this;
  nOldWidth = UIRegion::GetWidth((UIRegion *)&this->vfptr);
  v5 = (HashList<UIRegion *,UIRegion *,1>::HashListData *)UIRegion::GetHeight((UIRegion *)&v4->vfptr);
  v6 = _width;
  v7 = _height;
  iter.m_iter.m_pData = v5;
  if ( UIElement::GetAttribute_Int(v4, 0x3Cu, &nMaxHeight) && v7 > nMaxHeight )
    v7 = nMaxHeight;
  if ( UIElement::GetAttribute_Int(v4, 0x3Eu, &nMinHeight) && v7 < nMinHeight )
    v7 = nMinHeight;
  if ( UIElement::GetAttribute_Int(v4, 0x3Du, &nMaxWidth) && _width > nMaxWidth )
    v6 = nMaxWidth;
  if ( UIElement::GetAttribute_Int(v4, 0x3Fu, &nMinWidth) && v6 < nMinWidth )
    v6 = nMinWidth;
  if ( nOldWidth != v6 || (_DWORD)iter.m_iter.m_pData != v7 )
  {
    v21 = a2;
    UIRegion::ResizeTo((UIRegion *)&v4->vfptr, v6, v7);
    v8 = v4->m_object;
    if ( !v8 )
    {
      v9 = v4->m_parent;
      if ( v9 )
        v8 = UIRegion::GetObjectA(v9);
      else
        v8 = 0;
    }
    if ( *((_BYTE *)&v4->1 + 2) & 1 )
    {
      if ( v8 )
      {
        _width = 3;
        UIElement::GetCurrentUIObjectMode(v4, (unsigned int *)&_width);
        if ( _width == 3 )
        {
          ((void (__thiscall *)(UIObject *, int, int))v8->vfptr[4].__vecDelDtor)(v8, v6, v7);
          UIRegion::ForceUpdate((UIRegion *)&v4->vfptr, 1u);
        }
        v6 = v8->m_nVirtualY;
        v10 = v8->vfptr;
        _height = v8->m_nVirtualX;
        v11 = UIRegion::GetHeight((UIRegion *)&v4->vfptr);
        v12 = UIRegion::GetWidth((UIRegion *)&v4->vfptr);
        ((void (__thiscall *)(UIObject *, const int, int, int, int))v10[3].__vecDelDtor)(v8, _height, v6, v12, v11);
        UIElement::UpdateObjectScale(v4);
      }
    }
    else
    {
      UIElement::UpdateSurfaceBox(v4, 0);
      UIRegion::ForceUpdate((UIRegion *)&v4->vfptr, 1u);
    }
    if ( (v4->m_nFlags >> 5) & 1 && UIElementManager::s_pInstance )
      UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 7u, 0);
    if ( (v4->m_nFlags >> 9) & 1 )
    {
      v13 = v4->m_desc.m_elementID;
      v6 = UIRegion::GetHeight((UIRegion *)&v4->vfptr);
      v14 = UIRegion::GetWidth((UIRegion *)&v4->vfptr);
      _width = UIRegion::GetHeight((UIRegion *)&v4->vfptr);
      v15 = UIRegion::GetWidth((UIRegion *)&v4->vfptr);
      msg.ptWindow.y = _width;
      msg.idElement = v13;
      msg.pElement = v4;
      msg.idMessage = 36;
      msg.dwParam1 = 0;
      msg.dwParam2 = 0;
      msg.tsSerialNumber.m_timestamp = 0;
      msg.ptWindow.x = v15;
      msg.ptElement.x = v14;
      msg.ptElement.y = v6;
      if ( UIElementManager::s_pInstance )
        UIElementManager::BroadcastElementMessage(UIElementManager::s_pInstance, &msg);
    }
    v16 = 0;
    if ( v4->m_children.m_ihlIntrusive.m_hash.m_numElements )
    {
      v17 = v4->m_children.m_ihlIntrusive.m_list.head_;
      if ( v17 )
        v16 = (int)&v17[-1];
      else
        v16 = 0;
    }
    for ( iter.m_iter.m_pHashList = &v4->m_children.m_ihlIntrusive; v16; v16 = v19 - 8 )
    {
      v18 = *(UIElement **)(v16 + 16);
      if ( v18 )
        UIElement::UpdateForParentSizeChange(v18, v6, v16, v21);
      v19 = *(_DWORD *)(v16 + 8);
      if ( !v19 )
        break;
    }
    v20 = ((int (__thiscall *)(UIElement *))v4->vfptr[13].OnAction)(v4);
    if ( v20 )
      (*(void (__thiscall **)(int, UIElement *))(*(_DWORD *)v20 + 244))(v20, v4);
  }
}
// 463C30: could not find valid save-restore pair for edi

//----- (00463E80) --------------------------------------------------------  // acclient.c:160329
void __usercall UIElement::UpdateForScreenPositionChange(UIElement *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  UIElement *v3; // esi@1
  UIObject *v4; // edi@2
  UIRegion *v5; // ecx@3
  UIRegion *v6; // eax@6
  unsigned int v7; // ebx@6
  UIRegion *v8; // eax@6
  unsigned int v9; // eax@6
  unsigned int v10; // ST0C_4@8
  unsigned int v11; // ST08_4@8
  int v12; // eax@9
  DLListData *v13; // eax@10
  int i; // esi@13
  int v15; // ecx@14
  int v16; // esi@16
  int v17; // [sp+4h] [bp-10h]@2

  v3 = this;
  if ( *((_BYTE *)&this->1 + 2) & 1 )
  {
    v17 = a3;
    v4 = this->m_object;
    if ( v4 || (v5 = this->m_parent) != 0 && (v4 = UIRegion::GetObjectA(v5)) != 0 )
    {
      if ( ((int (__thiscall *)(UIElement *, int, int))v3->vfptr[13].OnAction)(v3, a2, v17) )
      {
        v6 = (UIRegion *)((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3);
        v7 = UIRegion::GetScreenX0(v6);
        v8 = (UIRegion *)((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3);
        v9 = UIRegion::GetScreenY0(v8);
      }
      else
      {
        v7 = 0;
        v9 = 0;
      }
      v10 = v4->m_nVirtualHeight;
      v11 = v4->m_nVirtualWidth;
      ((void (__thiscall *)(UIObject *, int, int))v4->vfptr[3].__vecDelDtor)(
        v4,
        v7 + v3->m_box.m_x0,
        v9 + v3->m_box.m_y0);
    }
  }
  v12 = 0;
  if ( v3->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v13 = v3->m_children.m_ihlIntrusive.m_list.head_;
    if ( v13 )
      v12 = (int)&v13[-1];
    else
      v12 = 0;
  }
  for ( i = v12; i; i = v16 - 8 )
  {
    v15 = *(_DWORD *)(i + 16);
    if ( v15 )
      (*(void (**)(void))(*(_DWORD *)v15 + 276))();
    v16 = *(_DWORD *)(i + 8);
    if ( !v16 )
      break;
  }
}
// 463E80: could not find valid save-restore pair for edi

//----- (00463F60) --------------------------------------------------------  // acclient.c:160396
void __thiscall UIElement::UpdateForParentVisibilityChange(UIElement *this, int i_bHeirarchyVisible)
{
  UIElement *v2; // edi@1
  int v3; // esi@1
  DLListData *v4; // ecx@2
  int v5; // ecx@6
  int v6; // esi@9

  v2 = this;
  ((void (__stdcall *)(int))this->vfptr[25].OnAction)(i_bHeirarchyVisible);
  v3 = 0;
  if ( v2->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v4 = v2->m_children.m_ihlIntrusive.m_list.head_;
    if ( v4 )
      v3 = (int)&v4[-1];
    else
      v3 = 0;
  }
  for ( ; v3; v3 = v6 - 8 )
  {
    v5 = *(_DWORD *)(v3 + 16);
    if ( v5 && (*(_DWORD *)(v5 + 164) >> 1) & 1 )
      (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 248))(i_bHeirarchyVisible);
    v6 = *(_DWORD *)(v3 + 8);
    if ( !v6 )
      break;
  }
}

//----- (00463FE0) --------------------------------------------------------  // acclient.c:160427
UIElement *__thiscall UIElement::GetFirstChildElement(UIElement *this)
{
  DLListData *v1; // eax@2
  int v2; // eax@3
  UIElement *result; // eax@4

  if ( this->m_children.m_ihlIntrusive.m_hash.m_numElements
    && (v1 = this->m_children.m_ihlIntrusive.m_list.head_) != 0
    && (v2 = (int)&v1[-1]) != 0 )
    result = *(UIElement **)(v2 + 16);
  else
    result = 0;
  return result;
}

//----- (00464010) --------------------------------------------------------  // acclient.c:160443
void __thiscall IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>(IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>Vtbl *)IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashSetData<UIListener *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashSetData<UIListener *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79BF18: using guessed type int (__thiscall *IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable[3])(void *, char);

//----- (004640A0) --------------------------------------------------------  // acclient.c:160476
char __thiscall IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::resize_internal(IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *v3; // esi@1
  char result; // al@2
  HashSetData<UIListener *> *v5; // edi@3
  int v6; // ecx@4
  HashSetData<UIListener *> **v7; // eax@5
  int v8; // eax@6
  HashSetData<UIListener *> **v9; // ebx@7
  HashSetData<UIListener *> *v10; // ecx@7
  HashSetData<UIListener *> *v11; // eax@9
  HashSetData<UIListener *> *v12; // edx@10
  HashSetData<UIListener *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashSetData<UIListener *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashSetData<UIListener *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashSetData<UIListener *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashSetData<UIListener *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::resize_internal(v3, *v15);
        }
        v16 = (unsigned int)v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashSetData<UIListener *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashSetData<UIListener *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004641E0) --------------------------------------------------------  // acclient.c:160592
char __thiscall IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<UIRegion *,UIRegion *,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<UIRegion *,UIRegion *,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<UIRegion *,UIRegion *,1>::HashListData **v8; // edi@7
  HashList<UIRegion *,UIRegion *,1>::HashListData *v9; // ecx@7
  HashList<UIRegion *,UIRegion *,1>::HashListData *v10; // eax@9
  HashList<UIRegion *,UIRegion *,1>::HashListData *v11; // edx@10
  HashList<UIRegion *,UIRegion *,1>::HashListData *v12; // eax@17
  HashList<UIRegion *,UIRegion *,1>::HashListData *v13; // edi@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashList<UIRegion *,UIRegion *,1>::HashListData **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashList<UIRegion *,UIRegion *,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<UIRegion *,UIRegion *,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add_internal(v2, v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004642B0) --------------------------------------------------------  // acclient.c:160687
bool __thiscall PropertyCollection::ContainsProperty(PropertyCollection *this, const unsigned int _propertyName)
{
  HashTableData<unsigned long,BaseProperty> *v2; // eax@1
  bool result; // al@4

  v2 = this->m_hashProperties.m_intrusiveTable.m_buckets[_propertyName
                                                       % this->m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != _propertyName )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = &v2->m_data != 0;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (00464300) --------------------------------------------------------  // acclient.c:160711
char __thiscall UIElement::ContainsProperty(UIElement *this, const unsigned int _name)
{
  UIElement *v2; // esi@1
  char result; // al@2
  StateDesc *v4; // ecx@3
  bool v5; // zf@5

  v2 = this;
  if ( PropertyCollection::ContainsProperty(&this->m_instanceProperties, _name)
    || (v4 = v2->m_curStateDesc) != 0 && StateDesc::ContainsProperty(v4, _name) )
  {
    result = 1;
  }
  else
  {
    v5 = StateDesc::ContainsProperty((StateDesc *)&v2->m_desc.vfptr, _name) == 0;
    result = 1;
    if ( v5 )
      result = 0;
  }
  return result;
}

//----- (00464360) --------------------------------------------------------  // acclient.c:160735
UIElement *__thiscall UIElement::GetNextChildElement(UIElement *this, UIElement *i_pPrevChild)
{
  HashList<UIRegion *,UIRegion *,1>::HashListData *i; // eax@1
  DLListData *v3; // eax@5
  int v4; // eax@6
  UIElement *result; // eax@7

  for ( i = this->m_children.m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)i_pPrevChild >> 8) | (unsigned __int64)((_DWORD)i_pPrevChild << 24))
                                                           % this->m_children.m_ihlIntrusive.m_hash.m_numBuckets];
        i;
        i = i->m_hashNext )
  {
    if ( (UIElement *)i->m_hashKey == i_pPrevChild )
      break;
  }
  if ( i && (v3 = i->dllist_next) != 0 && (v4 = (int)&v3[-1]) != 0 )
    result = *(UIElement **)(v4 + 16);
  else
    result = 0;
  return result;
}

//----- (004643C0) --------------------------------------------------------  // acclient.c:160758
UIElement *__thiscall UIElement::GetPrevChildElement(UIElement *this, UIElement *i_pNextChild)
{
  HashList<UIRegion *,UIRegion *,1>::HashListData *i; // eax@1
  DLListData *v3; // eax@5
  int v4; // eax@6
  UIElement *result; // eax@7

  for ( i = this->m_children.m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)i_pNextChild >> 8) | (unsigned __int64)((_DWORD)i_pNextChild << 24))
                                                           % this->m_children.m_ihlIntrusive.m_hash.m_numBuckets];
        i;
        i = i->m_hashNext )
  {
    if ( (UIElement *)i->m_hashKey == i_pNextChild )
      break;
  }
  if ( i && (v3 = i->dllist_prev) != 0 && (v4 = (int)&v3[-1]) != 0 )
    result = *(UIElement **)(v4 + 16);
  else
    result = 0;
  return result;
}

//----- (00464420) --------------------------------------------------------  // acclient.c:160781
char __thiscall IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::add(IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *this, HashSetData<UIListener *> *data)
{
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashSetData<UIListener *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashSetData<UIListener *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[(unsigned int)data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::grow(this);
    v5 = (unsigned int)data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashSetData<UIListener *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashSetData<UIListener *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (004644A0) --------------------------------------------------------  // acclient.c:160825
HashList<UIRegion *,UIRegion *,1>::HashListData *__thiscall IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::remove(IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, UIRegion *const *key)
{
  int v2; // edx@1
  HashList<UIRegion *,UIRegion *,1>::HashListData **v3; // eax@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v4; // esi@1
  int v5; // edx@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *result; // eax@4
  _BYTE v7[12]; // ST00_12@6

  v2 = (((unsigned int)*key >> 8) | (unsigned __int64)((unsigned int)*key << 24)) % this->m_numBuckets;
  v3 = this->m_buckets;
  v4 = v3[v2];
  v5 = (int)&v3[v2];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != (UIRegion *)*key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    *(_DWORD *)v7 = this;
    *(_QWORD *)&v7[4] = __PAIR__((unsigned int)v4, v5);
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
      (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)this,
      *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v7);
    result = v4;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00464510) --------------------------------------------------------  // acclient.c:160864
char __thiscall IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::grow(IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::resize_internal(v2, *v3);
}

//----- (00464560) --------------------------------------------------------  // acclient.c:160882
UIElement *__thiscall UIElement::FindRelative(UIElement *this, unsigned int _relativeID)
{
  unsigned int v2; // ebp@1
  UIElement *v3; // esi@1
  UIElement *v4; // ebx@1
  int v5; // eax@2
  UIElement *v6; // ecx@2
  signed int v7; // edi@2
  int v8; // eax@7
  int v9; // eax@8
  UIElement *v10; // esi@9
  UIElement *result; // eax@22
  unsigned int _relativeIDa; // [sp+14h] [bp+4h]@2

  v2 = _relativeID;
  v3 = this;
  v4 = UIElement::GetChildRecursive(this, _relativeID);
  if ( v4 )
  {
LABEL_22:
    result = v4;
  }
  else
  {
    v5 = ((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3);
    v6 = v3;
    v7 = v5;
    _relativeIDa = (unsigned int)v3;
    while ( v6->m_desc.m_elementID != v2 )
    {
      if ( !v7 )
        goto LABEL_22;
      if ( *(_DWORD *)(v7 + 288) )
      {
        v8 = *(_DWORD *)(v7 + 292);
        if ( v8 )
        {
          v9 = v8 - 8;
          if ( v9 )
          {
            v10 = *(UIElement **)(v9 + 16);
            if ( v10 )
            {
              while ( !v4 )
              {
                if ( v10->m_desc.m_elementID == v2 )
                {
                  v4 = v10;
                }
                else if ( v10 != v6 )
                {
                  v4 = UIElement::GetChildRecursive(v10, v2);
                }
                v10 = UIElement::GetNextChildElement((UIElement *)v7, v10);
                if ( !v10 )
                  break;
                v6 = (UIElement *)_relativeIDa;
              }
            }
          }
        }
      }
      _relativeIDa = v7;
      v7 = (*(_DWORD *)(v7 + 1364) >> 21) & 1 ? 0 : (*(int (__thiscall **)(signed int))(*(_DWORD *)v7 + 160))(v7);
      if ( v4 )
        goto LABEL_22;
      v6 = (UIElement *)_relativeIDa;
    }
    result = v6;
  }
  return result;
}

//----- (00464640) --------------------------------------------------------  // acclient.c:160956
char __thiscall HashSet<UIListener *>::add(HashSet<UIListener *> *this, UIListener *const *_key)
{
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1> *v2; // esi@1
  HashSetData<UIListener *> *v3; // eax@1
  void *v4; // eax@4
  char result; // al@5

  v2 = &this->m_intrusiveTable;
  v3 = this->m_intrusiveTable.m_buckets[(unsigned int)*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != (UIListener *)*_key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    v4 = operator new(8u);
    if ( v4 )
    {
      *(_DWORD *)v4 = *_key;
      *((_DWORD *)v4 + 1) = 0;
      IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::add(v2, (HashSetData<UIListener *> *)v4);
      result = 1;
    }
    else
    {
      IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::add(v2, 0);
      result = 1;
    }
  }
  return result;
}

//----- (004646B0) --------------------------------------------------------  // acclient.c:160998
HashSet<UIListener *> *__thiscall HashSet<UIListener *>::vector_deleting_destructor(HashSet<UIListener *> *this, unsigned int a2)
{
  HashSet<UIListener *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<UIListener *>Vtbl *)HashSet<UIListener *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79BF18: using guessed type int (__thiscall *IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable[3])(void *, char);
// 79BF1C: using guessed type int (__thiscall *HashSet<UIListener *>::vftable[2])(void *, char);

//----- (00464710) --------------------------------------------------------  // acclient.c:161024
HashList<UIRegion *,UIRegion *,1>::HashListData *__thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::remove(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, UIRegion *const *val)
{
  IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // edi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v3; // esi@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[(((unsigned int)*val >> 8) | (unsigned __int64)((unsigned int)*val << 24))
                          % v2->m_hash.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey != (UIRegion *)*val )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return 0;
    }
    if ( v3 )
    {
      DLListBase::Remove(&this->m_list, (DLListData *)&v3->dllist_next);
      IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::remove(&v2->m_hash, val);
    }
  }
  return v3;
}

//----- (00464780) --------------------------------------------------------  // acclient.c:161050
void __thiscall IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add_internal(IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *data)
{
  IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
  int v3; // edx@3
  HashList<UIRegion *,UIRegion *,1>::HashListData **v4; // eax@3
  int v5; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::grow(this);
  v3 = (((unsigned int)data->m_hashKey >> 8) | (unsigned __int64)((unsigned int)data->m_hashKey << 24))
     % v2->m_numBuckets;
  v4 = v2->m_buckets;
  data->m_hashNext = v4[v3];
  v4[v3] = data;
  v5 = (int)&v4[v3];
  if ( (HashList<UIRegion *,UIRegion *,1>::HashListData **)v5 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = (HashList<UIRegion *,UIRegion *,1>::HashListData **)v5;
  ++v2->m_numElements;
}

//----- (004647D0) --------------------------------------------------------  // acclient.c:161072
void __userpurge UIElement::UIElement(UIElement *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement *v4; // esi@1
  int v5; // ebp@1
  int v6; // eax@2
  int v7; // edi@2

  v4 = this;
  UIRegion::UIRegion((UIRegion *)&this->vfptr, 0, 0, 0, 0, 0);
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement::vftable;
  v4->m_itemDragged = 0;
  v4->m_pFocusElement = 0;
  MediaMachine::MediaMachine(&v4->m_mediaMachine);
  v4->m_layout = 0;
  ElementDesc::ElementDesc(&v4->m_desc, _full_desc);
  v4->m_state = 0;
  v4->m_curStateDesc = 0;
  PropertyCollection::PropertyCollection(&v4->m_instanceProperties);
  v4->m_currentBorder = 0;
  UILocationData::UILocationData(&v4->m_defaultLocation);
  StringInfo::StringInfo(&v4->m_TTText);
  v4->m_bShouldBeMouseVisible = 0;
  v4->m_bIsMouseVisible = 0;
  v4->m_cursorHotX = 0;
  v4->m_cursorHotY = 0;
  v4->m_cursorDID.id = INVALID_DID_53.id;
  v4->m_nFlags = 0;
  v4->m_eClampGameView = 0;
  v4->m_surfaceBox.m_x0 = 0;
  v4->m_surfaceBox.m_y0 = 0;
  v4->m_surfaceBox.m_x1 = 0;
  v4->m_surfaceBox.m_y1 = 0;
  v4->m_hashListeners.vfptr = (HashSet<UIListener *>Vtbl *)HashSet<UIListener *>::vftable;
  IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>(
    &v4->m_hashListeners.m_intrusiveTable,
    0x17u);
  v4->m_iterListeners.m_iter.m_currHashTable = 0;
  v4->m_iterListeners.m_iter.m_currBucket = 0;
  v4->m_iterListeners.m_iter.m_currElement = 0;
  v4->m_idInputMap = 0;
  v4->m_layout = _layout;
  ((void (*)(void))_layout->vfptr->AddRef)();
  UIElement::MoveTo(v4, v4->m_desc.m_x, v4->m_desc.m_y);
  UIElement::ResizeTo(v4, a2, v4->m_desc.m_width, v4->m_desc.m_height);
  v5 = v4->m_desc.m_zLevel;
  if ( v5 != v4->m_zlevel )
  {
    v6 = ((int (__thiscall *)(UIElement *))v4->vfptr[13].OnAction)(v4);
    v7 = v6;
    v4->m_zlevel = v5;
    if ( v6 )
    {
      (*(void (__thiscall **)(int, UIElement *))(*(_DWORD *)v6 + 112))(v6, v4);
      (*(void (__thiscall **)(int, UIElement *))(*(_DWORD *)v7 + 108))(v7, v4);
    }
  }
  v4->m_dragDropCallback = (bool (__cdecl *)(UIElement *, UIElement *))DBObj::InitLoad;
  v4->m_mediaMachine.m_owner = v4;
}
// 79BF1C: using guessed type int (__thiscall *HashSet<UIListener *>::vftable[2])(void *, char);
// 79BF20: using guessed type int (__thiscall *UIElement::vftable)(void *, char);

//----- (00464950) --------------------------------------------------------  // acclient.c:161135
void __thiscall UIRegion::SetShouldEraseBackground(UIRegion *this, bool i_bErase)
{
  *((_DWORD *)this + 41) ^= ((unsigned __int8)*((_DWORD *)this + 41) ^ (unsigned __int8)(8 * i_bErase)) & 8;
}

//----- (00464970) --------------------------------------------------------  // acclient.c:161141
unsigned int __thiscall UIElement::GetActivatable(UIElement *this)
{
  return (this->m_nFlags >> 2) & 1;
}

//----- (00464980) --------------------------------------------------------  // acclient.c:161147
BOOL __thiscall UIElement::HasCursor(UIElement *this)
{
  return this->m_cursorDID.id != INVALID_DID_53.id;
}

//----- (004649A0) --------------------------------------------------------  // acclient.c:161153
void __thiscall UIElement::RegisterForElementMessages(UIElement *this, UIListener *i_pListener)
{
  UIElement *v2; // esi@1

  v2 = this;
  HashSet<UIListener *>::add(&this->m_hashListeners, &i_pListener);
  UIListener::OnRegisteredWithElement(i_pListener, v2);
}

//----- (004649D0) --------------------------------------------------------  // acclient.c:161163
void __thiscall UIElement::UnregisterForElementMessages(UIElement *this, UIListener *i_pListener)
{
  UIElement *v2; // esi@1
  HashSetData<UIListener *> *v3; // eax@1
  UIListener *v4; // edi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v5; // eax@4

  v2 = this;
  v3 = this->m_iterListeners.m_iter.m_currElement;
  v4 = i_pListener;
  if ( v3 && v3->m_hashKey == i_pListener )
    HashSetIterator<UIListener *>::operator++((HashIterator<unsigned long,unsigned long,0> *)&this->m_iterListeners);
  v5 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&v2->m_hashListeners.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&i_pListener);
  if ( v5 )
    operator delete(v5);
  UIListener::OnUnregisteredWithElement(v4, v2);
}

//----- (00464A20) --------------------------------------------------------  // acclient.c:161184
void __thiscall HashList<UIRegion *,UIRegion *,1>::flush(HashList<UIRegion *,UIRegion *,1> *this)
{
  HashList<UIRegion *,UIRegion *,1> *v1; // edi@1
  DLListData *v2; // eax@3
  DLListData *v3; // ecx@4
  DLListData *v4; // ecx@6
  bool v5; // zf@6
  DLListData *v6; // ecx@10
  UIRegion *const *v7; // esi@13

  v1 = this;
  while ( v1->m_ihlIntrusive.m_hash.m_numElements > 0 )
  {
    v2 = v1->m_ihlIntrusive.m_list.head_;
    if ( !v2 )
      goto LABEL_19;
    v3 = v2->dllist_prev;
    if ( v3 )
    {
      v3->dllist_next = v2->dllist_next;
    }
    else
    {
      v4 = v2->dllist_next;
      v5 = v2->dllist_next == 0;
      v1->m_ihlIntrusive.m_list.head_ = v2->dllist_next;
      if ( !v5 )
        v4->dllist_prev = 0;
    }
    if ( v2->dllist_next )
    {
      v2->dllist_next->dllist_prev = v2->dllist_prev;
    }
    else
    {
      v6 = v1->m_ihlIntrusive.m_list.tail_->dllist_prev;
      v1->m_ihlIntrusive.m_list.tail_ = v6;
      if ( v6 )
        v6->dllist_next = 0;
    }
    v2->dllist_next = 0;
    v2->dllist_prev = 0;
    if ( v2 )
      v7 = (UIRegion *const *)&v2[-1];
    else
LABEL_19:
      v7 = 0;
    IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::remove(
      &v1->m_ihlIntrusive.m_hash,
      v7);
    if ( v7 )
      operator delete((void *)v7);
  }
}

//----- (00464AA0) --------------------------------------------------------  // acclient.c:161240
char __thiscall IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add(IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *data)
{
  HashList<UIRegion *,UIRegion *,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_buckets[(((unsigned int)data->m_hashKey >> 8) | (unsigned __int64)((unsigned int)data->m_hashKey << 24))
                     % this->m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != data->m_hashKey )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add_internal(this, data);
    result = 1;
  }
  return result;
}

//----- (00464AF0) --------------------------------------------------------  // acclient.c:161269
char __thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::place_at_tail(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *pMoving)
{
  IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v3; // eax@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[(((unsigned int)pMoving->m_hashKey >> 8) | (unsigned __int64)((unsigned int)pMoving->m_hashKey << 24))
                          % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != pMoving->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add(&this->m_hash, pMoving);
  DLListBase::InsertAfter(&v2->m_list, (DLListData *)&pMoving->dllist_next, v2->m_list.tail_);
  return 1;
}

//----- (00464B60) --------------------------------------------------------  // acclient.c:161295
char __thiscall UIElement::SetProperty(UIElement *this, BaseProperty *_property)
{
  BaseProperty *v2; // edi@1
  UIElement *v3; // esi@1
  char v4; // bl@1

  v2 = _property;
  v3 = this;
  _property = (BaseProperty *)BaseProperty::GetPropertyName(_property);
  v4 = HashTable<unsigned long,BaseProperty,1>::set(
         (HashTable<unsigned long,BaseProperty,1> *)&v3->m_instanceProperties.m_hashProperties.vfptr,
         (const unsigned int *)&_property,
         v2);
  if ( v4 )
    ((void (__thiscall *)(UIElement *, BaseProperty *))v3->vfptr[16].OnLoseFocus)(v3, v2);
  return v4;
}

//----- (00464BA0) --------------------------------------------------------  // acclient.c:161314
void __thiscall UIElement::DeleteChildren(UIElement *this)
{
  HashList<UIRegion *,UIRegion *,1> *v1; // edi@1
  int v2; // esi@1
  DLListData *v3; // eax@2
  int v4; // ecx@6
  int v5; // esi@6

  v1 = &this->m_children;
  v2 = 0;
  if ( this->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v3 = this->m_children.m_ihlIntrusive.m_list.head_;
    if ( v3 )
      v2 = (int)&v3[-1];
    else
      v2 = 0;
  }
  while ( v2 )
  {
    v4 = *(_DWORD *)v2;
    v5 = *(_DWORD *)(v2 + 8);
    if ( v5 )
      v2 = v5 - 8;
    else
      v2 = 0;
    if ( v4 )
      (**(void (__stdcall ***)(_DWORD))v4)(1);
  }
  HashList<UIRegion *,UIRegion *,1>::flush(v1);
}

//----- (00464C00) --------------------------------------------------------  // acclient.c:161347
char __thiscall HashList<UIRegion *,UIRegion *,1>::move_to_tail(HashList<UIRegion *,UIRegion *,1> *this, UIRegion *const *keyToMove)
{
  HashList<UIRegion *,UIRegion *,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)*keyToMove >> 8) | (unsigned __int64)((unsigned int)*keyToMove << 24))
                                           % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey != (UIRegion *)*keyToMove )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::place_at_tail(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (00464C50) --------------------------------------------------------  // acclient.c:161373
char __thiscall IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::push_tail(IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *this, HashList<UIRegion *,UIRegion *,1>::HashListData *val)
{
  IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v3; // eax@1
  char result; // al@4

  v2 = this;
  v3 = v2->m_hash.m_buckets[(((unsigned int)val->m_hashKey >> 8) | (unsigned __int64)((unsigned int)val->m_hashKey << 24))
                          % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::add(&this->m_hash, val);
    DLListBase::InsertAfter(&v2->m_list, (DLListData *)&val->dllist_next, v2->m_list.tail_);
    result = 1;
  }
  return result;
}

//----- (00464CB0) --------------------------------------------------------  // acclient.c:161405
PropertyCollection *__thiscall PropertyCollection::vector_deleting_destructor(PropertyCollection *this, unsigned int a2)
{
  PropertyCollection *v2; // esi@1

  v2 = this;
  PropertyCollection::~PropertyCollection(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00464CD0) --------------------------------------------------------  // acclient.c:161417
void __thiscall UIElement::~UIElement(UIElement *this)
{
  UIElement *v1; // edi@1
  UIElementManager *v2; // esi@1
  unsigned int v3; // ebx@5
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@7
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@7
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // ebp@7
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // ecx@8
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // eax@12
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // edx@13
  LayoutDesc *v10; // ecx@20
  void *v11; // eax@22
  void *v12; // [sp+Ch] [bp-20h]@8
  UIListener *pListener; // [sp+10h] [bp-1Ch]@8
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *iter; // [sp+14h] [bp-18h]@7
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+20h] [bp-Ch]@7

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement::vftable;
  v2 = UIElementManager::s_pInstance;
  UIElement::DeleteChildren(this);
  if ( (v1->m_nFlags >> 18) & 1 )
    v1->m_nFlags &= 0xFFFBFFFF;
  if ( (v1->m_nFlags >> 19) & 1 )
    UIElement::StopResizing(v1);
  v3 = 0;
  if ( v2 )
    UIElementManager::DeletingElement(v2, v1);
  UIElement::SetUIObject(v1, 0);
  UIElement::SetParent(v1, 0);
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_hashListeners.m_intrusiveTable,
         &result);
  v5 = v4->m_currElement;
  v6 = v4->m_currBucket;
  iter = v4->m_currHashTable;
  if ( v5 )
  {
    do
    {
      v3 = (unsigned int)&v5->m_hashNext->m_hashKey;
      pListener = (UIListener *)v5->m_hashKey;
      v12 = v5;
      v7 = v6;
      if ( !v3 )
      {
        while ( 1 )
        {
          ++v7;
          if ( v7 == &iter->m_buckets[iter->m_numBuckets] )
            break;
          if ( *v7 )
          {
            v3 = (unsigned int)*v7;
            break;
          }
        }
      }
      v8 = *v6;
      if ( *v6 == v5 )
        goto LABEL_27;
      do
      {
        v9 = v8;
        v8 = v8->m_hashNext;
      }
      while ( v8 != v5 );
      if ( v9 )
        v9->m_hashNext = v8->m_hashNext;
      else
LABEL_27:
        *v6 = v8->m_hashNext;
      --iter->m_numElements;
      v5 = (HashTableData<unsigned long,HeritageGroup_CG> *)v3;
      v6 = v7;
      if ( v12 )
        operator delete(v12);
      UIListener::OnUnregisteredWithElement(pListener, v1);
    }
    while ( v3 );
  }
  v10 = v1->m_layout;
  if ( v10 != (LayoutDesc *)v3 )
  {
    ((void (*)(void))v10->vfptr->Release)();
    v1->m_layout = (LayoutDesc *)v3;
  }
  v1->m_hashListeners.vfptr = (HashSet<UIListener *>Vtbl *)HashSet<UIListener *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashListeners.m_intrusiveTable);
  v11 = v1->m_hashListeners.m_intrusiveTable.m_buckets;
  v1->m_hashListeners.m_intrusiveTable.vfptr = (IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>Vtbl *)IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable;
  if ( v11 != v1->m_hashListeners.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v11);
  v1->m_hashListeners.m_intrusiveTable.m_buckets = (HashSetData<UIListener *> **)v3;
  v1->m_hashListeners.m_intrusiveTable.m_firstInterestingBucket = (HashSetData<UIListener *> **)v3;
  v1->m_hashListeners.m_intrusiveTable.m_numBuckets = v3;
  v1->m_hashListeners.m_intrusiveTable.m_numElements = v3;
  StringInfo::~StringInfo(&v1->m_TTText);
  PropertyCollection::~PropertyCollection(&v1->m_instanceProperties);
  ElementDesc::~ElementDesc(&v1->m_desc);
  MediaMachine::~MediaMachine(&v1->m_mediaMachine);
  UIRegion::~UIRegion((UIRegion *)&v1->vfptr);
}
// 79BF18: using guessed type int (__thiscall *IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable[3])(void *, char);
// 79BF1C: using guessed type int (__thiscall *HashSet<UIListener *>::vftable[2])(void *, char);
// 79BF20: using guessed type int (__thiscall *UIElement::vftable)(void *, char);

//----- (00464E70) --------------------------------------------------------  // acclient.c:161526
char __thiscall UIElement::SetState(UIElement *this, unsigned int _state)
{
  UIElement *v2; // esi@1
  unsigned int v3; // edi@1
  StateDesc *v4; // eax@1
  int v5; // esi@8
  DLListData *v6; // ecx@9
  int v7; // esi@15
  void *v8; // esi@18
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@22
  HashTableData<unsigned long,HeritageGroup_CG> *v10; // esi@22
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v11; // ebx@22
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // edi@22
  HashTableData<unsigned long,BaseProperty> *v13; // eax@23
  BasePropertyDesc *v14; // ecx@29
  unsigned int v15; // edx@29
  BasePropertyValue *v16; // ecx@33
  unsigned int v17; // edx@33
  HashTableData<unsigned long,BaseProperty> **v18; // ecx@40
  HashTableData<unsigned long,BaseProperty> **v19; // eax@40
  HashTableData<unsigned long,BaseProperty> *v20; // esi@43
  HashTableData<unsigned long,BaseProperty> **v21; // edi@48
  HashTableData<unsigned long,BaseProperty> *v22; // eax@49
  int v23; // eax@61
  UIElement *v25; // [sp+14h] [bp-10Ch]@1
  BaseProperty cNewValue; // [sp+18h] [bp-108h]@1
  StateDesc *pcNewStateDesc; // [sp+20h] [bp-100h]@1
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+24h] [bp-FCh]@12
  PropertyCollection cNewProperties; // [sp+30h] [bp-F0h]@18
  PropertyCollection cOldProperties; // [sp+A8h] [bp-78h]@18

  v2 = this;
  v3 = _state;
  v25 = this;
  cNewValue.m_pcPropertyDesc = (BasePropertyDesc *)this->m_curStateDesc;
  v4 = ElementDesc::AccessStateDesc(&this->m_desc, _state);
  pcNewStateDesc = v4;
  if ( !v4 )
    v3 = 0;
  if ( v3 == v2->m_state )
    return 1;
  v2->m_curStateDesc = v4;
  v2->m_state = v3;
  if ( v4 )
  {
    if ( !v4->m_bPassToChildren )
      goto LABEL_18;
  }
  else if ( !v2->m_desc.m_bPassToChildren )
  {
    goto LABEL_18;
  }
  v5 = 0;
  if ( v25->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v6 = v25->m_children.m_ihlIntrusive.m_list.head_;
    if ( v6 )
      v5 = (int)&v6[-1];
    else
      v5 = 0;
  }
  for ( iter.m_iter.m_pHashList = &v25->m_children.m_ihlIntrusive; v5; v5 = v7 - 8 )
  {
    if ( *(_DWORD *)v5 )
      (*(void (__stdcall **)(unsigned int))(**(_DWORD **)v5 + 156))(v3);
    v7 = *(_DWORD *)(v5 + 8);
    if ( !v7 )
      break;
  }
  v2 = v25;
LABEL_18:
  cOldProperties.vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &cOldProperties.m_hashProperties.m_intrusiveTable,
    0);
  v8 = &v2->m_desc.m_properties;
  cOldProperties.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  PropertyCollection::operator=(&cOldProperties, v8);
  cNewProperties.vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &cNewProperties.m_hashProperties.m_intrusiveTable,
    0);
  cNewProperties.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  PropertyCollection::operator=(&cNewProperties, v8);
  if ( (_DWORD)cNewValue.m_pcPropertyDesc )
    PropertyCollection::UpdateCollection(
      &cOldProperties,
      (PropertyCollection *)&cNewValue.m_pcPropertyDesc->m_minValue,
      1);
  if ( pcNewStateDesc )
    PropertyCollection::UpdateCollection(&cNewProperties, &pcNewStateDesc->m_properties, 1);
  PropertyCollection::UpdateCollection(&cOldProperties, &v25->m_instanceProperties, 1);
  PropertyCollection::UpdateCollection(&cNewProperties, &v25->m_instanceProperties, 1);
  v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&cOldProperties.m_hashProperties.m_intrusiveTable,
         (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
  v10 = v9->m_currElement;
  v11 = v9->m_currHashTable;
  v12 = v9->m_currBucket;
  if ( !v10 )
    goto LABEL_40;
  do
  {
LABEL_23:
    cNewValue.m_pcPropertyDesc = 0;
    cNewValue.m_pcPropertyValue = 0;
    v13 = cNewProperties.m_hashProperties.m_intrusiveTable.m_buckets[v10->m_hashKey
                                                                   % cNewProperties.m_hashProperties.m_intrusiveTable.m_numBuckets];
    if ( !v13 )
      goto LABEL_26;
    while ( v13->m_hashKey != v10->m_hashKey )
    {
      v13 = v13->m_hashNext;
      if ( !v13 )
        goto LABEL_26;
    }
    if ( !v13 )
    {
LABEL_26:
      BaseProperty::SetPropertyName(&cNewValue, v10->m_hashKey);
LABEL_27:
      ((void (__stdcall *)(BaseProperty *))v25->vfptr[16].OnLoseFocus)(&cNewValue);
      goto LABEL_28;
    }
    BaseProperty::operator=(&cNewValue, (int)&v13->m_data);
    if ( !BaseProperty::Compare(&cNewValue, (BaseProperty *)&v10->m_data) )
      goto LABEL_27;
LABEL_28:
    if ( (_DWORD)cNewValue.m_pcPropertyDesc )
    {
      v14 = cNewValue.m_pcPropertyDesc;
      v15 = cNewValue.m_pcPropertyDesc->m_cRef - 1;
      cNewValue.m_pcPropertyDesc->m_cRef = v15;
      if ( !v15 )
        ((void (__stdcall *)(signed int))v14->vfptr->__vecDelDtor)(1);
      cNewValue.m_pcPropertyDesc = 0;
    }
    if ( cNewValue.m_pcPropertyValue )
    {
      v16 = cNewValue.m_pcPropertyValue;
      v17 = cNewValue.m_pcPropertyValue->m_cRef - 1;
      cNewValue.m_pcPropertyValue->m_cRef = v17;
      if ( !v17 )
        ((void (__stdcall *)(signed int))v16->vfptr->__vecDelDtor)(1);
      cNewValue.m_pcPropertyValue = 0;
    }
    v10 = v10->m_hashNext;
  }
  while ( v10 );
  while ( 1 )
  {
    ++v12;
    if ( v12 == &v11->m_buckets[v11->m_numBuckets] )
      break;
    if ( *v12 )
    {
      v10 = *v12;
      if ( *v12 )
        goto LABEL_23;
      break;
    }
  }
LABEL_40:
  v18 = &cNewProperties.m_hashProperties.m_intrusiveTable.m_buckets[cNewProperties.m_hashProperties.m_intrusiveTable.m_numBuckets];
  v19 = cNewProperties.m_hashProperties.m_intrusiveTable.m_firstInterestingBucket;
  if ( cNewProperties.m_hashProperties.m_intrusiveTable.m_firstInterestingBucket == v18 )
  {
LABEL_43:
    v19 = 0;
    v20 = 0;
  }
  else
  {
    while ( !*v19 )
    {
      ++v19;
      cNewProperties.m_hashProperties.m_intrusiveTable.m_firstInterestingBucket = v19;
      if ( v19 == v18 )
        goto LABEL_43;
    }
    v20 = *v19;
  }
  v21 = v19;
  if ( v20 )
  {
    do
    {
LABEL_49:
      v22 = cOldProperties.m_hashProperties.m_intrusiveTable.m_buckets[v20->m_hashKey
                                                                     % cOldProperties.m_hashProperties.m_intrusiveTable.m_numBuckets];
      if ( !v22 )
        goto LABEL_55;
      while ( v22->m_hashKey != v20->m_hashKey )
      {
        v22 = v22->m_hashNext;
        if ( !v22 )
          goto LABEL_55;
      }
      if ( !v22 || v22 == (HashTableData<unsigned long,BaseProperty> *)-8 )
LABEL_55:
        ((void (__stdcall *)(int))v25->vfptr[16].OnLoseFocus)(&v20->m_data);
      v20 = v20->m_hashNext;
    }
    while ( v20 );
    while ( 1 )
    {
      ++v21;
      if ( v21 == &cNewProperties.m_hashProperties.m_intrusiveTable.m_buckets[cNewProperties.m_hashProperties.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v21 )
      {
        v20 = *v21;
        if ( *v21 )
          goto LABEL_49;
        break;
      }
    }
  }
  if ( pcNewStateDesc )
    v23 = (int)&pcNewStateDesc->m_media;
  else
    v23 = (int)&v25->m_desc.m_media;
  if ( *(_DWORD *)(v23 + 8) )
    MediaMachine::Reset(&v25->m_mediaMachine, (SmartArray<MediaDesc *,1> *)v23);
  PropertyCollection::~PropertyCollection(&cNewProperties);
  PropertyCollection::~PropertyCollection(&cOldProperties);
  return 1;
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);

//----- (00465200) --------------------------------------------------------  // acclient.c:161758
void __thiscall UIElement::MatchElement(UIElement *this, UIElement *_elem)
{
  UIElement *v2; // ebp@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@1
  Graphic *v7; // eax@7
  RenderSurface *v8; // esi@8
  Graphic *v9; // eax@9
  Graphic *v10; // eax@10
  int v11; // edi@13
  DLListData *v12; // ecx@14
  UIElement *v13; // esi@18
  UIElement *v14; // eax@19
  int v15; // eax@23
  UIElementManager *v16; // ebx@25
  int v17; // eax@26
  DLListData *v18; // eax@27
  int v19; // edi@30
  int v20; // esi@31
  LayoutDesc *v21; // eax@33
  HashSet<UIElement *>Vtbl *v22; // eax@34
  int v23; // eax@36
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+10h] [bp-84h]@1
  PropertyCollection collection; // [sp+1Ch] [bp-78h]@1

  v2 = this;
  collection.vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &collection.m_hashProperties.m_intrusiveTable,
    0);
  collection.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  PropertyCollection::operator=(&collection, &_elem->m_instanceProperties);
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&collection.m_hashProperties.m_intrusiveTable,
         (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
  v4 = v3->m_currElement;
  v5 = v3->m_currHashTable;
  v6 = v3->m_currBucket;
  if ( v4 )
  {
    do
    {
LABEL_2:
      ((void (__thiscall *)(UIElement *, int))v2->vfptr[17].OnLoseFocus)(v2, &v4->m_data);
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
        break;
      if ( *v6 )
      {
        v4 = *v6;
        if ( *v6 )
          goto LABEL_2;
        break;
      }
    }
  }
  MediaMachine::Reset(&v2->m_mediaMachine, &_elem->m_mediaMachine.m_array);
  if ( !v2->m_mediaMachine.m_array.m_num )
  {
    v7 = _elem->m_image;
    if ( v7 )
    {
      v8 = v7->m_image;
      if ( v8 )
      {
        UIRegion::ClearImage((UIRegion *)&v2->vfptr);
        v9 = (Graphic *)operator new(0xCu);
        if ( v9 )
          Graphic::Graphic(v9, v8);
        else
          v10 = 0;
        UIRegion::SetImage((UIRegion *)&v2->vfptr, v10);
      }
    }
  }
  v11 = 0;
  if ( v2->m_children.m_ihlIntrusive.m_hash.m_numElements )
  {
    v12 = v2->m_children.m_ihlIntrusive.m_list.head_;
    if ( v12 )
      v11 = (int)&v12[-1];
    else
      v11 = 0;
  }
  iter.m_iter.m_pHashList = &v2->m_children.m_ihlIntrusive;
  if ( v11 )
  {
    do
    {
      v13 = *(UIElement **)(v11 + 16);
      if ( v13 )
      {
        v14 = UIElement::GetChild(_elem, v13->m_desc.m_elementID);
        if ( v14 )
        {
          v13->vfptr[20].__vecDelDtor((IInputActionCallback *)v13, (unsigned int)v14);
        }
        else if ( UIElementManager::s_pInstance )
        {
          UIElementManager::AddElementToDeleteQueue(UIElementManager::s_pInstance, v13);
        }
      }
      v15 = *(_DWORD *)(v11 + 8);
      if ( !v15 )
        break;
      v11 = v15 - 8;
    }
    while ( v15 != 8 );
  }
  v16 = UIElementManager::s_pInstance;
  if ( UIElementManager::s_pInstance )
  {
    v17 = 0;
    if ( _elem->m_children.m_ihlIntrusive.m_hash.m_numElements )
    {
      v18 = _elem->m_children.m_ihlIntrusive.m_list.head_;
      if ( v18 )
        v17 = (int)&v18[-1];
      else
        v17 = 0;
    }
    v19 = v17;
    iter.m_iter.m_pHashList = &_elem->m_children.m_ihlIntrusive;
    if ( v17 )
    {
      do
      {
        v20 = *(_DWORD *)(v19 + 16);
        if ( v20 )
        {
          if ( !UIElement::GetChild(v2, *(_DWORD *)(v20 + 740)) )
          {
            v21 = *(LayoutDesc **)(v20 + 568);
            if ( v21 )
            {
              v22 = UIElementManager::CreateChildElement(v16, v2, v21, (ElementDesc *)(v20 + 572));
              if ( v22 )
                (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, _DWORD))v22->__vecDelDtor + 60))(v22, v20);
            }
          }
        }
        v23 = *(_DWORD *)(v19 + 8);
        if ( !v23 )
          break;
        v19 = v23 - 8;
      }
      while ( v23 != 8 );
    }
    v2->vfptr[13].__vecDelDtor((IInputActionCallback *)v2, _elem->m_state);
  }
  PropertyCollection::~PropertyCollection(&collection);
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);

//----- (00465420) --------------------------------------------------------  // acclient.c:161921
char __thiscall HashList<UIRegion *,UIRegion *,1>::push_tail(HashList<UIRegion *,UIRegion *,1> *this, UIRegion *const *key, UIRegion *const *val)
{
  HashList<UIRegion *,UIRegion *,1> *v3; // edi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  HashList<UIRegion *,UIRegion *,1>::HashListData *v6; // esi@5
  char result; // al@7
  char v8; // bl@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[(((unsigned int)*key >> 8) | (unsigned __int64)((unsigned int)*key << 24))
                                         % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != (UIRegion *)*key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<UIRegion *,UIRegion *,1>::move_to_tail(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x14u);
    if ( v5 )
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = *val;
      v6 = (HashList<UIRegion *,UIRegion *,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v8 = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::push_tail(
           &v3->m_ihlIntrusive,
           v6);
    if ( !v8 )
    {
      if ( v6 )
        operator delete(v6);
    }
    result = v8;
  }
  return result;
}

//----- (004654C0) --------------------------------------------------------  // acclient.c:161976
UIElement *__thiscall UIElement::vector_deleting_destructor(UIElement *this, unsigned int a2)
{
  UIElement *v2; // esi@1

  v2 = this;
  UIElement::~UIElement(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004654E0) --------------------------------------------------------  // acclient.c:161988
void __thiscall UIElement::BringChildToTop(UIElement *this, UIElement *i_pChild)
{
  HashList<UIRegion *,UIRegion *,1> *v2; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v3; // eax@1

  v2 = &this->m_children;
  v3 = IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::remove(
         &this->m_children.m_ihlIntrusive,
         (UIRegion *const *)&i_pChild);
  if ( v3 )
  {
    operator delete(v3);
    HashList<UIRegion *,UIRegion *,1>::push_tail(v2, (UIRegion *const *)&i_pChild, (UIRegion *const *)&i_pChild);
  }
}

//----- (006EB2F0) --------------------------------------------------------  // acclient.c:767023
int _E73_61()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_8, "Display.Resolution");
  return atexit(_E74_45);
}

//----- (006EB310) --------------------------------------------------------  // acclient.c:767030
int _E76_31()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_8, "Display.FullScreen");
  return atexit(_E77_59);
}

//----- (006EB330) --------------------------------------------------------  // acclient.c:767037
int _E79_31()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_8, "Display.RefreshRate");
  return atexit(_E80_32);
}

//----- (006EB350) --------------------------------------------------------  // acclient.c:767044
int _E82_21()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_8, "Display.SyncToRefresh");
  return atexit(_E83_21);
}

//----- (006EB370) --------------------------------------------------------  // acclient.c:767051
void _E85_16()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_38, PFID_A8R8G8B8);
}

//----- (006EB380) --------------------------------------------------------  // acclient.c:767057
int _E103_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_29, "None");
  return atexit(_E104_34);
}

//----- (006EB3A0) --------------------------------------------------------  // acclient.c:767064
int _E106_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_29, "Speed");
  return atexit(_E107_66);
}

//----- (006EB3C0) --------------------------------------------------------  // acclient.c:767071
int _E109_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_29, "Noise");
  return atexit(sub_75D9B0);
}

//----- (006EB3E0) --------------------------------------------------------  // acclient.c:767078
int _E112_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_29, "Sine");
  return atexit(_E113_45);
}

//----- (006EB400) --------------------------------------------------------  // acclient.c:767085
int _E115_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_29, "Square");
  return atexit(_E116_37);
}

//----- (006EB420) --------------------------------------------------------  // acclient.c:767092
int _E118_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_29, "Bounce");
  return atexit(_E119_67);
}

//----- (006EB440) --------------------------------------------------------  // acclient.c:767099
int _E121_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_29, "Perlin");
  return atexit(_E122_54);
}

//----- (006EB460) --------------------------------------------------------  // acclient.c:767106
int _E124_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_29, "Fractal");
  return atexit(_E125_29);
}

//----- (006EB480) --------------------------------------------------------  // acclient.c:767113
int _E127_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_29, "FrameLoop");
  return atexit(_E128_30);
}

//----- (006EB4A0) --------------------------------------------------------  // acclient.c:767120
int _E130_15()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_3, "Misc.TooltipEnable");
  return atexit(_E131_26);
}

//----- (006EB4C0) --------------------------------------------------------  // acclient.c:767127
int _E133_14()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_3, "Misc.TooltipDelay");
  return atexit(_E134_25);
}

//----- (006EB4E0) --------------------------------------------------------  // acclient.c:767134
int _E1_53()
{
  return atexit(_E2_53);
}

//----- (0075D890) --------------------------------------------------------  // acclient.c:885761
void __cdecl _E74_45()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D8C0) --------------------------------------------------------  // acclient.c:885774
void __cdecl _E77_59()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D8F0) --------------------------------------------------------  // acclient.c:885787
void __cdecl _E80_32()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D920) --------------------------------------------------------  // acclient.c:885800
void __cdecl _E83_21()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D950) --------------------------------------------------------  // acclient.c:885813
void __cdecl _E104_34()
{
  char *v0; // esi@1

  v0 = &waveform_None_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D980) --------------------------------------------------------  // acclient.c:885826
void __cdecl _E107_66()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D9B0) --------------------------------------------------------  // acclient.c:885839
void __cdecl sub_75D9B0()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D9E0) --------------------------------------------------------  // acclient.c:885852
void __cdecl _E113_45()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DA10) --------------------------------------------------------  // acclient.c:885865
void __cdecl _E116_37()
{
  char *v0; // esi@1

  v0 = &waveform_Square_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DA40) --------------------------------------------------------  // acclient.c:885878
void __cdecl _E119_67()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DA70) --------------------------------------------------------  // acclient.c:885891
void __cdecl _E122_54()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DAA0) --------------------------------------------------------  // acclient.c:885904
void __cdecl _E125_29()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DAD0) --------------------------------------------------------  // acclient.c:885917
void __cdecl _E128_30()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_29.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_29.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DB00) --------------------------------------------------------  // acclient.c:885930
void __cdecl _E131_26()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DB30) --------------------------------------------------------  // acclient.c:885943
void __cdecl _E134_25()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

