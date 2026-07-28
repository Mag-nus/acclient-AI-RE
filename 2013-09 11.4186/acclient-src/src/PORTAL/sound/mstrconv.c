/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : mstrconv
   Object     : PORTAL\sound\mstrconv.obj
   Functions  : 10
   Addresses  : 00553E90 - 00554940 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00553E90) --------------------------------------------------------  // acclient.c:387200
BOOL __cdecl GetInFileData(void *lpDest, unsigned int cbToGet)
{
  unsigned int v2; // ecx@0
  unsigned int cbRead; // [sp+0h] [bp-4h]@1

  cbRead = v2;
  return !ReadFile(hInFile, lpDest, cbToGet, &cbRead, 0) || cbRead != cbToGet;
}

//----- (00553ED0) --------------------------------------------------------  // acclient.c:387210
void __cdecl ConverterCleanup()
{
  HLOCAL v0; // ecx@3
  unsigned int v1; // edi@4
  int v2; // esi@5

  if ( hInFile != (HANDLE)-1 )
  {
    CloseHandle(hInFile);
    hInFile = (HANDLE)-1;
  }
  v0 = hMem;
  if ( hMem )
  {
    v1 = 0;
    if ( dword_86FA90 )
    {
      v2 = 0;
      do
      {
        if ( *(_DWORD *)((char *)v0 + v2 + 12) )
        {
          LocalFree(*(HLOCAL *)((char *)v0 + v2 + 12));
          v0 = hMem;
        }
        ++v1;
        v2 += 40;
      }
      while ( v1 < dword_86FA90 );
    }
    LocalFree(v0);
    hMem = 0;
  }
}
// 86FA90: using guessed type int dword_86FA90;

//----- (00553F40) --------------------------------------------------------  // acclient.c:387247
int __cdecl RefillTrackBuffer(INTRACKSTATE *ptsTrack)
{
  INTRACKSTATE *v1; // esi@1
  unsigned int v2; // ST08_4@3
  HANDLE v3; // ST04_4@3
  DWORD v4; // edi@3
  unsigned int v5; // eax@4
  BOOL v6; // eax@7
  INTRACKSTATE *v7; // ecx@7

  v1 = ptsTrack;
  if ( ptsTrack )
  {
    if ( ptsTrack->dwLeftOnDisk )
    {
      v2 = ptsTrack->foNextReadStart;
      v3 = hInFile;
      ptsTrack->pTrackCurrent = ptsTrack->pTrackStart;
      v4 = SetFilePointer(v3, v2, 0, 0);
      if ( v4 != -1 )
      {
        v5 = v1->dwLeftOnDisk;
        if ( v5 <= 0x400 )
          v1->dwLeftInBuffer = v5;
        else
          v1->dwLeftInBuffer = 1024;
        v6 = ReadFile(hInFile, v1->pTrackStart, v1->dwLeftInBuffer, (LPDWORD)&ptsTrack, 0);
        v7 = ptsTrack;
        v1->dwLeftOnDisk -= (unsigned int)ptsTrack;
        v1->foNextReadStart = (unsigned int)((char *)&v7->fdwTrack + v4);
        v1->dwLeftInBuffer = (unsigned int)v7;
        if ( v6 && v7 )
          return 0;
        v1->dwLeftInBuffer = (unsigned int)v7;
      }
    }
  }
  return 1;
}

