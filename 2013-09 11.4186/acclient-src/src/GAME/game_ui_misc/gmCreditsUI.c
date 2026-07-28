/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCreditsUI
   Object     : GAME\game_ui_misc\gmCreditsUI.obj
   Functions  : 22
   Addresses  : 004E6E10 - 007633C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E6E10) --------------------------------------------------------  // acclient.c:276807
gmUIMainFramework *__thiscall gmUIMainFramework::vector_deleting_destructor(gmUIMainFramework *this, unsigned int a2)
{
  gmUIMainFramework *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmUIMainFramework::vftable;
  UIMainFramework::~UIMainFramework((UIMainFramework *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C1CA0: using guessed type int (__thiscall *gmUIMainFramework::vftable)(void *, char);

//----- (004E6E40) --------------------------------------------------------  // acclient.c:276821
void __thiscall gmCreditsUI::ListenToGlobalMessage(gmCreditsUI *this, unsigned int messageID, int data_int)
{
  if ( messageID == 3 )
    ((void (*)(void))this->vfptr[5].OnAction)();
}

//----- (004E6E50) --------------------------------------------------------  // acclient.c:276828
bool __thiscall UIFramework::Shown(UIFramework *this)
{
  bool result; // al@1

  result = this->m_shown;
  if ( this->m_bCanForceHide )
  {
    if ( this->m_bIsForcedHidden )
      result = 0;
  }
  return result;
}

//----- (004E6E70) --------------------------------------------------------  // acclient.c:276842
IDClass<_tagDataID,32,0> *__thiscall gmCreditsUI::GetNextPictureID(gmCreditsUI *this, IDClass<_tagDataID,32,0> *result)
{
  gmCreditsUI *v2; // esi@1
  IDClass<_tagDataID,32,0> *v3; // eax@2
  BasePropertyValue *v4; // ecx@3
  BasePropertyDesc *v5; // eax@3
  BasePropertyValue *v6; // edx@3
  int v7; // edi@3
  BasePropertyValue *v8; // ecx@5
  BasePropertyDesc *v9; // eax@7
  bool v10; // zf@7
  IDClass<_tagDataID,32,0> *v11; // esi@7
  int v12; // edx@8
  int v13; // edi@16
  int v14; // eax@20
  BasePropertyValue *v15; // ecx@20
  int v16; // edx@20
  IDClass<_tagDataID,32,0> picDID; // [sp+Ch] [bp-Ch]@5
  BaseProperty picProp; // [sp+10h] [bp-8h]@3

  v2 = this;
  if ( !this->m_numPictures )
  {
    v3 = result;
    result->id = stru_840904.id;
    return v3;
  }
  v4 = this->m_pictureProp.m_pcPropertyValue;
  v5 = 0;
  v6 = 0;
  v7 = v2->m_lastPicture;
  picProp.m_pcPropertyDesc = 0;
  picProp.m_pcPropertyValue = 0;
  if ( !v4 )
    goto LABEL_15;
  if ( !(unsigned __int8)((int (__stdcall *)(int, BaseProperty *))v4->vfptr[61].__vecDelDtor)(v7, &picProp) )
  {
    v6 = picProp.m_pcPropertyValue;
    v5 = picProp.m_pcPropertyDesc;
LABEL_15:
    v11 = result;
    result->id = stru_840904.id;
    if ( v5 )
    {
      v13 = v5->m_cRef - 1;
      v5->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      v6 = picProp.m_pcPropertyValue;
      picProp.m_pcPropertyDesc = 0;
    }
    if ( v6 )
    {
      v14 = (int)&v6->m_cRef;
      v15 = v6;
      v16 = v6->m_cRef - 1;
      *(_DWORD *)v14 = v16;
      if ( !v16 )
        ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
    }
    return v11;
  }
  picDID.id = stru_840904.id;
  v8 = picProp.m_pcPropertyValue;
  if ( picProp.m_pcPropertyValue )
  {
    ((void (__stdcall *)(IDClass<_tagDataID,32,0> *))picProp.m_pcPropertyValue->vfptr[44].__vecDelDtor)(&picDID);
    v8 = picProp.m_pcPropertyValue;
  }
  v9 = picProp.m_pcPropertyDesc;
  v10 = (_DWORD)picProp.m_pcPropertyDesc == 0;
  v2->m_lastPicture = (v2->m_lastPicture + 1) % v2->m_numPictures;
  v11 = result;
  result->id = picDID.id;
  if ( !v10 )
  {
    v12 = v9->m_cRef - 1;
    v9->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
    v8 = picProp.m_pcPropertyValue;
    picProp.m_pcPropertyDesc = 0;
  }
  if ( v8 )
  {
    v10 = v8->m_cRef-- == 1;
    if ( v10 )
    {
      ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
      return result;
    }
  }
  return v11;
}

//----- (004E6FC0) --------------------------------------------------------  // acclient.c:276938
void __thiscall gmCreditsUI::~gmCreditsUI(gmCreditsUI *this)
{
  gmCreditsUI *v1; // esi@1
  BasePropertyDesc *v2; // ecx@3
  bool v3; // zf@4
  BasePropertyValue *v4; // ecx@7

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCreditsUI::vftable;
  UIMainFramework::RemoveRootElement((UIMainFramework *)&this->vfptr, &this->m_pictureField);
  UIMainFramework::RemoveRootElement((UIMainFramework *)&v1->vfptr, &v1->m_textField);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_aPictureElements);
  DialogFactory::CloseDialog(v1->m_waitContext);
  v1->m_waitContext = 0;
  if ( (v1->m_aPictureElements.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_aPictureElements.m_data);
  v2 = v1->m_pictureProp.m_pcPropertyDesc;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pictureProp.m_pcPropertyDesc = 0;
  }
  v4 = v1->m_pictureProp.m_pcPropertyValue;
  if ( v4 )
  {
    v3 = v4->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->m_pictureProp.m_pcPropertyValue = 0;
  }
  v1->vfptr = (IInputActionCallbackVtbl *)&gmUIMainFramework::vftable;
  UIMainFramework::~UIMainFramework((UIMainFramework *)&v1->vfptr);
}
// 7C1CA0: using guessed type int (__thiscall *gmUIMainFramework::vftable)(void *, char);
// 7C1CE8: using guessed type int (__thiscall *gmCreditsUI::vftable)(void *, char);

//----- (004E7080) --------------------------------------------------------  // acclient.c:276977
gmCreditsUI *__thiscall gmCreditsUI::vector_deleting_destructor(gmCreditsUI *this, unsigned int a2)
{
  gmCreditsUI *v2; // esi@1

  v2 = this;
  gmCreditsUI::~gmCreditsUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E70A0) --------------------------------------------------------  // acclient.c:276989
void __usercall gmCreditsUI::Initialize(gmCreditsUI *this@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  gmCreditsUI *v3; // esi@1
  UIElement *v4; // ecx@3
  unsigned int i; // ebx@4
  unsigned int v6; // eax@6
  char *v7; // edi@9
  char *v8; // edi@13
  IInputActionCallbackVtbl *v9; // edi@16
  int v10; // eax@16
  IInputActionCallbackVtbl *v11; // edi@16
  int v12; // eax@16
  UIElement_Text *v13; // eax@16
  IInputActionCallbackVtbl *v14; // edi@16
  int v15; // ST10_4@16
  int v16; // eax@16
  signed int v17; // eax@18
  UIRegion *v18; // ecx@18
  double v19; // st7@18
  long double v20; // st7@18
  UIElement *v21; // ecx@18
  BasePropertyValue *v22; // ecx@18
  int v23; // [sp+Ch] [bp-B0h]@4
  PStringBase<char> txt; // [sp+1Ch] [bp-A0h]@5
  IDClass<_tagDataID,32,0> creditTableDID; // [sp+20h] [bp-9Ch]@3
  float duration; // [sp+24h] [bp-98h]@18
  StringInfo info; // [sp+2Ch] [bp-90h]@5

  v3 = this;
  if ( this->m_textField )
  {
    if ( this->m_textArea )
    {
      UIListener::RegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
      v4 = v3->m_textField;
      creditTableDID.id = stru_840904.id;
      UIElement::GetAttribute_DataID(v4, 0x10000003u, &creditTableDID);
      if ( creditTableDID.id != stru_840904.id )
      {
        v23 = a3;
        for ( i = 1; ; ++i )
        {
          txt.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PStringBase<char>::sprintf(&txt, "ID_Credits%d", i);
          StringInfo::StringInfo(&info);
          v6 = txt.m_charbuffer ? compute_str_hash(txt.m_charbuffer->m_data) : 0;
          StringInfo::SetStringIDandTableID(&info, v6, creditTableDID);
          if ( !StringInfo::IsValid(&info, 1) )
            break;
          UIElement_Text::AppendStringInfo(v3->m_textArea, &info);
          StringInfo::~StringInfo(&info);
          v7 = &txt.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&txt.m_charbuffer[-1]) )
          {
            if ( v7 )
              (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
          }
        }
        StringInfo::~StringInfo(&info);
        v8 = &txt.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&txt.m_charbuffer[-1]) && v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
        v9 = v3->m_textArea->vfptr;
        v10 = UIRegion::GetHeight((UIRegion *)&v3->m_textField->vfptr);
        ((void (__thiscall *)(UIElement_Text *, _DWORD, int, int, int))v9[3].OnLoseFocus)(
          v3->m_textArea,
          0,
          v10,
          v23,
          a2);
        v11 = v3->m_textArea->vfptr;
        v12 = UIRegion::GetWidth((UIRegion *)&v3->m_textField->vfptr);
        ((void (__thiscall *)(UIElement_Text *, int, _DWORD))v11[4].__vecDelDtor)(v3->m_textArea, v12, 0);
        UIElement_Text::RecalculateGlyphList(v3->m_textArea);
        v13 = v3->m_textArea;
        v14 = v13->vfptr;
        v15 = v13->m_iScrollableHeight;
        v16 = UIRegion::GetWidth((UIRegion *)&v3->m_textField->vfptr);
        ((void (__thiscall *)(UIElement_Text *, int, int))v14[4].__vecDelDtor)(v3->m_textArea, v16, v15);
        if ( !UIElement::GetAttribute_Float(v3->m_textField, 0x10000004u, (float *)&info) )
          info.m_strToken.m_charbuffer = (PSRefBufferCharData<char> *)1065353216;
        v17 = UIRegion::GetHeight((UIRegion *)&v3->m_textField->vfptr);
        v18 = (UIRegion *)&v3->m_textArea->vfptr;
        duration = (double)v17;
        v19 = (double)UIRegion::GetHeight(v18);
        info.m_stringID = i;
        v3->m_duration = (duration + v19) / ((v19 / (double)i + duration) / *(float *)&info.m_strToken.m_charbuffer);
        v20 = Timer::compute_time();
        v21 = v3->m_pictureField;
        v3->m_endTime = v20 + v3->m_duration;
        ((void (__cdecl *)(signed int, int))v21->vfptr[17].OnAction)(268435461, &v3->m_pictureProp);
        v22 = v3->m_pictureProp.m_pcPropertyValue;
        if ( v22 )
          ((void (__stdcall *)(int))v22->vfptr[60].__vecDelDtor)(&v3->m_numPictures);
      }
    }
  }
}
// 4E70A0: could not find valid save-restore pair for ebp
// 4E70A0: could not find valid save-restore pair for edi

