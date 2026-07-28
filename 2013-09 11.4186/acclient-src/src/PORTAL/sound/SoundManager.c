/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SoundManager
   Object     : PORTAL\sound\SoundManager.obj
   Functions  : 89
   Addresses  : 00507EE0 - 007720C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00507EE0) --------------------------------------------------------  // acclient.c:309494
SoundBufRef *__thiscall IntrusiveHashTable<unsigned long,CLostCell *,0>::find(IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *this, IDClass<_tagDataID,32,0> *key)
{
  SoundBufRef *result; // eax@1

  for ( result = this->m_buckets[key->id % this->m_numBuckets]; result; result = result->m_hashNext )
  {
    if ( result->m_hashKey.id == key->id )
      break;
  }
  return result;
}

//----- (0054FEC0) --------------------------------------------------------  // acclient.c:383003
void __cdecl SoundManager::PlaySoundInternal(SoundBufRef *current_sound, int pan, int attenuation)
{
  signed int v3; // ebx@3
  int v4; // esi@4
  struct SoundPlayingData *v5; // edi@4
  signed int v6; // ecx@8
  SoundBuf *v7; // eax@16
  struct SoundPlayingData *v8; // eax@17
  unsigned int v9; // edx@19
  long double now; // [sp+4h] [bp-8h]@3

  if ( !SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp )
  {
    now = *(double *)&Timer::cur_time;
    v3 = 0;
    while ( 1 )
    {
      v4 = (SoundManager::curr_playing_buffer_ + v3) % 16;
      v5 = (&SoundManager::playing_sounds_)[v4];
      if ( !v5 )
        break;
      if ( !LODWORD(v5->priority)
        || !(SoundBuf::GetStatus((SoundBuf *)&(&SoundManager::playing_sounds_)[v4]->buffer) & 1) )
        goto LABEL_14;
      ++v3;
      if ( v3 >= 16 )
      {
        v6 = 0;
        while ( 1 )
        {
          v4 = (SoundManager::curr_playing_buffer_ + v6) % 16;
          v5 = (&SoundManager::playing_sounds_)[v4];
          if ( flt_86F514[4 * v4] < (double)current_sound->data_.priority_ )
            break;
          ++v6;
          if ( v6 >= 16 )
            return;
        }
        if ( v5 )
        {
          SoundBuf::Stop((SoundBuf *)&(&SoundManager::playing_sounds_)[v4]->buffer);
LABEL_14:
          if ( v5 )
          {
            SoundBuf::~SoundBuf((SoundBuf *)&v5->buffer);
            operator delete(v5);
          }
          break;
        }
        break;
      }
    }
    v7 = (SoundBuf *)operator new(0x20u);
    if ( v7 )
      SoundBuf::SoundBuf(v7, current_sound->sound_buf_);
    else
      v8 = 0;
    v9 = 4 * v4;
    (&SoundManager::playing_sounds_)[v9 / 4] = v8;
    flt_86F514[v9] = current_sound->data_.priority_;
    dword_86F518[v9] = LODWORD(now);
    dword_86F51C[v9] = HIDWORD(now);
    SoundManager::curr_playing_buffer_ = (v4 + 1) % 16;
    SoundBuf::Play((SoundBuf *)&v8->buffer, pan, attenuation);
  }
}
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;
// 86F3A8: using guessed type int SoundManager::curr_playing_buffer_;
// 86F510: using guessed type struct SoundPlayingData *SoundManager::playing_sounds_;
// 86F514: using guessed type float flt_86F514[];
// 86F518: using guessed type int dword_86F518[];
// 86F51C: using guessed type int dword_86F51C[];

//----- (00550020) --------------------------------------------------------  // acclient.c:383078
int __cdecl SoundManager::GetAttenuation(float distance, float volume, int *attenuation, int is_ambient)
{
  double v4; // st7@2
  long double v5; // st7@7
  int result; // eax@10
  unsigned __int64 v7; // rax@11

  if ( distance >= 5.0 )
    v4 = VOL_MIN_DIST_SQ_13 * volume / (distance * distance);
  else
    v4 = volume;
  if ( v4 > 1.0 )
    v4 = 1.0;
  if ( is_ambient )
    v5 = v4 * SoundManager::ambient_sound_volume;
  else
    v5 = v4 * SoundManager::effect_sound_volume;
  if ( v5 > 0.0 )
  {
    v7 = (unsigned __int64)_ceil(__FYL2X__(v5, 0.69314718055994528623) * INV_LOG_OF_2_13 * 6.0206);
    *attenuation = v7;
    if ( (signed int)v7 >= SoundManager::VOL_MIN )
    {
      result = 1;
    }
    else
    {
      *attenuation = SoundManager::VOL_MIN;
      result = 0;
    }
  }
  else
  {
    *attenuation = SoundManager::VOL_MIN;
    result = 0;
  }
  return result;
}
// 81F060: using guessed type int SoundManager::VOL_MIN;
// 81F070: using guessed type float SoundManager::ambient_sound_volume;

