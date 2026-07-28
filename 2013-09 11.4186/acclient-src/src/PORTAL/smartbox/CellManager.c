/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CellManager
   Object     : PORTAL\smartbox\CellManager.obj
   Functions  : 102
   Addresses  : 00455710 - 0075C880 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00455710) --------------------------------------------------------  // acclient.c:146438
void __thiscall CellManager::UpdateLoadPoint(CellManager *this)
{
  unsigned int v1; // eax@1

  v1 = this->load_pos.objcell_id;
  if ( v1 )
  {
    if ( (unsigned __int16)v1 < 0x100u )
      LScape::update_loadpoint(this->lscape, v1);
  }
}

//----- (00455730) --------------------------------------------------------  // acclient.c:146451
double __cdecl LScape::calc_object_light()
{
  return sqrt(LScape::sunlight.z * LScape::sunlight.z + LScape::sunlight.y * LScape::sunlight.y + LScape::sunlight.x
                                                                                                * LScape::sunlight.x)
       * 0.2
       + LScape::ambient_level;
}

//----- (00455770) --------------------------------------------------------  // acclient.c:146460
void __thiscall Ambient::ReleaseSoundTables(Ambient *this)
{
  Ambient *v1; // ebx@1
  unsigned int v2; // edi@1
  AmbientSTBDesc *v3; // esi@2
  CSoundTable *v4; // ecx@2

  v1 = this;
  v2 = 0;
  if ( this->num_sounds )
  {
    do
    {
      v3 = v1->sounds.data[v2]->desc;
      v4 = v3->sound_table;
      if ( v4 )
      {
        if ( !v3->play_count )
        {
          ((void (*)(void))v4->vfptr->Release)();
          v3->sound_table = 0;
        }
      }
      ++v2;
    }
    while ( v2 < v1->num_sounds );
  }
}

//----- (004557B0) --------------------------------------------------------  // acclient.c:146490
void __thiscall CellManager::CellManager(CellManager *this)
{
  CellManager *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->lscape = 0;
  this->last_prefetch_cell_id = 0;
  *(_QWORD *)&this->last_prefetch_check = 0i64;
  this->blocking_for_cells = 0;
  this->all_cells_available = 1;
  this->num_cells_waiting = 0;
  this->total_num_cells_waiting = 0;
  this->curr_cell = 0;
  v2 = (char *)&this->load_pos.frame;
  v1->load_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->load_pos.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v1->keep_lscape_loaded = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00455810) --------------------------------------------------------  // acclient.c:146520
void __thiscall CellManager::~CellManager(CellManager *this)
{
  this->load_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00455820) --------------------------------------------------------  // acclient.c:146527
int __thiscall CellManager::PreFetchCells(CellManager *this, IDClass<_tagDataID,32,0> cell_did, int blocking)
{
  CellManager *v3; // esi@1
  int result; // eax@2
  unsigned int v5; // ecx@3
  int v6; // eax@8
  unsigned int v7; // eax@15
  unsigned int v8; // eax@19
  unsigned int v9; // ST08_4@19
  unsigned int num_waiting_elements; // [sp+0h] [bp-4h]@1

  num_waiting_elements = (unsigned int)this;
  v3 = this;
  if ( (unsigned __int8)((int (*)(void))DBCache::s_pCache->vfptr[2].QueryInterface)() )
    return 1;
  v5 = 0;
  num_waiting_elements = 0;
  if ( (unsigned __int16)cell_did.id >= 0x100u )
  {
    v6 = CEnvCell::PreFetchCells((CEnvCell *)cell_did.id, (IDClass<_tagDataID,32,0>)&num_waiting_elements);
  }
  else
  {
    if ( !blocking && v3->all_cells_available && !((cell_did.id ^ v3->last_prefetch_cell_id) & 0xFFFF0000) )
    {
      v3->all_cells_available = 1;
      goto LABEL_13;
    }
    v6 = LScape::PreFetchCells(v3->lscape, (IDClass<_tagDataID,32,0>)(cell_did.id | 0xFFFF), &num_waiting_elements);
  }
  v5 = num_waiting_elements;
  if ( v6 )
    v3->all_cells_available = 1;
  else
    v3->all_cells_available = 0;
LABEL_13:
  v3->last_prefetch_cell_id = cell_did.id;
  if ( !blocking )
  {
    if ( !v3->all_cells_available )
      return v3->all_cells_available;
LABEL_24:
    if ( v3->blocking_for_cells )
    {
      v3->blocking_for_cells = 0;
      ECM_DDD::SendNotice_RuntimeDDDStatus(0, 0, 0);
      v3->num_cells_waiting = 0;
      v3->total_num_cells_waiting = 0;
    }
    return v3->all_cells_available;
  }
  if ( v5 )
  {
    v7 = v3->total_num_cells_waiting;
    if ( v7 )
    {
      if ( v5 > v7 )
        v3->total_num_cells_waiting = v5;
      v8 = v3->total_num_cells_waiting - v5;
      v9 = v3->total_num_cells_waiting;
      v3->num_cells_waiting = v8;
      ECM_DDD::SendNotice_RuntimeDDDStatus(1, v8, v9);
    }
    else
    {
      v3->total_num_cells_waiting = v5;
      ECM_DDD::SendNotice_RuntimeDDDStatus(1, 0, v5);
    }
  }
  if ( v3->all_cells_available )
    goto LABEL_24;
  if ( !v3->blocking_for_cells )
  {
    result = v3->all_cells_available;
    v3->blocking_for_cells = 1;
    return result;
  }
  return v3->all_cells_available;
}

