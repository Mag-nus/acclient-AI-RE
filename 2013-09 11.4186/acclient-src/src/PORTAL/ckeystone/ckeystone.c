/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ckeystone
   Object     : PORTAL\ckeystone\ckeystone.obj
   Functions  : 99
   Addresses  : 00556B60 - 00772F50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00556B60) --------------------------------------------------------  // acclient.c:390094
bool __cdecl CheckForMSXML4()
{
  HMODULE v0; // esi@1
  bool result; // al@2
  bool v2; // bl@3

  v0 = LoadLibraryA("msxml4.dll");
  if ( v0 )
  {
    fMSXML4Initted = 1;
    CParseXml::CParseXml();
    fMSXML4Initted = CParseXml::Init();
    FreeLibrary(v0);
    v2 = fMSXML4Initted;
    CParseXml::~CParseXml();
    result = v2;
  }
  else
  {
    fMSXML4Initted = 0;
    result = 0;
  }
  return result;
}
// 86FC48: using guessed type bool fMSXML4Initted;

//----- (00556C00) --------------------------------------------------------  // acclient.c:390121
void __cdecl KeyStone::Update()
{
  if ( KeyStone::m_lpKeystone )
    ((void (*)(void))KeyStone::m_lpKeystone->vfptr[2].Release)();
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;

//----- (00556C10) --------------------------------------------------------  // acclient.c:390129
int __cdecl KeyStone::Create()
{
  HWND v0; // esi@4
  HIMC v1; // edi@4
  int result; // eax@6
  int v3; // [sp+18h] [bp-6004h]@7
  char MultiByteStr; // [sp+1Ch] [bp-6000h]@3
  char v5; // [sp+2004h] [bp-4018h]@4
  unsigned __int16 WideCharStr; // [sp+201Ch] [bp-4000h]@4

  if ( !RenderDevice::render_device || !KeyStone::m_fnKeystoneCreate )
    goto LABEL_10;
  if ( __getcwd(&MultiByteStr, 0x2000) )
  {
    MultiByteToWideChar(0, 0, &MultiByteStr, -1, &WideCharStr, 0x2000);
    v0 = Device::m_hWnd;
    v1 = ImmGetContext(Device::m_hWnd);
    ImmReleaseContext(v0, v1);
    KeyStone::m_lpKeystone = KeyStone::m_fnKeystoneCreate(
                               v0,
                               LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
                               (const unsigned __int16 *)&v5,
                               0,
                               0,
                               0,
                               0);
    ImmAssociateContext(v0, v1);
  }
  if ( KeyStone::m_lpKeystone )
  {
    v3 = 0;
    ((void (__stdcall *)(signed int, signed int, int *))KeyStone::m_lpKeystone->vfptr[7].Release)(105, 2, &v3);
    result = 1;
  }
  else
  {
LABEL_10:
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;
// 86FC24: using guessed type struct IKeystone *(__cdecl static *KeyStone::m_fnKeystoneCreate)(HWND, struct IDirect3DDevice9 *, const unsigned __int16 *, __int32 (__cdecl static *)(struct IDirect3DDevice9 *, const void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned __int32, enum _D3DFORMAT, enum _D3DPOOL, unsigned __int32, unsigned __int32, unsigned __int32, struct _D3DXIMAGE_INFO *, struct tagPALETTEENTRY *, struct IDirect3DTexture9 **), __int32 (__cdecl static *)(unsigned int, unsigned __int32, unsigned __int32, enum _D3DPOOL, struct IDirect3DVertexBuffer9 **), void *(__cdecl static *)(unsigned __int32), void (__cdecl static *)(void *));

//----- (00556CF0) --------------------------------------------------------  // acclient.c:390174
int __cdecl KeyStone::Init()
{
  HMODULE v0; // eax@3
  void (__stdcall *v1)(); // esi@3
  __int32 (__cdecl static *v2)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *); // eax@3
  int (*v3)(void); // eax@3
  __int32 (__cdecl static *v4)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *); // eax@3
  int (*v5)(void); // eax@3

  if ( KeyStone::m_hKeystoneLib )
    return 1;
  if ( CheckForMSXML4() )
  {
    v0 = LoadLibraryA("keystone.dll");
    v1 = *(void (__stdcall **)())GetProcAddress;
    KeyStone::m_hKeystoneLib = v0;
    KeyStone::m_fnKeystoneCreate = (struct IKeystone *(__cdecl static *)(HWND, struct IDirect3DDevice9 *, const unsigned __int16 *, __int32 (__cdecl static *)(struct IDirect3DDevice9 *, const void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned __int32, enum _D3DFORMAT, enum _D3DPOOL, unsigned __int32, unsigned __int32, unsigned __int32, struct _D3DXIMAGE_INFO *, struct tagPALETTEENTRY *, struct IDirect3DTexture9 **), __int32 (__cdecl static *)(unsigned int, unsigned __int32, unsigned __int32, enum _D3DPOOL, struct IDirect3DVertexBuffer9 **), void *(__cdecl static *)(unsigned __int32), void (__cdecl static *)(void *)))GetProcAddress(v0, "KeystoneCreate");
    KeyStone::m_hAC2HelpPluginLib = LoadLibraryA("plugins\\ACHelpPlugin.dll");
    v1();
    KeyStone::m_fnAC2HelpPluginExecute = v2;
    v1();
    KeyStone::m_fnAC2HelpPluginTerminate = v3;
    KeyStone::m_hAC2PluginManagerLib = LoadLibraryA("plugins\\ACPluginManager.dll");
    v1();
    KeyStone::m_fnAC2PluginManagerExecute = v4;
    v1();
    KeyStone::m_fnAC2PluginManagerTerminate = v5;
    if ( KeyStone::m_fnKeystoneCreate )
      return 1;
    KeyStone::m_hDummyAccel = CreateAcceleratorTableA(0, 0);
  }
  return 0;
}
// 556CF0: could not find valid save-restore pair for edi
// 556CF0: could not find valid save-restore pair for esi
// 86FC24: using guessed type struct IKeystone *(__cdecl static *KeyStone::m_fnKeystoneCreate)(HWND, struct IDirect3DDevice9 *, const unsigned __int16 *, __int32 (__cdecl static *)(struct IDirect3DDevice9 *, const void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned __int32, enum _D3DFORMAT, enum _D3DPOOL, unsigned __int32, unsigned __int32, unsigned __int32, struct _D3DXIMAGE_INFO *, struct tagPALETTEENTRY *, struct IDirect3DTexture9 **), __int32 (__cdecl static *)(unsigned int, unsigned __int32, unsigned __int32, enum _D3DPOOL, struct IDirect3DVertexBuffer9 **), void *(__cdecl static *)(unsigned __int32), void (__cdecl static *)(void *));
// 86FC34: using guessed type __int32 (__cdecl static *KeyStone::m_fnAC2HelpPluginExecute)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *);
// 86FC38: using guessed type int (*KeyStone::m_fnAC2HelpPluginTerminate)(void);
// 86FC3C: using guessed type __int32 (__cdecl static *KeyStone::m_fnAC2PluginManagerExecute)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *);
// 86FC40: using guessed type int (*KeyStone::m_fnAC2PluginManagerTerminate)(void);

//----- (00556DB0) --------------------------------------------------------  // acclient.c:390216
int __cdecl KeyStone::DispatchMessageA(unsigned int msg, unsigned int wparam, int lparam, int *_bool)
{
  signed int v4; // esi@1
  int result; // eax@2
  int v6; // eax@3

  v4 = 0;
  if ( KeyStone::m_lpKeystone )
  {
    v6 = ((int (__stdcall *)(unsigned int, unsigned int, int, int *))KeyStone::m_lpKeystone->vfptr[3].QueryInterface)(
           msg,
           wparam,
           lparam,
           _bool);
    if ( v6 )
    {
      v4 = 1;
      (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
    }
    result = v4;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;

//----- (00556DF0) --------------------------------------------------------  // acclient.c:390246
int __cdecl KeyStone::IsHelpFocused()
{
  int result; // eax@2
  signed int v1; // esi@3
  int v2; // eax@3

  if ( KeyStone::m_lpKeystone )
  {
    v1 = 0;
    v2 = ((int (*)(void))KeyStone::m_lpKeystone->vfptr[3].Release)();
    if ( v2 )
    {
      v1 = 1;
      (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
    }
    result = v1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;

//----- (00556E20) --------------------------------------------------------  // acclient.c:390272
int __cdecl KeyStone::IsOverKeystoneWindow(tagPOINT ptMouse)
{
  int result; // eax@2
  signed int v2; // esi@3
  int v3; // eax@3

  if ( KeyStone::m_lpKeystone )
  {
    v2 = 0;
    v3 = ((int (__stdcall *)(tagPOINT *))KeyStone::m_lpKeystone->vfptr[8].QueryInterface)(&ptMouse);
    if ( v3 )
    {
      v2 = 1;
      (*(void (__stdcall **)(int))(*(_DWORD *)v3 + 8))(v3);
    }
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;

//----- (00556E50) --------------------------------------------------------  // acclient.c:390298
int __cdecl KeyStone::TranslateAcceleratorA(HWND__ *hWnd, HACCEL__ *hAccel, tagMSG *pMsg)
{
  int result; // eax@2
  HACCEL__ *v4; // eax@3

  if ( KeyStone::m_lpKeystone )
  {
    v4 = hAccel;
    if ( !hAccel )
      v4 = KeyStone::m_hDummyAccel;
    result = KeyStone::m_lpKeystone->vfptr[9].QueryInterface((IUnknown *)hWnd, (_GUID *)v4, (void **)pMsg);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;

//----- (00556E80) --------------------------------------------------------  // acclient.c:390319
int __cdecl KeyStone::LoseFocus()
{
  int v0; // eax@2
  int result; // eax@3

  if ( KeyStone::m_lpKeystone && (v0 = ((int (*)(void))KeyStone::m_lpKeystone->vfptr[3].Release)()) != 0 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v0 + 8))(v0);
    KeyStone::m_lpKeystone->vfptr[3].AddRef(0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;

//----- (00556EB0) --------------------------------------------------------  // acclient.c:390339
int __cdecl KeyStone::ClosePluginManager()
{
  int result; // eax@3

  if ( KeyStone::m_lpKeystone && KeyStone::m_fnAC2PluginManagerTerminate )
  {
    KeyStone::m_fnAC2PluginManagerTerminate();
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;
// 86FC40: using guessed type int (*KeyStone::m_fnAC2PluginManagerTerminate)(void);

//----- (00556ED0) --------------------------------------------------------  // acclient.c:390358
int __cdecl KeyStone::OpenPluginManager()
{
  int result; // eax@5

  if ( !KeyStone::m_lpKeystone )
    goto LABEL_9;
  if ( KeyStone::m_fnAC2PluginManagerTerminate )
    KeyStone::m_fnAC2PluginManagerTerminate();
  if ( KeyStone::m_fnAC2PluginManagerExecute )
  {
    KeyStone::m_fnAC2PluginManagerExecute(
      KeyStone::m_lpKeystone,
      (unsigned __int16 *(__cdecl static *)(const unsigned __int16 *))UIObject::DynamicCast_UIViewportObject,
      0);
    result = 1;
  }
  else
  {
LABEL_9:
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;
// 86FC3C: using guessed type __int32 (__cdecl static *KeyStone::m_fnAC2PluginManagerExecute)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *);
// 86FC40: using guessed type int (*KeyStone::m_fnAC2PluginManagerTerminate)(void);

//----- (00556F10) --------------------------------------------------------  // acclient.c:390386
int __cdecl KeyStone::Release()
{
  struct IKeystone *v0; // eax@1

  v0 = KeyStone::m_lpKeystone;
  if ( KeyStone::m_lpKeystone )
  {
    if ( KeyStone::m_fnAC2HelpPluginTerminate )
    {
      KeyStone::m_fnAC2HelpPluginTerminate();
      v0 = KeyStone::m_lpKeystone;
    }
    if ( v0 )
    {
      if ( KeyStone::m_fnAC2PluginManagerTerminate )
      {
        KeyStone::m_fnAC2PluginManagerTerminate();
        v0 = KeyStone::m_lpKeystone;
      }
      if ( v0 )
      {
        v0->vfptr->Release((IUnknown *)v0);
        KeyStone::m_lpKeystone = 0;
      }
    }
  }
  return 1;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;
// 86FC38: using guessed type int (*KeyStone::m_fnAC2HelpPluginTerminate)(void);
// 86FC40: using guessed type int (*KeyStone::m_fnAC2PluginManagerTerminate)(void);

//----- (00556F60) --------------------------------------------------------  // acclient.c:390419
int __cdecl KeyStone::Cleanup()
{
  struct IKeystone *v0; // eax@1

  v0 = KeyStone::m_lpKeystone;
  if ( KeyStone::m_lpKeystone )
  {
    if ( KeyStone::m_fnAC2HelpPluginTerminate )
    {
      KeyStone::m_fnAC2HelpPluginTerminate();
      v0 = KeyStone::m_lpKeystone;
    }
    if ( v0 )
    {
      if ( KeyStone::m_fnAC2PluginManagerTerminate )
      {
        KeyStone::m_fnAC2PluginManagerTerminate();
        v0 = KeyStone::m_lpKeystone;
      }
      if ( v0 )
      {
        v0->vfptr->Release((IUnknown *)v0);
        KeyStone::m_lpKeystone = 0;
      }
    }
  }
  if ( KeyStone::m_hKeystoneLib )
    FreeLibrary(KeyStone::m_hKeystoneLib);
  if ( KeyStone::m_hAC2HelpPluginLib )
    FreeLibrary(KeyStone::m_hAC2HelpPluginLib);
  if ( KeyStone::m_hAC2PluginManagerLib )
    FreeLibrary(KeyStone::m_hAC2PluginManagerLib);
  if ( KeyStone::m_hDummyAccel )
    DestroyAcceleratorTable(KeyStone::m_hDummyAccel);
  KeyStone::m_hKeystoneLib = 0;
  KeyStone::m_fnKeystoneCreate = 0;
  KeyStone::m_hAC2HelpPluginLib = 0;
  KeyStone::m_hAC2PluginManagerLib = 0;
  KeyStone::m_hDummyAccel = 0;
  return 1;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;
// 86FC24: using guessed type struct IKeystone *(__cdecl static *KeyStone::m_fnKeystoneCreate)(HWND, struct IDirect3DDevice9 *, const unsigned __int16 *, __int32 (__cdecl static *)(struct IDirect3DDevice9 *, const void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned __int32, enum _D3DFORMAT, enum _D3DPOOL, unsigned __int32, unsigned __int32, unsigned __int32, struct _D3DXIMAGE_INFO *, struct tagPALETTEENTRY *, struct IDirect3DTexture9 **), __int32 (__cdecl static *)(unsigned int, unsigned __int32, unsigned __int32, enum _D3DPOOL, struct IDirect3DVertexBuffer9 **), void *(__cdecl static *)(unsigned __int32), void (__cdecl static *)(void *));
// 86FC38: using guessed type int (*KeyStone::m_fnAC2HelpPluginTerminate)(void);
// 86FC40: using guessed type int (*KeyStone::m_fnAC2PluginManagerTerminate)(void);

//----- (00557010) --------------------------------------------------------  // acclient.c:390466
int __cdecl KeyStone::OpenHelp(const unsigned int _token, const int _table)
{
  int result; // eax@5
  char *v3; // esi@8
  PStringBase<unsigned short> help; // [sp+0h] [bp-A0h]@8
  StringInfo info; // [sp+4h] [bp-9Ch]@8
  int v6; // [sp+9Ch] [bp-4h]@8

  if ( !KeyStone::m_lpKeystone )
    goto LABEL_15;
  if ( KeyStone::m_fnAC2HelpPluginTerminate )
    KeyStone::m_fnAC2HelpPluginTerminate();
  if ( KeyStone::m_fnAC2HelpPluginExecute )
  {
    if ( _token )
    {
      StringInfo::StringInfo(&info);
      v6 = 0;
      StringInfo::SetStringIDandTableEnum(&info, _token, _table);
      StringInfo::GetString(&info, &help, 0);
      LOBYTE(v6) = 1;
      KeyStone::m_fnAC2HelpPluginExecute(
        KeyStone::m_lpKeystone,
        (unsigned __int16 *(__cdecl static *)(const unsigned __int16 *))UIObject::DynamicCast_UIViewportObject,
        help.m_charbuffer);
      v3 = (char *)&help.m_charbuffer[-1].m_data[6];
      LOBYTE(v6) = 0;
      if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
      }
      v6 = -1;
      StringInfo::~StringInfo(&info);
    }
    else
    {
      KeyStone::m_fnAC2HelpPluginExecute(
        KeyStone::m_lpKeystone,
        (unsigned __int16 *(__cdecl static *)(const unsigned __int16 *))UIObject::DynamicCast_UIViewportObject,
        0);
    }
    result = 1;
  }
  else
  {
LABEL_15:
    result = 0;
  }
  return result;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;
// 86FC34: using guessed type __int32 (__cdecl static *KeyStone::m_fnAC2HelpPluginExecute)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *);
// 86FC38: using guessed type int (*KeyStone::m_fnAC2HelpPluginTerminate)(void);

//----- (00557140) --------------------------------------------------------  // acclient.c:390522
int __cdecl KeyStone::IsPluginManagerOpen()
{
  unsigned int v0; // eax@1
  signed int v1; // edi@2
  signed int v2; // esi@3
  unsigned int v3; // eax@3
  char *v4; // esi@6
  PStringBase<unsigned short> v6; // [sp+8h] [bp-10h]@1
  int v7; // [sp+14h] [bp-4h]@1

  v0 = _wcslen(L"acpluginmanager");
  PStringBase<unsigned short>::allocate_ref_buffer(&v6, v0);
  _wcscpy(v6.m_charbuffer->m_data, L"acpluginmanager");
  v7 = 0;
  if ( KeyStone::m_lpKeystone )
  {
    v2 = 0;
    v3 = KeyStone::m_lpKeystone->vfptr[1].Release((IUnknown *)v6.m_charbuffer);
    if ( v3 )
    {
      v2 = 1;
      (*(void (__stdcall **)(unsigned int))(*(_DWORD *)v3 + 8))(v3);
    }
    v1 = v2;
  }
  else
  {
    v1 = 0;
  }
  v4 = (char *)&v6.m_charbuffer[-1].m_data[6];
  v7 = -1;
  if ( !InterlockedDecrement((volatile LONG *)&v6.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return v1;
}
// 86FC1C: using guessed type struct IKeystone *KeyStone::m_lpKeystone;

//----- (007072E0) --------------------------------------------------------  // acclient.c:794455
int sub_7072E0()
{
  return atexit(nullsub_1273);
}

//----- (007072F0) --------------------------------------------------------  // acclient.c:794461
int _E4_3()
{
  return atexit(_E5_3);
}

//----- (00707300) --------------------------------------------------------  // acclient.c:794467
int _E7_3()
{
  Outside_CellID_3.id = Invalid_CellID_3.id + 1;
  return atexit(_E8_3);
}

//----- (00707320) --------------------------------------------------------  // acclient.c:794474
int _E10_2()
{
  In_Limbo_CellID_2.id = Outside_CellID_3.id + 1;
  return atexit(_E11_2);
}

//----- (00707340) --------------------------------------------------------  // acclient.c:794481
int _E13_2()
{
  First_Interior_CellID_2.id = In_Limbo_CellID_2.id + 1;
  return atexit(_E14_2);
}

//----- (00707360) --------------------------------------------------------  // acclient.c:794488
int _E16_2()
{
  Last_Interior_CellID_2.id = Invalid_CellID_3.id - 1;
  return atexit(_E17_2);
}

//----- (00707380) --------------------------------------------------------  // acclient.c:794495
int _E21_4()
{
  return atexit(_E22_4);
}

//----- (00707390) --------------------------------------------------------  // acclient.c:794501
int _E40_2()
{
  return atexit(_E41_2);
}

//----- (007073A0) --------------------------------------------------------  // acclient.c:794507
int _E43_3()
{
  return atexit(_E44_3);
}

//----- (007073B0) --------------------------------------------------------  // acclient.c:794513
int sub_7073B0()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_30, "Display.Resolution");
  return atexit(_E74_81);
}

//----- (007073D0) --------------------------------------------------------  // acclient.c:794520
int _E76_66()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_30, "Display.FullScreen");
  return atexit(_E77_94);
}

//----- (007073F0) --------------------------------------------------------  // acclient.c:794527
int _E79_60()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_30, "Display.RefreshRate");
  return atexit(_E80_59);
}

//----- (00707410) --------------------------------------------------------  // acclient.c:794534
int _E82_39()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_30, "Display.SyncToRefresh");
  return atexit(_E83_37);
}

//----- (00707430) --------------------------------------------------------  // acclient.c:794541
void _E85_27()
{
  PixelFormatDesc::PixelFormatDesc(&stru_86FD1C, PFID_A8R8G8B8);
}

//----- (00707440) --------------------------------------------------------  // acclient.c:794547
void sub_707440()
{
  LODWORD(dword_86FD64) = 1053364187;
}

//----- (00707450) --------------------------------------------------------  // acclient.c:794553
void _E105_47()
{
  flt_86FD14 = 1000.0 + 1.0;
}

//----- (00707470) --------------------------------------------------------  // acclient.c:794559
void _E107_36()
{
  flt_86FD84 = 24.0 * 8.0;
}

//----- (00707490) --------------------------------------------------------  // acclient.c:794565
void _E109_71()
{
  flt_86FD68 = 24.0 * 0.5;
}

//----- (007074B0) --------------------------------------------------------  // acclient.c:794571
int _E111_47()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_35, "Render.TextureFiltering");
  return atexit(sub_772A10);
}

//----- (007074D0) --------------------------------------------------------  // acclient.c:794578
int _E114_57()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_35, "Render.LandscapeDetailTextures");
  return atexit(sub_772A40);
}

//----- (007074F0) --------------------------------------------------------  // acclient.c:794585
int _E117_65()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_35, "Render.BuildingDetailTextures");
  return atexit(sub_772A70);
}

//----- (00707510) --------------------------------------------------------  // acclient.c:794592
int _E120_63()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_35, "Render.FieldOfView");
  return atexit(sub_772AA0);
}

//----- (00707530) --------------------------------------------------------  // acclient.c:794599
int _E123_41()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_35, "Render.LandscapeTextureDetail");
  return atexit(sub_772AD0);
}

//----- (00707550) --------------------------------------------------------  // acclient.c:794606
int _E126_47()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_35, "Render.EnvironmentTextureDetail");
  return atexit(sub_772B00);
}