//----- (00553FE0) --------------------------------------------------------  // acclient.c:387288
int __usercall AddEventToStreamBuffer@<eax>(TEMPEVENT *pteTemp@<ebp>, _ConvertInfo *lpciInfo@<esi>, int a3@<edi>)
{
  int v3; // ebp@1
  int v4; // ecx@1
  int result; // eax@2
  unsigned int v6; // edx@3
  char *v7; // ebx@10
  int v8; // eax@11
  unsigned __int8 v9; // al@14
  unsigned __int16 v10; // ax@16
  int v11; // eax@16
  int v12; // edx@16
  unsigned int v13; // eax@32
  int v14; // ebx@32
  unsigned __int16 v15; // dx@32

  v3 = *(_DWORD *)(a3 + 72);
  v4 = *(_DWORD *)a3 + v3 + *(_DWORD *)(a3 + 64);
  if ( !v4 )
    return -101;
  v6 = tkCurrentTime;
  if ( !v3 )
    *(_DWORD *)(a3 + 76) = tkCurrentTime;
  if ( v6 - *(_DWORD *)(a3 + 76) > dwBufferTickLength )
  {
    if ( *(_DWORD *)(a3 + 80) )
    {
      *(_DWORD *)(a3 + 80) = 0;
      return -104;
    }
    *(_DWORD *)(a3 + 80) = 1;
  }
  v7 = &lpciInfo->mhBuffer.lpData[-v6];
  tkCurrentTime = (unsigned int)lpciInfo->mhBuffer.lpData;
  if ( bInsertTempo )
  {
    v8 = *(_DWORD *)(a3 + 68) - v3;
    bInsertTempo = 0;
    if ( (unsigned int)v8 < 0xC )
      return -104;
    if ( dwCurrentTempo )
    {
      *(_DWORD *)v4 = 0;
      *(_DWORD *)(v4 + 4) = 0;
      v4 += 192;
      *(_DWORD *)(v4 - 184) = 100 * dwCurrentTempo / dwTempoMultiplier | 0x1000000;
      *(_DWORD *)(a3 + 72) += 12;
    }
  }
  v9 = LOBYTE(lpciInfo->mhBuffer.dwBufferLength);
  if ( v9 >= 0xF0u )
  {
    if ( v9 == -16 || v9 == -9 )
    {
      if ( dwMallocBlocks )
      {
        _free((void *)lpciInfo->mhBuffer.dwUser);
        --dwMallocBlocks;
      }
      result = 0;
    }
    else if ( BYTE1(lpciInfo->mhBuffer.dwBufferLength) == 81 )
    {
      if ( (unsigned int)(*(_DWORD *)(a3 + 68) - *(_DWORD *)(a3 + 72)) >= 0xC )
      {
        *(_DWORD *)(v4 + 4) = 0;
        *(_DWORD *)v4 = v7;
        v13 = lpciInfo->mhBuffer.dwUser;
        v14 = *(_BYTE *)(v13 + 2);
        HIBYTE(v15) = *(_BYTE *)v13;
        LOBYTE(v15) = *(_BYTE *)(v13 + 1);
        *(_DWORD *)(v4 + 8) = v14 | (v15 << 8);
        dwCurrentTempo = v14 | (v15 << 8);
        *(_DWORD *)(v4 + 8) = 100 * *(_DWORD *)(v4 + 8) / dwTempoMultiplier | 0x1000000;
        if ( dwCurrentTempo )
          dwBufferTickLength = 60000 * dword_86FA88 / dwCurrentTempo;
        if ( dwMallocBlocks )
        {
          _free((void *)lpciInfo->mhBuffer.dwUser);
          --dwMallocBlocks;
        }
        *(_DWORD *)(a3 + 72) += 12;
        result = 0;
      }
      else
      {
        if ( dwMallocBlocks )
        {
          _free((void *)lpciInfo->mhBuffer.dwUser);
          --dwMallocBlocks;
        }
        result = -104;
      }
    }
    else
    {
      if ( dwMallocBlocks )
      {
        _free((void *)lpciInfo->mhBuffer.dwUser);
        --dwMallocBlocks;
      }
      result = -105;
    }
  }
  else
  {
    if ( (unsigned int)(*(_DWORD *)(a3 + 68) - *(_DWORD *)(a3 + 72)) < 0xC )
      return -104;
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)v4 = v7;
    HIBYTE(v10) = BYTE2(lpciInfo->mhBuffer.dwBufferLength);
    LOBYTE(v10) = BYTE1(lpciInfo->mhBuffer.dwBufferLength);
    v11 = LOBYTE(lpciInfo->mhBuffer.dwBufferLength) | (v10 << 8);
    *(_DWORD *)(v4 + 8) = v11;
    v12 = lpciInfo->mhBuffer.dwBufferLength & 0xF0;
    if ( (_BYTE)v12 == -80 && BYTE1(lpciInfo->mhBuffer.dwBufferLength) == 7 || (_BYTE)v12 == -64 || (_BYTE)v12 == -112 )
      *(_DWORD *)(v4 + 8) = v11 | 0x40000000;
    *(_DWORD *)(a3 + 72) += 12;
    result = 0;
  }
  return result;
}
// 86FA2C: using guessed type unsigned __int32 dwCurrentTempo;
// 86FA30: using guessed type unsigned __int32 dwTempoMultiplier;
// 86FA34: using guessed type unsigned __int32 dwBufferTickLength;
// 86FA88: using guessed type int dword_86FA88;

