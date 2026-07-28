/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextInputDialog
   Object     : ENGINE\uielement_util_dialog\TextInputDialog.obj
   Functions  : 9
   Addresses  : 00474E60 - 006EC340 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00474E60) --------------------------------------------------------  // acclient.c:177995
TextInputDialog *__thiscall TextInputDialog::DynamicCast(TextInputDialog *this, unsigned int i_eType)
{
  TextInputDialog *result; // eax@1

  result = this;
  if ( i_eType != 24 )
    result = (TextInputDialog *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00474E80) --------------------------------------------------------  // acclient.c:178006
Dialog *__usercall TextInputDialog::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  Dialog *v3; // esi@1
  Dialog *result; // eax@2

  v3 = (Dialog *)operator new(0x690u);
  if ( v3 )
  {
    Dialog::Dialog(v3, a1, _layout, _full_desc);
    v3->vfptr = (IInputActionCallbackVtbl *)&TextInputDialog::vftable;
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79D768: using guessed type int (__thiscall *TextInputDialog::vftable)(void *, char);

//----- (00474EC0) --------------------------------------------------------  // acclient.c:178027
TextInputDialog *__thiscall TextInputDialog::scalar_deleting_destructor(TextInputDialog *this, unsigned int a2)
{
  TextInputDialog *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&TextInputDialog::vftable;
  Dialog::~Dialog((Dialog *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D768: using guessed type int (__thiscall *TextInputDialog::vftable)(void *, char);

//----- (00474EF0) --------------------------------------------------------  // acclient.c:178041
void __cdecl TextInputDialog::Register()
{
  UIElement::RegisterElementClass(0x18u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))TextInputDialog::Create);
}

//----- (00474F00) --------------------------------------------------------  // acclient.c:178047
void __thiscall TextInputDialog::SetData(TextInputDialog *this, PropertyCollection *i_cData)
{
  TextInputDialog *v2; // esi@1
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
  v3 = 0x97 % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets;
  v4 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v5 = v4[v3];
  if ( v5 )
  {
    while ( v5->m_hashKey != 151 )
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
      v6 = UIElement::GetChildRecursive((UIElement *)&v2->vfptr, 0x2Au);
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

//----- (00475020) --------------------------------------------------------  // acclient.c:178113
char __thiscall PropertyCollection::AddProperty(PropertyCollection *this, BaseProperty *_property)
{
  BaseProperty *v2; // edi@1
  PropertyCollection *v3; // esi@1

  v2 = _property;
  v3 = this;
  _property = (BaseProperty *)BaseProperty::GetPropertyName(_property);
  return HashTable<unsigned long,BaseProperty,1>::add(
           (HashTable<unsigned long,BaseProperty,1> *)&v3->m_hashProperties.vfptr,
           (const unsigned int *)&_property,
           v2);
}

//----- (00475050) --------------------------------------------------------  // acclient.c:178128
int __thiscall TextInputDialog::ListenToElementMessage(TextInputDialog *this, UIElementMessageInfo *i_rMsg)
{
  TextInputDialog *v2; // ebx@1
  UIElement *v3; // eax@3
  UIElement_Text *v4; // esi@4
  PStringBase<unsigned short> *v5; // eax@5
  char *v6; // esi@7
  char *v7; // esi@10
  int v8; // eax@14
  PStringBase<unsigned short> result; // [sp+Ch] [bp-10h]@5
  unsigned int _key; // [sp+10h] [bp-Ch]@13
  BaseProperty p; // [sp+14h] [bp-8h]@5

  v2 = this;
  if ( i_rMsg->idElement != 42 || i_rMsg->idMessage != 1 )
  {
    v8 = Dialog::ListenToElementMessage((Dialog *)&this->vfptr, i_rMsg);
  }
  else
  {
    v3 = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x2Bu);
    if ( v3 )
    {
      v4 = (UIElement_Text *)v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
      if ( v4 )
      {
        p.m_pcPropertyDesc = 0;
        p.m_pcPropertyValue = 0;
        BaseProperty::SetPropertyName(&p, 0x98u);
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
    v8 = 2;
  }
  return v8;
}

//----- (00475190) --------------------------------------------------------  // acclient.c:178188
void __thiscall TextInputDialog::CancelDialog(TextInputDialog *this)
{
  TextInputDialog *v1; // esi@1
  BasePropertyDesc *v2; // ecx@4
  unsigned int v3; // edx@4
  BasePropertyValue *v4; // ecx@8
  unsigned int v5; // edx@8
  unsigned int _key; // [sp+4h] [bp-Ch]@3
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = this;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x98u);
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

//----- (006EC340) --------------------------------------------------------  // acclient.c:768034
int _E1_77()
{
  return atexit(_E2_77);
}

