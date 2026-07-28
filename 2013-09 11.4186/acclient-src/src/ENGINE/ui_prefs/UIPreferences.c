/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIPreferences
   Object     : ENGINE\ui_prefs\UIPreferences.obj
   Functions  : 80
   Addresses  : 004134D0 - 0077E9A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004134D0) --------------------------------------------------------  // acclient.c:79203
IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *this, IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *result, PStringBase<char> *_key)
{
  PSRefBufferCharData<char> *v3; // esi@1
  unsigned int v4; // eax@1
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v5; // edi@1
  unsigned int v6; // ebx@1
  int v7; // edx@3
  HashTableData<PStringBase<char>,UIPreferenceItem *> **v8; // eax@3
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v9; // esi@3
  HashTableData<PStringBase<char>,UIPreferenceItem *> **i; // ebx@3
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v11; // eax@6

  v3 = _key->m_charbuffer;
  v4 = *(_DWORD *)&_key->m_charbuffer[-1].m_data[8];
  v5 = this;
  v6 = this->m_numBuckets;
  if ( v4 == -1 )
  {
    v4 = compute_str_hash(_key->m_charbuffer->m_data);
    *(_DWORD *)&v3[-1].m_data[8] = v4;
  }
  v7 = v4 % v6;
  v8 = v5->m_buckets;
  v9 = v8[v7];
  for ( i = &v8[v7]; v9; v9 = v9->m_hashNext )
  {
    if ( PStringBase<char>::operator==(&v9->m_hashKey, _key) )
      break;
  }
  v11 = result;
  result->m_currHashTable = v5;
  result->m_currElement = v9;
  result->m_currBucket = i;
  return v11;
}

//----- (00428900) --------------------------------------------------------  // acclient.c:100913
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *this, IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> iter)
{
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v2; // eax@1
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v3; // edx@2

  v2 = *iter.m_currBucket;
  if ( *iter.m_currBucket == iter.m_currElement )
    goto LABEL_8;
  do
  {
    v3 = v2;
    v2 = v2->m_hashNext;
  }
  while ( v2 != iter.m_currElement );
  if ( v3 )
  {
    v3->m_hashNext = v2->m_hashNext;
    --this->m_numElements;
  }
  else
  {
LABEL_8:
    *iter.m_currBucket = v2->m_hashNext;
    --this->m_numElements;
  }
}

//----- (005DD250) --------------------------------------------------------  // acclient.c:519991
IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vector_deleting_destructor(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v2; // esi@1
  HashTableData<PStringBase<char>,UIPreferenceItem *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E9588: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable)(void *, char);

//----- (005DD290) --------------------------------------------------------  // acclient.c:520012
void __thiscall UIPreferenceItem::~UIPreferenceItem(UIPreferenceItem *this)
{
  char *v1; // esi@1

  v1 = &this->m_strPreference.m_charbuffer[-2].m_data[12];
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItem::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v1 + 1) )
  {
    if ( v1 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  }
}
// 7E9590: using guessed type int (__thiscall *UIPreferenceItem::vftable)(void *, char);

//----- (005DD2C0) --------------------------------------------------------  // acclient.c:520027
UIPreferenceItem *__thiscall UIPreferenceItem::scalar_deleting_destructor(UIPreferenceItem *this, unsigned int a2)
{
  UIPreferenceItem *v2; // edi@1
  char *v3; // esi@1

  v2 = this;
  v3 = &this->m_strPreference.m_charbuffer[-2].m_data[12];
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItem::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v3 + 1) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E9590: using guessed type int (__thiscall *UIPreferenceItem::vftable)(void *, char);

//----- (005DD310) --------------------------------------------------------  // acclient.c:520044
void __thiscall UIPreferenceItemBool::UIPreferenceItemBool(UIPreferenceItemBool *this)
{
  UIPreferenceItemBool *v1; // esi@1

  v1 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItem::vftable;
  PStringBase<char>::PStringBase<char>(&this->m_strPreference, &name);
  v1->m_dataType = 0;
  v1->m_eStringTable = 0;
  v1->m_tokenPreference = 0;
  v1->m_tokenTooltip = 0;
  v1->m_bCache = 0;
  v1->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemBool::vftable;
}
// 7E9590: using guessed type int (__thiscall *UIPreferenceItem::vftable)(void *, char);
// 7E9600: using guessed type int (__thiscall *UIPreferenceItemBool::vftable)(void *, char);

//----- (005DD350) --------------------------------------------------------  // acclient.c:520062
bool __thiscall UIPreferenceItemBool::InqBool(UIPreferenceItemBool *this, bool *o_value)
{
  return UserPreferences::InqValue(&this->m_strPreference, o_value);
}

