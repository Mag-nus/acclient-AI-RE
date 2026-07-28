/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : VividTargetInd
   Object     : GAME\game_ui_misc\VividTargetInd.obj
   Functions  : 45
   Addresses  : 004F5CE0 - 006F91C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F5CE0) --------------------------------------------------------  // acclient.c:289397
void __thiscall VividTargetIndicator::SetSelected(VividTargetIndicator *this, unsigned int iid)
{
  VividTargetIndicator *v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // esi@4
  HashBaseData<unsigned long> *v5; // eax@6
  HashBaseData<unsigned long> *v6; // ebx@6
  HashBaseData<unsigned long> *v7; // eax@11
  RGBAColor *v8; // eax@20
  int v9; // edi@20
  RGBAColor result; // [sp+Ch] [bp-10h]@20

  v2 = this;
  if ( SmartBox::smartbox )
    v3 = SmartBox::smartbox->player_id;
  else
    v3 = 0;
  v4 = iid;
  if ( v3 == iid )
    v4 = 0;
  v5 = ClientObjMaintSystem::GetWeenieObject(v4);
  v6 = v5;
  if ( !v5 || ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v5) || v6[8].id == 2 )
  {
    v4 = 0;
    v6 = 0;
  }
  if ( v4 != v2->m_idSelectedTarget )
  {
    v7 = ClientObjMaintSystem::GetWeenieObject(v2->m_idSelectedTarget);
    if ( v7 )
      ((void (__stdcall *)(VividTargetIndicator *))v7[1].vfptr[3].__vecDelDtor)(v2);
    v2->m_idSelectedTarget = v4;
    if ( v6 )
      ((void (__thiscall *)(int, _UNKNOWN *, VividTargetIndicator *))v6[1].vfptr[1].__vecDelDtor)(
        &v6[1],
        &loc_4DD245,
        v2);
  }
  if ( SmartBox::smartbox )
    SmartBox::SetTargetObjectID(SmartBox::smartbox, v4);
  if ( v2->m_bDisplayOn )
  {
    if ( v4 )
    {
      v8 = gmRadarUI::GetBlipColor(&result, v4);
      v9 = (int)&v2->m_clrSelectedObjectColor;
      *(_DWORD *)v9 = LODWORD(v8->r);
      *(_DWORD *)(v9 + 4) = LODWORD(v8->g);
      *(_DWORD *)(v9 + 8) = LODWORD(v8->b);
      *(_DWORD *)(v9 + 12) = LODWORD(v8->a);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))v2->m_pOnScreen->vfptr[2].__vecDelDtor)(0);
      v2->m_pOffScreen->vfptr[2].__vecDelDtor((IInputActionCallback *)v2->m_pOffScreen, 0);
    }
  }
}

