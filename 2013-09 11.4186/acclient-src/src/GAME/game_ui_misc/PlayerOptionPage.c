/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PlayerOptionPage
   Object     : GAME\game_ui_misc\PlayerOptionPage.obj
   Functions  : 137
   Addresses  : 004F2680 - 00764790 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F2680) --------------------------------------------------------  // acclient.c:286446
void __userpurge PlayerOptionPage::PlayerOptionPage(PlayerOptionPage *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  PlayerOptionPage *v4; // esi@1

  v4 = this;
  OptionPage::OptionPage((OptionPage *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (IInputActionCallbackVtbl *)&PlayerOptionPage::vftable;
  v4->vfptr = (IOptionChangeHandlerVtbl *)&gmConfigUI::vftable;
  v4->m_pOptionBox = 0;
}
// 7C4344: using guessed type void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *);
// 7C4350: using guessed type int (__thiscall *PlayerOptionPage::vftable)(void *, char);

//----- (004F26C0) --------------------------------------------------------  // acclient.c:286460
void __thiscall PlayerOptionPage::~PlayerOptionPage(PlayerOptionPage *this)
{
  this->vfptr = (IInputActionCallbackVtbl *)&PlayerOptionPage::vftable;
  this->vfptr = (IOptionChangeHandlerVtbl *)&gmConfigUI::vftable;
  OptionPage::~OptionPage((OptionPage *)&this->vfptr);
}
// 7C4344: using guessed type void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *);
// 7C4350: using guessed type int (__thiscall *PlayerOptionPage::vftable)(void *, char);

//----- (004F26E0) --------------------------------------------------------  // acclient.c:286470
void __thiscall PlayerOptionPage::OnVisibilityChanged(PlayerOptionPage *this, bool i_bVisibleNow)
{
  PlayerOptionPage *v2; // esi@1

  v2 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisibleNow);
  if ( i_bVisibleNow )
    ((void (__thiscall *)(PlayerOptionPage *))v2->vfptr[26].__vecDelDtor)(v2);
  else
    ((void (__thiscall *)(PlayerOptionPage *))v2->vfptr[26].OnLoseFocus)(v2);
}

//----- (004F2710) --------------------------------------------------------  // acclient.c:286483
char __thiscall PlayerOptionPage::SaveCurrentValues(PlayerOptionPage *this)
{
  OptionPage *v1; // esi@1
  CPlayerSystem *v2; // eax@1

  v1 = (OptionPage *)this;
  v2 = CPlayerSystem::GetPlayerSystem();
  CPlayerModule::SaveToServer(&v2->playerModule, 0);
  return OptionPage::SaveCurrentValues(v1);
}

//----- (004F2730) --------------------------------------------------------  // acclient.c:286495
bool __thiscall PlayerOptionPage::AddSeperator(PlayerOptionPage *this)
{
  UIElement_ListBox *v1; // ecx@1
  int v2; // eax@2

  v1 = this->m_pOptionBox;
  if ( v1 )
    v2 = UIElement_ListBox::AddItemFromTemplateList(v1, 1u, 0) != 0;
  else
    LOBYTE(v2) = 0;
  return v2;
}

//----- (004F2750) --------------------------------------------------------  // acclient.c:286509
void __stdcall PlayerOptionPage::SetToggleLabel(UIOption_Checkbox *pToggle, unsigned int tokLabel, unsigned int tokTooltip)
{
  StringInfo _info; // [sp+4h] [bp-90h]@1

  StringInfo::StringInfo(&_info);
  StringInfo::SetStringIDandTableEnum(&_info, tokLabel, 268435459);
  UIElement_Text::SetStringInfo((UIElement_Text *)&pToggle->vfptr, &_info);
  StringInfo::SetStringIDandTableEnum(&_info, tokTooltip, 268435459);
  pToggle->vfptr[7].RecvNotice_ServerSaysAttemptFailed((NoticeHandler *)pToggle, (unsigned int)&_info);
  StringInfo::~StringInfo(&_info);
}

//----- (004F27D0) --------------------------------------------------------  // acclient.c:286522
void __thiscall PlayerOptionPage::OnOptionChanged(PlayerOptionPage *this, UIOption *pOption)
{
  UIElement *v2; // edi@1
  UIElement *v3; // esi@1
  UIElement *v4; // ebx@1

  v2 = (UIElement *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2];
  v3 = UIElement::GetChildRecursive(
         (UIElement *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2],
         0x100001FCu);
  v4 = UIElement::GetChildRecursive(v2, 0x100001FDu);
  if ( OptionPage::Changed((OptionPage *)v2) )
  {
    if ( v3 )
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 1u);
    if ( v4 )
      v4->vfptr[13].__vecDelDtor((IInputActionCallback *)v4, 1u);
  }
  else
  {
    if ( v3 )
      v3->vfptr[13].__vecDelDtor((IInputActionCallback *)v3, 13u);
    if ( v4 )
      v4->vfptr[13].__vecDelDtor((IInputActionCallback *)v4, 13u);
  }
}

