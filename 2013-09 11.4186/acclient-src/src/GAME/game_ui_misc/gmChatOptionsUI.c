/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmChatOptionsUI
   Object     : GAME\game_ui_misc\gmChatOptionsUI.obj
   Functions  : 74
   Addresses  : 0049ED80 - 006F0800 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0049ED80) --------------------------------------------------------  // acclient.c:215901
ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *__thiscall ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::scalar_deleting_destructor(ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *this, unsigned int a2)
{
  ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v2; // esi@1

  v2 = this;
  this->vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049EDA0) --------------------------------------------------------  // acclient.c:215914
UIOption_CheckboxBitfield64 *__thiscall gmChatOptionsUI::AddCheckboxBitfield64Option(gmChatOptionsUI *this, const unsigned int *i_ePropName, unsigned int i_nUserData)
{
  OptionPage *v3; // ebx@1
  UIElement_ListBox *v4; // ecx@1
  UIOption_CheckboxBitfield64 *v5; // esi@1
  int v6; // eax@2
  int v7; // eax@3
  signed int v9; // [sp-8h] [bp-10h]@8

  v3 = (OptionPage *)this;
  v4 = this->m_pOptionBox;
  v5 = 0;
  if ( v4 )
  {
    v6 = UIElement_ListBox::AddItemFromTemplateList(v4, 8u, 0);
    if ( v6 )
    {
      v7 = (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v6 + 148))(v6, 268435524);
      if ( !v7 )
        return 0;
      v5 = (UIOption_CheckboxBitfield64 *)(v7 - 32);
      if ( v7 != 32 )
      {
        UIOption_CheckboxBitfield64::SetGameplayOptionProperty(v5, *i_ePropName, Chat_PropType);
        UIOption::SetUserData((UIOption *)&v5->vfptr, i_nUserData);
        switch ( i_nUserData )
        {
          case 8u:
            ((void (__thiscall *)(UIOption_CheckboxBitfield64 *, signed int, _DWORD))v5->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
              v5,
              -67108865,
              0);
            break;
          case 2u:
            v9 = 4124;
            goto LABEL_12;
          case 3u:
            v9 = 265216;
            goto LABEL_12;
          case 4u:
            v9 = 0x80000;
            goto LABEL_12;
          case 5u:
            v9 = 2013265920;
LABEL_12:
            ((void (__thiscall *)(UIOption_CheckboxBitfield64 *, signed int, _DWORD))v5->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
              v5,
              v9,
              0);
            UIOption_CheckboxBitfield64::AddChild(
              v5,
              0x83912021ui64,
              ID_ChatOption_TextFilter_Gameplay,
              ID_ChatOption_TextFilter_Gameplay_Desc);
            break;
          default:
            break;
        }
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          (unsigned int)&loc_600040,
          ID_ChatOption_TextFilter_Combat,
          ID_ChatOption_TextFilter_Combat_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x20080ui64,
          ID_ChatOption_TextFilter_Magic,
          ID_ChatOption_TextFilter_Magic_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x1004ui64,
          ID_ChatOption_TextFilter_AreaSpeech,
          ID_ChatOption_TextFilter_AreaSpeech_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x18ui64,
          ID_ChatOption_TextFilter_Tells,
          ID_ChatOption_TextFilter_Tells_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x40C00ui64,
          ID_ChatOption_TextFilter_Allegience,
          ID_ChatOption_TextFilter_Allegience_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x80000ui64,
          ID_ChatOption_TextFilter_Fellowship,
          ID_ChatOption_TextFilter_Fellowship_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x8000000ui64,
          ID_ChatOption_TextFilter_General,
          ID_ChatOption_TextFilter_General_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x10000000ui64,
          ID_ChatOption_TextFilter_Trade,
          ID_ChatOption_TextFilter_Trade_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x20000000ui64,
          ID_ChatOption_TextFilter_LFG,
          ID_ChatOption_TextFilter_LFG_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x40000000ui64,
          ID_ChatOption_TextFilter_Roleplay,
          ID_ChatOption_TextFilter_Roleplay_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x100000000ui64,
          ID_ChatOption_TextFilter_Society,
          ID_ChatOption_TextFilter_Society_Desc);
        UIOption_CheckboxBitfield64::AddChild(
          v5,
          0x4000000ui64,
          ID_ChatOption_TextFilter_Error,
          ID_ChatOption_TextFilter_Error_Desc);
        UIOption_CheckboxBitfield64::CreateChildren(v5);
        OptionPage::RegisterOption(v3, (UIOption *)&v5->vfptr);
      }
    }
  }
  return v5;
}

//----- (0049EFF0) --------------------------------------------------------  // acclient.c:216041
void __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::init(DualHash<UIOption_Slider *,UIOption_Slider *> *this, unsigned int table_size)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v2; // ebx@1
  void *v3; // eax@1
  int v4; // edx@2
  int v5; // eax@2
  unsigned int v6; // ecx@3
  int v7; // eax@5
  unsigned int v8; // edi@7
  unsigned int v9; // ST00_4@7
  void *v10; // eax@7
  int v11; // edx@8
  int v12; // eax@8
  unsigned int v13; // ecx@9

  v2 = this;
  this->m_num_buckets = table_size;
  this->m_num_elements = 0;
  v3 = operator new[](16 * table_size + 4);
  if ( v3 )
  {
    v4 = (int)((char *)v3 + 4);
    *(_DWORD *)v3 = table_size;
    v5 = (int)((char *)v3 + 4);
    if ( ((table_size - 1) & 0x80000000) == 0 )
    {
      v6 = table_size;
      do
      {
        *(_DWORD *)v5 = &List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
        *(_DWORD *)(v5 + 4) = 0;
        *(_DWORD *)(v5 + 8) = 0;
        *(_DWORD *)(v5 + 12) = 0;
        v5 += 16;
        --v6;
      }
      while ( v6 );
    }
    v7 = v4;
  }
  else
  {
    v7 = 0;
  }
  v8 = v2->m_num_buckets;
  v9 = 16 * v2->m_num_buckets + 4;
  v2->m_left_buckets = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v7;
  v10 = operator new[](v9);
  if ( v10 )
  {
    v11 = (int)((char *)v10 + 4);
    *(_DWORD *)v10 = v8;
    v12 = (int)((char *)v10 + 4);
    if ( ((v8 - 1) & 0x80000000) == 0 )
    {
      v13 = v8;
      do
      {
        *(_DWORD *)v12 = &List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
        *(_DWORD *)(v12 + 4) = 0;
        *(_DWORD *)(v12 + 8) = 0;
        *(_DWORD *)(v12 + 12) = 0;
        v12 += 16;
        --v13;
      }
      while ( v13 );
    }
    v2->m_right_buckets = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v11;
  }
  else
  {
    v2->m_right_buckets = 0;
  }
}
// 7A8D74: using guessed type int (__thiscall *List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable)(void *, char);

