/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : wxutil
   Object     : ENGINE\render_base\wxutil.obj
   Functions  : 9
   Addresses  : 006C10C0 - 006C16E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C10C0) --------------------------------------------------------  // acclient.c:729287
void __thiscall CAMEvent::CAMEvent(CAMEvent *this, int fManualReset)
{
  this->m_hEvent = CreateEventA(0, fManualReset, 0, 0);
}

//----- (006C10E0) --------------------------------------------------------  // acclient.c:729293
void __thiscall CAMEvent::~CAMEvent(CAMEvent *this)
{
  if ( this->m_hEvent )
    CloseHandle(this->m_hEvent);
}

//----- (006C10F0) --------------------------------------------------------  // acclient.c:729300
unsigned __int16 *__stdcall lstrcpyWInternal(unsigned __int16 *lpString1, const unsigned __int16 *lpString2)
{
  unsigned __int16 *v2; // edx@1
  const unsigned __int16 *v3; // esi@1
  unsigned __int16 *result; // eax@1
  const unsigned __int16 v5; // cx@2

  v2 = lpString1;
  v3 = lpString2;
  result = lpString1;
  do
  {
    v5 = *v3;
    *v2 = *v3;
    ++v2;
    ++v3;
  }
  while ( v5 );
  return result;
}

//----- (006C1120) --------------------------------------------------------  // acclient.c:729322
unsigned __int16 *__stdcall lstrcpynWInternal(unsigned __int16 *lpString1, const unsigned __int16 *lpString2, int iMaxLength)
{
  unsigned __int16 *v3; // edx@1
  int v4; // edi@1
  unsigned __int16 *result; // eax@1
  const unsigned __int16 *v6; // esi@2
  const unsigned __int16 v7; // cx@4

  v3 = lpString1;
  v4 = iMaxLength;
  result = lpString1;
  if ( iMaxLength )
  {
    v6 = lpString2;
    while ( 1 )
    {
      --v4;
      if ( !v4 )
        break;
      v7 = *v6;
      *v3 = *v6;
      ++v3;
      ++v6;
      if ( !v7 )
        return result;
    }
    *v3 = 0;
  }
  return result;
}

//----- (006C1160) --------------------------------------------------------  // acclient.c:729354
int __stdcall lstrcmpWInternal(const unsigned __int16 *lpString1, const unsigned __int16 *lpString2)
{
  const unsigned __int16 *v2; // edx@1
  const unsigned __int16 *v3; // esi@1
  const unsigned __int16 v4; // ax@2
  const unsigned __int16 v5; // cx@2

  v2 = lpString2;
  v3 = lpString1;
  while ( 1 )
  {
    v4 = *v3;
    v5 = *v2;
    if ( *v3 != *v2 )
      break;
    ++v3;
    if ( v4 )
    {
      ++v2;
      if ( v5 )
        continue;
    }
    return 0;
  }
  return v4 - v5;
}

//----- (006C11A0) --------------------------------------------------------  // acclient.c:729382
int __stdcall lstrlenWInternal(const unsigned __int16 *lpString)
{
  int result; // eax@1

  result = -1;
  do
    ++result;
  while ( lpString[result] );
  return result;
}