//----- (004F2850) --------------------------------------------------------  // acclient.c:286550
void __thiscall PlayerOptionPage::OnOptionChangeConfirmed(PlayerOptionPage *this, UIOption *pOption, bool bConfirm)
{
  PlayerOptionPage *v3; // esi@1

  v3 = this;
  if ( bConfirm )
    ((void (__thiscall *)(_DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2][39].m_hashKey)(&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]);
  v3->vfptr->__vecDelDtor((IInputActionCallback *)v3, (unsigned int)pOption);
}

//----- (004F2880) --------------------------------------------------------  // acclient.c:286561
PlayerOptionPage *__thiscall PlayerOptionPage::vector_deleting_destructor(PlayerOptionPage *this, unsigned int a2)
{
  PlayerOptionPage *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&PlayerOptionPage::vftable;
  this->vfptr = (IOptionChangeHandlerVtbl *)&gmConfigUI::vftable;
  OptionPage::~OptionPage((OptionPage *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C4344: using guessed type void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *);
// 7C4350: using guessed type int (__thiscall *PlayerOptionPage::vftable)(void *, char);

//----- (004F28B0) --------------------------------------------------------  // acclient.c:286577
bool __thiscall PlayerOptionPage::AddHeader(PlayerOptionPage *this, unsigned int st)
{
  UIElement_ListBox *v2; // ecx@1
  int v3; // eax@2
  UIElement_Text *v4; // esi@3
  StringInfo _info; // [sp+4h] [bp-90h]@4

  v2 = this->m_pOptionBox;
  if ( v2 )
  {
    v3 = UIElement_ListBox::AddItemFromTemplateList(v2, 0, 0);
    if ( v3 )
    {
      v4 = (UIElement_Text *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v3 + 148))(v3, 12);
      if ( v4 )
      {
        StringInfo::StringInfo(&_info);
        StringInfo::SetStringIDandTableEnum(&_info, st, 268435459);
        if ( StringInfo::IsValid(&_info, 1) )
          UIElement_Text::SetStringInfo(v4, &_info);
        StringInfo::~StringInfo(&_info);
      }
    }
  }
  return 0;
}

//----- (004F2930) --------------------------------------------------------  // acclient.c:286605
UIOption_CheckboxSlider *__thiscall PlayerOptionPage::AddToggleWithSliderOption(PlayerOptionPage *this, PStringBase<char> *strToggleName, PStringBase<char> *strSliderName)
{
  OptionPage *v3; // edi@1
  UIElement_ListBox *v4; // ecx@1
  UIOption_CheckboxSlider *v5; // esi@1
  int v6; // eax@2
  int v7; // eax@3

  v3 = (OptionPage *)this;
  v4 = this->m_pOptionBox;
  v5 = 0;
  if ( !v4 )
    return v5;
  v6 = UIElement_ListBox::AddItemFromTemplateList(v4, 5u, 0);
  if ( !v6 )
    return v5;
  v7 = (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v6 + 148))(v6, 268435510);
  if ( v7 )
  {
    v5 = (UIOption_CheckboxSlider *)(v7 - 28);
    if ( v7 != 28 )
    {
      UIOption_CheckboxSlider::SetUIPreference(v5, strToggleName, strSliderName);
      OptionPage::RegisterOption(v3, (UIOption *)&v5->vfptr);
    }
    return v5;
  }
  return 0;
}

