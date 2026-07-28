/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : mstream
   Object     : PORTAL\sound\mstream.obj
   Functions  : 9
   Addresses  : 00552F60 - 00553770 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00552F60) --------------------------------------------------------  // acclient.c:386257
int __cdecl SetChannelVolume(unsigned int dwChannel, unsigned int volpct)
{
  HMIDIOUT v2; // esi@1
  int result; // eax@2
  unsigned int v4; // edx@3

  v2 = hStream;
  if ( hStream )
  {
    v4 = volpct * (_DWORD)(&dwVolCache)[dwChannel];
    *(&dwVolPctCache + dwChannel) = volpct;
    result = midiOutShortMsg(v2, dwChannel | (v4 / 0x64 << 16) | 0x7B0) == 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86F9E8: using guessed type unsigned __int32 *dwVolCache;

//----- (00552FB0) --------------------------------------------------------  // acclient.c:386279
HLOCAL FreeBuffers()
{
  HLOCAL result; // eax@1
  midihdr_tag *v1; // esi@3
  signed int v2; // edi@3
  unsigned int v3; // esi@5

  result = (HLOCAL)b_BuffersAllocated;
  if ( b_BuffersAllocated )
  {
    if ( bBuffersPrepared )
    {
      v1 = &ciStreamBuffers;
      v2 = 6;
      do
      {
        midiOutUnprepareHeader(hStream, v1, 0x40u);
        v1 = (midihdr_tag *)((char *)v1 + 84);
        --v2;
        bBuffersPrepared = 0;
      }
      while ( v2 );
    }
    v3 = 0;
    do
    {
      result = *(char **)((char *)&ciStreamBuffers.lpData + v3);
      if ( result )
      {
        result = LocalFree(*((HLOCAL *)result - 1));
        *(char **)((char *)&ciStreamBuffers.lpData + v3) = 0;
      }
      v3 += 84;
    }
    while ( v3 < 0x1F8 );
    b_BuffersAllocated = 0;
  }
  return result;
}
// 86FA50: using guessed type int bBuffersPrepared;
// 86FA64: using guessed type int b_BuffersAllocated;

//----- (00553030) --------------------------------------------------------  // acclient.c:386322
int __cdecl StreamBufferSetup(char *szFileBuffer)
{
  int result; // eax@3
  unsigned int v2; // ebx@4
  unsigned int v3; // esi@4
  HLOCAL v4; // eax@5
  unsigned int v5; // ecx@6
  midihdr_tag *v6; // esi@14
  int v7; // eax@19
  unsigned int v8; // ecx@19
  int v9; // eax@20
  int v10; // eax@20
  int v11; // eax@23
  int v12; // ecx@23
  bool v13; // sf@28
  unsigned __int8 v14; // of@28
  int bFoundEnd; // [sp+4h] [bp-Ch]@1
  midiproptimediv_tag mptd; // [sp+8h] [bp-8h]@11

  bFoundEnd = 0;
  if ( !hStream && midiStreamOpen((LPHMIDISTRM)&hStream, &uMIDIDeviceID, 1u, (DWORD_PTR)MidiProc, 0, 0x30000u) )
    return 0;
  v2 = 0;
  v3 = 0;
  do
  {
    *(unsigned int *)((char *)&ciStreamBuffers.dwBufferLength + v3 * 84) = 1024;
    v4 = LocalAlloc(0x40u, 0x423u);
    if ( v4 )
    {
      v5 = (unsigned int)((char *)v4 + 35) & 0xFFFFFFE0;
      *(_DWORD *)(v5 - 4) = v4;
    }
    else
    {
      v5 = 0;
    }
    *(char **)((char *)&ciStreamBuffers.lpData + v3 * 84) = (char *)v5;
    if ( !v5 )
    {
      if ( v2 > 0 )
      {
        v6 = &ciStreamBuffers;
        do
        {
          if ( v6->lpData )
          {
            LocalFree(*((HLOCAL *)v6->lpData - 1));
            v6->lpData = 0;
          }
          v6 = (midihdr_tag *)((char *)v6 + 84);
          --v2;
        }
        while ( v2 );
      }
      return 0;
    }
    ++v3;
    ++v2;
  }
  while ( v3 < 6 );
  b_BuffersAllocated = 1;
  if ( ConverterInit(szFileBuffer) )
    return 0;
  mptd.cbStruct = 8;
  mptd.dwTimeDiv = dword_86FA88;
  if ( midiStreamProperty((HMIDISTRM)hStream, (LPBYTE)&mptd, 0x80000001) )
  {
LABEL_12:
    ConverterCleanup();
    result = 0;
  }
  else
  {
    v7 = 0;
    nEmptyBuffers = 6;
    v8 = 1;
    nCurrentBuffer = 0;
    do
    {
      v9 = 21 * v7;
      dword_86F7F0[v9] = 0;
      dword_86F7F4[v9] = 1024;
      dword_86F7FC[v9] = 0;
      dword_86F800[v9] = 0;
      v10 = ConvertToBuffer(v8, (_ConvertInfo *)((char *)&ciStreamBuffers + v9 * 4));
      if ( v10 )
      {
        if ( v10 != -103 )
          goto LABEL_12;
        bFoundEnd = 1;
      }
      v11 = nCurrentBuffer;
      v12 = 84 * nCurrentBuffer;
      *(&ciStreamBuffers.dwBytesRecorded + 21 * nCurrentBuffer) = dword_86F7F8[21 * nCurrentBuffer];
      if ( !bBuffersPrepared )
      {
        if ( midiOutPrepareHeader(hStream, (midihdr_tag *)((char *)&ciStreamBuffers + v12), 0x40u) )
          goto LABEL_12;
        v11 = nCurrentBuffer;
      }
      if ( midiStreamOut((HMIDISTRM)hStream, (midihdr_tag *)((char *)&ciStreamBuffers + 84 * v11), 0x40u) )
        break;
      --nEmptyBuffers;
      v8 = 0;
      if ( bFoundEnd )
        break;
      v7 = nCurrentBuffer + 1;
      v14 = __OFSUB__(nCurrentBuffer + 1, 6);
      v13 = nCurrentBuffer++ - 5 < 0;
    }
    while ( v13 ^ v14 );
    bBuffersPrepared = 1;
    result = 1;
    nCurrentBuffer = 0;
  }
  return result;
}
// 86F7F0: using guessed type int dword_86F7F0[];
// 86F7F4: using guessed type int dword_86F7F4[];
// 86F7F8: using guessed type int dword_86F7F8[];
// 86F7FC: using guessed type int dword_86F7FC[];
// 86F800: using guessed type int dword_86F800[];
// 86FA38: using guessed type int nEmptyBuffers;
// 86FA3C: using guessed type int nCurrentBuffer;
// 86FA50: using guessed type int bBuffersPrepared;
// 86FA64: using guessed type int b_BuffersAllocated;
// 86FA88: using guessed type int dword_86FA88;

//----- (00553240) --------------------------------------------------------  // acclient.c:386452
void __cdecl midiStop()
{
  HMIDIOUT v0; // ecx@1
  unsigned int v1; // eax@4

  v0 = hStream;
  if ( !hStream )
    return;
  if ( bPlaying || bFileOpen )
  {
    v1 = uCallbackStatus;
    if ( uCallbackStatus == 200 )
    {
LABEL_9:
      if ( midiStreamStop((HMIDISTRM)hStream) )
        return;
      v0 = hStream;
      bPaused = 0;
      bPlaying = 0;
      goto LABEL_11;
    }
LABEL_7:
    if ( v1 != 300 )
      uCallbackStatus = 100;
    goto LABEL_9;
  }
  v1 = uCallbackStatus;
  if ( uCallbackStatus != 200 )
    goto LABEL_7;
LABEL_11:
  if ( !midiOutReset(v0) && (WaitForSingleObject(hBufferReturnEvent, 0x7D0u) == 258 || uCallbackStatus == 200) )
  {
    uCallbackStatus = 0;
    if ( bFileOpen )
    {
      ConverterCleanup();
      bFileOpen = 0;
    }
    FreeBuffers();
    if ( hStream )
    {
      midiStreamClose((HMIDISTRM)hStream);
      hStream = 0;
      midiStreamOpen((LPHMIDISTRM)&hStream, &uMIDIDeviceID, 1u, (DWORD_PTR)MidiProc, 0, 0x30000u);
    }
    is_pending = 0;
    pending_loop = 0;
    dwQueuedTempoMultiplier = 100;
  }
}
// 86FA44: using guessed type unsigned int uCallbackStatus;
// 86FA48: using guessed type int bFileOpen;
// 86FA4C: using guessed type int bPlaying;
// 86FA54: using guessed type int bPaused;
// 86FA6C: using guessed type int is_pending;

//----- (00553350) --------------------------------------------------------  // acclient.c:386509
void __cdecl midiCleanup()
{
  midiStop();
  if ( hStream )
  {
    midiStreamClose((HMIDISTRM)hStream);
    hStream = 0;
  }
  if ( hBufferReturnEvent )
  {
    CloseHandle(hBufferReturnEvent);
    hBufferReturnEvent = 0;
  }
  MidiIsSetup = 0;
}

//----- (00553390) --------------------------------------------------------  // acclient.c:386526
int __cdecl midiPlay(char *filename, int loop, int stopprev, unsigned int dwTempo)
{
  signed int v4; // esi@6
  int result; // eax@12

  dwTempoMultiplier = dwTempo;
  bInsertTempo = 1;
  if ( bPlaying || bFileOpen )
  {
    if ( !stopprev )
    {
      lstrcpyA(pending, filename);
      dwQueuedTempoMultiplier = dwTempo;
      is_pending = 1;
      result = 1;
      pending_loop = loop;
      return result;
    }
    midiStop();
  }
  if ( StreamBufferSetup(filename) )
  {
    v4 = 0;
    while ( !midiOutShortMsg(
               hStream,
               (v4 + 176) | ((unsigned int)(&dwVolCache)[v4] * *(&dwVolPctCache + v4) / 0x64 << 16) | 0x700) )
    {
      ++v4;
      if ( v4 >= 16 )
      {
        uCallbackStatus = 0;
        bFileOpen = 1;
        if ( midiStartCallback )
          midiStartCallback();
        if ( !midiStreamRestart((HMIDISTRM)hStream) )
        {
          bPlaying = 1;
          result = 1;
          bLooped = loop;
          is_pending = 0;
          pending_loop = 0;
          dwQueuedTempoMultiplier = 100;
          return result;
        }
        return 0;
      }
    }
  }
  return 0;
}
// 86F9E8: using guessed type unsigned __int32 *dwVolCache;
// 86FA30: using guessed type unsigned __int32 dwTempoMultiplier;
// 86FA44: using guessed type unsigned int uCallbackStatus;
// 86FA48: using guessed type int bFileOpen;
// 86FA4C: using guessed type int bPlaying;
// 86FA58: using guessed type int bLooped;
// 86FA5C: using guessed type int bInsertTempo;
// 86FA6C: using guessed type int is_pending;
// 86FA74: using guessed type void (__cdecl *midiStartCallback)();

//----- (005534C0) --------------------------------------------------------  // acclient.c:386587
int __cdecl midiPlayNext()
{
  int result; // eax@2

  if ( is_pending )
  {
    is_pending = 0;
    result = midiPlay(pending, pending_loop, 1, dwQueuedTempoMultiplier);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86FA6C: using guessed type int is_pending;

//----- (00553500) --------------------------------------------------------  // acclient.c:386605
void __stdcall MidiProc(HMIDIIN__ *__formal, unsigned int uMsg, unsigned int a3, unsigned int dwParam1, unsigned int a5)
{
  int v5; // esi@3
  unsigned int v6; // eax@3
  int v7; // esi@3
  int v8; // edx@3
  int v9; // edi@3
  int v10; // eax@20
  int v11; // eax@30
  int v12; // eax@30
  midihdr_tag *v13; // edx@33

  if ( uMsg == 969 )
  {
    if ( uCallbackStatus == 200 )
      return;
    v10 = nEmptyBuffers++ + 1;
    if ( uCallbackStatus == 300 )
    {
      if ( v10 >= 6 )
      {
        uCallbackStatus = 200;
        SetEvent(hBufferReturnEvent);
        if ( is_pending )
          midiPlayNext();
        else
          midiStop();
      }
    }
    else if ( uCallbackStatus == 100 )
    {
      if ( v10 >= 6 )
      {
        uCallbackStatus = 200;
        SetEvent(hBufferReturnEvent);
      }
    }
    else if ( bPlaying && v10 )
    {
      v11 = 21 * nCurrentBuffer;
      dword_86F7F0[v11] = 0;
      dword_86F7F4[v11] = 1024;
      dword_86F7FC[v11] = 0;
      dword_86F7F8[v11] = 0;
      dword_86F800[v11] = 0;
      v12 = ConvertToBuffer(0, (_ConvertInfo *)((char *)&ciStreamBuffers + v11 * 4));
      if ( v12 )
      {
        if ( v12 == -103 )
        {
          nWaitingBuffers = 5;
          uCallbackStatus = 300;
          return;
        }
      }
      else
      {
        v13 = (midihdr_tag *)((char *)&ciStreamBuffers + 84 * nCurrentBuffer);
        *(&ciStreamBuffers.dwBytesRecorded + 21 * nCurrentBuffer) = dword_86F7F8[21 * nCurrentBuffer];
        if ( !midiStreamOut((HMIDISTRM)hStream, v13, 0x40u) )
        {
          --nEmptyBuffers;
          nCurrentBuffer = (nCurrentBuffer + 1) % 6;
          return;
        }
      }
      ConverterCleanup();
      return;
    }
  }
  else if ( uMsg == 970 )
  {
    v5 = *(_DWORD *)(dwParam1 + 28);
    v6 = *(_DWORD *)(v5 + *(_DWORD *)dwParam1 + 8);
    v7 = *(_DWORD *)dwParam1 + v5;
    v8 = v6 & 0xF;
    v9 = v6 & 0xF;
    if ( (unsigned __int8)(v6 & 0xF0) == 128 )
    {
      if ( (v9 == 14 || v9 == 15) && midiEventCallback )
        midiEventCallback(0x80u, v8, (v6 >> 16) & 0x7F);
    }
    else if ( (unsigned __int8)(v6 & 0xF0) == 144 )
    {
      if ( (v9 == 14 || v9 == 15) && midiEventCallback )
        midiEventCallback(0x90u, v8, (v6 >> 16) & 0x7F);
    }
    else if ( (unsigned __int8)(v6 & 0xF0) == 176 && *(_BYTE *)(v7 + 9) == 7 )
    {
      (&dwVolCache)[v8] = (unsigned __int32 *)((v6 >> 16) & 0x7F);
      SetChannelVolume(*(_DWORD *)(v7 + 8) & 0xF, *(&dwVolPctCache + (*(_DWORD *)(v7 + 8) & 0xF)));
      if ( v9 == 14 || v9 == 15 )
      {
        if ( midiEventCallback )
          midiEventCallback(7u, *(_DWORD *)(v7 + 8) & 0xF, (*(_DWORD *)(v7 + 8) >> 16) & 0x7F);
      }
    }
  }
}
// 86F7F0: using guessed type int dword_86F7F0[];
// 86F7F4: using guessed type int dword_86F7F4[];
// 86F7F8: using guessed type int dword_86F7F8[];
// 86F7FC: using guessed type int dword_86F7FC[];
// 86F800: using guessed type int dword_86F800[];
// 86F9E8: using guessed type unsigned __int32 *dwVolCache;
// 86FA38: using guessed type int nEmptyBuffers;
// 86FA3C: using guessed type int nCurrentBuffer;
// 86FA44: using guessed type unsigned int uCallbackStatus;
// 86FA4C: using guessed type int bPlaying;
// 86FA6C: using guessed type int is_pending;
// 86FA70: using guessed type void (__cdecl *midiEventCallback)(unsigned __int8, int, unsigned __int32);

//----- (00553770) --------------------------------------------------------  // acclient.c:386718
int __cdecl midiSetup()
{
  int result; // eax@10

  if ( MidiIsSetup )
  {
    midiStop();
    if ( hStream )
    {
      midiStreamClose((HMIDISTRM)hStream);
      hStream = 0;
    }
    if ( hBufferReturnEvent )
    {
      CloseHandle(hBufferReturnEvent);
      hBufferReturnEvent = 0;
    }
  }
  MidiIsSetup = 0;
  is_pending = 0;
  if ( midiOutGetNumDevs()
    && ((memset32(&dwVolCache, 100, 0x10u),
         memset32(&dwVolPctCache, 100, 0x10u),
         dwTempoMultiplier = 100,
         hBufferReturnEvent)
     || (hBufferReturnEvent = CreateEventA(0, 0, 0, "Wait For Buffer Return")) != 0)
    && !midiStreamOpen((LPHMIDISTRM)&hStream, &uMIDIDeviceID, 1u, (DWORD_PTR)MidiProc, 0, 0x30000u) )
  {
    MidiIsSetup = 1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86F9E8: using guessed type unsigned __int32 *dwVolCache;
// 86FA30: using guessed type unsigned __int32 dwTempoMultiplier;
// 86FA6C: using guessed type int is_pending;

