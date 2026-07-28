/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSceneType
   Object     : PORTAL\cregion\CSceneType.obj
   Functions  : 33
   Addresses  : 005031C0 - 00765840 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005031C0) --------------------------------------------------------  // acclient.c:304403
unsigned int __thiscall CSceneType::pack_size(CSceneType *this)
{
  return 4 * this->scenes.m_num + 8;
}

//----- (005031D0) --------------------------------------------------------  // acclient.c:304409
unsigned int __thiscall CSceneType::pack(CSceneType *this, void **addr, unsigned int *size)
{
  void *v3; // edi@1
  unsigned int v4; // esi@3
  unsigned int v5; // edx@7

  v3 = *addr;
  if ( *size >= 4 )
  {
    *(_DWORD *)v3 = this->scenes.m_num;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v4 = 0;
  if ( this->scenes.m_num )
  {
    do
    {
      if ( *size >= 4 )
      {
        *(_DWORD *)*addr = this->scenes.m_data[v4].id;
        *addr = (char *)*addr + 4;
        *size -= 4;
      }
      ++v4;
    }
    while ( v4 < this->scenes.m_num );
  }
  v5 = (_BYTE *)*addr - (_BYTE *)v3 + *size;
  *size = v5;
  return v5;
}

//----- (00503230) --------------------------------------------------------  // acclient.c:304443
void __thiscall CSceneType::CSceneType(CSceneType *this)
{
  CSceneType *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->scene_name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->scenes.m_data = 0;
  v1->scenes.m_sizeAndDeallocate = 0;
  v1->scenes.m_num = 0;
  v1->sound_table_desc = 0;
}

//----- (00503260) --------------------------------------------------------  // acclient.c:304459
void __thiscall CSceneType::~CSceneType(CSceneType *this)
{
  CSceneType *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@2
  int v4; // esi@4

  v1 = this;
  v2 = (char *)&this->scenes;
  SmartArray<IDClass<_tagDataID,32,0>,1>::Reset(&this->scenes);
  if ( (*((_DWORD *)v2 + 1) & 0x80000000) == 0x80000000 )
  {
    v3 = *(_DWORD *)v2;
    if ( v3 )
      operator delete[]((void *)(v3 - 4));
  }
  v4 = (int)&v1->scene_name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (005032C0) --------------------------------------------------------  // acclient.c:304484
int __thiscall CSceneType::unpack(CSceneType *this, void **addr, unsigned int *size)
{
  unsigned int v3; // esi@2
  unsigned int *v4; // ebx@6
  unsigned int v5; // ebp@6
  unsigned int *v6; // edx@8
  int v7; // eax@9
  unsigned int v8; // edx@10
  int v9; // ST18_4@15
  CSceneType *v16; // [sp+4h] [bp-8h]@1

  v16 = this;
  if ( *size < 4 )
  {
    v3 = (unsigned int)size;
  }
  else
  {
    v3 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  SmartArray<IDClass<_tagDataID,32,0>,1>::Reset(&this->scenes);
  if ( v3 )
  {
    SmartArray<IDClass<_tagDataID,32,0>,1>::grow(&v16->scenes, v3);
    if ( v3 )
    {
      v4 = size;
      v5 = v3;
      do
      {
        if ( *size >= 4 )
        {
          v6 = *(unsigned int **)*addr;
          *addr = (char *)*addr + 4;
          *size -= 4;
          v4 = v6;
        }
        v7 = v16->scenes.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v16->scenes.m_num < v7 )
          goto LABEL_23;
        v8 = v7 + 1;
        if ( (unsigned int)(v7 + 1) > 8 )
        {
          if ( v8 <= 0x4000 )
          {
            v9 = v7 + 1;
            __asm { bsr     this, [esp+18h+var_4] }
            if ( v8 > 1 << _EAX )
              v8 = 2 * (1 << _EAX);
          }
          else if ( v8 & 0x3FFF )
          {
            v8 += 0x4000 - (v8 & 0x3FFF);
          }
        }
        else
        {
          v8 = 8;
        }
        if ( SmartArray<IDClass<_tagDataID,32,0>,1>::grow(&v16->scenes, v8) )
LABEL_23:
          v16->scenes.m_data[v16->scenes.m_num++].id = (unsigned int)v4;
        --v5;
      }
      while ( v5 );
    }
  }
  return 1;
}

//----- (006F9E70) --------------------------------------------------------  // acclient.c:782595
int _E73_85()
{
  return atexit(_E74_64);
}

//----- (006F9E80) --------------------------------------------------------  // acclient.c:782601
int _E76_50()
{
  return atexit(_E77_78);
}

//----- (006F9E90) --------------------------------------------------------  // acclient.c:782607
int _E79_43()
{
  return atexit(_E80_42);
}

//----- (006F9EA0) --------------------------------------------------------  // acclient.c:782613
void _E98_5()
{
  LODWORD(dword_8416C4) = 1053364187;
}

//----- (006F9EB0) --------------------------------------------------------  // acclient.c:782619
void sub_6F9EB0()
{
  flt_8416C8 = 1000.0 + 1.0;
}

//----- (006F9ED0) --------------------------------------------------------  // acclient.c:782625
void _E102_13()
{
  flt_8416CC = 24.0 * 8.0;
}

//----- (006F9EF0) --------------------------------------------------------  // acclient.c:782631
void _E104_7()
{
  flt_8416D0 = 24.0 * 0.5;
}

//----- (006F9F10) --------------------------------------------------------  // acclient.c:782637
int _E106_90()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_11, "Sound.SoundDisabled");
  return atexit(_E107_85);
}

