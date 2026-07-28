/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmBarberUI
   Object     : GAME\game_ui_misc\gmBarberUI.obj
   Functions  : 109
   Addresses  : 004DE140 - 006F60B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004DE140) --------------------------------------------------------  // acclient.c:268985
void __thiscall CharAppearanceData::CharAppearanceData(CharAppearanceData *this)
{
  this->base_palette.id = script_id.id;
  this->head_object.id = script_id.id;
  this->eyes_texture.id = script_id.id;
  this->nose_texture.id = script_id.id;
  this->mouth_texture.id = script_id.id;
  this->default_eyes_texture.id = script_id.id;
  this->default_nose_texture.id = script_id.id;
  this->default_mouth_texture.id = script_id.id;
  this->hair_palette.id = script_id.id;
  this->eyes_palette.id = script_id.id;
  this->skin_palette.id = script_id.id;
}

//----- (004DE1B0) --------------------------------------------------------  // acclient.c:269001
void __userpurge gmBarberUI::gmBarberUI(gmBarberUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmBarberUI *v4; // esi@1
  int v5; // ecx@1
  signed int v6; // edx@1
  int v7; // ecx@3
  signed int v8; // edx@3

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmBarberUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmBarberUI::vftable;
  v4->m_pRotateClockButton = 0;
  v4->m_pRotateCounterClockButton = 0;
  v4->m_pShadeScroll = 0;
  v4->m_pGradCircle = 0;
  v4->m_pGradGraphic = 0;
  v4->m_pGradPlug = 0;
  v4->m_iCurColor = -1;
  v4->m_iHoldheadgear = -999;
  v4->m_bRotating = 0;
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
// 7BED00: using guessed type bool (__thiscall *gmBarberUI::vftable)(DBCache *this);
// 7BEFA8: using guessed type int (__thiscall *gmBarberUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DE2B0) --------------------------------------------------------  // acclient.c:269067
gmBarberUI *__thiscall gmBarberUI::DynamicCast(gmBarberUI *this, unsigned int i_eType)
{
  gmBarberUI *result; // eax@1

  result = this;
  if ( i_eType != 268435530 )
    result = (gmBarberUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004DE2D0) --------------------------------------------------------  // acclient.c:269078
signed int gmBarberUI::GetUIElementType()
{
  return 268435530;
}

//----- (004DE2E0) --------------------------------------------------------  // acclient.c:269084
void __thiscall gmBarberUI::PostInit(gmBarberUI *this)
{
  gmBarberUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@2
  int v4; // eax@5

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v3 = (int)&v1->vfptr;
  else
    v3 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100016u, (NoticeHandler *)v3);
  if ( v1 )
    v4 = (int)&v1->vfptr;
  else
    v4 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD279 + 5), (NoticeHandler *)v4);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  LODWORD(v1->m_fCurHeading) = 1127481344;
}

//----- (004DE340) --------------------------------------------------------  // acclient.c:269109
void __usercall gmBarberUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmBarberUI *v3; // eax@1

  v3 = (gmBarberUI *)operator new(0x868u);
  if ( v3 )
    gmBarberUI::gmBarberUI(v3, a1, _layout, _full_desc);
}

//----- (004DE370) --------------------------------------------------------  // acclient.c:269119
void __thiscall HairStyle_CG::HairStyle_CG(HairStyle_CG *this, HairStyle_CG *__that)
{
  this->vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
  this->iconImage.id = __that->iconImage.id;
  this->bald = __that->bald;
  this->alternateSetup.id = __that->alternateSetup.id;
  ObjDesc::ObjDesc(&this->objDesc, &__that->objDesc);
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (004DE3B0) --------------------------------------------------------  // acclient.c:269130
void __thiscall gmBarberUI::RecvNotice_PlayerObjDescChanged(gmBarberUI *this)
{
  gmBarberUI *v1; // esi@1

  v1 = this;
  if ( UIElement::IsVisible((UIElement *)&this[-1].m_desc.m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[1]) )
    gmCG3DView::Update((gmCG3DView *)v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[18]);
}

//----- (004DE3D0) --------------------------------------------------------  // acclient.c:269140
void __thiscall gmBarberUI::SetShade(gmBarberUI *this, long double _dShade)
{
  gmBarberUI *v2; // esi@1
  float _val; // ST04_4@1
  CharGenState *v4; // eax@1
  signed int v5; // edx@1

  v2 = this;
  _val = _dShade;
  UIElement::SetAttribute_Float((UIElement *)&this->m_pShadeScroll->vfptr, 0x86u, _val);
  CPlayerSystem::GetCharGenState(v2->m_pPlayerSystem);
  v5 = v2->m_eCurPart;
  if ( v5 == 1 )
  {
    CharGenState::SetHairShade(v4, _dShade);
  }
  else if ( v5 > 2 && v5 <= 5 )
  {
    CharGenState::SetSkinShade(v4, _dShade);
  }
  if ( UIElement::IsVisible((UIElement *)&v2->vfptr) )
    gmCG3DView::Update(v2->m_p3DView);
}

//----- (004DE450) --------------------------------------------------------  // acclient.c:269165
void __thiscall gmBarberUI::DoRotation(gmBarberUI *this)
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

//----- (004DE520) --------------------------------------------------------  // acclient.c:269194
void __thiscall gmBarberUI::Rotate(gmBarberUI *this, gmBarberUI::ERotateDirection _eDir)
{
  gmBarberUI *v2; // esi@1

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

//----- (004DE5A0) --------------------------------------------------------  // acclient.c:269221
UIElement_Field *__thiscall gmBarberUI::scalar_deleting_destructor(gmBarberUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmBarberUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmBarberUI::vftable;
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
// 7BED00: using guessed type bool (__thiscall *gmBarberUI::vftable)(DBCache *this);
// 7BEFA8: using guessed type int (__thiscall *gmBarberUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DE600) --------------------------------------------------------  // acclient.c:269246
void __cdecl gmBarberUI::Register()
{
  UIElement::RegisterElementClass(0x1000004Au, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmBarberUI::Create);
}

//----- (004DE620) --------------------------------------------------------  // acclient.c:269252
void __thiscall gmBarberUI::ListenToGlobalMessage(gmBarberUI *this, unsigned int _messageID, int _data_int)
{
  if ( _messageID == 3 )
  {
    if ( this->m_bRotating )
      gmBarberUI::DoRotation(this);
  }
}

//----- (004DE640) --------------------------------------------------------  // acclient.c:269262
void __thiscall gmBarberUI::DoColorSpots(gmBarberUI *this, int _iPart)
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
  gmBarberUI *v28; // [sp+2Ch] [bp-34h]@1
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
      if ( i >= v28->m_tChoices[_iPart].iNumColors )
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

//----- (004DE880) --------------------------------------------------------  // acclient.c:269389
void __thiscall gmBarberUI::DoGradDisk(gmBarberUI *this, bool _bUsePlug)
{
  gmBarberUI *v2; // esi@1
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
    v11 = *((_DWORD *)&v2->vfptr + 7 * (v9 + 68));
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

//----- (004DEB40) --------------------------------------------------------  // acclient.c:269541
void __thiscall gmBarberUI::SetColor(gmBarberUI *this, int _iColor)
{
  gmBarberUI *v2; // esi@1
  int v3; // eax@1
  CPlayerSystem *v4; // ecx@5
  CharGenState *v5; // eax@5
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
  if ( v2->m_eCurPart == 1 )
  {
    CharGenState::SetHairColor(v5, v2->m_iCurColor);
  }
  else if ( v2->m_eCurPart == 2 )
  {
    CharGenState::SetEyeColor(v5, v2->m_iCurColor);
    _iColora = 1;
  }
  gmBarberUI::DoGradDisk(v2, _iColora);
  if ( UIElement::IsVisible((UIElement *)&v2->vfptr) )
    gmCG3DView::Update(v2->m_p3DView);
}

//----- (004DEBF0) --------------------------------------------------------  // acclient.c:269574
void __thiscall gmBarberUI::SetupParts(gmBarberUI *this)
{
  gmBarberUI *v1; // esi@1
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
  v10 = curSX.mShirtList.m_num;
  v1->m_tChoices[3].iNumColors = 0;
  LODWORD(v1->m_tChoices[3].dShade) = 0;
  HIDWORD(v1->m_tChoices[3].dShade) = 0;
  v1->m_tChoices[6].iCurrentChoice = *(_DWORD *)(v3 + 252);
  v1->m_tChoices[6].iNumChoices = v10;
  v1->m_tChoices[6].iCurrentColor = *(_DWORD *)(v3 + 256);
  v11 = curSX.mPantsList.m_num;
  v1->m_tChoices[6].iNumColors = *(_DWORD *)(v3 + 280);
  v1->m_tChoices[6].dShade = *(double *)(v3 + 352);
  v1->m_tChoices[7].iCurrentChoice = *(_DWORD *)(v3 + 260);
  v1->m_tChoices[7].iNumChoices = v11;
  v1->m_tChoices[7].iCurrentColor = *(_DWORD *)(v3 + 264);
  v1->m_tChoices[7].iNumColors = *(_DWORD *)(v3 + 284);
  v1->m_tChoices[7].dShade = *(double *)(v3 + 360);
  v1->m_tChoices[8].iCurrentChoice = *(_DWORD *)(v3 + 268);
  v1->m_tChoices[8].iNumChoices = curSX.mFootwearList.m_num;
  v1->m_tChoices[8].iCurrentColor = *(_DWORD *)(v3 + 272);
  v1->m_tChoices[8].iNumColors = *(_DWORD *)(v3 + 288);
  v1->m_tChoices[8].dShade = *(double *)(v3 + 368);
  Sex_CG::~Sex_CG(&curSX);
  HeritageGroup_CG::~HeritageGroup_CG(&curHG);
}

//----- (004DEDF0) --------------------------------------------------------  // acclient.c:269646
void __thiscall gmBarberUI::SetSelection(gmBarberUI *this, gmBarberUI::EParts _ePart)
{
  gmBarberUI *v2; // ebx@1
  CPlayerSystem *v3; // ecx@1
  int v4; // eax@1
  int v5; // edi@1
  int v6; // esi@1
  signed int v7; // ebp@1
  UIElement *v8; // ecx@3
  signed int v9; // esi@3
  unsigned int v10; // ebp@6
  QualifiedDataID *v11; // eax@7
  int v12; // eax@8
  unsigned int v13; // ecx@8
  int v14; // edx@8
  unsigned int v15; // eax@8
  unsigned int v16; // eax@9
  signed int v17; // ebp@9
  int v18; // esi@10
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
  int v33; // eax@17
  int v34; // esi@18
  int v35; // ecx@19
  int v36; // ebp@19
  IDClass<_tagDataID,32,0> *v37; // eax@22
  unsigned int v38; // eax@22
  int v39; // edx@22
  int v40; // ecx@22
  int v41; // eax@22
  int v42; // esi@25
  int v43; // edi@25
  int iNumPalSets; // [sp+10h] [bp-1E8h]@1
  long double dCurShade; // [sp+14h] [bp-1E4h]@7
  int iPart; // [sp+1Ch] [bp-1DCh]@1
  int iCurColor; // [sp+20h] [bp-1D8h]@1
  int iSampleColor; // [sp+24h] [bp-1D4h]@1
  int i; // [sp+28h] [bp-1D0h]@17
  PalSet *v50; // [sp+2Ch] [bp-1CCh]@19
  int v51; // [sp+30h] [bp-1C8h]@21
  IDClass<_tagDataID,32,0> result; // [sp+34h] [bp-1C4h]@22
  PalSet *palSet[9]; // [sp+38h] [bp-1C0h]@7
  Sex_CG curSX; // [sp+5Ch] [bp-19Ch]@1
  HeritageGroup_CG curHG; // [sp+138h] [bp-C0h]@1

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
      v13 = *(_DWORD *)(v5 + 340);
      iSampleColor = 208;
      iPart = 0;
      v14 = v12 == -1 ? 0 : v12;
      v15 = *(_DWORD *)(v5 + 336);
      iCurColor = v14;
      dCurShade = COERCE_DOUBLE(__PAIR__(v13, v15));
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
        while ( v17 < (signed int)v16 );
      }
      v2->m_pCurSelection = (UIElement *)&v2->m_pEyesSpin->vfptr;
      v21 = *(_DWORD *)(v5 + 236);
      iNumPalSets = v16;
      iPart = 1;
      iCurColor = v21;
      dCurShade = 0.5;
      goto LABEL_25;
    case 3:
      iNumPalSets = 1;
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, curSX.skinPalSet, 0x18u);
      v23 = DBObj::Get(v22);
      v2->m_pCurSelection = (UIElement *)&v2->m_pNoseSpin->vfptr;
      v24 = *(_DWORD *)(v5 + 328);
      palSet[0] = (PalSet *)v23;
      v25 = *(_DWORD *)(v5 + 332);
      iPart = 2;
      dCurShade = COERCE_DOUBLE(__PAIR__(v25, v24));
      goto LABEL_16;
    case 4:
      iNumPalSets = 1;
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, curSX.skinPalSet, 0x18u);
      v27 = DBObj::Get(v26);
      v2->m_pCurSelection = (UIElement *)&v2->m_pMouthSpin->vfptr;
      v28 = *(_DWORD *)(v5 + 332);
      palSet[0] = (PalSet *)v27;
      v29 = *(_DWORD *)(v5 + 328);
      iPart = 3;
      dCurShade = COERCE_DOUBLE(__PAIR__(v28, v29));
      goto LABEL_16;
    case 5:
      iNumPalSets = 1;
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&dCurShade, curSX.skinPalSet, 0x18u);
      palSet[0] = (PalSet *)DBObj::Get(v30);
      v2->m_pCurSelection = (UIElement *)&v2->m_pSkinSpin->vfptr;
      v31 = *(_DWORD *)(v5 + 328);
      v32 = *(_DWORD *)(v5 + 332);
      iPart = 4;
      dCurShade = COERCE_DOUBLE(__PAIR__(v32, v31));
LABEL_16:
      iSampleColor = 176;
      iCurColor = 0;
      break;
    default:
      break;
  }
  v33 = 0;
  i = 0;
  if ( iNumPalSets > 0 )
  {
    v34 = (int)&v2->m_tColorWheel[0].iGreen;
    do
    {
      v36 = 0;
      v50 = palSet[v33];
      v35 = (int)v50;
      if ( v50 )
      {
        *(_DWORD *)(v34 + 4) = 0;
        *(_DWORD *)v34 = 0;
        *(_DWORD *)(v34 - 4) = 0;
        if ( *(_DWORD *)(v35 + 56) > 0 )
        {
          v51 = v35;
          do
          {
            v37 = PalSet::GetPaletteID_Integral((PalSet *)v35, &result, v36);
            v38 = ClientCharGenState::GetColorFromPal((IDClass<_tagDataID,32,0>)v37->id, iSampleColor);
            *(_DWORD *)(v34 - 4) += (unsigned __int8)(v38 >> 16);
            v39 = (unsigned __int8)v38 + *(_DWORD *)(v34 + 4);
            *(_DWORD *)v34 += BYTE1(v38);
            v40 = v51;
            *(_DWORD *)(v34 + 4) = v39;
            v41 = *(_DWORD *)(v40 + 56);
            v35 = (int)v50;
            ++v36;
          }
          while ( v36 < v41 );
        }
        *(_DWORD *)(v34 - 4) /= *(_DWORD *)(v35 + 56);
        *(_DWORD *)v34 /= *(_DWORD *)(v35 + 56);
        *(_DWORD *)(v34 + 4) /= *(_DWORD *)(v35 + 56);
        v33 = i;
      }
      ++v33;
      v34 += 28;
      i = v33;
    }
    while ( v33 < iNumPalSets );
  }
