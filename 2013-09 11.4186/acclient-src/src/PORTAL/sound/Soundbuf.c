/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Soundbuf
   Object     : PORTAL\sound\Soundbuf.obj
   Functions  : 38
   Addresses  : 00552670 - 007726D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00552670) --------------------------------------------------------  // acclient.c:385645
void __thiscall SoundBuf::ReleaseAll(SoundBuf *this)
{
  SoundBuf *v1; // esi@1
  IDirectSoundBuffer *v2; // eax@3
  IDirectSound3DBuffer *v3; // eax@5

  v1 = this;
  if ( this->m_filename )
  {
    operator delete[](this->m_filename);
    v1->m_filename = 0;
  }
  v2 = v1->m_pBuf;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v1->m_pBuf);
    v1->m_pBuf = 0;
  }
  v3 = v1->m_p3DBuf;
  if ( v3 )
  {
    v3->vfptr->Release((IUnknown *)v1->m_p3DBuf);
    v1->m_p3DBuf = 0;
  }
  v1->m_pBuf = 0;
  v1->m_p3DBuf = 0;
  v1->m_filename = 0;
  v1->m_tagval = 0;
  v1->m_bufsize = 0;
  v1->m_3D = 0;
  v1->m_gid.id = stru_86F724.id;
}

//----- (005526D0) --------------------------------------------------------  // acclient.c:385679
int __thiscall SoundBuf::CopyWaveToBuffer(SoundBuf *this, WaveFile *pWave)
{
  SoundBuf *v2; // ebx@1
  IDirectSoundBuffer *v3; // eax@1
  char *v4; // ebp@3
  unsigned int v5; // ecx@4
  int v6; // eax@4
  char *v7; // eax@5
  char *v8; // edi@10
  unsigned int v9; // esi@11
  char v10; // al@11
  unsigned int v11; // ecx@11
  int result; // eax@12
  unsigned int bytesSoundBlock1; // [sp+20h] [bp-64h]@1
  char *pSoundBlock1; // [sp+24h] [bp-60h]@1
  char *pSoundBlock2; // [sp+28h] [bp-5Ch]@1
  unsigned int bytesSoundBlock2; // [sp+2Ch] [bp-58h]@1
  tACMSTREAMHEADER ach; // [sp+30h] [bp-54h]@5

  v2 = this;
  v3 = this->m_pBuf;
  pSoundBlock1 = 0;
  pSoundBlock2 = 0;
  bytesSoundBlock1 = 0;
  bytesSoundBlock2 = 0;
  if ( v3
    && pWave
    && (v4 = pWave->m_pData,
        !((int (__stdcall *)(IDirectSoundBuffer *, _DWORD, unsigned int, char **, unsigned int *, char **, unsigned int *, _DWORD))v3->vfptr[3].Release)(
           v3,
           0,
           this->m_bufsize,
           &pSoundBlock1,
           &bytesSoundBlock1,
           &pSoundBlock2,
           &bytesSoundBlock2,
           0)) )
  {
    v5 = v2->m_bufsize;
    v6 = bytesSoundBlock1 < v5;
    if ( phas )
    {
      v7 = pWave->m_pData;
      ach.cbSrcLength = pWave->m_nDataSize;
      ach.pbSrc = v7;
      ach.cbStruct = 84;
      ach.fdwStatus = 0;
      ach.pbDst = pSoundBlock1;
      ach.cbDstLength = bytesSoundBlock1;
      if ( !acmStreamPrepareHeader(phas, &ach, 0) )
      {
        acmStreamConvert(phas, &ach, 4u);
        ach.cbSrcLength = pWave->m_nDataSize;
        ach.cbDstLength = bytesSoundBlock1;
        acmStreamUnprepareHeader(phas, &ach, 0);
      }
    }
    else
    {
      if ( bytesSoundBlock1 < v5 )
        v5 = bytesSoundBlock1;
      qmemcpy(pSoundBlock1, v4, v5);
      if ( v6 )
      {
        v8 = pSoundBlock2;
        if ( pSoundBlock2 )
        {
          v9 = (unsigned int)&v4[bytesSoundBlock1];
          v10 = LOBYTE(v2->m_bufsize) - bytesSoundBlock1;
          v11 = (v2->m_bufsize - bytesSoundBlock1) >> 2;
          qmemcpy(pSoundBlock2, &v4[bytesSoundBlock1], 4 * v11);
          qmemcpy(&v8[4 * v11], (const void *)(v9 + 4 * v11), v10 & 3);
        }
      }
    }
    ((void (__stdcall *)(IDirectSoundBuffer *, char *, unsigned int, char *, unsigned int))v2->m_pBuf->vfptr[6].AddRef)(
      v2->m_pBuf,
      pSoundBlock1,
      bytesSoundBlock1,
      pSoundBlock2,
      bytesSoundBlock2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00552830) --------------------------------------------------------  // acclient.c:385770
IDirectSoundBuffer *__thiscall SoundBuf::Stop(SoundBuf *this)
{
  IDirectSoundBuffer *result; // eax@1

  result = this->m_pBuf;
  if ( result )
    result = (IDirectSoundBuffer *)(((int (__stdcall *)(IDirectSoundBuffer *))result->vfptr[6].QueryInterface)(result) == 0);
  return result;
}

//----- (00552850) --------------------------------------------------------  // acclient.c:385781
unsigned int __thiscall SoundBuf::GetStatus(SoundBuf *this)
{
  IDirectSoundBuffer *v1; // eax@1
  unsigned int result; // eax@2
  unsigned int stat; // [sp+8h] [bp-4h]@1

  stat = (unsigned int)this;
  v1 = this->m_pBuf;
  if ( !v1 || ((int (__stdcall *)(IDirectSoundBuffer *, unsigned int *))v1->vfptr[3].QueryInterface)(v1, &stat) )
    result = -1;
  else
    result = stat;
  return result;
}

//----- (00552880) --------------------------------------------------------  // acclient.c:385797
int __cdecl DBWave::Get(IDClass<_tagDataID,32,0> did)
{
  QualifiedDataID *v1; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, did, 0xFu);
  return DBObj::Get(v1);
}

//----- (005528B0) --------------------------------------------------------  // acclient.c:385807
void __thiscall SoundBuf::SoundBuf(SoundBuf *this, SoundBuf *sb)
{
  SoundBuf *v2; // esi@1
  char *v3; // ebx@1
  char *v4; // ebp@1
  CDirSound *v5; // eax@1
  IDirectSound *v6; // eax@2
  int v7; // edx@4

  v2 = this;
  v3 = (char *)&this->m_pBuf;
  v4 = (char *)&this->m_p3DBuf;
  this->m_pBuf = 0;
  this->m_p3DBuf = 0;
  this->m_filename = 0;
  this->m_tagval = 0;
  this->m_bufsize = 0;
  this->m_3D = 0;
  this->m_gid.id = stru_86F724.id;
  v5 = GetDirectSound();
  v2->m_pCDirSound = v5;
  if ( v5 )
  {
    v6 = v5->m_pDirectSoundObj;
    if ( v6 )
    {
      if ( !((int (__stdcall *)(IDirectSound *, IDirectSoundBuffer *, char *))v6->vfptr[1].Release)(v6, sb->m_pBuf, v3) )
      {
        v2->m_bufsize = sb->m_bufsize;
        v2->m_tagval = sb->m_tagval;
        v7 = sb->m_3D;
        v2->m_3D = v7;
        v2->m_gid.id = sb->m_gid.id;
        if ( v7 )
          (***(void (__stdcall ****)(_DWORD, _DWORD, _DWORD))v3)(*(_DWORD *)v3, &IID_IDirectSound3DBuffer, v4);
      }
    }
  }
}

//----- (00552930) --------------------------------------------------------  // acclient.c:385848
int __thiscall SoundBuf::Create(SoundBuf *this, int use_static)
{
  SoundBuf *v2; // ebx@1
  unsigned int v4; // ebp@5
  unsigned int v5; // eax@10
  QualifiedDataID *v6; // eax@11
  int v7; // eax@11
  int v8; // esi@12
  WaveFile *v9; // eax@14
  int v10; // eax@15
  HMMIO__ *v11; // edi@16
  int v12; // eax@21
  int v13; // edi@21
  tWAVEFORMATEX *v14; // ST08_4@22
  IDirectSoundBuffer *v15; // eax@32
  DBWave *dwave; // [sp+1Ch] [bp-4Ch]@9
  int ret; // [sp+20h] [bp-48h]@1
  IDirectSound *pds; // [sp+24h] [bp-44h]@1
  QualifiedDataID v19; // [sp+28h] [bp-40h]@11
  tWAVEFORMATEX dstfmt; // [sp+30h] [bp-38h]@22
  _DSBUFFERDESC dsBufferDesc; // [sp+44h] [bp-24h]@21

  v2 = this;
  ret = 0;
  pds = this->m_pCDirSound->m_pDirectSoundObj;
  if ( !pds )
    return 0;
  if ( this->m_3D && this->m_pCDirSound->m_lpDs3dListener )
  {
    v4 = 65712;
  }
  else
  {
    v4 = 65760;
    this->m_3D = 0;
  }
  if ( use_static )
    v4 |= 2u;
  dwave = 0;
  if ( SoundBuf::useDatabase )
  {
    v5 = this->m_gid.id;
    if ( v5 == stru_86F724.id )
      return ret;
    QualifiedDataID::QualifiedDataID(&v19, (IDClass<_tagDataID,32,0>)v5, 0xFu);
    v7 = DBObj::Get(v6);
    dwave = (DBWave *)v7;
    if ( !v7 )
      return ret;
    v8 = v7 + 56;
  }
  else
  {
    if ( !this->m_filename )
      return ret;
    v9 = (WaveFile *)operator new(0x68u);
    if ( !v9 )
      return ret;
    WaveFile::WaveFile(v9);
    v8 = v10;
    if ( !v10 )
      return ret;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&use_static, v2->m_filename);
    v11 = WaveFile::Open((WaveFile *)v8, (PStringBase<char> *)&use_static);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&use_static);
    if ( !v11 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      return 0;
    }
    if ( !WaveFile::Load((WaveFile *)v8) )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      return 0;
    }
  }
  if ( v8 )
  {
    memset(&dsBufferDesc, 0, sizeof(dsBufferDesc));
    dsBufferDesc.dwFlags = v4;
    dsBufferDesc.dwSize = 36;
    v12 = *(_DWORD *)(v8 + 4);
    v13 = *(_WORD *)v12 != 1;
    if ( *(_WORD *)v12 != 1 )
    {
      dstfmt.wFormatTag = 1;
      dstfmt.nChannels = 1;
      dsBufferDesc.lpwfxFormat = &dstfmt;
      v14 = *(tWAVEFORMATEX **)(v8 + 4);
      dstfmt.wBitsPerSample = 16;
      dstfmt.nSamplesPerSec = 11025;
      dstfmt.nBlockAlign = 2;
      dstfmt.nAvgBytesPerSec = 22050;
      dstfmt.cbSize = 0;
      if ( acmStreamOpen(&phas, 0, v14, &dstfmt, 0, 0, 0, 4u) )
      {
LABEL_35:
        if ( dwave )
          ((void (*)(void))dwave->vfptr->Release)();
        return ret;
      }
      if ( acmStreamSize(phas, *(_DWORD *)(v8 + 92), (LPDWORD)&use_static, 0) )
      {
LABEL_29:
        if ( v13 )
        {
          acmStreamClose(phas, 0);
          phas = 0;
        }
        if ( v2->m_3D )
        {
          v15 = v2->m_pBuf;
          if ( v15 )
          {
            if ( v15->vfptr->QueryInterface((IUnknown *)v15, &IID_IDirectSound3DBuffer, (void **)&v2->m_p3DBuf) )
              v2->m_3D = 0;
          }
        }
        goto LABEL_35;
      }
      dsBufferDesc.dwBufferBytes = use_static;
    }
    else
    {
      dsBufferDesc.lpwfxFormat = *(tWAVEFORMATEX **)(v8 + 4);
      dsBufferDesc.dwBufferBytes = *(_DWORD *)(v8 + 92);
    }
    if ( !((int (__stdcall *)(IDirectSound *, _DSBUFFERDESC *, int, _DWORD))pds->vfptr[1].QueryInterface)(
            pds,
            &dsBufferDesc,
            &v2->m_pBuf,
            0) )
    {
      v2->m_bufsize = dsBufferDesc.dwBufferBytes;
      if ( SoundBuf::CopyWaveToBuffer(v2, (WaveFile *)v8) )
        ret = 1;
    }
    goto LABEL_29;
  }
  return ret;
}
// 81F220: using guessed type int SoundBuf::useDatabase;