//----- (005DD370) --------------------------------------------------------  // acclient.c:520068
char __thiscall UIPreferenceItemBool::SetBool(UIPreferenceItemBool *this, const bool i_value)
{
  return UserPreferences::SetValue(&this->m_strPreference, i_value);
}

//----- (005DD390) --------------------------------------------------------  // acclient.c:520074
char __thiscall UIPreferenceItemBool::InqCachedBool(UIPreferenceItemBool *this, bool *o_value)
{
  *o_value = this->m_bCache;
  return 1;
}

//----- (005DD3A0) --------------------------------------------------------  // acclient.c:520081
char __thiscall UIPreferenceItemBool::SetCachedBool(UIPreferenceItemBool *this, const bool i_value)
{
  this->m_bCache = i_value;
  return 1;
}

//----- (005DD3B0) --------------------------------------------------------  // acclient.c:520088
UIPreferenceItemBool *__thiscall UIPreferenceItemBool::vector_deleting_destructor(UIPreferenceItemBool *this, unsigned int a2)
{
  UIPreferenceItemBool *v2; // esi@1

  v2 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemBool::vftable;
  UIPreferenceItem::~UIPreferenceItem((UIPreferenceItem *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E9600: using guessed type int (__thiscall *UIPreferenceItemBool::vftable)(void *, char);

//----- (005DD3E0) --------------------------------------------------------  // acclient.c:520102
void __thiscall UIPreferenceItemEnum::UIPreferenceItemEnum(UIPreferenceItemEnum *this)
{
  UIPreferenceItemEnum *v1; // esi@1

  v1 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItem::vftable;
  PStringBase<char>::PStringBase<char>(&this->m_strPreference, &name);
  v1->m_dataType = 0;
  v1->m_eStringTable = 0;
  v1->m_tokenPreference = 0;
  v1->m_tokenTooltip = 0;
  v1->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemEnum::vftable;
  v1->m_nCache = -1;
  v1->m_arrayChoices.m_data = 0;
  v1->m_arrayChoices.m_sizeAndDeallocate = 0;
  v1->m_arrayChoices.m_num = 0;
}
// 7E9590: using guessed type int (__thiscall *UIPreferenceItem::vftable)(void *, char);
// 7E9670: using guessed type int (__thiscall *UIPreferenceItemEnum::vftable)(void *, char);

//----- (005DD420) --------------------------------------------------------  // acclient.c:520123
bool __thiscall UIPreferenceItemEnum::InqEnum(UIPreferenceItemEnum *this, unsigned int *o_value)
{
  return UserPreferences::InqValue(&this->m_strPreference, o_value);
}

//----- (005DD440) --------------------------------------------------------  // acclient.c:520129
char __thiscall UIPreferenceItemEnum::SetEnum(UIPreferenceItemEnum *this, const unsigned int i_value)
{
  return UserPreferences::SetValue(&this->m_strPreference, i_value);
}

//----- (005DD460) --------------------------------------------------------  // acclient.c:520135
UIPreferenceItem *__thiscall UIPreferenceItemEnum::scalar_deleting_destructor(UIPreferenceItemEnum *this, unsigned int a2)
{
  UIPreferenceItem *v2; // esi@1

  v2 = (UIPreferenceItem *)this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemEnum::vftable;
  SmartArray<char *,1>::~SmartArray<char *,1>((SmartArray<long,1> *)&this->m_arrayChoices);
  UIPreferenceItem::~UIPreferenceItem(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E9670: using guessed type int (__thiscall *UIPreferenceItemEnum::vftable)(void *, char);

//----- (005DD490) --------------------------------------------------------  // acclient.c:520150
char __thiscall UIPreferenceItemEnum::InqEnumChoices(UIPreferenceItemEnum *this, SmartArray<unsigned long,1> *o_arrayChoices)
{
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)o_arrayChoices, (int)&this->m_arrayChoices);
  return 1;
}

//----- (005DD4B0) --------------------------------------------------------  // acclient.c:520157
char __thiscall UIPreferenceItemEnum::SetEnumChoices(UIPreferenceItemEnum *this, SmartArray<unsigned long,1> *i_arrayChoices)
{
  return SmartArray<unsigned long,1>::AddToEnd(&this->m_arrayChoices, i_arrayChoices);
}

//----- (005DD4C0) --------------------------------------------------------  // acclient.c:520163
char __thiscall SmartArray<unsigned long,1>::AddToEnd(SmartArray<unsigned long,1> *this, SmartArray<unsigned long,1> *i_rRhs)
{
  SmartArray<unsigned long,1> *v2; // esi@1
  unsigned int i; // eax@1
  unsigned int v4; // ecx@2
  int v5; // edx@2

  v2 = this;
  SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)this, i_rRhs->m_num + this->m_num);
  for ( i = i_rRhs->m_num - 1; (i & 0x80000000) == 0; v2->m_data[v5] = v4 )
  {
    v4 = i_rRhs->m_data[i];
    v5 = i-- + v2->m_num;
  }
  v2->m_num += i_rRhs->m_num;
  return 1;
}

//----- (005DD510) --------------------------------------------------------  // acclient.c:520182
void __thiscall UIPreferenceItemFloat::UIPreferenceItemFloat(UIPreferenceItemFloat *this)
{
  UIPreferenceItemFloat *v1; // esi@1

  v1 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItem::vftable;
  PStringBase<char>::PStringBase<char>(&this->m_strPreference, &name);
  v1->m_dataType = 0;
  v1->m_eStringTable = 0;
  v1->m_tokenPreference = 0;
  v1->m_tokenTooltip = 0;
  LODWORD(v1->m_nCache) = 0;
  LODWORD(v1->m_nMin) = 0;
  v1->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemFloat::vftable;
  LODWORD(v1->m_nMax) = 1065353216;
}
// 7E9590: using guessed type int (__thiscall *UIPreferenceItem::vftable)(void *, char);
// 7E96E0: using guessed type int (__thiscall *UIPreferenceItemFloat::vftable)(void *, char);

//----- (005DD550) --------------------------------------------------------  // acclient.c:520202
bool __thiscall UIPreferenceItemFloat::InqFloat(UIPreferenceItemFloat *this, float *o_value)
{
  return UserPreferences::InqValue(&this->m_strPreference, o_value);
}

//----- (005DD570) --------------------------------------------------------  // acclient.c:520208
char __thiscall UIPreferenceItemFloat::SetFloat(UIPreferenceItemFloat *this, const float i_value)
{
  return UserPreferences::SetValue(&this->m_strPreference, i_value);
}

//----- (005DD590) --------------------------------------------------------  // acclient.c:520214
char __thiscall UIPreferenceItemInt::InqIntegerRange(UIPreferenceItemInt *this, int *o_nMin, int *o_nMax)
{
  *o_nMin = this->m_nMin;
  *o_nMax = this->m_nMax;
  return 1;
}

//----- (005DD5B0) --------------------------------------------------------  // acclient.c:520222
char __thiscall UIPreferenceItemFloat::SetFloatRange(UIPreferenceItemInt *this, const int i_nMin, const int i_nMax)
{
  this->m_nMin = i_nMin;
  this->m_nMax = i_nMax;
  return 1;
}

//----- (005DD5D0) --------------------------------------------------------  // acclient.c:520230
UIPreferenceItemFloat *__thiscall UIPreferenceItemFloat::vector_deleting_destructor(UIPreferenceItemFloat *this, unsigned int a2)
{
  UIPreferenceItemFloat *v2; // esi@1

  v2 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemFloat::vftable;
  UIPreferenceItem::~UIPreferenceItem((UIPreferenceItem *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E96E0: using guessed type int (__thiscall *UIPreferenceItemFloat::vftable)(void *, char);

//----- (005DD600) --------------------------------------------------------  // acclient.c:520244
void __thiscall UIPreferenceItemInt::UIPreferenceItemInt(UIPreferenceItemInt *this)
{
  UIPreferenceItemInt *v1; // esi@1

  v1 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItem::vftable;
  PStringBase<char>::PStringBase<char>(&this->m_strPreference, &name);
  v1->m_dataType = 0;
  v1->m_eStringTable = 0;
  v1->m_tokenPreference = 0;
  v1->m_tokenTooltip = 0;
  v1->m_nCache = 0;
  v1->m_nMin = 0;
  v1->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemInt::vftable;
  v1->m_nMax = 1;
}
// 7E9590: using guessed type int (__thiscall *UIPreferenceItem::vftable)(void *, char);
// 7E9750: using guessed type int (__thiscall *UIPreferenceItemInt::vftable)(void *, char);

//----- (005DD640) --------------------------------------------------------  // acclient.c:520264
bool __thiscall UIPreferenceItemInt::InqInteger(UIPreferenceItemInt *this, int *o_value)
{
  return UserPreferences::InqValue(&this->m_strPreference, o_value);
}

//----- (005DD660) --------------------------------------------------------  // acclient.c:520270
char __thiscall UIPreferenceItemInt::SetInteger(UIPreferenceItemInt *this, const int i_value)
{
  return UserPreferences::SetValue(&this->m_strPreference, i_value);
}

//----- (005DD680) --------------------------------------------------------  // acclient.c:520276
char __thiscall UIPreferenceItemInt::InqCachedInteger(UIPreferenceItemInt *this, int *o_value)
{
  *o_value = this->m_nCache;
  return 1;
}

//----- (005DD690) --------------------------------------------------------  // acclient.c:520283
char __thiscall UIPreferenceItemFloat::SetCachedFloat(UIPreferenceItemInt *this, const int i_value)
{
  this->m_nCache = i_value;
  return 1;
}

//----- (005DD6A0) --------------------------------------------------------  // acclient.c:520290
UIPreferenceItemInt *__thiscall UIPreferenceItemInt::vector_deleting_destructor(UIPreferenceItemInt *this, unsigned int a2)
{
  UIPreferenceItemInt *v2; // esi@1

  v2 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemInt::vftable;
  UIPreferenceItem::~UIPreferenceItem((UIPreferenceItem *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E9750: using guessed type int (__thiscall *UIPreferenceItemInt::vftable)(void *, char);

//----- (005DD6D0) --------------------------------------------------------  // acclient.c:520304
void __thiscall UIPreferenceItemString::UIPreferenceItemString(UIPreferenceItemString *this)
{
  UIPreferenceItemString *v1; // esi@1

  v1 = this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItem::vftable;
  PStringBase<char>::PStringBase<char>(&this->m_strPreference, &name);
  v1->m_dataType = 0;
  v1->m_eStringTable = 0;
  v1->m_tokenPreference = 0;
  v1->m_tokenTooltip = 0;
  v1->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemString::vftable;
  PStringBase<char>::PStringBase<char>(&v1->m_strCache, &name);
}
// 7E9590: using guessed type int (__thiscall *UIPreferenceItem::vftable)(void *, char);
// 7E97C0: using guessed type int (__thiscall *UIPreferenceItemString::vftable)(void *, char);

//----- (005DD710) --------------------------------------------------------  // acclient.c:520322
char __thiscall UIPreferenceItemString::InqString(UIPreferenceItemString *this, PStringBase<char> *o_value)
{
  return UserPreferences::InqValue(&this->m_strPreference, o_value);
}

//----- (005DD730) --------------------------------------------------------  // acclient.c:520328
char __thiscall UIPreferenceItemString::SetString(UIPreferenceItemString *this, PStringBase<char> *i_value)
{
  return UserPreferences::SetValue(&this->m_strPreference, i_value);
}

//----- (005DD750) --------------------------------------------------------  // acclient.c:520334
char __thiscall UIPreferenceItemString::InqCachedString(UIPreferenceItemString *this, PStringBase<char> *o_value)
{
  PStringBase<char>::set(o_value, &this->m_strCache);
  return 1;
}

//----- (005DD770) --------------------------------------------------------  // acclient.c:520341
char __thiscall UIPreferenceItemString::SetCachedString(UIPreferenceItemString *this, PStringBase<char> *i_value)
{
  PStringBase<char>::set(&this->m_strCache, i_value);
  return 1;
}

//----- (005DD790) --------------------------------------------------------  // acclient.c:520348
UIPreferenceItem *__thiscall UIPreferenceItemString::vector_deleting_destructor(UIPreferenceItemString *this, unsigned int a2)
{
  UIPreferenceItem *v2; // esi@1

  v2 = (UIPreferenceItem *)this;
  this->vfptr = (UIPreferenceItemVtbl *)&UIPreferenceItemString::vftable;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&this->m_strCache);
  UIPreferenceItem::~UIPreferenceItem(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E97C0: using guessed type int (__thiscall *UIPreferenceItemString::vftable)(void *, char);

//----- (005DD7C0) --------------------------------------------------------  // acclient.c:520363
char __cdecl UIPreferences::InqPreference(PStringBase<char> *i_strPreference, unsigned int *o_eStringTable, unsigned int *o_tokenDisplay, unsigned int *o_tokenTooltip)
{
  UIPreferenceItem *v4; // ecx@2
  char v5; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v4 = result.m_currElement->m_data;
    v5 = 1;
    if ( v4 )
    {
      *o_eStringTable = v4->m_eStringTable;
      *o_tokenDisplay = v4->m_tokenPreference;
      *o_tokenTooltip = v4->m_tokenTooltip;
      v5 = 1;
    }
  }
  else
  {
    v5 = 0;
  }
  return v5;
}

//----- (005DD810) --------------------------------------------------------  // acclient.c:520393
char __cdecl UIPreferences::SetPreferenceRange(PStringBase<char> *i_strPreference, const float i_nMin, const float i_nMax)
{
  UIPreferenceItem *v3; // ecx@2
  char v4; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v3 = result.m_currElement->m_data;
    v4 = 1;
    if ( v3 )
      v4 = ((int (__stdcall *)(_DWORD, _DWORD))v3->vfptr->SetFloatRange)(LODWORD(i_nMin), LODWORD(i_nMax));
  }
  else
  {
    v4 = 0;
  }
  return v4;
}

//----- (005DD860) --------------------------------------------------------  // acclient.c:520418
char __cdecl UIPreferences::InqPreferenceRange(PStringBase<char> *i_strPreference, float *o_nMin, float *o_nMax)
{
  UIPreferenceItem *v3; // ecx@2
  char v4; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v3 = result.m_currElement->m_data;
    v4 = 1;
    if ( v3 )
      v4 = ((int (__stdcall *)(float *, float *))v3->vfptr->InqFloatRange)(o_nMin, o_nMax);
  }
  else
  {
    v4 = 0;
  }
  return v4;
}

//----- (005DD8B0) --------------------------------------------------------  // acclient.c:520443
char __cdecl UIPreferences::InqPreferenceRange(PStringBase<char> *i_strPreference, int *o_nMin, int *o_nMax)
{
  UIPreferenceItem *v3; // ecx@2
  char v4; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v3 = result.m_currElement->m_data;
    v4 = 1;
    if ( v3 )
      v4 = ((int (__stdcall *)(int *, int *))v3->vfptr->InqIntegerRange)(o_nMin, o_nMax);
  }
  else
  {
    v4 = 0;
  }
  return v4;
}

//----- (005DD900) --------------------------------------------------------  // acclient.c:520468
char __cdecl UIPreferences::SetEnumChoices(PStringBase<char> *i_strPreference, SmartArray<unsigned long,1> *i_arrayChoices)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
    if ( v2 )
      v3 = ((int (__stdcall *)(SmartArray<unsigned long,1> *))v2->vfptr->SetEnumChoices)(i_arrayChoices);
  }
  else
  {
    v3 = 0;
  }
  return v3;
}

//----- (005DD940) --------------------------------------------------------  // acclient.c:520493
char __cdecl UIPreferences::InqEnumChoices(PStringBase<char> *i_strPreference, SmartArray<unsigned long,1> *o_arrayChoices)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
    if ( v2 )
      v3 = ((int (__stdcall *)(SmartArray<unsigned long,1> *))v2->vfptr->InqEnumChoices)(o_arrayChoices);
  }
  else
  {
    v3 = 0;
  }
  return v3;
}

