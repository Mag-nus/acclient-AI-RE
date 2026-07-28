/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIMainFramework
   Object     : ENGINE\uiframework\UIMainFramework.obj
   Functions  : 30
   Addresses  : 006A0C00 - 00790160 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A0C00) --------------------------------------------------------  // acclient.c:697341
int __thiscall UIMainFramework::CreateAndAddRootElement(UIMainFramework *this, const unsigned int layoutEnum, const unsigned int elementID)
{
  UIMainFramework *v3; // esi@1
  int result; // eax@1

  v3 = this;
  DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&layoutEnum, layoutEnum, 5);
  result = 0;
  if ( layoutEnum != stru_8F9CA0.id )
    result = ((int (__thiscall *)(UIMainFramework *, const unsigned int, const unsigned int))v3->vfptr[2].OnAction)(
               v3,
               layoutEnum,
               elementID);
  return result;
}

//----- (006A0C40) --------------------------------------------------------  // acclient.c:697358
void __thiscall UIMainFramework::RemoveRootElement(UIMainFramework *this, UIElement **element)
{
  UIListener *v2; // edi@1
  char v3; // bl@2

  v2 = (UIListener *)this;
  if ( *element )
  {
    v3 = SmartArray<UIElement *,1>::RemoveUnOrdered(
           (SmartArray<bool (__cdecl*)(void),1> *)&this->m_rootElements,
           (bool (__cdecl *const *)())element);
    UIElement::UnregisterForElementMessages(*element, v2);
    if ( v3 )
      UIElementManager::RemoveAndDeleteRootElement(UIElementManager::s_pInstance, *element);
    *element = 0;
  }
}

//----- (006A0C90) --------------------------------------------------------  // acclient.c:697377
void __thiscall UIMainFramework::UIMainFramework(UIMainFramework *this)
{
  UIMainFramework *v1; // esi@1

  v1 = this;
  UIFramework::UIFramework((UIFramework *)&this->vfptr);
  v1->vfptr = (IInputActionCallbackVtbl *)&UIMainFramework::vftable;
  v1->m_rootElements.m_data = 0;
  v1->m_rootElements.m_sizeAndDeallocate = 0;
  v1->m_rootElements.m_num = 0;
}
// 801800: using guessed type int (__thiscall *UIMainFramework::vftable)(void *, char);

//----- (006A0CC0) --------------------------------------------------------  // acclient.c:697391
void __thiscall UIMainFramework::~UIMainFramework(UIMainFramework *this)
{
  UIMainFramework *v1; // esi@1

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIMainFramework::vftable;
  DialogFactory::Reset();
  if ( (v1->m_rootElements.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_rootElements.m_data);
  UIFramework::~UIFramework((UIFramework *)&v1->vfptr);
}
// 801800: using guessed type int (__thiscall *UIMainFramework::vftable)(void *, char);

//----- (006A0D00) --------------------------------------------------------  // acclient.c:697405
UIMainFramework *__thiscall UIMainFramework::scalar_deleting_destructor(UIMainFramework *this, unsigned int a2)
{
  UIMainFramework *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIMainFramework::vftable;
  DialogFactory::Reset();
  if ( (v2->m_rootElements.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v2->m_rootElements.m_data);
  UIFramework::~UIFramework((UIFramework *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 801800: using guessed type int (__thiscall *UIMainFramework::vftable)(void *, char);

//----- (006A0D50) --------------------------------------------------------  // acclient.c:697422
UIElement *__thiscall UIMainFramework::CreateAndAddRootElementByDataID(UIMainFramework *this, IDClass<_tagDataID,32,0> _layoutID, const unsigned int _elementID)
{
  UIMainFramework *v3; // edi@1
  UIElement *result; // eax@1
  UIElement *v5; // esi@1

  v3 = this;
  result = (UIElement *)UIElementManager::CreateRootElementByDataID(
                          UIElementManager::s_pInstance,
                          _layoutID,
                          _elementID);
  v5 = result;
  _elementID = (const unsigned int)result;
  if ( result )
  {
    UIElement::RegisterForElementMessages(result, (UIListener *)&v3->vfptr);
    SmartArray<QualityChangeHandler *,1>::add_unique(&v3->m_rootElements, (UIElement *const *)&_elementID);
    result = v5;
  }
  return result;
}

//----- (00721650) --------------------------------------------------------  // acclient.c:819118
void sub_721650()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9C68, PFID_A8R8G8B8);
}

//----- (00721660) --------------------------------------------------------  // acclient.c:819124
int sub_721660()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_85, "None");
  return atexit(_E92_69);
}

//----- (00721680) --------------------------------------------------------  // acclient.c:819131
int _E94_60()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_85, "Speed");
  return atexit(sub_78FFB0);
}

//----- (007216A0) --------------------------------------------------------  // acclient.c:819138
int sub_7216A0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_85, "Noise");
  return atexit(sub_78FFE0);
}

//----- (007216C0) --------------------------------------------------------  // acclient.c:819145
int sub_7216C0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_85, "Sine");
  return atexit(sub_790010);
}

//----- (007216E0) --------------------------------------------------------  // acclient.c:819152
int sub_7216E0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_85, "Square");
  return atexit(sub_790040);
}

//----- (00721700) --------------------------------------------------------  // acclient.c:819159
int sub_721700()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_85, "Bounce");
  return atexit(sub_790070);
}

//----- (00721720) --------------------------------------------------------  // acclient.c:819166
int sub_721720()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_85, "Perlin");
  return atexit(sub_7900A0);
}

//----- (00721740) --------------------------------------------------------  // acclient.c:819173
int sub_721740()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_85, "Fractal");
  return atexit(_E113_93);
}

//----- (00721760) --------------------------------------------------------  // acclient.c:819180
int sub_721760()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_85, "FrameLoop");
  return atexit(_E116_85);
}

//----- (00721780) --------------------------------------------------------  // acclient.c:819187
int sub_721780()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_51, "Misc.TooltipEnable");
  return atexit(sub_790130);
}

//----- (007217A0) --------------------------------------------------------  // acclient.c:819194
int _E121_94()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_51, "Misc.TooltipDelay");
  return atexit(sub_790160);
}

//----- (007217C0) --------------------------------------------------------  // acclient.c:819201
int sub_7217C0()
{
  return atexit(nullsub_364);
}

//----- (0078FF80) --------------------------------------------------------  // acclient.c:936477
void __cdecl _E92_69()
{
  char *v0; // esi@1

  v0 = &waveform_None_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FFB0) --------------------------------------------------------  // acclient.c:936490
void __cdecl sub_78FFB0()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FFE0) --------------------------------------------------------  // acclient.c:936503
void __cdecl sub_78FFE0()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790010) --------------------------------------------------------  // acclient.c:936516
void __cdecl sub_790010()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790040) --------------------------------------------------------  // acclient.c:936529
void __cdecl sub_790040()
{
  char *v0; // esi@1

  v0 = &waveform_Square_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790070) --------------------------------------------------------  // acclient.c:936542
void __cdecl sub_790070()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007900A0) --------------------------------------------------------  // acclient.c:936555
void __cdecl sub_7900A0()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007900D0) --------------------------------------------------------  // acclient.c:936568
void __cdecl _E113_93()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790100) --------------------------------------------------------  // acclient.c:936581
void __cdecl _E116_85()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_85.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_85.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790130) --------------------------------------------------------  // acclient.c:936594
void __cdecl sub_790130()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790160) --------------------------------------------------------  // acclient.c:936607
void __cdecl sub_790160()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

