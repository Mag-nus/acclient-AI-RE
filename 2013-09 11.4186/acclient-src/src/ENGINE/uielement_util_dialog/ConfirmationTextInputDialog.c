/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ConfirmationTextInputDialog
   Object     : ENGINE\uielement_util_dialog\ConfirmationTextInputDialog.obj
   Functions  : 8
   Addresses  : 004759A0 - 006EC370 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004759A0) --------------------------------------------------------  // acclient.c:178704
ConfirmationTextInputDialog *__thiscall ConfirmationTextInputDialog::DynamicCast(ConfirmationTextInputDialog *this, unsigned int i_eType)
{
  ConfirmationTextInputDialog *result; // eax@1

  result = this;
  if ( i_eType != 21 )
    result = (ConfirmationTextInputDialog *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004759C0) --------------------------------------------------------  // acclient.c:178715
Dialog *__usercall ConfirmationTextInputDialog::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  Dialog *v3; // esi@1
  Dialog *result; // eax@2

  v3 = (Dialog *)operator new(0x690u);
  if ( v3 )
  {
    Dialog::Dialog(v3, a1, _layout, _full_desc);
    v3->vfptr = (IInputActionCallbackVtbl *)&ConfirmationTextInputDialog::vftable;
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79DB40: using guessed type int (__thiscall *ConfirmationTextInputDialog::vftable)(void *, char);

//----- (00475A00) --------------------------------------------------------  // acclient.c:178736
ConfirmationTextInputDialog *__thiscall ConfirmationTextInputDialog::scalar_deleting_destructor(ConfirmationTextInputDialog *this, unsigned int a2)
{
  ConfirmationTextInputDialog *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&ConfirmationTextInputDialog::vftable;
  Dialog::~Dialog((Dialog *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79DB40: using guessed type int (__thiscall *ConfirmationTextInputDialog::vftable)(void *, char);

//----- (00475A30) --------------------------------------------------------  // acclient.c:178750
void __cdecl ConfirmationTextInputDialog::Register()
{
  UIElement::RegisterElementClass(
    0x15u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))ConfirmationTextInputDialog::Create);
}

//----- (00475A40) --------------------------------------------------------  // acclient.c:178758
void __thiscall ConfirmationTextInputDialog::SetData(ConfirmationTextInputDialog *this, PropertyCollection *i_cData)
{
  ConfirmationTextInputDialog *v2; // esi@1
  unsigned int v3; // edx@1
  HashTableData<unsigned long,BaseProperty> **v4; // eax@1
  BasePropertyDesc *v5; // ecx@1
  HashTableData<unsigned long,BaseProperty> *v6; // eax@1
  UIElement *v7; // eax@8
  UIElement_Text *v8; // eax@9
  HashTableData<unsigned long,BaseProperty> *v9; // eax@12
  UIElement *v10; // eax@19
  UIElement_Text *v11; // eax@20
  bool v12; // zf@24
  BasePropertyValue *v13; // ecx@28
  unsigned int v14; // edx@28
  BaseProperty p; // [sp+14h] [bp-98h]@1
  StringInfo tmp; // [sp+1Ch] [bp-90h]@6

  v2 = this;
  Dialog::SetData((Dialog *)&this->vfptr, i_cData);
  ((void (__thiscall *)(ConfirmationTextInputDialog *))v2->vfptr[21].__vecDelDtor)(v2);
  v3 = 0x9A % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets;
  v4 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets;
  v5 = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v6 = v4[v3];
  if ( v6 )
  {
    while ( v6->m_hashKey != 154 )
    {
      v6 = v6->m_hashNext;
      if ( !v6 )
        goto LABEL_12;
    }
    if ( v6 )
    {
      BaseProperty::operator=(&p, (int)&v6->m_data);
      StringInfo::StringInfo(&tmp);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&tmp);
      v7 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x2Eu);
      if ( v7 )
      {
        v8 = (UIElement_Text *)v7->vfptr[12].OnAction((IInputActionCallback *)v7, (InputEvent *)12);
        if ( v8 )
          UIElement_Text::SetStringInfo(v8, &tmp);
      }
      StringInfo::~StringInfo(&tmp);
      v5 = p.m_pcPropertyDesc;
    }
  }
LABEL_12:
  v9 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0x9B
                                                             % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v9 )
  {
    while ( v9->m_hashKey != 155 )
    {
      v9 = v9->m_hashNext;
      if ( !v9 )
        goto LABEL_23;
    }
    if ( v9 )
    {
      BaseProperty::operator=(&p, (int)&v9->m_data);
      StringInfo::StringInfo(&tmp);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&tmp);
      v10 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x2Fu);
      if ( v10 )
      {
        v11 = (UIElement_Text *)v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
        if ( v11 )
          UIElement_Text::SetStringInfo(v11, &tmp);
      }
      StringInfo::~StringInfo(&tmp);
      v5 = p.m_pcPropertyDesc;
    }
  }
