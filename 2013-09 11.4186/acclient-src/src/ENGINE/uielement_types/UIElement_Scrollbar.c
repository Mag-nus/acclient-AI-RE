/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Scrollbar
   Object     : ENGINE\uielement_types\UIElement_Scrollbar.obj
   Functions  : 52
   Addresses  : 0046FFF0 - 0075E850 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046FFF0) --------------------------------------------------------  // acclient.c:172895
void __userpurge UIElement_Scrollbar::UIElement_Scrollbar(UIElement_Scrollbar *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Scrollbar *v4; // esi@1

  v4 = this;
  UIElement_Button::UIElement_Button((UIElement_Button *)&this->vfptr, a2, _layout, _full_desc);
  v4->m_pWidget = 0;
  LODWORD(v4->m_tAnimStartTime) = 0;
  HIDWORD(v4->m_tAnimStartTime) = 0;
  LODWORD(v4->m_tAnimEndTime) = 0;
  HIDWORD(v4->m_tAnimEndTime) = 0;
  LODWORD(v4->m_fAnimStartPos) = 0;
  LODWORD(v4->m_fAnimEndPos) = 0;
  v4->m_nMouseWidgetXOffset = 0;
  v4->m_nMouseWidgetYOffset = 0;
  v4->m_eIncrementButtonID = 0;
  v4->m_eDecrementButtonID = 0;
  v4->m_bitField = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Scrollbar::vftable;
  v4->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  v4->m_nNextPageTime = INVALID_TIME_8;
}
// 79D0E8: using guessed type int (__thiscall *UIElement_Scrollbar::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00470080) --------------------------------------------------------  // acclient.c:172921
UIElement_Scrollbar *__thiscall UIElement_Scrollbar::DynamicCast(UIElement_Scrollbar *this, unsigned int i_eType)
{
  UIElement_Scrollbar *result; // eax@1

  result = this;
  if ( i_eType != 11 && i_eType != 1 && i_eType != 12 )
    result = (UIElement_Scrollbar *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (004700B0) --------------------------------------------------------  // acclient.c:172932
void __usercall UIElement_Scrollbar::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Scrollbar *v3; // eax@1

  v3 = (UIElement_Scrollbar *)operator new(0x780u);
  if ( v3 )
    UIElement_Scrollbar::UIElement_Scrollbar(v3, a1, _layout, _full_desc);
}

//----- (004700E0) --------------------------------------------------------  // acclient.c:172942
bool __thiscall UIElement_Scrollbar::RegisterInputMaps(UIElement_Scrollbar *this, int i_nPriority)
{
  UIElement_Scrollbar *v2; // esi@1
  bool result; // al@2
  char v4; // bl@3

  v2 = this;
  if ( ICIDM::s_cidm )
  {
    v4 = UIElement_Text::RegisterInputMaps((UIElement_Text *)&this->vfptr, i_nPriority);
    result = v4 | ((int (__stdcall *)(signed int, UIElement_Scrollbar *, int))ICIDM::s_cidm->vfptr->RegisterInputMap)(
                    10,
                    v2,
                    i_nPriority);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00470120) --------------------------------------------------------  // acclient.c:172965
bool __thiscall UIElement_Scrollbar::UnregisterInputMaps(UIElement_Scrollbar *this)
{
  UIElement_Scrollbar *v1; // esi@1
  bool result; // al@2
  char v3; // bl@3

  v1 = this;
  if ( ICIDM::s_cidm )
  {
    v3 = UIElement_Text::UnregisterInputMaps((UIElement_Text *)&this->vfptr);
    result = v3 | ((int (__stdcall *)(signed int, UIElement_Scrollbar *))ICIDM::s_cidm->vfptr->UnregisterInputMap)(
                    10,
                    v1);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00470150) --------------------------------------------------------  // acclient.c:172987
void __stdcall UIElement_Scrollbar::SetupDefaultHotClick(UIElement *pElement)
{
  UIElement *v2; // esi@1

  v2 = pElement;
  UIElement::SetAttribute_Bool(pElement, 0xFu, 1);
  if ( !UIElement::GetAttribute_Float(v2, 0x10u, (float *)&pElement) )
  {
    pElement = (UIElement *)1056964608;
    UIElement::SetAttribute_Float(v2, 0x10u, 0.5);
  }
  if ( !UIElement::GetAttribute_Float(v2, 0x11u, (float *)&pElement) )
  {
    pElement = (UIElement *)1040187392;
    UIElement::SetAttribute_Float(v2, 0x11u, 0.125);
  }
}

//----- (004701C0) --------------------------------------------------------  // acclient.c:173006
int __thiscall UIElement_Scrollbar::PositionToStop(UIElement_Scrollbar *this, float i_fNewPosition)
{
  UIElement *v2; // esi@1
  int v3; // edi@3
  unsigned __int64 v4; // rax@4
  bool bDontUseEndPoints; // [sp+7h] [bp-5h]@3
  int nStopPositions; // [sp+8h] [bp-4h]@1

  v2 = (UIElement *)this;
  nStopPositions = 1;
  if ( UIElement::GetAttribute_Int((UIElement *)&this->vfptr, 0x7Du, &nStopPositions) && nStopPositions )
  {
    v3 = 0;
    bDontUseEndPoints = 0;
    UIElement::GetAttribute_Bool(v2, 0x7Eu, &bDontUseEndPoints);
    if ( bDontUseEndPoints )
    {
      v4 = (unsigned __int64)((double)nStopPositions * i_fNewPosition);
    }
    else
    {
      if ( nStopPositions > 1 )
      {
        --nStopPositions;
        v3 = (unsigned __int64)((double)nStopPositions * i_fNewPosition + 0.5);
      }
      LODWORD(v4) = v3;
    }
  }
  else
  {
    LODWORD(v4) = -1;
  }
  return v4;
}

//----- (00470260) --------------------------------------------------------  // acclient.c:173043
UIElementMessageInfo *__thiscall UIElement_Scrollbar::GetScrollbarPositionFromMessage(UIElement_Scrollbar *this, UIElementMessageInfo *i_rMsg, UIElementMessageInfo *i_rMsga)
{
  UIElement *v3; // ebx@1
  unsigned int v4; // edi@1
  UIElement *v5; // esi@2
  UIElementMessageInfo *result; // eax@3

  v3 = (UIElement *)i_rMsga->ptElement.y;
  v4 = i_rMsga->ptElement.x;
  if ( (UIElement_Scrollbar *)((int (*)(void))i_rMsga->pElement->vfptr[13].OnAction)() == this )
  {
    v5 = i_rMsga->pElement;
    v4 += v5->m_box.m_x0;
    v3 = (UIElement *)((char *)v3 + v5->m_box.m_y0);
  }
  result = i_rMsg;
  i_rMsg->idElement = v4;
  i_rMsg->pElement = v3;
  return result;
}

//----- (004702A0) --------------------------------------------------------  // acclient.c:173065
int __thiscall UIElement_Scrollbar::ComputeActiveSize(UIElement_Scrollbar *this, int a2)
{
  UIElement_Scrollbar *v2; // esi@1
  int v3; // edx@1
  int v4; // ebx@1
  UIRegion *v5; // ecx@1
  int v6; // ebp@1
  int v7; // edi@1
  UIRegion *v8; // ecx@4
  int result; // eax@8
  bool bDontUseEndPoints; // [sp+13h] [bp-9h]@6
  tagPOINT ptWidgetSize; // [sp+14h] [bp-8h]@2

  v2 = this;
  v3 = this->m_rectScrollingArea.left;
  v4 = this->m_rectScrollingArea.bottom - this->m_rectScrollingArea.top;
  v5 = (UIRegion *)&this->m_pWidget->vfptr;
  v6 = 0;
  v7 = v2->m_rectScrollingArea.right - v3;
  if ( v5 )
    ptWidgetSize.x = UIRegion::GetWidth(v5);
  else
    ptWidgetSize.x = 0;
  v8 = (UIRegion *)&v2->m_pWidget->vfptr;
  if ( v8 )
    v6 = UIRegion::GetHeight(v8);
  bDontUseEndPoints = 0;
  UIElement::GetAttribute_Bool((UIElement *)&v2->vfptr, 0x7Eu, &bDontUseEndPoints);
  if ( !bDontUseEndPoints )
  {
    v7 -= ptWidgetSize.x;
    v4 -= v6;
  }
  result = a2;
  *(_DWORD *)a2 = v7;
  *(_DWORD *)(a2 + 4) = v4;
  return result;
}

//----- (00470330) --------------------------------------------------------  // acclient.c:173105
void __thiscall UIElement_Scrollbar::SetBitMask(UIElement_Scrollbar *this, const bool i_bVal, const unsigned int i_nMask)
{
  if ( i_bVal )
    this->m_bitField |= i_nMask;
  else
    this->m_bitField &= ~i_nMask;
}

//----- (00470370) --------------------------------------------------------  // acclient.c:173114
void __thiscall UIElement_Scrollbar::SetHorizontal(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 1;
  else
    this->m_bitField = v2 & 0xFFFFFFFE;
}

//----- (004703A0) --------------------------------------------------------  // acclient.c:173126
void __thiscall UIElement_Scrollbar::SetProportional(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 2;
  else
    this->m_bitField = v2 & 0xFFFFFFFD;
}

//----- (004703D0) --------------------------------------------------------  // acclient.c:173138
void __thiscall UIElement_Scrollbar::SetDisabled(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 4;
  else
    this->m_bitField = v2 & 0xFFFFFFFB;
}

//----- (00470400) --------------------------------------------------------  // acclient.c:173150
void __thiscall UIElement_Scrollbar::SetHideDisabled(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 8;
  else
    this->m_bitField = v2 & 0xFFFFFFF7;
}

//----- (00470430) --------------------------------------------------------  // acclient.c:173162
void __thiscall UIElement_Scrollbar::SetSmoothMovement(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x10;
  else
    this->m_bitField = v2 & 0xFFFFFFEF;
}

//----- (00470460) --------------------------------------------------------  // acclient.c:173174
void __thiscall UIElement_Scrollbar::SetDisallowUpdating(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x20;
  else
    this->m_bitField = v2 & 0xFFFFFFDF;
}

//----- (00470490) --------------------------------------------------------  // acclient.c:173186
void __thiscall UIElement_Scrollbar::SetMoveToTouched(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x40;
  else
    this->m_bitField = v2 & 0xFFFFFFBF;
}

//----- (004704C0) --------------------------------------------------------  // acclient.c:173198
void __thiscall UIElement_Scrollbar::SetHasStopLocations(UIElement_Scrollbar *this, const bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x100;
  else
    this->m_bitField = v2 & 0xFFFFFEFF;
}

//----- (004704F0) --------------------------------------------------------  // acclient.c:173210
int __thiscall UIElement_Scrollbar::GetSecondaryCoordinate(UIElement_Scrollbar *this, tagPOINT *i_pt)
{
  int result; // eax@2

  if ( this->m_bitField & 1 )
    result = i_pt->y;
  else
    result = i_pt->x;
  return result;
}

//----- (00470510) --------------------------------------------------------  // acclient.c:173222
void __cdecl UIElement_Scrollbar::Register()
{
  UIElement::RegisterElementClass(
    0xBu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Scrollbar::Create);
}

//----- (00470520) --------------------------------------------------------  // acclient.c:173230
void __thiscall UIElement_Scrollbar::Initialize(UIElement_Scrollbar *this)
{
  UIElement *v1; // esi@1
  UIElement_Scrollbar *v2; // [sp-2h] [bp-4h]@1

  v2 = this;
  v1 = (UIElement *)this;
  UIElement::Initialize((UIElement *)&this->vfptr);
  BYTE3(v2) = 0;
  UIElement::GetAttribute_Bool(v1, 0x7Cu, (bool *)&v2 + 3);
  if ( !BYTE3(v2) )
    UIElement_Scrollbar::SetupDefaultHotClick(v1);
}

//----- (00470550) --------------------------------------------------------  // acclient.c:173245
void __thiscall UIElement_Scrollbar::StartAnimation(UIElement_Scrollbar *this)
{
  UIElement_Scrollbar *v1; // esi@1
  bool v2; // bl@1
  double v3; // st7@3
  ICMDCommandEnum v4; // eax@3
  float fDuration; // [sp+0h] [bp-4h]@1

  fDuration = *(float *)&this;
  v1 = this;
  v2 = (this->m_bitField & 0x400000) == 0x400000;
  fDuration = 0.0;
  if ( UIElement::GetAttribute_Float((UIElement *)&this->vfptr, 0x84u, &fDuration) && fabs(fDuration) > 0.00019999999 )
  {
    LODWORD(v1->m_fAnimStartPos) = 0;
    UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x86u, &v1->m_fAnimStartPos);
    v1->m_fAnimEndPos = v1->m_fAnimStartPos;
    UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x85u, &v1->m_fAnimEndPos);
    v3 = fDuration;
    v4 = (signed int)Timer::cur_time.Cmd;
    HIDWORD(v1->m_tAnimStartTime) = Timer::cur_time.Param;
    LODWORD(v1->m_tAnimStartTime) = v4;
    v1->m_bitField |= 0x400000u;
    v1->m_tAnimEndTime = v3 + v1->m_tAnimStartTime;
    if ( !v2 )
      UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  }
}

//----- (00470620) --------------------------------------------------------  // acclient.c:173275
UIElement_Button *__thiscall UIElement_Scrollbar::GetButtonPointer_(UIElement_Scrollbar *this, bool i_bIncrement)
{
  UIElement_Scrollbar *v2; // esi@1
  UIElement_Button *result; // eax@1
  unsigned int v4; // ecx@2
  UIElement *v5; // eax@5
  UIElement_Button *v6; // edi@6

  v2 = this;
  result = 0;
  if ( i_bIncrement )
    v4 = this->m_eIncrementButtonID;
  else
    v4 = this->m_eDecrementButtonID;
  if ( v4 )
  {
    v5 = UIElement::FindRelative((UIElement *)&v2->vfptr, v4);
    if ( v5
      && (v6 = (UIElement_Button *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)1)) != 0
      && (UIElement_Scrollbar *)UIElement::FindRelative((UIElement *)&v6->vfptr, v2->m_desc.m_elementID) == v2 )
      result = v6;
    else
      result = 0;
  }
  return result;
}