//----- (00455930) --------------------------------------------------------  // acclient.c:146608
void __thiscall CellManager::Reset(CellManager *this)
{
  CellManager *v1; // esi@1
  unsigned int v2; // eax@1
  CObjCell *v3; // ecx@1
  bool v4; // bl@1
  bool v5; // al@7

  v1 = this;
  v2 = this->load_pos.objcell_id;
  v3 = this->curr_cell;
  v4 = (unsigned __int16)v2 < 0x100u;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr[4].Release)();
    ((void (*)(void))v1->curr_cell->vfptr->Release)();
    if ( v1->curr_cell->seen_outside )
      v4 = 1;
    v1->curr_cell = 0;
    CEnvCell::flush_cells();
  }
  if ( v4 )
    LScape::release_all(v1->lscape);
  Ambient::FlushSoundTables(v1->ambient_sounds);
  v5 = v1->blocking_for_cells;
  v1->load_pos.objcell_id = 0;
  if ( v5 )
  {
    v1->blocking_for_cells = 0;
    ECM_DDD::SendNotice_RuntimeDDDStatus(0, 0, 0);
    v1->num_cells_waiting = 0;
    v1->total_num_cells_waiting = 0;
  }
  v1->all_cells_available = 1;
}

//----- (004559B0) --------------------------------------------------------  // acclient.c:146645
void __userpurge CellManager::ChangePosition(CellManager *this@<ecx>, double a2@<st0>, Position *p, int blocking)
{
  Position *v4; // ebp@1
  unsigned int v5; // eax@1
  CellManager *v6; // esi@1
  signed int v7; // edi@3
  CObjCell *v8; // ecx@7
  unsigned int v9; // ecx@9
  int v10; // ebp@9
  unsigned int v11; // eax@12
  unsigned int v12; // edi@12
  unsigned int v13; // eax@17
  CObjCell *v14; // eax@21
  CObjCell *v15; // eax@22
  signed int v16; // ebp@25
  SmartBox *v17; // edi@32
  unsigned int v18; // ST04_4@33
  float v19; // ST00_4@33
  RGBColor v20; // [sp+18h] [bp-Ch]@32

  v4 = p;
  v5 = p->objcell_id;
  v6 = this;
  if ( !v5 )
  {
    CellManager::Reset(this);
    return;
  }
  v7 = 1;
  if ( !this->blocking_for_cells )
    v7 = blocking;
  if ( this->load_pos.objcell_id != v5 || !this->curr_cell )
  {
    CellManager::PreFetchCells(this, (IDClass<_tagDataID,32,0>)v5, v7);
    v8 = v6->curr_cell;
    if ( v8 )
    {
      ((void (*)(void))v8->vfptr[4].Release)();
      ((void (*)(void))v6->curr_cell->vfptr->Release)();
      v6->curr_cell = 0;
    }
    v9 = (unsigned __int16)p->objcell_id;
    v10 = v9 < 0x100;
    if ( v7 )
    {
      LScape::release_all(v6->lscape);
      goto LABEL_20;
    }
    if ( v9 < 0x100 )
      LScape::update_loadpoint(v6->lscape, p->objcell_id);
    v11 = CObjCell::Get(p->objcell_id);
    v12 = v11;
    if ( !v11 )
      goto LABEL_20;
    if ( !v10 )
    {
      if ( !*(_DWORD *)(v11 + 232) && !v6->keep_lscape_loaded )
      {
        LScape::release_all(v6->lscape);
        (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v12 + 112))(v12);
        v6->curr_cell = (CObjCell *)v12;
LABEL_20:
        if ( v6->curr_cell )
        {
          ++CEnvCell::master_incell_timestamp;
          Render::world_lights.num_static_lights = 0;
          Render::world_lights.num_dynamic_lights = 0;
          v14 = v6->curr_cell;
          cell_from = v14->pos.objcell_id;
          Frame::operator=((int)&stru_81EF50, (int)&v14->pos.frame);
        }
        CEnvCell::flush_cells();
        v15 = v6->curr_cell;
        if ( v15 )
        {
          if ( v10 || v15->seen_outside )
          {
            v20 = (RGBColor)LScape::sunlight;
            Render::world_lights.sunlight = LScape::sunlight;
            v16 = 1;
            RGBColor::SetColor32(&v20, LScape::sunlight_color.color);
            v17 = SmartBox::smartbox;
            Render::world_lights.sunlight_color = v20;
            Render::world_lights.m_bSunlightValid = 0;
            if ( SmartBox::smartbox )
            {
              v18 = LScape::ambient_color.color;
              a2 = LScape::calc_object_light();
              v19 = a2;
              SmartBox::SetWorldAmbientLight(v17, v19, v18);
            }
          }
          else
          {
            v16 = 0;
            if ( SmartBox::smartbox )
              SmartBox::SetWorldAmbientLight(SmartBox::smartbox, 0.2, 0xFFFFFFFF);
          }
          Ambient::InitSounds(v6->ambient_sounds, p);
          gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)v6->ambient_sounds);
          if ( v16 )
            LScape::add_ambient_sounds(v6->lscape, v6->ambient_sounds);
          Ambient::UpdatePlayQueue(v6->ambient_sounds, a2);
          Ambient::ReleaseSoundTables(v6->ambient_sounds);
        }
        v4 = p;
        goto LABEL_31;
      }
      v13 = Position::get_outside_cell_id(p);
      LScape::update_loadpoint(v6->lscape, v13);
    }
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v12 + 112))(v12);
    v6->curr_cell = (CObjCell *)v12;
    goto LABEL_20;
  }
