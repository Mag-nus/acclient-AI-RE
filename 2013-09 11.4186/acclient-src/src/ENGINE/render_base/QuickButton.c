/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QuickButton
   Object     : ENGINE\render_base\QuickButton.obj
   Functions  : 8
   Addresses  : 00698D80 - 00699240 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00698D80) --------------------------------------------------------  // acclient.c:688804
char __thiscall QuickButton::LeftMouseButtonPressed(QuickButton *this, const int _X, const int _Y)
{
  int v3; // edx@1
  char result; // al@1
  int v5; // esi@2

  v3 = this->m_X;
  result = 0;
  if ( _X >= v3 )
  {
    v5 = this->m_Y;
    if ( _Y >= v5 && _X < (signed int)(v3 + this->m_Width) && _Y < (signed int)(v5 + this->m_Height) )
    {
      result = 1;
      this->m_IsPressed = 1;
    }
  }
  return result;
}

//----- (00698DC0) --------------------------------------------------------  // acclient.c:688825
bool __thiscall QuickButton::LeftMouseButtonReleased(QuickButton *this, const int _X, const int _Y)
{
  int v3; // eax@2
  int v4; // edx@3
  bool result; // al@6

  result = 0;
  if ( this->m_IsPressed )
  {
    v3 = this->m_X;
    this->m_IsPressed = 0;
    if ( _X >= v3 )
    {
      v4 = this->m_Y;
      if ( _Y >= v4 && _X < (signed int)(v3 + this->m_Width) && _Y < (signed int)(v4 + this->m_Height) )
        result = 1;
    }
  }
  return result;
}

//----- (00698E10) --------------------------------------------------------  // acclient.c:688847
void __thiscall QuickButton::SetCheckedState(QuickButton *this, const bool _IsChecked)
{
  this->m_IsChecked = _IsChecked;
}

//----- (00698E20) --------------------------------------------------------  // acclient.c:688853
void __thiscall QuickButton::Render(QuickButton *this)
{
  QuickButton *v1; // esi@1
  char *v2; // eax@1
  float v3; // edx@1
  float v4; // ecx@1
  double v5; // st7@18
  RGBAColor ButtonLabelColor; // [sp+4h] [bp-20h]@1
  RGBAColor WindowColor; // [sp+14h] [bp-10h]@1

  v1 = this;
  v2 = (char *)&this->m_ColorAndOpacity;
  v3 = this->m_ColorAndOpacity.g;
  WindowColor.r = this->m_ColorAndOpacity.r;
  v4 = this->m_ColorAndOpacity.b;
  WindowColor.g = v3;
  LODWORD(WindowColor.a) = *((_DWORD *)v2 + 3);
  ButtonLabelColor = stru_8349EC;
  WindowColor.b = v4;
  if ( WindowColor.a < 0.0 )
    LODWORD(WindowColor.a) = 0;
  if ( WindowColor.r < 0.0 )
    LODWORD(WindowColor.r) = 0;
  if ( WindowColor.g < 0.0 )
    LODWORD(WindowColor.g) = 0;
  if ( WindowColor.b < 0.0 )
    LODWORD(WindowColor.b) = 0;
  RGBAColor::CapHigh(&WindowColor);
  if ( stru_8349EC.a < 0.0 )
    LODWORD(ButtonLabelColor.a) = 0;
  if ( ButtonLabelColor.r < 0.0 )
    LODWORD(ButtonLabelColor.r) = 0;
  if ( ButtonLabelColor.g < 0.0 )
    LODWORD(ButtonLabelColor.g) = 0;
  if ( ButtonLabelColor.b < 0.0 )
    LODWORD(ButtonLabelColor.b) = 0;
  RGBAColor::CapHigh(&ButtonLabelColor);
  if ( v1->m_IsPressed )
  {
    WindowColor.r = WindowColor.r * 0.25;
    WindowColor.g = WindowColor.g * 0.25;
    v5 = WindowColor.b * 0.25;
  }
  else
  {
    if ( !v1->m_IsChecked )
      goto LABEL_22;
    WindowColor.r = WindowColor.r * 1.75;
    WindowColor.g = WindowColor.g * 1.75;
    v5 = WindowColor.b * 1.75;
  }
  WindowColor.b = v5;
  ButtonLabelColor.r = ButtonLabelColor.r * 0.25;
  ButtonLabelColor.g = ButtonLabelColor.g * 0.25;
  ButtonLabelColor.b = ButtonLabelColor.b * 0.25;
LABEL_22:
  if ( WindowColor.a < 0.0 )
    LODWORD(WindowColor.a) = 0;
  if ( WindowColor.r < 0.0 )
    LODWORD(WindowColor.r) = 0;
  if ( WindowColor.g < 0.0 )
    LODWORD(WindowColor.g) = 0;
  if ( WindowColor.b < 0.0 )
    LODWORD(WindowColor.b) = 0;
  RGBAColor::CapHigh(&WindowColor);
  if ( ButtonLabelColor.a < 0.0 )
    LODWORD(ButtonLabelColor.a) = 0;
  if ( ButtonLabelColor.r < 0.0 )
    LODWORD(ButtonLabelColor.r) = 0;
  if ( ButtonLabelColor.g < 0.0 )
    LODWORD(ButtonLabelColor.g) = 0;
  if ( ButtonLabelColor.b < 0.0 )
    LODWORD(ButtonLabelColor.b) = 0;
  RGBAColor::CapHigh(&ButtonLabelColor);
  QuickWindow::RenderWindowBackground((QuickWindow *)&v1->vfptr, v1->m_pBackgroundTexture, &WindowColor);
  QuickWindow::RenderText(
    (QuickWindow *)&v1->vfptr,
    0,
    0,
    v1->m_ButtonLabel.m_charbuffer->m_data,
    (unsigned __int64)(ButtonLabelColor.b * 255.0) | (((unsigned int)(unsigned __int64)(ButtonLabelColor.g * 255.0) | (((unsigned int)(unsigned __int64)(ButtonLabelColor.r * 255.0) | ((unsigned int)(unsigned __int64)(ButtonLabelColor.a * 255.0) << 8)) << 8)) << 8));
}
// 795344: using guessed type float FLOAT_0_0;

