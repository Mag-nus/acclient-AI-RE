/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCGAppearancePage
   Object     : GAME\game_ui_misc\gmCGAppearancePage.obj
   Functions  : 56
   Addresses  : 0047C7D0 - 006ECE80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0047C7D0) --------------------------------------------------------  // acclient.c:185456
void __thiscall gmCGAppearancePage::PostInit(gmCGAppearancePage *this)
{
  UIListener *v1; // esi@1
  GlobalEventHandler *v2; // eax@1
  int v3; // edx@2

  v1 = (UIListener *)this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v3 = (int)&v1[12].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7];
  else
    v3 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100016u, (NoticeHandler *)v3);
  UIListener::RegisterForGlobalMessage(v1, 3u);
}

//----- (0047C810) --------------------------------------------------------  // acclient.c:185474
gmCGAppearancePage *__thiscall gmCGAppearancePage::DynamicCast(gmCGAppearancePage *this, unsigned int i_eType)
{
  gmCGAppearancePage *result; // eax@1

  result = this;
  if ( i_eType != 268435516 )
    result = (gmCGAppearancePage *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0047C830) --------------------------------------------------------  // acclient.c:185485
signed int gmCGAppearancePage::GetUIElementType()
{
  return 268435516;
}

//----- (0047C840) --------------------------------------------------------  // acclient.c:185491
void __thiscall gmCGAppearancePage::RecvNotice_PlayerObjDescChanged(gmCGAppearancePage *this)
{
  gmCGAppearancePage *v1; // esi@1

  v1 = this;
  if ( UIElement::IsVisible((UIElement *)&this[-1].m_desc.m_type) )
    gmCG3DView::Update((gmCG3DView *)v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_numBuckets);
}

//----- (0047C860) --------------------------------------------------------  // acclient.c:185501
void __thiscall gmCGAppearancePage::SetShade(gmCGAppearancePage *this, long double _dShade)
{
  gmCGAppearancePage *v2; // esi@1
  float _val; // ST04_4@1
  int v4; // eax@1

  v2 = this;
  _val = _dShade;
  UIElement::SetAttribute_Float((UIElement *)&this->m_pShadeScroll->vfptr, 0x86u, _val);
  CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
  switch ( v2->m_eCurPart )
  {
    case 1:
      CharGenState::SetHairShade((CharGenState *)v4, _dShade);
      break;
    case 3:
    case 4:
    case 5:
      CharGenState::SetSkinShade((CharGenState *)v4, _dShade);
      break;
    case 6:
      *(long double *)(v4 + 344) = _dShade;
      break;
    case 7:
      *(long double *)(v4 + 352) = _dShade;
      break;
    case 8:
      *(long double *)(v4 + 360) = _dShade;
      break;
    case 9:
      *(long double *)(v4 + 368) = _dShade;
      break;
    default:
      break;
  }
  if ( UIElement::IsVisible((UIElement *)&v2->vfptr) )
    gmCG3DView::Update(v2->m_p3DView);
}

//----- (0047C960) --------------------------------------------------------  // acclient.c:185541
void __thiscall gmCGAppearancePage::DoZoomAnimation(gmCGAppearancePage *this)
{
  unsigned int v1; // edx@2
  long double v2; // st7@3
  long double v3; // st7@5
  char *v4; // eax@5
  char *v5; // edx@5

  if ( this->m_dAnimDuration < 0.0 )
  {
    LODWORD(this->m_dAnimDuration) = 858993459;
    HIDWORD(this->m_dAnimDuration) = 1071854387;
    v1 = Timer::cur_time.Param;
    LODWORD(this->m_dAnimStartTime) = Timer::cur_time.Cmd;
    HIDWORD(this->m_dAnimStartTime) = v1;
  }
  v2 = COERCE_DOUBLE(Timer::cur_time.Cmd) - this->m_dAnimStartTime;
  if ( v2 >= this->m_dAnimDuration )
  {
    this->m_bShouldZoomAnimate = 0;
    v2 = this->m_dAnimDuration;
  }
  v3 = v2 / this->m_dAnimDuration;
  v4 = (char *)&this->m_vectCurPosition;
  v5 = (char *)&this->m_vectCurDirection;
  *(float *)v4 = (this->m_vectTargPosition.x - this->m_vectStartPosition.x) * v3 + this->m_vectStartPosition.x;
  *((float *)v4 + 1) = (this->m_vectTargPosition.y - this->m_vectStartPosition.y) * v3 + this->m_vectStartPosition.y;
  *((float *)v4 + 2) = (this->m_vectTargPosition.z - this->m_vectStartPosition.z) * v3 + this->m_vectStartPosition.z;
  *(float *)v5 = (this->m_vectTargDirection.x - this->m_vectStartDirection.x) * v3 + this->m_vectStartDirection.x;
  *((float *)v5 + 1) = (this->m_vectTargDirection.y - this->m_vectStartDirection.y) * v3 + this->m_vectStartDirection.y;
  *((float *)v5 + 2) = (this->m_vectTargDirection.z - this->m_vectStartDirection.z) * v3 + this->m_vectStartDirection.z;
  gmCG3DView::SetCamera(this->m_p3DView, &this->m_vectCurPosition, &this->m_vectCurDirection);
}

//----- (0047CA80) --------------------------------------------------------  // acclient.c:185576
void __thiscall gmCGAppearancePage::DoRotation(gmCGAppearancePage *this)
{
  unsigned int v1; // edx@2
  long double v2; // st7@3
  long double v3; // st6@3
  float v4; // eax@10

  if ( this->m_dLastRotateTime < 0.0 )
  {
    v1 = Timer::cur_time.Param;
    LODWORD(this->m_dLastRotateTime) = Timer::cur_time.Cmd;
    HIDWORD(this->m_dLastRotateTime) = v1;
  }
  v2 = *(double *)&Timer::cur_time;
  v3 = (COERCE_DOUBLE(Timer::cur_time.Cmd) - this->m_dLastRotateTime) / this->m_dRotationPerSec * 360.0;
  if ( this->m_eRotateDir == 1 )
    this->m_fCurHeading = v3 + this->m_fCurHeading;
  else
    this->m_fCurHeading = this->m_fCurHeading - v3;
  if ( this->m_fCurHeading < 0.0 )
    this->m_fCurHeading = this->m_fCurHeading + 360.0;
  if ( this->m_fCurHeading > 360.0 )
    this->m_fCurHeading = this->m_fCurHeading - 360.0;
  v4 = this->m_fCurHeading;
  this->m_dLastRotateTime = v2;
  gmCG3DView::SetPlayerHeading(this->m_p3DView, v4);
}

//----- (0047CB50) --------------------------------------------------------  // acclient.c:185605
void __thiscall gmCGAppearancePage::Rotate(gmCGAppearancePage *this, gmCGAppearancePage::ERotateDirection _eDir)
{
  gmCGAppearancePage *v2; // esi@1

  v2 = this;
  if ( this->m_bRotating && _eDir == this->m_eRotateDir )
  {
    this->m_bRotating = 0;
  }
  else
  {
    if ( _eDir == 1 )
    {
      ((void (__stdcall *)(_DWORD))this->m_pRotateCounterClockButton->vfptr[13].__vecDelDtor)(1);
    }
    else if ( _eDir == 2 )
    {
      ((void (__stdcall *)(_DWORD))this->m_pRotateClockButton->vfptr[13].__vecDelDtor)(1);
    }
    v2->m_eRotateDir = _eDir;
    LODWORD(v2->m_dLastRotateTime) = 0;
    HIDWORD(v2->m_dLastRotateTime) = -1074790400;
    v2->m_bRotating = 1;
  }
}

//----- (0047CBD0) --------------------------------------------------------  // acclient.c:185632
long double __cdecl MathLib::Clamp(const long double _Number, const long double _MinValue, const long double _MaxValue)
{
  const long double result; // st7@2

  if ( _Number <= _MaxValue )
  {
    if ( _Number >= _MinValue )
      result = _Number;
    else
      result = _MinValue;
  }
  else
  {
    result = _MaxValue;
  }
  return result;
}

//----- (0047CC00) --------------------------------------------------------  // acclient.c:185651
void *__thiscall EyesStrip_CG::vector_deleting_destructor(EyesStrip_CG *this, unsigned int a2)
{
  EyesStrip_CG *v2; // edi@1
  int v3; // eax@2
  char *v4; // ebp@2
  EyesStrip_CG *v5; // esi@2
  int v6; // eax@2
  int v7; // edi@3
  void *result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].objDesc_Bald.num_anim_part_changes;
    v4 = (char *)&this[-1].objDesc_Bald.num_anim_part_changes;
    v5 = &this[v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        --v5;
        v5->vfptr = (EyesStrip_CGVtbl *)&EyesStrip_CG::vftable;
        ObjDesc::~ObjDesc(&v5->objDesc_Bald);
        ObjDesc::~ObjDesc(&v5->objDesc);
        --v7;
      }
      while ( v7 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    this->vfptr = (EyesStrip_CGVtbl *)&EyesStrip_CG::vftable;
    ObjDesc::~ObjDesc(&this->objDesc_Bald);
    ObjDesc::~ObjDesc(&v2->objDesc);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}
// 79FA84: using guessed type void (__thiscall *EyesStrip_CG::vftable)(EyesStrip_CG *this, struct Archive *);

//----- (0047CC80) --------------------------------------------------------  // acclient.c:185699
BOOL __thiscall SmartArray<int,1>::ShouldDeallocate_(SmartArray<int,1> *this)
{
  return (this->m_sizeAndDeallocate & 0x80000000) == 2147483648;
}

//----- (0047CCA0) --------------------------------------------------------  // acclient.c:185705
int __cdecl PalSet::Get(IDClass<_tagDataID,32,0> did)
{
  QualifiedDataID *v1; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, did, 0x18u);
  return DBObj::Get(v1);
}

//----- (0047CCC0) --------------------------------------------------------  // acclient.c:185715
void __userpurge gmCGAppearancePage::gmCGAppearancePage(gmCGAppearancePage *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGAppearancePage *v4; // esi@1
  int v5; // ecx@1
  signed int v6; // edx@1
  int v7; // ecx@3
  signed int v8; // edx@3

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCGAppearancePage::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmCGAppearancePage::vftable;
  v4->m_pPlayerSystem = 0;
  v4->m_pFemaleButton = 0;
  v4->m_pMaleButton = 0;
  v4->m_pFaceButton = 0;
  v4->m_pClothesButton = 0;
  v4->m_pZoomInButton = 0;
  v4->m_pZoomOutButton = 0;
  v4->m_pRotateClockButton = 0;
  v4->m_pRotateCounterClockButton = 0;
  v4->m_pShadeScroll = 0;
  v4->m_pGradCircle = 0;
  v4->m_pGradGraphic = 0;
  v4->m_pGradPlug = 0;
  v4->m_pCurSelection = 0;
  v4->m_iCurColor = -1;
  v4->m_iHoldheadgear = -999;
  v4->m_bShouldZoomAnimate = 0;
  v4->m_bRotating = 0;
  LODWORD(v4->m_vectTargPosition.x) = 0;
  LODWORD(v4->m_vectTargPosition.y) = 0;
  LODWORD(v4->m_vectTargPosition.z) = 0;
  LODWORD(v4->m_vectCurPosition.x) = 0;
  LODWORD(v4->m_vectCurPosition.y) = 0;
  LODWORD(v4->m_vectCurPosition.z) = 0;
  LODWORD(v4->m_vectTargDirection.x) = 0;
  LODWORD(v4->m_vectTargDirection.y) = 0;
  LODWORD(v4->m_vectTargDirection.z) = 0;
  LODWORD(v4->m_vectCurDirection.x) = 0;
  LODWORD(v4->m_vectCurDirection.y) = 0;
  LODWORD(v4->m_vectCurDirection.z) = 0;
  LODWORD(v4->m_fCurHeading) = 0;
  LODWORD(v4->m_dAnimStartTime) = 0;
  HIDWORD(v4->m_dAnimStartTime) = 0;
  LODWORD(v4->m_dAnimDuration) = 0;
  HIDWORD(v4->m_dAnimDuration) = 0;
  LODWORD(v4->m_dRotationPerSec) = 0;
  HIDWORD(v4->m_dRotationPerSec) = 1074266112;
  v4->m_eRotateDir = 0;
  v5 = (int)v4->m_tChoices;
  v6 = 9;
  do
  {
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 12) = 0;
    *(_DWORD *)(v5 + 16) = 0;
    *(_DWORD *)(v5 + 20) = 0;
    v5 += 24;
    --v6;
  }
  while ( v6 );
  v4->m_eCurPart = 1;
  v7 = (int)v4->m_tColorWheel;
  v8 = 9;
  do
  {
    *(_DWORD *)v7 = 0;
    *(_DWORD *)(v7 + 4) = 0;
    *(_DWORD *)(v7 + 8) = 0;
    *(_DWORD *)(v7 + 12) = 0;
    *(_DWORD *)(v7 + 16) = 0;
    *(_DWORD *)(v7 + 20) = 0;
    *(_DWORD *)(v7 + 24) = 0;
    v7 += 28;
    --v8;
  }
  while ( v8 );
}
// 79FA90: using guessed type bool (__thiscall *gmCGAppearancePage::vftable)(DBCache *this);
// 79FD38: using guessed type int (__thiscall *gmCGAppearancePage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047CE40) --------------------------------------------------------  // acclient.c:185802
UIElement_Field *__thiscall gmCGAppearancePage::vector_deleting_destructor(gmCGAppearancePage *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCGAppearancePage::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmCGAppearancePage::vftable;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79FA90: using guessed type bool (__thiscall *gmCGAppearancePage::vftable)(DBCache *this);
// 79FD38: using guessed type int (__thiscall *gmCGAppearancePage::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0047CEA0) --------------------------------------------------------  // acclient.c:185827
void __usercall gmCGAppearancePage::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCGAppearancePage *v3; // eax@1

  v3 = (gmCGAppearancePage *)operator new(0x8E0u);
  if ( v3 )
    gmCGAppearancePage::gmCGAppearancePage(v3, a1, _layout, _full_desc);
}

