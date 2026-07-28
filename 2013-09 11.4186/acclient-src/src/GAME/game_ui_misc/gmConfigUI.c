/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmConfigUI
   Object     : GAME\game_ui_misc\gmConfigUI.obj
   Functions  : 161
   Addresses  : 0049E2C0 - 00760BE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0049E2C0) --------------------------------------------------------  // acclient.c:215400
signed int __thiscall gmConfigUI::DynamicCast(gmConfigUI *this, unsigned int i_eType)
{
  return i_eType != 268435496 ? 0 : (unsigned int)this;
}

//----- (0049E2E0) --------------------------------------------------------  // acclient.c:215406
signed int gmConfigUI::GetUIElementType()
{
  return 268435496;
}

//----- (0049E2F0) --------------------------------------------------------  // acclient.c:215412
void __thiscall gmConfigUI::~gmConfigUI(gmConfigUI *this)
{
  UIListener *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = (UIListener *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmConfigUI::vftable;
  this->vfptr = (IOptionChangeHandlerVtbl *)&gmConfigUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmConfigUI::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  UIListener::UnRegisterForGlobalMessage(v1, 0xCu);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  PlayerOptionPage::~PlayerOptionPage((PlayerOptionPage *)v1);
}
// 7A84E0: using guessed type bool (__thiscall *gmConfigUI::vftable)(DBCache *this);
// 7A8788: using guessed type int (__thiscall *gmConfigUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4344: using guessed type void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *);

//----- (0049E340) --------------------------------------------------------  // acclient.c:215437
UIElement *__usercall gmConfigUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x620u);
  if ( v3 )
  {
    PlayerOptionPage::PlayerOptionPage((PlayerOptionPage *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 385) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmConfigUI::vftable;
    *((_DWORD *)v3 + 380) = &gmConfigUI::vftable;
    *((_DWORD *)v3 + 385) = &gmConfigUI::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7A84E0: using guessed type bool (__thiscall *gmConfigUI::vftable)(DBCache *this);
// 7A8788: using guessed type int (__thiscall *gmConfigUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4344: using guessed type void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *);

//----- (0049E3A0) --------------------------------------------------------  // acclient.c:215464
int __thiscall gmChatOptionsUI::ListenToElementMessage(gmConfigUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // esi@1

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 268435964 )
    {
      ((void (*)(void))this->vfptr[26].__vecDelDtor)();
    }
    else
    {
      if ( i_rMsg->idElement == 268435965 )
      {
        ((void (*)(void))this->vfptr[26].OnLoseFocus)();
        return UIElement::ListenToElementMessage(v2, i_rMsg);
      }
      if ( i_rMsg->idElement == 268435966 )
      {
        ((void (*)(void))this->vfptr[26].OnAction)();
        return UIElement::ListenToElementMessage(v2, i_rMsg);
      }
    }
  }
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (0049E400) --------------------------------------------------------  // acclient.c:215493
void __thiscall gmConfigUI::InitOptions(gmConfigUI *this)
{
  gmConfigUI *v1; // esi@1
  UIOption_Menu *v2; // eax@1
  UIOption_CheckboxSlider *v3; // eax@1
  UIOption_CheckboxSlider *v4; // eax@1
  UIOption_CheckboxSlider *v5; // eax@1
  UIOption_Checkbox *v6; // eax@1
  UIOption_Slider *v7; // eax@1
  unsigned int v8; // ST08_4@1
  unsigned int v9; // ST04_4@1
  UIOption_Slider *v10; // eax@1
  unsigned int v11; // ST08_4@1
  unsigned int v12; // ST04_4@1
  UIOption_Slider *v13; // edi@1
  UIOption_Checkbox *v14; // eax@1
  UIOption *v15; // edi@1
  UIOption_Checkbox *v16; // eax@1
  UIOption_Checkbox *v17; // eax@1
  UIOption_Slider *v18; // edi@1
  UIOption_Checkbox *v19; // eax@1
  UIOption_Slider *v20; // edi@1
  UIOption_Slider *v21; // edi@1
  UIOption_Menu *v22; // eax@1
  UIOption_Menu *v23; // eax@1
  UIOption_Menu *v24; // eax@1
  UIOption_Menu *v25; // eax@1
  UIOption_Checkbox *v26; // eax@1
  UIOption_Checkbox *v27; // eax@1
  UIOption_Slider *v28; // eax@1
  UIOption_Checkbox *v29; // eax@1
  UIOption_Checkbox *v30; // eax@1
  UIOption_Menu *v31; // eax@1
  UIOption_Menu *v32; // eax@1

  v1 = this;
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&this->vfptr, ID_Sound_SoundSection);
  v2 = PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &Sound_SoundFeatures_4, 1);
  ((void (__thiscall *)(UIOption_Menu *, _DWORD))v2->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v2, 0);
  v3 = PlayerOptionPage::AddToggleWithSliderOption(
         (PlayerOptionPage *)&v1->vfptr,
         &Sound_SoundDisabled_4,
         &Sound_SoundVolume_4);
  ((void (__thiscall *)(UIOption_CheckboxSlider *, signed int, signed int))v3->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
    v3,
    1,
    1065353216);
  v4 = PlayerOptionPage::AddToggleWithSliderOption(
         (PlayerOptionPage *)&v1->vfptr,
         &Sound_AmbientSoundDisabled_4,
         &Sound_AmbientSoundVolume_4);
  ((void (__thiscall *)(UIOption_CheckboxSlider *, signed int, signed int))v4->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
    v4,
    1,
    1065353216);
  v5 = PlayerOptionPage::AddToggleWithSliderOption(
         (PlayerOptionPage *)&v1->vfptr,
         &Sound_InterfaceSoundDisabled_4,
         &Sound_InterfaceSoundVolume_4);
  ((void (__thiscall *)(UIOption_CheckboxSlider *, signed int, signed int))v5->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
    v5,
    1,
    1065353216);
  v6 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Sound_PlaySoundOnlyWhenActive_4);
  ((void (__thiscall *)(UIOption_Checkbox *, signed int))v6->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v6, 1);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_Camera_CameraSection);
  v7 = PlayerOptionPage::AddSliderOption((PlayerOptionPage *)&v1->vfptr, &Camera_Stiffness_2, 1);
  v8 = ID_Graphics_Value_Hard;
  v9 = ID_Graphics_Value_Soft;
  v1->m_pStiffness = v7;
  PlayerOptionPage::SetSliderLabel(v7, v9, v8);
  ((void (__stdcall *)(signed int))v1->m_pStiffness->vfptr[7].RecvNotice_DisplayFinalStringInfo)(1055286886);
  v10 = PlayerOptionPage::AddSliderOption((PlayerOptionPage *)&v1->vfptr, &Camera_AdjustmentSpeed_2, 1);
  v11 = ID_Graphics_Value_Fast;
  v12 = ID_Graphics_Value_Slow;
  v1->m_pAdjustmentSpeed = v10;
  PlayerOptionPage::SetSliderLabel(v10, v12, v11);
  ((void (__stdcall *)(signed int))v1->m_pAdjustmentSpeed->vfptr[7].RecvNotice_DisplayFinalStringInfo)(1109393408);
  v13 = PlayerOptionPage::AddSliderOption((PlayerOptionPage *)&v1->vfptr, &Render_FieldOfView_17, 1);
  PlayerOptionPage::SetSliderLabel(v13, ID_Graphics_Value_Narrow, ID_Graphics_Value_Wide);
  ((void (__thiscall *)(UIOption_Slider *, signed int))v13->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v13, 1119092736);
  v14 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Camera_AlignToSlope_2);
  v1->m_pSlope = v14;
  ((void (__thiscall *)(UIOption_Checkbox *, signed int))v14->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v14, 1);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_Graphics_GraphicsSection);
  v15 = (UIOption *)PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &Display_Resolution_13, 0);
  ((void (__thiscall *)(UIOption *, signed int))v15->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v15, 52429400);
  UIOption::SetConfirmChange(v15, 1);
  v16 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Display_FullScreen_13);
  ((void (__thiscall *)(UIOption_Checkbox *, signed int))v16->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v16, 1);
  v17 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Display_SyncToRefresh_13);
  ((void (__thiscall *)(UIOption_Checkbox *, _DWORD))v17->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v17, 0);
  v18 = PlayerOptionPage::AddSliderOption((PlayerOptionPage *)&v1->vfptr, &Render_ScreenBrightness_17, 1);
  PlayerOptionPage::SetSliderLabel(v18, ID_Graphics_Value_Dark, ID_Graphics_Value_Bright);
  ((void (__thiscall *)(UIOption_Slider *, _DWORD))v18->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v18, 0);
  v19 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Render_AutomaticDegrades_17);
  ((void (__thiscall *)(UIOption_Checkbox *, _DWORD))v19->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v19, 0);
  v20 = PlayerOptionPage::AddSliderOption((PlayerOptionPage *)&v1->vfptr, &Render_GraphicsPerformance_17, 1);
  PlayerOptionPage::SetSliderLabel(v20, ID_Graphics_Value_Speed, ID_Graphics_Value_Detail);
  ((void (__thiscall *)(UIOption_Slider *, _DWORD))v20->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v20, 0);
  v21 = PlayerOptionPage::AddSliderOption((PlayerOptionPage *)&v1->vfptr, &Render_DegradeDistance_17, 1);
  PlayerOptionPage::SetSliderLabel(v21, ID_Graphics_Value_Close, ID_Graphics_Value_Far);
  ((void (__thiscall *)(UIOption_Slider *, signed int))v21->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v21, 1112014848);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_Graphics_TextureSection);
  v22 = PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &Render_LandscapeTextureDetail_17, 1);
  ((void (__thiscall *)(UIOption_Menu *, signed int))v22->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v22, 2);
  v23 = PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &Render_EnvironmentTextureDetail_17, 1);
  ((void (__thiscall *)(UIOption_Menu *, signed int))v23->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v23, 1);
  v24 = PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &Render_TextureFiltering_17, 1);
  ((void (__thiscall *)(UIOption_Menu *, signed int))v24->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v24, 1);
  v25 = PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &Render_LandscapeDrawDistance_17, 1);
  ((void (__thiscall *)(UIOption_Menu *, signed int))v25->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v25, 8);
  v26 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Render_BuildingDetailTextures_17);
  ((void (__thiscall *)(UIOption_Checkbox *, signed int))v26->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v26, 1);
  v27 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Render_MultiPassAlpha_17);
  ((void (__thiscall *)(UIOption_Checkbox *, _DWORD))v27->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v27, 0);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_Input_InputSection);
  v28 = PlayerOptionPage::AddSliderOption((PlayerOptionPage *)&v1->vfptr, &Input_MouseLookSensitivity_2, 0);
  v1->m_pSensitivity = v28;
  ((void (__thiscall *)(UIOption_Slider *, signed int))v28->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v28, 1057803469);
  v29 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Input_InvertMouseLookYAxis_2);
  v1->m_pInvert = v29;
  ((void (__thiscall *)(UIOption_Checkbox *, _DWORD))v29->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v29, 0);
  v30 = PlayerOptionPage::AddToggleOption((PlayerOptionPage *)&v1->vfptr, &Input_UseMouseTurning_2);
  v1->m_pMouseTurn = v30;
  ((void (__thiscall *)(UIOption_Checkbox *, _DWORD))v30->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v30, 0);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_UI_UISection);
  v31 = PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &UI_ChatFontFace_0, 1);
  ((void (__thiscall *)(UIOption_Menu *, signed int))v31->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v31, 2);
  v32 = PlayerOptionPage::AddMenuOption((PlayerOptionPage *)&v1->vfptr, &UI_ChatFontSize_0, 1);
  ((void (__thiscall *)(UIOption_Menu *, signed int))v32->vfptr[7].RecvNotice_DisplayFinalStringInfo)(v32, 1);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
}