//----- (00699120) --------------------------------------------------------  // acclient.c:688938
void __thiscall QuickButton::~QuickButton(QuickButton *this)
{
  QuickButton *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  int v5; // edi@6

  v1 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&QuickButton::vftable;
  this->m_IsPressed = 0;
  this->m_IsChecked = 0;
  v2 = this->m_ButtonLabel.m_charbuffer;
  if ( v2 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_ButtonLabel.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  v5 = (int)&v1->m_ButtonLabel.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  QuickWindow::~QuickWindow((QuickWindow *)&v1->vfptr);
}
// 800AA4: using guessed type int (__thiscall *QuickButton::vftable)(void *, char);

//----- (006991A0) --------------------------------------------------------  // acclient.c:688968
char __thiscall QuickButton::InitButton(QuickButton *this, const int _X, const int _Y, const unsigned int _Width, const unsigned int _Height, const unsigned int _BorderWidth, const unsigned int _BorderHeight, PStringBase<char> *_ButtonLabel)
{
  QuickButton *v8; // esi@1
  PSRefBufferCharData<char> *v9; // eax@2
  int v10; // edi@3
  PSRefBufferCharData<char> *v11; // eax@6
  char result; // al@7

  v8 = this;
  if ( QuickWindow::Init((QuickWindow *)&this->vfptr, _X, _Y, _Width, _Height, _BorderWidth, _BorderHeight) )
  {
    v8->m_IsPressed = 0;
    v8->m_IsChecked = 0;
    v9 = v8->m_ButtonLabel.m_charbuffer;
    if ( v9 != _ButtonLabel->m_charbuffer )
    {
      v10 = (int)&v9[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) )
      {
        if ( v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      }
      v11 = _ButtonLabel->m_charbuffer;
      v8->m_ButtonLabel.m_charbuffer = _ButtonLabel->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v11[-1]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00699220) --------------------------------------------------------  // acclient.c:689004
QuickButton *__thiscall QuickButton::scalar_deleting_destructor(QuickButton *this, unsigned int a2)
{
  QuickButton *v2; // esi@1

  v2 = this;
  QuickButton::~QuickButton(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00699240) --------------------------------------------------------  // acclient.c:689016
TResult *__cdecl QuickButton::Create(TResult *result, QuickButton **_pOutObject, const int _X, const int _Y, const unsigned int _Width, const unsigned int _Height, const unsigned int _BorderWidth, const unsigned int _BorderHeight, PStringBase<char> *_ButtonLabel)
{
  QuickWindow *v9; // eax@1
  QuickWindow *v10; // esi@1
  volatile LONG *v11; // ST18_4@2
  QuickButton *v12; // ecx@2
  QuickButton *v13; // ecx@6
  bool v14; // zf@7
  TResult *v15; // eax@10

  v9 = (QuickWindow *)operator new(0x50u);
  v10 = v9;
  if ( v9 )
  {
    QuickWindow::QuickWindow(v9);
    v10->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&QuickButton::vftable;
    LOBYTE(v10[1].vfptr) = 0;
    BYTE1(v10[1].vfptr) = 0;
    v11 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v10[1].m_cRef = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v11);
    v12 = (QuickButton *)v10;
  }
  else
  {
    v12 = 0;
  }
  *_pOutObject = v12;
  if ( !v12 )
  {
LABEL_10:
    v15 = result;
    result->m_val = -2147467259;
    return v15;
  }
  if ( !QuickButton::InitButton(v12, _X, _Y, _Width, _Height, _BorderWidth, _BorderHeight, _ButtonLabel) )
  {
    v13 = *_pOutObject;
    if ( *_pOutObject )
    {
      v14 = v13->m_cRef-- == 1;
      if ( v14 )
        ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
      *_pOutObject = 0;
    }
    goto LABEL_10;
  }
  v15 = result;
  result->m_val = 0;
  return v15;
}
// 800AA4: using guessed type int (__thiscall *QuickButton::vftable)(void *, char);