//----- (00470680) --------------------------------------------------------  // acclient.c:173303
void __thiscall UIElement_Scrollbar::UpdateButtonID_(UIElement_Scrollbar *this, bool i_bIncrement, unsigned int i_eNewID)
{
  UIElement_Scrollbar *v3; // esi@1
  UIElement *v4; // eax@4

  v3 = this;
  if ( i_bIncrement )
    this->m_eIncrementButtonID = i_eNewID;
  else
    this->m_eDecrementButtonID = i_eNewID;
  v4 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, i_eNewID);
  if ( v4 )
  {
    UIElement_Scrollbar::SetupDefaultHotClick(v4);
  }
  else
  {
    v3->m_bitField |= (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)";
    UIListener::RegisterForGlobalMessage((UIListener *)&v3->vfptr, 3u);
  }
}

//----- (004706D0) --------------------------------------------------------  // acclient.c:173326
void __thiscall UIElement_Scrollbar::HandlePageClick(UIElement_Scrollbar *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Scrollbar *v2; // esi@1
  UIElement *v3; // ecx@1
  int v4; // ebx@2
  int v5; // ebp@2
  int v6; // eax@2
  int v7; // ecx@2
  int v8; // edi@3
  int v9; // edx@5
  bool v10; // dl@7
  int v11; // edi@8
  int ptWidgetSize; // [sp+4h] [bp-8h]@2

  v2 = this;
  v3 = this->m_pWidget;
  if ( v3 )
  {
    v4 = v3->m_box.m_x0;
    v5 = v3->m_box.m_y0;
    ptWidgetSize = UIRegion::GetWidth((UIRegion *)&v3->vfptr);
    v6 = UIRegion::GetHeight((UIRegion *)&v2->m_pWidget->vfptr);
    v7 = v2->m_bitField & 1;
    if ( v7 )
      v8 = i_rMsg->ptElement.x;
    else
      v8 = i_rMsg->ptElement.y;
    v9 = v4;
    if ( v7 != 1 )
      v9 = v5;
    v10 = v8 < v9;
    if ( v7 == 1 )
      v11 = i_rMsg->ptElement.x;
    else
      v11 = i_rMsg->ptElement.y;
    if ( v7 == 1 )
      v6 = ptWidgetSize;
    else
      v4 = v5;
    if ( v10 || v11 > v4 + v6 )
      UIElement::BroadcastElementMessage((UIElement *)&v2->vfptr, 16 - (v10 != 0), 0, 0);
  }
}