//----- (005500E0) --------------------------------------------------------  // acclient.c:383120
BOOL __cdecl SoundManager::PlayProbability(float probability)
{
  return (double)_rand() * 0.000030518509 < probability;
}

//----- (00550110) --------------------------------------------------------  // acclient.c:383126
void __thiscall SoundBufRef::SoundBufRef(SoundBufRef *this, IDClass<_tagDataID,32,0> gid)
{
  SoundBufRef *v2; // esi@1
  SoundBuf *v3; // eax@1
  SoundBuf *v4; // eax@2

  v2 = this;
  this->m_hashKey.id = gid.id;
  this->m_hashNext = 0;
  SoundData::SoundData(&this->data_);
  v2->links_ = 1;
  v2->buffer_num_ = -1;
  v3 = (SoundBuf *)operator new(0x20u);
  if ( v3 )
  {
    SoundBuf::SoundBuf(v3, gid, 0, 1, 0);
    v2->sound_buf_ = v4;
  }
  else
  {
    v2->sound_buf_ = 0;
  }
}

//----- (00550170) --------------------------------------------------------  // acclient.c:383151
void __cdecl SoundManager::PlaySoundInternal(SoundBufRef *current_sound, Position *pos, float volume, int is_ambient)
{
  int v4; // esi@3
  double v5; // st7@4
  float dist; // [sp+0h] [bp-Ch]@3
  float angle; // [sp+4h] [bp-8h]@3
  float player_heading; // [sp+8h] [bp-4h]@3

  if ( !SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp )
  {
    player_heading = Frame::get_heading(&SoundManager::player_position_.frame);
    dist = Position::distance(pos, &SoundManager::player_position_);
    angle = Position::heading(pos, &SoundManager::player_position_);
    v4 = 0;
    if ( SoundManager::s_SoundFeatures != 1 )
    {
      v5 = fmod(angle - player_heading, 360.0);
      if ( v5 > 180.0 )
        v5 = v5 - 360.0;
      player_heading = COERCE_FLOAT(abs((unsigned __int64)dist));
      if ( (double)SLODWORD(player_heading) >= 5.0 )
        v4 = (unsigned __int64)(sin(v5 * 0.017453292) * -15.0);
    }
    if ( SoundManager::GetAttenuation(dist, volume, (int *)&player_heading, is_ambient) )
      SoundManager::PlaySoundInternal(current_sound, v4, SLODWORD(player_heading));
  }
}
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;
// 86F3A4: using guessed type unsigned __int32 SoundManager::s_SoundFeatures;

//----- (00550270) --------------------------------------------------------  // acclient.c:383183
IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::scalar_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *v2; // esi@1
  SoundBufRef **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CAF60: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::vftable)(void *, char);

//----- (005502B0) --------------------------------------------------------  // acclient.c:383204
void __cdecl SoundManager::ShutDown()
{
  SoundBufRef *v0; // edi@1
  SoundBufRef **v1; // esi@2
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *v2; // ebx@2
  signed int v3; // edi@7
  int v4; // eax@8
  SoundBuf *v5; // esi@8
  IntrusiveHashIterator<IDClass<_tagDataID,32,0>,SoundBufRef *,0> iter; // [sp+8h] [bp-Ch]@1

  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
    &SoundManager::sound_hash_,
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
  v0 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    v1 = iter.m_currBucket;
    v2 = iter.m_currHashTable;
    do
    {
LABEL_3:
      SoundBuf::Stop(v0->sound_buf_);
      v0 = v0->m_hashNext;
    }
    while ( v0 );
    while ( 1 )
    {
      ++v1;
      if ( v1 == &v2->m_buckets[v2->m_numBuckets] )
        break;
      if ( *v1 )
      {
        v0 = *v1;
        if ( *v1 )
          goto LABEL_3;
        break;
      }
    }
  }
  v3 = 0;
  do
  {
    v4 = (v3 + SoundManager::curr_playing_buffer_) % 16;
    v5 = (SoundBuf *)&(&SoundManager::playing_sounds_)[v4]->buffer;
    if ( v5 )
    {
      SoundBuf::Stop((SoundBuf *)&(&SoundManager::playing_sounds_)[v4]->buffer);
      SoundBuf::~SoundBuf(v5);
      operator delete(v5);
    }
    ++v3;
  }
  while ( v3 < 16 );
  midiCleanup();
  SoundCleanup();
  if ( SoundManager::s_bInittedPrefs )
  {
    UserPreferences::UnregisterPreference(&Sound_SoundDisabled_16);
    UserPreferences::UnregisterPreference(&Sound_SoundVolume_16);
    UserPreferences::UnregisterPreference(&Sound_AmbientSoundDisabled_16);
    UserPreferences::UnregisterPreference(&Sound_AmbientSoundVolume_16);
    UserPreferences::UnregisterPreference(&Sound_InterfaceSoundDisabled_16);
    UserPreferences::UnregisterPreference(&Sound_InterfaceSoundVolume_16);
    UserPreferences::UnregisterPreference(&Sound_SoundFeatures_16);
    UserPreferences::UnregisterPreference(&Sound_PlaySoundOnlyWhenActive_16);
  }
}
// 86F3A8: using guessed type int SoundManager::curr_playing_buffer_;
// 86F3AC: using guessed type bool SoundManager::s_bInittedPrefs;
// 86F510: using guessed type struct SoundPlayingData *SoundManager::playing_sounds_;

