/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WaveFile
   Object     : PORTAL\sound\WaveFile.obj
   Functions  : 8
   Addresses  : 00553840 - 00553CD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00553840) --------------------------------------------------------  // acclient.c:386760
int __thiscall WaveFile::Cue(WaveFile *this)
{
  WaveFile *v1; // esi@1
  MMRESULT v2; // eax@2

  v1 = this;
  if ( mmioSeek(this->m_hmmio, this->m_mmckiRiff.dwDataOffset + 4, 0) == -1 )
  {
    v1->m_mmr = 263;
  }
  else
  {
    v1->m_mmckiData.ckid = 1635017060;
    v2 = mmioDescend(v1->m_hmmio, &v1->m_mmckiData, &v1->m_mmckiRiff, 0x10u);
    v1->m_mmr = v2;
    if ( !v2 )
    {
      v1->m_nBytesPlayed = 0;
      return 1;
    }
  }
  return 0;
}

//----- (005538A0) --------------------------------------------------------  // acclient.c:386785
unsigned int __thiscall WaveFile::Read(WaveFile *this, char *pbDest, unsigned int cbSize)
{
  WaveFile *v3; // esi@1
  MMRESULT v4; // eax@1
  unsigned int v5; // eax@2
  unsigned int v6; // ebx@2
  unsigned int v7; // edi@4
  char *v8; // ebp@5
  char *v9; // eax@5
  MMRESULT v10; // eax@7
  char v11; // cl@9
  MMRESULT v12; // eax@10
  _MMIOINFO mmioinfo; // [sp+10h] [bp-48h]@1

  v3 = this;
  v4 = mmioGetInfo(this->m_hmmio, &mmioinfo, 0);
  v3->m_mmr = v4;
  if ( v4 )
    return 0;
  v5 = v3->m_mmckiData.cksize;
  v6 = cbSize;
  if ( cbSize > v5 )
    v6 = v3->m_mmckiData.cksize;
  v7 = 0;
  v3->m_mmckiData.cksize = v5 - v6;
  if ( !v6 )
  {
LABEL_10:
    v12 = mmioSetInfo(v3->m_hmmio, &mmioinfo, 0);
    v3->m_mmr = v12;
    if ( !v12 )
    {
      v3->m_nBytesPlayed += v6;
      return v6;
    }
    return 0;
  }
  v8 = mmioinfo.pchEndRead;
  v9 = mmioinfo.pchNext;
  while ( 1 )
  {
    if ( v9 == v8 )
    {
      v10 = mmioAdvance(v3->m_hmmio, &mmioinfo, 0);
      v3->m_mmr = v10;
      if ( v10 )
        return 0;
      v9 = mmioinfo.pchNext;
      v8 = mmioinfo.pchEndRead;
      if ( mmioinfo.pchNext == mmioinfo.pchEndRead )
        break;
    }
    v11 = *v9++;
    pbDest[v7++] = v11;
    mmioinfo.pchNext = v9;
    if ( v7 >= v6 )
      goto LABEL_10;
  }
  v3->m_mmr = 261;
  return 0;
}

//----- (00553970) --------------------------------------------------------  // acclient.c:386848
unsigned int __thiscall WaveFile::Load(WaveFile *this)
{
  WaveFile *v1; // esi@1
  unsigned int v2; // ebx@1
  unsigned int result; // eax@2
  char *v4; // eax@5
  unsigned int v5; // edi@6

  v1 = this;
  v2 = 0;
  if ( this->m_nDataSize )
  {
    if ( this->m_pData )
      operator delete[](this->m_pData);
    v4 = (char *)operator new[](v1->m_nDataSize);
    v1->m_pData = v4;
    if ( v4 )
    {
      v5 = v1->m_nDataSize;
      if ( WaveFile::Read(v1, v4, v1->m_nDataSize) == v5 )
        v2 = v5;
    }
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005539C0) --------------------------------------------------------  // acclient.c:386880
void __thiscall WaveFile::WaveFile(WaveFile *this)
{
  char *v1; // edx@1
  char *v2; // edx@1
  char *v3; // edx@1

  this->vfptr = (WaveFileVtbl *)&WaveFile::vftable;
  this->m_pData = 0;
  this->m_pwfmt = 0;
  this->m_hmmio = 0;
  this->m_nBlockAlign = 0;
  this->m_nAvgDataRate = 0;
  this->m_nDataSize = 0;
  this->m_nFormatSize = 0;
  this->m_nBytesPlayed = 0;
  this->m_nDuration = 0;
  v1 = (char *)&this->m_mmckiRiff;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  *((_DWORD *)v1 + 3) = 0;
  *((_DWORD *)v1 + 4) = 0;
  v2 = (char *)&this->m_mmckiFmt;
  *(_DWORD *)v2 = 0;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 4) = 0;
  v3 = (char *)&this->m_mmckiData;
  *(_DWORD *)v3 = 0;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 4) = 0;
}
// 7CB320: using guessed type int (__thiscall *WaveFile::vftable)(void *, char);

//----- (00553A20) --------------------------------------------------------  // acclient.c:386918
void __thiscall WaveFile::ReleaseAll(WaveFile *this)
{
  WaveFile *v1; // esi@1
  HMMIO__ *v2; // eax@1
  int v3; // ecx@7
  int v4; // eax@7
  int v5; // esi@7

  v1 = this;
  v2 = this->m_hmmio;
  if ( v2 )
  {
    mmioClose(v2, 0);
    v1->m_hmmio = 0;
  }
  if ( v1->m_pData )
  {
    operator delete[](v1->m_pData);
    v1->m_pData = 0;
  }
  if ( v1->m_pwfmt )
  {
    operator delete[](v1->m_pwfmt);
    v1->m_pwfmt = 0;
  }
  v1->m_pData = 0;
  v1->m_pwfmt = 0;
  v1->m_hmmio = 0;
  v1->m_nBlockAlign = 0;
  v1->m_nAvgDataRate = 0;
  v1->m_nDataSize = 0;
  v1->m_nFormatSize = 0;
  v1->m_nBytesPlayed = 0;
  v1->m_nDuration = 0;
  v3 = (int)&v1->m_mmckiRiff;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 16) = 0;
  v4 = (int)&v1->m_mmckiFmt;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  v5 = (int)&v1->m_mmckiData;
  *(_DWORD *)(v4 + 16) = 0;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 16) = 0;
}