//----- (0049E820) --------------------------------------------------------  // acclient.c:215633
gmConfigUI *__thiscall gmConfigUI::vector_deleting_destructor(gmConfigUI *this, unsigned int a2)
{
  gmConfigUI *v2; // esi@1

  v2 = this;
  gmConfigUI::~gmConfigUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0049E840) --------------------------------------------------------  // acclient.c:215645
void __thiscall gmConfigUI::PostInit(gmConfigUI *this)
{
  gmConfigUI *v1; // esi@1
  UIElement *v2; // eax@1
  GlobalEventHandler *v3; // eax@3

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v1->m_pStiffness = 0;
  v1->m_pAdjustmentSpeed = 0;
  v1->m_pSensitivity = 0;
  v1->m_pSlope = 0;
  v1->m_pInvert = 0;
  v1->m_pMouseTurn = 0;
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000200u);
  if ( v2 )
    v1->m_pOptionBox = (UIElement_ListBox *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
  ((void (__thiscall *)(gmConfigUI *))v1->vfptr[27].__vecDelDtor)(v1);
  v1->vfptr->OnOptionChanged(&v1->vfptr, 0);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, 5100150u, (NoticeHandler *)&v1->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xCu);
}

//----- (0049E8D0) --------------------------------------------------------  // acclient.c:215670
void __cdecl gmConfigUI::Register()
{
  UIElement::RegisterElementClass(0x10000028u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmConfigUI::Create);
}