LABEL_31:
  v6->load_pos.objcell_id = v4->objcell_id;
  Frame::operator=((int)&v6->load_pos.frame, (int)&v4->frame);
}
// 81DCB8: using guessed type int CEnvCell::master_incell_timestamp;

//----- (00455BE0) --------------------------------------------------------  // acclient.c:146767
int __thiscall CellManager::CheckPrefetchStatus(CellManager *this)
{
  CellManager *v1; // esi@1
  int v2; // eax@2
  unsigned int v3; // ecx@2
  int result; // eax@2

  v1 = this;
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - this->last_prefetch_check <= 5.0 )
  {
    result = 0;
  }
  else
  {
    v2 = CellManager::PreFetchCells(this, (IDClass<_tagDataID,32,0>)this->load_pos.objcell_id, this->blocking_for_cells);
    v3 = Timer::cur_time.Param;
    LODWORD(v1->last_prefetch_check) = Timer::cur_time.Cmd;
    HIDWORD(v1->last_prefetch_check) = v3;
    result = v2 != 0;
  }
  return result;
}

//----- (006E9AD0) --------------------------------------------------------  // acclient.c:765797
void _E91_28()
{
  outside_val_19 = 1000.0 + 1.0;
}

//----- (006E9AF0) --------------------------------------------------------  // acclient.c:765803
void _E93_8()
{
  block_length_19 = 24.0 * 8.0;
}

//----- (006E9B10) --------------------------------------------------------  // acclient.c:765809
void _E95_8()
{
  half_square_length_19 = 24.0 * 0.5;
}

