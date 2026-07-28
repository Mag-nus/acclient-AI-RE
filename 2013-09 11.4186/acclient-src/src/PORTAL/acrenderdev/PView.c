/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PView
   Object     : PORTAL\acrenderdev\PView.obj
   Functions  : 116
   Addresses  : 005A42E0 - 00776FA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A42E0) --------------------------------------------------------  // acclient.c:461028
void __stdcall PView::remove_views(unsigned __int16 num_stabs, unsigned int *stab_list)
{
  unsigned int *v3; // esi@2
  int v4; // edi@2
  RenderVertexStreamD3D *v5; // eax@3

  if ( num_stabs )
  {
    v3 = stab_list;
    v4 = num_stabs;
    do
    {
      v5 = CEnvCell::GetVisible(*v3);
      if ( v5 )
        --v5[1].m_VertexFormatInfo.offsetTCPair[2];
      ++v3;
      --v4;
    }
    while ( v4 );
  }
}

//----- (005A4320) --------------------------------------------------------  // acclient.c:461051
void __stdcall PView::GetClip(Sidedness side, CPolygon *ppoly, Vec2Dscreen **clip_view, int *clip_pts, int check)
{
  signed int v6; // edi@1
  int v7; // eax@5
  Vec2Dscreen **v8; // ST00_4@5
  int v9; // ecx@6
  int v10; // eax@6
  Vec2Dscreen **v11; // edx@7
  int v12; // ecx@10
  int v13; // eax@11
  int v14; // eax@14
  Vec2Dscreen *temp_screen[32]; // [sp+Ch] [bp-80h]@8

  *clip_pts = 0;
  v6 = 0;
  if ( ppoly->num_pts )
  {
    do
    {
      ppoly->screen[v6] = PrimD3DRender::xformStart((AC1Legacy::Vector3 *)ppoly->vertices[v6], 1);
      ++v6;
    }
    while ( v6 < ppoly->num_pts );
  }
  if ( check )
  {
    if ( side )
    {
      v9 = ppoly->num_pts;
      v10 = 0;
      if ( v9 > 0 )
      {
        v11 = &ppoly->screen[v9 - 1];
        do
        {
          temp_screen[v10++] = *v11;
          --v11;
        }
        while ( v10 < v9 );
      }
      Render::PolyCurrent = 0;
      LODWORD(Render::PolyCurrentMod) = 1065353216;
      Render::PolyCurrentPos = 1;
      ACRender::polyClipFinish(temp_screen, v9, clip_view, clip_pts, 0);
    }
    else
    {
      v7 = ppoly->num_pts;
      v8 = ppoly->screen;
      Render::PolyCurrent = 0;
      LODWORD(Render::PolyCurrentMod) = 1065353216;
      Render::PolyCurrentPos = 1;
      ACRender::polyClipFinish(v8, v7, clip_view, clip_pts, 0);
    }
  }
  else
  {
    v12 = ppoly->num_pts;
    *clip_pts = v12;
    if ( side )
    {
      v14 = 0;
      if ( v12 > 0 )
      {
        do
        {
          clip_view[v14] = ppoly->screen[ppoly->num_pts - v14 - 1];
          ++v14;
        }
        while ( v14 < *clip_pts );
      }
    }
    else
    {
      v13 = 0;
      if ( v12 > 0 )
      {
        do
        {
          clip_view[v13] = ppoly->screen[v13];
          ++v13;
        }
        while ( v13 < *clip_pts );
      }
    }
  }
}
// 846054: using guessed type float Render::PolyCurrentMod;
// 8460B8: using guessed type int Render::PolyCurrentPos;
// 8662FC: using guessed type struct CPolygon *Render::PolyCurrent;

//----- (005A44A0) --------------------------------------------------------  // acclient.c:461143
void __thiscall DArray<portal_info>::grow(DArray<portal_info> *this, unsigned int size)
{
  DArray<portal_info> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3
  void *v5; // ecx@4

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](8 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        v5 = v2->data;
        *((_DWORD *)v3 + 2 * v4) = v2->data[v4].seen;
        *((_DWORD *)v3 + 2 * v4 + 1) = *((_DWORD *)v5 + 2 * v4 + 1);
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (portal_info *)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<portal_info>::shrink(this, size);
  }
}

//----- (005A4510) --------------------------------------------------------  // acclient.c:461177
void __thiscall DArray<CEnvCell *>::grow(DArray<CEnvCell *> *this, unsigned int size)
{
  DArray<CEnvCell *> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->data[v4];
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (CEnvCell **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<CEnvCell *>::shrink(this, size);
  }
}

//----- (005A4570) --------------------------------------------------------  // acclient.c:461208
void __thiscall DArray<CellListType *>::grow(DArray<CellListType *> *this, unsigned int size)
{
  DArray<CellListType *> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->data[v4];
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (CellListType **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<CellListType *>::shrink(this, size);
  }
}

//----- (005A45D0) --------------------------------------------------------  // acclient.c:461239
void __thiscall DArray<portal_view_type *>::grow(DArray<portal_view_type *> *this, unsigned int size)
{
  DArray<portal_view_type *> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->data[v4];
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (portal_view_type **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<portal_view_type *>::shrink(this, size);
  }
}

//----- (005A4630) --------------------------------------------------------  // acclient.c:461270
void __thiscall DArray<portal_info>::shrink(DArray<portal_info> *this, unsigned int size)
{
  DArray<portal_info> *v2; // esi@1
  portal_info *v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5
  void *v6; // edx@6

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](8 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          v6 = v2->data;
          *((_DWORD *)v4 + 2 * v5) = v2->data[v5].seen;
          *((_DWORD *)v4 + 2 * v5 + 1) = *((_DWORD *)v6 + 2 * v5 + 1);
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (portal_info *)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<portal_info>::grow(this, size);
  }
}

//----- (005A46C0) --------------------------------------------------------  // acclient.c:461317
void __thiscall DArray<CEnvCell *>::shrink(DArray<CEnvCell *> *this, unsigned int size)
{
  DArray<CEnvCell *> *v2; // esi@1
  CEnvCell **v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](4 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          *((_DWORD *)v4 + v5) = v2->data[v5];
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (CEnvCell **)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<CEnvCell *>::grow(this, size);
  }
}

//----- (005A4740) --------------------------------------------------------  // acclient.c:461361
void __thiscall DArray<CellListType *>::shrink(DArray<CellListType *> *this, unsigned int size)
{
  DArray<CellListType *> *v2; // esi@1
  CellListType **v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](4 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          *((_DWORD *)v4 + v5) = v2->data[v5];
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (CellListType **)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<CellListType *>::grow(this, size);
  }
}

//----- (005A47C0) --------------------------------------------------------  // acclient.c:461405
void __thiscall DArray<portal_view_type *>::shrink(DArray<portal_view_type *> *this, unsigned int size)
{
  DArray<portal_view_type *> *v2; // esi@1
  portal_view_type **v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](4 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          *((_DWORD *)v4 + v5) = v2->data[v5];
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (portal_view_type **)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<portal_view_type *>::grow(this, size);
  }
}