//----- (005DD980) --------------------------------------------------------  // acclient.c:520518
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<PStringBase<char>,UIPreferenceItem *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,UIPreferenceItem *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7E9588: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable)(void *, char);

//----- (005DDA10) --------------------------------------------------------  // acclient.c:520551
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::add_internal(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *this, HashTableData<PStringBase<char>,UIPreferenceItem *> *data)
{
  char *v2; // edi@1
  unsigned int v3; // eax@1
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v4; // esi@1
  unsigned int v5; // ebp@1
  int v6; // edx@3
  HashTableData<PStringBase<char>,UIPreferenceItem *> **v7; // eax@3
  int v8; // eax@3

  v2 = data->m_hashKey.m_charbuffer->m_data;
  v3 = *(_DWORD *)&data->m_hashKey.m_charbuffer[-1].m_data[8];
  v4 = this;
  v5 = this->m_numBuckets;
  if ( v3 == -1 )
  {
    v3 = compute_str_hash(v2);
    *((_DWORD *)v2 - 2) = v3;
  }
  v6 = v3 % v5;
  v7 = v4->m_buckets;
  data->m_hashNext = v7[v6];
  v7[v6] = data;
  v8 = (int)&v7[v6];
  if ( (HashTableData<PStringBase<char>,UIPreferenceItem *> **)v8 < v4->m_firstInterestingBucket )
    v4->m_firstInterestingBucket = (HashTableData<PStringBase<char>,UIPreferenceItem *> **)v8;
  ++v4->m_numElements;
}

