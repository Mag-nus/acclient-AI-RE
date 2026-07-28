/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSurface
   Object     : PORTAL\cgeometry\CSurface.obj
   Functions  : 43
   Addresses  : 00527170 - 0076A340 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00527170) --------------------------------------------------------  // acclient.c:342700
signed int CSurface::GetDBOType()
{
  return 13;
}

//----- (00535E80) --------------------------------------------------------  // acclient.c:357704
PixelFormatID __thiscall ImgTex::get_image_type(ImgTex *this)
{
  RenderSurface *v1; // eax@1
  PixelFormatID result; // eax@2

  v1 = this->m_pImageData;
  if ( v1 )
    result = v1->pfDesc.format;
  else
    result = 0;
  return result;
}

//----- (00535EA0) --------------------------------------------------------  // acclient.c:357718
void __thiscall CSurface::SetPalette(CSurface *this, Palette *palette)
{
  CSurface *v2; // esi@1

  v2 = this;
  if ( this->base1pal )
  {
    Palette::releasePalette(this->base1pal);
    v2->base1pal = 0;
  }
  v2->base1pal = Palette::copyRef(palette);
}

//----- (00535ED0) --------------------------------------------------------  // acclient.c:357732
void __cdecl CSurface::releaseCustomSurface(CSurface *surface)
{
  ((void (*)(void))surface->vfptr->Release)();
}

//----- (00535EE0) --------------------------------------------------------  // acclient.c:357738
int __thiscall CSurface::ClearSurface(CSurface *this)
{
  CSurface *v1; // esi@1
  int result; // eax@2
  ImgTex *v3; // ecx@3

  v1 = this;
  if ( this->m_pMaintainer )
  {
    result = 0;
  }
  else
  {
    v3 = this->base1map;
    if ( v3 )
    {
      ((void (*)(void))v3->vfptr->Release)();
      v1->base1map = 0;
    }
    if ( v1->base1pal )
    {
      Palette::releasePalette(v1->base1pal);
      v1->base1pal = 0;
    }
    result = 1;
  }
  return result;
}

//----- (00535F20) --------------------------------------------------------  // acclient.c:357768
int __thiscall CSurface::UsePalette(CSurface *this, Palette *pal)
{
  int result; // eax@6

  if ( this->m_pMaintainer )
    goto LABEL_10;
  if ( this->handler == 4 )
    this->handler = 2;
  if ( this->handler == 2 && pal )
  {
    CSurface::SetPalette(this, pal);
    result = 1;
  }
  else
  {
LABEL_10:
    result = 0;
  }
  return result;
}

