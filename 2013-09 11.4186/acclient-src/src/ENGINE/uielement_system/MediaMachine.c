/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MediaMachine
   Object     : ENGINE\uielement_system\MediaMachine.obj
   Functions  : 65
   Addresses  : 00465520 - 0075DED0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00465520) --------------------------------------------------------  // acclient.c:162005
char __thiscall MediaMachine::Update_Pause(MediaMachine *this, MD_Data_Pause *_desc)
{
  char v2; // cl@5
  char result; // al@7
  double curTime; // [sp+8h] [bp-8h]@3

  if ( _desc && this->m_owner )
  {
    curTime = Timer::compute_time();
    if ( _desc->m_endTime == -1.0 )
      _desc->m_endTime = Random::RollDice(_desc->m_minDuration, _desc->m_maxDuration) + curTime;
    v2 = 0;
    if ( curTime >= _desc->m_endTime )
    {
      _desc->m_endTime = INVALID_TIME_5;
      v2 = 1;
    }
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004655B0) --------------------------------------------------------  // acclient.c:162032
char __thiscall MediaMachine::Update_Jump(MediaMachine *this, MD_Data_Jump *_desc)
{
  MD_Data_Jump *v2; // edi@1
  MediaMachine *v3; // esi@1
  char result; // al@5
  float _desca; // [sp+Ch] [bp+4h]@3

  v2 = _desc;
  v3 = this;
  if ( _desc && this->m_owner )
  {
    _desca = _desc->m_probability;
    if ( Random::RollDice(0.0, 1.0) <= _desca )
      v3->m_curIndex = v2->m_jumpItemIndex - 1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00465600) --------------------------------------------------------  // acclient.c:162056
char __thiscall MediaMachine::Update_Message(MediaMachine *this, MD_Data_Message *_desc)
{
  MD_Data_Message *v2; // edi@1
  MediaMachine *v3; // esi@1
  UIElement *v4; // eax@2
  char result; // al@6
  float _desca; // [sp+Ch] [bp+4h]@4

  v2 = _desc;
  v3 = this;
  if ( _desc && (v4 = this->m_owner) != 0 && (v4->m_nFlags >> 17) & 1 )
  {
    _desca = _desc->m_probability;
    if ( Random::RollDice(0.0, 1.0) <= _desca )
      UIElement::BroadcastElementMessage(v3->m_owner, v2->m_messageID, 0, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00465660) --------------------------------------------------------  // acclient.c:162081
bool __thiscall MediaMachine::Update_State(MediaMachine *this, MD_Data_State *_desc)
{
  MD_Data_State *v2; // edi@1
  MediaMachine *v3; // esi@1
  float _desca; // [sp+Ch] [bp+4h]@3

  v2 = _desc;
  v3 = this;
  if ( _desc )
  {
    if ( this->m_owner )
    {
      _desca = _desc->m_probability;
      if ( Random::RollDice(0.0, 1.0) <= _desca )
        ((void (__stdcall *)(unsigned int))v3->m_owner->vfptr[13].__vecDelDtor)(v2->m_stateID);
    }
  }
  return 0;
}

//----- (004656B0) --------------------------------------------------------  // acclient.c:162102
char __thiscall MediaMachine::Update_Movie(MediaMachine *this, MD_Data_Movie *_desc)
{
  UIElement *v2; // eax@2
  char result; // al@4

  if ( _desc && (v2 = this->m_owner) != 0 && (v2->m_nFlags >> 17) & 1 )
    result = MD_Data_Movie::Update(_desc, v2);
  else
    result = 0;
  return result;
}

//----- (004656E0) --------------------------------------------------------  // acclient.c:162115
char __thiscall MediaMachine::Update_Anim(MediaMachine *this, MD_Data_Anim *_desc)
{
  MD_Data_Anim *v2; // esi@1
  MediaMachine *v3; // ebx@1
  long double v4; // st7@3
  long double v5; // st7@6
  MD_Data_Anim **v6; // eax@8
  void *v7; // eax@10
  MD_Data_Anim *v8; // edx@12
  unsigned int v9; // eax@12
  int v10; // edi@13
  char v11; // cl@15
  char result; // al@17
  long double curTime; // [sp+8h] [bp-8h]@3

  v2 = _desc;
  v3 = this;
  if ( *(float *)&_desc != 0.0 && this->m_owner )
  {
    v4 = Timer::compute_time();
    curTime = v4;
    if ( v2->m_StartTime == -1.0 )
    {
      v2->m_StartTime = v4;
      v2->m_displayedFrameNum = -1;
    }
    v2->vfptr->GetDuration((MediaDesc *)v2);
    if ( fabs(v4) > 0.00019999999 )
      v5 = (curTime - v2->m_StartTime) / v4;
    else
      v5 = 0.0;
    *(float *)&_desc = v5;
    LODWORD(curTime) = 0;
    v6 = (MD_Data_Anim **)&curTime;
    if ( v5 >= 0.0 )
      v6 = &_desc;
    *(float *)&_desc = *(float *)v6;
    LODWORD(curTime) = 1065353216;
    v7 = &curTime;
    if ( *(float *)&_desc <= 1.0 )
      v7 = &_desc;
    v8 = *(MD_Data_Anim **)v7;
    v9 = v2->m_frames.m_num;
    _desc = v8;
    if ( v9 )
    {
      LODWORD(curTime) = v9 - 1;
      v10 = (unsigned __int64)((double)(v9 - 1) * *(float *)&_desc + 0.5);
      if ( v10 != v2->m_displayedFrameNum )
      {
        UIRegion::SetImageByDID((UIRegion *)&v3->m_owner->vfptr, v2->m_frames.m_data[v10], v2->m_drawMode);
        v2->m_displayedFrameNum = v10;
      }
    }
    v11 = 0;
    if ( *(float *)&_desc == 1.0 )
    {
      v2->m_StartTime = INVALID_TIME_5;
      v2->m_displayedFrameNum = -1;
      v11 = 1;
    }
    result = v11;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00465830) --------------------------------------------------------  // acclient.c:162186
char __thiscall MediaMachine::Update_Alpha(MediaMachine *this, MD_Data_Alpha *_desc)
{
  UIRegion *v2; // ecx@2
  unsigned int v3; // eax@3
  char result; // al@4

  if ( _desc && (v2 = (UIRegion *)&this->m_owner->vfptr) != 0 )
  {
    v3 = _desc->m_file.id;
    if ( v3 == INVALID_DID_54.id )
    {
      UIRegion::ClearAlphaImage(v2);
      result = 1;
    }
    else
    {
      UIRegion::SetAlphaImageByDID(v2, (IDClass<_tagDataID,32,0>)v3);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00465870) --------------------------------------------------------  // acclient.c:162214
char __thiscall MediaMachine::Update_Image(MediaMachine *this, MD_Data_Image *_desc)
{
  UIRegion *v2; // ecx@2
  unsigned int v3; // eax@3
  char result; // al@4

  if ( _desc && (v2 = (UIRegion *)&this->m_owner->vfptr) != 0 )
  {
    v3 = _desc->m_file.id;
    if ( v3 == INVALID_DID_54.id )
    {
      UIRegion::ClearImage(v2);
      result = 1;
    }
    else
    {
      UIRegion::SetImageByDID(v2, (IDClass<_tagDataID,32,0>)v3, _desc->m_drawMode);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004658B0) --------------------------------------------------------  // acclient.c:162242
bool __thiscall MediaMachine::Update_Sound(MediaMachine *this, MD_Data_Sound *_desc)
{
  QualifiedDataID *v2; // eax@4
  int v3; // eax@4
  bool result; // al@5
  unsigned int v5; // esi@6
  QualifiedDataID v6; // [sp+4h] [bp-8h]@4

  if ( _desc && this->m_owner )
  {
    if ( _desc->m_stype )
    {
      QualifiedDataID::QualifiedDataID(&v6, _desc->m_file, 0x22u);
      v3 = DBObj::Get(v2);
      if ( v3 )
      {
        SoundManager::PlaySoundFromCenter(_desc->m_stype, (CSoundTable *)v3);
        return 1;
      }
    }
    else
    {
      v5 = _desc->m_file.id;
      if ( v5 )
        SoundManager::PlaySoundFromCenter((IDClass<_tagDataID,32,0>)v5, 1.0);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00465930) --------------------------------------------------------  // acclient.c:162278
char __thiscall MediaMachine::Update_Fade(MediaMachine *this, MD_Data_Fade *_desc)
{
  MD_Data_Fade *v2; // edi@1
  MediaMachine *v3; // esi@1
  UIElement *v4; // eax@3
  UIObject *v5; // eax@4
  UIRegion *v6; // eax@5
  int v7; // esi@8
  long double v8; // st7@10
  int v9; // ecx@11
  long double v10; // st7@13
  MD_Data_Fade **v11; // eax@15
  MD_Data_Fade **v12; // eax@17
  double v13; // st7@19
  float v14; // ST00_4@20
  char v15; // cl@21
  long double curTime; // [sp+Ch] [bp-8h]@3

  v2 = _desc;
  v3 = this;
  if ( *(float *)&_desc == 0.0 || !this->m_owner )
    return 0;
  curTime = Timer::compute_time();
  v4 = v3->m_owner;
  if ( v4->m_object )
  {
    v5 = v4->m_object;
  }
  else
  {
    v6 = v4->m_parent;
    if ( !v6 )
    {
LABEL_9:
      v7 = 0;
      goto LABEL_10;
    }
    v5 = UIRegion::GetObjectA(v6);
  }
  if ( !v5 )
    goto LABEL_9;
  v7 = ((int (__thiscall *)(UIObject *))v5->vfptr[7].__vecDelDtor)(v5);
LABEL_10:
  v8 = v2->m_startTime;
  if ( v8 == -1.0 )
  {
    v9 = HIDWORD(curTime);
    LODWORD(v2->m_startTime) = LODWORD(curTime);
    HIDWORD(v2->m_startTime) = v9;
  }
  v2->vfptr->GetDuration((MediaDesc *)v2);
  if ( fabs(v8) > 0.00019999999 )
    v10 = (curTime - v2->m_startTime) / v8;
  else
    v10 = 1.0;
  *(float *)&_desc = v10;
  LODWORD(curTime) = 0;
  v11 = (MD_Data_Fade **)&curTime;
  if ( v10 >= 0.0 )
    v11 = &_desc;
  *(float *)&_desc = *(float *)v11;
  LODWORD(curTime) = 1065353216;
  v12 = (MD_Data_Fade **)&curTime;
  if ( *(float *)&_desc <= 1.0 )
    v12 = &_desc;
  v13 = v2->m_startAlpha;
  *(float *)&_desc = *(float *)v12;
  if ( v7 )
  {
    v14 = (v2->m_endAlpha - v13) * *(float *)&_desc + v13;
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 72))(v7, LODWORD(v14));
  }
  v15 = 0;
  if ( *(float *)&_desc == 1.0 )
  {
    v2->m_startTime = INVALID_TIME_5;
    v15 = 1;
  }
  return v15;
}

//----- (00465A80) --------------------------------------------------------  // acclient.c:162360
char __thiscall MediaMachine::Update_Cursor(MediaMachine *this, MD_Data_Cursor *_desc)
{
  UIElement *v2; // ecx@2
  unsigned int v3; // edx@3
  char result; // al@4

  if ( _desc && (v2 = this->m_owner) != 0 )
  {
    v3 = _desc->m_file.id;
    if ( v3 == INVALID_DID_54.id )
    {
      UIElement::UnSetCursor(v2);
      result = 1;
    }
    else
    {
      UIElement::SetCursor(v2, (IDClass<_tagDataID,32,0>)v3, _desc->m_xHotspot, _desc->m_yHotspot);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00465AC0) --------------------------------------------------------  // acclient.c:162388
void __thiscall MediaMachine::MediaMachine(MediaMachine *this)
{
  MediaMachine *v1; // esi@1

  v1 = this;
  UIListener::UIListener((UIListener *)&this->vfptr);
  v1->m_owner = 0;
  v1->vfptr = (IInputActionCallbackVtbl *)&MediaMachine::vftable;
  v1->m_array.m_data = 0;
  v1->m_array.m_sizeAndDeallocate = 0;
  v1->m_array.m_num = 0;
  v1->m_curIndex = 0;
}
// 79C0BC: using guessed type int (__thiscall *MediaMachine::vftable)(void *, char);

//----- (00465AF0) --------------------------------------------------------  // acclient.c:162404
void __thiscall MediaMachine::Cleanup(MediaMachine *this)
{
  MediaMachine *v1; // esi@1
  unsigned int v2; // edi@1
  MediaDesc *v3; // ecx@2
  unsigned int v4; // eax@5
  unsigned int v5; // ecx@5
  int i; // eax@8

  v1 = this;
  v2 = 0;
  if ( this->m_array.m_num )
  {
    do
    {
      v3 = v1->m_array.m_data[v2];
      if ( v3 )
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      ++v2;
    }
    while ( v2 < v1->m_array.m_num );
  }
  v4 = v1->m_array.m_sizeAndDeallocate;
  v5 = v1->m_array.m_sizeAndDeallocate & 0x80000000;
  v1->m_array.m_num = 0;
  if ( v5 == 0x80000000 )
  {
    operator delete[](v1->m_array.m_data);
    v1->m_array.m_data = 0;
    v1->m_array.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_array.m_data )
  {
    for ( i = (v4 & 0x7FFFFFFF) - 1; i >= 0; v1->m_array.m_data[i + 1] = 0 )
      --i;
  }
}

//----- (00465BA0) --------------------------------------------------------  // acclient.c:162443
void __thiscall MediaMachine::Update(MediaMachine *this)
{
  MediaMachine *v1; // esi@1
  MediaDesc *v2; // ecx@2
  MD_Data_Anim *v3; // eax@4
  char v4; // al@4
  MD_Data_Alpha *v5; // eax@5
  MD_Data_Pause *v6; // eax@6
  MD_Data_Image *v7; // eax@7
  MD_Data_Sound *v8; // eax@8
  MD_Data_Jump *v9; // eax@9
  MD_Data_Fade *v10; // eax@10
  MD_Data_Message *v11; // eax@11
  MD_Data_State *v12; // eax@12
  MD_Data_Movie *v13; // eax@13
  MD_Data_Cursor *v14; // eax@14
  int v15; // ecx@16

  v1 = this;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  if ( v1->m_curIndex < v1->m_array.m_num )
  {
    while ( 1 )
    {
      v2 = v1->m_array.m_data[v1->m_curIndex];
      if ( v2 )
      {
        switch ( v2->m_type )
        {
          case 3u:
            v3 = (MD_Data_Anim *)((int (*)(void))v2->vfptr->DynamicCast_Anim)();
            v4 = MediaMachine::Update_Anim(v1, v3);
            break;
          case 2u:
            v5 = (MD_Data_Alpha *)((int (*)(void))v2->vfptr->DynamicCast_Alpha)();
            v4 = MediaMachine::Update_Alpha(v1, v5);
            break;
          case 8u:
            v6 = (MD_Data_Pause *)((int (*)(void))v2->vfptr->DynamicCast_Pause)();
            v4 = MediaMachine::Update_Pause(v1, v6);
            break;
          case 5u:
            v7 = (MD_Data_Image *)((int (*)(void))v2->vfptr->DynamicCast_Image)();
            v4 = MediaMachine::Update_Image(v1, v7);
            break;
          case 9u:
            v8 = (MD_Data_Sound *)((int (*)(void))v2->vfptr->DynamicCast_Sound)();
            v4 = MediaMachine::Update_Sound(v1, v8);
            break;
          case 6u:
            v9 = (MD_Data_Jump *)((int (*)(void))v2->vfptr->DynamicCast_Jump)();
            v4 = MediaMachine::Update_Jump(v1, v9);
            break;
          case 0xBu:
            v10 = (MD_Data_Fade *)((int (*)(void))v2->vfptr->DynamicCast_Fade)();
            v4 = MediaMachine::Update_Fade(v1, v10);
            break;
          case 7u:
            v11 = (MD_Data_Message *)((int (*)(void))v2->vfptr->DynamicCast_Message)();
            v4 = MediaMachine::Update_Message(v1, v11);
            break;
          case 0xAu:
            v12 = (MD_Data_State *)((int (*)(void))v2->vfptr->DynamicCast_State)();
            v4 = MediaMachine::Update_State(v1, v12);
            break;
          case 1u:
            v13 = (MD_Data_Movie *)((int (*)(void))v2->vfptr->DynamicCast_Movie)();
            v4 = MediaMachine::Update_Movie(v1, v13);
            break;
          case 4u:
            v14 = (MD_Data_Cursor *)((int (*)(void))v2->vfptr->DynamicCast_Cursor)();
            v4 = MediaMachine::Update_Cursor(v1, v14);
            break;
          default:
            goto LABEL_16;
        }
        if ( !v4 )
          break;
      }
LABEL_16:
      v15 = v1->m_curIndex + 1;
      v1->m_curIndex = v15;
      if ( v15 >= v1->m_array.m_num )
        return;
    }
    UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  }
}

//----- (00465CF0) --------------------------------------------------------  // acclient.c:162533
void __thiscall MediaMachine::ListenToGlobalMessage(MediaMachine *this, unsigned int _messageID, int _data_int)
{
  if ( _messageID == 3 )
    MediaMachine::Update(this);
}

//----- (00465D00) --------------------------------------------------------  // acclient.c:162540
void __thiscall MediaMachine::~MediaMachine(MediaMachine *this)
{
  MediaMachine *v1; // esi@1

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&MediaMachine::vftable;
  MediaMachine::Cleanup(this);
  if ( (v1->m_array.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_array.m_data);
  UIListener::~UIListener((UIListener *)&v1->vfptr);
}
// 79C0BC: using guessed type int (__thiscall *MediaMachine::vftable)(void *, char);

//----- (00465D40) --------------------------------------------------------  // acclient.c:162554
MediaMachine *__thiscall MediaMachine::scalar_deleting_destructor(MediaMachine *this, unsigned int a2)
{
  MediaMachine *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&MediaMachine::vftable;
  MediaMachine::Cleanup(this);
  if ( (v2->m_array.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v2->m_array.m_data);
  UIListener::~UIListener((UIListener *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79C0BC: using guessed type int (__thiscall *MediaMachine::vftable)(void *, char);

//----- (00465D90) --------------------------------------------------------  // acclient.c:162571
void __thiscall MediaMachine::Reset(MediaMachine *this, SmartArray<MediaDesc *,1> *_media)
{
  MediaMachine *v2; // ebp@1
  SmartArray<MediaDesc *,1> *v3; // eax@1
  unsigned int v4; // ebx@1
  MediaDesc *v5; // eax@2
  MediaDesc *v6; // eax@3
  MediaDesc *v7; // edi@3
  int v8; // eax@4
  unsigned int v9; // eax@5

  v2 = this;
  MediaMachine::Cleanup(this);
  v3 = _media;
  v4 = 0;
  if ( _media->m_num )
  {
    do
    {
      v5 = v3->m_data[v4];
      if ( v5 )
      {
        MediaDesc::CreateMediaType(v5);
        v7 = v6;
        if ( v6 )
        {
          v8 = v2->m_array.m_sizeAndDeallocate & 0x7FFFFFFF;
          if ( v2->m_array.m_num < v8
            || (v9 = SmartArray<UIChildFramework *,1>::get_new_size(v8 + 1),
                SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v2->m_array, v9)) )
            v2->m_array.m_data[v2->m_array.m_num++] = v7;
        }
      }
      v3 = _media;
      ++v4;
    }
    while ( v4 < _media->m_num );
  }
  v2->m_curIndex = 0;
  MediaMachine::Update(v2);
}

//----- (006EB4F0) --------------------------------------------------------  // acclient.c:767140
int _E73_62()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_30, "None");
  return atexit(_E74_46);
}

//----- (006EB510) --------------------------------------------------------  // acclient.c:767147
int _E76_32()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_30, "Speed");
  return atexit(_E77_60);
}

//----- (006EB530) --------------------------------------------------------  // acclient.c:767154
int _E79_32()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_30, "Noise");
  return atexit(_E80_33);
}

//----- (006EB550) --------------------------------------------------------  // acclient.c:767161
int _E82_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_30, "Sine");
  return atexit(_E83_22);
}

//----- (006EB570) --------------------------------------------------------  // acclient.c:767168
int _E85_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_30, "Square");
  return atexit(_E86_16);
}

//----- (006EB590) --------------------------------------------------------  // acclient.c:767175
int _E88_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_30, "Bounce");
  return atexit(_E89_27);
}

//----- (006EB5B0) --------------------------------------------------------  // acclient.c:767182
int _E91_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_30, "Perlin");
  return atexit(_E92_29);
}

//----- (006EB5D0) --------------------------------------------------------  // acclient.c:767189
int _E94_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_30, "Fractal");
  return atexit(sub_75DCF0);
}

