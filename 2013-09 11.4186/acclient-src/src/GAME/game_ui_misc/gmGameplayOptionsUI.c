/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmGameplayOptionsUI
   Object     : GAME\game_ui_misc\gmGameplayOptionsUI.obj
   Functions  : 31
   Addresses  : 0049E030 - 00760030 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0049E030) --------------------------------------------------------  // acclient.c:215245
gmGameplayOptionsUI *__thiscall gmGameplayOptionsUI::DynamicCast(gmGameplayOptionsUI *this, unsigned int i_eType)
{
  gmGameplayOptionsUI *result; // eax@1

  result = this;
  if ( i_eType != 268435497 )
    result = (gmGameplayOptionsUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (0049E050) --------------------------------------------------------  // acclient.c:215256
signed int gmGameplayOptionsUI::GetUIElementType()
{
  return 268435497;
}

//----- (0049E060) --------------------------------------------------------  // acclient.c:215262
UIElement *__usercall gmGameplayOptionsUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x5FCu);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmGameplayOptionsUI::vftable;
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A7FF0: using guessed type int (__thiscall *gmGameplayOptionsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0049E0B0) --------------------------------------------------------  // acclient.c:215286
UIElement_Field *__thiscall gmGameplayOptionsUI::scalar_deleting_destructor(gmGameplayOptionsUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmGameplayOptionsUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7A7FF0: using guessed type int (__thiscall *gmGameplayOptionsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0049E0F0) --------------------------------------------------------  // acclient.c:215306
void __cdecl gmGameplayOptionsUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000029u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmGameplayOptionsUI::Create);
}

//----- (0049E110) --------------------------------------------------------  // acclient.c:215314
int __thiscall gmGameplayOptionsUI::ListenToElementMessage(gmGameplayOptionsUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIElement *v3; // ebx@1
  unsigned int v4; // eax@2
  int v5; // eax@4
  HINSTANCE v6; // esi@6
  HINSTANCE v8; // esi@10
  char *v9; // esi@12
  int v10; // eax@15
  PStringBase<char> IEDownloadURL; // [sp+0h] [bp-4h]@1

  IEDownloadURL.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v2 = i_rMsg;
  v3 = (UIElement *)this;
  if ( i_rMsg->idMessage != 1 )
    return UIElement::ListenToElementMessage(v3, v2);
  v4 = i_rMsg->idElement;
  if ( i_rMsg->idElement > 0x10000207 )
  {
    v10 = v4 - 268436940;
    if ( v10 )
    {
      if ( v10 == 75 )
        UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 1u, 268435495);
    }
    else
    {
      UIElementManager::BroadcastGlobalMessage(UIElementManager::s_pInstance, 0xCu, 0);
    }
    return UIElement::ListenToElementMessage(v3, v2);
  }
  if ( i_rMsg->idElement == 268435975 )
  {
    PStringBase<char>::PStringBase<char>(
      &IEDownloadURL,
      "http://support.turbine.com/ics/support/ticketnewwizard.asp?style=classic");
    v8 = ShellExecuteA(0, "open", IEDownloadURL.m_charbuffer->m_data, 0, 0, 1);
    if ( (signed int)v8 <= 32 )
    {
      i_rMsg = (UIElementMessageInfo *)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PStringBase<char>::sprintf(
        (PStringBase<char> *)&i_rMsg,
        "An error occurred while trying to launch your web browser. (Error code %d)\nThe web site to submit an abuse report is listed below. Please go there to complete your request.\n%s\n",
        v8,
        IEDownloadURL.m_charbuffer);
      MessageBoxA(0, (LPCSTR)i_rMsg, "Asheron's Call Error", 0);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_rMsg);
    }
    v9 = &IEDownloadURL.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&IEDownloadURL.m_charbuffer[-1]) && v9 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      return UIElement::ListenToElementMessage(v3, v2);
    }
    return UIElement::ListenToElementMessage(v3, v2);
  }
  v5 = v4 - 268435971;
  if ( !v5 )
  {
    CM_UI::SendNotice_EndCharacterSession(1);
    return UIElement::ListenToElementMessage(v3, v2);
  }
  if ( v5 != 3 )
    return UIElement::ListenToElementMessage(v3, v2);
  PStringBase<char>::PStringBase<char>(
    &IEDownloadURL,
    "http://support.turbine.com/ics/support/ticketnewwizard.asp?style=classic");
  v6 = ShellExecuteA(0, "open", IEDownloadURL.m_charbuffer->m_data, 0, 0, 1);
  if ( (signed int)v6 <= 32 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_rMsg);
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&i_rMsg,
      "An error occurred while trying to launch your web browser. (Error code %d)\nThe web site to submit an urgent assistance request is listed below. Please go there to complete your request.\n%s\n",
      v6,
      IEDownloadURL.m_charbuffer);
    MessageBoxA(0, (LPCSTR)i_rMsg, "Asheron's Call Error", 0);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_rMsg);
  }
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&IEDownloadURL);
  return UIElement::ListenToElementMessage(v3, v2);
}

