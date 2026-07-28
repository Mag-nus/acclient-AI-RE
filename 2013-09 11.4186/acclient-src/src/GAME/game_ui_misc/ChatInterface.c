/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ChatInterface
   Object     : GAME\game_ui_misc\ChatInterface.obj
   Functions  : 92
   Addresses  : 004F2F10 - 00764B40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F2F10) --------------------------------------------------------  // acclient.c:287011
BOOL __thiscall ChatInterface::TypeIsActive(ChatInterface *this, unsigned int i_ltt)
{
  return (unsigned int)(1i64 << i_ltt) & this->m_llTextTypeFilter
      || ((unsigned __int64)(1i64 << i_ltt) >> 32) & HIDWORD(this->m_llTextTypeFilter);
}

//----- (004F2F50) --------------------------------------------------------  // acclient.c:287018
void __thiscall ChatInterface::RecvNotice_PlayerDescReceived(ChatInterface *this, CACQualities *i_playerDesc, CPlayerModule *i_playerModule)
{
  (*(void (**)(void))&this->vfptr[7].gap4[4])();
}

//----- (004F2F60) --------------------------------------------------------  // acclient.c:287024
void __thiscall ChatInterface::RecvNotice_ClearChatBuffer(ChatInterface *this, unsigned int i_idWindow)
{
  ChatInterface *v2; // eax@1
  UIElement_Text *v3; // ecx@1

  v2 = this;
  v3 = this->m_chatLog;
  if ( v3 && (!i_idWindow || i_idWindow == v2->m_eWindowID) )
    UIElement_Text::ClearAllText(v3);
}

//----- (004F2F90) --------------------------------------------------------  // acclient.c:287036
void __thiscall ChatInterface::ActivateChatEntry(ChatInterface *this)
{
  ChatInterface *v1; // esi@1

  v1 = this;
  ((void (*)(void))this->m_chatEntry->vfptr[21].__vecDelDtor)();
  ((void (*)(void))v1->m_chatEntry->vfptr[21].OnLoseFocus)();
  CM_UI::SendNotice_ToggleChatEntry(1);
}

//----- (004F2FC0) --------------------------------------------------------  // acclient.c:287047
void __thiscall ChatInterface::DeactivateChatEntry(ChatInterface *this)
{
  ChatInterface *v1; // esi@1

  v1 = this;
  ((void (*)(void))this->m_chatEntry->vfptr[22].__vecDelDtor)();
  ((void (*)(void))v1->m_chatEntry->vfptr[21].OnAction)();
  CM_UI::SendNotice_ToggleChatEntry(0);
}

//----- (004F2FF0) --------------------------------------------------------  // acclient.c:287058
void __thiscall ChatInterface::HandleCommandOrAliasKey(ChatInterface *this, unsigned int i_inputAction)
{
  ChatInterface *v2; // esi@1
  unsigned int v3; // eax@1
  UIElement_Text *v4; // ecx@4
  StringInfo info; // [sp+4h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&info);
  v3 = ID_CmdPrefix_0;
  if ( i_inputAction != 268435496 )
    v3 = ID_AliasPrefix_0;
  info.m_stringID = v3;
  StringInfo::SetTableEnum(&info, 6);
  if ( StringInfo::IsValid(&info, 1) )
  {
    v4 = v2->m_chatEntry;
    if ( v4 )
    {
      ((void (*)(void))v4->vfptr[21].__vecDelDtor)();
      ((void (*)(void))v2->m_chatEntry->vfptr[21].OnLoseFocus)();
      CM_UI::SendNotice_ToggleChatEntry(1);
      UIElement_Text::SetStringInfo(v2->m_chatEntry, &info);
      UIElement_Text::Deselect(v2->m_chatEntry);
      UIElement_Text::MoveCursorToEnd(v2->m_chatEntry);
    }
  }
  StringInfo::~StringInfo(&info);
}

//----- (004F30A0) --------------------------------------------------------  // acclient.c:287089
bool __thiscall ChatInterface::IsTextEntryFocused(ChatInterface *this)
{
  UIElement *v1; // esi@1
  ChatInterface *v2; // edi@1

  v1 = UIElementManager::s_pInstance->m_activeElement;
  v2 = this;
  return v1
      && v1 == UIElement::GetRootElement((UIElement *)&this->vfptr)
      && (UIElement_Text *)UIElement::GetFocusDescendant(v1) == v2->m_chatEntry;
}

//----- (004F30E0) --------------------------------------------------------  // acclient.c:287102
void __thiscall ChatInterface::RecvNotice_GameplayOptionChanged(ChatInterface *this, BaseProperty *i_prop, unsigned int i_dwUserData)
{
  ChatInterface *v3; // esi@1
  BasePropertyValue *v4; // ecx@3

  v3 = this;
  if ( BaseProperty::GetPropertyName(i_prop) == (BasePropertyDesc *)268435583 && i_dwUserData == v3->m_eWindowID )
  {
    v4 = i_prop->m_pcPropertyValue;
    if ( v4 )
      ((void (__stdcall *)(int))v4->vfptr[58].__vecDelDtor)(&v3->m_llTextTypeFilter);
  }
}

//----- (004F3120) --------------------------------------------------------  // acclient.c:287117
void __thiscall ChatInterface::SetOpacity(ChatInterface *this, float i_fOpacity)
{
  UIObject *v2; // eax@1
  UIRegion *v3; // ecx@2
  int v4; // eax@4

  this->m_fCurrentOpacity = i_fOpacity;
  v2 = this->m_object;
  if ( v2 || (v3 = this->m_parent) != 0 && (v2 = UIRegion::GetObjectA(v3)) != 0 )
  {
    v4 = ((int (__thiscall *)(UIObject *))v2->vfptr[7].__vecDelDtor)(v2);
    if ( v4 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 72))(v4, LODWORD(i_fOpacity));
  }
}

//----- (004F3160) --------------------------------------------------------  // acclient.c:287134
char __thiscall ChatInterface::SetUIObject(ChatInterface *this, UIObject *i_pcUIObject)
{
  ChatInterface *v2; // esi@1
  char v3; // al@1
  char v4; // bl@1
  UIObject *v5; // eax@1
  UIRegion *v6; // ecx@2
  int v7; // eax@4
  float i_pcUIObjecta; // [sp+Ch] [bp+4h]@1

  v2 = this;
  v3 = UIElement::SetUIObject((UIElement *)this, i_pcUIObject);
  i_pcUIObjecta = v2->m_fActiveOpacity;
  v4 = v3;
  v2->m_fActiveOpacity = i_pcUIObjecta;
  v5 = (UIObject *)v2->m_parent;
  if ( v5 || (v6 = (UIRegion *)v2->m_eBlitMode) != 0 && (v5 = UIRegion::GetObjectA(v6)) != 0 )
  {
    v7 = ((int (__thiscall *)(UIObject *))v5->vfptr[7].__vecDelDtor)(v5);
    if ( v7 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v7 + 72))(v7, LODWORD(i_pcUIObjecta));
  }
  return v4;
}