//----- (004F5DD0) --------------------------------------------------------  // acclient.c:289458
int __stdcall VividTargetIndicator::CopyImage(RenderSurface *i_pImg, RGBAColor *i_clr)
{
  int v3; // eax@1
  int v4; // esi@1
  int v5; // ebp@2
  RenderSurface *v6; // edi@2
  unsigned int v7; // ST28_4@2
  PixelFormatID v8; // eax@2
  const unsigned int v9; // eax@7
  Graphic *v10; // eax@8
  int v11; // eax@9
  int v12; // ebx@9
  unsigned int i_pImga; // [sp+Ch] [bp+4h]@2

  v3 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
  v4 = v3;
  if ( v3 )
  {
    v5 = *(_DWORD *)v3;
    v6 = i_pImg;
    v7 = i_pImg->width;
    i_pImga = i_pImg->height;
    v8 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
    if ( (unsigned __int8)(*(int (__thiscall **)(int, unsigned int, unsigned int, PixelFormatID, signed int))(v5 + 88))(
                            v4,
                            v7,
                            i_pImga,
                            v8,
                            1) )
    {
      switch ( s_BlitMethod )
      {
        case 1u:
          SurfaceWindow::Blit((SurfaceWindow *)(v4 + 172), &v6->window, 0, 1.0);
          SurfaceWindow::Color((SurfaceWindow *)(v4 + 172), 0, Blit_Multiply, i_clr);
          break;
        case 2u:
          SurfaceWindow::Blit((SurfaceWindow *)(v4 + 172), &v6->window, 0, 1.0);
          SurfaceWindow::Color((SurfaceWindow *)(v4 + 172), 0, Blit_Colorize, i_clr);
          break;
        case 3u:
          SurfaceWindow::Blit((SurfaceWindow *)(v4 + 172), &v6->window, 0, 1.0);
          SurfaceWindow::Color((SurfaceWindow *)(v4 + 172), 0, Blit_Screen, i_clr);
          break;
        case 4u:
          v9 = RGBAColor::GetColor32(i_clr);
          SurfaceWindow::BlitAndColor((SurfaceWindow *)(v4 + 172), &v6->window, 0, 1.0, 0, Blit_Colorize, v9);
          break;
        default:
          break;
      }
      v10 = (Graphic *)operator new(0xCu);
      if ( v10 )
      {
        Graphic::Graphic(v10, (RenderSurface *)v4);
        v12 = v11;
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
        return v12;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
  }
  return 0;
}

//----- (004F5F40) --------------------------------------------------------  // acclient.c:289524
void __thiscall VividTargetIndicator::RecvNotice_ServerSaysMoveItem(VividTargetIndicator *this, unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  VividTargetIndicator::SetSelected(this, ACCWeenieObject::selectedID);
}

//----- (004F5FB0) --------------------------------------------------------  // acclient.c:289555
void __thiscall VividTargetIndicator::UpdateDisplayState(VividTargetIndicator *this)
{
  VividTargetIndicator *v1; // esi@1
  CPlayerSystem *v2; // eax@1
  char v3; // al@1
  bool v4; // cl@1

  v1 = this;
  v2 = CPlayerSystem::GetPlayerSystem();
  v3 = PlayerModule::VividTargetingIndicator((PlayerModule *)&v2->playerModule.vfptr);
  v4 = v1->m_bEnabled;
  v1->m_bDisplayOn = v3;
  if ( v4 && v3 )
  {
    VividTargetIndicator::SetSelected(v1, v1->m_idSelectedTarget);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v1->m_pOnScreen->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v1->m_pOffScreen->vfptr[2].__vecDelDtor)(0);
  }
}

//----- (004F6000) --------------------------------------------------------  // acclient.c:289579
void __thiscall VividTargetIndicator::RecvNotice_PlayerDescReceived(VividTargetIndicator *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  VividTargetIndicator *v3; // esi@1
  CPlayerSystem *v4; // eax@1
  char v5; // al@1
  bool v6; // cl@1

  v3 = this;
  v4 = CPlayerSystem::GetPlayerSystem();
  v5 = PlayerModule::VividTargetingIndicator((PlayerModule *)&v4->playerModule.vfptr);
  v6 = v3->m_bEnabled;
  v3->m_bDisplayOn = v5;
  if ( v6 && v5 )
  {
    VividTargetIndicator::SetSelected(v3, v3->m_idSelectedTarget);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))v3->m_pOnScreen->vfptr[2].__vecDelDtor)(0);
    ((void (__stdcall *)(_DWORD))v3->m_pOffScreen->vfptr[2].__vecDelDtor)(0);
  }
}

//----- (004F6050) --------------------------------------------------------  // acclient.c:289603
void __thiscall VividTargetIndicator::RecvNotice_PlayerOptionChanged(VividTargetIndicator *this, PlayerOption i_eOption)
{
  VividTargetIndicator *v2; // esi@1
  CPlayerSystem *v3; // eax@2
  char v4; // al@2
  bool v5; // cl@2

  v2 = this;
  if ( i_eOption == 14 )
  {
    v3 = CPlayerSystem::GetPlayerSystem();
    v4 = PlayerModule::VividTargetingIndicator((PlayerModule *)&v3->playerModule.vfptr);
    v5 = v2->m_bEnabled;
    v2->m_bDisplayOn = v4;
    if ( v5 && v4 )
    {
      VividTargetIndicator::SetSelected(v2, v2->m_idSelectedTarget);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))v2->m_pOnScreen->vfptr[2].__vecDelDtor)(0);
      ((void (__stdcall *)(_DWORD))v2->m_pOffScreen->vfptr[2].__vecDelDtor)(0);
    }
  }
}

//----- (004F60A0) --------------------------------------------------------  // acclient.c:289630
void __thiscall VividTargetIndicator::SetEnabled(VividTargetIndicator *this, bool i_bOn)
{
  VividTargetIndicator *v2; // esi@1
  CPlayerSystem *v3; // eax@2
  char v4; // al@2
  bool v5; // cl@2

  v2 = this;
  if ( this->m_bEnabled != i_bOn )
  {
    this->m_bEnabled = i_bOn;
    v3 = CPlayerSystem::GetPlayerSystem();
    v4 = PlayerModule::VividTargetingIndicator((PlayerModule *)&v3->playerModule.vfptr);
    v5 = v2->m_bEnabled;
    v2->m_bDisplayOn = v4;
    if ( v5 && v4 )
    {
      VividTargetIndicator::SetSelected(v2, v2->m_idSelectedTarget);
    }
    else
    {
      ((void (__stdcall *)(_DWORD))v2->m_pOnScreen->vfptr[2].__vecDelDtor)(0);
      ((void (__stdcall *)(_DWORD))v2->m_pOffScreen->vfptr[2].__vecDelDtor)(0);
    }
  }
}