//----- (00535F60) --------------------------------------------------------  // acclient.c:357790
int __thiscall CSurface::RestorePalette(CSurface *this)
{
  CSurface *v1; // esi@1
  ImgTex *v2; // eax@2
  int result; // eax@3
  Palette *v4; // edi@4

  v1 = this;
  if ( !this->m_pMaintainer && (v2 = this->base1map) != 0 )
  {
    v4 = v2->m_pPalette;
    if ( this->base1pal )
    {
      Palette::releasePalette(this->base1pal);
      v1->base1pal = 0;
    }
    v1->base1pal = Palette::copyRef(v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00535FB0) --------------------------------------------------------  // acclient.c:357817
int __thiscall CSurface::SetTextureAndPalette(CSurface *this, ImgTex *texture, Palette *palette)
{
  CSurface *v3; // esi@1
  bool v4; // zf@1
  Palette *v5; // edi@4
  ImgTex *v6; // ecx@5
  int result; // eax@7

  v3 = this;
  v4 = (this->type & 4) == 0;
  this->handler = 2;
  if ( v4 )
    ImgTex::fCurrentTextureScale = ImgTex::fIndexedTextureScale;
  else
    ImgTex::fCurrentTextureScale = ImgTex::fClipmapTextureScale;
  v5 = ImgTex::CreateCombinedTexture(texture, palette, (this->type >> 2) & 1);
  if ( v5 )
  {
    v6 = v3->base1map;
    if ( v6 )
    {
      ((void (*)(void))v6->vfptr->Release)();
      v3->base1map = 0;
    }
    v3->base1map = (ImgTex *)v5;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 845768: using guessed type enum ImageScaleType ImgTex::fClipmapTextureScale;
// 845770: using guessed type enum ImageScaleType ImgTex::fIndexedTextureScale;
// 845774: using guessed type enum ImageScaleType ImgTex::fCurrentTextureScale;

//----- (00536030) --------------------------------------------------------  // acclient.c:357855
char __thiscall CSurface::PurgeResource(CSurface *this)
{
  CSurface *v1; // esi@1
  char result; // al@1
  int v3; // ecx@3

  v1 = this;
  result = DBObj::InitLoad();
  if ( result )
  {
    if ( *(_DWORD *)&v1->m_AllowedInFreeList != 4 )
    {
      v3 = *((_DWORD *)&v1->m_bIsLost + 1);
      if ( v3 )
      {
        (*(void (**)(void))(*(_DWORD *)v3 + 20))();
        *((_DWORD *)&v1->m_bIsLost + 1) = 0;
      }
    }
    result = 1;
  }
  return result;
}

//----- (00536060) --------------------------------------------------------  // acclient.c:357880
void __thiscall CSurface::CSurface(CSurface *this)
{
  CSurface *v1; // esi@1
  unsigned int v2; // edx@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_845060);
  GraphicsResource::GraphicsResource((GraphicsResource *)&v1->vfptr);
  v1->color_value = -1;
  v1->solid_index = -1;
  v1->vfptr = (InterfaceVtbl *)&CSurface::vftable;
  v1->vfptr = (GraphicsResourceVtbl *)&CSurface::vftable;
  v1->type = 0;
  v1->handler = 0;
  v1->indexed_texture_id.id = stru_845060.id;
  LODWORD(v1->diffuse) = 1065353216;
  v1->base1map = 0;
  v1->base1pal = 0;
  LODWORD(v1->translucency) = 0;
  LODWORD(v1->luminosity) = 0;
  v1->orig_texture_id.id = stru_845060.id;
  v2 = stru_845060.id;
  LODWORD(v1->orig_diffuse) = 1065353216;
  v1->orig_palette_id.id = v2;
  LODWORD(v1->orig_luminosity) = 0;
  GraphicsResource::SetAutoRestore((GraphicsResource *)&v1->vfptr, 1);
}
// 7C9714: using guessed type void *CSurface::vftable;
// 7C9728: using guessed type __int32 (__stdcall *CSurface::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005360F0) --------------------------------------------------------  // acclient.c:357911
DBObj *__thiscall CSurface::vector_deleting_destructor(CSurface *this, unsigned int a2)
{
  return CSurface::vector_deleting_destructor((CSurface *)((char *)this - 48), a2);
}

//----- (00536100) --------------------------------------------------------  // acclient.c:357917
void __thiscall CSurface::CSurface(CSurface *this, CSurface *cs)
{
  CSurface *v2; // esi@1
  SurfaceHandlerEnum v3; // eax@2
  ImgTex *v4; // ecx@5
  Palette *v5; // edi@7

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_845060);
  GraphicsResource::GraphicsResource((GraphicsResource *)&v2->vfptr);
  v2->vfptr = (GraphicsResourceVtbl *)&CSurface::vftable;
  v2->vfptr = (InterfaceVtbl *)&CSurface::vftable;
  if ( v2 != cs )
  {
    v2->type = cs->type;
    v3 = cs->handler;
    if ( v3 == 1 )
      v2->handler = 4;
    else
      v2->handler = v3;
    v2->indexed_texture_id.id = cs->indexed_texture_id.id;
    v2->base1map = 0;
    v2->base1pal = 0;
    v2->color_value = cs->color_value;
    v2->solid_index = cs->solid_index;
    v2->translucency = cs->translucency;
    v2->luminosity = cs->luminosity;
    v2->diffuse = cs->diffuse;
    v2->orig_texture_id.id = cs->orig_texture_id.id;
    v2->orig_palette_id.id = cs->orig_palette_id.id;
    v2->orig_luminosity = cs->orig_luminosity;
    v2->orig_diffuse = cs->orig_diffuse;
    v4 = cs->base1map;
    if ( v4 )
    {
      v2->base1map = v4;
      ((void (*)(void))v4->vfptr->AddRef)();
    }
    v5 = cs->base1pal;
    if ( v5 )
    {
      if ( v2->base1pal )
      {
        Palette::releasePalette(v2->base1pal);
        v2->base1pal = 0;
      }
      v2->base1pal = Palette::copyRef(v5);
    }
  }
}
// 7C9714: using guessed type void *CSurface::vftable;
// 7C9728: using guessed type __int32 (__stdcall *CSurface::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005361F0) --------------------------------------------------------  // acclient.c:357971
void __thiscall CSurface::Destroy(CSurface *this)
{
  CSurface *v1; // esi@1
  ImgTex *v2; // ecx@1

  v1 = this;
  v2 = this->base1map;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->base1map = 0;
  }
  if ( v1->base1pal )
  {
    Palette::releasePalette(v1->base1pal);
    v1->base1pal = 0;
  }
  v1->type = 0;
  v1->color_value = -1;
  v1->solid_index = -1;
  v1->indexed_texture_id.id = stru_845060.id;
  v1->orig_texture_id.id = stru_845060.id;
  v1->orig_palette_id.id = stru_845060.id;
  LODWORD(v1->translucency) = 0;
  LODWORD(v1->luminosity) = 0;
  LODWORD(v1->orig_luminosity) = 0;
  v1->handler = 0;
  LODWORD(v1->diffuse) = 1065353216;
  LODWORD(v1->orig_diffuse) = 1065353216;
}

//----- (00536270) --------------------------------------------------------  // acclient.c:358003
void __cdecl CSurface::makeCustomSurface(SurfaceHandlerEnum sh)
{
  CSurface *v1; // eax@3
  int v2; // eax@4

  if ( sh != 1 )
  {
    if ( sh )
    {
      v1 = (CSurface *)operator new(0x90u);
      if ( v1 )
      {
        CSurface::CSurface(v1);
        if ( v2 )
          *(_DWORD *)(v2 + 92) = sh;
      }
    }
  }
}

//----- (005362B0) --------------------------------------------------------  // acclient.c:358024
void __cdecl CSurface::makeCustomSurface(CSurface *copy_surface)
{
  CSurface *v1; // eax@2

  if ( copy_surface )
  {
    v1 = (CSurface *)operator new(0x90u);
    if ( v1 )
      CSurface::CSurface(v1, copy_surface);
  }
}

//----- (005362E0) --------------------------------------------------------  // acclient.c:358037
int __thiscall CSurface::UseTextureMap(CSurface *this, IDClass<_tagDataID,32,0> texture_id, int force_if_null)
{
  CSurface *v3; // esi@1
  int result; // eax@7

  v3 = this;
  if ( this->m_pMaintainer )
    goto LABEL_15;
  if ( this->handler == 4 )
    this->handler = 2;
  if ( this->handler == 2 && (this->base1map || force_if_null) )
  {
    if ( !(this->type & 6) )
      this->type = 2;
    this->indexed_texture_id.id = texture_id.id;
    if ( this->base1pal )
    {
      Palette::releasePalette(this->base1pal);
      v3->base1pal = 0;
    }
    result = 1;
  }
  else
  {
LABEL_15:
    result = 0;
  }
  return result;
}

//----- (00536350) --------------------------------------------------------  // acclient.c:358068
int __thiscall CSurface::UseTextureMap(CSurface *this, ImgTex *texture, SurfaceHandlerEnum sh)
{
  CSurface *v3; // esi@1
  int result; // eax@3
  ImgTex *v5; // ecx@6

  v3 = this;
  if ( this->m_pMaintainer || this->handler != sh )
  {
    result = 0;
  }
  else if ( texture )
  {
    v5 = this->base1map;
    if ( v5 )
    {
      ((void (*)(void))v5->vfptr->Release)();
      v3->base1map = 0;
    }
    v3->type = 2;
    v3->base1map = texture;
    texture->vfptr->AddRef((Interface *)texture);
    if ( v3->orig_texture_id.id == stru_845060.id )
      v3->orig_texture_id.id = v3->base1map->m_DID.id;
    if ( v3->base1pal )
    {
      Palette::releasePalette(v3->base1pal);
      v3->base1pal = 0;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005363E0) --------------------------------------------------------  // acclient.c:358107
IDClass<_tagDataID,32,0> *__thiscall CSurface::GetOriginalTextureMapID(CSurface *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->orig_texture_id.id;
  return v2;
}

//----- (005363F0) --------------------------------------------------------  // acclient.c:358117
IDClass<_tagDataID,32,0> *__thiscall CSurface::GetOriginalPaletteID(CSurface *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->orig_palette_id.id;
  return v2;
}

//----- (00536400) --------------------------------------------------------  // acclient.c:358127
void __thiscall CSurface::InitEnd(CSurface *this, SurfaceInitType init_type)
{
  CSurface *v2; // esi@1
  unsigned int v3; // eax@1
  QualifiedDataID *v4; // eax@5
  int v5; // edi@5
  ImgTex *v6; // ecx@6
  bool v7; // zf@9
  Palette *v8; // edi@10
  ImgTex *v9; // ecx@15
  ImgTex *v10; // ecx@17
  ImgTex *v11; // eax@20
  RenderSurface *v12; // ecx@21
  RenderSurface *v13; // ecx@23
  ImgTex *v14; // ecx@28
  QualifiedDataID v15; // [sp+Ch] [bp-8h]@5

  v2 = this;
  v3 = this->indexed_texture_id.id;
  if ( !v3 )
    v3 = this->orig_texture_id.id;
  if ( !v3 )
  {
    v10 = this->base1map;
    if ( !v10 )
      goto LABEL_20;
    ((void (*)(void))v10->vfptr->Release)();
LABEL_19:
    v2->base1map = 0;
    goto LABEL_20;
  }
  if ( !(this->type & 6) )
    goto LABEL_20;
  QualifiedDataID::QualifiedDataID(&v15, (IDClass<_tagDataID,32,0>)v3, 0xBu);
  v5 = DBObj::Get(v4);
  if ( !v5 )
  {
    if ( init_type != 4 )
      goto LABEL_20;
    v9 = v2->base1map;
    if ( !v9 )
      goto LABEL_20;
    ((void (*)(void))v9->vfptr->Release)();
    goto LABEL_19;
  }
  v6 = v2->base1map;
  if ( v6 )
  {
    ((void (*)(void))v6->vfptr->Release)();
    v2->base1map = 0;
  }
  v2->base1map = (ImgTex *)v5;
  if ( *(_DWORD *)(v5 + 104) )
  {
    v7 = v2->base1pal == 0;
    v2->indexed_texture_id.id = *(_DWORD *)(v5 + 40);
    if ( v7 )
    {
      v8 = *(Palette **)(v5 + 104);
      if ( v8 )
      {
        CSurface::SetPalette(v2, v8);
        if ( init_type == 1 || init_type == 2 )
          v2->orig_palette_id.id = v2->base1pal->m_DID.id;
      }
    }
  }
LABEL_20:
  v11 = v2->base1map;
  if ( v11 )
  {
    if ( (v12 = v11->m_pImageData) != 0 && v12->pfDesc.format == 41
      || (v13 = v11->m_pImageData) != 0 && v13->pfDesc.format == 101 )
    {
      if ( init_type != 2 && (!v2->base1pal || !CSurface::SetTextureAndPalette(v2, v11, v2->base1pal)) )
      {
        v14 = v2->base1map;
        if ( v14 )
        {
          ((void (*)(void))v14->vfptr->Release)();
          v2->base1map = 0;
        }
      }
    }
  }
  if ( v2->translucency > 0.00019999999 )
    v2->type |= 0x10u;
}

//----- (00536530) --------------------------------------------------------  // acclient.c:358217
char __thiscall CSurface::RestorePalShiftSurface(CSurface *this)
{
  CSurface *v1; // esi@1
  char v2; // bl@1
  QualifiedDataID *v3; // eax@1
  int v4; // eax@1
  int v5; // edi@1
  Palette *v6; // ebp@4
  ImgTex *v7; // ecx@6
  Palette *v8; // eax@11
  QualifiedDataID v10; // [sp+Ch] [bp-8h]@1

  v1 = this;
  v2 = 0;
  QualifiedDataID::QualifiedDataID(&v10, this->indexed_texture_id, 0xBu);
  v4 = DBObj::Get(v3);
  v5 = v4;
  if ( v4 )
  {
    if ( *(_BYTE *)(v4 + 56) )
      (*(void (__thiscall **)(int))(*(_DWORD *)(v4 + 48) + 12))(v4 + 48);
    v6 = v1->base1pal;
    if ( v6 || (v6 = *(Palette **)(v5 + 104)) != 0 )
    {
      v7 = v1->base1map;
      if ( v7 )
      {
        ((void (*)(void))v7->vfptr->Release)();
        v1->base1map = 0;
      }
      if ( v1->type & 4 )
        ImgTex::fCurrentTextureScale = ImgTex::fClipmapTextureScale;
      else
        ImgTex::fCurrentTextureScale = ImgTex::fIndexedTextureScale;
      v8 = ImgTex::CreateCombinedTexture((ImgTex *)v5, v6, (v1->type >> 2) & 1);
      v1->base1map = (ImgTex *)v8;
      if ( v8 )
        v2 = 1;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
  }
  return v2;
}
// 845768: using guessed type enum ImageScaleType ImgTex::fClipmapTextureScale;
// 845770: using guessed type enum ImageScaleType ImgTex::fIndexedTextureScale;
// 845774: using guessed type enum ImageScaleType ImgTex::fCurrentTextureScale;

//----- (005365F0) --------------------------------------------------------  // acclient.c:358265
void __thiscall CSurface::Serialize(CSurface *this, Archive *io_archive)
{
  CSurface *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@6
  unsigned int v5; // eax@10
  unsigned int v6; // eax@14
  unsigned int v7; // eax@18
  unsigned int v8; // eax@22
  unsigned int v9; // eax@26
  float v10; // edx@31

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->type;
    else
      v2->type = *(_DWORD *)v3;
  }
  if ( v2->type & 6 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v4 = Archive::GetBytes(io_archive, 4u);
    if ( v4 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v4 = v2->orig_texture_id.id;
      else
        v2->orig_texture_id.id = *(_DWORD *)v4;
    }
    Archive::CheckAlignment(io_archive, 4u);
    v5 = Archive::GetBytes(io_archive, 4u);
    if ( v5 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v5 = v2->orig_palette_id.id;
      else
        v2->orig_palette_id.id = *(_DWORD *)v5;
    }
  }
  else
  {
    Archive::CheckAlignment(io_archive, 4u);
    v6 = Archive::GetBytes(io_archive, 4u);
    if ( v6 )
    {
      if ( io_archive->m_flags & 1 )
        *(_DWORD *)v6 = v2->color_value;
      else
        v2->color_value = *(_DWORD *)v6;
    }
  }
  Archive::CheckAlignment(io_archive, 4u);
  v7 = Archive::GetBytes(io_archive, 4u);
  if ( v7 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v7 = LODWORD(v2->translucency);
    else
      LODWORD(v2->translucency) = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v8 = Archive::GetBytes(io_archive, 4u);
  if ( v8 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v8 = LODWORD(v2->luminosity);
    else
      LODWORD(v2->luminosity) = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v9 = Archive::GetBytes(io_archive, 4u);
  if ( v9 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v9 = LODWORD(v2->diffuse);
    else
      LODWORD(v2->diffuse) = *(_DWORD *)v9;
  }
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
  {
    v10 = v2->diffuse;
    v2->orig_luminosity = v2->luminosity;
    v2->orig_diffuse = v10;
    v2->handler = 1;
    CSurface::InitEnd(v2, SurfaceInitLoading);
  }
}

//----- (00536750) --------------------------------------------------------  // acclient.c:358358
void __thiscall CSurface::GetSubDataIDs(CSurface *this, QualifiedDataIDArray *id_array)
{
  QualifiedDataID *v2; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, this->orig_texture_id, 0);
  QualifiedDataIDArray::AddQDID(id_array, v2, 0);
}

//----- (00536780) --------------------------------------------------------  // acclient.c:358368
char __thiscall CSurface::RestoreLostSurface(CSurface *this)
{
  CSurface *v1; // esi@1
  char v2; // bl@1
  QualifiedDataID *v3; // eax@3
  int v4; // eax@3
  char result; // al@4
  char v6; // al@6
  int v7; // eax@8
  ImgTex *v8; // ecx@12
  QualifiedDataID v9; // [sp+8h] [bp-8h]@3

  v1 = this;
  v2 = 0;
  switch ( this->handler )
  {
    case 1:
    case 4:
      ImgTex::fCurrentTextureScale = ImgTex::fRGBATextureScale;
      if ( !this->base1map )
      {
        QualifiedDataID::QualifiedDataID(&v9, this->orig_texture_id, 0xBu);
        v4 = DBObj::Get(v3);
        v1->base1map = (ImgTex *)v4;
        if ( !v4 )
          goto LABEL_12;
      }
      result = 1;
      break;
    case 2:
      if ( this->indexed_texture_id.id )
      {
        v6 = CSurface::RestorePalShiftSurface(this);
        goto LABEL_11;
      }
      if ( this->base1map )
        goto LABEL_12;
      v7 = ImgTex::Get(this->orig_texture_id);
      v1->base1map = (ImgTex *)v7;
      if ( !v7 )
        goto LABEL_12;
      result = 1;
      break;
    case 3:
      ImgTex::fCurrentTextureScale = 0;
      v6 = TexMerge::RestoreSurface(this);
LABEL_11:
      v2 = v6;
      if ( v6 )
        goto LABEL_14;
      goto LABEL_12;
    default:
LABEL_12:
      v8 = v1->base1map;
      if ( v8 )
      {
        ((void (*)(void))v8->vfptr->Release)();
        v1->base1map = 0;
      }
LABEL_14:
      result = v2;
      break;
  }
  return result;
}
// 84576C: using guessed type enum ImageScaleType ImgTex::fRGBATextureScale;
// 845774: using guessed type enum ImageScaleType ImgTex::fCurrentTextureScale;

//----- (00536860) --------------------------------------------------------  // acclient.c:358437
DBObj *__thiscall CSurface::vector_deleting_destructor(CSurface *this, unsigned int a2)
{
  DBObj *v2; // esi@1
  GraphicsResource *v3; // edi@1

  v2 = (DBObj *)this;
  v3 = (GraphicsResource *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&CSurface::vftable;
  this->vfptr = (GraphicsResourceVtbl *)&CSurface::vftable;
  CSurface::Destroy(this);
  GraphicsResource::~GraphicsResource(v3);
  DBObj::~DBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9714: using guessed type void *CSurface::vftable;
// 7C9728: using guessed type __int32 (__stdcall *CSurface::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005368A0) --------------------------------------------------------  // acclient.c:358457
char __thiscall CSurface::RestoreResource(CSurface *this)
{
  GraphicsResource *v1; // esi@1
  bool v2; // al@1
  char v3; // bl@1

  v1 = (GraphicsResource *)this;
  v2 = GraphicsResource::RestoreResource((GraphicsResource *)this);
  v3 = v2;
  if ( (unsigned int)v1[1].vfptr & 6 )
    v3 = CSurface::RestoreLostSurface((CSurface *)&v1[-2].m_nResourceSize) & v2;
  if ( v3 )
    GraphicsResource::MarkResourceAsNotLost(v1);
  return v3;
}

//----- (006FFF10) --------------------------------------------------------  // acclient.c:787897
int _E73_95()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_24, "Display.Resolution");
  return atexit(_E74_71);
}

//----- (006FFF30) --------------------------------------------------------  // acclient.c:787904
int _E76_57()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_24, "Display.FullScreen");
  return atexit(_E77_85);
}

//----- (006FFF50) --------------------------------------------------------  // acclient.c:787911
int _E79_50()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_24, "Display.RefreshRate");
  return atexit(_E80_49);
}

//----- (006FFF70) --------------------------------------------------------  // acclient.c:787918
int _E82_31()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_24, "Display.SyncToRefresh");
  return atexit(_E83_29);
}