//----- (0049F0A0) --------------------------------------------------------  // acclient.c:216118
void __thiscall DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(DualHashIter<UIOption_Slider *,UIOption_Slider *> *this)
{
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v1; // eax@2
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v2; // eax@4
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v3; // edx@7
  char v4; // [sp+0h] [bp-Ch]@2

  if ( this->m_curr_bucket != this->m_end_bucket )
  {
    do
    {
      v1 = this->m_curr_bucket;
      if ( (char *)&this->m_curr_element != &v4 )
      {
        this->m_curr_element._current = this->m_curr_bucket->_head;
        this->m_curr_element._list = v1;
      }
      v2 = this->m_curr_bucket;
      if ( (char *)&this->m_end_element != &v4 )
      {
        this->m_end_element._current = 0;
        this->m_end_element._list = v2;
      }
      if ( this->m_end_element._current != this->m_curr_element._current )
        break;
      v3 = this->m_curr_bucket + 1;
      this->m_curr_bucket = v3;
    }
    while ( v3 != this->m_end_bucket );
  }
}

//----- (0049F100) --------------------------------------------------------  // acclient.c:216151
void __thiscall gmChatOptionsUI::PostInit(gmChatOptionsUI *this)
{
  gmChatOptionsUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000050Du);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
  else
    v3 = 0;
  v1->m_pOptionBox = (UIElement_ListBox *)v3;
  ((void (__thiscall *)(gmChatOptionsUI *))v1->vfptr[27].__vecDelDtor)(v1);
  v1->vfptr->OnOptionChanged(&v1->vfptr, 0);
}

