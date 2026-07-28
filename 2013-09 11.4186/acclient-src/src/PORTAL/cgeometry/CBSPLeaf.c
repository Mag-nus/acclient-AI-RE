/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBSPLeaf
   Object     : PORTAL\cgeometry\CBSPLeaf.obj
   Functions  : 84
   Addresses  : 0053D3D0 - 0076B6B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053D3D0) --------------------------------------------------------  // acclient.c:364072
void __thiscall BSPLEAF::BSPLEAF(BSPLEAF *this)
{
  BSPLEAF *v1; // esi@1

  v1 = this;
  BSPNODE::BSPNODE((BSPNODE *)&this->vfptr);
  v1->vfptr = (BSPNODEVtbl *)&BSPLEAF::vftable;
  v1->leaf_index = -1;
  v1->solid = 0;
}
// 7C9BA4: using guessed type int (__thiscall *BSPLEAF::vftable)(void *, char);

//----- (0053D3F0) --------------------------------------------------------  // acclient.c:364085
BOOL __thiscall BSPLEAF::point_intersects_solid(BSPLEAF *this, AC1Legacy::Vector3 *point)
{
  return this->num_polys != 0;
}

//----- (0053D400) --------------------------------------------------------  // acclient.c:364091
unsigned int __thiscall BSPLEAF::PackLeaf(BSPLEAF *this, void **addr, unsigned int size)
{
  BSPLEAF *v3; // edi@1
  unsigned int v4; // ebx@1
  char *v5; // eax@4
  unsigned int v6; // eax@5

  v3 = this;
  v4 = 4;
  if ( BSPNODE::pack_tree_type == 1 )
    v4 = 2 * this->num_polys + 28;
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = this->leaf_index;
    v5 = (char *)*addr + 4;
    *addr = v5;
    if ( BSPNODE::pack_tree_type == 1 )
    {
      *(_DWORD *)v5 = this->solid;
      *addr = (char *)*addr + 4;
      Plane::Pack((Plane *)&this->sphere, addr, size);
      *(_DWORD *)*addr = v3->num_polys;
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
    }
  }
  return v4;
}
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053D4A0) --------------------------------------------------------  // acclient.c:364132
int __thiscall BSPLEAF::UnPackLeaf(BSPLEAF *this, void **addr, unsigned int size)
{
  BSPLEAF *v3; // edi@1
  char *v4; // edx@1
  char *v5; // edx@2
  char *v6; // eax@2
  char *v7; // edx@3
  char *v8; // ecx@3
  char *v9; // eax@4
  unsigned int v10; // eax@4
  void *v11; // eax@5
  unsigned int v12; // ecx@5
  unsigned int v13; // eax@5
  __int16 v14; // dx@6

  v3 = this;
  this->leaf_index = *(_DWORD *)*addr;
  v4 = (char *)*addr + 4;
  *addr = v4;
  if ( BSPNODE::pack_tree_type == 1 )
  {
    this->solid = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = v5;
    if ( size >= 0xC )
    {
      LODWORD(this->sphere.center.x) = *(_DWORD *)v5;
      v7 = (char *)*addr + 4;
      *addr = v7;
      LODWORD(this->sphere.center.y) = *(_DWORD *)v7;
      v8 = (char *)*addr + 4;
      *addr = v8;
      LODWORD(v3->sphere.center.z) = *(_DWORD *)v8;
      v6 = (char *)*addr + 4;
      *addr = v6;
    }
    LODWORD(v3->sphere.radius) = *(_DWORD *)v6;
    v9 = (char *)*addr + 4;
    *addr = v9;
    v3->num_polys = *(_DWORD *)v9;
    *addr = (char *)*addr + 4;
    v10 = v3->num_polys;
    if ( v10 )
    {
      v11 = operator new[](4 * v10);
      v12 = v3->num_polys;
      v3->in_polys = (CPolygon **)v11;
      v13 = 0;
      if ( v12 )
      {
        do
        {
          v14 = *(_WORD *)*addr;
          *addr = (char *)*addr + 2;
          v3->in_polys[v13++] = &BSPNODE::pack_poly[v14];
        }
        while ( v13 < v3->num_polys );
      }
    }
  }
  return 1;
}
// 845378: using guessed type struct CPolygon *BSPNODE::pack_poly;
// 84537C: using guessed type enum BSPTreeType BSPNODE::pack_tree_type;