//----- (00470780) --------------------------------------------------------  // acclient.c:173371
double __thiscall UIElement_Scrollbar::StopToPosition(UIElement_Scrollbar *this, int i_nNewStop)
{
  UIElement *v2; // esi@1
  double result; // st7@8
  bool bDontUseEndPoints; // [sp+7h] [bp-5h]@7
  int nStopPositions; // [sp+8h] [bp-4h]@1

  v2 = (UIElement *)this;
  nStopPositions = 1;
  if ( UIElement::GetAttribute_Int((UIElement *)&this->vfptr, 0x7Du, &nStopPositions) && nStopPositions )
  {
    if ( i_nNewStop >= 0 )
    {
      if ( i_nNewStop > nStopPositions - 1 )
        i_nNewStop = nStopPositions - 1;
    }
    else
    {
      i_nNewStop = 0;
    }
    bDontUseEndPoints = 0;
    UIElement::GetAttribute_Bool(v2, 0x7Eu, &bDontUseEndPoints);
    if ( bDontUseEndPoints )
    {
      result = ((double)i_nNewStop + 0.5) / (double)nStopPositions;
    }
    else if ( nStopPositions <= 1 )
    {
      result = 0.5;
    }
    else
    {
      result = (double)i_nNewStop / (double)(nStopPositions - 1);
    }
  }
  else
  {
    result = -1.0;
  }
  return result;
}

//----- (00470830) --------------------------------------------------------  // acclient.c:173414
void __thiscall UIElement_Scrollbar::SetScrollbarStop(UIElement_Scrollbar *this, int i_nNewStop, bool i_bAllowSmoothMovement)
{
  int v3; // edi@1
  UIElement *v4; // esi@1
  double v5; // st7@1
  int i_nNewStopa; // [sp+Ch] [bp+4h]@1

  v3 = i_nNewStop;
  v4 = (UIElement *)this;
  v5 = UIElement_Scrollbar::StopToPosition(this, i_nNewStop);
  *(float *)&i_nNewStopa = v5;
  if ( v5 >= 0.0 )
  {
    UIElement::SetAttribute_Int(v4, 0x87u, v3);
    UIElement::SetAttribute_Float(v4, 0x86u, *(float *)&i_nNewStopa);
    UIElement::BroadcastElementMessage(v4, 0xAu, (unsigned __int64)(*(float *)&i_nNewStopa * 1000.0), v3);
  }
}

//----- (00470890) --------------------------------------------------------  // acclient.c:173434
double __thiscall UIElement_Scrollbar::PointToPosition(UIElement_Scrollbar *this, tagPOINT *i_ptElement)
{
  UIElement_Scrollbar *v2; // ebx@1
  UIRegion *v3; // ecx@1
  signed int v4; // ebp@1
  UIRegion *v5; // ecx@4
  int v6; // ecx@6
  int v7; // edi@6
  int v8; // eax@6
  int v9; // esi@6
  int v10; // edi@6
  int v11; // ebx@15
  signed int v12; // eax@17
  double result; // st7@20
  bool bDontUseEndPoints; // [sp+13h] [bp-11h]@6
  tagPOINT ptMax; // [sp+14h] [bp-10h]@1
  tagPOINT ptWidgetSize; // [sp+1Ch] [bp-8h]@2
  tagPOINT *i_ptElementa; // [sp+28h] [bp+4h]@15

  v2 = this;
  UIElement_Scrollbar::ComputeActiveSize(this, (int)&ptMax);
  v3 = (UIRegion *)&v2->m_pWidget->vfptr;
  v4 = 0;
  if ( v3 )
    ptWidgetSize.x = UIRegion::GetWidth(v3);
  else
    ptWidgetSize.x = 0;
  v5 = (UIRegion *)&v2->m_pWidget->vfptr;
  if ( v5 )
    v4 = UIRegion::GetHeight(v5);
  v6 = v2->m_rectScrollingArea.left;
  v7 = i_ptElement->y;
  --ptMax.x;
  v8 = v2->m_rectScrollingArea.top;
  v9 = i_ptElement->x - v6;
  --ptMax.y;
  v10 = v7 - v8;
  bDontUseEndPoints = 0;
  UIElement::GetAttribute_Bool((UIElement *)&v2->vfptr, 0x7Eu, &bDontUseEndPoints);
  if ( !bDontUseEndPoints )
  {
    v9 += ptWidgetSize.x / -2;
    v10 += v4 / -2;
    if ( v9 >= 0 )
    {
      if ( v9 > ptMax.x )
        v9 = ptMax.x;
    }
    else
    {
      v9 = 0;
    }
    if ( v10 >= 0 )
    {
      if ( v10 > ptMax.y )
        v10 = ptMax.y;
    }
    else
    {
      v10 = 0;
    }
  }
  v11 = v2->m_bitField & 1;
  i_ptElementa = (tagPOINT *)v9;
  if ( !v11 )
    i_ptElementa = (tagPOINT *)v10;
  v12 = ptMax.x;
  if ( v11 != 1 )
    v12 = ptMax.y;
  ptMax.x = v12;
  if ( v12 <= 1 )
    result = 0.0;
  else
    result = (double)(signed int)i_ptElementa / (double)*(signed int *)&ptMax;
  return result;
}