//----- (005A4840) --------------------------------------------------------  // acclient.c:461449
void __thiscall PView::DrawCells(PView *this, int from_outside)
{
  PView *v2; // edi@1
  bool v3; // zf@3
  unsigned int v4; // ebx@5
  CEnvCell *v5; // esi@6
  unsigned int v6; // eax@7
  unsigned int v7; // eax@8
  unsigned int v8; // ebp@10
  unsigned int v9; // ebx@11
  int v10; // edi@12
  CCellPortal *v11; // edx@13
  unsigned int v12; // ebp@21
  CEnvCell *v13; // esi@22
  unsigned int v14; // eax@23
  unsigned int v15; // eax@24
  unsigned int v16; // edi@26
  int v17; // ebx@26
  unsigned int i; // esi@31
  CEnvCell *v19; // eax@32
  int v20; // [sp+10h] [bp-18h]@10
  unsigned int iq; // [sp+14h] [bp-14h]@5
  PView *v22; // [sp+18h] [bp-10h]@1

  v2 = this;
  v22 = this;
  if ( this->outside_view.view_count )
  {
    Render::useSunlightSet(1);
    Render::PortalList = (struct portal_view_type *)v2;
    LScape::draw(v2->lscape);
    D3DPolyRender::FlushAlphaList(0.0);
    ++RenderDevice::render_device->m_nFrameStamp;
    if ( forceClear || (v3 = D3DPolyRender::portalsDrawnCount == 0, D3DPolyRender::portalsDrawnCount = 0, !v3) )
      ((void (__stdcall *)(signed int, RGBAColor *, signed int))RenderDevice::render_device->vfptr->Clear)(
        4,
        &stru_820FC0,
        1065353216);
    v4 = v2->cell_draw_num;
    iq = v2->cell_draw_num;
    if ( v4 )
    {
      while ( 1 )
      {
        v5 = v2->cell_draw_list.data[v4 - 1];
        if ( v5->structure->drawing_bsp )
          break;
LABEL_20:
        --v4;
        iq = v4;
        if ( !v4 )
          goto LABEL_21;
      }
      RenderDeviceD3D::SetCurrentMaterial((RenderDeviceD3D *)RenderDevice::render_device, 0, 0);
      Render::SetSurfaceArray(v5->surfaces);
      LODWORD(Render::object_scale_vec.x) = 1065353216;
      dword_81EEB4 = 1065353216;
      dword_81EEB8 = 1065353216;
      LODWORD(Render::object_scale) = 1065353216;
      Render::positionPush(3, &v5->pos);
      v6 = v5->num_view;
      if ( v6 )
      {
        v7 = v5->portal_view.data[v6 - 1]->view_count;
        if ( !(_WORD)v7 )
        {
LABEL_19:
          Render::framePop();
          goto LABEL_20;
        }
      }
      else
      {
        LOWORD(v7) = -1;
      }
      v8 = 0;
      v20 = (unsigned __int16)v7;
      do
      {
        CEnvCell::setup_view(v5, v8);
        v9 = 0;
        if ( v5->num_portals )
        {
          v10 = 0;
          do
          {
            v11 = v5->portals;
            if ( v11[v10].other_cell_id == -1 )
              D3DPolyRender::DrawPortalPolyInternal(v11[v10].portal, 0);
            ++v9;
            ++v10;
          }
          while ( v9 < v5->num_portals );
          v2 = v22;
        }
        ++v8;
        --v20;
      }
      while ( v20 );
      v4 = iq;
      goto LABEL_19;
    }
  }
LABEL_21:
  Render::useSunlightSet(0);
  Render::restore_all_lighting();
  v12 = v2->cell_draw_num;
  if ( v12 )
  {
    while ( 1 )
    {
      v13 = v2->cell_draw_list.data[v12 - 1];
      if ( v13->structure->drawing_bsp )
        break;
LABEL_30:
      --v12;
      if ( !v12 )
        goto LABEL_31;
    }
    RenderDeviceD3D::SetCurrentMaterial((RenderDeviceD3D *)RenderDevice::render_device, 0, 0);
    Render::SetSurfaceArray(v13->surfaces);
    LODWORD(Render::object_scale_vec.x) = 1065353216;
    dword_81EEB4 = 1065353216;
    dword_81EEB8 = 1065353216;
    LODWORD(Render::object_scale) = 1065353216;
    Render::positionPush(3, &v13->pos);
    v14 = v13->num_view;
    if ( v14 )
    {
      v15 = v13->portal_view.data[v14 - 1]->view_count;
      if ( !(_WORD)v15 )
      {
LABEL_29:
        Render::framePop();
        goto LABEL_30;
      }
    }
    else
    {
      LOWORD(v15) = -1;
    }
    v16 = 0;
    v17 = (unsigned __int16)v15;
    do
    {
      CEnvCell::setup_view(v13, v16);
      ((void (__stdcall *)(CEnvCell *))RenderDevice::render_device->vfptr->DrawEnvCell)(v13);
      ++v16;
      --v17;
    }
    while ( v17 );
    v2 = v22;
    goto LABEL_29;
  }
LABEL_31:
  for ( i = v2->cell_draw_num; i; --i )
  {
    v19 = v2->cell_draw_list.data[i - 1];
    Render::PortalList = v19->portal_view.data[v19->num_view - 1];
    ((void (__stdcall *)(CEnvCell *))RenderDevice::render_device->vfptr->DrawObjCellForDummies)(v19);
  }
  LODWORD(Render::object_scale_vec.x) = 1065353216;
  dword_81EEB4 = 1065353216;
  dword_81EEB8 = 1065353216;
  LODWORD(Render::object_scale) = 1065353216;
  Render::useSunlightSet(1);
}
// 81EC74: using guessed type float Render::object_scale;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;
// 866320: using guessed type struct portal_view_type *Render::PortalList;
// 8719B4: using guessed type unsigned __int16 D3DPolyRender::portalsDrawnCount;

//----- (005A4B70) --------------------------------------------------------  // acclient.c:461624
int __stdcall PView::InitCell(CEnvCell *cell, unsigned __int16 portal_in)
{
  CEnvCell *v3; // ebp@1
  portal_view_type *v4; // esi@1
  unsigned int v5; // ebx@1
  unsigned int v7; // ecx@3
  unsigned int v8; // eax@3
  int v9; // edx@6
  int v10; // ecx@7
  double v11; // st7@10
  signed int v12; // eax@11
  int v13; // eax@18
  int v14; // ecx@19
  int v15; // edi@19
  double v16; // st7@20
  double v17; // st6@20
  double v18; // st5@20
  double v19; // st4@20
  int v20; // edi@26
  unsigned int v21; // ecx@27
  int v22; // eax@28
  int v23; // [sp+Ch] [bp-8h]@6
  int out_portal; // [sp+10h] [bp-4h]@0
  float cella; // [sp+18h] [bp+4h]@3

  v3 = cell;
  v4 = cell->portal_view.data[cell->num_view - 1];
  v5 = 0;
  if ( !v4->view_count )
    return 0;
  Render::positionPush(3, &cell->pos);
  v7 = v4->portal.sizeOf;
  v4->cell_view_done = 0;
  v4->view_timestamp = PView::master_timestamp;
  v8 = cell->num_portals;
  cella = 0.0;
  if ( v7 < v8 )
    DArray<portal_info>::grow(&v4->portal, v8);
  if ( v3->num_portals )
  {
    v9 = 0;
    v23 = 0;
    do
    {
      v10 = *(int *)((char *)&v3->portals->portal + v9);
      if ( v5 == portal_in && !v4->portal.data[v5].inflag )
      {
        v4->portal.data[v5].inflag = 1;
        v4->portal.data[v5].seen = 1;
        goto LABEL_17;
      }
      v4->portal.data[v5].seen = 0;
      v11 = Render::FrameCurrent->z * *(float *)(v10 + 40)
          + Render::FrameCurrent->y * *(float *)(v10 + 36)
          + *(float *)(v10 + 32) * Render::FrameCurrent->x
          + *(float *)(v10 + 44);
      if ( v11 <= 0.00019999999 )
      {
        if ( v11 >= -0.00019999999 )
          goto LABEL_16;
        v12 = 1;
      }
      else
      {
        v12 = 0;
      }
      if ( v12 != *(int *)((char *)&v3->portals->portal_side + v9) )
      {
        v4->portal.data[v5].inflag = 1;
        goto LABEL_17;
      }
LABEL_16:
      v4->portal.data[v5].inflag = 0;
      out_portal = 1;
LABEL_17:
      if ( v4->portal.data[v5].inflag == 1 )
      {
        v13 = *(_BYTE *)(v10 + 14);
        if ( *(_BYTE *)(v10 + 14) )
        {
          v14 = *(_DWORD *)v10;
          v15 = v13;
          do
          {
            v16 = Render::FrameCurrent->x - **(float **)v14;
            v17 = Render::FrameCurrent->y - *(float *)(*(_DWORD *)v14 + 4);
            v18 = Render::FrameCurrent->z - *(float *)(*(_DWORD *)v14 + 8);
            v19 = v18 * v18 + v16 * v16 + v17 * v17;
            if ( v19 > cella )
              cella = v19;
            v14 += 4;
            --v15;
          }
          while ( v15 );
          v9 = v23;
        }
      }
      ++v5;
      v9 += 24;
      v23 = v9;
    }
    while ( v5 < v3->num_portals );
  }
  v4->max_indist = cella;
  if ( out_portal )
  {
    v20 = 0;
    if ( v4->view_count )
    {
      do
      {
        Render::set_view(&v4->view, v20);
        v21 = 0;
        if ( v3->num_portals )
        {
          do
          {
            v22 = (int)&v4->portal.data[v21].seen;
            if ( !*(_DWORD *)(v22 + 4) && !*(_DWORD *)v22 )
              *(_DWORD *)v22 = 1;
            ++v21;
          }
          while ( v21 < v3->num_portals );
        }
        ++v20;
      }
      while ( v20 < v4->view_count );
    }
  }
  v4->update_count = v4->view_count;
  Render::framePop();
  return 1;
}
// 8ED6B8: using guessed type unsigned __int32 PView::master_timestamp;

