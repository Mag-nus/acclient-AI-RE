/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBSPPortal
   Object     : PORTAL\cgeometry\CBSPPortal.obj
   Functions  : 75
   Addresses  : 0053D850 - 0076BCF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053D850) --------------------------------------------------------  // acclient.c:364396
void __thiscall BSPPORTAL::BSPPORTAL(BSPPORTAL *this)
{
  BSPPORTAL *v1; // esi@1

  v1 = this;
  BSPNODE::BSPNODE((BSPNODE *)&this->vfptr);
  v1->num_portals = 0;
  v1->in_portals = 0;
  v1->vfptr = (BSPNODEVtbl *)&BSPPORTAL::vftable;
}
// 7C9C00: using guessed type int (__thiscall *BSPPORTAL::vftable)(void *, char);

//----- (0053D870) --------------------------------------------------------  // acclient.c:364409
void __thiscall BSPPORTAL::portal_draw_portals_only(BSPPORTAL *this, int portalPolyOrPortalContents)
{
  BSPPORTAL *i; // esi@1
  double v3; // st7@2
  signed int v4; // eax@3
  int v5; // eax@7
  BSPNODE *v6; // ecx@9
  int v7; // eax@10
  BSPNODE *v8; // ecx@12
  BSPNODE *v9; // ecx@15
  int v10; // eax@16
  unsigned int v11; // edi@20
  BSPNODE *v12; // ecx@23
  int v13; // eax@24
  unsigned int v14; // edi@28
  int v15; // eax@32

  for ( i = this; ; i = (BSPPORTAL *)v8 )
  {
    v3 = Render::FrameCurrent->z * i->splitting_plane.N.z
       + Render::FrameCurrent->y * i->splitting_plane.N.y
       + i->splitting_plane.N.x * Render::FrameCurrent->x
       + i->splitting_plane.d;
    if ( v3 <= 0.00019999999 )
    {
      v4 = 1;
      if ( v3 >= -0.00019999999 )
        v4 = 2;
    }
    else
    {
      v4 = 0;
    }
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 != 1 )
          return;
        v6 = i->pos_node;
        if ( !v6 )
          goto LABEL_14;
        v7 = v6->type;
        if ( v7 == 1279607110 )
          goto LABEL_14;
        if ( v7 == 1347375700 )
        {
          BSPPORTAL::portal_draw_portals_only((BSPPORTAL *)v6, portalPolyOrPortalContents);
LABEL_14:
          v8 = i->neg_node;
          goto LABEL_31;
        }
        BSPNODE::build_draw_portals_only(v6, portalPolyOrPortalContents);
        v8 = i->neg_node;
      }
      else
      {
        v9 = i->pos_node;
        if ( v9 )
        {
          v10 = v9->type;
          if ( v10 != 1279607110 )
          {
            if ( v10 == 1347375700 )
              BSPPORTAL::portal_draw_portals_only((BSPPORTAL *)v9, portalPolyOrPortalContents);
            else
              BSPNODE::build_draw_portals_only(v9, portalPolyOrPortalContents);
          }
        }
        v11 = 0;
        if ( i->num_portals )
        {
          do
            ((void (__stdcall *)(CPortalPoly *, signed int, int))RenderDevice::render_device->vfptr->DrawPortal)(
              i->in_portals[v11++],
              1,
              portalPolyOrPortalContents);
          while ( v11 < i->num_portals );
        }
        v8 = i->neg_node;
      }
    }
    else
    {
      v12 = i->neg_node;
      if ( v12 )
      {
        v13 = v12->type;
        if ( v13 != 1279607110 )
        {
          if ( v13 == 1347375700 )
            BSPPORTAL::portal_draw_portals_only((BSPPORTAL *)v12, portalPolyOrPortalContents);
          else
            BSPNODE::build_draw_portals_only(v12, portalPolyOrPortalContents);
        }
      }
      v14 = 0;
      if ( i->num_portals )
      {
        do
          ((void (__stdcall *)(CPortalPoly *, signed int, int))RenderDevice::render_device->vfptr->DrawPortal)(
            i->in_portals[v14++],
            1,
            portalPolyOrPortalContents);
        while ( v14 < i->num_portals );
      }
      v8 = i->pos_node;
    }
