/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption_CheckboxBitfield64
   Object     : GAME\game_ui_misc\UIOption_CheckboxBitfield64.obj
   Functions  : 36
   Addresses  : 00485660 - 006ED610 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00485660) --------------------------------------------------------  // acclient.c:193048
void __thiscall UIOption_CheckboxBitfield64::ChildInfo::ChildInfo(UIOption_CheckboxBitfield64::ChildInfo *this)
{
  UIOption_CheckboxBitfield64::ChildInfo *v1; // esi@1

  v1 = this;
  this->llMask = 0i64;
  StringInfo::StringInfo(&this->siLabel);
  StringInfo::StringInfo(&v1->siTooltip);
}

//----- (004856A0) --------------------------------------------------------  // acclient.c:193059
BOOL __thiscall UIOption_CheckboxBitfield64::Changed(UIOption_CheckboxBitfield64 *this)
{
  return LODWORD(this->m_saved) != LODWORD(this->m_current) || HIDWORD(this->m_saved) != HIDWORD(this->m_current);
}

//----- (004856D0) --------------------------------------------------------  // acclient.c:193065
char __thiscall UIOption_CheckboxBitfield64::SaveCurrentValue(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // esi@1
  int v2; // eax@1
  int v3; // edx@1

  v1 = this;
  v2 = ((int (*)(void))this->vfptr[7].RecvNotice_DisplayStringInfo)();
  LODWORD(v1->m_current) = v2;
  LODWORD(v1->m_saved) = v2;
  HIDWORD(v1->m_current) = v3;
  HIDWORD(v1->m_saved) = v3;
  return 1;
}