//----- (006EB5F0) --------------------------------------------------------  // acclient.c:767196
int _E97_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_30, "FrameLoop");
  return atexit(_E98_44);
}

//----- (006EB610) --------------------------------------------------------  // acclient.c:767203
void _E100_24()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_39, PFID_A8R8G8B8);
}

//----- (006EB620) --------------------------------------------------------  // acclient.c:767209
int _E118_19()
{
  return atexit(_E119_68);
}

//----- (006EB630) --------------------------------------------------------  // acclient.c:767215
int _E121_17()
{
  return atexit(_E122_55);
}

//----- (006EB640) --------------------------------------------------------  // acclient.c:767221
int _E124_19()
{
  return atexit(_E125_30);
}

//----- (006EB650) --------------------------------------------------------  // acclient.c:767227
int _E127_15()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_3, "Sound.SoundDisabled");
  return atexit(_E128_31);
}

//----- (006EB670) --------------------------------------------------------  // acclient.c:767234
int _E130_16()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_3, "Sound.SoundVolume");
  return atexit(_E131_27);
}

//----- (006EB690) --------------------------------------------------------  // acclient.c:767241
int _E133_15()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_3, "Sound.AmbientSoundDisabled");
  return atexit(_E134_26);
}

//----- (006EB6B0) --------------------------------------------------------  // acclient.c:767248
int _E136_13()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_3, "Sound.AmbientSoundVolume");
  return atexit(_E137_25);
}