//----- (00552B90) --------------------------------------------------------  // acclient.c:385992
int __thiscall SoundBuf::Restore(SoundBuf *this)
{
  SoundBuf *v1; // edi@1
  int result; // eax@1
  int v3; // ebp@3
  int v4; // eax@5
  int v5; // esi@6
  int v6; // ecx@8
  int v7; // ebx@8
  IDirectSoundBuffer *v8; // eax@9
  WaveFile *v9; // eax@20
  int v10; // eax@21
  unsigned int dwSize; // [sp+14h] [bp-1Ch]@9
  int ret; // [sp+18h] [bp-18h]@1
  tWAVEFORMATEX wfmx; // [sp+1Ch] [bp-14h]@9

  v1 = this;
  result = (int)this->m_pBuf;
  ret = 0;
  if ( result )
  {
    if ( (*(int (__stdcall **)(int))(*(_DWORD *)result + 80))(result) )
      return ret;
    v3 = 0;
    if ( SoundBuf::useDatabase )
    {
      if ( v1->m_gid.id != stru_86F724.id )
      {
        v4 = DBWave::Get(v1->m_gid);
        v3 = v4;
        if ( v4 )
        {
          v5 = v4 + 56;
          goto LABEL_7;
        }
      }
      return ret;
    }
    if ( !v1->m_filename )
      return ret;
    v9 = (WaveFile *)operator new(0x68u);
    if ( !v9 )
      return ret;
    WaveFile::WaveFile(v9);
    v5 = v10;
    if ( !v10 )
      return ret;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&dwSize, v1->m_filename);
    WaveFile::Open((WaveFile *)v5, (PStringBase<char> *)&dwSize);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&dwSize);
    if ( WaveFile::Load((WaveFile *)v5) )
    {
LABEL_7:
      if ( v5 )
      {
        v6 = *(_DWORD *)(v5 + 4);
        v7 = *(_WORD *)v6 != 1;
        if ( *(_WORD *)v6 == 1
          || (v8 = v1->m_pBuf,
              dwSize = 0,
              !((int (__stdcall *)(IDirectSoundBuffer *, tWAVEFORMATEX *, signed int, unsigned int *))v8->vfptr[1].Release)(
                 v8,
                 &wfmx,
                 18,
                 &dwSize))
          && dwSize <= 0x12
          && !acmStreamOpen(&phas, 0, *(LPWAVEFORMATEX *)(v5 + 4), &wfmx, 0, 0, 0, 0) )
        {
          if ( SoundBuf::CopyWaveToBuffer(v1, (WaveFile *)v5) )
            ret = 1;
          if ( v7 )
          {
            acmStreamClose(phas, 0);
            phas = 0;
          }
        }
        if ( v3 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
      }
      return ret;
    }
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    result = ret;
  }
  return result;
}
// 81F220: using guessed type int SoundBuf::useDatabase;