//----- (004F6100) --------------------------------------------------------  // acclient.c:289658
void __thiscall VividTargetIndicator::RecvNotice_SelectionChanged(VividTargetIndicator *this)
{
  VividTargetIndicator::SetSelected(this, ACCWeenieObject::selectedID);
}

//----- (004F6110) --------------------------------------------------------  // acclient.c:289664
void __thiscall VividTargetIndicator::RecvNotice_ChangeRadarLook(VividTargetIndicator *this, CWeenieObject *i_obj)
{
  VividTargetIndicator::SetSelected(this, ACCWeenieObject::selectedID);
}

//----- (004F6120) --------------------------------------------------------  // acclient.c:289670
void __thiscall VividTargetIndicator::OnQualityRemoved(VividTargetIndicator *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  VividTargetIndicator::SetSelected((VividTargetIndicator *)((char *)this - 4), ACCWeenieObject::selectedID);
}

//----- (004F6140) --------------------------------------------------------  // acclient.c:289676
void __thiscall VividTargetIndicator::SetOffScreenImage(VividTargetIndicator *this, unsigned int i_vti, RGBAColor *i_clr)
{
  VividTargetIndicator *v3; // esi@1
  int v4; // ebp@3

  v3 = this;
  if ( i_vti != this->m_vtiCurrent || !(unsigned __int8)RGBAColor::operator==(i_clr, &this->m_clrOffScreen) )
  {
    v4 = VividTargetIndicator::CopyImage(v3->m_rgSourceImages.m_data[i_vti], i_clr);
    UIRegion::ClearImage((UIRegion *)&v3->m_pOffScreen->vfptr);
    UIRegion::SetImage((UIRegion *)&v3->m_pOffScreen->vfptr, (Graphic *)v4);
    v3->m_clrOffScreen = *i_clr;
    v3->m_vtiCurrent = i_vti;
  }
}

//----- (004F61B0) --------------------------------------------------------  // acclient.c:289693
void __thiscall VividTargetIndicator::SetOnScreenColor(VividTargetIndicator *this, RGBAColor *i_clr)
{
  VividTargetIndicator *v2; // edi@1
  signed int v3; // esi@2
  int v4; // ebx@3
  char *v5; // [sp+8h] [bp-4h]@1

  v2 = this;
  v5 = (char *)&this->m_clrOnScreen;
  if ( !(unsigned __int8)RGBAColor::operator==(i_clr, &this->m_clrOnScreen) )
  {
    v3 = 1;
    do
    {
      v4 = VividTargetIndicator::CopyImage(v2->m_rgSourceImages.m_data[v3], i_clr);
      UIRegion::ClearImage((UIRegion *)&v2->m_rgOnScreenCorners.m_data[v3]->vfptr);
      UIRegion::SetImage((UIRegion *)&v2->m_rgOnScreenCorners.m_data[v3]->vfptr, (Graphic *)v4);
      ++v3;
    }
    while ( (unsigned int)(v3 * 4) <= 0x10 );
    *(_OWORD *)v5 = *i_clr;
  }
}