LABEL_25:
  v42 = iPart;
  v43 = iCurColor;
  v2->m_iCurColor = iCurColor;
  v2->m_iPartIndex = v42;
  v2->m_tChoices[v42].iNumColors = iNumPalSets;
  ((void (__stdcall *)(signed int))v2->m_pCurSelection->vfptr[13].__vecDelDtor)(6);
  gmBarberUI::DoColorSpots(v2, v42);
  if ( _ePart == 2 )
  {
    gmBarberUI::DoGradDisk(v2, 1);
    ((void (__stdcall *)(_DWORD))v2->m_pShadeScroll->vfptr[2].__vecDelDtor)(0);
  }
  else
  {
    gmBarberUI::DoGradDisk(v2, 0);
    ((void (__stdcall *)(signed int))v2->m_pShadeScroll->vfptr[2].__vecDelDtor)(1);
    gmBarberUI::SetShade(v2, dCurShade);
  }
  gmBarberUI::SetColor(v2, v43);
  Sex_CG::~Sex_CG(&curSX);
  HeritageGroup_CG::~HeritageGroup_CG(&curHG);
}

//----- (004DF260) --------------------------------------------------------  // acclient.c:269885
UIElementMessageListenResult __thiscall gmBarberUI::ListenToElementMessage(gmBarberUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebx@1
  unsigned int v3; // eax@1
  gmBarberUI *v4; // esi@1
  int v5; // edi@6
  int v6; // eax@7
  int v7; // edi@7
  int v8; // eax@11
  UIElementMessageListenResult result; // eax@11
  int v10; // eax@12
  int v11; // edi@12
  int v12; // eax@16
  int v13; // edi@17
  int v14; // eax@18
  int v15; // eax@22
  int v16; // eax@26
  int v17; // eax@30
  int v18; // eax@31
  int v19; // edi@31
  int v20; // eax@35
  int v21; // eax@36
  int v22; // edi@36
  int v23; // eax@40
  long double v24; // st7@70
  int v25; // ecx@78
  int v26; // eax@78
  int v27; // eax@82
  int v28; // ecx@84
  int v29; // eax@84
  int v30; // eax@88
  int v31; // ecx@90
  int v32; // eax@90
  int v33; // eax@94
  int v34; // ecx@96
  int v35; // eax@96
  int v36; // eax@100
  int v37; // ecx@102
  int v38; // eax@102
  CharGenState *v39; // eax@115
  CharGenState *v40; // edi@115
  int v41; // ebp@115
  unsigned int v42; // eax@117
  int v43; // eax@140
  CharGenState *v44; // edi@140
  ACCharGenData *v45; // ebx@140
  int v46; // ebp@140
  unsigned int v47; // edi@140
  unsigned int v48; // ST3C_4@140
  int v49; // eax@140
  TextureMapChange *v50; // eax@143
  unsigned int v51; // edx@144
  unsigned int v52; // eax@144
  CPhysicsObj *v53; // ecx@149
  unsigned int v54; // eax@151
  signed int v55; // eax@157
  unsigned int v56; // edx@158
  int v57; // eax@162
  bool v58; // zf@166
  int v59; // eax@182
  unsigned int v60; // ecx@184
  int v61; // eax@191
  unsigned int v62; // eax@193
  SmartBox *v63; // ebx@200
  IDClass<_tagDataID,32,0> newSetupID; // [sp+Ch] [bp-248h]@115
  long double cgData; // [sp+10h] [bp-244h]@71
  IDClass<_tagDataID,32,0> head_texture; // [sp+18h] [bp-23Ch]@140
  IDClass<_tagDataID,32,0> default_head_texture; // [sp+1Ch] [bp-238h]@140
  int option1; // [sp+20h] [bp-234h]@140
  CharAppearanceData cad; // [sp+24h] [bp-230h]@205
  ObjDesc temp; // [sp+50h] [bp-204h]@205
  HairStyle_CG curHS; // [sp+7Ch] [bp-1D8h]@143
  HeritageGroup_CG curHG; // [sp+B8h] [bp-19Ch]@140
  Sex_CG curSX; // [sp+178h] [bp-DCh]@140

  v2 = i_rMsg;
  v3 = i_rMsg->idElement;
  v4 = this;
  if ( i_rMsg->idElement > 0x10000321 )
  {
    switch ( v3 )
    {
      case 0x1000059Eu:
        if ( i_rMsg->idMessage == 1 )
        {
          v25 = this->m_tChoices[0].iCurrentChoice;
          v26 = v4->m_tChoices[0].iNumChoices;
          if ( v25 < v26 )
          {
            if ( v25 < 0 )
              v4->m_tChoices[0].iCurrentChoice = v26 - 1;
          }
          else
          {
            v4->m_tChoices[0].iCurrentChoice = 0;
          }
          CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
          *(_DWORD *)(v27 + 240) = v4->m_tChoices[0].iCurrentChoice;
          gmBarberUI::SetSelection(v4, ECG_PARTS_HAIR);
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x1000059Fu:
        if ( i_rMsg->idMessage == 1 )
        {
          v28 = this->m_tChoices[1].iCurrentChoice;
          v29 = v4->m_tChoices[1].iNumChoices;
          if ( v28 < v29 )
          {
            if ( v28 < 0 )
              v4->m_tChoices[1].iCurrentChoice = v29 - 1;
          }
          else
          {
            v4->m_tChoices[1].iCurrentChoice = 0;
          }
          CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
          *(_DWORD *)(v30 + 220) = v4->m_tChoices[1].iCurrentChoice;
          gmBarberUI::SetSelection(v4, ECG_PARTS_EYES);
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x100005A0u:
        if ( i_rMsg->idMessage == 1 )
        {
          v31 = this->m_tChoices[2].iCurrentChoice;
          v32 = v4->m_tChoices[2].iNumChoices;
          if ( v31 < v32 )
          {
            if ( v31 < 0 )
              v4->m_tChoices[2].iCurrentChoice = v32 - 1;
          }
          else
          {
            v4->m_tChoices[2].iCurrentChoice = 0;
          }
          CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
          *(_DWORD *)(v33 + 224) = v4->m_tChoices[2].iCurrentChoice;
          gmBarberUI::SetSelection(v4, ECG_PARTS_NOSE);
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x100005A1u:
        if ( i_rMsg->idMessage == 1 )
        {
          v34 = this->m_tChoices[3].iCurrentChoice;
          v35 = v4->m_tChoices[3].iNumChoices;
          if ( v34 < v35 )
          {
            if ( v34 < 0 )
              v4->m_tChoices[3].iCurrentChoice = v35 - 1;
          }
          else
          {
            v4->m_tChoices[3].iCurrentChoice = 0;
          }
          CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
          *(_DWORD *)(v36 + 228) = v4->m_tChoices[3].iCurrentChoice;
          gmBarberUI::SetSelection(v4, ECG_PARTS_MOUTH);
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x100005A2u:
        if ( i_rMsg->idMessage == 1 )
        {
          v37 = this->m_tChoices[4].iCurrentChoice;
          v38 = v4->m_tChoices[4].iNumChoices;
          if ( v37 < v38 )
          {
            if ( v37 < 0 )
              v4->m_tChoices[4].iCurrentChoice = v38 - 1;
          }
          else
          {
            v4->m_tChoices[4].iCurrentChoice = 0;
          }
          CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
          gmBarberUI::SetSelection(v4, ECG_PARTS_SKIN);
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x100005A4u:
        if ( i_rMsg->idMessage == 1 )
          gmBarberUI::Rotate(this, ECG_ROTATE_CLOCKWISE);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x100005A5u:
        if ( i_rMsg->idMessage == 1 )
        {
          if ( this->m_bRotating && this->m_eRotateDir == 2 )
          {
            this->m_bRotating = 0;
          }
          else
          {
            ((void (__stdcall *)(signed int))this->m_pRotateClockButton->vfptr[13].__vecDelDtor)(1);
            LODWORD(v4->m_dLastRotateTime) = 0;
            HIDWORD(v4->m_dLastRotateTime) = -1074790400;
            v4->m_eRotateDir = 2;
            v4->m_bRotating = 1;
          }
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x100005C9u:
        if ( i_rMsg->idMessage == 1 )
        {
          CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
          v40 = v39;
          v41 = CharGenState::GetCharGenResult(v39);
          CharGenState::GetSetupID(v40, &newSetupID);
          if ( *(_DWORD *)(v41 + 4) != 11 || v4->m_pOption1Checkbox->m_state != 6 )
          {
            v42 = newSetupID.id;
          }
          else
          {
            v42 = newSetupID.id;
            if ( *(_DWORD *)(v41 + 8) == 2 )
            {
              if ( newSetupID.id == UNDEAD_FEMALE_SKELETON_SETUP.id )
              {
                v42 = UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP.id;
                newSetupID.id = UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP.id;
              }
              if ( v42 == UNDEAD_FEMALE_ZOMBIE_SETUP.id )
              {
                v42 = UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP.id;
                newSetupID.id = UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP.id;
              }
            }
            else
            {
              if ( newSetupID.id == UNDEAD_MALE_SKELETON_SETUP.id )
              {
                v42 = UNDEAD_MALE_SKELETON_NOFLAME_SETUP.id;
                newSetupID.id = UNDEAD_MALE_SKELETON_NOFLAME_SETUP.id;
              }
              if ( v42 == UNDEAD_MALE_ZOMBIE_SETUP.id )
              {
                v42 = UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP.id;
                newSetupID.id = UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP.id;
              }
            }
          }
          if ( *(_DWORD *)(v41 + 4) == 5 && v4->m_pOption1Checkbox->m_state == 6 )
          {
            v42 = UMBRAEN_FEMALE_NOCROWN_SETUP.id;
            if ( *(_DWORD *)(v41 + 8) != 2 )
              v42 = UMBRAEN_MALE_NOCROWN_SETUP.id;
            newSetupID.id = v42;
          }
          if ( *(_DWORD *)(v41 + 4) == 10 && v4->m_pOption1Checkbox->m_state == 6 )
          {
            v42 = PENUMBRAEN_FEMALE_NOCROWN_SETUP.id;
            if ( *(_DWORD *)(v41 + 8) != 2 )
              v42 = PENUMBRAEN_MALE_NOCROWN_SETUP.id;
            newSetupID.id = v42;
          }
          if ( v42 != script_id.id )
          {
            v4->m_p3DView->m_alternateSetupID.id = v42;
            gmCG3DView::Update(v4->m_p3DView);
          }
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x100005A6u:
        if ( i_rMsg->idMessage != 1 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
        v44 = (CharGenState *)v43;
        LODWORD(cgData) = *(_DWORD *)(v43 + 596);
        v45 = (ACCharGenData *)LODWORD(cgData);
        v46 = CharGenState::GetCharGenResult((CharGenState *)v43);
        option1 = 0;
        CharGenState::GetSetupID(v44, &newSetupID);
        v47 = script_id.id;
        v48 = *(_DWORD *)(v46 + 4);
        head_texture.id = script_id.id;
        default_head_texture.id = script_id.id;
        ACCharGenData::GetHG(v45, &curHG, v48);
        HeritageGroup_CG::GetSX(&curHG, &curSX, *(_DWORD *)(v46 + 8));
        v49 = *(_DWORD *)(v46 + 4);
        if ( v49 != 6 && v49 != 12 && v49 != 13 )
        {
          HairStyle_CG::HairStyle_CG(&curHS, &curSX.mHairStyleList.m_data[*(_DWORD *)(v46 + 32)]);
          v50 = ObjDesc::GetTextureMapChange(&curHS.objDesc, 0);
          if ( v50 )
          {
            v51 = v50->new_tex_id.id;
            v52 = v50->old_tex_id.id;
            head_texture.id = v51;
            default_head_texture.id = v52;
          }
          curHS.vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
          ObjDesc::~ObjDesc(&curHS.objDesc);
        }
        if ( *(_DWORD *)(v46 + 4) != 9 )
          goto LABEL_157;
        if ( v4->m_pOption1Checkbox->m_state == 6 )
        {
          option1 = 1;
          if ( !SmartBox::smartbox )
            goto LABEL_157;
          v53 = SmartBox::smartbox->player;
          if ( *(_DWORD *)(v46 + 8) == 2 )
          {
            CPhysicsObj::SetMotionTableID(v53, EmpyreanFemaleMotionDID);
            goto LABEL_157;
          }
          v54 = EmpyreanMaleMotionDID.id;
        }
        else
        {
          if ( !SmartBox::smartbox )
            goto LABEL_157;
          v53 = SmartBox::smartbox->player;
          if ( *(_DWORD *)(v46 + 8) == 2 )
          {
            CPhysicsObj::SetMotionTableID(v53, EmpyreanFemaleFloatMotionDID);
            goto LABEL_157;
          }
          v54 = EmpyreanMaleFloatMotionDID.id;
        }
        CPhysicsObj::SetMotionTableID(v53, (IDClass<_tagDataID,32,0>)v54);
LABEL_157:
        v55 = 0;
        if ( *(_DWORD *)(v46 + 4) != 11 )
          goto LABEL_181;
        v56 = UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP.id;
        v57 = newSetupID.id == UNDEAD_FEMALE_ZOMBIE_SETUP.id
           || newSetupID.id == UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP.id
           || newSetupID.id == UNDEAD_MALE_ZOMBIE_SETUP.id
           || newSetupID.id == UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP.id;
        if ( v4->m_pOption1Checkbox->m_state == 6 )
        {
          if ( *(_DWORD *)(v46 + 8) == 2 )
          {
            v58 = v57 == 0;
            v55 = 1;
            if ( v58 )
            {
              v47 = UNDEAD_FEMALE_SKELETON_NOFLAME_PES.id;
              newSetupID.id = UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP.id;
              goto LABEL_181;
            }
            v47 = UNDEAD_FEMALE_ZOMBIE_NOFLAME_PES.id;
            goto LABEL_180;
          }
          if ( !v57 )
          {
            v47 = UNDEAD_MALE_SKELETON_NOFLAME_PES.id;
            newSetupID.id = UNDEAD_MALE_SKELETON_NOFLAME_SETUP.id;
            v55 = 1;
            goto LABEL_181;
          }
          v56 = UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP.id;
          v47 = UNDEAD_MALE_ZOMBIE_NOFLAME_PES.id;
        }
        else
        {
          if ( *(_DWORD *)(v46 + 8) == 2 )
          {
            v58 = v57 == 0;
            v55 = 1;
            if ( v58 )
            {
              v47 = UNDEAD_FEMALE_SKELETON_PES.id;
              newSetupID.id = UNDEAD_FEMALE_SKELETON_SETUP.id;
            }
            else
            {
              v47 = UNDEAD_FEMALE_ZOMBIE_PES.id;
              newSetupID.id = UNDEAD_FEMALE_ZOMBIE_SETUP.id;
            }
LABEL_181:
            if ( *(_DWORD *)(v46 + 4) != 5 )
              goto LABEL_190;
            v59 = *(_DWORD *)(v46 + 8);
            if ( v4->m_pOption1Checkbox->m_state == 6 )
            {
              v58 = v59 == 2;
              v55 = 1;
              if ( !v58 )
              {
                v47 = UMBRAEN_MALE_NOCROWN_PES.id;
                newSetupID.id = UMBRAEN_MALE_NOCROWN_SETUP.id;
                goto LABEL_190;
              }
              v60 = UMBRAEN_FEMALE_NOCROWN_SETUP.id;
              v47 = UMBRAEN_FEMALE_NOCROWN_PES.id;
            }
            else
            {
              if ( v59 == 2 )
              {
                v47 = UMBRAEN_FEMALE_CROWN_PES.id;
                newSetupID.id = UMBRAEN_FEMALE_CROWN_SETUP.id;
                v55 = 1;
                goto LABEL_190;
              }
              v60 = UMBRAEN_MALE_CROWN_SETUP.id;
              v47 = UMBRAEN_MALE_CROWN_PES.id;
              v55 = 1;
            }
            newSetupID.id = v60;
LABEL_190:
            if ( *(_DWORD *)(v46 + 4) != 10 )
            {
LABEL_200:
              v63 = SmartBox::smartbox;
              if ( SmartBox::smartbox )
              {
                if ( v55 )
                  CPhysicsObj::destroy_particle_manager(SmartBox::smartbox->player);
                if ( v47 != script_id.id )
                  CPhysicsObj::play_script(v63->player, (IDClass<_tagDataID,32,0>)v47);
              }
              ObjDesc::ObjDesc(&temp);
              CharAppearanceData::CharAppearanceData(&cad);
              if ( ACCharGenData::GenerateBaseAppearanceData(LODWORD(cgData), (ACCharGenResult *)v46, &cad, &temp) )
                CM_Character::Event_FinishBarber(
                  cad.base_palette,
                  cad.head_object,
                  head_texture,
                  default_head_texture,
                  cad.eyes_texture,
                  cad.default_eyes_texture,
                  cad.nose_texture,
                  cad.default_nose_texture,
                  cad.mouth_texture,
                  cad.default_mouth_texture,
                  cad.skin_palette,
                  cad.hair_palette,
                  cad.eyes_palette,
                  newSetupID,
                  option1,
                  0);
              v4->vfptr[2].__vecDelDtor((IInputActionCallback *)v4, 0);
              ObjDesc::~ObjDesc(&temp);
              Sex_CG::~Sex_CG(&curSX);
              HeritageGroup_CG::~HeritageGroup_CG(&curHG);
              v2 = i_rMsg;
              return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
            }
            v61 = *(_DWORD *)(v46 + 8);
            if ( v4->m_pOption1Checkbox->m_state == 6 )
            {
              if ( v61 == 2 )
              {
                v62 = PENUMBRAEN_FEMALE_NOCROWN_SETUP.id;
                v47 = PENUMBRAEN_FEMALE_NOCROWN_PES.id;
LABEL_198:
                newSetupID.id = v62;
                goto LABEL_199;
              }
              v47 = PENUMBRAEN_MALE_NOCROWN_PES.id;
              newSetupID.id = PENUMBRAEN_MALE_NOCROWN_SETUP.id;
            }
            else
            {
              if ( v61 != 2 )
              {
                v62 = PENUMBRAEN_MALE_CROWN_SETUP.id;
                v47 = PENUMBRAEN_MALE_CROWN_PES.id;
                goto LABEL_198;
              }
              v47 = PENUMBRAEN_FEMALE_CROWN_PES.id;
              newSetupID.id = PENUMBRAEN_FEMALE_CROWN_SETUP.id;
            }
LABEL_199:
            v55 = 1;
            goto LABEL_200;
          }
          if ( v57 )
          {
            newSetupID.id = UNDEAD_MALE_ZOMBIE_SETUP.id;
            v47 = UNDEAD_MALE_ZOMBIE_PES.id;
            v55 = 1;
            goto LABEL_181;
          }
          v56 = UNDEAD_MALE_SKELETON_SETUP.id;
          v47 = UNDEAD_MALE_SKELETON_PES.id;
        }
        v55 = 1;
LABEL_180:
        newSetupID.id = v56;
        goto LABEL_181;
      case 0x100005A7u:
        if ( i_rMsg->idMessage == 1 )
          ((void (__stdcall *)(_DWORD))this->vfptr[2].__vecDelDtor)(0);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      default:
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
    }
  }
  if ( i_rMsg->idElement != 268436257 )
  {
    switch ( v3 )
    {
      case 0x1000030Au:
        if ( i_rMsg->idMessage == 1 )
        {
          switch ( *(_DWORD *)(((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)() + 740) )
          {
            case 0x1000059E:
              v5 = v4->m_tChoices[0].iCurrentChoice - 1;
              goto LABEL_26;
            case 0x1000059F:
              v6 = v4->m_tChoices[1].iNumChoices;
              v7 = v4->m_tChoices[1].iCurrentChoice - 1;
              v4->m_tChoices[1].iCurrentChoice = v7;
              if ( v7 < v6 )
              {
                if ( v7 < 0 )
                  v4->m_tChoices[1].iCurrentChoice = v6 - 1;
              }
              else
              {
                v4->m_tChoices[1].iCurrentChoice = 0;
              }
              CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
              *(_DWORD *)(v8 + 220) = v4->m_tChoices[1].iCurrentChoice;
              gmBarberUI::SetSelection(v4, ECG_PARTS_EYES);
              return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
            case 0x100005A0:
              v10 = v4->m_tChoices[2].iNumChoices;
              v11 = v4->m_tChoices[2].iCurrentChoice - 1;
              v4->m_tChoices[2].iCurrentChoice = v11;
              if ( v11 < v10 )
              {
                if ( v11 < 0 )
                  v4->m_tChoices[2].iCurrentChoice = v10 - 1;
              }
              else
              {
                v4->m_tChoices[2].iCurrentChoice = 0;
              }
              CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
              *(_DWORD *)(v12 + 224) = v4->m_tChoices[2].iCurrentChoice;
              gmBarberUI::SetSelection(v4, ECG_PARTS_NOSE);
              return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
            case 0x100005A1:
              v13 = v4->m_tChoices[3].iCurrentChoice - 1;
              goto LABEL_18;
            default:
              return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
          }
        }
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
      case 0x1000030Bu:
        if ( i_rMsg->idMessage != 1 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        switch ( *(_DWORD *)(((int (*)(void))i_rMsg->pElement->vfptr[13].OnAction)() + 740) )
        {
          case 0x1000059E:
            v5 = v4->m_tChoices[0].iCurrentChoice + 1;
LABEL_26:
            v4->m_tChoices[0].iCurrentChoice = v5;
            v16 = v4->m_tChoices[0].iNumChoices;
            if ( v5 < v16 )
            {
              if ( v5 < 0 )
                v4->m_tChoices[0].iCurrentChoice = v16 - 1;
            }
            else
            {
              v4->m_tChoices[0].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
            *(_DWORD *)(v17 + 240) = v4->m_tChoices[0].iCurrentChoice;
            gmBarberUI::SetSelection(v4, ECG_PARTS_HAIR);
            result = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
            break;
          case 0x1000059F:
            v18 = v4->m_tChoices[1].iNumChoices;
            v19 = v4->m_tChoices[1].iCurrentChoice + 1;
            v4->m_tChoices[1].iCurrentChoice = v19;
            if ( v19 < v18 )
            {
              if ( v19 < 0 )
                v4->m_tChoices[1].iCurrentChoice = v18 - 1;
            }
            else
            {
              v4->m_tChoices[1].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
            *(_DWORD *)(v20 + 220) = v4->m_tChoices[1].iCurrentChoice;
            gmBarberUI::SetSelection(v4, ECG_PARTS_EYES);
            result = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
            break;
          case 0x100005A0:
            v21 = v4->m_tChoices[2].iNumChoices;
            v22 = v4->m_tChoices[2].iCurrentChoice + 1;
            v4->m_tChoices[2].iCurrentChoice = v22;
            if ( v22 < v21 )
            {
              if ( v22 < 0 )
                v4->m_tChoices[2].iCurrentChoice = v21 - 1;
            }
            else
            {
              v4->m_tChoices[2].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
            *(_DWORD *)(v23 + 224) = v4->m_tChoices[2].iCurrentChoice;
            gmBarberUI::SetSelection(v4, ECG_PARTS_NOSE);
            result = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
            break;
          case 0x100005A1:
            v13 = v4->m_tChoices[3].iCurrentChoice + 1;
LABEL_18:
            v4->m_tChoices[3].iCurrentChoice = v13;
            v14 = v4->m_tChoices[3].iNumChoices;
            if ( v13 < v14 )
            {
              if ( v13 < 0 )
                v4->m_tChoices[3].iCurrentChoice = v14 - 1;
            }
            else
            {
              v4->m_tChoices[3].iCurrentChoice = 0;
            }
            CPlayerSystem::GetCharGenState(v4->m_pPlayerSystem);
            *(_DWORD *)(v15 + 228) = v4->m_tChoices[3].iCurrentChoice;
            gmBarberUI::SetSelection(v4, ECG_PARTS_MOUTH);
            result = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
            break;
          default:
            return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        }
        return result;
      case 0x1000030Fu:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 0 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 0);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000310u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 1 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 1);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000311u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 2 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 2);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000312u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 3 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 3);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000313u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 4 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 4);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000314u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 5 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 5);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000315u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 6 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 6);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000316u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 7 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 7);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      case 0x10000317u:
        if ( i_rMsg->idMessage != 1 || this->m_tChoices[this->m_iPartIndex].iNumColors <= 8 )
          return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
        gmBarberUI::SetColor(this, 8);
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
      default:
        return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
    }
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  }
  if ( i_rMsg->idMessage != 10 )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  v24 = (double)i_rMsg->dwParam1 * 0.001;
  if ( v24 <= 1.0 )
  {
    if ( v24 >= 0.0 )
      cgData = v24;
    else
      cgData = 0.0;
  }
  else
  {
    cgData = 1.0;
  }
  gmBarberUI::SetShade(this, cgData);
  return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (004E0040) --------------------------------------------------------  // acclient.c:270581
void __userpurge gmBarberUI::InitializePage(gmBarberUI *this@<ecx>, long double a2@<st0>, IDClass<_tagDataID,32,0> i_base_palette, IDClass<_tagDataID,32,0> i_head_object, IDClass<_tagDataID,32,0> i_head_texture, IDClass<_tagDataID,32,0> i_default_head_texture, IDClass<_tagDataID,32,0> i_eyes_texture, IDClass<_tagDataID,32,0> i_default_eyes_texture, IDClass<_tagDataID,32,0> i_nose_texture, IDClass<_tagDataID,32,0> i_default_nose_texture, IDClass<_tagDataID,32,0> i_mouth_texture, IDClass<_tagDataID,32,0> i_default_mouth_texture, IDClass<_tagDataID,32,0> i_skin_palette, IDClass<_tagDataID,32,0> i_hair_palette, IDClass<_tagDataID,32,0> i_eyes_palette, IDClass<_tagDataID,32,0> i_setup_id, int i_option1, int i_option2)
{
  gmBarberUI *v18; // esi@1
  CPlayerSystem *v19; // eax@1
  int v20; // eax@1
  CharGenState *v21; // edi@1
  ACCharGenData *v22; // eax@1
  int v23; // ebp@1
  InterfaceSystem *v24; // eax@1
  int v25; // ebx@1
  CBaseQualities *v26; // ebx@5
  UIElement *v27; // eax@5
  int v28; // eax@6
  UIElement *v29; // eax@8
  int v30; // eax@9
  UIElement *v31; // eax@11
  int v32; // eax@12
  UIElement *v33; // eax@14
  int v34; // eax@15
  UIElement *v35; // eax@17
  UIElement *v36; // eax@18
  UIElement *v37; // eax@21
  UIElement *v38; // eax@23
  UIElement *v39; // eax@25
  signed int v40; // edi@25
  signed int v41; // ebx@25
  int v42; // ebp@37
  bool v43; // sf@37
  unsigned __int8 v44; // of@37
  UIElement *v45; // eax@38
  int v46; // eax@39
  UIElement *v47; // eax@41
  int v48; // eax@42
  gmCG3DView *v49; // eax@44
  gmCG3DView *v50; // eax@45
  UIElement_Viewport *v51; // ST10_4@47
  gmCG3DView *v52; // ecx@47
  gmCG3DView *v53; // ecx@47
  gmCG3DView *v54; // edx@47
  unsigned int v55; // eax@47
  gmCG3DView *v56; // ecx@48
  unsigned int v57; // eax@48
  unsigned int v58; // eax@48
  UIElement *v59; // ecx@48
  UIElement *v60; // eax@49
  UIElement *v61; // eax@51
  unsigned int v62; // eax@53
  StringInfo *v63; // ecx@53
  gmCG3DView *v64; // ecx@56
  unsigned int v65; // eax@56
  unsigned int v66; // eax@56
  UIElement *v67; // ecx@56
  UIElement *v68; // eax@57
  UIElement *v69; // eax@59
  unsigned int v70; // eax@61
  signed int v71; // ebx@63
  ACCharGenData *v72; // edi@68
  unsigned int v73; // eax@68
  int v74; // ecx@68
  int v75; // eax@72
  bool v76; // bl@72
  unsigned int v77; // eax@72
  int v78; // ecx@72
  int v79; // eax@76
  unsigned int v80; // eax@76
  int v81; // ecx@76
  int v82; // eax@80
  unsigned int v83; // eax@80
  int v84; // ecx@80
  int v85; // eax@84
  CharGenState *v86; // ebx@84
  UIElement *v87; // eax@86
  int v88; // eax@87
  UIElement *v89; // eax@89
  int v90; // eax@90
  UIElement *v91; // eax@92
  int v92; // eax@93
  UIElement *v93; // eax@95
  int v94; // eax@96
  UIElement *v95; // eax@98
  int v96; // eax@99
  UIElement *v97; // eax@101
  int v98; // eax@102
  UIElement *v99; // eax@104
  int v100; // eax@105
  unsigned int v101; // eax@107
  unsigned int v102; // eax@110
  UIElement_Button *v103; // ecx@110
  unsigned int v104; // eax@115
  unsigned int v105; // eax@118
  unsigned int v106; // eax@125
  unsigned int v107; // eax@130
  int v108; // [sp-8h] [bp-214h]@1
  int i; // [sp+10h] [bp-1FCh]@1
  unsigned int heritage; // [sp+14h] [bp-1F8h]@5
  unsigned int gender; // [sp+18h] [bp-1F4h]@5
  unsigned int color; // [sp+1Ch] [bp-1F0h]@84
  AC1Legacy::Vector3 _vectPosition; // [sp+20h] [bp-1ECh]@47
  long double shade; // [sp+2Ch] [bp-1E0h]@84
  AC1Legacy::Vector3 _vectDirection; // [sp+34h] [bp-1D8h]@47
  CharGenState *cg; // [sp+40h] [bp-1CCh]@1
  unsigned int idSpot; // [sp+44h] [bp-1C8h]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+48h] [bp-1C4h]@1
  IDClass<_tagDataID,32,0> base_palette; // [sp+50h] [bp-1BCh]@5
  ACCharGenData *cgData; // [sp+54h] [bp-1B8h]@1
  TResult result; // [sp+58h] [bp-1B4h]@1
  StringInfo siOption1; // [sp+5Ch] [bp-1B0h]@48
  StringInfo siOlthoiSkin; // [sp+ECh] [bp-120h]@48
  StringInfo siOlthoiHair; // [sp+17Ch] [bp-90h]@48

  v18 = this;
  v19 = CPlayerSystem::GetPlayerSystem();
  v18->m_pPlayerSystem = v19;
  CPlayerSystem::GetCharGenState(v19);
  v21 = (CharGenState *)v20;
  v22 = *(ACCharGenData **)(v20 + 596);
  cg = v21;
  cgData = v22;
  CharGenState::RandomizeCharacter(v21, a2, 1);
  CharGenState::SetHeadgearStyle(v21, -1);
  v23 = 0;
  i = 0;
  v24 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v24, &result, &PlayerDesc_ClassType_19, (Interface **)&i);
  v108 = i;
  v25 = i;
  playerDesc.m_pInterface = 0;
  playerDesc.m_trStatus.m_val = 0;
  if ( i )
    (*(void (__thiscall **)(int))(*(_DWORD *)i + 16))(i);
  InterfacePtr<PlayerDesc>::_QueryInterface(&playerDesc, (int)&idSpot, v108, 0);
  if ( v25 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v25 + 20))(v25);
  v26 = (CBaseQualities *)&playerDesc.m_pInterface->vfptr;
  gender = 0;
  CBaseQualities::InqInt((CBaseQualities *)&playerDesc.m_pInterface->vfptr, 0x71u, (int *)&gender, 0, 0);
  CharGenState::SetGender(v21, gender);
  heritage = 0;
  CBaseQualities::InqInt(v26, 0xBCu, (int *)&heritage, 0, 0);
  CharGenState::SetHeritageGroup(v21, heritage);
  base_palette.id = script_id.id;
  CBaseQualities::InqDataID(v26, 6u, &base_palette);
  v27 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x1000059Eu);
  if ( v27 )
    v28 = v27->vfptr[12].OnAction((IInputActionCallback *)v27, (InputEvent *)1);
  else
    v28 = 0;
  v18->m_pHairSpin = (UIElement_Button *)v28;
  v18->m_pCurSelection = (UIElement *)v28;
  v29 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x1000059Fu);
  if ( v29 )
    v30 = v29->vfptr[12].OnAction((IInputActionCallback *)v29, (InputEvent *)1);
  else
    v30 = 0;
  v18->m_pEyesSpin = (UIElement_Button *)v30;
  v31 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005A0u);
  if ( v31 )
    v32 = v31->vfptr[12].OnAction((IInputActionCallback *)v31, (InputEvent *)1);
  else
    v32 = 0;
  v18->m_pNoseSpin = (UIElement_Button *)v32;
  v33 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005A1u);
  if ( v33 )
    v34 = v33->vfptr[12].OnAction((IInputActionCallback *)v33, (InputEvent *)1);
  else
    v34 = 0;
  v18->m_pMouthSpin = (UIElement_Button *)v34;
  v35 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005A2u);
  if ( v35 )
    v36 = (UIElement *)v35->vfptr[12].OnAction((IInputActionCallback *)v35, (InputEvent *)1);
  else
    v36 = 0;
  v18->m_pSkinSpin = (UIElement_Button *)v36;
  if ( v36 )
  {
    v37 = UIElement::GetChildRecursive(v36, 0x1000030Au);
    if ( v37 )
      UIElement::SetAttribute_Bool(v37, 0xDu, 1);
    v38 = UIElement::GetChildRecursive((UIElement *)&v18->m_pSkinSpin->vfptr, 0x1000030Bu);
    if ( v38 )
      UIElement::SetAttribute_Bool(v38, 0xDu, 1);
  }
  v39 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x1000059Du);
  v40 = idSpot;
  v41 = idSpot;
  v18->m_pFaceChoices = v39;
  for ( i = 0; ; v23 = i )
  {
    switch ( v23 )
    {
      case 0:
        v40 = 268436239;
        v41 = 268436248;
        break;
      case 1:
        v40 = 268436240;
        v41 = 268436249;
        break;
      case 2:
        v40 = 268436241;
        v41 = 268436250;
        break;
      case 3:
        v40 = 268436242;
        v41 = 268436251;
        break;
      case 4:
        v40 = 268436243;
        v41 = 268436252;
        break;
      case 5:
        v40 = 268436244;
        v41 = 268436253;
        break;
      case 6:
        v40 = 268436245;
        v41 = 268436254;
        break;
      case 7:
        v40 = 268436246;
        v41 = 268436255;
        break;
      case 8:
        v40 = 268436247;
        v41 = 268436256;
        break;
      default:
        break;
    }
    v42 = (int)((char *)v18 + 28 * i);
    *(_DWORD *)(v42 + 1912) = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, v40);
    *(_DWORD *)(v42 + 1916) = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, v41);
    v44 = __OFSUB__(i + 1, 9);
    v43 = i++ - 8 < 0;
    if ( !(v43 ^ v44) )
      break;
  }
  v18->m_pGradCircle = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x1000030Eu);
  v45 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x10000321u);
  if ( v45 )
    v46 = v45->vfptr[12].OnAction((IInputActionCallback *)v45, (InputEvent *)11);
  else
    v46 = 0;
  v18->m_pShadeScroll = (UIElement_Scrollbar *)v46;
  v47 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x1000059Bu);
  if ( v47 )
    v48 = v47->vfptr[12].OnAction((IInputActionCallback *)v47, (InputEvent *)13);
  else
    v48 = 0;
  v18->m_pViewport = (UIElement_Viewport *)v48;
  v49 = (gmCG3DView *)operator new(0x60u);
  if ( v49 )
    gmCG3DView::gmCG3DView(v49);
  else
    v50 = 0;
  v51 = v18->m_pViewport;
  v18->m_p3DView = v50;
  gmCG3DView::Initialize(v50, v51);
  v52 = v18->m_p3DView;
  LODWORD(v18->m_fCurHeading) = 1127481344;
  gmCG3DView::SetPlayerHeading(v52, 180.0);
  v53 = v18->m_p3DView;
  LODWORD(_vectDirection.x) = 0;
  LODWORD(_vectDirection.y) = 0;
  LODWORD(_vectDirection.z) = 0;
  LODWORD(_vectPosition.x) = 0;
  LODWORD(_vectPosition.y) = -1088002458;
  LODWORD(_vectPosition.z) = 1071225242;
  gmCG3DView::SetCamera(v53, &_vectPosition, &_vectDirection);
  v54 = v18->m_p3DView;
  LODWORD(_vectPosition.x) = 1050253722;
  LODWORD(_vectPosition.y) = 1072902963;
  LODWORD(_vectPosition.z) = 1059481190;
  UIElement_Viewport::SetLight(v54->m_pViewport, DISTANT_LIGHT, 2.0, (Vector3 *)&_vectPosition.x);
  CreatureMode::UseSharpMode((CreatureMode *)&v18->m_p3DView->m_pViewport->creature_mode_objects);
  v55 = cg->mHeritageGroup;
  if ( v55 == 6 )
  {
    v56 = v18->m_p3DView;
    LODWORD(_vectPosition.x) = 0;
    LODWORD(_vectPosition.y) = 0;
    LODWORD(_vectPosition.z) = 0;
    LODWORD(_vectDirection.x) = 0;
    LODWORD(_vectDirection.y) = -1085485875;
    LODWORD(_vectDirection.z) = 1069547520;
    gmCG3DView::SetCamera(v56, &_vectDirection, &_vectPosition);
    ((void (__stdcall *)(_DWORD))v18->m_pNoseSpin->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v18->m_pMouthSpin->vfptr[2].__vecDelDtor)(0);
    StringInfo::StringInfo(&siOption1);
    StringInfo::StringInfo(&siOlthoiSkin);
    StringInfo::StringInfo(&siOlthoiHair);
    v57 = compute_str_hash("ID_CharGen_GearText_HairButton");
    StringInfo::SetStringIDandTableEnum(&siOption1, v57, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pHairSpin->vfptr, &siOption1, 0, 1);
    v58 = compute_str_hash("ID_CharGen_GearText_EyesButton");
    StringInfo::SetStringIDandTableEnum(&siOlthoiHair, v58, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pEyesSpin->vfptr, &siOlthoiHair, 0, 1);
    v59 = (UIElement *)&v18->m_pEyesSpin->vfptr;
    if ( v59 )
    {
      v60 = UIElement::GetChildRecursive(v59, 0x1000030Au);
      if ( v60 )
        UIElement::SetAttribute_Bool(v60, 0xDu, 1);
      v61 = UIElement::GetChildRecursive((UIElement *)&v18->m_pEyesSpin->vfptr, 0x1000030Bu);
      if ( v61 )
        UIElement::SetAttribute_Bool(v61, 0xDu, 1);
    }
    ((void (__stdcall *)(_DWORD, signed int))v18->m_pSkinSpin->vfptr[3].OnLoseFocus)(0, 88);
    v62 = compute_str_hash("ID_CharGen_GearText_SkinButton");
    StringInfo::SetStringIDandTableEnum(&siOlthoiSkin, v62, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pSkinSpin->vfptr, &siOlthoiSkin, 0, 1);
    StringInfo::~StringInfo(&siOlthoiHair);
    StringInfo::~StringInfo(&siOlthoiSkin);
    v63 = &siOption1;
LABEL_62:
    StringInfo::~StringInfo(v63);
    goto LABEL_63;
  }
  if ( v55 == 12 || v55 == 13 )
  {
    v64 = v18->m_p3DView;
    LODWORD(_vectPosition.x) = 0;
    LODWORD(_vectPosition.y) = 0;
    LODWORD(_vectPosition.z) = 0;
    LODWORD(_vectDirection.x) = 0;
    LODWORD(_vectDirection.y) = -1085485875;
    LODWORD(_vectDirection.z) = 1069547520;
    gmCG3DView::SetCamera(v64, &_vectDirection, &_vectPosition);
    ((void (__stdcall *)(_DWORD))v18->m_pNoseSpin->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v18->m_pMouthSpin->vfptr[2].__vecDelDtor)(0);
    StringInfo::StringInfo(&siOlthoiHair);
    StringInfo::StringInfo(&siOlthoiSkin);
    StringInfo::StringInfo(&siOption1);
    v65 = compute_str_hash("ID_CharGen_OlthoiText_HairButton");
    StringInfo::SetStringIDandTableEnum(&siOlthoiHair, v65, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pHairSpin->vfptr, &siOlthoiHair, 0, 1);
    v66 = compute_str_hash("ID_CharGen_OlthoiText_EyesButton");
    StringInfo::SetStringIDandTableEnum(&siOption1, v66, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pEyesSpin->vfptr, &siOption1, 0, 1);
    v67 = (UIElement *)&v18->m_pEyesSpin->vfptr;
    if ( v67 )
    {
      v68 = UIElement::GetChildRecursive(v67, 0x1000030Au);
      if ( v68 )
        UIElement::SetAttribute_Bool(v68, 0xDu, 1);
      v69 = UIElement::GetChildRecursive((UIElement *)&v18->m_pEyesSpin->vfptr, 0x1000030Bu);
      if ( v69 )
        UIElement::SetAttribute_Bool(v69, 0xDu, 1);
    }
    ((void (__stdcall *)(_DWORD, signed int))v18->m_pSkinSpin->vfptr[3].OnLoseFocus)(0, 88);
    v70 = compute_str_hash("ID_CharGen_OlthoiText_SkinButton");
    StringInfo::SetStringIDandTableEnum(&siOlthoiSkin, v70, 268435458);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pSkinSpin->vfptr, &siOlthoiSkin, 0, 1);
    StringInfo::~StringInfo(&siOption1);
    StringInfo::~StringInfo(&siOlthoiSkin);
    v63 = &siOlthoiHair;
    goto LABEL_62;
  }