//----- (004709A0) --------------------------------------------------------  // acclient.c:173512
float __thiscall UIElement_Scrollbar::PositionToWidgetX0Y0(UIElement_Scrollbar *this, float i_fPosition, float i_fPositiona)
{
  UIElement_Scrollbar *v3; // esi@1
  int v4; // ebx@1
  UIRegion *v5; // ecx@1
  UIRegion *v6; // ecx@4
  int v7; // edi@7
  int v8; // eax@9
  int v9; // ebp@11
  int v10; // eax@12
  float result; // eax@16
  bool bDontUseEndPoints; // [sp+13h] [bp-19h]@11
  tagPOINT ptSize; // [sp+14h] [bp-18h]@1
  tagPOINT ptWidgetSize; // [sp+1Ch] [bp-10h]@2
  tagPOINT ptOfs; // [sp+24h] [bp-8h]@1

  v3 = this;
  UIElement_Scrollbar::ComputeActiveSize(this, (int)&ptSize);
  v4 = v3->m_rectScrollingArea.left;
  ptOfs.y = v3->m_rectScrollingArea.top;
  v5 = (UIRegion *)&v3->m_pWidget->vfptr;
  if ( v5 )
    ptWidgetSize.x = UIRegion::GetWidth(v5);
  else
    ptWidgetSize.x = 0;
  v6 = (UIRegion *)&v3->m_pWidget->vfptr;
  if ( v6 )
    ptWidgetSize.y = UIRegion::GetHeight(v6);
  else
    ptWidgetSize.y = 0;
  v7 = v3->m_bitField & 1;
  if ( !v7 )
    ptSize.x = ptSize.y;
  v8 = v4;
  if ( v7 != 1 )
    v8 = ptOfs.y;
  v9 = v8 + (unsigned __int64)((double)*(signed int *)&ptSize * i_fPositiona);
  bDontUseEndPoints = 0;
  UIElement::GetAttribute_Bool((UIElement *)&v3->vfptr, 0x7Eu, &bDontUseEndPoints);
  if ( bDontUseEndPoints )
  {
    v10 = ptWidgetSize.x;
    if ( !(v3->m_bitField & 1) )
      v10 = ptWidgetSize.y;
    v9 += v10 / -2;
  }
  if ( v3->m_bitField & 1 )
  {
    result = i_fPosition;
    *LODWORD(i_fPosition) = v9;
    *(_DWORD *)(LODWORD(i_fPosition) + 4) = 0;
  }
  else
  {
    result = i_fPosition;
    *LODWORD(i_fPosition) = 0;
    *(_DWORD *)(LODWORD(i_fPosition) + 4) = v9;
  }
  return result;
}

//----- (00470AA0) --------------------------------------------------------  // acclient.c:173574
void __thiscall UIElement_Scrollbar::UpdateScrollingArea(UIElement_Scrollbar *this)
{
  UIElement_Scrollbar *v1; // esi@1
  UIRegion *v2; // eax@1
  UIRegion *v3; // edi@1
  UIRegion *v4; // eax@3
  UIRegion *v5; // edi@3
  int v6; // edx@4
  int v7; // eax@4

  v1 = this;
  this->m_rectScrollingArea.top = 0;
  this->m_rectScrollingArea.left = 0;
  this->m_rectScrollingArea.right = UIRegion::GetWidth((UIRegion *)&this->vfptr);
  v1->m_rectScrollingArea.bottom = UIRegion::GetHeight((UIRegion *)&v1->vfptr);
  v2 = (UIRegion *)UIElement_Scrollbar::GetButtonPointer_(v1, 1);
  v3 = v2;
  if ( v2 )
  {
    v1->m_rectScrollingArea.top += UIRegion::GetHeight(v2);
    v1->m_rectScrollingArea.left += UIRegion::GetWidth(v3);
    ((void (__thiscall *)(UIRegion *, _DWORD, _DWORD))v3->vfptr[3].OnLoseFocus)(v3, 0, 0);
  }
  v4 = (UIRegion *)UIElement_Scrollbar::GetButtonPointer_(v1, 0);
  v5 = v4;
  if ( v4 )
  {
    v1->m_rectScrollingArea.right -= UIRegion::GetWidth(v4);
    v6 = v1->m_rectScrollingArea.bottom - UIRegion::GetHeight(v5);
    v7 = v1->m_rectScrollingArea.right;
    v1->m_rectScrollingArea.bottom = v6;
    ((void (__thiscall *)(UIRegion *, _DWORD, int))v5->vfptr[3].OnLoseFocus)(v5, v7, v6);
  }
}

//----- (00470B60) --------------------------------------------------------  // acclient.c:173610
void __thiscall UIElement_Scrollbar::ValidatePosition(UIElement_Scrollbar *this, float *io_fPosition)
{
  UIElement_Scrollbar *v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // eax@2

  v2 = this;
  v3 = this->m_bitField;
  if ( BYTE1(v3) & 1 )
  {
    v4 = UIElement_Scrollbar::PositionToStop(this, *io_fPosition);
    *io_fPosition = UIElement_Scrollbar::StopToPosition(v2, v4);
  }
  if ( *io_fPosition >= 0.0 )
  {
    if ( *io_fPosition > 1.0 )
      *(_DWORD *)io_fPosition = 1065353216;
  }
  else
  {
    *(_DWORD *)io_fPosition = 0;
  }
}

//----- (00470BC0) --------------------------------------------------------  // acclient.c:173635
void __thiscall UIElement_Scrollbar::~UIElement_Scrollbar(UIElement_Scrollbar *this)
{
  UIElement_Scrollbar *v1; // esi@1
  UIElement *v2; // eax@1
  UIElement *v3; // eax@4

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Scrollbar::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  this->m_eIncrementButtonID = 0;
  v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0);
  if ( v2 )
  {
    UIElement_Scrollbar::SetupDefaultHotClick(v2);
  }
  else
  {
    v1->m_bitField |= (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)";
    UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  }
  v1->m_eDecrementButtonID = 0;
  v3 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0);
  if ( v3 )
  {
    UIElement_Scrollbar::SetupDefaultHotClick(v3);
    UIElement_Button::~UIElement_Button((UIElement_Button *)&v1->vfptr);
  }
  else
  {
    v1->m_bitField |= (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)";
    UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
    UIElement_Button::~UIElement_Button((UIElement_Button *)&v1->vfptr);
  }
}
// 79D0E8: using guessed type int (__thiscall *UIElement_Scrollbar::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00470C50) --------------------------------------------------------  // acclient.c:173673
char __thiscall UIElement_Scrollbar::InqAvailableProperties(UIElement_Scrollbar *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement_Button::InqAvailableProperties((UIElement_Button *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0x12u, v2) )
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

//----- (00470CA0) --------------------------------------------------------  // acclient.c:173701
void __thiscall UIElement_Scrollbar::Global_Loop(UIElement_Scrollbar *this)
{
  UIElement_Scrollbar *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ST14_4@2
  UIElement *v4; // eax@2
  UIRegion *v5; // eax@2
  UIRegion *v6; // edi@2
  unsigned int v7; // ST14_4@4
  UIElement *v8; // eax@4
  UIRegion *v9; // eax@4
  UIRegion *v10; // edi@4
  int v11; // ebx@5
  float v12; // ST20_4@5
  IInputActionCallbackVtbl *v13; // ebp@5
  int v14; // ST0C_4@5
  int v15; // eax@5
  long double v16; // st7@8
  float _val; // ST18_4@10
  float fPercentage; // [sp+20h] [bp-4h]@8

  v1 = this;
  v2 = this->m_bitField;
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v2 )
  {
    this->m_bitField = v2 & 0xFF7FFFFF;
    v3 = this->m_eIncrementButtonID;
    v4 = (UIElement *)((int (*)(void))this->vfptr[13].OnAction)();
    v5 = (UIRegion *)UIElement::GetChildRecursive(v4, v3);
    v6 = v5;
    if ( v5 )
    {
      UIRegion::GetWidth(v5);
      UIRegion::GetHeight(v6);
      ((void (__thiscall *)(UIRegion *, UIElement_Scrollbar *))v6->vfptr[5].OnLoseFocus)(v6, v1);
      ((void (__thiscall *)(UIRegion *, _DWORD, _DWORD))v6->vfptr[3].OnLoseFocus)(v6, 0, 0);
      UIElement_Scrollbar::SetupDefaultHotClick((UIElement *)v6);
    }
    v7 = v1->m_eDecrementButtonID;
    v8 = (UIElement *)((int (__thiscall *)(UIElement_Scrollbar *))v1->vfptr[13].OnAction)(v1);
    v9 = (UIRegion *)UIElement::GetChildRecursive(v8, v7);
    v10 = v9;
    if ( v9 )
    {
      v11 = UIRegion::GetWidth(v9);
      v12 = COERCE_FLOAT(UIRegion::GetHeight(v10));
      ((void (__thiscall *)(UIRegion *, UIElement_Scrollbar *))v10->vfptr[5].OnLoseFocus)(v10, v1);
      v13 = v10->vfptr;
      v14 = UIRegion::GetHeight((UIRegion *)&v1->vfptr) - LODWORD(v12);
      v15 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
      ((void (__thiscall *)(UIRegion *, int, int))v13[3].OnLoseFocus)(v10, v15 - v11, v14);
      UIElement_Scrollbar::SetupDefaultHotClick((UIElement *)v10);
    }
    UIElement_Scrollbar::UpdateScrollingArea(v1);
    UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  }
  if ( v1->m_bitField & 0x400000 )
  {
    v16 = (COERCE_DOUBLE(Timer::cur_time.Cmd) - v1->m_tAnimStartTime) / (v1->m_tAnimEndTime - v1->m_tAnimStartTime);
    fPercentage = v16;
    if ( v16 >= 1.0 )
    {
      v1->m_bitField &= 0xFFBFFFFF;
      fPercentage = 1.0;
      UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
    }
    _val = (v1->m_fAnimEndPos - v1->m_fAnimStartPos) * fPercentage + v1->m_fAnimStartPos;
    UIElement::SetAttribute_Float((UIElement *)&v1->vfptr, 0x86u, _val);
  }
}