//----- (0047CED0) --------------------------------------------------------  // acclient.c:185837
void __thiscall gmCGAppearancePage::ListenToGlobalMessage(gmCGAppearancePage *this, unsigned int _messageID, int _data_int)
{
  gmCGAppearancePage *v3; // esi@1

  v3 = this;
  if ( _messageID == 3 )
  {
    if ( this->m_bShouldZoomAnimate )
      gmCGAppearancePage::DoZoomAnimation(this);
    if ( v3->m_bRotating )
      gmCGAppearancePage::DoRotation(v3);
  }
}

//----- (0047CF00) --------------------------------------------------------  // acclient.c:185852
void __thiscall gmCGAppearancePage::ZoomIn(gmCGAppearancePage *this)
{
  gmCGAppearancePage *v1; // esi@1
  int v2; // eax@2
  int v3; // eax@2
  UIElement_Button *v4; // ecx@9

  v1 = this;
  if ( this->m_bZoomedIn )
  {
    ((void (__stdcall *)(signed int))this->m_pZoomInButton->vfptr[13].__vecDelDtor)(6);
  }
  else
  {
    this->m_vectStartDirection.x = this->m_vectCurDirection.x;
    this->m_vectStartDirection.y = this->m_vectCurDirection.y;
    this->m_vectStartDirection.z = this->m_vectCurDirection.z;
    this->m_vectStartPosition.x = this->m_vectCurPosition.x;
    this->m_vectStartPosition.y = this->m_vectCurPosition.y;
    this->m_vectStartPosition.z = this->m_vectCurPosition.z;
    CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
    v3 = *(_DWORD *)(v2 + 212);
    if ( v3 == 12 )
    {
      LODWORD(v1->m_vectTargPosition.y) = -1075000115;
      LODWORD(v1->m_vectTargPosition.z) = 1072483533;
    }
    else if ( v3 == 13 )
    {
      LODWORD(v1->m_vectTargPosition.y) = -1069337805;
      LODWORD(v1->m_vectTargPosition.z) = 1076887552;
    }
    else
    {
      LODWORD(v1->m_vectTargPosition.z) = 1070805811;
      if ( v3 == 7 )
        LODWORD(v1->m_vectTargPosition.y) = -1084647014;
      else
        LODWORD(v1->m_vectTargPosition.y) = -1089680179;
    }
    LODWORD(v1->m_vectTargPosition.x) = 0;
    LODWORD(v1->m_vectTargDirection.x) = 0;
    LODWORD(v1->m_vectTargDirection.y) = 0;
    LODWORD(v1->m_vectTargDirection.z) = 0;
    v4 = v1->m_pZoomInButton;
    v1->m_bShouldZoomAnimate = 1;
    LODWORD(v1->m_dAnimDuration) = -1717986918;
    HIDWORD(v1->m_dAnimDuration) = -1078355559;
    ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(6);
    ((void (__stdcall *)(signed int))v1->m_pZoomOutButton->vfptr[13].__vecDelDtor)(1);
    gmCG3DView::StopAnimation(v1->m_p3DView);
    v1->m_bZoomedIn = 1;
  }
}

//----- (0047D050) --------------------------------------------------------  // acclient.c:185908
void __thiscall gmCGAppearancePage::ZoomOut(gmCGAppearancePage *this)
{
  gmCGAppearancePage *v1; // esi@1
  int v2; // eax@2
  int v3; // eax@2
  UIElement_Button *v4; // ecx@7

  v1 = this;
  if ( this->m_bZoomedIn )
  {
    this->m_vectStartDirection.x = this->m_vectCurDirection.x;
    this->m_vectStartDirection.y = this->m_vectCurDirection.y;
    this->m_vectStartDirection.z = this->m_vectCurDirection.z;
    this->m_vectStartPosition.x = this->m_vectCurPosition.x;
    this->m_vectStartPosition.y = this->m_vectCurPosition.y;
    this->m_vectStartPosition.z = this->m_vectCurPosition.z;
    CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
    v3 = *(_DWORD *)(v2 + 212);
    if ( v3 == 12 )
    {
      LODWORD(v1->m_vectTargPosition.y) = -1066192077;
      LODWORD(v1->m_vectTargPosition.z) = 1066611507;
    }
    else if ( v3 == 13 )
    {
      LODWORD(v1->m_vectTargPosition.y) = -1061788058;
      LODWORD(v1->m_vectTargPosition.z) = 1070805811;
    }
    else
    {
      LODWORD(v1->m_vectTargPosition.y) = -1071644672;
      LODWORD(v1->m_vectTargPosition.z) = 1064514355;
    }
    LODWORD(v1->m_vectTargPosition.x) = 0;
    LODWORD(v1->m_vectTargDirection.x) = 0;
    LODWORD(v1->m_vectTargDirection.y) = 0;
    LODWORD(v1->m_vectTargDirection.z) = 0;
    v4 = v1->m_pZoomInButton;
    v1->m_bShouldZoomAnimate = 1;
    LODWORD(v1->m_dAnimDuration) = -1717986918;
    HIDWORD(v1->m_dAnimDuration) = -1078355559;
    ((void (__stdcall *)(signed int))v4->vfptr[13].__vecDelDtor)(1);
    ((void (__stdcall *)(signed int))v1->m_pZoomOutButton->vfptr[13].__vecDelDtor)(6);
    gmCG3DView::StartAnimation(v1->m_p3DView);
    v1->m_bZoomedIn = 0;
  }
  else
  {
    ((void (__stdcall *)(signed int))this->m_pZoomOutButton->vfptr[13].__vecDelDtor)(6);
  }
}

//----- (0047D190) --------------------------------------------------------  // acclient.c:185961
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *v2; // esi@1
  HashTableData<unsigned long,Sex_CG> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable;
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
// 79FE74: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable)(void *, char);

//----- (0047D1D0) --------------------------------------------------------  // acclient.c:185982
void __thiscall SmartArray<IDClass<_tagDataID,32,0>,1>::~SmartArray<IDClass<_tagDataID,32,0>,1>(SmartArray<IDClass<_tagDataID,32,0>,1> *this)
{
  IDClass<_tagDataID,32,0> *v1; // ecx@2

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
      operator delete[](&v1[-1]);
  }
}

//----- (0047D1F0) --------------------------------------------------------  // acclient.c:185995
void __thiscall SmartArray<Skill_CG,1>::~SmartArray<Skill_CG,1>(SmartArray<Skill_CG,1> *this)
{
  Skill_CG *v1; // edx@2
  int v2; // ecx@3
  int v3; // eax@3
  int v4; // ecx@3
  int v5; // ecx@4

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( this->m_data )
    {
      v2 = v1[-1].primaryCost;
      v3 = (int)&v1[v2];
      v4 = v2 - 1;
      if ( v4 >= 0 )
      {
        v5 = v4 + 1;
        do
        {
          v3 -= 16;
          --v5;
          *(_DWORD *)v3 = &Skill_CG::vftable;
        }
        while ( v5 );
      }
      operator delete[](&v1[-1].primaryCost);
    }
  }
}
// 79FA7C: using guessed type void (__thiscall *Skill_CG::vftable)(Skill_CG *this, struct Archive *);

//----- (0047D240) --------------------------------------------------------  // acclient.c:186029
void __thiscall SmartArray<HairStyle_CG,1>::~SmartArray<HairStyle_CG,1>(SmartArray<HairStyle_CG,1> *this)
{
  HairStyle_CG *v1; // ecx@2
  int v2; // eax@3
  void *v3; // ebx@3
  int v4; // esi@3
  int v5; // eax@3
  int v6; // edi@4

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
    {
      v2 = v1[-1].objDesc.num_anim_part_changes;
      v3 = &v1[-1].objDesc.num_anim_part_changes;
      v4 = (int)&v1[v2];
      v5 = v2 - 1;
      if ( v5 >= 0 )
      {
        v6 = v5 + 1;
        do
        {
          v4 -= 60;
          *(_DWORD *)v4 = &HairStyle_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v4 + 16));
          --v6;
        }
        while ( v6 );
      }
      operator delete[](v3);
    }
  }
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (0047D2A0) --------------------------------------------------------  // acclient.c:186066
void __thiscall SmartArray<EyesStrip_CG,1>::~SmartArray<EyesStrip_CG,1>(SmartArray<EyesStrip_CG,1> *this)
{
  EyesStrip_CG *v1; // ecx@2
  int v2; // eax@3
  void *v3; // ebx@3
  int v4; // esi@3
  int v5; // eax@3
  int v6; // edi@4

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
    {
      v2 = v1[-1].objDesc_Bald.num_anim_part_changes;
      v3 = &v1[-1].objDesc_Bald.num_anim_part_changes;
      v4 = (int)&v1[v2];
      v5 = v2 - 1;
      if ( v5 >= 0 )
      {
        v6 = v5 + 1;
        do
        {
          v4 -= 100;
          *(_DWORD *)v4 = &EyesStrip_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v4 + 56));
          ObjDesc::~ObjDesc((ObjDesc *)(v4 + 12));
          --v6;
        }
        while ( v6 );
      }
      operator delete[](v3);
    }
  }
}
// 79FA84: using guessed type void (__thiscall *EyesStrip_CG::vftable)(EyesStrip_CG *this, struct Archive *);

//----- (0047D300) --------------------------------------------------------  // acclient.c:186104
void __thiscall SmartArray<FaceStrip_CG,1>::~SmartArray<FaceStrip_CG,1>(SmartArray<FaceStrip_CG,1> *this)
{
  FaceStrip_CG *v1; // ecx@2
  int v2; // eax@3
  void *v3; // ebx@3
  int v4; // esi@3
  int v5; // eax@3
  int v6; // edi@4

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
    {
      v2 = v1[-1].objDesc.num_anim_part_changes;
      v3 = &v1[-1].objDesc.num_anim_part_changes;
      v4 = (int)&v1[v2];
      v5 = v2 - 1;
      if ( v5 >= 0 )
      {
        v6 = v5 + 1;
        do
        {
          v4 -= 52;
          *(_DWORD *)v4 = &FaceStrip_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v4 + 8));
          --v6;
        }
        while ( v6 );
      }
      operator delete[](v3);
    }
  }
}
// 79FA88: using guessed type void (__thiscall *FaceStrip_CG::vftable)(FaceStrip_CG *this, struct Archive *);

