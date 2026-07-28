/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Ambient
   Object     : PORTAL\sound\Ambient.obj
   Functions  : 64
   Addresses  : 00550CD0 - 007722C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00550CD0) --------------------------------------------------------  // acclient.c:383788
void __thiscall IntermitSound::ResetCount(IntermitSound *this)
{
  this->desc->play_count = 0;
  LODWORD(this->sound_count) = 0;
  this->num_dir = 0;
  LODWORD(this->play_chance) = 0;
}

//----- (00550CF0) --------------------------------------------------------  // acclient.c:383797
void __thiscall IntermitSound::AddDir(IntermitSound *this, LandDefs::Direction dir, float min, float max)
{
  unsigned int v4; // esi@1
  unsigned int v5; // edx@1
  char *v6; // eax@2

  v4 = this->num_dir;
  v5 = 0;
  if ( v4 )
  {
    v6 = (char *)this->sound_dir;
    do
    {
      if ( dir == *(_DWORD *)v6 )
        break;
      ++v5;
      v6 += 4;
    }
    while ( v5 < this->num_dir );
  }
  if ( v5 == v4 )
  {
    this->sound_dir[v5] = dir;
    this->max_dist[v5] = max;
    this->min_dist[v5] = min;
    ++this->num_dir;
  }
  else
  {
    if ( min < (double)this->min_dist[v5] )
      this->min_dist[v5] = min;
    if ( max > (double)this->max_dist[v5] )
      this->max_dist[v5] = max;
  }
}

//----- (00550D70) --------------------------------------------------------  // acclient.c:383834
void __thiscall ConstantSound::ResetCount(ConstantSound *this)
{
  this->desc->play_count = 0;
  LODWORD(this->sound_count) = 0;
}

//----- (00550D80) --------------------------------------------------------  // acclient.c:383841
double __thiscall ConstantSound::GetVolume(ConstantSound *this)
{
  return this->current_volume;
}

//----- (00550D90) --------------------------------------------------------  // acclient.c:383847
void __stdcall Ambient::PlaySoundA(SoundType stype, CSoundTable *stable, Position *pos, float volume)
{
  if ( pos )
    SoundManager::PlayAmbientSound(stype, stable, pos, volume);
  else
    SoundManager::PlayAmbientSoundFromCenter(stype, stable, volume);
}

//----- (00550DD0) --------------------------------------------------------  // acclient.c:383856
double __stdcall Ambient::CalcWeight(AC1Legacy::Vector3 *view_diff)
{
  double result; // st7@2
  float view_diffa; // [sp+4h] [bp+4h]@1

  view_diffa = view_diff->x * view_diff->x + view_diff->y * view_diff->y + view_diff->z * view_diff->z;
  if ( view_diffa <= (double)Ambient::ambient_sound_max_dist_sq )
  {
    if ( view_diffa >= (double)Ambient::ambient_sound_min_dist_sq )
      result = Ambient::ambient_sound_min_dist_sq / view_diffa;
    else
      result = 1.0;
  }
  else
  {
    result = 0.0;
  }
  return result;
}
// 81F14C: using guessed type float Ambient::ambient_sound_min_dist_sq;
// 81F154: using guessed type float Ambient::ambient_sound_max_dist_sq;