//----- (004F31C0) --------------------------------------------------------  // acclient.c:287160
void __thiscall ChatInterface::BuildChatColorLookupTable(ChatInterface *this)
{
  ChatInterface *v1; // ebx@1
  signed int v2; // esi@4
  BasePropertyDesc *v3; // ecx@75
  unsigned int v4; // edx@75
  BasePropertyValue *v5; // ecx@79
  unsigned int v6; // edx@79
  BasePropertyDesc *v7; // ecx@83
  unsigned int v8; // edx@83
  BasePropertyValue *v9; // ecx@87
  unsigned int v10; // edx@87
  BaseProperty p; // [sp+124h] [bp-10h]@2
  BaseProperty subP; // [sp+12Ch] [bp-8h]@2

  v1 = this;
  if ( this->m_chatLog )
  {
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&p, 0x1Bu);
    subP.m_pcPropertyDesc = 0;
    subP.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&subP, 0x19u);
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorGreen);
    }
    v2 = 34;
    do
    {
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[63].__vecDelDtor)(&subP);
      }
      --v2;
    }
    while ( v2 );
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorWhite);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(2, &subP);
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorGrey);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(12, &subP);
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorYellow);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(3, &subP);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(31, &subP);
        if ( p.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&p);
          ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(10, &subP);
          if ( p.m_pcPropertyValue )
          {
            BaseProperty::CheckCopyOnWrite(&p);
            ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(19, &subP);
          }
        }
      }
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorTan);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(4, &subP);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(11, &subP);
      }
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorPink);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(8, &subP);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(9, &subP);
      }
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorOrange);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(18, &subP);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(33, &subP);
      }
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorBlueGrey);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(27, &subP);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(28, &subP);
        if ( p.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&p);
          ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(29, &subP);
          if ( p.m_pcPropertyValue )
          {
            BaseProperty::CheckCopyOnWrite(&p);
            ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(30, &subP);
            if ( p.m_pcPropertyValue )
            {
              BaseProperty::CheckCopyOnWrite(&p);
              ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(32, &subP);
              if ( p.m_pcPropertyValue )
              {
                BaseProperty::CheckCopyOnWrite(&p);
                ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(14, &subP);
              }
            }
          }
        }
      }
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorDarkRed);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(15, &subP);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(6, &subP);
        if ( p.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&p);
          ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(21, &subP);
        }
      }
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorLightRed);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(22, &subP);
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorLightBlue);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(7, &subP);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(17, &subP);
      }
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorCyan);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(13, &subP);
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorBrightPurple);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(5, &subP);
    }
    if ( subP.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&subP);
      ((void (__stdcall *)(_DWORD))subP.m_pcPropertyValue->vfptr[39].__vecDelDtor)(&colorBrightRed);
    }
    if ( p.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&p);
      ((void (__stdcall *)(_DWORD, _DWORD))p.m_pcPropertyValue->vfptr[62].__vecDelDtor)(26, &subP);
    }
    ((void (__stdcall *)(BaseProperty *))v1->m_chatLog->vfptr[17].OnLoseFocus)(&p);
    if ( (_DWORD)subP.m_pcPropertyDesc )
    {
      v3 = subP.m_pcPropertyDesc;
      v4 = subP.m_pcPropertyDesc->m_cRef - 1;
      subP.m_pcPropertyDesc->m_cRef = v4;
      if ( !v4 )
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      subP.m_pcPropertyDesc = 0;
    }
    if ( subP.m_pcPropertyValue )
    {
      v5 = subP.m_pcPropertyValue;
      v6 = subP.m_pcPropertyValue->m_cRef - 1;
      subP.m_pcPropertyValue->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      subP.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v7 = p.m_pcPropertyDesc;
      v8 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v8;
      if ( !v8 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( p.m_pcPropertyValue )
    {
      v9 = p.m_pcPropertyValue;
      v10 = p.m_pcPropertyValue->m_cRef - 1;
      p.m_pcPropertyValue->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004F3840) --------------------------------------------------------  // acclient.c:287440
void __thiscall ChatInterface::ListenToGlobalMessage(ChatInterface *this, unsigned int i_messageID, int i_data_int)
{
  ChatInterface *v3; // esi@1
  bool v4; // al@3
  long double v5; // st7@5
  long double v6; // st7@6
  long double v7; // st7@8
  UIObject *v8; // eax@11
  UIRegion *v9; // ecx@12
  int v10; // eax@14
  float i_messageIDa; // [sp+8h] [bp+4h]@11

  v3 = this;
  if ( i_messageID != 3 )
    return;
  if ( (LODWORD(this->m_alphaBlendMod) >> 4) & 1
    || (v4 = ChatInterface::IsTextEntryFocused((ChatInterface *)((char *)this - 4))) != 0 )
    v4 = 1;
  v5 = fabs(v3->m_fDefaultOpacity - *(float *)&v3->m_eWindowID) * 0.050000001;
  if ( v4 )
  {
    v6 = v5 + v3->m_fActiveOpacity;
    v3->m_fActiveOpacity = v6;
    if ( v6 >= v3->m_fDefaultOpacity )
    {
      v3->m_fActiveOpacity = v3->m_fDefaultOpacity;
LABEL_10:
      UIListener::UnRegisterForGlobalMessage((UIListener *)v3, 3u);
      goto LABEL_11;
    }
  }
  else
  {
    v7 = v3->m_fActiveOpacity - v5;
    v3->m_fActiveOpacity = v7;
    if ( v7 <= *(float *)&v3->m_eWindowID )
    {
      LODWORD(v3->m_fActiveOpacity) = v3->m_eWindowID;
      goto LABEL_10;
    }
  }
LABEL_11:
  i_messageIDa = v3->m_fActiveOpacity;
  v3->m_fActiveOpacity = i_messageIDa;
  v8 = (UIObject *)v3->m_parent;
  if ( v8 || (v9 = (UIRegion *)v3->m_eBlitMode) != 0 && (v8 = UIRegion::GetObjectA(v9)) != 0 )
  {
    v10 = ((int (__thiscall *)(UIObject *))v8->vfptr[7].__vecDelDtor)(v8);
    if ( v10 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v10 + 72))(v10, LODWORD(i_messageIDa));
  }
}

//----- (004F3920) --------------------------------------------------------  // acclient.c:287494
void __thiscall ChatInterface::UpdateFromPlayerModule(ChatInterface *this)
{
  ChatInterface *v1; // esi@1
  CPlayerSystem *v2; // eax@3
  unsigned int v3; // ST00_4@3
  bool v4; // al@3
  BasePropertyValue *v5; // ecx@3
  BasePropertyDesc *v6; // ecx@7
  unsigned int v7; // edx@7
  bool v8; // zf@11
  BaseProperty prop; // [sp+8h] [bp-8h]@3

  v1 = this;
  if ( this->m_eWindowID && CPlayerSystem::GetPlayerSystem() )
  {
    v2 = CPlayerSystem::GetPlayerSystem();
    v3 = v1->m_eWindowID;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    v4 = PlayerModule::InqChatWindowOption((PlayerModule *)&v2->playerModule.vfptr, v3, 0x1000007Fu, &prop);
    v5 = prop.m_pcPropertyValue;
    if ( v4 && prop.m_pcPropertyValue )
    {
      ((void (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[58].__vecDelDtor)(&v1->m_llTextTypeFilter);
      v5 = prop.m_pcPropertyValue;
    }
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v6 = prop.m_pcPropertyDesc;
      v7 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      v5 = prop.m_pcPropertyValue;
      prop.m_pcPropertyDesc = 0;
    }
    if ( v5 )
    {
      v8 = v5->m_cRef-- == 1;
      if ( v8 )
        ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004F39E0) --------------------------------------------------------  // acclient.c:287540
void __userpurge ChatInterface::ResizeTo(ChatInterface *this@<ecx>, int a2@<edi>, const int i_cWidth, const int i_cHeight)
{
  ChatInterface *v4; // esi@1
  UIElement_Text *v5; // ecx@1
  bool v6; // bl@1

  v4 = this;
  v5 = this->m_chatEntry;
  v6 = 0;
  if ( v5 )
    v6 = UIElement_Text::IsAtVerticalEnd(v5);
  UIElement::ResizeTo((UIElement *)v4, a2, i_cWidth, i_cHeight);
  if ( v6 )
    UIElement_Text::ScrollToPosition(v4->m_chatEntry, v4->m_chatEntry->m_glyphList.m_glyphList._num_elements);
}

//----- (004F3A30) --------------------------------------------------------  // acclient.c:287557
void __thiscall ChatInterface::SelectCommandFromHistory(ChatInterface *this, bool i_fPrevious)
{
  ChatInterface *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@2
  PStringBase<unsigned short> *v5; // eax@9
  bool v6; // al@9
  int v7; // edi@9
  bool v8; // bl@9
  unsigned int v9; // ecx@15
  int v10; // eax@15

  v2 = this;
  v3 = this->m_LastInputHistoryPos;
  if ( i_fPrevious )
  {
    v4 = this->m_InputHistory.m_num;
    if ( v3 < v4 )
    {
      if ( v3 )
      {
        v2->m_LastInputHistoryPos = v3 - 1;
        goto LABEL_5;
      }
    }
    else if ( v4 )
    {
      v2->m_LastInputHistoryPos = v4 - 1;
LABEL_5:
      UIElement_Text::SetText(v2->m_chatEntry, &v2->m_InputHistory.m_data[v2->m_LastInputHistoryPos]);
      UIElement_Text::ScrollToPosition(v2->m_chatEntry, v2->m_chatEntry->m_glyphList.m_glyphList._num_elements);
      return;
    }
  }
  else if ( v3 == -1 )
  {
    v5 = UIElement_Text::GetText(this->m_chatEntry, (PStringBase<unsigned short> *)&i_fPrevious);
    v6 = PStringBase<unsigned short>::operator!=(v5, &PStringBase<unsigned short>::null_string);
    v7 = i_fPrevious - 20;
    v8 = v6;
    if ( !InterlockedDecrement((volatile LONG *)(i_fPrevious - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
      UIElement_Text::SetText(v2->m_chatEntry, &PStringBase<unsigned short>::null_string);
  }
  else
  {
    v9 = this->m_InputHistory.m_num;
    v10 = v3 + 1;
    v2->m_LastInputHistoryPos = v10;
    if ( v10 < v9 )
      goto LABEL_5;
    UIElement_Text::SetText(v2->m_chatEntry, &PStringBase<unsigned short>::null_string);
    v2->m_LastInputHistoryPos = -1;
  }
}

//----- (004F3B30) --------------------------------------------------------  // acclient.c:287615
char __thiscall ChatInterface::OnToggleChatEntry(ChatInterface *this)
{
  UIElement *v1; // ebx@1
  ChatInterface *v2; // esi@1
  UIElement *v3; // edi@3
  char result; // al@4

  v1 = UIElementManager::s_pInstance->m_activeElement;
  v2 = this;
  if ( v1
    && v1 == UIElement::GetRootElement((UIElement *)&this->vfptr)
    && (v3 = (UIElement *)&v2->m_chatEntry->vfptr, UIElement::GetFocusDescendant(v1) == v3) )
  {
    ((void (__thiscall *)(UIElement *))v3->vfptr[22].__vecDelDtor)(v3);
    ((void (*)(void))v2->m_chatEntry->vfptr[21].OnAction)();
    CM_UI::SendNotice_ToggleChatEntry(0);
    result = 1;
  }
  else
  {
    ((void (*)(void))v2->m_chatEntry->vfptr[21].__vecDelDtor)();
    ((void (*)(void))v2->m_chatEntry->vfptr[21].OnLoseFocus)();
    CM_UI::SendNotice_ToggleChatEntry(1);
    result = 1;
  }
  return result;
}

//----- (004F3BC0) --------------------------------------------------------  // acclient.c:287644
void __thiscall ChatInterface::SetDefaultOpacity(ChatInterface *this, float i_fOpacity)
{
  ChatInterface *v2; // esi@1
  double v3; // st7@1
  UIElement *v4; // edi@4

  v2 = this;
  v3 = this->m_fActiveOpacity;
  this->m_fDefaultOpacity = i_fOpacity;
  if ( v3 < i_fOpacity )
    ChatInterface::SetActiveOpacity(this, i_fOpacity);
  if ( !((*((_DWORD *)&v2->0 + 41) >> 4) & 1) )
  {
    v4 = UIElementManager::s_pInstance->m_activeElement;
    if ( !v4
      || v4 != UIElement::GetRootElement((UIElement *)&v2->vfptr)
      || (UIElement_Text *)UIElement::GetFocusDescendant(v4) != v2->m_chatEntry )
      ChatInterface::SetOpacity(v2, v2->m_fDefaultOpacity);
  }
}

//----- (004F3C40) --------------------------------------------------------  // acclient.c:287666
void __thiscall ChatInterface::SetActiveOpacity(ChatInterface *this, float i_fOpacity)
{
  ChatInterface *v2; // esi@1
  double v3; // st7@1
  UIElement *v4; // edi@4
  UIObject *v5; // eax@7
  UIRegion *v6; // ecx@8
  int v7; // eax@10
  float i_fOpacitya; // [sp+8h] [bp+4h]@7

  v2 = this;
  v3 = this->m_fDefaultOpacity;
  this->m_fActiveOpacity = i_fOpacity;
  if ( v3 > i_fOpacity )
    ChatInterface::SetDefaultOpacity(this, i_fOpacity);
  if ( (*((_DWORD *)&v2->0 + 41) >> 4) & 1
    || (v4 = UIElementManager::s_pInstance->m_activeElement) != 0
    && v4 == UIElement::GetRootElement((UIElement *)&v2->vfptr)
    && (UIElement_Text *)UIElement::GetFocusDescendant(v4) == v2->m_chatEntry )
  {
    i_fOpacitya = v2->m_fActiveOpacity;
    v2->m_fCurrentOpacity = i_fOpacitya;
    v5 = v2->m_object;
    if ( v5 || (v6 = v2->m_parent) != 0 && (v5 = UIRegion::GetObjectA(v6)) != 0 )
    {
      v7 = ((int (__thiscall *)(UIObject *))v5->vfptr[7].__vecDelDtor)(v5);
      if ( v7 )
        (*(void (__thiscall **)(int, float))(*(_DWORD *)v7 + 72))(v7, LODWORD(i_fOpacitya));
    }
  }
}

//----- (004F3D00) --------------------------------------------------------  // acclient.c:287699
char __thiscall SmartArray<PStringBase<unsigned short>,1>::RemoveOrderedByIndex(SmartArray<PStringBase<unsigned short>,1> *this, unsigned int index)
{
  SmartArray<PStringBase<unsigned short>,1> *v2; // edi@1
  unsigned int v3; // eax@1
  PStringBase<unsigned short> *v4; // ecx@2
  int v5; // eax@2
  unsigned int v6; // esi@2
  int v7; // ebp@2
  int v8; // eax@3
  int v9; // ebx@4
  int v10; // eax@7
  wchar_t *v11; // esi@9
  volatile LONG *v12; // ebx@9
  int v13; // edi@9
  int v14; // eax@9
  int v15; // ebp@10
  int v16; // esi@14
  char result; // al@17

  v2 = this;
  v3 = this->m_num;
  if ( index >= v3 )
  {
    result = 0;
  }
  else
  {
    v4 = this->m_data;
    v5 = v3 - 1;
    v6 = (unsigned int)&v4[index];
    v7 = (int)&v4[v5];
    for ( v2->m_num = v5; v6 < v7; v6 += 4 )
    {
      v8 = *(_DWORD *)v6;
      if ( *(_DWORD *)v6 != *(_DWORD *)(v6 + 4) )
      {
        v9 = v8 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        v10 = *(_DWORD *)(v6 + 4);
        *(_DWORD *)v6 = v10;
        InterlockedIncrement((volatile LONG *)(v10 - 16));
      }
    }
    v11 = PStringBase<unsigned short>::s_NullBuffer;
    v12 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    v13 = (int)&v2->m_data[v2->m_num];
    v14 = *(_DWORD *)v13;
    if ( *(wchar_t **)v13 != v11 )
    {
      v15 = v14 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v14 - 20 + 4)) && v15 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      *(_DWORD *)v13 = v11;
      InterlockedIncrement(v12);
    }
    v16 = (int)(v11 - 10);
    if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) )
    {
      if ( v16 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    }
    result = 1;
  }
  return result;
}

//----- (004F3DD0) --------------------------------------------------------  // acclient.c:287768
void __thiscall ChatInterface::PostInit(ChatInterface *this)
{
  ChatInterface *v1; // esi@1
  UIElement *v2; // eax@8
  int v3; // eax@9
  UIElement *v4; // eax@11
  int v5; // eax@12
  GlobalEventHandler *v6; // eax@14
  GlobalEventHandler *v7; // edi@14
  ClientCommunicationSystem *v8; // eax@16
  ChatInterface *v9; // esi@18

  v1 = this;
  UIElement::PostInit((UIElement *)this);
  UIElement::GetAttribute_Enum((UIElement *)v1, 0x1000007Eu, &v1->m_oldState);
  switch ( v1->m_oldState )
  {
    case 1u:
    case 8u:
      v1->m_chatNewNonVisibleTextIndicator = (UIElement *)-67108865;
      goto LABEL_7;
    case 2u:
      v1->m_chatNewNonVisibleTextIndicator = (UIElement *)4124;
      goto LABEL_7;
    case 3u:
      v1->m_chatNewNonVisibleTextIndicator = (UIElement *)265216;
      goto LABEL_7;
    case 4u:
      v1->m_chatNewNonVisibleTextIndicator = (UIElement *)0x80000;
      goto LABEL_7;
    case 5u:
      v1->m_chatNewNonVisibleTextIndicator = (UIElement *)2013265920;
LABEL_7:
      LODWORD(v1->m_llTextTypeFilter) = 0;
      break;
    default:
      break;
  }
  v2 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000011u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    v3 = 0;
  v1->m_chatEntry = (UIElement_Text *)v3;
  v1->m_chatLog = (UIElement_Text *)UIElement::GetChildRecursive((UIElement *)v1, 0x1000048Cu);
  v4 = UIElement::GetChildRecursive((UIElement *)v1, 0x10000016u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  LODWORD(v1->m_fCurrentOpacity) = v5;
  v6 = GlobalEventHandler::GetGlobalEventHandler();
  v7 = v6;
  if ( v6 )
  {
    v6->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v6, 100022u, (NoticeHandler *)&v1[-1].m_pCCS);
    v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, 5100114u, (NoticeHandler *)&v1[-1].m_pCCS);
    v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, 5100135u, (NoticeHandler *)&v1[-1].m_pCCS);
    v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, 5100142u, (NoticeHandler *)&v1[-1].m_pCCS);
    v7->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v7, (unsigned int)&loc_4DD1F0, (NoticeHandler *)&v1[-1].m_pCCS);
  }
  UIListener::RegisterForGlobalMessage((UIListener *)v1, 1u);
  v8 = ClientCommunicationSystem::GetCommunicationSystem();
  v1->m_LastInputHistoryPos = (unsigned int)v8;
  if ( v8 )
    v8->vfptr->AddRef((Interface *)v8);
  v9 = (ChatInterface *)((char *)v1 - 4);
  ChatInterface::BuildChatColorLookupTable(v9);
  ((void (__thiscall *)(ChatInterface *, unsigned int, unsigned int))v9->vfptr[5].RecvNotice_OpenDialog)(
    v9,
    gmClient::sm_nFontFace,
    gmClient::sm_nFontSize);
  (*(void (__thiscall **)(ChatInterface *))&v9->vfptr[7].gap4[4])(v9);
}

