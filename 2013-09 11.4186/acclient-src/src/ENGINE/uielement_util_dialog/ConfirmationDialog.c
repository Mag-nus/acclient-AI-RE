/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ConfirmationDialog
   Object     : ENGINE\uielement_util_dialog\ConfirmationDialog.obj
   Functions  : 9
   Addresses  : 00476400 - 006EC390 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00476400) --------------------------------------------------------  // acclient.c:179336
ConfirmationDialog *__thiscall ConfirmationDialog::DynamicCast(ConfirmationDialog *this, unsigned int i_eType)
{
  ConfirmationDialog *result; // eax@1

  result = this;
  if ( i_eType != 19 )
    result = (ConfirmationDialog *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00476420) --------------------------------------------------------  // acclient.c:179347
Dialog *__usercall ConfirmationDialog::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  Dialog *v3; // esi@1
  Dialog *result; // eax@2

  v3 = (Dialog *)operator new(0x690u);
  if ( v3 )
  {
    Dialog::Dialog(v3, a1, _layout, _full_desc);
    v3->vfptr = (IInputActionCallbackVtbl *)&ConfirmationDialog::vftable;
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79DDD0: using guessed type int (__thiscall *ConfirmationDialog::vftable)(void *, char);

//----- (00476460) --------------------------------------------------------  // acclient.c:179368
int __thiscall UIElement::GetChildRecursiveTemplate<UIElement_Text>(UIElement *this, unsigned int _ID)
{
  UIElement *v2; // eax@1
  int result; // eax@2

  v2 = UIElement::GetChildRecursive(this, _ID);
  if ( v2 )
    result = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    result = 0;
  return result;
}

//----- (00476490) --------------------------------------------------------  // acclient.c:179382
ConfirmationDialog *__thiscall ConfirmationDialog::vector_deleting_destructor(ConfirmationDialog *this, unsigned int a2)
{
  ConfirmationDialog *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&ConfirmationDialog::vftable;
  Dialog::~Dialog((Dialog *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79DDD0: using guessed type int (__thiscall *ConfirmationDialog::vftable)(void *, char);

//----- (004764C0) --------------------------------------------------------  // acclient.c:179396
void __cdecl ConfirmationDialog::Register()
{
  UIElement::RegisterElementClass(
    0x13u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))ConfirmationDialog::Create);
}

//----- (004764D0) --------------------------------------------------------  // acclient.c:179404
void __thiscall ConfirmationDialog::SetData(ConfirmationDialog *this, PropertyCollection *i_cData)
{
  ConfirmationDialog *v2; // esi@1
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
  v3 = 0x90 % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets;
  v4 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets;
  v5 = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v6 = v4[v3];
  if ( v6 )
  {
    while ( v6->m_hashKey != 144 )
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
      v7 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x17u);
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
  v9 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0x91
                                                             % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v9 )
  {
    while ( v9->m_hashKey != 145 )
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
      v10 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x19u);
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

//----- (00476670) --------------------------------------------------------  // acclient.c:179502
int __thiscall ConfirmationDialog::ListenToElementMessage(ConfirmationDialog *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  ConfirmationDialog *v3; // esi@1
  int result; // eax@1
  BasePropertyDesc *v5; // ecx@8
  unsigned int v6; // edx@8
  BasePropertyValue *v7; // ecx@11
  bool v8; // zf@12
  BaseProperty p; // [sp+8h] [bp-8h]@5

  v2 = i_rMsg;
  v3 = this;
  result = 0;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 25 || i_rMsg->idElement == 23 )
    {
      p.m_pcPropertyDesc = 0;
      p.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&p, 0x92u);
      LOBYTE(i_rMsg) = v2->idElement == 23;
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(i_rMsg);
      }
      i_rMsg = (UIElementMessageInfo *)BaseProperty::GetPropertyName(&p);
      HashTable<unsigned long,BaseProperty,1>::add(
        (HashTable<unsigned long,BaseProperty,1> *)&v3->m_cData.m_hashProperties.vfptr,
        (const unsigned int *)&i_rMsg,
        &p);
      DialogFactory::CloseDialog(v3->m_nContext);
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v5 = p.m_pcPropertyDesc;
        v6 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v6;
        if ( !v6 )
          ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyDesc = 0;
      }
      v7 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        v8 = p.m_pcPropertyValue->m_cRef-- == 1;
        if ( v8 )
          ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
      }
      result = 2;
    }
  }
  else
  {
    result = Dialog::ListenToElementMessage((Dialog *)&this->vfptr, i_rMsg);
  }
  return result;
}

//----- (00476770) --------------------------------------------------------  // acclient.c:179562
void __thiscall ConfirmationDialog::CancelDialog(ConfirmationDialog *this)
{
  ConfirmationDialog *v1; // esi@1
  BasePropertyDesc *v2; // ecx@4
  unsigned int v3; // edx@4
  BasePropertyValue *v4; // ecx@8
  unsigned int v5; // edx@8
  unsigned int _key; // [sp+4h] [bp-Ch]@3
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = this;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x92u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(0);
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

//----- (006EC390) --------------------------------------------------------  // acclient.c:768064
int _E1_82()
{
  return atexit(_E2_82);
}