//----- (005A4D90) --------------------------------------------------------  // acclient.c:461760
void __stdcall PView::AddToCell(CEnvCell *cell, unsigned __int16 portal_in)
{
  portal_view_type *v3; // esi@1
  int i; // ebx@1
  unsigned int v5; // eax@2
  int v6; // ecx@6

  Render::positionPush(3, &cell->pos);
  v3 = cell->portal_view.data[cell->num_view - 1];
  for ( i = v3->update_count; i < v3->view_count; ++i )
  {
    Render::set_view(&v3->view, i);
    v5 = 0;
    if ( cell->num_portals )
    {
      do
      {
        if ( v5 == portal_in && !v3->portal.data[v5].inflag )
          v3->portal.data[v5].inflag = 1;
        v6 = (int)&v3->portal.data[v5].seen;
        if ( !*(_DWORD *)(v6 + 4) && !*(_DWORD *)v6 )
          *(_DWORD *)v6 = 1;
        ++v5;
      }
      while ( v5 < cell->num_portals );
    }
  }
  Render::framePop();
}

//----- (005A4E30) --------------------------------------------------------  // acclient.c:461791
void __stdcall PView::SetOtherSeen(CEnvCell *pres_cell, unsigned int portal_id)
{
  CCellPortal *v3; // ecx@1
  CEnvCell *v4; // eax@1
  int v5; // ecx@1
  int v6; // edx@1
  int v7; // eax@1

  v3 = &pres_cell->portals[portal_id];
  v4 = v3->other_cell_ptr;
  v5 = v3->other_portal_id;
  v6 = (int)&v4->portals[v5];
  v7 = (int)&v4->portal_view.data[v4->num_view - 1]->portal.data[v5].seen;
  if ( !*(_DWORD *)(v6 + 4) )
    *(_DWORD *)(v6 + 4) = pres_cell;
  if ( *(_DWORD *)(v7 + 4) )
    *(_DWORD *)v7 = 1;
}

//----- (005A4E90) --------------------------------------------------------  // acclient.c:461811
int __thiscall PView::AdjustDrawList(PView *this, CEnvCell *cell_in_list, CEnvCell *new_cell)
{
  PView *v3; // ebx@1
  unsigned int v4; // esi@1
  unsigned int v5; // ebp@2
  CEnvCell **v6; // edx@2
  CEnvCell **v7; // eax@2
  unsigned int v8; // ecx@3
  unsigned int v10; // edi@7
  int v11; // eax@8
  unsigned int v12; // eax@11
  unsigned int i; // eax@15
  CEnvCell *v14; // edx@16
  int v15; // ecx@16
  DArray<CEnvCell *> *v16; // [sp+10h] [bp-4h]@2

  v3 = this;
  v4 = 0;
  if ( this->cell_draw_num )
  {
    v5 = new_cell->m_DID.id;
    v6 = this->cell_draw_list.data;
    v16 = &this->cell_draw_list;
    v7 = this->cell_draw_list.data;
    do
    {
      v8 = (*v7)->m_DID.id;
      if ( v8 == v5 )
        break;
      if ( v8 == cell_in_list->m_DID.id )
      {
        v10 = v4;
        if ( v4 < v3->cell_draw_num )
        {
          v11 = (int)&v6[v4];
          do
          {
            if ( *(_DWORD *)(*(_DWORD *)v11 + 40) == v5 )
              break;
            ++v10;
            v11 += 4;
          }
          while ( v10 < v3->cell_draw_num );
        }
        v12 = v3->cell_draw_num;
        if ( v10 == v12 )
        {
          if ( v12 >= v3->cell_draw_list.sizeOf )
            DArray<CEnvCell *>::grow(v16, v12 + 100);
          ++v3->cell_draw_num;
        }
        for ( i = v10; i > v4; *(_DWORD *)v15 = v14 )
        {
          v14 = v16->data[i - 1];
          v15 = (int)&v16->data[i--];
        }
        v16->data[v4] = new_cell;
        return 1;
      }
      ++v4;
      ++v7;
    }
    while ( v4 < v3->cell_draw_num );
  }
  return 0;
}

//----- (005A4F50) --------------------------------------------------------  // acclient.c:461879
void __thiscall PView::InsCellTodoList(PView *this, CEnvCell *cell, float dist)
{
  PView *v3; // esi@1
  unsigned int v4; // eax@1
  char *v5; // edi@2
  unsigned int i; // eax@2
  void *v7; // eax@5
  CellListType *v8; // ebx@9
  unsigned int j; // ecx@9
  CellListType **v10; // edx@10
  CellListType *v11; // edi@10
  int v12; // edx@10

  v3 = this;
  v4 = this->cell_todo_num;
  if ( v4 >= this->cell_todo_list.sizeOf )
  {
    v5 = (char *)&this->cell_todo_list;
    DArray<CellListType *>::grow(&this->cell_todo_list, v4 + 30);
    for ( i = v3->cell_todo_num; i < v3->cell_todo_list.sizeOf; ++i )
      *(_DWORD *)(*(_DWORD *)v5 + 4 * i) = 0;
  }
  if ( !v3->cell_todo_list.data[v3->cell_todo_num] )
  {
    v7 = operator new(8u);
    if ( v7 )
    {
      *(_DWORD *)v7 = 0;
      *((_DWORD *)v7 + 1) = 0;
    }
    else
    {
      v7 = 0;
    }
    v3->cell_todo_list.data[v3->cell_todo_num] = (CellListType *)v7;
  }
  v8 = v3->cell_todo_list.data[v3->cell_todo_num];
  v8->cell = cell;
  v8->dist = dist;
  for ( j = v3->cell_todo_num; j; *(_DWORD *)v12 = v11 )
  {
    v10 = v3->cell_todo_list.data;
    v11 = v10[j - 1];
    v12 = (int)&v10[j];
    if ( dist < (double)v11->dist )
      break;
    --j;
  }
  v3->cell_todo_list.data[j] = v8;
  ++v3->cell_todo_num;
}