//----- (0049F150) --------------------------------------------------------  // acclient.c:216170
void __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::add_internal(DualHash<UIOption_Slider *,UIOption_Slider *> *this, UIOption_Slider *const *left, UIOption_Slider *const *right)
{
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v3; // esi@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v4; // edi@1
  void *v5; // eax@1
  void *v6; // ebx@2
  void *v7; // eax@4
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v8; // ecx@7
  void *v9; // eax@9
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v10; // ecx@12

  v3 = &this->m_left_buckets[(((unsigned int)*left >> 8) | (unsigned __int64)((unsigned int)*left << 24))
                           % this->m_num_buckets];
  v4 = &this->m_right_buckets[(((unsigned int)*right >> 8) | (unsigned __int64)((unsigned int)*right << 24))
                            % this->m_num_buckets];
  v5 = operator new(8u);
  if ( v5 )
  {
    *(_DWORD *)v5 = *left;
    *((_DWORD *)v5 + 1) = *right;
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = operator new(0xCu);
  if ( v7 )
  {
    *(_DWORD *)v7 = v6;
    *((_DWORD *)v7 + 1) = 0;
    *((_DWORD *)v7 + 2) = 0;
    if ( v3->_head )
    {
      v8 = v3->_tail;
      v8->next = (ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v7;
      *((_DWORD *)v7 + 2) = v8;
    }
    else
    {
      v3->_head = (ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v7;
    }
    v3->_tail = (ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v7;
    ++v3->_num_elements;
  }
  v9 = operator new(0xCu);
  if ( v9 )
  {
    *(_DWORD *)v9 = v6;
    *((_DWORD *)v9 + 1) = 0;
    *((_DWORD *)v9 + 2) = 0;
    if ( v4->_head )
    {
      v10 = v4->_tail;
      v10->next = (ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v9;
      *((_DWORD *)v9 + 2) = v10;
      v4->_tail = (ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v9;
      ++v4->_num_elements;
    }
    else
    {
      v4->_head = (ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v9;
      v4->_tail = (ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)v9;
      ++v4->_num_elements;
    }
  }
}

//----- (0049F230) --------------------------------------------------------  // acclient.c:216239
int __thiscall DualHashIter<UIOption_Slider *,UIOption_Slider *>::operator==(DualHashIter<UIOption_Slider *,UIOption_Slider *> *this, DualHashIter<UIOption_Slider *,UIOption_Slider *> *rhs)
{
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v2; // eax@1
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v3; // edx@3
  int result; // eax@7

  v2 = this->m_curr_bucket;
  if ( this->m_curr_bucket
    && v2 != this->m_end_bucket
    && (v3 = this->m_curr_element._current, this->m_end_element._current != v3) )
    result = v2 == rhs->m_curr_bucket && rhs->m_curr_element._current == v3;
  else
    result = !rhs->m_curr_bucket
          || rhs->m_curr_bucket == rhs->m_end_bucket
          || rhs->m_end_element._current == rhs->m_curr_element._current;
  return result;
}

//----- (0049F2A0) --------------------------------------------------------  // acclient.c:216258
DualHashIter<UIOption_Slider *,UIOption_Slider *> *__thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::find_left(DualHash<UIOption_Slider *,UIOption_Slider *> *this, DualHashIter<UIOption_Slider *,UIOption_Slider *> *result, UIOption_Slider *const *left)
{
  unsigned int v3; // esi@1
  int v4; // edx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v5; // ecx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v6; // esi@1
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v7; // ebx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *i; // edx@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> *v9; // eax@4
  char *v10; // ecx@4
  char *v11; // edi@4
  char v12; // [sp+18h] [bp-18h]@4
  char v13; // [sp+24h] [bp-Ch]@6

  v3 = this->m_num_buckets;
  v4 = (((unsigned int)*left >> 8) | (unsigned __int64)((unsigned int)*left << 24)) % this->m_num_buckets;
  v5 = this->m_left_buckets;
  v6 = &v5[v3];
  v4 *= 16;
  v7 = *(ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> **)((char *)&v5->_head + v4);
  for ( i = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)((char *)v5 + v4); v7; v7 = v7->next )
  {
    if ( v7->data->m_left_data == (UIOption_Slider *)*left )
      break;
  }
  v9 = result;
  v10 = (char *)&result->m_curr_element;
  *(_DWORD *)v10 = ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  *((_DWORD *)v10 + 1) = 0;
  *((_DWORD *)v10 + 2) = 0;
  v11 = (char *)&result->m_end_element;
  *(_DWORD *)v11 = ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  *((_DWORD *)v11 + 1) = 0;
  *((_DWORD *)v11 + 2) = 0;
  result->m_end_bucket = v6;
  result->m_curr_bucket = i;
  if ( (char *)&result->m_curr_element != &v12 )
  {
    result->m_curr_element._current = v7;
    result->m_curr_element._list = i;
  }
  if ( v11 != &v13 )
  {
    result->m_end_element._current = 0;
    result->m_end_element._list = i;
  }
  return v9;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049F330) --------------------------------------------------------  // acclient.c:216309
DualHashIter<UIOption_Slider *,UIOption_Slider *> *__thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::find_right(DualHash<UIOption_Slider *,UIOption_Slider *> *this, DualHashIter<UIOption_Slider *,UIOption_Slider *> *result, UIOption_Slider *const *right)
{
  unsigned int v3; // esi@1
  int v4; // edx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v5; // ecx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v6; // esi@1
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v7; // ebx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *i; // edx@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> *v9; // eax@4
  char *v10; // ecx@4
  char *v11; // edi@4
  char v12; // [sp+18h] [bp-18h]@4
  char v13; // [sp+24h] [bp-Ch]@6

  v3 = this->m_num_buckets;
  v4 = (((unsigned int)*right >> 8) | (unsigned __int64)((unsigned int)*right << 24)) % this->m_num_buckets;
  v5 = this->m_right_buckets;
  v6 = &v5[v3];
  v4 *= 16;
  v7 = *(ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> **)((char *)&v5->_head + v4);
  for ( i = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)((char *)v5 + v4); v7; v7 = v7->next )
  {
    if ( v7->data->m_right_data == (UIOption_Slider *)*right )
      break;
  }
  v9 = result;
  v10 = (char *)&result->m_curr_element;
  *(_DWORD *)v10 = ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  *((_DWORD *)v10 + 1) = 0;
  *((_DWORD *)v10 + 2) = 0;
  v11 = (char *)&result->m_end_element;
  *(_DWORD *)v11 = ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  *((_DWORD *)v11 + 1) = 0;
  *((_DWORD *)v11 + 2) = 0;
  result->m_end_bucket = v6;
  result->m_curr_bucket = i;
  if ( (char *)&result->m_curr_element != &v12 )
  {
    result->m_curr_element._current = v7;
    result->m_curr_element._list = i;
  }
  if ( v11 != &v13 )
  {
    result->m_end_element._current = 0;
    result->m_end_element._list = i;
  }
  return v9;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049F3D0) --------------------------------------------------------  // acclient.c:216360
char __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::find_left(DualHash<UIOption_Slider *,UIOption_Slider *> *this, UIOption_Slider *const *left, UIOption_Slider **right)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v3; // esi@1
  char result; // al@2
  DualHashIter<UIOption_Slider *,UIOption_Slider *> rhs; // [sp+4h] [bp-40h]@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> iter; // [sp+24h] [bp-20h]@1

  v3 = this;
  DualHash<UIOption_Slider *,UIOption_Slider *>::find_left(this, &iter, left);
  rhs.m_curr_bucket = &v3->m_left_buckets[v3->m_num_buckets];
  rhs.m_end_bucket = rhs.m_curr_bucket;
  rhs.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_curr_element._current = 0;
  rhs.m_curr_element._list = 0;
  rhs.m_end_element._current = 0;
  rhs.m_end_element._list = 0;
  DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(&rhs);
  if ( (unsigned __int8)DualHashIter<UIOption_Slider *,UIOption_Slider *>::operator==(&iter, &rhs) )
  {
    result = 0;
  }
  else
  {
    *right = iter.m_curr_element._current->data->m_right_data;
    result = 1;
  }
  return result;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049F460) --------------------------------------------------------  // acclient.c:216392
char __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::find_right(DualHash<UIOption_Slider *,UIOption_Slider *> *this, UIOption_Slider *const *right, UIOption_Slider **left)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v3; // esi@1
  char result; // al@2
  DualHashIter<UIOption_Slider *,UIOption_Slider *> rhs; // [sp+4h] [bp-40h]@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> iter; // [sp+24h] [bp-20h]@1

  v3 = this;
  DualHash<UIOption_Slider *,UIOption_Slider *>::find_right(this, &iter, right);
  rhs.m_curr_bucket = &v3->m_left_buckets[v3->m_num_buckets];
  rhs.m_end_bucket = rhs.m_curr_bucket;
  rhs.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_curr_element._current = 0;
  rhs.m_curr_element._list = 0;
  rhs.m_end_element._current = 0;
  rhs.m_end_element._list = 0;
  DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(&rhs);
  if ( (unsigned __int8)DualHashIter<UIOption_Slider *,UIOption_Slider *>::operator==(&iter, &rhs) )
  {
    result = 0;
  }
  else
  {
    *left = iter.m_curr_element._current->data->m_left_data;
    result = 1;
  }
  return result;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049F4F0) --------------------------------------------------------  // acclient.c:216424
bool __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::contains_left(DualHash<UIOption_Slider *,UIOption_Slider *> *this, UIOption_Slider *const *left)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v2; // esi@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> *v3; // eax@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> rhs; // [sp+4h] [bp-40h]@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> result; // [sp+24h] [bp-20h]@1

  v2 = this;
  rhs.m_curr_bucket = &this->m_left_buckets[this->m_num_buckets];
  rhs.m_end_bucket = rhs.m_curr_bucket;
  rhs.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_curr_element._current = 0;
  rhs.m_curr_element._list = 0;
  rhs.m_end_element._current = 0;
  rhs.m_end_element._list = 0;
  DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(&rhs);
  v3 = DualHash<UIOption_Slider *,UIOption_Slider *>::find_left(v2, &result, left);
  return (unsigned __int8)DualHashIter<UIOption_Slider *,UIOption_Slider *>::operator==(v3, &rhs) == 0;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049F560) --------------------------------------------------------  // acclient.c:216447
bool __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::contains_right(DualHash<UIOption_Slider *,UIOption_Slider *> *this, UIOption_Slider *const *right)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v2; // esi@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> *v3; // eax@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> rhs; // [sp+4h] [bp-40h]@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> result; // [sp+24h] [bp-20h]@1

  v2 = this;
  rhs.m_curr_bucket = &this->m_left_buckets[this->m_num_buckets];
  rhs.m_end_bucket = rhs.m_curr_bucket;
  rhs.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  rhs.m_curr_element._current = 0;
  rhs.m_curr_element._list = 0;
  rhs.m_end_element._current = 0;
  rhs.m_end_element._list = 0;
  DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(&rhs);
  v3 = DualHash<UIOption_Slider *,UIOption_Slider *>::find_right(v2, &result, right);
  return (unsigned __int8)DualHashIter<UIOption_Slider *,UIOption_Slider *>::operator==(v3, &rhs) == 0;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049F5D0) --------------------------------------------------------  // acclient.c:216470
void __thiscall gmChatOptionsUI::OnOptionChanged(gmChatOptionsUI *this, UIOption *pOption)
{
  UIOption *v2; // ebp@1
  gmChatOptionsUI *v3; // edi@1
  int v4; // eax@2
  UIOption_Slider *v5; // esi@3
  DualHash<UIOption_Slider *,UIOption_Slider *> *v6; // edi@4
  UIOption *v7; // ebx@5
  double v8; // st7@5
  float i_fNewValue; // ST04_4@6
  UIOption *v10; // edi@8
  double v11; // st7@8
  float v12; // ST08_4@9
  UIOption_Slider *pThisSlider; // [sp+18h] [bp-Ch]@3
  float v14; // [sp+1Ch] [bp-8h]@5
  PlayerOptionPage *v15; // [sp+20h] [bp-4h]@1

  v2 = pOption;
  v3 = this;
  v15 = (PlayerOptionPage *)this;
  if ( pOption )
  {
    v4 = ((int (__thiscall *)(UIOption *, signed int))pOption->vfptr[7].RecvNotice_RuntimeDDDStatus)(pOption, 268435511);
    if ( v4 )
    {
      v5 = (UIOption_Slider *)(v4 - 32);
      pThisSlider = (UIOption_Slider *)(v4 - 32);
      if ( v4 != 32 )
      {
        v6 = (DualHash<UIOption_Slider *,UIOption_Slider *> *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
        pOption = 0;
        if ( DualHash<UIOption_Slider *,UIOption_Slider *>::find_left(v6, &pThisSlider, (UIOption_Slider **)&pOption) )
        {
          v14 = UIOption_Slider::GetCurrentValue(v5);
          v7 = pOption;
          v8 = UIOption_Slider::GetCurrentValue((UIOption_Slider *)pOption);
          if ( v8 < v14 )
          {
            i_fNewValue = UIOption_Slider::GetCurrentValue(v5);
            UIOption_Slider::SetCurrentValue((UIOption_Slider *)v7, i_fNewValue);
          }
        }
        if ( DualHash<UIOption_Slider *,UIOption_Slider *>::find_right(v6, &pThisSlider, (UIOption_Slider **)&pOption) )
        {
          v14 = UIOption_Slider::GetCurrentValue(v5);
          v10 = pOption;
          v11 = UIOption_Slider::GetCurrentValue((UIOption_Slider *)pOption);
          if ( v11 > v14 )
          {
            v12 = UIOption_Slider::GetCurrentValue(v5);
            UIOption_Slider::SetCurrentValue((UIOption_Slider *)v10, v12);
          }
        }
      }
    }
  }
  PlayerOptionPage::OnOptionChanged(v15, v2);
}

//----- (0049F6C0) --------------------------------------------------------  // acclient.c:216530
void __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::clear(DualHash<UIOption_Slider *,UIOption_Slider *> *this)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v1; // ebx@1
  int v2; // ebp@2
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *i; // esi@3
  int j; // esi@7
  int v5; // ecx@8
  int v6; // eax@9
  int k; // esi@15
  int v8; // ecx@16
  int v9; // eax@17
  unsigned int loop; // [sp+0h] [bp-4h]@1

  v1 = this;
  loop = 0;
  if ( this->m_num_buckets )
  {
    v2 = 0;
    do
    {
      for ( i = v1->m_left_buckets[v2]._head; i; i = i->next )
      {
        if ( i->data )
          operator delete(i->data);
      }
      for ( j = (int)&v1->m_left_buckets[v2]; ; --*(_DWORD *)(j + 12) )
      {
        v5 = *(_DWORD *)(j + 4);
        if ( !v5 )
          break;
        v6 = *(_DWORD *)(v5 + 4);
        *(_DWORD *)(j + 4) = v6;
        if ( v6 )
          *(_DWORD *)(v6 + 8) = 0;
        else
          *(_DWORD *)(j + 8) = 0;
        if ( v5 )
          operator delete((void *)v5);
      }
      for ( k = (int)&v1->m_right_buckets[v2]; ; --*(_DWORD *)(k + 12) )
      {
        v8 = *(_DWORD *)(k + 4);
        if ( !v8 )
          break;
        v9 = *(_DWORD *)(v8 + 4);
        *(_DWORD *)(k + 4) = v9;
        if ( v9 )
          *(_DWORD *)(v9 + 8) = 0;
        else
          *(_DWORD *)(k + 8) = 0;
        if ( v8 )
          operator delete((void *)v8);
      }
      ++v2;
      ++loop;
    }
    while ( loop < v1->m_num_buckets );
  }
  v1->m_num_elements = 0;
}

//----- (0049F790) --------------------------------------------------------  // acclient.c:216592
void *__thiscall List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vector_deleting_destructor(List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *this, unsigned int a2)
{
  char v2; // bl@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v3; // edi@1
  unsigned int v4; // eax@2
  char *v5; // ebp@2
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v6; // esi@2
  int v7; // eax@2
  int v8; // ebx@3
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v9; // ecx@5
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v10; // eax@6
  void *result; // eax@16

  v2 = a2;
  v3 = this;
  if ( a2 & 2 )
  {
    v4 = this[-1]._num_elements;
    v5 = (char *)&this[-1]._num_elements;
    v6 = &this[v4];
    v7 = v4 - 1;
    if ( v7 >= 0 )
    {
      v8 = v7 + 1;
      do
      {
        --v6;
        v6->vfptr = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)&List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
        while ( 1 )
        {
          v9 = v6->_head;
          if ( !v9 )
            break;
          v10 = v9->next;
          v6->_head = v10;
          if ( v10 )
            v10->prev = 0;
          else
            v6->_tail = 0;
          if ( v9 )
            operator delete(v9);
          --v6->_num_elements;
        }
        --v8;
      }
      while ( v8 );
      v2 = a2;
    }
    if ( v2 & 1 )
      operator delete[](v5);
    result = v5;
  }
  else
  {
    this->vfptr = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)&List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
    List<SkillRecord *>::flush((List<SkillRecord *> *)this);
    if ( a2 & 1 )
      operator delete(v3);
    result = v3;
  }
  return result;
}
// 7A8D74: using guessed type int (__thiscall *List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable)(void *, char);