LABEL_23:
  if ( v5 )
  {
    v12 = v5->m_cRef-- == 1;
    if ( v12 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v13 = p.m_pcPropertyValue;
    v14 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v14;
    if ( !v14 )
      ((void (__stdcall *)(_DWORD))v13->vfptr->__vecDelDtor)(1);
  }
}

//----- (00475BE0) --------------------------------------------------------  // acclient.c:178857
int __thiscall ConfirmationTextInputDialog::ListenToElementMessage(ConfirmationTextInputDialog *this, UIElementMessageInfo *i_rMsg)
{
  ConfirmationTextInputDialog *v2; // ebx@1
  UIElement *v3; // eax@3
  UIElement_Text *v4; // esi@4
  PStringBase<unsigned short> *v5; // eax@5
  char *v6; // esi@7
  char *v7; // esi@10
  PStringBase<unsigned short> result; // [sp+Ch] [bp-10h]@5
  unsigned int _key; // [sp+10h] [bp-Ch]@13
  BaseProperty p; // [sp+14h] [bp-8h]@5

  v2 = this;
  if ( i_rMsg->idMessage != 1 )
    return Dialog::ListenToElementMessage((Dialog *)&this->vfptr, i_rMsg);
  if ( i_rMsg->idElement != 46 )
  {
    if ( i_rMsg->idElement == 47 )
    {
      ((void (__thiscall *)(_DWORD))this->vfptr[26].OnLoseFocus)(this);
      return 2;
    }
    return Dialog::ListenToElementMessage((Dialog *)&this->vfptr, i_rMsg);
  }
  v3 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x2Cu);
  if ( v3 )
  {
    v4 = (UIElement_Text *)v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
    if ( v4 )
    {
      p.m_pcPropertyDesc = 0;
      p.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&p, 0x9Cu);
      v5 = UIElement_Text::GetText(v4, &result);
      PStringBase<unsigned short>::to_spstring(v5, (PStringBase<char> *)&i_rMsg, 0);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[41].__vecDelDtor)(&i_rMsg);
      }
      v6 = (char *)&i_rMsg[-1].ptWindow;
      if ( !InterlockedDecrement(&i_rMsg[-1].ptWindow.y) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
      {
        if ( v7 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      }
      _key = (unsigned int)BaseProperty::GetPropertyName(&p);
      HashTable<unsigned long,BaseProperty,1>::add(
        (HashTable<unsigned long,BaseProperty,1> *)&v2->m_cData.m_hashProperties.vfptr,
        &_key,
        &p);
      BaseProperty::~BaseProperty(&p);
    }
  }
  DialogFactory::CloseDialog(v2->m_nContext);
  return 2;
}

//----- (00475D40) --------------------------------------------------------  // acclient.c:178919
void __thiscall ConfirmationTextInputDialog::CancelDialog(ConfirmationTextInputDialog *this)
{
  ConfirmationTextInputDialog *v1; // esi@1
  BasePropertyDesc *v2; // ecx@4
  unsigned int v3; // edx@4
  BasePropertyValue *v4; // ecx@8
  unsigned int v5; // edx@8
  unsigned int _key; // [sp+4h] [bp-Ch]@3
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = this;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x9Cu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[41].__vecDelDtor)(&PStringBase<char>::null_string);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&v1->m_cData.m_hashProperties.vfptr,
    &_key,
    &p);
  DialogFactory::CloseDialog(v1->m_nContext);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v2 = p.m_pcPropertyDesc;
    v3 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v3;
    if ( !v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v4 = p.m_pcPropertyValue;
    v5 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  }
}

//----- (006EC370) --------------------------------------------------------  // acclient.c:768052
int _E1_80()
{
  return atexit(_E2_80);
}

