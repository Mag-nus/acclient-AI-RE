/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmRadarUI
   Object     : GAME\game_ui_misc\gmRadarUI.obj
   Functions  : 101
   Addresses  : 004D7530 - 007628A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004D7530) --------------------------------------------------------  // acclient.c:262610
void __thiscall RadarInfo::RadarInfo(RadarInfo *this, ACCWeenieObject *obj)
{
  this->object = obj;
  this->color = RGBAColor_Null_4;
  this->shape = 0;
}

//----- (004D7570) --------------------------------------------------------  // acclient.c:262618
void __thiscall RadarInfo::RadarInfo(RadarInfo *this)
{
  this->object = 0;
  this->color = RGBAColor_Null_4;
  this->shape = 0;
}

//----- (004D75B0) --------------------------------------------------------  // acclient.c:262626
UIElementMessageListenResult __thiscall gmRadarUI::ListenToElementMessage(gmRadarUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  UIElement *v3; // esi@1
  UIElementMessageListenResult result; // eax@4
  CPlayerSystem *v5; // eax@9
  CPlayerSystem *v6; // eax@10
  CPlayerSystem *v7; // eax@11
  unsigned int v8; // eax@14

  v2 = i_rMsg->idMessage;
  v3 = (UIElement *)this;
  if ( v2 == 24 )
  {
    if ( (gmRadarUI *)i_rMsg->pElement == this )
    {
      if ( i_rMsg->dwParam1 )
      {
        UIListener::RegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
        result = UIElement::ListenToElementMessage(v3, i_rMsg);
      }
      else
      {
        UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
        result = UIElement::ListenToElementMessage(v3, i_rMsg);
      }
      return result;
    }
    return UIElement::ListenToElementMessage(v3, i_rMsg);
  }
  if ( v2 != 25 )
    return UIElement::ListenToElementMessage(v3, i_rMsg);
  if ( i_rMsg->idElement != 268437017 )
  {
    if ( (gmRadarUI *)i_rMsg->pElement == this )
    {
      v8 = this->m_iidObjectUnderMouse;
      if ( v8 )
        ACCWeenieObject::SetSelectedObject(v8, 0);
    }
    return UIElement::ListenToElementMessage(v3, i_rMsg);
  }
  if ( !CPlayerSystem::GetPlayerSystem() )
    return UIElement::ListenToElementMessage(v3, i_rMsg);
  v5 = CPlayerSystem::GetPlayerSystem();
  if ( (unsigned __int8)PlayerModule::LockUI((PlayerModule *)&v5->playerModule.vfptr) )
  {
    v6 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetLockUI((PlayerModule *)&v6->playerModule.vfptr, 0);
  }
  else
  {
    v7 = CPlayerSystem::GetPlayerSystem();
    PlayerModule::SetLockUI((PlayerModule *)&v7->playerModule.vfptr, 1);
  }
  UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 0xDu, 0);
  return UIElement::ListenToElementMessage(v3, i_rMsg);
}

//----- (004D7680) --------------------------------------------------------  // acclient.c:262686
void __thiscall gmRadarUI::UpdateLockedStatus(gmRadarUI *this)
{
  gmRadarUI *v1; // esi@1
  CPlayerSystem *v2; // eax@2

  v1 = this;
  if ( CPlayerSystem::GetPlayerSystem()
    && (v2 = CPlayerSystem::GetPlayerSystem(),
        (unsigned __int8)PlayerModule::LockUI((PlayerModule *)&v2->playerModule.vfptr)) )
  {
    ((void (__stdcall *)(signed int))v1->m_pLockUIButton->vfptr[13].__vecDelDtor)(268435555);
    ((void (__stdcall *)(_DWORD))v1->m_pDragButton->vfptr[2].__vecDelDtor)(0);
  }
  else
  {
    ((void (__stdcall *)(signed int))v1->m_pLockUIButton->vfptr[13].__vecDelDtor)(268435556);
    ((void (__stdcall *)(signed int))v1->m_pDragButton->vfptr[2].__vecDelDtor)(1);
  }
}

//----- (004D76F0) --------------------------------------------------------  // acclient.c:262707
RGBAColor *__cdecl gmRadarUI::GetBlipColor(RGBAColor *result, ACCWeenieObject *i_obj)
{
  unsigned int v2; // ecx@2
  int v3; // eax@3
  RGBAColor *v4; // eax@5
  unsigned int v5; // eax@25
  float v6; // esi@25
  float v7; // ebx@25
  float v8; // ebp@25
  float v9; // edi@25
  ClientFellowshipSystem *pFellowSystem; // [sp+0h] [bp-4h]@34

  if ( !i_obj )
    goto LABEL_42;
  v2 = i_obj->pwd._bitfield;
  if ( (v2 & 0x80u) != 0 )
    goto LABEL_42;
  v3 = i_obj->pwd._blipColor;
  if ( v3 )
  {
    switch ( v3 )
    {
      case 1:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarBlue_0;
        break;
      case 2:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarGold_0;
        break;
      case 3:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarWhite_0;
        break;
      case 4:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarPurple_0;
        break;
      case 5:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarRed_0;
        break;
      case 6:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarPink_0;
        break;
      case 7:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarGreen_0;
        break;
      case 8:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarYellow_0;
        break;
      case 9:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarCyan_0;
        break;
      case 10:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarBrightGreen_0;
        break;
      default:
        v4 = result;
        COERCE_RGBACOLOR(result->r) = RGBAColor_RadarDefault_0;
        break;
    }
    return v4;
  }
  if ( v2 & 0x40000 )
  {
    v4 = result;
    COERCE_RGBACOLOR(result->r) = RGBAColor_RadarPortal_0;
    return v4;
  }
  if ( BYTE1(v2) & 2 )
  {
    v4 = result;
    COERCE_RGBACOLOR(result->r) = RGBAColor_RadarVendor_0;
    return v4;
  }
  if ( v2 & 0x10
    && ((int (__thiscall *)(ACCWeenieObject *))i_obj->vfptr[11].__vecDelDtor)(i_obj)
    && !((int (__thiscall *)(ACCWeenieObject *))i_obj->vfptr[4].__vecDelDtor)(i_obj) )
  {
    v4 = result;
    COERCE_RGBACOLOR(result->r) = RGBAColor_RadarCreature_0;
    return v4;
  }
  if ( !((int (__thiscall *)(ACCWeenieObject *))i_obj->vfptr[4].__vecDelDtor)(i_obj) )
  {
LABEL_42:
    v4 = result;
    COERCE_RGBACOLOR(result->r) = RGBAColor_RadarDefault_0;
    return v4;
  }
  v5 = i_obj->pwd._bitfield;
  v6 = RGBAColor_RadarDefault_0.r;
  v7 = RGBAColor_RadarDefault_0.b;
  v8 = RGBAColor_RadarDefault_0.a;
  v9 = RGBAColor_RadarDefault_0.g;
  if ( !(v5 & 0x100000) || v5 & 0x40 )
  {
    if ( ((int (*)(void))i_obj->vfptr[8].__vecDelDtor)() )
    {
      v6 = RGBAColor_RadarPlayerKiller_0.r;
      v9 = RGBAColor_RadarPlayerKiller_0.g;
      v7 = RGBAColor_RadarPlayerKiller_0.b;
      v8 = RGBAColor_RadarPlayerKiller_0.a;
    }
    else if ( ((int (*)(void))i_obj->vfptr[9].__vecDelDtor)() )
    {
      v6 = RGBAColor_RadarPKLite_0.r;
      v9 = RGBAColor_RadarPKLite_0.g;
      v7 = RGBAColor_RadarPKLite_0.b;
      v8 = RGBAColor_RadarPKLite_0.a;
    }
    else if ( i_obj->pwd._bitfield & 0x200000 )
    {
      v6 = RGBAColor_RadarCreature_0.r;
      v9 = RGBAColor_RadarCreature_0.g;
      v7 = RGBAColor_RadarCreature_0.b;
      v8 = RGBAColor_RadarCreature_0.a;
    }
  }
  else
  {
    v6 = RGBAColor_RadarAdmin_0.r;
    v9 = RGBAColor_RadarAdmin_0.g;
    v7 = RGBAColor_RadarAdmin_0.b;
    v8 = RGBAColor_RadarAdmin_0.a;
  }
  pFellowSystem = ClientFellowshipSystem::GetFellowshipSystem();
  if ( ClientFellowshipSystem::IsFellowshipLeader(pFellowSystem, i_obj->id) )
  {
    v6 = RGBAColor_RadarFellowshipLeader_0.r;
    v9 = RGBAColor_RadarFellowshipLeader_0.g;
    v7 = RGBAColor_RadarFellowshipLeader_0.b;
    v8 = RGBAColor_RadarFellowshipLeader_0.a;
  }
  else if ( ClientFellowshipSystem::IsFellow(pFellowSystem, i_obj->id) )
  {
    v6 = RGBAColor_RadarFellowship_0.r;
    v9 = RGBAColor_RadarFellowship_0.g;
    v7 = RGBAColor_RadarFellowship_0.b;
    v8 = RGBAColor_RadarFellowship_0.a;
  }
  v4 = result;
  result->r = v6;
  result->g = v9;
  result->b = v7;
  result->a = v8;
  return v4;
}

//----- (004D7B60) --------------------------------------------------------  // acclient.c:262863
int __stdcall gmRadarUI::GetBlipShape(ACCWeenieObject *i_obj)
{
  ClientFellowshipSystem *v2; // esi@3
  int result; // eax@4
  unsigned int v4; // eax@6
  HashBaseData<unsigned long> *v5; // eax@8
  HashBaseData<unsigned long> *v6; // esi@8

  if ( i_obj && SLOBYTE(i_obj->pwd._bitfield) >= 0 )
  {
    v2 = ClientFellowshipSystem::GetFellowshipSystem();
    if ( ClientFellowshipSystem::IsFellow(v2, i_obj->id) )
      return 6 - (ClientFellowshipSystem::IsFellowshipLeader(v2, i_obj->id) != 0);
    if ( SmartBox::smartbox )
      v4 = SmartBox::smartbox->player_id;
    else
      v4 = 0;
    v5 = ClientObjMaintSystem::GetWeenieObject(v4);
    v6 = v5;
    if ( !v5 )
      goto LABEL_20;
    if ( ACCWeenieObject::IsAllegianceMember(i_obj, (ACCWeenieObject *)v5) )
      return 2;
    if ( ((int (__thiscall *)(_DWORD))i_obj->vfptr[8].__vecDelDtor)(i_obj)
      && ((int (__thiscall *)(HashBaseData<unsigned long> *))v6->vfptr[8].__vecDelDtor)(v6)
      || ((int (__thiscall *)(_DWORD))i_obj->vfptr[9].__vecDelDtor)(i_obj)
      && ((int (__thiscall *)(HashBaseData<unsigned long> *))v6->vfptr[9].__vecDelDtor)(v6) )
      result = 3;
    else
LABEL_20:
      result = 4;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004D7C30) --------------------------------------------------------  // acclient.c:262903
void __stdcall gmRadarUI::DrawPoint(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x, y, x, y);
  }
}

//----- (004D7C70) --------------------------------------------------------  // acclient.c:262913
void __stdcall gmRadarUI::DrawEdges(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  RGBAColor *v5; // ebp@2

  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    v5 = color;
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x, y - 1, x, y - 1);
  }
  else
  {
    v5 = color;
  }
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, v5, x, y + 1, x, y + 1);
    if ( i_pSurface )
    {
      UISurface::PrepareSurface(i_pSurface);
      SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, v5, x - 1, y, x - 1, y);
    }
  }
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, v5, x + 1, y, x + 1, y);
  }
}