//----- (006C11C0) --------------------------------------------------------  // acclient.c:729394
int __stdcall llMulDiv(__int64 a, __int64 b, __int64 c, __int64 d)
{
  int v4; // edi@2
  int v5; // edx@4
  unsigned int v6; // eax@7
  int v7; // ecx@8
  int v8; // ebp@10
  unsigned int v9; // esi@10
  unsigned __int64 v10; // rax@10
  unsigned int v11; // ecx@12
  signed int v12; // edi@15
  __int64 ST30_8_19; // ST30_8@19
  unsigned int v14; // edi@19
  unsigned int v15; // ecx@19
  unsigned __int64 v16; // kr38_8@19
  unsigned int v17; // ecx@25
  unsigned __int64 v18; // rax@27
  int v19; // ebx@34
  unsigned __int64 v20; // kr48_8@34
  int v21; // edi@37
  unsigned int v22; // ecx@37
  __int64 ub; // [sp+10h] [bp-28h]@5
  int ud; // [sp+18h] [bp-20h]@12
  unsigned int ud_4; // [sp+1Ch] [bp-1Ch]@2
  int bSign; // [sp+3Ch] [bp+4h]@10
  unsigned __int64 uc; // [sp+44h] [bp+Ch]@10
  signed int ca; // [sp+4Ch] [bp+14h]@37

  if ( SHIDWORD(a) < 0 )
  {
    v4 = -(signed int)a;
    ud_4 = (unsigned __int64)-a >> 32;
  }
  else
  {
    ud_4 = HIDWORD(a);
    v4 = a;
  }
  v5 = HIDWORD(b);
  if ( SHIDWORD(b) < 0 )
    ub = -b;
  else
    ub = b;
  v6 = HIDWORD(c);
  if ( SHIDWORD(c) < 0 )
  {
    v7 = -(signed int)c;
    v6 = (unsigned __int64)-c >> 32;
  }
  else
  {
    v7 = c;
  }
  uc = __PAIR__(v6, v7);
  bSign = (SHIDWORD(a) < 0) ^ (v5 < 0);
  v8 = v4 * ub;
  v9 = ((unsigned int)v4 * (unsigned __int64)(unsigned int)ub >> 32) + ud_4 * ub + HIDWORD(ub) * v4;
  v10 = (unsigned int)(((unsigned int)((unsigned int)v4 * (unsigned __int64)(unsigned int)ub >> 32)
                      + ud_4 * (unsigned __int64)(unsigned int)ub
                      + HIDWORD(ub) * (unsigned __int64)(unsigned int)v4) >> 32)
      + HIDWORD(ub) * (unsigned __int64)ud_4;
  if ( !d )
    goto LABEL_21;
  if ( bSign )
  {
    ud = -(signed int)d;
    v11 = (unsigned __int64)-d >> 32;
    if ( SHIDWORD(d) >= 0 && (SHIDWORD(d) > 0 || (_DWORD)d) )
    {
      v12 = -1;
      goto LABEL_19;
    }
  }
  else
  {
    v11 = HIDWORD(d);
    ud = d;
    if ( d < 0 )
    {
      v12 = -1;
      goto LABEL_19;
    }
  }
  v12 = 0;
LABEL_19:
  LODWORD(ST30_8_19) = v12;
  HIDWORD(ST30_8_19) = v12;
  v14 = ((unsigned int)ud + (unsigned __int64)(unsigned int)v8) >> 32;
  v8 += ud;
  v16 = v14 + v9 + (unsigned __int64)v11;
  v15 = v16 >> 32;
  v9 = v16;
  v10 += ST30_8_19 + v15;
  if ( SHIDWORD(v10) < 0 )
  {
    v9 = (__PAIR__((unsigned int)~(_DWORD)v16, ~v8) + 1) >> 32;
    v8 = -v8;
    bSign = bSign == 0;
    v10 = ((v9 | v8) == 0) + ~v10;
  }
LABEL_21:
  if ( c < 0 )
    bSign = bSign == 0;
  if ( HIDWORD(uc) > HIDWORD(v10) )
  {
    v17 = uc;
  }
  else if ( HIDWORD(uc) < HIDWORD(v10) || (v17 = uc, (unsigned int)uc <= (unsigned int)v10) )
  {
    if ( bSign )
      LODWORD(v18) = 0;
    else
      LODWORD(v18) = -1;
    return v18;
  }
  if ( v10 )
  {
    if ( HIDWORD(uc) )
    {
      v21 = 0;
      v22 = 0;
      ca = 64;
      do
      {
        v22 = __PAIR__(v22, v21) >> 31;
        v21 *= 2;
        v10 *= 2i64;
        if ( (v9 & 0x80000000) != 0 )
          LODWORD(v10) = v10 + 1;
        v9 = __PAIR__(v9, v8) >> 31;
        v8 *= 2;
        if ( uc <= v10 )
        {
          v10 -= uc;
          v22 = (__PAIR__(v22, v21++) + 1) >> 32;
        }
        --ca;
      }
      while ( ca );
      if ( bSign )
        v21 = -v21;
      LODWORD(v18) = v21;
    }
    else
    {
      v20 = __PAIR__(__PAIR__(v10, v9) % v17, v8) / (unsigned int)uc + __PAIR__(__PAIR__(v10, v9) / v17, 0);
      v19 = __PAIR__(__PAIR__(v10, v9) % v17, v8) / (unsigned int)uc;
      if ( bSign )
        v19 = -(signed int)v20;
      LODWORD(v18) = v19;
    }
  }
  else
  {
    v18 = __PAIR__(v9, v8) / __PAIR__(HIDWORD(uc), v17);
    if ( bSign )
      v18 = -(signed __int64)v18;
  }
  return v18;
}

