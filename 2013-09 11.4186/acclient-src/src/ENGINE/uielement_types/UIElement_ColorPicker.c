/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_ColorPicker
   Object     : ENGINE\uielement_types\UIElement_ColorPicker.obj
   Functions  : 37
   Addresses  : 0046AE30 - 0075E310 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046AE30) --------------------------------------------------------  // acclient.c:167452
void __userpurge UIElement_ColorPicker::UIElement_ColorPicker(UIElement_ColorPicker *this@<ecx>, int a2@<edi>, LayoutDesc *i_layout, ElementDesc *i_full_desc)
{
  UIElement_ColorPicker *v4; // esi@1

  v4 = this;
  UIElement::UIElement((UIElement *)&this->vfptr, a2, i_layout, i_full_desc);
  v4->m_bDisplaySelection = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_ColorPicker::vftable;
  LODWORD(v4->m_rgbaCurrentSelected.r) = 0;
  LODWORD(v4->m_rgbaCurrentSelected.g) = 0;
  LODWORD(v4->m_rgbaCurrentSelected.b) = 0;
  LODWORD(v4->m_rgbaCurrentSelected.a) = 0;
  v4->m_nFlags |= 0x2000u;
  v4->m_nCurrentSelection = -1;
}
// 79C3D0: using guessed type int (__thiscall *UIElement_ColorPicker::vftable)(void *, char);

//----- (0046AE90) --------------------------------------------------------  // acclient.c:167470
signed int __thiscall UIElement_ColorPicker::DynamicCast(UIElement_ColorPicker *this, unsigned int i_eType)
{
  return i_eType != 16 ? 0 : (unsigned int)this;
}

//----- (0046AEB0) --------------------------------------------------------  // acclient.c:167476
void __usercall UIElement_ColorPicker::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_ColorPicker *v3; // eax@1

  v3 = (UIElement_ColorPicker *)operator new(0x608u);
  if ( v3 )
    UIElement_ColorPicker::UIElement_ColorPicker(v3, a1, _layout, _full_desc);
}