//----- (00707570) --------------------------------------------------------  // acclient.c:794613
int _E129_42()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_35, "Render.SceneryDrawDistance");
  return atexit(sub_772B30);
}

//----- (00707590) --------------------------------------------------------  // acclient.c:794620
int _E132_42()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_35, "Render.LandscapeDrawDistance");
  return atexit(sub_772B60);
}

//----- (007075B0) --------------------------------------------------------  // acclient.c:794627
int _E135_49()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_35, "Render.ScreenBrightness");
  return atexit(_E136_84);
}

//----- (007075D0) --------------------------------------------------------  // acclient.c:794634
int _E138_37()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_35, "Render.AspectRatio");
  return atexit(_E139_84);
}

//----- (007075F0) --------------------------------------------------------  // acclient.c:794641
int _E141_39()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_35, "Render.DisplayAdapter");
  return atexit(_E142_79);
}

//----- (00707610) --------------------------------------------------------  // acclient.c:794648
int _E144_36()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_35, "Render.MaxHardwareClass");
  return atexit(_E145_81);
}

//----- (00707630) --------------------------------------------------------  // acclient.c:794655
int _E147_35()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_35, "Render.AutomaticDegrades");
  return atexit(_E148_77);
}

//----- (00707650) --------------------------------------------------------  // acclient.c:794662
int _E150_34()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_35, "Render.GraphicsPerformance");
  return atexit(_E151_75);
}