//----- (00470E00) --------------------------------------------------------  // acclient.c:173773
void __thiscall UIElement_Scrollbar::ListenToGlobalMessage(UIElement_Scrollbar *this, unsigned int _messageID, int _data_int)
{
  UIElement_Scrollbar *v3; // esi@1

  v3 = this;
  UIElement_Button::ListenToGlobalMessage((UIElement_Button *)&this->vfptr, _messageID, _data_int);
  if ( _messageID == 3 )
    UIElement_Scrollbar::Global_Loop(v3);
}

//----- (00470E30) --------------------------------------------------------  // acclient.c:173784
void __thiscall UIElement_Scrollbar::HandleMoveSteps(UIElement_Scrollbar *this, const unsigned int _attributeID, const int _nSteps)
{
  UIElement_Scrollbar *v3; // esi@1
  int nNewStop; // [sp+0h] [bp-4h]@1

  v3 = this;
  nNewStop = 0;
  if ( UIElement::GetAttribute_Int((UIElement *)&this->vfptr, 0x87u, &nNewStop) )
    UIElement_Scrollbar::SetScrollbarStop(v3, _nSteps + nNewStop, 1);
  else
    UIElement::BroadcastElementMessage((UIElement *)&v3->vfptr, (_nSteps <= 0) + 13, _nSteps, 0);
}

//----- (00470E90) --------------------------------------------------------  // acclient.c:173798
void __thiscall UIElement_Scrollbar::HandleButtonClick(UIElement_Scrollbar *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Scrollbar::HandleMoveSteps(this, 0x86u, i_rMsg->idElement != this->m_eIncrementButtonID ? -1 : 1);
}

//----- (00470EC0) --------------------------------------------------------  // acclient.c:173804
void __thiscall UIElement_Scrollbar::SetScrollbarPosition(UIElement_Scrollbar *this, float i_fNewPosition, bool i_bAllowSmoothMovement)
{
  UIElement *v3; // esi@1
  int v4; // eax@5

  v3 = (UIElement *)this;
  if ( i_fNewPosition >= 0.0 )
  {
    if ( i_fNewPosition > 1.0 )
      i_fNewPosition = 1.0;
  }
  else
  {
    i_fNewPosition = 0.0;
  }
  v4 = UIElement_Scrollbar::PositionToStop(this, i_fNewPosition);
  if ( v4 < 0 )
  {
    UIElement::SetAttribute_Float(v3, 0x86u, i_fNewPosition);
    UIElement::BroadcastElementMessage(v3, 0xAu, (unsigned __int64)(i_fNewPosition * 1000.0), 0xFFFFFFFF);
  }
  else
  {
    UIElement_Scrollbar::SetScrollbarStop((UIElement_Scrollbar *)v3, v4, i_bAllowSmoothMovement);
  }
}