//----- (0047D360) --------------------------------------------------------  // acclient.c:186141
void *__thiscall Style_CG::vector_deleting_destructor(Style_CG *this, unsigned int a2)
{
  Style_CG *v2; // esi@1
  unsigned int v3; // eax@2
  char *v4; // ebx@2
  Style_CG *v5; // edi@2
  int v6; // eax@2
  PSRefBufferCharData<char> *v7; // esi@4
  int v8; // esi@4
  void *result; // eax@10
  char *v10; // edi@11
  int v11; // [sp+4h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].weenieDefault.id;
    v4 = (char *)&this[-1].weenieDefault;
    v5 = &this[v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v11 = v6 + 1;
      do
      {
        v7 = v5[-1].name.m_charbuffer;
        --v5;
        v8 = (int)&v7[-2].m_data[12];
        v5->vfptr = (Style_CGVtbl *)&Style_CG::vftable;
        if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        --v11;
      }
      while ( v11 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v10 = &this->name.m_charbuffer[-2].m_data[12];
    this->vfptr = (Style_CGVtbl *)&Style_CG::vftable;
    if ( !InterlockedDecrement((volatile LONG *)v10 + 1) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (0047D420) --------------------------------------------------------  // acclient.c:186195
void __thiscall Template_CG::~Template_CG(Template_CG *this)
{
  Template_CG *v1; // esi@1
  int v2; // esi@5

  v1 = this;
  this->vfptr = (Template_CGVtbl *)&Template_CG::vftable;
  if ( (this->mPrimarySkillsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->mPrimarySkillsList.m_data);
  if ( (v1->mNormalSkillsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->mNormalSkillsList.m_data);
  v2 = (int)&v1->name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) )
  {
    if ( v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  }
}
// 79FE78: using guessed type void (__thiscall *Template_CG::vftable)(Template_CG *this, struct Archive *);

//----- (0047D490) --------------------------------------------------------  // acclient.c:186216
void __cdecl gmCGAppearancePage::Register()
{
  UIElement::RegisterElementClass(
    0x1000003Cu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmCGAppearancePage::Create);
}

//----- (0047D4B0) --------------------------------------------------------  // acclient.c:186224
void __thiscall gmCGAppearancePage::SetChoice(gmCGAppearancePage *this, gmCGAppearancePage::EType _eType)
{
  gmCGAppearancePage *v2; // esi@1
  UIElement *v3; // ecx@1
  signed int v4; // eax@3
  int v5; // ST00_4@5
  CharGenState *v6; // eax@5
  int v7; // eax@7
  CharGenState *v8; // eax@7

  v2 = this;
  v3 = this->m_pClothesChoices;
  v2->m_eCurType = _eType;
  ((void (__stdcall *)(_DWORD))v3->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v2->m_pFaceChoices->vfptr[2].__vecDelDtor)(0);
  if ( _eType == 1 )
  {
    ((void (__stdcall *)(signed int))v2->m_pFaceButton->vfptr[13].__vecDelDtor)(268435479);
    ((void (__stdcall *)(signed int))v2->m_pClothesButton->vfptr[13].__vecDelDtor)(268435478);
    CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
    v2->m_iHoldheadgear = *(_DWORD *)(v7 + 244);
    CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
    CharGenState::SetHeadgearStyle(v8, -1);
    ((void (__stdcall *)(signed int))v2->m_pFaceChoices->vfptr[2].__vecDelDtor)(1);
    gmCGAppearancePage::ZoomIn(v2);
  }
  else if ( _eType == 2 )
  {
    v2->m_vectStartDirection.x = v2->m_vectCurDirection.x;
    v2->m_vectStartDirection.y = v2->m_vectCurDirection.y;
    v2->m_vectStartDirection.z = v2->m_vectCurDirection.z;
    v2->m_vectStartPosition.x = v2->m_vectCurPosition.x;
    v2->m_vectStartPosition.y = v2->m_vectCurPosition.y;
    v2->m_vectStartPosition.z = v2->m_vectCurPosition.z;
    ((void (__stdcall *)(signed int))v2->m_pFaceButton->vfptr[13].__vecDelDtor)(268435478);
    ((void (__stdcall *)(signed int))v2->m_pClothesButton->vfptr[13].__vecDelDtor)(268435479);
    v4 = v2->m_iHoldheadgear;
    if ( v4 > -2 && v4 < v2->m_tChoices[5].iNumChoices )
    {
      v5 = v2->m_iHoldheadgear;
      CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
      CharGenState::SetHeadgearStyle(v6, v5);
    }
    ((void (__stdcall *)(signed int))v2->m_pClothesChoices->vfptr[2].__vecDelDtor)(1);
    gmCGAppearancePage::ZoomOut(v2);
  }
}

//----- (0047D600) --------------------------------------------------------  // acclient.c:186273
void *__thiscall Template_CG::vector_deleting_destructor(Template_CG *this, unsigned int a2)
{
  char v2; // bl@1
  Template_CG *v3; // esi@1
  unsigned int v4; // eax@2
  char *v5; // edi@2
  Template_CG *v6; // ebp@2
  int v7; // eax@2
  int v8; // edi@3
  int v9; // esi@8
  void *result; // eax@15
  int v11; // [sp+8h] [bp-8h]@3
  char *v12; // [sp+Ch] [bp-4h]@2

  v2 = a2;
  v3 = this;
  if ( a2 & 2 )
  {
    v4 = this[-1].mPrimarySkillsList.m_num;
    v5 = (char *)&this[-1].mPrimarySkillsList.m_num;
    v6 = &this[v4];
    v7 = v4 - 1;
    v12 = (char *)&this[-1].mPrimarySkillsList.m_num;
    if ( v7 >= 0 )
    {
      v8 = (int)&v6->mNormalSkillsList.m_sizeAndDeallocate;
      v11 = v7 + 1;
      do
      {
        --v6;
        v8 -= 64;
        v6->vfptr = (Template_CGVtbl *)&Template_CG::vftable;
        if ( (*(_DWORD *)(v8 + 12) & 0x80000000) == 0x80000000 )
          operator delete[](*(void **)(v8 + 8));
        if ( (*(_DWORD *)v8 & 0x80000000) == 0x80000000 )
          operator delete[](*(void **)(v8 - 4));
        v9 = *(_DWORD *)(v8 - 40) - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        --v11;
      }
      while ( v11 );
      v5 = v12;
      v2 = a2;
    }
    if ( v2 & 1 )
      operator delete[](v5);
    result = v5;
  }
  else
  {
    Template_CG::~Template_CG(this);
    if ( a2 & 1 )
      operator delete(v3);
    result = v3;
  }
  return result;
}
// 79FE78: using guessed type void (__thiscall *Template_CG::vftable)(Template_CG *this, struct Archive *);

//----- (0047D6F0) --------------------------------------------------------  // acclient.c:186334
void __thiscall Sex_CG::~Sex_CG(Sex_CG *this)
{
  Sex_CG *v1; // esi@1
  Style_CG *v2; // ecx@4
  Style_CG *v3; // ecx@7
  Style_CG *v4; // ecx@10
  Style_CG *v5; // ecx@13
  IDClass<_tagDataID,32,0> *v6; // eax@16
  IDClass<_tagDataID,32,0> *v7; // eax@19
  int v8; // esi@21

  v1 = this;
  this->vfptr = (Sex_CGVtbl *)&Sex_CG::vftable;
  if ( (this->mClothingColorsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->mClothingColorsList.m_data);
  if ( (v1->mFootwearList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v2 = v1->mFootwearList.m_data;
    if ( v2 )
      Style_CG::vector_deleting_destructor(v2, 3u);
  }
  if ( (v1->mPantsList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v3 = v1->mPantsList.m_data;
    if ( v3 )
      Style_CG::vector_deleting_destructor(v3, 3u);
  }
  if ( (v1->mShirtList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v4 = v1->mShirtList.m_data;
    if ( v4 )
      Style_CG::vector_deleting_destructor(v4, 3u);
  }
  if ( (v1->mHeadgearList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v5 = v1->mHeadgearList.m_data;
    if ( v5 )
      Style_CG::vector_deleting_destructor(v5, 3u);
  }
  SmartArray<FaceStrip_CG,1>::~SmartArray<FaceStrip_CG,1>(&v1->mMouthStripList);
  SmartArray<FaceStrip_CG,1>::~SmartArray<FaceStrip_CG,1>(&v1->mNoseStripList);
  SmartArray<EyesStrip_CG,1>::~SmartArray<EyesStrip_CG,1>(&v1->mEyeStripList);
  if ( (v1->mEyeColorList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v6 = v1->mEyeColorList.m_data;
    if ( v6 )
      operator delete[](&v6[-1]);
  }
  SmartArray<HairStyle_CG,1>::~SmartArray<HairStyle_CG,1>(&v1->mHairStyleList);
  if ( (v1->mHairColorList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v7 = v1->mHairColorList.m_data;
    if ( v7 )
      operator delete[](&v7[-1]);
  }
  ObjDesc::~ObjDesc(&v1->objDesc);
  v8 = (int)&v1->name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) )
  {
    if ( v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
}
// 79FE7C: using guessed type void (__thiscall *Sex_CG::vftable)(Sex_CG *this, struct Archive *);

//----- (0047D850) --------------------------------------------------------  // acclient.c:186400
void __thiscall gmCGAppearancePage::DoColorSpots(gmCGAppearancePage *this, int _iPart)
{
  signed int v2; // ebx@1
  char *v3; // esi@1
  QualifiedDataID *v4; // eax@2
  int v5; // edi@2
  QualifiedDataID *v6; // eax@2
  RenderSurface *v7; // ebp@2
  double v8; // st7@3
  int v9; // eax@3
  double v10; // st7@3
  int v11; // ecx@5
  double v12; // st7@5
  bool v13; // zf@7
  RenderSurface *v14; // ebx@8
  int v15; // eax@9
  InterfaceVtbl *v16; // ebp@9
  PixelFormatID v17; // eax@9
  Graphic *v18; // eax@9
  int v19; // eax@10
  Graphic *v20; // eax@16
  Graphic *v21; // eax@17
  int i; // [sp+14h] [bp-4Ch]@1
  IDClass<_tagDataID,32,0> idBlank; // [sp+18h] [bp-48h]@2
  IDClass<_tagDataID,32,0> idCap; // [sp+1Ch] [bp-44h]@2
  int v25; // [sp+20h] [bp-40h]@9
  int v26; // [sp+24h] [bp-3Ch]@9
  DBObjGrabber<RenderSurface> spCapBullet; // [sp+28h] [bp-38h]@2
  gmCGAppearancePage *v28; // [sp+2Ch] [bp-34h]@1
  QualifiedDataID v29; // [sp+30h] [bp-30h]@2
  QualifiedDataID v30; // [sp+38h] [bp-28h]@2
  RGBAColor newColor; // [sp+40h] [bp-20h]@3
  RGBAColor black; // [sp+50h] [bp-10h]@3

  v2 = 0;
  v28 = this;
  i = 0;
  v3 = (char *)&this->m_tColorWheel[0].pGraphic;
  do
  {
    DBObj::GetDIDByEnum(&idBlank, 268435469, 7);
    DBObj::GetDIDByEnum(&idCap, 268435471, 7);
    (*(void (__stdcall **)(signed int))(**((_DWORD **)v3 - 2) + 24))(1);
    QualifiedDataID::QualifiedDataID(&v29, idBlank, 0xCu);
    v5 = DBObj::Get(v4);
    QualifiedDataID::QualifiedDataID(&v30, idCap, 0xCu);
    v7 = (RenderSurface *)DBObj::Get(v6);
    spCapBullet.m_object = v7;
    if ( v5 )
    {
      v8 = (double)*((unsigned int *)v3 - 5);
      LODWORD(black.r) = 0;
      LODWORD(black.g) = 0;
      LODWORD(black.b) = 0;
      LODWORD(black.a) = 1065353216;
      v9 = *((_DWORD *)v3 - 4);
      newColor.r = v8 * 0.0039215689;
      v10 = (double)*((signed int *)v3 - 4);
      if ( v9 < 0 )
        v10 = v10 + 4294967300.0;
      v11 = *((_DWORD *)v3 - 3);
      newColor.g = v10 * 0.0039215689;
      v12 = (double)*((signed int *)v3 - 3);
      if ( v11 < 0 )
        v12 = v12 + 4294967300.0;
      v13 = *(_DWORD *)v3 == 0;
      LODWORD(newColor.a) = 1065353216;
      newColor.b = v12 * 0.0039215689;
      if ( v13 )
      {
        v14 = (RenderSurface *)(*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
        if ( v14 )
        {
          v15 = *(_DWORD *)(v5 + 164);
          v16 = v14->vfptr;
          v26 = *(_DWORD *)(v5 + 160);
          v25 = v15;
          v17 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
          ((void (__thiscall *)(RenderSurface *, int, int, PixelFormatID, signed int))v16[3].AddRef)(
            v14,
            v26,
            v25,
            v17,
            1);
          v18 = (Graphic *)operator new(0xCu);
          if ( v18 )
            Graphic::Graphic(v18, v14);
          else
            v19 = 0;
          v7 = spCapBullet.m_object;
          *(_DWORD *)v3 = v19;
        }
      }
      v2 = i;
      if ( i >= *((_DWORD *)&v28->vfptr + 2 * (3 * _iPart + 225)) )
      {
        SurfaceWindow::Blit((SurfaceWindow *)(*(_DWORD *)(*(_DWORD *)v3 + 8) + 172), &v7->window, 0, 1.0);
      }
      else
      {
        SurfaceWindow::Blit(
          (SurfaceWindow *)(*(_DWORD *)(*(_DWORD *)v3 + 8) + 172),
          (SurfaceWindow *)(v5 + 172),
          0,
          1.0);
        SurfaceWindow::ReplaceColor((SurfaceWindow *)(*(_DWORD *)(*(_DWORD *)v3 + 8) + 172), &black, &newColor);
      }
      UIRegion::ClearImage(*((UIRegion **)v3 - 2));
      v20 = (Graphic *)operator new(0xCu);
      if ( v20 )
        Graphic::Graphic(v20, *(RenderSurface **)(*(_DWORD *)v3 + 8));
      else
        v21 = 0;
      UIRegion::SetImage(*((UIRegion **)v3 - 2), v21);
    }
    if ( v7 )
      v7->vfptr->Release((Interface *)v7);
    if ( v5 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    ++v2;
    v3 += 28;
    i = v2;
  }
  while ( v2 < 9 );
}

//----- (0047DA90) --------------------------------------------------------  // acclient.c:186527
void __thiscall gmCGAppearancePage::DoGradDisk(gmCGAppearancePage *this, bool _bUsePlug)
{
  gmCGAppearancePage *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  int v4; // eax@1
  RenderSurface *v5; // ebp@1
  QualifiedDataID *v6; // eax@1
  int v7; // eax@1
  RenderSurface *v8; // ebx@1
  int v9; // eax@3
  int v10; // ecx@3
  unsigned int v11; // eax@3
  Graphic *v12; // eax@3
  RenderSurface *v13; // edi@4
  unsigned int v14; // eax@5
  unsigned int v15; // ebx@5
  InterfaceVtbl *v16; // ebp@5
  PixelFormatID v17; // eax@5
  Graphic *v18; // eax@5
  Graphic *v19; // eax@6
  RenderSurface *v20; // edi@10
  unsigned int v21; // ebx@11
  InterfaceVtbl *v22; // ebp@11
  PixelFormatID v23; // eax@11
  Graphic *v24; // eax@11
  Graphic *v25; // eax@12
  const unsigned int v26; // eax@16
  Graphic *v27; // eax@16
  Graphic *v28; // eax@17
  Graphic *v29; // eax@18
  DBObjGrabber<RenderSurface> spPlug; // [sp+20h] [bp-34h]@1
  DBObjGrabber<RenderSurface> spGrad; // [sp+24h] [bp-30h]@1
  IDClass<_tagDataID,32,0> idGrad; // [sp+28h] [bp-2Ch]@1
  IDClass<_tagDataID,32,0> idPlug; // [sp+2Ch] [bp-28h]@1
  unsigned int v34; // [sp+30h] [bp-24h]@3
  QualifiedDataID v35; // [sp+34h] [bp-20h]@1
  QualifiedDataID v36; // [sp+3Ch] [bp-18h]@1
  RGBAColor gradColor; // [sp+44h] [bp-10h]@3

  v2 = this;
  DBObj::GetDIDByEnum(&idGrad, 268435470, 7);
  DBObj::GetDIDByEnum(&idPlug, 268435472, 7);
  QualifiedDataID::QualifiedDataID(&v35, idGrad, 0xCu);
  v4 = DBObj::Get(v3);
  v5 = (RenderSurface *)v4;
  spGrad.m_object = (RenderSurface *)v4;
  QualifiedDataID::QualifiedDataID(&v36, idPlug, 0xCu);
  v7 = DBObj::Get(v6);
  v8 = (RenderSurface *)v7;
  spPlug.m_object = (RenderSurface *)v7;
  if ( v5 )
  {
    if ( !v7 )
      goto LABEL_24;
    v9 = v2->m_iCurColor;
    v10 = v2->m_iCurColor;
    gradColor.r = (double)v2->m_tColorWheel[v10].iRed * 0.0039215689;
    v11 = *((_DWORD *)&v2->vfptr + 7 * (v9 + 72));
    v34 = v11;
    v34 = v2->m_tColorWheel[v10].iBlue;
    gradColor.g = (double)v11 * 0.0039215689;
    v12 = v2->m_pGradGraphic;
    LODWORD(gradColor.a) = 1065353216;
    gradColor.b = (double)v34 * 0.0039215689;
    if ( !v12 )
    {
      v13 = (RenderSurface *)(*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
      if ( v13 )
      {
        v14 = v5->width;
        v15 = v5->height;
        v16 = v13->vfptr;
        v34 = v14;
        v17 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
        ((void (__thiscall *)(RenderSurface *, unsigned int, unsigned int, PixelFormatID, signed int))v16[3].AddRef)(
          v13,
          v34,
          v15,
          v17,
          1);
        v18 = (Graphic *)operator new(0xCu);
        if ( v18 )
          Graphic::Graphic(v18, v13);
        else
          v19 = 0;
        v5 = spGrad.m_object;
        v8 = spPlug.m_object;
        v2->m_pGradGraphic = v19;
      }
    }
    if ( !v2->m_pGradPlug )
    {
      v20 = (RenderSurface *)(*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
      if ( v20 )
      {
        v21 = v8->height;
        v22 = v20->vfptr;
        v34 = spPlug.m_object->width;
        v23 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
        ((void (__thiscall *)(RenderSurface *, unsigned int, unsigned int, PixelFormatID, signed int))v22[3].AddRef)(
          v20,
          v34,
          v21,
          v23,
          1);
        v24 = (Graphic *)operator new(0xCu);
        if ( v24 )
          Graphic::Graphic(v24, v20);
        else
          v25 = 0;
        v5 = spGrad.m_object;
        v8 = spPlug.m_object;
        v2->m_pGradPlug = v25;
      }
    }
    if ( _bUsePlug )
    {
      SurfaceWindow::Blit(&v2->m_pGradPlug->m_image->window, &v8->window, 0, 1.0);
      UIRegion::ClearImage((UIRegion *)&v2->m_pGradCircle->vfptr);
      v29 = (Graphic *)operator new(0xCu);
      if ( v29 )
      {
        Graphic::Graphic(v29, v2->m_pGradPlug->m_image);
        goto LABEL_21;
      }
    }
    else
    {
      v26 = RGBAColor::GetColor32(&gradColor);
      SurfaceWindow::BlitAndColor(&v2->m_pGradGraphic->m_image->window, &v5->window, 0, 1.0, 0, Blit_Multiply, v26);
      UIRegion::ClearImage((UIRegion *)&v2->m_pGradCircle->vfptr);
      v27 = (Graphic *)operator new(0xCu);
      if ( v27 )
      {
        Graphic::Graphic(v27, v2->m_pGradGraphic->m_image);
LABEL_21:
        UIRegion::SetImage((UIRegion *)&v2->m_pGradCircle->vfptr, v28);
        goto LABEL_22;
      }
    }
    v28 = 0;
    goto LABEL_21;
  }
LABEL_22:
  if ( v8 )
    v8->vfptr->Release((Interface *)v8);
LABEL_24:
  if ( v5 )
    v5->vfptr->Release((Interface *)v5);
}

//----- (0047DD50) --------------------------------------------------------  // acclient.c:186679
void __thiscall gmCGAppearancePage::SetColor(gmCGAppearancePage *this, int _iColor)
{
  gmCGAppearancePage *v2; // esi@1
  int v3; // eax@1
  CPlayerSystem *v4; // ecx@5
  int v5; // eax@5
  bool _iColora; // [sp+8h] [bp+4h]@5

  v2 = this;
  v3 = this->m_iCurColor;
  if ( v3 != -1 )
    this->m_tColorWheel[v3].pPointer->vfptr[2].__vecDelDtor((IInputActionCallback *)this->m_tColorWheel[v3].pPointer, 0);
  if ( _iColor != -1 )
    ((void (__stdcall *)(signed int))v2->m_tColorWheel[_iColor].pPointer->vfptr[2].__vecDelDtor)(1);
  v4 = v2->m_pPlayerSystem;
  v2->m_iCurColor = _iColor;
  CPlayerSystem::GetCharGenState(v4);
  _iColora = 0;
  switch ( v2->m_eCurPart )
  {
    case 1:
      CharGenState::SetHairColor((CharGenState *)v5, v2->m_iCurColor);
      break;
    case 2:
      CharGenState::SetEyeColor((CharGenState *)v5, v2->m_iCurColor);
      _iColora = 1;
      break;
    case 6:
      *(_DWORD *)(v5 + 248) = v2->m_iCurColor;
      break;
    case 7:
      *(_DWORD *)(v5 + 256) = v2->m_iCurColor;
      break;
    case 8:
      *(_DWORD *)(v5 + 264) = v2->m_iCurColor;
      break;
    case 9:
      *(_DWORD *)(v5 + 272) = v2->m_iCurColor;
      break;
    default:
      break;
  }
  gmCGAppearancePage::DoGradDisk(v2, _iColora);
  if ( UIElement::IsVisible((UIElement *)&v2->vfptr) )
    gmCG3DView::Update(v2->m_p3DView);
}

//----- (0047DE60) --------------------------------------------------------  // acclient.c:186727
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,Sex_CG> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,Sex_CG> **v5; // edx@5
  HashTableData<unsigned long,Sex_CG> *v6; // edi@5
  HashTableData<unsigned long,Sex_CG> *v7; // eax@7
  HashTableData<unsigned long,Sex_CG> *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,Sex_CG> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,Sex_CG> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_17:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      Sex_CG::~Sex_CG(&v6->m_data);
      operator delete(v6);
    }
  }
}

//----- (0047DEF0) --------------------------------------------------------  // acclient.c:186787
HashTable<unsigned long,Sex_CG,0> *__thiscall HashTable<unsigned long,Sex_CG,0>::vector_deleting_destructor(HashTable<unsigned long,Sex_CG,0> *this, unsigned int a2)
{
  HashTable<unsigned long,Sex_CG,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,Sex_CG,0>Vtbl *)&HashTable<unsigned long,Sex_CG,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable;
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
// 79FE74: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable)(void *, char);
// 79FE80: using guessed type int (__thiscall *HashTable<unsigned long,Sex_CG,0>::vftable)(void *, char);

//----- (0047DF50) --------------------------------------------------------  // acclient.c:186813
void __thiscall HeritageGroup_CG::~HeritageGroup_CG(HeritageGroup_CG *this)
{
  HeritageGroup_CG *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1
  Template_CG *v4; // ecx@4
  int v5; // edi@10

  v1 = this;
  v2 = (char *)&this->mGenderList.m_intrusiveTable;
  this->vfptr = (HeritageGroup_CGVtbl *)&HeritageGroup_CG::vftable;
  this->mGenderList.vfptr = (HashTable<unsigned long,Sex_CG,0>Vtbl *)&HashTable<unsigned long,Sex_CG,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::delete_contents(&this->mGenderList.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  if ( (v1->mTemplateList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v4 = v1->mTemplateList.m_data;
    if ( v4 )
      Template_CG::vector_deleting_destructor(v4, 3u);
  }
  SmartArray<Skill_CG,1>::~SmartArray<Skill_CG,1>(&v1->mSkillList);
  if ( (v1->mSecondaryStartAreaList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->mSecondaryStartAreaList.m_data);
  if ( (v1->mPrimaryStartAreaList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->mPrimaryStartAreaList.m_data);
  v5 = (int)&v1->name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}
// 79FE74: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable)(void *, char);
// 79FE80: using guessed type int (__thiscall *HashTable<unsigned long,Sex_CG,0>::vftable)(void *, char);
// 79FE84: using guessed type void (__thiscall *HeritageGroup_CG::vftable)(HeritageGroup_CG *this, struct Archive *);

//----- (0047E020) --------------------------------------------------------  // acclient.c:186857
void __thiscall gmCGAppearancePage::SetupParts(gmCGAppearancePage *this)
{
  gmCGAppearancePage *v1; // esi@1
  int v2; // eax@1
  int v3; // edi@1
  int v4; // ecx@1
  unsigned int v5; // ecx@1
  unsigned int v6; // eax@1
  unsigned int v7; // edx@1
  int v8; // ecx@1
  unsigned int v9; // edx@1
  unsigned int v10; // ecx@1
  unsigned int v11; // edx@1
  unsigned int v12; // ecx@1
  int v13; // eax@1
  Sex_CG curSX; // [sp+8h] [bp-1A0h]@1
  HeritageGroup_CG curHG; // [sp+E8h] [bp-C0h]@1

  v1 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v3 = v2;
  ACCharGenData::GetHG(*(ACCharGenData **)(v2 + 596), &curHG, *(_DWORD *)(v2 + 212));
  HeritageGroup_CG::GetSX(&curHG, &curSX, *(_DWORD *)(v3 + 216));
  v4 = *(_DWORD *)(v3 + 240);
  v1->m_tChoices[0].iNumChoices = curSX.mHairStyleList.m_num;
  v1->m_tChoices[0].iCurrentChoice = v4;
  v5 = curSX.mHairColorList.m_num;
  v1->m_tChoices[0].iCurrentColor = *(_DWORD *)(v3 + 232);
  v6 = curSX.mEyeStripList.m_num;
  v1->m_tChoices[0].iNumColors = v5;
  v1->m_tChoices[0].dShade = *(double *)(v3 + 336);
  v1->m_tChoices[1].iCurrentChoice = *(_DWORD *)(v3 + 220);
  v7 = curSX.mEyeColorList.m_num;
  v1->m_tChoices[1].iNumChoices = v6;
  v8 = *(_DWORD *)(v3 + 236);
  v1->m_tChoices[1].iNumColors = v7;
  v9 = curSX.mNoseStripList.m_num;
  v1->m_tChoices[1].iCurrentColor = v8;
  LODWORD(v1->m_tChoices[1].dShade) = 0;
  HIDWORD(v1->m_tChoices[1].dShade) = 0;
  v1->m_tChoices[2].iCurrentChoice = *(_DWORD *)(v3 + 224);
  v1->m_tChoices[2].iNumChoices = v9;
  v1->m_tChoices[2].iNumColors = 0;
  LODWORD(v1->m_tChoices[2].dShade) = 0;
  HIDWORD(v1->m_tChoices[2].dShade) = 0;
  v1->m_tChoices[2].iCurrentColor = -1;
  v1->m_tChoices[3].iCurrentChoice = *(_DWORD *)(v3 + 228);
  v1->m_tChoices[3].iNumChoices = curSX.mMouthStripList.m_num;
  v1->m_tChoices[3].iCurrentColor = -1;
  v10 = curSX.mHeadgearList.m_num;
  v1->m_tChoices[3].iNumColors = 0;
  LODWORD(v1->m_tChoices[3].dShade) = 0;
  HIDWORD(v1->m_tChoices[3].dShade) = 0;
  v1->m_tChoices[5].iCurrentChoice = *(_DWORD *)(v3 + 244);
  v1->m_tChoices[5].iNumChoices = v10;
  v1->m_tChoices[5].iCurrentColor = *(_DWORD *)(v3 + 248);
  v11 = curSX.mShirtList.m_num;
  v1->m_tChoices[5].iNumColors = *(_DWORD *)(v3 + 276);
  v1->m_tChoices[5].dShade = *(double *)(v3 + 344);
  v1->m_tChoices[6].iCurrentChoice = *(_DWORD *)(v3 + 252);
  v1->m_tChoices[6].iNumChoices = v11;
  v1->m_tChoices[6].iCurrentColor = *(_DWORD *)(v3 + 256);
  v1->m_tChoices[6].iNumColors = *(_DWORD *)(v3 + 280);
  v1->m_tChoices[6].dShade = *(double *)(v3 + 352);
  v1->m_tChoices[7].iCurrentChoice = *(_DWORD *)(v3 + 260);
  v1->m_tChoices[7].iNumChoices = curSX.mPantsList.m_num;
  v1->m_tChoices[7].iCurrentColor = *(_DWORD *)(v3 + 264);
  v12 = curSX.mFootwearList.m_num;
  v1->m_tChoices[7].iNumColors = *(_DWORD *)(v3 + 284);
  v1->m_tChoices[7].dShade = *(double *)(v3 + 360);
  v13 = *(_DWORD *)(v3 + 268);
  v1->m_tChoices[8].iNumChoices = v12;
  v1->m_tChoices[8].iCurrentChoice = v13;
  v1->m_tChoices[8].iCurrentColor = *(_DWORD *)(v3 + 272);
  v1->m_tChoices[8].iNumColors = *(_DWORD *)(v3 + 288);
  v1->m_tChoices[8].dShade = *(double *)(v3 + 368);
  Sex_CG::~Sex_CG(&curSX);
  HeritageGroup_CG::~HeritageGroup_CG(&curHG);
}

//----- (0047E260) --------------------------------------------------------  // acclient.c:186938
void __thiscall gmCGAppearancePage::SetSelection(gmCGAppearancePage *this, gmCGAppearancePage::EParts _ePart)
{
  gmCGAppearancePage *v2; // ebx@1
  CPlayerSystem *v3; // ecx@1
  int v4; // eax@1
  int v5; // esi@1
  int v6; // edi@1
  signed int v7; // ebp@1
  UIElement *v8; // ecx@3
  signed int v9; // edi@3
  unsigned int v10; // ebp@6
  QualifiedDataID *v11; // eax@7
  int v12; // eax@8
  int v13; // edx@8
  int v14; // ecx@8
  int v15; // eax@8
  int v16; // eax@9
  int v17; // ebp@9
  int v18; // edi@10
  unsigned int v19; // eax@11
  int v20; // edx@11
  int v21; // edx@12
  QualifiedDataID *v22; // eax@13
  int v23; // eax@13
  unsigned int v24; // edx@13
  unsigned int v25; // eax@13
  QualifiedDataID *v26; // eax@14
  int v27; // eax@14
  unsigned int v28; // ecx@14
  unsigned int v29; // eax@14
  QualifiedDataID *v30; // eax@15
  unsigned int v31; // ecx@15
  unsigned int v32; // edx@15
  int v33; // ebp@16
  int v34; // edi@16
  IDClass<_tagDataID,32,0> *v35; // eax@17
  QualifiedDataID *v36; // eax@17
  int v37; // edx@18
  int v38; // ebp@19
  int v39; // edi@19
  IDClass<_tagDataID,32,0> *v40; // eax@20
  QualifiedDataID *v41; // eax@20
  int v42; // ecx@21
  unsigned int v43; // edx@21
  unsigned int v44; // eax@21
  int v45; // ebp@22
  int v46; // edi@22
  IDClass<_tagDataID,32,0> *v47; // eax@23
  QualifiedDataID *v48; // eax@23
  int v49; // eax@24
  unsigned int v50; // ecx@24
  unsigned int v51; // edx@24
  int v52; // ebp@25
  int v53; // edi@25
  IDClass<_tagDataID,32,0> *v54; // eax@26
  QualifiedDataID *v55; // eax@26
  int v56; // eax@30
  int v57; // edi@31
  unsigned int v58; // ecx@32
  int v59; // ebp@32
  IDClass<_tagDataID,32,0> *v60; // eax@35
  unsigned int v61; // eax@35
  int v62; // edx@35
  unsigned int v63; // ecx@35
  int v64; // eax@35
  int v65; // esi@38
  int v66; // edi@38
  int v67; // eax@38
  long double dCurShade; // [sp+14h] [bp-1E8h]@7
  int iNumPalSets; // [sp+1Ch] [bp-1E0h]@1
  int iPart; // [sp+20h] [bp-1DCh]@1
  int iSampleColor; // [sp+24h] [bp-1D8h]@1
  int iCurColor; // [sp+28h] [bp-1D4h]@1
  int i; // [sp+2Ch] [bp-1D0h]@20
  IDClass<_tagDataID,32,0> v74; // [sp+30h] [bp-1CCh]@23
  IDClass<_tagDataID,32,0> result; // [sp+34h] [bp-1C8h]@17
  PalSet *palSet[9]; // [sp+38h] [bp-1C4h]@7
  IDClass<_tagDataID,32,0> v77; // [sp+5Ch] [bp-1A0h]@35
  Sex_CG curSX; // [sp+60h] [bp-19Ch]@1
  HeritageGroup_CG curHG; // [sp+13Ch] [bp-C0h]@1

  v2 = this;
  v3 = this->m_pPlayerSystem;
  iPart = 0;
  iSampleColor = 0;
  iNumPalSets = 0;
  iCurColor = 0;
  CPlayerSystem::GetCharGenState(v3);
  v5 = v4;
  ACCharGenData::GetHG(*(ACCharGenData **)(v4 + 596), &curHG, *(_DWORD *)(v4 + 212));
  HeritageGroup_CG::GetSX(&curHG, &curSX, *(_DWORD *)(v5 + 216));
  v2->m_eCurPart = _ePart;
  v2->m_LastHeritageGroup = *(_DWORD *)(v5 + 212);
  v6 = (int)&v2->m_tColorWheel[0].pPointer;
  v7 = 9;
  do
  {
    (*(void (__stdcall **)(signed int))(**(_DWORD **)(v6 - 4) + 24))(1);
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v6 + 24))(0);
    v6 += 28;
    --v7;
  }
  while ( v7 );
  v8 = v2->m_pCurSelection;
  v9 = 0;
  if ( v8 )
    ((void (__stdcall *)(signed int))v8->vfptr[13].__vecDelDtor)(1);
  switch ( _ePart )
  {
    case 1:
      v10 = curSX.mHairColorList.m_num;
      iNumPalSets = curSX.mHairColorList.m_num;
      if ( (signed int)curSX.mHairColorList.m_num > 0 )
      {
        do
        {
          QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, curSX.mHairColorList.m_data[v9], 0x18u);
          palSet[v9++] = (PalSet *)DBObj::Get(v11);
        }
        while ( v9 < (signed int)v10 );
      }
      v2->m_pCurSelection = (UIElement *)&v2->m_pHairSpin->vfptr;
      v12 = *(_DWORD *)(v5 + 232);
      v13 = *(_DWORD *)(v5 + 336);
      iSampleColor = 208;
      iPart = 0;
      LODWORD(dCurShade) = v13;
      v14 = v12 == -1 ? 0 : v12;
      v15 = *(_DWORD *)(v5 + 340);
      iCurColor = v14;
      HIDWORD(dCurShade) = v15;
      break;
    case 2:
      v16 = curSX.mEyeColorList.m_num;
      v17 = 0;
      if ( (signed int)curSX.mEyeColorList.m_num > 0 )
      {
        v18 = (int)&v2->m_tColorWheel[0].iGreen;
        do
        {
          v19 = ClientCharGenState::GetColorFromPal(curSX.mEyeColorList.m_data[v17], 259);
          *(_DWORD *)(v18 - 4) = (unsigned __int8)(v19 >> 16);
          v20 = BYTE1(v19);
          *(_DWORD *)(v18 + 4) = (unsigned __int8)v19;
          v16 = curSX.mEyeColorList.m_num;
          *(_DWORD *)v18 = v20;
          ++v17;
          v18 += 28;
        }
        while ( v17 < v16 );
      }
      v2->m_pCurSelection = (UIElement *)&v2->m_pEyesSpin->vfptr;
      v21 = *(_DWORD *)(v5 + 236);
      iNumPalSets = v16;
      iPart = 1;
      iCurColor = v21;
      dCurShade = 0.5;
      goto LABEL_38;
    case 3:
      iNumPalSets = 1;
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, curSX.skinPalSet, 0x18u);
      v23 = DBObj::Get(v22);
      v2->m_pCurSelection = (UIElement *)&v2->m_pNoseSpin->vfptr;
      v24 = *(_DWORD *)(v5 + 328);
      palSet[0] = (PalSet *)v23;
      v25 = *(_DWORD *)(v5 + 332);
      iSampleColor = 176;
      iPart = 2;
      iCurColor = 0;
      dCurShade = COERCE_DOUBLE(__PAIR__(v25, v24));
      break;
    case 4:
      iNumPalSets = 1;
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, curSX.skinPalSet, 0x18u);
      v27 = DBObj::Get(v26);
      v2->m_pCurSelection = (UIElement *)&v2->m_pMouthSpin->vfptr;
      v28 = *(_DWORD *)(v5 + 332);
      palSet[0] = (PalSet *)v27;
      v29 = *(_DWORD *)(v5 + 328);
      iSampleColor = 176;
      iPart = 3;
      iCurColor = 0;
      goto LABEL_29;
    case 5:
      iNumPalSets = 1;
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, curSX.skinPalSet, 0x18u);
      palSet[0] = (PalSet *)DBObj::Get(v30);
      v2->m_pCurSelection = (UIElement *)&v2->m_pSkinSpin->vfptr;
      v31 = *(_DWORD *)(v5 + 328);
      v32 = *(_DWORD *)(v5 + 332);
      iSampleColor = 176;
      iPart = 4;
      iCurColor = 0;
      dCurShade = COERCE_DOUBLE(__PAIR__(v32, v31));
      break;
    case 6:
      v34 = 0;
      iNumPalSets = *(_DWORD *)(v5 + 276);
      v33 = iNumPalSets;
      if ( iNumPalSets > 0 )
      {
        do
        {
          v35 = CharGenState::GetHeadgearPalSetID((CharGenState *)v5, &result, v34);
          QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, (IDClass<_tagDataID,32,0>)v35->id, 0x18u);
          palSet[v34++] = (PalSet *)DBObj::Get(v36);
        }
        while ( v34 < v33 );
      }
      v2->m_pCurSelection = (UIElement *)&v2->m_pHeadgearSpin->vfptr;
      v37 = *(_DWORD *)(v5 + 248);
      v29 = *(_DWORD *)(v5 + 344);
      v28 = *(_DWORD *)(v5 + 348);
      iPart = 5;
      goto LABEL_28;
    case 7:
      v39 = 0;
      iNumPalSets = *(_DWORD *)(v5 + 280);
      v38 = iNumPalSets;
      if ( iNumPalSets > 0 )
      {
        do
        {
          v40 = CharGenState::GetShirtPalSetID((CharGenState *)v5, (IDClass<_tagDataID,32,0> *)&i, v39);
          QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, (IDClass<_tagDataID,32,0>)v40->id, 0x18u);
          palSet[v39++] = (PalSet *)DBObj::Get(v41);
        }
        while ( v39 < v38 );
      }
      v2->m_pCurSelection = (UIElement *)&v2->m_pShirtSpin->vfptr;
      v42 = *(_DWORD *)(v5 + 256);
      v43 = *(_DWORD *)(v5 + 352);
      v44 = *(_DWORD *)(v5 + 356);
      iSampleColor = 1312;
      iPart = 6;
      iCurColor = v42;
      dCurShade = COERCE_DOUBLE(__PAIR__(v44, v43));
      break;
    case 8:
      v46 = 0;
      iNumPalSets = *(_DWORD *)(v5 + 284);
      v45 = iNumPalSets;
      if ( iNumPalSets > 0 )
      {
        do
        {
          v47 = CharGenState::GetTrousersPalSetID((CharGenState *)v5, &v74, v46);
          QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, (IDClass<_tagDataID,32,0>)v47->id, 0x18u);
          palSet[v46++] = (PalSet *)DBObj::Get(v48);
        }
        while ( v46 < v45 );
      }
      v2->m_pCurSelection = (UIElement *)&v2->m_pTrousersSpin->vfptr;
      v49 = *(_DWORD *)(v5 + 264);
      v50 = *(_DWORD *)(v5 + 360);
      v51 = *(_DWORD *)(v5 + 364);
      iSampleColor = 1312;
      iPart = 7;
      iCurColor = v49;
      dCurShade = COERCE_DOUBLE(__PAIR__(v51, v50));
      break;
    case 9:
      v53 = 0;
      iNumPalSets = *(_DWORD *)(v5 + 288);
      v52 = iNumPalSets;
      if ( iNumPalSets > 0 )
      {
        do
        {
          v54 = CharGenState::GetFootwearPalSetID((CharGenState *)v5, (IDClass<_tagDataID,32,0> *)&iSampleColor, v53);
          QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, (IDClass<_tagDataID,32,0>)v54->id, 0x18u);
          palSet[v53++] = (PalSet *)DBObj::Get(v55);
        }
        while ( v53 < v52 );
      }
      v2->m_pCurSelection = (UIElement *)&v2->m_pFootwearSpin->vfptr;
      v37 = *(_DWORD *)(v5 + 272);
      v29 = *(_DWORD *)(v5 + 368);
      v28 = *(_DWORD *)(v5 + 372);
      iPart = 8;
LABEL_28:
      iSampleColor = 1312;
      iCurColor = v37;
LABEL_29:
      dCurShade = COERCE_DOUBLE(__PAIR__(v28, v29));
      break;
    default:
      break;
  }
  v56 = 0;
  i = 0;
  if ( iNumPalSets > 0 )
  {
    v57 = (int)&v2->m_tColorWheel[0].iGreen;
    do
    {
      v59 = 0;
      v74.id = (unsigned int)palSet[v56];
      v58 = v74.id;
      if ( v74.id )
      {
        *(_DWORD *)(v57 + 4) = 0;
        *(_DWORD *)v57 = 0;
        *(_DWORD *)(v57 - 4) = 0;
        if ( *(_DWORD *)(v58 + 56) > 0 )
        {
          result.id = v58;
          do
          {
            v60 = PalSet::GetPaletteID_Integral((PalSet *)v58, &v77, v59);
            v61 = ClientCharGenState::GetColorFromPal((IDClass<_tagDataID,32,0>)v60->id, iSampleColor);
            *(_DWORD *)(v57 - 4) += (unsigned __int8)(v61 >> 16);
            v62 = (unsigned __int8)v61 + *(_DWORD *)(v57 + 4);
            *(_DWORD *)v57 += BYTE1(v61);
            v63 = result.id;
            *(_DWORD *)(v57 + 4) = v62;
            v64 = *(_DWORD *)(v63 + 56);
            v58 = v74.id;
            ++v59;
          }
          while ( v59 < v64 );
        }
        *(_DWORD *)(v57 - 4) /= *(_DWORD *)(v58 + 56);
        *(_DWORD *)v57 /= *(_DWORD *)(v58 + 56);
        *(_DWORD *)(v57 + 4) /= *(_DWORD *)(v58 + 56);
        v56 = i;
      }
      ++v56;
      v57 += 28;
      i = v56;
    }
    while ( v56 < iNumPalSets );
  }
LABEL_38:
  v65 = iPart;
  v66 = iCurColor;
  v67 = iNumPalSets;
  v2->m_iCurColor = iCurColor;
  v2->m_iPartIndex = v65;
  *((_DWORD *)&v2->vfptr + 2 * (3 * v65 + 225)) = v67;
  ((void (__stdcall *)(signed int))v2->m_pCurSelection->vfptr[13].__vecDelDtor)(6);
  gmCGAppearancePage::DoColorSpots(v2, v65);
  if ( _ePart == 2 )
  {
    gmCGAppearancePage::DoGradDisk(v2, 1);
    ((void (__stdcall *)(_DWORD))v2->m_pShadeScroll->vfptr[2].__vecDelDtor)(0);
  }
  else
  {
    gmCGAppearancePage::DoGradDisk(v2, 0);
    ((void (__stdcall *)(signed int))v2->m_pShadeScroll->vfptr[2].__vecDelDtor)(1);
    gmCGAppearancePage::SetShade(v2, dCurShade);
  }
  gmCGAppearancePage::SetColor(v2, v66);
  Sex_CG::~Sex_CG(&curSX);
  HeritageGroup_CG::~HeritageGroup_CG(&curHG);
}

//----- (0047E8F0) --------------------------------------------------------  // acclient.c:187297
void __usercall gmCGAppearancePage::Update(gmCGAppearancePage *this@<ecx>, long double a2@<st0>)
{
  gmCGAppearancePage *v2; // esi@1
  int v3; // eax@1
  int v4; // edi@1
  int v5; // eax@1
  int v6; // eax@5
  UIElement_Button *v7; // ecx@8
  unsigned int v8; // eax@8
  unsigned int v9; // eax@8
  UIElement *v10; // ecx@8
  UIElement *v11; // eax@9
  UIElement *v12; // eax@11
  unsigned int v13; // eax@13
  int v14; // edi@13
  AC1Legacy::Vector3 *v15; // ebp@13
  StringInfo *v16; // ecx@13
  unsigned int v17; // eax@18
  unsigned int v18; // eax@18
  UIElement *v19; // ecx@18
  UIElement *v20; // eax@19
  UIElement *v21; // eax@21
  unsigned int v22; // eax@23
  bool v23; // zf@23
  signed int v24; // ecx@23
  unsigned int v25; // eax@26
  unsigned int v26; // eax@26
  UIElement *v27; // ecx@26
  UIElement *v28; // eax@27
  UIElement *v29; // eax@29
  unsigned int v30; // eax@31
  signed int v31; // ecx@32
  signed int v32; // eax@32
  gmCG3DView *v33; // ecx@37
  AC1Legacy::Vector3 *v34; // [sp+8h] [bp-1C4h]@23
  AC1Legacy::Vector3 *v35; // [sp+Ch] [bp-1C0h]@23
  int v36; // [sp+10h] [bp-1BCh]@0
  StringInfo siSkin; // [sp+1Ch] [bp-1B0h]@8
  StringInfo siHair; // [sp+ACh] [bp-120h]@8
  StringInfo siEyes; // [sp+13Ch] [bp-90h]@8

  v2 = this;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v4 = v3;
  v5 = *(_DWORD *)(v3 + 216) - 1;
  if ( v5 )
  {
    if ( v5 == 1 )
    {
      ((void (__stdcall *)(signed int, int))v2->m_pFemaleButton->vfptr[13].__vecDelDtor)(268435479, v36);
      ((void (__cdecl *)(signed int))v2->m_pMaleButton->vfptr[13].__vecDelDtor)(268435478);
    }
  }
  else
  {
    ((void (__stdcall *)(signed int, int))v2->m_pFemaleButton->vfptr[13].__vecDelDtor)(268435478, v36);
    ((void (__cdecl *)(signed int))v2->m_pMaleButton->vfptr[13].__vecDelDtor)(268435479);
  }
  v6 = *(_DWORD *)(v4 + 212);
  if ( v6 == 6 )
  {
    if ( v2->m_LastHeritageGroup != 6 )
    {
      CharGenState::RandomizeAppearance((CharGenState *)v4, a2, 0);
      CharGenState::RandomizeClothing((CharGenState *)v4, 1);
    }
    v7 = v2->m_pClothesButton;
    v2->m_LastHeritageGroup = *(_DWORD *)(v4 + 212);
    ((void (__stdcall *)(_DWORD))v7->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v2->m_pNoseSpin->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v2->m_pMouthSpin->vfptr[2].__vecDelDtor)(0);
    StringInfo::StringInfo(&siEyes);
    StringInfo::StringInfo(&siSkin);
    StringInfo::StringInfo(&siHair);
    v8 = compute_str_hash("ID_CharGen_GearText_HairButton");
    StringInfo::SetStringIDandTableEnum(&siEyes, v8, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pHairSpin->vfptr, &siEyes, 0, 1);
    v9 = compute_str_hash("ID_CharGen_GearText_EyesButton");
    StringInfo::SetStringIDandTableEnum(&siHair, v9, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pEyesSpin->vfptr, &siHair, 0, 1);
    v10 = (UIElement *)&v2->m_pEyesSpin->vfptr;
    if ( v10 )
    {
      v11 = UIElement::GetChildRecursive(v10, 0x1000030Au);
      if ( v11 )
        UIElement::SetAttribute_Bool(v11, 0xDu, 1);
      v12 = UIElement::GetChildRecursive((UIElement *)&v2->m_pEyesSpin->vfptr, 0x1000030Bu);
      if ( v12 )
        UIElement::SetAttribute_Bool(v12, 0xDu, 1);
    }
    ((void (__stdcall *)(_DWORD, signed int))v2->m_pSkinSpin->vfptr[3].OnLoseFocus)(0, 90);
    v13 = compute_str_hash("ID_CharGen_GearText_SkinButton");
    StringInfo::SetStringIDandTableEnum(&siSkin, v13, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pSkinSpin->vfptr, &siSkin, 0, 1);
    gmCGAppearancePage::SetChoice(v2, ECG_CHOICE_FACE);
    gmCGAppearancePage::SetSelection(v2, ECG_PARTS_HAIR);
    v14 = (int)&v2->m_vectTargPosition;
    *(_DWORD *)v14 = 0;
    *(_DWORD *)(v14 + 4) = -1089680179;
    *(_DWORD *)(v14 + 8) = 1070805811;
    v15 = &v2->m_vectCurDirection;
    LODWORD(v2->m_vectCurPosition.x) = 0;
    LODWORD(v2->m_vectCurPosition.y) = -1089680179;
    LODWORD(v2->m_vectCurPosition.z) = 1070805811;
    gmCG3DView::SetCamera(v2->m_p3DView, &v2->m_vectTargPosition, &v2->m_vectCurDirection);
    StringInfo::~StringInfo(&siHair);
    StringInfo::~StringInfo(&siSkin);
    v16 = &siEyes;
  }
  else
  {
    if ( v6 == 12 || v6 == 13 )
    {
      ((void (__stdcall *)(_DWORD))v2->m_pClothesButton->vfptr[2].__vecDelDtor)(0);
      ((void (__stdcall *)(_DWORD))v2->m_pNoseSpin->vfptr[2].__vecDelDtor)(0);
      ((void (__stdcall *)(_DWORD))v2->m_pMouthSpin->vfptr[2].__vecDelDtor)(0);
      StringInfo::StringInfo(&siHair);
      StringInfo::StringInfo(&siSkin);
      StringInfo::StringInfo(&siEyes);
      v25 = compute_str_hash("ID_CharGen_OlthoiText_HairButton");
      StringInfo::SetStringIDandTableEnum(&siHair, v25, 268435458);
      UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pHairSpin->vfptr, &siHair, 0, 1);
      v26 = compute_str_hash("ID_CharGen_OlthoiText_EyesButton");
      StringInfo::SetStringIDandTableEnum(&siEyes, v26, 268435458);
      UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pEyesSpin->vfptr, &siEyes, 0, 1);
      v27 = (UIElement *)&v2->m_pEyesSpin->vfptr;
      if ( v27 )
      {
        v28 = UIElement::GetChildRecursive(v27, 0x1000030Au);
        if ( v28 )
          UIElement::SetAttribute_Bool(v28, 0xDu, 1);
        v29 = UIElement::GetChildRecursive((UIElement *)&v2->m_pEyesSpin->vfptr, 0x1000030Bu);
        if ( v29 )
          UIElement::SetAttribute_Bool(v29, 0xDu, 1);
      }
      ((void (__stdcall *)(_DWORD, signed int))v2->m_pSkinSpin->vfptr[3].OnLoseFocus)(0, 90);
      v30 = compute_str_hash("ID_CharGen_OlthoiText_SkinButton");
      StringInfo::SetStringIDandTableEnum(&siSkin, v30, 268435458);
      UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pSkinSpin->vfptr, &siSkin, 0, 1);
      gmCGAppearancePage::SetChoice(v2, ECG_CHOICE_FACE);
      gmCGAppearancePage::SetSelection(v2, ECG_PARTS_HAIR);
      v23 = *(_DWORD *)(v4 + 212) == 12;
      v14 = (int)&v2->m_vectTargPosition;
      LODWORD(v2->m_vectTargPosition.x) = 0;
      if ( v23 )
      {
        v31 = -1075000115;
        v32 = 1072483533;
      }
      else
      {
        v31 = -1069337805;
        v32 = 1076887552;
      }
      LODWORD(v2->m_vectTargPosition.z) = v32;
      LODWORD(v2->m_vectTargPosition.y) = v31;
      v15 = &v2->m_vectCurDirection;
      LODWORD(v2->m_vectCurPosition.x) = 0;
      v35 = &v2->m_vectCurDirection;
      LODWORD(v2->m_vectCurPosition.y) = v31;
      LODWORD(v2->m_vectCurPosition.z) = v32;
      v34 = &v2->m_vectTargPosition;
    }
    else
    {
      if ( v2->m_LastHeritageGroup == 6 )
      {
        CharGenState::RandomizeAppearance((CharGenState *)v4, a2, 0);
        CharGenState::RandomizeClothing((CharGenState *)v4, 1);
      }
      v2->m_LastHeritageGroup = *(_DWORD *)(v4 + 212);
      StringInfo::StringInfo(&siHair);
      StringInfo::StringInfo(&siSkin);
      StringInfo::StringInfo(&siEyes);
      v17 = compute_str_hash("ID_CharGen_HairStyle");
      StringInfo::SetStringIDandTableEnum(&siHair, v17, 268435458);
      UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pHairSpin->vfptr, &siHair, 0, 1);
      v18 = compute_str_hash("ID_CharGen_Eyes");
      StringInfo::SetStringIDandTableEnum(&siEyes, v18, 268435458);
      UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pEyesSpin->vfptr, &siEyes, 0, 1);
      v19 = (UIElement *)&v2->m_pEyesSpin->vfptr;
      if ( v19 )
      {
        v20 = UIElement::GetChildRecursive(v19, 0x1000030Au);
        if ( v20 )
          UIElement::SetAttribute_Bool(v20, 0xDu, 0);
        v21 = UIElement::GetChildRecursive((UIElement *)&v2->m_pEyesSpin->vfptr, 0x1000030Bu);
        if ( v21 )
          UIElement::SetAttribute_Bool(v21, 0xDu, 0);
      }
      ((void (__stdcall *)(_DWORD, signed int))v2->m_pSkinSpin->vfptr[3].OnLoseFocus)(0, 180);
      v22 = compute_str_hash("ID_CharGen_Skin");
      StringInfo::SetStringIDandTableEnum(&siSkin, v22, 268435458);
      UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v2->m_pSkinSpin->vfptr, &siSkin, 0, 1);
      ((void (__stdcall *)(signed int))v2->m_pClothesButton->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v2->m_pNoseSpin->vfptr[2].__vecDelDtor)(1);
      ((void (__stdcall *)(signed int))v2->m_pMouthSpin->vfptr[2].__vecDelDtor)(1);
      v15 = &v2->m_vectCurDirection;
      v14 = (int)&v2->m_vectTargPosition;
      v23 = v2->m_LastHeritageGroup == 7;
      v35 = &v2->m_vectCurDirection;
      *(_DWORD *)v14 = 0;
      v34 = &v2->m_vectTargPosition;
      *(_DWORD *)(v14 + 8) = 1070805811;
      v24 = -1084647014;
      if ( !v23 )
        v24 = -1089680179;
      LODWORD(v2->m_vectTargPosition.y) = v24;
      LODWORD(v2->m_vectCurPosition.z) = 1070805811;
      LODWORD(v2->m_vectCurPosition.y) = v24;
      LODWORD(v2->m_vectCurPosition.x) = 0;
    }
    gmCG3DView::SetCamera(v2->m_p3DView, v34, v35);
    StringInfo::~StringInfo(&siEyes);
    StringInfo::~StringInfo(&siSkin);
    v16 = &siHair;
  }
  StringInfo::~StringInfo(v16);
  gmCGAppearancePage::SetupParts(v2);
  gmCGAppearancePage::SetSelection(v2, v2->m_eCurPart);
  if ( UIElement::IsVisible((UIElement *)&v2->vfptr) )
  {
    gmCG3DView::Update(v2->m_p3DView);
    gmCG3DView::SetCamera(v2->m_p3DView, (AC1Legacy::Vector3 *)v14, v15);
    v33 = v2->m_p3DView;
    if ( v2->m_bZoomedIn )
      gmCG3DView::StopAnimation(v33);
    else
      gmCG3DView::StartAnimation(v33);
  }
}

//----- (0047EF30) --------------------------------------------------------  // acclient.c:187530
int __userpurge gmCGAppearancePage::ListenToElementMessage@<eax>(gmCGAppearancePage *this@<ecx>, long double a2@<st0>, UIElementMessageInfo *i_rMsg)
{
  gmCGAppearancePage *v3; // esi@1
  CharGenState *v4; // eax@3
  CharGenState *v6; // eax@6
  int v7; // ecx@13
  int v8; // eax@13
  int v9; // eax@16
  int v10; // ecx@19
  int v11; // eax@19
  int v12; // eax@23
  int v13; // ecx@25
  int v14; // eax@25
  int v15; // eax@29
  int v16; // ecx@31
  int v17; // eax@31
  int v18; // eax@35
  int v19; // ecx@37
  int v20; // eax@37
  int v21; // eax@43
  int v22; // ecx@43
  CharGenState *v23; // eax@48
  CharGenState *v24; // edi@48
  int v25; // ecx@50
  int v26; // eax@50
  CharGenState *v27; // eax@54
  CharGenState *v28; // edi@54
  int v29; // ecx@56
  int v30; // eax@56
  CharGenState *v31; // eax@60
  CharGenState *v32; // edi@60
  int v33; // ecx@62
  int v34; // eax@62
  CharGenState *v35; // eax@66
  CharGenState *v36; // edi@66
  int v37; // edi@71
  int v38; // edi@72
  int v39; // edi@73
  int v40; // ecx@74
  int v41; // edi@74
  CharGenState *v42; // eax@79
  CharGenState *v43; // edi@79
  int v44; // eax@80
  int v45; // edi@80
  CharGenState *v46; // eax@84
  CharGenState *v47; // edi@84
  int v48; // eax@85
  int v49; // edi@85
  CharGenState *v50; // eax@89
  CharGenState *v51; // edi@89
  int v52; // eax@90
  int v53; // edi@90
  CharGenState *v54; // eax@94
  CharGenState *v55; // edi@94
  int v56; // eax@100
  int v57; // eax@104
  int v58; // eax@106
  int v59; // eax@110
  int v60; // eax@112
  int v61; // eax@116
  int v62; // ecx@117
  int v63; // edi@117
  CharGenState *v64; // eax@122
  CharGenState *v65; // edi@122
  int v66; // eax@123
  int v67; // edi@123
  CharGenState *v68; // eax@127
  CharGenState *v69; // edi@127
  int v70; // eax@128
  int v71; // edi@128
  CharGenState *v72; // eax@132
  CharGenState *v73; // edi@132
  int v74; // eax@133
  int v75; // edi@133
  CharGenState *v76; // eax@137
  CharGenState *v77; // edi@137
  long double v78; // st7@166

  v3 = this;
  switch ( i_rMsg->idElement )
  {
    case 0x100003A7u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
      CharGenState::SetGender(v4, 2u);
      gmCGAppearancePage::Update(v3, a2);
      if ( !UIElement::IsVisible((UIElement *)&v3->vfptr) )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCG3DView::Update(v3->m_p3DView);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003A8u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
      CharGenState::SetGender(v6, 1u);
      gmCGAppearancePage::Update(v3, a2);
      if ( !UIElement::IsVisible((UIElement *)&v3->vfptr) )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCG3DView::Update(v3->m_p3DView);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003A9u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetChoice(this, ECG_CHOICE_FACE);
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_HAIR);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003AAu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetChoice(this, ECG_CHOICE_CLOTHES);
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_HEADGEAR);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003AFu:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v7 = this->m_tChoices[0].iCurrentChoice;
      v8 = v3->m_tChoices[0].iNumChoices;
      if ( v7 >= v8 )
      {
LABEL_98:
        v3->m_tChoices[0].iCurrentChoice = 0;
      }
      else
      {
LABEL_14:
        if ( v7 < 0 )
          v3->m_tChoices[0].iCurrentChoice = v8 - 1;
      }
LABEL_16:
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      *(_DWORD *)(v9 + 240) = v3->m_tChoices[0].iCurrentChoice;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_HAIR);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B0u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v10 = this->m_tChoices[1].iCurrentChoice;
      v11 = v3->m_tChoices[1].iNumChoices;
      if ( v10 < v11 )
      {
        if ( v10 < 0 )
          v3->m_tChoices[1].iCurrentChoice = v11 - 1;
      }
      else
      {
        v3->m_tChoices[1].iCurrentChoice = 0;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      *(_DWORD *)(v12 + 220) = v3->m_tChoices[1].iCurrentChoice;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_EYES);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B1u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v13 = this->m_tChoices[2].iCurrentChoice;
      v14 = v3->m_tChoices[2].iNumChoices;
      if ( v13 < v14 )
      {
        if ( v13 < 0 )
          v3->m_tChoices[2].iCurrentChoice = v14 - 1;
      }
      else
      {
        v3->m_tChoices[2].iCurrentChoice = 0;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      *(_DWORD *)(v15 + 224) = v3->m_tChoices[2].iCurrentChoice;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_NOSE);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B2u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v16 = this->m_tChoices[3].iCurrentChoice;
      v17 = v3->m_tChoices[3].iNumChoices;
      if ( v16 < v17 )
      {
        if ( v16 < 0 )
          v3->m_tChoices[3].iCurrentChoice = v17 - 1;
      }
      else
      {
        v3->m_tChoices[3].iCurrentChoice = 0;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      *(_DWORD *)(v18 + 228) = v3->m_tChoices[3].iCurrentChoice;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_MOUTH);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B3u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v19 = this->m_tChoices[4].iCurrentChoice;
      v20 = v3->m_tChoices[4].iNumChoices;
      if ( v19 < v20 )
      {
        if ( v19 < 0 )
          v3->m_tChoices[4].iCurrentChoice = v20 - 1;
      }
      else
      {
        v3->m_tChoices[4].iCurrentChoice = 0;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_SKIN);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B5u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v21 = this->m_tChoices[5].iCurrentChoice;
      v22 = this->m_tChoices[5].iNumChoices;
      if ( v21 < v22 )
      {
        if ( v21 < 0 && v21 != -1 )
          v3->m_tChoices[5].iCurrentChoice = v22 - 1;
      }
      else
      {
        v3->m_tChoices[5].iCurrentChoice = -1;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      v24 = v23;
      CharGenState::SetHeadgearStyle(v23, v3->m_tChoices[5].iCurrentChoice);
      v3->m_tChoices[5].iCurrentColor = v24->headgearColor;
      v3->m_tChoices[5].iNumColors = v24->numHeadgearColors;
      v3->m_tChoices[5].dShade = v24->headgearShade;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_HEADGEAR);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B6u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v25 = this->m_tChoices[6].iCurrentChoice;
      v26 = v3->m_tChoices[6].iNumChoices;
      if ( v25 < v26 )
      {
        if ( v25 < 0 )
          v3->m_tChoices[6].iCurrentChoice = v26 - 1;
      }
      else
      {
        v3->m_tChoices[6].iCurrentChoice = 0;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      v28 = v27;
      CharGenState::SetShirtStyle(v27, v3->m_tChoices[6].iCurrentChoice);
      v3->m_tChoices[6].iCurrentColor = v28->shirtColor;
      v3->m_tChoices[6].iNumColors = v28->numShirtColors;
      v3->m_tChoices[6].dShade = v28->shirtShade;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_SHIRT);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B7u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v29 = this->m_tChoices[7].iCurrentChoice;
      v30 = v3->m_tChoices[7].iNumChoices;
      if ( v29 < v30 )
      {
        if ( v29 < 0 )
          v3->m_tChoices[7].iCurrentChoice = v30 - 1;
      }
      else
      {
        v3->m_tChoices[7].iCurrentChoice = 0;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      v32 = v31;
      CharGenState::SetTrousersStyle(v31, v3->m_tChoices[7].iCurrentChoice);
      v3->m_tChoices[7].iCurrentColor = v32->trousersColor;
      v3->m_tChoices[7].iNumColors = v32->numTrousersColors;
      v3->m_tChoices[7].dShade = v32->trousersShade;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_TROUSERS);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x100003B8u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v33 = this->m_tChoices[8].iCurrentChoice;
      v34 = v3->m_tChoices[8].iNumChoices;
      if ( v33 < v34 )
      {
        if ( v33 < 0 )
          v3->m_tChoices[8].iCurrentChoice = v34 - 1;
      }
      else
      {
        v3->m_tChoices[8].iCurrentChoice = 0;
      }
      CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
      v36 = v35;
      CharGenState::SetFootwearStyle(v35, v3->m_tChoices[8].iCurrentChoice);
      v3->m_tChoices[8].iCurrentColor = v36->footwearColor;
      v3->m_tChoices[8].iNumColors = v36->numFootwearColors;
      v3->m_tChoices[8].dShade = v36->footwearShade;
      gmCGAppearancePage::SetSelection(v3, ECG_PARTS_FOOTWEAR);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x1000030Au:
      if ( i_rMsg->idMessage == 1 )
      {
        switch ( *(_DWORD *)(((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)() + 740) )
        {
          case 0x100003AF:
            v8 = v3->m_tChoices[0].iNumChoices;
            v7 = v3->m_tChoices[0].iCurrentChoice - 1;
            v3->m_tChoices[0].iCurrentChoice = v7;
            if ( v7 < v8 )
              goto LABEL_14;
            v3->m_tChoices[0].iCurrentChoice = 0;
            goto LABEL_16;
          case 0x100003B0:
            v37 = v3->m_tChoices[1].iCurrentChoice - 1;
            goto LABEL_100;
          case 0x100003B1:
            v38 = v3->m_tChoices[2].iCurrentChoice - 1;
            goto LABEL_106;
          case 0x100003B2:
            v39 = v3->m_tChoices[3].iCurrentChoice - 1;
            goto LABEL_112;
          case 0x100003B5:
            v40 = v3->m_tChoices[5].iNumChoices;
            v41 = v3->m_tChoices[5].iCurrentChoice - 1;
            v3->m_tChoices[5].iCurrentChoice = v41;
            if ( v41 < v40 )
            {
              if ( v41 < 0 && v41 != -1 )
                v3->m_tChoices[5].iCurrentChoice = v40 - 1;
            }
            else
            {
              v3->m_tChoices[5].iCurrentChoice = -1;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v43 = v42;
            CharGenState::SetHeadgearStyle(v42, v3->m_tChoices[5].iCurrentChoice);
            v3->m_tChoices[5].iCurrentColor = v43->headgearColor;
            v3->m_tChoices[5].iNumColors = v43->numHeadgearColors;
            v3->m_tChoices[5].dShade = v43->headgearShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_HEADGEAR);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B6:
            v44 = v3->m_tChoices[6].iNumChoices;
            v45 = v3->m_tChoices[6].iCurrentChoice - 1;
            v3->m_tChoices[6].iCurrentChoice = v45;
            if ( v45 < v44 )
            {
              if ( v45 < 0 )
                v3->m_tChoices[6].iCurrentChoice = v44 - 1;
            }
            else
            {
              v3->m_tChoices[6].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v47 = v46;
            CharGenState::SetShirtStyle(v46, v3->m_tChoices[6].iCurrentChoice);
            v3->m_tChoices[6].iCurrentColor = v47->shirtColor;
            v3->m_tChoices[6].iNumColors = v47->numShirtColors;
            v3->m_tChoices[6].dShade = v47->shirtShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_SHIRT);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B7:
            v48 = v3->m_tChoices[7].iNumChoices;
            v49 = v3->m_tChoices[7].iCurrentChoice - 1;
            v3->m_tChoices[7].iCurrentChoice = v49;
            if ( v49 < v48 )
            {
              if ( v49 < 0 )
                v3->m_tChoices[7].iCurrentChoice = v48 - 1;
            }
            else
            {
              v3->m_tChoices[7].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v51 = v50;
            CharGenState::SetTrousersStyle(v50, v3->m_tChoices[7].iCurrentChoice);
            v3->m_tChoices[7].iCurrentColor = v51->trousersColor;
            v3->m_tChoices[7].iNumColors = v51->numTrousersColors;
            v3->m_tChoices[7].dShade = v51->trousersShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_TROUSERS);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B8:
            v52 = v3->m_tChoices[8].iNumChoices;
            v53 = v3->m_tChoices[8].iCurrentChoice - 1;
            v3->m_tChoices[8].iCurrentChoice = v53;
            if ( v53 < v52 )
            {
              if ( v53 < 0 )
                v3->m_tChoices[8].iCurrentChoice = v52 - 1;
            }
            else
            {
              v3->m_tChoices[8].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v55 = v54;
            CharGenState::SetFootwearStyle(v54, v3->m_tChoices[8].iCurrentChoice);
            v3->m_tChoices[8].iCurrentColor = v55->footwearColor;
            v3->m_tChoices[8].iNumColors = v55->numFootwearColors;
            v3->m_tChoices[8].dShade = v55->footwearShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_FOOTWEAR);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          default:
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
      }
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x1000030Bu:
      if ( i_rMsg->idMessage == 1 )
      {
        switch ( *(_DWORD *)(((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)() + 740) )
        {
          case 0x100003AF:
            v8 = v3->m_tChoices[0].iNumChoices;
            v7 = v3->m_tChoices[0].iCurrentChoice + 1;
            v3->m_tChoices[0].iCurrentChoice = v7;
            if ( v7 >= v8 )
              goto LABEL_98;
            goto LABEL_14;
          case 0x100003B0:
            v37 = v3->m_tChoices[1].iCurrentChoice + 1;
LABEL_100:
            v3->m_tChoices[1].iCurrentChoice = v37;
            v56 = v3->m_tChoices[1].iNumChoices;
            if ( v37 < v56 )
            {
              if ( v37 < 0 )
                v3->m_tChoices[1].iCurrentChoice = v56 - 1;
            }
            else
            {
              v3->m_tChoices[1].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            *(_DWORD *)(v57 + 220) = v3->m_tChoices[1].iCurrentChoice;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_EYES);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B1:
            v38 = v3->m_tChoices[2].iCurrentChoice + 1;
LABEL_106:
            v3->m_tChoices[2].iCurrentChoice = v38;
            v58 = v3->m_tChoices[2].iNumChoices;
            if ( v38 < v58 )
            {
              if ( v38 < 0 )
                v3->m_tChoices[2].iCurrentChoice = v58 - 1;
            }
            else
            {
              v3->m_tChoices[2].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            *(_DWORD *)(v59 + 224) = v3->m_tChoices[2].iCurrentChoice;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_NOSE);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B2:
            v39 = v3->m_tChoices[3].iCurrentChoice + 1;
LABEL_112:
            v3->m_tChoices[3].iCurrentChoice = v39;
            v60 = v3->m_tChoices[3].iNumChoices;
            if ( v39 < v60 )
            {
              if ( v39 < 0 )
                v3->m_tChoices[3].iCurrentChoice = v60 - 1;
            }
            else
            {
              v3->m_tChoices[3].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            *(_DWORD *)(v61 + 228) = v3->m_tChoices[3].iCurrentChoice;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_MOUTH);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B5:
            v62 = v3->m_tChoices[5].iNumChoices;
            v63 = v3->m_tChoices[5].iCurrentChoice + 1;
            v3->m_tChoices[5].iCurrentChoice = v63;
            if ( v63 < v62 )
            {
              if ( v63 < 0 && v63 != -1 )
                v3->m_tChoices[5].iCurrentChoice = v62 - 1;
            }
            else
            {
              v3->m_tChoices[5].iCurrentChoice = -1;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v65 = v64;
            CharGenState::SetHeadgearStyle(v64, v3->m_tChoices[5].iCurrentChoice);
            v3->m_tChoices[5].iCurrentColor = v65->headgearColor;
            v3->m_tChoices[5].iNumColors = v65->numHeadgearColors;
            v3->m_tChoices[5].dShade = v65->headgearShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_HEADGEAR);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B6:
            v66 = v3->m_tChoices[6].iNumChoices;
            v67 = v3->m_tChoices[6].iCurrentChoice + 1;
            v3->m_tChoices[6].iCurrentChoice = v67;
            if ( v67 < v66 )
            {
              if ( v67 < 0 )
                v3->m_tChoices[6].iCurrentChoice = v66 - 1;
            }
            else
            {
              v3->m_tChoices[6].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v69 = v68;
            CharGenState::SetShirtStyle(v68, v3->m_tChoices[6].iCurrentChoice);
            v3->m_tChoices[6].iCurrentColor = v69->shirtColor;
            v3->m_tChoices[6].iNumColors = v69->numShirtColors;
            v3->m_tChoices[6].dShade = v69->shirtShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_SHIRT);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B7:
            v70 = v3->m_tChoices[7].iNumChoices;
            v71 = v3->m_tChoices[7].iCurrentChoice + 1;
            v3->m_tChoices[7].iCurrentChoice = v71;
            if ( v71 < v70 )
            {
              if ( v71 < 0 )
                v3->m_tChoices[7].iCurrentChoice = v70 - 1;
            }
            else
            {
              v3->m_tChoices[7].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v73 = v72;
            CharGenState::SetTrousersStyle(v72, v3->m_tChoices[7].iCurrentChoice);
            v3->m_tChoices[7].iCurrentColor = v73->trousersColor;
            v3->m_tChoices[7].iNumColors = v73->numTrousersColors;
            v3->m_tChoices[7].dShade = v73->trousersShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_TROUSERS);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          case 0x100003B8:
            v74 = v3->m_tChoices[8].iNumChoices;
            v75 = v3->m_tChoices[8].iCurrentChoice + 1;
            v3->m_tChoices[8].iCurrentChoice = v75;
            if ( v75 < v74 )
            {
              if ( v75 < 0 )
                v3->m_tChoices[8].iCurrentChoice = v74 - 1;
            }
            else
            {
              v3->m_tChoices[8].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
            v77 = v76;
            CharGenState::SetFootwearStyle(v76, v3->m_tChoices[8].iCurrentChoice);
            v3->m_tChoices[8].iCurrentColor = v77->footwearColor;
            v3->m_tChoices[8].iNumColors = v77->numFootwearColors;
            v3->m_tChoices[8].dShade = v77->footwearShade;
            gmCGAppearancePage::SetSelection(v3, ECG_PARTS_FOOTWEAR);
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
          default:
            return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
      }
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x1000030Fu:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 0 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 0);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000310u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 1);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000311u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 2 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 2);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000312u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 3 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 3);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000313u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 4 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 4);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000314u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 5 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 5);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000315u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 6 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 6);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000316u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 7 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 7);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000317u:
      if ( i_rMsg->idMessage != 1 || (signed int)(&this->vfptr)[2 * (this->m_iPartIndex + 75)] <= 8 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::SetColor(this, 8);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000321u:
      if ( i_rMsg->idMessage != 10 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      v78 = MathLib::Clamp((double)i_rMsg->dwParam1 * 0.001, 0.0, 1.0);
      gmCGAppearancePage::SetShade(v3, v78);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000325u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::ZoomIn(this);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000326u:
      if ( i_rMsg->idMessage != 1 )
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      gmCGAppearancePage::ZoomOut(this);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
    case 0x10000323u:
      if ( i_rMsg->idMessage == 1 )
        gmCGAppearancePage::Rotate(this, ECG_ROTATE_CLOCKWISE);
      break;
    case 0x10000324u:
      if ( i_rMsg->idMessage == 1 )
        gmCGAppearancePage::Rotate(this, ECG_ROTATE_COUNTERCLOCKWISE);
      break;
    default:
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (0047FDD0) --------------------------------------------------------  // acclient.c:188165
void __userpurge gmCGAppearancePage::InitializePage(gmCGAppearancePage *this@<ecx>, long double a2@<st0>, gmCharGenMainUI *_pMain)
{
  gmCGAppearancePage *v3; // esi@1
  CPlayerSystem *v4; // eax@1
  CharGenState *v5; // eax@1
  UIElement *v6; // eax@1
  int v7; // eax@2
  UIElement *v8; // eax@4
  int v9; // eax@5
  UIElement *v10; // eax@7
  int v11; // eax@8
  UIElement *v12; // eax@10
  int v13; // eax@11
  UIElement *v14; // eax@13
  int v15; // eax@14
  UIElement *v16; // eax@16
  int v17; // eax@17
  UIElement *v18; // eax@19
  int v19; // eax@20
  UIElement *v20; // eax@22
  int v21; // eax@23
  UIElement *v22; // eax@25
  UIElement *v23; // eax@26
  UIElement *v24; // eax@29
  UIElement *v25; // eax@31
  UIElement *v26; // eax@33
  int v27; // eax@34
  UIElement *v28; // eax@36
  int v29; // eax@37
  UIElement *v30; // eax@39
  int v31; // eax@40
  UIElement *v32; // eax@42
  int v33; // eax@43
  UIElement *v34; // eax@45
  int v35; // eax@46
  UIElement *v36; // eax@48
  int v37; // eax@49
  UIElement *v38; // eax@51
  int v39; // eax@52
  UIElement *v40; // eax@54
  int v41; // eax@55
  gmCharGenMainUI *v42; // eax@57
  unsigned int v43; // edi@57
  unsigned int v44; // ebp@57
  int v45; // ebx@69
  bool v46; // sf@69
  unsigned __int8 v47; // of@69
  UIElement *v48; // eax@70
  int v49; // eax@71
  UIElement *v50; // eax@73
  int v51; // eax@74
  gmCG3DView *v52; // eax@76
  gmCG3DView *v53; // eax@77
  UIElement_Viewport *v54; // ST04_4@79
  gmCG3DView *v55; // ecx@79
  int v56; // ecx@79
  unsigned int v57; // eax@79
  signed int v58; // ebx@80
  signed int v59; // edx@80
  int v60; // eax@85
  int v61; // eax@85
  int v62; // eax@85
  CharGenState *v63; // eax@89
  unsigned int v64; // [sp-8h] [bp-Ch]@87
  CharGenState *cg; // [sp+0h] [bp-4h]@1
  gmCharGenMainUI *_pMaina; // [sp+8h] [bp+4h]@57

  v3 = this;
  this->m_pMainFramework = _pMain;
  v4 = CPlayerSystem::GetPlayerSystem();
  v3->m_pPlayerSystem = v4;
  CPlayerSystem::GetCharGenState(v4);
  cg = v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003A7u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)1);
  else
    v7 = 0;
  v3->m_pFemaleButton = (UIElement_Button *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003A8u);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)1);
  else
    v9 = 0;
  v3->m_pMaleButton = (UIElement_Button *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003A9u);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)1);
  else
    v11 = 0;
  v3->m_pFaceButton = (UIElement_Button *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003AAu);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)1);
  else
    v13 = 0;
  v3->m_pClothesButton = (UIElement_Button *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003AFu);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)1);
  else
    v15 = 0;
  v3->m_pHairSpin = (UIElement_Button *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B0u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)1);
  else
    v17 = 0;
  v3->m_pEyesSpin = (UIElement_Button *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B1u);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)1);
  else
    v19 = 0;
  v3->m_pNoseSpin = (UIElement_Button *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B2u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)1);
  else
    v21 = 0;
  v3->m_pMouthSpin = (UIElement_Button *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B3u);
  if ( v22 )
    v23 = (UIElement *)v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)1);
  else
    v23 = 0;
  v3->m_pSkinSpin = (UIElement_Button *)v23;
  if ( v23 )
  {
    v24 = UIElement::GetChildRecursive(v23, 0x1000030Au);
    if ( v24 )
      UIElement::SetAttribute_Bool(v24, 0xDu, 1);
    v25 = UIElement::GetChildRecursive((UIElement *)&v3->m_pSkinSpin->vfptr, 0x1000030Bu);
    if ( v25 )
      UIElement::SetAttribute_Bool(v25, 0xDu, 1);
  }
  v26 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B5u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)1);
  else
    v27 = 0;
  v3->m_pHeadgearSpin = (UIElement_Button *)v27;
  v28 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B6u);
  if ( v28 )
    v29 = v28->vfptr[12].OnAction((IInputActionCallback *)v28, (InputEvent *)1);
  else
    v29 = 0;
  v3->m_pShirtSpin = (UIElement_Button *)v29;
  v30 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B7u);
  if ( v30 )
    v31 = v30->vfptr[12].OnAction((IInputActionCallback *)v30, (InputEvent *)1);
  else
    v31 = 0;
  v3->m_pTrousersSpin = (UIElement_Button *)v31;
  v32 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B8u);
  if ( v32 )
    v33 = v32->vfptr[12].OnAction((IInputActionCallback *)v32, (InputEvent *)1);
  else
    v33 = 0;
  v3->m_pFootwearSpin = (UIElement_Button *)v33;
  v34 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x10000325u);
  if ( v34 )
    v35 = v34->vfptr[12].OnAction((IInputActionCallback *)v34, (InputEvent *)1);
  else
    v35 = 0;
  v3->m_pZoomInButton = (UIElement_Button *)v35;
  v36 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x10000326u);
  if ( v36 )
    v37 = v36->vfptr[12].OnAction((IInputActionCallback *)v36, (InputEvent *)1);
  else
    v37 = 0;
  v3->m_pZoomOutButton = (UIElement_Button *)v37;
  v38 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x10000323u);
  if ( v38 )
    v39 = v38->vfptr[12].OnAction((IInputActionCallback *)v38, (InputEvent *)1);
  else
    v39 = 0;
  v3->m_pRotateClockButton = (UIElement_Button *)v39;
  v40 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x10000324u);
  if ( v40 )
    v41 = v40->vfptr[12].OnAction((IInputActionCallback *)v40, (InputEvent *)1);
  else
    v41 = 0;
  v3->m_pRotateCounterClockButton = (UIElement_Button *)v41;
  v3->m_pFaceChoices = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003AEu);
  v3->m_pClothesChoices = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003B4u);
  v42 = 0;
  _pMaina = 0;
  v43 = 0;
  v44 = 0;
  while ( 1 )
  {
    switch ( v42 )
    {
      case 0u:
        v43 = 268436239;
        v44 = 268436248;
        break;
      case 1u:
        v43 = 268436240;
        v44 = 268436249;
        break;
      case 2u:
        v43 = 268436241;
        v44 = 268436250;
        break;
      case 3u:
        v43 = 268436242;
        v44 = 268436251;
        break;
      case 4u:
        v43 = 268436243;
        v44 = 268436252;
        break;
      case 5u:
        v43 = 268436244;
        v44 = 268436253;
        break;
      case 6u:
        v43 = 268436245;
        v44 = 268436254;
        break;
      case 7u:
        v43 = 268436246;
        v44 = 268436255;
        break;
      case 8u:
        v43 = 268436247;
        v44 = 268436256;
        break;
      default:
        break;
    }
    v45 = (int)((char *)v3 + 28 * (_DWORD)v42);
    *(_DWORD *)(v45 + 2024) = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, v43);
    *(_DWORD *)(v45 + 2028) = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, v44);
    v47 = __OFSUB__((char *)&_pMaina->vfptr + 1, 9);
    v46 = (signed int)&_pMaina[-1].m_uiRandomizeWarningContext < 0;
    _pMaina = (gmCharGenMainUI *)((char *)_pMaina + 1);
    if ( !(v46 ^ v47) )
      break;
    v42 = _pMaina;
  }
  v3->m_pGradCircle = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x1000030Eu);
  v48 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x10000321u);
  if ( v48 )
    v49 = v48->vfptr[12].OnAction((IInputActionCallback *)v48, (InputEvent *)11);
  else
    v49 = 0;
  v3->m_pShadeScroll = (UIElement_Scrollbar *)v49;
  v50 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, 0x100003BBu);
  if ( v50 )
    v51 = v50->vfptr[12].OnAction((IInputActionCallback *)v50, (InputEvent *)13);
  else
    v51 = 0;
  v3->m_pViewport = (UIElement_Viewport *)v51;
  v52 = (gmCG3DView *)operator new(0x60u);
  if ( v52 )
    gmCG3DView::gmCG3DView(v52);
  else
    v53 = 0;
  v54 = v3->m_pViewport;
  v3->m_p3DView = v53;
  gmCG3DView::Initialize(v53, v54);
  v55 = v3->m_p3DView;
  LODWORD(v3->m_fCurHeading) = 1127481344;
  gmCG3DView::SetPlayerHeading(v55, 180.0);
  v56 = (int)&v3->m_vectCurDirection;
  *(_DWORD *)v56 = 0;
  *(_DWORD *)(v56 + 4) = 0;
  *(_DWORD *)(v56 + 8) = 0;
  v57 = cg->mHeritageGroup;
  if ( v57 == 12 )
  {
    v58 = -1075000115;
    v59 = 1072483533;
  }
  else if ( v57 == 13 )
  {
    v58 = -1069337805;
    v59 = 1076887552;
  }
  else
  {
    v59 = 1070805811;
    v58 = -1084647014;
    if ( v57 != 7 )
      v58 = -1089680179;
  }
  LODWORD(v3->m_vectTargPosition.z) = v59;
  LODWORD(v3->m_vectTargPosition.y) = v58;
  v60 = (int)&v3->m_vectCurPosition;
  LODWORD(v3->m_vectTargPosition.x) = 0;
  *(_DWORD *)v60 = 0;
  *(_DWORD *)(v60 + 4) = v58;
  *(_DWORD *)(v60 + 8) = v59;
  gmCG3DView::SetCamera(v3->m_p3DView, &v3->m_vectCurPosition, &v3->m_vectCurDirection);
  v3->m_bZoomedIn = 0;
  gmCGAppearancePage::SetChoice(v3, ECG_CHOICE_FACE);
  CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
  v62 = *(_DWORD *)(v61 + 216) - 1;
  if ( v62 )
  {
    if ( v62 != 1 )
      goto LABEL_90;
    v64 = 1;
  }
  else
  {
    v64 = 2;
  }
  CPlayerSystem::GetCharGenState(v3->m_pPlayerSystem);
  CharGenState::SetGender(v63, v64);
  gmCGAppearancePage::Update(v3, a2);