//----- (0049F830) --------------------------------------------------------  // acclient.c:216657
void __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::destroy(DualHash<UIOption_Slider *,UIOption_Slider *> *this)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v1; // esi@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v2; // ecx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v3; // ecx@5

  v1 = this;
  DualHash<UIOption_Slider *,UIOption_Slider *>::clear(this);
  v2 = v1->m_left_buckets;
  if ( v2 )
  {
    if ( v2[-1]._num_elements )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v2[-1]._num_elements);
  }
  v3 = v1->m_right_buckets;
  if ( v3 )
  {
    if ( v3[-1]._num_elements )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v3[-1]._num_elements);
  }
}

//----- (0049F880) --------------------------------------------------------  // acclient.c:216684
void __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::inc_num_elements(DualHash<UIOption_Slider *,UIOption_Slider *> *this, unsigned int amount)
{
  int v2; // esi@1
  unsigned int v3; // ecx@1
  int v4; // eax@1
  unsigned int v5; // edx@1
  DualHash<UIOption_Slider *,UIOption_Slider *> temp; // [sp+4h] [bp-10h]@2

  v2 = (int)this;
  v3 = amount + this->m_num_elements;
  v4 = *(_DWORD *)v2;
  v5 = *(_DWORD *)v2 >> 1;
  *(_DWORD *)(v2 + 4) = v3;
  if ( v3 > v5 )
  {
    temp.m_num_buckets = 0;
    temp.m_left_buckets = 0;
    temp.m_right_buckets = 0;
    DualHash<UIOption_Slider *,UIOption_Slider *>::init(&temp, 2 * v4);
    DualHash<UIOption_Slider *,UIOption_Slider *>::operator=(&temp, v2);
    DualHash<UIOption_Slider *,UIOption_Slider *>::destroy((DualHash<UIOption_Slider *,UIOption_Slider *> *)v2);
    DualHash<UIOption_Slider *,UIOption_Slider *>::init(
      (DualHash<UIOption_Slider *,UIOption_Slider *> *)v2,
      2 * *(_DWORD *)v2);
    DualHash<UIOption_Slider *,UIOption_Slider *>::operator=(
      (DualHash<UIOption_Slider *,UIOption_Slider *> *)v2,
      (int)&temp);
    DualHash<UIOption_Slider *,UIOption_Slider *>::destroy(&temp);
  }
}