LABEL_63:
  gmBarberUI::SetupParts(v18);
  v71 = 0;
  if ( i_setup_id.id == UNDEAD_MALE_SKELETON_SETUP.id
    || i_setup_id.id == UNDEAD_MALE_SKELETON_NOFLAME_SETUP.id
    || i_setup_id.id == UNDEAD_FEMALE_SKELETON_SETUP.id
    || i_setup_id.id == UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP.id )
    v71 = 1;
  v72 = cgData;
  LOBYTE(i) = i_head_texture.id == BALD_TEXTURE_57.id;
  v73 = ACCharGenData::GetHairIndexFromID(
          cgData,
          heritage,
          gender,
          i_head_object,
          i_head_texture.id == BALD_TEXTURE_57.id);
  v18->m_tChoices[0].iCurrentChoice = v73;
  v74 = v18->m_tChoices[0].iNumChoices;
  if ( (signed int)v73 < v74 )
  {
    if ( (v73 & 0x80000000) != 0 )
      v18->m_tChoices[0].iCurrentChoice = v74 - 1;
  }
  else
  {
    v18->m_tChoices[0].iCurrentChoice = 0;
  }
  CPlayerSystem::GetCharGenState(v18->m_pPlayerSystem);
  *(_DWORD *)(v75 + 240) = v18->m_tChoices[0].iCurrentChoice;
  gmBarberUI::SetSelection(v18, ECG_PARTS_HAIR);
  v76 = v71 != 0;
  v77 = ACCharGenData::GetEyeStripIndexFromID(v72, heritage, gender, i_eyes_texture, v76, i);
  v18->m_tChoices[1].iCurrentChoice = v77;
  v78 = v18->m_tChoices[1].iNumChoices;
  if ( (signed int)v77 < v78 )
  {
    if ( (v77 & 0x80000000) != 0 )
      v18->m_tChoices[1].iCurrentChoice = v78 - 1;
  }
  else
  {
    v18->m_tChoices[1].iCurrentChoice = 0;
  }
  CPlayerSystem::GetCharGenState(v18->m_pPlayerSystem);
  *(_DWORD *)(v79 + 220) = v18->m_tChoices[1].iCurrentChoice;
  gmBarberUI::SetSelection(v18, ECG_PARTS_EYES);
  v80 = ACCharGenData::GetNoseStripIndexFromID(v72, heritage, gender, i_nose_texture, v76);
  v18->m_tChoices[2].iCurrentChoice = v80;
  v81 = v18->m_tChoices[2].iNumChoices;
  if ( (signed int)v80 < v81 )
  {
    if ( (v80 & 0x80000000) != 0 )
      v18->m_tChoices[2].iCurrentChoice = v81 - 1;
  }
  else
  {
    v18->m_tChoices[2].iCurrentChoice = 0;
  }
  CPlayerSystem::GetCharGenState(v18->m_pPlayerSystem);
  *(_DWORD *)(v82 + 224) = v18->m_tChoices[2].iCurrentChoice;
  gmBarberUI::SetSelection(v18, ECG_PARTS_NOSE);
  v83 = ACCharGenData::GetMouthStripIndexFromID(v72, heritage, gender, i_mouth_texture, v76);
  v18->m_tChoices[3].iCurrentChoice = v83;
  v84 = v18->m_tChoices[3].iNumChoices;
  if ( (signed int)v83 < v84 )
  {
    if ( (v83 & 0x80000000) != 0 )
      v18->m_tChoices[3].iCurrentChoice = v84 - 1;
  }
  else
  {
    v18->m_tChoices[3].iCurrentChoice = 0;
  }
  CPlayerSystem::GetCharGenState(v18->m_pPlayerSystem);
  *(_DWORD *)(v85 + 228) = v18->m_tChoices[3].iCurrentChoice;
  gmBarberUI::SetSelection(v18, ECG_PARTS_MOUTH);
  color = 0;
  shade = 0.0;
  gmBarberUI::SetSelection(v18, ECG_PARTS_HAIR);
  ACCharGenData::GetHairColorFromID(v72, heritage, gender, i_hair_palette, &color, &shade);
  v86 = cg;
  CharGenState::SetHairColor(cg, color);
  CharGenState::SetHairShade(v86, shade);
  gmBarberUI::SetColor(v18, color);
  gmBarberUI::SetShade(v18, shade);
  ACCharGenData::GetSkinShadeFromID(v72, heritage, gender, i_skin_palette, &shade);
  CharGenState::SetSkinShade(v86, shade);
  ACCharGenData::GetEyeColorFromID(v72, heritage, gender, i_eyes_palette, &color);
  CharGenState::SetEyeColor(v86, color);
  if ( UIElement::IsVisible((UIElement *)&v18->vfptr) )
    gmCG3DView::Update(v18->m_p3DView);
  v87 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005A4u);
  if ( v87 )
    v88 = v87->vfptr[12].OnAction((IInputActionCallback *)v87, (InputEvent *)1);
  else
    v88 = 0;
  v18->m_pRotateClockButton = (UIElement_Button *)v88;
  v89 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005A5u);
  if ( v89 )
    v90 = v89->vfptr[12].OnAction((IInputActionCallback *)v89, (InputEvent *)1);
  else
    v90 = 0;
  v18->m_pRotateCounterClockButton = (UIElement_Button *)v90;
  v91 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005A6u);
  if ( v91 )
    v92 = v91->vfptr[12].OnAction((IInputActionCallback *)v91, (InputEvent *)1);
  else
    v92 = 0;
  v18->m_pApplyButton = (UIElement_Button *)v92;
  v93 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005A7u);
  if ( v93 )
    v94 = v93->vfptr[12].OnAction((IInputActionCallback *)v93, (InputEvent *)1);
  else
    v94 = 0;
  v18->m_pCancelButton = (UIElement_Button *)v94;
  v95 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005C9u);
  if ( v95 )
    v96 = v95->vfptr[12].OnAction((IInputActionCallback *)v95, (InputEvent *)1);
  else
    v96 = 0;
  v18->m_pOption1Checkbox = (UIElement_Button *)v96;
  v97 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005CAu);
  if ( v97 )
    v98 = v97->vfptr[12].OnAction((IInputActionCallback *)v97, (InputEvent *)1);
  else
    v98 = 0;
  v18->m_pOption2Checkbox = (UIElement_Button *)v98;
  v99 = UIElement::GetChildRecursive((UIElement *)&v18->vfptr, 0x100005CBu);
  if ( v99 )
    v100 = v99->vfptr[12].OnAction((IInputActionCallback *)v99, (InputEvent *)1);
  else
    v100 = 0;
  v18->m_pOption3Checkbox = (UIElement_Button *)v100;
  v101 = v86->mHeritageGroup;
  if ( v101 == 6 )
  {
    ((void (__stdcall *)(_DWORD))v18->m_pOption1Checkbox->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v18->m_pOption2Checkbox->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v18->m_pOption3Checkbox->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(signed int, signed int))v18->m_pApplyButton->vfptr[3].OnLoseFocus)(352, 274);
    ((void (__thiscall *)(UIElement_Button *, signed int, signed int))v18->m_pCancelButton->vfptr[3].OnLoseFocus)(
      v18->m_pCancelButton,
      232,
      274);
    goto LABEL_135;
  }
  if ( v101 == 9 )
  {
    StringInfo::StringInfo(&siOption1);
    ((void (__stdcall *)(signed int))v18->m_pOption1Checkbox->vfptr[2].__vecDelDtor)(1);
    v102 = compute_str_hash("ID_Barber_Empyrean_Earthbound");
    StringInfo::SetStringIDandTableEnum(&siOption1, v102, 268435457);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pOption1Checkbox->vfptr, &siOption1, 0, 1);
    v103 = v18->m_pOption1Checkbox;
    if ( i_option1 )
    {
      ((void (__stdcall *)(signed int))v103->vfptr[13].__vecDelDtor)(6);
LABEL_121:
      ((void (__stdcall *)(_DWORD))v18->m_pOption2Checkbox->vfptr[2].__vecDelDtor)(0);
      ((void (__stdcall *)(_DWORD))v18->m_pOption3Checkbox->vfptr[2].__vecDelDtor)(0);
      ((void (__stdcall *)(signed int, signed int))v18->m_pApplyButton->vfptr[3].OnLoseFocus)(352, 298);
      ((void (__thiscall *)(UIElement_Button *, signed int, signed int))v18->m_pCancelButton->vfptr[3].OnLoseFocus)(
        v18->m_pCancelButton,
        232,
        298);
      StringInfo::~StringInfo(&siOption1);
      goto LABEL_135;
    }