//----- (0046AEE0) --------------------------------------------------------  // acclient.c:167486
char __thiscall UIElement_ColorPicker::SetCurrentSelectedColor(UIElement_ColorPicker *this, RGBAColor *i_rgba)
{
  UIElement_ColorPicker *v2; // esi@1
  Graphic *v3; // eax@1
  RenderSurface *v4; // edi@2
  unsigned int v5; // ST0C_4@4
  char result; // al@4
  int x; // [sp+0h] [bp-4h]@1

  x = (int)this;
  v2 = this;
  v3 = this->m_image;
  if ( v3
    && (v4 = v3->m_image) != 0
    && (this->m_rgbaCurrentSelected = *i_rgba,
        x = 0,
        i_rgba = 0,
        SurfaceWindow::SearchForColor(&v4->window, &x, (int *)&i_rgba, &this->m_rgbaCurrentSelected, 0)) )
  {
    v5 = (_DWORD)i_rgba * v4->width + x;
    v2->m_nCurrentSelection = v5;
    UIElement::BroadcastElementMessage((UIElement *)&v2->vfptr, 0x30u, v5, 0);
    UIRegion::MakeRootDirtyHere((UIRegion *)&v2->vfptr);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046AF90) --------------------------------------------------------  // acclient.c:167519
bool __thiscall UIElement_ColorPicker::IndexToRGBA(UIElement_ColorPicker *this, const unsigned int *i_index, RGBAColor *o_rgbaVal)
{
  Graphic *v3; // eax@1
  RenderSurface *v4; // ecx@2
  unsigned int v5; // esi@3
  unsigned int v6; // eax@4
  bool result; // al@5

  v3 = this->m_image;
  if ( v3 && (v4 = v3->m_image) != 0 && (v5 = v4->width) != 0 && (v6 = *i_index, *i_index < v5 * v4->height) )
    result = SurfaceWindow::GetColorFromPoint(&v4->window, o_rgbaVal, v6 % v5, v6 / v5) != 0;
  else
    result = 0;
  return result;
}

//----- (0046AFF0) --------------------------------------------------------  // acclient.c:167536
void __thiscall UIElement_ColorPicker::HandleMouseClick(UIElement_ColorPicker *this, tagPOINT *i_ptElement)
{
  UIElement_ColorPicker *v2; // esi@1
  int v3; // eax@1
  float v4; // eax@2
  int v5; // ecx@2
  float v6; // edx@2
  float v7; // eax@2
  RGBAColor rgbaVal; // [sp+8h] [bp-20h]@1
  char v9; // [sp+18h] [bp-10h]@1

  v2 = this;
  v3 = ((int (__stdcall *)(char *))this->vfptr[4].OnAction)(&v9);
  v2->m_nCurrentSelection = i_ptElement->x + i_ptElement->y * (*(_DWORD *)(v3 + 8) - *(_DWORD *)v3 + 1);
  if ( UIElement_ColorPicker::IndexToRGBA(v2, &v2->m_nCurrentSelection, &rgbaVal) )
  {
    v4 = rgbaVal.g;
    v5 = (int)&v2->m_rgbaCurrentSelected;
    *(_DWORD *)v5 = (_DWORD)rgbaVal.r;
    v6 = rgbaVal.b;
    *(float *)(v5 + 4) = v4;
    v7 = rgbaVal.a;
    *(float *)(v5 + 8) = v6;
    *(float *)(v5 + 12) = v7;
  }
  UIElement::BroadcastElementMessage((UIElement *)&v2->vfptr, 0x30u, v2->m_nCurrentSelection, 0);
  UIRegion::MakeRootDirtyHere((UIRegion *)&v2->vfptr);
}

//----- (0046B070) --------------------------------------------------------  // acclient.c:167566
void __thiscall UIElement_ColorPicker::DrawSelf(UIElement_ColorPicker *this, Box2D *i_rectObjectSelf, Box2D *i_rectObjectClip, SmartArray<Box2D,1> *i_aObjectBoxes, UISurface *i_pSurface)
{
  UIElement_ColorPicker *v5; // esi@1
  SurfaceWindow *v6; // ebx@2
  int v7; // eax@2
  unsigned int v8; // ecx@2
  int v9; // eax@2
  int v10; // edx@2
  int v11; // ecx@2
  int v12; // ebp@2
  int v13; // eax@4
  int v14; // esi@4
  int v15; // ecx@6
  int v16; // eax@8
  RGBAColor color; // [sp+Ch] [bp-10h]@2
  SmartArray<Box2D,1> *i_aObjectBoxesa; // [sp+28h] [bp+Ch]@2
  int i_pSurfacea; // [sp+2Ch] [bp+10h]@2

  v5 = this;
  UIRegion::DrawSelf((UIRegion *)&this->vfptr, i_rectObjectSelf, i_rectObjectClip, i_aObjectBoxes, i_pSurface);
  if ( v5->m_nCurrentSelection != -1 )
  {
    UISurface::PrepareSurface(i_pSurface);
    v6 = &i_pSurface->m_pLocalSurface->window;
    v7 = v5->vfptr[4].OnAction((IInputActionCallback *)v5, (InputEvent *)&color);
    v8 = *(_DWORD *)(v7 + 8) - *(_DWORD *)v7 + 1;
    v9 = v5->m_nCurrentSelection / v8;
    v10 = v5->m_nCurrentSelection % v8;
    v11 = i_rectObjectSelf->m_x0;
    v12 = i_rectObjectSelf->m_y0;
    i_pSurfacea = i_rectObjectSelf->m_x0;
    i_aObjectBoxesa = (SmartArray<Box2D,1> *)v9;
    if ( i_rectObjectSelf->m_x0 + v10 - 2 >= i_rectObjectSelf->m_x0 )
      i_pSurfacea = v11 + v10 - 2;
    v13 = v9 + v12 - 2;
    v14 = i_rectObjectSelf->m_y0;
    if ( v13 >= v12 )
      v14 = v13;
    v15 = v11 + v10 + 2;
    if ( v15 > i_rectObjectSelf->m_x1 )
      v15 = i_rectObjectSelf->m_x1;
    v16 = (int)((char *)&i_aObjectBoxesa->m_data + v12 + 2);
    if ( v16 > i_rectObjectSelf->m_y1 )
      v16 = i_rectObjectSelf->m_y1;
    LODWORD(color.r) = 1065353216;
    LODWORD(color.g) = 1065353216;
    LODWORD(color.b) = 1065353216;
    LODWORD(color.a) = 1065353216;
    SurfaceWindow::DrawBox(v6, &color, i_pSurfacea, v14, v15, v16);
  }
}

//----- (0046B150) --------------------------------------------------------  // acclient.c:167619
void __cdecl UIElement_ColorPicker::Register()
{
  UIElement::RegisterElementClass(
    0x10u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_ColorPicker::Create);
}

//----- (0046B160) --------------------------------------------------------  // acclient.c:167627
UIElement_ColorPicker *__thiscall UIElement_ColorPicker::scalar_deleting_destructor(UIElement_ColorPicker *this, unsigned int a2)
{
  UIElement_ColorPicker *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_ColorPicker::vftable;
  UIElement::~UIElement((UIElement *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79C3D0: using guessed type int (__thiscall *UIElement_ColorPicker::vftable)(void *, char);

//----- (0046B190) --------------------------------------------------------  // acclient.c:167641
void __userpurge UIElement_ColorPicker::OnSetAttribute(UIElement_ColorPicker *this@<ecx>, int a2@<ebx>, BaseProperty *i_attribute)
{
  BaseProperty *v3; // esi@1
  UIElement_ColorPicker *v4; // edi@1
  char *v5; // eax@1
  BasePropertyValue *v6; // ecx@3
  BasePropertyValue *v7; // ecx@6
  RGBAColor rgbaVal; // [sp+8h] [bp-10h]@3

  v3 = i_attribute;
  v4 = this;
  UIElement::OnSetAttribute((UIElement *)&this->vfptr, a2, i_attribute);
  v5 = (char *)&BaseProperty::GetPropertyName(v3)[-1].m_ePatchFlags + 2;
  if ( v5 )
  {
    if ( v5 == (char *)1 )
    {
      v6 = v3->m_pcPropertyValue;
      LODWORD(rgbaVal.r) = 0;
      LODWORD(rgbaVal.g) = 0;
      LODWORD(rgbaVal.b) = 0;
      LODWORD(rgbaVal.a) = 1065353216;
      if ( v6 )
        ((void (__stdcall *)(RGBAColor *))v6->vfptr[38].__vecDelDtor)(&rgbaVal);
      UIElement_ColorPicker::SetCurrentSelectedColor(v4, &rgbaVal);
    }
  }
  else
  {
    v7 = v3->m_pcPropertyValue;
    LOBYTE(i_attribute) = 0;
    if ( v7 )
      ((void (__stdcall *)(BaseProperty **))v7->vfptr[28].__vecDelDtor)(&i_attribute);
    v4->m_bDisplaySelection = (char)i_attribute;
  }
}

//----- (0046B230) --------------------------------------------------------  // acclient.c:167679
int __thiscall UIElement_ColorPicker::ListenToElementMessage(UIElement_ColorPicker *this, UIElementMessageInfo *i_rMsg)
{
  int result; // eax@3

  if ( (UIElement_ColorPicker *)i_rMsg->pElement != this || i_rMsg->idMessage != 25 )
  {
    result = UIElement::ListenToElementMessage((UIElement *)&this->vfptr, i_rMsg);
  }
  else
  {
    UIElement_ColorPicker::HandleMouseClick(this, &i_rMsg->ptElement);
    result = 2;
  }
  return result;
}

//----- (0046B260) --------------------------------------------------------  // acclient.c:167696
char __thiscall UIElement_ColorPicker::InqAvailableProperties(UIElement_ColorPicker *this, AvailablePropertySet *o_set)
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
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)o_set, 3u, v2) )
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

//----- (0046D590) --------------------------------------------------------  // acclient.c:170061
BOOL __thiscall UIElement_ColorPicker::GetShouldBeMouseVisible(UIElement_ColorPicker *this)
{
  UIElement_ColorPicker *v1; // esi@1

  v1 = this;
  return (unsigned __int8)UIElement::GetShouldBeMouseVisible((UIElement *)&this->vfptr) || v1->m_state != 13;
}

//----- (006EBA30) --------------------------------------------------------  // acclient.c:767451
void _E73_66()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_41, PFID_A8R8G8B8);
}