//----- (006F9F30) --------------------------------------------------------  // acclient.c:782644
int _E109_55()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_11, "Sound.SoundVolume");
  return atexit(sub_7656F0);
}

//----- (006F9F50) --------------------------------------------------------  // acclient.c:782651
int _E112_82()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_11, "Sound.AmbientSoundDisabled");
  return atexit(_E113_60);
}

//----- (006F9F70) --------------------------------------------------------  // acclient.c:782658
int _E115_61()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_11, "Sound.AmbientSoundVolume");
  return atexit(_E116_53);
}

//----- (006F9F90) --------------------------------------------------------  // acclient.c:782665
int _E118_62()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_11, "Sound.InterfaceSoundDisabled");
  return atexit(_E119_82);
}

//----- (006F9FB0) --------------------------------------------------------  // acclient.c:782672
int _E121_56()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_11, "Sound.InterfaceSoundVolume");
  return atexit(_E122_85);
}

//----- (006F9FD0) --------------------------------------------------------  // acclient.c:782679
int _E124_58()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_11, "Sound.SoundFeatures");
  return atexit(_E125_57);
}

//----- (006F9FF0) --------------------------------------------------------  // acclient.c:782686
int _E127_47()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_11, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E128_56);
}

//----- (006FA010) --------------------------------------------------------  // acclient.c:782693
int _E130_45()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_11, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_8416F8, "Mono");
  return atexit(_E131_48);
}

//----- (006FA040) --------------------------------------------------------  // acclient.c:782701
void _E133_35()
{
  VOL_MIN_DIST_SQ_8 = 5.0 * 5.0;
}

//----- (006FA060) --------------------------------------------------------  // acclient.c:782707
void _E135_27()
{
  INV_LOG_OF_2_8 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006FA080) --------------------------------------------------------  // acclient.c:782713
int sub_6FA080()
{
  return atexit(nullsub_1060);
}

//----- (007656C0) --------------------------------------------------------  // acclient.c:891979
void __cdecl _E107_85()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007656F0) --------------------------------------------------------  // acclient.c:891992
void __cdecl sub_7656F0()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765720) --------------------------------------------------------  // acclient.c:892005
void __cdecl _E113_60()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765750) --------------------------------------------------------  // acclient.c:892018
void __cdecl _E116_53()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765780) --------------------------------------------------------  // acclient.c:892031
void __cdecl _E119_82()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007657B0) --------------------------------------------------------  // acclient.c:892044
void __cdecl _E122_85()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007657E0) --------------------------------------------------------  // acclient.c:892057
void __cdecl _E125_57()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765810) --------------------------------------------------------  // acclient.c:892070
void __cdecl _E128_56()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00765840) --------------------------------------------------------  // acclient.c:892083
void __cdecl _E131_48()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_8;
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