LABEL_31:
    if ( !v8 )
      return;
    v15 = v8->type;
    if ( v15 == 1279607110 )
      return;
    if ( v15 != 1347375700 )
      break;
  }
  BSPNODE::build_draw_portals_only(v8, portalPolyOrPortalContents);
}

//----- (0053D9E0) --------------------------------------------------------  // acclient.c:364531
void __thiscall BSPPORTAL::Destroy(BSPPORTAL *this)
{
  BSPPORTAL *v1; // esi@1
  unsigned int v2; // ebx@2
  CPortalPoly **v3; // eax@3
  void *v4; // edi@3

  v1 = this;
  if ( this->in_portals )
  {
    v2 = 0;
    if ( this->num_portals )
    {
      do
      {
        v3 = v1->in_portals;
        v4 = v3[v2];
        if ( v4 )
        {
          CPortalPoly::~CPortalPoly(v3[v2]);
          operator delete(v4);
        }
        ++v2;
      }
      while ( v2 < v1->num_portals );
    }
    operator delete[](v1->in_portals);
    v1->in_portals = 0;
  }
  v1->num_portals = 0;
  BSPNODE::Destroy((BSPNODE *)&v1->vfptr);
}

//----- (0053DA40) --------------------------------------------------------  // acclient.c:364565
int __thiscall BSPPORTAL::pack_portal_size(BSPPORTAL *this)
{
  BSPPORTAL *v1; // edi@1
  BSPNODE *v2; // ST0C_4@1
  int v3; // esi@1
  int v4; // esi@1
  int result; // eax@2
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this;
  v2 = this->pos_node;
  dummy = 0;
  v3 = BSPNODE::PackChild(v2, &dummy, 0) + 16;
  v4 = BSPNODE::PackChild(v1->neg_node, &dummy, 0) + v3;
  if ( BSPNODE::pack_tree_type )
    result = v4;
  else
    result = v4 + 2 * (v1->num_polys + 2 * v1->num_portals + 12);
  return result;
}
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053DAA0) --------------------------------------------------------  // acclient.c:364589
int __thiscall BSPPORTAL::PackPortal(BSPPORTAL *this, void **addr, unsigned int size)
{
  BSPPORTAL *v3; // edi@1
  int v4; // ebp@1
  char *v5; // ebx@3
  unsigned int v6; // eax@3
  unsigned int v7; // eax@5
  char *v8; // ecx@6

  v3 = this;
  v4 = BSPPORTAL::pack_portal_size(this);
  if ( size >= v4 )
  {
    Plane::Pack(&v3->splitting_plane, addr, size);
    BSPNODE::PackChild(v3->pos_node, addr, size);
    BSPNODE::PackChild(v3->neg_node, addr, size);
    if ( BSPNODE::pack_tree_type == DRAWING_BSP )
    {
      Plane::Pack((Plane *)&v3->sphere, addr, size);
      *(_DWORD *)*addr = v3->num_polys;
      v5 = (char *)*addr + 4;
      *addr = v5;
      *(_DWORD *)v5 = v3->num_portals;
      *addr = (char *)*addr + 4;
      v6 = 0;
      if ( v3->num_polys )
      {
        do
        {
          *(_WORD *)*addr = v3->in_polys[v6]->poly_id;
          *addr = (char *)*addr + 2;
          ++v6;
        }
        while ( v6 < v3->num_polys );
      }
      v7 = 0;
      if ( v3->num_portals )
      {
        do
        {
          *(_WORD *)*addr = v3->in_portals[v7]->portal->poly_id;
          v8 = (char *)*addr + 2;
          *addr = v8;
          *(_WORD *)v8 = v3->in_portals[v7]->portal_index;
          *addr = (char *)*addr + 2;
          ++v7;
        }
        while ( v7 < v3->num_portals );
      }
    }
  }
  return v4;
}
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053DB70) --------------------------------------------------------  // acclient.c:364645
int __thiscall BSPPORTAL::UnPackPortal(BSPPORTAL *this, void **addr, unsigned int size)
{
  float *v3; // ebp@1
  BSPPORTAL *v4; // edi@1
  char *v5; // edx@3
  char *v6; // ecx@3
  char *v8; // ebx@9
  unsigned int v9; // eax@9
  void *v10; // eax@10
  unsigned int v11; // ecx@10
  unsigned int v12; // eax@10
  __int16 v13; // dx@11
  unsigned int v14; // eax@12
  unsigned int v15; // ebx@13
  CPortalPoly *v16; // eax@14
  CPortalPoly *v17; // eax@15
  __int16 v18; // cx@17
  __int16 v19; // cx@17

  v3 = (float *)*addr;
  v4 = this;
  if ( size < 0x10 )
    return 0;
  if ( size >= 0xC )
  {
    LODWORD(this->splitting_plane.N.x) = *(_DWORD *)v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(this->splitting_plane.N.y) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    LODWORD(v4->splitting_plane.N.z) = *(_DWORD *)v6;
    *addr = (char *)*addr + 4;
  }
  LODWORD(v4->splitting_plane.d) = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  if ( !BSPNODE::UnPackChild(&v4->pos_node, addr, size) || !BSPNODE::UnPackChild(&v4->neg_node, addr, size) )
  {
    *addr = v3;
    return 0;
  }
  if ( BSPNODE::pack_tree_type == DRAWING_BSP )
  {
    CSphere::UnPack(&v4->sphere, addr, size);
    v4->num_polys = *(_DWORD *)*addr;
    v8 = (char *)*addr + 4;
    *addr = v8;
    v4->num_portals = *(_DWORD *)v8;
    *addr = (char *)*addr + 4;
    v9 = v4->num_polys;
    if ( v9 )
    {
      v10 = operator new[](4 * v9);
      v11 = v4->num_polys;
      v4->in_polys = (CPolygon **)v10;
      v12 = 0;
      if ( v11 )
      {
        do
        {
          v13 = *(_WORD *)*addr;
          *addr = (char *)*addr + 2;
          v4->in_polys[v12++] = &BSPNODE::pack_poly[v13];
        }
        while ( v12 < v4->num_polys );
      }
    }
    v14 = v4->num_portals;
    if ( v14 )
    {
      v4->in_portals = (CPortalPoly **)operator new[](4 * v14);
      v15 = 0;
      if ( v4->num_portals )
      {
        do
        {
          v16 = (CPortalPoly *)operator new(8u);
          if ( v16 )
            CPortalPoly::CPortalPoly(v16);
          else
            v17 = 0;
          v4->in_portals[v15] = v17;
          v18 = *(_WORD *)*addr;
          *addr = (char *)*addr + 2;
          v4->in_portals[v15]->portal = &BSPNODE::pack_poly[v18];
          v19 = *(_WORD *)*addr;
          *addr = (char *)*addr + 2;
          v4->in_portals[v15++]->portal_index = v19;
        }
        while ( v15 < v4->num_portals );
      }
    }
  }
  return 1;
}
// 845378: using guessed type struct CPolygon *BSPNODE::pack_poly;
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053DD00) --------------------------------------------------------  // acclient.c:364744
BSPNODE *__thiscall BSPPORTAL::scalar_deleting_destructor(BSPPORTAL *this, unsigned int a2)
{
  BSPNODE *v2; // esi@1

  v2 = (BSPNODE *)this;
  this->vfptr = (BSPNODEVtbl *)&BSPPORTAL::vftable;
  BSPPORTAL::Destroy(this);
  BSPNODE::~BSPNODE(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9C00: using guessed type int (__thiscall *BSPPORTAL::vftable)(void *, char);

//----- (007016A0) --------------------------------------------------------  // acclient.c:789120
void _E89_6()
{
  PixelFormatDesc::PixelFormatDesc(&stru_845620, PFID_A8R8G8B8);
}

//----- (007016B0) --------------------------------------------------------  // acclient.c:789126
void sub_7016B0()
{
  LODWORD(dword_845658) = 1053364187;
}

//----- (007016C0) --------------------------------------------------------  // acclient.c:789132
void sub_7016C0()
{
  flt_84565C = 1000.0 + 1.0;
}

//----- (007016E0) --------------------------------------------------------  // acclient.c:789138
void sub_7016E0()
{
  flt_845660 = 24.0 * 8.0;
}

//----- (00701700) --------------------------------------------------------  // acclient.c:789144
void sub_701700()
{
  flt_845664 = 24.0 * 0.5;
}

//----- (00701720) --------------------------------------------------------  // acclient.c:789150
int _E99_36()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_32, "Render.TextureFiltering");
  return atexit(sub_76B6F0);
}