//----- (006E9B30) --------------------------------------------------------  // acclient.c:765815
void _E97_27()
{
  DEFAULT_VIEW_RADIUS_6 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006E9B50) --------------------------------------------------------  // acclient.c:765821
void _E99_4()
{
  MIN_QUANTUM_6 = 1.0 / 30.0;
}

//----- (006E9B70) --------------------------------------------------------  // acclient.c:765827
void _E101()
{
  MAX_QUANTUM_6 = 1.0 / 5.0;
}

//----- (006E9B90) --------------------------------------------------------  // acclient.c:765833
void _E103_12()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_33, PFID_A8R8G8B8);
}

//----- (006E9BA0) --------------------------------------------------------  // acclient.c:765839
int _E105_5()
{
  return atexit(nullsub_306);
}

//----- (006E9BB0) --------------------------------------------------------  // acclient.c:765845
int _E108_8()
{
  return atexit(nullsub_307);
}

//----- (006E9BC0) --------------------------------------------------------  // acclient.c:765851
int _E111_7()
{
  return atexit(nullsub_308);
}

//----- (006E9BD0) --------------------------------------------------------  // acclient.c:765857
int _E114_9()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_2, "Sound.SoundDisabled");
  return atexit(sub_75C0C0);
}

//----- (006E9BF0) --------------------------------------------------------  // acclient.c:765864
int _E117_7()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_2, "Sound.SoundVolume");
  return atexit(sub_75C0F0);
}

//----- (006E9C10) --------------------------------------------------------  // acclient.c:765871
int _E120_10()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_2, "Sound.AmbientSoundDisabled");
  return atexit(sub_75C120);
}

//----- (006E9C30) --------------------------------------------------------  // acclient.c:765878
int _E123_7()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_2, "Sound.AmbientSoundVolume");
  return atexit(sub_75C150);
}

//----- (006E9C50) --------------------------------------------------------  // acclient.c:765885
int _E126_11()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_2, "Sound.InterfaceSoundDisabled");
  return atexit(_E127_92);
}

//----- (006E9C70) --------------------------------------------------------  // acclient.c:765892
int _E129_10()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_2, "Sound.InterfaceSoundVolume");
  return atexit(_E130_84);
}

//----- (006E9C90) --------------------------------------------------------  // acclient.c:765899
int _E132_11()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_2, "Sound.SoundFeatures");
  return atexit(_E133_77);
}

//----- (006E9CB0) --------------------------------------------------------  // acclient.c:765906
int _E135_10()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_2, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E136_61);
}

//----- (006E9CD0) --------------------------------------------------------  // acclient.c:765913
int _E138_11()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_2, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_83CCC4, "Mono");
  return atexit(_E139_62);
}

//----- (006E9D00) --------------------------------------------------------  // acclient.c:765921
void _E141_11()
{
  VOL_MIN_DIST_SQ_1 = 5.0 * 5.0;
}

//----- (006E9D20) --------------------------------------------------------  // acclient.c:765927
void _E143_0()
{
  INV_LOG_OF_2_1 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006E9D40) --------------------------------------------------------  // acclient.c:765933
int _E145_11()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_14, "Render.TextureFiltering");
  return atexit(_E146_20);
}

//----- (006E9D60) --------------------------------------------------------  // acclient.c:765940
int _E148_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_14, "Render.LandscapeDetailTextures");
  return atexit(_E149_20);
}

//----- (006E9D80) --------------------------------------------------------  // acclient.c:765947
int _E151_11()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_14, "Render.BuildingDetailTextures");
  return atexit(_E152_19);
}

//----- (006E9DA0) --------------------------------------------------------  // acclient.c:765954
int _E154_12()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_14, "Render.FieldOfView");
  return atexit(_E155_17);
}

//----- (006E9DC0) --------------------------------------------------------  // acclient.c:765961
int _E157_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_14, "Render.LandscapeTextureDetail");
  return atexit(_E158_20);
}

//----- (006E9DE0) --------------------------------------------------------  // acclient.c:765968
int _E160_12()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_14, "Render.EnvironmentTextureDetail");
  return atexit(_E161_17);
}

//----- (006E9E00) --------------------------------------------------------  // acclient.c:765975
int _E163_10()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_14, "Render.SceneryDrawDistance");
  return atexit(_E164_20);
}