//----- (004F3F60) --------------------------------------------------------  // acclient.c:287844
void __userpurge ChatInterface::OnSetAttribute(ChatInterface *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  BaseProperty *v3; // esi@1
  ChatInterface *v4; // edi@1
  char *v5; // eax@1
  BasePropertyValue *v6; // ecx@3
  BasePropertyValue *v7; // ecx@6

  v3 = _attribute;
  v4 = this;
  UIElement::OnSetAttribute((UIElement *)this, a2, _attribute);
  v5 = (char *)&BaseProperty::GetPropertyName(v3)[-1315861].m_availableProperties.m_reqHash.m_intrusiveTable.m_aInplaceBuckets[2];
  if ( v5 )
  {
    if ( v5 == (char *)1 )
    {
      v6 = v3->m_pcPropertyValue;
      _attribute = (BaseProperty *)1065353216;
      if ( v6 )
        ((void (__stdcall *)(BaseProperty **))v6->vfptr[34].__vecDelDtor)(&_attribute);
      ChatInterface::SetActiveOpacity((ChatInterface *)((char *)v4 - 4), *(float *)&_attribute);
    }
  }
  else
  {
    v7 = v3->m_pcPropertyValue;
    _attribute = (BaseProperty *)1065353216;
    if ( v7 )
      ((void (__stdcall *)(BaseProperty **))v7->vfptr[34].__vecDelDtor)(&_attribute);
    ChatInterface::SetDefaultOpacity((ChatInterface *)((char *)v4 - 4), *(float *)&_attribute);
  }
}

//----- (004F3FE0) --------------------------------------------------------  // acclient.c:287878
PStringBase<unsigned short> *__thiscall PStringBase<unsigned short>::substring(PStringBase<unsigned short> *this, PStringBase<unsigned short> *result, unsigned int first, unsigned int last)
{
  PStringBase<unsigned short> *v4; // esi@1
  PSRefBufferCharData<unsigned short> *v5; // esi@1
  unsigned int v6; // ecx@1
  PSRefBufferCharData<unsigned short> *v7; // eax@2
  PStringBase<unsigned short> *v8; // ebx@2
  char *v9; // esi@2
  unsigned int v10; // eax@3
  PSRefBufferCharData<unsigned short> *v11; // eax@5
  LONG v12; // eax@2
  PStringBase<unsigned short> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v5 = v4->m_charbuffer;
  v6 = *(_DWORD *)&v5[-1].m_data[14] - 1;
  if ( first < v6 )
  {
    v10 = last;
    if ( last >= v6 )
      v10 = *(_DWORD *)&v5[-1].m_data[14] - 2;
    PStringBase<unsigned short>::append_n_chars(&retval, (const unsigned __int16 *)v5 + first, v10 - first + 1);
    v11 = retval.m_charbuffer;
    v8 = result;
    result->m_charbuffer = retval.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v11[-1].m_data[8]);
    v9 = (char *)&retval.m_charbuffer[-1].m_data[6];
    v12 = InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1].m_data[8]);
  }
  else
  {
    v7 = retval.m_charbuffer;
    v8 = result;
    result->m_charbuffer = retval.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v7[-1].m_data[8]);
    v9 = (char *)&retval.m_charbuffer[-1].m_data[6];
    v12 = InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1].m_data[8]);
  }
  if ( !v12 && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  return v8;
}