//----- (006EBA40) --------------------------------------------------------  // acclient.c:767457
int _E91_32()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_7, "Misc.TooltipEnable");
  return atexit(_E92_30);
}

//----- (006EBA60) --------------------------------------------------------  // acclient.c:767464
int _E94_19()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_7, "Misc.TooltipDelay");
  return atexit(sub_75E160);
}

//----- (006EBA80) --------------------------------------------------------  // acclient.c:767471
int _E97_32()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_31, "None");
  return atexit(_E98_45);
}

//----- (006EBAA0) --------------------------------------------------------  // acclient.c:767478
int _E100_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_31, "Speed");
  return atexit(_E101_64);
}

//----- (006EBAC0) --------------------------------------------------------  // acclient.c:767485
int _E103_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_31, "Noise");
  return atexit(_E104_35);
}

//----- (006EBAE0) --------------------------------------------------------  // acclient.c:767492
int _E106_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_31, "Sine");
  return atexit(_E107_67);
}

//----- (006EBB00) --------------------------------------------------------  // acclient.c:767499
int _E109_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_31, "Square");
  return atexit(sub_75E250);
}

//----- (006EBB20) --------------------------------------------------------  // acclient.c:767506
int _E112_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_31, "Bounce");
  return atexit(_E113_46);
}

