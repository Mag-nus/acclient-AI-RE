/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Device
   Object     : ENGINE\device\Device.obj
   Functions  : 142
   Addresses  : 00438E40 - 00729AC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00438E40) --------------------------------------------------------  // acclient.c:117920
void __thiscall RenderDevicePresentation::RenderDevicePresentation(RenderDevicePresentation *this)
{
  this->hRenderWindow = 0;
  this->Width = 800;
  this->Height = 600;
  this->FullScreen = 0;
  this->FSRefreshRate = 0;
  this->FSBitsPerPixel = 32;
  this->FSTripleBuffering = 0;
  this->FSSyncToDisplayRefresh = 0;
  this->Antialiasing = 0;
}

//----- (00438E70) --------------------------------------------------------  // acclient.c:117934
SurfaceWindow *__thiscall SurfaceWindow::scalar_deleting_destructor(SurfaceWindow *this, unsigned int a2)
{
  SurfaceWindow *v2; // esi@1

  v2 = this;
  this->vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
  SurfaceWindow::End(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00438EA0) --------------------------------------------------------  // acclient.c:117948
char __thiscall Device::DeviceDialogBoxGateway::ReportThread_OnDialogBoxBegin(Device::DeviceDialogBoxGateway *this)
{
  char result; // al@1
  unsigned int dwResult; // [sp+0h] [bp-4h]@1

  dwResult = (unsigned int)this;
  result = 0;
  if ( RenderDevice::render_device )
  {
    if ( RenderDevice::render_device->m_presentation.FullScreen )
    {
      SendMessageTimeoutA(Device::m_hWnd, 0x112u, 0xF020u, 0, 0, 0x3E8u, &dwResult);
      result = 1;
    }
  }
  return result;
}

//----- (00438EE0) --------------------------------------------------------  // acclient.c:117967
void __stdcall Device::DeviceDialogBoxGateway::ReportThread_OnDialogBoxEnd(unsigned int context)
{
  if ( (_BYTE)context )
    SendMessageTimeoutA(Device::m_hWnd, 0x112u, 0xF120u, 0, 0, 0x3E8u, &context);
}

//----- (00438F10) --------------------------------------------------------  // acclient.c:117974
void __thiscall Device::DeviceDialogBoxGateway::DeviceDialogBoxGateway(Device::DeviceDialogBoxGateway *this)
{
  Device::DeviceDialogBoxGateway *v1; // esi@1

  v1 = this;
  DialogBoxGateway::DialogBoxGateway((DialogBoxGateway *)&this->vfptr);
  v1->vfptr = (CPluginPrototypeVtbl *)&Device::DeviceDialogBoxGateway::vftable;
}
// 798D18: using guessed type int (__thiscall *Device::DeviceDialogBoxGateway::vftable)(void *, char);

//----- (00438F30) --------------------------------------------------------  // acclient.c:117985
void __cdecl Device::Done()
{
  Device::m_bIsDone = 1;
}
// 837194: using guessed type bool Device::m_bIsDone;

//----- (00438F40) --------------------------------------------------------  // acclient.c:117992
int __cdecl Device::ForwardToInputManager(HWND__ *hWindow, unsigned int message, unsigned int wParam, int lParam, bool *o_fHandled)
{
  int result; // eax@3
  tagMSG msg; // [sp+0h] [bp-1Ch]@3

  if ( Device::m_bIsInitialized && ICIDM::s_cidm )
  {
    msg.hwnd = hWindow;
    msg.message = message;
    msg.wParam = wParam;
    msg.lParam = lParam;
    msg.time = GetMessageTime();
    result = ((int (__stdcall *)(tagMSG *, bool *))ICIDM::s_cidm->vfptr->OnMessage)(&msg, o_fHandled);
  }
  else
  {
    *o_fHandled = 0;
    result = 0;
  }
  return result;
}
// 837196: using guessed type bool Device::m_bIsInitialized;

//----- (00438FB0) --------------------------------------------------------  // acclient.c:118016
void __cdecl Device::DoFrameSleep()
{
  DWORD v0; // esi@1
  DWORD v1; // eax@2

  v0 = 0;
  if ( !Device::m_bIsActiveApp )
  {
    v1 = timeGetTime() - lastTime;
    if ( v1 < 0x63 )
      v0 = 99 - v1;
  }
  Sleep(v0);
  lastTime = timeGetTime();
}
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00438FF0) --------------------------------------------------------  // acclient.c:118034
void __cdecl Device::Activate()
{
  if ( !Device::m_bIsActiveApp )
  {
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->Activate)(1);
    Device::m_bIsActiveApp = 1;
  }
}
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00439020) --------------------------------------------------------  // acclient.c:118046
void __cdecl Device::Deactivate()
{
  HCURSOR v0; // eax@6

  if ( Device::m_bIsActiveApp )
  {
    Device::m_bIsActiveApp = 0;
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->Activate)(0);
    if ( !RenderDevice::render_device || !RenderDevice::render_device->m_presentation.FullScreen )
    {
      v0 = LoadCursorA(0, (LPCSTR)0x7F00);
      SetCursor(v0);
    }
  }
}
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00439070) --------------------------------------------------------  // acclient.c:118065
char __cdecl Device::LoadDisplayPreferences(RenderDevicePresentation *_Presentation)
{
  unsigned int v1; // edx@1
  char result; // al@7

  v1 = (unsigned __int16)Device::m_DisplayPrefs.Resolution;
  if ( Device::m_DisplayPrefs.Resolution >> 16 < 0x320 || v1 < 0x258 )
  {
    result = 0;
  }
  else
  {
    _Presentation->Width = Device::m_DisplayPrefs.Resolution >> 16;
    _Presentation->Height = v1;
    _Presentation->FullScreen = byte_817B68;
    _Presentation->FSRefreshRate = dword_817B6C;
    _Presentation->FSTripleBuffering = byte_817B70;
    _Presentation->FSSyncToDisplayRefresh = byte_817B71;
    _Presentation->Antialiasing = byte_817B72;
    if ( Device::m_bUseForcedResolution )
    {
      _Presentation->Width = Device::m_nForcedWidth;
      _Presentation->Height = Device::m_nForcedHeight;
    }
    if ( !Device::m_bAllowFullScreenMode )
      _Presentation->FullScreen = 0;
    result = 1;
  }
  return result;
}
// 817B02: using guessed type bool Device::m_bAllowFullScreenMode;
// 817B64: using guessed type struct DisplayPrefs Device::m_DisplayPrefs;
// 817B68: using guessed type char byte_817B68;
// 817B6C: using guessed type int dword_817B6C;
// 817B70: using guessed type char byte_817B70;
// 817B71: using guessed type char byte_817B71;
// 817B72: using guessed type char byte_817B72;
// 8371A0: using guessed type bool Device::m_bUseForcedResolution;

//----- (00439100) --------------------------------------------------------  // acclient.c:118105
char __fastcall Device::ShutdownGraphicsEngine(PSRefBufferCharData<char> *a1)
{
  HCURSOR v1; // eax@6

  if ( Device::m_bIsActiveApp )
  {
    a1 = (PSRefBufferCharData<char> *)ICIDM::s_cidm;
    Device::m_bIsActiveApp = 0;
    if ( ICIDM::s_cidm )
      ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->Activate)(0);
    if ( !RenderDevice::render_device
      || (LOBYTE(a1) = RenderDevice::render_device->m_presentation.FullScreen, !(_BYTE)a1) )
    {
      v1 = LoadCursorA(0, (LPCSTR)0x7F00);
      SetCursor(v1);
    }
  }
  SceneTool::Shutdown(a1);
  Render::ShutdownRenderingSystem();
  return 1;
}
// 837197: using guessed type bool Device::m_bIsActiveApp;

//----- (00439160) --------------------------------------------------------  // acclient.c:118129
int __cdecl Device::GetScreenshotSurface()
{
  int v0; // ebp@1
  int result; // eax@1
  int v2; // esi@4
  int v3; // edi@4
  int v4; // eax@6
  int v5; // ebx@6
  tagPOINT point; // [sp+4h] [bp-44h]@4
  tagRECT rect; // [sp+Ch] [bp-3Ch]@4
  SurfaceWindow SourceWindow; // [sp+1Ch] [bp-2Ch]@4

  v0 = ((int (*)(void))RenderDevice::render_device->vfptr->GenerateSurfaceFromFrontBuffer)();
  result = 0;
  if ( v0 )
  {
    if ( RenderDevice::render_device->m_presentation.FullScreen )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v0 + 16))(v0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v0 + 20))(v0);
      result = v0;
    }
    else
    {
      point.y = 0;
      point.x = 0;
      ClientToScreen(Device::m_hWnd, &point);
      GetClientRect(Device::m_hWnd, &rect);
      rect.left += point.x;
      rect.top += point.y;
      rect.right += point.x;
      rect.bottom += point.y;
      SurfaceWindow::SurfaceWindow(&SourceWindow, (RenderSurface *)v0, &rect);
      v2 = SourceWindow.rect.right - SourceWindow.rect.left;
      v3 = SourceWindow.rect.bottom - SourceWindow.rect.top;
      if ( (unsigned int)(SourceWindow.rect.right - SourceWindow.rect.left) < 1 || (unsigned int)v3 < 1 )
      {
        v5 = point.x;
      }
      else
      {
        v4 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateSurface)();
        v5 = v4;
        if ( v4 )
        {
          (*(void (__thiscall **)(int, int, int, _DWORD, signed int))(*(_DWORD *)v4 + 88))(
            v4,
            v2,
            v3,
            *(_DWORD *)(v0 + 220),
            1);
          SurfaceWindow::Blit((SurfaceWindow *)(v5 + 172), &SourceWindow);
        }
      }
      SourceWindow.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
      SurfaceWindow::End(&SourceWindow);
      (*(void (__thiscall **)(int))(*(_DWORD *)v0 + 20))(v0);
      result = v5;
    }
  }
  return result;
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (00439290) --------------------------------------------------------  // acclient.c:118194
int __cdecl Device::Error(PStringBase<char> *errtext, PStringBase<char> *errtitle, bool fatal)
{
  int v3; // eax@1

  v3 = (int)"fatal";
  if ( !fatal )
    v3 = (int)"non-fatal";
  IError::ReportGenericError("%s: %s (%s)\n", errtitle->m_charbuffer, errtext->m_charbuffer, v3);
  if ( fatal )
    Device::m_bIsDone = 1;
  return 0;
}
// 837194: using guessed type bool Device::m_bIsDone;

//----- (004392D0) --------------------------------------------------------  // acclient.c:118209
char __cdecl Device::SetCursorFromIcon(HICON__ *hNewIcon)
{
  HICON__ *v1; // esi@1
  DWORD v2; // eax@3

  v1 = hNewIcon;
  if ( hNewIcon || (v1 = LoadCursorA((HINSTANCE)hNewIcon, (LPCSTR)0x7F00)) != 0 )
  {
    v2 = GetClassLongA(Device::m_hWnd, -12);
    if ( (HICON__ *)v2 != v1 )
      DestroyIcon((HICON)v2);
    SetClassLongA(Device::m_hWnd, -12, (LONG)v1);
    SetCursor(v1);
  }
  return 1;
}

//----- (00439320) --------------------------------------------------------  // acclient.c:118227
void __cdecl Device::ShowCursor(bool show)
{
  if ( Device::m_fMouseIsShown != show )
  {
    ShowCursor(show);
    Device::m_fMouseIsShown = show;
  }
}
// 817B0C: using guessed type bool Device::m_fMouseIsShown;

//----- (004393C0) --------------------------------------------------------  // acclient.c:118287
void __cdecl _STL::__unguarded_linear_insert(PrefDisplayModeType *__last, PrefDisplayModeType __val)
{
  PrefDisplayModeType *v2; // ecx@1
  PrefDisplayModeType *v3; // eax@1
  unsigned int v4; // esi@2

  v2 = __last;
  v3 = __last - 1;
  if ( __val.nSize < __last[-1].nSize )
  {
    do
    {
      v2->nWidth = v3->nWidth;
      v2->nHeight = v3->nHeight;
      v2->nSize = v3->nSize;
      v2->nModeDesc = v3->nModeDesc;
      v4 = v3[-1].nSize;
      v2 = v3;
      --v3;
    }
    while ( __val.nSize < v4 );
  }
  *v2 = __val;
}

//----- (00439410) --------------------------------------------------------  // acclient.c:118313
void __cdecl _STL::__push_heap(unsigned int *__first, int __holeIndex, int __topIndex, unsigned int __val)
{
  int v4; // ecx@1
  int v5; // eax@1
  unsigned int v6; // edx@2

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      v6 = __first[v5];
      if ( v6 >= __val )
        break;
      __first[v4] = v6;
      v4 = v5;
      v5 = (v5 - 1) / 2;
    }
    while ( v4 > __topIndex );
    __first[v4] = __val;
  }
}

//----- (00439460) --------------------------------------------------------  // acclient.c:118342
void __cdecl _STL::__push_heap(PrefDisplayModeType *__first, int __holeIndex, int __topIndex, PrefDisplayModeType __val)
{
  int v4; // esi@1
  int i; // eax@1
  PrefDisplayModeType *v6; // ecx@2
  PrefDisplayModeType *v7; // esi@3

  v4 = __holeIndex;
  for ( i = (__holeIndex - 1) / 2; v4 > __topIndex; i = (i - 1) / 2 )
  {
    v6 = &__first[i];
    if ( __first[i].nSize >= __val.nSize )
      break;
    v7 = &__first[v4];
    v7->nWidth = v6->nWidth;
    v7->nHeight = v6->nHeight;
    v7->nSize = v6->nSize;
    v7->nModeDesc = v6->nModeDesc;
    v4 = i;
  }
  __first[v4] = __val;
}