//----- (00707670) --------------------------------------------------------  // acclient.c:794669
int _E153_32()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_35, "Render.DegradeDistance");
  return atexit(_E154_76);
}

//----- (00707690) --------------------------------------------------------  // acclient.c:794676
int _E156_34()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_35, "Render.MultiPassAlpha");
  return atexit(_E157_72);
}

//----- (007076B0) --------------------------------------------------------  // acclient.c:794683
int _E159_32()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_35, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_86FDD0, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_86FDD4, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_86FDD8, "Anisotropic");
  return atexit(_E160_75);
}

//----- (00707700) --------------------------------------------------------  // acclient.c:794693
int _E162_34()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_35, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_86FDB8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_86FDBC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86FDC0, "High");
  PStringBase<char>::PStringBase<char>(&stru_86FDC4, "VeryHigh");
  return atexit(_E163_68);
}

//----- (00707760) --------------------------------------------------------  // acclient.c:794704
int _E165_30()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_35, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_86FCE0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_86FCE4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86FCE8, "High");
  PStringBase<char>::PStringBase<char>(&stru_86FCEC, "VeryHigh");
  return atexit(_E166_70);
}

//----- (007077C0) --------------------------------------------------------  // acclient.c:794715
int _E168_31()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_35, "Low");
  PStringBase<char>::PStringBase<char>(&stru_86FD5C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86FD60, "High");
  return atexit(_E169_69);
}