//----- (00470F50) --------------------------------------------------------  // acclient.c:173832
void __thiscall UIElement_Scrollbar::ScrollToPoint(UIElement_Scrollbar *this, UIElementMessageInfo *i_rMsg, bool i_bAllowSmoothMovement)
{
  int v3; // ebx@1
  UIElement_Scrollbar *v4; // ebp@1
  int v5; // edi@1
  UIElement *v6; // esi@2
  float i_fNewPosition; // ST00_4@3
  tagPOINT ptElementMe; // [sp+18h] [bp-8h]@3

  v3 = i_rMsg->ptElement.y;
  v4 = this;
  v5 = i_rMsg->ptElement.x;
  if ( (UIElement_Scrollbar *)((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)() == this )
  {
    v6 = i_rMsg->pElement;
    v5 += v6->m_box.m_x0;
    v3 += v6->m_box.m_y0;
  }
  ptElementMe.x = v5;
  ptElementMe.y = v3;
  i_fNewPosition = UIElement_Scrollbar::PointToPosition(v4, &ptElementMe);
  UIElement_Scrollbar::SetScrollbarPosition(v4, i_fNewPosition, i_bAllowSmoothMovement);
}

//----- (00470FB0) --------------------------------------------------------  // acclient.c:173857
void __thiscall UIElement_Scrollbar::StartWidgetDrag(UIElement_Scrollbar *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Scrollbar *v2; // esi@1
  int v3; // ebx@3
  int v4; // ebp@3
  UIElement *v5; // edi@4

  v2 = this;
  if ( this->m_bitField & 0x40 )
    UIElement_Scrollbar::ScrollToPoint(this, i_rMsg, 1);
  v3 = i_rMsg->ptElement.x;
  v4 = i_rMsg->ptElement.y;
  if ( (UIElement_Scrollbar *)((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)() == v2 )
  {
    v5 = i_rMsg->pElement;
    v3 += v5->m_box.m_x0;
    v4 += v5->m_box.m_y0;
  }
  v2->m_ptDragStart.x = v3;
  v2->m_ptDragStart.y = v4;
  UIElement::GetAttribute_Float((UIElement *)&v2->vfptr, 0x86u, &v2->m_fResetPosition);
  v2->m_bWidgetDragActive = 1;
}

//----- (00471020) --------------------------------------------------------  // acclient.c:173882
void __thiscall UIElement_Scrollbar::ScrollNPixelsFromReset(UIElement_Scrollbar *this, tagPOINT *i_ptDelta, bool i_bAllowSmoothScrolling)
{
  UIElement_Scrollbar *v3; // esi@1
  int v4; // eax@1
  int v5; // ecx@1
  float i_fNewPosition; // ST00_4@8
  int nPriCoord; // [sp+Ch] [bp-8h]@1
  int v8; // [sp+10h] [bp-4h]@2
  int i_ptDeltaa; // [sp+18h] [bp+4h]@6

  v3 = this;
  UIElement_Scrollbar::ComputeActiveSize(this, (int)&nPriCoord);
  v4 = v3->m_bitField & 1;
  v5 = nPriCoord;
  if ( !v4 )
    v5 = v8;
  nPriCoord = v5;
  if ( v5 )
  {
    if ( v4 == 1 )
      i_ptDeltaa = i_ptDelta->x;
    else
      i_ptDeltaa = i_ptDelta->y;
    i_fNewPosition = (double)i_ptDeltaa / (double)nPriCoord + v3->m_fResetPosition;
    UIElement_Scrollbar::SetScrollbarPosition(v3, i_fNewPosition, i_bAllowSmoothScrolling);
  }
  else
  {
    UIElement_Scrollbar::SetScrollbarPosition(v3, 0.0, i_bAllowSmoothScrolling);
  }
}

//----- (004710B0) --------------------------------------------------------  // acclient.c:173915
UIElement_Scrollbar *__thiscall UIElement_Scrollbar::scalar_deleting_destructor(UIElement_Scrollbar *this, unsigned int a2)
{
  UIElement_Scrollbar *v2; // esi@1

  v2 = this;
  UIElement_Scrollbar::~UIElement_Scrollbar(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004710D0) --------------------------------------------------------  // acclient.c:173927
void __thiscall UIElement_Scrollbar::UpdateLayout(UIElement_Scrollbar *this)
{
  UIElement_Scrollbar *v1; // esi@1
  UIRegion *v2; // ecx@8
  signed int v3; // edi@9
  int v4; // ecx@10
  int v5; // ebx@10
  unsigned __int64 v6; // rax@12
  float v7; // ebx@18
  int v8; // edi@18
  bool v9; // bl@18
  UIElement *v10; // eax@18
  UIElement *v11; // ebp@18
  IInputActionCallbackVtbl *v12; // edx@19
  int v13; // ebx@20
  UIElement *v14; // eax@20
  unsigned int v15; // ecx@20
  UIElement *v16; // ebp@20
  int v17; // edi@22
  bool v18; // bl@22
  UIElement *v19; // eax@22
  unsigned int v20; // ecx@22
  UIElement *v21; // ebp@22
  int v22; // ebx@24
  UIElement *v23; // eax@24
  unsigned int v24; // ecx@24
  UIElement *v25; // ebp@24
  unsigned int v26; // eax@26
  unsigned int v27; // eax@30
  bool v28; // [sp+4Dh] [bp-25h]@20
  bool v29; // [sp+4Dh] [bp-25h]@24
  float fPosition; // [sp+4Eh] [bp-24h]@4
  int nStopPositions; // [sp+52h] [bp-20h]@4
  int v32; // [sp+56h] [bp-1Ch]@10
  float fWidgetSize; // [sp+5Ah] [bp-18h]@10
  int v34; // [sp+5Eh] [bp-14h]@18
  int iMinWidgetSize; // [sp+62h] [bp-10h]@10
  int nNewStop; // [sp+66h] [bp-Ch]@6
  tagPOINT ptWidgetSize; // [sp+6Ah] [bp-8h]@9

  v1 = this;
  if ( !this->m_pWidget )
    this->m_pWidget = UIElement::GetChild((UIElement *)&this->vfptr, 1u);
  if ( !(v1->m_bitField & 0x20) )
  {
    fPosition = 0.0;
    UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x86u, &fPosition);
    nStopPositions = 1;
    if ( UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x7Du, &nStopPositions)
      && nStopPositions
      && !UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x87u, &nNewStop) )
    {
      UIElement_Scrollbar::SetScrollbarPosition(v1, fPosition, 0);
    }
    else
    {
      UIElement_Scrollbar::UpdateScrollingArea(v1);
      v2 = (UIRegion *)&v1->m_pWidget->vfptr;
      if ( v2 )
      {
        v3 = UIRegion::GetWidth(v2);
        ptWidgetSize.y = UIRegion::GetHeight((UIRegion *)&v1->m_pWidget->vfptr);
        if ( v1->m_bitField & 2 )
        {
          fWidgetSize = 1.0;
          UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x88u, &fWidgetSize);
          iMinWidgetSize = 0;
          UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x89u, &iMinWidgetSize);
          v4 = v1->m_rectScrollingArea.bottom - v1->m_rectScrollingArea.top;
          v5 = v1->m_bitField & 1;
          v32 = v1->m_rectScrollingArea.right - v1->m_rectScrollingArea.left;
          if ( !v5 )
            v32 = v4;
          v6 = (unsigned __int64)((double)v32 * fWidgetSize + 0.5);
          if ( (signed int)v6 < iMinWidgetSize )
            LODWORD(v6) = iMinWidgetSize;
          if ( v5 == 1 )
            v3 = v6;
          else
            ptWidgetSize.y = v6;
          ((void (__stdcall *)(signed int, int))v1->m_pWidget->vfptr[4].__vecDelDtor)(v3, ptWidgetSize.y);
        }
        UIElement_Scrollbar::PositionToWidgetX0Y0(v1, COERCE_FLOAT(&fWidgetSize), fPosition);
        v7 = fWidgetSize;
        ((void (__stdcall *)(_DWORD, int))v1->m_pWidget->vfptr[3].OnLoseFocus)(LODWORD(fWidgetSize), v34);
        v8 = LODWORD(v7) + v3 / 2;
        v9 = (v1->m_bitField & 4) == 4;
        iMinWidgetSize = UIRegion::GetHeight((UIRegion *)&v1->vfptr);
        v10 = UIElement::GetChild((UIElement *)&v1->vfptr, 4u);
        v11 = v10;
        if ( v10 )
        {
          v12 = v10->vfptr;
          LOBYTE(v10) = v9 == 0;
          v12[2].__vecDelDtor((IInputActionCallback *)v11, (unsigned int)v10);
          ((void (__thiscall *)(UIElement *, _DWORD, _DWORD))v11->vfptr[3].OnLoseFocus)(v11, 0, 0);
          ((void (__thiscall *)(UIElement *, int, int))v11->vfptr[4].__vecDelDtor)(v11, v8, iMinWidgetSize);
        }
        v28 = (v1->m_bitField & 4) == 4;
        iMinWidgetSize = UIRegion::GetHeight((UIRegion *)&v1->vfptr);
        v13 = UIRegion::GetWidth((UIRegion *)&v1->vfptr) - v8;
        v14 = UIElement::GetChild((UIElement *)&v1->vfptr, 6u);
        v16 = v14;
        if ( v14 )
        {
          LOBYTE(v15) = v28 == 0;
          v14->vfptr[2].__vecDelDtor((IInputActionCallback *)v14, v15);
          ((void (__thiscall *)(UIElement *, int, _DWORD))v16->vfptr[3].OnLoseFocus)(v16, v8, 0);
          ((void (__thiscall *)(UIElement *, int, int))v16->vfptr[4].__vecDelDtor)(v16, v13, iMinWidgetSize);
        }
        v17 = v34 + ptWidgetSize.y / 2;
        v18 = (v1->m_bitField & 4) == 4;
        iMinWidgetSize = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
        v19 = UIElement::GetChild((UIElement *)&v1->vfptr, 5u);
        v21 = v19;
        if ( v19 )
        {
          LOBYTE(v20) = v18 == 0;
          v19->vfptr[2].__vecDelDtor((IInputActionCallback *)v19, v20);
          ((void (__thiscall *)(UIElement *, _DWORD, _DWORD))v21->vfptr[3].OnLoseFocus)(v21, 0, 0);
          ((void (__thiscall *)(UIElement *, int, int))v21->vfptr[4].__vecDelDtor)(v21, iMinWidgetSize, v17);
        }
        v29 = (v1->m_bitField & 4) == 4;
        v22 = UIRegion::GetHeight((UIRegion *)&v1->vfptr) - v17;
        iMinWidgetSize = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
        v23 = UIElement::GetChild((UIElement *)&v1->vfptr, 7u);
        v25 = v23;
        if ( v23 )
        {
          LOBYTE(v24) = v29 == 0;
          v23->vfptr[2].__vecDelDtor((IInputActionCallback *)v23, v24);
          ((void (__thiscall *)(UIElement *, _DWORD, int))v25->vfptr[3].OnLoseFocus)(v25, 0, v17);
          ((void (__thiscall *)(UIElement *, int, int))v25->vfptr[4].__vecDelDtor)(v25, iMinWidgetSize, v22);
        }
      }
      v26 = v1->m_bitField;
      LOBYTE(v26) = v26 & 4 && v26 & 8;
      LOBYTE(v26) = (_BYTE)v26 == 0;
      v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, v26);
      v27 = v1->m_bitField;
      if ( v27 & 0x1000000 )
        v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, (v27 & 4) != 4 ? 1 : 13);
    }
  }
}

