/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Browser
   Object     : ENGINE\uielement_types\UIElement_Browser.obj
   Functions  : 25
   Addresses  : 0046B2B0 - 0075E3E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046B2B0) --------------------------------------------------------  // acclient.c:167724
HRESULT __cdecl RedirectWindowDC_Thunk(HWND__ *i_hwnd)
{
  HRESULT (__stdcall *v1)(HWND__ *, bool, IAlternateDCProvider *); // eax@1
  HMODULE v2; // eax@2
  HRESULT result; // eax@5
  HWND__ *v4; // [sp+0h] [bp-4h]@0
  void *retaddr; // [sp+4h] [bp+0h]@5

  v1 = pfnRedirectWindowDC;
  if ( pfnRedirectWindowDC )
    goto LABEL_9;
  v2 = hModule;
  if ( !hModule )
  {
    v2 = LoadLibraryA("Trowser.dll");
    hModule = v2;
  }
  v1 = (HRESULT (__stdcall *)(HWND__ *, bool, IAlternateDCProvider *))GetProcAddress(v2, "RedirectWindowDC");
  pfnRedirectWindowDC = v1;
  if ( v1 )
LABEL_9:
    result = v1(v4, (bool)retaddr, (IAlternateDCProvider *)i_hwnd);
  else
    result = -2147418113;
  return result;
}

//----- (0046B300) --------------------------------------------------------  // acclient.c:167752
void __userpurge UIElement_Browser::UIElement_Browser(UIElement_Browser *this@<ecx>, int a2@<edi>, LayoutDesc *layout, ElementDesc *full_desc)
{
  UIElement_Browser *v4; // esi@1
  int v5; // eax@1
  char v6; // dl@1
  bool v7; // zf@1
  HMODULE v8; // eax@2

  v4 = this;
  UIElement::UIElement((UIElement *)&this->vfptr, a2, layout, full_desc);
  v5 = dword_83D46C;
  v6 = ~(unsigned __int8)(*((_DWORD *)&v4->0 + 41) >> 1) & 1;
  v7 = dword_83D46C == 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Browser::vftable;
  v4->vfptr = (IAlternateDCProviderVtbl *)&UIElement_Browser::vftable;
  v4->vfptr = (IBrowserCallbackVtbl *)&UIElement_Browser::vftable;
  v4->m_pWebBrowser = 0;
  v4->m_fLastTrueVisibility = v6;
  v4->m_fAllowFullscreenBrowser = 0;
  if ( !v7 )
    goto LABEL_8;
  v8 = hModule;
  if ( !hModule )
  {
    v8 = LoadLibraryA("Trowser.dll");
    hModule = v8;
  }
  v5 = (int)GetProcAddress(v8, "CreateBrowserControl");
  dword_83D46C = v5;
  if ( v5 )
LABEL_8:
    ((void (__stdcall *)(IBrowserControl **))v5)(&v4->m_pWebBrowser);
}
// 79C544: using guessed type void (__thiscall *UIElement_Browser::vftable)(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 79C564: using guessed type bool (__thiscall *UIElement_Browser::vftable)(AsyncCache *this, const struct QualifiedDataID *i_nMin, struct DBOCache *);
// 79C570: using guessed type int (__thiscall *UIElement_Browser::vftable)(void *, char);
// 83D46C: using guessed type int dword_83D46C;

//----- (0046B3A0) --------------------------------------------------------  // acclient.c:167791
signed int __thiscall UIElement_Browser::DynamicCast(UIElement_Browser *this, unsigned int i_eType)
{
  return i_eType != 14 ? 0 : (unsigned int)this;
}

//----- (0046B3C0) --------------------------------------------------------  // acclient.c:167797
void __usercall UIElement_Browser::Create(int a1@<edi>, LayoutDesc *layout, ElementDesc *full_desc)
{
  UIElement_Browser *v3; // eax@1

  v3 = (UIElement_Browser *)operator new(0x600u);
  if ( v3 )
    UIElement_Browser::UIElement_Browser(v3, a1, layout, full_desc);
}

//----- (0046B3F0) --------------------------------------------------------  // acclient.c:167807
void __thiscall UIElement_Browser::SetVisible(UIElement_Browser *this, int visible)
{
  UIElement_Browser *v2; // esi@1
  char v3; // al@1
  char v4; // bl@1
  IBrowserControl *v5; // ecx@9

  v2 = this;
  UIElement::SetVisible((UIElement *)&this->vfptr, visible);
  v3 = UIElement::IsVisible((UIElement *)&v2->vfptr);
  v4 = v3;
  LOBYTE(visible) = v3;
  if ( v2->m_fLastTrueVisibility != v3 )
  {
    if ( v3 )
    {
      ++UIElement_Browser::sm_cVisibleWindows;
      if ( UIElement_Browser::sm_cVisibleWindows == 1 && !v2->m_fAllowFullscreenBrowser )
        Device::AllowFullScreenMode(0);
    }
    else
    {
      --UIElement_Browser::sm_cVisibleWindows;
      if ( !UIElement_Browser::sm_cVisibleWindows )
        Device::AllowFullScreenMode(1);
    }
    v2->m_fLastTrueVisibility = v4;
  }
  v5 = v2->m_pWebBrowser;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr[2].QueryInterface)(visible);
}
// 83D40C: using guessed type unsigned __int32 UIElement_Browser::sm_cVisibleWindows;