//----- (004E7310) --------------------------------------------------------  // acclient.c:277092
void __usercall gmCreditsUI::gmCreditsUI(gmCreditsUI *this@<ecx>, int a2@<ebp>)
{
  gmCreditsUI *v2; // esi@1
  unsigned int v3; // edi@1
  int v4; // eax@5
  UIElement *v5; // eax@8
  BasePropertyDesc *v6; // ecx@11
  BasePropertyValue *v7; // ecx@15
  bool alternate; // [sp+Fh] [bp-Dh]@3
  unsigned int textElemID; // [sp+10h] [bp-Ch]@6
  BaseProperty elemProp; // [sp+14h] [bp-8h]@6

  v2 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v2->vfptr = (IInputActionCallbackVtbl *)&gmCreditsUI::vftable;
  v2->m_waitContext = 0;
  v2->m_lastPicture = 0;
  v2->m_lastX = 0;
  v2->m_lastY = 0;
  v2->m_pictureProp.m_pcPropertyDesc = 0;
  v2->m_pictureProp.m_pcPropertyValue = 0;
  HIDWORD(v2->m_endTime) = HIDWORD(INVALID_TIME_61);
  v2->m_numPictures = 0;
  LODWORD(v2->m_duration) = 0;
  LODWORD(v2->m_endTime) = LODWORD(INVALID_TIME_61);
  v2->m_aPictureElements.m_data = 0;
  v2->m_aPictureElements.m_sizeAndDeallocate = 0;
  v2->m_aPictureElements.m_num = 0;
  v2->m_pictureField = 0;
  v2->m_textField = 0;
  v2->m_textArea = 0;
  v3 = (unsigned int)ICIDM::s_cidm;
  if ( !ICIDM::s_cidm->vfptr->CtrlKeyDown((ICIDM *)ICIDM::s_cidm)
    || !(unsigned __int8)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 96))(v3)
    || (alternate = 1, (unsigned __int8)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)v3 + 88))(v3)) )
    alternate = 0;
  v2->m_pictureField = (UIElement *)UIMainFramework::CreateAndAddRootElement(
                                      (UIMainFramework *)&v2->vfptr,
                                      0x10000004u,
                                      (alternate != 0) + 268436499);
  v4 = UIMainFramework::CreateAndAddRootElement(
         (UIMainFramework *)&v2->vfptr,
         0x10000004u,
         2 * (alternate != 0) + 268436496);
  v2->m_textField = (UIElement *)v4;
  if ( v4 )
  {
    textElemID = 0;
    elemProp.m_pcPropertyDesc = 0;
    elemProp.m_pcPropertyValue = 0;
    (*(void (__thiscall **)(int, signed int, BaseProperty *))(*(_DWORD *)v4 + 208))(v4, 268435458, &elemProp);
    if ( elemProp.m_pcPropertyValue )
      ((void (__stdcall *)(_DWORD))elemProp.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&textElemID);
    v5 = UIElement::GetChildRecursive(v2->m_textField, textElemID);
    if ( v5 )
      v2->m_textArea = (UIElement_Text *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)12);
    if ( (_DWORD)elemProp.m_pcPropertyDesc )
    {
      v6 = elemProp.m_pcPropertyDesc;
      v3 = elemProp.m_pcPropertyDesc->m_cRef - 1;
      elemProp.m_pcPropertyDesc->m_cRef = v3;
      if ( !v3 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
      elemProp.m_pcPropertyDesc = 0;
    }
    if ( elemProp.m_pcPropertyValue )
    {
      v7 = elemProp.m_pcPropertyValue;
      v3 = elemProp.m_pcPropertyValue->m_cRef - 1;
      elemProp.m_pcPropertyValue->m_cRef = v3;
      if ( !v3 )
        ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    }
  }
  gmCreditsUI::Initialize(v2, a2, v3);
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(9, v2, 3000);
}
// 7C1CE8: using guessed type int (__thiscall *gmCreditsUI::vftable)(void *, char);