//----- (004F4080) --------------------------------------------------------  // acclient.c:287924
char __thiscall PStringBaseIter_Common<unsigned short>::FindChar(PStringBaseIter_Common<unsigned short> *this, PStringBase<unsigned short> *s, bool reverse)
{
  PStringBaseIter_Common<unsigned short> *v3; // esi@1
  unsigned int v4; // eax@2
  PStringBaseIter_Common<unsigned short>Vtbl *v5; // edx@3
  int v6; // eax@3
  unsigned __int16 v7; // ax@3
  unsigned __int16 v9; // ax@7
  int v10; // edi@8
  PStringBaseIter_Common<unsigned short>Vtbl *v11; // edx@12
  unsigned int v12; // ST00_4@12
  unsigned __int16 v13; // ax@12
  PStringBaseIter_Const<unsigned short> iter; // [sp+Ch] [bp-10h]@1

  iter.pstring_ptr = s;
  v3 = this;
  iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
  iter.curr = 0;
  iter.mark = 0;
  if ( reverse )
  {
    while ( 1 )
    {
      v4 = v3->curr;
      if ( v4 < 1 )
        break;
      v5 = v3->vfptr;
      v6 = v4 - 1;
      v3->curr = v6;
      iter.curr = 0;
      v7 = v5->IndexToChar(v3, v6);
      if ( PStringBaseIter_Common<unsigned short>::FindChar(
             (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
             v7,
             0) )
        return 1;
    }
    v3->curr = 0;
    return 0;
  }
  v9 = this->vfptr->IndexToChar(this, this->curr);
  if ( !PStringBaseIter_Common<unsigned short>::FindChar((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, v9, 0) )
  {
    while ( 1 )
    {
      v10 = v3->curr + 1;
      v3->curr = v10 <= v3->vfptr->GetStrLen(v3) ? v10 : v3->vfptr->GetStrLen(v3);
      if ( !v3->vfptr->IndexToChar(v3, v3->curr) )
        break;
      v11 = v3->vfptr;
      v12 = v3->curr;
      iter.curr = 0;
      v13 = v11->IndexToChar(v3, v12);
      if ( PStringBaseIter_Common<unsigned short>::FindChar(
             (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
             v13,
             0) )
        return 1;
    }
    return 0;
  }
  return 1;
}
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

//----- (004F4160) --------------------------------------------------------  // acclient.c:287990
void __thiscall ChatInterface::~ChatInterface(ChatInterface *this)
{
  ChatInterface *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1
  unsigned int v4; // ecx@3
  PStringBase<char> *v5; // ecx@6

  v1 = this;
  v2 = (NoticeHandler *)&this[-1].m_pCCS;
  this[-1].m_pCCS = (ClientCommunicationSystem *)&ChatInterface::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ChatInterface::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)this, 1u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v4 = v1->m_LastInputHistoryPos;
  if ( v4 )
  {
    (*(void (**)(void))(*(_DWORD *)v4 + 20))();
    v1->m_LastInputHistoryPos = 0;
  }
  if ( ((unsigned int)v1->m_InputHistory.m_data & 0x80000000) == 0x80000000 )
  {
    v5 = (PStringBase<char> *)v1->m_pChatTargetButtonText;
    if ( v5 )
      PStringBase<unsigned short>::vector_deleting_destructor(v5, 3u);
  }
  UIElement_Field::~UIElement_Field((UIElement_Field *)(v1 != (ChatInterface *)4 ? (unsigned int)v1 : 0));
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4838: using guessed type int (__stdcall *ChatInterface::vftable)(char);
// 7C4970: using guessed type bool (__thiscall *ChatInterface::vftable)(DBCache *this);

//----- (004F41F0) --------------------------------------------------------  // acclient.c:288027
void __thiscall ChatInterface::StartTell(ChatInterface *this, PStringBase<unsigned short> *i_strName)
{
  ChatInterface *v2; // esi@1
  PStringBase<unsigned short> *v3; // esi@1

  v2 = this;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&i_strName,
    0,
    L"@tell %s, ",
    i_strName->m_charbuffer);
  ((void (*)(void))v2->m_chatEntry->vfptr[21].__vecDelDtor)();
  ((void (*)(void))v2->m_chatEntry->vfptr[21].OnLoseFocus)();
  CM_UI::SendNotice_ToggleChatEntry(1);
  UIElement_Text::SetText(v2->m_chatEntry, (PStringBase<unsigned short> *)&i_strName);
  UIElement_Text::MoveCursorToPosition(v2->m_chatEntry, (int)i_strName[-1].m_charbuffer);
  UIElement_Text::ClearSelection(v2->m_chatEntry);
  v3 = i_strName - 5;
  if ( !InterlockedDecrement((volatile LONG *)&i_strName[-4]) )
  {
    if ( v3 )
      (*(void (__thiscall **)(_DWORD, _DWORD))&v3->m_charbuffer->m_data[0])(v3, 1);
  }
}

//----- (004F4290) --------------------------------------------------------  // acclient.c:288053
void __thiscall ChatInterface::TruncateChatLog(ChatInterface *this, unsigned int i_uiNewLength)
{
  UIElement_Text *v2; // ecx@1
  int v3; // eax@2
  int v4; // eax@3
  unsigned int v5; // edi@3
  char v6; // bl@5
  unsigned int v7; // esi@5
  unsigned int v8; // ecx@9
  char v9; // al@13
  unsigned int v10; // esi@13
  char v11; // bl@13
  char *v12; // esi@18
  char *v13; // esi@21
  PStringBase<unsigned short> strLog; // [sp+Ch] [bp-18h]@2
  ChatInterface *v15; // [sp+10h] [bp-14h]@1
  PStringBaseIter<unsigned short> iter; // [sp+14h] [bp-10h]@3

  v15 = this;
  v2 = this->m_chatLog;
  if ( v2 )
  {
    UIElement_Text::GetText(v2, &strLog);
    v3 = *(_DWORD *)&strLog.m_charbuffer[-1].m_data[14];
    if ( v3 <= i_uiNewLength )
    {
      v13 = (char *)&strLog.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strLog.m_charbuffer[-1].m_data[8]) && v13 )
        (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    }
    else
    {
      v4 = v3 - i_uiNewLength;
      v5 = v4;
      iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
      iter.pstring_ptr = &strLog;
      iter.mark = 0;
      iter.curr = 0;
      if ( v4 )
        PStringBaseIter_Common<unsigned short>::Next((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, v4);
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_uiNewLength, L"\n");
      v6 = PStringBaseIter_Common<unsigned short>::FindChar(
             (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
             (PStringBase<unsigned short> *)&i_uiNewLength,
             1);
      v7 = i_uiNewLength - 20;
      if ( !InterlockedDecrement((volatile LONG *)(i_uiNewLength - 20 + 4)) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      if ( v6 )
      {
        v8 = iter.curr;
        if ( v5 - iter.curr < *(_DWORD *)&strLog.m_charbuffer[-1].m_data[14] / 0xAu )
          goto LABEL_26;
      }
      iter.curr = 0;
      if ( v5 )
        PStringBaseIter_Common<unsigned short>::Next((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, v5);
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_uiNewLength, L"\n");
      v9 = PStringBaseIter_Common<unsigned short>::FindChar(
             (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
             (PStringBase<unsigned short> *)&i_uiNewLength,
             0);
      v10 = i_uiNewLength - 20;
      v11 = v9;
      if ( !InterlockedDecrement((volatile LONG *)(i_uiNewLength - 20 + 4)) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      if ( v11 && (v8 = iter.curr, iter.curr - v5 < *(_DWORD *)&strLog.m_charbuffer[-1].m_data[14] / 0xAu) )
      {
LABEL_26:
        UIElement_Text::BeheadText(v15->m_chatLog, v8 + 1, 1);
        iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strLog);
      }
      else
      {
        UIElement_Text::BeheadText(v15->m_chatLog, v5, 1);
        v12 = (char *)&strLog.m_charbuffer[-1].m_data[6];
        iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
        if ( !InterlockedDecrement((volatile LONG *)&strLog.m_charbuffer[-1].m_data[8]) )
        {
          if ( v12 )
            (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
        }
      }
    }
  }
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

//----- (004F4460) --------------------------------------------------------  // acclient.c:288144
void __thiscall ChatInterface::RecvNotice_FontSettingsChanged(ChatInterface *this, unsigned int i_nFontFace, unsigned int i_nFontSize)
{
  unsigned int v3; // ebx@1
  ChatInterface *v4; // ebp@1
  unsigned int v5; // esi@2
  int v6; // edi@3
  int v7; // eax@6
  int v8; // esi@6
  unsigned int v9; // esi@8
  unsigned int nFontEnumValue; // [sp+8h] [bp-4h]@4

  v3 = i_nFontFace;
  v4 = this;
  if ( i_nFontFace <= 5 )
  {
    v5 = i_nFontSize;
    if ( i_nFontSize <= 5 )
    {
      v6 = DBObj::GetByEnum(268435457, 2, 0x26u);
      if ( v6 )
      {
        PStringBase<char>::PStringBase<char>(
          (PStringBase<char> *)&i_nFontSize,
          0,
          "Chat_%s_%s",
          *(&UI_ChatFontFace_Choices_2 + v3),
          *(&UI_ChatFontSize_Choices_2 + v5));
        if ( EnumIDMap::NameToEnum((EnumIDMap *)v6, (PStringBase<char> *)&i_nFontSize, &nFontEnumValue) )
        {
          if ( (unsigned __int8)EnumIDMap::EnumToDID(
                                  (EnumIDMap *)v6,
                                  nFontEnumValue,
                                  (IDClass<_tagDataID,32,0> *)&i_nFontFace) )
          {
            v7 = Font::Get((IDClass<_tagDataID,32,0>)i_nFontFace);
            v8 = v7;
            if ( v7 )
            {
              UIElement_Text::ChangeExistingTextToNewFont(v4->m_chatLog, (Font *)v7);
              UIElement_Text::SetFontDIDWithoutChangingExistingText(
                v4->m_chatLog,
                (IDClass<_tagDataID,32,0>)i_nFontFace);
              (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
            }
          }
        }
        v9 = i_nFontSize - 20;
        if ( !InterlockedDecrement((volatile LONG *)(i_nFontSize - 20 + 4)) )
        {
          if ( v9 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        }
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
      }
    }
  }
}

//----- (004F4550) --------------------------------------------------------  // acclient.c:288203
void __thiscall ChatInterface::ChatInterface(ChatInterface *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  ChatInterface *v3; // esi@1
  char *v4; // edi@1
  int v5; // edx@1

  v3 = this;
  v4 = (char *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, (int)&this->vfptr, _layout, _full_desc);
  v3->m_eWindowID = 0;
  v3->m_chatEntry = 0;
  v3->m_chatLog = 0;
  v3->m_chatNewNonVisibleTextIndicator = 0;
  v3->m_pChatTargetButtonText = 0;
  v3->vfptr = (NoticeHandlerVtbl *)&ChatInterface::vftable;
  *(_DWORD *)v4 = &ChatInterface::vftable;
  LODWORD(v3->m_fDefaultOpacity) = 1056964608;
  LODWORD(v3->m_fCurrentOpacity) = 1056964608;
  LODWORD(v3->m_fActiveOpacity) = 1065353216;
  LODWORD(v3->m_llTextTypeFilter) = -1;
  HIDWORD(v3->m_llTextTypeFilter) = -1;
  v3->m_InputHistory.m_data = 0;
  v3->m_InputHistory.m_sizeAndDeallocate = 0;
  v3->m_InputHistory.m_num = 0;
  v3->m_pCCS = 0;
  v3->m_LastInputHistoryPos = -1;
  v5 = HIDWORD(v3->m_llTextTypeFilter);
  LODWORD(v3->m_llTextTypeFilter) &= 0xFBFFFFFF;
  HIDWORD(v3->m_llTextTypeFilter) = v5;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4838: using guessed type int (__stdcall *ChatInterface::vftable)(char);
// 7C4970: using guessed type bool (__thiscall *ChatInterface::vftable)(DBCache *this);

//----- (004F4610) --------------------------------------------------------  // acclient.c:288239
int __thiscall ChatInterface::scalar_deleting_destructor(ChatInterface *this, char a2)
{
  ChatInterface *v2; // esi@1
  int result; // eax@1

  v2 = this;
  ChatInterface::~ChatInterface(this);
  result = (int)&v2[-1].m_pCCS;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_pCCS);
    result = (int)&v2[-1].m_pCCS;
  }
  return result;
}

//----- (004F4640) --------------------------------------------------------  // acclient.c:288256
void __thiscall ChatInterface::RecvNotice_DisplayFinalStringInfo(ChatInterface *this, unsigned int i_type, StringInfo *i_siMsg, StringInfo *i_siPrefix, unsigned int i_idDestinationOverride)
{
  ChatInterface *v5; // esi@1
  unsigned int v6; // edi@5
  bool v7; // bl@8

  v5 = this;
  if ( i_idDestinationOverride == this->m_eWindowID
    || !i_idDestinationOverride && (unsigned __int8)ChatInterface::TypeIsActive(this, i_type) )
  {
    if ( v5->m_chatLog->m_glyphList.m_glyphList._num_elements )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&i_idDestinationOverride,
        L"\n");
      UIElement_Text::AppendTextWithFont(
        v5->m_chatLog,
        (PStringBase<unsigned short> *)&i_idDestinationOverride,
        0,
        i_type);
      v6 = i_idDestinationOverride - 20;
      if ( !InterlockedDecrement((volatile LONG *)(i_idDestinationOverride - 20 + 4)) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
    }
    v7 = UIElement_Text::IsAtVerticalEnd(v5->m_chatLog);
    if ( StringInfo::IsValid(i_siPrefix, 1) )
      UIElement_Text::AppendStringInfoWithFont(v5->m_chatLog, i_siPrefix, 0, 12);
    UIElement_Text::AppendStringInfoWithFont(v5->m_chatLog, i_siMsg, 0, i_type);
    if ( v5->m_chatLog->m_glyphList.m_glyphList._num_elements > 0x2710 )
      ChatInterface::TruncateChatLog(v5, 0x1D4Cu);
    if ( v7 )
      UIElement_Text::ScrollToPosition(v5->m_chatLog, v5->m_chatLog->m_glyphList.m_glyphList._num_elements);
    else
      ((void (__stdcall *)(signed int))v5->m_chatNewNonVisibleTextIndicator->vfptr[13].__vecDelDtor)(1);
  }
}

//----- (004F4760) --------------------------------------------------------  // acclient.c:288297
bool __thiscall ChatInterface::SetReplyTextInChatBox(ChatInterface *this)
{
  ChatInterface *v1; // ebp@1
  bool v2; // bl@1
  char *v3; // esi@1
  PStringBase<unsigned short> v4; // ST18_4@5
  int v5; // ecx@5
  PSRefBufferCharData<unsigned short> *v6; // edx@5
  bool v7; // zf@8
  PSRefBufferCharData<unsigned short> *v8; // ecx@8
  char *v9; // esi@11
  PSRefBufferCharData<unsigned short> **v11; // ebx@14
  char *v12; // esi@15
  char *v13; // esi@19
  const wchar_t **v14; // eax@22
  int v15; // eax@22
  char *v16; // esi@22
  bool v17; // bl@22
  char *v18; // esi@25
  const wchar_t **v19; // eax@32
  int v20; // eax@32
  char *v21; // esi@32
  bool v22; // bl@32
  char *v23; // esi@35
  const wchar_t **v24; // eax@42
  int v25; // eax@42
  char *v26; // esi@42
  bool v27; // bl@42
  char *v28; // esi@45
  PStringBase<char> *v29; // eax@50
  char *v30; // esi@50
  ChatInterface *v31; // esi@54
  char *v32; // esi@55
  char *v33; // esi@58
  PStringBase<unsigned short> curText; // [sp+2Ch] [bp-24h]@5
  PStringBase<unsigned short> strNewText; // [sp+30h] [bp-20h]@50
  PStringBase<char> result; // [sp+34h] [bp-1Ch]@1
  PStringBase<unsigned short> v37; // [sp+38h] [bp-18h]@22
  ChatInterface *v38; // [sp+3Ch] [bp-14h]@1
  PStringBaseIter<unsigned short> iter; // [sp+40h] [bp-10h]@22

  v1 = this;
  v38 = this;
  v2 = *(_DWORD *)&gmCCommunicationSystem::GetLastTellerName(&result)->m_charbuffer[-1].m_data[12] == 1;
  v3 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  if ( v2 )
    return 0;
  UIElement_Text::GetText(v1->m_chatEntry, &curText);
  v4.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::whitespace_string;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4);
  PStringBase<unsigned short>::trim(&curText, 1, 0, v4);
  v5 = *(_DWORD *)&curText.m_charbuffer[-1].m_data[14];
  v6 = (PSRefBufferCharData<unsigned short> *)((char *)curText.m_charbuffer + 2 * v5 - 2);
  if ( v5 )
    v6 = curText.m_charbuffer;
  if ( v6->m_data[0] != 47 )
  {
    v7 = v5 == 0;
    v8 = (PSRefBufferCharData<unsigned short> *)((char *)curText.m_charbuffer + 2 * v5 - 2);
    if ( !v7 )
      v8 = curText.m_charbuffer;
    if ( v8->m_data[0] != 64 )
    {
      v9 = (char *)&curText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) && v9 )
      {
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
        return 0;
      }
      return 0;
    }
  }
  v11 = (PSRefBufferCharData<unsigned short> **)PStringBase<unsigned short>::substring(
                                                  &curText,
                                                  (PStringBase<unsigned short> *)&result,
                                                  1u,
                                                  *(_DWORD *)&curText.m_charbuffer[-1].m_data[14]);
  if ( curText.m_charbuffer != *v11 )
  {
    v12 = (char *)&curText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    curText.m_charbuffer = *v11;
    InterlockedIncrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]);
  }
  v13 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
  iter.pstring_ptr = &curText;
  iter.curr = 0;
  iter.mark = 0;
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&result, L"r ");
  v14 = (const wchar_t **)PStringBase<unsigned short>::substring(&curText, &v37, 0, 1u);
  v15 = __wcsicmp(*v14, (const wchar_t *)result.m_charbuffer);
  v16 = (char *)&v37.m_charbuffer[-1].m_data[6];
  v17 = v15 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v37.m_charbuffer[-1].m_data[8]) && v16 )
    (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  v18 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v18 )
    (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
  if ( v17 )
  {
    if ( (unsigned int)iter.vfptr->GetStrLen(&iter) >= 1 )
      iter.mark = 1;
    else
      iter.mark = iter.vfptr->GetStrLen(&iter);
  }
  else
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&result, L"rp ");
    v19 = (const wchar_t **)PStringBase<unsigned short>::substring(&curText, &v37, 0, 2u);
    v20 = __wcsicmp(*v19, (const wchar_t *)result.m_charbuffer);
    v21 = (char *)&v37.m_charbuffer[-1].m_data[6];
    v22 = v20 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v37.m_charbuffer[-1].m_data[8]) && v21 )
      (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
    v23 = &result.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v23 )
      (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
    if ( v22 )
    {
      if ( (unsigned int)iter.vfptr->GetStrLen(&iter) >= 2 )
        iter.mark = 2;
      else
        iter.mark = iter.vfptr->GetStrLen(&iter);
    }
    else
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&result, L"reply ");
      v24 = (const wchar_t **)PStringBase<unsigned short>::substring(&curText, &v37, 0, 5u);
      v25 = __wcsicmp(*v24, (const wchar_t *)result.m_charbuffer);
      v26 = (char *)&v37.m_charbuffer[-1].m_data[6];
      v27 = v25 == 0;
      if ( !InterlockedDecrement((volatile LONG *)&v37.m_charbuffer[-1].m_data[8]) && v26 )
        (**(void (__thiscall ***)(char *, signed int))v26)(v26, 1);
      v28 = &result.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v28 )
        (**(void (__thiscall ***)(char *, signed int))v28)(v28, 1);
      if ( !v27 )
      {
        iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&curText);
        return 0;
      }
      PStringBaseIter_Common<unsigned short>::SetMark((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, 5u);
    }
  }
  v29 = gmCCommunicationSystem::GetLastTellerName((PStringBase<char> *)&v37);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&strNewText, 0, L"@tell %hs,", v29->m_charbuffer);
  v30 = (char *)&v37.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v37.m_charbuffer[-1].m_data[8]) && v30 )
    (**(void (__thiscall ***)(char *, signed int))v30)(v30, 1);
  if ( PStringBaseIter<unsigned short>::Replace(&iter, &strNewText) )
  {
    v31 = v38;
    UIElement_Text::SetText(v38->m_chatEntry, &curText);
    UIElement_Text::MoveCursorToPosition(v31->m_chatEntry, *(_DWORD *)&strNewText.m_charbuffer[-1].m_data[14]);
    UIElement_Text::ClearSelection(v31->m_chatEntry);
  }
  v32 = (char *)&strNewText.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strNewText.m_charbuffer[-1].m_data[8]) && v32 )
    (**(void (__thiscall ***)(char *, signed int))v32)(v32, 1);
  v33 = (char *)&curText.m_charbuffer[-1].m_data[6];
  iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) && v33 )
  {
    (**(void (__thiscall ***)(char *, signed int))v33)(v33, 1);
    return 0;
  }
  return 0;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

