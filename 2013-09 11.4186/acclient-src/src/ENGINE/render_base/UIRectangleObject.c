/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIRectangleObject
   Object     : ENGINE\render_base\UIRectangleObject.obj
   Functions  : 8
   Addresses  : 00694E60 - 007193D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00694E60) --------------------------------------------------------  // acclient.c:684697
void __thiscall UIRectangleObject::Render(UIRectangleObject *this)
{
  UIRectangleObject *v1; // esi@1
  float clipX; // [sp+4h] [bp-28h]@1
  float clipY1; // [sp+8h] [bp-24h]@1
  float clipX1; // [sp+Ch] [bp-20h]@1
  float clipY; // [sp+10h] [bp-1Ch]@1
  Vector3 b; // [sp+14h] [bp-18h]@1
  Vector3 a; // [sp+20h] [bp-Ch]@1

  v1 = this;
  SurfaceWindow::WindowToClip(
    &RenderDevice::render_device->m_pFrameBufferSurface->window,
    this->m_nVirtualX,
    this->m_nVirtualY,
    &clipX,
    &clipY);
  SurfaceWindow::WindowToClip(
    &RenderDevice::render_device->m_pFrameBufferSurface->window,
    v1->m_nVirtualWidth + v1->m_nVirtualX - 1,
    v1->m_nVirtualHeight + v1->m_nVirtualY - 1,
    &clipX1,
    &clipY1);
  SceneTool::StoreMatrices();
  SceneTool::IdentityMatrices();
  b.x = clipX1;
  b.z = clipY;
  v1 = (UIRectangleObject *)((char *)v1 + 80);
  a.x = clipX;
  LODWORD(b.y) = 1065353216;
  LODWORD(a.y) = 1065353216;
  a.z = clipY;
  SceneTool::DrawLine(&a, &b, (RGBAColor *)v1, 0, 0);
  a.z = clipY1;
  b.x = clipX;
  a.x = clipX;
  LODWORD(a.y) = 1065353216;
  LODWORD(b.y) = 1065353216;
  b.z = clipY;
  SceneTool::DrawLine(&b, &a, (RGBAColor *)v1, 0, 0);
  a.x = clipX1;
  LODWORD(a.y) = 1065353216;
  a.z = clipY1;
  b.x = clipX;
  LODWORD(b.y) = 1065353216;
  b.z = clipY1;
  SceneTool::DrawLine(&b, &a, (RGBAColor *)v1, 0, 0);
  a.z = clipY1;
  b.x = clipX1;
  a.x = clipX1;
  LODWORD(a.y) = 1065353216;
  LODWORD(b.y) = 1065353216;
  b.z = clipY;
  SceneTool::DrawLine(&b, &a, (RGBAColor *)v1, 0, 0);
  SceneTool::RestoreMatrices();
}

//----- (00694FF0) --------------------------------------------------------  // acclient.c:684755
void __thiscall UIRectangleObject::UIRectangleObject(UIRectangleObject *this)
{
  UIRectangleObject *v1; // esi@1

  v1 = this;
  UIObject::UIObject((UIObject *)&this->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&UIRectangleObject::vftable;
  v1->m_color = stru_8345AC;
}
// 800744: using guessed type int (__thiscall *UIRectangleObject::vftable)(void *, char);

//----- (00719350) --------------------------------------------------------  // acclient.c:811925
void sub_719350()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F86E0, PFID_A8R8G8B8);
}

//----- (00719360) --------------------------------------------------------  // acclient.c:811931
void sub_719360()
{
  LODWORD(dword_8F871C) = 1053364187;
}

//----- (00719370) --------------------------------------------------------  // acclient.c:811937
void sub_719370()
{
  flt_8F8720 = 1000.0 + 1.0;
}

//----- (00719390) --------------------------------------------------------  // acclient.c:811943
void sub_719390()
{
  flt_8F8724 = 24.0 * 8.0;
}

//----- (007193B0) --------------------------------------------------------  // acclient.c:811949
void sub_7193B0()
{
  flt_8F8728 = 24.0 * 0.5;
}

//----- (007193D0) --------------------------------------------------------  // acclient.c:811955
int sub_7193D0()
{
  return atexit(nullsub_290);
}