//----- (004D7D20) --------------------------------------------------------  // acclient.c:262945
void __stdcall gmRadarUI::DrawCorners(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  int v5; // ebx@1
  const int v6; // ebp@1
  const int v7; // ebx@3
  const int v8; // edi@3
  int ya; // [sp+20h] [bp+10h]@1

  v5 = y;
  v6 = y + 1;
  ya = x + 1;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, ya, v6, ya, v6);
  }
  v7 = v5 - 1;
  v8 = x - 1;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, v8, v7, v8, v7);
    if ( i_pSurface )
    {
      UISurface::PrepareSurface(i_pSurface);
      SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, v8, v6, v8, v6);
      if ( i_pSurface )
      {
        UISurface::PrepareSurface(i_pSurface);
        SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, ya, v7, ya, v7);
      }
    }
  }
}

//----- (004D7DE0) --------------------------------------------------------  // acclient.c:262981
void __stdcall gmRadarUI::DrawCross(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x, y, x, y);
  }
  gmRadarUI::DrawEdges(i_pSurface, color, x, y);
}

//----- (004D7E30) --------------------------------------------------------  // acclient.c:262992
void __stdcall gmRadarUI::DrawX(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x, y, x, y);
  }
  gmRadarUI::DrawCorners(i_pSurface, color, x, y);
}

//----- (004D7E80) --------------------------------------------------------  // acclient.c:263003
void __stdcall gmRadarUI::DrawTriangle(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  const int v5; // edi@3
  RGBAColor *v6; // ebp@4

  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x, y, x, y);
  }
  v5 = y + 1;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    v6 = color;
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x - 1, v5, x - 1, v5);
  }
  else
  {
    v6 = color;
  }
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, v6, x, v5, x, v5);
  }
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, v6, x + 1, v5, x + 1, v5);
  }
}

//----- (004D7F30) --------------------------------------------------------  // acclient.c:263037
void __stdcall gmRadarUI::DrawInvertedTriangle(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  const int v5; // edi@3
  RGBAColor *v6; // ebp@4

  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x, y, x, y);
  }
  v5 = y - 1;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    v6 = color;
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x - 1, v5, x - 1, v5);
  }
  else
  {
    v6 = color;
  }
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, v6, x, v5, x, v5);
  }
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, v6, x + 1, v5, x + 1, v5);
  }
}

//----- (004D7FE0) --------------------------------------------------------  // acclient.c:263071
void __stdcall gmRadarUI::DrawSelected(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  int v5; // edi@2
  int v6; // ebx@2

  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    v5 = y;
    v6 = x;
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, x - 2, y + 3, x + 2, y + 3);
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, v6 + 3, v5 - 2, v6 + 3, v5 + 2);
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, v6 - 2, v5 - 3, v6 + 2, v5 - 3);
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, v6 - 3, y - 2, v6 - 3, y + 2);
  }
}

//----- (004D80A0) --------------------------------------------------------  // acclient.c:263092
void __thiscall HashBaseIter<unsigned long>::Next(HashBaseIter<unsigned long> *this)
{
  HashBaseData<unsigned long> *v1; // eax@1
  HashBase<unsigned long> *v2; // edx@4
  unsigned int v3; // eax@5
  HashBaseData<unsigned long> *v4; // eax@6

  v1 = this->curPtr_;
  if ( v1 )
  {
    this->lastThisChain_ = v1;
    this->curPtr_ = v1->hash_next;
  }
  if ( !this->curPtr_ )
  {
    v2 = this->myHash_;
    while ( 1 )
    {
      v3 = this->curBucket_ + 1;
      this->lastThisChain_ = 0;
      this->curBucket_ = v3;
      if ( v3 >= v2->table_size )
        break;
      v4 = v2->buckets[v3];
      this->curPtr_ = v4;
      if ( v4 )
        return;
    }
    this->fEnd_ = 1;
  }
}

//----- (004D80F0) --------------------------------------------------------  // acclient.c:263125
char __thiscall SmartArray<RadarInfo,1>::RemoveUnOrdered(SmartArray<RadarInfo,1> *this, RadarInfo *i_rData)
{
  RadarInfo *v2; // edx@1
  unsigned int v3; // esi@1
  RadarInfo *v4; // edi@1
  char result; // al@4
  int v6; // [sp+10h] [bp-18h]@5
  RGBAColor v7; // [sp+14h] [bp-14h]@5
  int v8; // [sp+24h] [bp-4h]@5

  v2 = this->m_data;
  v3 = this->m_num;
  v4 = this->m_data;
  if ( this->m_data >= &this->m_data[v3] )
  {
LABEL_4:
    result = 0;
  }
  else
  {
    while ( v4->object != i_rData->object )
    {
      ++v4;
      if ( v4 >= &this->m_data[this->m_num] )
        goto LABEL_4;
    }
    this->m_num = v3 - 1;
    qmemcpy(v4, &v2[v3 - 1], 0x18u);
    v7 = RGBAColor_Null_4;
    v6 = 0;
    v8 = 0;
    qmemcpy(&this->m_data[this->m_num], &v6, sizeof(this->m_data[this->m_num]));
    result = 1;
  }
  return result;
}

//----- (004D81A0) --------------------------------------------------------  // acclient.c:263163
void __thiscall gmRadarUI::MoveTo(gmRadarUI *this, const int i_x, const int i_y)
{
  int v3; // ebx@1
  gmRadarUI *v4; // esi@1
  int v5; // edi@1
  UIRegion *v6; // eax@2
  int v7; // ebp@2
  UIRegion *v8; // eax@3
  int v9; // ebx@3
  UIRegion *v10; // eax@6
  int v11; // ebp@6
  UIRegion *v12; // eax@7
  int v13; // edi@7
  char *v14; // edi@10
  int v15; // ebx@10
  PlayerModule *v16; // edi@12
  int v17; // ebx@12
  BasePropertyDesc *v18; // ecx@15
  unsigned int v19; // edx@15
  BasePropertyValue *v20; // ecx@19
  unsigned int v21; // edx@19
  BasePropertyDesc *v22; // ecx@23
  unsigned int v23; // edx@23
  BasePropertyValue *v24; // ecx@27
  unsigned int v25; // edx@27
  BaseProperty propY; // [sp+10h] [bp-10h]@12
  BaseProperty propX; // [sp+18h] [bp-8h]@10

  v3 = i_x;
  v4 = this;
  v5 = i_y;
  if ( ((int (*)(void))this->vfptr[13].OnAction)() )
  {
    v6 = (UIRegion *)((int (__thiscall *)(gmRadarUI *))v4->vfptr[13].OnAction)(v4);
    v7 = UIRegion::GetWidth(v6);
    if ( i_x > v7 - UIRegion::GetWidth((UIRegion *)&v4->vfptr) )
    {
      v8 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
      v9 = UIRegion::GetWidth(v8);
      v3 = v9 - UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    }
    if ( v3 < 0 )
      v3 = 0;
    v10 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
    v11 = UIRegion::GetHeight(v10);
    if ( i_y > v11 - UIRegion::GetHeight((UIRegion *)&v4->vfptr) )
    {
      v12 = (UIRegion *)((int (__thiscall *)(_DWORD))v4->vfptr[13].OnAction)(v4);
      v13 = UIRegion::GetHeight(v12);
      v5 = v13 - UIRegion::GetHeight((UIRegion *)&v4->vfptr);
    }
    if ( v5 < 0 )
      v5 = 0;
  }
  UIElement::MoveTo((UIElement *)&v4->vfptr, v3, v5);
  v14 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
  propX.m_pcPropertyDesc = 0;
  propX.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&propX, 0x10000086u);
  v15 = v4->m_box.m_x0;
  if ( propX.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&propX);
    ((void (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v15);
  }
  v16 = (PlayerModule *)(v14 + 4);
  PlayerModule::SetChatWindowOption(v16, v4->m_eWindowID, &propX);
  propY.m_pcPropertyDesc = 0;
  propY.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&propY, 0x10000087u);
  v17 = v4->m_box.m_y0;
  if ( propY.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&propY);
    ((void (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v17);
  }
  PlayerModule::SetChatWindowOption(v16, v4->m_eWindowID, &propY);
  if ( (_DWORD)propY.m_pcPropertyDesc )
  {
    v18 = propY.m_pcPropertyDesc;
    v19 = propY.m_pcPropertyDesc->m_cRef - 1;
    propY.m_pcPropertyDesc->m_cRef = v19;
    if ( !v19 )
      ((void (__stdcall *)(_DWORD))v18->vfptr->__vecDelDtor)(1);
    propY.m_pcPropertyDesc = 0;
  }
  if ( propY.m_pcPropertyValue )
  {
    v20 = propY.m_pcPropertyValue;
    v21 = propY.m_pcPropertyValue->m_cRef - 1;
    propY.m_pcPropertyValue->m_cRef = v21;
    if ( !v21 )
      ((void (__stdcall *)(_DWORD))v20->vfptr->__vecDelDtor)(1);
    propY.m_pcPropertyValue = 0;
  }
  if ( (_DWORD)propX.m_pcPropertyDesc )
  {
    v22 = propX.m_pcPropertyDesc;
    v23 = propX.m_pcPropertyDesc->m_cRef - 1;
    propX.m_pcPropertyDesc->m_cRef = v23;
    if ( !v23 )
      ((void (__stdcall *)(_DWORD))v22->vfptr->__vecDelDtor)(1);
    propX.m_pcPropertyDesc = 0;
  }
  if ( propX.m_pcPropertyValue )
  {
    v24 = propX.m_pcPropertyValue;
    v25 = propX.m_pcPropertyValue->m_cRef - 1;
    propX.m_pcPropertyValue->m_cRef = v25;
    if ( !v25 )
      ((void (__stdcall *)(_DWORD))v24->vfptr->__vecDelDtor)(1);
  }
}

//----- (004D8390) --------------------------------------------------------  // acclient.c:263278
void __thiscall gmRadarUI::RemoveObject(gmRadarUI *this, ACCWeenieObject *i_pObj)
{
  gmRadarUI *v2; // esi@1
  NoticeHandler *v3; // eax@3
  RadarInfo i_rData; // [sp+8h] [bp-18h]@5

  v2 = this;
  if ( i_pObj )
  {
    if ( this )
      v3 = (NoticeHandler *)&this->vfptr;
    else
      v3 = 0;
    i_pObj->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)&i_pObj->vfptr, v3);
    i_rData.color.g = RGBAColor_Null_4.g;
    LODWORD(i_rData.color.r) = (_DWORD)RGBAColor_Null_4.r;
    i_rData.object = i_pObj;
    i_rData.color.b = RGBAColor_Null_4.b;
    i_rData.color.a = RGBAColor_Null_4.a;
    i_rData.shape = 0;
    SmartArray<RadarInfo,1>::RemoveUnOrdered(&v2->m_aRadarInfos, &i_rData);
  }
}

//----- (004D8410) --------------------------------------------------------  // acclient.c:263303
RGBAColor *__cdecl gmRadarUI::GetBlipColor(RGBAColor *result, unsigned int i_iid)
{
  HashBaseData<unsigned long> *v2; // eax@1

  v2 = ClientObjMaintSystem::GetWeenieObject(i_iid);
  gmRadarUI::GetBlipColor(result, (ACCWeenieObject *)v2);
  return result;
}

//----- (004D8430) --------------------------------------------------------  // acclient.c:263313
void __stdcall gmRadarUI::DrawHollow(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  gmRadarUI::DrawEdges(i_pSurface, color, x, y);
  gmRadarUI::DrawCorners(i_pSurface, color, x, y);
}

//----- (004D8470) --------------------------------------------------------  // acclient.c:263320
void __stdcall gmRadarUI::DrawXBox(UISurface *i_pSurface, RGBAColor *color, int x, int y)
{
  int v5; // ebx@1
  const int v6; // ebp@1
  const int v7; // ebx@3
  const int v8; // ebp@5
  int xa; // [sp+1Ch] [bp+Ch]@1

  v5 = x;
  gmRadarUI::DrawEdges(i_pSurface, color, x, y);
  gmRadarUI::DrawCorners(i_pSurface, color, x, y);
  v6 = y - 2;
  xa = x - 2;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, xa, v6, xa, v6);
  }
  v7 = v5 + 2;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, v7, v6, v7, v6);
  }
  v8 = y + 2;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, xa, v8, xa, v8);
    if ( i_pSurface )
    {
      UISurface::PrepareSurface(i_pSurface);
      SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, color, v7, v8, v7, v8);
    }
  }
}