//----- (004F6230) --------------------------------------------------------  // acclient.c:289718
void __thiscall VividTargetIndicator::~VividTargetIndicator(VividTargetIndicator *this)
{
  VividTargetIndicator *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&VividTargetIndicator::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)VividTargetIndicator::vftable;
  VividTargetIndicator::s_pVTInstance = 0;
  (*(void (__stdcall **)(QualityChangeHandlerVtbl **))&QualityRegistrar::s_pQR->vfptr->gap14[0])(&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
    v2->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v2, (NoticeHandler *)v1);
  if ( (v1->m_rgOnScreenCorners.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_rgOnScreenCorners.m_data);
  if ( (v1->m_rgSourceImages.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_rgSourceImages.m_data);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C5364: using guessed type void (__thiscall *VividTargetIndicator::vftable[2])(VividTargetIndicator *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7C5370: using guessed type bool (__thiscall *VividTargetIndicator::vftable)(DBCache *this);

//----- (004F62B0) --------------------------------------------------------  // acclient.c:289743
void __thiscall VividTargetIndicator::OnDraw(VividTargetIndicator *this, unsigned int object_id, ObjectSelectStatus oss, tagRECT *bbox, const float heading)
{
  VividTargetIndicator *v5; // esi@1
  UIRegion *v6; // ecx@30
  signed int v7; // eax@31
  RenderDevice *v8; // edi@31
  double v9; // st7@31
  long double v10; // st5@32
  long double v11; // st5@32
  double v12; // st6@35
  double v13; // st6@38
  double v14; // st6@41
  double v15; // st6@44
  long double v16; // st4@52
  UIElement *v17; // ebx@54
  IInputActionCallbackVtbl *v18; // ebp@54
  float _MaxValue; // ST0C_4@54
  float v20; // ST0C_4@54
  float v21; // ST08_4@54
  unsigned __int64 v22; // rax@54
  int v23; // eax@55
  int v24; // ebp@55
  int v25; // eax@55
  int v26; // ebx@55
  int v27; // edi@55
  unsigned int v28; // edx@55
  int v29; // ebp@55
  int v30; // eax@65
  int h; // [sp+18h] [bp-4h]@55
  const float object_ida; // [sp+20h] [bp+4h]@31
  unsigned int object_idb; // [sp+20h] [bp+4h]@55
  float x; // [sp+24h] [bp+8h]@31
  float xa; // [sp+24h] [bp+8h]@55
  float width; // [sp+28h] [bp+Ch]@35
  int headinga; // [sp+2Ch] [bp+10h]@55

  v5 = this;
  if ( !this->m_bEnabled || !this->m_bDisplayOn || !object_id )
  {
    ((void (__stdcall *)(signed int))this->m_pOnScreen->vfptr[2].__vecDelDtor)(0);
LABEL_77:
    v5->m_pOffScreen->vfptr[2].__vecDelDtor((IInputActionCallback *)v5->m_pOffScreen, 0);
    return;
  }
  if ( oss == 1 )
  {
    VividTargetIndicator::SetOnScreenColor(this, &this->m_clrSelectedObjectColor);
    v23 = UIRegion::GetWidth(*((UIRegion **)v5->m_rgOnScreenCorners.m_data + 1));
    v24 = v23;
    object_idb = v23;
    v25 = UIRegion::GetHeight(*((UIRegion **)v5->m_rgOnScreenCorners.m_data + 1));
    LODWORD(xa) = RenderDevice::render_device->m_viewportHeight - v25 - 8;
    v26 = bbox->right;
    headinga = bbox->bottom;
    v27 = bbox->left - v24;
    v28 = RenderDevice::render_device->m_viewportWidth - v24 - 8;
    v29 = bbox->top - v25;
    h = v25;
    if ( v27 > v26 )
      v27 = v26 - 1;
    if ( v29 > headinga )
      v29 = headinga - 1;
    if ( v27 < 8 )
      v27 = 8;
    if ( v29 < 8 )
      v29 = 8;
    if ( v26 < (signed int)(object_idb + 8) )
      v26 = object_idb + 8;
    v30 = v25 + 8;
    if ( headinga < v30 )
      headinga = v30;
    if ( v27 > (signed int)(v28 - object_idb) )
      v27 = v28 - object_idb;
    if ( v29 > LODWORD(xa) - h )
      v29 = LODWORD(xa) - h;
    if ( v26 > (signed int)v28 )
      v26 = v28;
    if ( headinga > SLODWORD(xa) )
      headinga = LODWORD(xa);
    ((void (__stdcall *)(int, int))v5->m_pOnScreen->vfptr[3].OnLoseFocus)(v27, v29);
    ((void (__stdcall *)(int, int))v5->m_pOnScreen->vfptr[4].__vecDelDtor)(object_idb + v26 - v27, h + headinga - v29);
    ((void (__stdcall *)(signed int))v5->m_pOnScreen->vfptr[2].__vecDelDtor)(1);
    goto LABEL_77;
  }
  if ( oss == 2 )
  {
    if ( heading >= 338.0 || heading < 23.0 )
    {
      VividTargetIndicator::SetOffScreenImage(this, 6u, &this->m_clrSelectedObjectColor);
    }
    else if ( heading < 23.0 || heading >= 68.0 )
    {
      if ( heading < 68.0 || heading >= 113.0 )
      {
        if ( heading < 113.0 || heading >= 158.0 )
        {
          if ( heading < 158.0 || heading >= 203.0 )
          {
            if ( heading < 203.0 || heading >= 248.0 )
            {
              if ( heading < 248.0 || heading >= 293.0 )
              {
                if ( heading >= 293.0 && heading < 338.0 )
                  VividTargetIndicator::SetOffScreenImage(this, 5u, &this->m_clrSelectedObjectColor);
              }
              else
              {
                VividTargetIndicator::SetOffScreenImage(this, 8u, &this->m_clrSelectedObjectColor);
              }
            }
            else
            {
              VividTargetIndicator::SetOffScreenImage(this, 0xAu, &this->m_clrSelectedObjectColor);
            }
          }
          else
          {
            VividTargetIndicator::SetOffScreenImage(this, 0xBu, &this->m_clrSelectedObjectColor);
          }
        }
        else
        {
          VividTargetIndicator::SetOffScreenImage(this, 0xCu, &this->m_clrSelectedObjectColor);
        }
      }
      else
      {
        VividTargetIndicator::SetOffScreenImage(this, 9u, &this->m_clrSelectedObjectColor);
      }
    }
    else
    {
      VividTargetIndicator::SetOffScreenImage(this, 7u, &this->m_clrSelectedObjectColor);
    }
    v6 = (UIRegion *)&v5->m_pOffScreen->vfptr;
    if ( v6 )
    {
      x = (double)UIRegion::GetWidth(v6);
      *(float *)&v7 = COERCE_FLOAT(UIRegion::GetHeight((UIRegion *)&v5->m_pOffScreen->vfptr));
      v8 = RenderDevice::render_device;
      object_ida = *(float *)&v7;
      v9 = (double)v7;
      if ( heading <= 45.0 )
      {
        v10 = tan(0.017453292 * heading) * ((double)RenderDevice::render_device->m_viewportHeight * 0.5);
        heading = min_dist;
        v11 = v10 + (double)RenderDevice::render_device->m_viewportWidth * 0.5;
LABEL_53:
        object_ida = v11 - x * 0.5;
        goto LABEL_54;
      }
      if ( heading <= 45.0 || heading > 90.0 )
      {
        if ( heading <= 90.0 || heading > 135.0 )
        {
          if ( heading <= 135.0 || heading > 180.0 )
          {
            if ( heading <= 180.0 || heading > 225.0 )
            {
              if ( heading <= 225.0 || heading > 270.0 )
              {
                if ( heading <= 270.0 || heading > 315.0 )
                {
                  if ( heading > 315.0 )
                  {
                    v16 = tan((360.0 - heading) * 0.017453292);
                    heading = min_dist;
                    v11 = (double)RenderDevice::render_device->m_viewportWidth * 0.5
                        - v16 * ((double)RenderDevice::render_device->m_viewportHeight * 0.5);
                    goto LABEL_53;
                  }
                }
                else
                {
                  object_ida = min_dist;
                  heading = (double)RenderDevice::render_device->m_viewportHeight * 0.5
                          - tan((heading - 270.0) * 0.017453292)
                          * ((double)RenderDevice::render_device->m_viewportWidth
                           * 0.5)
                          - v9 * 0.5;
                }
              }
              else
              {
                object_ida = min_dist;
                heading = tan((270.0 - heading) * 0.017453292)
                        * ((double)RenderDevice::render_device->m_viewportWidth
                         * 0.5)
                        + (double)RenderDevice::render_device->m_viewportHeight * 0.5
                        - v9 * 0.5;
              }
            }
            else
            {
              v15 = (double)RenderDevice::render_device->m_viewportHeight;
              object_ida = (double)RenderDevice::render_device->m_viewportWidth * 0.5
                         - tan((heading - 180.0) * 0.017453292) * (v15 * 0.5)
                         - x * 0.5;
              heading = v15 - 8.0 - v9;
            }
          }
          else
          {
            v14 = (double)RenderDevice::render_device->m_viewportHeight;
            object_ida = tan((180.0 - heading) * 0.017453292) * (v14 * 0.5)
                       + (double)RenderDevice::render_device->m_viewportWidth * 0.5
                       - x * 0.5;
            heading = v14 - 8.0 - v9;
          }
        }
        else
        {
          v13 = (double)RenderDevice::render_device->m_viewportWidth;
          object_ida = v13 - 8.0 - x;
          heading = tan((heading - 90.0) * 0.017453292) * (v13 * 0.5)
                  + (double)RenderDevice::render_device->m_viewportHeight * 0.5
                  - v9 * 0.5;
        }
      }
      else
      {
        v12 = (double)RenderDevice::render_device->m_viewportWidth;
        object_ida = v12 - 8.0 - x;
        width = v12;
        heading = (double)RenderDevice::render_device->m_viewportHeight * 0.5
                - tan((90.0 - heading) * 0.017453292) * (width * 0.5)
                - v9 * 0.5;
      }
LABEL_54:
      v17 = v5->m_pOffScreen;
      v18 = v17->vfptr;
      _MaxValue = (double)RenderDevice::render_device->m_viewportHeight - 8.0 - v9;
      LODWORD(v20) = (unsigned __int64)MathLib::Clamp(heading, 8.0, _MaxValue);
      v21 = (double)v8->m_viewportWidth - 8.0 - x;
      v22 = (unsigned __int64)MathLib::Clamp(object_ida, 8.0, v21);
      ((void (__fastcall *)(UIElement *, _DWORD, _DWORD, float))v18[3].OnLoseFocus)(
        v17,
        HIDWORD(v22),
        v22,
        LODWORD(v20));
      ((void (__stdcall *)(_DWORD))v5->m_pOnScreen->vfptr[2].__vecDelDtor)(0);
      v5->m_pOffScreen->vfptr[2].__vecDelDtor((IInputActionCallback *)v5->m_pOffScreen, 1u);
      return;
    }
  }
}

//----- (004F6AE0) --------------------------------------------------------  // acclient.c:289991
void __thiscall VividTargetIndicator::VividTargetIndicator(VividTargetIndicator *this)
{
  char *v1; // eax@1
  char *v2; // eax@1
  char *v3; // esi@1
  unsigned int i; // eax@4
  signed int v5; // eax@10
  int v6; // esi@13
  int v7; // eax@14
  VividTargetIndicator *v8; // [sp+0h] [bp-4h]@1

  v8 = this;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&VividTargetIndicator::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)VividTargetIndicator::vftable;
  v1 = (char *)&this->m_rgSourceImages;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  this->m_pOffScreen = 0;
  this->m_pOnScreen = 0;
  v2 = (char *)&this->m_rgOnScreenCorners;
  *(_DWORD *)v2 = 0;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  this->m_bDisplayOn = 0;
  this->m_bEnabled = 1;
  v3 = (char *)&this->m_rgSourceImages;
  VividTargetIndicator::s_pVTInstance = this;
  if ( (this->m_rgSourceImages.m_sizeAndDeallocate & 0x7FFFFFFF) >= 0xD )
  {
    for ( i = 13; i < this->m_rgSourceImages.m_num; ++i )
      *(_DWORD *)(*(_DWORD *)v3 + 4 * i) = 0;
  }
  else if ( !SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&this->m_rgSourceImages, 0xDu) )
  {
    goto LABEL_7;
  }
  *((_DWORD *)v3 + 2) = 13;
LABEL_7:
  if ( (v8->m_rgOnScreenCorners.m_sizeAndDeallocate & 0x7FFFFFFF) >= 5 )
  {
    v5 = 5;
    if ( v8->m_rgOnScreenCorners.m_num > 5 )
    {
      do
        v8->m_rgOnScreenCorners.m_data[v5++] = 0;
      while ( v5 < v8->m_rgOnScreenCorners.m_num );
    }
    goto LABEL_12;
  }
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v8->m_rgOnScreenCorners, 5u) )
LABEL_12:
    v8->m_rgOnScreenCorners.m_num = 5;
  v6 = 1;
  do
  {
    v7 = DBObj::GetByEnum(v6, 268435465, 0xCu);
    if ( v6 < v8->m_rgSourceImages.m_num )
      v8->m_rgSourceImages.m_data[v6] = (RenderSurface *)v7;
    ++v6;
  }
  while ( (unsigned int)v6 <= 0xC );
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C5364: using guessed type void (__thiscall *VividTargetIndicator::vftable[2])(VividTargetIndicator *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7C5370: using guessed type bool (__thiscall *VividTargetIndicator::vftable)(DBCache *this);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);