//----- (005A5010) --------------------------------------------------------  // acclient.c:461932
void __thiscall PView::AdjustCellPlace(PView *this, CEnvCell *cell_in_list, CEnvCell *new_cell)
{
  CEnvCell *v3; // esi@1
  PView *v4; // ebp@1
  CEnvCell *v5; // ST0C_4@1
  unsigned int v6; // edi@2
  int v7; // ebx@3
  CEnvCell *new_cella; // [sp+10h] [bp+8h]@1

  v3 = new_cell;
  v4 = this;
  v5 = new_cell;
  new_cella = (CEnvCell *)new_cell->portal_view.data[new_cell->num_view - 1];
  if ( PView::AdjustDrawList(this, cell_in_list, v5) )
  {
    v6 = 0;
    if ( v3->num_portals )
    {
      v7 = 0;
      do
      {
        if ( *((_DWORD *)&new_cella->vfptr->IUnknown_QueryInterface + 2 * v6) == 1
          && *((_DWORD *)&new_cella->vfptr->IUnknown_AddRef + 2 * v6) == 1 )
          PView::AdjustCellPlace(v4, v3, v3->portals[v7].other_cell_ptr);
        ++v6;
        ++v7;
      }
      while ( v6 < v3->num_portals );
    }
  }
}

//----- (005A5090) --------------------------------------------------------  // acclient.c:461965
void __thiscall CEnvCell::curr_view_push(CEnvCell *this)
{
  CEnvCell *v1; // esi@1
  unsigned int v2; // eax@1
  void *v3; // eax@4

  v1 = this;
  v2 = this->num_view;
  if ( v2 >= this->portal_view.sizeOf )
  {
    DArray<portal_view_type *>::grow(&this->portal_view, v2 + 1);
    v1->portal_view.data[v1->num_view] = 0;
  }
  if ( !v1->portal_view.data[v1->num_view] )
  {
    v3 = operator new(0x48u);
    if ( v3 )
    {
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 3) = 0;
      *((_DWORD *)v3 + 2) = 0;
      *((_DWORD *)v3 + 1) = 128;
      *((_DWORD *)v3 + 5) = 0;
      *((_DWORD *)v3 + 8) = 0;
      *((_DWORD *)v3 + 7) = 0;
      *((_DWORD *)v3 + 6) = 128;
      *((_DWORD *)v3 + 9) = 0;
      *((_DWORD *)v3 + 12) = 0;
      *((_DWORD *)v3 + 11) = 0;
      *((_DWORD *)v3 + 10) = 128;
      *((_DWORD *)v3 + 16) = 0;
    }
    else
    {
      v3 = 0;
    }
    v1->portal_view.data[v1->num_view] = (portal_view_type *)v3;
  }
  v1->portal_view.data[v1->num_view]->view_count = 0;
  v1->portal_view.data[v1->num_view]->update_count = 0;
  v1->portal_view.data[v1->num_view++]->view_timestamp = 0;
}

//----- (005A5170) --------------------------------------------------------  // acclient.c:462009
void __thiscall PView::~PView(PView *this)
{
  PView *v1; // esi@1
  unsigned int v2; // edi@1
  view_vertex *v3; // ecx@5
  float v4; // eax@6
  void *v5; // ebp@6
  int v6; // edx@6
  int v7; // eax@6
  DiskSpace *v8; // edi@6
  int v9; // ebx@7

  v1 = this;
  v2 = 0;
  if ( this->cell_todo_list.sizeOf )
  {
    do
    {
      if ( v1->cell_todo_list.data[v2] )
      {
        operator delete(v1->cell_todo_list.data[v2]);
        v1->cell_todo_list.data[v2] = 0;
      }
      ++v2;
    }
    while ( v2 < v1->cell_todo_list.sizeOf );
  }
  operator delete[](v1->cell_todo_list.data);
  v1->cell_todo_list.data = 0;
  operator delete[](v1->cell_draw_list.data);
  v1->cell_draw_list.data = 0;
  v3 = v1->outside_view.view.vertex.data;
  if ( v3 )
  {
    v4 = v3[-1].plane.d;
    v5 = &v3[-1].plane.d;
    v6 = 3 * LODWORD(v4);
    v7 = LODWORD(v4) - 1;
    v8 = (DiskSpace *)&v3[8 * v6 / 0x18u];
    if ( v7 >= 0 )
    {
      v9 = v7 + 1;
      do
      {
        v8 -= 24;
        gmNoticeHandler::RecvNotice_PrevSpellSelection(v8);
        --v9;
      }
      while ( v9 );
    }
    operator delete[](v5);
  }
  v1->outside_view.view.vertex.data = 0;
  operator delete[](v1->outside_view.view.poly.data);
  v1->outside_view.view.poly.data = 0;
  operator delete[](v1->outside_view.portal.data);
  v1->outside_view.portal.data = 0;
}

//----- (005A5210) --------------------------------------------------------  // acclient.c:462069
void __stdcall PView::add_views(unsigned __int16 num_stabs, unsigned int *stab_list)
{
  unsigned int *v3; // esi@2
  int v4; // edi@2
  CEnvCell *v5; // eax@3

  if ( num_stabs )
  {
    v3 = stab_list;
    v4 = num_stabs;
    do
    {
      v5 = (CEnvCell *)CEnvCell::GetVisible(*v3);
      if ( v5 )
        CEnvCell::curr_view_push(v5);
      ++v3;
      --v4;
    }
    while ( v4 );
  }
}

//----- (005A5250) --------------------------------------------------------  // acclient.c:462092
void __thiscall PView::FixCellList(PView *this, CEnvCell *cell_in_list, CEnvCell *new_cell)
{
  PView *v3; // esi@1

  v3 = this;
  PView::AdjustCellPlace(this, cell_in_list, new_cell);
  PView::AdjustCellView(v3, cell_in_list);
}

//----- (005A5270) --------------------------------------------------------  // acclient.c:462102
void __thiscall PView::PView(PView *this, int draw_lscape)
{
  this->outside_view.portal.data = 0;
  this->outside_view.portal.sizeOf = 0;
  this->outside_view.portal.next_available = 0;
  this->outside_view.portal.blocksize = 128;
  this->outside_view.view.poly.data = 0;
  this->outside_view.view.poly.sizeOf = 0;
  this->outside_view.view.poly.next_available = 0;
  this->outside_view.view.poly.blocksize = 128;
  this->outside_view.view.vertex.data = 0;
  this->outside_view.view.vertex.sizeOf = 0;
  this->outside_view.view.vertex.next_available = 0;
  this->outside_view.view.vertex.blocksize = 128;
  this->outside_view.view_timestamp = 0;
  this->cell_draw_list.data = 0;
  this->cell_draw_list.sizeOf = 0;
  this->cell_draw_list.next_available = 0;
  this->cell_draw_list.blocksize = 128;
  this->cell_todo_list.data = 0;
  this->cell_todo_list.sizeOf = 0;
  this->cell_todo_list.next_available = 0;
  this->cell_todo_list.blocksize = 128;
  this->cell_todo_num = 0;
  this->lscape = 0;
  this->draw_landscape = draw_lscape;
}