//----- (00701740) --------------------------------------------------------  // acclient.c:789157
int _E102_25()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_32, "Render.LandscapeDetailTextures");
  return atexit(sub_76B720);
}

//----- (00701760) --------------------------------------------------------  // acclient.c:789164
int _E105_41()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_32, "Render.BuildingDetailTextures");
  return atexit(sub_76B750);
}

//----- (00701780) --------------------------------------------------------  // acclient.c:789171
int _E108_80()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_32, "Render.FieldOfView");
  return atexit(sub_76B780);
}

//----- (007017A0) --------------------------------------------------------  // acclient.c:789178
int _E111_44()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_32, "Render.LandscapeTextureDetail");
  return atexit(sub_76B7B0);
}

//----- (007017C0) --------------------------------------------------------  // acclient.c:789185
int _E114_54()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_32, "Render.EnvironmentTextureDetail");
  return atexit(sub_76B7E0);
}

//----- (007017E0) --------------------------------------------------------  // acclient.c:789192
int _E117_62()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_32, "Render.SceneryDrawDistance");
  return atexit(sub_76B810);
}

//----- (00701800) --------------------------------------------------------  // acclient.c:789199
int _E120_60()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_32, "Render.LandscapeDrawDistance");
  return atexit(sub_76B840);
}