//----- (00707800) --------------------------------------------------------  // acclient.c:794724
int _E171_30()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_35, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_86FDE0, "Low");
  PStringBase<char>::PStringBase<char>(&stru_86FDE4, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_86FDE8, "High");
  PStringBase<char>::PStringBase<char>(&stru_86FDEC, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_86FDF0, "Extreme");
  return atexit(_E172_67);
}

//----- (00707870) --------------------------------------------------------  // acclient.c:794736
int _E174_31()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_35, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_86FD78, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_86FD7C, "Wide");
  return atexit(_E175_64);
}

//----- (007078B0) --------------------------------------------------------  // acclient.c:794745
int _E177_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_61, "None");
  return atexit(_E178_64);
}

//----- (007078D0) --------------------------------------------------------  // acclient.c:794752
int _E180_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_61, "Speed");
  return atexit(_E181_64);
}

//----- (007078F0) --------------------------------------------------------  // acclient.c:794759
int _E183_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_61, "Noise");
  return atexit(_E184_61);
}

//----- (00707910) --------------------------------------------------------  // acclient.c:794766
int _E186_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_61, "Sine");
  return atexit(_E187_60);
}

//----- (00707930) --------------------------------------------------------  // acclient.c:794773
int _E189_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_61, "Square");
  return atexit(_E190_61);
}