//----- (004F2990) --------------------------------------------------------  // acclient.c:286636
UIOption_Checkbox *__thiscall PlayerOptionPage::AddToggleOption(PlayerOptionPage *this, PStringBase<char> *strPrefName)
{
  OptionPage *v2; // edi@1
  UIElement_ListBox *v3; // ecx@1
  UIOption_Checkbox *v4; // esi@1
  int v5; // eax@2
  UIElement *v6; // eax@3
  int v7; // eax@4

  v2 = (OptionPage *)this;
  v3 = this->m_pOptionBox;
  v4 = 0;
  if ( !v3 )
    return v4;
  v5 = UIElement_ListBox::AddItemFromTemplateList(v3, 2u, 0);
  if ( !v5 )
    return v4;
  v6 = UIElement::GetChildRecursive((UIElement *)v5, 0x10000219u);
  if ( !v6 )
    return v4;
  v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435509);
  if ( v7 )
  {
    v4 = (UIOption_Checkbox *)(v7 - 32);
    if ( v7 != 32 )
    {
      UIOption_Checkbox::SetUIPreference(v4, strPrefName);
      OptionPage::RegisterOption(v2, (UIOption *)&v4->vfptr);
    }
    return v4;
  }
  return 0;
}

//----- (004F2A00) --------------------------------------------------------  // acclient.c:286671
UIOption_Checkbox *__thiscall PlayerOptionPage::AddToggleOption(PlayerOptionPage *this, PlayerOption po)
{
  OptionPage *v2; // edi@1
  UIElement_ListBox *v3; // ecx@1
  UIOption_Checkbox *v4; // esi@1
  int v5; // eax@2
  UIElement *v6; // eax@3
  int v7; // eax@4

  v2 = (OptionPage *)this;
  v3 = this->m_pOptionBox;
  v4 = 0;
  if ( !v3 )
    return v4;
  v5 = UIElement_ListBox::AddItemFromTemplateList(v3, 2u, 0);
  if ( !v5 )
    return v4;
  v6 = UIElement::GetChildRecursive((UIElement *)v5, 0x10000219u);
  if ( !v6 )
    return v4;
  v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)268435509);
  if ( v7 )
  {
    v4 = (UIOption_Checkbox *)(v7 - 32);
    if ( v7 != 32 )
    {
      UIOption_Checkbox::SetPlayerOption(v4, po);
      OptionPage::RegisterOption(v2, (UIOption *)&v4->vfptr);
    }
    return v4;
  }
  return 0;
}

//----- (004F2A70) --------------------------------------------------------  // acclient.c:286706
UIOption_Slider *__thiscall PlayerOptionPage::AddSliderOption(PlayerOptionPage *this, PStringBase<char> *strPrefName, bool i_fUseSliderLabels)
{
  OptionPage *v3; // edi@1
  UIElement_ListBox *v4; // ecx@1
  UIOption_Slider *v5; // esi@1
  int v6; // eax@2
  UIElement *v7; // eax@3
  int v8; // eax@4

  v3 = (OptionPage *)this;
  v4 = this->m_pOptionBox;
  v5 = 0;
  if ( !v4 )
    return v5;
  v6 = UIElement_ListBox::AddItemFromTemplateList(v4, i_fUseSliderLabels != 0 ? 6 : 3, 0);
  if ( !v6 )
    return v5;
  v7 = UIElement::GetChildRecursive((UIElement *)v6, 0x1000021Cu);
  if ( !v7 )
    return v5;
  v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)268435511);
  if ( v8 )
  {
    v5 = (UIOption_Slider *)(v8 - 32);
    if ( v8 != 32 )
    {
      UIOption_Slider::SetUIPreference(v5, strPrefName);
      OptionPage::RegisterOption(v3, (UIOption *)&v5->vfptr);
    }
    return v5;
  }
  return 0;
}