//----- (0049F8F0) --------------------------------------------------------  // acclient.c:216716
DualHash<UIOption_Slider *,UIOption_Slider *> *__thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::operator=(DualHash<UIOption_Slider *,UIOption_Slider *> *this, int a2)
{
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v2; // eax@1
  int v3; // edx@1
  List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v4; // esi@1
  ListNode<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *v5; // edi@1
  int v6; // ecx@2
  int v7; // eax@2
  char v8; // al@8
  unsigned int amount; // [sp+10h] [bp-48h]@1
  DualHash<UIOption_Slider *,UIOption_Slider *> *v11; // [sp+14h] [bp-44h]@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> v12; // [sp+18h] [bp-40h]@1
  DualHashIter<UIOption_Slider *,UIOption_Slider *> v13; // [sp+38h] [bp-20h]@1

  v11 = this;
  DualHash<UIOption_Slider *,UIOption_Slider *>::clear(this);
  v2 = *(List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> **)(a2 + 8);
  v3 = *(_DWORD *)a2;
  v13.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  v13.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  v12.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  v12.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
  amount = 0;
  v12.m_curr_bucket = v2;
  v12.m_end_bucket = &v2[v3];
  v12.m_curr_element._current = 0;
  v12.m_curr_element._list = 0;
  v12.m_end_element._current = 0;
  v12.m_end_element._list = 0;
  DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(&v12);
  v4 = v12.m_curr_bucket;
  v5 = v12.m_curr_element._current;
  v13.m_end_bucket = v12.m_end_bucket;
  v13.m_curr_element._list = v12.m_curr_element._list;
  v13.m_end_element._current = v12.m_end_element._current;
  v13.m_end_element._list = v12.m_end_element._list;
  while ( 1 )
  {
    v6 = *(_DWORD *)(a2 + 8);
    v7 = 16 * *(_DWORD *)a2;
    v12.m_curr_bucket = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)(v6 + v7);
    v12.m_end_bucket = (List<DualHashData<UIOption_Slider *,UIOption_Slider *> *> *)(v6 + v7);
    v12.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
    v12.m_curr_element._current = 0;
    v12.m_curr_element._list = 0;
    v12.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
    v12.m_end_element._current = 0;
    v12.m_end_element._list = 0;
    DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(&v12);
    if ( v4 && v4 != v13.m_end_bucket && v13.m_end_element._current != v5 )
      v8 = v4 != v12.m_curr_bucket || v12.m_curr_element._current != v5 ? 0 : 1;
    else
      v8 = (_DWORD)v12.m_curr_bucket
        && v12.m_curr_bucket != v12.m_end_bucket
        && v12.m_end_element._current != v12.m_curr_element._current ? 0 : 1;
    v12.m_end_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
    v12.m_curr_element.vfptr = (ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>Vtbl *)ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable;
    if ( v8 )
      break;
    ++amount;
    DualHash<UIOption_Slider *,UIOption_Slider *>::add_internal(v11, &v5->data->m_left_data, &v5->data->m_right_data);
    if ( v4 != v13.m_end_bucket )
    {
      v5 = v5->next;
      v13.m_curr_element._current = v5;
      if ( v13.m_end_element._current == v5 )
      {
        v13.m_curr_bucket = v4 + 1;
        DualHashIter<UIOption_Slider *,UIOption_Slider *>::start_bucket(&v13);
        v5 = v13.m_curr_element._current;
        v4 = v13.m_curr_bucket;
      }
    }
  }
  DualHash<UIOption_Slider *,UIOption_Slider *>::inc_num_elements(v11, amount);
  return v11;
}
// 7A8D70: using guessed type int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char);

//----- (0049FA80) --------------------------------------------------------  // acclient.c:216796
void __userpurge gmChatOptionsUI::gmChatOptionsUI(gmChatOptionsUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmChatOptionsUI *v4; // esi@1
  int v5; // ecx@1

  v4 = this;
  PlayerOptionPage::PlayerOptionPage((PlayerOptionPage *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v5 = (int)&v4->m_hashSliderLinks;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmChatOptionsUI::vftable;
  v4->vfptr = (IOptionChangeHandlerVtbl *)&gmChatOptionsUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  DualHash<UIOption_Slider *,UIOption_Slider *>::init(&v4->m_hashSliderLinks, 0x40u);
}
// 7A8D78: using guessed type void (__thiscall *gmChatOptionsUI::vftable)(gmChatOptionsUI *this, const struct UIOption *);
// 7A8D80: using guessed type int (__thiscall *gmChatOptionsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0049FAE0) --------------------------------------------------------  // acclient.c:216818
signed int __thiscall gmChatOptionsUI::DynamicCast(gmChatOptionsUI *this, unsigned int i_eType)
{
  return i_eType != 268435522 ? 0 : (unsigned int)this;
}

//----- (0049FB00) --------------------------------------------------------  // acclient.c:216824
signed int gmChatOptionsUI::GetUIElementType()
{
  return 268435522;
}

//----- (0049FB10) --------------------------------------------------------  // acclient.c:216830
void __thiscall gmChatOptionsUI::~gmChatOptionsUI(gmChatOptionsUI *this)
{
  PlayerOptionPage *v1; // esi@1
  char *v2; // edi@1
  NoticeHandler *v3; // ebx@1
  int v4; // ecx@1
  int v5; // ecx@5

  v1 = (PlayerOptionPage *)this;
  v2 = (char *)&this->m_hashSliderLinks;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmChatOptionsUI::vftable;
  this->vfptr = (IOptionChangeHandlerVtbl *)&gmChatOptionsUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  DualHash<UIOption_Slider *,UIOption_Slider *>::clear(&this->m_hashSliderLinks);
  v4 = *((_DWORD *)v2 + 2);
  if ( v4 )
  {
    if ( *(_DWORD *)(v4 - 4) )
      (**(void (__stdcall ***)(_DWORD))v4)(3);
    else
      operator delete[]((void *)(v4 - 4));
  }
  v5 = *((_DWORD *)v2 + 3);
  if ( v5 )
  {
    if ( *(_DWORD *)(v5 - 4) )
      (**(void (__stdcall ***)(_DWORD))v5)(3);
    else
      operator delete[]((void *)(v5 - 4));
  }
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  PlayerOptionPage::~PlayerOptionPage(v1);
}
// 7A8D78: using guessed type void (__thiscall *gmChatOptionsUI::vftable)(gmChatOptionsUI *this, const struct UIOption *);
// 7A8D80: using guessed type int (__thiscall *gmChatOptionsUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (0049FBA0) --------------------------------------------------------  // acclient.c:216870
void __usercall gmChatOptionsUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmChatOptionsUI *v3; // eax@1

  v3 = (gmChatOptionsUI *)operator new(0x618u);
  if ( v3 )
    gmChatOptionsUI::gmChatOptionsUI(v3, a1, _layout, _full_desc);
}

//----- (0049FBD0) --------------------------------------------------------  // acclient.c:216880
char __thiscall DualHash<UIOption_Slider *,UIOption_Slider *>::add(DualHash<UIOption_Slider *,UIOption_Slider *> *this, UIOption_Slider *const *left, UIOption_Slider *const *right)
{
  DualHash<UIOption_Slider *,UIOption_Slider *> *v3; // esi@1
  char result; // al@3

  v3 = this;
  if ( DualHash<UIOption_Slider *,UIOption_Slider *>::contains_left(this, left)
    || DualHash<UIOption_Slider *,UIOption_Slider *>::contains_right(v3, right) )
  {
    result = 0;
  }
  else
  {
    DualHash<UIOption_Slider *,UIOption_Slider *>::add_internal(v3, left, right);
    DualHash<UIOption_Slider *,UIOption_Slider *>::inc_num_elements(v3, 1u);
    result = 1;
  }
  return result;
}

//----- (0049FC20) --------------------------------------------------------  // acclient.c:216901
gmChatOptionsUI *__thiscall gmChatOptionsUI::vector_deleting_destructor(gmChatOptionsUI *this, unsigned int a2)
{
  gmChatOptionsUI *v2; // esi@1

  v2 = this;
  gmChatOptionsUI::~gmChatOptionsUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0049FC40) --------------------------------------------------------  // acclient.c:216913
void __cdecl gmChatOptionsUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000042u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmChatOptionsUI::Create);
}