//----- (00471430) --------------------------------------------------------  // acclient.c:174074
void __thiscall UIElement_Scrollbar::ResizeTo(UIElement_Scrollbar *this, const int _width, const int _height)
{
  UIElement_Scrollbar *v3; // esi@1

  v3 = this;
  UIElement_Text::ResizeTo((UIElement_Text *)&this->vfptr, _width, _height);
  UIElement_Scrollbar::UpdateLayout(v3);
}

//----- (00471450) --------------------------------------------------------  // acclient.c:174084
void __thiscall UIElement_Scrollbar::HandleMouseWheel(UIElement_Scrollbar *this, unsigned int _buttonID)
{
  UIElement_Scrollbar *v2; // esi@1
  bool v3; // bl@1
  unsigned int v4; // eax@2

  v2 = this;
  v3 = _buttonID == 5;
  _buttonID = 0;
  if ( UIElement::GetAttribute_Float((UIElement *)&this->vfptr, 0x86u, (float *)&_buttonID) )
  {
    v4 = v2->m_bitField;
    if ( BYTE1(v4) & 1 )
      UIElement_Scrollbar::HandleMoveSteps(v2, 0x86u, (2 * (v3 != 0) - 1) * ((v4 & 1) != 1 ? 1 : -1));
    else
      UIElement::BroadcastElementMessage((UIElement *)&v2->vfptr, 14 - (v3 != 0), 0, 0);
  }
}