//----- (0053D580) --------------------------------------------------------  // acclient.c:364199
int __thiscall BSPLEAF::sphere_intersects_poly(BSPLEAF *this, CSphere *check_pos, AC1Legacy::Vector3 *movement, CPolygon **polygon, AC1Legacy::Vector3 *contact_pt)
{
  BSPLEAF *v5; // edi@1
  unsigned int v6; // ebx@1
  int result; // eax@3
  unsigned int v8; // esi@4

  v5 = this;
  v6 = this->num_polys;
  if ( v6 && CSphere::intersects(&this->sphere, check_pos) )
  {
    v8 = 0;
    if ( v6 )
    {
      while ( !CPolygon::pos_hits_sphere(v5->in_polys[v8], check_pos, movement, contact_pt, polygon) )
      {
        ++v8;
        if ( v8 >= v5->num_polys )
          goto LABEL_7;
      }
      result = 1;
    }
    else
    {
LABEL_7:
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053D5F0) --------------------------------------------------------  // acclient.c:364235
int __thiscall BSPLEAF::sphere_intersects_solid(BSPLEAF *this, CSphere *check_pos, int center_check)
{
  BSPLEAF *v3; // esi@1
  unsigned int v4; // ebx@1
  int result; // eax@2
  unsigned int v6; // edi@7

  v3 = this;
  v4 = this->num_polys;
  if ( v4 )
  {
    if ( center_check && this->solid )
    {
      result = 1;
    }
    else if ( CSphere::intersects(&this->sphere, check_pos) && (v6 = 0, v4) )
    {
      while ( !CPolygon::hits_sphere(v3->in_polys[v6], check_pos) )
      {
        ++v6;
        if ( v6 >= v3->num_polys )
          goto LABEL_10;
      }
      result = 1;
    }
    else
    {
LABEL_10:
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053D670) --------------------------------------------------------  // acclient.c:364274
int __thiscall BSPLEAF::hits_walkable(BSPLEAF *this, SPHEREPATH *path, CSphere *valid_pos, AC1Legacy::Vector3 *up)
{
  BSPLEAF *v4; // edi@1
  unsigned int v5; // ebx@1
  int result; // eax@2
  unsigned int v7; // esi@4

  v4 = this;
  v5 = this->num_polys;
  if ( v5 )
  {
    if ( CSphere::intersects(&this->sphere, valid_pos) && (v7 = 0, v5) )
    {
      while ( !CPolygon::walkable_hits_sphere(v4->in_polys[v7], path, valid_pos, up)
           || !CPolygon::check_small_walkable(v4->in_polys[v7], valid_pos, up) )
      {
        ++v7;
        if ( v7 >= v4->num_polys )
          goto LABEL_8;
      }
      result = 1;
    }
    else
    {
LABEL_8:
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053D6F0) --------------------------------------------------------  // acclient.c:364310
void __thiscall BSPLEAF::find_walkable(BSPLEAF *this, SPHEREPATH *path, CSphere *valid_pos, CPolygon **polygon, AC1Legacy::Vector3 *movement, AC1Legacy::Vector3 *up, int *changed)
{
  BSPLEAF *v7; // edi@1
  unsigned int v8; // ebx@1
  unsigned int v9; // esi@3

  v7 = this;
  v8 = this->num_polys;
  if ( v8 )
  {
    if ( CSphere::intersects(&this->sphere, valid_pos) )
    {
      v9 = 0;
      if ( v8 )
      {
        do
        {
          if ( CPolygon::walkable_hits_sphere(v7->in_polys[v9], path, valid_pos, up) )
          {
            if ( CPolygon::adjust_sphere_to_plane(v7->in_polys[v9], path, valid_pos, movement) )
            {
              *changed = 1;
              *polygon = v7->in_polys[v9];
            }
          }
          ++v9;
        }
        while ( v9 < v7->num_polys );
      }
    }
  }
}

//----- (0053D780) --------------------------------------------------------  // acclient.c:364344
int __thiscall BSPLEAF::sphere_intersects_solid_poly(BSPLEAF *this, CSphere *check_pos, float radius, int *center_solid, CPolygon **hit_poly, int center_check)
{
  BSPLEAF *v6; // esi@1
  int result; // eax@2
  unsigned int v8; // edi@7

  v6 = this;
  if ( this->num_polys )
  {
    if ( center_check && this->solid )
      *center_solid = 1;
    if ( CSphere::intersects(&this->sphere, check_pos) && (v8 = 0, v6->num_polys) )
    {
      while ( !CPolygon::hits_sphere(v6->in_polys[v8], check_pos) )
      {
        ++v8;
        if ( v8 >= v6->num_polys )
          goto LABEL_10;
      }
      *hit_poly = v6->in_polys[v8];
      result = 1;
    }
    else
    {
LABEL_10:
      result = *center_solid;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0053D810) --------------------------------------------------------  // acclient.c:364380
BSPNODE *__thiscall BSPLEAF::scalar_deleting_destructor(BSPLEAF *this, unsigned int a2)
{
  BSPNODE *v2; // esi@1

  v2 = (BSPNODE *)this;
  this->vfptr = (BSPNODEVtbl *)&BSPLEAF::vftable;
  this->leaf_index = -1;
  BSPNODE::Destroy((BSPNODE *)&this->vfptr);
  BSPNODE::~BSPNODE(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9BA4: using guessed type int (__thiscall *BSPLEAF::vftable)(void *, char);

//----- (00701060) --------------------------------------------------------  // acclient.c:788807
void _E89_5()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8454CC, PFID_A8R8G8B8);
}

//----- (00701070) --------------------------------------------------------  // acclient.c:788813
void sub_701070()
{
  LODWORD(dword_845504) = 1053364187;
}

//----- (00701080) --------------------------------------------------------  // acclient.c:788819
void sub_701080()
{
  flt_845508 = 1000.0 + 1.0;
}

//----- (007010A0) --------------------------------------------------------  // acclient.c:788825
void sub_7010A0()
{
  flt_84550C = 24.0 * 8.0;
}

//----- (007010C0) --------------------------------------------------------  // acclient.c:788831
void sub_7010C0()
{
  flt_845510 = 24.0 * 0.5;
}

//----- (007010E0) --------------------------------------------------------  // acclient.c:788837
int _E99_35()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_31, "Render.TextureFiltering");
  return atexit(sub_76B0B0);
}

//----- (00701100) --------------------------------------------------------  // acclient.c:788844
int _E102_24()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_31, "Render.LandscapeDetailTextures");
  return atexit(sub_76B0E0);
}

//----- (00701120) --------------------------------------------------------  // acclient.c:788851
int _E105_40()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_31, "Render.BuildingDetailTextures");
  return atexit(sub_76B110);
}

//----- (00701140) --------------------------------------------------------  // acclient.c:788858
int _E108_79()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_31, "Render.FieldOfView");
  return atexit(sub_76B140);
}