//----- (004E74E0) --------------------------------------------------------  // acclient.c:277173
void __usercall gmCreditsUI::Create(int a1@<ebp>)
{
  gmCreditsUI *v1; // eax@1

  v1 = (gmCreditsUI *)operator new(0xE0u);
  if ( v1 )
    gmCreditsUI::gmCreditsUI(v1, a1);
}

//----- (004E7500) --------------------------------------------------------  // acclient.c:277183
void __cdecl gmCreditsUI::Register(unsigned int mode)
{
  UIFlow::RegisterFrameworkClass(mode, (UIMainFramework *(__cdecl *)())gmCreditsUI::Create);
}

//----- (004E7520) --------------------------------------------------------  // acclient.c:277189
void __thiscall gmCreditsUI::CreateAndAddPicture(gmCreditsUI *this)
{
  gmCreditsUI *v1; // edi@1
  IDClass<_tagDataID,32,0> v2; // ebx@1
  UIElement *v3; // eax@2
  HashSet<UIElement *>Vtbl *v4; // esi@2
  int v5; // eax@3
  unsigned int v6; // ecx@3
  int v7; // eax@3
  UIElement *pictureElement; // [sp+10h] [bp-1D0h]@1
  int height; // [sp+14h] [bp-1CCh]@5
  int width; // [sp+18h] [bp-1C8h]@5
  ElementDesc edesc; // [sp+1Ch] [bp-1C4h]@2

  v1 = this;
  gmCreditsUI::GetNextPictureID(this, (IDClass<_tagDataID,32,0> *)&pictureElement);
  v2.id = (unsigned int)pictureElement;
  if ( pictureElement != (UIElement *)stru_840904.id )
  {
    ElementDesc::ElementDesc(&edesc);
    v3 = v1->m_pictureField;
    edesc.m_type = 3;
    edesc.m_elementID = 268436501;
    v4 = UIElementManager::CreateChildElement(UIElementManager::s_pInstance, v3, v3->m_layout, &edesc);
    pictureElement = (UIElement *)v4;
    if ( v4 )
    {
      v5 = UIRegion::GetHeight((UIRegion *)&v1->m_pictureField->vfptr);
      v6 = v1->m_aPictureElements.m_num;
      v7 = v5 + 1;
      if ( v6 )
        v7 = UIRegion::GetScreenY1((UIRegion *)&v1->m_aPictureElements.m_data[v6 - 1]->vfptr) + 1;
      (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, _DWORD, int))v4->__vecDelDtor + 11))(v4, 0, v7);
      UIElement::SetMediaImage((UIElement *)v4, v2, 1u);
      UIElement::InqImageSize((UIElement *)v4, &width, &height);
      (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, int, int))v4->__vecDelDtor + 12))(v4, width, height);
      SmartArray<UIElement_Button *,1>::AddToEnd(
        (SmartArray<BSPNODE *,1> *)&v1->m_aPictureElements,
        (BSPNODE *const *)&pictureElement);
    }
    ElementDesc::~ElementDesc(&edesc);
  }
}

