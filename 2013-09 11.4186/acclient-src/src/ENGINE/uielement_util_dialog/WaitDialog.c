/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : WaitDialog
   Object     : ENGINE\uielement_util_dialog\WaitDialog.obj
   Functions  : 8
   Addresses  : 00474C60 - 006EC330 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00474C60) --------------------------------------------------------  // acclient.c:177856
void __thiscall Dialog::SetContext(Dialog *this, unsigned int i_nContext)
{
  this->m_nContext = i_nContext;
}

//----- (00474C70) --------------------------------------------------------  // acclient.c:177862
WaitDialog *__thiscall WaitDialog::DynamicCast(WaitDialog *this, unsigned int i_eType)
{
  WaitDialog *result; // eax@1

  result = this;
  if ( i_eType != 25 )
    result = (WaitDialog *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00474C90) --------------------------------------------------------  // acclient.c:177873
UIElement *__usercall WaitDialog::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x698u);
  if ( v3 )
  {
    Dialog::Dialog((Dialog *)v3, a1, _layout, _full_desc);
    *(_DWORD *)v3 = &WaitDialog::vftable;
    *((_DWORD *)v3 + 420) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79D620: using guessed type int (__thiscall *WaitDialog::vftable)(void *, char);

//----- (00474CD0) --------------------------------------------------------  // acclient.c:177895
void __thiscall WaitDialog::ListenToGlobalMessage(WaitDialog *this, unsigned int i_eMessageID, int i_nData)
{
  unsigned int v3; // eax@2

  if ( i_eMessageID == 1 )
  {
    v3 = this->m_eKey;
    if ( v3 )
    {
      if ( i_nData == v3 )
        DialogFactory::CloseDialog(this->m_nContext);
    }
  }
}

//----- (00474D20) --------------------------------------------------------  // acclient.c:177917
WaitDialog *__thiscall WaitDialog::vector_deleting_destructor(WaitDialog *this, unsigned int a2)
{
  WaitDialog *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&WaitDialog::vftable;
  Dialog::~Dialog((Dialog *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79D620: using guessed type int (__thiscall *WaitDialog::vftable)(void *, char);

//----- (00474D50) --------------------------------------------------------  // acclient.c:177931
void __cdecl WaitDialog::Register()
{
  UIElement::RegisterElementClass(0x19u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))WaitDialog::Create);
}

//----- (00474D60) --------------------------------------------------------  // acclient.c:177937
void __thiscall WaitDialog::SetData(WaitDialog *this, PropertyCollection *i_cData)
{
  WaitDialog *v2; // esi@1
  unsigned int v3; // edx@1
  HashTableData<unsigned long,BaseProperty> **v4; // ecx@1
  HashTableData<unsigned long,BaseProperty> *v5; // eax@1
  BasePropertyDesc *v6; // ecx@9
  unsigned int v7; // edx@9
  BasePropertyValue *v8; // ecx@13
  unsigned int v9; // edx@13
  BaseProperty p; // [sp+8h] [bp-98h]@1
  StringInfo tmp; // [sp+10h] [bp-90h]@6

  v2 = this;
  Dialog::SetData((Dialog *)&this->vfptr, i_cData);
  v3 = 0x9E % v2->m_cData.m_hashProperties.m_intrusiveTable.m_numBuckets;
  v4 = v2->m_cData.m_hashProperties.m_intrusiveTable.m_buckets;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v5 = v4[v3];
  if ( v5 )
  {
    while ( v5->m_hashKey != 158 )
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
        ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&v2->m_eKey);
      UIListener::RegisterForGlobalMessage((UIListener *)&v2->vfptr, 1u);
      StringInfo::~StringInfo(&tmp);
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v6 = p.m_pcPropertyDesc;
        v7 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v7;
        if ( !v7 )
          ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyDesc = 0;
      }
      if ( p.m_pcPropertyValue )
      {
        v8 = p.m_pcPropertyValue;
        v9 = p.m_pcPropertyValue->m_cRef - 1;
        p.m_pcPropertyValue->m_cRef = v9;
        if ( !v9 )
          ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (006EC330) --------------------------------------------------------  // acclient.c:768028
int _E1_76()
{
  return atexit(_E2_76);
}