//----- (0049E8F0) --------------------------------------------------------  // acclient.c:215676
void __thiscall gmConfigUI::SetMouseTurningDefaults(gmConfigUI *this)
{
  AC1Legacy::PSRefBuffer<char> *v1; // edi@1
  gmConfigUI *v2; // esi@1
  UIOption_Slider *v3; // ecx@1
  double v4; // st7@2
  const char *v5; // ST08_4@3
  ClientSystem *v6; // eax@3
  UIOption_Slider *v7; // ecx@4
  double v8; // st7@5
  const char *v9; // ST08_4@6
  ClientSystem *v10; // eax@6
  UIOption_Slider *v11; // ecx@7
  double v12; // st7@8
  const char *v13; // ST08_4@9
  ClientSystem *v14; // eax@9
  UIOption_Checkbox *v15; // ecx@10
  const char *v16; // ST08_4@12
  ClientSystem *v17; // eax@12
  UIOption_Checkbox *v18; // ecx@13
  const char *v19; // ST08_4@15
  ClientSystem *v20; // eax@15
  UIOption_Checkbox *v21; // ecx@16
  const char *v22; // ST08_4@18
  ClientSystem *v23; // eax@18
  AC1Legacy::PStringBase<char> txtmsg; // [sp+18h] [bp-8h]@1
  float old_sensitivity; // [sp+1Ch] [bp-4h]@2

  v1 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v2 = this;
  txtmsg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v3 = v2->m_pStiffness;
  if ( v3 )
  {
    v4 = UIOption_Slider::GetCurrentValue(v3);
    old_sensitivity = v4;
    if ( v4 != 0.94999999 )
    {
      UIOption_Slider::SetCurrentValue(v2->m_pStiffness, 0.94999999);
      AC1Legacy::PStringBase<char>::sprintf(
        &txtmsg,
        "Camera Stiffness was changed from %f to the mouse turning default of %f.",
        old_sensitivity,
        1610612736,
        1072588390);
      v1 = txtmsg.m_buffer;
      v5 = txtmsg.m_buffer->m_data;
      v6 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v6, v5, 7u, 1, 0);
    }
  }
  v7 = v2->m_pAdjustmentSpeed;
  if ( v7 )
  {
    v8 = UIOption_Slider::GetCurrentValue(v7);
    old_sensitivity = v8;
    if ( v8 != 50.0 )
    {
      UIOption_Slider::SetCurrentValue(v2->m_pAdjustmentSpeed, 50.0);
      AC1Legacy::PStringBase<char>::sprintf(
        &txtmsg,
        "Camera Adjustment was changed from %f to the mouse turning default of %f.",
        old_sensitivity,
        1610612736,
        1072588390);
      v1 = txtmsg.m_buffer;
      v9 = txtmsg.m_buffer->m_data;
      v10 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v10, v9, 7u, 1, 0);
    }
  }
  v11 = v2->m_pSensitivity;
  if ( v11 )
  {
    v12 = UIOption_Slider::GetCurrentValue(v11);
    old_sensitivity = v12;
    if ( v12 != 0.69999999 )
    {
      UIOption_Slider::SetCurrentValue(v2->m_pSensitivity, 0.69999999);
      AC1Legacy::PStringBase<char>::sprintf(
        &txtmsg,
        "Mouse Sensitivity was changed from %f to the mouse turning default of %f.",
        old_sensitivity,
        1610612736,
        1072588390);
      v1 = txtmsg.m_buffer;
      v13 = txtmsg.m_buffer->m_data;
      v14 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v14, v13, 7u, 1, 0);
    }
  }
  v15 = v2->m_pSlope;
  if ( v15 && (unsigned __int8)((int (*)(void))v15->vfptr[7].RecvNotice_DisplayWeenieError)() == 1 )
  {
    ((void (__stdcall *)(_DWORD))v2->m_pSlope->vfptr[7].RecvNotice_DisplayStringInfo)(0);
    AC1Legacy::PStringBase<char>::sprintf(
      &txtmsg,
      "Align To Slope was changed from TRUE to the mouse turning default of FALSE.");
    v1 = txtmsg.m_buffer;
    v16 = txtmsg.m_buffer->m_data;
    v17 = (ClientSystem *)ClientUISystem::GetUISystem();
    ClientSystem::AddTextToScroll(v17, v16, 7u, 1, 0);
  }
  v18 = v2->m_pInvert;
  if ( v18 && !(unsigned __int8)((int (*)(void))v18->vfptr[7].RecvNotice_DisplayWeenieError)() )
  {
    ((void (__stdcall *)(signed int))v2->m_pInvert->vfptr[7].RecvNotice_DisplayStringInfo)(1);
    AC1Legacy::PStringBase<char>::sprintf(
      &txtmsg,
      "Invert Mouselook Axes was changed from FALSE to the mouse turning default of TRUE.");
    v1 = txtmsg.m_buffer;
    v19 = txtmsg.m_buffer->m_data;
    v20 = (ClientSystem *)ClientUISystem::GetUISystem();
    ClientSystem::AddTextToScroll(v20, v19, 7u, 1, 0);
  }
  v21 = v2->m_pMouseTurn;
  if ( v21 && !(unsigned __int8)((int (*)(void))v21->vfptr[7].RecvNotice_DisplayWeenieError)() )
  {
    ((void (__stdcall *)(signed int))v2->m_pMouseTurn->vfptr[7].RecvNotice_DisplayStringInfo)(1);
    AC1Legacy::PStringBase<char>::sprintf(
      &txtmsg,
      "Turn to Face Camera was changed from FALSE to the mouse turning default of TRUE.");
    v1 = txtmsg.m_buffer;
    v22 = txtmsg.m_buffer->m_data;
    v23 = (ClientSystem *)ClientUISystem::GetUISystem();
    ClientSystem::AddTextToScroll(v23, v22, 7u, 1, 0);
  }
  ((void (__thiscall *)(gmConfigUI *))v2->vfptr[26].__vecDelDtor)(v2);
  if ( !InterlockedDecrement((volatile LONG *)&v1->m_cRef) )
  {
    if ( v1 )
      v1->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v1, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0049EB90) --------------------------------------------------------  // acclient.c:215814