LABEL_120:
    ((void (__stdcall *)(signed int))v103->vfptr[13].__vecDelDtor)(1);
    goto LABEL_121;
  }
  if ( v101 == 11 )
  {
    StringInfo::StringInfo(&siOption1);
    if ( i_setup_id.id != script_id.id )
      v18->m_p3DView->m_alternateSetupID.id = i_setup_id.id;
    ((void (__stdcall *)(signed int))v18->m_pOption1Checkbox->vfptr[2].__vecDelDtor)(1);
    v104 = compute_str_hash("ID_Barber_Undead_NoFlame");
    StringInfo::SetStringIDandTableEnum(&siOption1, v104, 268435457);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pOption1Checkbox->vfptr, &siOption1, 0, 1);
    if ( i_setup_id.id == UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP.id
      || i_setup_id.id == UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP.id
      || i_setup_id.id == UNDEAD_MALE_SKELETON_NOFLAME_SETUP.id )
      goto LABEL_133;
    v105 = UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP.id;
LABEL_132:
    if ( i_setup_id.id != v105 )
    {
      v103 = v18->m_pOption1Checkbox;
      goto LABEL_120;
    }
LABEL_133:
    ((void (__stdcall *)(signed int))v18->m_pOption1Checkbox->vfptr[13].__vecDelDtor)(6);
    goto LABEL_121;
  }
  if ( v101 == 5 )
  {
    StringInfo::StringInfo(&siOption1);
    if ( i_setup_id.id != script_id.id )
      v18->m_p3DView->m_alternateSetupID.id = i_setup_id.id;
    ((void (__stdcall *)(signed int))v18->m_pOption1Checkbox->vfptr[2].__vecDelDtor)(1);
    v106 = compute_str_hash("ID_Barber_Shadow_NoCrown");
    StringInfo::SetStringIDandTableEnum(&siOption1, v106, 268435457);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pOption1Checkbox->vfptr, &siOption1, 0, 1);
    if ( i_setup_id.id == UMBRAEN_MALE_NOCROWN_SETUP.id )
      goto LABEL_133;
    v105 = UMBRAEN_FEMALE_NOCROWN_SETUP.id;
    goto LABEL_132;
  }
  if ( v101 == 10 )
  {
    StringInfo::StringInfo(&siOption1);
    if ( i_setup_id.id != script_id.id )
      v18->m_p3DView->m_alternateSetupID.id = i_setup_id.id;
    ((void (__stdcall *)(_DWORD))v18->m_pOption1Checkbox->vfptr[2].__vecDelDtor)(1);
    v107 = compute_str_hash("ID_Barber_Shadow_NoCrown");
    StringInfo::SetStringIDandTableEnum(&siOption1, v107, 268435457);
    UIElement_Text::SetStringInfoWithFont((UIElement_Text *)&v18->m_pOption1Checkbox->vfptr, &siOption1, 0, 1);
    if ( i_setup_id.id == PENUMBRAEN_MALE_NOCROWN_SETUP.id )
      goto LABEL_133;
    v105 = PENUMBRAEN_FEMALE_NOCROWN_SETUP.id;
    goto LABEL_132;
  }
  ((void (__stdcall *)(_DWORD))v18->m_pOption1Checkbox->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v18->m_pOption2Checkbox->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v18->m_pOption3Checkbox->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(signed int, signed int))v18->m_pApplyButton->vfptr[3].OnLoseFocus)(352, 274);
  ((void (__thiscall *)(UIElement_Button *, signed int, signed int))v18->m_pCancelButton->vfptr[3].OnLoseFocus)(
    v18->m_pCancelButton,
    232,
    274);