//----- (00553AC0) --------------------------------------------------------  // acclient.c:386973
HMMIO__ *__thiscall WaveFile::Open(WaveFile *this, PStringBase<char> *filename)
{
  PSRefBufferCharData<char> *v2; // eax@1
  WaveFile *v3; // esi@1
  char *v4; // edi@1
  HMMIO__ *result; // eax@1
  MMRESULT v6; // eax@3
  HMMIO v7; // ST00_4@6
  MMRESULT v8; // eax@6
  unsigned int v9; // eax@10
  void *v10; // eax@10
  LONG v11; // eax@12
  bool v12; // zf@12
  tWAVEFORMATEX *v13; // eax@14
  HMMIO v14; // ST04_4@14
  MMRESULT v15; // eax@14
  WaveFile *v16; // ecx@14
  unsigned int v17; // eax@15
  int cbExtra; // [sp+Ch] [bp-14h]@1
  pcmwaveformat_tag pcmwf; // [sp+10h] [bp-10h]@7

  v2 = filename->m_charbuffer;
  cbExtra = 0;
  v3 = this;
  v4 = (char *)operator new[](*(_DWORD *)&v2[-1].m_data[12]);
  _strncpy(v4, filename->m_charbuffer->m_data, *(_DWORD *)&filename->m_charbuffer[-1].m_data[12]);
  v3->m_hmmio = mmioOpenA(v4, 0, 0x10000u);
  operator delete[](v4);
  result = v3->m_hmmio;
  if ( !result )
  {
    v3->m_mmr = 259;
    return result;
  }
  v6 = mmioDescend(result, &v3->m_mmckiRiff, 0, 0);
  v3->m_mmr = v6;
  if ( v6 )
    goto LABEL_18;
  if ( v3->m_mmckiRiff.ckid != 1179011410 || v3->m_mmckiRiff.fccType != 1163280727 )
  {
    v3->m_mmr = 272;
    goto LABEL_18;
  }
  v7 = v3->m_hmmio;
  v3->m_mmckiFmt.ckid = 544501094;
  v8 = mmioDescend(v7, &v3->m_mmckiFmt, &v3->m_mmckiRiff, 0x10u);
  v3->m_mmr = v8;
  if ( v8 )
  {
LABEL_18:
    v16 = v3;
    goto LABEL_19;
  }
  if ( mmioRead(v3->m_hmmio, (HPSTR)&pcmwf, 16) != 16
    || pcmwf.wf.wFormatTag != 1 && mmioRead(v3->m_hmmio, (HPSTR)&cbExtra, 2) != 2 )
    goto LABEL_13;
  v9 = (unsigned __int16)cbExtra + 18;
  v3->m_nFormatSize = v9;
  v10 = operator new[](v9);
  v3->m_pwfmt = (tWAVEFORMATEX *)v10;
  if ( !v10 )
  {
    v3->m_mmr = 258;
    WaveFile::ReleaseAll(v3);
    return 0;
  }
  *(_OWORD *)v10 = pcmwf;
  v3->m_pwfmt->cbSize = cbExtra;
  if ( (_WORD)cbExtra )
  {
    v11 = mmioRead(v3->m_hmmio, (HPSTR)&v3->m_pwfmt[1], (unsigned __int16)cbExtra);
    v12 = v11 == (unsigned __int16)cbExtra;
    v3->m_mmr = v11;
    if ( !v12 )
    {
LABEL_13:
      v3->m_mmr = 261;
      WaveFile::ReleaseAll(v3);
      return 0;
    }
  }
  v13 = v3->m_pwfmt;
  v3->m_nBlockAlign = v13->nBlockAlign;
  v14 = v3->m_hmmio;
  v3->m_nAvgDataRate = v13->nAvgBytesPerSec;
  v15 = mmioAscend(v14, &v3->m_mmckiFmt, 0);
  v3->m_mmr = v15;
  v16 = v3;
  if ( !v15 )
  {
    WaveFile::Cue(v3);
    v17 = v3->m_mmckiData.cksize;
    v3->m_nDataSize = v17;
    v3->m_nDuration = 1000 * v17 / v3->m_nAvgDataRate;
    return (HMMIO__ *)1;
  }
LABEL_19:
  WaveFile::ReleaseAll(v16);
  return 0;
}

//----- (00553CC0) --------------------------------------------------------  // acclient.c:387075
void __thiscall WaveFile::~WaveFile(WaveFile *this)
{
  this->vfptr = (WaveFileVtbl *)&WaveFile::vftable;
  WaveFile::ReleaseAll(this);
}
// 7CB320: using guessed type int (__thiscall *WaveFile::vftable)(void *, char);

//----- (00553CD0) --------------------------------------------------------  // acclient.c:387083
WaveFile *__thiscall WaveFile::scalar_deleting_destructor(WaveFile *this, unsigned int a2)
{
  WaveFile *v2; // esi@1

  v2 = this;
  this->vfptr = (WaveFileVtbl *)&WaveFile::vftable;
  WaveFile::ReleaseAll(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CB320: using guessed type int (__thiscall *WaveFile::vftable)(void *, char);