//----- (005A52D0) --------------------------------------------------------  // acclient.c:462131
void __thiscall PView::AddViewToPortals(PView *this, CEnvCell *pres_cell)
{
  CEnvCell *v2; // ebp@1
  int v3; // eax@1
  int v4; // ebx@3
  int v5; // esi@3
  int v6; // eax@3
  int v7; // eax@6
  int v8; // edi@7
  int v9; // eax@7
  int v10; // ecx@8
  bool v11; // cf@17
  PView *v12; // [sp+4h] [bp-8h]@1
  unsigned int iq; // [sp+8h] [bp-4h]@1
  CEnvCell *pres_cella; // [sp+10h] [bp+4h]@2

  v2 = pres_cell;
  v3 = 0;
  v12 = this;
  iq = 0;
  if ( pres_cell->num_portals )
  {
    pres_cella = 0;
    while ( 1 )
    {
      v4 = (int)((char *)pres_cella + (unsigned int)v2->portals);
      v5 = *(_DWORD *)(v4 + 4);
      v6 = (int)&v2->portal_view.data[v2->num_view - 1]->portal.data[v3].seen;
      if ( !v5 )
        goto LABEL_17;
      if ( *(_DWORD *)(v6 + 4) == 1 )
        goto LABEL_17;
      if ( !*(_DWORD *)v6 )
        goto LABEL_17;
      v7 = *(_DWORD *)(v5 + 308);
      if ( !v7 )
        goto LABEL_17;
      v8 = *(_DWORD *)(*(_DWORD *)(v5 + 312) + 4 * v7 - 4);
      v9 = *(_DWORD *)(v8 + 56);
      if ( !v9 )
        goto LABEL_17;
      v10 = *(_DWORD *)(v8 + 68);
      if ( !v10 )
        break;
      if ( v10 != v9 )
      {
        PView::AddToCell((CEnvCell *)v5, *(_WORD *)(v4 + 16));
        if ( *(_DWORD *)(v8 + 60) )
        {
          PView::FixCellList(v12, (CEnvCell *)v5, v2);
          *(_DWORD *)(v8 + 68) = *(_DWORD *)(v8 + 56);
        }
        else
        {
          *(_DWORD *)(v8 + 68) = *(_DWORD *)(v8 + 56);
        }
LABEL_15:
        if ( *(_DWORD *)(v4 + 16) >= 0 )
          PView::SetOtherSeen(v2, iq);
      }
LABEL_17:
      v3 = iq + 1;
      v11 = iq++ + 1 < v2->num_portals;
      pres_cella = (CEnvCell *)((char *)pres_cella + 24);
      if ( !v11 )
        return;
    }
    if ( PView::InitCell((CEnvCell *)v5, *(_WORD *)(v4 + 16)) )
      PView::InsCellTodoList(v12, (CEnvCell *)v5, *(float *)(v8 + 52));
    goto LABEL_15;
  }
}

//----- (005A5400) --------------------------------------------------------  // acclient.c:462205
int __stdcall PView::OtherPortalClip(CCellPortal *portal, Vec2Dscreen **clip_view, int *clip_pts)
{
  int result; // eax@3
  CEnvCell *v5; // eax@4
  CCellPortal *v6; // ecx@4
  int v7; // esi@4
  Sidedness v8; // ebp@4

  if ( !(_S225_32 & 1) )
  {
    _S225_32 |= 1u;
    temp_view.portal.data = 0;
    unk_8ED834 = 0;
    unk_8ED830 = 0;
    unk_8ED82C = 128;
    dword_8ED83C = 0;
    unk_8ED848 = 0;
    unk_8ED844 = 0;
    unk_8ED840 = 128;
    stru_8ED84C.data = 0;
    stru_8ED84C.sizeOf = 0;
    stru_8ED84C.next_available = 0;
    stru_8ED84C.blocksize = 128;
    unk_8ED868 = 0;
    atexit(_E226_26);
  }
  unk_8ED860 = 0;
  result = Render::copy_view(&temp_view, clip_view, *clip_pts);
  if ( result )
  {
    v5 = portal->other_cell_ptr;
    v6 = v5->portals;
    v7 = (int)&v6[portal->other_portal_id];
    v8 = v6[portal->other_portal_id].portal_side == 0;
    Render::positionPush(3, &v5->pos);
    Render::set_view(&unk_8ED838, 0);
    PView::GetClip(v8, *(CPolygon **)(v7 + 8), clip_view, clip_pts, 1);
    Render::framePop();
    result = *clip_pts != 0;
  }
  return result;
}

//----- (005A5520) --------------------------------------------------------  // acclient.c:462249
int __thiscall PView::ClipPortals(PView *this, CEnvCell *pres_cell, unsigned int first_view)
{
  CEnvCell *v3; // ebp@1
  unsigned int v4; // eax@1
  struct portal_view_type *v5; // eax@1
  unsigned int v6; // ecx@1
  int v7; // ebx@1
  signed int v8; // edi@1
  int v9; // ecx@4
  int v10; // eax@4
  CCellPortal *v11; // esi@6
  CEnvCell *v12; // eax@6
  int v13; // esi@6
  RenderVertexStreamD3D *v14; // eax@8
  CEnvCell *v16; // esi@13
  unsigned int v17; // edi@13
  unsigned int v18; // ecx@14
  int v19; // eax@14
  int v20; // eax@16
  CCellPortal *v21; // esi@18
  CPolygon *v22; // eax@18
  Sidedness v23; // ecx@18
  PView *v24; // ebx@18
  int v25; // esi@18
  int v26; // ecx@18
  int v27; // edi@19
  int v28; // eax@20
  int v29; // eax@31
  unsigned int v30; // ecx@33
  bool v31; // sf@33
  unsigned __int8 v32; // of@33
  int clip_pts; // [sp+10h] [bp-10h]@18
  int out_portal; // [sp+14h] [bp-Ch]@1
  int jq; // [sp+18h] [bp-8h]@14
  PView *v36; // [sp+1Ch] [bp-4h]@1
  CEnvCell *pres_cella; // [sp+24h] [bp+4h]@1

  v3 = pres_cell;
  v4 = pres_cell->num_view;
  v36 = this;
  v5 = pres_cell->portal_view.data[v4 - 1];
  Render::PortalList = v5;
  v6 = pres_cell->num_portals;
  v7 = 0;
  v8 = 0;
  pres_cella = (CEnvCell *)v5;
  out_portal = 0;
  if ( (signed int)v6 <= 0 )
    return 0;
  while ( 1 )
  {
    v9 = v5->portal.data[v8].seen;
    v10 = (int)&v5->portal.data[v8].seen;
    if ( v9 )
    {
      if ( *(_DWORD *)(v10 + 4) != 1 )
      {
        v11 = v3->portals;
        v12 = v11[v7].other_cell_ptr;
        v13 = (int)&v11[v7];
        if ( v12
          || *(_DWORD *)v13 == -1
          || (v14 = CEnvCell::GetVisible(*(_DWORD *)v13), (*(_DWORD *)(v13 + 4) = v14) != 0) )
          out_portal = 1;
      }
    }
    ++v8;
    ++v7;
    if ( v8 >= (signed int)v3->num_portals )
      break;
    v5 = (struct portal_view_type *)pres_cella;
  }
  if ( !out_portal )
    return 0;
  Render::positionPush(3, &v3->pos);
  v16 = pres_cella;
  v17 = first_view;
  if ( (signed int)first_view >= (signed int)pres_cella->vfptr )
    goto LABEL_36;
  do
  {
    Render::set_view((view_type *)&v16->m_timeStamp, v17);
    v18 = v3->num_portals;
    v19 = 0;
    jq = 0;
    if ( (signed int)v18 <= 0 )
      goto LABEL_35;
    out_portal = 0;
    do
    {
      v20 = (int)((char *)v16->vfptr + 8 * v19);
      if ( *(_DWORD *)v20 )
      {
        if ( *(_DWORD *)(v20 + 4) != 1 )
        {
          v21 = v3->portals;
          v22 = *(CPolygon **)((char *)&v21->portal + out_portal);
          v23 = *(int *)((char *)&v21->portal_side + out_portal);
          v24 = v36;
          v25 = (int)((char *)v21 + out_portal);
          PView::GetClip(v23, v22, clip_view, &clip_pts, 1);
          v26 = clip_pts;
          if ( clip_pts )
          {
            v27 = *(_DWORD *)(v25 + 4);
            if ( *(_DWORD *)v25 == -1 )
            {
              v28 = v24->draw_landscape;
              if ( v28 )
              {
                if ( cliplandscape )
                {
                  Render::copy_view(&v24->outside_view, clip_view, clip_pts);
                }
                else if ( v28 )
                {
                  Render::copy_view(&v24->outside_view, 0, 0);
                }
              }
            }
            else
            {
              if ( !v27 )
                goto LABEL_33;
              if ( !*(_DWORD *)(v25 + 20) && *(_DWORD *)(v25 + 16) >= 0 )
              {
                if ( !PView::OtherPortalClip((CCellPortal *)v25, clip_view, &clip_pts) )
                {
                  Render::set_view((view_type *)&pres_cella->m_timeStamp, first_view);
                  goto LABEL_33;
                }
                Render::set_view((view_type *)&pres_cella->m_timeStamp, first_view);
                v26 = clip_pts;
              }
              v29 = *(_DWORD *)(v27 + 308);
              if ( v29 )
                Render::copy_view(*(portal_view_type **)(*(_DWORD *)(v27 + 312) + 4 * v29 - 4), clip_view, v26);
            }
          }
        }
      }
LABEL_33:
      v30 = v3->num_portals;
      v16 = pres_cella;
      v19 = jq + 1;
      v32 = __OFSUB__(jq + 1, v30);
      v31 = ((jq++ + 1 - v30) & 0x80000000) != 0;
      out_portal += 24;
    }
    while ( v31 ^ v32 );
    v17 = first_view;
LABEL_35:
    ++v17;
    first_view = v17;
  }
  while ( (signed int)v17 < (signed int)v16->vfptr );
LABEL_36:
  Render::framePop();
  return 1;
}
// 866320: using guessed type struct portal_view_type *Render::PortalList;