//----- (005503C0) --------------------------------------------------------  // acclient.c:383276
void __cdecl SoundManager::SetPlayerPosition(Position *pos)
{
  SoundManager::player_position_.objcell_id = pos->objcell_id;
  Frame::operator=((int)&SoundManager::player_position_.frame, (int)&pos->frame);
}

//----- (005503F0) --------------------------------------------------------  // acclient.c:383283
void __thiscall SoundManager::InitPrefs(PSRefBufferCharData<char> *this)
{
  char *v1; // edi@1
  char *v2; // edi@4
  char *v3; // edi@7
  char *v4; // edi@10
  char *v5; // edi@13
  char *v6; // edi@16
  char *v7; // edi@19
  char *v8; // edi@22
  PStringBase<char> _Description; // [sp+1Ch] [bp-4h]@1

  _Description.m_charbuffer = this;
  PStringBase<char>::PStringBase<char>(&_Description, "Sound Volume");
  UserPreferences::RegisterPreference(
    (float *)&_Description,
    &SoundManager::effect_sound_volume,
    &Sound_SoundVolume_16,
    &_Description,
    0,
    0,
    0,
    0);
  v1 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Ambient Sound Volume");
  UserPreferences::RegisterPreference(
    (float *)&_Description,
    &SoundManager::ambient_sound_volume,
    &Sound_AmbientSoundVolume_16,
    &_Description,
    0,
    0,
    0,
    0);
  v2 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Interface Sound Volume");
  UserPreferences::RegisterPreference(
    (float *)&_Description,
    &SoundManager::interface_sound_volume,
    &Sound_InterfaceSoundVolume_16,
    &_Description,
    0,
    0,
    0,
    0);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Sound Features");
  UserPreferences::RegisterPreference(
    (unsigned int *)&_Description,
    &SoundManager::s_SoundFeatures,
    &Sound_SoundFeatures_16,
    &_Description,
    0,
    2u,
    Sound_SoundFeatures_Choices_16,
    0);
  v4 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Sound Disabled");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &SoundManager::effect_sounds_enabled,
    &Sound_SoundDisabled_16,
    &_Description,
    0,
    0,
    0,
    0);
  v5 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Ambient Sound Disabled");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &SoundManager::ambient_sounds_enabled,
    &Sound_AmbientSoundDisabled_16,
    &_Description,
    0,
    0,
    0,
    0);
  v6 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Interface Sound Disabled");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &SoundManager::interface_sounds_enabled,
    &Sound_InterfaceSoundDisabled_16,
    &_Description,
    0,
    0,
    0,
    0);
  v7 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Play Sound Only When Active");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &SoundManager::s_bPlaySoundOnlyWhenActive,
    &Sound_PlaySoundOnlyWhenActive_16,
    &_Description,
    0,
    0,
    0,
    0);
  v8 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  SoundManager::s_bInittedPrefs = 1;
}
// 81F064: using guessed type bool SoundManager::effect_sounds_enabled;
// 81F06C: using guessed type bool SoundManager::ambient_sounds_enabled;
// 81F070: using guessed type float SoundManager::ambient_sound_volume;
// 81F074: using guessed type bool SoundManager::interface_sounds_enabled;
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 86F3A4: using guessed type unsigned __int32 SoundManager::s_SoundFeatures;
// 86F3AC: using guessed type bool SoundManager::s_bInittedPrefs;