void __thiscall gmConfigUI::ListenToGlobalMessage(gmConfigUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 12 )
    gmConfigUI::SetMouseTurningDefaults(this);
}

//----- (0049EBA0) --------------------------------------------------------  // acclient.c:215821
void __stdcall gmConfigUI::RecvNotice_UserPreferenceChanged_Menu(PStringBase<char> *i_strPref, unsigned int i_oldValue, unsigned int i_newValue)
{
  unsigned int v4; // eax@9
  BasePropertyDesc *v5; // ecx@12
  unsigned int v6; // edx@12
  BasePropertyValue *v7; // ecx@16
  unsigned int v8; // edx@16
  BaseProperty p; // [sp+10h] [bp-114h]@5
  unsigned int _key; // [sp+18h] [bp-10Ch]@7
  PropertyCollection pc; // [sp+1Ch] [bp-108h]@5
  StringInfo info; // [sp+94h] [bp-90h]@9

  if ( (!PStringBase<char>::operator!=(i_strPref, &Render_LandscapeTextureDetail_17)
     || !PStringBase<char>::operator!=(i_strPref, &Render_EnvironmentTextureDetail_17))
    && (!i_oldValue || !i_newValue) )
  {
    PropertyCollection::PropertyCollection(&pc);
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x8Eu);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(3);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    BaseProperty::SetPropertyName(&p, 0xC3u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    StringInfo::StringInfo(&info);
    v4 = compute_str_hash("ID_Option_HighResChange");
    StringInfo::SetStringIDandTableEnum(&info, v4, 268435460);
    BaseProperty::SetPropertyName(&p, 0xC5u);
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
    }
    _key = (unsigned int)BaseProperty::GetPropertyName(&p);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
      &_key,
      &p);
    DialogFactory::MakeDialogInCurrentUI(&pc);
    StringInfo::~StringInfo(&info);
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v5 = p.m_pcPropertyDesc;
      v6 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v7 = p.m_pcPropertyValue;
      v8 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyValue = 0;
    }
    PropertyCollection::~PropertyCollection(&pc);
  }
}

//----- (006EF610) --------------------------------------------------------  // acclient.c:771544
void _E91_64()
{
  outside_val_56 = 1000.0 + 1.0;
}

//----- (006EF630) --------------------------------------------------------  // acclient.c:771550
void _E93_40()
{
  block_length_56 = 24.0 * 8.0;
}

//----- (006EF650) --------------------------------------------------------  // acclient.c:771556
void _E95_40()
{
  half_square_length_56 = 24.0 * 0.5;
}

//----- (006EF670) --------------------------------------------------------  // acclient.c:771562
int _E97_65()
{
  return atexit(_E98_77);
}

//----- (006EF680) --------------------------------------------------------  // acclient.c:771568
int _E100_58()
{
  return atexit(_E101_95);
}

//----- (006EF690) --------------------------------------------------------  // acclient.c:771574
int _E103_50()
{
  return atexit(_E104_65);
}

//----- (006EF6A0) --------------------------------------------------------  // acclient.c:771580
int _E106_40()
{
  PStringBase<char>::PStringBase<char>(&Camera_AlignToSlope_2, "Camera.AlignToSlope");
  return atexit(_E107_73);
}

//----- (006EF6C0) --------------------------------------------------------  // acclient.c:771587
int _E109_23()
{
  PStringBase<char>::PStringBase<char>(&Camera_Stiffness_2, "Camera.Stiffness");
  return atexit(sub_7600E0);
}