//----- (00701160) --------------------------------------------------------  // acclient.c:788865
int _E111_43()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_31, "Render.LandscapeTextureDetail");
  return atexit(sub_76B170);
}

//----- (00701180) --------------------------------------------------------  // acclient.c:788872
int _E114_53()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_31, "Render.EnvironmentTextureDetail");
  return atexit(sub_76B1A0);
}

//----- (007011A0) --------------------------------------------------------  // acclient.c:788879
int _E117_61()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_31, "Render.SceneryDrawDistance");
  return atexit(sub_76B1D0);
}

//----- (007011C0) --------------------------------------------------------  // acclient.c:788886
int _E120_59()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_31, "Render.LandscapeDrawDistance");
  return atexit(sub_76B200);
}

//----- (007011E0) --------------------------------------------------------  // acclient.c:788893
int _E123_37()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_31, "Render.ScreenBrightness");
  return atexit(sub_76B230);
}

//----- (00701200) --------------------------------------------------------  // acclient.c:788900
int _E126_43()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_31, "Render.AspectRatio");
  return atexit(sub_76B260);
}

//----- (00701220) --------------------------------------------------------  // acclient.c:788907
int _E129_35()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_31, "Render.DisplayAdapter");
  return atexit(sub_76B290);
}

//----- (00701240) --------------------------------------------------------  // acclient.c:788914
int _E132_38()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_31, "Render.MaxHardwareClass");
  return atexit(_E133_97);
}