//----- (004D8540) --------------------------------------------------------  // acclient.c:263358
void __thiscall gmRadarUI::UpdateFromPlayerModule(gmRadarUI *this)
{
  gmRadarUI *v1; // edi@1
  char *v2; // esi@1
  PlayerModule *v3; // esi@4
  unsigned int v4; // ST00_4@4
  int y; // [sp+Ch] [bp-18h]@9
  int x; // [sp+10h] [bp-14h]@7
  BaseProperty propY; // [sp+14h] [bp-10h]@4
  BaseProperty propX; // [sp+1Ch] [bp-8h]@4

  v1 = this;
  v2 = (char *)&CPlayerSystem::GetPlayerSystem()->playerModule;
  if ( v1->m_eWindowID && CPlayerSystem::GetPlayerSystem() && !CPlayerSystem::GetPlayerSystem()->m_layoutFromFile )
  {
    v3 = (PlayerModule *)(v2 + 4);
    v4 = v1->m_eWindowID;
    propX.m_pcPropertyDesc = 0;
    propX.m_pcPropertyValue = 0;
    propY.m_pcPropertyDesc = 0;
    propY.m_pcPropertyValue = 0;
    if ( PlayerModule::InqChatWindowOption(v3, v4, 0x10000086u, &propX)
      && PlayerModule::InqChatWindowOption(v3, v1->m_eWindowID, 0x10000087u, &propY)
      && propX.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propX.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&x)
      && propY.m_pcPropertyValue
      && (unsigned __int8)((int (__stdcall *)(_DWORD))propY.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&y) )
      ((void (__thiscall *)(gmRadarUI *, int, int))v1->vfptr[3].OnLoseFocus)(v1, x, y);
    BaseProperty::~BaseProperty(&propY);
    BaseProperty::~BaseProperty(&propX);
  }
  gmRadarUI::UpdateLockedStatus(v1);
}

//----- (004D8630) --------------------------------------------------------  // acclient.c:263393
void __thiscall SmartArray<RadarInfo,1>::Reset(SmartArray<RadarInfo,1> *this)
{
  SmartArray<RadarInfo,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@5
  int v7; // edx@5
  void *v8; // edi@6
  void *v9; // edi@6
  int v10; // [sp+8h] [bp-18h]@5
  RGBAColor v11; // [sp+Ch] [bp-14h]@6
  int v12; // [sp+1Ch] [bp-4h]@5

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v10 = 0;
      v12 = 0;
      v6 = 24 * v4;
      v7 = v5 + 1;
      do
      {
        v8 = v1->m_data;
        v11 = RGBAColor_Null_4;
        v9 = (char *)v8 + v6;
        v6 -= 24;
        --v7;
        qmemcpy(v9, &v10, 0x18u);
      }
      while ( v7 );
    }
  }
}

//----- (004D86E0) --------------------------------------------------------  // acclient.c:263443
char __thiscall SmartArray<RadarInfo,1>::grow(SmartArray<RadarInfo,1> *this, unsigned int i_nSize)
{
  SmartArray<RadarInfo,1> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // eax@5
  RadarInfo *v6; // ebp@5
  int v7; // ecx@7
  int v8; // eax@8
  unsigned int v9; // edx@8
  const void *v10; // esi@9
  void *v11; // edi@9

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<RadarInfo,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](24 * i_nSize);
    v6 = (RadarInfo *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(v5, 0x18u, i_nSize, (void *(__thiscall *)(void *))RadarInfo::RadarInfo);
      if ( v2->m_data )
      {
        v7 = v2->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          v9 = v2->m_num;
          do
          {
            v10 = &v2->m_data[v8];
            v11 = &v6[v8];
            --v8;
            --v9;
            qmemcpy(v11, v10, 0x18u);
          }
          while ( v9 );
          v3 = i_nSize;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = v6;
      v2->m_sizeAndDeallocate = v3 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (004D87A0) --------------------------------------------------------  // acclient.c:263501
void __userpurge gmRadarUI::gmRadarUI(gmRadarUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmRadarUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)QualityChangeHandler::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmRadarUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmRadarUI::vftable;
  v4->vfptr = (QualityChangeHandlerVtbl *)gmRadarUI::vftable;
  v4->m_fRadarRange = RADAR_OUTDOOR_RADIUS_0;
  v4->m_aRadarInfos.m_data = 0;
  v4->m_aRadarInfos.m_sizeAndDeallocate = 0;
  v4->m_aRadarInfos.m_num = 0;
  v4->m_iidObjectUnderMouse = 0;
  LODWORD(v4->m_fPlayerHeading) = 0;
  Vector2::Vector2(&v4->m_vecCenterPoint, 0.0, 0.0);
  v4->m_nRadarRadius = 0;
  LODWORD(v4->m_fNorthTokenMagnitude) = 0;
  LODWORD(v4->m_fEastTokenMagnitude) = 0;
  LODWORD(v4->m_fSouthTokenMagnitude) = 0;
  LODWORD(v4->m_fWestTokenMagnitude) = 0;
  v4->m_pNorthToken = 0;
  v4->m_pEastToken = 0;
  v4->m_pSouthToken = 0;
  v4->m_pWestToken = 0;
  v4->m_pCoordinateContainerField = 0;
  v4->m_pCombinedCoordsText = 0;
  v4->m_pXCoordText = 0;
  v4->m_pYCoordText = 0;
  v4->m_pLockUIButton = 0;
  v4->m_pDragButton = 0;
  LODWORD(v4->m_ttNextUpdateTime) = 0;
  HIDWORD(v4->m_ttNextUpdateTime) = 0;
  LODWORD(v4->m_fCurXCoord) = 0;
  HIDWORD(v4->m_fCurXCoord) = 0;
  LODWORD(v4->m_fCurYCoord) = 0;
  HIDWORD(v4->m_fCurYCoord) = 0;
  v4->m_eWindowID = 0;
}
// 7A5AA4: using guessed type void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 7BD90C: using guessed type void (__thiscall *gmRadarUI::vftable[2])(gmRadarUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7BD918: using guessed type bool (__thiscall *gmRadarUI::vftable)(DBCache *this);
// 7BDBC0: using guessed type int (__thiscall *gmRadarUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004D88B0) --------------------------------------------------------  // acclient.c:263549
gmRadarUI *__thiscall gmRadarUI::DynamicCast(gmRadarUI *this, unsigned int i_eType)
{
  gmRadarUI *result; // eax@1

  result = this;
  if ( i_eType != 268435472 )
    result = (gmRadarUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004D88E0) --------------------------------------------------------  // acclient.c:263566
void __thiscall gmRadarUI::~gmRadarUI(gmRadarUI *this)
{
  gmRadarUI *v1; // esi@1
  NoticeHandler *v2; // ebx@1
  char *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmRadarUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmRadarUI::vftable;
  this->vfptr = (QualityChangeHandlerVtbl *)gmRadarUI::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  (*(void (__stdcall **)(char *))&QualityRegistrar::s_pQR->vfptr->gap14[0])(v3);
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v2);
  CAsyncStateHandler::OnStateHandlerInit((Logger::ILoggingOutputHandler *)&v1->m_vecCenterPoint);
  if ( (v1->m_aRadarInfos.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_aRadarInfos.m_data);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7BD90C: using guessed type void (__thiscall *gmRadarUI::vftable[2])(gmRadarUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32);
// 7BD918: using guessed type bool (__thiscall *gmRadarUI::vftable)(DBCache *this);
// 7BDBC0: using guessed type int (__thiscall *gmRadarUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004D8970) --------------------------------------------------------  // acclient.c:263597
void __usercall gmRadarUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmRadarUI *v3; // eax@1

  v3 = (gmRadarUI *)operator new(0x680u);
  if ( v3 )
    gmRadarUI::gmRadarUI(v3, a1, _layout, _full_desc);
}

//----- (004D89A0) --------------------------------------------------------  // acclient.c:263607
void __thiscall gmRadarUI::RecvNotice_BeingDeleted(gmRadarUI *this, CWeenieObject *i_obj)
{
  gmRadarUI::RemoveObject((gmRadarUI *)((char *)this - 1528), (ACCWeenieObject *)i_obj);
}

//----- (004D89B0) --------------------------------------------------------  // acclient.c:263613
void __thiscall gmRadarUI::UpdateRadarLook(gmRadarUI *this, ACCWeenieObject *i_pObj)
{
  gmRadarUI *v2; // ebx@1
  unsigned int v3; // ecx@2
  unsigned int v4; // eax@2
  RadarInfo *v5; // esi@3
  RGBAColor *v6; // eax@7
  int v7; // ecx@7
  RGBAColor result; // [sp+8h] [bp-10h]@7

  v2 = this;
  if ( i_pObj )
  {
    v3 = this->m_aRadarInfos.m_num;
    v4 = 0;
    if ( v3 )
    {
      v5 = v2->m_aRadarInfos.m_data;
      while ( v5->object != i_pObj )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          return;
      }
      v6 = gmRadarUI::GetBlipColor(&result, i_pObj);
      v7 = (int)&v5->color;
      *(_DWORD *)v7 = LODWORD(v6->r);
      *(_DWORD *)(v7 + 4) = LODWORD(v6->g);
      *(_DWORD *)(v7 + 8) = LODWORD(v6->b);
      *(_DWORD *)(v7 + 12) = LODWORD(v6->a);
      v5->shape = gmRadarUI::GetBlipShape(i_pObj);
    }
  }
}

//----- (004D8A30) --------------------------------------------------------  // acclient.c:263650
void __stdcall gmRadarUI::DrawBlip(UISurface *i_pSurface, RadarInfo *info, float intensity, int x, int y, bool selected)
{
  RadarBlipShape v7; // eax@2
  float v8; // edx@2
  float v9; // ecx@2
  RGBAColor color; // [sp+4h] [bp-10h]@2

  if ( !ClientUISystem::GetUISystem()->m_bRadarBlank )
  {
    v7 = info->shape;
    color.r = info->color.r;
    color.g = info->color.g;
    v8 = info->color.b;
    v9 = info->color.a;
    color.r = color.r * intensity;
    color.g = color.g * intensity;
    color.b = v8 * intensity;
    color.a = v9;
    switch ( v7 )
    {
      case 1:
        gmRadarUI::DrawPoint(i_pSurface, &color, x, y);
        break;
      case 2:
        gmRadarUI::DrawHollow(i_pSurface, &color, x, y);
        break;
      case 4:
        gmRadarUI::DrawCross(i_pSurface, &color, x, y);
        break;
      case 3:
        gmRadarUI::DrawX(i_pSurface, &color, x, y);
        break;
      case 7:
        gmRadarUI::DrawXBox(i_pSurface, &color, x, y);
        break;
      case 5:
        gmRadarUI::DrawTriangle(i_pSurface, &color, x, y);
        break;
      case 6:
        gmRadarUI::DrawInvertedTriangle(i_pSurface, &color, x, y);
        break;
      default:
        break;
    }
    if ( selected )
      gmRadarUI::DrawSelected(i_pSurface, &color, x, y);
  }
}

//----- (004D8B60) --------------------------------------------------------  // acclient.c:263700
gmRadarUI *__thiscall gmRadarUI::scalar_deleting_destructor(gmRadarUI *this, unsigned int a2)
{
  gmRadarUI *v2; // esi@1

  v2 = this;
  gmRadarUI::~gmRadarUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D8B80) --------------------------------------------------------  // acclient.c:263712
void __cdecl gmRadarUI::Register()
{
  UIElement::RegisterElementClass(0x10000010u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmRadarUI::Create);
}

//----- (004D8BA0) --------------------------------------------------------  // acclient.c:263718
void __thiscall gmRadarUI::RecvNotice_ChangeRadarLook(gmRadarUI *this, CWeenieObject *i_obj)
{
  gmRadarUI::UpdateRadarLook((gmRadarUI *)((char *)this - 1528), (ACCWeenieObject *)i_obj);
}

//----- (004D8BB0) --------------------------------------------------------  // acclient.c:263724
void __thiscall gmRadarUI::OnQualityChanged(gmRadarUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  gmRadarUI *v4; // edi@1
  unsigned int v5; // eax@2
  HashSetData<UIElement *> *v6; // ebp@5
  int v7; // ebx@6
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *v8; // esi@7
  void *(__thiscall *v9)(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *, unsigned int); // ecx@7
  int v10; // esi@7
  RGBAColor *v11; // eax@9
  int v12; // ecx@9
  RGBAColor result; // [sp+8h] [bp-10h]@9

  v4 = this;
  if ( SmartBox::smartbox )
    v5 = SmartBox::smartbox->player_id;
  else
    v5 = 0;
  if ( cwobj->id == v5 )
  {
    v6 = 0;
    if ( this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] )
    {
      v7 = 0;
      do
      {
        v8 = v4->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
        v9 = v8[v7].__vecDelDtor;
        v10 = (int)&v8[v7];
        if ( v9 )
        {
          if ( (*(int (**)(void))(*(_DWORD *)v9 + 16))() )
          {
            v11 = gmRadarUI::GetBlipColor(&result, *(ACCWeenieObject **)v10);
            v12 = v10 + 4;
            *(_DWORD *)v12 = LODWORD(v11->r);
            *(_DWORD *)(v12 + 4) = LODWORD(v11->g);
            *(_DWORD *)(v12 + 8) = LODWORD(v11->b);
            *(_DWORD *)(v12 + 12) = LODWORD(v11->a);
            *(_DWORD *)(v10 + 20) = gmRadarUI::GetBlipShape(*(ACCWeenieObject **)v10);
          }
        }
        v6 = (HashSetData<UIElement *> *)((char *)v6 + 1);
        v7 += 6;
      }
      while ( v6 < v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] );
    }
  }
  else
  {
    gmRadarUI::UpdateRadarLook((gmRadarUI *)((char *)this - 1532), (ACCWeenieObject *)cwobj);
  }
}

