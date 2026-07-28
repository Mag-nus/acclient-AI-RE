/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIListener
   Object     : ENGINE\uielement_system\UIListener.obj
   Functions  : 21
   Addresses  : 00465E20 - 0075DF50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00465E20) --------------------------------------------------------  // acclient.c:162614
void __thiscall UIListener::RegisterForElementMessage(UIListener *this, unsigned int _elementID, unsigned int _messageID)
{
  if ( UIElementManager::s_pInstance )
    UIElementManager::RegisterForElementMessage(UIElementManager::s_pInstance, this, _elementID, _messageID);
}

//----- (00465E40) --------------------------------------------------------  // acclient.c:162621
void __thiscall UIListener::UnRegisterForElementMessage(UIListener *this, unsigned int _elementID, unsigned int _messageID)
{
  if ( UIElementManager::s_pInstance )
    UIElementManager::UnRegisterForElementMessage(UIElementManager::s_pInstance, this, _elementID, _messageID);
}

//----- (00465E60) --------------------------------------------------------  // acclient.c:162628
void __thiscall UIListener::RegisterForGlobalMessage(UIListener *this, unsigned int _messageID)
{
  if ( UIElementManager::s_pInstance )
    UIElementManager::RegisterForGlobalMessage(UIElementManager::s_pInstance, this, _messageID);
}

//----- (00465E80) --------------------------------------------------------  // acclient.c:162635
void __thiscall UIListener::UnRegisterForGlobalMessage(UIListener *this, unsigned int _messageID)
{
  if ( UIElementManager::s_pInstance )
    UIElementManager::UnRegisterForGlobalMessage(UIElementManager::s_pInstance, this, _messageID);
}

//----- (00465EA0) --------------------------------------------------------  // acclient.c:162642
IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *__thiscall IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vector_deleting_destructor(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *v2; // esi@1
  HashSetData<UIElement *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *)IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable;
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
// 79C0D4: using guessed type int (__thiscall *IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable[3])(void *, char);

//----- (00465EE0) --------------------------------------------------------  // acclient.c:162663
char __thiscall IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::grow(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::resize_internal(v2, *v3);
}

//----- (00465F30) --------------------------------------------------------  // acclient.c:162681
void __thiscall IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *)IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashSetData<UIElement *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashSetData<UIElement *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79C0D4: using guessed type int (__thiscall *IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable[3])(void *, char);

//----- (00465FC0) --------------------------------------------------------  // acclient.c:162714
char __thiscall IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::resize_internal(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *v3; // esi@1
  char result; // al@2
  HashSetData<UIElement *> *v5; // edi@3
  int v6; // ecx@4
  HashSetData<UIElement *> **v7; // eax@5
  int v8; // eax@6
  HashSetData<UIElement *> **v9; // ebx@7
  HashSetData<UIElement *> *v10; // ecx@7
  HashSetData<UIElement *> *v11; // eax@9
  HashSetData<UIElement *> *v12; // edx@10
  HashSetData<UIElement *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashSetData<UIElement *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashSetData<UIElement *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashSetData<UIElement *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashSetData<UIElement *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::resize_internal(v3, *v15);
        }
        v16 = (unsigned int)v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashSetData<UIElement *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashSetData<UIElement *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00466100) --------------------------------------------------------  // acclient.c:162830
