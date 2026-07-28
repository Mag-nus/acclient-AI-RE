/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Dialog
   Object     : ENGINE\uielement_util_dialog\Dialog.obj
   Functions  : 10
   Addresses  : 00476830 - 006EC3A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00476830) --------------------------------------------------------  // acclient.c:179607
void __userpurge Dialog::Dialog(Dialog *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  Dialog *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (IInputActionCallbackVtbl *)&Dialog::vftable;
  v4->m_nContext = 0;
  PropertyCollection::PropertyCollection(&v4->m_cData);
  v4->m_tNow = INVALID_TIME_10;
  v4->m_tExpiration = INVALID_TIME_10;
  v4->m_pcPendingDisplay = 0;
  v4->m_pcPendingDisplayText = 0;
}
// 79DF20: using guessed type int (__thiscall *Dialog::vftable)(void *, char);

//----- (004768A0) --------------------------------------------------------  // acclient.c:179624
void __thiscall Dialog::~Dialog(Dialog *this)
{
  UIElement_Field *v1; // esi@1

  v1 = (UIElement_Field *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&Dialog::vftable;
  PropertyCollection::~PropertyCollection(&this->m_cData);
  UIElement_Field::~UIElement_Field(v1);
}
// 79DF20: using guessed type int (__thiscall *Dialog::vftable)(void *, char);

//----- (004768C0) --------------------------------------------------------  // acclient.c:179636
int __thiscall Dialog::ListenToElementMessage(Dialog *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // esi@1

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 36 && (Dialog *)i_rMsg->pElement == this )
    ((void (*)(void))this->vfptr[27].__vecDelDtor)();
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004768F0) --------------------------------------------------------  // acclient.c:179647
UIElement_Field *__thiscall Dialog::vector_deleting_destructor(Dialog *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1

  v2 = (UIElement_Field *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&Dialog::vftable;
  PropertyCollection::~PropertyCollection(&this->m_cData);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79DF20: using guessed type int (__thiscall *Dialog::vftable)(void *, char);

//----- (00476930) --------------------------------------------------------  // acclient.c:179662
void __thiscall Dialog::UpdatePendingDialogDisplay(Dialog *this, unsigned int i_iNumPending)
{
  Dialog *v2; // esi@1
  UIElement *v3; // eax@3
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // ecx@8

  v2 = this;
  if ( !this->m_pcPendingDisplay || !this->m_pcPendingDisplayText )
  {
    v3 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x33u);
    v2->m_pcPendingDisplay = v3;
    if ( v3 && (v4 = UIElement::GetChildRecursive(v3, 0x34u)) != 0 )
      v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
    else
      v5 = 0;
    v2->m_pcPendingDisplayText = (UIElement_Text *)v5;
  }
  v6 = v2->m_pcPendingDisplay;
  if ( v6 )
    ((void (__stdcall *)(int))v6->vfptr[13].__vecDelDtor)(25 - (i_iNumPending != 0));
}

//----- (004769B0) --------------------------------------------------------  // acclient.c:179687
void __thiscall Dialog::UpdatePopupSizeAndPosition(Dialog *this)
{
  UIElement *v1; // ebp@1
  UIElement *v2; // eax@1
  int v3; // ebx@2
  UIRegion *v4; // esi@4
  int v5; // edi@5
  int v6; // edi@5
  int v7; // edi@5
  IInputActionCallbackVtbl *v8; // ebx@6
  int v9; // eax@6
  int v10; // ST04_4@7
  signed int v11; // eax@7

  v1 = (UIElement *)this;
  v2 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x3Eu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    v3 = 0;
  v4 = (UIRegion *)UIElement::GetChildRecursive(v1, 0x3Du);
  if ( v4 )
  {
    UIElement_Text::RecalculateGlyphList((UIElement_Text *)v3);
    v5 = *(_DWORD *)(v3 + 1540);
    v6 = v5 - UIRegion::GetHeight((UIRegion *)v3);
    v7 = UIRegion::GetHeight(v4) + v6;
    if ( UIRegion::GetHeight(v4) < v7 )
    {
      v8 = v4->vfptr;
      v9 = UIRegion::GetWidth(v4);
      ((void (__thiscall *)(UIRegion *, int, int))v8[4].__vecDelDtor)(v4, v9, v7);
    }
    v10 = UIRegion::GetHeight((UIRegion *)&v1->vfptr) / 2;
    v11 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
    UIElement::CenterAt((UIElement *)v4, v11 / 2, v10);
  }
}

//----- (00476A50) --------------------------------------------------------  // acclient.c:179727
void __thiscall Dialog::UpdateDialogText(Dialog *this)
{
  Dialog *v1; // esi@1
  unsigned int v2; // edx@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@1
  HashTableData<unsigned long,BaseProperty> *v4; // edx@1
  UIElement *v5; // eax@8
  UIElement_Text *v6; // edi@9
  __int64 v7; // ST04_8@10
  unsigned int v8; // eax@10
  BasePropertyDesc *v9; // ecx@12
  unsigned int v10; // edx@12
  BasePropertyValue *v11; // ecx@16
  unsigned int v12; // edx@16
  BaseProperty p; // [sp+Ch] [bp-98h]@1
  StringInfo tmp; // [sp+14h] [bp-90h]@6

  v1 = this;
  v2 = 0xC5 % this->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets;
  v3 = this->m_cData.m_hashProperties.m_intrusiveTable.m_buckets;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v4 = v3[v2];
  if ( v4 )
  {
    while ( v4->m_hashKey != 197 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        return;
    }
    if ( v4 )
    {
      BaseProperty::operator=(&p, (int)&v4->m_data);
      StringInfo::StringInfo(&tmp);
      if ( p.m_pcPropertyValue )
      {
        if ( (unsigned __int8)((int (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&tmp) )
        {
          v5 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x3Eu);
          if ( v5 )
          {
            v6 = (UIElement_Text *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)12);
            if ( v6 )
            {
              v7 = (signed int)(unsigned __int64)(v1->m_tExpiration - v1->m_tNow);
              v8 = compute_str_hash("time");
              StringInfo::AddVariable_Int(&tmp, v8, v7);
              UIElement_Text::SetStringInfo(v6, &tmp);
              ((void (__thiscall *)(Dialog *))v1->vfptr[27].__vecDelDtor)(v1);
            }
          }
        }
      }
      StringInfo::~StringInfo(&tmp);
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v9 = p.m_pcPropertyDesc;
        v10 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v10;
        if ( !v10 )
          ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyDesc = 0;
      }
      if ( p.m_pcPropertyValue )
      {
        v11 = p.m_pcPropertyValue;
        v12 = p.m_pcPropertyValue->m_cRef - 1;
        p.m_pcPropertyValue->m_cRef = v12;
        if ( !v12 )
          ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (00476B90) --------------------------------------------------------  // acclient.c:179804
void __thiscall Dialog::ListenToGlobalMessage(Dialog *this, unsigned int i_eMessageID, int i_nData)
{
  long double v3; // st7@2

  if ( i_eMessageID == 3 )
  {
    v3 = *(double *)&Timer::cur_time;
    if ( COERCE_DOUBLE(Timer::cur_time.Cmd) > this->m_tNow )
    {
      this->m_tNow = *(double *)&Timer::cur_time;
      if ( v3 <= this->m_tExpiration )
        Dialog::UpdateDialogText(this);
      else
        ((void (*)(void))this->vfptr[26].OnLoseFocus)();
    }
  }
}

//----- (00476BE0) --------------------------------------------------------  // acclient.c:179823
void __thiscall Dialog::SetData(Dialog *this, PropertyCollection *i_cData)
{
  Dialog *v2; // esi@1
  unsigned int v3; // edx@1
  HashTableData<unsigned long,BaseProperty> **v4; // ecx@1
  HashTableData<unsigned long,BaseProperty> *v5; // eax@1
  HashTableData<unsigned long,BaseProperty> *v6; // eax@9
  double v7; // st7@16
  unsigned int v8; // edx@16
  BasePropertyDesc *v9; // ecx@18
  unsigned int v10; // edx@18
  BasePropertyValue *v11; // ecx@22
  unsigned int v12; // edx@22
  BaseProperty p; // [sp+Ch] [bp-8h]@1

  v2 = this;
  PropertyCollection::operator=(&this->m_cData, i_cData);
  v3 = 0xAC % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets;
  v4 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v5 = v4[v3];
  if ( v5 )
  {
    while ( v5->m_hashKey != 172 )
    {
      v5 = v5->m_hashNext;
      if ( !v5 )
        goto LABEL_9;
    }
    if ( v5 )
    {
      BaseProperty::operator=(&p, (int)&v5->m_data);
      LOBYTE(i_cData) = 0;
      if ( p.m_pcPropertyValue )
      {
        ((void (__stdcall *)(PropertyCollection **))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&i_cData);
        if ( (_BYTE)i_cData )
          UIElement::SetAttribute_Bool((UIElement *)&v2->vfptr, 0x40u, 1);
      }
    }
  }
LABEL_9:
  v6 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xC6
                                                             % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v6 )
  {
    while ( v6->m_hashKey != 198 )
    {
      v6 = v6->m_hashNext;
      if ( !v6 )
        goto LABEL_17;
    }
    if ( v6 )
    {
      BaseProperty::operator=(&p, (int)&v6->m_data);
      *(float *)&i_cData = 0.0;
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(PropertyCollection **))p.m_pcPropertyValue->vfptr[34].__vecDelDtor)(&i_cData);
      v7 = *(float *)&i_cData;
      v8 = Timer::cur_time.Param;
      LODWORD(v2->m_tNow) = Timer::cur_time.Cmd;
      HIDWORD(v2->m_tNow) = v8;
      v2->m_tExpiration = v7 + v2->m_tNow;
      UIListener::RegisterForGlobalMessage((UIListener *)&v2->vfptr, 3u);
    }
  }
LABEL_17:
  Dialog::UpdateDialogText(v2);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v9 = p.m_pcPropertyDesc;
    v10 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v10;
    if ( !v10 )
      ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v11 = p.m_pcPropertyValue;
    v12 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v12;
    if ( !v12 )
      ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
  }
}

//----- (006EC3A0) --------------------------------------------------------  // acclient.c:768070
int _E1_83()
{
  return atexit(_E2_83);
}

