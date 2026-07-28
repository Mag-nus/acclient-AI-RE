/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MenuDialog
   Object     : ENGINE\uielement_util_dialog\MenuDialog.obj
   Functions  : 8
   Addresses  : 00475450 - 006EC360 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00475450) --------------------------------------------------------  // acclient.c:178368
MenuDialog *__thiscall MenuDialog::DynamicCast(MenuDialog *this, unsigned int i_eType)
{
  MenuDialog *result; // eax@1

  result = this;
  if ( i_eType != 22 )
    result = (MenuDialog *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00475470) --------------------------------------------------------  // acclient.c:178379
UIElement *__usercall MenuDialog::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x698u);
  if ( v3 )
  {
    Dialog::Dialog((Dialog *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &MenuDialog::vftable;
    *((_DWORD *)v3 + 420) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79D9F8: using guessed type int (__thiscall *MenuDialog::vftable)(void *, char);

//----- (004754B0) --------------------------------------------------------  // acclient.c:178401
MenuDialog *__thiscall MenuDialog::vector_deleting_destructor(MenuDialog *this, unsigned int a2)
{
  MenuDialog *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&MenuDialog::vftable;
  Dialog::~Dialog((Dialog *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D9F8: using guessed type int (__thiscall *MenuDialog::vftable)(void *, char);

//----- (004754E0) --------------------------------------------------------  // acclient.c:178415
void __cdecl MenuDialog::Register()
{
  UIElement::RegisterElementClass(0x16u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))MenuDialog::Create);
}

//----- (004754F0) --------------------------------------------------------  // acclient.c:178421
void __thiscall MenuDialog::SetData(MenuDialog *this, PropertyCollection *i_cData)
{
  MenuDialog *v2; // edi@1
  UIElement *v3; // eax@1
  int v4; // eax@2
  HashTableData<unsigned long,BaseProperty> *v5; // eax@5
  unsigned int v6; // esi@12
  BasePropertyValue *v7; // ecx@13
  int v8; // eax@18
  BasePropertyDesc *v9; // ecx@23
  unsigned int v10; // esi@23
  BasePropertyValue *v11; // ecx@27
  unsigned int v12; // edx@27
  UIElement *v13; // eax@29
  HashTableData<unsigned long,BaseProperty> *v14; // eax@30
  UIElement *v15; // eax@37
  HashTableData<unsigned long,BaseProperty> *v16; // eax@38
  UIElement *v17; // eax@45
  UIElement_Text *v18; // eax@46
  BasePropertyDesc *v19; // ecx@50
  unsigned int v20; // edx@50
  BasePropertyValue *v21; // ecx@54
  unsigned int v22; // edx@54
  BaseProperty p; // [sp+28h] [bp-A4h]@1
  int nItem; // [sp+30h] [bp-9Ch]@11
  BaseProperty menuItem; // [sp+34h] [bp-98h]@12
  StringInfo tmp; // [sp+3Ch] [bp-90h]@16

  v2 = this;
  Dialog::SetData((Dialog *)&this->vfptr, i_cData);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v3 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x1Du);
  if ( v3 )
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)6);
  else
    v4 = 0;
  v2->m_pcMenu = (UIElement_Menu *)v4;
  if ( v4 )
  {
    v5 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xA0
                                                               % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
    if ( v5 )
    {
      while ( v5->m_hashKey != 160 )
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
  v14 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xA4
                                                              % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v14 )
  {
    while ( v14->m_hashKey != 164 )
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
  v16 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets[0xA2
                                                              % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( v16 )
  {
    while ( v16->m_hashKey != 162 )
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
      v17 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x1Eu);
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
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v19 = p.m_pcPropertyDesc;
    v20 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v20;
    if ( !v20 )
      ((void (__stdcall *)(_DWORD))v19->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v21 = p.m_pcPropertyValue;
    v22 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v22;
    if ( !v22 )
      ((void (__stdcall *)(_DWORD))v21->vfptr->__vecDelDtor)(1);
  }
}

//----- (004757E0) --------------------------------------------------------  // acclient.c:178600
int __thiscall MenuDialog::ListenToElementMessage(MenuDialog *this, UIElementMessageInfo *i_rMsg)
{
  MenuDialog *v2; // esi@1
  int result; // eax@1
  unsigned int v4; // edi@4
  BasePropertyDesc *v5; // ecx@7
  unsigned int v6; // edx@7
  BasePropertyValue *v7; // ecx@10
  bool v8; // zf@11
  BaseProperty p; // [sp+8h] [bp-8h]@4

  v2 = this;
  result = 0;
  if ( i_rMsg->idMessage == 1 )
  {
    if ( i_rMsg->idElement == 30 )
    {
      p.m_pcPropertyDesc = 0;
      p.m_pcPropertyValue = 0;
      BaseProperty::SetPropertyName(&p, 0xA4u);
      v4 = UIElement_Menu::GetSelectedIndex(v2->m_pcMenu);
      if ( p.m_pcPropertyValue )
      {
        BaseProperty::CheckCopyOnWrite(&p);
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[31].__vecDelDtor)(v4);
      }
      i_rMsg = (UIElementMessageInfo *)BaseProperty::GetPropertyName(&p);
      HashTable<unsigned long,BaseProperty,1>::set(
        (HashTable<unsigned long,BaseProperty,1> *)&v2->m_cData.m_hashProperties.vfptr,
        (const unsigned int *)&i_rMsg,
        &p);
      DialogFactory::CloseDialog(v2->m_nContext);
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

//----- (004758E0) --------------------------------------------------------  // acclient.c:178659
void __thiscall MenuDialog::CancelDialog(MenuDialog *this)
{
  MenuDialog *v1; // esi@1
  BasePropertyDesc *v2; // ecx@4
  unsigned int v3; // edx@4
  BasePropertyValue *v4; // ecx@8
  unsigned int v5; // edx@8
  unsigned int _key; // [sp+4h] [bp-Ch]@3
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = this;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0xA4u);
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

//----- (006EC360) --------------------------------------------------------  // acclient.c:768046
int _E1_79()
{
  return atexit(_E2_79);
}