//----- (00552D00) --------------------------------------------------------  // acclient.c:386081
void __thiscall SoundBuf::SoundBuf(SoundBuf *this, IDClass<_tagDataID,32,0> gid, int tagval, int use_static, int use_3D)
{
  SoundBuf *v5; // esi@1
  CDirSound *v6; // eax@1

  v5 = this;
  this->m_pBuf = 0;
  this->m_p3DBuf = 0;
  this->m_filename = 0;
  this->m_bufsize = 0;
  this->m_tagval = tagval;
  this->m_3D = use_3D;
  this->m_gid.id = gid.id;
  v6 = GetDirectSound();
  v5->m_pCDirSound = v6;
  if ( v6 )
    SoundBuf::Create(v5, use_static);
}

//----- (00552D50) --------------------------------------------------------  // acclient.c:386101
IDirectSoundBuffer *__thiscall SoundBuf::Play(SoundBuf *this, int pan, int vol)
{
  int v3; // eax@1
  SoundBuf *v4; // esi@1
  IDirectSoundBuffer *v5; // ecx@6
  int v6; // ecx@9
  IDirectSoundBuffer *v7; // eax@11
  IDirectSoundBuffer *result; // eax@13
  signed int v9; // edi@13
  int v10; // eax@15

  v3 = pan;
  v4 = this;
  if ( pan >= -15 )
  {
    if ( pan <= 15 )
    {
      if ( !pan )
        goto LABEL_9;
    }
    else
    {
      v3 = 15;
    }
  }
  else
  {
    v3 = -15;
  }
  v5 = this->m_pBuf;
  if ( v5 && !v4->m_3D )
    ((void (__stdcall *)(IDirectSoundBuffer *, int))v5->vfptr[5].AddRef)(v5, 100 * v3);
LABEL_9:
  v6 = vol;
  if ( vol < SoundManager::VOL_MIN )
    v6 = SoundManager::VOL_MIN;
  v7 = v4->m_pBuf;
  if ( v7 )
    ((void (__stdcall *)(IDirectSoundBuffer *, int))v7->vfptr[5].QueryInterface)(v7, 100 * v6);
  result = v4->m_pBuf;
  v9 = 0;
  if ( result )
  {
    if ( !((int (__stdcall *)(int, _DWORD))result->vfptr[4].AddRef)(result, 0) )
    {
      v10 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v4->m_pBuf->vfptr[4].QueryInterface)(
              v4->m_pBuf,
              0,
              0,
              0);
      if ( v10 != -2005401450 )
        goto LABEL_18;
      if ( SoundBuf::Restore(v4) )
      {
        v10 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v4->m_pBuf->vfptr[4].QueryInterface)(
                v4->m_pBuf,
                0,
                0,
                0);
LABEL_18:
        if ( !v10 )
          v9 = 1;
        goto LABEL_20;
      }
    }