//----- (00707950) --------------------------------------------------------  // acclient.c:794780
int _E192_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_61, "Bounce");
  return atexit(_E193_49);
}

//----- (00707970) --------------------------------------------------------  // acclient.c:794787
int _E195_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_61, "Perlin");
  return atexit(_E196_56);
}

//----- (00707990) --------------------------------------------------------  // acclient.c:794794
int _E198_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_61, "Fractal");
  return atexit(_E199_48);
}

//----- (007079B0) --------------------------------------------------------  // acclient.c:794801
int _E201_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_61, "FrameLoop");
  return atexit(_E202_49);
}

//----- (00772950) --------------------------------------------------------  // acclient.c:906432
void __cdecl _E74_81()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772980) --------------------------------------------------------  // acclient.c:906445
void __cdecl _E77_94()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007729B0) --------------------------------------------------------  // acclient.c:906458
void __cdecl _E80_59()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007729E0) --------------------------------------------------------  // acclient.c:906471
void __cdecl _E83_37()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772A10) --------------------------------------------------------  // acclient.c:906484
void __cdecl sub_772A10()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772A40) --------------------------------------------------------  // acclient.c:906497
void __cdecl sub_772A40()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772A70) --------------------------------------------------------  // acclient.c:906510
void __cdecl sub_772A70()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772AA0) --------------------------------------------------------  // acclient.c:906523
void __cdecl sub_772AA0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772AD0) --------------------------------------------------------  // acclient.c:906536
void __cdecl sub_772AD0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772B00) --------------------------------------------------------  // acclient.c:906549
void __cdecl sub_772B00()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772B30) --------------------------------------------------------  // acclient.c:906562
void __cdecl sub_772B30()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772B60) --------------------------------------------------------  // acclient.c:906575
void __cdecl sub_772B60()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772B90) --------------------------------------------------------  // acclient.c:906588
void __cdecl _E136_84()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772BC0) --------------------------------------------------------  // acclient.c:906601
void __cdecl _E139_84()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772BF0) --------------------------------------------------------  // acclient.c:906614
void __cdecl _E142_79()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772C20) --------------------------------------------------------  // acclient.c:906627
void __cdecl _E145_81()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772C50) --------------------------------------------------------  // acclient.c:906640
void __cdecl _E148_77()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772C80) --------------------------------------------------------  // acclient.c:906653
void __cdecl _E151_75()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772CB0) --------------------------------------------------------  // acclient.c:906666
void __cdecl _E154_76()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772CE0) --------------------------------------------------------  // acclient.c:906679
void __cdecl _E157_72()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772D10) --------------------------------------------------------  // acclient.c:906692
void __cdecl _E160_75()
{
  eh_vector_destructor_iterator(
    Render_TextureFiltering_Choices_35,
    4u,
    4,
    (void (__thiscall *)(void *))PStringBase<char>::~PStringBase<char>);
}