//----- (004D8C60) --------------------------------------------------------  // acclient.c:263779
void __thiscall gmRadarUI::OnQualityRemoved(gmRadarUI *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  gmRadarUI::UpdateRadarLook((gmRadarUI *)((char *)this - 1532), (ACCWeenieObject *)cwobj);
}

//----- (004D8C80) --------------------------------------------------------  // acclient.c:263785
void __thiscall gmRadarUI::UpdateCoordinates(gmRadarUI *this)
{
  gmRadarUI *v1; // esi@1
  CPlayerSystem *v2; // eax@1
  CPlayerSystem *v3; // edi@1
  int v4; // edx@6
  int v5; // ecx@6
  UIElement_Text *v6; // eax@6
  int v7; // edx@6
  unsigned __int16 *v8; // edx@8
  unsigned __int16 *v9; // ecx@12
  unsigned __int16 *v10; // ecx@24
  unsigned __int16 *v11; // ecx@33
  UIElement *v12; // ecx@40
  int v13; // edi@40
  UIElement_Text *v14; // ecx@42
  UIElement_Text *v15; // ecx@44
  UIElement_Text *v16; // ecx@46
  double strXCoord; // [sp+8h] [bp-28h]@16
  int bCoordinatesVisible; // [sp+14h] [bp-1Ch]@2
  long double y; // [sp+18h] [bp-18h]@3
  long double x; // [sp+20h] [bp-10h]@3
  long double v21; // [sp+28h] [bp-8h]@19

  v1 = this;
  v2 = CPlayerSystem::GetPlayerSystem();
  v3 = v2;
  if ( v2 )
  {
    LOBYTE(bCoordinatesVisible) = 0;
    if ( (unsigned __int8)PlayerModule::CoordinatesOnRadar((PlayerModule *)&v2->playerModule.vfptr) )
    {
      x = 0.0;
      y = 0.0;
      if ( CPlayerSystem::InqPlayerCoords(v3, &x, &y) )
      {
        LOBYTE(bCoordinatesVisible) = 1;
        if ( x != v1->m_fCurXCoord || y != v1->m_fCurYCoord )
        {
          v4 = LODWORD(x);
          v5 = LODWORD(y);
          HIDWORD(v1->m_fCurXCoord) = HIDWORD(x);
          v6 = v1->m_pCombinedCoordsText;
          LODWORD(v1->m_fCurXCoord) = v4;
          v7 = HIDWORD(y);
          LODWORD(v1->m_fCurYCoord) = v5;
          HIDWORD(v1->m_fCurYCoord) = v7;
          if ( v6 )
          {
            if ( x >= 0.0 )
            {
              v8 = L"E";
              if ( x <= 0.0 )
                v8 = &word_794320;
            }
            else
            {
              v8 = L"W";
            }
            if ( y >= 0.0 )
            {
              v9 = L"N";
              if ( y <= 0.0 )
                v9 = &word_794320;
            }
            else
            {
              v9 = L"S";
            }
            if ( x < 0.0 )
              strXCoord = -x;
            else
              strXCoord = x;
            if ( y < 0.0 )
              v21 = -y;
            else
              v21 = y;
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&strXCoord,
              0,
              L"%.1f%s,%.1f%s",
              v21,
              v9,
              strXCoord,
              v8);
            UIElement_Text::SetText(v1->m_pCombinedCoordsText, (PStringBase<unsigned short> *)&strXCoord);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strXCoord);
          }
          if ( v1->m_pYCoordText )
          {
            if ( y >= 0.0 )
            {
              v10 = L"N";
              if ( y <= 0.0 )
                v10 = &word_794320;
            }
            else
            {
              v10 = L"S";
            }
            if ( y < 0.0 )
              v21 = -y;
            else
              v21 = y;
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&strXCoord,
              0,
              L"%.1f%s",
              v21,
              v10);
            UIElement_Text::SetText(v1->m_pYCoordText, (PStringBase<unsigned short> *)&strXCoord);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strXCoord);
          }
          if ( v1->m_pXCoordText )
          {
            if ( x >= 0.0 )
            {
              v11 = L"E";
              if ( x <= 0.0 )
                v11 = &word_794320;
            }
            else
            {
              v11 = L"W";
            }
            if ( x < 0.0 )
              v21 = -x;
            else
              v21 = x;
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (PStringBase<unsigned short> *)&strXCoord,
              0,
              L"%.1f%s",
              v21,
              v11);
            UIElement_Text::SetText(v1->m_pXCoordText, (PStringBase<unsigned short> *)&strXCoord);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strXCoord);
          }
        }
      }
    }
    v12 = v1->m_pCoordinateContainerField;
    v13 = bCoordinatesVisible;
    if ( v12 )
      ((void (__stdcall *)(int))v12->vfptr[2].__vecDelDtor)(bCoordinatesVisible);
    v14 = v1->m_pCombinedCoordsText;
    if ( v14 )
      ((void (__stdcall *)(int))v14->vfptr[2].__vecDelDtor)(v13);
    v15 = v1->m_pXCoordText;
    if ( v15 )
      ((void (__stdcall *)(int))v15->vfptr[2].__vecDelDtor)(v13);
    v16 = v1->m_pYCoordText;
    if ( v16 )
      ((void (__stdcall *)(int))v16->vfptr[2].__vecDelDtor)(v13);
    ((void (__stdcall *)(signed int))v1->m_pLockUIButton->vfptr[2].__vecDelDtor)(1);
  }
}
// 7A659C: using guessed type wchar_t aN_1[2];
// 7A65A0: using guessed type wchar_t aS_9[2];
// 7A65A4: using guessed type wchar_t aE[2];
// 7A65A8: using guessed type wchar_t aW_0[2];

//----- (004D9000) --------------------------------------------------------  // acclient.c:263948
char __thiscall SmartArray<RadarInfo,1>::AddToEnd(SmartArray<RadarInfo,1> *this, RadarInfo *i_rData)
{
  SmartArray<RadarInfo,1> *v2; // ebx@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<RadarInfo,1>::grow(v2, v4)) != 0) )
  {
    qmemcpy(&v2->m_data[v2->m_num++], i_rData, sizeof(v2->m_data[v2->m_num++]));
    result = 1;
  }
  return result;
}