//----- (005A5770) --------------------------------------------------------  // acclient.c:462412
void __thiscall PView::AdjustCellView(PView *this, CEnvCell *pres_cell)
{
  PView *v2; // edi@1

  v2 = this;
  if ( PView::ClipPortals(this, pres_cell, pres_cell->portal_view.data[pres_cell->num_view - 1]->update_count) )
    PView::AddViewToPortals(v2, pres_cell);
}

//----- (005A57B0) --------------------------------------------------------  // acclient.c:462422
void __thiscall PView::ConstructView(PView *this, CEnvCell *cell, unsigned __int16 portal_in)
{
  PView *v3; // esi@1
  unsigned int v4; // eax@2
  CellListType **v5; // ecx@3
  int v6; // eax@3
  CEnvCell *v7; // edi@3
  unsigned int v8; // eax@4
  unsigned int v9; // eax@6
  CEnvCell **v10; // edx@6

  v3 = this;
  this->outside_view.view_count = 0;
  ++PView::master_timestamp;
  this->cell_todo_num = 0;
  this->cell_draw_num = 0;
  PView::InitCell(cell, portal_in);
  PView::InsCellTodoList(v3, cell, 0.0);
  while ( 1 )
  {
    v4 = v3->cell_todo_num;
    if ( !v4 )
      break;
    v5 = v3->cell_todo_list.data;
    v6 = v4 - 1;
    v3->cell_todo_num = v6;
    v7 = v5[v6]->cell;
    if ( !v7 )
      break;
    v8 = v3->cell_draw_num;
    if ( v8 >= v3->cell_draw_list.sizeOf )
      DArray<CEnvCell *>::grow(&v3->cell_draw_list, v8 + 30);
    v9 = v3->cell_draw_num;
    v10 = v3->cell_draw_list.data;
    v3->cell_draw_num = v9 + 1;
    v10[v9] = v7;
    v7->portal_view.data[v7->num_view - 1]->cell_view_done = 1;
    if ( PView::ClipPortals(v3, v7, 0) )
      PView::AddViewToPortals(v3, v7);
  }
}
// 8ED6B8: using guessed type unsigned __int32 PView::master_timestamp;

//----- (005A5860) --------------------------------------------------------  // acclient.c:462466
void __thiscall PView::DrawInside(PView *this, CEnvCell *cell)
{
  CEnvCell *v2; // esi@1
  PView *v3; // edi@1
  Position dummy; // [sp+14h] [bp-48h]@1

  v2 = cell;
  v3 = this;
  dword_81EEB4 = 1065353216;
  LODWORD(Render::object_scale_vec.x) = 1065353216;
  dword_81EEB8 = 1065353216;
  LODWORD(Render::object_scale) = 1065353216;
  CEnvCell::curr_view_push(cell);
  PView::add_views(LOWORD(v2->num_stabs), v2->stab_list);
  dummy.vfptr = (PackObjVtbl *)&Position::vftable;
  dummy.objcell_id = 0;
  LODWORD(dummy.frame.qw) = 1065353216;
  LODWORD(dummy.frame.qx) = 0;
  LODWORD(dummy.frame.qy) = 0;
  LODWORD(dummy.frame.qz) = 0;
  LODWORD(dummy.frame.m_fOrigin.x) = 0;
  LODWORD(dummy.frame.m_fOrigin.y) = 0;
  LODWORD(dummy.frame.m_fOrigin.z) = 0;
  Frame::cache(&dummy.frame);
  dummy.objcell_id = cell->m_DID.id;
  Render::positionPush(3, &dummy);
  Render::copy_view(v2->portal_view.data[v2->num_view - 1], 0, 4u);
  PView::ConstructView(v3, cell, 0xFFFFu);
  PView::DrawCells(v3, 0);
  Render::framePop();
  PView::remove_views(LOWORD(v2->num_stabs), v2->stab_list);
  --v2->num_view;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 81EC74: using guessed type float Render::object_scale;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;

//----- (005A59A0) --------------------------------------------------------  // acclient.c:462506
int __thiscall PView::ConstructView(PView *this, CBldPortal *outside_portal, CPolygon *ppoly, int check, int portalPolyOrPortalContents)
{
  CPolygon *v5; // esi@1
  PView *v6; // ebp@1
  double v7; // st7@1
  Sidedness v8; // eax@2
  RenderVertexStreamD3D *v10; // eax@10
  CEnvCell *v11; // edi@10
  int v12; // ebx@12

  v5 = ppoly;
  v6 = this;
  v7 = Render::FrameCurrent->z * ppoly->plane.N.z
     + Render::FrameCurrent->y * ppoly->plane.N.y
     + Render::FrameCurrent->x * ppoly->plane.N.x
     + ppoly->plane.d;
  if ( v7 <= 0.00019999999 )
  {
    v8 = 1;
    if ( v7 >= -0.00019999999 )
      v8 = 2;
  }
  else
  {
    v8 = 0;
  }
  if ( outside_portal->portal_side )
  {
    if ( v8 != 1 )
      return 0;
  }
  else if ( v8 )
  {
    return 0;
  }
  PView::GetClip(v8, ppoly, clip_view_0, (int *)&ppoly, check);
  if ( !ppoly )
    return 0;
  v10 = CEnvCell::GetVisible(outside_portal->other_cell_id);
  v11 = (CEnvCell *)v10;
  if ( !v10
    || !Render::copy_view(
          *(portal_view_type **)(v10[1].m_VertexFormatInfo.offsetTCPair[3]
                               + 4 * v10[1].m_VertexFormatInfo.offsetTCPair[2]
                               - 4),
          clip_view_0,
          (unsigned int)ppoly) )
    return 0;
  v12 = portalPolyOrPortalContents;
  if ( portalPolyOrPortalContents != 2 )
    D3DPolyRender::DrawPortalPolyInternal(v5, portalPolyOrPortalContents == 1);
  Render::framePop();
  if ( v12 != 1 )
    PView::ConstructView(v6, v11, LOWORD(outside_portal->other_portal_id));
  return 1;
}

//----- (005A5AB0) --------------------------------------------------------  // acclient.c:462564
void __thiscall PView::DrawPortal(PView *this, CPortalPoly *portal, int check, int portalPolyOrPortalContents)
{
  PView *v4; // esi@1
  CBldPortal *v5; // edi@1
  CPolygon *v6; // ebx@1

  v4 = this;
  ((void (*)(void))Render::m_pRenderer->vfptr->polyListFinishInternal)();
  Render::PolyNext = (struct polyListEntry *)&Render::PolyList;
  ACRender::backup_curr_state();
  LODWORD(Render::object_scale) = 1065353216;
  dword_81EEB8 = 1065353216;
  LODWORD(Render::object_scale_vec.x) = 1065353216;
  dword_81EEB4 = 1065353216;
  v5 = v4->outdoor_portal_list[portal->portal_index];
  v6 = portal->portal;
  PView::add_views(LOWORD(v5->num_stabs), v5->stab_list);
  if ( PView::ConstructView(v4, v5, v6, check, portalPolyOrPortalContents) )
  {
    if ( portalPolyOrPortalContents != 1 )
      PView::DrawCells(v4, 1);
    ACRender::restore_curr_state();
    Render::positionPush(3, CBuildingObj::curr_pos);
    Render::obj_view_set();
  }
  else
  {
    if ( portalPolyOrPortalContents == 3 )
      D3DPolyRender::DrawPortalPolyInternal(v6, 0);
    ACRender::restore_curr_state();
  }
  PView::remove_views(LOWORD(v5->num_stabs), v5->stab_list);
}
// 81EC74: using guessed type float Render::object_scale;
// 81EEB0: using guessed type struct Vector3 Render::object_scale_vec;
// 81EEB4: using guessed type int dword_81EEB4;
// 81EEB8: using guessed type int dword_81EEB8;
// 8662D8: using guessed type struct polyListEntry *Render::PolyNext;

//----- (0070CB90) --------------------------------------------------------  // acclient.c:799612
int sub_70CB90()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_37, "Display.Resolution");
  return atexit(_E74_88);
}