//----- (004F4B70) --------------------------------------------------------  // acclient.c:288476
bool __thiscall ChatInterface::SetMonarchReplyTextInChatBox(ChatInterface *this)
{
  ChatInterface *v1; // ebp@1
  bool v2; // bl@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  PStringBase<unsigned short> v4; // ST10_4@5
  int v5; // ecx@5
  PSRefBufferCharData<unsigned short> *v6; // edx@5
  PSRefBufferCharData<unsigned short> *v7; // ecx@8
  char *v8; // esi@11
  bool v9; // zf@12
  PSRefBufferCharData<unsigned short> **v10; // ebx@13
  char *v11; // esi@14
  char *v12; // esi@18
  const wchar_t **v13; // eax@21
  int v14; // eax@21
  char *v15; // esi@21
  bool v16; // bl@21
  char *v17; // esi@24
  AC1Legacy::PStringBase<char> *v18; // eax@31
  PSRefBufferCharData<unsigned short> *v19; // esi@31
  ChatInterface *v20; // esi@35
  char *v21; // esi@36
  PStringBase<unsigned short> curText; // [sp+1Ch] [bp-24h]@5
  PStringBase<unsigned short> strNewText; // [sp+20h] [bp-20h]@31
  AC1Legacy::PStringBase<char> result; // [sp+24h] [bp-1Ch]@1
  PStringBase<unsigned short> v26; // [sp+28h] [bp-18h]@21
  ChatInterface *v27; // [sp+2Ch] [bp-14h]@1
  PStringBaseIter<unsigned short> iter; // [sp+30h] [bp-10h]@21

  v1 = this;
  v27 = this;
  v2 = gmCCommunicationSystem::GetLastAtMonarchUserName(&result)->m_buffer->m_len == 1;
  v3 = result.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  if ( !v2 )
  {
    UIElement_Text::GetText(v1->m_chatEntry, &curText);
    v4.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::whitespace_string;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4);
    PStringBase<unsigned short>::trim(&curText, 1, 0, v4);
    v5 = *(_DWORD *)&curText.m_charbuffer[-1].m_data[14];
    v6 = (PSRefBufferCharData<unsigned short> *)((char *)curText.m_charbuffer + 2 * v5 - 2);
    if ( v5 )
      v6 = curText.m_charbuffer;
    if ( v6->m_data[0] != 47 )
    {
      v9 = v5 == 0;
      v7 = (PSRefBufferCharData<unsigned short> *)((char *)curText.m_charbuffer + 2 * v5 - 2);
      if ( !v9 )
        v7 = curText.m_charbuffer;
      if ( v7->m_data[0] != 64 )
      {
        v8 = (char *)&curText.m_charbuffer[-1].m_data[6];
        if ( InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) )
          return 0;
        v9 = v8 == 0;
        goto LABEL_41;
      }
    }
    v10 = (PSRefBufferCharData<unsigned short> **)PStringBase<unsigned short>::substring(
                                                    &curText,
                                                    (PStringBase<unsigned short> *)&result,
                                                    1u,
                                                    *(_DWORD *)&curText.m_charbuffer[-1].m_data[14]);
    if ( curText.m_charbuffer != *v10 )
    {
      v11 = (char *)&curText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) && v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
      curText.m_charbuffer = *v10;
      InterlockedIncrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]);
    }
    v12 = (char *)&result.m_buffer[-1].m_cRef;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer[-1].m_cRef + 1) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
    iter.pstring_ptr = &curText;
    iter.curr = 0;
    iter.mark = 0;
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&result, L"mr ");
    v13 = (const wchar_t **)PStringBase<unsigned short>::substring(&curText, &v26, 0, 2u);
    v14 = __wcsicmp(*v13, (const wchar_t *)result.m_buffer);
    v15 = (char *)&v26.m_charbuffer[-1].m_data[6];
    v16 = v14 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v26.m_charbuffer[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
    v17 = (char *)&result.m_buffer[-1].m_cRef;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer[-1].m_cRef + 1) && v17 )
      (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
    if ( v16 )
    {
      if ( (unsigned int)iter.vfptr->GetStrLen(&iter) >= 2 )
        iter.mark = 2;
      else
        iter.mark = iter.vfptr->GetStrLen(&iter);
      v18 = gmCCommunicationSystem::GetLastAtMonarchUserName((AC1Legacy::PStringBase<char> *)&v26);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&strNewText, 0, L"@tell %hs,", v18->m_buffer->m_data);
      v19 = v26.m_charbuffer;
      if ( !InterlockedDecrement((volatile LONG *)&v26.m_charbuffer->m_data[2]) && v19 )
        (**(void (__thiscall ***)(PSRefBufferCharData<unsigned short> *, signed int))&v19->m_data[0])(v19, 1);
      if ( PStringBaseIter<unsigned short>::Replace(&iter, &strNewText) )
      {
        v20 = v27;
        UIElement_Text::SetText(v27->m_chatEntry, &curText);
        UIElement_Text::MoveCursorToPosition(v20->m_chatEntry, *(_DWORD *)&strNewText.m_charbuffer[-1].m_data[14]);
        UIElement_Text::ClearSelection(v20->m_chatEntry);
      }
      v21 = (char *)&strNewText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strNewText.m_charbuffer[-1].m_data[8]) && v21 )
        (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
    }
    v8 = (char *)&curText.m_charbuffer[-1].m_data[6];
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) )
    {
      v9 = v8 == 0;
LABEL_41:
      if ( !v9 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      return 0;
    }
  }
  return 0;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