//----- (005DDA60) --------------------------------------------------------  // acclient.c:520581
char __cdecl UIPreferences::ModifyPreference(PStringBase<char> *i_strPreference, int i_bValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = (*((int (__stdcall **)(_DWORD))&v2->vfptr->__vecDelDtor + 2))(i_bValue);
  return v3;
}

//----- (005DDAA0) --------------------------------------------------------  // acclient.c:520607
char __cdecl UIPreferences::ModifyPreference(PStringBase<char> *i_strPreference, const int i_nValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = ((int (__stdcall *)(const int))v2->vfptr->SetInteger)(i_nValue);
  return v3;
}

//----- (005DDAE0) --------------------------------------------------------  // acclient.c:520633
char __cdecl UIPreferences::ModifyPreference(PStringBase<char> *i_strPreference, const unsigned int i_nValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = ((int (__stdcall *)(const unsigned int))v2->vfptr->SetEnum)(i_nValue);
  return v3;
}

//----- (005DDB20) --------------------------------------------------------  // acclient.c:520659
char __cdecl UIPreferences::ModifyPreference(PStringBase<char> *i_strPreference, const float i_nValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = ((int (__stdcall *)(_DWORD))v2->vfptr->SetFloat)(LODWORD(i_nValue));
  return v3;
}