//----- (00550E40) --------------------------------------------------------  // acclient.c:383879
signed int __stdcall Ambient::CalcDir(AC1Legacy::Vector3 *view_diff)
{
  long double v2; // st7@1
  signed int result; // eax@2
  float v4; // [sp+0h] [bp-8h]@1
  float ay; // [sp+4h] [bp-4h]@1
  float view_diffa; // [sp+Ch] [bp+4h]@1

  v2 = view_diff->y;
  view_diffa = view_diff->x;
  v4 = fabs(view_diffa);
  ay = fabs(v2);
  if ( Ambient::ambient_sound_min_dist_sq * 0.5 <= v2 * v2 + view_diffa * view_diffa )
  {
    if ( v4 < 0.00019999999 || ay / v4 > 2.0 )
    {
      result = 1;
      if ( v2 < 0.0 )
        result = 2;
    }
    else if ( ay < 0.00019999999 || v4 / ay > 2.0 )
    {
      if ( view_diffa < 0.0 )
        result = 4;
      else
        result = 3;
    }
    else if ( view_diffa < 0.0 )
    {
      if ( v2 < 0.0 )
        result = 6;
      else
        result = 5;
    }
    else if ( v2 < 0.0 )
    {
      result = 8;
    }
    else
    {
      result = 7;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 81F14C: using guessed type float Ambient::ambient_sound_min_dist_sq;

//----- (00550F80) --------------------------------------------------------  // acclient.c:383931
BOOL __thiscall IntermitSound::CanHear(IntermitSound *this)
{
  return this->play_chance > 0.0;
}

//----- (00550FA0) --------------------------------------------------------  // acclient.c:383937
BOOL __thiscall IntermitSound::PlayNow(IntermitSound *this)
{
  float v1; // ST08_4@1

  v1 = this->play_chance;
  return Random::RollDice(0.0, 1.0) <= v1;
}

//----- (00550FD0) --------------------------------------------------------  // acclient.c:383946
int __usercall ConstantSound::CanHear@<eax>(ConstantSound *this@<ecx>, double a2@<st0>)
{
  ConstantSound *v2; // esi@1
  int result; // eax@2

  v2 = this;
  ((void (*)(void))this->vfptr->GetVolume)();
  if ( a2 >= Ambient::ambient_sound_min_vol )
    result = v2->desc->sound_table != 0;
  else
    result = 0;
  return result;
}
// 81F158: using guessed type float Ambient::ambient_sound_min_vol;

//----- (00551000) --------------------------------------------------------  // acclient.c:383962
void __thiscall ConstantSound::AddTo(ConstantSound *this, float weight, AC1Legacy::Vector3 *diff, LandDefs::Direction dir)
{
  this->sound_count = weight + this->sound_count;
}

//----- (00551010) --------------------------------------------------------  // acclient.c:383968
void __thiscall DArray<AmbientSound *>::grow_check(DArray<AmbientSound *> *this, unsigned int size)
{
  DArray<AmbientSound *> *v2; // esi@1
  unsigned int v3; // edi@2
  void *v4; // ebx@2
  unsigned int v5; // eax@2

  v2 = this;
  if ( size >= this->sizeOf )
  {
    v3 = this->blocksize + size;
    v4 = operator new[](4 * v3);
    v5 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v4 + v5) = v2->data[v5];
        ++v5;
      }
      while ( v5 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (AmbientSound **)v4;
    v2->sizeOf = v3;
  }
}

//----- (00551070) --------------------------------------------------------  // acclient.c:383997
double __thiscall IntermitSound::GetVolume(IntermitSound *this)
{
  return this->desc->ambient_sounds.m_data[this->ambient_sound_id]->volume;
}

//----- (00551080) --------------------------------------------------------  // acclient.c:384003
double __thiscall IntermitSound::GetPlayInterval(IntermitSound *this)
{
  AmbientSoundDesc *v1; // eax@1

  v1 = this->desc->ambient_sounds.m_data[this->ambient_sound_id];
  return Random::RollDice(v1->min_rate, v1->max_rate);
}

//----- (005510A0) --------------------------------------------------------  // acclient.c:384012
double __thiscall ConstantSound::GetPlayInterval(ConstantSound *this)
{
  return this->desc->ambient_sounds.m_data[this->ambient_sound_id]->min_rate;
}

//----- (005510B0) --------------------------------------------------------  // acclient.c:384018
AmbientSound *__thiscall Ambient::GetSound(Ambient *this, AmbientSTBDesc *sound_desc, unsigned int sound_id)
{
  AmbientSTBDesc *v3; // ebx@1
  Ambient *v4; // esi@1
  unsigned int v5; // edx@1
  unsigned int v6; // edi@1
  AmbientSound **v7; // ecx@2
  int v8; // edi@7
  void *v9; // eax@8
  unsigned int v11; // ecx@14
  int is_constant; // [sp+10h] [bp-4h]@1
  AmbientSTBDesc *sound_desca; // [sp+18h] [bp+4h]@1

  v3 = sound_desc;
  v4 = this;
  is_constant = sound_desc->ambient_sounds.m_data[sound_id]->is_continuous;
  v5 = this->num_sounds;
  v6 = 0;
  sound_desca = 0;
  if ( !v5 )
  {
LABEL_7:
    v8 = (int)&v4->sounds;
    DArray<AmbientSound *>::grow_check(&v4->sounds, v5);
    if ( is_constant )
    {
      v9 = operator new(0x1Cu);
      if ( v9 )
      {
        *((_DWORD *)v9 + 1) = 0;
        *((_DWORD *)v9 + 2) = 0;
        *(_DWORD *)v9 = &ConstantSound::vftable;
        *((_DWORD *)v9 + 6) = 0;
        *((_DWORD *)v9 + 3) = v3;
        *((_DWORD *)v9 + 4) = sound_id;
LABEL_14:
        v11 = v4->num_sounds;
        v4->num_sounds = v11 + 1;
        *(_DWORD *)(*(_DWORD *)v8 + 4 * v11) = v9;
        return *(AmbientSound **)(*(_DWORD *)v8 + 4 * (_DWORD)sound_desca);
      }
    }
    else
    {
      v9 = operator new(0x80u);
      if ( v9 )
      {
        *((_DWORD *)v9 + 1) = 0;
        *((_DWORD *)v9 + 2) = 0;
        *(_DWORD *)v9 = &IntermitSound::vftable;
        *((_DWORD *)v9 + 6) = 0;
        *((_DWORD *)v9 + 23) = 0;
        *((_DWORD *)v9 + 3) = v3;
        *((_DWORD *)v9 + 4) = sound_id;
        goto LABEL_14;
      }
    }
    v9 = 0;
    goto LABEL_14;
  }
  v7 = this->sounds.data;
  while ( (*v7)->desc != v3 || (*v7)->ambient_sound_id != sound_id )
  {
    ++v6;
    ++v7;
    if ( v6 >= v4->num_sounds )
    {
      sound_desca = (AmbientSTBDesc *)v6;
      goto LABEL_7;
    }
  }
  return v4->sounds.data[v6];
}
// 7CB0C4: using guessed type void (__thiscall *IntermitSound::vftable)(IntermitSound *__hidden this);
// 7CB0E4: using guessed type void (__thiscall *ConstantSound::vftable)(ConstantSound *__hidden this);

//----- (005511A0) --------------------------------------------------------  // acclient.c:384095
void __thiscall AmbientSTBDesc::AmbientSTBDesc(AmbientSTBDesc *this)
{
  this->stb_id.id = 0;
  this->stb_not_found = 0;
  this->ambient_sounds.m_data = 0;
  this->ambient_sounds.m_size = 0;
  this->ambient_sounds.m_num = 0;
  this->sound_table = 0;
  this->play_count = 0;
}

//----- (005511C0) --------------------------------------------------------  // acclient.c:384107
void __thiscall AmbientSTBDesc::~AmbientSTBDesc(AmbientSTBDesc *this)
{
  AmbientSTBDesc *v1; // esi@1
  unsigned int v2; // edi@1
  void *v3; // ST04_4@3

  v1 = this;
  v2 = 0;
  if ( this->ambient_sounds.m_num )
  {
    do
      operator delete(v1->ambient_sounds.m_data[v2++]);
    while ( v2 < v1->ambient_sounds.m_num );
  }
  v3 = v1->ambient_sounds.m_data;
  v1->ambient_sounds.m_num = 0;
  v1->ambient_sounds.m_size = 0;
  operator delete[](v3);
  v1->ambient_sounds.m_data = 0;
  operator delete[](v1->ambient_sounds.m_data);
}

//----- (00551220) --------------------------------------------------------  // acclient.c:384130
unsigned int __thiscall AmbientSTBDesc::Pack(AmbientSTBDesc *this, void **addr, unsigned int *size)
{
  unsigned int v3; // esi@2
  unsigned int v4; // esi@4
  unsigned int v5; // edi@6
  unsigned int v6; // edi@7
  char *v7; // edi@9

  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = this->stb_id.id;
    *addr = (char *)*addr + 4;
    v3 = *size - 4;
    *size = v3;
    if ( v3 >= 4 )
    {
      *(_DWORD *)*addr = this->ambient_sounds.m_num;
      *addr = (char *)*addr + 4;
      *size -= 4;
    }
  }
  v4 = 0;
  if ( this->ambient_sounds.m_num )
  {
    do
    {
      if ( *size >= 4 )
      {
        *(_DWORD *)*addr = this->ambient_sounds.m_data[v4]->stype;
        *addr = (char *)*addr + 4;
        v5 = *size - 4;
        *size = v5;
        if ( v5 >= 4 )
        {
          *(float *)*addr = this->ambient_sounds.m_data[v4]->volume;
          *addr = (char *)*addr + 4;
          v6 = *size - 4;
          *size = v6;
          if ( v6 >= 4 )
          {
            *(float *)*addr = this->ambient_sounds.m_data[v4]->base_chance;
            *addr = (char *)*addr + 4;
            *size -= 4;
          }
        }
      }
      *(float *)*addr = this->ambient_sounds.m_data[v4]->min_rate;
      v7 = (char *)*addr + 4;
      *addr = v7;
      if ( *size >= 4 )
      {
        *(float *)v7 = this->ambient_sounds.m_data[v4]->max_rate;
        *addr = (char *)*addr + 4;
        *size -= 4;
      }
      ++v4;
    }
    while ( v4 < this->ambient_sounds.m_num );
  }
  return *size;
}

//----- (00551300) --------------------------------------------------------  // acclient.c:384193
unsigned int __thiscall AmbientSTBDesc::pack_size(AmbientSTBDesc *this)
{
  return 20 * this->ambient_sounds.m_num + 8;
}

//----- (00551310) --------------------------------------------------------  // acclient.c:384199
void __thiscall IntermitSound::UpdateSound(IntermitSound *this, float total_weight)
{
  if ( this->sound_count > 0.0 )
  {
    ++this->desc->play_count;
    this->play_chance = this->desc->ambient_sounds.m_data[this->ambient_sound_id]->base_chance
                      / total_weight
                      * this->sound_count;
  }
}

//----- (00551350) --------------------------------------------------------  // acclient.c:384211
int __thiscall IntermitSound::GetSoundPos(IntermitSound *this, Position *base_pos)
{
  IntermitSound *v2; // esi@1
  float upper_bound; // ST18_4@1
  double v4; // st7@1
  unsigned __int64 v5; // rax@1
  int v6; // edi@1
  LandDefs::Direction v7; // ebx@1
  float heading; // ST2C_4@1
  float v9; // ST2C_4@1
  float min; // ST28_4@1
  float max; // ST30_4@1
  double v12; // st7@1
  char *v13; // eax@1
  float sound_loc_8; // ST3C_4@1
  double v15; // st7@1
  float sound_loc; // ST34_4@1
  float sound_loc_4; // ST38_4@1
  double v18; // st7@1
  float v19; // ST34_4@1
  float v20; // ST38_4@1

  v2 = this;
  upper_bound = (double)this->num_dir;
  v4 = Random::RollDice(0.0, upper_bound);
  v5 = (unsigned __int64)_floor(v4);
  v6 = v5;
  v7 = v2->sound_dir[v5];
  heading = Random::RollDice(0.0, ::upper_bound);
  v9 = LandDefs::heading(v7) + heading - ::upper_bound * 0.5;
  min = v2->min_dist[v6];
  max = v2->max_dist[v6];
  v12 = Random::RollDice(0.0, 1.0);
  v13 = (char *)&base_pos->frame.m_fOrigin;
  sound_loc_8 = base_pos->frame.m_fOrigin.z;
  v15 = v12 * ((max - min) * v12) + min;
  sound_loc = sin(v9) * v15;
  sound_loc_4 = v15 * cos(v9);
  v18 = sound_loc_4 + base_pos->frame.m_fOrigin.y;
  v19 = sound_loc + base_pos->frame.m_fOrigin.x;
  *(float *)v13 = v19;
  v20 = v18;
  *((float *)v13 + 1) = v20;
  *((float *)v13 + 2) = sound_loc_8;
  return 1;
}

//----- (00551450) --------------------------------------------------------  // acclient.c:384259
void __thiscall IntermitSound::AddTo(IntermitSound *this, float weight, AC1Legacy::Vector3 *diff, LandDefs::Direction dir)
{
  IntermitSound *v4; // esi@1
  long double v5; // st4@1
  float max; // ST10_4@3
  float min; // ST0C_4@3
  float offset; // [sp+Ch] [bp-4h]@1
  float diffa; // [sp+18h] [bp+8h]@2

  v4 = this;
  offset = Ambient::ambient_sound_min_dist * 0.5;
  v5 = sqrt(diff->x * diff->x + diff->y * diff->y + diff->z * diff->z);
  this->sound_count = weight + this->sound_count;
  if ( dir )
  {
    max = offset + v5;
    min = v5 - offset;
    IntermitSound::AddDir(this, dir, min, max);
  }
  else
  {
    diffa = 5.0 - 1.0;
    IntermitSound::AddDir(this, NORTH_OF_VIEWER, diffa, offset);
    IntermitSound::AddDir(v4, SOUTH_OF_VIEWER, diffa, offset);
    IntermitSound::AddDir(v4, EAST_OF_VIEWER, diffa, offset);
    IntermitSound::AddDir(v4, WEST_OF_VIEWER, diffa, offset);
    IntermitSound::AddDir(v4, NORTHWEST_OF_VIEWER, diffa, offset);
    IntermitSound::AddDir(v4, NORTHEAST_OF_VIEWER, diffa, offset);
    IntermitSound::AddDir(v4, SOUTHWEST_OF_VIEWER, diffa, offset);
    IntermitSound::AddDir(v4, SOUTHEAST_OF_VIEWER, diffa, offset);
  }
}
// 81F148: using guessed type float Ambient::ambient_sound_min_dist;

//----- (00551540) --------------------------------------------------------  // acclient.c:384294
void __thiscall ConstantSound::UpdateSound(ConstantSound *this, float total_weight)
{
  if ( this->sound_count == 0.0 )
  {
    LODWORD(this->current_volume) = 0;
  }
  else
  {
    ++this->desc->play_count;
    this->current_volume = this->desc->ambient_sounds.m_data[this->ambient_sound_id]->volume
                         / total_weight
                         * this->sound_count;
  }
}

//----- (00551580) --------------------------------------------------------  // acclient.c:384310
void __thiscall Ambient::Destroy(Ambient *this)
{
  Ambient *v1; // esi@1
  unsigned int v2; // edi@1
  AmbientSound *v3; // eax@2
  void *v4; // ST00_4@3

  v1 = this;
  v2 = 0;
  if ( this->num_sounds )
  {
    do
    {
      v3 = v1->sounds.data[v2];
      if ( v3 )
      {
        v4 = v1->sounds.data[v2];
        v3->vfptr = (AmbientSoundVtbl *)&AmbientSound::vftable;
        operator delete(v4);
      }
      v1->sounds.data[v2++] = 0;
    }
    while ( v2 < v1->num_sounds );
  }
  v1->num_sounds = 0;
  LODWORD(v1->total_sound_count) = 0;
}
// 7CB0A4: using guessed type void (__thiscall *AmbientSound::vftable)(gmNoticeHandler *this);

//----- (005515D0) --------------------------------------------------------  // acclient.c:384340
void __thiscall Ambient::InitSounds(Ambient *this, Position *play_pos)
{
  Ambient *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // edi@1

  v2 = this;
  this->player_pos.objcell_id = play_pos->objcell_id;
  Frame::operator=((int)&this->player_pos.frame, (int)&play_pos->frame);
  v3 = v2->num_sounds;
  v4 = 0;
  LODWORD(v2->total_sound_count) = 0;
  if ( v3 )
  {
    do
      ((void (*)(void))v2->sounds.data[v4++]->vfptr->ResetCount)();
    while ( v4 < v2->num_sounds );
  }
}

//----- (00551610) --------------------------------------------------------  // acclient.c:384361
void __thiscall Ambient::AddSound(Ambient *this, AmbientSTBDesc *in_desc, Position *pos)
{
  Ambient *v3; // ebx@1
  unsigned int v4; // esi@4
  AmbientSound *v5; // eax@5
  signed int view_dir; // [sp+4h] [bp-10h]@3
  AC1Legacy::Vector3 view_diff; // [sp+8h] [bp-Ch]@2
  float posa; // [sp+1Ch] [bp+8h]@3

  v3 = this;
  if ( SoundManager::ambient_sounds_enabled )
  {
    Position::get_offset(&this->player_pos, &view_diff, pos);
    if ( view_diff.z * view_diff.z + view_diff.y * view_diff.y + view_diff.x * view_diff.x <= Ambient::ambient_sound_max_dist_sq )
    {
      posa = Ambient::CalcWeight(&view_diff);
      view_dir = Ambient::CalcDir(&view_diff);
      if ( posa != 0.0 )
      {
        v4 = 0;
        v3->total_sound_count = posa + v3->total_sound_count;
        if ( in_desc->ambient_sounds.m_num )
        {
          do
          {
            v5 = Ambient::GetSound(v3, in_desc, v4);
            v5->vfptr->AddTo(v5, COERCE_FLOAT(LODWORD(posa)), &view_diff, (LandDefs::Direction)view_dir);
            ++v4;
          }
          while ( v4 < in_desc->ambient_sounds.m_num );
        }
      }
    }
  }
}
// 81F06C: using guessed type bool SoundManager::ambient_sounds_enabled;
// 81F154: using guessed type float Ambient::ambient_sound_max_dist_sq;

//----- (005516E0) --------------------------------------------------------  // acclient.c:384400
void __thiscall Ambient::Ambient(Ambient *this)
{
  Ambient *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->player_pos.frame;
  v1->player_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->player_pos.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  LODWORD(v1->total_sound_count) = 0;
  v1->num_sounds = 0;
  v1->sounds.data = (AmbientSound **)operator new[](0x20u);
  v1->sounds.sizeOf = 8;
  v1->sounds.next_available = 0;
  v1->sounds.blocksize = 8;
  v1->sound_queue.vfptr = (AC1Legacy::PQueueArray<double>Vtbl *)AC1Legacy::PQueueArray<double>::vftable;
  v1->sound_queue.curNumNodes = 0;
  v1->sound_queue.A = (AC1Legacy::PQueueArray<double>::PQueueNode *)operator new[](0x100u);
  v1->sound_queue.minAllocatedNodes = 16;
  v1->sound_queue.allocatedNodes = 16;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7C66A4: using guessed type int (__thiscall *AC1Legacy::PQueueArray<double>::vftable[5])(void *, char);

//----- (00551760) --------------------------------------------------------  // acclient.c:384433
void __thiscall Ambient::~Ambient(Ambient *this)
{
  Ambient *v1; // esi@1
  void *v2; // ST04_4@1

  v1 = this;
  Ambient::Destroy(this);
  v2 = v1->sound_queue.A;
  v1->sound_queue.vfptr = (AC1Legacy::PQueueArray<double>Vtbl *)AC1Legacy::PQueueArray<double>::vftable;
  operator delete[](v2);
  operator delete[](v1->sounds.data);
  v1->sounds.data = 0;
  v1->player_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C66A4: using guessed type int (__thiscall *AC1Legacy::PQueueArray<double>::vftable[5])(void *, char);

//----- (005517A0) --------------------------------------------------------  // acclient.c:384451
void __userpurge Ambient::Play(Ambient *this@<ecx>, double a2@<st0>, AmbientSound *asound)
{
  Ambient *v3; // ebp@1
  AmbientSound *v4; // esi@1
  bool v5; // zf@3
  AmbientSTBDesc *v6; // eax@3
  CSoundTable *v7; // edi@3
  AmbientSoundVtbl *v8; // edx@3
  SoundType v9; // ebx@3
  float volume; // ST0C_4@4
  Position pos; // [sp+18h] [bp-48h]@1
  float asounda; // [sp+64h] [bp+4h]@5

  v3 = this;
  pos.vfptr = (PackObjVtbl *)&Position::vftable;
  pos.objcell_id = SoundManager::player_position_.objcell_id;
  Frame::operator=((int)&pos.frame, (int)&SoundManager::player_position_.frame);
  v4 = asound;
  if ( asound->vfptr->CanHear(asound) )
  {
    if ( asound->vfptr->PlayNow(asound) )
    {
      v5 = asound->vfptr->GetSoundPos(asound, &pos) == 0;
      v6 = asound->desc;
      v7 = v6->sound_table;
      v8 = asound->vfptr;
      v9 = v6->ambient_sounds.m_data[asound->ambient_sound_id]->stype;
      if ( v5 )
      {
        v8->GetVolume(asound);
        asounda = a2;
        SoundManager::PlayAmbientSoundFromCenter(v9, v7, asounda);
      }
      else
      {
        v8->GetVolume(asound);
        volume = a2;
        Ambient::PlaySoundA(v9, v7, &pos, volume);
      }
    }
    v4->vfptr->GetPlayInterval(v4);
    AC1Legacy::PQueueArray<double>::Insert(
      (PQueueArray<double,void *> *)&v3->sound_queue,
      a2 + COERCE_DOUBLE(Timer::cur_time.Cmd),
      v4);
    v4->on_queue = 1;
  }
  else
  {
    asound->on_queue = 0;
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00551880) --------------------------------------------------------  // acclient.c:384506
void __thiscall Ambient::UseTime(Ambient *this)
{
  Ambient *v1; // edi@1
  AC1Legacy::PQueueArray<double>::PQueueNode *v2; // eax@3
  double v3; // st7@4
  void *data; // [sp+Ch] [bp-Ch]@1
  long double key; // [sp+10h] [bp-8h]@5

  v1 = this;
  data = 0;
  if ( SoundManager::ambient_sounds_enabled )
  {
    while ( v1->sound_queue.curNumNodes > 0 )
    {
      v2 = v1->sound_queue.A;
      if ( !v2 )
        break;
      v3 = v2->key;
      if ( v3 >= COERCE_DOUBLE(Timer::cur_time.Cmd) )
        break;
      AC1Legacy::PQueueArray<double>::RemoveMin(&v1->sound_queue, &key, &data);
      Ambient::Play(v1, v3, (AmbientSound *)data);
    }
  }
}
// 81F06C: using guessed type bool SoundManager::ambient_sounds_enabled;

//----- (005518F0) --------------------------------------------------------  // acclient.c:384534
int __thiscall AmbientSTBDesc::UnPack(AmbientSTBDesc *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  void **v4; // edi@1
  unsigned int v5; // edx@2
  void **v6; // ebx@3
  char *v7; // ebp@5
  void *v8; // ebx@7
  int v9; // ecx@8
  int v10; // eax@10
  int v11; // eax@13
  unsigned int v12; // eax@15
  unsigned int v13; // eax@17
  bool v14; // cf@20
  int stype; // [sp+10h] [bp-4h]@0
  int num_ambient_sounds; // [sp+1Ch] [bp+8h]@6

  v3 = size;
  v4 = addr;
  if ( *size < 4 || (v5 = *(_DWORD *)*addr, *addr = (char *)*addr + 4, *size -= 4, this->stb_id.id = v5, *size < 4) )
  {
    v6 = addr;
  }
  else
  {
    v6 = *(void ***)*addr;
    *addr = (char *)*addr + 4;
    addr = v6;
    *size -= 4;
  }
  v7 = (char *)&this->ambient_sounds;
  if ( AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(
         (AC1Legacy::SmartArray<Season *> *)&this->ambient_sounds,
         (unsigned int)v6) )
  {
    num_ambient_sounds = 0;
    if ( !v6 )
      return 1;
    while ( 1 )
    {
      v8 = operator new(0x18u);
      if ( *v3 >= 4 )
      {
        v9 = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        stype = v9;
        *v3 -= 4;
      }
      *(_DWORD *)v8 = stype;
      if ( *v3 >= 4 )
      {
        *((_DWORD *)v8 + 2) = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        v10 = *v3 - 4;
        *v3 = v10;
        if ( (unsigned int)v10 >= 4 )
        {
          *((_DWORD *)v8 + 3) = *(_DWORD *)*v4;
          *v4 = (char *)*v4 + 4;
          *v3 -= 4;
        }
      }
      *((_DWORD *)v8 + 1) = *((float *)v8 + 3) == 0.0;
      if ( *v3 >= 4 )
      {
        *((_DWORD *)v8 + 4) = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        v11 = *v3 - 4;
        *v3 = v11;
        if ( (unsigned int)v11 >= 4 )
        {
          *((_DWORD *)v8 + 5) = *(_DWORD *)*v4;
          *v4 = (char *)*v4 + 4;
          *v3 -= 4;
        }
      }
      v12 = *((_DWORD *)v7 + 1);
      if ( *((_DWORD *)v7 + 2) >= v12 )
      {
        v13 = v12 ? 2 * v12 : 8;
        if ( !AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v7, v13) )
          break;
      }
      *(_DWORD *)(*(_DWORD *)v7 + 4 * *((_DWORD *)v7 + 2)) = v8;
      v14 = num_ambient_sounds + 1 < (unsigned int)addr;
      ++*((_DWORD *)v7 + 2);
      ++num_ambient_sounds;
      if ( !v14 )
        return 1;
    }
  }
  return 0;
}

//----- (00551A50) --------------------------------------------------------  // acclient.c:384629
void __usercall Ambient::UpdatePlayQueue(Ambient *this@<ecx>, double a2@<st0>)
{
  Ambient *v2; // edi@1
  unsigned int v3; // ebx@2
  AmbientSound *v4; // esi@3

  v2 = this;
  if ( SoundManager::ambient_sounds_enabled )
  {
    v3 = 0;
    if ( this->num_sounds )
    {
      do
      {
        v4 = v2->sounds.data[v3];
        ((void (__thiscall *)(AmbientSound *, _DWORD))v4->vfptr->UpdateSound)(
          v2->sounds.data[v3],
          LODWORD(v2->total_sound_count));
        if ( !v4->on_queue )
          Ambient::Play(v2, a2, v4);
        ++v3;
      }
      while ( v3 < v2->num_sounds );
    }
  }
}
// 81F06C: using guessed type bool SoundManager::ambient_sounds_enabled;

//----- (0069CE00) --------------------------------------------------------  // acclient.c:693126
double AmbientSound::GetVolume()
{
  return 0.0;
}

//----- (00706790) --------------------------------------------------------  // acclient.c:793757
void sub_706790()
{
  flt_86F62C = 1000.0 + 1.0;
}

//----- (007067B0) --------------------------------------------------------  // acclient.c:793763
void sub_7067B0()
{
  flt_86F630 = 24.0 * 8.0;
}

//----- (007067D0) --------------------------------------------------------  // acclient.c:793769
void sub_7067D0()
{
  flt_86F634 = 24.0 * 0.5;
}

//----- (007067F0) --------------------------------------------------------  // acclient.c:793775
int sub_7067F0()
{
  return atexit(nullsub_1246);
}

//----- (00706800) --------------------------------------------------------  // acclient.c:793781
int sub_706800()
{
  return atexit(nullsub_1247);
}

//----- (00706810) --------------------------------------------------------  // acclient.c:793787
int sub_706810()
{
  return atexit(nullsub_1248);
}

//----- (00706820) --------------------------------------------------------  // acclient.c:793793
int sub_706820()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_17, "Sound.SoundDisabled");
  return atexit(_E107_90);
}

//----- (00706840) --------------------------------------------------------  // acclient.c:793800
int _E109_70()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_17, "Sound.SoundVolume");
  return atexit(sub_772170);
}