//----- (00554210) --------------------------------------------------------  // acclient.c:387416
int __usercall GetTrackByte@<eax>(INTRACKSTATE *ptsTrack@<ebp>, int a2@<esi>, char *lpbyByte)
{
  int result; // eax@3
  int v4; // ecx@4

  if ( *(_DWORD *)(a2 + 8) || !RefillTrackBuffer((INTRACKSTATE *)a2) )
  {
    *lpbyByte = **(_BYTE **)(a2 + 16);
    v4 = *(_DWORD *)(a2 + 16) + 1;
    --*(_DWORD *)(a2 + 8);
    *(_DWORD *)(a2 + 16) = v4;
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00554250) --------------------------------------------------------  // acclient.c:387437
int __usercall GetTrackVDWord@<eax>(INTRACKSTATE *ptsTrack@<ebp>, int a2@<esi>, unsigned int *lpdw)
{
  int v3; // edi@1
  int v4; // eax@5
  char v5; // cl@5

  v3 = 0;
  if ( *(_BYTE *)a2 & 1 )
    return 1;
  while ( *(_DWORD *)(a2 + 8) )
  {
LABEL_5:
    v4 = *(_DWORD *)(a2 + 16);
    v5 = *(_BYTE *)v4;
    *(_DWORD *)(a2 + 16) = v4 + 1;
    --*(_DWORD *)(a2 + 8);
    v3 = v5 & 0x7F | (v3 << 7);
    if ( v5 >= 0 )
    {
      *lpdw = v3;
      return 0;
    }
  }
  if ( *(_DWORD *)(a2 + 36) )
  {
    if ( RefillTrackBuffer((INTRACKSTATE *)a2) )
      return 1;
    goto LABEL_5;
  }
  *(_DWORD *)a2 |= 1u;
  return 1;
}

//----- (005542B0) --------------------------------------------------------  // acclient.c:387471
int __usercall GetTrackEvent@<eax>(INTRACKSTATE *ptsTrack@<edi>, TEMPEVENT *pteTemp@<esi>, int a3@<eax>, size_t *a4@<ebp>)
{
  int v4; // esi@1
  int v5; // ecx@5
  char v6; // al@5
  char v7; // cl@6
  char v8; // cl@13
  unsigned int v9; // ebx@15
  char *v11; // eax@31
  size_t v12; // ebx@32
  bool v13; // zf@32
  char *v14; // eax@40
  size_t v15; // ebx@41
  unsigned int tkDelta; // [sp+Ch] [bp-4h]@45

  v4 = a3;
  ptsTrack->fdwTrack = 0;
  ptsTrack->dwTrackLength = 0;
  ptsTrack->dwLeftInBuffer = 0;
  ptsTrack->pTrackStart = 0;
  if ( *(_BYTE *)a3 & 1 || !*(_DWORD *)(a3 + 8) && (!*(_DWORD *)(a3 + 36) || RefillTrackBuffer((INTRACKSTATE *)a3)) )
    return 1;
  v5 = *(_DWORD *)(v4 + 16);
  v6 = *(_BYTE *)v5;
  *(_DWORD *)(v4 + 16) = v5 + 1;
  --*(_DWORD *)(v4 + 8);
  if ( v6 < 0 )
  {
    v8 = v6 & 0xF0;
    if ( (v6 & 0xF0) == -16 )
    {
      if ( v6 == -16 || v6 == -9 )
      {
        a4 = &ptsTrack->dwLeftInBuffer;
        LOBYTE(ptsTrack->dwTrackLength) = v6;
        if ( GetTrackVDWord((INTRACKSTATE *)((char *)ptsTrack + 8), v4, &ptsTrack->dwLeftInBuffer) )
          return 1;
        if ( *(_DWORD *)(v4 + 8) + *(_DWORD *)(v4 + 36) >= *a4 )
        {
          v14 = (char *)_malloc(*a4);
          ptsTrack->pTrackStart = v14;
          if ( !v14 )
            return 1;
          v15 = 0;
          v13 = *a4 == 0;
          ++dwMallocBlocks;
          if ( !v13 )
          {
            while ( !GetTrackByte((INTRACKSTATE *)a4, v4, &ptsTrack->pTrackStart[v15]) )
            {
              ++v15;
              if ( v15 >= *a4 )
                goto LABEL_44;
            }
            return 1;
          }
          goto LABEL_44;
        }
      }
      else
      {
        if ( v6 != -1 )
          return 1;
        LOBYTE(ptsTrack->dwTrackLength) = -1;
        if ( *(_DWORD *)(v4 + 8) || *(_DWORD *)(v4 + 36) )
        {
          if ( GetTrackByte((INTRACKSTATE *)a4, v4, (char *)&ptsTrack->dwTrackLength + 1) )
            return 1;
          a4 = &ptsTrack->dwLeftInBuffer;
          if ( GetTrackVDWord((INTRACKSTATE *)((char *)ptsTrack + 8), v4, &ptsTrack->dwLeftInBuffer) )
            return 1;
          if ( *a4 )
          {
            if ( *(_DWORD *)(v4 + 8) + *(_DWORD *)(v4 + 36) < *a4 )
              goto LABEL_39;
            v11 = (char *)_malloc(*a4);
            ptsTrack->pTrackStart = v11;
            if ( !v11 )
              return 1;
            v12 = 0;
            v13 = *a4 == 0;
            ++dwMallocBlocks;
            if ( !v13 )
            {
              while ( !GetTrackByte((INTRACKSTATE *)a4, v4, &ptsTrack->pTrackStart[v12]) )
              {
                ++v12;
                if ( v12 >= *a4 )
                  goto LABEL_35;
              }
              return 1;
            }
          }
LABEL_35:
          if ( BYTE1(ptsTrack->dwTrackLength) == 47 )
            *(_DWORD *)v4 |= 1u;
          goto LABEL_44;
        }
      }
    }
    else
    {
      LOBYTE(ptsTrack->dwTrackLength) = v6;
      *(_BYTE *)(v4 + 24) = v6;
      if ( v8 == -64 || (v9 = 2, v8 == -48) )
        v9 = 1;
      ptsTrack->dwLeftInBuffer = v9 + 1;
      if ( *(_DWORD *)(v4 + 8) + *(_DWORD *)(v4 + 36) >= v9 )
      {
        if ( GetTrackByte((INTRACKSTATE *)a4, v4, (char *)&ptsTrack->dwTrackLength + 1)
          || v9 == 2 && GetTrackByte((INTRACKSTATE *)a4, v4, (char *)&ptsTrack->dwTrackLength + 2) )
          return 1;
        goto LABEL_44;
      }
    }
LABEL_39:
    *(_DWORD *)v4 |= 1u;
    return 1;
  }
  v7 = *(_BYTE *)(v4 + 24);
  if ( !v7 )
    return 1;
  BYTE1(ptsTrack->dwTrackLength) = v6;
  LOBYTE(ptsTrack->dwTrackLength) = v7;
  ptsTrack->dwLeftInBuffer = 2;
  if ( (v7 & 0xF0) == -64 || (v7 & 0xF0) == -48 )
    goto LABEL_44;
  if ( !*(_DWORD *)(v4 + 8) && !*(_DWORD *)(v4 + 36) )
    goto LABEL_39;
  if ( GetTrackByte((INTRACKSTATE *)a4, v4, (char *)&ptsTrack->dwTrackLength + 2) )
    return 1;
  ++ptsTrack->dwLeftInBuffer;
LABEL_44:
  ptsTrack->fdwTrack = *(_DWORD *)(v4 + 20);
  if ( !(*(_BYTE *)v4 & 1) )
  {
    if ( !GetTrackVDWord((INTRACKSTATE *)a4, v4, &tkDelta) )
    {
      *(_DWORD *)(v4 + 20) += tkDelta;
      return 0;
    }
    return 1;
  }
  return 0;
}

//----- (00554530) --------------------------------------------------------  // acclient.c:387618
int __cdecl ConverterInit(char *szInFile)
{
  HANDLE v1; // eax@1
  unsigned __int16 v2; // cx@9
  unsigned __int16 v3; // dx@9
  HLOCAL v4; // eax@9
  int v5; // esi@10
  HLOCAL v6; // eax@12
  DWORD v7; // edi@16
  HANDLE v8; // eax@20
  DWORD v9; // eax@20
  bool v10; // zf@20
  int result; // eax@26
  unsigned int cbHeader; // [sp+10h] [bp-18h]@6
  unsigned int dwTag; // [sp+14h] [bp-14h]@3
  unsigned int cbRead; // [sp+18h] [bp-10h]@18
  unsigned int idx; // [sp+1Ch] [bp-Ch]@3
  MIDIFILEHDR Header; // [sp+20h] [bp-8h]@8

  dword_86FA88 = 0;
  dword_86FA8C = 0;
  dword_86FA90 = 0;
  tkCurrentTime = 0;
  ifs.cbFileLength = 0;
  hMem = 0;
  v1 = CreateFileA(szInFile, 0x80000000, 1u, 0, 3u, 0x80u, 0);
  hInFile = v1;
  if ( v1 == (HANDLE)-1
    || (ifs.cbFileLength = GetFileSize(v1, 0), ifs.cbFileLength == -1)
    || !ReadFile(hInFile, &dwTag, 4u, &idx, 0)
    || idx != 4
    || dwTag != 1684558925
    || GetInFileData(&cbHeader, 4u)
    || (cbHeader = (((cbHeader << 16) | (unsigned __int16)(cbHeader & 0xFF00)) << 8) | (((cbHeader >> 16) | cbHeader & 0xFF0000) >> 8),
        cbHeader < 6)
    || GetInFileData(&Header, cbHeader)
    || (LOBYTE(v2) = 0,
        HIBYTE(v2) = Header.wFormat,
        LOBYTE(v3) = 0,
        dword_86FA8C = ((unsigned int)Header.wFormat >> 8) | v2,
        LOBYTE(v2) = 0,
        HIBYTE(v2) = LOBYTE(Header.wTrackCount),
        HIBYTE(v3) = LOBYTE(Header.wTimeDivision),
        dword_86FA90 = ((unsigned int)Header.wTrackCount >> 8) | v2,
        dword_86FA88 = ((unsigned int)Header.wTimeDivision >> 8) | v3,
        v4 = LocalAlloc(0x40u, 40 * dword_86FA90),
        (hMem = v4) == 0) )
  {
LABEL_27:
    ConverterCleanup();
    result = 1;
  }
  else
  {
    v5 = (int)v4;
    for ( idx = 0; idx < dword_86FA90; ++idx )
    {
      if ( !v5 )
        break;
      v6 = LocalAlloc(0x40u, 0x400u);
      *(_DWORD *)(v5 + 12) = v6;
      if ( !v6 || GetInFileData(&dwTag, 4u) || dwTag != 1802654797 || GetInFileData(&cbHeader, 4u) )
        goto LABEL_27;
      cbHeader = (((cbHeader << 16) | (unsigned __int16)(cbHeader & 0xFF00)) << 8) | (((cbHeader >> 16) | cbHeader & 0xFF0000) >> 8);
      *(_DWORD *)(v5 + 4) = cbHeader;
      *(_DWORD *)(v5 + 28) = SetFilePointer(hInFile, 0, 0, 1u);
      v7 = 1024;
      if ( *(_DWORD *)(v5 + 4) <= 0x400u )
        v7 = *(_DWORD *)(v5 + 4);
      if ( !ReadFile(hInFile, *(LPVOID *)(v5 + 12), v7, &cbRead, 0) || cbRead != v7 )
        goto LABEL_27;
      v8 = hInFile;
      *(_DWORD *)(v5 + 36) = *(_DWORD *)(v5 + 4) - cbRead;
      *(_DWORD *)(v5 + 8) = cbRead;
      v9 = SetFilePointer(v8, 0, 0, 1u);
      *(_DWORD *)(v5 + 16) = *(_DWORD *)(v5 + 12);
      v10 = *(_DWORD *)(v5 + 8) == 0;
      *(_DWORD *)(v5 + 32) = v9;
      *(_DWORD *)v5 = 0;
      *(_BYTE *)(v5 + 24) = 0;
      *(_DWORD *)(v5 + 20) = 0;
      if ( !v10 || *(_DWORD *)(v5 + 36) )
      {
        if ( GetTrackVDWord((INTRACKSTATE *)SetFilePointer, v5, (unsigned int *)(v5 + 20)) )
          goto LABEL_27;
        SetFilePointer(hInFile, *(_DWORD *)(v5 + 4) + *(_DWORD *)(v5 + 28), 0, 0);
      }
      else
      {
        *(_DWORD *)v5 = 1;
      }
      v5 += 40;
    }
    result = 0;
  }
  return result;
}
// 86FA84: using guessed type struct INFILESTATE ifs;
// 86FA88: using guessed type int dword_86FA88;
// 86FA8C: using guessed type int dword_86FA8C;
// 86FA90: using guessed type int dword_86FA90;

//----- (00554820) --------------------------------------------------------  // acclient.c:387721
int __cdecl RewindConverter()
{
  int v0; // esi@1
  DWORD v1; // edi@3
  HANDLE v2; // ecx@7
  DWORD v3; // eax@7
  bool v4; // zf@7
  int v5; // edx@7
  unsigned int cbRead; // [sp+10h] [bp-8h]@5
  unsigned int idx; // [sp+14h] [bp-4h]@1

  v0 = (int)hMem;
  tkCurrentTime = 0;
  idx = 0;
  if ( dword_86FA90 )
  {
    while ( v0 )
    {
      SetFilePointer(hInFile, *(_DWORD *)(v0 + 28), 0, 0);
      v1 = 1024;
      if ( *(_DWORD *)(v0 + 4) <= 0x400u )
        v1 = *(_DWORD *)(v0 + 4);
      if ( !ReadFile(hInFile, *(LPVOID *)(v0 + 12), v1, &cbRead, 0) || cbRead != v1 )
      {
Rewind_Cleanup:
        if ( !idx )
          return 0;
        return 1;
      }
      v2 = hInFile;
      *(_DWORD *)(v0 + 36) = *(_DWORD *)(v0 + 4) - cbRead;
      *(_DWORD *)(v0 + 8) = cbRead;
      v3 = SetFilePointer(v2, 0, 0, 1u);
      v4 = *(_DWORD *)(v0 + 8) == 0;
      v5 = *(_DWORD *)(v0 + 12);
      *(_DWORD *)(v0 + 32) = v3;
      *(_DWORD *)(v0 + 16) = v5;
      *(_DWORD *)v0 = 0;
      *(_BYTE *)(v0 + 24) = 0;
      *(_DWORD *)(v0 + 20) = 0;
      if ( !v4 || *(_DWORD *)(v0 + 36) )
      {
        if ( GetTrackVDWord((INTRACKSTATE *)SetFilePointer, v0, (unsigned int *)(v0 + 20)) )
          goto Rewind_Cleanup;
        SetFilePointer(hInFile, *(_DWORD *)(v0 + 4) + *(_DWORD *)(v0 + 28), 0, 0);
      }
      else
      {
        *(_DWORD *)v0 = 1;
      }
      v0 += 40;
      ++idx;
      if ( idx >= dword_86FA90 )
        return 0;
    }
  }
  return 0;
}
// 86FA90: using guessed type int dword_86FA90;

//----- (00554940) --------------------------------------------------------  // acclient.c:387782
int __cdecl ConvertToBuffer(unsigned int dwFlags, _ConvertInfo *lpciInfo)
{
  char *v3; // eax@4
  __int16 v4; // cx@4
  HLOCAL v5; // ecx@18
  int v6; // eax@18
  signed int v7; // esi@18
  unsigned int v8; // edi@18
  int v9; // eax@30
  int v10; // eax@36

  if ( !lpciInfo )
    return -101;
  lpciInfo->dwBytesRecorded = 0;
  if ( dwFlags & 1 )
  {
    v3 = 0;
    v4 = 0;
    dwProgressBytes = 0;
    dwStatus = 0;
    teTemp.pLongData = 0;
    teTemp.tkEvent = 0;
    *(_DWORD *)&teTemp.byShortData[0] = 0;
    teTemp.dwEventLength = 0;
    ptsFound = 0;
    ptsTrack = 0;
  }
  else
  {
    v4 = *(_WORD *)&teTemp.byShortData[0];
    v3 = teTemp.pLongData;
  }
  if ( !(dwStatus & 1) )
  {
    if ( dwStatus & 2 )
      return -102;
    if ( !(dwStatus & 4) )
      goto LABEL_18;
    dwStatus ^= 4u;
    if ( (_BYTE)v4 != -1 || HIBYTE(v4) != 47 )
    {
      v9 = AddEventToStreamBuffer(0, (_ConvertInfo *)&teTemp, (int)lpciInfo);
      if ( !v9 )
        goto LABEL_18;
      if ( v9 == -104 )
      {
LABEL_32:
        dwStatus |= 4u;
        return 0;
      }
      if ( v9 == -105 )
        goto LABEL_18;
      if ( !dwMallocBlocks )
        return 1;
      _free(teTemp.pLongData);
    }
    else
    {
      if ( dwMallocBlocks )
      {
        _free(v3);
        goto LABEL_17;
      }
      while ( 1 )
      {
        while ( 1 )
        {
LABEL_18:
          v5 = hMem;
          v6 = 0;
          v7 = -1;
          v8 = 0;
          ptsFound = 0;
          tkNext = -1;
          ptsTrack = (INTRACKSTATE *)hMem;
          if ( (unsigned int)dword_86FA90 <= 0 )
            goto LABEL_47;
          do
          {
            if ( !v5 )
              break;
            if ( !(*(_BYTE *)v5 & 1) && *((_DWORD *)v5 + 5) < (unsigned int)v7 )
            {
              v7 = *((_DWORD *)v5 + 5);
              v6 = (int)v5;
            }
            ++v8;
            v5 = (char *)v5 + 40;
          }
          while ( v8 < dword_86FA90 );
          ptsTrack = (INTRACKSTATE *)v5;
          ptsFound = (INTRACKSTATE *)v6;
          tkNext = v7;
          if ( !v6 )
          {
LABEL_47:
            dwStatus |= 1u;
            return 0;
          }
          if ( GetTrackEvent((INTRACKSTATE *)&teTemp, (TEMPEVENT *)v7, v6, 0) )
          {
            dwStatus |= 2u;
            return -101;
          }
          if ( teTemp.byShortData[0] != -1 || teTemp.byShortData[1] != 47 )
            break;
          if ( dwMallocBlocks )
          {
            _free(teTemp.pLongData);
LABEL_17:
            --dwMallocBlocks;
          }
        }
        v10 = AddEventToStreamBuffer(0, (_ConvertInfo *)&teTemp, (int)lpciInfo);
        if ( v10 )
        {
          if ( v10 == -104 )
            goto LABEL_32;
          if ( v10 != -105 )
            break;
        }
      }
      if ( !dwMallocBlocks )
        return 1;
      _free(teTemp.pLongData);
    }
    --dwMallocBlocks;
    return 1;
  }
  if ( bLooped )
  {
    RewindConverter();
    dwProgressBytes = 0;
    dwStatus = 0;
    goto LABEL_18;
  }
  return -103;
}
// 86FA28: using guessed type unsigned __int32 dwProgressBytes;
// 86FA58: using guessed type int bLooped;
// 86FA90: using guessed type int dword_86FA90;