//----- (004394E0) --------------------------------------------------------  // acclient.c:118366
PrefDisplayModeType *__cdecl _STL::__copy_backward(PrefDisplayModeType *__first, PrefDisplayModeType *__last, PrefDisplayModeType *__result)
{
  PrefDisplayModeType *v3; // ecx@1
  signed int v4; // edx@2
  PrefDisplayModeType *result; // eax@2

  v3 = __last;
  if ( __last - __first <= 0 )
  {
    result = __result;
  }
  else
  {
    v4 = __last - __first;
    result = __result;
    do
    {
      --v3;
      --result;
      --v4;
      result->nWidth = v3->nWidth;
      result->nHeight = v3->nHeight;
      result->nSize = v3->nSize;
      result->nModeDesc = v3->nModeDesc;
    }
    while ( v4 );
  }
  return result;
}

//----- (00439530) --------------------------------------------------------  // acclient.c:118397
char __cdecl ConsoleCommand_QuitCommand()
{
  char result; // al@1

  result = 1;
  Device::m_bIsDone = 1;
  return result;
}
// 837194: using guessed type bool Device::m_bIsDone;

//----- (00439540) --------------------------------------------------------  // acclient.c:118408
Device::DeviceDialogBoxGateway *__thiscall Device::DeviceDialogBoxGateway::scalar_deleting_destructor(Device::DeviceDialogBoxGateway *this, unsigned int a2)
{
  Device::DeviceDialogBoxGateway *v2; // esi@1

  v2 = this;
  DialogBoxGateway::~DialogBoxGateway((DialogBoxGateway *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00439560) --------------------------------------------------------  // acclient.c:118420
int __stdcall Device::WndProc(HWND__ *hWindow, unsigned int message, unsigned int wParam, int lParam)
{
  LRESULT v4; // ebp@1
  int v5; // eax@1
  int v6; // ebx@1
  bool v7; // zf@27
  int result; // eax@31
  bool fHandled; // [sp+12h] [bp-16h]@1
  bool bImeUiTrapped; // [sp+13h] [bp-15h]@1
  int lImeUiRc; // [sp+14h] [bp-14h]@1
  tagTRACKMOUSEEVENT evt; // [sp+18h] [bp-10h]@51

  v4 = 0;
  fHandled = 1;
  bImeUiTrapped = 0;
  lImeUiRc = 0;
  v5 = KeyStone::IsHelpFocused();
  v6 = lParam;
  if ( !v5 )
    lImeUiRc = UIObject::DynamicCast_UIViewportObject();
  if ( message > 0x200 )
  {
    switch ( message )
    {
      default:
        goto LABEL_29;
      case 0x231u:
        if ( !RenderDevice::render_device || !RenderDevice::render_device->m_presentation.FullScreen )
LABEL_40:
          Device::Deactivate();
        break;
      case 0x232u:
        if ( !RenderDevice::render_device || !RenderDevice::render_device->m_presentation.FullScreen )
          Device::Activate();
        break;
      case 0x218u:
        if ( wParam )
          goto LABEL_29;
        v4 = 1112363332;
        break;
      case 0x281u:
      case 0x282u:
      case 0x283u:
      case 0x284u:
$L136917:
        if ( bImeUiTrapped )
          goto LABEL_31;
        KeyStone::DispatchMessageA(message, wParam, v6, &lParam);
        if ( !lParam )
LABEL_29:
          fHandled = 0;
        break;
      case 0x201u:
      case 0x204u:
      case 0x207u:
      case 0x20Bu:
        SetFocus(Device::m_hWnd);
        goto $L136930;
      case 0x202u:
      case 0x203u:
      case 0x205u:
      case 0x206u:
      case 0x208u:
      case 0x209u:
      case 0x20Au:
      case 0x20Cu:
      case 0x20Du:
        goto $L136930;
      case 0x219u:
        goto $L136934;
      case 0x2A3u:
        Device::m_bTrackLeaveCalled = 0;
        v4 = Device::ForwardToInputManager(hWindow, message, wParam, v6, &fHandled);
        break;
    }
  }
  else
  {
    if ( message == 512 )
    {
$L136930:
      if ( !Device::m_bTrackLeaveCalled )
      {
        Device::m_bTrackLeaveCalled = 1;
        evt.cbSize = 16;
        evt.dwFlags = 2;
        evt.hwndTrack = Device::m_hWnd;
        _TrackMouseEvent(&evt);
      }
$L136931:
      KeyStone::DispatchMessageA(message, wParam, v6, 0);
      goto $L136934;
    }
    if ( message <= 0x1F )
    {
      if ( message != 31 )
      {
        switch ( message )
        {
          case 6u:
            Device::m_bIsMinimized = wParam >> 16 != 0;
            if ( !(_WORD)wParam )
              goto LABEL_40;
            if ( (signed int)(unsigned __int16)wParam > 0
              && (signed int)(unsigned __int16)wParam <= 2
              && wParam >> 16 == 0 )
              Device::Activate();
            goto LABEL_30;
          case 0x1Cu:
            if ( DBCache::IsLoader() )
              gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)((_WORD)wParam == 0));
            if ( !wParam )
              goto LABEL_40;
            if ( !Device::m_bIsMinimized )
              Device::Activate();
            goto LABEL_30;
          case 5u:
            if ( wParam == 1 )
            {
              Device::m_bIsMinimized = 1;
              Device::Deactivate();
            }
            goto LABEL_30;
          case 0x14u:
            if ( !Device::m_bIsReady || !Device::m_bIsActiveApp )
              goto LABEL_29;
            v4 = 1;
            goto LABEL_30;
          case 2u:
          case 0x10u:
            goto $L136916;
          default:
            goto LABEL_29;
          case 7u:
          case 8u:
            break;
        }
      }
$L136934:
      v4 = Device::ForwardToInputManager(hWindow, message, wParam, v6, &fHandled);
      goto LABEL_30;
    }
    switch ( message )
    {
      case 0x112u:
        if ( (unsigned __int16)(wParam & 0xFFF0) == 61536 )
        {
$L136916:
          Device::m_bIsDone = 1;
          break;
        }
        if ( (unsigned __int16)(wParam & 0xFFF0) != 61760 )
        {
          v7 = (unsigned __int16)(wParam & 0xFFF0) == 61808;
LABEL_28:
          if ( !v7 )
            goto LABEL_29;
        }
        break;
      default:
        goto LABEL_29;
      case 0x104u:
        v4 = Device::ForwardToInputManager(hWindow, message, wParam, v6, &fHandled);
        if ( wParam == 115 )
          goto LABEL_29;
        if ( wParam != 13 )
          goto LABEL_36;
        Device::m_bToggleFullScreenMode = 1;
        goto LABEL_29;
      case 0x105u:
        v4 = Device::ForwardToInputManager(hWindow, message, wParam, v6, &fHandled);
LABEL_36:
        v7 = Device::m_bSysKeysEnabled == 0;
        goto LABEL_28;
      case 0x51u:
      case 0x10Du:
      case 0x10Eu:
      case 0x10Fu:
        goto $L136917;
      case 0x100u:
      case 0x101u:
      case 0x102u:
        goto $L136931;
      case 0x106u:
        goto $L136934;
    }
  }
LABEL_30:
  if ( bImeUiTrapped )
  {
LABEL_31:
    result = lImeUiRc;
  }
  else
  {
    if ( !fHandled )
      v4 = DefWindowProcA(hWindow, message, wParam, v6);
    result = v4;
  }
  return result;
}
// 817B00: using guessed type bool Device::m_bIsMinimized;
// 817B01: using guessed type bool Device::m_bSysKeysEnabled;
// 837194: using guessed type bool Device::m_bIsDone;
// 837195: using guessed type bool Device::m_bIsReady;
// 837197: using guessed type bool Device::m_bIsActiveApp;
// 837199: using guessed type bool Device::m_bToggleFullScreenMode;
// 83719A: using guessed type bool Device::m_bTrackLeaveCalled;

//----- (00439A50) --------------------------------------------------------  // acclient.c:118630
void __cdecl Device::SendStringToClipboard(PStringBase<unsigned short> _txt)
{
  PSRefBufferCharData<unsigned short> *v1; // edi@1
  unsigned int v2; // esi@1
  bool v3; // bl@1
  LPVOID v4; // eax@2
  unsigned int v5; // ecx@2
  int v6; // ebp@3
  unsigned int v7; // edx@4
  bool v8; // cf@4
  int v9; // edx@4
  LPVOID v10; // eax@8
  unsigned int v11; // ecx@8
  int v12; // ebp@9
  unsigned int v13; // edx@10
  int v14; // edx@10
  HGLOBAL _txta; // [sp+14h] [bp+4h]@2

  v1 = _txt.m_charbuffer;
  v2 = *(_DWORD *)&_txt.m_charbuffer[-1].m_data[14];
  v3 = Device::m_nOSVersion != 2;
  if ( Device::m_nOSVersion == 2 )
  {
    _txta = GlobalAlloc(0x42u, 2 * v2 + 2);
    v10 = GlobalLock(_txta);
    v11 = 0;
    if ( (signed int)v2 > 0 )
    {
      v12 = (char *)v1 - (_BYTE *)v10;
      do
      {
        v13 = *(_DWORD *)&v1[-1].m_data[14];
        v8 = v11 < v13;
        v14 = (int)((char *)v1 + 2 * v13 - 2);
        if ( v8 )
          v14 = (int)((char *)v10 + v12);
        *(_WORD *)v10 = *(_WORD *)v14;
        ++v11;
        v10 = (char *)v10 + 2;
      }
      while ( (signed int)v11 < (signed int)v2 );
    }
  }
  else
  {
    _txta = GlobalAlloc(0x42u, v2 + 1);
    v4 = GlobalLock(_txta);
    v5 = 0;
    if ( (signed int)v2 > 0 )
    {
      v6 = (int)v1;
      do
      {
        v7 = *(_DWORD *)&v1[-1].m_data[14];
        v8 = v5 < v7;
        v9 = (int)((char *)v1 + 2 * v7 - 2);
        if ( v8 )
          v9 = v6;
        *((_BYTE *)v4 + v5++) = *(_BYTE *)v9;
        v6 += 2;
      }
      while ( (signed int)v5 < (signed int)v2 );
    }
  }
  GlobalUnlock(_txta);
  OpenClipboard(Device::m_hWnd);
  EmptyClipboard();
  SetClipboardData(v3 != 0 ? 1 : 13, _txta);
  CloseClipboard();
  if ( !InterlockedDecrement((volatile LONG *)&v1[-1].m_data[8]) && v1 != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v1[-1].m_data[6])(&v1[-1].m_data[6], 1);
}
// 83719C: using guessed type unsigned __int32 Device::m_nOSVersion;

//----- (00439B50) --------------------------------------------------------  // acclient.c:118705
bool __cdecl Device::DoEventLoop()
{
  bool v0; // al@12
  tagMSG msg; // [sp+4h] [bp-1Ch]@1

  Device::m_bIsWithinEventLoop = 1;
  while ( PeekMessageA(&msg, 0, 0, 0, 1u) )
  {
    if ( msg.message == 18 )
      break;
    if ( !DBCache::IsLoader() && !KeyStone::TranslateAcceleratorA(msg.hwnd, 0, &msg) )
    {
      TranslateMessage(&msg);
      DispatchMessageA(&msg);
    }
  }
  if ( Device::m_bToggleFullScreenMode )
  {
    if ( Render::m_pRenderer && Device::m_bIsActiveApp )
    {
      v0 = Device::m_bAllowFullScreenMode && !byte_817B68;
      byte_817B68 = v0;
    }
    Device::m_bToggleFullScreenMode = 0;
  }
  Device::m_bIsWithinEventLoop = 0;
  return Device::m_bIsDone;
}
// 817B02: using guessed type bool Device::m_bAllowFullScreenMode;
// 817B68: using guessed type char byte_817B68;
// 837194: using guessed type bool Device::m_bIsDone;
// 837197: using guessed type bool Device::m_bIsActiveApp;
// 837198: using guessed type bool Device::m_bIsWithinEventLoop;
// 837199: using guessed type bool Device::m_bToggleFullScreenMode;

//----- (00439C30) --------------------------------------------------------  // acclient.c:118741
char __cdecl Device::SetCursorFromImage(const unsigned int xHotSpot, const unsigned int yHotSpot, RenderSurface *image)
{
  HICON__ *v3; // ecx@0
  char result; // al@2
  HICON__ *hNewIcon; // [sp+0h] [bp-4h]@1

  hNewIcon = v3;
  if ( CreateIconFromRenderSurface(xHotSpot, yHotSpot, image, &hNewIcon) )
  {
    Device::SetCursorFromIcon(hNewIcon);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00439C70) --------------------------------------------------------  // acclient.c:118761
bool __cdecl PSUtils::is_uint32(PStringBase<char> str)
{
  bool v1; // bl@3
  const char *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  _strtoul(str.m_charbuffer->m_data, (char **)&end, 0);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1])
    && str.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&str.m_charbuffer[-2].m_data[12])(&str.m_charbuffer[-2].m_data[12], 1);
  return v1;
}