LABEL_135:
  if ( (_DWORD)playerDesc.m_pInterface )
    ((void (*)(void))playerDesc.m_pInterface->vfptr->Release)();
}

//----- (004E0EC0) --------------------------------------------------------  // acclient.c:271177
void __userpurge gmBarberUI::RecvNotice_StartBarberNotice(gmBarberUI *this@<ecx>, long double a2@<st0>, IDClass<_tagDataID,32,0> i_base_palette, IDClass<_tagDataID,32,0> i_head_object, IDClass<_tagDataID,32,0> i_head_texture, IDClass<_tagDataID,32,0> i_default_head_texture, IDClass<_tagDataID,32,0> i_eyes_texture, IDClass<_tagDataID,32,0> i_default_eyes_texture, IDClass<_tagDataID,32,0> i_nose_texture, IDClass<_tagDataID,32,0> i_default_nose_texture, IDClass<_tagDataID,32,0> i_mouth_texture, IDClass<_tagDataID,32,0> i_default_mouth_texture, IDClass<_tagDataID,32,0> i_skin_palette, IDClass<_tagDataID,32,0> i_hair_palette, IDClass<_tagDataID,32,0> i_eyes_palette, IDClass<_tagDataID,32,0> i_setup_id, int i_option1, int i_option2)
{
  gmBarberUI *v18; // edi@1
  char *v19; // esi@1

  v18 = this;
  v19 = (char *)&this[-1].m_desc.m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[1];
  gmBarberUI::InitializePage(
    (gmBarberUI *)((char *)this - 1528),
    a2,
    i_base_palette,
    i_head_object,
    i_head_texture,
    i_default_head_texture,
    i_eyes_texture,
    i_default_eyes_texture,
    i_nose_texture,
    i_default_nose_texture,
    i_mouth_texture,
    i_default_mouth_texture,
    i_skin_palette,
    i_hair_palette,
    i_eyes_palette,
    i_setup_id,
    i_option1,
    i_option2);
  gmCG3DView::Update((gmCG3DView *)v18->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[18]);
  (*(void (__thiscall **)(char *, signed int))(*(_DWORD *)v19 + 24))(v19, 1);
}