//----- (005DDB60) --------------------------------------------------------  // acclient.c:520685
char __cdecl UIPreferences::InqPreferenceValue(PStringBase<char> *i_strPreference, bool *o_bValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = (*((int (__stdcall **)(bool *))&v2->vfptr->__vecDelDtor + 1))(o_bValue);
  return v3;
}

//----- (005DDBA0) --------------------------------------------------------  // acclient.c:520711
char __cdecl UIPreferences::InqPreferenceValue(PStringBase<char> *i_strPreference, int *o_nValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = (*((int (__stdcall **)(int *))&v2->vfptr->__vecDelDtor + 3))(o_nValue);
  return v3;
}

//----- (005DDBE0) --------------------------------------------------------  // acclient.c:520737
char __cdecl UIPreferences::InqPreferenceValue(PStringBase<char> *i_strPreference, unsigned int *o_nValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = ((int (__stdcall *)(unsigned int *))v2->vfptr->InqEnum)(o_nValue);
  return v3;
}

//----- (005DDC20) --------------------------------------------------------  // acclient.c:520763
char __cdecl UIPreferences::InqPreferenceValue(PStringBase<char> *i_strPreference, float *o_nValue)
{
  UIPreferenceItem *v2; // ecx@2
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v2 = result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v2 = 0;
  }
  if ( v3 )
    v3 = ((int (__stdcall *)(float *))v2->vfptr->InqFloat)(o_nValue);
  return v3;
}