//----- (0070CBB0) --------------------------------------------------------  // acclient.c:799619
int _E76_72()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_37, "Display.FullScreen");
  return atexit(sub_776A90);
}

//----- (0070CBD0) --------------------------------------------------------  // acclient.c:799626
int _E79_66()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_37, "Display.RefreshRate");
  return atexit(_E80_65);
}

//----- (0070CBF0) --------------------------------------------------------  // acclient.c:799633
int _E82_44()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_37, "Display.SyncToRefresh");
  return atexit(_E83_42);
}

//----- (0070CC10) --------------------------------------------------------  // acclient.c:799640
void _E101_40()
{
  dword_8ED6E8 = 1024;
}

//----- (0070CC20) --------------------------------------------------------  // acclient.c:799646
void sub_70CC20()
{
  dword_8ED6EC = 0x7FFF;
}

//----- (0070CC30) --------------------------------------------------------  // acclient.c:799652
int _E105_54()
{
  const int result; // eax@1

  result = dword_8ED6E8;
  dword_8ED6F0 = dword_8ED6E8;
  return result;
}

//----- (0070CC40) --------------------------------------------------------  // acclient.c:799662
void _E107_44()
{
  LODWORD(dword_8ED6F4) = 1053364187;
}

//----- (0070CC50) --------------------------------------------------------  // acclient.c:799668
void _E109_80()
{
  flt_8ED6F8 = 1000.0 + 1.0;
}

//----- (0070CC70) --------------------------------------------------------  // acclient.c:799674
void _E111_57()
{
  flt_8ED6FC = 24.0 * 8.0;
}

//----- (0070CC90) --------------------------------------------------------  // acclient.c:799680
void _E113_31()
{
  flt_8ED700 = 24.0 * 0.5;
}

//----- (0070CCB0) --------------------------------------------------------  // acclient.c:799686
void _E115_86()
{
  flt_8ED708 = 0.00019999999 * 3.0 + 0.1;
}

//----- (0070CCD0) --------------------------------------------------------  // acclient.c:799692
void _E117_82()
{
  dbl_8ED710 = 1.0 / 30.0;
}

//----- (0070CCF0) --------------------------------------------------------  // acclient.c:799698
void _E119_32()
{
  dbl_8ED718 = 1.0 / 5.0;
}

//----- (0070CD10) --------------------------------------------------------  // acclient.c:799704
void _E121_72()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8ED720, PFID_A8R8G8B8);
}

//----- (0070CD20) --------------------------------------------------------  // acclient.c:799710
int _E123_46()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_41, "Render.TextureFiltering");
  return atexit(sub_776B20);
}

//----- (0070CD40) --------------------------------------------------------  // acclient.c:799717
int _E126_53()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_41, "Render.LandscapeDetailTextures");
  return atexit(sub_776B50);
}

//----- (0070CD60) --------------------------------------------------------  // acclient.c:799724
int _E129_47()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_41, "Render.BuildingDetailTextures");
  return atexit(sub_776B80);
}

//----- (0070CD80) --------------------------------------------------------  // acclient.c:799731
int _E132_48()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_41, "Render.FieldOfView");
  return atexit(sub_776BB0);
}

//----- (0070CDA0) --------------------------------------------------------  // acclient.c:799738
int _E135_55()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_41, "Render.LandscapeTextureDetail");
  return atexit(_E136_90);
}

//----- (0070CDC0) --------------------------------------------------------  // acclient.c:799745
int _E138_43()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_41, "Render.EnvironmentTextureDetail");
  return atexit(_E139_90);
}

//----- (0070CDE0) --------------------------------------------------------  // acclient.c:799752
int _E141_45()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_41, "Render.SceneryDrawDistance");
  return atexit(_E142_85);
}

//----- (0070CE00) --------------------------------------------------------  // acclient.c:799759
int _E144_42()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_41, "Render.LandscapeDrawDistance");
  return atexit(_E145_87);
}

//----- (0070CE20) --------------------------------------------------------  // acclient.c:799766
int _E147_41()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_41, "Render.ScreenBrightness");
  return atexit(_E148_83);
}

//----- (0070CE40) --------------------------------------------------------  // acclient.c:799773
int _E150_40()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_41, "Render.AspectRatio");
  return atexit(_E151_81);
}

//----- (0070CE60) --------------------------------------------------------  // acclient.c:799780
int _E153_38()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_41, "Render.DisplayAdapter");
  return atexit(_E154_82);
}

//----- (0070CE80) --------------------------------------------------------  // acclient.c:799787
int _E156_40()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_41, "Render.MaxHardwareClass");
  return atexit(_E157_78);
}

//----- (0070CEA0) --------------------------------------------------------  // acclient.c:799794
int _E159_38()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_41, "Render.AutomaticDegrades");
  return atexit(_E160_81);
}