//----- (00701260) --------------------------------------------------------  // acclient.c:788921
int _E135_41()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_31, "Render.AutomaticDegrades");
  return atexit(_E136_80);
}

//----- (00701280) --------------------------------------------------------  // acclient.c:788928
int _E138_33()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_31, "Render.GraphicsPerformance");
  return atexit(_E139_80);
}

//----- (007012A0) --------------------------------------------------------  // acclient.c:788935
int _E141_33()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_31, "Render.DegradeDistance");
  return atexit(_E142_75);
}

//----- (007012C0) --------------------------------------------------------  // acclient.c:788942
int _E144_32()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_31, "Render.MultiPassAlpha");
  return atexit(_E145_77);
}

//----- (007012E0) --------------------------------------------------------  // acclient.c:788949
int _E147_30()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_31, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_84555C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_845560, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_845564, "Anisotropic");
  return atexit(_E148_73);
}

//----- (00701330) --------------------------------------------------------  // acclient.c:788959
int _E150_30()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_31, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_84556C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845570, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845574, "High");
  PStringBase<char>::PStringBase<char>(&stru_845578, "VeryHigh");
  return atexit(_E151_71);
}

//----- (00701390) --------------------------------------------------------  // acclient.c:788970
int _E153_28()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_31, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_845580, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845584, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845588, "High");
  PStringBase<char>::PStringBase<char>(&stru_84558C, "VeryHigh");
  return atexit(_E154_72);
}

//----- (007013F0) --------------------------------------------------------  // acclient.c:788981
int _E156_30()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_31, "Low");
  PStringBase<char>::PStringBase<char>(&stru_845594, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_845598, "High");
  return atexit(_E157_68);
}

//----- (00701430) --------------------------------------------------------  // acclient.c:788990
int _E159_28()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_31, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8455A0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8455A4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8455A8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8455AC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8455B0, "Extreme");
  return atexit(_E160_71);
}

//----- (007014A0) --------------------------------------------------------  // acclient.c:789002
int _E162_30()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_31, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8455B8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8455BC, "Wide");
  return atexit(_E163_64);
}

//----- (007014E0) --------------------------------------------------------  // acclient.c:789011
int _E165_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_55, "None");
  return atexit(_E166_66);
}

//----- (00701500) --------------------------------------------------------  // acclient.c:789018
int _E168_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_55, "Speed");
  return atexit(_E169_65);
}

//----- (00701520) --------------------------------------------------------  // acclient.c:789025
int _E171_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_55, "Noise");
  return atexit(_E172_63);
}

//----- (00701540) --------------------------------------------------------  // acclient.c:789032
int _E174_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_55, "Sine");
  return atexit(_E175_60);
}

//----- (00701560) --------------------------------------------------------  // acclient.c:789039
int _E177_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_55, "Square");
  return atexit(_E178_60);
}

//----- (00701580) --------------------------------------------------------  // acclient.c:789046
int _E180_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_55, "Bounce");
  return atexit(_E181_60);
}

//----- (007015A0) --------------------------------------------------------  // acclient.c:789053
int _E183_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_55, "Perlin");
  return atexit(_E184_57);
}

//----- (007015C0) --------------------------------------------------------  // acclient.c:789060
int _E186_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_55, "Fractal");
  return atexit(_E187_56);
}

//----- (007015E0) --------------------------------------------------------  // acclient.c:789067
int _E189_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_55, "FrameLoop");
  return atexit(_E190_57);
}

//----- (00701600) --------------------------------------------------------  // acclient.c:789074
void _E192_20()
{
  flt_8455E4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00701620) --------------------------------------------------------  // acclient.c:789080
void _E194_6()
{
  dbl_8455E8 = 1.0 / 30.0;
}