//----- (004F6C30) --------------------------------------------------------  // acclient.c:290064
void __cdecl VividTargetIndicator::Draw(unsigned int object_id, ObjectSelectStatus oss, tagRECT *bbox, const float heading)
{
  if ( VividTargetIndicator::s_pVTInstance )
    VividTargetIndicator::OnDraw(VividTargetIndicator::s_pVTInstance, object_id, oss, bbox, heading);
}

//----- (004F6C60) --------------------------------------------------------  // acclient.c:290071
char __thiscall VividTargetIndicator::Initialized(VividTargetIndicator *this, gmSmartBoxUI *i_pParent)
{
  VividTargetIndicator *v2; // edi@1
  UIElement *v3; // eax@1
  UIElement *v4; // eax@1
  UIElement *v5; // eax@3
  UIElement *v6; // eax@5
  UIElement *v7; // eax@7
  UIElement **v8; // eax@11
  GlobalEventHandler *v9; // eax@15
  GlobalEventHandler *v10; // esi@15
  char result; // al@19

  v2 = this;
  this->m_pOffScreen = UIElement::GetChild((UIElement *)&i_pParent->vfptr, 0x10000045u);
  v3 = UIElement::GetChild((UIElement *)&i_pParent->vfptr, 0x10000038u);
  v2->m_pOnScreen = v3;
  v4 = UIElement::GetChild(v3, 0x10000039u);
  if ( v2->m_rgOnScreenCorners.m_num > 1 )
    *((_DWORD *)v2->m_rgOnScreenCorners.m_data + 1) = v4;
  v5 = UIElement::GetChild(v2->m_pOnScreen, 0x1000003Au);
  if ( v2->m_rgOnScreenCorners.m_num > 2 )
    *((_DWORD *)v2->m_rgOnScreenCorners.m_data + 2) = v5;
  v6 = UIElement::GetChild(v2->m_pOnScreen, 0x1000003Bu);
  if ( v2->m_rgOnScreenCorners.m_num > 3 )
    *((_DWORD *)v2->m_rgOnScreenCorners.m_data + 3) = v6;
  v7 = UIElement::GetChild(v2->m_pOnScreen, 0x1000003Cu);
  if ( v2->m_rgOnScreenCorners.m_num > 4 )
    *((_DWORD *)v2->m_rgOnScreenCorners.m_data + 4) = v7;
  if ( v2->m_pOffScreen && v2->m_pOnScreen && (v8 = v2->m_rgOnScreenCorners.m_data, v8[1]) && v8[2] && v8[3] && v8[4] )
  {
    v9 = GlobalEventHandler::GetGlobalEventHandler();
    v10 = v9;
    if ( v9 )
    {
      v9->vfptr->RegisterNoticeHandler(
        (NoticeRegistrar *)v9,
        (unsigned int)((char *)&loc_4DD1EE + 1),
        (NoticeHandler *)v2);
      v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v2);
      v10->vfptr->RegisterNoticeHandler(
        (NoticeRegistrar *)v10,
        (unsigned int)((char *)&loc_4DD21E + 1),
        (NoticeHandler *)v2);
      v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, 100008u, (NoticeHandler *)v2);
    }
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
      7,
      26,
      &v2->vfptr);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
      0,
      7,
      26,
      &v2->vfptr);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
      0,
      1,
      134,
      &v2->vfptr);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
      0,
      1,
      95,
      &v2->vfptr);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
      0,
      1,
      133,
      &v2->vfptr);
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
      0,
      5,
      1,
      &v2->vfptr);
    VividTargetIndicator::UpdateDisplayState(v2);
    if ( SmartBox::smartbox )
      SmartBox::SetTargettingCallback(SmartBox::smartbox, VividTargetIndicator::Draw);
    result = 1;
  }
  else
  {
    v2->m_bDisplayOn = 0;
    result = 0;
  }
  return result;
}