//----- (0070CEC0) --------------------------------------------------------  // acclient.c:799801
int _E162_41()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_41, "Render.GraphicsPerformance");
  return atexit(_E163_74);
}

//----- (0070CEE0) --------------------------------------------------------  // acclient.c:799808
int _E165_36()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_41, "Render.DegradeDistance");
  return atexit(_E166_76);
}

//----- (0070CF00) --------------------------------------------------------  // acclient.c:799815
int _E168_37()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_41, "Render.MultiPassAlpha");
  return atexit(_E169_75);
}

//----- (0070CF20) --------------------------------------------------------  // acclient.c:799822
int _E171_36()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_41, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8ED79C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8ED7A0, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8ED7A4, "Anisotropic");
  return atexit(_E172_73);
}

//----- (0070CF70) --------------------------------------------------------  // acclient.c:799832
int _E174_38()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_41, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED7AC, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED7B0, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED7B4, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED7B8, "VeryHigh");
  return atexit(_E175_70);
}

//----- (0070CFD0) --------------------------------------------------------  // acclient.c:799843
int _E177_35()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_41, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED7C0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED7C4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED7C8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED7CC, "VeryHigh");
  return atexit(_E178_70);
}

//----- (0070D030) --------------------------------------------------------  // acclient.c:799854
int _E180_35()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_41, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED7D4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED7D8, "High");
  return atexit(_E181_70);
}

//----- (0070D070) --------------------------------------------------------  // acclient.c:799863
int _E183_34()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_41, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8ED7E0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8ED7E4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8ED7E8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8ED7EC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8ED7F0, "Extreme");
  return atexit(_E184_67);
}

//----- (0070D0E0) --------------------------------------------------------  // acclient.c:799875
int _E186_34()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_41, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8ED7F8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8ED7FC, "Wide");
  return atexit(_E187_66);
}

//----- (0070D120) --------------------------------------------------------  // acclient.c:799884
int _E189_33()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_68, "None");
  return atexit(_E190_67);
}

//----- (0070D140) --------------------------------------------------------  // acclient.c:799891
int _E192_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_68, "Speed");
  return atexit(_E193_53);
}

//----- (0070D160) --------------------------------------------------------  // acclient.c:799898
int _E195_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_68, "Noise");
  return atexit(_E196_60);
}

//----- (0070D180) --------------------------------------------------------  // acclient.c:799905
int _E198_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_68, "Sine");
  return atexit(_E199_52);
}

//----- (0070D1A0) --------------------------------------------------------  // acclient.c:799912
int _E201_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_68, "Square");
  return atexit(_E202_53);
}

//----- (0070D1C0) --------------------------------------------------------  // acclient.c:799919
int _E204_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_68, "Bounce");
  return atexit(_E205_45);
}

//----- (0070D1E0) --------------------------------------------------------  // acclient.c:799926
int _E207_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_68, "Perlin");
  return atexit(_E208_49);
}

//----- (0070D200) --------------------------------------------------------  // acclient.c:799933
int _E210_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_68, "Fractal");
  return atexit(_E211_45);
}

//----- (0070D220) --------------------------------------------------------  // acclient.c:799940
int _E213_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_68, "FrameLoop");
  return atexit(_E214_47);
}

//----- (0070D240) --------------------------------------------------------  // acclient.c:799947
int _E216_13()
{
  return atexit(_E217_43);
}

//----- (0070D250) --------------------------------------------------------  // acclient.c:799953
int _E219_10()
{
  return atexit(_E220_42);
}

//----- (0070D260) --------------------------------------------------------  // acclient.c:799959
int _E222_9()
{
  return atexit(_E223_42);
}

//----- (0070D270) --------------------------------------------------------  // acclient.c:799965
int sub_70D270()
{
  return atexit(nullsub_1452);
}

//----- (007768B0) --------------------------------------------------------  // acclient.c:910364
void __cdecl _E190_67()
{
  char *v0; // esi@1

  v0 = &waveform_None_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007768E0) --------------------------------------------------------  // acclient.c:910377
void __cdecl _E193_53()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776910) --------------------------------------------------------  // acclient.c:910390
void __cdecl _E196_60()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776940) --------------------------------------------------------  // acclient.c:910403
void __cdecl _E199_52()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776970) --------------------------------------------------------  // acclient.c:910416
void __cdecl _E202_53()
{
  char *v0; // esi@1

  v0 = &waveform_Square_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007769A0) --------------------------------------------------------  // acclient.c:910429
void __cdecl _E205_45()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007769D0) --------------------------------------------------------  // acclient.c:910442
void __cdecl _E208_49()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776A00) --------------------------------------------------------  // acclient.c:910455
void __cdecl _E211_45()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776A30) --------------------------------------------------------  // acclient.c:910468
void __cdecl _E214_47()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_68.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_68.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776A60) --------------------------------------------------------  // acclient.c:910481
void __cdecl _E74_88()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776A90) --------------------------------------------------------  // acclient.c:910494
void __cdecl sub_776A90()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776AC0) --------------------------------------------------------  // acclient.c:910507
void __cdecl _E80_65()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776AF0) --------------------------------------------------------  // acclient.c:910520
void __cdecl _E83_42()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_37.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_37.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776B20) --------------------------------------------------------  // acclient.c:910533
void __cdecl sub_776B20()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776B50) --------------------------------------------------------  // acclient.c:910546
void __cdecl sub_776B50()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776B80) --------------------------------------------------------  // acclient.c:910559
void __cdecl sub_776B80()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776BB0) --------------------------------------------------------  // acclient.c:910572
void __cdecl sub_776BB0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776BE0) --------------------------------------------------------  // acclient.c:910585
void __cdecl _E136_90()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776C10) --------------------------------------------------------  // acclient.c:910598
void __cdecl _E139_90()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776C40) --------------------------------------------------------  // acclient.c:910611
void __cdecl _E142_85()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776C70) --------------------------------------------------------  // acclient.c:910624
void __cdecl _E145_87()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776CA0) --------------------------------------------------------  // acclient.c:910637
void __cdecl _E148_83()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776CD0) --------------------------------------------------------  // acclient.c:910650
void __cdecl _E151_81()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776D00) --------------------------------------------------------  // acclient.c:910663
void __cdecl _E154_82()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776D30) --------------------------------------------------------  // acclient.c:910676
void __cdecl _E157_78()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776D60) --------------------------------------------------------  // acclient.c:910689
void __cdecl _E160_81()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776D90) --------------------------------------------------------  // acclient.c:910702
void __cdecl _E163_74()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776DC0) --------------------------------------------------------  // acclient.c:910715
void __cdecl _E166_76()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776DF0) --------------------------------------------------------  // acclient.c:910728
void __cdecl _E169_75()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00776E20) --------------------------------------------------------  // acclient.c:910741
void __cdecl _E172_73()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_41;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00776E60) --------------------------------------------------------  // acclient.c:910766
void __cdecl _E175_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_41;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00776EA0) --------------------------------------------------------  // acclient.c:910791
void __cdecl _E178_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_41;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00776EE0) --------------------------------------------------------  // acclient.c:910816
void __cdecl _E181_70()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_41;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00776F20) --------------------------------------------------------  // acclient.c:910841
void __cdecl _E184_67()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_41;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00776F60) --------------------------------------------------------  // acclient.c:910866
void __cdecl _E187_66()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_68;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00776FA0) --------------------------------------------------------  // acclient.c:910891
void __cdecl _E226_26()
{
  DArray<view_vertex>::~DArray<view_vertex>(&stru_8ED84C);
  operator delete[](dword_8ED83C);
  dword_8ED83C = 0;
  operator delete[](temp_view.portal.data);
  temp_view.portal.data = 0;
}