//----- (00439DA0) --------------------------------------------------------  // acclient.c:118835
void __cdecl _STL::__unguarded_insertion_sort_aux(unsigned int *__first, unsigned int *__last)
{
  unsigned int *i; // edi@1
  unsigned int v3; // esi@2
  unsigned int v4; // ecx@2
  int v5; // eax@2
  unsigned int *v6; // edx@2

  for ( i = __first; i != __last; *v6 = v3 )
  {
    v3 = *i;
    v4 = *(i - 1);
    v5 = (int)(i - 1);
    v6 = i;
    if ( *i < v4 )
    {
      do
      {
        *v6 = v4;
        v4 = *(_DWORD *)(v5 - 4);
        v6 = (unsigned int *)v5;
        v5 -= 4;
      }
      while ( v3 < v4 );
    }
    ++i;
  }
}

//----- (00439DE0) --------------------------------------------------------  // acclient.c:118865
void __cdecl _STL::__unguarded_insertion_sort_aux(PrefDisplayModeType *__first, PrefDisplayModeType *__last)
{
  PrefDisplayModeType *i; // esi@1
  PrefDisplayModeType v3; // ST04_16@2

  for ( i = __first; i != __last; ++i )
  {
    *(_QWORD *)&v3.nWidth = *(_QWORD *)&i->nWidth;
    *(_QWORD *)&v3.nSize = *(_QWORD *)&i->nSize;
    _STL::__unguarded_linear_insert(i, v3);
  }
}

//----- (00439E30) --------------------------------------------------------  // acclient.c:118879
void __cdecl _STL::__adjust_heap(unsigned int *__first, int __holeIndex, int __len, unsigned int __val)
{
  int v4; // ecx@1
  int v5; // eax@1
  bool i; // zf@1

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( __first[v5] < __first[v5 - 1] )
      --v5;
    __first[v4] = __first[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    __first[v4] = __first[v5 - 1];
    v4 = v5 - 1;
  }
  _STL::__push_heap(__first, v4, __holeIndex, __val);
}

//----- (00439E90) --------------------------------------------------------  // acclient.c:118904
void __cdecl _STL::__adjust_heap(PrefDisplayModeType *__first, int __holeIndex, int __len, PrefDisplayModeType __val)
{
  int v4; // ecx@1
  int v5; // eax@1
  bool i; // zf@1
  PrefDisplayModeType *v7; // esi@4
  PrefDisplayModeType *v8; // ecx@4
  PrefDisplayModeType *v9; // esi@6
  PrefDisplayModeType *v10; // ecx@6
  PrefDisplayModeType v11; // ST0C_16@7

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( __first[v5].nSize < *((_DWORD *)&__first[v5] - 2) )
      --v5;
    v7 = &__first[v5];
    v8 = &__first[v4];
    v8->nWidth = v7->nWidth;
    v8->nHeight = v7->nHeight;
    v8->nSize = v7->nSize;
    v8->nModeDesc = v7->nModeDesc;
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    v9 = &__first[v5 - 1];
    v10 = &__first[v4];
    v10->nWidth = v9->nWidth;
    v10->nHeight = v9->nHeight;
    v10->nSize = v9->nSize;
    v10->nModeDesc = v9->nModeDesc;
    v4 = v5 - 1;
  }
  *(_QWORD *)&v11.nWidth = *(_QWORD *)&__val;
  *(_QWORD *)&v11.nSize = *(_QWORD *)&__val.nSize;
  _STL::__push_heap(__first, v4, __holeIndex, v11);
}

//----- (00439F50) --------------------------------------------------------  // acclient.c:118946
unsigned int *__cdecl _STL::__unguarded_partition(unsigned int *__first, unsigned int *__last, unsigned int __pivot)
{
  unsigned int *v3; // ecx@1
  unsigned int *result; // eax@1
  unsigned int v5; // esi@3
  unsigned int v6; // esi@4
  unsigned int v7; // esi@5
  unsigned int v8; // esi@7

  v3 = __last;
  for ( result = __first; ; ++result )
  {
    if ( *result < __pivot )
    {
      do
      {
        v5 = result[1];
        ++result;
      }
      while ( v5 < __pivot );
    }
    v6 = *(v3 - 1);
    --v3;
    if ( __pivot < v6 )
    {
      do
      {
        v7 = *(v3 - 1);
        --v3;
      }
      while ( __pivot < v7 );
    }
    if ( result >= v3 )
      break;
    v8 = *result;
    *result = *v3;
    *v3 = v8;
  }
  return result;
}

//----- (00439FA0) --------------------------------------------------------  // acclient.c:118988
PrefDisplayModeType *__cdecl _STL::__unguarded_partition(PrefDisplayModeType *__first, PrefDisplayModeType *__last, PrefDisplayModeType __pivot)
{
  PrefDisplayModeType *v3; // ecx@1
  PrefDisplayModeType *result; // eax@1
  unsigned int v5; // esi@3
  unsigned int v6; // esi@4
  unsigned int v7; // esi@5
  unsigned int v8; // edx@7
  unsigned int v9; // esi@7
  unsigned int v10; // ST1C_4@7
  unsigned int v11; // ST18_4@7

  v3 = __last;
  for ( result = __first; ; ++result )
  {
    if ( result->nSize < __pivot.nSize )
    {
      do
      {
        v5 = result[1].nSize;
        ++result;
      }
      while ( v5 < __pivot.nSize );
    }
    v6 = v3[-1].nSize;
    --v3;
    if ( __pivot.nSize < v6 )
    {
      do
      {
        v7 = v3[-1].nSize;
        --v3;
      }
      while ( __pivot.nSize < v7 );
    }
    if ( result >= v3 )
      break;
    v8 = result->nWidth;
    v9 = result->nHeight;
    v10 = result->nModeDesc;
    v11 = result->nSize;
    result->nWidth = v3->nWidth;
    result->nHeight = v3->nHeight;
    result->nSize = v3->nSize;
    result->nModeDesc = v3->nModeDesc;
    v3->nWidth = v8;
    v3->nHeight = v9;
    v3->nSize = v11;
    v3->nModeDesc = v10;
  }
  return result;
}

//----- (0043A030) --------------------------------------------------------  // acclient.c:119042
void __cdecl _STL::__make_heap(unsigned int *__first, unsigned int *__last)
{
  int v2; // ebx@1
  int v3; // esi@2
  unsigned int v4; // ecx@3

  v2 = __last - __first;
  if ( v2 >= 2 )
  {
    v3 = (v2 - 2) / 2;
    _STL::__adjust_heap(__first, v3, __last - __first, __first[v3]);
    while ( v3 )
    {
      v4 = __first[v3-- - 1];
      _STL::__adjust_heap(__first, v3, v2, v4);
    }
  }
}

//----- (0043A090) --------------------------------------------------------  // acclient.c:119062
void __cdecl _STL::__make_heap(PrefDisplayModeType *__first, PrefDisplayModeType *__last)
{
  int v2; // edi@1
  int v3; // esi@2
  PrefDisplayModeType *v4; // ebx@2
  PrefDisplayModeType *v5; // edx@2
  PrefDisplayModeType v6; // ST0C_16@2
  PrefDisplayModeType v7; // ST0C_16@3

  v2 = __last - __first;
  if ( v2 >= 2 )
  {
    v3 = (v2 - 2) / 2;
    v4 = &__first[v3];
    v5 = &__first[v3];
    *(_QWORD *)&v6.nWidth = *(_QWORD *)&v5->nWidth;
    *(_QWORD *)&v6.nSize = *(_QWORD *)&v5->nSize;
    _STL::__adjust_heap(__first, v3, __last - __first, v6);
    while ( v3 )
    {
      --v4;
      *(_QWORD *)&v7.nWidth = *(_QWORD *)&v4->nWidth;
      --v3;
      *(_QWORD *)&v7.nSize = *(_QWORD *)&v4->nSize;
      _STL::__adjust_heap(__first, v3, v2, v7);
    }
  }
}

//----- (0043A130) --------------------------------------------------------  // acclient.c:119092
void __thiscall Device::Cleanup(PSRefBufferCharData<char> *this)
{
  char *v1; // esi@2
  char *v2; // esi@5
  char *v3; // esi@8
  char *v4; // esi@11
  CInputManager *v5; // esi@14
  PSRefBufferCharData<char> *v6; // ecx@14
  PStringBase<char> _Name; // [sp+Ch] [bp-4h]@1

  _Name.m_charbuffer = this;
  if ( Device::m_bIsInitialized )
  {
    PStringBase<char>::PStringBase<char>(&_Name, "Exit");
    GlobalRegistry::UnregisterCommand(&_Name);
    v1 = &_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v1 )
      (**(void (__thiscall ***)(char *, signed int))v1)(v1, 1);
    PStringBase<char>::PStringBase<char>(&_Name, "Quit");
    GlobalRegistry::UnregisterCommand(&_Name);
    v2 = &_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
      (**(void (__thiscall ***)(char *, signed int))v2)(v2, 1);
    PStringBase<char>::PStringBase<char>(&_Name, "UpdatePresentation");
    GlobalRegistry::UnregisterCommand(&_Name);
    v3 = &_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
      (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
    PStringBase<char>::PStringBase<char>(&_Name, "ForceDisplayResolution");
    GlobalRegistry::UnregisterCommand(&_Name);
    v4 = &_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    Device::Deactivate();
    v5 = ICIDM::s_cidm;
    Device::m_bIsReady = 0;
    (*(void (__thiscall **)(CInputManager *))&ICIDM::s_cidm->vfptr->gap4[8])(ICIDM::s_cidm);
    v5->vfptr->__vecDelDtor((ICIDM *)v5, 1u);
    ICIDM::s_cidm = 0;
    Device::ShutdownGraphicsEngine(v6);
    if ( Device::m_hWnd )
    {
      DestroyWindow(Device::m_hWnd);
      if ( !Device::m_bIsChildWnd )
        PostQuitMessage(0);
      Device::m_hWnd = 0;
    }
    UserPreferences::UnregisterPreference(&Display_Resolution_3);
    UserPreferences::UnregisterPreference(&Display_FullScreen_3);
    UserPreferences::UnregisterPreference(&Display_RefreshRate_3);
    UserPreferences::UnregisterPreference(&Display_SyncToRefresh_3);
    if ( Device::sm_pDeviceDialogGateway )
      ((void (__stdcall *)(signed int))Device::sm_pDeviceDialogGateway->vfptr->__vecDelDtor)(1);
    Device::sm_pDeviceDialogGateway = 0;
    SetThreadExecutionState(0x80000000);
    Device::m_bIsInitialized = 0;
  }
}
// 837195: using guessed type bool Device::m_bIsReady;
// 837196: using guessed type bool Device::m_bIsInitialized;
// 8371A8: using guessed type bool Device::m_bIsChildWnd;
// 8371AC: using guessed type struct Device::DeviceDialogBoxGateway *Device::sm_pDeviceDialogGateway;