//----- (006EF450) --------------------------------------------------------  // acclient.c:771439
void _E91_63()
{
  outside_val_55 = 1000.0 + 1.0;
}

//----- (006EF470) --------------------------------------------------------  // acclient.c:771445
void _E93_39()
{
  block_length_55 = 24.0 * 8.0;
}

//----- (006EF490) --------------------------------------------------------  // acclient.c:771451
void _E95_39()
{
  half_square_length_55 = 24.0 * 0.5;
}

//----- (006EF4B0) --------------------------------------------------------  // acclient.c:771457
int _E97_64()
{
  return atexit(_E98_76);
}

//----- (006EF4C0) --------------------------------------------------------  // acclient.c:771463
int _E100_57()
{
  return atexit(_E101_94);
}

//----- (006EF4D0) --------------------------------------------------------  // acclient.c:771469
int _E103_49()
{
  return atexit(_E104_64);
}

//----- (006EF4E0) --------------------------------------------------------  // acclient.c:771475
int _E106_39()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_25, "Misc.TooltipEnable");
  return atexit(_E107_72);
}

//----- (006EF500) --------------------------------------------------------  // acclient.c:771482
int _E109_22()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_25, "Misc.TooltipDelay");
  return atexit(sub_75FEE0);
}

//----- (006EF520) --------------------------------------------------------  // acclient.c:771489
int _E112_34()
{
  PStringBase<char>::PStringBase<char>(&Camera_AlignToSlope_1, "Camera.AlignToSlope");
  return atexit(_E113_49);
}

//----- (006EF540) --------------------------------------------------------  // acclient.c:771496
int _E115_25()
{
  PStringBase<char>::PStringBase<char>(&Camera_Stiffness_1, "Camera.Stiffness");
  return atexit(_E116_41);
}

//----- (006EF560) --------------------------------------------------------  // acclient.c:771503
int _E118_31()
{
  PStringBase<char>::PStringBase<char>(&Camera_AdjustmentSpeed_1, "Camera.AdjustmentSpeed");
  return atexit(_E119_73);
}

//----- (006EF580) --------------------------------------------------------  // acclient.c:771510
int _E121_32()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSensitivity_1, "Input.MouseLookSensitivity");
  return atexit(_E122_69);
}

//----- (006EF5A0) --------------------------------------------------------  // acclient.c:771517
int _E124_32()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSmoothingAmount_1, "Input.MouseLookSmoothingAmount");
  return atexit(_E125_40);
}

//----- (006EF5C0) --------------------------------------------------------  // acclient.c:771524
int _E127_26()
{
  PStringBase<char>::PStringBase<char>(&Input_InvertMouseLookYAxis_1, "Input.InvertMouseLookYAxis");
  return atexit(_E128_41);
}

//----- (006EF5E0) --------------------------------------------------------  // acclient.c:771531
int _E130_22()
{
  PStringBase<char>::PStringBase<char>(&Input_UseMouseTurning_1, "Input.UseMouseTurning");
  return atexit(_E131_31);
}

//----- (006EF600) --------------------------------------------------------  // acclient.c:771538
int sub_6EF600()
{
  return atexit(nullsub_938);
}

//----- (0075FEB0) --------------------------------------------------------  // acclient.c:887627
void __cdecl _E107_72()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FEE0) --------------------------------------------------------  // acclient.c:887640
void __cdecl sub_75FEE0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FF10) --------------------------------------------------------  // acclient.c:887653
void __cdecl _E113_49()
{
  char *v0; // esi@1

  v0 = &Camera_AlignToSlope_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AlignToSlope_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FF40) --------------------------------------------------------  // acclient.c:887666
void __cdecl _E116_41()
{
  char *v0; // esi@1

  v0 = &Camera_Stiffness_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_Stiffness_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FF70) --------------------------------------------------------  // acclient.c:887679
void __cdecl _E119_73()
{
  char *v0; // esi@1

  v0 = &Camera_AdjustmentSpeed_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AdjustmentSpeed_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FFA0) --------------------------------------------------------  // acclient.c:887692
void __cdecl _E122_69()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSensitivity_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSensitivity_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FFD0) --------------------------------------------------------  // acclient.c:887705
void __cdecl _E125_40()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSmoothingAmount_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSmoothingAmount_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760000) --------------------------------------------------------  // acclient.c:887718
void __cdecl _E128_41()
{
  char *v0; // esi@1

  v0 = &Input_InvertMouseLookYAxis_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_InvertMouseLookYAxis_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760030) --------------------------------------------------------  // acclient.c:887731
void __cdecl _E131_31()
{
  char *v0; // esi@1

  v0 = &Input_UseMouseTurning_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_UseMouseTurning_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