//----- (0049FC60) --------------------------------------------------------  // acclient.c:216921
void __thiscall gmChatOptionsUI::InitOptions(gmChatOptionsUI *this)
{
  gmChatOptionsUI *v1; // edi@1
  UIElement_ListBox *v2; // ecx@1
  UIOption *v3; // ebx@1
  int v4; // eax@2
  UIElement *v5; // eax@3
  int v6; // eax@4
  UIElement_ListBox *v7; // ecx@7
  UIOption *v8; // esi@7
  int v9; // eax@8
  UIElement *v10; // eax@9
  int v11; // eax@10
  UIElement_ListBox *v12; // ecx@16
  int v13; // eax@17
  int v14; // eax@18
  UIOption *v15; // esi@19
  UIElement_ListBox *v16; // ecx@21
  int v17; // eax@22
  int v18; // eax@23
  UIOption *v19; // esi@24
  UIOption_Slider *right; // [sp+Ch] [bp-8h]@13
  UIOption_Slider *left; // [sp+10h] [bp-4h]@13

  v1 = this;
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&this->vfptr, ID_ChatOption_GeneralOptions_Section);
  v2 = v1->m_pOptionBox;
  v3 = 0;
  if ( v2 )
  {
    v4 = UIElement_ListBox::AddItemFromTemplateList(v2, 3u, 0);
    if ( v4 )
    {
      v5 = UIElement::GetChildRecursive((UIElement *)v4, 0x1000021Cu);
      if ( v5 )
      {
        v6 = v5->vfptr[12].OnAction((IInputActionCallback *)v5, (InputEvent *)268435511);
        if ( v6 )
        {
          v3 = (UIOption *)(v6 - 32);
          if ( v6 != 32 )
          {
            UIOption_Slider::SetGameplayOptionProperty((UIOption_Slider *)(v6 - 32), 0x10000080u);
            OptionPage::RegisterOption((OptionPage *)&v1->vfptr, v3);
          }
        }
        else
        {
          v3 = 0;
        }
      }
    }
  }
  v7 = v1->m_pOptionBox;
  v8 = 0;
  if ( v7 )
  {
    v9 = UIElement_ListBox::AddItemFromTemplateList(v7, 6u, 0);
    if ( v9 )
    {
      v10 = UIElement::GetChildRecursive((UIElement *)v9, 0x1000021Cu);
      if ( v10 )
      {
        v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)268435511);
        if ( v11 )
        {
          v8 = (UIOption *)(v11 - 32);
          if ( v11 != 32 )
          {
            UIOption_Slider::SetGameplayOptionProperty((UIOption_Slider *)(v11 - 32), 0x10000081u);
            OptionPage::RegisterOption((OptionPage *)&v1->vfptr, v8);
          }
        }
        else
        {
          v8 = 0;
        }
      }
    }
  }
  PlayerOptionPage::SetSliderLabel((UIOption_Slider *)v8, ID_UI_Value_Transparent, ID_UI_Value_Opaque);
  right = (UIOption_Slider *)v8;
  left = (UIOption_Slider *)v3;
  if ( v3 && v8 )
    DualHash<UIOption_Slider *,UIOption_Slider *>::add(&v1->m_hashSliderLinks, &left, &right);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_ChatOption_MainChatWindow_Section);
  v12 = v1->m_pOptionBox;
  if ( v12 )
  {
    v13 = UIElement_ListBox::AddItemFromTemplateList(v12, 8u, 0);
    if ( v13 )
    {
      v14 = (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v13 + 148))(v13, 268435524);
      if ( v14 )
      {
        v15 = (UIOption *)(v14 - 32);
        if ( v14 != 32 )
        {
          UIOption_CheckboxBitfield64::SetGameplayOptionProperty(
            (UIOption_CheckboxBitfield64 *)(v14 - 32),
            0x1000007Fu,
            Chat_PropType);
          UIOption::SetUserData(v15, 8u);
          ((void (__thiscall *)(UIOption *, signed int, _DWORD))v15->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
            v15,
            -67108865,
            0);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            (unsigned int)&loc_600040,
            ID_ChatOption_TextFilter_Combat,
            ID_ChatOption_TextFilter_Combat_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x20080ui64,
            ID_ChatOption_TextFilter_Magic,
            ID_ChatOption_TextFilter_Magic_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x1004ui64,
            ID_ChatOption_TextFilter_AreaSpeech,
            ID_ChatOption_TextFilter_AreaSpeech_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x18ui64,
            ID_ChatOption_TextFilter_Tells,
            ID_ChatOption_TextFilter_Tells_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x40C00ui64,
            ID_ChatOption_TextFilter_Allegience,
            ID_ChatOption_TextFilter_Allegience_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x80000ui64,
            ID_ChatOption_TextFilter_Fellowship,
            ID_ChatOption_TextFilter_Fellowship_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x8000000ui64,
            ID_ChatOption_TextFilter_General,
            ID_ChatOption_TextFilter_General_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x10000000ui64,
            ID_ChatOption_TextFilter_Trade,
            ID_ChatOption_TextFilter_Trade_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x20000000ui64,
            ID_ChatOption_TextFilter_LFG,
            ID_ChatOption_TextFilter_LFG_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x40000000ui64,
            ID_ChatOption_TextFilter_Roleplay,
            ID_ChatOption_TextFilter_Roleplay_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x100000000ui64,
            ID_ChatOption_TextFilter_Society,
            ID_ChatOption_TextFilter_Society_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v15,
            0x4000000ui64,
            ID_ChatOption_TextFilter_Error,
            ID_ChatOption_TextFilter_Error_Desc);
          UIOption_CheckboxBitfield64::CreateChildren((UIOption_CheckboxBitfield64 *)v15);
          OptionPage::RegisterOption((OptionPage *)&v1->vfptr, v15);
        }
      }
    }
  }
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_ChatOption_FloatyChatWindow1_Section);
  gmChatOptionsUI::AddCheckboxBitfield64Option(v1, &Option_TextType_Property, 2u);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_ChatOption_FloatyChatWindow2_Section);
  gmChatOptionsUI::AddCheckboxBitfield64Option(v1, &Option_TextType_Property, 3u);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_ChatOption_FloatyChatWindow3_Section);
  gmChatOptionsUI::AddCheckboxBitfield64Option(v1, &Option_TextType_Property, 4u);
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
  PlayerOptionPage::AddHeader((PlayerOptionPage *)&v1->vfptr, ID_ChatOption_FloatyChatWindow4_Section);
  v16 = v1->m_pOptionBox;
  if ( v16 )
  {
    v17 = UIElement_ListBox::AddItemFromTemplateList(v16, 8u, 0);
    if ( v17 )
    {
      v18 = (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v17 + 148))(v17, 268435524);
      if ( v18 )
      {
        v19 = (UIOption *)(v18 - 32);
        if ( v18 != 32 )
        {
          UIOption_CheckboxBitfield64::SetGameplayOptionProperty(
            (UIOption_CheckboxBitfield64 *)(v18 - 32),
            0x1000007Fu,
            Chat_PropType);
          UIOption::SetUserData(v19, 5u);
          ((void (__thiscall *)(UIOption *, signed int, _DWORD))v19->vfptr[7].RecvNotice_DisplayFinalStringInfo)(
            v19,
            2013265920,
            0);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x83912021ui64,
            ID_ChatOption_TextFilter_Gameplay,
            ID_ChatOption_TextFilter_Gameplay_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            (unsigned int)&loc_600040,
            ID_ChatOption_TextFilter_Combat,
            ID_ChatOption_TextFilter_Combat_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x20080ui64,
            ID_ChatOption_TextFilter_Magic,
            ID_ChatOption_TextFilter_Magic_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x1004ui64,
            ID_ChatOption_TextFilter_AreaSpeech,
            ID_ChatOption_TextFilter_AreaSpeech_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x18ui64,
            ID_ChatOption_TextFilter_Tells,
            ID_ChatOption_TextFilter_Tells_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x40C00ui64,
            ID_ChatOption_TextFilter_Allegience,
            ID_ChatOption_TextFilter_Allegience_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x80000ui64,
            ID_ChatOption_TextFilter_Fellowship,
            ID_ChatOption_TextFilter_Fellowship_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x8000000ui64,
            ID_ChatOption_TextFilter_General,
            ID_ChatOption_TextFilter_General_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x10000000ui64,
            ID_ChatOption_TextFilter_Trade,
            ID_ChatOption_TextFilter_Trade_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x20000000ui64,
            ID_ChatOption_TextFilter_LFG,
            ID_ChatOption_TextFilter_LFG_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x40000000ui64,
            ID_ChatOption_TextFilter_Roleplay,
            ID_ChatOption_TextFilter_Roleplay_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x100000000ui64,
            ID_ChatOption_TextFilter_Society,
            ID_ChatOption_TextFilter_Society_Desc);
          UIOption_CheckboxBitfield64::AddChild(
            (UIOption_CheckboxBitfield64 *)v19,
            0x4000000ui64,
            ID_ChatOption_TextFilter_Error,
            ID_ChatOption_TextFilter_Error_Desc);
          UIOption_CheckboxBitfield64::CreateChildren((UIOption_CheckboxBitfield64 *)v19);
          OptionPage::RegisterOption((OptionPage *)&v1->vfptr, v19);
        }
      }
    }
  }
  PlayerOptionPage::AddSeperator((PlayerOptionPage *)&v1->vfptr);
}