//----- (00772D30) --------------------------------------------------------  // acclient.c:906702
void __cdecl _E163_68()
{
  eh_vector_destructor_iterator(
    Render_LandscapeTextureDetail_Choices_35,
    4u,
    5,
    (void (__thiscall *)(void *))PStringBase<char>::~PStringBase<char>);
}

//----- (00772D50) --------------------------------------------------------  // acclient.c:906712
void __cdecl _E166_70()
{
  eh_vector_destructor_iterator(
    Render_EnvironmentTextureDetail_Choices_35,
    4u,
    5,
    (void (__thiscall *)(void *))PStringBase<char>::~PStringBase<char>);
}

//----- (00772D70) --------------------------------------------------------  // acclient.c:906722
void __cdecl _E169_69()
{
  eh_vector_destructor_iterator(
    Render_SceneryDrawDistance_Choices_35,
    4u,
    3,
    (void (__thiscall *)(void *))PStringBase<char>::~PStringBase<char>);
}

//----- (00772D90) --------------------------------------------------------  // acclient.c:906732
void __cdecl _E172_67()
{
  eh_vector_destructor_iterator(
    Render_LandscapeDrawDistance_Choices_35,
    4u,
    6,
    (void (__thiscall *)(void *))PStringBase<char>::~PStringBase<char>);
}