//----- (006F8E10) --------------------------------------------------------  // acclient.c:781645
void sub_6F8E10()
{
  flt_841254 = 1000.0 + 1.0;
}

//----- (006F8E30) --------------------------------------------------------  // acclient.c:781651
void sub_6F8E30()
{
  flt_841258 = 24.0 * 8.0;
}

//----- (006F8E50) --------------------------------------------------------  // acclient.c:781657
void sub_6F8E50()
{
  flt_84125C = 24.0 * 0.5;
}

//----- (006F8E70) --------------------------------------------------------  // acclient.c:781663
int sub_6F8E70()
{
  return atexit(nullsub_651);
}

//----- (006F8E80) --------------------------------------------------------  // acclient.c:781669
int sub_6F8E80()
{
  return atexit(nullsub_652);
}

//----- (006F8E90) --------------------------------------------------------  // acclient.c:781675
int sub_6F8E90()
{
  return atexit(nullsub_653);
}

//----- (006F8EA0) --------------------------------------------------------  // acclient.c:781681
void _E106_84()
{
  dword_841260 = 1024;
}

//----- (006F8EB0) --------------------------------------------------------  // acclient.c:781687
void _E108_65()
{
  dword_841264 = 0x7FFF;
}

//----- (006F8EC0) --------------------------------------------------------  // acclient.c:781693
int _E110_55()
{
  const int result; // eax@1

  result = dword_841260;
  INITIAL_MAX_DATA_RATE_59 = dword_841260;
  return result;
}