//----- (004D9060) --------------------------------------------------------  // acclient.c:263968
void __thiscall gmRadarUI::UpdateCompassTokens(gmRadarUI *this)
{
  gmRadarUI *v1; // esi@1
  InterfaceSystem *v2; // eax@1
  float v3; // edi@1
  int v4; // ebp@3
  float v5; // edi@5
  CPhysicsObj *v6; // ecx@7
  double v7; // st7@9
  UIRegion *v8; // ecx@10
  IInputActionCallbackVtbl *v9; // ebp@11
  long double v10; // st7@11
  UIRegion *v11; // ecx@11
  int v12; // ST08_4@11
  unsigned __int64 v13; // rax@11
  UIRegion *v14; // ecx@12
  IInputActionCallbackVtbl *v15; // ebp@13
  long double v16; // st7@13
  UIRegion *v17; // ecx@13
  int v18; // ST08_4@13
  unsigned __int64 v19; // rax@13
  UIRegion *v20; // ecx@14
  IInputActionCallbackVtbl *v21; // ebp@15
  UIRegion *v22; // ecx@15
  int v23; // ST08_4@15
  unsigned __int64 v24; // rax@15
  UIRegion *v25; // ecx@16
  IInputActionCallbackVtbl *v26; // ebx@17
  long double v27; // st7@17
  UIRegion *v28; // ecx@17
  int v29; // ST08_4@17
  unsigned __int64 v30; // rax@17
  int v31; // [sp+0h] [bp-2Ch]@1
  float heading_from_north; // [sp+18h] [bp-14h]@1
  float west_Xcoord; // [sp+1Ch] [bp-10h]@1
  int v34; // [sp+20h] [bp-Ch]@1
  float v35; // [sp+24h] [bp-8h]@3
  float north_Xcoord; // [sp+28h] [bp-4h]@1

  v1 = this;
  heading_from_north = 0.0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, (TResult *)&north_Xcoord, &PlayerDesc_ClassType_17, (Interface **)&heading_from_north);
  v31 = LODWORD(heading_from_north);
  v3 = heading_from_north;
  west_Xcoord = 0.0;
  v34 = 0;
  if ( heading_from_north != 0.0 )
    (*(void (__thiscall **)(_DWORD))(*LODWORD(heading_from_north) + 16))(LODWORD(heading_from_north));
  v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&west_Xcoord, (int)&v35, v31, 0);
  if ( v3 != 0.0 )
    (*(void (__thiscall **)(float))(*LODWORD(v3) + 20))(LODWORD(v3));
  v5 = west_Xcoord;
  if ( west_Xcoord != 0.0 )
  {
    if ( v4 < 0 )
      goto LABEL_21;
    v6 = SmartBox::smartbox->player;
    if ( !v6 )
    {
      (*(void (__thiscall **)(_DWORD))(*LODWORD(west_Xcoord) + 20))(LODWORD(west_Xcoord));
      return;
    }
    v7 = CPhysicsObj::get_heading(v6);
    if ( v7 == v1->m_fPlayerHeading )
      goto LABEL_21;
    v8 = (UIRegion *)&v1->m_pNorthToken->vfptr;
    v1->m_fPlayerHeading = v7;
    heading_from_north = v7 * 0.017453292;
    if ( v8 )
    {
      v9 = v8->vfptr;
      v10 = heading_from_north + 3.141592653589793;
      north_Xcoord = sin(v10) * v1->m_fNorthTokenMagnitude;
      v35 = cos(v10) * v1->m_fNorthTokenMagnitude + v1->m_vecCenterPoint.y;
      west_Xcoord = COERCE_FLOAT(UIRegion::GetHeight(v8));
      v11 = (UIRegion *)&v1->m_pNorthToken->vfptr;
      v12 = (unsigned __int64)(v35 - (double)SLODWORD(west_Xcoord) * 0.5);
      v35 = north_Xcoord + v1->m_vecCenterPoint.x;
      north_Xcoord = COERCE_FLOAT(UIRegion::GetWidth(v11));
      v13 = (unsigned __int64)(v35 - (double)SLODWORD(north_Xcoord) * 0.5);
      ((void (__fastcall *)(UIElement *, _DWORD, _DWORD, int))v9[3].OnLoseFocus)(
        v1->m_pNorthToken,
        HIDWORD(v13),
        v13,
        v12);
    }
    v14 = (UIRegion *)&v1->m_pEastToken->vfptr;
    if ( v14 )
    {
      v15 = v14->vfptr;
      v16 = heading_from_north + 1.5707964;
      west_Xcoord = sin(v16) * v1->m_fEastTokenMagnitude;
      v35 = cos(v16) * v1->m_fEastTokenMagnitude + v1->m_vecCenterPoint.y;
      north_Xcoord = COERCE_FLOAT(UIRegion::GetHeight(v14));
      v17 = (UIRegion *)&v1->m_pEastToken->vfptr;
      v18 = (unsigned __int64)(v35 - (double)SLODWORD(north_Xcoord) * 0.5);
      v35 = west_Xcoord + v1->m_vecCenterPoint.x;
      north_Xcoord = COERCE_FLOAT(UIRegion::GetWidth(v17));
      v19 = (unsigned __int64)(v35 - (double)SLODWORD(north_Xcoord) * 0.5);
      ((void (__fastcall *)(UIElement *, _DWORD, _DWORD, int))v15[3].OnLoseFocus)(
        v1->m_pEastToken,
        HIDWORD(v19),
        v19,
        v18);
    }
    v20 = (UIRegion *)&v1->m_pSouthToken->vfptr;
    if ( v20 )
    {
      v21 = v20->vfptr;
      west_Xcoord = sin(heading_from_north) * v1->m_fSouthTokenMagnitude;
      v35 = cos(heading_from_north) * v1->m_fSouthTokenMagnitude + v1->m_vecCenterPoint.y;
      north_Xcoord = COERCE_FLOAT(UIRegion::GetHeight(v20));
      v22 = (UIRegion *)&v1->m_pSouthToken->vfptr;
      v23 = (unsigned __int64)(v35 - (double)SLODWORD(north_Xcoord) * 0.5);
      v35 = west_Xcoord + v1->m_vecCenterPoint.x;
      north_Xcoord = COERCE_FLOAT(UIRegion::GetWidth(v22));
      v24 = (unsigned __int64)(v35 - (double)SLODWORD(north_Xcoord) * 0.5);
      ((void (__fastcall *)(UIElement *, _DWORD, _DWORD, int))v21[3].OnLoseFocus)(
        v1->m_pSouthToken,
        HIDWORD(v24),
        v24,
        v23);
    }
    v25 = (UIRegion *)&v1->m_pWestToken->vfptr;
    if ( v25 )
    {
      v26 = v25->vfptr;
      v27 = heading_from_north + 4.712389;
      west_Xcoord = sin(v27) * v1->m_fWestTokenMagnitude;
      v35 = cos(v27) * v1->m_fWestTokenMagnitude + v1->m_vecCenterPoint.y;
      north_Xcoord = COERCE_FLOAT(UIRegion::GetHeight(v25));
      v28 = (UIRegion *)&v1->m_pWestToken->vfptr;
      v29 = (unsigned __int64)(v35 - (double)SLODWORD(north_Xcoord) * 0.5);
      v35 = west_Xcoord + v1->m_vecCenterPoint.x;
      north_Xcoord = COERCE_FLOAT(UIRegion::GetWidth(v28));
      v30 = (unsigned __int64)(v35 - (double)SLODWORD(north_Xcoord) * 0.5);
      ((void (__fastcall *)(UIElement *, _DWORD, _DWORD, int))v26[3].OnLoseFocus)(
        v1->m_pWestToken,
        HIDWORD(v30),
        v30,
        v29);
      (*(void (__thiscall **)(float))(*LODWORD(v5) + 20))(LODWORD(v5));
    }
    else
    {
LABEL_21:
      (*(void (__thiscall **)(_DWORD))(*LODWORD(v5) + 20))(LODWORD(v5));
    }
  }
}

//----- (004D9380) --------------------------------------------------------  // acclient.c:264121
void __thiscall gmRadarUI::DrawObjects(gmRadarUI *this, UISurface *i_pSurface)
{
  gmRadarUI *v2; // esi@1
  unsigned int v3; // eax@1
  double v4; // st7@1
  RadarInfo *v5; // edi@3
  ACCWeenieObject *v6; // eax@3
  RadarInfo *v7; // edi@3
  InterfaceSystem *v8; // eax@4
  int v9; // ebp@4
  CObjectMaint *v10; // ebx@8
  HashBaseData<unsigned long> *v11; // eax@10
  double v12; // st7@15
  double v13; // st7@15
  int v14; // ebp@15
  unsigned __int64 v15; // rax@15
  double v16; // st7@15
  double v17; // st6@15
  double v18; // st7@17
  int v19; // ebx@19
  unsigned int v20; // ebx@19
  int v21; // edi@19
  unsigned int v22; // eax@19
  int v23; // eax@19
  ACCWeenieObject *v24; // edi@21
  unsigned int v25; // edx@21
  InterfaceVtbl *v26; // eax@25
  bool v27; // cf@29
  int v28; // [sp-8h] [bp-F4h]@4
  int y; // [sp+10h] [bp-DCh]@4
  float v30; // [sp+14h] [bp-D8h]@15
  unsigned int v31; // [sp+18h] [bp-D4h]@2
  ACCWeenieObject *object; // [sp+1Ch] [bp-D0h]@3
  unsigned int index; // [sp+20h] [bp-CCh]@1
  PStringBase<unsigned short> strObjectName; // [sp+24h] [bp-C8h]@21
  float intensity; // [sp+28h] [bp-C4h]@23
  InterfacePtr<CObjectMaint> objMaint; // [sp+2Ch] [bp-C0h]@4
  _STL::pair<unsigned long,unsigned long> curClosestObject; // [sp+34h] [bp-B8h]@1
  AC1Legacy::Vector3 v; // [sp+3Ch] [bp-B0h]@13
  float fSquaredRadarRange; // [sp+48h] [bp-A4h]@1
  RadarInfo *info; // [sp+4Ch] [bp-A0h]@3
  int x; // [sp+50h] [bp-9Ch]@15
  char v42; // [sp+54h] [bp-98h]@6
  TResult result; // [sp+58h] [bp-94h]@4
  StringInfo siObjectName; // [sp+5Ch] [bp-90h]@21

  v2 = this;
  v3 = this->m_aRadarInfos.m_num;
  v4 = this->m_fRadarRange - 1.0;
  this->m_iidObjectUnderMouse = 0;
  curClosestObject.first = 0;
  curClosestObject.second = -1;
  index = 0;
  fSquaredRadarRange = v4 * v4;
  if ( !v3 )
  {
LABEL_32:
    if ( !v2->m_iidObjectUnderMouse )
    {
      *((_DWORD *)&v2->0 + 41) &= 0xFFFFFFDF;
      UIElement::ClearTooltip((UIElement *)&v2->vfptr);
    }
    return;
  }
  v31 = 0;
  while ( 1 )
  {
    v5 = v2->m_aRadarInfos.m_data;
    v6 = v5[v31 / 0x18].object;
    v7 = &v5[v31 / 0x18];
    info = v7;
    object = v6;
    if ( v6 )
      break;
LABEL_29:
    v27 = index++ + 1 < v2->m_aRadarInfos.m_num;
    v31 += 24;
    if ( !v27 )
    {
      if ( curClosestObject.first )
        v2->m_iidObjectUnderMouse = curClosestObject.first;
      goto LABEL_32;
    }
  }
  y = 0;
  v8 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v8, &result, &CObjectMaint_ClassType, (Interface **)&y);
  v28 = y;
  v9 = y;
  objMaint.m_pInterface = 0;
  objMaint.m_trStatus.m_val = 0;
  if ( y )
    (*(void (__thiscall **)(int))(*(_DWORD *)y + 16))(y);
  y = *(_DWORD *)InterfacePtr<CObjectMaint>::_QueryInterface(&objMaint, (int)&v42, v28, 0);
  objMaint.m_trStatus.m_val = y;
  if ( v9 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
  v10 = objMaint.m_pInterface;
  if ( !(_DWORD)objMaint.m_pInterface )
    return;
  if ( y >= 0 )
  {
    v11 = CObjectMaint::GetObjectA(objMaint.m_pInterface, v7->object->id);
    if ( v11 && v11[12].vfptr && v11[6].hash_next )
    {
      SmartBox::convert_to_player_space(SmartBox::smartbox, (CPhysicsObj *)v11, &v);
      if ( v.y * v.y + v.x * v.x >= fSquaredRadarRange )
      {
        v10->vfptr->Release((Interface *)v10);
        goto LABEL_29;
      }
      v12 = (double)v2->m_nRadarRadius;
      v30 = v12;
      v13 = v12 / v2->m_fRadarRange;
      v14 = (unsigned __int64)(v.x * v13 + v2->m_vecCenterPoint.x);
      x = (unsigned __int64)(v.x * v13 + v2->m_vecCenterPoint.x);
      v15 = (unsigned __int64)(v2->m_vecCenterPoint.y - v13 * v.y);
      v16 = (double)x;
      v17 = v2->m_vecCenterPoint.x;
      y = v15;
      if ( v16 < v17 - v30
        || v16 > v30 + v2->m_vecCenterPoint.x
        || (v18 = (double)y, v18 < v2->m_vecCenterPoint.y - v30)
        || v18 > v30 + v2->m_vecCenterPoint.y )
      {
        v10->vfptr->Release((Interface *)v10);
        goto LABEL_29;
      }
      v19 = ((int (__fastcall *)(CInputManager *, _DWORD))ICIDM::s_cidm->vfptr->GetMouseX)(ICIDM::s_cidm, HIDWORD(v15));
      v20 = v19 - UIRegion::GetScreenX0((UIRegion *)&v2->vfptr);
      v21 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
      v22 = UIRegion::GetScreenY0((UIRegion *)&v2->vfptr);
      v23 = (v21 - v22 - y) * (v21 - v22 - y) + (v20 - v14) * (v20 - v14);
      if ( (unsigned int)v23 > 0x24 || v23 >= curClosestObject.second )
      {
        v24 = object;
      }
      else
      {
        v24 = object;
        v25 = object->id;
        curClosestObject.second = v23;
        curClosestObject.first = v25;
        ACCWeenieObject::GetObjectNameWide(object, &strObjectName, NAME_APPROPRIATE, 0);
        StringInfo::StringInfo(&siObjectName);
        StringInfo::SetLiteralValue(&siObjectName, &strObjectName, 1);
        UIElement::SetTooltip((UIElement *)&v2->vfptr, &siObjectName);
        *((_DWORD *)&v2->0 + 41) |= 0x20u;
        StringInfo::~StringInfo(&siObjectName);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strObjectName);
      }
      intensity = 0.64999998;
      if ( fabs(v.z) < 5.0 )
        intensity = 1.0;
      gmRadarUI::DrawBlip(i_pSurface, info, intensity, v14, y, v24->id == ACCWeenieObject::selectedID);
      v26 = objMaint.m_pInterface->vfptr;
    }
    else
    {
      v26 = v10->vfptr;
    }
    ((void (*)(void))v26->Release)();
    goto LABEL_29;
  }
  if ( (_DWORD)objMaint.m_pInterface )
    objMaint.m_pInterface->vfptr->Release((Interface *)objMaint.m_pInterface);
}