//----- (004E7610) --------------------------------------------------------  // acclient.c:277234
void __thiscall gmCreditsUI::ScrollPictures(gmCreditsUI *this, int pixels)
{
  gmCreditsUI *v2; // esi@1
  unsigned int v3; // eax@2
  unsigned int v4; // ebx@4
  UIRegion *v5; // edi@5
  unsigned int v6; // eax@5
  UIElement *v7; // edi@6
  unsigned int v8; // eax@7
  int v9; // eax@8
  unsigned int v10; // eax@11
  unsigned int v11; // edi@12

  v2 = this;
  if ( this->m_pictureField )
  {
    v3 = this->m_aPictureElements.m_num;
    if ( v3 )
    {
      v4 = 0;
      if ( v3 )
      {
        do
        {
          v5 = (UIRegion *)&v2->m_aPictureElements.m_data[v4]->vfptr;
          v6 = UIRegion::GetScreenY0(v5);
          ((void (__thiscall *)(UIRegion *, _DWORD, int))v5->vfptr[3].OnLoseFocus)(v5, 0, v6 - pixels);
          ++v4;
        }
        while ( v4 < v2->m_aPictureElements.m_num );
      }
      v7 = *v2->m_aPictureElements.m_data;
      if ( (UIRegion::GetScreenY1((UIRegion *)&v7->vfptr) & 0x80000000) != 0 )
      {
        v8 = v2->m_aPictureElements.m_num;
        if ( v8 )
        {
          v9 = v8 - 1;
          v2->m_aPictureElements.m_num = v9;
          if ( v9 )
          {
            *v2->m_aPictureElements.m_data = v2->m_aPictureElements.m_data[v9];
            v2->m_aPictureElements.m_data[v2->m_aPictureElements.m_num] = 0;
          }
        }
        UIElement::AddToDeleteQueue(v7);
      }
    }
    else
    {
      gmCreditsUI::CreateAndAddPicture(this);
    }
    v10 = v2->m_aPictureElements.m_num;
    if ( v10 )
    {
      v11 = UIRegion::GetScreenY0((UIRegion *)&v2->m_aPictureElements.m_data[v10 - 1]->vfptr);
      if ( (signed int)v11 < UIRegion::GetHeight((UIRegion *)&v2->m_pictureField->vfptr) )
        gmCreditsUI::CreateAndAddPicture(v2);
    }
  }
}