//----- (00550640) --------------------------------------------------------  // acclient.c:383411
void __cdecl SoundManager::Init(HWND__ *hwnd)
{
  PSRefBufferCharData<char> *v1; // ecx@0
  unsigned int v2; // eax@3

  SoundManager::InitPrefs(v1);
  SoundSetup(hwnd);
  midiSetup();
  if ( SoundOK() )
  {
    v2 = _time(0);
    _srand(v2);
  }
  else
  {
    SoundManager::effect_sounds_enabled = 0;
  }
}
// 81F064: using guessed type bool SoundManager::effect_sounds_enabled;

//----- (00550680) --------------------------------------------------------  // acclient.c:383432
SoundBufRef *__cdecl SoundManager::GetSound(SoundType stype, CSoundTable *sound_table, SoundData *stdata)
{
  double v3; // st7@4
  unsigned int v4; // esi@4
  unsigned __int64 v5; // rax@4
  SoundData *v6; // edx@5
  SoundBufRef *result; // eax@6
  SoundTableData *stdata1; // [sp+0h] [bp-4h]@1

  stdata1 = 0;
  if ( sound_table
    && CSoundTable::Lookup(sound_table, stype, &stdata1)
    && stdata1->num_stdatas_
    && (v3 = Random::RollDice(0.0, 1.0),
        v4 = stdata1->num_stdatas_,
        v5 = (unsigned __int64)((double)(v4 - 1) * v3),
        (unsigned int)v5 < v4)
    && (v6 = &stdata1->data_[v5],
        stdata->sound_id_.id = v6->sound_id_.id,
        stdata->priority_ = v6->priority_,
        stdata->probability_ = v6->probability_,
        stdata->volume_ = v6->volume_,
        stdata->sound_id_.id) )
    result = IntrusiveHashTable<unsigned long,CLostCell *,0>::find(
               (IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *)&SoundManager::sound_hash_,
               &stdata->sound_id_);
  else
    result = 0;
  return result;
}

//----- (00550730) --------------------------------------------------------  // acclient.c:383464
void __cdecl SoundManager::PlaySoundA(IDClass<_tagDataID,32,0> gid, CPhysicsObj *physobj)
{
  HashTableData<unsigned long,HeritageGroup_CG> *v2; // eax@4

  if ( SoundManager::effect_sounds_enabled && (!SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp) )
  {
    v2 = SoundManager::sound_hash_.m_buckets[gid.id % SoundManager::sound_hash_.m_numBuckets];
    if ( v2 )
    {
      while ( v2->m_hashKey != gid.id )
      {
        v2 = v2->m_hashNext;
        if ( !v2 )
          return;
      }
      if ( v2 )
        SoundManager::PlaySoundInternal((SoundBufRef *)v2, &physobj->m_position, SoundManager::effect_sound_volume, 0);
    }
  }
}
// 81F064: using guessed type bool SoundManager::effect_sounds_enabled;
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (005507A0) --------------------------------------------------------  // acclient.c:383489
void __cdecl SoundManager::PlaySoundA(IDClass<_tagDataID,32,0> gid, CPhysicsObj *physobj, float prio, float prob, float vol)
{
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@4

  if ( SoundManager::effect_sounds_enabled && (!SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp) )
  {
    v5 = SoundManager::sound_hash_.m_buckets[gid.id % SoundManager::sound_hash_.m_numBuckets];
    if ( v5 )
    {
      while ( v5->m_hashKey != gid.id )
      {
        v5 = v5->m_hashNext;
        if ( !v5 )
          return;
      }
      if ( v5 )
      {
        if ( SoundManager::PlayProbability(prob) )
          SoundManager::PlaySoundInternal((SoundBufRef *)v5, &physobj->m_position, vol, 0);
      }
    }
  }
}
// 81F064: using guessed type bool SoundManager::effect_sounds_enabled;
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00550820) --------------------------------------------------------  // acclient.c:383517
void __cdecl SoundManager::PlayAmbientSound(SoundType stype, CSoundTable *sound_table, Position *pos, float volume)
{
  SoundBufRef *v4; // esi@2
  float v5; // ST18_4@3
  SoundData current_data; // [sp+8h] [bp-10h]@2
  float volumea; // [sp+28h] [bp+10h]@2

  if ( SoundManager::ambient_sounds_enabled )
  {
    volumea = SoundManager::ambient_sound_volume * volume;
    SoundData::SoundData(&current_data);
    v4 = SoundManager::GetSound(stype, sound_table, &current_data);
    if ( v4 )
    {
      v5 = current_data.probability_;
      if ( (double)_rand() * 0.000030518509 < v5 )
        SoundManager::PlaySoundInternal(v4, pos, volumea, 1);
    }
  }
}
// 81F06C: using guessed type bool SoundManager::ambient_sounds_enabled;
// 81F070: using guessed type float SoundManager::ambient_sound_volume;