//----- (006EB6D0) --------------------------------------------------------  // acclient.c:767255
int _E139_12()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_3, "Sound.InterfaceSoundDisabled");
  return atexit(_E140_20);
}

//----- (006EB6F0) --------------------------------------------------------  // acclient.c:767262
int _E142_12()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_3, "Sound.InterfaceSoundVolume");
  return atexit(_E143_21);
}

//----- (006EB710) --------------------------------------------------------  // acclient.c:767269
int _E145_12()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_3, "Sound.SoundFeatures");
  return atexit(_E146_21);
}

//----- (006EB730) --------------------------------------------------------  // acclient.c:767276
int _E148_12()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_3, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E149_21);
}

//----- (006EB750) --------------------------------------------------------  // acclient.c:767283
int _E151_12()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_3, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_83D2D4, "Mono");
  return atexit(_E152_20);
}

//----- (006EB780) --------------------------------------------------------  // acclient.c:767291
void _E154_13()
{
  LODWORD(dword_83D2D8) = 1053364187;
}

//----- (006EB790) --------------------------------------------------------  // acclient.c:767297
void _E156_14()
{
  outside_val_24 = 1000.0 + 1.0;
}

//----- (006EB7B0) --------------------------------------------------------  // acclient.c:767303
void _E158_0()
{
  block_length_24 = 24.0 * 8.0;
}