//----- (005DDC60) --------------------------------------------------------  // acclient.c:520789
HashTableData<PStringBase<char>,UIPreferenceItem *> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::remove(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *this, PStringBase<char> *key)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v2; // esi@1
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v3; // edi@1
  _BYTE v4[12]; // ST00_12@2
  HashTableData<PStringBase<char>,UIPreferenceItem *> *result; // eax@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> iter; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    this,
    &iter,
    key);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    *(_QWORD *)&v4[4] = *(_QWORD *)&iter.m_currBucket;
    *(_DWORD *)v4 = iter.m_currHashTable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
      v2,
      *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005DDCC0) --------------------------------------------------------  // acclient.c:520820
HashTable<PStringBase<char>,UIPreferenceItem *,0> *__thiscall HashTable<PStringBase<char>,UIPreferenceItem *,0>::vector_deleting_destructor(HashTable<PStringBase<char>,UIPreferenceItem *,0> *this, unsigned int a2)
{
  HashTable<PStringBase<char>,UIPreferenceItem *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<PStringBase<char>,UIPreferenceItem *,0>Vtbl *)&HashTable<PStringBase<char>,UIPreferenceItem *,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E9588: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable)(void *, char);
// 7E9830: using guessed type int (__thiscall *HashTable<PStringBase<char>,UIPreferenceItem *,0>::vftable)(void *, char);