//----- (006EF6E0) --------------------------------------------------------  // acclient.c:771594
int _E112_35()
{
  PStringBase<char>::PStringBase<char>(&Camera_AdjustmentSpeed_2, "Camera.AdjustmentSpeed");
  return atexit(_E113_50);
}

//----- (006EF700) --------------------------------------------------------  // acclient.c:771601
int _E115_26()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_4, "Sound.SoundDisabled");
  return atexit(_E116_42);
}

//----- (006EF720) --------------------------------------------------------  // acclient.c:771608
int _E118_32()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_4, "Sound.SoundVolume");
  return atexit(_E119_74);
}

//----- (006EF740) --------------------------------------------------------  // acclient.c:771615
int _E121_33()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_4, "Sound.AmbientSoundDisabled");
  return atexit(_E122_70);
}

//----- (006EF760) --------------------------------------------------------  // acclient.c:771622
int _E124_33()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_4, "Sound.AmbientSoundVolume");
  return atexit(_E125_41);
}

//----- (006EF780) --------------------------------------------------------  // acclient.c:771629
int _E127_27()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_4, "Sound.InterfaceSoundDisabled");
  return atexit(_E128_42);
}

//----- (006EF7A0) --------------------------------------------------------  // acclient.c:771636
int _E130_23()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_4, "Sound.InterfaceSoundVolume");
  return atexit(_E131_32);
}

//----- (006EF7C0) --------------------------------------------------------  // acclient.c:771643
int _E133_20()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_4, "Sound.SoundFeatures");
  return atexit(_E134_28);
}

//----- (006EF7E0) --------------------------------------------------------  // acclient.c:771650
int _E136_16()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_4, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E137_27);
}

//----- (006EF800) --------------------------------------------------------  // acclient.c:771657
int _E139_17()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_4, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_83E5CC, "Mono");
  return atexit(_E140_22);
}

//----- (006EF830) --------------------------------------------------------  // acclient.c:771665
int _E142_15()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_26, "Misc.TooltipEnable");
  return atexit(_E143_23);
}

//----- (006EF850) --------------------------------------------------------  // acclient.c:771672
int _E145_16()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_26, "Misc.TooltipDelay");
  return atexit(_E146_23);
}

//----- (006EF870) --------------------------------------------------------  // acclient.c:771679
int _E148_16()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_13, "Display.Resolution");
  return atexit(_E149_23);
}

//----- (006EF890) --------------------------------------------------------  // acclient.c:771686
int _E151_16()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_13, "Display.FullScreen");
  return atexit(_E152_22);
}

//----- (006EF8B0) --------------------------------------------------------  // acclient.c:771693
int _E154_16()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_13, "Display.RefreshRate");
  return atexit(_E155_19);
}

//----- (006EF8D0) --------------------------------------------------------  // acclient.c:771700
int _E157_14()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_13, "Display.SyncToRefresh");
  return atexit(_E158_21);
}

//----- (006EF8F0) --------------------------------------------------------  // acclient.c:771707
int _E160_16()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_17, "Render.TextureFiltering");
  return atexit(_E161_19);
}

//----- (006EF910) --------------------------------------------------------  // acclient.c:771714
int _E163_13()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_17, "Render.LandscapeDetailTextures");
  return atexit(_E164_21);
}

//----- (006EF930) --------------------------------------------------------  // acclient.c:771721
int _E166_13()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_17, "Render.BuildingDetailTextures");
  return atexit(_E167_17);
}

//----- (006EF950) --------------------------------------------------------  // acclient.c:771728
int _E169_11()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_17, "Render.FieldOfView");
  return atexit(_E170_16);
}

//----- (006EF970) --------------------------------------------------------  // acclient.c:771735
int _E172_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_17, "Render.LandscapeTextureDetail");
  return atexit(_E173_15);
}

//----- (006EF990) --------------------------------------------------------  // acclient.c:771742
int _E175_10()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_17, "Render.EnvironmentTextureDetail");
  return atexit(_E176_16);
}

//----- (006EF9B0) --------------------------------------------------------  // acclient.c:771749
int _E178_10()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_17, "Render.SceneryDrawDistance");
  return atexit(_E179_15);
}

//----- (006EF9D0) --------------------------------------------------------  // acclient.c:771756
int _E181_10()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_17, "Render.LandscapeDrawDistance");
  return atexit(_E182_15);
}

//----- (006EF9F0) --------------------------------------------------------  // acclient.c:771763
int _E184_8()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_17, "Render.ScreenBrightness");
  return atexit(_E185_12);
}

//----- (006EFA10) --------------------------------------------------------  // acclient.c:771770
int _E187_8()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_17, "Render.AspectRatio");
  return atexit(_E188_13);
}

//----- (006EFA30) --------------------------------------------------------  // acclient.c:771777
int _E190_8()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_17, "Render.DisplayAdapter");
  return atexit(_E191_12);
}

//----- (006EFA50) --------------------------------------------------------  // acclient.c:771784
int _E193_8()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_17, "Render.MaxHardwareClass");
  return atexit(_E194_19);
}

//----- (006EFA70) --------------------------------------------------------  // acclient.c:771791
int _E196_10()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_17, "Render.AutomaticDegrades");
  return atexit(_E197_10);
}

//----- (006EFA90) --------------------------------------------------------  // acclient.c:771798
int _E199_8()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_17, "Render.GraphicsPerformance");
  return atexit(_E200_15);
}

//----- (006EFAB0) --------------------------------------------------------  // acclient.c:771805
int _E202_8()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_17, "Render.DegradeDistance");
  return atexit(_E203_14);
}

//----- (006EFAD0) --------------------------------------------------------  // acclient.c:771812
int _E205_9()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_17, "Render.MultiPassAlpha");
  return atexit(_E206_17);
}