//----- (004D9720) --------------------------------------------------------  // acclient.c:264290
void __thiscall gmRadarUI::DrawChildren(gmRadarUI *this, Box2D *i_rectObjectSelf, Box2D *i_rectObjectClip, SmartArray<Box2D,1> *i_aObjectBoxes, UISurface *i_pSurface)
{
  gmRadarUI *v5; // edi@1
  int v6; // ebx@1
  int v7; // ebp@1
  const int v8; // ebp@3
  const int v9; // ebx@3
  const int v10; // ebp@5
  const int v11; // ebx@5
  const int v12; // ebx@7
  const int v13; // ebp@7
  const int v14; // ebx@9
  const int v15; // edi@9

  v5 = this;
  UIRegion::DrawChildren((UIRegion *)&this->vfptr, i_rectObjectSelf, i_rectObjectClip, i_aObjectBoxes, i_pSurface);
  gmRadarUI::DrawObjects(v5, i_pSurface);
  v6 = (unsigned __int64)v5->m_vecCenterPoint.y;
  v7 = (unsigned __int64)v5->m_vecCenterPoint.x;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, &RGBAColor_RadarBrightGreen_0, v7, v6, v7, v6);
  }
  gmRadarUI::DrawEdges(i_pSurface, &RGBAColor_RadarBrightGreen_0, v7, v6);
  v8 = (unsigned __int64)v5->m_vecCenterPoint.y;
  v9 = (unsigned __int64)v5->m_vecCenterPoint.x - 2;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, &RGBAColor_RadarBrightGreen_0, v9, v8, v9, v8);
  }
  v10 = (unsigned __int64)v5->m_vecCenterPoint.y;
  v11 = (unsigned __int64)v5->m_vecCenterPoint.x + 2;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, &RGBAColor_RadarBrightGreen_0, v11, v10, v11, v10);
  }
  v12 = (unsigned __int64)v5->m_vecCenterPoint.y - 2;
  v13 = (unsigned __int64)v5->m_vecCenterPoint.x;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, &RGBAColor_RadarBrightGreen_0, v13, v12, v13, v12);
  }
  v14 = (unsigned __int64)v5->m_vecCenterPoint.y + 2;
  v15 = (unsigned __int64)v5->m_vecCenterPoint.x;
  if ( i_pSurface )
  {
    UISurface::PrepareSurface(i_pSurface);
    SurfaceWindow::FillArea(&i_pSurface->m_pLocalSurface->window, &RGBAColor_RadarBrightGreen_0, v15, v14, v15, v14);
  }
}

//----- (004D98A0) --------------------------------------------------------  // acclient.c:264346
void __thiscall gmRadarUI::UseTime(gmRadarUI *this)
{
  gmRadarUI *v1; // ebx@1
  InterfaceSystem *v2; // eax@2
  Interface *v3; // esi@2
  int v4; // ebp@4
  PlayerDesc *v5; // esi@6
  int v6; // [sp-14h] [bp-34h]@2
  Interface *_rpInterface; // [sp+4h] [bp-1Ch]@2
  TResult result; // [sp+8h] [bp-18h]@2
  char v9; // [sp+Ch] [bp-14h]@4
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+10h] [bp-10h]@2
  long double cur_time; // [sp+18h] [bp-8h]@1

  v1 = this;
  cur_time = *(double *)&Timer::cur_time;
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_ttNextUpdateTime )
  {
    _rpInterface = 0;
    v2 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_17, &_rpInterface);
    v3 = _rpInterface;
    v6 = (int)_rpInterface;
    spPlayerDesc.m_pInterface = 0;
    spPlayerDesc.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    v4 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v9, v6, 0);
    if ( v3 )
      v3->vfptr->Release(v3);
    v5 = spPlayerDesc.m_pInterface;
    if ( (_DWORD)spPlayerDesc.m_pInterface && v4 >= 0 && SmartBox::smartbox->player )
    {
      CPlayerSystem::GetPlayerSystem();
      v1->m_fRadarRange = CPlayerSystem::GetRadarRadius();
      gmRadarUI::UpdateCompassTokens(v1);
      gmRadarUI::UpdateCoordinates(v1);
      ((void (__stdcall *)(signed int))v1->m_pLockUIButton->vfptr[2].__vecDelDtor)(1);
      UIRegion::MakeRootDirtyHere((UIRegion *)&v1->vfptr);
    }
    v1->m_ttNextUpdateTime = cur_time + 0.025;
    if ( v5 )
      v5->vfptr->Release((Interface *)v5);
  }
}

//----- (004D99A0) --------------------------------------------------------  // acclient.c:264393
char __thiscall SmartArray<RadarInfo,1>::add_unique(SmartArray<RadarInfo,1> *this, RadarInfo *_data)
{
  unsigned int v2; // esi@1
  unsigned int v3; // eax@1
  RadarInfo *v4; // edx@2
  char result; // al@5

  v2 = this->m_num;
  v3 = 0;
  if ( !v2 )
    goto LABEL_5;
  v4 = this->m_data;
  while ( v4->object != _data->object )
  {
    ++v3;
    ++v4;
    if ( v3 >= v2 )
      goto LABEL_5;
  }
  if ( v3 != -1 )
    result = 0;
  else
LABEL_5:
    result = SmartArray<RadarInfo,1>::AddToEnd(this, _data);
  return result;
}

//----- (004D99E0) --------------------------------------------------------  // acclient.c:264421
void __thiscall gmRadarUI::ListenToGlobalMessage(gmRadarUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 3 )
  {
    gmRadarUI::UseTime(this);
  }
  else if ( i_messageID == 13 )
  {
    gmRadarUI::UpdateLockedStatus(this);
  }
}

//----- (004D9A00) --------------------------------------------------------  // acclient.c:264434
void __userpurge gmRadarUI::AddObject(gmRadarUI *this@<ecx>, int a2@<ebx>, ACCWeenieObject *i_pObj)
{
  gmRadarUI *v3; // edi@1
  unsigned int v4; // eax@4
  InterfacePtr<Interface> *v5; // eax@7
  CObjectMaint *v6; // ebx@9
  RGBAColor *v7; // eax@14
  float v8; // edx@14
  float v9; // ecx@14
  float v10; // edx@14
  int v11; // eax@17
  int v12; // [sp-4h] [bp-48h]@9
  InterfacePtr<CObjectMaint> objMaint; // [sp+8h] [bp-3Ch]@7
  InterfacePtr<Interface> result; // [sp+10h] [bp-34h]@7
  AC1Legacy::Vector3 point; // [sp+20h] [bp-24h]@13
  RadarInfo info; // [sp+2Ch] [bp-18h]@14

  v3 = this;
  if ( i_pObj && SLOBYTE(i_pObj->pwd._bitfield) >= 0 )
  {
    v4 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
    if ( v4 != i_pObj->id )
    {
      v5 = GetClassObject(&result, &CObjectMaint_ClassType);
      InterfacePtr<CObjectMaint>::InterfacePtr<CObjectMaint>(&objMaint, v5);
      if ( (_DWORD)result.m_pInterface )
        ((void (*)(void))result.m_pInterface->vfptr->Release)();
      v12 = a2;
      v6 = objMaint.m_pInterface;
      if ( (_DWORD)objMaint.m_pInterface )
      {
        if ( (objMaint.m_trStatus.m_val & 0x80000000) != 0 )
        {
          objMaint.m_pInterface->vfptr->Release((Interface *)objMaint.m_pInterface);
          return;
        }
        if ( CObjectMaint::GetObjectA(objMaint.m_pInterface, i_pObj->id)
          && ACCWeenieObject::InqShowableOnRadar(i_pObj, &point) )
        {
          RadarInfo::RadarInfo(&info, i_pObj);
          v7 = gmRadarUI::GetBlipColor((RGBAColor *)&result, i_pObj);
          v8 = v7->g;
          info.color.r = v7->r;
          v9 = v7->b;
          info.color.g = v8;
          v10 = v7->a;
          info.color.b = v9;
          info.color.a = v10;
          info.shape = gmRadarUI::GetBlipShape(i_pObj);
          if ( info.shape == Undef_RadarBlipShape )
          {
            v6->vfptr->Release((Interface *)v6);
            return;
          }
          if ( v3 )
            v11 = (int)&v3->vfptr;
          else
            v11 = 0;
          ((void (__thiscall *)(NoticeRegistrarVtbl **, _UNKNOWN *, int, int))i_pObj->vfptr->RegisterNoticeHandler)(
            &i_pObj->vfptr,
            &loc_4DD245,
            v11,
            v12);
          ((void (__thiscall *)(NoticeRegistrarVtbl **, signed int))i_pObj->vfptr->RegisterNoticeHandler)(
            &i_pObj->vfptr,
            100015);
          SmartArray<RadarInfo,1>::add_unique(&v3->m_aRadarInfos, &info);
        }
        v6->vfptr->Release((Interface *)v6);
      }
    }
  }
}
// 4D9A00: could not find valid save-restore pair for ebx

//----- (004D9B60) --------------------------------------------------------  // acclient.c:264510
void __userpurge gmRadarUI::RecvNotice_CreateObject(gmRadarUI *this@<ecx>, int a2@<ebx>, unsigned int i_iidObject)
{
  gmRadarUI *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@1

  v3 = this;
  v4 = ClientObjMaintSystem::GetWeenieObject(i_iidObject);
  if ( v4 )
    gmRadarUI::AddObject((gmRadarUI *)((char *)v3 - 1528), a2, (ACCWeenieObject *)v4);
}

//----- (004D9B90) --------------------------------------------------------  // acclient.c:264522
void __thiscall gmRadarUI::Init(gmRadarUI *this)
{
  int v1; // ebx@1
  GlobalEventHandler *v2; // eax@1
  int v3; // ecx@3
  InterfaceSystem *v4; // eax@8
  Interface *v5; // esi@8
  int v6; // edi@10
  CObjectMaint *v7; // esi@12
  HashBaseData<unsigned long> *v8; // eax@16
  CPlayerSystem *v9; // eax@27
  char v10; // al@27
  int v11; // ecx@27
  int v12; // [sp-8h] [bp-44h]@8
  Interface *_rpInterface; // [sp+10h] [bp-2Ch]@8
  gmRadarUI *v14; // [sp+14h] [bp-28h]@1
  TResult result; // [sp+18h] [bp-24h]@8
  char v16; // [sp+1Ch] [bp-20h]@10
  InterfacePtr<CObjectMaint> objMaint; // [sp+20h] [bp-1Ch]@8
  LongHashIter<CPhysicsObj> iter; // [sp+28h] [bp-14h]@15

  v1 = (int)this;
  v14 = this;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = v1 + 1528;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100014u, (NoticeHandler *)v3);
  }
  SmartArray<RadarInfo,1>::Reset((SmartArray<RadarInfo,1> *)(v1 + 1540));
  if ( CPlayerSystem::GetPlayerSystem() )
  {
    CPlayerSystem::GetPlayerSystem();
    *(float *)(v1 + 1536) = CPlayerSystem::GetRadarRadius();
  }
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &CObjectMaint_ClassType, &_rpInterface);
  v5 = _rpInterface;
  v12 = (int)_rpInterface;
  objMaint.m_pInterface = 0;
  objMaint.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  v6 = *(_DWORD *)InterfacePtr<CObjectMaint>::_QueryInterface(&objMaint, (int)&v16, v12, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v7 = objMaint.m_pInterface;
  if ( (_DWORD)objMaint.m_pInterface )
  {
    if ( v6 < 0 )
    {
      objMaint.m_pInterface->vfptr->Release((Interface *)objMaint.m_pInterface);
      return;
    }
    iter.myHash_ = (HashBase<unsigned long> *)&objMaint.m_pInterface->object_table.vfptr;
    iter.lastThisChain_ = 0;
    iter.curBucket_ = 0;
    if ( (_DWORD)objMaint.m_pInterface != -132 )
    {
      v8 = *objMaint.m_pInterface->object_table.buckets;
      iter.fEnd_ = 0;
      iter.curPtr_ = v8;
      if ( v8 )
      {
LABEL_19:
        LOBYTE(v1) = 1;
        while ( 1 )
        {
          if ( v8 )
          {
            if ( (unsigned int)v8[14].vfptr & 1 )
              goto LABEL_24;
            if ( v8[25].vfptr )
              break;
          }
LABEL_25:
          if ( iter.fEnd_ )
          {
            v1 = (int)v14;
            goto LABEL_27;
          }
        }
        gmRadarUI::AddObject(v14, v1, (ACCWeenieObject *)v8[25].vfptr);
LABEL_24:
        HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
        v8 = iter.curPtr_;
        goto LABEL_25;
      }
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
      if ( !iter.fEnd_ )
      {
        v8 = iter.curPtr_;
        goto LABEL_19;
      }
    }
LABEL_27:
    v9 = CPlayerSystem::GetPlayerSystem();
    v10 = PlayerModule::LockUI((PlayerModule *)&v9->playerModule.vfptr);
    v11 = *(_DWORD *)(v1 + 1620);
    if ( v10 )
    {
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v11 + 156))(268435555);
      v7->vfptr->Release((Interface *)v7);
    }
    else
    {
      (*(void (__stdcall **)(signed int))(*(_DWORD *)v11 + 156))(268435556);
      v7->vfptr->Release((Interface *)v7);
    }
  }
}