//----- (005DDD20) --------------------------------------------------------  // acclient.c:520846
char __cdecl UIPreferences::AttachPreference(PStringBase<char> *i_strPreference, const unsigned int i_dataType, const unsigned int i_eStringTable, const unsigned int i_tokenDisplay, const unsigned int i_tokenTooltip)
{
  char v5; // al@2
  UIPreferenceItemBool *v6; // eax@4
  UIPreferenceItem *v7; // eax@5
  UIPreferenceItemEnum *v8; // eax@6
  UIPreferenceItemFloat *v9; // eax@8
  UIPreferenceItemInt *v10; // eax@10
  UIPreferenceItemString *v11; // eax@12
  UIPreferenceItem *v12; // esi@14
  UIPreferenceItem *uiPreference; // [sp+4h] [bp-10h]@14
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+8h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    &result,
    i_strPreference);
  if ( result.m_currElement )
  {
    v5 = 0;
  }
  else
  {
    switch ( i_dataType )
    {
      case 4u:
        v6 = (UIPreferenceItemBool *)operator new(0x1Cu);
        if ( !v6 )
          goto LABEL_17;
        UIPreferenceItemBool::UIPreferenceItemBool(v6);
        goto LABEL_14;
      case 2u:
        v8 = (UIPreferenceItemEnum *)operator new(0x28u);
        if ( !v8 )
          goto LABEL_17;
        UIPreferenceItemEnum::UIPreferenceItemEnum(v8);
        goto LABEL_14;
      case 3u:
        v9 = (UIPreferenceItemFloat *)operator new(0x24u);
        if ( !v9 )
          goto LABEL_17;
        UIPreferenceItemFloat::UIPreferenceItemFloat(v9);
        goto LABEL_14;
      case 1u:
        v10 = (UIPreferenceItemInt *)operator new(0x24u);
        if ( !v10 )
          goto LABEL_17;
        UIPreferenceItemInt::UIPreferenceItemInt(v10);
        goto LABEL_14;
      case 5u:
        v11 = (UIPreferenceItemString *)operator new(0x1Cu);
        if ( !v11 )
          goto LABEL_17;
        UIPreferenceItemString::UIPreferenceItemString(v11);
LABEL_14:
        v12 = v7;
        uiPreference = v7;
        if ( !v7 )
          goto LABEL_17;
        if ( UIPreferenceItem::Initialize(
               v7,
               i_strPreference,
               i_dataType,
               i_eStringTable,
               i_tokenDisplay,
               i_tokenTooltip) )
        {
          v5 = HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
                 &UIPreferences::m_uiPreferences,
                 i_strPreference,
                 &uiPreference);
        }
        else
        {
          v12->vfptr->__vecDelDtor(v12, 1u);
LABEL_17:
          v5 = 0;
        }
        break;
      default:
        goto LABEL_17;
    }
  }
  return v5;
}

//----- (005DDE40) --------------------------------------------------------  // acclient.c:520933
char __cdecl UIPreferences::DetachPreference(PStringBase<char> *i_strPreference)
{
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v1; // eax@1
  void *v2; // edi@1
  int v3; // esi@2
  char result; // al@5

  v1 = IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::remove(
         &UIPreferences::m_uiPreferences.m_intrusiveTable,
         i_strPreference);
  v2 = v1;
  if ( v1 )
  {
    v3 = (int)&v1->m_hashKey.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    operator delete(v2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0068B4C0) --------------------------------------------------------  // acclient.c:674737
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *this)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<PStringBase<char>,UIPreferenceItem *> **v3; // eax@3
  int v4; // eax@4
  HashTableData<PStringBase<char>,UIPreferenceItem *> **v5; // edx@5
  void *v6; // ebx@5
  void *v7; // eax@7
  void *v8; // ecx@8
  int v9; // edi@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<PStringBase<char>,UIPreferenceItem *> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<PStringBase<char>,UIPreferenceItem *> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_20;
    do
    {
      v8 = v7;
      v7 = (void *)*((_DWORD *)v7 + 1);
    }
    while ( v7 != v6 );
    if ( v8 )
      *((_DWORD *)v8 + 1) = *((_DWORD *)v7 + 1);
    else
LABEL_20:
      *v5 = (HashTableData<PStringBase<char>,UIPreferenceItem *> *)*((_DWORD *)v7 + 1);
    --v1->m_numElements;
    if ( v6 )
    {
      v9 = *(_DWORD *)v6 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
      {
        if ( v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      }
      operator delete(v6);
    }
  }
}

//----- (0068B570) --------------------------------------------------------  // acclient.c:674803
char __thiscall HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(HashTable<PStringBase<char>,UIPreferenceItem *,0> *this, PStringBase<char> *_key, UIPreferenceItem *const *_data)
{
  HashTable<PStringBase<char>,UIPreferenceItem *,0> *v3; // edi@1
  void *v4; // esi@1
  PSRefBufferCharData<char> *v5; // eax@2
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v6; // edi@4
  char v7; // al@5
  int v8; // edi@7
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+8h] [bp-Ch]@4

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    v5 = _key->m_charbuffer;
    *(_DWORD *)v4 = _key->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
  }
  else
  {
    v4 = 0;
  }
  v6 = &v3->m_intrusiveTable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    v6,
    &result,
    (PStringBase<char> *)v4);
  if ( result.m_currElement )
  {
    if ( v4 )
    {
      v8 = *(_DWORD *)v4 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      operator delete(v4);
    }
    v7 = 0;
  }
  else
  {
    IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::add_internal(
      v6,
      (HashTableData<PStringBase<char>,UIPreferenceItem *> *)v4);
    v7 = 1;
  }
  return v7;
}