//----- (006EFAF0) --------------------------------------------------------  // acclient.c:771819
int _E208_11()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_17, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83E62C, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83E630, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83E634, "Anisotropic");
  return atexit(_E209_12);
}

//----- (006EFB40) --------------------------------------------------------  // acclient.c:771829
int _E211_9()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_17, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83E63C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83E640, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83E644, "High");
  PStringBase<char>::PStringBase<char>(&stru_83E648, "VeryHigh");
  return atexit(_E212_15);
}

//----- (006EFBA0) --------------------------------------------------------  // acclient.c:771840
int _E214_11()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_17, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83E650, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83E654, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83E658, "High");
  PStringBase<char>::PStringBase<char>(&stru_83E65C, "VeryHigh");
  return atexit(_E215_11);
}

//----- (006EFC00) --------------------------------------------------------  // acclient.c:771851
int _E217_9()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_17, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83E664, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83E668, "High");
  return atexit(_E218_12);
}

//----- (006EFC40) --------------------------------------------------------  // acclient.c:771860
int _E220_9()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_17, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83E670, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83E674, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83E678, "High");
  PStringBase<char>::PStringBase<char>(&stru_83E67C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83E680, "Extreme");
  return atexit(_E221_12);
}

//----- (006EFCB0) --------------------------------------------------------  // acclient.c:771872
int _E223_9()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_17, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83E688, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83E68C, "Wide");
  return atexit(_E224_12);
}

//----- (006EFCF0) --------------------------------------------------------  // acclient.c:771881
int _E226_9()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSensitivity_2, "Input.MouseLookSensitivity");
  return atexit(_E227_12);
}

//----- (006EFD10) --------------------------------------------------------  // acclient.c:771888
int _E229_9()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSmoothingAmount_2, "Input.MouseLookSmoothingAmount");
  return atexit(_E230_12);
}

//----- (006EFD30) --------------------------------------------------------  // acclient.c:771895
int _E232_9()
{
  PStringBase<char>::PStringBase<char>(&Input_InvertMouseLookYAxis_2, "Input.InvertMouseLookYAxis");
  return atexit(_E233_11);
}

//----- (006EFD50) --------------------------------------------------------  // acclient.c:771902
int _E235_9()
{
  PStringBase<char>::PStringBase<char>(&Input_UseMouseTurning_2, "Input.UseMouseTurning");
  return atexit(_E236_11);
}

//----- (006EFD70) --------------------------------------------------------  // acclient.c:771909
int _E238_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_36, "None");
  return atexit(_E239_11);
}

//----- (006EFD90) --------------------------------------------------------  // acclient.c:771916
int _E241_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_36, "Speed");
  return atexit(_E242_11);
}

//----- (006EFDB0) --------------------------------------------------------  // acclient.c:771923
int _E244_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_36, "Noise");
  return atexit(_E245_10);
}

//----- (006EFDD0) --------------------------------------------------------  // acclient.c:771930
int _E247_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_36, "Sine");
  return atexit(_E248_10);
}

//----- (006EFDF0) --------------------------------------------------------  // acclient.c:771937
int _E250_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_36, "Square");
  return atexit(_E251_10);
}

//----- (006EFE10) --------------------------------------------------------  // acclient.c:771944
int _E253_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_36, "Bounce");
  return atexit(_E254_11);
}

//----- (006EFE30) --------------------------------------------------------  // acclient.c:771951
int _E256_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_36, "Perlin");
  return atexit(_E257_9);
}

//----- (006EFE50) --------------------------------------------------------  // acclient.c:771958
int _E259_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_36, "Fractal");
  return atexit(_E260_10);
}

//----- (006EFE70) --------------------------------------------------------  // acclient.c:771965
int _E262_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_36, "FrameLoop");
  return atexit(_E263_9);
}

//----- (006EFE90) --------------------------------------------------------  // acclient.c:771972
int _E265_9()
{
  PStringBase<char>::PStringBase<char>(&Input_KeymapFile_0, "Input.KeymapFile");
  return atexit(_E266_9);
}

//----- (006EFEB0) --------------------------------------------------------  // acclient.c:771979
int _E268_8()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontFace_0, "UI.ChatFontFace");
  return atexit(_E269_8);
}

//----- (006EFED0) --------------------------------------------------------  // acclient.c:771986
int _E271_7()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontSize_0, "UI.ChatFontSize");
  return atexit(_E272_7);
}

//----- (006EFEF0) --------------------------------------------------------  // acclient.c:771993
int _E274_7()
{
  PStringBase<char>::PStringBase<char>(UI_ChatFontFace_Choices_0, "Arial");
  PStringBase<char>::PStringBase<char>(&stru_83E6D4, "CourierNew");
  PStringBase<char>::PStringBase<char>(&stru_83E6D8, "PalatinoLinotype");
  PStringBase<char>::PStringBase<char>(&stru_83E6DC, "Tahoma");
  PStringBase<char>::PStringBase<char>(&stru_83E6E0, "TimesNewRoman");
  return atexit(_E275_7);
}

//----- (006EFF50) --------------------------------------------------------  // acclient.c:772004
int _E277_7()
{
  PStringBase<char>::PStringBase<char>(UI_ChatFontSize_Choices_0, "Tiny");
  PStringBase<char>::PStringBase<char>(&stru_83E6E8, "Small");
  PStringBase<char>::PStringBase<char>(&stru_83E6EC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83E6F0, "Large");
  PStringBase<char>::PStringBase<char>(&stru_83E6F4, "XL");
  return atexit(_E278_7);
}

//----- (006EFFB0) --------------------------------------------------------  // acclient.c:772015
void _E281()
{
  LOWEST_DATA_RATE_73 = 1024;
}