//----- (006E9E20) --------------------------------------------------------  // acclient.c:765982
int _E166_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_14, "Render.LandscapeDrawDistance");
  return atexit(_E167_16);
}

//----- (006E9E40) --------------------------------------------------------  // acclient.c:765989
int _E169_9()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_14, "Render.ScreenBrightness");
  return atexit(_E170_15);
}

//----- (006E9E60) --------------------------------------------------------  // acclient.c:765996
int _E172_9()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_14, "Render.AspectRatio");
  return atexit(_E173_14);
}

//----- (006E9E80) --------------------------------------------------------  // acclient.c:766003
int _E175_9()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_14, "Render.DisplayAdapter");
  return atexit(_E176_15);
}

//----- (006E9EA0) --------------------------------------------------------  // acclient.c:766010
int _E178_9()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_14, "Render.MaxHardwareClass");
  return atexit(_E179_14);
}

//----- (006E9EC0) --------------------------------------------------------  // acclient.c:766017
int _E181_9()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_14, "Render.AutomaticDegrades");
  return atexit(_E182_14);
}

//----- (006E9EE0) --------------------------------------------------------  // acclient.c:766024
int _E184_7()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_14, "Render.GraphicsPerformance");
  return atexit(_E185_11);
}

//----- (006E9F00) --------------------------------------------------------  // acclient.c:766031
int _E187_7()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_14, "Render.DegradeDistance");
  return atexit(_E188_12);
}

//----- (006E9F20) --------------------------------------------------------  // acclient.c:766038
int _E190_7()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_14, "Render.MultiPassAlpha");
  return atexit(_E191_11);
}

//----- (006E9F40) --------------------------------------------------------  // acclient.c:766045
int _E193_7()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_14, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83CD1C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83CD20, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83CD24, "Anisotropic");
  return atexit(_E194_18);
}

//----- (006E9F90) --------------------------------------------------------  // acclient.c:766055
int _E196_9()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_14, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CD2C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CD30, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CD34, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CD38, "VeryHigh");
  return atexit(_E197_9);
}

//----- (006E9FF0) --------------------------------------------------------  // acclient.c:766066
int _E199_7()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_14, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CD40, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CD44, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CD48, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CD4C, "VeryHigh");
  return atexit(_E200_14);
}

//----- (006EA050) --------------------------------------------------------  // acclient.c:766077
int _E202_7()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_14, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CD54, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CD58, "High");
  return atexit(_E203_13);
}

//----- (006EA090) --------------------------------------------------------  // acclient.c:766086
int _E205_8()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_14, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83CD60, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83CD64, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83CD68, "High");
  PStringBase<char>::PStringBase<char>(&stru_83CD6C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83CD70, "Extreme");
  return atexit(_E206_16);
}

//----- (006EA100) --------------------------------------------------------  // acclient.c:766098
int _E208_10()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_14, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83CD78, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83CD7C, "Wide");
  return atexit(_E209_11);
}

//----- (006EA140) --------------------------------------------------------  // acclient.c:766107
int _E211_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_26, "None");
  return atexit(_E212_14);
}

//----- (006EA160) --------------------------------------------------------  // acclient.c:766114
int _E214_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_26, "Speed");
  return atexit(_E215_10);
}

//----- (006EA180) --------------------------------------------------------  // acclient.c:766121
int _E217_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_26, "Noise");
  return atexit(_E218_11);
}

//----- (006EA1A0) --------------------------------------------------------  // acclient.c:766128
int _E220_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_26, "Sine");
  return atexit(_E221_11);
}

//----- (006EA1C0) --------------------------------------------------------  // acclient.c:766135
int _E223_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_26, "Square");
  return atexit(_E224_11);
}

//----- (006EA1E0) --------------------------------------------------------  // acclient.c:766142
int _E226_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_26, "Bounce");
  return atexit(_E227_11);
}

//----- (006EA200) --------------------------------------------------------  // acclient.c:766149
int _E229_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_26, "Perlin");
  return atexit(_E230_11);
}

//----- (006EA220) --------------------------------------------------------  // acclient.c:766156
int _E232_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_26, "Fractal");
  return atexit(_E233_10);
}

//----- (006EA240) --------------------------------------------------------  // acclient.c:766163
int _E235_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_26, "FrameLoop");
  return atexit(_E236_10);
}