//----- (00701820) --------------------------------------------------------  // acclient.c:789206
int _E123_38()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_32, "Render.ScreenBrightness");
  return atexit(sub_76B870);
}

//----- (00701840) --------------------------------------------------------  // acclient.c:789213
int _E126_44()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_32, "Render.AspectRatio");
  return atexit(sub_76B8A0);
}

//----- (00701860) --------------------------------------------------------  // acclient.c:789220
int _E129_36()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_32, "Render.DisplayAdapter");
  return atexit(sub_76B8D0);
}

//----- (00701880) --------------------------------------------------------  // acclient.c:789227
int _E132_39()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_32, "Render.MaxHardwareClass");
  return atexit(_E133_98);
}

//----- (007018A0) --------------------------------------------------------  // acclient.c:789234
int _E135_42()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_32, "Render.AutomaticDegrades");
  return atexit(_E136_81);
}

//----- (007018C0) --------------------------------------------------------  // acclient.c:789241
int _E138_34()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_32, "Render.GraphicsPerformance");
  return atexit(_E139_81);
}

//----- (007018E0) --------------------------------------------------------  // acclient.c:789248
int _E141_34()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_32, "Render.DegradeDistance");
  return atexit(_E142_76);
}

//----- (00701900) --------------------------------------------------------  // acclient.c:789255
int _E144_33()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_32, "Render.MultiPassAlpha");
  return atexit(_E145_78);
}

//----- (00701920) --------------------------------------------------------  // acclient.c:789262
int _E147_31()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_32, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8456B0, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8456B4, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8456B8, "Anisotropic");
  return atexit(_E148_74);
}

//----- (00701970) --------------------------------------------------------  // acclient.c:789272
int _E150_31()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_32, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8456C0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8456C4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8456C8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8456CC, "VeryHigh");
  return atexit(_E151_72);
}

//----- (007019D0) --------------------------------------------------------  // acclient.c:789283
int _E153_29()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_32, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8456D4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8456D8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8456DC, "High");
  PStringBase<char>::PStringBase<char>(&stru_8456E0, "VeryHigh");
  return atexit(_E154_73);
}

//----- (00701A30) --------------------------------------------------------  // acclient.c:789294
int _E156_31()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_32, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8456E8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8456EC, "High");
  return atexit(_E157_69);
}

//----- (00701A70) --------------------------------------------------------  // acclient.c:789303
int _E159_29()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_32, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8456F4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8456F8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8456FC, "High");
  PStringBase<char>::PStringBase<char>(&stru_845700, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_845704, "Extreme");
  return atexit(_E160_72);
}

//----- (00701AE0) --------------------------------------------------------  // acclient.c:789315
int _E162_31()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_32, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_84570C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_845710, "Wide");
  return atexit(_E163_65);
}

//----- (00701B20) --------------------------------------------------------  // acclient.c:789324
int _E165_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_56, "None");
  return atexit(_E166_67);
}

//----- (00701B40) --------------------------------------------------------  // acclient.c:789331
int _E168_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_56, "Speed");
  return atexit(_E169_66);
}

//----- (00701B60) --------------------------------------------------------  // acclient.c:789338
int _E171_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_56, "Noise");
  return atexit(_E172_64);
}