//----- (006F5A90) --------------------------------------------------------  // acclient.c:778176
void sub_6F5A90()
{
  flt_840550 = 1000.0 + 1.0;
}

//----- (006F5AB0) --------------------------------------------------------  // acclient.c:778182
void _E93_88()
{
  flt_840554 = 24.0 * 8.0;
}

//----- (006F5AD0) --------------------------------------------------------  // acclient.c:778188
void _E95_88()
{
  flt_840558 = 24.0 * 0.5;
}

//----- (006F5AF0) --------------------------------------------------------  // acclient.c:778194
int sub_6F5AF0()
{
  return atexit(nullsub_618);
}

//----- (006F5B00) --------------------------------------------------------  // acclient.c:778200
int sub_6F5B00()
{
  return atexit(nullsub_619);
}

//----- (006F5B10) --------------------------------------------------------  // acclient.c:778206
int _E103_98()
{
  return atexit(nullsub_620);
}

//----- (006F5B20) --------------------------------------------------------  // acclient.c:778212
void _E106_71()
{
  DEFAULT_VIEW_RADIUS_72 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F5B40) --------------------------------------------------------  // acclient.c:778218
void _E108_55()
{
  MIN_QUANTUM_72 = 1.0 / 30.0;
}

//----- (006F5B60) --------------------------------------------------------  // acclient.c:778224
void _E110_46()
{
  MAX_QUANTUM_72 = 1.0 / 5.0;
}

