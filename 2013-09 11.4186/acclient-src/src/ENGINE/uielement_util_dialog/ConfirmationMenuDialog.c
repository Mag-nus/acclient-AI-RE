/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ConfirmationMenuDialog
   Object     : ENGINE\uielement_util_dialog\ConfirmationMenuDialog.obj
   Functions  : 8
   Addresses  : 00475E10 - 006EC380 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00475E10) --------------------------------------------------------  // acclient.c:178964
ConfirmationMenuDialog *__thiscall ConfirmationMenuDialog::DynamicCast(ConfirmationMenuDialog *this, unsigned int i_eType)
{
  ConfirmationMenuDialog *result; // eax@1

  result = this;
  if ( i_eType != 20 )
    result = (ConfirmationMenuDialog *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00475E30) --------------------------------------------------------  // acclient.c:178975
UIElement *__usercall ConfirmationMenuDialog::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x698u);
  if ( v3 )
  {
    Dialog::Dialog((Dialog *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &ConfirmationMenuDialog::vftable;
    *((_DWORD *)v3 + 420) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79DC88: using guessed type int (__thiscall *ConfirmationMenuDialog::vftable)(void *, char);

//----- (00475E70) --------------------------------------------------------  // acclient.c:178997
ConfirmationMenuDialog *__thiscall ConfirmationMenuDialog::vector_deleting_destructor(ConfirmationMenuDialog *this, unsigned int a2)
{
  ConfirmationMenuDialog *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&ConfirmationMenuDialog::vftable;
  Dialog::~Dialog((Dialog *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79DC88: using guessed type int (__thiscall *ConfirmationMenuDialog::vftable)(void *, char);

//----- (00475EA0) --------------------------------------------------------  // acclient.c:179011
void __cdecl ConfirmationMenuDialog::Register()
{
  UIElement::RegisterElementClass(
    0x14u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))ConfirmationMenuDialog::Create);
}

//----- (00475EB0) --------------------------------------------------------  // acclient.c:179019
void __thiscall ConfirmationMenuDialog::SetData(ConfirmationMenuDialog *this, PropertyCollection *i_cData)
{
  ConfirmationMenuDialog *v2; // esi@1
  UIElement *v3; // eax@1
  int v4; // eax@2
  HashTableData<unsigned long,BaseProperty> *v5; // eax@5
  unsigned int v6; // edi@12
  BasePropertyValue *v7; // ecx@13
  int v8; // eax@18
  BasePropertyDesc *v9; // ecx@23
  unsigned int v10; // edi@23
  BasePropertyValue *v11; // ecx@27
  unsigned int v12; // edx@27
  UIElement *v13; // eax@29
  HashTableData<unsigned long,BaseProperty> *v14; // eax@30
  UIElement *v15; // eax@37
  HashTableData<unsigned long,BaseProperty> *v16; // eax@38
  UIElement *v17; // eax@45
  UIElement_Text *v18; // eax@46
  HashTableData<unsigned long,BaseProperty> *v19; // eax@49
  UIElement *v20; // eax@56
  UIElement_Text *v21; // eax@57
  BasePropertyDesc *v22; // ecx@61
  unsigned int v23; // edx@61
  BasePropertyValue *v24; // ecx@65
  unsigned int v25; // edx@65
  BaseProperty p; // [sp+30h] [bp-A4h]@1
  int nItem; // [sp+38h] [bp-9Ch]@11
  BaseProperty menuItem; // [sp+3Ch] [bp-98h]@12
  StringInfo tmp; // [sp+44h] [bp-90h]@16

  v2 = this;
  Dialog::SetData((Dialog *)&this->vfptr, i_cData);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v3 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x21u);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)6);
  else
    v4 = 0;
  v2->m_pcMenu = (UIElement_Menu *)v4;
  if ( v4 )
  {
    v5 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xA6
                                                               % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
    if ( v5 )
    {
      while ( v5->m_hashKey != 166 )
      {
        v5 = v5->m_hashNext;
        if ( !v5 )
          goto LABEL_30;
      }
      if ( v5 )
      {
        BaseProperty::operator=(&p, (int)&v5->m_data);
        if ( p.m_pcPropertyValue )
        {
          if ( (unsigned __int8)((int (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&nItem) )
          {
            v6 = 0;
            menuItem.m_pcPropertyDesc = 0;
            menuItem.m_pcPropertyValue = 0;
            if ( (unsigned int)nItem > 0 )
            {
              v7 = p.m_pcPropertyValue;
              do
              {
                if ( v7 )
                {
                  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v7->vfptr[61].__vecDelDtor)(
                                          v6,
                                          &menuItem) )
                  {
                    StringInfo::StringInfo(&tmp);
                    if ( menuItem.m_pcPropertyValue
                      && (unsigned __int8)((int (__stdcall *)(_DWORD))menuItem.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&tmp) )
                    {
                      v8 = UIElement_Menu::GetNumItems(v2->m_pcMenu);
                      UIElement_Menu::InsertTextItem(v2->m_pcMenu, &tmp, v8);
                    }
                    StringInfo::~StringInfo(&tmp);
                  }
                  v7 = p.m_pcPropertyValue;
                }
                ++v6;
              }
              while ( v6 < nItem );
              if ( (_DWORD)menuItem.m_pcPropertyDesc )
              {
                v9 = menuItem.m_pcPropertyDesc;
                v10 = menuItem.m_pcPropertyDesc->m_cRef - 1;
                menuItem.m_pcPropertyDesc->m_cRef = v10;
                if ( !v10 )
                  ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
                menuItem.m_pcPropertyDesc = 0;
              }
              if ( menuItem.m_pcPropertyValue )
              {
                v11 = menuItem.m_pcPropertyValue;
                v12 = menuItem.m_pcPropertyValue->m_cRef - 1;
                menuItem.m_pcPropertyValue->m_cRef = v12;
                if ( !v12 )
                  ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
              }
            }
          }
        }
        v13 = UIElement_Menu::GetItem(v2->m_pcMenu, 0);
        UIElement_Menu::SetSelectedItem(v2->m_pcMenu, v13, 1);
      }
    }
  }
LABEL_30:
  v14 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xAB
                                                              % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v14 )
  {
    while ( v14->m_hashKey != 171 )
    {
      v14 = v14->m_hashNext;
      if ( !v14 )
        goto LABEL_38;
    }
    if ( v14 )
    {
      BaseProperty::operator=(&p, (int)&v14->m_data);
      nItem = 0;
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[30].__vecDelDtor)(&nItem);
      v15 = UIElement_Menu::GetItem(v2->m_pcMenu, nItem);
      UIElement_Menu::SetSelectedItem(v2->m_pcMenu, v15, 1);
    }
  }