//----- (0043A2D0) --------------------------------------------------------  // acclient.c:119156
char __cdecl Device::ChangePresentation()
{
  char v0; // al@3
  int v1; // edi@3
  int v2; // ebx@3
  int v3; // ebp@3
  int v4; // ecx@4
  int v5; // edx@4
  int v6; // esi@4
  signed int v7; // ebx@5
  signed int v8; // eax@5
  int v9; // edx@10
  HWND__ *v10; // esi@10
  int v11; // ecx@10
  PSRefBufferCharData<unsigned short> *v12; // ecx@22
  PSRefBufferCharData<unsigned short> *v14; // ecx@24
  PSRefBufferCharData<unsigned short> *v15; // ecx@24
  PStringBase<unsigned short> v16; // [sp-1Ch] [bp-94h]@24
  PStringBase<unsigned short> v17; // [sp-18h] [bp-90h]@24
  PStringBase<unsigned short> v18; // [sp-14h] [bp-8Ch]@24
  int v19; // [sp-10h] [bp-88h]@22
  char v20; // [sp+7h] [bp-71h]@3
  int v21; // [sp+8h] [bp-70h]@3
  int v22; // [sp+Ch] [bp-6Ch]@4
  int v23; // [sp+10h] [bp-68h]@4
  int nWindowHeight; // [sp+14h] [bp-64h]@4
  int nFrameWidth; // [sp+18h] [bp-60h]@4
  int nTitleHeight; // [sp+1Ch] [bp-5Ch]@3
  int nScreenWidth; // [sp+24h] [bp-54h]@9
  RenderDeviceConfig config; // [sp+28h] [bp-50h]@2
  tagRECT rWorkArea; // [sp+30h] [bp-48h]@6
  tagRECT rcOldLoc; // [sp+40h] [bp-38h]@2
  RenderDevicePresentation v31; // [sp+50h] [bp-28h]@3
  int v32; // [sp+54h] [bp-24h]@3
  int v33; // [sp+58h] [bp-20h]@3
  RenderDevicePresentation presentation; // [sp+5Ch] [bp-1Ch]@2

  if ( !Render::m_pRenderer )
    return 0;
  qmemcpy(&rcOldLoc, &RenderDevice::render_device->m_presentation, 0x1Cu);
  qmemcpy(&presentation, &rcOldLoc, sizeof(presentation));
  config.hFocusWindow = RenderDevice::render_device->m_config.hFocusWindow;
  *(_DWORD *)&config.bUseStencilBuffer = *(_DWORD *)&RenderDevice::render_device->m_config.bUseStencilBuffer;
  if ( !Device::LoadDisplayPreferences(&presentation) )
    return 0;
  SetWindowLongA(Device::m_hWnd, -16, presentation.FullScreen != 0 ? -1845493760 : 315228160);
  SetWindowPos(Device::m_hWnd, (HWND)0xFFFFFFFE, 0, 0, 0, 0, 0x27u);
  v0 = Render::RestartRenderingSystem(&v31, (RenderDeviceConfig *)&nTitleHeight);
  qmemcpy(&v31, &RenderDevice::render_device->m_presentation, sizeof(v31));
  v1 = v32;
  v20 = v0;
  v2 = 0;
  v3 = 0;
  v21 = v33;
  if ( (_BYTE)presentation.hRenderWindow )
    goto LABEL_22;
  v22 = GetSystemMetrics(7);
  nWindowHeight = GetSystemMetrics(8);
  v23 = GetSystemMetrics(4);
  nFrameWidth = GetSystemMetrics(0);
  v4 = GetSystemMetrics(1);
  v1 += 2 * v22;
  v5 = v23 + 2 * nWindowHeight;
  v6 = v5 + v21;
  v21 += v5;
  if ( (_BYTE)rcOldLoc.left )
  {
    v7 = nFrameWidth - v1 - ((unsigned __int64)(nFrameWidth - v1) >> 32);
    v8 = v4 - v6;
  }
  else
  {
    if ( !GetWindowRect(Device::m_hWnd, (tagRECT *)((char *)&rWorkArea + 4)) )
      goto LABEL_9;
    v7 = rWorkArea.top + rWorkArea.bottom - v1 - ((unsigned __int64)(rWorkArea.top + rWorkArea.bottom - v1) >> 32);
    v8 = rWorkArea.right + rcOldLoc.left - v6;
  }
  v2 = v7 >> 1;
  v3 = v8 / 2;
LABEL_9:
  if ( SystemParametersInfoA(0x30u, 0x10u, &nScreenWidth, 0) )
  {
    v9 = nScreenWidth;
    v10 = config.hFocusWindow;
    v11 = rWorkArea.left - (_DWORD)config.hFocusWindow;
    if ( v1 > *(_DWORD *)&config.bUseStencilBuffer - nScreenWidth )
    {
      v9 = nScreenWidth - v22;
    }
    else
    {
      if ( v1 + v2 > *(_DWORD *)&config.bUseStencilBuffer )
        v2 = *(_DWORD *)&config.bUseStencilBuffer - nScreenWidth - v1;
      v10 = config.hFocusWindow;
      if ( v2 >= nScreenWidth )
        goto LABEL_17;
    }
    v2 = v9;
LABEL_17:
    if ( v21 > v11 )
      goto LABEL_29;
    if ( v21 + v3 > rWorkArea.left )
      v3 = v11 - v21;
    if ( v3 < (signed int)v10 )
LABEL_29:
      v3 = (int)v10;
  }
LABEL_22:
  SetWindowPos(Device::m_hWnd, (HWND)(((_BYTE)presentation.hRenderWindow != 0) - 2), v2, v3, v1, v21, 0x100u);
  v19 = 0;
  if ( !v20 )
  {
    v18.m_charbuffer = v12;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v18, &word_794320);
    v17.m_charbuffer = v14;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v17, &word_794320);
    v16.m_charbuffer = v15;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v16, &word_794320);
    PlatformString::DisplayString(0x80u, v16, v17, v18, (PlatformString::DisplayStringMode)v19);
    _exit(1);
  }
  UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 0xEu, v19);
  return v20;
}

//----- (0043A540) --------------------------------------------------------  // acclient.c:119282
char __cdecl Device::SaveScreenshot(PStringBase<char> *o_strFileName)
{
  char result; // al@2
  int v2; // ebx@3
  signed int v3; // esi@4
  PSRefBufferCharData<char> *v4; // eax@8
  int v5; // esi@9
  PSRefBufferCharData<char> *v6; // eax@12
  char *v7; // esi@13
  char *v8; // esi@16
  char *v9; // esi@19
  char fResult; // [sp+11h] [bp-Dh]@7
  PStringBase<char> sFilename; // [sp+12h] [bp-Ch]@4
  PStringBase<char> strDirectory; // [sp+16h] [bp-8h]@4
  PStringBase<char> strPreferenceFile; // [sp+1Ah] [bp-4h]@4

  if ( Render::m_pRenderer )
  {
    v2 = Device::GetScreenshotSurface();
    if ( v2 )
    {
      strPreferenceFile.m_charbuffer = UserPreferences::sm_strDefaultFile.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]);
      strDirectory.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PSUtils::get_directory(&strDirectory, &strPreferenceFile);
      sFilename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v3 = 0;
      do
      {
        PStringBase<char>::sprintf(&sFilename, "%sScreenShot%05d.jpg", strDirectory.m_charbuffer, v3);
        if ( !(unsigned __int8)PSUtils::check_access(&sFilename, 0) )
          break;
        ++v3;
      }
      while ( v3 < 100000 );
      fResult = RenderSurface::SaveJPG((RenderSurface *)v2, &sFilename);
      if ( fResult )
      {
        v4 = o_strFileName->m_charbuffer;
        if ( o_strFileName->m_charbuffer != sFilename.m_charbuffer )
        {
          v5 = (int)&v4[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
          v6 = sFilename.m_charbuffer;
          o_strFileName->m_charbuffer = sFilename.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&v6[-1]);
        }
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 20))(v2);
      v7 = &sFilename.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&sFilename.m_charbuffer[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = &strDirectory.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strDirectory.m_charbuffer[-1]) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      v9 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) )
      {
        if ( v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      }
      result = fResult;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0043A6B0) --------------------------------------------------------  // acclient.c:119361
void __thiscall Device::Show16BitWarning(void *this)
{
  PSRefBufferCharData<unsigned short> *v1; // ecx@1
  PSRefBufferCharData<unsigned short> *v2; // ecx@1
  PStringBase<unsigned short> v3; // [sp-10h] [bp-10h]@1
  PStringBase<unsigned short> v4; // [sp-Ch] [bp-Ch]@1
  PStringBase<unsigned short> v5; // [sp-8h] [bp-8h]@1
  PlatformString::DisplayStringMode v6; // [sp-4h] [bp-4h]@1

  v6 = 1;
  v5.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v5, &word_794320);
  v4.m_charbuffer = v1;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v4, &word_794320);
  v3.m_charbuffer = v2;
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v3, &word_794320);
  PlatformString::DisplayString(0x7Bu, v3, v4, v5, v6);
}

//----- (0043A6F0) --------------------------------------------------------  // acclient.c:119381
char __thiscall SmartArray<PrefDisplayModeType,1>::AddToEnd(SmartArray<PrefDisplayModeType,1> *this, PrefDisplayModeType *i_rData)
{
  SmartArray<PrefDisplayModeType,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<RenderDisplayModeType,1>::grow((SmartArray<RenderDisplayModeType,1> *)v2, v4)) != 0) )
  {
    v2->m_data[v2->m_num++] = *i_rData;
    result = 1;
  }
  return result;
}

//----- (0043A750) --------------------------------------------------------  // acclient.c:119401
void __cdecl Device::ForceDisplayResolution(const bool _bEnable, const unsigned int _nWidth, const unsigned int _nHeight)
{
  bool v3; // cl@1
  unsigned int v4; // eax@10
  unsigned int v5; // eax@11
  RenderDevicePresentation presentation; // [sp+0h] [bp-1Ch]@9

  v3 = Device::m_bUseForcedResolution;
  Device::m_nForcedWidth = _nWidth;
  Device::m_nForcedHeight = _nHeight;
  Device::m_bUseForcedResolution = _bEnable;
  if ( Render::m_pRenderer )
  {
    if ( Device::m_bIsInitialized )
    {
      if ( _bEnable )
      {
        if ( RenderDevice::GetDisplayWidth(RenderDevice::render_device) == Device::m_nForcedWidth
          && RenderDevice::GetDisplayHeight(RenderDevice::render_device) == Device::m_nForcedHeight )
          return;
      }
      else
      {
        if ( !v3 )
          return;
        presentation.Width = 800;
        presentation.Height = 600;
        if ( Device::LoadDisplayPreferences(&presentation) )
        {
          v4 = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
          if ( v4 == presentation.Width )
          {
            v5 = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
            if ( v5 == presentation.Height )
              return;
          }
        }
      }
    }
    if ( Render::m_pRenderer )
    {
      if ( Device::m_bIsInitialized )
        Device::ChangePresentation();
    }
  }
}
// 837196: using guessed type bool Device::m_bIsInitialized;
// 8371A0: using guessed type bool Device::m_bUseForcedResolution;

