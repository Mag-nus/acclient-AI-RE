/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSoundDesc
   Object     : PORTAL\cregion\CSoundDesc.obj
   Functions  : 33
   Addresses  : 00502740 - 00765620 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00502740) --------------------------------------------------------  // acclient.c:303556
void __thiscall CSoundDesc::Destroy(CSoundDesc *this)
{
  CSoundDesc *v1; // esi@1
  unsigned int v2; // ebx@1
  void *v3; // edi@2
  void *v4; // ST04_4@5

  v1 = this;
  v2 = 0;
  if ( this->stb_desc.m_num )
  {
    do
    {
      v3 = v1->stb_desc.m_data[v2];
      if ( v3 )
      {
        AmbientSTBDesc::~AmbientSTBDesc(v1->stb_desc.m_data[v2]);
        operator delete(v3);
      }
      ++v2;
    }
    while ( v2 < v1->stb_desc.m_num );
  }
  v4 = v1->stb_desc.m_data;
  v1->stb_desc.m_num = 0;
  v1->stb_desc.m_size = 0;
  operator delete[](v4);
  v1->stb_desc.m_data = 0;
}

//----- (005027A0) --------------------------------------------------------  // acclient.c:303587
int __thiscall CSoundDesc::pack_size(CSoundDesc *this)
{
  CSoundDesc *v1; // edi@1
  unsigned int v2; // esi@1
  signed int v3; // ebx@1
  int result; // eax@4

  v1 = this;
  v2 = 0;
  v3 = 4;
  if ( this->stb_desc.m_num )
  {
    do
      v3 += AmbientSTBDesc::pack_size(v1->stb_desc.m_data[v2++]);
    while ( v2 < v1->stb_desc.m_num );
  }
  if ( v3 & 3 )
    result = v3 + 4 - (v3 & 3);
  else
    result = v3;
  return result;
}

//----- (005027F0) --------------------------------------------------------  // acclient.c:303611
unsigned int __thiscall CSoundDesc::Pack(CSoundDesc *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // eax@1
  CSoundDesc *v4; // edi@1
  unsigned int v5; // ebx@1
  unsigned int v6; // esi@3
  unsigned int v7; // esi@5
  unsigned int result; // eax@7

  v3 = size;
  v4 = this;
  v5 = this->stb_desc.m_num;
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = v5;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v6 = 0;
  if ( v5 )
  {
    do
    {
      AmbientSTBDesc::Pack(v4->stb_desc.m_data[v6], addr, v3);
      v3 = size;
      ++v6;
    }
    while ( v6 < v5 );
  }
  v7 = 0;
  if ( v4->stb_desc.m_num )
  {
    do
      AmbientSTBDesc::pack_size(v4->stb_desc.m_data[v7++]);
    while ( v7 < v4->stb_desc.m_num );
    result = *size;
  }
  else
  {
    result = *v3;
  }
  return result;
}

//----- (00502860) --------------------------------------------------------  // acclient.c:303656
void __thiscall CSoundDesc::~CSoundDesc(CSoundDesc *this)
{
  void **v1; // esi@1

  v1 = (void **)this;
  CSoundDesc::Destroy(this);
  operator delete[](*v1);
}

//----- (00502880) --------------------------------------------------------  // acclient.c:303666
void __thiscall CSoundDesc::GetSubDataIDs(CSoundDesc *this, QualifiedDataIDArray *id_array)
{
  CSoundDesc *v2; // edi@1
  unsigned int v3; // esi@1
  IDClass<_tagDataID,32,0> v4; // eax@2
  QualifiedDataID *v5; // eax@3
  QualifiedDataID v6; // [sp+8h] [bp-8h]@3

  v2 = this;
  v3 = 0;
  if ( this->stb_desc.m_num )
  {
    do
    {
      v4.id = v2->stb_desc.m_data[v3]->stb_id.id;
      if ( v4.id != stru_8415FC.id )
      {
        QualifiedDataID::QualifiedDataID(&v6, v4, 0);
        QualifiedDataIDArray::AddQDID(id_array, v5, 0);
      }
      ++v3;
    }
    while ( v3 < v2->stb_desc.m_num );
  }
}