LABEL_38:
  v16 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xA8
                                                              % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v16 )
  {
    while ( v16->m_hashKey != 168 )
    {
      v16 = v16->m_hashNext;
      if ( !v16 )
        goto LABEL_49;
    }
    if ( v16 )
    {
      BaseProperty::operator=(&p, (int)&v16->m_data);
      StringInfo::StringInfo(&tmp);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&tmp);
      v17 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x22u);
      if ( v17 )
      {
        v18 = (UIElement_Text *)v17->vfptr[12].OnAction((IInputActionCallback *)v17, (InputEvent *)12);
        if ( v18 )
          UIElement_Text::SetStringInfo(v18, &tmp);
      }
      StringInfo::~StringInfo(&tmp);
    }
  }
LABEL_49:
  v19 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xA9
                                                              % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v19 )
  {
    while ( v19->m_hashKey != 169 )
    {
      v19 = v19->m_hashNext;
      if ( !v19 )
        goto LABEL_60;
    }
    if ( v19 )
    {
      BaseProperty::operator=(&p, (int)&v19->m_data);
      StringInfo::StringInfo(&tmp);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[48].__vecDelDtor)(&tmp);
      v20 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x23u);
      if ( v20 )
      {
        v21 = (UIElement_Text *)v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)12);
        if ( v21 )
          UIElement_Text::SetStringInfo(v21, &tmp);
      }
      StringInfo::~StringInfo(&tmp);
    }
  }
LABEL_60:
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v22 = p.m_pcPropertyDesc;
    v23 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v23;
    if ( !v23 )
      ((void (__stdcall *)(_DWORD))v22->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v24 = p.m_pcPropertyValue;
    v25 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v25;
    if ( !v25 )
      ((void (__stdcall *)(_DWORD))v24->vfptr->__vecDelDtor)(1);
  }
}

//----- (00476230) --------------------------------------------------------  // acclient.c:179228
int __thiscall ConfirmationMenuDialog::ListenToElementMessage(ConfirmationMenuDialog *this, UIElementMessageInfo *i_rMsg)
{
  ConfirmationMenuDialog *v2; // esi@1
  int result; // eax@1
  unsigned int v4; // edx@3
  unsigned int v5; // edi@5
  BasePropertyDesc *v6; // ecx@10
  unsigned int v7; // edx@10
  BasePropertyValue *v8; // ecx@13
  bool v9; // zf@14
  BaseProperty p; // [sp+8h] [bp-8h]@7

  v2 = this;
  result = 0;
  if ( i_rMsg->idMessage == 1 )
  {
    v4 = i_rMsg->idElement;
    if ( i_rMsg->idElement == 34 || v4 == 35 )
    {
      v5 = -1;
      if ( v4 == 34 )
        v5 = UIElement_Menu::GetSelectedIndex(this->m_pcMenu);
      p.m_pcPropertyDesc = 0;
      p.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&p, 0xABu);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v5);
      }
      i_rMsg = (UIElementMessageInfo *)BaseProperty::GetPropertyName(&p);
      HashTable<unsigned long,BaseProperty,1>::set(
        (HashTable<unsigned long,BaseProperty,1> *)&v2->m_cData.m_hashProperties.vfptr,
        (const unsigned int *)&i_rMsg,
        &p);
      DialogFactory::CloseDialog(v2->m_nContext);
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v6 = p.m_pcPropertyDesc;
        v7 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v7;
        if ( !v7 )
          ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyDesc = 0;
      }
      v8 = p.m_pcPropertyValue;
      if ( p.m_pcPropertyValue )
      {
        v9 = p.m_pcPropertyValue->m_cRef-- == 1;
        if ( v9 )
          ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
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

//----- (00476340) --------------------------------------------------------  // acclient.c:179291
void __thiscall ConfirmationMenuDialog::CancelDialog(ConfirmationMenuDialog *this)
{
  ConfirmationMenuDialog *v1; // esi@1
  BasePropertyDesc *v2; // ecx@4
  unsigned int v3; // edx@4
  BasePropertyValue *v4; // ecx@8
  unsigned int v5; // edx@8
  unsigned int _key; // [sp+4h] [bp-Ch]@3
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = this;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0xABu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[31].__vecDelDtor)(-1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::set(
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

//----- (006EC380) --------------------------------------------------------  // acclient.c:768058
int _E1_81()
{
  return atexit(_E2_81);
}

