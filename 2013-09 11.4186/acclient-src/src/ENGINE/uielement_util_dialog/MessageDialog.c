/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MessageDialog
   Object     : ENGINE\uielement_util_dialog\MessageDialog.obj
   Functions  : 8
   Addresses  : 00474D10 - 006EC350 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00474D10) --------------------------------------------------------  // acclient.c:177911
void __thiscall MessageDialog::CancelDialog(MessageDialog *this)
{
  DialogFactory::CloseDialog(this->m_nContext);
}

//----- (00475260) --------------------------------------------------------  // acclient.c:178233
MessageDialog *__thiscall MessageDialog::DynamicCast(MessageDialog *this, unsigned int i_eType)
{
  MessageDialog *result; // eax@1

  result = this;
  if ( i_eType != 23 )
    result = (MessageDialog *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00475280) --------------------------------------------------------  // acclient.c:178244
Dialog *__usercall MessageDialog::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  Dialog *v3; // esi@1
  Dialog *result; // eax@2

  v3 = (Dialog *)operator new(0x690u);
  if ( v3 )
  {
    Dialog::Dialog(v3, a1, _layout, _full_desc);
    v3->vfptr = (IInputActionCallbackVtbl *)&MessageDialog::vftable;
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79D8B0: using guessed type int (__thiscall *MessageDialog::vftable)(void *, char);

//----- (004752C0) --------------------------------------------------------  // acclient.c:178265
int __thiscall MessageDialog::ListenToElementMessage(MessageDialog *this, UIElementMessageInfo *i_rMsg)
{
  int result; // eax@3

  if ( i_rMsg->idMessage != 1 || i_rMsg->idElement != 38 )
  {
    result = Dialog::ListenToElementMessage((Dialog *)&this->vfptr, i_rMsg);
  }
  else
  {
    DialogFactory::CloseDialog(this->m_nContext);
    result = 2;
  }
  return result;
}

//----- (004752F0) --------------------------------------------------------  // acclient.c:178282
MessageDialog *__thiscall MessageDialog::scalar_deleting_destructor(MessageDialog *this, unsigned int a2)
{
  MessageDialog *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&MessageDialog::vftable;
  Dialog::~Dialog((Dialog *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D8B0: using guessed type int (__thiscall *MessageDialog::vftable)(void *, char);

//----- (00475320) --------------------------------------------------------  // acclient.c:178296
void __cdecl MessageDialog::Register()
{
  UIElement::RegisterElementClass(0x17u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))MessageDialog::Create);
}

//----- (00475330) --------------------------------------------------------  // acclient.c:178302
void __thiscall MessageDialog::SetData(MessageDialog *this, PropertyCollection *i_cData)
{
  MessageDialog *v2; // esi@1
  unsigned int v3; // edx@1
  HashTableData<unsigned long,BaseProperty> **v4; // ecx@1
  HashTableData<unsigned long,BaseProperty> *v5; // eax@1
  UIElement *v6; // eax@8
  UIElement_Text *v7; // eax@9
  BasePropertyDesc *v8; // ecx@12
  unsigned int v9; // edx@12
  BasePropertyValue *v10; // ecx@16
  unsigned int v11; // edx@16
  BaseProperty p; // [sp+Ch] [bp-98h]@1
  StringInfo tmp; // [sp+14h] [bp-90h]@6

  v2 = this;
  Dialog::SetData((Dialog *)&this->vfptr, i_cData);
  v3 = 0x95 % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets;
  v4 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v5 = v4[v3];
  if ( v5 )
  {
    while ( v5->m_hashKey != 149 )
    {
      v5 = v5->m_hashNext;
      if ( !v5 )
        return;
    }
    if ( v5 )
    {
      BaseProperty::operator=(&p, (int)&v5->m_data);
      StringInfo::StringInfo(&tmp);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&tmp);
      v6 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x26u);
      if ( v6 )
      {
        v7 = (UIElement_Text *)v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
        if ( v7 )
          UIElement_Text::SetStringInfo(v7, &tmp);
      }
      StringInfo::~StringInfo(&tmp);
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v8 = p.m_pcPropertyDesc;
        v9 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v9;
        if ( !v9 )
          ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyDesc = 0;
      }
      if ( p.m_pcPropertyValue )
      {
        v10 = p.m_pcPropertyValue;
        v11 = p.m_pcPropertyValue->m_cRef - 1;
        p.m_pcPropertyValue->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (006EC350) --------------------------------------------------------  // acclient.c:768040
int _E1_78()
{
  return atexit(_E2_78);
}