//----- (006EA260) --------------------------------------------------------  // acclient.c:766170
int _E1_48()
{
  return atexit(_E2_48);
}

//----- (0075C0C0) --------------------------------------------------------  // acclient.c:883986
void __cdecl sub_75C0C0()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C0F0) --------------------------------------------------------  // acclient.c:883999
void __cdecl sub_75C0F0()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C120) --------------------------------------------------------  // acclient.c:884012
void __cdecl sub_75C120()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C150) --------------------------------------------------------  // acclient.c:884025
void __cdecl sub_75C150()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C180) --------------------------------------------------------  // acclient.c:884038
void __cdecl _E127_92()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C1B0) --------------------------------------------------------  // acclient.c:884051
void __cdecl _E130_84()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C1E0) --------------------------------------------------------  // acclient.c:884064
void __cdecl _E133_77()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C210) --------------------------------------------------------  // acclient.c:884077
void __cdecl _E136_61()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C240) --------------------------------------------------------  // acclient.c:884090
void __cdecl _E139_62()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_1;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
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

//----- (0075C280) --------------------------------------------------------  // acclient.c:884115
void __cdecl _E146_20()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C2B0) --------------------------------------------------------  // acclient.c:884128
void __cdecl _E149_20()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C2E0) --------------------------------------------------------  // acclient.c:884141
void __cdecl _E152_19()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C310) --------------------------------------------------------  // acclient.c:884154
void __cdecl _E155_17()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C340) --------------------------------------------------------  // acclient.c:884167
void __cdecl _E158_20()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C370) --------------------------------------------------------  // acclient.c:884180
void __cdecl _E161_17()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C3A0) --------------------------------------------------------  // acclient.c:884193
void __cdecl _E164_20()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C3D0) --------------------------------------------------------  // acclient.c:884206
void __cdecl _E167_16()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C400) --------------------------------------------------------  // acclient.c:884219
void __cdecl _E170_15()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C430) --------------------------------------------------------  // acclient.c:884232
void __cdecl _E173_14()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C460) --------------------------------------------------------  // acclient.c:884245
void __cdecl _E176_15()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C490) --------------------------------------------------------  // acclient.c:884258
void __cdecl _E179_14()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C4C0) --------------------------------------------------------  // acclient.c:884271
void __cdecl _E182_14()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C4F0) --------------------------------------------------------  // acclient.c:884284
void __cdecl _E185_11()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C520) --------------------------------------------------------  // acclient.c:884297
void __cdecl _E188_12()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C550) --------------------------------------------------------  // acclient.c:884310
void __cdecl _E191_11()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C580) --------------------------------------------------------  // acclient.c:884323
void __cdecl _E194_18()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_14;
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

//----- (0075C5C0) --------------------------------------------------------  // acclient.c:884348
void __cdecl _E197_9()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_14;
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

//----- (0075C600) --------------------------------------------------------  // acclient.c:884373
void __cdecl _E200_14()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_14;
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

//----- (0075C640) --------------------------------------------------------  // acclient.c:884398
void __cdecl _E203_13()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_14;
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

//----- (0075C680) --------------------------------------------------------  // acclient.c:884423
void __cdecl _E206_16()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_14;
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

//----- (0075C6C0) --------------------------------------------------------  // acclient.c:884448
void __cdecl _E209_11()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_26;
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

//----- (0075C700) --------------------------------------------------------  // acclient.c:884473
void __cdecl _E212_14()
{
  char *v0; // esi@1

  v0 = &waveform_None_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C730) --------------------------------------------------------  // acclient.c:884486
void __cdecl _E215_10()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C760) --------------------------------------------------------  // acclient.c:884499
void __cdecl _E218_11()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C790) --------------------------------------------------------  // acclient.c:884512
void __cdecl _E221_11()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C7C0) --------------------------------------------------------  // acclient.c:884525
void __cdecl _E224_11()
{
  char *v0; // esi@1

  v0 = &waveform_Square_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C7F0) --------------------------------------------------------  // acclient.c:884538
void __cdecl _E227_11()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C820) --------------------------------------------------------  // acclient.c:884551
void __cdecl _E230_11()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C850) --------------------------------------------------------  // acclient.c:884564
void __cdecl _E233_10()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075C880) --------------------------------------------------------  // acclient.c:884577
void __cdecl _E236_10()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