//----- (0043A830) --------------------------------------------------------  // acclient.c:119451
char __cdecl Device::ConsoleCommand_ForceDisplayResolution(PStringBaseArray<char> *i_asArgs)
{
  unsigned int v1; // eax@1
  char result; // al@2
  PStringBase<char> v3; // ST08_4@4
  PStringBase<char> v4; // ST08_4@5
  PStringBase<char> *v5; // esi@6
  unsigned __int32 v6; // ST08_4@6
  unsigned __int32 v7; // eax@6

  v1 = i_asArgs->m_num;
  if ( v1 )
  {
    if ( v1 >= 2
      && (v3.m_charbuffer = i_asArgs->m_data->m_charbuffer,
          InterlockedIncrement((volatile LONG *)&v3.m_charbuffer[-1]),
          PSUtils::is_uint32(v3))
      && (v4.m_charbuffer = i_asArgs->m_data[1].m_charbuffer,
          InterlockedIncrement((volatile LONG *)&v4.m_charbuffer[-1]),
          PSUtils::is_uint32(v4)) )
    {
      v5 = i_asArgs->m_data;
      v6 = PStringBase<char>::to_uint32(i_asArgs->m_data + 1);
      v7 = PStringBase<char>::to_uint32(v5);
      Device::ForceDisplayResolution(1, v7, v6);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    Device::ForceDisplayResolution(0, Device::m_nForcedWidth, Device::m_nForcedHeight);
    result = 1;
  }
  return result;
}

//----- (0043A8D0) --------------------------------------------------------  // acclient.c:119492
void __cdecl Device::AllowFullScreenMode(const bool _Allow)
{
  Device::m_bAllowFullScreenMode = _Allow;
  if ( Render::m_pRenderer
    && Device::m_bIsInitialized
    && RenderDevice::render_device->m_presentation.FullScreen
    && !_Allow )
    Device::ChangePresentation();
}
// 817B02: using guessed type bool Device::m_bAllowFullScreenMode;
// 837196: using guessed type bool Device::m_bIsInitialized;

//----- (0043A910) --------------------------------------------------------  // acclient.c:119505
bool __cdecl Device::GetStringFromClipboard()
{
  bool v0; // bl@1
  UINT v1; // esi@1
  HANDLE v3; // eax@3
  void *v4; // ebp@3
  unsigned int v5; // eax@3
  unsigned int v6; // edi@3
  LPVOID v7; // ebx@4
  const unsigned __int16 *v8; // esi@6
  signed int i; // eax@7
  unsigned int v10; // edi@10
  LPVOID v11; // ebx@10
  void *v12; // eax@11
  int v13; // ecx@13
  PStringBase<unsigned short> *v14; // [sp+4h] [bp-4h]@0

  v0 = Device::m_nOSVersion != 2;
  v1 = Device::m_nOSVersion != 2 ? 1 : 13;
  if ( !IsClipboardFormatAvailable(v1) )
    return 0;
  OpenClipboard(Device::m_hWnd);
  v3 = GetClipboardData(v1);
  v4 = v3;
  v5 = GlobalSize(v3);
  v6 = v5;
  if ( v0 )
  {
    v7 = GlobalLock(v4);
    if ( !v7 )
      return 0;
    v8 = (const unsigned __int16 *)operator new[](2 * v6);
    if ( v8 )
    {
      for ( i = 0; i < (signed int)v6; ++i )
        v8[i] = *((_BYTE *)v7 + i);
    }
  }
  else
  {
    v10 = v5 >> 1;
    v11 = GlobalLock(v4);
    if ( !v11 )
      return 0;
    v12 = operator new[](2 * v10);
    v8 = (const unsigned __int16 *)v12;
    if ( v12 && (signed int)v10 > 0 )
    {
      v13 = (_BYTE *)v11 - (_BYTE *)v12;
      do
      {
        *(_WORD *)v12 = *(_WORD *)((char *)v12 + v13);
        v12 = (char *)v12 + 2;
        --v10;
      }
      while ( v10 );
    }
  }
  GlobalUnlock(v4);
  CloseClipboard();
  PStringBase<unsigned short>::set(v14, v8);
  operator delete[]((void *)v8);
  return *(_DWORD *)&v14->m_charbuffer[-1].m_data[14] != 1;
}
// 43A910: could not find valid save-restore pair for ebp
// 43A910: could not find valid save-restore pair for edi
// 83719C: using guessed type unsigned __int32 Device::m_nOSVersion;

//----- (0043AA20) --------------------------------------------------------  // acclient.c:119574
char __cdecl Device::StartupGraphicsEngine(int _nWidth, int _nHeight, bool _bWindowed)
{
  HDC v3; // esi@2
  int v4; // edi@2
  void *v5; // ecx@2
  PSRefBufferCharData<unsigned short> *v6; // ecx@4
  PSRefBufferCharData<unsigned short> *v7; // ecx@4
  char result; // al@14
  PStringBase<unsigned short> v9; // [sp-10h] [bp-40h]@4
  PStringBase<unsigned short> v10; // [sp-Ch] [bp-3Ch]@4
  PStringBase<unsigned short> v11; // [sp-8h] [bp-38h]@4
  PlatformString::DisplayStringMode v12; // [sp-4h] [bp-34h]@4
  RenderDeviceConfig deviceConfig; // [sp+Ch] [bp-24h]@8
  RenderDevicePresentation presentation; // [sp+14h] [bp-1Ch]@8

  if ( _bWindowed )
  {
    v3 = CreateICA("Display", 0, 0, 0);
    v4 = GetDeviceCaps(v3, 12);
    DeleteDC(v3);
    if ( v4 == 16 )
    {
      Device::Show16BitWarning(v5);
    }
    else if ( v4 != 32 )
    {
      v12 = 0;
      v11.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v5;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v11, &word_794320);
      v10.m_charbuffer = v6;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v10, &word_794320);
      v9.m_charbuffer = v7;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v9, &word_794320);
      PlatformString::DisplayString(0x7Du, v9, v10, v11, v12);
      _exit(1);
    }
  }
  presentation.Width = _nWidth;
  presentation.hRenderWindow = 0;
  presentation.FSRefreshRate = 0;
  presentation.FSBitsPerPixel = 32;
  presentation.FSTripleBuffering = 0;
  presentation.FSSyncToDisplayRefresh = 0;
  presentation.Antialiasing = 0;
  deviceConfig.hFocusWindow = 0;
  deviceConfig.bUseStencilBuffer = 1;
  deviceConfig.bSoftwareVertexProcessing = 0;
  deviceConfig.bUsePureDevice = 1;
  presentation.Height = _nHeight;
  if ( !Device::m_bAllowFullScreenMode || (presentation.FullScreen = 1, _bWindowed) )
    presentation.FullScreen = 0;
  if ( Device::LoadDisplayPreferences(&presentation)
    && (presentation.hRenderWindow = Device::m_hWnd,
        deviceConfig.hFocusWindow = Device::m_hWnd,
        Render::StartupRenderingDevice(&presentation, &deviceConfig))
    && SceneTool::Startup() )
  {
    Render::Init();
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 817B02: using guessed type bool Device::m_bAllowFullScreenMode;

//----- (0043AB50) --------------------------------------------------------  // acclient.c:119643
char __cdecl Device::InitWindow(int width, int height, bool bWindowed)
{
  char result; // al@2

  Device::m_bIsReady = 0;
  if ( Device::StartupGraphicsEngine(width, height, bWindowed) )
  {
    result = 1;
    Device::m_bIsReady = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 837195: using guessed type bool Device::m_bIsReady;

//----- (0043AB80) --------------------------------------------------------  // acclient.c:119662
void __cdecl _STL::__insertion_sort(unsigned int *__first, unsigned int *__last)
{
  unsigned int *v2; // esi@2
  int v3; // ebp@3
  unsigned int v4; // edi@4
  unsigned int v5; // ecx@8
  int v6; // eax@8
  unsigned int *i; // edx@8

  if ( __first != __last )
  {
    v2 = __first + 1;
    if ( __first + 1 != __last )
    {
      v3 = 4 - (_DWORD)__first;
      do
      {
        v4 = *v2;
        if ( *v2 >= *__first )
        {
          v5 = *(v2 - 1);
          v6 = (int)(v2 - 1);
          for ( i = v2; v4 < v5; v6 -= 4 )
          {
            *i = v5;
            v5 = *(_DWORD *)(v6 - 4);
            i = (unsigned int *)v6;
          }
          *i = v4;
        }
        else
        {
          if ( (signed int)((char *)v2 + v3 - 4) > 0 )
            _memmove((void *)((char *)v2 - ((char *)v2 + v3 - 4) + 4), __first, (size_t)((char *)v2 + v3 - 4));
          *__first = v4;
        }
        ++v2;
      }
      while ( v2 != __last );
    }
  }
}

//----- (0043AC00) --------------------------------------------------------  // acclient.c:119706
void __cdecl _STL::__linear_insert(PrefDisplayModeType *__first, PrefDisplayModeType *__last, PrefDisplayModeType __val)
{
  PrefDisplayModeType *v3; // esi@1
  unsigned int v4; // edi@1
  unsigned int v5; // eax@2
  unsigned int v6; // ecx@2
  PrefDisplayModeType v7; // ST04_16@3

  v3 = __first;
  v4 = __val.nSize;
  if ( __val.nSize >= __first->nSize )
  {
    *(_QWORD *)&v7.nWidth = *(_QWORD *)&__val;
    *(_QWORD *)&v7.nSize = *(_QWORD *)&__val.nSize;
    _STL::__unguarded_linear_insert(__last, v7);
  }
  else
  {
    _STL::__copy_backward(__first, __last, __last + 1);
    v5 = __val.nHeight;
    v6 = __val.nModeDesc;
    v3->nWidth = __val.nWidth;
    v3->nHeight = v5;
    v3->nSize = v4;
    v3->nModeDesc = v6;
  }
}

//----- (0043AC80) --------------------------------------------------------  // acclient.c:119735
void __cdecl _STL::sort_heap(unsigned int *__first, unsigned int *__last)
{
  signed int v2; // eax@1
  unsigned int v3; // ecx@2
  int v4; // edi@2

  v2 = (char *)__last - (char *)__first;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v3 = *(unsigned int *)((char *)__first + v2 - 4);
      v4 = v2 - 4;
      *(unsigned int *)((char *)__first + v2 - 4) = *__first;
      _STL::__adjust_heap(__first, 0, (v2 - 4) >> 2, v3);
      v2 = v4;
    }
    while ( (signed int)(v4 & 0xFFFFFFFC) > 4 );
  }
}

//----- (0043ACD0) --------------------------------------------------------  // acclient.c:119757
void __cdecl _STL::sort_heap(PrefDisplayModeType *__first, PrefDisplayModeType *__last)
{
  signed int v2; // ecx@1
  char *v3; // edi@2
  unsigned int v4; // edx@2
  unsigned int v5; // ebx@2
  __int64 v6; // ST38_8@2
  int v7; // edi@2
  PrefDisplayModeType v8; // ST0C_16@2

  v2 = (char *)__last - (char *)__first;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFF0) > 16 )
  {
    do
    {
      v3 = (char *)&__first[-1] + v2;
      v4 = *(_DWORD *)v3;
      v5 = *((_DWORD *)v3 + 1);
      v6 = *((_QWORD *)v3 + 1);
      *(_OWORD *)v3 = *__first;
      v7 = v2 - 16;
      *(_QWORD *)&v8.nWidth = __PAIR__(v5, v4);
      *(_QWORD *)&v8.nSize = v6;
      _STL::__adjust_heap(__first, 0, (v2 - 16) >> 4, v8);
      v2 = v7;
    }
    while ( (signed int)(v7 & 0xFFFFFFF0) > 16 );
  }
}

//----- (0043AD70) --------------------------------------------------------  // acclient.c:119788
void __cdecl _STL::__insertion_sort(PrefDisplayModeType *__first, PrefDisplayModeType *__last)
{
  PrefDisplayModeType *i; // esi@2
  PrefDisplayModeType v3; // ST08_16@3

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      *(_QWORD *)&v3.nWidth = *(_QWORD *)&i->nWidth;
      *(_QWORD *)&v3.nSize = *(_QWORD *)&i->nSize;
      _STL::__linear_insert(__first, i, v3);
    }
  }
}

//----- (0043ADD0) --------------------------------------------------------  // acclient.c:119805
void __cdecl _STL::__partial_sort(unsigned int *__first, unsigned int *__middle, unsigned int *__last)
{
  unsigned int *i; // edi@1
  unsigned int v4; // eax@2

  _STL::__make_heap(__first, __middle);
  for ( i = __middle; i < __last; ++i )
  {
    v4 = *i;
    if ( *i < *__first )
    {
      *i = *__first;
      _STL::__adjust_heap(__first, 0, __middle - __first, v4);
    }
  }
  _STL::sort_heap(__first, __middle);
}

//----- (0043AE40) --------------------------------------------------------  // acclient.c:119824
void __cdecl _STL::__partial_sort(PrefDisplayModeType *__first, PrefDisplayModeType *__middle, PrefDisplayModeType *__last)
{
  PrefDisplayModeType *v3; // ebx@1
  PrefDisplayModeType *i; // edi@1
  unsigned int v5; // eax@3
  unsigned int v6; // ecx@3
  __int64 v7; // kr00_8@3
  __int64 v8; // ST38_8@3
  PrefDisplayModeType v9; // ST0C_16@3

  v3 = __middle;
  _STL::__make_heap(__first, __middle);
  for ( i = __middle; i < __last; ++i )
  {
    if ( i->nSize < __first->nSize )
    {
      v5 = i->nWidth;
      v6 = i->nHeight;
      v7 = *(_QWORD *)&i->nSize;
      v8 = *(_QWORD *)&i->nSize;
      *i = *__first;
      v3 = __middle;
      *(_QWORD *)&v9.nWidth = __PAIR__(v6, v5);
      *(_QWORD *)&v9.nSize = v8;
      _STL::__adjust_heap(__first, 0, __middle - __first, v9);
    }
  }
  _STL::sort_heap(__first, v3);
}