LABEL_20:
    result = (IDirectSoundBuffer *)v9;
  }
  return result;
}
// 81F060: using guessed type int SoundManager::VOL_MIN;

//----- (00706C30) --------------------------------------------------------  // acclient.c:794023
int sub_706C30()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_19, "Sound.SoundDisabled");
  return atexit(_E74_76);
}

//----- (00706C50) --------------------------------------------------------  // acclient.c:794030
int _E76_62()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_19, "Sound.SoundVolume");
  return atexit(_E77_90);
}

//----- (00706C70) --------------------------------------------------------  // acclient.c:794037
int _E79_56()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_19, "Sound.AmbientSoundDisabled");
  return atexit(_E80_55);
}

//----- (00706C90) --------------------------------------------------------  // acclient.c:794044
int _E82_37()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_19, "Sound.AmbientSoundVolume");
  return atexit(_E83_35);
}

//----- (00706CB0) --------------------------------------------------------  // acclient.c:794051
int _E85_26()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_19, "Sound.InterfaceSoundDisabled");
  return atexit(_E86_23);
}

//----- (00706CD0) --------------------------------------------------------  // acclient.c:794058
int _E88_20()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_19, "Sound.InterfaceSoundVolume");
  return atexit(_E89_33);
}

//----- (00706CF0) --------------------------------------------------------  // acclient.c:794065
int sub_706CF0()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_19, "Sound.SoundFeatures");
  return atexit(_E92_38);
}