//----- (005508B0) --------------------------------------------------------  // acclient.c:383541
void __cdecl SoundManager::PlayAmbientSoundFromCenter(SoundType stype, CSoundTable *sound_table, float center_volume)
{
  SoundBufRef *v3; // esi@2
  int attenuation; // [sp+4h] [bp-14h]@3
  SoundData current_data; // [sp+8h] [bp-10h]@2
  float center_volumea; // [sp+24h] [bp+Ch]@2

  if ( SoundManager::ambient_sounds_enabled )
  {
    center_volumea = SoundManager::ambient_sound_volume * center_volume;
    SoundData::SoundData(&current_data);
    v3 = SoundManager::GetSound(stype, sound_table, &current_data);
    if ( v3 )
    {
      *(float *)&attenuation = current_data.probability_;
      if ( (double)_rand() * 0.000030518509 < *(float *)&attenuation )
      {
        if ( SoundManager::GetAttenuation(0.0, center_volumea, &attenuation, 1) )
          SoundManager::PlaySoundInternal(v3, 0, attenuation);
      }
    }
  }
}
// 81F06C: using guessed type bool SoundManager::ambient_sounds_enabled;
// 81F070: using guessed type float SoundManager::ambient_sound_volume;

//----- (00550950) --------------------------------------------------------  // acclient.c:383568
void __cdecl SoundManager::PlaySoundFromCenter(SoundType stype, CSoundTable *sound_table)
{
  SoundBufRef *v2; // esi@4
  int attenuation; // [sp+0h] [bp-14h]@6
  SoundData current_data; // [sp+4h] [bp-10h]@4

  if ( SoundManager::interface_sounds_enabled && (!SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp) )
  {
    SoundData::SoundData(&current_data);
    v2 = SoundManager::GetSound(stype, sound_table, &current_data);
    if ( v2 && SoundManager::PlayProbability(current_data.probability_) )
    {
      if ( SoundManager::GetAttenuation(0.0, current_data.volume_, &attenuation, 0) )
        SoundManager::PlaySoundInternal(v2, 0, attenuation);
    }
  }
}
// 81F074: using guessed type bool SoundManager::interface_sounds_enabled;
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (005509E0) --------------------------------------------------------  // acclient.c:383590
void __cdecl SoundManager::PlaySoundFromCenter(IDClass<_tagDataID,32,0> gid, float center_volume)
{
  int v2; // ecx@0
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@4
  int attenuation; // [sp+0h] [bp-4h]@1

  attenuation = v2;
  if ( SoundManager::interface_sounds_enabled && (!SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp) )
  {
    v3 = SoundManager::sound_hash_.m_buckets[gid.id % SoundManager::sound_hash_.m_numBuckets];
    if ( v3 )
    {
      while ( v3->m_hashKey != gid.id )
      {
        v3 = v3->m_hashNext;
        if ( !v3 )
          return;
      }
      if ( v3 )
      {
        if ( SoundManager::GetAttenuation(0.0, center_volume, &attenuation, 0) )
          SoundManager::PlaySoundInternal((SoundBufRef *)v3, 0, attenuation);
      }
    }
  }
}
// 81F074: using guessed type bool SoundManager::interface_sounds_enabled;
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00550A60) --------------------------------------------------------  // acclient.c:383621
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (SoundBufRef **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (SoundBufRef **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7CAF60: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::vftable)(void *, char);

//----- (00550AF0) --------------------------------------------------------  // acclient.c:383654
void __cdecl SoundManager::PlaySoundA(SoundType stype, CPhysicsObj *physobj, float volume)
{
  CSoundTable *v3; // eax@4
  SoundBufRef *v4; // esi@5
  SoundData current_data; // [sp+0h] [bp-10h]@4

  if ( SoundManager::effect_sounds_enabled && (!SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp) )
  {
    SoundData::SoundData(&current_data);
    v3 = physobj->sound_table;
    if ( v3 )
    {
      v4 = SoundManager::GetSound(stype, v3, &current_data);
      if ( v4 )
      {
        if ( SoundManager::PlayProbability(current_data.probability_) )
          SoundManager::PlaySoundInternal(v4, &physobj->m_position, volume, 0);
      }
    }
  }
}
// 81F064: using guessed type bool SoundManager::effect_sounds_enabled;
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00550B70) --------------------------------------------------------  // acclient.c:383680
void __cdecl SoundManager::PlaySoundA(SoundType stype, CPhysicsObj *physobj)
{
  CSoundTable *v2; // eax@4
  SoundBufRef *v3; // esi@5
  SoundData current_data; // [sp+0h] [bp-10h]@4

  if ( SoundManager::effect_sounds_enabled && (!SoundManager::s_bPlaySoundOnlyWhenActive || Device::m_bIsActiveApp) )
  {
    SoundData::SoundData(&current_data);
    v2 = physobj->sound_table;
    if ( v2 )
    {
      v3 = SoundManager::GetSound(stype, v2, &current_data);
      if ( v3 )
      {
        if ( SoundManager::PlayProbability(current_data.probability_) )
          SoundManager::PlaySoundInternal(v3, &physobj->m_position, current_data.volume_, 0);
      }
    }
  }
}
// 81F064: using guessed type bool SoundManager::effect_sounds_enabled;
// 81F07C: using guessed type bool SoundManager::s_bPlaySoundOnlyWhenActive;
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00550BF0) --------------------------------------------------------  // acclient.c:383706
void __cdecl SoundManager::CreateSound(IDClass<_tagDataID,32,0> gid)
{
  HashTableData<unsigned long,HeritageGroup_CG> *v1; // eax@1
  SoundBufRef *v2; // eax@6
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v3; // eax@7

  v1 = SoundManager::sound_hash_.m_buckets[gid.id % SoundManager::sound_hash_.m_numBuckets];
  if ( !v1 )
    goto LABEL_6;
  while ( v1->m_hashKey != gid.id )
  {
    v1 = v1->m_hashNext;
    if ( !v1 )
      goto LABEL_6;
  }
  if ( v1 )
  {
    ++v1->m_data.environmentSetupID.id;
  }
  else
  {
LABEL_6:
    v2 = (SoundBufRef *)operator new(0x24u);
    if ( v2 )
    {
      SoundBufRef::SoundBufRef(v2, gid);
      IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&SoundManager::sound_hash_,
        v3);
    }
    else
    {
      IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&SoundManager::sound_hash_,
        0);
    }
  }
}