//----- (006F5B80) --------------------------------------------------------  // acclient.c:778230
void _E112_63()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840570, PFID_A8R8G8B8);
}

//----- (006F5B90) --------------------------------------------------------  // acclient.c:778236
int _E114_32()
{
  return atexit(nullsub_544);
}

//----- (006F5BA0) --------------------------------------------------------  // acclient.c:778242
void _E118_49()
{
  LOWEST_DATA_RATE_97 = 1024;
}

//----- (006F5BB0) --------------------------------------------------------  // acclient.c:778248
void _E120_36()
{
  HIGHEST_DATA_RATE_97 = 0x7FFF;
}

//----- (006F5BC0) --------------------------------------------------------  // acclient.c:778254
int _E122_21()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_97;
  INITIAL_MAX_DATA_RATE_45 = LOWEST_DATA_RATE_97;
  return result;
}

//----- (006F5BD0) --------------------------------------------------------  // acclient.c:778264
int _E127_39()
{
  return atexit(_E128_49);
}

//----- (006F5BE0) --------------------------------------------------------  // acclient.c:778270
int _E130_32()
{
  return atexit(_E131_38);
}

//----- (006F5BF0) --------------------------------------------------------  // acclient.c:778276
int _E133_26()
{
  return atexit(_E134_30);
}

