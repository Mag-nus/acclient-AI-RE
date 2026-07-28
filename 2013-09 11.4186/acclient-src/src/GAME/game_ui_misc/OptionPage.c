/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : OptionPage
   Object     : GAME\game_ui_misc\OptionPage.obj
   Functions  : 15
   Addresses  : 004F2C60 - 006F8840 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F2C60) --------------------------------------------------------  // acclient.c:286825
char __thiscall OptionPage::SaveCurrentValues(OptionPage *this)
{
  OptionPage *v1; // esi@1
  unsigned int v2; // edi@1
  char v3; // bl@1
  UIOption *v4; // ecx@2

  v1 = this;
  v2 = 0;
  v3 = 1;
  if ( this->m_UIOptionArray.m_num )
  {
    do
    {
      v4 = v1->m_UIOptionArray.m_data[v2];
      if ( v4 )
        v3 &= ((int (*)(void))v4->vfptr[7].RecvNotice_WorldName)();
      ++v2;
    }
    while ( v2 < v1->m_UIOptionArray.m_num );
  }
  v1->vfptr->OnOptionChanged(&v1->vfptr, 0);
  return v3;
}

//----- (004F2CB0) --------------------------------------------------------  // acclient.c:286851
char __thiscall OptionPage::RestoreDefaultValues(OptionPage *this)
{
  OptionPage *v1; // esi@1
  unsigned int v2; // edi@1
  char v3; // bl@1
  UIOption *v4; // ecx@2

  v1 = this;
  v2 = 0;
  v3 = 1;
  if ( this->m_UIOptionArray.m_num )
  {
    do
    {
      v4 = v1->m_UIOptionArray.m_data[v2];
      if ( v4 )
        v3 &= ((int (*)(void))v4->vfptr[7].RecvNotice_ServerDied)();
      ++v2;
    }
    while ( v2 < v1->m_UIOptionArray.m_num );
  }
  v1->vfptr->OnOptionChanged(&v1->vfptr, 0);
  return v3;
}

//----- (004F2D00) --------------------------------------------------------  // acclient.c:286877
char __thiscall OptionPage::RestoreSavedValues(OptionPage *this)
{
  OptionPage *v1; // esi@1
  unsigned int v2; // edi@1
  char v3; // bl@1
  UIOption *v4; // ecx@2

  v1 = this;
  v2 = 0;
  v3 = 1;
  if ( this->m_UIOptionArray.m_num )
  {
    do
    {
      v4 = v1->m_UIOptionArray.m_data[v2];
      if ( v4 && (unsigned __int8)((int (*)(void))v4->vfptr[7].RecvNotice_SetSelectedItem)() )
        v3 &= ((int (*)(void))v1->m_UIOptionArray.m_data[v2]->vfptr[7].RecvNotice_CharacterError)();
      ++v2;
    }
    while ( v2 < v1->m_UIOptionArray.m_num );
  }
  v1->vfptr->OnOptionChanged(&v1->vfptr, 0);
  return v3;
}