//----- (00772DB0) --------------------------------------------------------  // acclient.c:906742
void __cdecl _E175_64()
{
  eh_vector_destructor_iterator(
    Render_AspectRatio_Choices_35,
    4u,
    3,
    (void (__thiscall *)(void *))PStringBase<char>::~PStringBase<char>);
}

//----- (00772DD0) --------------------------------------------------------  // acclient.c:906752
void __cdecl _E178_64()
{
  char *v0; // esi@1

  v0 = &waveform_None_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772E00) --------------------------------------------------------  // acclient.c:906765
void __cdecl _E181_64()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772E30) --------------------------------------------------------  // acclient.c:906778
void __cdecl _E184_61()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772E60) --------------------------------------------------------  // acclient.c:906791
void __cdecl _E187_60()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772E90) --------------------------------------------------------  // acclient.c:906804
void __cdecl _E190_61()
{
  char *v0; // esi@1

  v0 = &waveform_Square_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772EC0) --------------------------------------------------------  // acclient.c:906817
void __cdecl _E193_49()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772EF0) --------------------------------------------------------  // acclient.c:906830
void __cdecl _E196_56()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772F20) --------------------------------------------------------  // acclient.c:906843
void __cdecl _E199_48()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00772F50) --------------------------------------------------------  // acclient.c:906856
void __cdecl _E202_49()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_61.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_61.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