//----- (00706D10) --------------------------------------------------------  // acclient.c:794072
int _E94_26()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_19, "Sound.PlaySoundOnlyWhenActive");
  return atexit(sub_7726A0);
}

//----- (00706D30) --------------------------------------------------------  // acclient.c:794079
int sub_706D30()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_19, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_86F720, "Mono");
  return atexit(sub_7726D0);
}

//----- (00706D60) --------------------------------------------------------  // acclient.c:794087
int sub_706D60()
{
  return atexit(nullsub_1250);
}

//----- (00706D70) --------------------------------------------------------  // acclient.c:794093
int sub_706D70()
{
  return atexit(nullsub_1251);
}

//----- (00706D80) --------------------------------------------------------  // acclient.c:794099
int sub_706D80()
{
  return atexit(_E107_92);
}

//----- (00706D90) --------------------------------------------------------  // acclient.c:794105
void _E125_10()
{
  LODWORD(dword_86F728) = 1053364187;
}

//----- (00706DA0) --------------------------------------------------------  // acclient.c:794111
void _E127_52()
{
  flt_86F72C = 1000.0 + 1.0;
}

//----- (00706DC0) --------------------------------------------------------  // acclient.c:794117
void _E129_41()
{
  flt_86F730 = 24.0 * 8.0;
}

//----- (00706DE0) --------------------------------------------------------  // acclient.c:794123
void _E131_7()
{
  flt_86F734 = 24.0 * 0.5;
}

//----- (00706E00) --------------------------------------------------------  // acclient.c:794129
void _E133_40()
{
  VOL_MIN_DIST_SQ_16 = 5.0 * 5.0;
}

//----- (00706E20) --------------------------------------------------------  // acclient.c:794135
void _E135_48()
{
  INV_LOG_OF_2_16 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (00706E40) --------------------------------------------------------  // acclient.c:794141
int sub_706E40()
{
  return atexit(nullsub_1249);
}

//----- (00772550) --------------------------------------------------------  // acclient.c:906238
void __cdecl _E74_76()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772580) --------------------------------------------------------  // acclient.c:906251
void __cdecl _E77_90()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007725B0) --------------------------------------------------------  // acclient.c:906264
void __cdecl _E80_55()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007725E0) --------------------------------------------------------  // acclient.c:906277
void __cdecl _E83_35()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772610) --------------------------------------------------------  // acclient.c:906290
void __cdecl _E86_23()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772640) --------------------------------------------------------  // acclient.c:906303
void __cdecl _E89_33()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772670) --------------------------------------------------------  // acclient.c:906316
void __cdecl _E92_38()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007726A0) --------------------------------------------------------  // acclient.c:906329
void __cdecl sub_7726A0()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007726D0) --------------------------------------------------------  // acclient.c:906342
void __cdecl sub_7726D0()
{
  IDClass<_tagDataID,32,0> *v0; // edi@1
  signed int v1; // ebp@1
  unsigned int v2; // esi@2
  int v3; // esi@2

  v0 = &stru_86F724;
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