//----- (004714D0) --------------------------------------------------------  // acclient.c:174104
void __userpurge UIElement_Scrollbar::OnSetAttribute(UIElement_Scrollbar *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  BaseProperty *v3; // esi@1
  UIElement_Scrollbar *v4; // edi@1
  BasePropertyValue *v5; // ecx@2
  BasePropertyValue *v6; // ecx@5
  BasePropertyValue *v7; // ecx@8
  BasePropertyValue *v8; // ecx@11
  BasePropertyValue *v9; // ecx@14
  BasePropertyValue *v10; // ecx@17
  BasePropertyValue *v11; // ecx@21
  int v12; // eax@23
  UIElement *v13; // ecx@23
  BasePropertyValue *v14; // ecx@27
  BasePropertyValue *v15; // ecx@30
  BasePropertyValue *v16; // ecx@33
  BasePropertyValue *v17; // ecx@36
  float v18; // ebx@38
  unsigned int v19; // eax@39
  BasePropertyValue *v20; // ecx@42
  BasePropertyValue *v21; // ecx@45
  BasePropertyValue *v22; // ecx@48
  BasePropertyValue *v23; // ecx@51
  BasePropertyValue *v24; // ecx@54
  float f; // [sp+4h] [bp-4h]@1

  f = *(float *)&this;
  v3 = _attribute;
  v4 = this;
  UIElement_Button::OnSetAttribute((UIElement_Button *)&this->vfptr, a2, _attribute);
  switch ( BaseProperty::GetPropertyName(v3) )
  {
    case 0x7Bu:
      v5 = v3->m_pcPropertyValue;
      if ( v5 )
        ((void (__stdcall *)(BaseProperty **))v5->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetHorizontal(v4, (const bool)_attribute);
      UIElement_Scrollbar::UpdateLayout(v4);
      return;
    case 0x83u:
      v6 = v3->m_pcPropertyValue;
      if ( v6 )
        ((void (__stdcall *)(BaseProperty **))v6->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetSmoothMovement(v4, (const bool)_attribute);
      return;
    case 0x82u:
      v7 = v3->m_pcPropertyValue;
      if ( v7 )
        ((void (__stdcall *)(BaseProperty **))v7->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetProportional(v4, (const bool)_attribute);
      UIElement_Scrollbar::UpdateLayout(v4);
      return;
    case 0x76u:
      v8 = v3->m_pcPropertyValue;
      if ( v8 )
        ((void (__stdcall *)(BaseProperty **))v8->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetDisabled(v4, (const bool)_attribute);
      UIElement_Scrollbar::UpdateLayout(v4);
      return;
    case 0x79u:
      v9 = v3->m_pcPropertyValue;
      if ( v9 )
        ((void (__stdcall *)(BaseProperty **))v9->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetHideDisabled(v4, (const bool)_attribute);
      UIElement_Scrollbar::UpdateLayout(v4);
      return;
    case 0x7Au:
      v10 = v3->m_pcPropertyValue;
      if ( v10 )
        ((void (__stdcall *)(BaseProperty **))v10->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetBitMask(v4, (const bool)_attribute, 0x1000000u);
      goto $L99240;
    case 0x88u:
    case 0x89u:
      goto $L99240;
    case 0x7Cu:
      v11 = v3->m_pcPropertyValue;
      if ( v11 )
        ((void (__stdcall *)(BaseProperty **))v11->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetMoveToTouched(v4, (const bool)_attribute);
      v13 = v4->m_pWidget;
      if ( v13 )
      {
        LOBYTE(v12) = (_BYTE)_attribute == 0;
        ((void (__stdcall *)(int))v13->vfptr[22].OnLoseFocus)(v12);
      }
      if ( (_BYTE)_attribute )
        UIElement::SetAttribute_Bool((UIElement *)&v4->vfptr, 0xFu, 0);
      break;
    case 0x7Fu:
      v14 = v3->m_pcPropertyValue;
      if ( v14 )
        ((void (__stdcall *)(BaseProperty **))v14->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetHasStopLocations(v4, (const bool)_attribute);
      break;
    case 0x7Du:
      v15 = v3->m_pcPropertyValue;
      if ( v15 )
        ((void (__stdcall *)(BaseProperty **))v15->vfptr[30].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetHasStopLocations(v4, _attribute != 0);
      break;
    case 0x75u:
      v16 = v3->m_pcPropertyValue;
      if ( v16 )
        ((void (__stdcall *)(BaseProperty **))v16->vfptr[28].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::SetDisallowUpdating(v4, (const bool)_attribute);
      break;
    case 0x86u:
      v17 = v3->m_pcPropertyValue;
      if ( v17 )
        ((void (__stdcall *)(float *))v17->vfptr[34].__vecDelDtor)(&f);
      _attribute = (BaseProperty *)LODWORD(f);
      UIElement_Scrollbar::ValidatePosition(v4, (float *)&_attribute);
      v18 = *(float *)&_attribute;
      if ( (unsigned __int8)AreFloatEqual(f, *(const float *)&_attribute, 0.00019999999) )
      {
$L99240:
        UIElement_Scrollbar::UpdateLayout(v4);
      }
      else
      {
        v19 = (unsigned int)BaseProperty::GetPropertyName(v3);
        UIElement::SetAttribute_Float((UIElement *)&v4->vfptr, v19, v18);
      }
      break;
    case 0x85u:
      if ( v4->m_bitField & 0x10 )
      {
        UIElement_Scrollbar::StartAnimation(v4);
      }
      else
      {
        v20 = v3->m_pcPropertyValue;
        if ( v20 )
          ((void (__stdcall *)(BaseProperty **))v20->vfptr[34].__vecDelDtor)(&_attribute);
        UIElement::SetAttribute_Float((UIElement *)&v4->vfptr, 0x86u, *(float *)&_attribute);
      }
      break;
    case 0x77u:
      v21 = v3->m_pcPropertyValue;
      if ( v21 )
        ((void (__stdcall *)(BaseProperty **))v21->vfptr[42].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::UpdateButtonID_(v4, 1, (unsigned int)_attribute);
      break;
    case 0x78u:
      v22 = v3->m_pcPropertyValue;
      if ( v22 )
        ((void (__stdcall *)(BaseProperty **))v22->vfptr[42].__vecDelDtor)(&_attribute);
      UIElement_Scrollbar::UpdateButtonID_(v4, 0, (unsigned int)_attribute);
      break;
    case 0x80u:
      v23 = v3->m_pcPropertyValue;
      if ( v23 )
        ((void (__stdcall *)(BaseProperty **))v23->vfptr[34].__vecDelDtor)(&_attribute);
      UIElement::SetAttribute_Float((UIElement *)&v4->vfptr, 0x10u, *(float *)&_attribute);
      break;
    case 0x81u:
      v24 = v3->m_pcPropertyValue;
      if ( v24 )
        ((void (__stdcall *)(BaseProperty **))v24->vfptr[34].__vecDelDtor)(&_attribute);
      UIElement::SetAttribute_Float((UIElement *)&v4->vfptr, 0x11u, *(float *)&_attribute);
      break;
    default:
      UIElement_Button::OnSetAttribute((UIElement_Button *)&v4->vfptr, a2, v3);
      break;
  }
}

//----- (00471870) --------------------------------------------------------  // acclient.c:174273
int __thiscall UIElement_Scrollbar::ListenToElementMessage(UIElement_Scrollbar *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebp@1
  UIElement_Scrollbar *v3; // esi@1
  UIElement *v4; // ecx@1
  HashSetData<unsigned long> *v5; // eax@6
  HashSetData<unsigned long> *v6; // eax@11
  char v7; // bl@14
  unsigned int v8; // eax@18
  bool v9; // dl@20
  int v10; // edi@26
  ICIDMVtbl *v11; // eax@26
  int v12; // eax@26
  int v13; // ebx@26
  int result; // eax@26
  int v15; // edx@42
  bool v16; // al@42
  tagPOINT ptMe; // [sp+Ch] [bp-38h]@37
  tagPOINT ptTotalDelta; // [sp+14h] [bp-30h]@42
  UIElementMessageInfo msg; // [sp+1Ch] [bp-28h]@26
  bool i_rMsga; // [sp+48h] [bp+4h]@4

  v2 = i_rMsg;
  v3 = this;
  v4 = i_rMsg->pElement;
  i_rMsga = v4 == v3->m_pWidget || (UIElement_Scrollbar *)v4 == v3 && v3->m_bitField & 0x40;
  v5 = v4->m_mouseDownTable.m_intrusiveTable.m_buckets[7 % v4->m_mouseDownTable.m_intrusiveTable.m_numBuckets];
  if ( v5 )
  {
    while ( v5->m_hashKey != 7 )
    {
      v5 = v5->m_hashNext;
      if ( !v5 )
        goto LABEL_11;
    }
    if ( v5 )
      goto LABEL_17;
  }
LABEL_11:
  v6 = v4->m_mouseDownTable.m_intrusiveTable.m_buckets[0xA % v4->m_mouseDownTable.m_intrusiveTable.m_numBuckets];
  if ( v6 )
  {
    while ( v6->m_hashKey != 10 )
    {
      v6 = v6->m_hashNext;
      if ( !v6 )
      {
        v7 = 0;
        goto LABEL_18;
      }
    }
    if ( v6 )
    {
LABEL_17:
      v7 = 1;
      goto LABEL_18;
    }
  }
  v7 = 0;
LABEL_18:
  v8 = v2->dwParam1;
  v9 = v8 == 7 || v8 == 10;
  switch ( v2->idMessage )
  {
    case 2u:
      if ( v2->idElement == v3->m_eIncrementButtonID || v2->idElement == v3->m_eDecrementButtonID )
      {
        UIElement_Scrollbar::HandleButtonClick(v3, v2);
        result = UIElement_Button::ListenToElementMessage((UIElement_Button *)&v3->vfptr, v2);
      }
      else
      {
        if ( (UIElement_Scrollbar *)v4 != v3 )
          goto LABEL_44;
        UIElementMessageInfo::UIElementMessageInfo(&msg, v2);
        v10 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
        v11 = ICIDM::s_cidm->vfptr;
        msg.ptWindow.x = v10;
        v12 = ((int (*)(void))v11->GetMouseY)();
        v13 = v12;
        msg.ptWindow.y = v12;
        msg.ptElement.x = v10 - UIRegion::GetScreenX0((UIRegion *)&v3->vfptr);
        msg.ptElement.y = v13 - UIRegion::GetScreenY0((UIRegion *)&v3->vfptr);
        UIElement_Scrollbar::HandlePageClick(v3, &msg);
        result = UIElement_Button::ListenToElementMessage((UIElement_Button *)&v3->vfptr, v2);
      }
      break;
    case 0x1Cu:
      if ( !i_rMsga || !v7 )
        goto LABEL_44;
      UIElement_Scrollbar::StartWidgetDrag(v3, v2);
      result = UIElement_Button::ListenToElementMessage((UIElement_Button *)&v3->vfptr, v2);
      break;
    case 0x1Du:
      if ( !i_rMsga || !v9 || !v3->m_bWidgetDragActive )
        goto LABEL_44;
      v3->m_bWidgetDragActive = 0;
      result = UIElement_Button::ListenToElementMessage((UIElement_Button *)&v3->vfptr, v2);
      break;
    case 0x1Eu:
      if ( !i_rMsga || !v7 )
        goto LABEL_44;
      UIElement_Scrollbar::GetScrollbarPositionFromMessage(v3, (UIElementMessageInfo *)&ptMe, v2);
      if ( abs(UIElement_Scrollbar::GetSecondaryCoordinate(v3, &ptMe)) <= 100 )
      {
        if ( v3->m_bitField & 0x40 )
        {
          UIElement_Scrollbar::ScrollToPoint(v3, v2, v3->m_bWidgetDragActive);
        }
        else
        {
          v15 = v3->m_ptDragStart.y;
          ptTotalDelta.x = ptMe.x - v3->m_ptDragStart.x;
          v16 = v3->m_bWidgetDragActive;
          ptTotalDelta.y = ptMe.y - v15;
          UIElement_Scrollbar::ScrollNPixelsFromReset(v3, &ptTotalDelta, v16);
        }
        v3->m_bWidgetDragActive = 1;
        goto LABEL_44;
      }
      if ( !v3->m_bWidgetDragActive )
        goto LABEL_44;
      UIElement_Scrollbar::SetScrollbarPosition(v3, v3->m_fResetPosition, 0);
      v3->m_bWidgetDragActive = 0;
      result = UIElement_Button::ListenToElementMessage((UIElement_Button *)&v3->vfptr, v2);
      break;
    default:
LABEL_44:
      result = UIElement_Button::ListenToElementMessage((UIElement_Button *)&v3->vfptr, v2);
      break;
  }
  return result;
}

//----- (006EC030) --------------------------------------------------------  // acclient.c:767825
int _E73_72()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_11, "Misc.TooltipEnable");
  return atexit(_E74_54);
}

//----- (006EC050) --------------------------------------------------------  // acclient.c:767832
int _E76_40()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_11, "Misc.TooltipDelay");
  return atexit(_E77_68);
}

//----- (006EC070) --------------------------------------------------------  // acclient.c:767839
int _E1_67()
{
  return atexit(_E2_67);
}

//----- (0075E820) --------------------------------------------------------  // acclient.c:886774
void __cdecl _E74_54()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E850) --------------------------------------------------------  // acclient.c:886787
void __cdecl _E77_68()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