//----- (006FFF90) --------------------------------------------------------  // acclient.c:787925
int _E85_21()
{
  return atexit(_E86_18);
}

//----- (006FFFA0) --------------------------------------------------------  // acclient.c:787931
int _E88_16()
{
  return atexit(_E89_29);
}

//----- (006FFFB0) --------------------------------------------------------  // acclient.c:787937
int sub_6FFFB0()
{
  return atexit(_E92_33);
}

//----- (006FFFC0) --------------------------------------------------------  // acclient.c:787943
void _E94_22()
{
  PixelFormatDesc::PixelFormatDesc(&stru_845064, PFID_A8R8G8B8);
}

//----- (006FFFD0) --------------------------------------------------------  // acclient.c:787949
void _E112_92()
{
  LODWORD(dword_84509C) = 1053364187;
}

//----- (006FFFE0) --------------------------------------------------------  // acclient.c:787955
void _E114_50()
{
  flt_8450A0 = 1000.0 + 1.0;
}

//----- (00700000) --------------------------------------------------------  // acclient.c:787961
void _E116_21()
{
  flt_8450A4 = 24.0 * 8.0;
}

//----- (00700020) --------------------------------------------------------  // acclient.c:787967
void _E118_69()
{
  flt_8450A8 = 24.0 * 0.5;
}

//----- (00700040) --------------------------------------------------------  // acclient.c:787973
int sub_700040()
{
  return atexit(nullsub_1181);
}

//----- (0076A2B0) --------------------------------------------------------  // acclient.c:897222
void __cdecl _E74_71()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A2E0) --------------------------------------------------------  // acclient.c:897235
void __cdecl _E77_85()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A310) --------------------------------------------------------  // acclient.c:897248
void __cdecl _E80_49()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076A340) --------------------------------------------------------  // acclient.c:897261
void __cdecl _E83_29()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_24.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_24.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