//----- (00706860) --------------------------------------------------------  // acclient.c:793807
int _E112_95()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_17, "Sound.AmbientSoundDisabled");
  return atexit(_E113_68);
}

//----- (00706880) --------------------------------------------------------  // acclient.c:793814
int _E115_69()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_17, "Sound.AmbientSoundVolume");
  return atexit(_E116_60);
}

//----- (007068A0) --------------------------------------------------------  // acclient.c:793821
int _E118_70()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_17, "Sound.InterfaceSoundDisabled");
  return atexit(_E119_86);
}

//----- (007068C0) --------------------------------------------------------  // acclient.c:793828
int _E121_60()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_17, "Sound.InterfaceSoundVolume");
  return atexit(_E122_87);
}

//----- (007068E0) --------------------------------------------------------  // acclient.c:793835
int _E124_61()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_17, "Sound.SoundFeatures");
  return atexit(_E125_59);
}

//----- (00706900) --------------------------------------------------------  // acclient.c:793842
int _E127_50()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_17, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E128_58);
}

//----- (00706920) --------------------------------------------------------  // acclient.c:793849
int _E130_48()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_17, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_86F660, "Mono");
  return atexit(_E131_50);
}

//----- (00706950) --------------------------------------------------------  // acclient.c:793857
void _E133_38()
{
  VOL_MIN_DIST_SQ_14 = 5.0 * 5.0;
}