//----- (006EBB40) --------------------------------------------------------  // acclient.c:767513
int _E115_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_31, "Perlin");
  return atexit(_E116_38);
}

//----- (006EBB60) --------------------------------------------------------  // acclient.c:767520
int _E118_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_31, "Fractal");
  return atexit(_E119_69);
}

//----- (006EBB80) --------------------------------------------------------  // acclient.c:767527
int _E121_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_31, "FrameLoop");
  return atexit(_E122_56);
}

//----- (006EBBA0) --------------------------------------------------------  // acclient.c:767534
int _E1_58()
{
  return atexit(_E2_58);
}

//----- (0075E130) --------------------------------------------------------  // acclient.c:886332
void __cdecl _E92_30()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E160) --------------------------------------------------------  // acclient.c:886345
void __cdecl sub_75E160()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E190) --------------------------------------------------------  // acclient.c:886358
void __cdecl _E98_45()
{
  char *v0; // esi@1

  v0 = &waveform_None_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E1C0) --------------------------------------------------------  // acclient.c:886371
void __cdecl _E101_64()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E1F0) --------------------------------------------------------  // acclient.c:886384
void __cdecl _E104_35()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E220) --------------------------------------------------------  // acclient.c:886397
void __cdecl _E107_67()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E250) --------------------------------------------------------  // acclient.c:886410
void __cdecl sub_75E250()
{
  char *v0; // esi@1

  v0 = &waveform_Square_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E280) --------------------------------------------------------  // acclient.c:886423
void __cdecl _E113_46()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E2B0) --------------------------------------------------------  // acclient.c:886436
void __cdecl _E116_38()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E2E0) --------------------------------------------------------  // acclient.c:886449
void __cdecl _E119_69()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E310) --------------------------------------------------------  // acclient.c:886462
void __cdecl _E122_56()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