//----- (005028D0) --------------------------------------------------------  // acclient.c:303693
int __thiscall CSoundDesc::UnPack(CSoundDesc *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // ebp@1
  CSoundDesc *v4; // esi@1
  unsigned int v5; // ebx@2
  AmbientSTBDesc *v6; // eax@7
  AmbientSTBDesc *v7; // eax@8
  AmbientSTBDesc *v8; // edi@8
  unsigned int v9; // eax@11
  unsigned int v10; // eax@13
  int result; // eax@18
  unsigned int num_stb; // [sp+18h] [bp+8h]@6

  v3 = size;
  v4 = this;
  if ( *size < 4 )
  {
    v5 = (unsigned int)addr;
  }
  else
  {
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  CSoundDesc::Destroy(this);
  if ( v5 )
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v4, v5);
  num_stb = 0;
  if ( v5 )
  {
    while ( 1 )
    {
      v6 = (AmbientSTBDesc *)operator new(0x1Cu);
      if ( v6 )
      {
        AmbientSTBDesc::AmbientSTBDesc(v6);
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      if ( !AmbientSTBDesc::UnPack(v8, addr, v3) )
        break;
      v9 = v4->stb_desc.m_size;
      if ( v4->stb_desc.m_num < v9
        || (!v9 ? (v10 = 8) : (v10 = 2 * v9),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v4, v10)) )
        v4->stb_desc.m_data[v4->stb_desc.m_num++] = v8;
      ++num_stb;
      if ( num_stb >= v5 )
        goto LABEL_18;
    }
    result = 0;
  }
  else
  {
LABEL_18:
    result = 1;
  }
  return result;
}

//----- (006F9B70) --------------------------------------------------------  // acclient.c:782423
void sub_6F9B70()
{
  flt_8415F0 = 1000.0 + 1.0;
}

//----- (006F9B90) --------------------------------------------------------  // acclient.c:782429
void sub_6F9B90()
{
  flt_8415F4 = 24.0 * 8.0;
}

//----- (006F9BB0) --------------------------------------------------------  // acclient.c:782435
void sub_6F9BB0()
{
  flt_8415F8 = 24.0 * 0.5;
}

//----- (006F9BD0) --------------------------------------------------------  // acclient.c:782441
int sub_6F9BD0()
{
  return atexit(nullsub_1044);
}

//----- (006F9BE0) --------------------------------------------------------  // acclient.c:782447
int sub_6F9BE0()
{
  return atexit(nullsub_1045);
}

//----- (006F9BF0) --------------------------------------------------------  // acclient.c:782453
int sub_6F9BF0()
{
  return atexit(nullsub_1046);
}

//----- (006F9C00) --------------------------------------------------------  // acclient.c:782459
int _E106_89()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_10, "Sound.SoundDisabled");
  return atexit(_E107_84);
}

//----- (006F9C20) --------------------------------------------------------  // acclient.c:782466
int _E109_54()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_10, "Sound.SoundVolume");
  return atexit(sub_7654D0);
}

//----- (006F9C40) --------------------------------------------------------  // acclient.c:782473
int _E112_81()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_10, "Sound.AmbientSoundDisabled");
  return atexit(_E113_59);
}

//----- (006F9C60) --------------------------------------------------------  // acclient.c:782480
int _E115_60()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_10, "Sound.AmbientSoundVolume");
  return atexit(_E116_52);
}

//----- (006F9C80) --------------------------------------------------------  // acclient.c:782487
int _E118_61()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_10, "Sound.InterfaceSoundDisabled");
  return atexit(_E119_81);
}

//----- (006F9CA0) --------------------------------------------------------  // acclient.c:782494
int _E121_55()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_10, "Sound.InterfaceSoundVolume");
  return atexit(_E122_84);
}

//----- (006F9CC0) --------------------------------------------------------  // acclient.c:782501
int _E124_57()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_10, "Sound.SoundFeatures");
  return atexit(_E125_56);
}

//----- (006F9CE0) --------------------------------------------------------  // acclient.c:782508
int _E127_46()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_10, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E128_55);
}

//----- (006F9D00) --------------------------------------------------------  // acclient.c:782515
int _E130_44()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_10, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_841624, "Mono");
  return atexit(_E131_47);
}

//----- (006F9D30) --------------------------------------------------------  // acclient.c:782523
void _E133_34()
{
  VOL_MIN_DIST_SQ_7 = 5.0 * 5.0;
}

//----- (006F9D50) --------------------------------------------------------  // acclient.c:782529
void _E135_26()
{
  INV_LOG_OF_2_7 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006F9D70) --------------------------------------------------------  // acclient.c:782535
int sub_6F9D70()
{
  return atexit(nullsub_1043);
}

//----- (007654A0) --------------------------------------------------------  // acclient.c:891850
void __cdecl _E107_84()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007654D0) --------------------------------------------------------  // acclient.c:891863
void __cdecl sub_7654D0()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765500) --------------------------------------------------------  // acclient.c:891876
void __cdecl _E113_59()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765530) --------------------------------------------------------  // acclient.c:891889
void __cdecl _E116_52()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765560) --------------------------------------------------------  // acclient.c:891902
void __cdecl _E119_81()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765590) --------------------------------------------------------  // acclient.c:891915
void __cdecl _E122_84()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007655C0) --------------------------------------------------------  // acclient.c:891928
void __cdecl _E125_56()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007655F0) --------------------------------------------------------  // acclient.c:891941
void __cdecl _E128_55()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765620) --------------------------------------------------------  // acclient.c:891954
void __cdecl _E131_47()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_7;
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