//----- (004F2AF0) --------------------------------------------------------  // acclient.c:286741
UIOption_Menu *__thiscall PlayerOptionPage::AddMenuOption(PlayerOptionPage *this, PStringBase<char> *strPrefName, bool i_fFromUI)
{
  OptionPage *v3; // edi@1
  UIElement_ListBox *v4; // ecx@1
  UIOption_Menu *v5; // esi@1
  int v6; // eax@2
  UIElement *v7; // eax@3
  int v8; // eax@4

  v3 = (OptionPage *)this;
  v4 = this->m_pOptionBox;
  v5 = 0;
  if ( v4 )
  {
    v6 = UIElement_ListBox::AddItemFromTemplateList(v4, 4u, 0);
    if ( v6 )
    {
      v7 = UIElement::GetChildRecursive((UIElement *)v6, 0x10000224u);
      if ( v7 )
      {
        v8 = v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)268435512);
        if ( !v8 )
          return 0;
        v5 = (UIOption_Menu *)(v8 - 32);
        if ( v8 != 32 )
        {
          if ( i_fFromUI )
          {
            UIOption_Menu::SetUIPreference(v5, strPrefName);
            OptionPage::RegisterOption(v3, (UIOption *)&v5->vfptr);
            return v5;
          }
          UIOption_Menu::SetUserPreference(v5, strPrefName);
          OptionPage::RegisterOption(v3, (UIOption *)&v5->vfptr);
        }
      }
    }
  }
  return v5;
}

//----- (004F2B80) --------------------------------------------------------  // acclient.c:286783
void __stdcall PlayerOptionPage::SetSliderLabel(UIOption_Slider *pSlider, unsigned int tokMinLabel, unsigned int tokMaxLabel)
{
  UIElement *v4; // eax@1
  UIElement *v5; // esi@1
  UIElement *v6; // eax@2
  UIElement_Text *v7; // edi@3
  UIElement *v8; // eax@5
  UIElement_Text *v9; // esi@6
  StringInfo _info; // [sp+8h] [bp-90h]@4

  v4 = (UIElement *)((int (__thiscall *)(_DWORD))pSlider->vfptr[13].OnAction)(&pSlider->vfptr);
  v5 = v4;
  if ( v4 )
  {
    v6 = UIElement::GetChildRecursive(v4, 0x1000021Eu);
    if ( v6 )
    {
      v7 = (UIElement_Text *)v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
      if ( v7 )
      {
        StringInfo::StringInfo(&_info);
        StringInfo::SetStringIDandTableEnum(&_info, tokMinLabel, 268435459);
        UIElement_Text::SetStringInfo(v7, &_info);
        StringInfo::~StringInfo(&_info);
      }
    }
    v8 = UIElement::GetChildRecursive(v5, 0x1000021Fu);
    if ( v8 )
    {
      v9 = (UIElement_Text *)v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
      if ( v9 )
      {
        StringInfo::StringInfo(&_info);
        StringInfo::SetStringIDandTableEnum(&_info, tokMaxLabel, 268435459);
        UIElement_Text::SetStringInfo(v9, &_info);
        StringInfo::~StringInfo(&_info);
      }
    }
  }
}

//----- (006F7E70) --------------------------------------------------------  // acclient.c:780759
void sub_6F7E70()
{
  flt_840EE0 = 1000.0 + 1.0;
}

//----- (006F7E90) --------------------------------------------------------  // acclient.c:780765
void sub_6F7E90()
{
  flt_840EE4 = 24.0 * 8.0;
}

//----- (006F7EB0) --------------------------------------------------------  // acclient.c:780771
void sub_6F7EB0()
{
  flt_840EE8 = 24.0 * 0.5;
}

//----- (006F7ED0) --------------------------------------------------------  // acclient.c:780777
int sub_6F7ED0()
{
  return atexit(nullsub_944);
}

//----- (006F7EE0) --------------------------------------------------------  // acclient.c:780783
int sub_6F7EE0()
{
  return atexit(nullsub_945);
}

//----- (006F7EF0) --------------------------------------------------------  // acclient.c:780789
int sub_6F7EF0()
{
  return atexit(nullsub_946);
}

//----- (006F7F00) --------------------------------------------------------  // acclient.c:780795
int _E106_82()
{
  PStringBase<char>::PStringBase<char>(&Camera_AlignToSlope_3, "Camera.AlignToSlope");
  return atexit(_E107_80);
}

//----- (006F7F20) --------------------------------------------------------  // acclient.c:780802
int _E109_49()
{
  PStringBase<char>::PStringBase<char>(&Camera_Stiffness_3, "Camera.Stiffness");
  return atexit(sub_763D90);
}

//----- (006F7F40) --------------------------------------------------------  // acclient.c:780809
int _E112_74()
{
  PStringBase<char>::PStringBase<char>(&Camera_AdjustmentSpeed_3, "Camera.AdjustmentSpeed");
  return atexit(_E113_55);
}