//----- (004D9D30) --------------------------------------------------------  // acclient.c:264639
void __thiscall gmRadarUI::PostInit(gmRadarUI *this)
{
  gmRadarUI *v1; // esi@1
  IInputActionCallbackVtbl *v2; // edx@1
  BasePropertyValue *v3; // ecx@8
  BasePropertyDesc *v4; // ecx@13
  unsigned int v5; // edi@13
  int v6; // edx@17
  int v7; // ecx@21
  int v8; // edi@21
  float v9; // ecx@25
  int v10; // edx@25
  UIElement *v11; // eax@27
  UIElement *v12; // eax@28
  int v13; // ecx@29
  double v14; // st7@29
  float _y; // ST54_4@29
  float _x; // ST50_4@29
  double v17; // st7@29
  double v18; // st6@29
  long double v19; // st7@29
  UIElement *v20; // eax@31
  int v21; // edx@32
  double v22; // st7@32
  float v23; // ST54_4@32
  float v24; // ST50_4@32
  double v25; // st7@32
  double v26; // st6@32
  long double v27; // st7@32
  UIElement *v28; // eax@34
  int v29; // ecx@35
  double v30; // st7@35
  float v31; // ST54_4@35
  float v32; // ST50_4@35
  double v33; // st7@35
  double v34; // st6@35
  long double v35; // st7@35
  UIElement *v36; // eax@37
  int v37; // edx@38
  double v38; // st7@38
  float v39; // ST54_4@38
  float v40; // ST50_4@38
  double v41; // st7@38
  double v42; // st6@38
  long double v43; // st7@38
  UIElement *v44; // eax@42
  int v45; // eax@43
  UIElement *v46; // eax@47
  int v47; // eax@48
  UIElement *v48; // eax@52
  int v49; // eax@53
  GlobalEventHandler *v50; // eax@56
  BasePropertyDesc *v51; // ecx@63
  unsigned int v52; // edx@63
  BasePropertyValue *v53; // ecx@67
  unsigned int v54; // edx@67
  int x; // [sp+64h] [bp-40h]@6
  int y; // [sp+68h] [bp-3Ch]@6
  unsigned int eNorthTokenID; // [sp+6Ch] [bp-38h]@27
  unsigned int eEastTokenID; // [sp+70h] [bp-34h]@30
  unsigned int eSouthTokenID; // [sp+74h] [bp-30h]@33
  unsigned int eWestTokenID; // [sp+78h] [bp-2Ch]@36
  unsigned int eCoordinateContainerFieldID; // [sp+7Ch] [bp-28h]@39
  unsigned int eCombinedCoordsFieldID; // [sp+80h] [bp-24h]@41
  unsigned int eXCoordFieldID; // [sp+84h] [bp-20h]@46
  unsigned int eYCoordFieldID; // [sp+88h] [bp-1Ch]@51
  BaseProperty bpY; // [sp+8Ch] [bp-18h]@2
  BaseProperty bpCenterPoint; // [sp+94h] [bp-10h]@1
  Vector2 vecWest; // [sp+9Ch] [bp-8h]@2

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x1000007Eu, &v1->m_eWindowID);
  v2 = v1->vfptr;
  bpCenterPoint.m_pcPropertyDesc = 0;
  bpCenterPoint.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__thiscall *)(gmRadarUI *, signed int, BaseProperty *))v2[17].OnAction)(
                          v1,
                          268435502,
                          &bpCenterPoint) )
  {
    LODWORD(vecWest.x) = 0;
    LODWORD(vecWest.y) = 0;
    bpY.m_pcPropertyDesc = 0;
    bpY.m_pcPropertyValue = 0;
    if ( bpCenterPoint.m_pcPropertyValue )
    {
      if ( (unsigned __int8)((int (__stdcall *)(signed int, Vector2 *))bpCenterPoint.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                              268435503,
                              &vecWest)
        && bpCenterPoint.m_pcPropertyValue
        && (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))bpCenterPoint.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                              268435504,
                              &bpY) )
      {
        x = 0;
        y = 0;
        if ( LODWORD(vecWest.y) )
          (*(void (__stdcall **)(int *))(*LODWORD(vecWest.y) + 120))(&x);
        v3 = bpY.m_pcPropertyValue;
        if ( bpY.m_pcPropertyValue )
        {
          ((void (__stdcall *)(int *))bpY.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&y);
          v3 = bpY.m_pcPropertyValue;
        }
        v1->m_vecCenterPoint.x = (double)x;
        v1->m_vecCenterPoint.y = (double)y;
      }
      else
      {
        v3 = bpY.m_pcPropertyValue;
      }
      if ( (_DWORD)bpY.m_pcPropertyDesc )
      {
        v4 = bpY.m_pcPropertyDesc;
        v5 = bpY.m_pcPropertyDesc->m_cRef - 1;
        bpY.m_pcPropertyDesc->m_cRef = v5;
        if ( !v5 )
          ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
        v3 = bpY.m_pcPropertyValue;
        bpY.m_pcPropertyDesc = 0;
      }
      if ( v3 )
      {
        v6 = v3->m_cRef - 1;
        v3->m_cRef = v6;
        if ( !v6 )
          ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(1);
        bpY.m_pcPropertyValue = 0;
      }
      if ( (_DWORD)vecWest.x )
      {
        v7 = (signed int)vecWest.x;
        v8 = *(_DWORD *)((_DWORD)vecWest.x + 4) - 1;
        *(_DWORD *)((_DWORD)vecWest.x + 4) = v8;
        if ( !v8 )
          (**(void (__stdcall ***)(_DWORD))v7)(1);
        LODWORD(vecWest.x) = 0;
      }
      if ( LODWORD(vecWest.y) )
      {
        v9 = vecWest.y;
        v10 = *(_DWORD *)(LODWORD(vecWest.y) + 4) - 1;
        *(_DWORD *)(LODWORD(vecWest.y) + 4) = v10;
        if ( !v10 )
          (*(void (__stdcall **)(signed int))*LODWORD(v9))(1);
      }
    }
  }
  UIElement::GetAttribute_Int((UIElement *)&v1->vfptr, 0x1000002Du, &v1->m_nRadarRadius);
  ((void (__thiscall *)(gmRadarUI *, signed int))v1->vfptr[22].OnLoseFocus)(v1, 1);
  v1->m_pLockUIButton = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000619u);
  v11 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100006A3u);
  v1->m_pDragButton = v11;
  v11->vfptr[2].__vecDelDtor((IInputActionCallback *)v11, 0);
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000031u, &eNorthTokenID) )
  {
    v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eNorthTokenID);
    v1->m_pNorthToken = v12;
    if ( v12 )
    {
      v13 = v12->m_box.m_x1;
      y = v12->m_box.m_y0 + v12->m_box.m_y1;
      v14 = (double)y * 0.5;
      y = v12->m_box.m_x0 + v13;
      _y = v14;
      _x = (double)y * 0.5;
      Vector2::Vector2(&vecWest, _x, _y);
      v17 = v1->m_vecCenterPoint.x - vecWest.x;
      v18 = v1->m_vecCenterPoint.y - vecWest.y;
      v19 = sqrt(v18 * v18 + v17 * v17);
      v1->m_fNorthTokenMagnitude = v19;
      CAsyncStateHandler::OnStateHandlerInit((Logger::ILoggingOutputHandler *)&vecWest);
    }
  }
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000033u, &eEastTokenID) )
  {
    v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eEastTokenID);
    v1->m_pEastToken = v20;
    if ( v20 )
    {
      v21 = v20->m_box.m_x1;
      y = v20->m_box.m_y0 + v20->m_box.m_y1;
      v22 = (double)y * 0.5;
      y = v20->m_box.m_x0 + v21;
      v23 = v22;
      v24 = (double)y * 0.5;
      Vector2::Vector2(&vecWest, v24, v23);
      v25 = v1->m_vecCenterPoint.x - vecWest.x;
      v26 = v1->m_vecCenterPoint.y - vecWest.y;
      v27 = sqrt(v26 * v26 + v25 * v25);
      v1->m_fEastTokenMagnitude = v27;
      CAsyncStateHandler::OnStateHandlerInit((Logger::ILoggingOutputHandler *)&vecWest);
    }
  }
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000032u, &eSouthTokenID) )
  {
    v28 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eSouthTokenID);
    v1->m_pSouthToken = v28;
    if ( v28 )
    {
      v29 = v28->m_box.m_x1;
      y = v28->m_box.m_y0 + v28->m_box.m_y1;
      v30 = (double)y * 0.5;
      y = v28->m_box.m_x0 + v29;
      v31 = v30;
      v32 = (double)y * 0.5;
      Vector2::Vector2(&vecWest, v32, v31);
      v33 = v1->m_vecCenterPoint.x - vecWest.x;
      v34 = v1->m_vecCenterPoint.y - vecWest.y;
      v35 = sqrt(v34 * v34 + v33 * v33);
      v1->m_fSouthTokenMagnitude = v35;
      CAsyncStateHandler::OnStateHandlerInit((Logger::ILoggingOutputHandler *)&vecWest);
    }
  }
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000034u, &eWestTokenID) )
  {
    v36 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eWestTokenID);
    v1->m_pWestToken = v36;
    if ( v36 )
    {
      v37 = v36->m_box.m_x1;
      y = v36->m_box.m_y0 + v36->m_box.m_y1;
      v38 = (double)y * 0.5;
      y = v36->m_box.m_x0 + v37;
      v39 = v38;
      v40 = (double)y * 0.5;
      Vector2::Vector2(&vecWest, v40, v39);
      v41 = v1->m_vecCenterPoint.x - vecWest.x;
      v42 = v1->m_vecCenterPoint.y - vecWest.y;
      v43 = sqrt(v42 * v42 + v41 * v41);
      v1->m_fWestTokenMagnitude = v43;
      CAsyncStateHandler::OnStateHandlerInit((Logger::ILoggingOutputHandler *)&vecWest);
    }
  }
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000035u, &eCoordinateContainerFieldID) )
    v1->m_pCoordinateContainerField = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eCoordinateContainerFieldID);
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000036u, &eCombinedCoordsFieldID) )
  {
    v44 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eCombinedCoordsFieldID);
    if ( v44 )
      v45 = v44->vfptr[12].OnAction((IInputActionCallback *)v44, (InputEvent *)12);
    else
      v45 = 0;
    v1->m_pCombinedCoordsText = (UIElement_Text *)v45;
  }
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000037u, &eXCoordFieldID) )
  {
    v46 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eXCoordFieldID);
    if ( v46 )
      v47 = v46->vfptr[12].OnAction((IInputActionCallback *)v46, (InputEvent *)12);
    else
      v47 = 0;
    v1->m_pXCoordText = (UIElement_Text *)v47;
  }
  if ( UIElement::GetAttribute_Enum((UIElement *)&v1->vfptr, 0x10000038u, &eYCoordFieldID) )
  {
    v48 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, eYCoordFieldID);
    if ( v48 )
      v49 = v48->vfptr[12].OnAction((IInputActionCallback *)v48, (InputEvent *)12);
    else
      v49 = 0;
    v1->m_pYCoordText = (UIElement_Text *)v49;
  }
  v50 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v50 )
    v50->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v50, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1->vfptr);
  ((void (__stdcall *)(signed int, signed int, QualityChangeHandlerVtbl **))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandlerForThePlayer)(
    7,
    26,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, signed int, signed int, QualityChangeHandlerVtbl **))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
    0,
    7,
    26,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, signed int, signed int, QualityChangeHandlerVtbl **))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
    0,
    1,
    134,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, signed int, signed int, QualityChangeHandlerVtbl **))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
    0,
    1,
    95,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
    0,
    1,
    133,
    &v1->vfptr);
  ((void (__stdcall *)(_DWORD, signed int, signed int, _DWORD))QualityRegistrar::s_pQR->vfptr->RegisterQualityHandler)(
    0,
    5,
    1,
    &v1->vfptr);
  if ( (*((_DWORD *)&v1->0 + 41) >> 1) & 1 )
    UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xDu);
  if ( CPlayerSystem::GetPlayerSystem()->player_desc_received )
    gmRadarUI::Init(v1);
  v1->vfptr[13].__vecDelDtor((IInputActionCallback *)v1, 268435555u);
  if ( (_DWORD)bpCenterPoint.m_pcPropertyDesc )
  {
    v51 = bpCenterPoint.m_pcPropertyDesc;
    v52 = bpCenterPoint.m_pcPropertyDesc->m_cRef - 1;
    bpCenterPoint.m_pcPropertyDesc->m_cRef = v52;
    if ( !v52 )
      ((void (__stdcall *)(signed int))v51->vfptr->__vecDelDtor)(1);
    bpCenterPoint.m_pcPropertyDesc = 0;
  }
  if ( bpCenterPoint.m_pcPropertyValue )
  {
    v53 = bpCenterPoint.m_pcPropertyValue;
    v54 = bpCenterPoint.m_pcPropertyValue->m_cRef - 1;
    bpCenterPoint.m_pcPropertyValue->m_cRef = v54;
    if ( !v54 )
      ((void (__stdcall *)(signed int))v53->vfptr->__vecDelDtor)(1);
  }
}