//----- (004F4E20) --------------------------------------------------------  // acclient.c:288606
bool __thiscall ChatInterface::SetPatronReplyTextInChatBox(ChatInterface *this)
{
  ChatInterface *v1; // ebp@1
  bool v2; // bl@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  PStringBase<unsigned short> v4; // ST10_4@5
  int v5; // ecx@5
  PSRefBufferCharData<unsigned short> *v6; // edx@5
  PSRefBufferCharData<unsigned short> *v7; // ecx@8
  char *v8; // esi@11
  bool v9; // zf@12
  PSRefBufferCharData<unsigned short> **v10; // ebx@13
  char *v11; // esi@14
  char *v12; // esi@18
  const wchar_t **v13; // eax@21
  int v14; // eax@21
  char *v15; // esi@21
  bool v16; // bl@21
  char *v17; // esi@24
  AC1Legacy::PStringBase<char> *v18; // eax@31
  PSRefBufferCharData<unsigned short> *v19; // esi@31
  ChatInterface *v20; // esi@35
  char *v21; // esi@36
  PStringBase<unsigned short> curText; // [sp+1Ch] [bp-24h]@5
  PStringBase<unsigned short> strNewText; // [sp+20h] [bp-20h]@31
  AC1Legacy::PStringBase<char> result; // [sp+24h] [bp-1Ch]@1
  PStringBase<unsigned short> v26; // [sp+28h] [bp-18h]@21
  ChatInterface *v27; // [sp+2Ch] [bp-14h]@1
  PStringBaseIter<unsigned short> iter; // [sp+30h] [bp-10h]@21

  v1 = this;
  v27 = this;
  v2 = gmCCommunicationSystem::GetLastAtPatronUserName(&result)->m_buffer->m_len == 1;
  v3 = result.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  if ( !v2 )
  {
    UIElement_Text::GetText(v1->m_chatEntry, &curText);
    v4.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::whitespace_string;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::whitespace_string - 4);
    PStringBase<unsigned short>::trim(&curText, 1, 0, v4);
    v5 = *(_DWORD *)&curText.m_charbuffer[-1].m_data[14];
    v6 = (PSRefBufferCharData<unsigned short> *)((char *)curText.m_charbuffer + 2 * v5 - 2);
    if ( v5 )
      v6 = curText.m_charbuffer;
    if ( v6->m_data[0] != 47 )
    {
      v9 = v5 == 0;
      v7 = (PSRefBufferCharData<unsigned short> *)((char *)curText.m_charbuffer + 2 * v5 - 2);
      if ( !v9 )
        v7 = curText.m_charbuffer;
      if ( v7->m_data[0] != 64 )
      {
        v8 = (char *)&curText.m_charbuffer[-1].m_data[6];
        if ( InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) )
          return 0;
        v9 = v8 == 0;
        goto LABEL_41;
      }
    }
    v10 = (PSRefBufferCharData<unsigned short> **)PStringBase<unsigned short>::substring(
                                                    &curText,
                                                    (PStringBase<unsigned short> *)&result,
                                                    1u,
                                                    *(_DWORD *)&curText.m_charbuffer[-1].m_data[14]);
    if ( curText.m_charbuffer != *v10 )
    {
      v11 = (char *)&curText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) && v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
      curText.m_charbuffer = *v10;
      InterlockedIncrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]);
    }
    v12 = (char *)&result.m_buffer[-1].m_cRef;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer[-1].m_cRef + 1) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
    iter.pstring_ptr = &curText;
    iter.curr = 0;
    iter.mark = 0;
    PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&result, L"pr ");
    v13 = (const wchar_t **)PStringBase<unsigned short>::substring(&curText, &v26, 0, 2u);
    v14 = __wcsicmp(*v13, (const wchar_t *)result.m_buffer);
    v15 = (char *)&v26.m_charbuffer[-1].m_data[6];
    v16 = v14 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v26.m_charbuffer[-1].m_data[8]) && v15 )
      (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
    v17 = (char *)&result.m_buffer[-1].m_cRef;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer[-1].m_cRef + 1) && v17 )
      (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
    if ( v16 )
    {
      if ( (unsigned int)iter.vfptr->GetStrLen(&iter) >= 2 )
        iter.mark = 2;
      else
        iter.mark = iter.vfptr->GetStrLen(&iter);
      v18 = gmCCommunicationSystem::GetLastAtPatronUserName((AC1Legacy::PStringBase<char> *)&v26);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&strNewText, 0, L"@tell %hs,", v18->m_buffer->m_data);
      v19 = v26.m_charbuffer;
      if ( !InterlockedDecrement((volatile LONG *)&v26.m_charbuffer->m_data[2]) && v19 )
        (**(void (__thiscall ***)(PSRefBufferCharData<unsigned short> *, signed int))&v19->m_data[0])(v19, 1);
      if ( PStringBaseIter<unsigned short>::Replace(&iter, &strNewText) )
      {
        v20 = v27;
        UIElement_Text::SetText(v27->m_chatEntry, &curText);
        UIElement_Text::MoveCursorToPosition(v20->m_chatEntry, *(_DWORD *)&strNewText.m_charbuffer[-1].m_data[14]);
        UIElement_Text::ClearSelection(v20->m_chatEntry);
      }
      v21 = (char *)&strNewText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strNewText.m_charbuffer[-1].m_data[8]) && v21 )
        (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
    }
    v8 = (char *)&curText.m_charbuffer[-1].m_data[6];
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&curText.m_charbuffer[-1].m_data[8]) )
    {
      v9 = v8 == 0;
LABEL_41:
      if ( !v9 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      return 0;
    }
  }
  return 0;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

//----- (004F50D0) --------------------------------------------------------  // acclient.c:288736
void __thiscall ChatInterface::HandleTextReplacements(ChatInterface *this)
{
  ChatInterface *v1; // esi@1

  v1 = this;
  if ( this->m_chatEntry
    && !ChatInterface::SetReplyTextInChatBox(this)
    && !ChatInterface::SetMonarchReplyTextInChatBox(v1) )
    ChatInterface::SetPatronReplyTextInChatBox(v1);
}