//----- (00550C60) --------------------------------------------------------  // acclient.c:383746
void __cdecl SoundManager::DestroySound(IDClass<_tagDataID,32,0> gid)
{
  HashTableData<unsigned long,HeritageGroup_CG> *v1; // edx@1
  bool v2; // zf@6
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@7
  void *v4; // edi@7
  void *v5; // esi@8

  v1 = SoundManager::sound_hash_.m_buckets[gid.id % SoundManager::sound_hash_.m_numBuckets];
  if ( v1 )
  {
    while ( v1->m_hashKey != gid.id )
    {
      v1 = v1->m_hashNext;
      if ( !v1 )
        return;
    }
    if ( v1 )
    {
      v2 = v1->m_data.environmentSetupID.id-- == 1;
      if ( v2 )
      {
        v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
               (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&SoundManager::sound_hash_,
               &gid);
        v4 = v3;
        if ( v3 )
        {
          v5 = v3[3].m_hashNext;
          if ( v5 )
          {
            SoundBuf::~SoundBuf((SoundBuf *)v3[3].m_hashNext);
            operator delete(v5);
          }
          operator delete(v4);
        }
      }
    }
  }
}

//----- (007062C0) --------------------------------------------------------  // acclient.c:793458
int sub_7062C0()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_16, "Sound.SoundDisabled");
  return atexit(_E74_74);
}

//----- (007062E0) --------------------------------------------------------  // acclient.c:793465
int _E76_60()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_16, "Sound.SoundVolume");
  return atexit(_E77_88);
}

//----- (00706300) --------------------------------------------------------  // acclient.c:793472
int _E79_54()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_16, "Sound.AmbientSoundDisabled");
  return atexit(_E80_53);
}

//----- (00706320) --------------------------------------------------------  // acclient.c:793479
int _E82_35()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_16, "Sound.AmbientSoundVolume");
  return atexit(_E83_33);
}

//----- (00706340) --------------------------------------------------------  // acclient.c:793486
int _E85_24()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_16, "Sound.InterfaceSoundDisabled");
  return atexit(_E86_21);
}

//----- (00706360) --------------------------------------------------------  // acclient.c:793493
int _E88_18()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_16, "Sound.InterfaceSoundVolume");
  return atexit(_E89_31);
}

//----- (00706380) --------------------------------------------------------  // acclient.c:793500
int sub_706380()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_16, "Sound.SoundFeatures");
  return atexit(_E92_36);
}

//----- (007063A0) --------------------------------------------------------  // acclient.c:793507
int _E94_24()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_16, "Sound.PlaySoundOnlyWhenActive");
  return atexit(sub_771DE0);
}