//----- (004DA380) --------------------------------------------------------  // acclient.c:264961
void __thiscall gmRadarUI::RecvNotice_PlayerDescReceived(gmRadarUI *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  char *v3; // esi@1

  v3 = (char *)&this[-1].m_box.m_y1;
  gmRadarUI::Init((gmRadarUI *)((char *)this - 1528));
  (*(void (__thiscall **)(char *))(*(_DWORD *)v3 + 312))(v3);
}

//----- (006F5130) --------------------------------------------------------  // acclient.c:777629
void sub_6F5130()
{
  flt_840290 = 1000.0 + 1.0;
}

//----- (006F5150) --------------------------------------------------------  // acclient.c:777635
void _E93_85()
{
  flt_840294 = 24.0 * 8.0;
}

//----- (006F5170) --------------------------------------------------------  // acclient.c:777641
void _E95_85()
{
  flt_840298 = 24.0 * 0.5;
}

//----- (006F5190) --------------------------------------------------------  // acclient.c:777647
int sub_6F5190()
{
  return atexit(nullsub_637);
}

//----- (006F51A0) --------------------------------------------------------  // acclient.c:777653
int sub_6F51A0()
{
  return atexit(nullsub_638);
}

//----- (006F51B0) --------------------------------------------------------  // acclient.c:777659
int _E103_95()
{
  return atexit(nullsub_639);
}

//----- (006F51C0) --------------------------------------------------------  // acclient.c:777665
void _E106_68()
{
  PixelFormatDesc::PixelFormatDesc(&stru_84029C, PFID_A8R8G8B8);
}

//----- (006F51D0) --------------------------------------------------------  // acclient.c:777671
int _E128_4()
{
  RGBAColor_RadarDefault_0 = RGBAColor_RadarWhite_0;
  return LODWORD(RGBAColor_RadarWhite_0.a);
}

//----- (006F5200) --------------------------------------------------------  // acclient.c:777678
int _E130_30()
{
  RGBAColor_RadarAdmin_0 = RGBAColor_RadarCyan_0;
  return LODWORD(RGBAColor_RadarCyan_0.a);
}

//----- (006F5230) --------------------------------------------------------  // acclient.c:777685
int _E132_20()
{
  RGBAColor_RadarAdvocate_0 = RGBAColor_RadarPink_0;
  return LODWORD(RGBAColor_RadarPink_0.a);
}

//----- (006F5260) --------------------------------------------------------  // acclient.c:777692
int _E134_5()
{
  RGBAColor_RadarCreature_0 = RGBAColor_RadarGold_0;
  return LODWORD(RGBAColor_RadarGold_0.a);
}

//----- (006F5290) --------------------------------------------------------  // acclient.c:777699
int _E136_20()
{
  RGBAColor_RadarLifeStone_0 = RGBAColor_RadarBlue_0;
  return LODWORD(RGBAColor_RadarBlue_0.a);
}

//----- (006F52C0) --------------------------------------------------------  // acclient.c:777706
int _E138_18()
{
  RGBAColor_RadarNPC_0 = RGBAColor_RadarYellow_0;
  return LODWORD(RGBAColor_RadarYellow_0.a);
}

//----- (006F52F0) --------------------------------------------------------  // acclient.c:777713
int _E140_2()
{
  RGBAColor_RadarPlayerKiller_0 = RGBAColor_RadarRed_0;
  return LODWORD(RGBAColor_RadarRed_0.a);
}

//----- (006F5320) --------------------------------------------------------  // acclient.c:777720
int _E142_18()
{
  RGBAColor_RadarPortal_0 = RGBAColor_RadarPurple_0;
  return LODWORD(RGBAColor_RadarPurple_0.a);
}

//----- (006F5350) --------------------------------------------------------  // acclient.c:777727
int _E144_17()
{
  RGBAColor_RadarSentinel_0 = RGBAColor_RadarCyan_0;
  return LODWORD(RGBAColor_RadarCyan_0.a);
}

//----- (006F5380) --------------------------------------------------------  // acclient.c:777734
int _E146_3()
{
  RGBAColor_RadarVendor_0 = RGBAColor_RadarYellow_0;
  return LODWORD(RGBAColor_RadarYellow_0.a);
}

//----- (006F53B0) --------------------------------------------------------  // acclient.c:777741
int _E148_19()
{
  RGBAColor_RadarFellowship_0 = RGBAColor_RadarBrightGreen_0;
  return LODWORD(RGBAColor_RadarBrightGreen_0.a);
}

//----- (006F53E0) --------------------------------------------------------  // acclient.c:777748
int _E150_17()
{
  RGBAColor_RadarFellowshipLeader_0 = RGBAColor_RadarBrightGreen_0;
  return LODWORD(RGBAColor_RadarBrightGreen_0.a);
}

//----- (006F5410) --------------------------------------------------------  // acclient.c:777755
int _E152_3()
{
  RGBAColor_RadarPKLite_0 = RGBAColor_RadarPink_0;
  return LODWORD(RGBAColor_RadarPink_0.a);
}

//----- (006F5440) --------------------------------------------------------  // acclient.c:777762
void _E157_16()
{
  DEFAULT_VIEW_RADIUS_69 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F5460) --------------------------------------------------------  // acclient.c:777768
void _E159_16()
{
  MIN_QUANTUM_69 = 1.0 / 30.0;
}

//----- (006F5480) --------------------------------------------------------  // acclient.c:777774
void _E161_2()
{
  MAX_QUANTUM_69 = 1.0 / 5.0;
}

//----- (006F54A0) --------------------------------------------------------  // acclient.c:777780
int _E163_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_38, "None");
  return atexit(_E164_22);
}

//----- (006F54C0) --------------------------------------------------------  // acclient.c:777787
int _E166_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_38, "Speed");
  return atexit(_E167_18);
}

//----- (006F54E0) --------------------------------------------------------  // acclient.c:777794
int _E169_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_38, "Noise");
  return atexit(_E170_17);
}

//----- (006F5500) --------------------------------------------------------  // acclient.c:777801
int _E172_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_38, "Sine");
  return atexit(_E173_16);
}

//----- (006F5520) --------------------------------------------------------  // acclient.c:777808
int _E175_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_38, "Square");
  return atexit(_E176_17);
}

//----- (006F5540) --------------------------------------------------------  // acclient.c:777815
int _E178_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_38, "Bounce");
  return atexit(_E179_16);
}

//----- (006F5560) --------------------------------------------------------  // acclient.c:777822
int _E181_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_38, "Perlin");
  return atexit(_E182_16);
}

//----- (006F5580) --------------------------------------------------------  // acclient.c:777829
int _E184_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_38, "Fractal");
  return atexit(_E185_13);
}

//----- (006F55A0) --------------------------------------------------------  // acclient.c:777836
int _E187_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_38, "FrameLoop");
  return atexit(_E188_14);
}

//----- (006F55C0) --------------------------------------------------------  // acclient.c:777843
int _E190_10()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_37, "Misc.TooltipEnable");
  return atexit(_E191_13);
}

//----- (006F55E0) --------------------------------------------------------  // acclient.c:777850
int _E193_9()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_37, "Misc.TooltipDelay");
  return atexit(_E194_20);
}

//----- (006F5600) --------------------------------------------------------  // acclient.c:777857
int _E196_12()
{
  return atexit(_E197_11);
}

//----- (006F5610) --------------------------------------------------------  // acclient.c:777863
void _E199_9()
{
  LOWEST_DATA_RATE_95 = 1024;
}

//----- (006F5620) --------------------------------------------------------  // acclient.c:777869
void _E201_7()
{
  HIGHEST_DATA_RATE_95 = 0x7FFF;
}

//----- (006F5630) --------------------------------------------------------  // acclient.c:777875
int _E203_1()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_95;
  INITIAL_MAX_DATA_RATE_43 = LOWEST_DATA_RATE_95;
  return result;
}

//----- (006F5640) --------------------------------------------------------  // acclient.c:777885
void _E206_3()
{
  sin_r_angle = sin(1.570796326794897);
}

//----- (006F5650) --------------------------------------------------------  // acclient.c:777891
void _E208_13()
{
  cos_r_angle = cos(1.570796326794897);
}

//----- (006F5660) --------------------------------------------------------  // acclient.c:777897
int sub_6F5660()
{
  return atexit(nullsub_636);
}

//----- (007626C0) --------------------------------------------------------  // acclient.c:889574
void __cdecl _E164_22()
{
  char *v0; // esi@1

  v0 = &waveform_None_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007626F0) --------------------------------------------------------  // acclient.c:889587
void __cdecl _E167_18()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762720) --------------------------------------------------------  // acclient.c:889600
void __cdecl _E170_17()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762750) --------------------------------------------------------  // acclient.c:889613
void __cdecl _E173_16()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762780) --------------------------------------------------------  // acclient.c:889626
void __cdecl _E176_17()
{
  char *v0; // esi@1

  v0 = &waveform_Square_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007627B0) --------------------------------------------------------  // acclient.c:889639
void __cdecl _E179_16()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007627E0) --------------------------------------------------------  // acclient.c:889652
void __cdecl _E182_16()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762810) --------------------------------------------------------  // acclient.c:889665
void __cdecl _E185_13()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762840) --------------------------------------------------------  // acclient.c:889678
void __cdecl _E188_14()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_38.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_38.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00762870) --------------------------------------------------------  // acclient.c:889691
void __cdecl _E191_13()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007628A0) --------------------------------------------------------  // acclient.c:889704
void __cdecl _E194_20()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