//----- (004F5100) --------------------------------------------------------  // acclient.c:288748
void __thiscall ChatInterface::ProcessCommand(ChatInterface *this)
{
  ChatInterface *v1; // esi@1
  UIElement_Text *v2; // ecx@1
  char *v3; // esi@3
  LONG v4; // eax@3
  ClientCommunicationSystem *v5; // ecx@4
  bool v6; // cf@6
  bool v7; // zf@6
  PStringBase<unsigned short> text; // [sp+0h] [bp-4h]@1

  text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  v2 = this->m_chatEntry;
  if ( v2 )
  {
    UIElement_Text::GetPreParsedText(v2, &text);
    if ( *(_DWORD *)&text.m_charbuffer[-1].m_data[14] == 1 )
    {
      v3 = (char *)&text.m_charbuffer[-1].m_data[6];
      v4 = InterlockedDecrement((volatile LONG *)&text.m_charbuffer[-1].m_data[8]);
    }
    else
    {
      v5 = v1->m_pCCS;
      if ( v5 )
        ClientCommunicationSystem::OnChatCommand(v5, &text, v1->m_eWindowID);
      SmartArray<PStringBase<unsigned short>,1>::AddToEnd(
        (SmartArray<PStringBase<unsigned short>,1> *)&v1->m_InputHistory.m_data,
        &text);
      v6 = v1->m_InputHistory.m_num < 0x64;
      v7 = v1->m_InputHistory.m_num == 100;
      v1->m_LastInputHistoryPos = -1;
      if ( !v6 && !v7 )
      {
        do
          SmartArray<PStringBase<unsigned short>,1>::RemoveOrderedByIndex(
            (SmartArray<PStringBase<unsigned short>,1> *)&v1->m_InputHistory.m_data,
            0);
        while ( v1->m_InputHistory.m_num > 0x64 );
      }
      UIElement_Text::ClearAllText(v1->m_chatEntry);
      v3 = (char *)&text.m_charbuffer[-1].m_data[6];
      v4 = InterlockedDecrement((volatile LONG *)&text.m_charbuffer[-1].m_data[8]);
    }
    if ( !v4 )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
}

//----- (004F51C0) --------------------------------------------------------  // acclient.c:288802
UIElementMessageListenResult __thiscall ChatInterface::ListenToElementMessage(ChatInterface *this, UIElementMessageInfo *i_rMsg)
{
  ChatInterface *v2; // esi@1
  UIElement_Text *v3; // ecx@4
  UIElementMessageListenResult result; // eax@5

  v2 = this;
  switch ( i_rMsg->idMessage )
  {
    case 1u:
      if ( i_rMsg->idElement == 268435481 )
      {
        ChatInterface::ProcessCommand((ChatInterface *)((char *)this - 4));
        result = UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
      }
      else
      {
        if ( i_rMsg->idElement != 268436620 )
          return UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
        v3 = this->m_chatEntry;
        if ( !v3 )
          return UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
        UIElement_Text::ScrollToPosition(v3, v3->m_glyphList.m_glyphList._num_elements);
        ((void (__stdcall *)(signed int))v2->m_chatLog->vfptr[13].__vecDelDtor)(13);
        result = UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
      }
      return result;
    case 0x12u:
      if ( i_rMsg->pElement != LODWORD(this->m_fCurrentOpacity) || LOWORD(i_rMsg->dwParam1) != 32 )
        return UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
      ChatInterface::HandleTextReplacements((ChatInterface *)((char *)this - 4));
      return UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
    case 0x29u:
    case 0x2Au:
    case 0x2Fu:
      if ( i_rMsg->pElement != LODWORD(this->m_fCurrentOpacity) )
        return UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
      goto $L177049;
    case 0x1Bu:
    case 0x1Fu:
$L177049:
      UIListener::RegisterForGlobalMessage((UIListener *)this, 3u);
      break;
    default:
      return UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
  }
  return UIElement::ListenToElementMessage((UIElement *)v2, i_rMsg);
}

//----- (004F52D0) --------------------------------------------------------  // acclient.c:288852
void __thiscall ChatInterface::HandleEnterKey(ChatInterface *this)
{
  UIElement *v1; // edi@1
  ChatInterface *v2; // esi@1
  CPlayerSystem *v3; // eax@4

  v1 = UIElementManager::s_pInstance->m_activeElement;
  v2 = this;
  if ( v1
    && v1 == UIElement::GetRootElement((UIElement *)&this->vfptr)
    && (UIElement_Text *)UIElement::GetFocusDescendant(v1) == v2->m_chatEntry )
  {
    v3 = CPlayerSystem::GetPlayerSystem();
    if ( !(unsigned __int8)PlayerModule::StayInChatMode((PlayerModule *)&v3->playerModule.vfptr) )
    {
      ((void (*)(void))v2->m_chatEntry->vfptr[22].__vecDelDtor)();
      ((void (*)(void))v2->m_chatEntry->vfptr[21].OnAction)();
      CM_UI::SendNotice_ToggleChatEntry(0);
    }
    ChatInterface::ProcessCommand(v2);
  }
}

//----- (004F5350) --------------------------------------------------------  // acclient.c:288876
void __thiscall ChatInterface::HandleReplyKey(ChatInterface *this, unsigned int i_inputAction)
{
  ChatInterface *v2; // ebx@1
  PStringBase<unsigned short> v3; // esi@1
  PStringBase<char> *v4; // eax@4
  const unsigned __int16 *v5; // eax@4
  char *v6; // esi@4
  AC1Legacy::PSRefBuffer<char> *v7; // esi@7
  AC1Legacy::PStringBase<char> *v8; // eax@8
  const unsigned __int16 *v9; // eax@8
  char *v10; // esi@8
  AC1Legacy::PStringBase<char> *v11; // eax@12
  const unsigned __int16 *v12; // eax@12
  char *v13; // esi@12
  LONG v14; // eax@7
  int v15; // esi@25
  PStringBase<unsigned short> strTarget; // [sp+10h] [bp-13Ch]@1
  AC1Legacy::PStringBase<char> v17; // [sp+14h] [bp-138h]@8
  PStringBase<unsigned short> v18; // [sp+18h] [bp-134h]@12
  PStringBase<char> result; // [sp+1Ch] [bp-130h]@4
  AC1Legacy::PStringBase<char> v20; // [sp+20h] [bp-12Ch]@12
  PStringBase<unsigned short> v21; // [sp+24h] [bp-128h]@4
  PStringBase<unsigned short> v22; // [sp+28h] [bp-124h]@8
  StringInfo info; // [sp+2Ch] [bp-120h]@1
  StringInfo siCommandPrefix; // [sp+BCh] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&info);
  StringInfo::SetStringIDandTableEnum(&info, ID_AssistedTell_0, 6);
  StringInfo::StringInfo(&siCommandPrefix);
  StringInfo::SetStringIDandTableEnum(&siCommandPrefix, ID_CmdPrefix_0, 6);
  StringInfo::AddVariable_StringInfo(&info, PREFIX_0, &siCommandPrefix);
  v3.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  strTarget.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( i_inputAction == 268435488 )
  {
    v11 = gmCCommunicationSystem::GetLastAtMonarchUserName(&v20);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v18, 0, v11->m_buffer->m_data);
    PStringBase<unsigned short>::operator=(&strTarget, v12);
    v13 = (char *)&v18.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1].m_data[8]) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    v7 = v20.m_buffer;
    goto LABEL_16;
  }
  if ( i_inputAction == 268435489 )
  {
    v8 = gmCCommunicationSystem::GetLastAtPatronUserName(&v17);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v22, 0, v8->m_buffer->m_data);
    PStringBase<unsigned short>::operator=(&strTarget, v9);
    v10 = (char *)&v22.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v22.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    v7 = v17.m_buffer;
LABEL_16:
    v14 = InterlockedDecrement((volatile LONG *)&v7->m_cRef);
    goto LABEL_17;
  }
  if ( i_inputAction != 268435490 )
    goto LABEL_21;
  v4 = gmCCommunicationSystem::GetLastTellerName(&result);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v21, 0, v4);
  PStringBase<unsigned short>::operator=(&strTarget, v5);
  v6 = (char *)&v21.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v21.m_charbuffer[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  v7 = (AC1Legacy::PSRefBuffer<char> *)&result.m_charbuffer[-2].m_data[12];
  v14 = InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]);
LABEL_17:
  if ( !v14 && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  v3.m_charbuffer = strTarget.m_charbuffer;
LABEL_21:
  if ( *(_DWORD *)&v3.m_charbuffer[-1].m_data[14] != 1 )
  {
    InterlockedIncrement((volatile LONG *)&v3.m_charbuffer[-1].m_data[8]);
    StringInfo::AddVariable_String(&info, TARGET_0, v3);
    if ( StringInfo::IsValid(&info, 1) )
    {
      if ( v2->m_chatEntry )
      {
        ChatInterface::ActivateChatEntry(v2);
        UIElement_Text::SetStringInfo(v2->m_chatEntry, &info);
        UIElement_Text::Deselect(v2->m_chatEntry);
        UIElement_Text::MoveCursorToEnd(v2->m_chatEntry);
      }
    }
  }
  v15 = (int)&v3.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v15 + 4)) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  StringInfo::~StringInfo(&siCommandPrefix);
  StringInfo::~StringInfo(&info);
}

//----- (004F5590) --------------------------------------------------------  // acclient.c:288973
bool __thiscall ChatInterface::OnChildAction(ChatInterface *this, UIElement *i_pChild, InputEvent *i_evt)
{
  bool result; // al@4

  if ( i_evt->m_fStart && i_pChild == LODWORD(this->m_fCurrentOpacity) )
  {
    switch ( i_evt->m_InputAction )
    {
      case 0x25u:
        ChatInterface::HandleEnterKey((ChatInterface *)((char *)this - 4));
        result = 1;
        break;
      case 0x1Cu:
        UIElement_Text::ScrollToPosition(this->m_chatEntry, 0);
        result = 1;
        break;
      case 0x1Du:
        UIElement_Text::ScrollToPosition(this->m_chatEntry, this->m_chatEntry->m_glyphList.m_glyphList._num_elements);
        result = 1;
        break;
      case 0x20u:
        UIElement_Text::ScrollPage(this->m_chatEntry, 1);
        result = 1;
        break;
      case 0x21u:
        UIElement_Text::ScrollPage(this->m_chatEntry, 0);
        result = 1;
        break;
      case 0x1Eu:
        ChatInterface::SelectCommandFromHistory((ChatInterface *)((char *)this - 4), 1);
        result = 1;
        break;
      case 0x1Fu:
        ChatInterface::SelectCommandFromHistory((ChatInterface *)((char *)this - 4), 0);
        result = 1;
        break;
      case 0x27u:
        ChatInterface::DeactivateChatEntry((ChatInterface *)((char *)this - 4));
        result = 1;
        break;
      default:
        goto LABEL_12;
    }
  }
  else
  {
LABEL_12:
    result = UIElement::OnChildAction((UIElement *)this, i_pChild, i_evt);
  }
  return result;
}