//----- (0046B470) --------------------------------------------------------  // acclient.c:167842
void __usercall UIElement_Browser::UpdateForScreenPositionChange(UIElement_Browser *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  UIElement_Browser *v3; // esi@1
  unsigned int v4; // edi@2
  unsigned int v5; // eax@2

  v3 = this;
  UIElement::UpdateForScreenPositionChange((UIElement *)&this->vfptr, a2, a3);
  if ( v3->m_pWebBrowser )
  {
    v4 = UIRegion::GetScreenX0((UIRegion *)&v3->vfptr);
    v5 = UIRegion::GetScreenY0((UIRegion *)&v3->vfptr);
    ((void (__stdcall *)(unsigned int, unsigned int))v3->m_pWebBrowser->vfptr[1].AddRef)(v4, v5);
  }
}

//----- (0046B4B0) --------------------------------------------------------  // acclient.c:167859
void __thiscall UIElement_Browser::PostBlit(UIElement_Browser *this, Box2D *i_boxDest, UISurface *i_pTargetSurface)
{
  bool v3; // al@2

  if ( this->m_fAllowFullscreenBrowser )
  {
    v3 = RenderDevice::render_device->m_presentation.FullScreen;
    if ( v3 != this->m_fFullScreen )
      this->m_fFullScreen = v3;
  }
}

//----- (0046B4E0) --------------------------------------------------------  // acclient.c:167872
char __thiscall UIElement_Browser::CreateWindowHelper(UIElement_Browser *this)
{
  UIElement_Browser *v1; // esi@1
  unsigned int v2; // edi@1
  unsigned int v3; // ebx@1
  int v4; // ebp@1
  int v5; // eax@1
  IBrowserControl *v6; // ecx@1
  HWND__ *v7; // eax@3
  IUnknownVtbl *v8; // edi@3
  int v9; // eax@3
  char result; // al@3

  v1 = this;
  v2 = UIRegion::GetScreenX0((UIRegion *)&this->vfptr);
  v3 = UIRegion::GetScreenY0((UIRegion *)&v1->vfptr);
  v4 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
  v5 = UIRegion::GetHeight((UIRegion *)&v1->vfptr);
  v6 = v1->m_pWebBrowser;
  if ( v6
    && (unsigned __int8)((int (__stdcall *)(HWND, unsigned int, unsigned int, int, int, int))v6->vfptr[1].QueryInterface)(
                          Device::m_hWnd,
                          v2,
                          v3,
                          v4,
                          v5,
                          &v1->vfptr) )
  {
    v7 = (HWND__ *)((int (__cdecl *)(signed int, int))v1->m_pWebBrowser->vfptr[2].AddRef)(1, &v1->vfptr);
    RedirectWindowDC_Thunk(v7);
    v8 = v1->m_pWebBrowser->vfptr;
    LOBYTE(v9) = UIElement::IsVisible((UIElement *)&v1->vfptr);
    ((void (__thiscall *)(IBrowserControl *, int))v8[2].QueryInterface)(v1->m_pWebBrowser, v9);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046B580) --------------------------------------------------------  // acclient.c:167915
char __thiscall UIElement_Browser::ReleaseDC(UIElement_Browser *this, HDC__ *i_hdc, int *o_iResult)
{
  char result; // al@3

  if ( LOBYTE(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0])
    && BYTE2(this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0]) )
  {
    UIRegion::MakeRootDirtyHere((UIRegion *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]);
    *o_iResult = 1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046B5B0) --------------------------------------------------------  // acclient.c:167934