//----- (006F5C00) --------------------------------------------------------  // acclient.c:778282
int _E136_21()
{
  return atexit(_E137_29);
}

//----- (006F5C10) --------------------------------------------------------  // acclient.c:778288
int _E139_21()
{
  return atexit(_E140_24);
}

//----- (006F5C20) --------------------------------------------------------  // acclient.c:778294
int _E142_19()
{
  return atexit(_E143_25);
}

//----- (006F5C30) --------------------------------------------------------  // acclient.c:778300
int _E145_20()
{
  return atexit(_E146_25);
}

//----- (006F5C40) --------------------------------------------------------  // acclient.c:778306
int _E148_21()
{
  return atexit(_E149_25);
}

//----- (006F5C50) --------------------------------------------------------  // acclient.c:778312
int _E151_19()
{
  return atexit(_E152_23);
}

//----- (006F5C60) --------------------------------------------------------  // acclient.c:778318
int _E154_19()
{
  return atexit(_E155_20);
}

//----- (006F5C70) --------------------------------------------------------  // acclient.c:778324
int _E157_18()
{
  return atexit(_E158_22);
}

//----- (006F5C80) --------------------------------------------------------  // acclient.c:778330
int _E160_20()
{
  return atexit(_E161_21);
}

//----- (006F5C90) --------------------------------------------------------  // acclient.c:778336
int _E163_16()
{
  return atexit(_E164_23);
}

//----- (006F5CA0) --------------------------------------------------------  // acclient.c:778342
int _E166_17()
{
  return atexit(_E167_19);
}

//----- (006F5CB0) --------------------------------------------------------  // acclient.c:778348
int _E169_14()
{
  return atexit(_E170_18);
}

//----- (006F5CC0) --------------------------------------------------------  // acclient.c:778354
int _E172_15()
{
  return atexit(_E173_17);
}

//----- (006F5CD0) --------------------------------------------------------  // acclient.c:778360
int _E175_13()
{
  return atexit(_E176_18);
}

//----- (006F5CE0) --------------------------------------------------------  // acclient.c:778366
int _E178_13()
{
  return atexit(_E179_17);
}

//----- (006F5CF0) --------------------------------------------------------  // acclient.c:778372
int _E181_13()
{
  return atexit(_E182_17);
}

//----- (006F5D00) --------------------------------------------------------  // acclient.c:778378
int _E184_11()
{
  return atexit(_E185_14);
}

//----- (006F5D10) --------------------------------------------------------  // acclient.c:778384
int _E187_10()
{
  return atexit(_E188_15);
}

//----- (006F5D20) --------------------------------------------------------  // acclient.c:778390
int _E190_11()
{
  return atexit(_E191_14);
}

//----- (006F5D30) --------------------------------------------------------  // acclient.c:778396
int _E193_10()
{
  return atexit(_E194_21);
}

//----- (006F5D40) --------------------------------------------------------  // acclient.c:778402
int _E196_13()
{
  return atexit(_E197_12);
}

//----- (006F5D50) --------------------------------------------------------  // acclient.c:778408
int _E199_10()
{
  return atexit(_E200_16);
}

//----- (006F5D60) --------------------------------------------------------  // acclient.c:778414
int _E202_10()
{
  return atexit(_E203_15);
}

//----- (006F5D70) --------------------------------------------------------  // acclient.c:778420
int _E205_10()
{
  return atexit(_E206_18);
}

//----- (006F5D80) --------------------------------------------------------  // acclient.c:778426
int _E208_14()
{
  return atexit(_E209_13);
}

//----- (006F5D90) --------------------------------------------------------  // acclient.c:778432
int _E211_10()
{
  return atexit(_E212_16);
}

//----- (006F5DA0) --------------------------------------------------------  // acclient.c:778438
int _E214_13()
{
  return atexit(_E215_12);
}

//----- (006F5DB0) --------------------------------------------------------  // acclient.c:778444
int _E217_10()
{
  return atexit(_E218_13);
}

//----- (006F5DC0) --------------------------------------------------------  // acclient.c:778450
int _E220_10()
{
  return atexit(_E221_13);
}

//----- (006F5DD0) --------------------------------------------------------  // acclient.c:778456
int _E223_10()
{
  return atexit(_E224_13);
}

//----- (006F5DE0) --------------------------------------------------------  // acclient.c:778462
int _E226_10()
{
  return atexit(_E227_13);
}

//----- (006F5DF0) --------------------------------------------------------  // acclient.c:778468
int _E229_10()
{
  return atexit(_E230_13);
}

//----- (006F5E00) --------------------------------------------------------  // acclient.c:778474
int _E232_10()
{
  UNDEAD_MALE_CLOTHING_DEFAULT.id = UNDEAD_MALE_UNDEAD_SETUP.id;
  return atexit(_E233_12);
}

//----- (006F5E20) --------------------------------------------------------  // acclient.c:778481
int _E235_10()
{
  UNDEAD_FEMALE_CLOTHING_DEFAULT.id = UNDEAD_FEMALE_UNDEAD_SETUP.id;
  return atexit(_E236_12);
}

//----- (006F5E40) --------------------------------------------------------  // acclient.c:778488
int _E238_9()
{
  UMBRAEN_MALE_CLOTHING_DEFAULT.id = UMBRAEN_MALE_CROWN_SETUP.id;
  return atexit(_E239_12);
}

//----- (006F5E60) --------------------------------------------------------  // acclient.c:778495
int _E241_9()
{
  UMBRAEN_FEMALE_CLOTHING_DEFAULT.id = UMBRAEN_FEMALE_CROWN_SETUP.id;
  return atexit(_E242_12);
}

//----- (006F5E80) --------------------------------------------------------  // acclient.c:778502
int _E244_9()
{
  PENUMBRAEN_MALE_CLOTHING_DEFAULT.id = PENUMBRAEN_MALE_CROWN_SETUP.id;
  return atexit(_E245_11);
}

//----- (006F5EA0) --------------------------------------------------------  // acclient.c:778509
int _E247_9()
{
  PENUMBRAEN_FEMALE_CLOTHING_DEFAULT.id = PENUMBRAEN_FEMALE_CROWN_SETUP.id;
  return atexit(_E248_11);
}

//----- (006F5EC0) --------------------------------------------------------  // acclient.c:778516
int _E250_9()
{
  return atexit(_E251_11);
}

//----- (006F5ED0) --------------------------------------------------------  // acclient.c:778522
int _E253_9()
{
  return atexit(_E254_12);
}

//----- (006F5EE0) --------------------------------------------------------  // acclient.c:778528
int _E256_9()
{
  return atexit(_E257_10);
}

//----- (006F5EF0) --------------------------------------------------------  // acclient.c:778534
int _E259_10()
{
  return atexit(_E260_11);
}

//----- (006F5F00) --------------------------------------------------------  // acclient.c:778540
int _E262_10()
{
  return atexit(_E263_10);
}

//----- (006F5F10) --------------------------------------------------------  // acclient.c:778546
int _E265_10()
{
  return atexit(_E266_10);
}

//----- (006F5F20) --------------------------------------------------------  // acclient.c:778552
int _E268_9()
{
  return atexit(_E269_9);
}

//----- (006F5F30) --------------------------------------------------------  // acclient.c:778558
int _E271_8()
{
  return atexit(_E272_8);
}

//----- (006F5F40) --------------------------------------------------------  // acclient.c:778564
int _E274_8()
{
  return atexit(_E275_8);
}

//----- (006F5F50) --------------------------------------------------------  // acclient.c:778570
int _E277_8()
{
  return atexit(_E278_8);
}

//----- (006F5F60) --------------------------------------------------------  // acclient.c:778576
int _E280_7()
{
  return atexit(_E281_8);
}

//----- (006F5F70) --------------------------------------------------------  // acclient.c:778582
int _E283_8()
{
  return atexit(_E284_7);
}

//----- (006F5F80) --------------------------------------------------------  // acclient.c:778588
int _E286_7()
{
  return atexit(_E287_8);
}

//----- (006F5F90) --------------------------------------------------------  // acclient.c:778594
int _E289_7()
{
  return atexit(_E290_8);
}

//----- (006F5FA0) --------------------------------------------------------  // acclient.c:778600
int _E292_8()
{
  return atexit(_E293_7);
}

//----- (006F5FB0) --------------------------------------------------------  // acclient.c:778606
int _E295_7()
{
  return atexit(_E296_8);
}

//----- (006F5FC0) --------------------------------------------------------  // acclient.c:778612
int _E298_8()
{
  return atexit(_E299_6);
}

//----- (006F5FD0) --------------------------------------------------------  // acclient.c:778618
int _E301_6()
{
  return atexit(_E302_7);
}

//----- (006F5FE0) --------------------------------------------------------  // acclient.c:778624
int _E304_7()
{
  return atexit(_E305_6);
}

//----- (006F5FF0) --------------------------------------------------------  // acclient.c:778630
int _E307_6()
{
  return atexit(_E308_7);
}

//----- (006F6000) --------------------------------------------------------  // acclient.c:778636
int _E310_7()
{
  return atexit(_E311_6);
}

//----- (006F6010) --------------------------------------------------------  // acclient.c:778642
int _E313_6()
{
  return atexit(_E314_7);
}

//----- (006F6020) --------------------------------------------------------  // acclient.c:778648
int _E316_7()
{
  return atexit(_E317_6);
}

//----- (006F6030) --------------------------------------------------------  // acclient.c:778654
int _E319_6()
{
  return atexit(_E320_7);
}

//----- (006F6040) --------------------------------------------------------  // acclient.c:778660
int _E322_7()
{
  return atexit(_E323_6);
}

//----- (006F6050) --------------------------------------------------------  // acclient.c:778666
int _E325_6()
{
  return atexit(_E326_7);
}

//----- (006F6060) --------------------------------------------------------  // acclient.c:778672
int _E328_7()
{
  return atexit(_E329_6);
}

//----- (006F6070) --------------------------------------------------------  // acclient.c:778678
int _E331_6()
{
  return atexit(_E332_7);
}

//----- (006F6080) --------------------------------------------------------  // acclient.c:778684
int _E334_6()
{
  return atexit(_E335_6);
}

//----- (006F6090) --------------------------------------------------------  // acclient.c:778690
int _E337_6()
{
  return atexit(_E338_6);
}

//----- (006F60A0) --------------------------------------------------------  // acclient.c:778696
int _E340_6()
{
  return atexit(_E341_6);
}

//----- (006F60B0) --------------------------------------------------------  // acclient.c:778702
int sub_6F60B0()
{
  return atexit(nullsub_617);
}