//----- (004F5690) --------------------------------------------------------  // acclient.c:289026
char __thiscall ChatInterface::OnAction(ChatInterface *this, InputEvent *i_evt)
{
  ChatInterface *v2; // esi@1
  char result; // al@2
  PStringBase<unsigned short> *v4; // eax@7

  v2 = this;
  switch ( i_evt->m_InputAction )
  {
    case 0x10000024u:
      result = ChatInterface::OnToggleChatEntry((ChatInterface *)((char *)this - 4));
      break;
    case 0x10000028u:
      ChatInterface::HandleCommandOrAliasKey((ChatInterface *)((char *)this - 4), i_evt->m_InputAction);
      result = 1;
      break;
    case 0x10000023u:
      ChatInterface::ActivateChatEntry((ChatInterface *)((char *)this - 4));
      UIElement_Text::SelectAll(LODWORD(v2->m_fCurrentOpacity));
      result = 1;
      break;
    case 0x10000119u:
      if ( (unsigned int)ACCWeenieObject::selectedID >= 0x50000001
        && (unsigned int)ACCWeenieObject::selectedID <= 0x6FFFFFFF )
      {
        v4 = (PStringBase<unsigned short> *)ACCWeenieObject::GetObjectNameWide(
                                              (ACCWeenieObject *)&i_evt,
                                              (PStringBase<unsigned short> *)ACCWeenieObject::selectedID,
                                              2u,
                                              0);
        CM_UI::SendNotice_StartTell(v4);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_evt);
      }
      result = 1;
      break;
    case 0x10000020u:
    case 0x10000021u:
    case 0x10000022u:
      ChatInterface::HandleReplyKey((ChatInterface *)((char *)this - 4), i_evt->m_InputAction);
      result = 1;
      break;
    default:
      result = UIElement::OnAction((UIElement *)this, i_evt);
      break;
  }
  return result;
}

//----- (006F8850) --------------------------------------------------------  // acclient.c:781287
void sub_6F8850()
{
  flt_8410C0 = 1000.0 + 1.0;
}

//----- (006F8870) --------------------------------------------------------  // acclient.c:781293
void sub_6F8870()
{
  flt_8410C4 = 24.0 * 8.0;
}

//----- (006F8890) --------------------------------------------------------  // acclient.c:781299
void sub_6F8890()
{
  flt_8410C8 = 24.0 * 0.5;
}

//----- (006F88B0) --------------------------------------------------------  // acclient.c:781305
int sub_6F88B0()
{
  return atexit(nullsub_711);
}

//----- (006F88C0) --------------------------------------------------------  // acclient.c:781311
int sub_6F88C0()
{
  return atexit(nullsub_712);
}

//----- (006F88D0) --------------------------------------------------------  // acclient.c:781317
int sub_6F88D0()
{
  return atexit(nullsub_713);
}

//----- (006F88E0) --------------------------------------------------------  // acclient.c:781323
void _E106_83()
{
  DEFAULT_VIEW_RADIUS_86 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F8900) --------------------------------------------------------  // acclient.c:781329
void _E108_64()
{
  MIN_QUANTUM_86 = 1.0 / 30.0;
}

//----- (006F8920) --------------------------------------------------------  // acclient.c:781335
void _E110_54()
{
  MAX_QUANTUM_86 = 1.0 / 5.0;
}

//----- (006F8940) --------------------------------------------------------  // acclient.c:781341
void _E112_75()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8410E0, PFID_A8R8G8B8);
}

//----- (006F8950) --------------------------------------------------------  // acclient.c:781347
void _E114_38()
{
  dword_841118 = 1024;
}

//----- (006F8960) --------------------------------------------------------  // acclient.c:781353
void _E116_15()
{
  dword_84111C = 0x7FFF;
}

//----- (006F8970) --------------------------------------------------------  // acclient.c:781359
int _E118_56()
{
  const int result; // eax@1

  result = dword_841118;
  INITIAL_MAX_DATA_RATE_57 = dword_841118;
  return result;
}

//----- (006F8980) --------------------------------------------------------  // acclient.c:781369
int _E121_50()
{
  return atexit(_E122_80);
}

//----- (006F8990) --------------------------------------------------------  // acclient.c:781375
int _E124_53()
{
  PStringBase<char>::PStringBase<char>(&Input_KeymapFile_2, "Input.KeymapFile");
  return atexit(_E125_52);
}

//----- (006F89B0) --------------------------------------------------------  // acclient.c:781382
int _E127_42()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontFace_2, "UI.ChatFontFace");
  return atexit(_E128_51);
}

//----- (006F89D0) --------------------------------------------------------  // acclient.c:781389
int _E130_40()
{
  PStringBase<char>::PStringBase<char>(&UI_ChatFontSize_2, "UI.ChatFontSize");
  return atexit(_E131_43);
}

//----- (006F89F0) --------------------------------------------------------  // acclient.c:781396
int _E133_30()
{
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&UI_ChatFontFace_Choices_2, "Arial");
  PStringBase<char>::PStringBase<char>(&stru_841134, "CourierNew");
  PStringBase<char>::PStringBase<char>(&stru_841138, "PalatinoLinotype");
  PStringBase<char>::PStringBase<char>(&stru_84113C, "Tahoma");
  PStringBase<char>::PStringBase<char>(&stru_841140, "TimesNewRoman");
  return atexit(_E134_33);
}

//----- (006F8A50) --------------------------------------------------------  // acclient.c:781407
int _E136_25()
{
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&UI_ChatFontSize_Choices_2, "Tiny");
  PStringBase<char>::PStringBase<char>(&stru_841148, "Small");
  PStringBase<char>::PStringBase<char>(&stru_84114C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_841150, "Large");
  PStringBase<char>::PStringBase<char>(&stru_841154, "XL");
  return atexit(_E137_32);
}

//----- (006F8AB0) --------------------------------------------------------  // acclient.c:781418
int _E139_24()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_42, "None");
  return atexit(_E140_27);
}

//----- (006F8AD0) --------------------------------------------------------  // acclient.c:781425
int _E142_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_42, "Speed");
  return atexit(_E143_27);
}

//----- (006F8AF0) --------------------------------------------------------  // acclient.c:781432
int _E145_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_42, "Noise");
  return atexit(_E146_28);
}

//----- (006F8B10) --------------------------------------------------------  // acclient.c:781439
int _E148_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_42, "Sine");
  return atexit(_E149_28);
}

//----- (006F8B30) --------------------------------------------------------  // acclient.c:781446
int _E151_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_42, "Square");
  return atexit(_E152_26);
}

//----- (006F8B50) --------------------------------------------------------  // acclient.c:781453
int _E154_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_42, "Bounce");
  return atexit(_E155_23);
}

//----- (006F8B70) --------------------------------------------------------  // acclient.c:781460
int _E157_21()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_42, "Perlin");
  return atexit(_E158_25);
}

//----- (006F8B90) --------------------------------------------------------  // acclient.c:781467
int _E160_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_42, "Fractal");
  return atexit(_E161_23);
}

//----- (006F8BB0) --------------------------------------------------------  // acclient.c:781474
int _E163_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_42, "FrameLoop");
  return atexit(_E164_25);
}

//----- (006F8BD0) --------------------------------------------------------  // acclient.c:781481
int _E166_20()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_44, "Misc.TooltipEnable");
  return atexit(_E167_21);
}

//----- (006F8BF0) --------------------------------------------------------  // acclient.c:781488
int _E169_17()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_44, "Misc.TooltipDelay");
  return atexit(_E170_20);
}

//----- (006F8C10) --------------------------------------------------------  // acclient.c:781495
unsigned int _E203_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_CmdPrefix");
  ID_CmdPrefix_0 = result;
  return result;
}

//----- (006F8C30) --------------------------------------------------------  // acclient.c:781505
unsigned int _E205_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_AliasPrefix");
  ID_AliasPrefix_0 = result;
  return result;
}

//----- (006F8C50) --------------------------------------------------------  // acclient.c:781515
unsigned int _E207_4()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_AssistedTell");
  ID_AssistedTell_0 = result;
  return result;
}

//----- (006F8C70) --------------------------------------------------------  // acclient.c:781525
unsigned int _E209_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("prefix");
  PREFIX_0 = result;
  return result;
}

//----- (006F8C90) --------------------------------------------------------  // acclient.c:781535
unsigned int _E211_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("target");
  TARGET_0 = result;
  return result;
}

//----- (006F8CB0) --------------------------------------------------------  // acclient.c:781545
int sub_6F8CB0()
{
  return atexit(nullsub_710);
}

//----- (00764850) --------------------------------------------------------  // acclient.c:891114
void __cdecl _E125_52()
{
  char *v0; // esi@1

  v0 = &Input_KeymapFile_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Input_KeymapFile_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764880) --------------------------------------------------------  // acclient.c:891127
void __cdecl _E128_51()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontFace_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontFace_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007648B0) --------------------------------------------------------  // acclient.c:891140
void __cdecl _E131_43()
{
  char *v0; // esi@1

  v0 = &UI_ChatFontSize_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UI_ChatFontSize_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007648E0) --------------------------------------------------------  // acclient.c:891153
void __cdecl _E134_33()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)UI_ChatFontSize_Choices_2;
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

//----- (00764920) --------------------------------------------------------  // acclient.c:891178
void __cdecl _E137_32()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_42;
  v1 = 5;
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

//----- (00764960) --------------------------------------------------------  // acclient.c:891203
void __cdecl _E140_27()
{
  char *v0; // esi@1

  v0 = &waveform_None_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764990) --------------------------------------------------------  // acclient.c:891216
void __cdecl _E143_27()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007649C0) --------------------------------------------------------  // acclient.c:891229
void __cdecl _E146_28()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007649F0) --------------------------------------------------------  // acclient.c:891242
void __cdecl _E149_28()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764A20) --------------------------------------------------------  // acclient.c:891255
void __cdecl _E152_26()
{
  char *v0; // esi@1

  v0 = &waveform_Square_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764A50) --------------------------------------------------------  // acclient.c:891268
void __cdecl _E155_23()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764A80) --------------------------------------------------------  // acclient.c:891281
void __cdecl _E158_25()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764AB0) --------------------------------------------------------  // acclient.c:891294
void __cdecl _E161_23()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764AE0) --------------------------------------------------------  // acclient.c:891307
void __cdecl _E164_25()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764B10) --------------------------------------------------------  // acclient.c:891320
void __cdecl _E167_21()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00764B40) --------------------------------------------------------  // acclient.c:891333
void __cdecl _E170_20()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