//----- (004E76F0) --------------------------------------------------------  // acclient.c:277297
void __thiscall gmCreditsUI::MakePleaseWaitDialog(gmCreditsUI *this)
{
  gmCreditsUI *v1; // esi@1
  unsigned int v2; // eax@1
  BasePropertyDesc *v3; // ecx@6
  unsigned int v4; // edx@6
  BasePropertyValue *v5; // ecx@10
  unsigned int v6; // esi@10
  BaseProperty p; // [sp+Ch] [bp-114h]@1
  unsigned int _key; // [sp+14h] [bp-10Ch]@3
  PropertyCollection pc; // [sp+18h] [bp-108h]@1
  StringInfo info; // [sp+90h] [bp-90h]@1

  v1 = this;
  StringInfo::StringInfo(&info);
  v2 = compute_str_hash("ID_Wait_PleaseWait");
  StringInfo::SetStringIDandTableEnum(&info, v2, 268435457);
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(2);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
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
  v1->m_waitContext = DialogFactory::MakeDialog((UIFramework *)&v1->vfptr, &pc);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v3 = p.m_pcPropertyDesc;
    v4 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v4;
    if ( !v4 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v5 = p.m_pcPropertyValue;
    v6 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
  StringInfo::~StringInfo(&info);
}

//----- (004E7850) --------------------------------------------------------  // acclient.c:277363
unsigned int __thiscall gmCreditsUI::ScrollText(gmCreditsUI *this)
{
  gmCreditsUI *v1; // esi@1
  long double v2; // st7@3
  double v3; // st6@3
  float *v4; // eax@5
  float *v5; // eax@7
  int v6; // edi@9
  int v7; // ebx@9
  int v8; // edi@9
  unsigned int v9; // ebx@9
  float percentage; // [sp+8h] [bp-8h]@3
  int v12; // [sp+Ch] [bp-4h]@5

  v1 = this;
  if ( !this->m_textArea || !this->m_textField )
    return 0;
  v2 = Timer::compute_time();
  v3 = v1->m_duration;
  percentage = 1.0;
  if ( v3 != 0.0 )
    percentage = 1.0 - (v1->m_endTime - v2) / v1->m_duration;
  v12 = 1065353216;
  v4 = &percentage;
  if ( percentage >= 1.0 )
    v4 = (float *)&v12;
  percentage = *v4;
  v12 = 0;
  v5 = &percentage;
  if ( percentage <= 0.0 )
    v5 = (float *)&v12;
  percentage = *v5;
  UIElement_Text::RecalculateGlyphList(v1->m_textArea);
  v6 = v1->m_textArea->m_iScrollableHeight;
  v12 = v6 + UIRegion::GetHeight((UIRegion *)&v1->m_textField->vfptr);
  v7 = (unsigned __int64)((double)v12 * percentage);
  v8 = UIRegion::GetHeight((UIRegion *)&v1->m_textField->vfptr) - v7;
  v9 = UIRegion::GetScreenY0((UIRegion *)&v1->m_textArea->vfptr) - v8;
  ((void (__stdcall *)(_DWORD, int))v1->m_textArea->vfptr[3].OnLoseFocus)(0, v8);
  if ( percentage == 1.0 )
  {
    UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
    gmCreditsUI::MakePleaseWaitDialog(v1);
    UIFramework::QueueUIMode(0x1000000Au);
    return 0;
  }
  return v9;
}

//----- (004E79A0) --------------------------------------------------------  // acclient.c:277413
char __thiscall gmCreditsUI::OnAction(gmCreditsUI *this, InputEvent *i_evt)
{
  gmCreditsUI *v2; // esi@1

  v2 = this;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  gmCreditsUI::MakePleaseWaitDialog(v2);
  UIFramework::QueueUIMode(0x1000000Au);
  return 1;
}

//----- (004E79D0) --------------------------------------------------------  // acclient.c:277425
void __thiscall gmCreditsUI::Update(gmCreditsUI *this)
{
  gmCreditsUI *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  v2 = gmCreditsUI::ScrollText(this);
  gmCreditsUI::ScrollPictures(v1, v2);
}

//----- (006F69F0) --------------------------------------------------------  // acclient.c:779342
int _E73_81()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_41, "Misc.TooltipEnable");
  return atexit(_E74_61);
}

//----- (006F6A10) --------------------------------------------------------  // acclient.c:779349
int _E76_47()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_41, "Misc.TooltipDelay");
  return atexit(_E77_75);
}

//----- (006F6A30) --------------------------------------------------------  // acclient.c:779356
unsigned int _E79_40()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_Wait_PleaseWait");
  ID_Wait_PleaseWait = result;
  return result;
}

//----- (006F6A50) --------------------------------------------------------  // acclient.c:779366
int sub_6F6A50()
{
  return atexit(nullsub_497);
}

//----- (00763390) --------------------------------------------------------  // acclient.c:889912
void __cdecl _E74_61()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007633C0) --------------------------------------------------------  // acclient.c:889925
void __cdecl _E77_75()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