//----- (006EFFC0) --------------------------------------------------------  // acclient.c:772021
void _E283_7()
{
  HIGHEST_DATA_RATE_73 = 0x7FFF;
}

//----- (006EFFD0) --------------------------------------------------------  // acclient.c:772027
int _E285_3()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_73;
  INITIAL_MAX_DATA_RATE_21 = LOWEST_DATA_RATE_73;
  return result;
}

//----- (006EFFE0) --------------------------------------------------------  // acclient.c:772037
int _E287()
{
  return atexit(_E288_4);
}

//----- (006EFFF0) --------------------------------------------------------  // acclient.c:772043
void _E290()
{
  DEFAULT_VIEW_RADIUS_30 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F0010) --------------------------------------------------------  // acclient.c:772049
void _E292_7()
{
  MIN_QUANTUM_30 = 1.0 / 30.0;
}

//----- (006F0030) --------------------------------------------------------  // acclient.c:772055
void _E294_3()
{
  MAX_QUANTUM_30 = 1.0 / 5.0;
}

//----- (006F0050) --------------------------------------------------------  // acclient.c:772061
void _E296()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_65, PFID_A8R8G8B8);
}

//----- (006F0060) --------------------------------------------------------  // acclient.c:772067
unsigned int _E298_7()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Sound_SoundSection");
  ID_Sound_SoundSection = result;
  return result;
}

//----- (006F0080) --------------------------------------------------------  // acclient.c:772077
unsigned int _E300_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Camera_CameraSection");
  ID_Camera_CameraSection = result;
  return result;
}

//----- (006F00A0) --------------------------------------------------------  // acclient.c:772087
unsigned int _E302()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_GraphicsSection");
  ID_Graphics_GraphicsSection = result;
  return result;
}

//----- (006F00C0) --------------------------------------------------------  // acclient.c:772097
unsigned int _E304_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_TextureSection");
  ID_Graphics_TextureSection = result;
  return result;
}

//----- (006F00E0) --------------------------------------------------------  // acclient.c:772107
unsigned int _E306_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Input_InputSection");
  ID_Input_InputSection = result;
  return result;
}

//----- (006F0100) --------------------------------------------------------  // acclient.c:772117
unsigned int _E308()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_UI_UISection");
  ID_UI_UISection = result;
  return result;
}

//----- (006F0120) --------------------------------------------------------  // acclient.c:772127
unsigned int _E310_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Dark");
  ID_Graphics_Value_Dark = result;
  return result;
}

//----- (006F0140) --------------------------------------------------------  // acclient.c:772137
unsigned int _E312_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Bright");
  ID_Graphics_Value_Bright = result;
  return result;
}

//----- (006F0160) --------------------------------------------------------  // acclient.c:772147
unsigned int _E314()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Speed");
  ID_Graphics_Value_Speed = result;
  return result;
}

//----- (006F0180) --------------------------------------------------------  // acclient.c:772157
unsigned int _E316_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Detail");
  ID_Graphics_Value_Detail = result;
  return result;
}

//----- (006F01A0) --------------------------------------------------------  // acclient.c:772167
unsigned int _E318_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Close");
  ID_Graphics_Value_Close = result;
  return result;
}

//----- (006F01C0) --------------------------------------------------------  // acclient.c:772177
unsigned int _E320()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Far");
  ID_Graphics_Value_Far = result;
  return result;
}

//----- (006F01E0) --------------------------------------------------------  // acclient.c:772187
unsigned int _E322_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Narrow");
  ID_Graphics_Value_Narrow = result;
  return result;
}

//----- (006F0200) --------------------------------------------------------  // acclient.c:772197
unsigned int _E324_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Wide");
  ID_Graphics_Value_Wide = result;
  return result;
}

//----- (006F0220) --------------------------------------------------------  // acclient.c:772207
unsigned int _E326()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Slow");
  ID_Graphics_Value_Slow = result;
  return result;
}

//----- (006F0240) --------------------------------------------------------  // acclient.c:772217
unsigned int _E328_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Fast");
  ID_Graphics_Value_Fast = result;
  return result;
}

//----- (006F0260) --------------------------------------------------------  // acclient.c:772227
unsigned int _E330_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Soft");
  ID_Graphics_Value_Soft = result;
  return result;
}

//----- (006F0280) --------------------------------------------------------  // acclient.c:772237
unsigned int _E332()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Graphics_Value_Hard");
  ID_Graphics_Value_Hard = result;
  return result;
}

//----- (006F02A0) --------------------------------------------------------  // acclient.c:772247
int sub_6F02A0()
{
  return atexit(nullsub_934);
}

//----- (007600B0) --------------------------------------------------------  // acclient.c:887744
void __cdecl _E107_73()
{
  char *v0; // esi@1

  v0 = &Camera_AlignToSlope_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AlignToSlope_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007600E0) --------------------------------------------------------  // acclient.c:887757
void __cdecl sub_7600E0()
{
  char *v0; // esi@1

  v0 = &Camera_Stiffness_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_Stiffness_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760110) --------------------------------------------------------  // acclient.c:887770
void __cdecl _E113_50()
{
  char *v0; // esi@1

  v0 = &Camera_AdjustmentSpeed_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AdjustmentSpeed_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760140) --------------------------------------------------------  // acclient.c:887783
void __cdecl _E116_42()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760170) --------------------------------------------------------  // acclient.c:887796
void __cdecl _E119_74()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007601A0) --------------------------------------------------------  // acclient.c:887809
void __cdecl _E122_70()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007601D0) --------------------------------------------------------  // acclient.c:887822
void __cdecl _E125_41()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760200) --------------------------------------------------------  // acclient.c:887835
void __cdecl _E128_42()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760230) --------------------------------------------------------  // acclient.c:887848
void __cdecl _E131_32()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760260) --------------------------------------------------------  // acclient.c:887861
void __cdecl _E134_28()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760290) --------------------------------------------------------  // acclient.c:887874
void __cdecl _E137_27()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007602C0) --------------------------------------------------------  // acclient.c:887887
void __cdecl _E140_22()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Misc_TooltipEnable_26;
  v1 = 2;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00760300) --------------------------------------------------------  // acclient.c:887912