//----- (006F8ED0) --------------------------------------------------------  // acclient.c:781703
void _E112_76()
{
  DEFAULT_VIEW_RADIUS_88 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F8EF0) --------------------------------------------------------  // acclient.c:781709
void _E114_39()
{
  MIN_QUANTUM_88 = 1.0 / 30.0;
}

//----- (006F8F10) --------------------------------------------------------  // acclient.c:781715
void _E116_16()
{
  MAX_QUANTUM_88 = 1.0 / 5.0;
}

//----- (006F8F30) --------------------------------------------------------  // acclient.c:781721
void _E118_57()
{
  PixelFormatDesc::PixelFormatDesc(&stru_841280, PFID_A8R8G8B8);
}

//----- (006F8F40) --------------------------------------------------------  // acclient.c:781727
int _E140_4()
{
  RGBAColor_RadarDefault_1 = RGBAColor_RadarWhite_1;
  return LODWORD(RGBAColor_RadarWhite_1.a);
}

//----- (006F8F70) --------------------------------------------------------  // acclient.c:781734
int _E142_23()
{
  RGBAColor_RadarAdmin_1 = RGBAColor_RadarCyan_1;
  return LODWORD(RGBAColor_RadarCyan_1.a);
}

//----- (006F8FA0) --------------------------------------------------------  // acclient.c:781741
int _E144_19()
{
  RGBAColor_RadarAdvocate_1 = RGBAColor_RadarPink_1;
  return LODWORD(RGBAColor_RadarPink_1.a);
}