//----- (0043AF00) --------------------------------------------------------  // acclient.c:119855
void __cdecl _STL::__introsort_loop(unsigned int *__first, unsigned int *__last, unsigned int *__formal, int __depth_limit, _STL::less<unsigned long> __comp)
{
  unsigned int *v5; // ebx@1
  int v6; // ebp@2
  unsigned int v7; // ecx@4
  int v8; // eax@4
  unsigned int v9; // edx@4
  unsigned int *v10; // eax@4
  unsigned int v11; // ebp@4
  unsigned int *v12; // esi@12
  int __depth_limita; // [sp+18h] [bp+10h]@4

  v5 = __last;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    v6 = __depth_limit;
    do
    {
      if ( !v6 )
      {
        _STL::__partial_sort(__first, v5, v5);
        return;
      }
      v7 = *__first;
      v8 = (v5 - __first) / 2;
      v9 = __first[v8];
      v10 = &__first[v8];
      __depth_limita = v6 - 1;
      v11 = *(v5 - 1);
      if ( *__first >= v9 )
      {
        if ( v7 < v11 )
          goto LABEL_9;
        if ( v9 < v11 )
        {
LABEL_11:
          v10 = v5 - 1;
          goto LABEL_12;
        }
      }
      else if ( v9 >= v11 )
      {
        if ( v7 < v11 )
          goto LABEL_11;
LABEL_9:
        v10 = __first;
        goto LABEL_12;
      }
LABEL_12:
      v6 = __depth_limita;
      v12 = _STL::__unguarded_partition(__first, v5, *v10);
      _STL::__introsort_loop(v12, v5, 0, __depth_limita, __comp);
      v5 = v12;
    }
    while ( (signed int)(((char *)v12 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}

//----- (0043AFB0) --------------------------------------------------------  // acclient.c:119914
void __cdecl _STL::__introsort_loop(PrefDisplayModeType *__first, PrefDisplayModeType *__last, PrefDisplayModeType *__formal, int __depth_limit, _STL::less<PrefDisplayModeType> __comp)
{
  PrefDisplayModeType *v5; // ebx@1
  int v6; // ebp@2
  unsigned int v7; // ecx@4
  int v8; // eax@4
  unsigned int v9; // edx@4
  PrefDisplayModeType *v10; // eax@4
  unsigned int v11; // ebp@4
  PrefDisplayModeType v12; // ST1C_16@12
  PrefDisplayModeType *v13; // esi@12
  int __depth_limita; // [sp+20h] [bp+10h]@4

  v5 = __last;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFF0) > 256 )
  {
    v6 = __depth_limit;
    do
    {
      if ( !v6 )
      {
        _STL::__partial_sort(__first, v5, v5);
        return;
      }
      v7 = __first->nSize;
      v8 = (v5 - __first) / 2;
      v9 = __first[v8].nSize;
      v10 = &__first[v8];
      __depth_limita = v6 - 1;
      v11 = v5[-1].nSize;
      if ( v7 >= v9 )
      {
        if ( v7 < v11 )
          goto LABEL_9;
        if ( v9 < v11 )
        {
LABEL_11:
          v10 = v5 - 1;
          goto LABEL_12;
        }
      }
      else if ( v9 >= v11 )
      {
        if ( v7 < v11 )
          goto LABEL_11;
LABEL_9:
        v10 = __first;
        goto LABEL_12;
      }
LABEL_12:
      *(_QWORD *)&v12.nWidth = *(_QWORD *)&v10->nWidth;
      *(_QWORD *)&v12.nSize = *(_QWORD *)&v10->nSize;
      v6 = __depth_limita;
      v13 = _STL::__unguarded_partition(__first, v5, v12);
      _STL::__introsort_loop(v13, v5, 0, __depth_limita, __comp);
      v5 = v13;
    }
    while ( (signed int)(((char *)v13 - (char *)__first) & 0xFFFFFFF0) > 256 );
  }
}

//----- (0043B090) --------------------------------------------------------  // acclient.c:119976
char __cdecl Device::InitializeDisplayPreferences()
{
  unsigned int *v0; // edx@1
  PrefDisplayModeType *v1; // ebp@2
  unsigned int v2; // ebx@2
  char *v3; // edi@2
  unsigned int v4; // eax@2
  unsigned int v5; // esi@3
  unsigned int v6; // ecx@8
  int v7; // eax@8
  unsigned int v8; // edx@8
  unsigned int v9; // eax@10
  PrefDisplayModeType *v10; // esi@11
  bool v11; // cf@19
  PrefDisplayModeType *v12; // esi@21
  int v13; // eax@22
  int i; // ecx@22
  unsigned int *v15; // edi@28
  unsigned int *v16; // ebx@28
  unsigned int v17; // esi@29
  signed int v18; // eax@29
  int j; // ecx@29
  unsigned int *v20; // ebp@35
  int v21; // edi@35
  unsigned int v22; // ebx@35
  PrefDisplayModeType *v23; // esi@36
  unsigned int v24; // esi@40
  unsigned int v25; // eax@40
  PStringBase<char> *v26; // ebp@40
  unsigned int v27; // ebx@41
  GlobalRegistryInstance *v28; // eax@46
  GlobalRegistryInstance *v29; // eax@47
  int v30; // eax@52
  PStringBase<char> *v31; // esi@54
  GlobalRegistryInstance *v32; // eax@57
  GlobalRegistryInstance *v33; // eax@58
  int v34; // eax@63
  PStringBase<char> *v35; // esi@65
  unsigned int v36; // ebx@68
  GlobalRegistryInstance *v37; // eax@68
  GlobalRegistryInstance *v38; // eax@69
  int v39; // eax@74
  PStringBase<char> *v40; // esi@76
  GlobalRegistryInstance *v41; // eax@79
  GlobalRegistryInstance *v42; // eax@80
  int v43; // eax@85
  PStringBase<char> *v44; // esi@87
  PSRefBufferCharData<char> *v45; // eax@91
  void *v46; // ebx@91
  int v47; // edi@91
  int v48; // eax@91
  int v49; // ebp@92
  int v50; // esi@93
  int v51; // esi@93
  int v52; // eax@99
  void *v53; // ebx@99
  unsigned int v54; // edi@99
  int v55; // eax@99
  int v56; // ebp@100
  int v57; // esi@101
  int v58; // esi@101
  FixedArray<PStringBase<char> > RefreshRateNameStrings; // [sp+Ch] [bp-7Ch]@2
  unsigned int RefreshRate; // [sp+14h] [bp-74h]@8
  int v62; // [sp+18h] [bp-70h]@34
  unsigned int DefaultResolution; // [sp+1Ch] [bp-6Ch]@3
  FixedArray<unsigned long> ResolutionValues; // [sp+20h] [bp-68h]@34
  PrefDisplayModeType PrefMode; // [sp+28h] [bp-60h]@10
  SmartArray<PrefDisplayModeType,1> PrefDisplayModes; // [sp+38h] [bp-50h]@2
  SmartArray<unsigned long,1> PrefRefreshRates; // [sp+44h] [bp-44h]@2
  PixelFormatDesc PFD; // [sp+50h] [bp-38h]@7

  v0 = 0;
  if ( !Render::m_pRenderer )
    return 0;
  v1 = 0;
  v2 = 0;
  v3 = (char *)&Render::m_pRenderer->m_DisplayModes;
  PrefDisplayModes.m_data = 0;
  PrefDisplayModes.m_sizeAndDeallocate = 0;
  PrefDisplayModes.m_num = 0;
  PrefRefreshRates.m_data = 0;
  PrefRefreshRates.m_sizeAndDeallocate = 0;
  PrefRefreshRates.m_num = 0;
  v4 = Render::m_pRenderer->m_DisplayModes.m_num;
  RefreshRateNameStrings.m_data = 0;
  if ( v4 == -1 )
    goto LABEL_21;
  v5 = 0;
  DefaultResolution = 0;
  do
  {
    if ( (unsigned int)RefreshRateNameStrings.m_data >= v4 )
    {
      v6 = 1024;
      v8 = 768;
      RefreshRate = 0;
    }
    else
    {
      if ( *(_DWORD *)(v5 + *(_DWORD *)v3) < 0x320u )
        goto LABEL_19;
      if ( *(_DWORD *)(v5 + *(_DWORD *)v3 + 4) < 0x258u )
        goto LABEL_19;
      ClipPlane::ClipPlane((ClipPlane *)&PFD);
      PixelFormatDesc::SetFormat(&PFD, *(PixelFormatID *)(v5 + *(_DWORD *)v3 + 8));
      v1 = PrefDisplayModes.m_data;
      v2 = PrefDisplayModes.m_num;
      if ( PFD.bitsPerPixel < 0x20u )
        goto LABEL_19;
      v6 = *(_DWORD *)(v5 + *(_DWORD *)v3);
      v7 = v5 + *(_DWORD *)v3;
      v8 = *(_DWORD *)(v7 + 4);
      RefreshRate = *(_DWORD *)(v7 + 12);
    }
    PrefMode.nSize = v6 * v8;
    PrefMode.nModeDesc = v8 | (v6 << 16);
    v9 = 0;
    PrefMode.nWidth = v6;
    PrefMode.nHeight = v8;
    if ( !v2 )
      goto LABEL_17;
    v10 = v1;
    while ( v10->nWidth != v6 || v10->nHeight != v8 )
    {
      ++v9;
      ++v10;
      if ( v9 >= v2 )
        goto LABEL_17;
    }
    if ( v9 == -1 )
LABEL_17:
      SmartArray<PrefDisplayModeType,1>::AddToEnd(&PrefDisplayModes, &PrefMode);
    SmartArray<QualityChangeHandler *,1>::add_unique(
      (SmartArray<UIElement *,1> *)&PrefRefreshRates,
      (UIElement *const *)&RefreshRate);
    v2 = PrefDisplayModes.m_num;
    v1 = PrefDisplayModes.m_data;
    v5 = DefaultResolution;
LABEL_19:
    v4 = *((_DWORD *)v3 + 2);
    v5 += 16;
    v11 = (PSRefBufferCharData<char> **)((char *)&RefreshRateNameStrings.m_data->m_charbuffer + 1) < (PSRefBufferCharData<char> **)(v4 + 1);
    RefreshRateNameStrings.m_data = (PStringBase<char> *)((char *)RefreshRateNameStrings.m_data + 1);
    DefaultResolution = v5;
  }
  while ( v11 );
  v0 = PrefRefreshRates.m_data;
LABEL_21:
  v12 = &v1[v2];
  if ( v1 != v12 )
  {
    v13 = (signed int)(16 * v2) >> 4;
    for ( i = 0; v13 != 1; ++i )
      v13 >>= 1;
    _STL::__introsort_loop(v1, &v1[v2], 0, 2 * i, (_STL::less<PrefDisplayModeType>)DefaultResolution);
    if ( (signed int)(16 * v2 & 0xFFFFFFF0) <= 256 )
    {
      _STL::__insertion_sort(v1, &v1[v2]);
    }
    else
    {
      _STL::__insertion_sort(v1, v1 + 16);
      _STL::__unguarded_insertion_sort_aux(v1 + 16, v12);
    }
    v0 = PrefRefreshRates.m_data;
  }
  v15 = &v0[PrefRefreshRates.m_num];
  v16 = v0;
  if ( v0 != v15 )
  {
    v17 = 4 * PrefRefreshRates.m_num;
    v18 = (signed int)(4 * PrefRefreshRates.m_num) >> 2;
    for ( j = 0; v18 != 1; ++j )
      v18 >>= 1;
    _STL::__introsort_loop(v0, &v0[PrefRefreshRates.m_num], 0, 2 * j, (_STL::less<unsigned long>)DefaultResolution);
    if ( (signed int)(v17 & 0xFFFFFFFC) <= 64 )
    {
      _STL::__insertion_sort(v16, v15);
    }
    else
    {
      _STL::__insertion_sort(v16, v16 + 16);
      _STL::__unguarded_insertion_sort_aux(v16 + 16, v15);
    }
  }
  RefreshRate = 0;
  v62 = 0;
  FixedArray<PStringBase<char>>::Create((FixedArray<PStringBase<char> > *)&RefreshRate, PrefDisplayModes.m_num);
  ResolutionValues.m_data = (unsigned int *)operator new[](4 * PrefDisplayModes.m_num);
  DefaultResolution = -1;
  RefreshRateNameStrings.m_data = 0;
  if ( PrefDisplayModes.m_num > 0 )
  {
    v20 = ResolutionValues.m_data;
    v21 = 0;
    v22 = RefreshRate - (_DWORD)ResolutionValues.m_data;
    do
    {
      v23 = &PrefDisplayModes.m_data[v21];
      PStringBase<char>::sprintf(
        (PStringBase<char> *)((char *)v20 + v22),
        "%ix%i",
        PrefDisplayModes.m_data[v21].nWidth,
        PrefDisplayModes.m_data[v21].nHeight);
      *v20 = PrefDisplayModes.m_data[v21].nModeDesc;
      if ( v23->nWidth == 1024 && v23->nHeight == 768 )
        DefaultResolution = v23->nModeDesc;
      ++v21;
      ++v20;
      RefreshRateNameStrings.m_data = (PStringBase<char> *)((char *)RefreshRateNameStrings.m_data + 1);
    }
    while ( (unsigned int)RefreshRateNameStrings.m_data < PrefDisplayModes.m_num );
  }
  v24 = 0;
  RefreshRateNameStrings.m_data = 0;
  RefreshRateNameStrings.m_num = 0;
  FixedArray<PStringBase<char>>::Create(&RefreshRateNameStrings, PrefRefreshRates.m_num);
  v25 = (unsigned int)operator new[](4 * PrefRefreshRates.m_num);
  v26 = RefreshRateNameStrings.m_data;
  PrefMode.nWidth = v25;
  if ( PrefRefreshRates.m_num > 0 )
  {
    v27 = PrefMode.nWidth - (_DWORD)RefreshRateNameStrings.m_data;
    do
    {
      if ( PrefRefreshRates.m_data[v24] )
        PStringBase<char>::sprintf(&v26[v24], "%ihz", PrefRefreshRates.m_data[v24]);
      else
        PStringBase<char>::set(&v26[v24], "Auto");
      *(PSRefBufferCharData<char> **)((char *)&v26[v24].m_charbuffer + v27) = (PSRefBufferCharData<char> *)PrefRefreshRates.m_data[v24];
      ++v24;
    }
    while ( v24 < PrefRefreshRates.m_num );
  }
  byte_817B68 = 1;
  Device::m_DisplayPrefs.Resolution = DefaultResolution;
  dword_817B6C = 0;
  PStringBase<char>::allocate_ref_buffer(
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    strlen("Selects display resolution"));
  strcpy((char *)RefreshRateNameStrings.m_data, "Selects display resolution");
  GlobalRegistry::RegisterVariableInternal(
    &Device::m_DisplayPrefs,
    GRVDataType_UInt32,
    &Display_Resolution_3,
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    0,
    PrefDisplayModes.m_num,
    (PStringBase<char> *)RefreshRate,
    ResolutionValues.m_data);
  v28 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v29 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v29 )
      GlobalRegistryInstance::GlobalRegistryInstance(v29);
    else
      v28 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v28;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v28, &Display_Resolution_3, (GRPObject **)&DefaultResolution) )
  {
    v30 = (*(int (**)(void))(*(_DWORD *)DefaultResolution + 68))();
    if ( v30 )
      *(_BYTE *)(v30 + 40) = 1;
  }
  v31 = RefreshRateNameStrings.m_data - 5;
  if ( !InterlockedDecrement((volatile LONG *)&RefreshRateNameStrings.m_data[-4]) && v31 )
    (*(void (__thiscall **)(PStringBase<char> *, signed int))&v31->m_charbuffer->m_data[0])(v31, 1);
  PStringBase<char>::allocate_ref_buffer(
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    strlen("Enables full screen mode"));
  strcpy((char *)RefreshRateNameStrings.m_data, "Enables full screen mode");
  GlobalRegistry::RegisterVariableInternal(
    &byte_817B68,
    GRVDataType_Bool,
    &Display_FullScreen_3,
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    0,
    0,
    0,
    0);
  v32 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v33 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v33 )
      GlobalRegistryInstance::GlobalRegistryInstance(v33);
    else
      v32 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v32;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v32, &Display_FullScreen_3, (GRPObject **)&DefaultResolution) )
  {
    v34 = (*(int (**)(void))(*(_DWORD *)DefaultResolution + 68))();
    if ( v34 )
      *(_BYTE *)(v34 + 40) = 1;
  }
  v35 = RefreshRateNameStrings.m_data - 5;
  if ( !InterlockedDecrement((volatile LONG *)&RefreshRateNameStrings.m_data[-4]) && v35 )
    (*(void (__thiscall **)(PStringBase<char> *, signed int))&v35->m_charbuffer->m_data[0])(v35, 1);
  PStringBase<char>::allocate_ref_buffer(
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    strlen("Selects full screen refresh rate."));
  strcpy((char *)RefreshRateNameStrings.m_data, "Selects full screen refresh rate.");
  v36 = PrefMode.nWidth;
  GlobalRegistry::RegisterVariableInternal(
    &dword_817B6C,
    GRVDataType_UInt32,
    &Display_RefreshRate_3,
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    0,
    PrefRefreshRates.m_num,
    v26,
    (const unsigned int *)PrefMode.nWidth);
  v37 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v38 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v38 )
      GlobalRegistryInstance::GlobalRegistryInstance(v38);
    else
      v37 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v37;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v37, &Display_RefreshRate_3, (GRPObject **)&DefaultResolution) )
  {
    v39 = (*(int (**)(void))(*(_DWORD *)DefaultResolution + 68))();
    if ( v39 )
      *(_BYTE *)(v39 + 40) = 1;
  }
  v40 = RefreshRateNameStrings.m_data - 5;
  if ( !InterlockedDecrement((volatile LONG *)&RefreshRateNameStrings.m_data[-4]) && v40 )
    (*(void (__thiscall **)(PStringBase<char> *, signed int))&v40->m_charbuffer->m_data[0])(v40, 1);
  PStringBase<char>::allocate_ref_buffer(
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    strlen("Syncs frames with the display's vertical refresh rate (eliminates tearing but reduces performance)"));
  strcpy(
    (char *)RefreshRateNameStrings.m_data,
    "Syncs frames with the display's vertical refresh rate (eliminates tearing but reduces performance)");
  GlobalRegistry::RegisterVariableInternal(
    &byte_817B71,
    GRVDataType_Bool,
    &Display_SyncToRefresh_3,
    (PStringBase<char> *)&RefreshRateNameStrings.m_data,
    0,
    0,
    0,
    0);
  v41 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v42 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v42 )
      GlobalRegistryInstance::GlobalRegistryInstance(v42);
    else
      v41 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v41;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v41, &Display_SyncToRefresh_3, (GRPObject **)&DefaultResolution) )
  {
    v43 = (*(int (**)(void))(*(_DWORD *)DefaultResolution + 68))();
    if ( v43 )
      *(_BYTE *)(v43 + 40) = 1;
  }
  v44 = RefreshRateNameStrings.m_data - 5;
  if ( !InterlockedDecrement((volatile LONG *)&RefreshRateNameStrings.m_data[-4]) && v44 )
    (*(void (__thiscall **)(PStringBase<char> *, signed int))&v44->m_charbuffer->m_data[0])(v44, 1);
  operator delete[]((void *)v36);
  if ( v26 )
  {
    v45 = v26[-1].m_charbuffer;
    v46 = &v26[-1];
    v47 = (int)&v26[(_DWORD)v45];
    v48 = (int)&v45[-1].m_data[15];
    if ( v48 >= 0 )
    {
      v49 = v48 + 1;
      do
      {
        v50 = *(_DWORD *)(v47 - 4);
        v47 -= 4;
        v51 = v50 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v51 + 4)) && v51 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v51)(v51, 1);
        --v49;
      }
      while ( v49 );
    }
    operator delete[](v46);
  }
  operator delete[](ResolutionValues.m_data);
  if ( RefreshRate )
  {
    v52 = *(_DWORD *)(RefreshRate - 4);
    v53 = (void *)(RefreshRate - 4);
    v54 = RefreshRate + 4 * v52;
    v55 = v52 - 1;
    if ( v55 >= 0 )
    {
      v56 = v55 + 1;
      do
      {
        v57 = *(_DWORD *)(v54 - 4);
        v54 -= 4;
        v58 = v57 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v58 + 4)) && v58 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v58)(v58, 1);
        --v56;
      }
      while ( v56 );
    }
    operator delete[](v53);
  }
  if ( (PrefRefreshRates.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](PrefRefreshRates.m_data);
  if ( (PrefDisplayModes.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](PrefDisplayModes.m_data);
  return 1;
}
// 817B64: using guessed type struct DisplayPrefs Device::m_DisplayPrefs;
// 817B68: using guessed type char byte_817B68;
// 817B6C: using guessed type int dword_817B6C;
// 817B71: using guessed type char byte_817B71;

//----- (0043B820) --------------------------------------------------------  // acclient.c:120402
char __cdecl Device::Init(bool bWindowed, PStringBase<char> *title, int swidth, int sheight, bool windowVisible, PStringBase<char> *i_strModule)
{
  PSRefBufferCharData<unsigned short> *v6; // ecx@4
  int v7; // esi@5
  PSRefBufferCharData<unsigned short> *v8; // ecx@6
  PSRefBufferCharData<unsigned short> *v9; // ecx@6
  HINSTANCE__ *v10; // eax@7
  int v11; // ecx@7
  HINSTANCE__ *v12; // ebp@7
  PSRefBufferCharData<unsigned short> *v13; // ecx@17
  int v14; // ebx@21
  int v15; // ebp@21
  int v16; // edi@21
  int v17; // ebx@22
  int v18; // esi@22
  int v19; // ebp@22
  int v20; // eax@22
  int v21; // edx@23
  int v22; // ecx@23
  PSRefBufferCharData<unsigned short> *v23; // ecx@36
  PSRefBufferCharData<unsigned short> *v24; // ecx@36
  CInputManager_WIN32 *v25; // eax@37
  CInputManager *v26; // eax@38
  Device::DeviceDialogBoxGateway *v27; // eax@44
  struct Device::DeviceDialogBoxGateway *v28; // eax@45
  PSRefBufferCharData<unsigned short> *v30; // ecx@48
  PSRefBufferCharData<unsigned short> *v31; // ecx@48
  PStringBase<unsigned short> v32; // [sp-10h] [bp-118h]@6
  PStringBase<unsigned short> v33; // [sp-Ch] [bp-114h]@6
  PStringBase<unsigned short> v34; // [sp-8h] [bp-110h]@6
  PlatformString::DisplayStringMode v35; // [sp-4h] [bp-10Ch]@6
  unsigned int dwStyle; // [sp+10h] [bp-F8h]@19
  int nWorkAreaHeight; // [sp+14h] [bp-F4h]@23
  int nFrameWidth; // [sp+18h] [bp-F0h]@10
  tagRECT rWorkArea; // [sp+1Ch] [bp-ECh]@22
  HINSTANCE__ *hInstance; // [sp+2Ch] [bp-DCh]@7
  RenderDevicePresentation presentation; // [sp+30h] [bp-D8h]@12
  tagWNDCLASSA wndClass; // [sp+4Ch] [bp-BCh]@16
  _OSVERSIONINFOA version; // [sp+74h] [bp-94h]@4
  bool bWindoweda; // [sp+10Ch] [bp+4h]@14

  if ( Device::m_bIsInitialized )
    return 0;
  if ( !GetMenu(Device::m_hWnd) )
    Device::m_bSysKeysEnabled = 0;
  version.dwOSVersionInfoSize = 148;
  if ( !GetVersionExA(&version) )
  {
    v35 = 0;
    v34.m_charbuffer = v6;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v34, &word_794320);
    v33.m_charbuffer = v30;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v33, &word_794320);
    v32.m_charbuffer = v31;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v32, &word_794320);
    PlatformString::DisplayString(0x6Bu, v32, v33, v34, v35);
    goto LABEL_49;
  }
  v7 = 0;
  Device::m_nOSVersion = version.dwPlatformId;
  if ( !version.dwPlatformId )
  {
    v35 = 0;
    v34.m_charbuffer = v6;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v34, &word_794320);
    v33.m_charbuffer = v8;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v33, &word_794320);
    v32.m_charbuffer = v9;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v32, &word_794320);
    PlatformString::DisplayString(0x6Au, v32, v33, v34, v35);