void __cdecl _E143_23()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760330) --------------------------------------------------------  // acclient.c:887925
void __cdecl _E146_23()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_26.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_26.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760360) --------------------------------------------------------  // acclient.c:887938
void __cdecl _E149_23()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760390) --------------------------------------------------------  // acclient.c:887951
void __cdecl _E152_22()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007603C0) --------------------------------------------------------  // acclient.c:887964
void __cdecl _E155_19()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007603F0) --------------------------------------------------------  // acclient.c:887977
void __cdecl _E158_21()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760420) --------------------------------------------------------  // acclient.c:887990
void __cdecl _E161_19()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760450) --------------------------------------------------------  // acclient.c:888003
void __cdecl _E164_21()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760480) --------------------------------------------------------  // acclient.c:888016
void __cdecl _E167_17()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007604B0) --------------------------------------------------------  // acclient.c:888029
void __cdecl _E170_16()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007604E0) --------------------------------------------------------  // acclient.c:888042
void __cdecl _E173_15()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760510) --------------------------------------------------------  // acclient.c:888055
void __cdecl _E176_16()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760540) --------------------------------------------------------  // acclient.c:888068
void __cdecl _E179_15()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760570) --------------------------------------------------------  // acclient.c:888081
void __cdecl _E182_15()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007605A0) --------------------------------------------------------  // acclient.c:888094
void __cdecl _E185_12()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007605D0) --------------------------------------------------------  // acclient.c:888107
void __cdecl _E188_13()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760600) --------------------------------------------------------  // acclient.c:888120
void __cdecl _E191_12()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760630) --------------------------------------------------------  // acclient.c:888133
void __cdecl _E194_19()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760660) --------------------------------------------------------  // acclient.c:888146
void __cdecl _E197_10()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760690) --------------------------------------------------------  // acclient.c:888159
void __cdecl _E200_15()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007606C0) --------------------------------------------------------  // acclient.c:888172
void __cdecl _E203_14()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007606F0) --------------------------------------------------------  // acclient.c:888185
void __cdecl _E206_17()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760720) --------------------------------------------------------  // acclient.c:888198
void __cdecl _E209_12()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_17;
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

//----- (00760760) --------------------------------------------------------  // acclient.c:888223
void __cdecl _E212_15()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_17;
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

//----- (007607A0) --------------------------------------------------------  // acclient.c:888248
void __cdecl _E215_11()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_17;
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

//----- (007607E0) --------------------------------------------------------  // acclient.c:888273
void __cdecl _E218_12()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_17;
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

//----- (00760820) --------------------------------------------------------  // acclient.c:888298
void __cdecl _E221_12()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_17;
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

//----- (00760860) --------------------------------------------------------  // acclient.c:888323
void __cdecl _E224_12()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Input_MouseLookSensitivity_2;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007608A0) --------------------------------------------------------  // acclient.c:888348
void __cdecl _E227_12()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSensitivity_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSensitivity_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007608D0) --------------------------------------------------------  // acclient.c:888361
void __cdecl _E230_12()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSmoothingAmount_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSmoothingAmount_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760900) --------------------------------------------------------  // acclient.c:888374
void __cdecl _E233_11()
{
  char *v0; // esi@1

  v0 = &Input_InvertMouseLookYAxis_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_InvertMouseLookYAxis_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760930) --------------------------------------------------------  // acclient.c:888387
void __cdecl _E236_11()
{
  char *v0; // esi@1

  v0 = &Input_UseMouseTurning_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_UseMouseTurning_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760960) --------------------------------------------------------  // acclient.c:888400
void __cdecl _E239_11()
{
  char *v0; // esi@1

  v0 = &waveform_None_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760990) --------------------------------------------------------  // acclient.c:888413
void __cdecl _E242_11()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007609C0) --------------------------------------------------------  // acclient.c:888426
void __cdecl _E245_10()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007609F0) --------------------------------------------------------  // acclient.c:888439
void __cdecl _E248_10()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760A20) --------------------------------------------------------  // acclient.c:888452
void __cdecl _E251_10()
{
  char *v0; // esi@1

  v0 = &waveform_Square_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760A50) --------------------------------------------------------  // acclient.c:888465
void __cdecl _E254_11()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760A80) --------------------------------------------------------  // acclient.c:888478
void __cdecl _E257_9()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760AB0) --------------------------------------------------------  // acclient.c:888491
void __cdecl _E260_10()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760AE0) --------------------------------------------------------  // acclient.c:888504
void __cdecl _E263_9()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760B10) --------------------------------------------------------  // acclient.c:888517
void __cdecl _E266_9()
{
  char *v0; // esi@1

  v0 = &Input_KeymapFile_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_KeymapFile_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760B40) --------------------------------------------------------  // acclient.c:888530
void __cdecl _E269_8()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontFace_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontFace_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760B70) --------------------------------------------------------  // acclient.c:888543
void __cdecl _E272_7()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontSize_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontSize_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760BA0) --------------------------------------------------------  // acclient.c:888556
void __cdecl _E275_7()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)UI_ChatFontSize_Choices_0;
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

//----- (00760BE0) --------------------------------------------------------  // acclient.c:888581
void __cdecl _E278_7()
{
  const int *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &LOWEST_DATA_RATE_73;
  v1 = 5;
  do
  {
    v2 = *(v0 - 1);
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