//----- (004F2D60) --------------------------------------------------------  // acclient.c:286903
char __thiscall OptionPage::Changed(OptionPage *this)
{
  OptionPage *v1; // edi@1
  unsigned int v2; // esi@1
  UIOption *v3; // ecx@2
  char result; // al@5

  v1 = this;
  v2 = 0;
  if ( this->m_UIOptionArray.m_num )
  {
    while ( 1 )
    {
      v3 = v1->m_UIOptionArray.m_data[v2];
      if ( v3 )
      {
        if ( (unsigned __int8)((int (*)(void))v3->vfptr[7].RecvNotice_SetSelectedItem)() )
          break;
      }
      ++v2;
      if ( v2 >= v1->m_UIOptionArray.m_num )
        goto LABEL_5;
    }
    result = 1;
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (004F2DA0) --------------------------------------------------------  // acclient.c:286937
void __userpurge OptionPage::OptionPage(OptionPage *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  OptionPage *v4; // esi@1

  v4 = this;
  UIElement::UIElement((UIElement *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (IOptionChangeHandlerVtbl *)&OptionPage::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&OptionPage::vftable;
  v4->vfptr = (IOptionChangeHandlerVtbl *)&OptionPage::vftable;
  v4->m_UIOptionArray.m_data = 0;
  v4->m_UIOptionArray.m_sizeAndDeallocate = 0;
  v4->m_UIOptionArray.m_num = 0;
}
// 7C44E4: using guessed type void *OptionPage::vftable;
// 7C44F0: using guessed type int (__thiscall *OptionPage::vftable)(void *, char);

//----- (004F2DF0) --------------------------------------------------------  // acclient.c:286954
void __thiscall OptionPage::~OptionPage(OptionPage *this)
{
  UIElement *v1; // esi@1

  v1 = (UIElement *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&OptionPage::vftable;
  this->vfptr = (IOptionChangeHandlerVtbl *)&OptionPage::vftable;
  if ( (this->m_UIOptionArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_UIOptionArray.m_data);
  UIElement::~UIElement(v1);
}
// 7C44E4: using guessed type void *OptionPage::vftable;
// 7C44F0: using guessed type int (__thiscall *OptionPage::vftable)(void *, char);

//----- (004F2E30) --------------------------------------------------------  // acclient.c:286969
UIElement *__thiscall OptionPage::vector_deleting_destructor(OptionPage *this, unsigned int a2)
{
  UIElement *v2; // esi@1

  v2 = (UIElement *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&OptionPage::vftable;
  this->vfptr = (IOptionChangeHandlerVtbl *)&OptionPage::vftable;
  if ( (this->m_UIOptionArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_UIOptionArray.m_data);
  UIElement::~UIElement(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C44E4: using guessed type void *OptionPage::vftable;
// 7C44F0: using guessed type int (__thiscall *OptionPage::vftable)(void *, char);

//----- (004F2E90) --------------------------------------------------------  // acclient.c:286987
void __thiscall OptionPage::RegisterOption(OptionPage *this, UIOption *_option)
{
  OptionPage *v2; // edi@1
  char *v3; // esi@2
  unsigned int v4; // eax@2
  unsigned int v5; // eax@3

  v2 = this;
  if ( _option )
  {
    v3 = (char *)&this->m_UIOptionArray;
    v4 = this->m_UIOptionArray.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( this->m_UIOptionArray.m_num < v4
      || (v5 = SmartArray<UIChildFramework *,1>::get_new_size(v4 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v2->m_UIOptionArray, v5)) )
      *(_DWORD *)(*(_DWORD *)v3 + 4 * v2->m_UIOptionArray.m_num++) = _option;
    if ( v2 )
      _option->vfptr[7].RecvNotice_BeingDeleted((NoticeHandler *)_option, (CWeenieObject *)&v2->vfptr);
    else
      _option->vfptr[7].RecvNotice_BeingDeleted((NoticeHandler *)_option, 0);
  }
}

//----- (006F87B0) --------------------------------------------------------  // acclient.c:781245
void sub_6F87B0()
{
  flt_841090 = 1000.0 + 1.0;
}

//----- (006F87D0) --------------------------------------------------------  // acclient.c:781251
void sub_6F87D0()
{
  flt_841094 = 24.0 * 8.0;
}

//----- (006F87F0) --------------------------------------------------------  // acclient.c:781257
void sub_6F87F0()
{
  flt_841098 = 24.0 * 0.5;
}

//----- (006F8810) --------------------------------------------------------  // acclient.c:781263
int sub_6F8810()
{
  return atexit(nullsub_988);
}

//----- (006F8820) --------------------------------------------------------  // acclient.c:781269
int sub_6F8820()
{
  return atexit(nullsub_989);
}

//----- (006F8830) --------------------------------------------------------  // acclient.c:781275
int sub_6F8830()
{
  return atexit(nullsub_990);
}

//----- (006F8840) --------------------------------------------------------  // acclient.c:781281
int sub_6F8840()
{
  return atexit(nullsub_987);
}