//----- (0069EB10) --------------------------------------------------------  // acclient.c:694982
bool __stdcall BasePropertyValue::InqTimeStamp(PStringBase<char> *i_value)
{
  return 0;
}

//----- (006A0220) --------------------------------------------------------  // acclient.c:696570
bool __stdcall AsyncCache::AsyncGetFromOtherSources(const float i_nMin, const float i_nMax)
{
  return 0;
}

//----- (007147B0) --------------------------------------------------------  // acclient.c:807342
int sub_7147B0()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_72, "None");
  return atexit(_E74_96);
}

//----- (007147D0) --------------------------------------------------------  // acclient.c:807349
int _E76_79()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_72, "Speed");
  return atexit(sub_77E820);
}

//----- (007147F0) --------------------------------------------------------  // acclient.c:807356
int _E79_74()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_72, "Noise");
  return atexit(_E80_72);
}

//----- (00714810) --------------------------------------------------------  // acclient.c:807363
int _E82_50()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_72, "Sine");
  return atexit(_E83_48);
}

//----- (00714830) --------------------------------------------------------  // acclient.c:807370
int _E85_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_72, "Square");
  return atexit(_E86_29);
}

//----- (00714850) --------------------------------------------------------  // acclient.c:807377
int _E88_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_72, "Bounce");
  return atexit(_E89_39);
}

//----- (00714870) --------------------------------------------------------  // acclient.c:807384
int sub_714870()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_72, "Perlin");
  return atexit(_E92_44);
}

//----- (00714890) --------------------------------------------------------  // acclient.c:807391
int _E94_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_72, "Fractal");
  return atexit(sub_77E940);
}

//----- (007148B0) --------------------------------------------------------  // acclient.c:807398
int sub_7148B0()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_72, "FrameLoop");
  return atexit(sub_77E970);
}

//----- (007148D0) --------------------------------------------------------  // acclient.c:807405
int sub_7148D0()
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>(
    &UIPreferences::m_uiPreferences.m_intrusiveTable,
    0x17u);
  return atexit(sub_77E9A0);
}

//----- (0077E7F0) --------------------------------------------------------  // acclient.c:917580
void __cdecl _E74_96()
{
  char *v0; // esi@1

  v0 = &waveform_None_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E820) --------------------------------------------------------  // acclient.c:917593
void __cdecl sub_77E820()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E850) --------------------------------------------------------  // acclient.c:917606
void __cdecl _E80_72()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E880) --------------------------------------------------------  // acclient.c:917619
void __cdecl _E83_48()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E8B0) --------------------------------------------------------  // acclient.c:917632
void __cdecl _E86_29()
{
  char *v0; // esi@1

  v0 = &waveform_Square_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E8E0) --------------------------------------------------------  // acclient.c:917645
void __cdecl _E89_39()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E910) --------------------------------------------------------  // acclient.c:917658
void __cdecl _E92_44()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E940) --------------------------------------------------------  // acclient.c:917671
void __cdecl sub_77E940()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E970) --------------------------------------------------------  // acclient.c:917684
void __cdecl sub_77E970()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E9A0) --------------------------------------------------------  // acclient.c:917697
void __cdecl sub_77E9A0()
{
  UIPreferences::m_uiPreferences.vfptr = (HashTable<PStringBase<char>,UIPreferenceItem *,0>Vtbl *)&HashTable<PStringBase<char>,UIPreferenceItem *,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents(&UIPreferences::m_uiPreferences.m_intrusiveTable);
  UIPreferences::m_uiPreferences.m_intrusiveTable.vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable;
  if ( (HashTableData<PStringBase<char>,UIPreferenceItem *> **)UIPreferences::m_uiPreferences.m_intrusiveTable.m_buckets != UIPreferences::m_uiPreferences.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](UIPreferences::m_uiPreferences.m_intrusiveTable.m_buckets);
  UIPreferences::m_uiPreferences.m_intrusiveTable.m_buckets = 0;
  UIPreferences::m_uiPreferences.m_intrusiveTable.m_firstInterestingBucket = 0;
  UIPreferences::m_uiPreferences.m_intrusiveTable.m_numBuckets = 0;
  UIPreferences::m_uiPreferences.m_intrusiveTable.m_numElements = 0;
}
// 7E9588: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable)(void *, char);
// 7E9830: using guessed type int (__thiscall *HashTable<PStringBase<char>,UIPreferenceItem *,0>::vftable)(void *, char);