UIElement_Browser *__thiscall UIElement_Browser::vector_deleting_destructor(UIElement_Browser *this, unsigned int a2)
{
  UIElement_Browser *v2; // esi@1
  IBrowserControl *v3; // eax@1

  v2 = this;
  v3 = this->m_pWebBrowser;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Browser::vftable;
  this->vfptr = (IAlternateDCProviderVtbl *)&UIElement_Browser::vftable;
  this->vfptr = (IBrowserCallbackVtbl *)&UIElement_Browser::vftable;
  if ( v3 )
  {
    v3->vfptr->Release((IUnknown *)v3);
    v2->m_pWebBrowser = 0;
  }
  UIElement::~UIElement((UIElement *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79C544: using guessed type void (__thiscall *UIElement_Browser::vftable)(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int);
// 79C564: using guessed type bool (__thiscall *UIElement_Browser::vftable)(AsyncCache *this, const struct QualifiedDataID *i_nMin, struct DBOCache *);
// 79C570: using guessed type int (__thiscall *UIElement_Browser::vftable)(void *, char);

//----- (0046B610) --------------------------------------------------------  // acclient.c:167959
void __cdecl UIElement_Browser::Register()
{
  UIElement::RegisterElementClass(0xEu, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Browser::Create);
}

//----- (0046B620) --------------------------------------------------------  // acclient.c:167965
void __thiscall UIElement_Browser::Initialize(UIElement_Browser *this)
{
  UIRegion *v1; // esi@1

  v1 = (UIRegion *)this;
  UIRegion::GetHeight((UIRegion *)&this->vfptr);
  UIRegion::GetWidth(v1);
  UIElement_Browser::CreateWindowHelper((UIElement_Browser *)v1);
  UIElement::Initialize((UIElement *)v1);
}

//----- (0046B640) --------------------------------------------------------  // acclient.c:167977
void __userpurge UIElement_Browser::ResizeTo(UIElement_Browser *this@<ecx>, int a2@<edi>, const int cx, const int cy)
{
  UIElement_Browser *v4; // esi@1
  IBrowserControl *v5; // eax@1
  IUnknownVtbl *v6; // edi@2
  int v7; // ST04_4@2
  int v8; // eax@2

  v4 = this;
  UIElement::ResizeTo((UIElement *)&this->vfptr, a2, cx, cy);
  UIRegion::GetHeight((UIRegion *)&v4->vfptr);
  UIRegion::GetWidth((UIRegion *)&v4->vfptr);
  v5 = v4->m_pWebBrowser;
  if ( v5 )
  {
    v6 = v5->vfptr;
    v7 = UIRegion::GetHeight((UIRegion *)&v4->vfptr);
    v8 = UIRegion::GetWidth((UIRegion *)&v4->vfptr);
    ((void (__thiscall *)(IBrowserControl *, int, int))v6[1].Release)(v4->m_pWebBrowser, v8, v7);
  }
}

//----- (0046B690) --------------------------------------------------------  // acclient.c:168000
char __thiscall UIElement_Browser::InqAvailableProperties(UIElement_Browser *this, AvailablePropertySet *o_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = o_set;
  v3 = 1;
  if ( !UIElement::InqAvailableProperties((UIElement *)&this->vfptr, o_set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&o_set);
  v4 = o_set;
  if ( o_set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)o_set, 2u, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046B6E0) --------------------------------------------------------  // acclient.c:168028
void __userpurge UIElement_Browser::OnSetAttribute(UIElement_Browser *this@<ecx>, int a2@<ebx>, BaseProperty *i_attribute)
{
  BaseProperty *v3; // esi@1
  UIElement_Browser *v4; // edi@1
  BasePropertyValue *v5; // ecx@3
  char *v6; // esi@6

  v3 = i_attribute;
  v4 = this;
  UIElement::OnSetAttribute((UIElement *)&this->vfptr, a2, i_attribute);
  if ( BaseProperty::GetPropertyName(v3) == (BasePropertyDesc *)173 && v4->m_pWebBrowser )
  {
    i_attribute = (BaseProperty *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v5 = v3->m_pcPropertyValue;
    if ( v5 && (unsigned __int8)((int (__stdcall *)(BaseProperty **))v5->vfptr[40].__vecDelDtor)(&i_attribute) )
      ((void (__stdcall *)(BaseProperty *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v4->m_pWebBrowser->vfptr[2].Release)(
        i_attribute,
        0,
        0,
        0,
        0,
        0);
    v6 = (char *)&i_attribute[-3].m_pcPropertyValue;
    if ( !InterlockedDecrement((volatile LONG *)&i_attribute[-2]) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
  }
}

//----- (006EBBB0) --------------------------------------------------------  // acclient.c:767540
void _E73_67()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_42, PFID_A8R8G8B8);
}

//----- (006EBBC0) --------------------------------------------------------  // acclient.c:767546
int _E91_33()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_10, "Display.Resolution");
  return atexit(_E92_31);
}

//----- (006EBBE0) --------------------------------------------------------  // acclient.c:767553
int _E94_20()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_10, "Display.FullScreen");
  return atexit(sub_75E380);
}

//----- (006EBC00) --------------------------------------------------------  // acclient.c:767560
int _E97_33()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_10, "Display.RefreshRate");
  return atexit(_E98_46);
}

//----- (006EBC20) --------------------------------------------------------  // acclient.c:767567
int _E100_26()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_10, "Display.SyncToRefresh");
  return atexit(_E101_65);
}

//----- (006EBC40) --------------------------------------------------------  // acclient.c:767574
int _E1_59()
{
  return atexit(_E2_59);
}

//----- (0075E350) --------------------------------------------------------  // acclient.c:886475
void __cdecl _E92_31()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E380) --------------------------------------------------------  // acclient.c:886488
void __cdecl sub_75E380()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E3B0) --------------------------------------------------------  // acclient.c:886501
void __cdecl _E98_46()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E3E0) --------------------------------------------------------  // acclient.c:886514
void __cdecl _E101_65()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