//----- (006F7F60) --------------------------------------------------------  // acclient.c:780816
int _E115_55()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_6, "Sound.SoundDisabled");
  return atexit(_E116_48);
}

//----- (006F7F80) --------------------------------------------------------  // acclient.c:780823
int _E118_55()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_6, "Sound.SoundVolume");
  return atexit(_E119_77);
}

//----- (006F7FA0) --------------------------------------------------------  // acclient.c:780830
int _E121_49()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_6, "Sound.AmbientSoundDisabled");
  return atexit(_E122_79);
}

//----- (006F7FC0) --------------------------------------------------------  // acclient.c:780837
int _E124_52()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_6, "Sound.AmbientSoundVolume");
  return atexit(_E125_51);
}

//----- (006F7FE0) --------------------------------------------------------  // acclient.c:780844
int _E127_41()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_6, "Sound.InterfaceSoundDisabled");
  return atexit(_E128_50);
}

//----- (006F8000) --------------------------------------------------------  // acclient.c:780851
int _E130_39()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_6, "Sound.InterfaceSoundVolume");
  return atexit(_E131_42);
}

//----- (006F8020) --------------------------------------------------------  // acclient.c:780858
int _E133_29()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_6, "Sound.SoundFeatures");
  return atexit(_E134_32);
}

//----- (006F8040) --------------------------------------------------------  // acclient.c:780865
int _E136_24()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_6, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E137_31);
}

//----- (006F8060) --------------------------------------------------------  // acclient.c:780872
int _E139_23()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_6, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_840F1C, "Mono");
  return atexit(_E140_26);
}

//----- (006F8090) --------------------------------------------------------  // acclient.c:780880
int _E142_21()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_43, "Misc.TooltipEnable");
  return atexit(_E143_26);
}

//----- (006F80B0) --------------------------------------------------------  // acclient.c:780887
int _E145_22()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_43, "Misc.TooltipDelay");
  return atexit(_E146_27);
}

//----- (006F80D0) --------------------------------------------------------  // acclient.c:780894
int _E148_24()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_19, "Display.Resolution");
  return atexit(_E149_27);
}

//----- (006F80F0) --------------------------------------------------------  // acclient.c:780901
int _E151_21()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_19, "Display.FullScreen");
  return atexit(_E152_25);
}

//----- (006F8110) --------------------------------------------------------  // acclient.c:780908
int _E154_21()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_19, "Display.RefreshRate");
  return atexit(_E155_22);
}

//----- (006F8130) --------------------------------------------------------  // acclient.c:780915
int _E157_20()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_19, "Display.SyncToRefresh");
  return atexit(_E158_24);
}

//----- (006F8150) --------------------------------------------------------  // acclient.c:780922
void _E160_22()
{
  DEFAULT_VIEW_RADIUS_85 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F8170) --------------------------------------------------------  // acclient.c:780928
void _E162_18()
{
  MIN_QUANTUM_85 = 1.0 / 30.0;
}

//----- (006F8190) --------------------------------------------------------  // acclient.c:780934
void _E164_5()
{
  MAX_QUANTUM_85 = 1.0 / 5.0;
}

//----- (006F81B0) --------------------------------------------------------  // acclient.c:780940
void _E166_19()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840F50, PFID_A8R8G8B8);
}

//----- (006F81C0) --------------------------------------------------------  // acclient.c:780946
void _E169_16()
{
  dword_840F88 = 1024;
}

//----- (006F81D0) --------------------------------------------------------  // acclient.c:780952
void _E171_15()
{
  dword_840F8C = 0x7FFF;
}

//----- (006F81E0) --------------------------------------------------------  // acclient.c:780958
int _E173_1()
{
  const int result; // eax@1

  result = dword_840F88;
  INITIAL_MAX_DATA_RATE_56 = dword_840F88;
  return result;
}

//----- (006F81F0) --------------------------------------------------------  // acclient.c:780968
int _E175_14()
{
  return atexit(_E176_19);
}

//----- (006F8200) --------------------------------------------------------  // acclient.c:780974
int _E178_14()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_19, "Render.TextureFiltering");
  return atexit(_E179_18);
}