//----- (00485700) --------------------------------------------------------  // acclient.c:193081
char __thiscall UIOption_CheckboxBitfield64::RestoreSavedValue(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_saved;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_CheckboxBitfield64 *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00485740) --------------------------------------------------------  // acclient.c:193095
char __thiscall UIOption_CheckboxBitfield64::RestoreDefaultValue(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // esi@1
  NoticeHandlerVtbl *v2; // edx@1

  v1 = this;
  v2 = this->vfptr;
  this->m_current = this->m_default;
  ((void (__stdcall *)(_DWORD))v2[7].RecvNotice_CloseDialog)(0);
  ((void (__thiscall *)(UIOption_CheckboxBitfield64 *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
  return 1;
}

//----- (00485780) --------------------------------------------------------  // acclient.c:193109
void __thiscall UIOption_CheckboxBitfield64::SetDefaultValue(UIOption_CheckboxBitfield64 *this, unsigned __int64 _default)
{
  this->m_default = _default;
}

//----- (004857A0) --------------------------------------------------------  // acclient.c:193115
void __thiscall UIOption_CheckboxBitfield64::RecvNotice_ReloadOptions(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // esi@1
  int v2; // eax@1
  int v3; // edx@1
  NoticeHandlerVtbl *v4; // edx@1

  v1 = this;
  v2 = ((int (*)(void))this->vfptr[7].RecvNotice_DisplayStringInfo)();
  HIDWORD(v1->m_current) = v3;
  v4 = v1->vfptr;
  LODWORD(v1->m_current) = v2;
  ((void (__thiscall *)(UIOption_CheckboxBitfield64 *))v4[7].RecvNotice_ServerSaysMoveItem)(v1);
}

//----- (004857D0) --------------------------------------------------------  // acclient.c:193131
unsigned __int64 *__cdecl BitUtils::SetBitsOnOrOff(unsigned __int64 *x, unsigned __int64 y, bool bSet)
{
  unsigned __int64 *result; // eax@1
  int v4; // ecx@2
  int v5; // ecx@3

  result = x;
  if ( bSet )
  {
    v4 = *((_DWORD *)x + 1);
    *(_DWORD *)x |= y;
    *((_DWORD *)x + 1) = HIDWORD(y) | v4;
  }
  else
  {
    v5 = ~HIDWORD(y) & *((_DWORD *)x + 1);
    *(_DWORD *)x &= ~(_DWORD)y;
    *((_DWORD *)x + 1) = v5;
  }
  return result;
}

//----- (00485810) --------------------------------------------------------  // acclient.c:193154
void *__thiscall UIOption_CheckboxBitfield64::ChildInfo::vector_deleting_destructor(UIOption_CheckboxBitfield64::ChildInfo *this, unsigned int a2)
{
  UIOption_CheckboxBitfield64::ChildInfo *v2; // esi@1
  PSRefBufferCharData<char> *v3; // ecx@2
  void *v4; // ebp@2
  int v5; // eax@2
  int v6; // ecx@2
  int v7; // esi@3
  int v8; // edi@3
  void *result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].siTooltip.m_strComment.m_charbuffer;
    v4 = &v2[-1].siTooltip.m_strComment;
    v5 = (int)&v2[(_DWORD)v3];
    v6 = (int)&v3[-1].m_data[15];
    if ( v6 >= 0 )
    {
      v7 = v5 + 8;
      v8 = v6 + 1;
      do
      {
        v7 -= 296;
        StringInfo::~StringInfo((StringInfo *)(v7 + 144));
        StringInfo::~StringInfo((StringInfo *)v7);
        --v8;
      }
      while ( v8 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    StringInfo::~StringInfo(&this->siTooltip);
    StringInfo::~StringInfo(&v2->siLabel);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (004858A0) --------------------------------------------------------  // acclient.c:193201
int __thiscall UIOption_CheckboxBitfield64::ChildInfo::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  StringInfo::operator=((StringInfo *)(this + 8), a2 + 8);
  StringInfo::operator=((StringInfo *)(v2 + 152), a2 + 152);
  return v2;
}

//----- (004858E0) --------------------------------------------------------  // acclient.c:193214
void __thiscall SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1>::Reset(SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1> *this)
{
  SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  int v6; // ebp@7
  int v7; // esi@8
  StringInfo v8; // [sp+10h] [bp-120h]@8
  StringInfo v9; // [sp+A0h] [bp-90h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      UIOption_CheckboxBitfield64::ChildInfo::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v6 = v4 + 1;
      do
      {
        StringInfo::StringInfo(&v8);
        StringInfo::StringInfo(&v9);
        v7 = (int)&v1->m_data[v5];
        *(_DWORD *)v7 = 0;
        *(_DWORD *)(v7 + 4) = 0;
        StringInfo::operator=((StringInfo *)(v7 + 8), (int)&v8);
        StringInfo::operator=((StringInfo *)(v7 + 152), (int)&v9);
        StringInfo::~StringInfo(&v9);
        StringInfo::~StringInfo(&v8);
        --v5;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (004859C0) --------------------------------------------------------  // acclient.c:193264
void __thiscall UIOption_CheckboxBitfield64::Refresh(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // edi@1
  int v2; // ebp@1
  UIOption_CheckboxBitfield64::ChildInfo *v3; // eax@2
  int v4; // edx@2
  int v5; // esi@2
  int v6; // eax@2
  int v7; // ecx@2
  bool v8; // bl@5
  UIElement *v9; // eax@5
  UIElement *v10; // eax@6
  int v11; // edx@6
  UIElement *v12; // esi@6
  UIElement *v13; // esi@8
  UIElement *v14; // ecx@9
  unsigned int v15; // [sp-14h] [bp-2Ch]@11
  bool bAllAreOn; // [sp+Bh] [bp-Dh]@3
  unsigned int i; // [sp+Ch] [bp-Ch]@1
  IDClass<_tagDataID,32,0> didImage; // [sp+10h] [bp-8h]@10
  IDClass<_tagDataID,32,0> _val; // [sp+14h] [bp-4h]@12

  v1 = this;
  v2 = 0;
  i = 0;
  if ( this->m_rgChildValues.m_num )
  {
    do
    {
      v3 = v1->m_rgChildValues.m_data;
      v4 = LODWORD(v3[v2].llMask);
      v5 = HIDWORD(v3[v2].llMask);
      v6 = v4 & v1->m_current;
      v7 = v5 & HIDWORD(v1->m_current);
      if ( v6 != v4 || (bAllAreOn = 1, v7 != v5) )
        bAllAreOn = 0;
      v8 = (v7 | v6) == 0;
      v9 = UIElement_ListBox::GetItem((UIElement_ListBox *)&v1->vfptr, i);
      if ( !v9 )
        goto LABEL_15;
      v10 = UIElement::GetChild(v9, 0x10000219u);
      v12 = v10;
      if ( !v10 )
        goto LABEL_15;
      LOBYTE(v11) = v8 == 0;
      UIElement::SetAttribute_Bool(v10, 0xEu, v11);
      if ( v8 )
        goto LABEL_15;
      v13 = UIElement::GetFirstChildElement(v12);
      if ( !v13 )
        goto LABEL_15;
      v14 = (UIElement *)&v1->vfptr;
      if ( bAllAreOn )
      {
        if ( UIElement::GetAttribute_DataID(v14, 0x10000082u, &didImage) )
        {
          v15 = didImage.id;
LABEL_14:
          UIElement::SetMediaImageForState(v13, (IDClass<_tagDataID,32,0>)v15, 1u, 6u);
          goto LABEL_15;
        }
      }
      else if ( UIElement::GetAttribute_DataID(v14, 0x10000083u, &_val) )
      {
        v15 = _val.id;
        goto LABEL_14;
      }
LABEL_15:
      ++v2;
      ++i;
    }
    while ( i < v1->m_rgChildValues.m_num );
  }
}

//----- (00485AE0) --------------------------------------------------------  // acclient.c:193340
int __thiscall UIOption_CheckboxBitfield64::ListenToElementMessage(UIOption_CheckboxBitfield64 *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIOption_CheckboxBitfield64 *v3; // esi@1
  UIElement *v4; // ecx@2
  UIOption_CheckboxBitfield64 *bChecked; // [sp+0h] [bp-4h]@1

  bChecked = this;
  v2 = i_rMsg;
  v3 = this;
  if ( i_rMsg->idMessage == 1 )
  {
    v4 = i_rMsg->pElement;
    if ( v4 )
    {
      if ( UIElement::GetAttribute_Int(v4, 0x10000084u, (int *)&i_rMsg)
        && UIElement::GetAttribute_Bool(v2->pElement, 0xEu, (bool *)&bChecked)
        && (unsigned int)i_rMsg < HIDWORD(v3->m_saved) )
      {
        BitUtils::SetBitsOnOrOff(
          (unsigned __int64 *)&v3->m_nAnimEndX,
          *(_QWORD *)(HIDWORD(v3->m_default) + 296 * (_DWORD)i_rMsg),
          (bool)bChecked);
        (*(void (__thiscall **)(int, signed int))(LODWORD(v3[-1].m_current) + 724))(&v3[-1].m_current, 1);
      }
    }
  }
  return UIElement_ListBox::ListenToElementMessage((UIElement_ListBox *)v3, v2);
}

//----- (00485B70) --------------------------------------------------------  // acclient.c:193371
char __thiscall SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1>::grow(SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](296 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x128u,
        i_nSize,
        (void *(__thiscall *)(void *))UIOption_CheckboxBitfield64::ChildInfo::ChildInfo);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              UIOption_CheckboxBitfield64::ChildInfo::operator=(v8 * 296 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              UIOption_CheckboxBitfield64::ChildInfo::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (UIOption_CheckboxBitfield64::ChildInfo *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00485C50) --------------------------------------------------------  // acclient.c:193435
void __thiscall UIOption_CheckboxBitfield64::UIOption_CheckboxBitfield64(UIOption_CheckboxBitfield64 *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_CheckboxBitfield64 *v3; // esi@1
  volatile LONG *v4; // ST04_4@1

  v3 = this;
  UIOption::UIOption((UIOption *)&this->vfptr);
  UIElement_ListBox::UIElement_ListBox((UIElement_ListBox *)&v3->vfptr, (int)&v3->vfptr, _layout, _full_desc);
  v3->vfptr = (IInputActionCallbackVtbl *)&UIOption_CheckboxBitfield64::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&UIOption_CheckboxBitfield64::vftable;
  LODWORD(v3->m_default) = 0;
  HIDWORD(v3->m_default) = 0;
  LODWORD(v3->m_saved) = 0;
  HIDWORD(v3->m_saved) = 0;
  LODWORD(v3->m_current) = 0;
  HIDWORD(v3->m_current) = 0;
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v3->m_prefName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v3->m_propName = 0;
  v3->m_propType = 0;
  v3->m_rgChildValues.m_data = 0;
  v3->m_rgChildValues.m_sizeAndDeallocate = 0;
  v3->m_rgChildValues.m_num = 0;
}
// 7A1CA0: using guessed type bool (__thiscall *UIOption_CheckboxBitfield64::vftable)(DBCache *this);
// 7A1F80: using guessed type void *UIOption_CheckboxBitfield64::vftable;

//----- (00485CE0) --------------------------------------------------------  // acclient.c:193464
signed int __thiscall UIOption_CheckboxBitfield64::DynamicCast(UIOption_CheckboxBitfield64 *this, unsigned int i_eType)
{
  signed int result; // eax@3

  if ( i_eType == 268435524 )
  {
    if ( this )
      result = (signed int)&this->vfptr;
    else
      result = 0;
  }
  else
  {
    result = (signed int)&this->vfptr;
    if ( i_eType != 5 )
      result = i_eType != 10 ? 0 : result;
  }
  return result;
}

//----- (00485D20) --------------------------------------------------------  // acclient.c:193485
signed int UIOption_CheckboxBitfield64::GetUIElementType()
{
  return 268435524;
}

//----- (00485D30) --------------------------------------------------------  // acclient.c:193491
UIOption_CheckboxBitfield64 *__thiscall UIOption_CheckboxBitfield64::vector_deleting_destructor(UIOption_CheckboxBitfield64 *this, unsigned int a2)
{
  return UIOption_CheckboxBitfield64::vector_deleting_destructor(
           (UIOption_CheckboxBitfield64 *)((char *)this - 32),
           a2);
}

//----- (00485D40) --------------------------------------------------------  // acclient.c:193499
signed int __thiscall UIOption_CheckboxBitfield64::DynamicCast(UIOption_CheckboxBitfield64 *this, unsigned int a2)
{
  return UIOption_CheckboxBitfield64::DynamicCast((UIOption_CheckboxBitfield64 *)((char *)this - 32), a2);
}

//----- (00485D50) --------------------------------------------------------  // acclient.c:193505
void __thiscall UIOption_CheckboxBitfield64::~UIOption_CheckboxBitfield64(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // esi@1
  UIElement_ListBox *v2; // ebx@1
  UIOption_CheckboxBitfield64::ChildInfo *v3; // ecx@2
  int v4; // edi@4

  v1 = this;
  v2 = (UIElement_ListBox *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption_CheckboxBitfield64::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIOption_CheckboxBitfield64::vftable;
  if ( (this->m_rgChildValues.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v3 = this->m_rgChildValues.m_data;
    if ( v3 )
      UIOption_CheckboxBitfield64::ChildInfo::vector_deleting_destructor(v3, 3u);
  }
  v4 = (int)&v1->m_prefName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  UIElement_ListBox::~UIElement_ListBox(v2);
  UIOption::~UIOption((UIOption *)&v1->vfptr);
}
// 7A1CA0: using guessed type bool (__thiscall *UIOption_CheckboxBitfield64::vftable)(DBCache *this);
// 7A1F80: using guessed type void *UIOption_CheckboxBitfield64::vftable;

//----- (00485DC0) --------------------------------------------------------  // acclient.c:193532
UIElement *__cdecl UIOption_CheckboxBitfield64::Create(LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIOption_CheckboxBitfield64 *v2; // eax@1
  int v3; // eax@2
  UIElement *result; // eax@3

  v2 = (UIOption_CheckboxBitfield64 *)operator new(0x6B8u);
  if ( v2 && (UIOption_CheckboxBitfield64::UIOption_CheckboxBitfield64(v2, _layout, _full_desc), v3) )
    result = (UIElement *)(v3 + 32);
  else
    result = 0;
  return result;
}

//----- (00485DF0) --------------------------------------------------------  // acclient.c:193547
void __thiscall UIOption_CheckboxBitfield64::CreateChildren(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // edi@1
  int v2; // ebp@1
  int v3; // ebx@2
  int v4; // eax@3
  UIElement *v5; // eax@4
  UIElement *v6; // eax@5
  UIElement_Text *v7; // esi@5
  IInputActionCallbackVtbl *v8; // ebx@8
  int v9; // ST04_4@8
  int v10; // eax@8

  v1 = this;
  v2 = 0;
  if ( this->m_rgChildValues.m_num )
  {
    v3 = 0;
    do
    {
      v4 = UIElement_ListBox::AddItemFromTemplateList((UIElement_ListBox *)&v1->vfptr, 0, 0);
      if ( v4 )
      {
        v5 = UIElement::GetChildRecursive((UIElement *)v4, 0x10000219u);
        if ( v5 )
        {
          v6 = (UIElement *)v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)1);
          v7 = (UIElement_Text *)v6;
          if ( v6 )
          {
            UIElement::SetAttribute_Int(v6, 0x10000084u, v2);
            UIElement_Text::SetStringInfo(v7, &v1->m_rgChildValues.m_data[v3].siLabel);
            UIElement::SetTooltip((UIElement *)&v7->vfptr, &v1->m_rgChildValues.m_data[v3].siTooltip);
          }
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_rgChildValues.m_num );
  }
  v8 = v1->vfptr;
  v9 = UIElement_ListBox::CalculatePaperSize((UIElement_ListBox *)&v1->vfptr, 0, -1);
  v10 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
  ((void (__thiscall *)(int, int, int))v8[4].__vecDelDtor)(&v1->vfptr, v10, v9);
  ((void (__thiscall *)(UIOption_CheckboxBitfield64 *))v1->vfptr[7].RecvNotice_ServerSaysMoveItem)(v1);
}

//----- (00485EB0) --------------------------------------------------------  // acclient.c:193596
UIOption_CheckboxBitfield64 *__thiscall UIOption_CheckboxBitfield64::vector_deleting_destructor(UIOption_CheckboxBitfield64 *this, unsigned int a2)
{
  UIOption_CheckboxBitfield64 *v2; // esi@1

  v2 = this;
  UIOption_CheckboxBitfield64::~UIOption_CheckboxBitfield64(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00485ED0) --------------------------------------------------------  // acclient.c:193608
void __cdecl UIOption_CheckboxBitfield64::Register()
{
  UIElement::RegisterElementClass(0x10000044u, UIOption_CheckboxBitfield64::Create);
}

//----- (00485EF0) --------------------------------------------------------  // acclient.c:193614
void __thiscall UIOption_CheckboxBitfield64::SetGameplayOptionProperty(UIOption_CheckboxBitfield64 *this, unsigned int i_propName, UIOption_CheckboxBitfield64::PropertyType i_type)
{
  UIOption_CheckboxBitfield64 *v3; // edi@1
  int v4; // eax@1
  char *v5; // esi@1
  bool v6; // bl@1
  PStringBase<char> v7; // [sp+0h] [bp-4h]@1

  v7.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  PStringBase<char>::PStringBase<char>(&v7, &name);
  v4 = __stricmp(v3->m_prefName.m_charbuffer->m_data, v7.m_charbuffer->m_data);
  v5 = &v7.m_charbuffer[-2].m_data[12];
  v6 = v4 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v7.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  if ( v6 )
  {
    v3->m_propName = i_propName;
    v3->m_propType = i_type;
  }
}

//----- (00485F70) --------------------------------------------------------  // acclient.c:193638
char __thiscall SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1>::AddToEnd(SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1> *this, UIOption_CheckboxBitfield64::ChildInfo *i_rData)
{
  SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1> *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2
  int v6; // esi@3

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1>::grow(v2, v4)) != 0) )
  {
    v6 = (int)&v2->m_data[v2->m_num];
    *(_QWORD *)v6 = i_rData->llMask;
    StringInfo::operator=((StringInfo *)(v6 + 8), (int)&i_rData->siLabel);
    StringInfo::operator=((StringInfo *)(v6 + 152), (int)&i_rData->siTooltip);
    ++v2->m_num;
    result = 1;
  }
  return result;
}

//----- (00485FF0) --------------------------------------------------------  // acclient.c:193663
char __thiscall UIOption_CheckboxBitfield64::Apply(UIOption_CheckboxBitfield64 *this, int _userRequested)
{
  UIOption_CheckboxBitfield64 *v2; // esi@1
  InterfaceSystem *v3; // eax@2
  Interface *v4; // edi@2
  const unsigned int v5; // ST08_4@6
  int v6; // edi@6
  int v7; // ebx@6
  UIOption_CheckboxBitfield64::PropertyType v8; // eax@8
  CPlayerModule *v9; // edi@8
  BasePropertyDesc *v10; // ecx@13
  unsigned int v11; // edx@13
  BasePropertyValue *v12; // ecx@17
  unsigned int v13; // edx@17
  char v14; // al@22
  int v15; // [sp-8h] [bp-34h]@2
  Interface *_rpInterface; // [sp+10h] [bp-1Ch]@2
  TResult result; // [sp+14h] [bp-18h]@2
  char v18; // [sp+18h] [bp-14h]@4
  BaseProperty prop; // [sp+1Ch] [bp-10h]@6
  InterfacePtr<CPlayerModule> spPM; // [sp+24h] [bp-8h]@2

  v2 = this;
  if ( this->m_propName )
  {
    _rpInterface = 0;
    v3 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v3, &result, &CPlayerModule_ClassType_0, &_rpInterface);
    v15 = (int)_rpInterface;
    v4 = _rpInterface;
    spPM.m_pInterface = 0;
    spPM.m_trStatus.m_val = 0;
    if ( _rpInterface )
      _rpInterface->vfptr->AddRef(_rpInterface);
    InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&v18, v15, 0);
    if ( v4 )
      v4->vfptr->Release(v4);
    v5 = v2->m_propName;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&prop, v5);
    v6 = LODWORD(v2->m_current);
    v7 = HIDWORD(v2->m_current);
    if ( prop.m_pcPropertyValue )
    {
      BaseProperty::CheckCopyOnWrite(&prop);
      ((void (__stdcall *)(int, int))prop.m_pcPropertyValue->vfptr[59].__vecDelDtor)(v6, v7);
    }
    v8 = v2->m_propType;
    v9 = spPM.m_pInterface;
    if ( v8 )
    {
      if ( v8 == 1 )
        PlayerModule::SetChatWindowOption((PlayerModule *)&spPM.m_pInterface->vfptr, v2->m_nUserData, &prop);
    }
    else
    {
      PlayerModule::SetOption((PlayerModule *)&spPM.m_pInterface->vfptr, &prop);
    }
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v10 = prop.m_pcPropertyDesc;
      v11 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      prop.m_pcPropertyDesc = 0;
    }
    if ( prop.m_pcPropertyValue )
    {
      v12 = prop.m_pcPropertyValue;
      v13 = prop.m_pcPropertyValue->m_cRef - 1;
      prop.m_pcPropertyValue->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      prop.m_pcPropertyValue = 0;
    }
    if ( v9 )
      v9->vfptr->Release((Interface *)v9);
    v2->vfptr[7].RecvNotice_CreateObject((NoticeHandler *)v2, _userRequested);
    v14 = 1;
  }
  else
  {
    v14 = 0;
  }
  return v14;
}

//----- (00486150) --------------------------------------------------------  // acclient.c:193753
int __thiscall UIOption_CheckboxBitfield64::GetValue(UIOption_CheckboxBitfield64 *this)
{
  UIOption_CheckboxBitfield64 *v1; // esi@1
  unsigned int v2; // ecx@1
  int v3; // eax@1
  int v4; // edx@1
  InterfaceSystem *v5; // eax@2
  Interface *v6; // edi@2
  UIOption_CheckboxBitfield64::PropertyType v7; // eax@6
  CPlayerModule *v8; // edi@6
  BasePropertyValue *v9; // ecx@6
  char v10; // al@8
  BasePropertyDesc *v11; // ecx@14
  unsigned int v12; // esi@14
  int v13; // edx@18
  int v14; // [sp-8h] [bp-38h]@2
  Interface *_rpInterface; // [sp+Ch] [bp-24h]@2
  TResult result; // [sp+10h] [bp-20h]@2
  char v17; // [sp+14h] [bp-1Ch]@4
  BaseProperty baseProp; // [sp+18h] [bp-18h]@6
  unsigned __int64 val; // [sp+20h] [bp-10h]@1
  InterfacePtr<CPlayerModule> spPM; // [sp+28h] [bp-8h]@2

  v1 = this;
  v2 = this->m_propName;
  v3 = LODWORD(v1->m_default);
  v4 = HIDWORD(v1->m_default);
  LODWORD(val) = LODWORD(v1->m_default);
  HIDWORD(val) = v4;
  if ( !v2 )
    return v3;
  _rpInterface = 0;
  v5 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v5, &result, &CPlayerModule_ClassType_0, &_rpInterface);
  v14 = (int)_rpInterface;
  v6 = _rpInterface;
  spPM.m_pInterface = 0;
  spPM.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<CPlayerModule>::_QueryInterface(&spPM, (int)&v17, v14, 0);
  if ( v6 )
    v6->vfptr->Release(v6);
  v7 = v1->m_propType;
  v8 = spPM.m_pInterface;
  v9 = 0;
  baseProp.m_pcPropertyDesc = 0;
  baseProp.m_pcPropertyValue = 0;
  if ( v7 == Normal_PropType )
  {
    v10 = PlayerModule::InqOption((PlayerModule *)&spPM.m_pInterface->vfptr, v1->m_propName, &baseProp);
LABEL_10:
    v9 = baseProp.m_pcPropertyValue;
    if ( v10 && baseProp.m_pcPropertyValue )
    {
      ((void (__stdcall *)(unsigned __int64 *))baseProp.m_pcPropertyValue->vfptr[58].__vecDelDtor)(&val);
      v9 = baseProp.m_pcPropertyValue;
    }
    if ( (_DWORD)baseProp.m_pcPropertyDesc )
    {
      v11 = baseProp.m_pcPropertyDesc;
      v12 = baseProp.m_pcPropertyDesc->m_cRef - 1;
      baseProp.m_pcPropertyDesc->m_cRef = v12;
      if ( !v12 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v9 = baseProp.m_pcPropertyValue;
      baseProp.m_pcPropertyDesc = 0;
    }
    goto LABEL_17;
  }
  if ( v7 == 1 )
  {
    v10 = PlayerModule::InqChatWindowOption(
            (PlayerModule *)&spPM.m_pInterface->vfptr,
            v1->m_nUserData,
            v1->m_propName,
            &baseProp);
    goto LABEL_10;
  }
LABEL_17:
  if ( v9 )
  {
    v13 = v9->m_cRef - 1;
    v9->m_cRef = v13;
    if ( !v13 )
      ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
    baseProp.m_pcPropertyValue = 0;
  }
  if ( v8 )
    v8->vfptr->Release((Interface *)v8);
  return val;
}

//----- (004862A0) --------------------------------------------------------  // acclient.c:193847
void __thiscall UIOption_CheckboxBitfield64::AddChild(UIOption_CheckboxBitfield64 *this, unsigned __int64 i_llMask, unsigned int i_stLabel, unsigned int i_stTooltip)
{
  UIOption_CheckboxBitfield64 *v4; // esi@1
  UIOption_CheckboxBitfield64::ChildInfo i_rData; // [sp+4h] [bp-128h]@1

  v4 = this;
  i_rData.llMask = i_llMask;
  StringInfo::StringInfo(&i_rData.siLabel);
  StringInfo::StringInfo(&i_rData.siTooltip);
  StringInfo::SetStringIDandTableEnum(&i_rData.siLabel, i_stLabel, 268435462);
  StringInfo::SetStringIDandTableEnum(&i_rData.siTooltip, i_stTooltip, 268435462);
  SmartArray<UIOption_CheckboxBitfield64::ChildInfo,1>::AddToEnd(&v4->m_rgChildValues, &i_rData);
  StringInfo::~StringInfo(&i_rData.siTooltip);
  StringInfo::~StringInfo(&i_rData.siLabel);
}

//----- (006ED580) --------------------------------------------------------  // acclient.c:769213
void _E91_47()
{
  outside_val_39 = 1000.0 + 1.0;
}

//----- (006ED5A0) --------------------------------------------------------  // acclient.c:769219
void _E93_23()
{
  block_length_39 = 24.0 * 8.0;
}

//----- (006ED5C0) --------------------------------------------------------  // acclient.c:769225
void _E95_23()
{
  half_square_length_39 = 24.0 * 0.5;
}

//----- (006ED5E0) --------------------------------------------------------  // acclient.c:769231
int _E97_48()
{
  return atexit(_E98_60);
}

//----- (006ED5F0) --------------------------------------------------------  // acclient.c:769237
int _E100_41()
{
  return atexit(_E101_78);
}

//----- (006ED600) --------------------------------------------------------  // acclient.c:769243
int _E103_33()
{
  return atexit(_E104_48);
}

//----- (006ED610) --------------------------------------------------------  // acclient.c:769249
int sub_6ED610()
{
  return atexit(nullsub_1009);
}