LABEL_90:
  if ( UIElement::IsVisible((UIElement *)&v3->vfptr) )
    gmCG3DView::Update(v3->m_p3DView);
  gmCGAppearancePage::SetupParts(v3);
  gmCGAppearancePage::SetSelection(v3, v3->m_eCurPart);
}

//----- (006ECD40) --------------------------------------------------------  // acclient.c:768648
void _E91_40()
{
  outside_val_32 = 1000.0 + 1.0;
}

//----- (006ECD60) --------------------------------------------------------  // acclient.c:768654
void _E93_16()
{
  block_length_32 = 24.0 * 8.0;
}

//----- (006ECD80) --------------------------------------------------------  // acclient.c:768660
void _E95_16()
{
  half_square_length_32 = 24.0 * 0.5;
}

//----- (006ECDA0) --------------------------------------------------------  // acclient.c:768666
int _E97_41()
{
  return atexit(_E98_53);
}

//----- (006ECDB0) --------------------------------------------------------  // acclient.c:768672
int _E100_34()
{
  return atexit(_E101_71);
}

//----- (006ECDC0) --------------------------------------------------------  // acclient.c:768678
int _E103_26()
{
  return atexit(_E104_41);
}

//----- (006ECDD0) --------------------------------------------------------  // acclient.c:768684
void _E106_22()
{
  DEFAULT_VIEW_RADIUS_16 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006ECDF0) --------------------------------------------------------  // acclient.c:768690
void _E108_14()
{
  MIN_QUANTUM_16 = 1.0 / 30.0;
}

//----- (006ECE10) --------------------------------------------------------  // acclient.c:768696
void _E110_5()
{
  MAX_QUANTUM_16 = 1.0 / 5.0;
}

//----- (006ECE30) --------------------------------------------------------  // acclient.c:768702
void _E112_18()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_51, PFID_A8R8G8B8);
}

//----- (006ECE40) --------------------------------------------------------  // acclient.c:768708
int _E114_17()
{
  return atexit(nullsub_513);
}

//----- (006ECE50) --------------------------------------------------------  // acclient.c:768714
void _E118_23()
{
  LOWEST_DATA_RATE_59 = 1024;
}

//----- (006ECE60) --------------------------------------------------------  // acclient.c:768720
void _E120_14()
{
  HIGHEST_DATA_RATE_59 = 0x7FFF;
}

//----- (006ECE70) --------------------------------------------------------  // acclient.c:768726
int _E122_3()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_59;
  INITIAL_MAX_DATA_RATE_7 = LOWEST_DATA_RATE_59;
  return result;
}

//----- (006ECE80) --------------------------------------------------------  // acclient.c:768736
int _E1_92()
{
  return atexit(_E2_92);
}