//----- (00706970) --------------------------------------------------------  // acclient.c:793863
void _E135_46()
{
  INV_LOG_OF_2_14 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (00706990) --------------------------------------------------------  // acclient.c:793869
void _E137_8()
{
  flt_86F670 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007069B0) --------------------------------------------------------  // acclient.c:793875
void _E139_27()
{
  dbl_86F678 = 1.0 / 30.0;
}

//----- (007069D0) --------------------------------------------------------  // acclient.c:793881
void _E141_38()
{
  dbl_86F680 = 1.0 / 5.0;
}

//----- (007069F0) --------------------------------------------------------  // acclient.c:793887
int sub_7069F0()
{
  return atexit(nullsub_1245);
}

//----- (00772140) --------------------------------------------------------  // acclient.c:905980
void __cdecl _E107_90()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772170) --------------------------------------------------------  // acclient.c:905993
void __cdecl sub_772170()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007721A0) --------------------------------------------------------  // acclient.c:906006
void __cdecl _E113_68()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007721D0) --------------------------------------------------------  // acclient.c:906019
void __cdecl _E116_60()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772200) --------------------------------------------------------  // acclient.c:906032
void __cdecl _E119_86()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772230) --------------------------------------------------------  // acclient.c:906045
void __cdecl _E122_87()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772260) --------------------------------------------------------  // acclient.c:906058
void __cdecl _E125_59()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772290) --------------------------------------------------------  // acclient.c:906071
void __cdecl _E128_58()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007722C0) --------------------------------------------------------  // acclient.c:906084
void __cdecl _E131_50()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_14;
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