//----- (006F8220) --------------------------------------------------------  // acclient.c:780981
int _E181_14()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_19, "Render.LandscapeDetailTextures");
  return atexit(_E182_18);
}

//----- (006F8240) --------------------------------------------------------  // acclient.c:780988
int _E184_12()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_19, "Render.BuildingDetailTextures");
  return atexit(_E185_15);
}

//----- (006F8260) --------------------------------------------------------  // acclient.c:780995
int _E187_11()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_19, "Render.FieldOfView");
  return atexit(_E188_16);
}

//----- (006F8280) --------------------------------------------------------  // acclient.c:781002
int _E190_12()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_19, "Render.LandscapeTextureDetail");
  return atexit(_E191_15);
}

//----- (006F82A0) --------------------------------------------------------  // acclient.c:781009
int _E193_11()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_19, "Render.EnvironmentTextureDetail");
  return atexit(_E194_22);
}

//----- (006F82C0) --------------------------------------------------------  // acclient.c:781016
int _E196_14()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_19, "Render.SceneryDrawDistance");
  return atexit(_E197_13);
}

//----- (006F82E0) --------------------------------------------------------  // acclient.c:781023
int _E199_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_19, "Render.LandscapeDrawDistance");
  return atexit(_E200_17);
}

//----- (006F8300) --------------------------------------------------------  // acclient.c:781030
int _E202_11()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_19, "Render.ScreenBrightness");
  return atexit(_E203_16);
}

//----- (006F8320) --------------------------------------------------------  // acclient.c:781037
int _E205_11()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_19, "Render.AspectRatio");
  return atexit(_E206_19);
}

//----- (006F8340) --------------------------------------------------------  // acclient.c:781044
int _E208_15()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_19, "Render.DisplayAdapter");
  return atexit(_E209_14);
}

//----- (006F8360) --------------------------------------------------------  // acclient.c:781051
int _E211_11()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_19, "Render.MaxHardwareClass");
  return atexit(_E212_17);
}

//----- (006F8380) --------------------------------------------------------  // acclient.c:781058
int _E214_14()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_19, "Render.AutomaticDegrades");
  return atexit(_E215_13);
}

//----- (006F83A0) --------------------------------------------------------  // acclient.c:781065
int _E217_11()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_19, "Render.GraphicsPerformance");
  return atexit(_E218_14);
}

//----- (006F83C0) --------------------------------------------------------  // acclient.c:781072
int _E220_11()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_19, "Render.DegradeDistance");
  return atexit(_E221_14);
}

//----- (006F83E0) --------------------------------------------------------  // acclient.c:781079
int _E223_11()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_19, "Render.MultiPassAlpha");
  return atexit(_E224_14);
}

//----- (006F8400) --------------------------------------------------------  // acclient.c:781086
int _E226_11()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_19, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_840FD8, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_840FDC, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_840FE0, "Anisotropic");
  return atexit(_E227_14);
}

//----- (006F8450) --------------------------------------------------------  // acclient.c:781096
int _E229_11()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_19, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_840FE8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_840FEC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_840FF0, "High");
  PStringBase<char>::PStringBase<char>(&stru_840FF4, "VeryHigh");
  return atexit(_E230_14);
}

//----- (006F84B0) --------------------------------------------------------  // acclient.c:781107
int _E232_11()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_19, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_840FFC, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841000, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841004, "High");
  PStringBase<char>::PStringBase<char>(&stru_841008, "VeryHigh");
  return atexit(_E233_13);
}

//----- (006F8510) --------------------------------------------------------  // acclient.c:781118
int _E235_11()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_19, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841010, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841014, "High");
  return atexit(_E236_13);
}

//----- (006F8550) --------------------------------------------------------  // acclient.c:781127
int _E238_10()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_19, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_84101C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_841020, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841024, "High");
  PStringBase<char>::PStringBase<char>(&stru_841028, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_84102C, "Extreme");
  return atexit(_E239_13);
}

//----- (006F85C0) --------------------------------------------------------  // acclient.c:781139
int _E241_10()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_19, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_841034, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_841038, "Wide");
  return atexit(_E242_13);
}

//----- (006F8600) --------------------------------------------------------  // acclient.c:781148
int _E244_10()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSensitivity_3, "Input.MouseLookSensitivity");
  return atexit(_E245_12);
}