//----- (006C14D0) --------------------------------------------------------  // acclient.c:729556
DWORD __stdcall WaitDispatchingMessages(void *hObject, unsigned int dwWait, HWND__ *hwnd, unsigned int uMsg, void *hEvent)
{
  unsigned int v5; // ebx@1
  DWORD v6; // esi@4
  DWORD result; // eax@4
  DWORD v8; // eax@9
  DWORD v9; // edi@9
  unsigned int v10; // esi@11
  DWORD v11; // eax@19
  HANDLE v12; // eax@24
  HANDLE v13; // eax@25
  HANDLE v14; // eax@29
  UINT v15; // eax@30
  bool v16; // zf@32
  UINT v17; // ST0C_4@33
  DWORD v18; // eax@33
  unsigned int dwStart; // [sp+Ch] [bp-30h]@1
  int bPeeked; // [sp+10h] [bp-2Ch]@1
  unsigned int dwThreadPriority; // [sp+14h] [bp-28h]@1
  void *hObjects[2]; // [sp+18h] [bp-24h]@1
  tagMSG msg; // [sp+20h] [bp-1Ch]@15
  DWORD hEventa; // [sp+50h] [bp+14h]@4

  v5 = dwWait;
  bPeeked = 0;
  dwStart = 0;
  dwThreadPriority = 0;
  hObjects[0] = hObject;
  hObjects[1] = hEvent;
  if ( dwWait != -1 && dwWait )
    dwStart = GetTickCount();
  v6 = (hEvent != 0) + 1;
  hEventa = v6;
  result = WaitForMultipleObjects(v6, hObjects, 0, 0);
  if ( result >= v6 )
  {
    while ( 1 )
    {
      if ( v5 > 0xA )
        v5 = 10;
      v8 = MsgWaitForMultipleObjects(v6, hObjects, 0, v5, 8 * (hwnd != 0) + 64);
      v9 = v8;
      if ( v8 == v6 )
      {
        v10 = dwWait;
      }
      else
      {
        if ( v8 != 258 )
          break;
        v10 = dwWait;
        if ( v5 == dwWait )
          break;
      }
      if ( hwnd && PeekMessageA(&msg, hwnd, uMsg, uMsg, 1u) )
      {
        do
          DispatchMessageA(&msg);
        while ( PeekMessageA(&msg, hwnd, uMsg, uMsg, 1u) );
      }
      PeekMessageA(&msg, 0, 0, 0, 0);
      if ( v10 != -1 && v10 )
      {
        v11 = GetTickCount();
        if ( v11 - dwStart <= v10 )
          dwWait = v10 - (v11 - dwStart);
        else
          dwWait = 0;
        dwStart = v11;
      }
      if ( !bPeeked )
      {
        v12 = GetCurrentThread();
        dwThreadPriority = GetThreadPriority(v12);
        if ( dwThreadPriority < 2 )
        {
          v13 = GetCurrentThread();
          SetThreadPriority(v13, 2);
        }
        bPeeked = 1;
      }
      v6 = hEventa;
      v9 = WaitForMultipleObjects(hEventa, hObjects, 0, 0);
      if ( v9 < hEventa )
        break;
      v5 = dwWait;
    }
    if ( bPeeked )
    {
      v14 = GetCurrentThread();
      SetThreadPriority(v14, dwThreadPriority);
      if ( (GetQueueStatus(8u) >> 16) & 8 )
      {
        v15 = uMsgId;
        if ( uMsgId || (v15 = RegisterWindowMessageA("AMUnblock"), (uMsgId = v15) != 0) )
        {
          do
          {
            v16 = PeekMessageA(&msg, HWND_MESSAGE|0x2, v15, v15, 1u) == 0;
            v15 = uMsgId;
          }
          while ( !v16 );
        }
        v17 = v15;
        v18 = GetCurrentThreadId();
        PostThreadMessageA(v18, v17, 0, 0);
      }
    }
    result = v9;
  }
  return result;
}

//----- (006C16E0) --------------------------------------------------------  // acclient.c:729670
unsigned int __cdecl CompatibleTimeSetEvent(unsigned int uDelay, unsigned int uResolution, void (__stdcall *lpTimeProc)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int), unsigned int dwUser, unsigned int fuEvent)
{
  bool v5; // al@6
  _OSVERSIONINFOA VersionInformation; // [sp+0h] [bp-94h]@2

  if ( !fCheckedVersion )
  {
    VersionInformation.dwOSVersionInfoSize = 148;
    v5 = GetVersionExA(&VersionInformation)
      && (VersionInformation.dwMajorVersion > 5
       || VersionInformation.dwMajorVersion == 5 && VersionInformation.dwMinorVersion >= 1);
    fTimeKillSynchronousFlagAvailable = v5;
    fCheckedVersion = 1;
  }
  if ( fTimeKillSynchronousFlagAvailable )
    fuEvent |= 0x100u;
  return timeSetEvent(uDelay, uResolution, lpTimeProc, dwUser, fuEvent);
}