//----- (006F02B0) --------------------------------------------------------  // acclient.c:772253
void _E91_65()
{
  outside_val_57 = 1000.0 + 1.0;
}

//----- (006F02D0) --------------------------------------------------------  // acclient.c:772259
void _E93_41()
{
  block_length_57 = 24.0 * 8.0;
}

//----- (006F02F0) --------------------------------------------------------  // acclient.c:772265
void _E95_41()
{
  half_square_length_57 = 24.0 * 0.5;
}

//----- (006F0310) --------------------------------------------------------  // acclient.c:772271
int _E97_66()
{
  return atexit(_E98_78);
}

//----- (006F0320) --------------------------------------------------------  // acclient.c:772277
int _E100_59()
{
  return atexit(_E101_96);
}

//----- (006F0330) --------------------------------------------------------  // acclient.c:772283
int _E103_51()
{
  return atexit(_E104_66);
}

//----- (006F0340) --------------------------------------------------------  // acclient.c:772289
void _E106_41()
{
  DEFAULT_VIEW_RADIUS_31 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F0360) --------------------------------------------------------  // acclient.c:772295
void _E108_29()
{
  MIN_QUANTUM_31 = 1.0 / 30.0;
}

//----- (006F0380) --------------------------------------------------------  // acclient.c:772301
void _E110_20()
{
  MAX_QUANTUM_31 = 1.0 / 5.0;
}

//----- (006F03A0) --------------------------------------------------------  // acclient.c:772307
void _E112_36()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_66, PFID_A8R8G8B8);
}

//----- (006F03B0) --------------------------------------------------------  // acclient.c:772313
int _E114_23()
{
  return atexit(nullsub_928);
}

//----- (006F03C0) --------------------------------------------------------  // acclient.c:772319
unsigned int _E117_22()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_GeneralOptions_Section");
  ID_ChatOption_GeneralOptions_Section = result;
  return result;
}