//----- (006F8620) --------------------------------------------------------  // acclient.c:781155
int _E247_10()
{
  PStringBase<char>::PStringBase<char>(&Input_MouseLookSmoothingAmount_3, "Input.MouseLookSmoothingAmount");
  return atexit(_E248_12);
}

//----- (006F8640) --------------------------------------------------------  // acclient.c:781162
int _E250_10()
{
  PStringBase<char>::PStringBase<char>(&Input_InvertMouseLookYAxis_3, "Input.InvertMouseLookYAxis");
  return atexit(_E251_12);
}

//----- (006F8660) --------------------------------------------------------  // acclient.c:781169
int _E253_10()
{
  PStringBase<char>::PStringBase<char>(&Input_UseMouseTurning_3, "Input.UseMouseTurning");
  return atexit(_E254_13);
}

//----- (006F8680) --------------------------------------------------------  // acclient.c:781176
int _E256_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_41, "None");
  return atexit(_E257_11);
}

//----- (006F86A0) --------------------------------------------------------  // acclient.c:781183
int _E259_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_41, "Speed");
  return atexit(_E260_12);
}

//----- (006F86C0) --------------------------------------------------------  // acclient.c:781190
int _E262_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_41, "Noise");
  return atexit(_E263_11);
}

//----- (006F86E0) --------------------------------------------------------  // acclient.c:781197
int _E265_11()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_41, "Sine");
  return atexit(_E266_11);
}

//----- (006F8700) --------------------------------------------------------  // acclient.c:781204
int _E268_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_41, "Square");
  return atexit(_E269_10);
}

//----- (006F8720) --------------------------------------------------------  // acclient.c:781211
int _E271_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_41, "Bounce");
  return atexit(_E272_9);
}

//----- (006F8740) --------------------------------------------------------  // acclient.c:781218
int _E274_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_41, "Perlin");
  return atexit(_E275_9);
}

//----- (006F8760) --------------------------------------------------------  // acclient.c:781225
int _E277_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_41, "Fractal");
  return atexit(_E278_9);
}

//----- (006F8780) --------------------------------------------------------  // acclient.c:781232
int _E280_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_41, "FrameLoop");
  return atexit(_E281_9);
}

//----- (006F87A0) --------------------------------------------------------  // acclient.c:781239
int sub_6F87A0()
{
  return atexit(nullsub_943);
}

//----- (00763D60) --------------------------------------------------------  // acclient.c:890341
void __cdecl _E107_80()
{
  char *v0; // esi@1

  v0 = &Camera_AlignToSlope_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AlignToSlope_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763D90) --------------------------------------------------------  // acclient.c:890354
void __cdecl sub_763D90()
{
  char *v0; // esi@1

  v0 = &Camera_Stiffness_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_Stiffness_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763DC0) --------------------------------------------------------  // acclient.c:890367
void __cdecl _E113_55()
{
  char *v0; // esi@1

  v0 = &Camera_AdjustmentSpeed_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Camera_AdjustmentSpeed_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763DF0) --------------------------------------------------------  // acclient.c:890380
void __cdecl _E116_48()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763E20) --------------------------------------------------------  // acclient.c:890393
void __cdecl _E119_77()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763E50) --------------------------------------------------------  // acclient.c:890406
void __cdecl _E122_79()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763E80) --------------------------------------------------------  // acclient.c:890419
void __cdecl _E125_51()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763EB0) --------------------------------------------------------  // acclient.c:890432
void __cdecl _E128_50()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763EE0) --------------------------------------------------------  // acclient.c:890445
void __cdecl _E131_42()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763F10) --------------------------------------------------------  // acclient.c:890458
void __cdecl _E134_32()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763F40) --------------------------------------------------------  // acclient.c:890471
void __cdecl _E137_31()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763F70) --------------------------------------------------------  // acclient.c:890484
void __cdecl _E140_26()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Misc_TooltipEnable_43;
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