//----- (00701640) --------------------------------------------------------  // acclient.c:789086
void _E196_19()
{
  dbl_8455F0 = 1.0 / 5.0;
}

//----- (00701660) --------------------------------------------------------  // acclient.c:789092
void _E198_18()
{
  dword_8455F8 = 1024;
}

//----- (00701670) --------------------------------------------------------  // acclient.c:789098
void _E200_4()
{
  dword_8455FC = 0x7FFF;
}

//----- (00701680) --------------------------------------------------------  // acclient.c:789104
int _E202_16()
{
  const int result; // eax@1

  result = dword_8455F8;
  INITIAL_MAX_DATA_RATE_96 = dword_8455F8;
  return result;
}

//----- (00701690) --------------------------------------------------------  // acclient.c:789114
int sub_701690()
{
  return atexit(nullsub_1179);
}

//----- (0076B0B0) --------------------------------------------------------  // acclient.c:898224
void __cdecl sub_76B0B0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B0E0) --------------------------------------------------------  // acclient.c:898237
void __cdecl sub_76B0E0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B110) --------------------------------------------------------  // acclient.c:898250
void __cdecl sub_76B110()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B140) --------------------------------------------------------  // acclient.c:898263
void __cdecl sub_76B140()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B170) --------------------------------------------------------  // acclient.c:898276
void __cdecl sub_76B170()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B1A0) --------------------------------------------------------  // acclient.c:898289
void __cdecl sub_76B1A0()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B1D0) --------------------------------------------------------  // acclient.c:898302
void __cdecl sub_76B1D0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B200) --------------------------------------------------------  // acclient.c:898315
void __cdecl sub_76B200()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B230) --------------------------------------------------------  // acclient.c:898328
void __cdecl sub_76B230()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B260) --------------------------------------------------------  // acclient.c:898341
void __cdecl sub_76B260()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B290) --------------------------------------------------------  // acclient.c:898354
void __cdecl sub_76B290()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B2C0) --------------------------------------------------------  // acclient.c:898367
void __cdecl _E133_97()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B2F0) --------------------------------------------------------  // acclient.c:898380
void __cdecl _E136_80()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B320) --------------------------------------------------------  // acclient.c:898393
void __cdecl _E139_80()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B350) --------------------------------------------------------  // acclient.c:898406
void __cdecl _E142_75()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B380) --------------------------------------------------------  // acclient.c:898419
void __cdecl _E145_77()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B3B0) --------------------------------------------------------  // acclient.c:898432
void __cdecl _E148_73()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_31;
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

//----- (0076B3F0) --------------------------------------------------------  // acclient.c:898457
void __cdecl _E151_71()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_31;
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

//----- (0076B430) --------------------------------------------------------  // acclient.c:898482
void __cdecl _E154_72()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_31;
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

//----- (0076B470) --------------------------------------------------------  // acclient.c:898507
void __cdecl _E157_68()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_31;
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

//----- (0076B4B0) --------------------------------------------------------  // acclient.c:898532
void __cdecl _E160_71()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_31;
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

//----- (0076B4F0) --------------------------------------------------------  // acclient.c:898557
void __cdecl _E163_64()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_55;
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

//----- (0076B530) --------------------------------------------------------  // acclient.c:898582
void __cdecl _E166_66()
{
  char *v0; // esi@1

  v0 = &waveform_None_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B560) --------------------------------------------------------  // acclient.c:898595
void __cdecl _E169_65()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B590) --------------------------------------------------------  // acclient.c:898608
void __cdecl _E172_63()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B5C0) --------------------------------------------------------  // acclient.c:898621
void __cdecl _E175_60()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B5F0) --------------------------------------------------------  // acclient.c:898634
void __cdecl _E178_60()
{
  char *v0; // esi@1

  v0 = &waveform_Square_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B620) --------------------------------------------------------  // acclient.c:898647
void __cdecl _E181_60()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B650) --------------------------------------------------------  // acclient.c:898660
void __cdecl _E184_57()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B680) --------------------------------------------------------  // acclient.c:898673
void __cdecl _E187_56()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076B6B0) --------------------------------------------------------  // acclient.c:898686
void __cdecl _E190_57()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