//----- (006F03E0) --------------------------------------------------------  // acclient.c:772329
unsigned int _E119_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_MainChatWindow_Section");
  ID_ChatOption_MainChatWindow_Section = result;
  return result;
}

//----- (006F0400) --------------------------------------------------------  // acclient.c:772339
unsigned int _E121_34()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_FloatyChatWindow1_Section");
  ID_ChatOption_FloatyChatWindow1_Section = result;
  return result;
}

//----- (006F0420) --------------------------------------------------------  // acclient.c:772349
unsigned int _E123_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_FloatyChatWindow2_Section");
  ID_ChatOption_FloatyChatWindow2_Section = result;
  return result;
}

//----- (006F0440) --------------------------------------------------------  // acclient.c:772359
unsigned int _E125_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_FloatyChatWindow3_Section");
  ID_ChatOption_FloatyChatWindow3_Section = result;
  return result;
}

//----- (006F0460) --------------------------------------------------------  // acclient.c:772369
unsigned int _E127_28()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_FloatyChatWindow4_Section");
  ID_ChatOption_FloatyChatWindow4_Section = result;
  return result;
}

//----- (006F0480) --------------------------------------------------------  // acclient.c:772379
unsigned int _E129_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_UI_Value_Transparent");
  ID_UI_Value_Transparent = result;
  return result;
}

//----- (006F04A0) --------------------------------------------------------  // acclient.c:772389
unsigned int _E131_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_UI_Value_Opaque");
  ID_UI_Value_Opaque = result;
  return result;
}

//----- (006F04C0) --------------------------------------------------------  // acclient.c:772399
unsigned int _E133_21()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Combat");
  ID_ChatOption_TextFilter_Combat = result;
  return result;
}

//----- (006F04E0) --------------------------------------------------------  // acclient.c:772409
unsigned int _E135_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Combat_Desc");
  ID_ChatOption_TextFilter_Combat_Desc = result;
  return result;
}

//----- (006F0500) --------------------------------------------------------  // acclient.c:772419
unsigned int _E137_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_AreaSpeech");
  ID_ChatOption_TextFilter_AreaSpeech = result;
  return result;
}

//----- (006F0520) --------------------------------------------------------  // acclient.c:772429
unsigned int _E139_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_AreaSpeech_Desc");
  ID_ChatOption_TextFilter_AreaSpeech_Desc = result;
  return result;
}

//----- (006F0540) --------------------------------------------------------  // acclient.c:772439
unsigned int _E141_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Gameplay");
  ID_ChatOption_TextFilter_Gameplay = result;
  return result;
}

//----- (006F0560) --------------------------------------------------------  // acclient.c:772449
unsigned int _E143_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Gameplay_Desc");
  ID_ChatOption_TextFilter_Gameplay_Desc = result;
  return result;
}

//----- (006F0580) --------------------------------------------------------  // acclient.c:772459
unsigned int _E145_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Magic");
  ID_ChatOption_TextFilter_Magic = result;
  return result;
}

//----- (006F05A0) --------------------------------------------------------  // acclient.c:772469
unsigned int _E147_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Magic_Desc");
  ID_ChatOption_TextFilter_Magic_Desc = result;
  return result;
}

//----- (006F05C0) --------------------------------------------------------  // acclient.c:772479
unsigned int _E149_2()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Tells");
  ID_ChatOption_TextFilter_Tells = result;
  return result;
}

//----- (006F05E0) --------------------------------------------------------  // acclient.c:772489
unsigned int _E151_17()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Tells_Desc");
  ID_ChatOption_TextFilter_Tells_Desc = result;
  return result;
}

//----- (006F0600) --------------------------------------------------------  // acclient.c:772499
unsigned int _E153_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Allegience");
  ID_ChatOption_TextFilter_Allegience = result;
  return result;
}

//----- (006F0620) --------------------------------------------------------  // acclient.c:772509
unsigned int _E155_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Allegience_Desc");
  ID_ChatOption_TextFilter_Allegience_Desc = result;
  return result;
}

//----- (006F0640) --------------------------------------------------------  // acclient.c:772519
unsigned int _E157_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Fellowship");
  ID_ChatOption_TextFilter_Fellowship = result;
  return result;
}

//----- (006F0660) --------------------------------------------------------  // acclient.c:772529
unsigned int _E159_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Fellowship_Desc");
  ID_ChatOption_TextFilter_Fellowship_Desc = result;
  return result;
}

//----- (006F0680) --------------------------------------------------------  // acclient.c:772539
unsigned int _E161_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_General");
  ID_ChatOption_TextFilter_General = result;
  return result;
}

//----- (006F06A0) --------------------------------------------------------  // acclient.c:772549
unsigned int _E163_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_General_Desc");
  ID_ChatOption_TextFilter_General_Desc = result;
  return result;
}

//----- (006F06C0) --------------------------------------------------------  // acclient.c:772559
unsigned int _E165_15()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Trade");
  ID_ChatOption_TextFilter_Trade = result;
  return result;
}

//----- (006F06E0) --------------------------------------------------------  // acclient.c:772569
unsigned int _E167_1()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Trade_Desc");
  ID_ChatOption_TextFilter_Trade_Desc = result;
  return result;
}

//----- (006F0700) --------------------------------------------------------  // acclient.c:772579
unsigned int _E169_12()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_LFG");
  ID_ChatOption_TextFilter_LFG = result;
  return result;
}

//----- (006F0720) --------------------------------------------------------  // acclient.c:772589
unsigned int _E171_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_LFG_Desc");
  ID_ChatOption_TextFilter_LFG_Desc = result;
  return result;
}

//----- (006F0740) --------------------------------------------------------  // acclient.c:772599
unsigned int _E173()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Roleplay");
  ID_ChatOption_TextFilter_Roleplay = result;
  return result;
}

//----- (006F0760) --------------------------------------------------------  // acclient.c:772609
unsigned int _E175_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Roleplay_Desc");
  ID_ChatOption_TextFilter_Roleplay_Desc = result;
  return result;
}

//----- (006F0780) --------------------------------------------------------  // acclient.c:772619
unsigned int _E177_14()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Society");
  ID_ChatOption_TextFilter_Society = result;
  return result;
}

//----- (006F07A0) --------------------------------------------------------  // acclient.c:772629
unsigned int _E179_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Society_Desc");
  ID_ChatOption_TextFilter_Society_Desc = result;
  return result;
}

//----- (006F07C0) --------------------------------------------------------  // acclient.c:772639
unsigned int _E181_11()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Error");
  ID_ChatOption_TextFilter_Error = result;
  return result;
}

//----- (006F07E0) --------------------------------------------------------  // acclient.c:772649
unsigned int _E183_13()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_ChatOption_TextFilter_Error_Desc");
  ID_ChatOption_TextFilter_Error_Desc = result;
  return result;
}

//----- (006F0800) --------------------------------------------------------  // acclient.c:772659
int sub_6F0800()
{
  return atexit(nullsub_929);
}