//----- (00763FB0) --------------------------------------------------------  // acclient.c:890509
void __cdecl _E143_26()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763FE0) --------------------------------------------------------  // acclient.c:890522
void __cdecl _E146_27()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764010) --------------------------------------------------------  // acclient.c:890535
void __cdecl _E149_27()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764040) --------------------------------------------------------  // acclient.c:890548
void __cdecl _E152_25()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764070) --------------------------------------------------------  // acclient.c:890561
void __cdecl _E155_22()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007640A0) --------------------------------------------------------  // acclient.c:890574
void __cdecl _E158_24()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007640D0) --------------------------------------------------------  // acclient.c:890587
void __cdecl _E179_18()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764100) --------------------------------------------------------  // acclient.c:890600
void __cdecl _E182_18()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764130) --------------------------------------------------------  // acclient.c:890613
void __cdecl _E185_15()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764160) --------------------------------------------------------  // acclient.c:890626
void __cdecl _E188_16()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764190) --------------------------------------------------------  // acclient.c:890639
void __cdecl _E191_15()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007641C0) --------------------------------------------------------  // acclient.c:890652
void __cdecl _E194_22()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007641F0) --------------------------------------------------------  // acclient.c:890665
void __cdecl _E197_13()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764220) --------------------------------------------------------  // acclient.c:890678
void __cdecl _E200_17()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764250) --------------------------------------------------------  // acclient.c:890691
void __cdecl _E203_16()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764280) --------------------------------------------------------  // acclient.c:890704
void __cdecl _E206_19()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007642B0) --------------------------------------------------------  // acclient.c:890717
void __cdecl _E209_14()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007642E0) --------------------------------------------------------  // acclient.c:890730
void __cdecl _E212_17()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764310) --------------------------------------------------------  // acclient.c:890743
void __cdecl _E215_13()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764340) --------------------------------------------------------  // acclient.c:890756
void __cdecl _E218_14()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764370) --------------------------------------------------------  // acclient.c:890769
void __cdecl _E221_14()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007643A0) --------------------------------------------------------  // acclient.c:890782
void __cdecl _E224_14()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007643D0) --------------------------------------------------------  // acclient.c:890795
void __cdecl _E227_14()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_19;
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

//----- (00764410) --------------------------------------------------------  // acclient.c:890820
void __cdecl _E230_14()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_19;
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

//----- (00764450) --------------------------------------------------------  // acclient.c:890845
void __cdecl _E233_13()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_19;
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

//----- (00764490) --------------------------------------------------------  // acclient.c:890870
void __cdecl _E236_13()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_19;
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

//----- (007644D0) --------------------------------------------------------  // acclient.c:890895
void __cdecl _E239_13()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_19;
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

//----- (00764510) --------------------------------------------------------  // acclient.c:890920
void __cdecl _E242_13()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &Input_MouseLookSensitivity_3;
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

//----- (00764550) --------------------------------------------------------  // acclient.c:890945
void __cdecl _E245_12()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSensitivity_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSensitivity_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764580) --------------------------------------------------------  // acclient.c:890958
void __cdecl _E248_12()
{
  char *v0; // esi@1

  v0 = &Input_MouseLookSmoothingAmount_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_MouseLookSmoothingAmount_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007645B0) --------------------------------------------------------  // acclient.c:890971
void __cdecl _E251_12()
{
  char *v0; // esi@1

  v0 = &Input_InvertMouseLookYAxis_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_InvertMouseLookYAxis_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007645E0) --------------------------------------------------------  // acclient.c:890984
void __cdecl _E254_13()
{
  char *v0; // esi@1

  v0 = &Input_UseMouseTurning_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_UseMouseTurning_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764610) --------------------------------------------------------  // acclient.c:890997
void __cdecl _E257_11()
{
  char *v0; // esi@1

  v0 = &waveform_None_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764640) --------------------------------------------------------  // acclient.c:891010
void __cdecl _E260_12()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764670) --------------------------------------------------------  // acclient.c:891023
void __cdecl _E263_11()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007646A0) --------------------------------------------------------  // acclient.c:891036
void __cdecl _E266_11()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007646D0) --------------------------------------------------------  // acclient.c:891049
void __cdecl _E269_10()
{
  char *v0; // esi@1

  v0 = &waveform_Square_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764700) --------------------------------------------------------  // acclient.c:891062
void __cdecl _E272_9()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764730) --------------------------------------------------------  // acclient.c:891075
void __cdecl _E275_9()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764760) --------------------------------------------------------  // acclient.c:891088
void __cdecl _E278_9()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764790) --------------------------------------------------------  // acclient.c:891101
void __cdecl _E281_9()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