LABEL_49:
    Device::m_bIsDone = 1;
    return 0;
  }
  v10 = GetModuleHandleA((*(_DWORD *)&i_strModule->m_charbuffer[-1].m_data[12] != 1 ? i_strModule->m_charbuffer : 0)->m_data);
  v11 = *(_DWORD *)&i_strModule->m_charbuffer[-1].m_data[12];
  v12 = v10;
  hInstance = v10;
  if ( v11 != 1 )
    Device::m_bIsChildWnd = 1;
  if ( Render::m_pRenderer )
    return 0;
  nFrameWidth = 1;
  if ( !Render::StartupRenderingSystem((RenderConfig *)&nFrameWidth) )
    return 0;
  if ( !Device::InitializeDisplayPreferences() )
    return 0;
  RenderDevicePresentation::RenderDevicePresentation(&presentation);
  if ( !Device::LoadDisplayPreferences(&presentation) )
    return 0;
  if ( !Device::m_bAllowFullScreenMode || (bWindoweda = 0, !presentation.FullScreen) )
    bWindoweda = 1;
  wndClass.lpfnWndProc = Device::WndProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = v12;
  wndClass.style = 0;
  wndClass.hIcon = LoadIconA(v12, (LPCSTR)0x65);
  wndClass.hbrBackground = (HBRUSH__ *)GetStockObject(4);
  wndClass.lpszMenuName = title->m_charbuffer->m_data;
  wndClass.hCursor = 0;
  wndClass.lpszClassName = "Turbine Device Class";
  if ( !RegisterClassA(&wndClass) && GetLastError() != 1410 )
  {
    v35 = 0;
LABEL_36:
    v34.m_charbuffer = v13;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v34, &word_794320);
    v33.m_charbuffer = v23;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v33, &word_794320);
    v32.m_charbuffer = v24;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v32, &word_794320);
    PlatformString::DisplayString(0x7Fu, v32, v33, v34, v35);
    goto LABEL_49;
  }
  dwStyle = bWindoweda != 0 ? 46792704 : -2113929216;
  if ( windowVisible )
    dwStyle = (bWindoweda != 0 ? 46792704 : -2113929216) | 0x10000000;
  v14 = presentation.Width;
  v15 = presentation.Height;
  v16 = 0;
  if ( bWindoweda )
  {
    v17 = GetSystemMetrics(7);
    nFrameWidth = v17;
    v18 = GetSystemMetrics(8);
    v19 = GetSystemMetrics(4);
    v20 = GetSystemMetrics(0);
    v14 = presentation.Width + 2 * v17;
    v15 = presentation.Height + v19 + 2 * v18;
    v7 = v20 / 2 - v14 / 2;
    v16 = GetSystemMetrics(1) / 2 - v15 / 2;
    if ( SystemParametersInfoA(0x30u, 0x10u, &rWorkArea, 0) )
    {
      v21 = rWorkArea.top;
      v22 = rWorkArea.bottom - rWorkArea.top;
      nWorkAreaHeight = rWorkArea.bottom - rWorkArea.top;
      if ( v14 > rWorkArea.right - rWorkArea.left )
      {
        v7 = rWorkArea.left - nFrameWidth;
      }
      else
      {
        if ( v14 + v7 > rWorkArea.right )
          v7 = rWorkArea.right - rWorkArea.left - v14;
        v22 = nWorkAreaHeight;
        v21 = rWorkArea.top;
        if ( v7 < rWorkArea.left )
          v7 = rWorkArea.left;
      }
      if ( v15 > v22 )
        goto LABEL_53;
      if ( v16 + v15 > rWorkArea.bottom )
        v16 = v22 - v15;
      if ( v16 < v21 )
LABEL_53:
        v16 = v21;
    }
  }
  Device::m_hWnd = CreateWindowExA(
                     0,
                     "Turbine Device Class",
                     title->m_charbuffer->m_data,
                     dwStyle,
                     v7,
                     v16,
                     v14,
                     v15,
                     0,
                     0,
                     hInstance,
                     0);
  if ( !Device::m_hWnd )
  {
    v35 = 0;
    goto LABEL_36;
  }
  v25 = (CInputManager_WIN32 *)operator new(0x3F8u);
  if ( v25 )
    CInputManager_WIN32::CInputManager_WIN32(v25);
  else
    v26 = 0;
  ICIDM::s_cidm = v26;
  if ( (unsigned __int8)(*(int (__thiscall **)(CInputManager *, HWND))&v26->vfptr->gap4[0])(v26, Device::m_hWnd) != 1 )
    return 0;
  if ( windowVisible )
  {
    ShowWindow(Device::m_hWnd, 1);
    UpdateWindow(Device::m_hWnd);
    SetForegroundWindow(Device::m_hWnd);
    SetActiveWindow(Device::m_hWnd);
    SetWindowPos(Device::m_hWnd, (HWND)(-(bWindoweda != 0) - 1), 0, 0, 0, 0, 0x153u);
  }
  if ( !Device::InitWindow(presentation.Width, presentation.Height, bWindoweda) )
    return 0;
  v27 = (Device::DeviceDialogBoxGateway *)operator new(8u);
  if ( v27 )
  {
    Device::DeviceDialogBoxGateway::DeviceDialogBoxGateway(v27);
    Device::sm_pDeviceDialogGateway = v28;
  }
  else
  {
    Device::sm_pDeviceDialogGateway = 0;
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&dwStyle, "Exits the application");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&nWorkAreaHeight, "Exit");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)())ConsoleCommand_QuitCommand,
    (PStringBase<char> *)&nWorkAreaHeight,
    (PStringBase<char> *)&dwStyle);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nWorkAreaHeight);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&dwStyle);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&dwStyle, "Exits the application");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&nWorkAreaHeight, "Quit");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)())ConsoleCommand_QuitCommand,
    (PStringBase<char> *)&nWorkAreaHeight,
    (PStringBase<char> *)&dwStyle);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nWorkAreaHeight);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&dwStyle);
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&dwStyle,
    "Restarts the rendering engine and applies new display settings");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&nWorkAreaHeight, "UpdatePresentation");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)())Device::ChangePresentation,
    (PStringBase<char> *)&nWorkAreaHeight,
    (PStringBase<char> *)&dwStyle);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nWorkAreaHeight);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&dwStyle);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&nFrameWidth, "ForceDisplayResolution [<Width> <Height>]");
  PStringBase<char>::PStringBase<char>(
    (PStringBase<char> *)&dwStyle,
    "Forces the display resolution to the specified width and height.  Pass no parameters to restore normal resolution.");
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&nWorkAreaHeight, "ForceDisplayResolution");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)(PStringBaseArray<char> *))Device::ConsoleCommand_ForceDisplayResolution,
    (PStringBase<char> *)&nWorkAreaHeight,
    (PStringBase<char> *)&dwStyle,
    (PStringBase<char> *)&nFrameWidth);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nWorkAreaHeight);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&dwStyle);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&nFrameWidth);
  SetThreadExecutionState(0x80000001);
  Device::m_bIsInitialized = 1;
  return 1;
}
// 817B01: using guessed type bool Device::m_bSysKeysEnabled;
// 817B02: using guessed type bool Device::m_bAllowFullScreenMode;
// 837194: using guessed type bool Device::m_bIsDone;
// 837196: using guessed type bool Device::m_bIsInitialized;
// 83719C: using guessed type unsigned __int32 Device::m_nOSVersion;
// 8371A8: using guessed type bool Device::m_bIsChildWnd;
// 8371AC: using guessed type struct Device::DeviceDialogBoxGateway *Device::sm_pDeviceDialogGateway;