//----- (00701B80) --------------------------------------------------------  // acclient.c:789345
int _E174_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_56, "Sine");
  return atexit(_E175_61);
}

//----- (00701BA0) --------------------------------------------------------  // acclient.c:789352
int _E177_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_56, "Square");
  return atexit(_E178_61);
}

//----- (00701BC0) --------------------------------------------------------  // acclient.c:789359
int _E180_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_56, "Bounce");
  return atexit(_E181_61);
}

//----- (00701BE0) --------------------------------------------------------  // acclient.c:789366
int _E183_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_56, "Perlin");
  return atexit(_E184_58);
}

//----- (00701C00) --------------------------------------------------------  // acclient.c:789373
int _E186_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_56, "Fractal");
  return atexit(_E187_57);
}

//----- (00701C20) --------------------------------------------------------  // acclient.c:789380
int _E189_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_56, "FrameLoop");
  return atexit(_E190_58);
}

//----- (00701C40) --------------------------------------------------------  // acclient.c:789387
int sub_701C40()
{
  return atexit(nullsub_1178);
}

//----- (0076B6F0) --------------------------------------------------------  // acclient.c:898699
void __cdecl sub_76B6F0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B720) --------------------------------------------------------  // acclient.c:898712
void __cdecl sub_76B720()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B750) --------------------------------------------------------  // acclient.c:898725
void __cdecl sub_76B750()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B780) --------------------------------------------------------  // acclient.c:898738
void __cdecl sub_76B780()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B7B0) --------------------------------------------------------  // acclient.c:898751
void __cdecl sub_76B7B0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B7E0) --------------------------------------------------------  // acclient.c:898764
void __cdecl sub_76B7E0()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B810) --------------------------------------------------------  // acclient.c:898777
void __cdecl sub_76B810()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B840) --------------------------------------------------------  // acclient.c:898790
void __cdecl sub_76B840()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B870) --------------------------------------------------------  // acclient.c:898803
void __cdecl sub_76B870()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B8A0) --------------------------------------------------------  // acclient.c:898816
void __cdecl sub_76B8A0()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B8D0) --------------------------------------------------------  // acclient.c:898829
void __cdecl sub_76B8D0()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B900) --------------------------------------------------------  // acclient.c:898842
void __cdecl _E133_98()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B930) --------------------------------------------------------  // acclient.c:898855
void __cdecl _E136_81()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B960) --------------------------------------------------------  // acclient.c:898868
void __cdecl _E139_81()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B990) --------------------------------------------------------  // acclient.c:898881
void __cdecl _E142_76()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B9C0) --------------------------------------------------------  // acclient.c:898894
void __cdecl _E145_78()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B9F0) --------------------------------------------------------  // acclient.c:898907
void __cdecl _E148_74()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_32;
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

//----- (0076BA30) --------------------------------------------------------  // acclient.c:898932
void __cdecl _E151_72()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_32;
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

//----- (0076BA70) --------------------------------------------------------  // acclient.c:898957
void __cdecl _E154_73()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_32;
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

//----- (0076BAB0) --------------------------------------------------------  // acclient.c:898982
void __cdecl _E157_69()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_32;
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

//----- (0076BAF0) --------------------------------------------------------  // acclient.c:899007
void __cdecl _E160_72()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_32;
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

//----- (0076BB30) --------------------------------------------------------  // acclient.c:899032
void __cdecl _E163_65()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_56;
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

//----- (0076BB70) --------------------------------------------------------  // acclient.c:899057
void __cdecl _E166_67()
{
  char *v0; // esi@1

  v0 = &waveform_None_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BBA0) --------------------------------------------------------  // acclient.c:899070
void __cdecl _E169_66()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BBD0) --------------------------------------------------------  // acclient.c:899083
void __cdecl _E172_64()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BC00) --------------------------------------------------------  // acclient.c:899096
void __cdecl _E175_61()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BC30) --------------------------------------------------------  // acclient.c:899109
void __cdecl _E178_61()
{
  char *v0; // esi@1

  v0 = &waveform_Square_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BC60) --------------------------------------------------------  // acclient.c:899122
void __cdecl _E181_61()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BC90) --------------------------------------------------------  // acclient.c:899135
void __cdecl _E184_58()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BCC0) --------------------------------------------------------  // acclient.c:899148
void __cdecl _E187_57()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BCF0) --------------------------------------------------------  // acclient.c:899161
void __cdecl _E190_58()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