//----- (007063C0) --------------------------------------------------------  // acclient.c:793514
int sub_7063C0()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_16, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_86F3EC, "Mono");
  return atexit(sub_771E10);
}

//----- (007063F0) --------------------------------------------------------  // acclient.c:793522
int sub_7063F0()
{
  return atexit(nullsub_1242);
}

//----- (00706400) --------------------------------------------------------  // acclient.c:793528
int sub_706400()
{
  return atexit(nullsub_1243);
}

//----- (00706410) --------------------------------------------------------  // acclient.c:793534
int sub_706410()
{
  return atexit(_E107_89);
}

//----- (00706420) --------------------------------------------------------  // acclient.c:793540
void _E125_8()
{
  LODWORD(dword_86F3F4) = 1053364187;
}

//----- (00706430) --------------------------------------------------------  // acclient.c:793546
void _E127_49()
{
  flt_86F3F8 = 1000.0 + 1.0;
}

//----- (00706450) --------------------------------------------------------  // acclient.c:793552
void _E129_39()
{
  flt_86F3FC = 24.0 * 8.0;
}

//----- (00706470) --------------------------------------------------------  // acclient.c:793558
void _E131_5()
{
  flt_86F400 = 24.0 * 0.5;
}

//----- (00706490) --------------------------------------------------------  // acclient.c:793564
void _E133_37()
{
  VOL_MIN_DIST_SQ_13 = 5.0 * 5.0;
}

//----- (007064B0) --------------------------------------------------------  // acclient.c:793570
void _E135_45()
{
  INV_LOG_OF_2_13 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (007064D0) --------------------------------------------------------  // acclient.c:793576
void _E137_7()
{
  flt_86F410 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007064F0) --------------------------------------------------------  // acclient.c:793582
void _E139_26()
{
  dbl_86F418 = 1.0 / 30.0;
}

//----- (00706510) --------------------------------------------------------  // acclient.c:793588
void _E141_37()
{
  dbl_86F420 = 1.0 / 5.0;
}

//----- (00706530) --------------------------------------------------------  // acclient.c:793594
void _E143_6()
{
  PixelFormatDesc::PixelFormatDesc(&stru_86F428, PFID_A8R8G8B8);
}

//----- (00706540) --------------------------------------------------------  // acclient.c:793600
void _E145_26()
{
  dword_86F460 = 1024;
}

//----- (00706550) --------------------------------------------------------  // acclient.c:793606
void _E147_34()
{
  dword_86F464 = 0x7FFF;
}

//----- (00706560) --------------------------------------------------------  // acclient.c:793612
int _E149_5()
{
  const int result; // eax@1

  result = dword_86F460;
  dword_86F468 = dword_86F460;
  return result;
}

//----- (00706570) --------------------------------------------------------  // acclient.c:793622
int _E151_24()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_28, "Display.Resolution");
  return atexit(_E152_29);
}

//----- (00706590) --------------------------------------------------------  // acclient.c:793629
int _E154_25()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_28, "Display.FullScreen");
  return atexit(_E155_25);
}

//----- (007065B0) --------------------------------------------------------  // acclient.c:793636
int _E157_23()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_28, "Display.RefreshRate");
  return atexit(_E158_27);
}

//----- (007065D0) --------------------------------------------------------  // acclient.c:793643
int _E160_26()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_28, "Display.SyncToRefresh");
  return atexit(_E161_25);
}

//----- (007065F0) --------------------------------------------------------  // acclient.c:793650
int _E163_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_60, "None");
  return atexit(_E164_27);
}

//----- (00706610) --------------------------------------------------------  // acclient.c:793657
int _E166_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_60, "Speed");
  return atexit(_E167_23);
}

//----- (00706630) --------------------------------------------------------  // acclient.c:793664
int _E169_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_60, "Noise");
  return atexit(_E170_23);
}

//----- (00706650) --------------------------------------------------------  // acclient.c:793671
int _E172_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_60, "Sine");
  return atexit(_E173_19);
}

//----- (00706670) --------------------------------------------------------  // acclient.c:793678
int _E175_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_60, "Square");
  return atexit(_E176_21);
}

//----- (00706690) --------------------------------------------------------  // acclient.c:793685
int _E178_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_60, "Bounce");
  return atexit(_E179_20);
}

//----- (007066B0) --------------------------------------------------------  // acclient.c:793692
int _E181_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_60, "Perlin");
  return atexit(_E182_20);
}

//----- (007066D0) --------------------------------------------------------  // acclient.c:793699
int _E184_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_60, "Fractal");
  return atexit(_E185_17);
}