//----- (006EB7D0) --------------------------------------------------------  // acclient.c:767309
void _E160_13()
{
  half_square_length_24 = 24.0 * 0.5;
}

//----- (006EB7F0) --------------------------------------------------------  // acclient.c:767315
void _E162_14()
{
  VOL_MIN_DIST_SQ_2 = 5.0 * 5.0;
}

//----- (006EB810) --------------------------------------------------------  // acclient.c:767321
void _E164_0()
{
  INV_LOG_OF_2_2 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006EB830) --------------------------------------------------------  // acclient.c:767327
int _E1_54()
{
  return atexit(_E2_54);
}

//----- (0075DBA0) --------------------------------------------------------  // acclient.c:885956
void __cdecl _E74_46()
{
  char *v0; // esi@1

  v0 = &waveform_None_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DBD0) --------------------------------------------------------  // acclient.c:885969
void __cdecl _E77_60()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DC00) --------------------------------------------------------  // acclient.c:885982
void __cdecl _E80_33()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DC30) --------------------------------------------------------  // acclient.c:885995
void __cdecl _E83_22()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DC60) --------------------------------------------------------  // acclient.c:886008
void __cdecl _E86_16()
{
  char *v0; // esi@1

  v0 = &waveform_Square_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DC90) --------------------------------------------------------  // acclient.c:886021
void __cdecl _E89_27()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DCC0) --------------------------------------------------------  // acclient.c:886034
void __cdecl _E92_29()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DCF0) --------------------------------------------------------  // acclient.c:886047
void __cdecl sub_75DCF0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DD20) --------------------------------------------------------  // acclient.c:886060
void __cdecl _E98_44()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DD50) --------------------------------------------------------  // acclient.c:886073
void __cdecl _E128_31()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DD80) --------------------------------------------------------  // acclient.c:886086
void __cdecl _E131_27()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DDB0) --------------------------------------------------------  // acclient.c:886099
void __cdecl _E134_26()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DDE0) --------------------------------------------------------  // acclient.c:886112
void __cdecl _E137_25()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DE10) --------------------------------------------------------  // acclient.c:886125
void __cdecl _E140_20()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DE40) --------------------------------------------------------  // acclient.c:886138
void __cdecl _E143_21()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DE70) --------------------------------------------------------  // acclient.c:886151
void __cdecl _E146_21()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DEA0) --------------------------------------------------------  // acclient.c:886164
void __cdecl _E149_21()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DED0) --------------------------------------------------------  // acclient.c:886177
void __cdecl _E152_20()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &dword_83D2D8;
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