//----- (006F8FD0) --------------------------------------------------------  // acclient.c:781748
int _E146_5()
{
  RGBAColor_RadarCreature_1 = RGBAColor_RadarGold_1;
  return LODWORD(RGBAColor_RadarGold_1.a);
}

//----- (006F9000) --------------------------------------------------------  // acclient.c:781755
int _E148_26()
{
  RGBAColor_RadarLifeStone_1 = RGBAColor_RadarBlue_1;
  return LODWORD(RGBAColor_RadarBlue_1.a);
}

//----- (006F9030) --------------------------------------------------------  // acclient.c:781762
int _E150_19()
{
  RGBAColor_RadarNPC_1 = RGBAColor_RadarYellow_1;
  return LODWORD(RGBAColor_RadarYellow_1.a);
}

//----- (006F9060) --------------------------------------------------------  // acclient.c:781769
int _E152_4()
{
  RGBAColor_RadarPlayerKiller_1 = RGBAColor_RadarRed_1;
  return LODWORD(RGBAColor_RadarRed_1.a);
}

//----- (006F9090) --------------------------------------------------------  // acclient.c:781776
int _E154_23()
{
  RGBAColor_RadarPortal_1 = RGBAColor_RadarPurple_1;
  return LODWORD(RGBAColor_RadarPurple_1.a);
}

//----- (006F90C0) --------------------------------------------------------  // acclient.c:781783
int _E156_19()
{
  RGBAColor_RadarSentinel_1 = RGBAColor_RadarCyan_1;
  return LODWORD(RGBAColor_RadarCyan_1.a);
}

//----- (006F90F0) --------------------------------------------------------  // acclient.c:781790
int _E158_5()
{
  RGBAColor_RadarVendor_1 = RGBAColor_RadarYellow_1;
  return LODWORD(RGBAColor_RadarYellow_1.a);
}

//----- (006F9120) --------------------------------------------------------  // acclient.c:781797
int _E160_24()
{
  RGBAColor_RadarFellowship_1 = RGBAColor_RadarBrightGreen_1;
  return LODWORD(RGBAColor_RadarBrightGreen_1.a);
}

//----- (006F9150) --------------------------------------------------------  // acclient.c:781804
int _E162_19()
{
  RGBAColor_RadarFellowshipLeader_1 = RGBAColor_RadarBrightGreen_1;
  return LODWORD(RGBAColor_RadarBrightGreen_1.a);
}

//----- (006F9180) --------------------------------------------------------  // acclient.c:781811
int _E164_6()
{
  RGBAColor_RadarPKLite_1 = RGBAColor_RadarPink_1;
  return LODWORD(RGBAColor_RadarPink_1.a);
}

//----- (006F91B0) --------------------------------------------------------  // acclient.c:781818
int _E169_18()
{
  return atexit(_E170_21);
}

//----- (006F91C0) --------------------------------------------------------  // acclient.c:781824
int sub_6F91C0()
{
  return atexit(nullsub_650);
}