char __thiscall IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::add(IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *this, HashSetData<UIElement *> *data)
{
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashSetData<UIElement *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashSetData<UIElement *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[(unsigned int)data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::grow(this);
    v5 = (unsigned int)data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashSetData<UIElement *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashSetData<UIElement *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00466180) --------------------------------------------------------  // acclient.c:162874
char __thiscall HashSet<UIElement *>::add(HashSet<UIElement *> *this, UIElement *const *_key)
{
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1> *v2; // esi@1
  HashSetData<UIElement *> *v3; // eax@1
  void *v4; // eax@4
  char result; // al@5

  v2 = &this->m_intrusiveTable;
  v3 = this->m_intrusiveTable.m_buckets[(unsigned int)*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != (UIElement *)*_key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    v4 = operator new(8u);
    if ( v4 )
    {
      *(_DWORD *)v4 = *_key;
      *((_DWORD *)v4 + 1) = 0;
      IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::add(v2, (HashSetData<UIElement *> *)v4);
      result = 1;
    }
    else
    {
      IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::add(v2, 0);
      result = 1;
    }
  }
  return result;
}

//----- (004661F0) --------------------------------------------------------  // acclient.c:162916
HashSet<UIElement *> *__thiscall HashSet<UIElement *>::vector_deleting_destructor(HashSet<UIElement *> *this, unsigned int a2)
{
  HashSet<UIElement *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<UIElement *>Vtbl *)HashSet<UIElement *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable;
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
// 79C0D4: using guessed type int (__thiscall *IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable[3])(void *, char);
// 79C0D8: using guessed type int (__thiscall *HashSet<UIElement *>::vftable[2])(void *, char);

//----- (00466250) --------------------------------------------------------  // acclient.c:162942
void __thiscall UIListener::UIListener(UIListener *this)
{
  UIListener *v1; // esi@1

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIListener::vftable;
  this->m_hashElementsRegisteredWith.vfptr = (HashSet<UIElement *>Vtbl *)HashSet<UIElement *>::vftable;
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>(
    &this->m_hashElementsRegisteredWith.m_intrusiveTable,
    0x17u);
  v1->m_tsSerialNumberLastListenedTo.m_timestamp = 0;
}
// 79C0D8: using guessed type int (__thiscall *HashSet<UIElement *>::vftable[2])(void *, char);
// 79C0DC: using guessed type int (__thiscall *UIListener::vftable)(void *, char);

//----- (00466280) --------------------------------------------------------  // acclient.c:162958
void __thiscall UIListener::~UIListener(UIListener *this)
{
  UIListener *v1; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@3
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@3
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebp@3
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@3
  UIElement *v6; // ecx@4
  void *v7; // eax@9
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+4h] [bp-Ch]@3

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIListener::vftable;
  if ( UIElementManager::s_pInstance )
    UIElementManager::UnRegisterForAllMessages(UIElementManager::s_pInstance, this);
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_hashElementsRegisteredWith.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  while ( v3 )
  {
    v6 = (UIElement *)v3->m_hashKey;
    v3 = v3->m_hashNext;
    if ( !v3 )
    {
      while ( 1 )
      {
        ++v5;
        if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
          break;
        if ( *v5 )
        {
          v3 = *v5;
          break;
        }
      }
    }
    UIElement::UnregisterForElementMessages(v6, v1);
  }
  v1->m_hashElementsRegisteredWith.vfptr = (HashSet<UIElement *>Vtbl *)HashSet<UIElement *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashElementsRegisteredWith.m_intrusiveTable);
  v7 = v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_buckets;
  v1->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr = (IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *)IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable;
  if ( v7 != v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v7);
  v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_buckets = 0;
  v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_numElements = 0;
  v1->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v1);
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 79C0D4: using guessed type int (__thiscall *IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable[3])(void *, char);
// 79C0D8: using guessed type int (__thiscall *HashSet<UIElement *>::vftable[2])(void *, char);
// 79C0DC: using guessed type int (__thiscall *UIListener::vftable)(void *, char);

//----- (00466340) --------------------------------------------------------  // acclient.c:163019
void __thiscall UIListener::OnRegisteredWithElement(UIListener *this, UIElement *i_pElement)
{
  HashSet<UIElement *>::add(&this->m_hashElementsRegisteredWith, &i_pElement);
}

//----- (00466350) --------------------------------------------------------  // acclient.c:163025
void __thiscall UIListener::OnUnregisteredWithElement(UIListener *this, UIElement *i_pElement)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v2; // eax@1

  v2 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_hashElementsRegisteredWith.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&i_pElement);
  if ( v2 )
    operator delete(v2);
}

//----- (00466370) --------------------------------------------------------  // acclient.c:163037
UIListener *__thiscall UIListener::scalar_deleting_destructor(UIListener *this, unsigned int a2)
{
  UIListener *v2; // esi@1

  v2 = this;
  UIListener::~UIListener(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006EB840) --------------------------------------------------------  // acclient.c:767333
int _E73_63()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_4, "Misc.TooltipEnable");
  return atexit(_E74_47);
}

//----- (006EB860) --------------------------------------------------------  // acclient.c:767340
int _E76_33()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_4, "Misc.TooltipDelay");
  return atexit(_E77_61);
}

//----- (006EB880) --------------------------------------------------------  // acclient.c:767347
int _E1_55()
{
  return atexit(_E2_55);
}

//----- (0075DF20) --------------------------------------------------------  // acclient.c:886202
void __cdecl _E74_47()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DF50) --------------------------------------------------------  // acclient.c:886215
void __cdecl _E77_61()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