//----- (006C6380) --------------------------------------------------------  // acclient.c:734482
int _E73_29()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_3, "Display.Resolution");
  return atexit(_E74_31);
}

//----- (006C63A0) --------------------------------------------------------  // acclient.c:734489
int _E76_19()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_3, "Display.FullScreen");
  return atexit(_E77_47);
}

//----- (006C63C0) --------------------------------------------------------  // acclient.c:734496
int _E79_19()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_3, "Display.RefreshRate");
  return atexit(_E80_21);
}

//----- (006C63E0) --------------------------------------------------------  // acclient.c:734503
int _E82_10()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_3, "Display.SyncToRefresh");
  return atexit(_E83_11);
}

//----- (006C6400) --------------------------------------------------------  // acclient.c:734510
int _E85_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_7, "None");
  return atexit(_E86_8);
}

//----- (006C6420) --------------------------------------------------------  // acclient.c:734517
int _E88_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_7, "Speed");
  return atexit(_E89_19);
}

//----- (006C6440) --------------------------------------------------------  // acclient.c:734524
int _E91_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_7, "Noise");
  return atexit(_E92_17);
}

//----- (006C6460) --------------------------------------------------------  // acclient.c:734531
int _E94_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_7, "Sine");
  return atexit(sub_7299D0);
}

//----- (006C6480) --------------------------------------------------------  // acclient.c:734538
int _E97_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_7, "Square");
  return atexit(_E98_32);
}

//----- (006C64A0) --------------------------------------------------------  // acclient.c:734545
int _E100_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_7, "Bounce");
  return atexit(_E101_60);
}

//----- (006C64C0) --------------------------------------------------------  // acclient.c:734552
int _E103_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_7, "Perlin");
  return atexit(_E104_30);
}

//----- (006C64E0) --------------------------------------------------------  // acclient.c:734559
int _E106_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_7, "Fractal");
  return atexit(_E107_62);
}

//----- (006C6500) --------------------------------------------------------  // acclient.c:734566
int _E109_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_7, "FrameLoop");
  return atexit(sub_729AC0);
}

//----- (006C6520) --------------------------------------------------------  // acclient.c:734573
void _E112_8()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_4, PFID_A8R8G8B8);
}

//----- (006C6530) --------------------------------------------------------  // acclient.c:734579
void _E130_7()
{
  LODWORD(dword_837234) = 1053364187;
}

//----- (006C6540) --------------------------------------------------------  // acclient.c:734585
void _E132()
{
  outside_val_5 = 1000.0 + 1.0;
}

//----- (006C6560) --------------------------------------------------------  // acclient.c:734591
void _E134_0()
{
  block_length_5 = 24.0 * 8.0;
}

//----- (006C6580) --------------------------------------------------------  // acclient.c:734597
void _E136_5()
{
  half_square_length_5 = 24.0 * 0.5;
}

//----- (006C65A0) --------------------------------------------------------  // acclient.c:734603
int _E138()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_1, "Render.TextureFiltering");
  return atexit(_E139_50);
}

//----- (006C65C0) --------------------------------------------------------  // acclient.c:734610
int _E141()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_1, "Render.LandscapeDetailTextures");
  return atexit(_E142_47);
}

//----- (006C65E0) --------------------------------------------------------  // acclient.c:734617
int _E144()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_1, "Render.BuildingDetailTextures");
  return atexit(_E145_49);
}

//----- (006C6600) --------------------------------------------------------  // acclient.c:734624
int _E147()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_1, "Render.FieldOfView");
  return atexit(_E148_48);
}

//----- (006C6620) --------------------------------------------------------  // acclient.c:734631
int _E150()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_1, "Render.LandscapeTextureDetail");
  return atexit(_E151_46);
}

//----- (006C6640) --------------------------------------------------------  // acclient.c:734638
int _E153()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_1, "Render.EnvironmentTextureDetail");
  return atexit(_E154_47);
}

//----- (006C6660) --------------------------------------------------------  // acclient.c:734645
int _E156_0()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_1, "Render.SceneryDrawDistance");
  return atexit(_E157_44);
}

//----- (006C6680) --------------------------------------------------------  // acclient.c:734652
int _E159()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_1, "Render.LandscapeDrawDistance");
  return atexit(_E160_47);
}

//----- (006C66A0) --------------------------------------------------------  // acclient.c:734659
int _E162_0()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_1, "Render.ScreenBrightness");
  return atexit(_E163_40);
}

//----- (006C66C0) --------------------------------------------------------  // acclient.c:734666
int _E165()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_1, "Render.AspectRatio");
  return atexit(_E166_42);
}

//----- (006C66E0) --------------------------------------------------------  // acclient.c:734673
int _E168_0()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_1, "Render.DisplayAdapter");
  return atexit(_E169_41);
}

//----- (006C6700) --------------------------------------------------------  // acclient.c:734680
int _E171_0()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_1, "Render.MaxHardwareClass");
  return atexit(_E172_39);
}

//----- (006C6720) --------------------------------------------------------  // acclient.c:734687
int _E174_0()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_1, "Render.AutomaticDegrades");
  return atexit(_E175_36);
}

//----- (006C6740) --------------------------------------------------------  // acclient.c:734694
int _E177_0()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_1, "Render.GraphicsPerformance");
  return atexit(_E178_36);
}

//----- (006C6760) --------------------------------------------------------  // acclient.c:734701
int _E180_0()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_1, "Render.DegradeDistance");
  return atexit(_E181_36);
}

//----- (006C6780) --------------------------------------------------------  // acclient.c:734708
int _E183_0()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_1, "Render.MultiPassAlpha");
  return atexit(_E184_34);
}

//----- (006C67A0) --------------------------------------------------------  // acclient.c:734715
int _E186_0()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_1, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83728C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_837290, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_837294, "Anisotropic");
  return atexit(_E187_33);
}

//----- (006C67F0) --------------------------------------------------------  // acclient.c:734725
int _E189_0()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_1, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83729C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8372A0, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8372A4, "High");
  PStringBase<char>::PStringBase<char>(&stru_8372A8, "VeryHigh");
  return atexit(_E190_34);
}

//----- (006C6850) --------------------------------------------------------  // acclient.c:734736
int _E192_0()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_1, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8372B0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8372B4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8372B8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8372BC, "VeryHigh");
  return atexit(_E193_33);
}

//----- (006C68B0) --------------------------------------------------------  // acclient.c:734747
int _E195_0()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_1, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8372C4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8372C8, "High");
  return atexit(_E196_41);
}

//----- (006C68F0) --------------------------------------------------------  // acclient.c:734756
int _E198_0()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_1, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8372D0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8372D4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8372D8, "High");
  PStringBase<char>::PStringBase<char>(&stru_8372DC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8372E0, "Extreme");
  return atexit(_E199_32);
}

//----- (006C6960) --------------------------------------------------------  // acclient.c:734768
int _E201_0()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_1, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8372E8, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8372EC, "Wide");
  return atexit(_E202_35);
}

//----- (006C69A0) --------------------------------------------------------  // acclient.c:734777
void _E204()
{
  DEFAULT_VIEW_RADIUS_2 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006C69C0) --------------------------------------------------------  // acclient.c:734783
void _E206()
{
  MIN_QUANTUM_2 = 1.0 / 30.0;
}

//----- (006C69E0) --------------------------------------------------------  // acclient.c:734789
void _E208_1()
{
  MAX_QUANTUM_2 = 1.0 / 5.0;
}

//----- (006C6A00) --------------------------------------------------------  // acclient.c:734795
int _E210()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_1, "Misc.TooltipEnable");
  return atexit(_E211_32);
}

//----- (006C6A20) --------------------------------------------------------  // acclient.c:734802
int _E213()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_1, "Misc.TooltipDelay");
  return atexit(_E214_34);
}

//----- (006C6A40) --------------------------------------------------------  // acclient.c:734809
int _E216()
{
  PStringBase<char>::PStringBase<char>(&sErrorTitle, "Error");
  return atexit(_E217_31);
}

//----- (006C6A60) --------------------------------------------------------  // acclient.c:734816
int _E1_27()
{
  return atexit(_E2_27);
}

//----- (00729370) --------------------------------------------------------  // acclient.c:827150
void __cdecl _E139_50()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007293A0) --------------------------------------------------------  // acclient.c:827163
void __cdecl _E142_47()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007293D0) --------------------------------------------------------  // acclient.c:827176
void __cdecl _E145_49()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729400) --------------------------------------------------------  // acclient.c:827189
void __cdecl _E148_48()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729430) --------------------------------------------------------  // acclient.c:827202
void __cdecl _E151_46()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729460) --------------------------------------------------------  // acclient.c:827215
void __cdecl _E154_47()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729490) --------------------------------------------------------  // acclient.c:827228
void __cdecl _E157_44()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007294C0) --------------------------------------------------------  // acclient.c:827241
void __cdecl _E160_47()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007294F0) --------------------------------------------------------  // acclient.c:827254
void __cdecl _E163_40()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729520) --------------------------------------------------------  // acclient.c:827267
void __cdecl _E166_42()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729550) --------------------------------------------------------  // acclient.c:827280
void __cdecl _E169_41()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729580) --------------------------------------------------------  // acclient.c:827293
void __cdecl _E172_39()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007295B0) --------------------------------------------------------  // acclient.c:827306
void __cdecl _E175_36()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007295E0) --------------------------------------------------------  // acclient.c:827319
void __cdecl _E178_36()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729610) --------------------------------------------------------  // acclient.c:827332
void __cdecl _E181_36()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729640) --------------------------------------------------------  // acclient.c:827345
void __cdecl _E184_34()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729670) --------------------------------------------------------  // acclient.c:827358
void __cdecl _E187_33()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_1;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (007296B0) --------------------------------------------------------  // acclient.c:827383
void __cdecl _E190_34()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_1;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (007296F0) --------------------------------------------------------  // acclient.c:827408
void __cdecl _E193_33()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_1;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (00729730) --------------------------------------------------------  // acclient.c:827433
void __cdecl _E196_41()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_1;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (00729770) --------------------------------------------------------  // acclient.c:827458
void __cdecl _E199_32()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_1;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
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

//----- (007297B0) --------------------------------------------------------  // acclient.c:827483
void __cdecl _E202_35()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &DEFAULT_VIEW_RADIUS_2;
  v1 = 3;
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

//----- (007297F0) --------------------------------------------------------  // acclient.c:827508
void __cdecl _E211_32()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729820) --------------------------------------------------------  // acclient.c:827521
void __cdecl _E214_34()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729850) --------------------------------------------------------  // acclient.c:827534
void __cdecl _E217_31()
{
  char *v0; // esi@1

  v0 = &sErrorTitle.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&sErrorTitle.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729880) --------------------------------------------------------  // acclient.c:827547
void __cdecl _E74_31()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007298B0) --------------------------------------------------------  // acclient.c:827560
void __cdecl _E77_47()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007298E0) --------------------------------------------------------  // acclient.c:827573
void __cdecl _E80_21()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729910) --------------------------------------------------------  // acclient.c:827586
void __cdecl _E83_11()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729940) --------------------------------------------------------  // acclient.c:827599
void __cdecl _E86_8()
{
  char *v0; // esi@1

  v0 = &waveform_None_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729970) --------------------------------------------------------  // acclient.c:827612
void __cdecl _E89_19()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007299A0) --------------------------------------------------------  // acclient.c:827625
void __cdecl _E92_17()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007299D0) --------------------------------------------------------  // acclient.c:827638
void __cdecl sub_7299D0()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729A00) --------------------------------------------------------  // acclient.c:827651
void __cdecl _E98_32()
{
  char *v0; // esi@1

  v0 = &waveform_Square_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729A30) --------------------------------------------------------  // acclient.c:827664
void __cdecl _E101_60()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729A60) --------------------------------------------------------  // acclient.c:827677
void __cdecl _E104_30()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729A90) --------------------------------------------------------  // acclient.c:827690
void __cdecl _E107_62()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729AC0) --------------------------------------------------------  // acclient.c:827703
void __cdecl sub_729AC0()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