//----- (007066F0) --------------------------------------------------------  // acclient.c:793706
int _E187_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_60, "FrameLoop");
  return atexit(_E188_18);
}

//----- (00706710) --------------------------------------------------------  // acclient.c:793713
int _E190_14()
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>(
    (IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *)&SoundManager::sound_hash_,
    0x40u);
  return atexit(_E191_17);
}

//----- (00706730) --------------------------------------------------------  // acclient.c:793722
int _E193_13()
{
  Frame::cache(&SoundManager::player_position_.frame);
  return atexit(_E194_24);
}

//----- (00706750) --------------------------------------------------------  // acclient.c:793729
int *_E196_20()
{
  int *result; // eax@1
  signed int v1; // edx@1

  result = dword_86F518;
  v1 = 16;
  do
  {
    *(result - 2) = 0;
    *(result - 1) = 0;
    *result = 0;
    result[1] = 0;
    result += 4;
    --v1;
  }
  while ( v1 );
  return result;
}
// 86F518: using guessed type int dword_86F518[];

//----- (00706780) --------------------------------------------------------  // acclient.c:793751
int sub_706780()
{
  return atexit(nullsub_1241);
}

//----- (00771C80) --------------------------------------------------------  // acclient.c:905662
void __cdecl _E194_24()
{
  SoundManager::player_position_.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00771C90) --------------------------------------------------------  // acclient.c:905669
void __cdecl _E74_74()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771CC0) --------------------------------------------------------  // acclient.c:905682
void __cdecl _E77_88()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771CF0) --------------------------------------------------------  // acclient.c:905695
void __cdecl _E80_53()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771D20) --------------------------------------------------------  // acclient.c:905708
void __cdecl _E83_33()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771D50) --------------------------------------------------------  // acclient.c:905721
void __cdecl _E86_21()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771D80) --------------------------------------------------------  // acclient.c:905734
void __cdecl _E89_31()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771DB0) --------------------------------------------------------  // acclient.c:905747
void __cdecl _E92_36()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771DE0) --------------------------------------------------------  // acclient.c:905760
void __cdecl sub_771DE0()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771E10) --------------------------------------------------------  // acclient.c:905773
void __cdecl sub_771E10()
{
  IDClass<_tagDataID,32,0> *v0; // edi@1
  signed int v1; // ebp@1
  unsigned int v2; // esi@2
  int v3; // esi@2

  v0 = &stru_86F3F0;
  v1 = 2;
  do
  {
    v2 = v0[-1].id;
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

//----- (00771E50) --------------------------------------------------------  // acclient.c:905798
void __cdecl _E152_29()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771E80) --------------------------------------------------------  // acclient.c:905811
void __cdecl _E155_25()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771EB0) --------------------------------------------------------  // acclient.c:905824
void __cdecl _E158_27()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771EE0) --------------------------------------------------------  // acclient.c:905837
void __cdecl _E161_25()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771F10) --------------------------------------------------------  // acclient.c:905850
void __cdecl _E164_27()
{
  char *v0; // esi@1

  v0 = &waveform_None_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771F40) --------------------------------------------------------  // acclient.c:905863
void __cdecl _E167_23()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771F70) --------------------------------------------------------  // acclient.c:905876
void __cdecl _E170_23()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771FA0) --------------------------------------------------------  // acclient.c:905889
void __cdecl _E173_19()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00771FD0) --------------------------------------------------------  // acclient.c:905902
void __cdecl _E176_21()
{
  char *v0; // esi@1

  v0 = &waveform_Square_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772000) --------------------------------------------------------  // acclient.c:905915
void __cdecl _E179_20()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772030) --------------------------------------------------------  // acclient.c:905928
void __cdecl _E182_20()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772060) --------------------------------------------------------  // acclient.c:905941
void __cdecl _E185_17()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772090) --------------------------------------------------------  // acclient.c:905954
void __cdecl _E188_18()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_60.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_60.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007720C0) --------------------------------------------------------  // acclient.c:905967
void __cdecl _E191_17()
{
  SoundManager::sound_hash_.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::vftable;
  if ( (HashTableData<unsigned long,HeritageGroup_CG> **)SoundManager::sound_hash_.m_buckets != SoundManager::sound_hash_.m_aInplaceBuckets )
    operator delete[](SoundManager::sound_hash_.m_buckets);
  SoundManager::sound_hash_.m_buckets = 0;
  SoundManager::sound_hash_.m_firstInterestingBucket = 0;
  SoundManager::sound_hash_.m_numBuckets = 0;
  SoundManager::sound_hash_.m_numElements = 0;
}
// 7CAF60: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::vftable)(void *, char);

